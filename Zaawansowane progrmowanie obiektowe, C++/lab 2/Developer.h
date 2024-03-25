#ifndef DEVELOPER_H
#define DEVELOPER_H

#include <iostream>
#include "Employee.h"

class Developer : public Employee
{
public:
    Developer(std::string surname, int age, int experience, int salary);
    Developer();
    virtual ~Developer();
    virtual void show();
    virtual int calculateSalary(int value);
    int calculateBonus(int value);
};

#endif // DEVELOPER_H
