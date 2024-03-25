//
// Created by User on 13.10.2023.
//

#ifndef LAB_1_CAT_H
#define LAB_1_CAT_H

#include "Animal.h"
#include <iostream>

using namespace std;

class Cat : public Animal {
private:
    int levelOfMouseHunting;
    int mice[5];
public:
    Cat();

    Cat(int levelOfMouseHunting1, int mice1[5]);

    void initMice(int mice1[5]);

    void initCat(int levelOfMouseHunting1, int mice1[5]);

    void setLevelOfMouseHunting(int value);

    int getLevelOfMouseHunting();

    int getMice(int index);

    void giveVoice();

    void info();
};

#endif //LAB_1_CAT_H
