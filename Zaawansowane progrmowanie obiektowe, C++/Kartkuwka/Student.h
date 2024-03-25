//
// Created by User on 08.12.2023.
//

#ifndef KARTKUWKA_STUDENT_H
#define KARTKUWKA_STUDENT_H

#include <iostream>
#include <string>

using namespace std;

/*Klasa student zawiera 4 pola: imię, nazwisko, numer indeksu oraz płeć.*/

class Student
{
public:
    string imie;
    string nazwisko;
    int indeks;
    string plec;

public:
    Student(string imie, string nazwisko, int indeks, string plec);
    void show() const;
    string getNazwisko() const;
    string getPlec() const;
    int getIndeks() const;
    void setIndeks(int indeks);
    void setPlec(string plec);
    void setNazwisko(string nazwisko);
};

#endif // KARTKUWKA_STUDENT_H
