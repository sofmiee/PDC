#include <iostream>
#include <windows.h>
#include <clocale>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//класс RecordBook
class RecordBook {
private:
    string number;
    vector<double> grades;

public:
    RecordBook() : number("000000") {}
    explicit RecordBook(const string& book_number) : number(book_number) {}

    void add_grade(double grade) {
        if (grade >= 0 && grade <= 5) {
            grades.push_back(grade);
        }
    }

    double get_average() const {
        if (grades.empty()) return 0;
        double sum = 0;
        for (double g : grades) {
            sum += g;
        }
        return sum / grades.size();
    }

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
    Student() : name("Неизвестно"), record_book("000000") {}
    explicit Student(const string& student_name, const string& book_number)
        : name(student_name), record_book(book_number) {}

    void add_grade(double grade) {
        record_book.add_grade(grade);
    }

    double get_average() const {
        return record_book.get_average();
    }

    void print_info() const {
        cout << "Студент: " << name << endl;
        record_book.print_info();
        cout << "Средний балл: " << get_average() << endl;
    }

    string get_name() const {
        return name;
    }

    string get_book_number() const {
        return record_book.get_number();
    }
};

//класс Group (агрегация)
class Group {
private:
    string group_name;
    vector<Student*> students;  //агрегация - храним указатели, не владеем

public:
    //конструктор
    explicit Group(const string& name) : group_name(name) {}

    //добавление студента
    void add_student(Student* student) {
        if (student != nullptr) {
            students.push_back(student);
            cout << "Студент " << student->get_name() << " добавлен в группу " << group_name << endl;
        }
    }

    //удаление студента по имени
    bool remove_student(const string& student_name) {
        for (auto it = students.begin(); it != students.end(); ++it) {
            if ((*it)->get_name() == student_name) {
                cout << "Студент " << student_name << " удален из группы " << group_name << endl;
                students.erase(it);
                return true;
            }
        }
        cout << "Студент " << student_name << " не найден в группе" << endl;
        return false;
    }

    //вычисление среднего балла по группе
    double get_group_average() const {
        if (students.empty()) {
            return 0;
        }

        double sum = 0;
        for (const auto& student : students) {
            sum += student->get_average();
        }
        return sum / students.size();
    }

    //вывод всех студентов группы
    void print_all() const {
        cout << "\nГруппа " << group_name << endl;
        if (students.empty()) {
            cout << "В группе нет студентов" << endl;
            return;
        }

        cout << "Список студентов (" << students.size() << "):" << endl;
        for (int i = 0; i < students.size(); i++) {
            cout << "\n" << i + 1 << ". ";
            students[i]->print_info();
        }
        cout << "\nСредний балл группы: " << get_group_average() << endl;
    }

    //геттер для названия группы
    string get_name() const {
        return group_name;
    }

    //геттер для количества студентов
    int get_size() const {
        return students.size();
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

    cout << "Агрегация группа студенты" << endl;

    //создаем студентов (они существуют независимо от группы)
    Student* s1 = new Student("Кирилл", "12345");
    Student* s2 = new Student("Мария", "67890");
    Student* s3 = new Student("Антон", "54321");
    Student* s4 = new Student("Елена", "09876");

    //добавляем оценки
    cout << "\nВведите оценки для Кирилла (3 оценки):" << endl;
    for (int i = 0; i < 3; i++) {
        double grade = grade_check(i + 1);
        s1->add_grade(grade);
    }

    cout << "\nВведите оценки для Марии (3 оценки):" << endl;
    for (int i = 0; i < 3; i++) {
        double grade = grade_check(i + 1);
        s2->add_grade(grade);
    }

    //добавляем оценки программно остальным
    s3->add_grade(4.2);
    s3->add_grade(3.8);
    s3->add_grade(4.5);

    s4->add_grade(5.0);
    s4->add_grade(4.8);
    s4->add_grade(4.9);

    //создаем группу
    Group group("ИУ8-101");

    //добавляем студентов в группу (агрегация)
    cout << "\nФормирование группы" << endl;
    group.add_student(s1);
    group.add_student(s2);
    group.add_student(s3);
    group.add_student(s4);

    //выводим информацию о группе
    group.print_all();

    //удаление
    cout << "\nУдаление студента" << endl;
    group.remove_student("Антон");

    //выводим обновленную группу
    group.print_all();

    cout << "\nСтуденты после удаления" << endl;
    s3->print_info();

    //показываем, что группа не владеет студентами
    cout << "Удаление студентов" << endl;

    //освобождаем память
    delete s1;
    delete s2;
    delete s3;
    delete s4;

    return 0;
}
