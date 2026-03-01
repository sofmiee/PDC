#include <iostream>
#include <windows.h>
#include <clocale>
#include <string>
#include <vector>

using namespace std;

//базовый класс Person
class Person {
protected:
    string name;

public:
    //конструктор
    explicit Person(const string& person_name) : name(person_name) {}

    //виртуальный деструктор
    virtual ~Person() {}

    //виртуальный метод print
    virtual void print() const {
        cout << "Имя: " << name << endl;
    }

    //геттер для имени
    string get_name() const {
        return name;
    }
};

//класс Student, наследник Person
class Student : public Person {
private:
    vector<double> grades;

public:
    //конструктор
    explicit Student(const string& student_name) : Person(student_name) {}

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

    //переопределение виртуального метода print
    void print() const override {
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
};

//класс Teacher, наследник Person
class Teacher : public Person {
private:
    string subject;

public:
    //конструктор
    explicit Teacher(const string& teacher_name, const string& teacher_subject)
        : Person(teacher_name), subject(teacher_subject) {}

    //переопределение виртуального метода print
    void print() const override {
        cout << "Преподаватель: " << name << endl;
        cout << "Предмет: " << subject << endl;
    }

    //геттер для предмета
    string get_subject() const {
        return subject;
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

    cout << "Наследрвание Person" << endl;

    //создаем вектор указателей на Person
    vector<Person*> people;

    //создаем студентов
    Student* s1 = new Student("Кирилл");
    Student* s2 = new Student("Мария");

    //создаем преподавателя
    Teacher* t1 = new Teacher("Павел Алексеевич", "Программирование");

    cout << "\nВведите оценки для Кирилла (3 оценки):" << endl;
    for (int i = 0; i < 3; i++) {
        double grade = grade_check(i + 1);
        s1->add_grade(grade);
    }

    cout << "\nВведите оценки для Марии (2 оценки):" << endl;
    for (int i = 0; i < 2; i++) {
        double grade = grade_check(i + 1);
        s2->add_grade(grade);
    }

    //добавляем всех в вектор
    people.push_back(s1);
    people.push_back(s2);
    people.push_back(t1);

    cout << "\n Все люди" << endl;
    for (const auto& person : people) {
        person->print();
    }

    cout << "\nСредние баллы студентов" << endl;
    for (const auto& person : people) {
        Student* student = dynamic_cast<Student*>(person);
        if (student) {
            cout << student->get_name() << ": " << student->get_average() << endl;
        }
    }

    //освобождаем память
    for (auto& person : people) {
        delete person;
    }

    return 0;
}
