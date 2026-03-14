#include "RecordBook.hpp"
#include <iostream>

using namespace std;

RecordBook::RecordBook() : number("000000") {}

RecordBook::RecordBook(const string& book_number) : number(book_number) {}

void RecordBook::add_grade(double grade) {
    if (grade >= 0 && grade <= 5) {
        grades.push_back(grade);
    }
}

double RecordBook::get_average() const {
    if (grades.empty()) return 0;
    
    double sum = 0;
    for (double g : grades) {
        sum += g;
    }
    return sum / grades.size();
}

void RecordBook::print_info() const {
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

string RecordBook::get_number() const {
    return number;
}
