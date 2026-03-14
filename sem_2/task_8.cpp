#include <iostream>
#include <windows.h>
#include <clocale>
#include <string>
#include <vector>

using namespace std;

//класс RecordBook
class RecordBook {
private:
    string number;          // номер зачётной книжки
    vector<double> grades;  // список оценок

public:
    //конструктор по умолчанию
    RecordBook() : number("000000") {}

    //конструктор с номером
    explicit RecordBook(const string& book_number) : number(book_number) {}

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

    //вывод информации о зачётке
    void print_info() const {
        cout << "Зачётка №" << number << endl;
        cout << "Оценки: ";
        if (grades.empty()) {
            cout << "нет оценок";
        } else {
            for (double g : grades) {
                cout << g << " ";
            }
        }
        cout << endl;
    }

    //геттер для номера
    string get_number() const {
        return number;
    }
};

//класс Student
class Student {
private:
    string name;
    RecordBook record_book;  

public:
    //конструктор по умолчанию
    Student() : name("Неизвестно"), record_book("000000") {}

    //параметризованный конструктор
    explicit Student(const string& student_name, const string& book_number)
        : name(student_name), record_book(book_number) {}

    //добавление оценки (через зачётку)
    void add_grade(double grade) {
        record_book.add_grade(grade);
    }

    //вычисление среднего балла (через зачётку)
    double get_average() const {
        return record_book.get_average();
    }

    //вывод информации о студенте
    void print_info() const {
        cout << "Студент: " << name << endl;
        record_book.print_info();
        cout << "Средний балл: " << get_average() << endl;
    }

    //геттер для имени
    string get_name() const {
        return name;
    }

    //геттер для номера зачётки
    string get_book_number() const {
        return record_book.get_number();
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

    cout << "Композиция Student и Recordbook" << endl;

    //создаем студентов с номерами зачёток
    Student s1("Кирилл", "12345");
    Student s2("Мария", "67890");
    Student s3;  //по умолчанию

    //добавляем оценки
    cout << "\nВведите оценки для Кирилла (3 оценки):" << endl;
    for (int i = 0; i < 3; i++) {
        double grade = grade_check(i + 1);
        s1.add_grade(grade);
    }

    cout << "\nВведите оценки для Марии (2 оценки):" << endl;
    for (int i = 0; i < 2; i++) {
        double grade = grade_check(i + 1);
        s2.add_grade(grade);
    }

    //добавляем оценки третьему студенту программно
    s3.add_grade(4.2);
    s3.add_grade(3.8);
    s3.add_grade(4.5);
    s3.add_grade(4.0);

    //выводим информацию
    cout << "\nИнформация о студентах" << endl;

    cout << "\nПервый студент:" << endl;
    s1.print_info();

    cout << "\nВторой студент:" << endl;
    s2.print_info();

    cout << "\nТретий студент:" << endl;
    s3.print_info();

    //демонстрация доступа к номеру зачётки
    cout << "\nНомера зачетных книжек" << endl;
    cout << s1.get_name() << ": " << s1.get_book_number() << endl;
    cout << s2.get_name() << ": " << s2.get_book_number() << endl;
    cout << "Студент по умолчанию: " << s3.get_book_number() << endl;
    
    return 0;
}
