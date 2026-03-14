#include <iostream>
#include <windows.h>
#include <clocale>
#include <vector>
#include <algorithm>

using namespace std;

//проверка корректности ввода оценок
double grade_check(int number) {
    double value;
    while (true) {
        cout << "Студент " << number << ": ";
        cin >> value;

        if (cin.fail() || value < 0 || value > 5) {
            cin.clear();
            cin.ignore(100, '\n');
            cout << "Ошибка! Введите число от 0 до 5: ";
        } else {
            cin.ignore(100, '\n');
            return value;
        }
    }
}

//проверка ввода количества студентов
int count_check() {
    int count;
    cout << "Введите количество студентов: ";
    while (true) {
        cin >> count;
        if (cin.fail() || count <= 0) {
            cin.clear();
            cin.ignore(100, '\n');
            cout << "Ошибка! Введите натуральное число: ";
        } else {
            cin.ignore(100, '\n');
            return count;
        }
    }
}

int main() {
    SetConsoleOutputCP(CP_UTF8);
    setlocale(LC_ALL, "RUS");

    //ввод количества студентов
    int N = count_check();

    //создаем вектор для хранения средних баллов
    vector<double> grades(N);

    cout << "Введите средние баллы студентов (от 0 до 5): " << endl;
    for (int i = 0; i < N; i++) {
        grades[i] = grade_check(i + 1);
    }

    //формируем вектор пар
    vector<pair<int, double>> student_ratings;
    for (int i = 0; i < N; i++) {
        student_ratings.push_back({i, grades[i]});
    }

    //сортируем с лямбда-функцией
    sort(student_ratings.begin(), student_ratings.end(),
         [](const pair<int, double>& a, const pair<int, double>& b) {
             if (a.second != b.second) {
                 return a.second > b.second; //по убыванию балла
             }
             return a.first < b.first; //по возрастанию индекса
         });


    cout << "Место   Студент   Средний балл" << endl;
    for (int i = 0; i < student_ratings.size(); i++) {
        int student_num = student_ratings[i].first + 1;
        double avg = student_ratings[i].second;
        cout << "  " << i + 1 << "      Студент " << student_num << "       " << avg << endl;
    }

    return 0;
}
