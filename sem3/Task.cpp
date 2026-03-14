#include "Task.h"

std::chrono::milliseconds Task::get_duration() {
    return duration_ms;
}

int Task::get_priority() {
    return priority;
}

int Task::get_steps() {
    return steps;
}

int Task::get_value() {
    return value;
}

int Task::get_current_step() {
    return currentStep;
}

void Task::next_step() {
    currentStep++;
}

Task::Task(int value, int priority, int steps, std::chrono::milliseconds duration_ms) {
    this->value = value;
    this->priority = priority;
    this->steps = steps;
    this->duration_ms = duration_ms;
}