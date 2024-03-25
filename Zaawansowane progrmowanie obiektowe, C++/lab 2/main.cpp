#include <iostream>
#include "Employee.h"
#include "Developer.h"
#include "TeamLeader.h"

void whoWorkMoreThan5Years(Employee **employees, int size)
{
    std::cout << "Pracownicy, którzy pracują więcej niż 5 lat:" << std::endl;
    for (int i = 0; i < size; ++i)
    {
        if (employees[i]->ageEmployment() > 5)
        {
            employees[i]->show();
        }
    }
    std::cout << std::endl;
}

void howManyEarnLessThanMeanBonus(Employee **employees, int size)
{
    int sum = 0;
    for (int i = 0; i < size; ++i)
    {
        sum += employees[i]->calculateBonus(100);
    }
    int mean = sum / size;
    int counter = 0;
    for (int i = 0; i < size; ++i)
    {
        if (employees[i]->calculateBonus(100) < mean)
        {
            std::cout << employees[i]->getSurname() << std::endl;
            counter++;
        }
    }
    std::cout << "Ilość pracowników, którzy dostali premię niższą niż średnia wszystkich premii: " << counter << std::endl;
}

int main()
{
    srand(time(NULL));
    Employee *employees[5];

    for (int i = 0; i < 5; ++i)
    {
        int type = rand() % 2;
        if (type == 0)
        {
            employees[i] = new Developer("Dev", 20 + rand() % 15, rand() % 5, 10000 + 5000 * rand() % 5);
        }
        else
        {
            employees[i] = new TeamLeader("TLead " + 1, 30 + rand() % 15, rand() % 10, 20000 + 5000 * rand() % 6);
        }
    }

    whoWorkMoreThan5Years(employees, 5);
    howManyEarnLessThanMeanBonus(employees, 5);

    return 0;
}