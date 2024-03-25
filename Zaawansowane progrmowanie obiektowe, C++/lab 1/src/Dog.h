#ifndef LAB_1_DOG_H
#define LAB_1_DOG_H

#include "Animal.h"
#include <iostream>

using namespace std;

class Dog : public Animal {
private:
    string breed;
    int levelOfGuideSkills;
    int levelOfTrackerSkills;
public:
    Dog(string breed1, int levelOfGuideSkills1, int levelOfTrackerSkills1);

    Dog();

    void setSkillLevel(int type, int value);

    int getSkillLevel(int type);

    void giveVoice();

    void info();
};

#endif //LAB_1_DOG_H
