#include "VirtualThread_8.h"
#include <iostream>
#include <cmath>
#include <chrono>
#include <thread>

int VirtualThread_8::max_priority() {
    int maximum = - 1;
    int maximum_i = 0;
    for (int i = 0; i < tasks.size(); i++) {
        if (tasks[i].get_priority() > maximum) {
            maximum = tasks[i].get_priority();
            maximum_i = i;
        }
    }
    return maximum_i;
}

bool VirtualThread_8::runStep(int thread_id) {
    if (tasks.empty()) {
        return false;
    }
    int n = max_priority();
    if (tasks[n].get_current_step() + 1 == tasks[n].get_steps()) {

        std::this_thread::sleep_for(std::chrono::milliseconds(tasks[n].get_duration()/tasks[n].get_steps()));

        std::cout << "Виртуальный поток " << thread_id << " выполняет шаг "
        << tasks[n].get_current_step() + 1 << "/" << tasks[n].get_steps()
        << " задачи с приоритетом " << tasks[n].get_priority() << std::endl;

        std::cout << "Виртуальный поток " << thread_id << " завершил задачу "
        << tasks[n].get_value() << ": результат = "
        << static_cast<int>(pow(tasks[n].get_value(), 2)) << std::endl;

        tasks.erase(tasks.begin() + n);

        return true;

    } else {
        tasks[n].next_step();

        std::this_thread::sleep_for(std::chrono::milliseconds(tasks[n].get_duration()/tasks[n].get_steps()));

        std::cout << "Виртуальный поток " << thread_id << " выполняет шаг "
        << tasks[n].get_current_step() << "/" << tasks[n].get_steps()
        << " задачи с приоритетом " << tasks[n].get_priority() << std::endl;

        return true;
    }
}

VirtualThread_8::VirtualThread_8(std::vector <Task> & tasks) {
    this -> tasks = tasks;
}