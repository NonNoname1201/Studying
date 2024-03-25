#ifndef LAB_4_CITIZEN_H
#define LAB_4_CITIZEN_H

#include <iostream>
#include <string>

using namespace std;

/*Stwórz klasę Citizen, która będzie reprezentowała mieszkańca i będzie zawierać następujące
pola oraz metody:
• pola prywatne: name, surname typu string, age typu int, sex typu char oraz postal_code
typu string;
• konstruktory: bezargumentowy oraz pozwalający na inicjalizację pól klasy;
• metodę show wyświetlającą informację o mieszkańcu;
• odpowiednie gettery do pól.
W zadaniu można używać algorytmów z biblioteki STL.*/

class Citizen
{
private:
    string name;
    string surname;
    int age;
    char sex;
    string postal_code;

public:
    Citizen();
    Citizen(string, string, int, char, string);
    void show();
    string getName();
    string getSurname();
    int getAge();
    char getSex();
    string getPostalCode();
};

#endif // LAB_4_CITIZEN_H
