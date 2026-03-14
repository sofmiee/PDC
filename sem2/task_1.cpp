#include <iostream>
#include <windows.h>
#include <clocale>

using namespace std;

//проверка корректности ввода оценок
double grade_check(int number) {
    double value; //вводимая оценка
    while (true) {
        cout << "Студент " << number << ": ";
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

//проверка ввода количиства студентов
int count_check() {
    int count;
    cout << "Введите количество студентов: ";
    while (true) {
        cin >> count;
        if (cin.fail() || count <= 0) {
            cin.clear();
            cin.ignore(100, '\n');
            cout << "Ошибка! Введите натуральное число студентов: ";
        } else {
            cin.ignore(100, '\n');
            return count;
        }
    }
}

//среднее арифметическое
double average(double* array, int size) {
    double sum = 0;
    for (int i = 0; i < size; i++) {
        sum += array[i];
    }
    return (sum / size);
}

double maximum(double* array, int size) {
    double local_max = array[0];
    for (int i = 0; i < size; i++) {
        if (local_max < array[i]) {
            local_max = array[i];
        }
    }
    return local_max;
}

double minimum(double* array, int size) {
    double local_min = array[0];
    for (int i = 0; i < size; i++) {
        if (local_min > array[i]) {
            local_min = array[i];
        }
    }
    return local_min;
}

//количество студентов, перешедших порог
double under_threshold(double* array, int size, double threshold) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (array[i] > threshold) {
            count += 1;
        }
    }
    return count;
}


int main() {
    SetConsoleOutputCP(CP_UTF8);
    setlocale(LC_ALL, "RUS");

    int N = count_check();

    //создаем динамический массив для оценок
    double* grades = new double[N];

    cout << "Введите средний балл студента (от 0 до 5): " << endl;
    for (int i = 0; i < N; i++) {
        grades[i] = grade_check(i + 1);

    }

    double threshold;
    cout << "Введите порог для подсчета студентов: ";
    cin >> threshold;

    cout << "Среднее арифметическое всех оценок: " << average(grades, N) << endl;
    cout << "Максимальная оценка: " << maximum(grades, N) << endl;
    cout << "Минимальное оценка: " << minimum(grades, N) << endl;
    cout << "Количество студентов преодолевших порог: " << under_threshold(grades, N, threshold) << endl;

    delete[] grades;
}
