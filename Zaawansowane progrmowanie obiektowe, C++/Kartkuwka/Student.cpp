//
// Created by User on 08.12.2023.
//

#include "Student.h"

Student::Student(string imie, string nazwisko, int indeks, string plec)
{
    this->imie = imie;
    this->nazwisko = nazwisko;
    this->indeks = indeks;
    this->plec = plec;
}

void Student::show() const
{
    cout << "imie: " << imie << "\tnazwisko: " << nazwisko << "\tindeks: " << indeks << "\tplec: " << plec << endl;
}

string Student::getNazwisko() const
{
    return nazwisko;
}

string Student::getPlec() const
{
    return plec;
}

int Student::getIndeks() const
{
    return indeks;
}

void Student::setIndeks(int indeks)
{
    this->indeks = indeks;
}

void Student::setPlec(string plec)
{
    this->plec = plec;
}

void Student::setNazwisko(string nazwisko)
{
    this->nazwisko = nazwisko;
}
