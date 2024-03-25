#include "TeamLeader.h"

TeamLeader::TeamLeader(std::string surname, int age, int experience, int salary) : Developer(surname, age, experience, salary)
{
}

TeamLeader::TeamLeader()
{
}

TeamLeader::~TeamLeader()
{
}

void TeamLeader::show()
{
    std::cout << " Jestem TeamLeader z " << this->getExperience() << " letnim doswiadczeniem" << std::endl;
}

int TeamLeader::calculateSalary(int value)
{
    return this->getSalary() + this->calculateBonus(value);
}

int TeamLeader::calculateBonus(int value)
{
    return value * (1 + this->getSalary() + this->getExperience());
}
