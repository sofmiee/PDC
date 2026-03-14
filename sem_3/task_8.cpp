#include "HyperThreadingSimulator_8.h"
#include "Task.h"
#include <vector>
#include <random>
#include <iostream>

int random_int (int start, int end) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist (start, end);

    return dist(gen);
}

int main() {
    int N;
    std::cout << "Введите количество задач: ";
    std::cin >> N;

    std::vector<Task> tasks_1;
    std::vector<Task> tasks_2;

    for (int i = 0; i < N / 2; i++) {

        tasks_1.push_back(Task(random_int(1, 50), random_int(1, N),random_int(2,5),
            std::chrono::milliseconds(random_int(200, 1000))));
    }
    for (int i = 0; i < N / 2 + N % 2; i++) {
        tasks_2.push_back(Task(random_int(1, 50), random_int(1, N),random_int(2,5),
            std::chrono::milliseconds(random_int(200, 1000))));
    }

    HyperThreadingSimulator_8 simulator(tasks_1, tasks_2);
    simulator.execute();
}