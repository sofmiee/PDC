#include "Student.hpp"
#include <iostream>

using namespace std;

Student::Student() : Person("Неизвестно"), record_book("000000") {}

Student::Student(const string& student_name, const string& book_number)
    : Person(student_name), record_book(book_number) {}

void Student::add_grade(double grade) {
    record_book.add_grade(grade);
}

double Student::get_average() const {
    return record_book.get_average();
}

void Student::print() const {
    cout << "Студент: " << name << endl;
    record_book.print_info();
    cout << "Средний балл: " << get_average() << endl;
}

string Student::get_book_number() const {
    return record_book.get_number();
}
