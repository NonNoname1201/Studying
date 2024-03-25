#include "Employee.h"

Employee::Employee(std::string surname, int age, int experience, int salary)
{
    this->surname = surname;
    this->age = age;
    this->experience = experience;
    this->salary = salary;
}

Employee::Employee()
{
    this->surname = "Unknown";
    this->age = 0;
    this->experience = 0;
    this->salary = 0;
}

Employee::~Employee()
{
}

void Employee::show()
{
    std::cout << "Surname: " << this->surname << std::endl;
    std::cout << "Age: " << this->age << std::endl;
    std::cout << "Experience: " << this->experience << std::endl;
    std::cout << "Salary: " << this->salary << std::endl;
}

int Employee::ageEmployment()
{
    return this->age - this->experience;
}

std::string Employee::getSurname()
{
    return this->surname;
}

int Employee::getAge()
{
    return this->age;
}

int Employee::getExperience()
{
    return this->experience;
}

int Employee::getSalary()
{
    return this->salary;
}