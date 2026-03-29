#ifndef TASKS_H
#define TASKS_H

#include <string>
#include <chrono>
#include <vector>

long long factorial(int n);
long long fibonacci(int n);
long long sum_of_digits(int n);
bool is_prime(int n);
long long gcd(int a, int b);
long long reverse_number(int n);

struct TaskResult {
    int task_id;
    int operation_type;
    int input_number;
    int second_number;
    std::string result_string;
    long long result_value;
    std::chrono::high_resolution_clock::time_point start_time;
    std::chrono::high_resolution_clock::time_point end_time;
};

TaskResult process_task(const std::vector<int>& task, int thread_id, int task_counter);

#endif // TASKS_H