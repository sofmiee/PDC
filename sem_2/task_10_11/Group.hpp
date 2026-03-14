#ifndef GROUP_HPP
#define GROUP_HPP

#include <string>
#include <vector>


class Student;

using namespace std;

class Group {
private:
    string group_name;
    vector<Student*> students; 

public:
    explicit Group(const string& name);
    
    void add_student(Student* student);
    bool remove_student(const string& student_name);
    double get_group_average() const;
    void print_all() const;
    string get_name() const;
    int get_size() const;
};

#endif
