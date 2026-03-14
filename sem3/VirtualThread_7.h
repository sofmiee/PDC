#ifndef SEM_2_VIRTUALTHREAD_7_H
#define SEM_2_VIRTUALTHREAD_7_H

#include <vector>
#include <string>

class VirtualThread_7 {
private:
    std::vector <std::string> * tasks;
    bool flag = false;
    int last_task = 0;
public:
    bool runNextTask(int thread_id);
    VirtualThread_7(std::vector <std::string> & tasks);
};


#endif //SEM_2_VIRTUALTHREAD_7_H