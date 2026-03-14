#include "VirtualThread_6.h"
#include <iostream>
#include <vector>
using namespace std;

int VirtualThread_6::iteration = 0; //итератор начинает с нуля

VirtualThread_6::VirtualThread_6(std::vector <int> &tasks) {
    this -> tasks = &tasks;
}

bool VirtualThread_6::run(int thread_id) {
    if ((*tasks).size() == iteration) {
        return false;
    }

    int factorial = 1;
    for (int i = 1; i <= (*tasks)[iteration]; i++) {
        factorial *= i;
    }

    std::cout << "Виртуальный поток " << thread_id << " вычисляет " << (*tasks)[iteration]
         << "! = " << factorial << endl;

    iteration++;

    return true;
}

