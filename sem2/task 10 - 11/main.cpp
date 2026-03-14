#include <iostream>
#include <windows.h>
#include <clocale>
#include <vector>
#include "Person.hpp"
#include "Student.hpp"
#include "Teacher.hpp"
#include "Group.hpp"
#include "FileManager.hpp"
#include "grade_check.hpp"

using namespace std;

int main() {
    SetConsoleOutputCP(CP_UTF8);
    setlocale(LC_ALL, "RUS");

    cout << "Размер заголовка файла: " << FileManager::get_header_size() << " байт" << endl;

    //создаем студентов
    Student* s1 = new Student("Кирилл", "12345");
    Student* s2 = new Student("Мария", "67890");
    Student* s3 = new Student("Антон", "54321");

    //добавляем оценки
    cout << "\nВведите оценки для Кирилла (3 оценки):" << endl;
    for (int i = 0; i < 3; i++) {
        double grade = grade_check(i + 1);
        s1->add_grade(grade);
    }

    s2->add_grade(5.0);
    s2->add_grade(4.8);
    s2->add_grade(4.9);

    s3->add_grade(4.2);
    s3->add_grade(3.8);
    s3->add_grade(4.5);

    //создаем группу
    Group group("ИУ8-101");
    group.add_student(s1);
    group.add_student(s2);
    group.add_student(s3);

    //выводим информацию
    group.print_all();

    //создаем преподавателя
    Teacher* t1 = new Teacher("Павел Алексеевич", "Программирование");
    cout << "\nПреподаватель" << endl;
    t1->print();

    //освобождаем память
    delete s1;
    delete s2;
    delete s3;
    delete t1;

    return 0;
}
