#include <iostream>
#include <vector>
#include <string>
#include <chrono>
#include <algorithm>
#include <boost/thread.hpp>

#include "Queue.h"
#include "Tasks.h"
#include "Thread.h"

using namespace std;

int main() {
    Queue task_queue;

    // формируем список задач в формате [тип_операции, число]
    // типы операций:
    // 1 - факториал
    // 2 - число Фибоначчи
    // 3 - сумма цифр
    // 4 - проверка на простоту
    // 5 - НОД (для этого типа нужно передать второе число)
    // 6 - реверс числа

    vector<vector<int>> tasks = {
        {1, 5},          // Факториал 5!
        {2, 8},          // 8-е число Фибоначчи
        {3, 12345},      // Сумма цифр 12345
        {4, 17},         // Проверка 17 на простоту
        {5, 48, 18},     // НОД(48, 18)
        {6, 12345},      // Реверс 12345
        {1, 7},          // Факториал 7!
        {2, 12},         // 12-е число Фибоначчи
        {3, 9876},       // Сумма цифр 9876
        {4, 97},         // Проверка 97 на простоту
        {5, 144, 60},    // НОД(144, 60)
        {6, 45678},      // Реверс 45678
        {1, 10},         // Факториал 10!
        {2, 15},         // 15-е число Фибоначчи
        {4, 1009}        // Проверка 1009 на простоту
    };

    for (size_t i = 0; i < tasks.size(); i++) {
        task_queue.add_task(tasks[i]);

        string operation_name;
        switch (tasks[i][0]) {
            case 1: operation_name = "Факториал"; break;
            case 2: operation_name = "Фибоначчи"; break;
            case 3: operation_name = "Сумма цифр"; break;
            case 4: operation_name = "Проверка на простоту"; break;
            case 5: operation_name = "НОД"; break;
            case 6: operation_name = "Реверс числа"; break;
        }

        cout << "Задача " << (i+1) << ": " << operation_name;
        if (tasks[i][0] == 5 && tasks[i].size() >= 3) {
            cout << " для чисел " << tasks[i][1] << " и " << tasks[i][2];
        } else {
            cout << " для числа " << tasks[i][1];
        }
        cout << endl;
    }

    // Результаты выполнения
    vector<TaskResult> results;
    boost::mutex results_mutex;
    int task_counter = 0;
    boost::mutex counter_mutex;

    const int NUM_THREADS = 3;
    vector<Thread> workers;

    auto start_time = chrono::high_resolution_clock::now();

    for (int i = 0; i < NUM_THREADS; i++) {
        workers.emplace_back(task_queue, results, results_mutex, i + 1,
                            task_counter, counter_mutex);
        workers.back().start();
    }

    while (!task_queue.is_empty()) {
        boost::this_thread::sleep_for(boost::chrono::milliseconds(100));
    }

    task_queue.finish();

    for (auto& worker : workers) {
        worker.join();
    }

    auto end_time = chrono::high_resolution_clock::now();
    auto duration = duration_cast<std::chrono::milliseconds>(end_time - start_time);

    cout << "РЕЗУЛЬТАТЫ ВЫПОЛНЕНИЯ" << endl;

    sort(results.begin(), results.end(),
         [](const TaskResult& a, const TaskResult& b) {
             return a.task_id < b.task_id;
         });

    for (const auto& result : results) {
        auto task_duration = duration_cast<std::chrono::microseconds>(result.end_time - result.start_time);
        cout << "Задача #" << result.task_id << ": " << result.result_string
             << " (время: " << task_duration.count() << " мкс)" << endl;
    }


    cout << "Всего выполнено задач: " << results.size() << endl;
    cout << "Количество рабочих потоков: " << NUM_THREADS << endl;
    cout << "Общее время выполнения: " << duration.count() << " мс" << endl;

    return 0;
}