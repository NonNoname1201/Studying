#include "Dog.h"
#include <iostream>

using namespace std;

Dog::Dog(string breed1, int levelOfGuideSkills1, int levelOfTrackerSkills1)
{
    breed = breed1;
    levelOfGuideSkills = levelOfGuideSkills1;
    levelOfTrackerSkills = levelOfTrackerSkills1;
}

Dog::Dog()
{
}

void Dog::setSkillLevel(int type, int value)
{
    if (type == 1)
    {
        levelOfGuideSkills = value;
    }
    else if (type == 2)
    {
        levelOfTrackerSkills = value;
    }
}

int Dog::getSkillLevel(int type)
{
    if (type == 1)
    {
        return levelOfGuideSkills;
    }
    else if (type == 2)
    {
        return levelOfTrackerSkills;
    }
    else
    {
        return -1;
    }
}

void Dog::giveVoice()
{
    cout << "Hau hau" << endl;
}

void Dog::info()
{
    cout << "Rasa: " << breed << " poziom umiejetnosci przewodnika: " << levelOfGuideSkills << " poziom umiejetnosci tropiciela: " << levelOfTrackerSkills << endl;
}
