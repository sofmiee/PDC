#include "ParallelSum.h"
#include <vector>
#include <iostream>


template <typename T>
void run() {
    std::vector<T> data;
    size_t n_threads;
    T start;
    T end;

    std::cout << "Для суммирования по диапазону [x1, x2] введите" << std::endl;
    std::cout << "x1: ";
    std::cin >> start;
    std::cout << "x2: ";
    std::cin >> end;
    std::cout << "Введите число потоков: ";
    std::cin >> n_threads;

    for (T i = start; i <= end; i++) {
        data.push_back(i);
    }

    ParallelSum<T> simulator(data, n_threads);

    T result = simulator.compute_sum();
    //проверка арифметической прогрессией
    if ((start + end) * (end - start + 1) / 2 == result) {
        std::cout<< "Итоговая сумма: "<< result << " Сумма верна!";
    } else {
        std::cout << "Ошибка! Ожидалось: " << (start + end) * (start - end + 1) / 2  << " Получено: " << result;
    }
}



int main() {
    run<double>();
    return 0;
}
