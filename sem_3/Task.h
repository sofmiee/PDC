#ifndef SEM_2_TASK_H
#define SEM_2_TASK_H
#include <chrono>


class Task {
private:
    int value;
    int priority;
    std::chrono::milliseconds duration_ms;
    int steps;
    int currentStep = 0;
public:
    Task(int value, int priority, int steps, std::chrono::milliseconds duration);
    int get_priority();
    int get_steps();
    int get_value();
    std::chrono::milliseconds get_duration();
    int get_current_step();
    void next_step();

};


#endif //SEM_2_TASK_H