#include <iostream>
#include "person.h"

using namespace std;
class Student : public Person {
private:
    string index;
public:
    Student() {
        cout << "Konstruktor bez. klasy pochodnej – Student" << endl;
    }

    Student(string name1, string surname1, int age1, string index1) : Person(name1, surname1, age1) {
        index = index1;
        cout << "Konstruktor klasy pochodnej - Student" << endl;
    }

    void setIndex(string newIndex) {
        index = newIndex;
    }

    string getIndex() {
        return index;
    }

    void showInfoStudent() {
        cout << "Imie: " << name << " nazwisko: " << surname << "wiek: " << age << " index: " << index << endl;
    }
};
