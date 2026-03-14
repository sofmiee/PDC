#include "HyperThreadingSimulator_7.h"
#include <vector>
#include <string>

HyperThreadingSimulator_7::HyperThreadingSimulator_7(std::vector <std::string> & tasks)
    : thread_1(tasks), thread_2(tasks) {}

void HyperThreadingSimulator_7::execute() {
    bool running = true;
    while (running) {
        running = false;
        if (thread_1.runNextTask(1)) {
            running = true;
        }
        if (thread_2.runNextTask(2)) {
            running = true;
        }
    }
}