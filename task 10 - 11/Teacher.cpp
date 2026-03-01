#include "Teacher.hpp"
#include <iostream>

using namespace std;

Teacher::Teacher(const string& teacher_name, const string& teacher_subject)
    : Person(teacher_name), subject(teacher_subject) {}

void Teacher::print() const {
    cout << "Преподаватель: " << name << endl;
    cout << "Предмет: " << subject << endl;
}

string Teacher::get_subject() const {
    return subject;
}
