#include "VirtualThread_7.h"
#include <iostream>
#include <vector>
#include <string>

static int iterator = 0;

bool VirtualThread_7::runNextTask(int thread_id) {
    if (last_task > (*tasks).size()) {
        return false;
    } else {
        if (flag) {
            std::cout << "Виртуальный поток " << thread_id << " закончил задачу "
            << (*tasks)[last_task] << std::endl;
            flag = false;
        }
        if (flag == false) {
            if (iterator >= (*tasks).size()) {
                return false;
            }
            std::cout << "Виртуальный поток " << thread_id << " начал задачу "
            << (*tasks)[iterator] << std::endl;
            last_task = iterator;
            ++iterator;
            flag = true;

            return true;
        }

    }
}

VirtualThread_7::VirtualThread_7(std::vector<std::string> & tasks) {
    this -> tasks = & tasks;
}
