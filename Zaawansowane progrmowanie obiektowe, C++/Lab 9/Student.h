//
// Created by User on 08.12.2023.
//

#ifndef LAB_9_STUDENT_H
#define LAB_9_STUDENT_H

#include <iostream>

using namespace std;

class Student {
private:
    string imie;
    string nazwisko;
    string plec;
    int ocena;
    string email;
public:
    Student(string imie, string nazwisko, string plec, int ocena, string email);
    string getImie();
    string getNazwisko();
    string getPlec();
    int getOcena();
    string getEmail();
    void setImie(string imie);
    void setNazwisko(string nazwisko);
    void setPlec(string plec);
    void setOcena(int ocena);
    void setEmail(string email);
    string toString();
};


#endif //LAB_9_STUDENT_H
