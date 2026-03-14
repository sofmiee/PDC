#include "Group.hpp"
#include "Student.hpp"  //здесь уже нужно полное определение
#include <iostream>
#include <algorithm>

using namespace std;

Group::Group(const string& name) : group_name(name) {}

void Group::add_student(Student* student) {
    if (student != nullptr) {
        students.push_back(student);
        cout << "Студент " << student->get_name() << " добавлен в группу " << group_name << endl;
    }
}

bool Group::remove_student(const string& student_name) {
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

double Group::get_group_average() const {
    if (students.empty()) return 0;
    
    double sum = 0;
    for (const auto& student : students) {
        sum += student->get_average();
    }
    return sum / students.size();
}

void Group::print_all() const {
    cout << "\n=== ГРУППА " << group_name << " ===" << endl;
    if (students.empty()) {
        cout << "В группе нет студентов" << endl;
        return;
    }
    
    cout << "Список студентов (" << students.size() << "):" << endl;
    for (int i = 0; i < students.size(); i++) {
        cout << "\n" << i + 1 << ". ";
        students[i]->print();
    }
    cout << "\nСредний балл группы: " << get_group_average() << endl;
}

string Group::get_name() const {
    return group_name;
}

int Group::get_size() const {
    return students.size();
}
