#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;
/*
int main() {
    int N;
    cout << "Введите число: ";
    cin >> N;

    auto start = high_resolution_clock::now();

    int sum = 0;
    for (int i = 1; i < N + 1; i++) {
        sum += i;
    }

    auto end = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(end - start);

    cout << "Сумма чисел от 0 до " << N << " = " << sum << endl;
    cout << "Время выполнения: " << duration.count() << " ms" << endl;
} */