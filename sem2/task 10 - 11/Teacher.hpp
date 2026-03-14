#ifndef TEACHER_HPP
#define TEACHER_HPP

#include <string>
#include "Person.hpp"

using namespace std;

class Teacher : public Person {
private:
    string subject;

public:
    explicit Teacher(const string& teacher_name, const string& teacher_subject);
    
    void print() const override;
    string get_subject() const;
};

#endif
