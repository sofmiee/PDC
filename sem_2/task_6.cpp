#include <iostream>
#include <windows.h>
#include <clocale>
#include <string>
#include <vector>

using namespace std;

class Student {
private:
    string name;
    vector<double> grades;

public:
    //конструктор по умолчанию
    Student() : name("Неизвестно") {}

    //параметризованный конструктор с explicit
    explicit Student(const string& student_name) : name(student_name) {}

    //добавление оценки
    void add_grade(double grade) {
        if (grade >= 0 && grade <= 5) {
            grades.push_back(grade);
        }
    }

    //вычисление среднего балла
    double get_average() const {
        if (grades.empty()) return 0;

        double sum = 0;
        for (double g : grades) {
            sum += g;
        }
        return sum / grades.size();
    }

    //вывод информации о студенте
    void print_info() const {
        cout << "Студент: " << name << endl;
        cout << "Оценки: ";
        if (grades.empty()) {
            cout << "нет оценок";
        } else {
            for (double g : grades) {
                cout << g << " ";
            }
        }
        cout << endl;
        cout << "Средний балл: " << get_average() << endl;
    }

    //геттер для имени
    string get_name() const {
        return name;
    }
};

//функция для проверки ввода оценки
double grade_check(int number) {
    double value;
    while (true) {
        cout << "Оценка " << number << ": ";
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

int main() {
    SetConsoleOutputCP(CP_UTF8);
    setlocale(LC_ALL, "RUS");

    //демонстрация explicit конструктора
    Student s1("Федя");    //так правильно

    //демонстрация конструктора по умолчанию
    Student s2;

    cout << "\nВведите оценки для студента Федя:" << endl;
    for (int i = 0; i < 3; i++) {
        double grade = grade_check(i + 1);
        s1.add_grade(grade);
    }

    s2.add_grade(4.2);
    s2.add_grade(3.8);
    s2.add_grade(4.5);

    cout << "\nИнформация о студентах" << endl;
    cout << "\nПервый студент:" << endl;
    s1.print_info();

    cout << "\nВторой студент:" << endl;
    s2.print_info();

    //создадим студента через ввод имени
    string input_name;
    cout << "\nВведите имя третьего студента: ";
    cin >> input_name;

    Student s3(input_name);

    s3.add_grade(4.8);
    s3.add_grade(4.9);

    cout << "\nТретий студент:" << endl;
    s3.print_info();

    return 0;
}
