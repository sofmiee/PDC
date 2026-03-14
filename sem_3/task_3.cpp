#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;
/*
int main() {
    int N;
    cout << "Введите количество секунд: ";
    cin >> N;

    seconds total (N);
    hours h = duration_cast<hours>(total);
    seconds current = total - h;
    minutes m = duration_cast<minutes>(current);
    current = m;

    cout << h.count() << " часов " << m.count() << " минут " << current.count() << " секунд";

} */