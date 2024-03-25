#include "Cat.h"
#include <iostream>

using namespace std;

Cat::Cat() {
}

Cat::Cat(int levelOfMouseHunting1, int mice1[5]) {
    levelOfMouseHunting = levelOfMouseHunting1;
    for (int i = 0; i < 5; i++) {
        mice[i] = mice1[i];
    }
}

void Cat::initMice(int mice1[5]) {
    for (int i = 0; i < 5; i++) {
        mice[i] = mice1[i];
    }
}

void Cat::initCat(int levelOfMouseHunting1, int mice1[5]) {
    levelOfMouseHunting = levelOfMouseHunting1;
    for (int i = 0; i < 5; i++) {
        mice[i] = mice1[i];
    }
}

void Cat::setLevelOfMouseHunting(int value) {
    levelOfMouseHunting = value;
}

int Cat::getLevelOfMouseHunting() {
    return levelOfMouseHunting;
}

int Cat::getMice(int index) {
    return mice[index];
}

void Cat::giveVoice() {
    cout << "Miau miau" << endl;
}

void Cat::info() {
    cout << "Poziom polowania na myszy: " << levelOfMouseHunting << " myszy: ";
    for (int i = 0; i < 5; i++) {
        cout << mice[i] << " ";
    }
    cout << endl;
}