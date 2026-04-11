#include "Storage.h"
#include <atomic>
#include <random>
#include <mutex>
#include <condition_variable>
#include <iostream>

std::mutex output_mutex;

Storage::Storage(int id, int amount, int need_amount)
    :id(id), amount(amount), need_amount(need_amount) {}

int Storage::get_amount() {
    return amount.load();
}

int Storage::get_need_amount() {
    return need_amount;
}

void Storage::add() {
    std::unique_lock<std::mutex> lock(mtx);
    cv.wait(lock, [this]{return zone_free;});
    zone_free = false;
    if (!ready_fill) {
        std::random_device rd;
        std::mt19937 gen(rd());

        if (need_amount.load() > 0) {
            std::uniform_int_distribution<> count(1, need_amount.load());

            int to_add = count(gen);
            need_amount.fetch_sub(to_add);
            amount.fetch_add(to_add);

            std::lock_guard<std::mutex> output_lock(output_mutex);
            std::cout << "Добавлено " << to_add << " в зону №" << id << std::endl;

            zone_free = true;
            cv.notify_one();
        }
    }
}

void Storage::check() {
    std::unique_lock<std::mutex> lock(mtx);
    cv.wait(lock, [this]{return zone_free;});
    zone_free = false;

    if (need_amount.load() == 0) {
        ready_fill = true;

        zone_free = true;
        cv.notify_one();
    } else {
    std::lock_guard<std::mutex> output_lock(output_mutex);
    std::cout << "Необходимо " << need_amount << " в зоне №" << id << std::endl;

    zone_free = true;
    cv.notify_one();
    }
}

bool Storage::full() {
    return ready_fill;
}
