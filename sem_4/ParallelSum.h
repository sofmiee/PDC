#ifndef SEM_4_PARALLELSUM_H
#define SEM_4_PARALLELSUM_H

#include <condition_variable>
#include <thread>
#include <vector>
#include <mutex>
#include <iostream>
#include <condition_variable>


template <class T>
class ParallelSum {
private:
    std::mutex mtx;
    std::condition_variable cv;

    std::vector <T> data;
    size_t n_threads;
    std::vector <std::thread> threads;
    T total_sum = 0;
    int active_threads;
public:
    ParallelSum(std::vector <T>& data, size_t n_threads);
    T compute_sum();
    inline T local_sum(size_t start, size_t end);
};


template <class T>
inline T ParallelSum<T>::local_sum(size_t start, size_t end) {
    T local = T(0);
    for (int i = start; i < end; i++) {
        local += data[i];

        if (i % 5 == 0) {
            std::this_thread::yield();
        }

    }
    return local;
}


template <class T>
T ParallelSum<T>::compute_sum() {
    std::unique_lock<std::mutex> lock(mtx);
    cv.wait(lock, [this]{return active_threads == 0;});

    return total_sum;
}


template<class T>
ParallelSum<T>::ParallelSum(std::vector<T>& data, size_t n_threads)
    :data(data), n_threads(n_threads)
{
    active_threads = n_threads;
    int segment_size = data.size() / n_threads;

    for (int i = 0; i < n_threads; i++) {
        int start = i * segment_size;
        int end = (i == n_threads - 1) ? data.size() : (i + 1) * segment_size;

        threads.push_back(std::thread([this, start, end]() {
            T local = local_sum(start, end);

            std::lock_guard<std::mutex> lock(mtx);
            total_sum += local;
            active_threads--;
            cv.notify_one();
            std::cout << "Поток №" << std::this_thread::get_id()
            << " Сумма: "<< local << std::endl;
        }));

        threads.back().detach();
    }
}


#endif //SEM_4_PARALLELSUM_H