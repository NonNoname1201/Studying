#include "Citizen.h"

Citizen::Citizen()
{
    name = "";
    surname = "";
    age = 0;
    sex = ' ';
    postal_code = "";
}

Citizen::Citizen(string name, string surname, int age, char sex, string postal_code)
{
    this->name = name;
    this->surname = surname;
    this->age = age;
    this->sex = sex;
    this->postal_code = postal_code;
}

string Citizen::getName()
{
    return name;
}

string Citizen::getSurname()
{
    return surname;
}

int Citizen::getAge()
{
    return age;
}

char Citizen::getSex()
{
    return sex;
}

string Citizen::getPostalCode()
{
    return postal_code;
}

void Citizen::show()
{
    cout << "Name: " << name << endl;
    cout << "Surname: " << surname << endl;
    cout << "Age: " << age << endl;
    cout << "Sex: " << sex << endl;
    cout << "Postal Code: " << postal_code << endl;
}