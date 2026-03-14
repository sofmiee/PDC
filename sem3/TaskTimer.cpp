#include "TaskTimer.h"
#include <algorithm>
#include <iostream>
#include <chrono>
#include <vector>

using namespace std;
using namespace std::chrono;

time_point<high_resolution_clock> TaskTimer::start_time;
time_point<high_resolution_clock> TaskTimer::end_time;
milliseconds TaskTimer::duration;

void TaskTimer::start() {
    start_time = high_resolution_clock::now();
}

void TaskTimer::stop() {
    end_time = high_resolution_clock::now();
}

milliseconds TaskTimer::getDuration() {
    duration = duration_cast<milliseconds>(end_time - start_time);
    return duration;
}

void TaskTimer::measureSorting(vector <int> array) {
    start();
    sort(array.begin(), array.end());
    stop();
    cout << "Время выполнения сортировки: " << getDuration().count() << " мс";
}