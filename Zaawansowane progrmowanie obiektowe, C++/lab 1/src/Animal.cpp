#include "Animal.h"
#include <iostream>

using namespace std;

Animal::Animal(int limbNr1, string name1, bool protectedAnimal1) {
    limbNr = limbNr1;
    name = name1;
    protectedAnimal = protectedAnimal1;
}

Animal::Animal() {
}

void Animal::setLimbNr(int limbNr1) {
    limbNr = limbNr1;
}

int Animal::getLimbNr() {
    return limbNr;
}

void Animal::setName(string name1) {
    name = name1;
}

string Animal::getName() {
    return name;
}

void Animal::setProtectedAnimal(bool protectedAnimal1) {
    protectedAnimal = protectedAnimal1;
}

bool Animal::getProtectedAnimal() {
    return protectedAnimal;
}

void Animal::giveVoice() {
    cout << "Glos zwierzecia" << endl;
}

void Animal::info() {
    cout << "Liczba konczyn: " << limbNr << " nazwa: " << name << " chroniony: " << protectedAnimal << endl;
}