#ifndef PERSON_H_INCLUDED
#define PERSON_H_INCLUDED

#include <iostream>

using namespace std;

class Person {
protected:
    string name;
    string surname;
    int age;
public:
    Person(string name1, string surname1, int age1);

    Person();

    void setAge(int age1);

    int getAge();

    string getSurname();

    bool is_18();

    void showInfoPerson();
};

#endif
