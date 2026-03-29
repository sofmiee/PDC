#include "Tasks.h"
#include <iostream>

long long factorial(int n) {
    if (n < 0) return -1;
    long long result = 1;
    for (int i = 2; i <= n; i++) {
        result *= i;
    }
    return result;
}

long long fibonacci(int n) {
    if (n <= 0) return 0;
    if (n == 1) return 0;
    if (n == 2) return 1;

    long long a = 0, b = 1, result = 0;
    for (int i = 3; i <= n; i++) {
        result = a + b;
        a = b;
        b = result;
    }
    return result;
}

long long sum_of_digits(int n) {
    n = abs(n);
    long long sum = 0;
    while (n > 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

bool is_prime(int n) {
    if (n <= 1) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;

    for (int i = 3; i * i <= n; i += 2) {
        if (n % i == 0) return false;
    }
    return true;
}

long long gcd(int a, int b) {
    a = abs(a);
    b = abs(b);
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

long long reverse_number(int n) {
    n = abs(n);
    long long reversed = 0;
    while (n > 0) {
        reversed = reversed * 10 + n % 10;
        n /= 10;
    }
    return reversed;
}

TaskResult process_task(const std::vector<int>& task, int thread_id, int task_counter) {
    TaskResult result;

    result.task_id = task_counter;
    result.input_number = 0;
    result.second_number = 0;
    result.result_value = 0;
    result.start_time = std::chrono::high_resolution_clock::now();

    if (task.size() < 2) {
        result.result_string = "Ошибка: некорректная задача";
        return result;
    }

    int operation_type = task[0];
    int number = task[1];

    result.operation_type = operation_type;
    result.input_number = number;

    std::string operation_name;
    long long value = 0;
    bool bool_value = false;

    switch (operation_type) {
        case 1:
            value = factorial(number);
            operation_name = "Факториал";
            result.result_string = std::to_string(number) + "! = " + std::to_string(value);
            result.result_value = value;
            break;

        case 2:
            value = fibonacci(number);
            operation_name = "Число Фибоначчи";
            result.result_string = std::to_string(number) + "-е число Фибоначчи = " + std::to_string(value);
            result.result_value = value;
            break;

        case 3:
            value = sum_of_digits(number);
            operation_name = "Сумма цифр";
            result.result_string = "Сумма цифр числа " + std::to_string(number) + " = " + std::to_string(value);
            result.result_value = value;
            break;

        case 4:
            bool_value = is_prime(number);
            operation_name = "Проверка на простоту";
            result.result_string = "Число " + std::to_string(number) +
                                  (bool_value ? " является простым" : " не является простым");
            result.result_value = bool_value ? 1 : 0;
            break;

        case 5:
            if (task.size() >= 3) {
                int second_num = task[2];
                result.second_number = second_num;
                value = gcd(number, second_num);
                operation_name = "НОД";
                result.result_string = "НОД(" + std::to_string(number) + ", " + std::to_string(second_num) + ") = " + std::to_string(value);
                result.result_value = value;
            } else {
                result.result_string = "Ошибка: для НОД нужно два числа";
            }
            break;

        case 6:
            value = reverse_number(number);
            operation_name = "Реверс числа";
            result.result_string = "Реверс числа " + std::to_string(number) + " = " + std::to_string(value);
            result.result_value = value;
            break;

        default:
            operation_name = "Неизвестная операция";
            result.result_string = "Ошибка: неизвестный тип операции " + std::to_string(operation_type);
    }

    result.end_time = std::chrono::high_resolution_clock::now();

    std::cout << "[Поток " << thread_id << "] Выполняет задачу #" << task_counter
              << ": " << operation_name << std::endl;

    return result;
}