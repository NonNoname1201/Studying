#ifndef LAB_1_STUDENT_H
#define LAB_1_STUDENT_H

#include <iostream>
#include "person.h"

using namespace std;

class Student : public Person
{
public:
    Student(string name1, string surname1, int age1, string index1);

    Student();

    void setIndex(string newIndex);

    string getIndex();

    void showInfoStudent();
};

#endif
