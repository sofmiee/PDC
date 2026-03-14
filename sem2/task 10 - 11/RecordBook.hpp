#ifndef RECORDBOOK_HPP
#define RECORDBOOK_HPP

#include <string>
#include <vector>

using namespace std;

class RecordBook {
private:
    string number;
    vector<double> grades;

public:
    RecordBook();
    explicit RecordBook(const string& book_number);
    
    void add_grade(double grade);
    double get_average() const;
    void print_info() const;
    string get_number() const;
};

#endif
