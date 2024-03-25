#ifndef TEAMLEADER_H
#define TEAMLEADER_H

#include <iostream>
#include "Developer.h"

class TeamLeader : public Developer
{
public:
    TeamLeader(std::string surname, int age, int experience, int salary);
    TeamLeader();
    virtual ~TeamLeader();
    virtual void show();
    virtual int calculateSalary(int value);
    int calculateBonus(int value);
};

#endif // TEAMLEADER_H