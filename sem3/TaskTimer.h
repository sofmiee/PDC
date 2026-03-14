#ifndef SEM_2_TASKTIMER_H
#define SEM_2_TASKTIMER_H

#include <iostream>
#include <chrono>
#include <vector>

using namespace std;
using namespace std::chrono;



class TaskTimer {
private:
    static time_point<high_resolution_clock> start_time;
    static time_point<high_resolution_clock> end_time;
    static milliseconds duration;
public:
    static void start();
    static void stop();
    static milliseconds getDuration();
    static void measureSorting(vector <int> array);

};


#endif //SEM_2_TASKTIMER_H