#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <iostream>

class Employee
{
public:
    Employee(std::string surname, int age, int experience, int salary);
    Employee();
    virtual ~Employee();
    virtual void show();
    virtual int calculateBonus(int value) = 0;
    int ageEmployment();
    std::string getSurname();
    int getAge();
    int getExperience();
    int getSalary();

private:
    std::string surname;
    int age;
    int experience;
    int salary;
};

#endif // EMPLOYEE_H