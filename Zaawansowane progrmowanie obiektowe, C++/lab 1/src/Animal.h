#ifndef LAB_1_ANIMAL_H
#define LAB_1_ANIMAL_H

#include <iostream>

using namespace std;

class Animal {
private:
    int limbNr;
    string name;
    bool protectedAnimal;
public:
    Animal();

    Animal(int limbNr1, string name1, bool protectedAnimal1 = true);

    void setLimbNr(int limbNr1);

    int getLimbNr();

    void setName(string name1);

    string getName();

    void setProtectedAnimal(bool protectedAnimal1);

    bool getProtectedAnimal();

    void giveVoice();

    void info();
};

#endif //LAB_1_ANIMAL_H
