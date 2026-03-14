#include <iostream>
#include <windows.h>
#include <clocale>
#include <vector>

using namespace std;

//проверка корректности ввода оценок
double grade_check() {
    double value;
    while (true) {
        cin >> value;
        if (cin.fail() || value < 0 || value > 5) { //если не цифра или не в диапозоне [0;5]
            cin.clear();
            cin.ignore(100, '\n');
            cout << "Ошибка! Введите число от 0 до 5: ";
        } else {
            cin.ignore(100, '\n');
            return value;
        }
    }
}

//проверка ввода количиства студентов или предметов
int count_check() {
    int count;
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

//средний балл одного студента
double student_average(const vector<double>& grades) {
    double sum = 0;
    for (double grade : grades) {
        sum += grade;
    }
    return sum / grades.size();
}

//средний балл по предмету
double subject_average(const vector<vector<double>>& grades, int subject_index) {
    double sum = 0;
    for (int i = 0; i < grades.size(); i++) {
        sum += grades[i][subject_index];
    }
    return sum / grades.size();
}

//поиск студента с максимальным средним баллом
int best_student(const vector<vector<double>>& grades) {
    int best_index = 0;
    double best_avg = student_average(grades[0]);

    for (int i = 1; i < grades.size(); i++) {
        double avg = student_average(grades[i]);
        if (avg > best_avg) {
            best_avg = avg;
            best_index = i;
        }
    }
    return best_index;
}

int main() {
    SetConsoleOutputCP(CP_UTF8);
    setlocale(LC_ALL, "RUS");

    cout << "Введите количество студентов: ";
    int N = count_check();

    cout << "Введите количество предметов: ";
    int M = count_check();

    //создаем двумерный вектор для оценок
    vector<vector<double>> grades(N, vector<double>(M));

    cout << "Введите оценки студентов (от 0 до 5): " << endl;
    for (int i = 0; i < N; i++) {
        cout << "Студент " << i + 1 << ":" << endl;
        for (int j = 0; j < M; j++) {
            cout << "  Предмет " << j + 1 << ": ";
            grades[i][j] = grade_check();
        }
    }

    //вывод средних баллов студентов
    cout << "\nСредние баллы студентов:" << endl;
    for (int i = 0; i < N; i++) {
        cout << "Студент " << i + 1 << ": " << student_average(grades[i]) << endl;
    }

    //вывод средних баллов по предметам
    cout << "\nСредние баллы по предметам:" << endl;
    for (int j = 0; j < M; j++) {
        cout << "Предмет " << j + 1 << ": " << subject_average(grades, j) << endl;
    }

    //поиск лучшего студента
    int best = best_student(grades);
    cout << "\nЛучший студент: Студент " << best + 1;
    cout << " (средний балл: " << student_average(grades[best]) << ")" << endl;
    
    return 0;
}
