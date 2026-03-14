#ifndef SEM_2_VIRTUALTHREAD_6_H
#define SEM_2_VIRTUALTHREAD_6_H

#include <vector>

class VirtualThread_6 {
private:
    std::vector<int>* tasks; //список заданий
    static int iteration; //текущее задание
public:
    VirtualThread_6(std::vector<int> &tasks); //конструктор
    bool run(int thread_id);
};


#endif //SEM_2_VIRTUALTHREAD_6_H