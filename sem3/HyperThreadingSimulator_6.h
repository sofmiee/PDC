#ifndef SEM_2_HYPERTHREADINGSIMULATOR_6_H
#define SEM_2_HYPERTHREADINGSIMULATOR_6_H

#include "VirtualThread_6.h"
#include <vector>

class HyperThreadingSimulator_6 {
private:
    VirtualThread_6 thread_1;
    VirtualThread_6 thread_2;
public:
    HyperThreadingSimulator_6(std::vector<int> &tasks);
    void execute();
};
#endif //SEM_2_HYPERTHREADINGSIMULATOR_6_H