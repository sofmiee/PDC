#ifndef SEM_2_HYPERTHREADINGSIMULATOR_7_H
#define SEM_2_HYPERTHREADINGSIMULATOR_7_H
#include "VirtualThread_7.h"
#include <vector>
#include <string>

class HyperThreadingSimulator_7 {
private:
    VirtualThread_7 thread_1;
    VirtualThread_7 thread_2;
public:
    HyperThreadingSimulator_7(std::vector <std::string> & tasks);
    void execute();
};


#endif //SEM_2_HYPERTHREADINGSIMULATOR_7_H