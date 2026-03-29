#include "Thread.h"
Thread::Thread(Queue& q, std::vector<TaskResult>& r, boost::mutex& rm, int id,
               int& tc, boost::mutex& cm)
        : queue(q), results(r), results_mutex(rm), thread_id(id),
          task_counter(tc), counter_mutex(cm) {}

void Thread::start() {
    thread = boost::thread(&Thread::run, this);
}

void Thread::join() {
    if (thread.joinable()) {
        thread.join();
    }
}

void Thread::run() {
    while (true) {
        std::vector<int> task = queue.get_task();

        if (task.empty()) {
            break;
        }

        int current_task_id;
        {
            boost::lock_guard<boost::mutex> lock(counter_mutex);
            current_task_id = ++task_counter;
        }


        TaskResult result = process_task(task, thread_id, current_task_id);


        {
            boost::lock_guard<boost::mutex> lock(results_mutex);
            results.push_back(result);
        }
    }

    std::cout << "[Поток " << thread_id << "] Завершил работу" << std::endl;
}
