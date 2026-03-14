#ifndef SEM_2_HYPERTHREADINGSIMULATOR_8_H
#define SEM_2_HYPERTHREADINGSIMULATOR_8_H
#include "VirtualThread_8.h"
#include <vector>

class HyperThreadingSimulator_8 {
private:
    VirtualThread_8 thread_1;
    VirtualThread_8 thread_2;
public:
    HyperThreadingSimulator_8(std::vector<Task> & tasks_1, std::vector<Task> & tasks_2);
    void execute();
};

#endif //SEM_2_HYPERTHREADINGSIMULATOR_8_H