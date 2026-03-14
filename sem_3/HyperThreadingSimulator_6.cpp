#include "HyperThreadingSimulator_6.h"
#include "VirtualThread_6.h"
#include <vector>

HyperThreadingSimulator_6::HyperThreadingSimulator_6(std::vector <int> &tasks)
    :
        thread_1 (tasks),
        thread_2 (tasks)
    {}

void HyperThreadingSimulator_6::execute() {
    bool running = true;
    while (running) {
        running = false; //считаем, что все закончилось, далее пробуем опровергнуть это

        if (thread_1.run(1)) {
            running = true;
        }
        if (thread_2.run(2)) {
            running = true;
        }
    }
}