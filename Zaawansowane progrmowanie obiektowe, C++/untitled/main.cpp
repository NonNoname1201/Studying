#include <boost/multi_index_container.hpp>
#include <boost/multi_index/hashed_index.hpp>
#include <boost/multi_index/member.hpp>
#include <iostream>
#include <string>
#include <vector>
#include "Contact.h"
#include "Contacts.h"
#include "TempF.h"
#include "Mix.h"

using namespace boost::multi_index;
using namespace std;

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

/*Zadanie 6.3. Statystyka
Napisz funkcję szablonową o parametrze T, która jako argument będzie zawierać kontener
vector typu T. Zadaniem funkcji jest wyświetlenie:
• elementów mniejszych niż średnia arytmetyczna wszystkich elementów;
• elementów znajdujących się między średnią arytmetyczna a medianą wszystkich
elementów;
• elementów dodatnich.
Można skorzystać z elementów biblioteki functional. Wykaz operatorów można znaleźć na
stronie http://www.cplusplus.com/reference/functional/ W celu przekazania argumentów do
funkcji należy użyć funkcji bind.
*/

int main()
{
    Contacts contacts;

    contacts.addContact(Contact("Jan", "Kowalski", 20, "123456789", "Kwiatowa"));
    contacts.addContact(Contact("Jana", "Kowalska", 20, "987654321", "Qwwqwwwq"));
    contacts.addContact(Contact("Januel", "Kowalski", 20, "98457344", "Kwiatowej"));
    contacts.addContact(Contact("Janor", "Kowalsczyzny", 20, "52356767", "Kwiatowa"));
    contacts.addContact(Contact("Janitor", "Kowalski", 20, "987654321", "Kwiatowej"));

    contacts.printContacts();

    cout << "---------------------" << endl;

    contacts.removeContact("123456789");

    contacts.printContacts();

    cout << "---------------------" << endl;

    contacts.findContactsByStreet("Kwiatowa");

    cout << "---------------------" << endl;

    contacts.findContactsByAge(20, 20);

    cout << "---------------------" << endl;

    contacts.findContactByPhone("987654321");

    cout << "---------------------" << endl;

    contacts.changeStreetName("Kwiatowa", "Kwiatowej");

    contacts.printContacts();

    cout << "---------------------" << endl;

    cout << "Number of adults: " << contacts.countAdults() << endl;

    cout << "---------------------" << endl;

    cout << "Number of unique surnames: " << contacts.countUniqueSurnames() << endl;

    cout << "---------------------" << endl;

    vector<int> vector;
    for (int i = 0; i < 10; i++)
    {
        vector.push_back(rand() % 100);
    }

    printVectorSmAvg(vector);
    printVectorBtwAvgMed(vector);
    printVectorPos(vector);

    cout << "---------------------" << endl;
    boost::fusion::vector<int, double, float, bool, char> fv;
    auto counts = countTypes(fv);

    for (const auto &pair : counts)
    {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }

    return 0;
}
