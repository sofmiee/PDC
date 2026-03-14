#include <iostream>
#include <chrono>
#include <thread>

using namespace std;
using namespace std::chrono;

/*
int main() {
    int N;
    cout << "Введите число секунд: ";
    cin >> N;

    for (int i = N; i >= 0; --i) {
        if (i > 4) {
            cout << "Осталось: " << i << " секунд" << endl;
            this_thread::sleep_for(seconds(1));

        } else if (i > 1) {
            cout << "Осталось: " << i << " секунды" << endl;
            this_thread::sleep_for(seconds(1));
        } else if (i == 1) {
            cout << "Осталось: " << i << " секунда" << endl;
            this_thread::sleep_for(seconds(1));
        } else {
            cout << "Время вышло!";
        }
    }

} */