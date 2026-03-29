// Queue.h
#ifndef QUEUE_H
#define QUEUE_H

#include <vector>
#include <queue>
#include <boost/thread.hpp>

class Queue {
private:
    std::queue<std::vector<int>> tasks;
    boost::mutex mutex;
    boost::condition_variable cond;
    bool finished;
    
public:
    Queue();
    void add_task(const std::vector<int>& task);
    std::vector<int> get_task();
    void finish();
    bool is_empty();
};

#endif