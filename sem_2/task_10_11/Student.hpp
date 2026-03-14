#ifndef STUDENT_HPP
#define STUDENT_HPP

#include <string>
#include "Person.hpp"
#include "RecordBook.hpp"

using namespace std;

class Student : public Person {
private:
    RecordBook record_book;

public:
    Student();
    explicit Student(const string& student_name, const string& book_number);
    
    void add_grade(double grade);
    double get_average() const;
    void print() const override;
    string get_book_number() const;
};

#endif
