//
// Created by User on 24.11.2023.
//

#ifndef UNTITLED_CONTACTS_H
#define UNTITLED_CONTACTS_H

#include <boost/multi_index_container.hpp>
#include <boost/multi_index/member.hpp>
#include <boost/multi_index/hashed_index.hpp>
#include <boost/multi_index/ordered_index.hpp>
#include <iostream>
#include <set>
#include <string>

#include "Contact.h"

using namespace boost::multi_index;
using namespace std;

/*
Książka telefoniczna powinna zostać zaimplementowana w oparciu o MultiIndex z biblioteki
Boost.
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

typedef multi_index_container<
    Contact,
    indexed_by<
        hashed_unique<
            member<Contact, string, &Contact::phone>>,
        ordered_non_unique<
            member<Contact, std::string, &Contact::street>>,
        ordered_non_unique<
            member<Contact, int, &Contact::age>>>>
    ContactsContainer;

typedef multi_index_container <
        student,
        indexed_by<
        ordered_non_unique<
                member<student, string, &student::nazwisko>>,
        ordered_unique<
                member<student, int, &student::indeks>>>>
                student_multi;

class Contacts
{
private:
    ContactsContainer contacts;

public:
    void addContact(Contact contact)
    {
        if (contacts.find(contact.getPhone()) == contacts.end())
        {
            contacts.insert(contact);
        }
    }

    void removeContact(const std::string &phone)
    {
        auto &phone_index = contacts.get<0>();
        phone_index.erase(phone);
    }

    void findContactsByStreet(string street)
    {
        auto &index = contacts.get<1>();
        auto iterator = index.find(street);
        while (iterator != index.end() && iterator->getStreet() == street)
        {
            cout << iterator->getName() << " " << iterator->getSurname() << " " << iterator->getAge() << " "
                 << iterator->getPhone() << " " << iterator->getStreet() << endl;
            iterator++;
        }
    }

    void findContactsByAge(int ageLowerBound, int ageUpperBound)
    {
        auto &index = contacts.get<2>();
        auto iterator = index.find(ageLowerBound);
        while (iterator != index.end() && iterator->getAge() <= ageUpperBound)
        {
            cout << iterator->getName() << " " << iterator->getSurname() << " " << iterator->getAge() << " "
                 << iterator->getPhone() << " " << iterator->getStreet() << endl;
            iterator++;
        }
    }

    void findContactByPhone(string phone)
    {
        auto &index = contacts.get<0>();
        auto iterator = index.find(phone);
        if (iterator != index.end())
        {
            cout << iterator->getName() << " " << iterator->getSurname() << " " << iterator->getAge() << " "
                 << iterator->getPhone() << " " << iterator->getStreet() << endl;
        }
    }

    void changeStreetName(string oldStreetName, string newStreetName)
    {
        auto &index = contacts.get<1>();
        auto iterator = index.find(oldStreetName);
        while (iterator != index.end() && iterator->getStreet() == oldStreetName)
        {
            auto &index = contacts.get<1>(); // Assuming the 1st index is by street
            auto iterator = index.find(oldStreetName);
            if (iterator != index.end())
            {
                Contact modifiedContact = *iterator;      // Copy the existing contact
                modifiedContact.setStreet(newStreetName); // Modify the copy
                index.replace(iterator, modifiedContact); // Replace the existing contact with the modified one
            }
            iterator++;
        }
    }

    int countAdults()
    {
        auto &index = contacts.get<2>();
        auto iterator = index.find(18);
        int counter = 0;
        while (iterator != index.end())
        {
            counter++;
            iterator++;
        }
        return counter;
    }

    int countUniqueSurnames()
    {
        std::set<std::string> uniqueSurnames;
        auto &index = contacts.get<1>();
        for (auto iterator = index.begin(); iterator != index.end(); ++iterator)
        {
            uniqueSurnames.insert(iterator->getSurname());
        }
        return uniqueSurnames.size();
    }

    void printContacts()
    {
        for (auto iterator = contacts.begin(); iterator != contacts.end(); ++iterator)
        {
            cout << iterator->getName() << " " << iterator->getSurname() << " " << iterator->getAge() << " "
                 << iterator->getPhone() << " " << iterator->getStreet() << endl;
        }
    }
};

#endif // UNTITLED_CONTACTS_H