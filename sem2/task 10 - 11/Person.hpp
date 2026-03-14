#ifndef PERSON_HPP
#define PERSON_HPP

#include <string>

using namespace std;

class Person {
protected:
    string name;

public:
    explicit Person(const string& person_name);
    virtual ~Person() {}
    
    virtual void print() const;
    
    inline string get_name() const {
        return name;
    }
};

#endif
