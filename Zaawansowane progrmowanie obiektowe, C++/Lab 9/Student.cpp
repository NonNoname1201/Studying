//
// Created by User on 08.12.2023.
//

#include "Student.h"

Student::Student(string imie, string nazwisko, string plec, int ocena, string email) {
    this->imie = imie;
    this->nazwisko = nazwisko;
    this->plec = plec;
    this->ocena = ocena;
    this->email = email;
}

string Student::getImie() {
    return imie;
}

string Student::getNazwisko() {
    return nazwisko;
}

string Student::getPlec() {
    return plec;
}

int Student::getOcena() {
    return ocena;
}

string Student::getEmail() {
    return email;
}

void Student::setImie(string imie) {
    this->imie = imie;
}

void Student::setNazwisko(string nazwisko) {
    this->nazwisko = nazwisko;
}

void Student::setPlec(string plec) {
    this->plec = plec;
}

void Student::setOcena(int ocena) {
    this->ocena = ocena;
}

void Student::setEmail(string email) {
    this->email = email;
}

string Student::toString() {
    return imie + ";" + nazwisko + ";" + plec + ";" + to_string(ocena) + ";" + email;
}