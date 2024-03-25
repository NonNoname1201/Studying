#ifndef UNTITLED_CONTACT_H
#define UNTITLED_CONTACT_H

/*Zadanie 6.2. Książka teleadresowa
Książka telefoniczna powinna zostać zaimplementowana w oparciu o MultiIndex z biblioteki
Boost. Należy stworzyć klasę Contact, która będzie przechowywała informację o jednym
kontakcie telefonicznym. Informacje, które powinny być przechowywane to: imię i nazwisko,
wiek, numer telefonu – wartość unikatowa oraz ulica.
Następnie należy stworzyć klasę Contacts, która będzie umożliwiała:
• przechowywanie książki teleadresowej;
• dodanie nowego kontaktu do książki teleadresowej. Jeśli podany numer telefonu
znajduje się w książce, nie należy go dodawać;
• usunięcie kontaktu z książki o podanym numerze telefonu;
• wyszukanie wszystkich osób mieszkających na tej samej ulicy;
• wyszukanie osób z podanego przedziału wiekowego;
• wyszukanie osoby po numerze telefonu;
• zmiana nazwy ulicy dla wszystkich osób mieszkających przy danej ulicy;
• policzenie ile osób w książce telefonicznej, które są pełnoletnie;
• policzenie ile unikatowych nazwisk znajduje się w książce;
• wyświetlenie zawartości książki teleadresowej.
W funkcji main należy przetestować stworzone klasy.
*/

#include <boost/multi_index_container.hpp>
#include <boost/multi_index/hashed_index.hpp>
#include <boost/multi_index/member.hpp>
#include <iostream>
#include <string>

using namespace boost::multi_index;
using namespace std;

class Contact
{
public:
    string name;
    string surname;
    int age;
    string phone;
    string street;

public:
    Contact(string name, string surname, int age, string phone, string street)
    {
        this->name = name;
        this->surname = surname;
        this->age = age;
        this->phone = phone;
        this->street = street;
    }

    string getName() const
    {
        return name;
    }

    void setName(string name)
    {
        this->name = name;
    }

    string getSurname() const
    {
        return surname;
    }

    void setSurname(string surname)
    {
        this->surname = surname;
    }

    int getAge() const
    {
        return age;
    }

    void setAge(int age)
    {
        this->age = age;
    }

    string getPhone() const
    {
        return phone;
    }

    void setPhone(string phone)
    {
        this->phone = phone;
    }

    string getStreet() const
    {
        return street;
    }

    void setStreet(string street) {
        this->street = street;
    }
};

#endif // UNTITLED_CONTACTS_H