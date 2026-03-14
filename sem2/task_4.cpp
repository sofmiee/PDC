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

    //до фильтра
    int excellent_count = 0;
    int danger_count = 0;

    for (double grade : grades) {
        if (grade >= 4.5) {
            excellent_count++;
        }
        if (grade < 3.0) {
            danger_count++;
        }
    }

    cout << "\nСтатистика до фильтра" << endl;
    cout << "Отличников (≥ 4.5): " << excellent_count << endl;
    cout << "Близких к отчислению (< 3.0): " << danger_count << endl;

    //ввод порога для фильтрации
    double threshold;
    cout << "\nВведите порог для отчисления: ";
    cin >> threshold;

    grades.erase(
        remove_if(grades.begin(), grades.end(),
            [threshold](double grade) {
                return grade < threshold; //удаляем если меньше порога
            }),
        grades.end()
    );

    //после фильтра
    excellent_count = 0;
    danger_count = 0;

    for (double grade : grades) {
        if (grade >= 4.5) {
            excellent_count++;
        }
        if (grade < 3.0) {
            danger_count++;
        }
    }

    cout << "\nСтатистика после фильтра" << endl;
    cout << "Отличников (≥ 4.5): " << excellent_count << endl;
    cout << "Близких к отчислению (< 3.0): " << danger_count << endl;

    return 0;
}
