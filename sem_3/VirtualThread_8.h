#ifndef SEM_2_VIRTUALTHREAD_8_H
#define SEM_2_VIRTUALTHREAD_8_H
#include <vector>
#include "Task.h"

class VirtualThread_8 {
private:
    std::vector <Task> tasks;
public:
    VirtualThread_8(std::vector <Task> & tasks);
    bool runStep(int thread_id);
    int max_priority();
};


#endif //SEM_2_VIRTUALTHREAD_8_H