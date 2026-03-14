#include "Person.hpp"
#include <iostream>

using namespace std;

Person::Person(const string& person_name) : name(person_name) {}

void Person::print() const {
    cout << "Имя: " << name << endl;
}
