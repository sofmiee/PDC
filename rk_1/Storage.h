#ifndef RK_1_STORAGE_H
#define RK_1_STORAGE_H

#include <atomic>
#include <mutex>
#include <condition_variable>


class Storage {
private:
    int id;
    std::atomic <int> amount;
    std::atomic <int> need_amount;
    bool zone_free = true;
    bool ready_fill = false;
    std::mutex mtx;
    std::condition_variable cv;
public:
    Storage(int id, int amount, int need_amount);
    void add();
    void check();
    int get_need_amount();
    int get_amount();
    bool full();
};

#endif //RK_1_STORAGE_H