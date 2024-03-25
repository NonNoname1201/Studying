#include "Developer.h"

Developer::Developer(std::string surname, int age, int experience, int salary) : Employee(surname, age, experience, salary)
{
}

Developer::Developer()
{
}

Developer::~Developer()
{
}

void Developer::show()
{
    std::cout << "Developer" << std::endl;
    Employee::show();
}

int Developer::calculateSalary(int value)
{
    return this->getSalary() + this->calculateBonus(value);
}

int Developer::calculateBonus(int value)
{
    return value + 0.2 * value * (this->getSalary() + this->getExperience());
}

// Path: Employee.cpp
