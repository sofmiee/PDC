#include "HyperThreadingSimulator_8.h"
#include "VirtualThread_8.h"
#include "Task.h"
#include <vector>

HyperThreadingSimulator_8::HyperThreadingSimulator_8(std::vector<Task> & tasks_1, std::vector<Task> & tasks_2)
    : thread_1(tasks_1), thread_2(tasks_2)
{}

void HyperThreadingSimulator_8::execute() {
    bool running = true;
    while (running) {
        running = false;
        if (thread_1.runStep(1)) {
            running = true;
        }
        if (thread_2.runStep(2)) {
            running = true;
        }
    }
}