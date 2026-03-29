#ifndef DZ_1_THREAD_H
#define DZ_1_THREAD_H

#include <boost/thread.hpp>
#include "Queue.h"
#include "Tasks.h"
#include <iostream>


class Thread {
private:
    boost::thread thread;
    Queue& queue;
    std::vector<TaskResult>& results;
    boost::mutex& results_mutex;
    int thread_id;
    int& task_counter;
    boost::mutex& counter_mutex;

public:
    Thread(Queue& q, std::vector<TaskResult>& r, boost::mutex& rm, int id, int& tc, boost::mutex& cm);
    void start();
    void join();
    void run();
};

#endif //DZ_1_THREAD_H