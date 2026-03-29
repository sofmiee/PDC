#include "Queue.h"

Queue::Queue() : finished(false) {}

void Queue::add_task(const std::vector<int>& task) {
    boost::lock_guard<boost::mutex> lock(mutex);
    tasks.push(task);
    cond.notify_one();
}

std::vector<int> Queue::get_task() {
    boost::unique_lock<boost::mutex> lock(mutex);

    while (tasks.empty() && !finished) {
        cond.wait(lock);
    }
    if (tasks.empty() && finished) {
        return {};
    }

    std::vector<int> task = tasks.front();
    tasks.pop();
    return task;
}

void Queue::finish() {
    boost::lock_guard<boost::mutex> lock(mutex);
    finished = true;
    cond.notify_all();  // Будим все потоки
}

bool Queue::is_empty() {
    boost::lock_guard<boost::mutex> lock(mutex);
    return tasks.empty();
}