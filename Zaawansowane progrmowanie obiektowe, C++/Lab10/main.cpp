#include <iostream>
#include <regex>
#include <string>
#include <fstream>
#include <map>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

/*Zadanie 10.1. Liczba zmiennoprzecinkowa
Zdefiniuj wyrażenie regularne, które pozwoli na sprawdzenie czy w danym łańcuchu znaków
znajduje się liczba zmiennoprzecinkowa ze znakiem (liczba całkowita od części ułamkowej
oddzielona jest kropką, np. +6.789, -7.234). W funkcji main należy przetestować stworzone
wyrażenia regularne.*/

/*Zadanie 10.2. Godzina
Zdefiniuj wyrażenie regularne do rozpoznawania godziny. Zakładamy, że zapis godziny jest
następujący: hh:mm:ss lub hh:mm, gdzie hh to godziny (0-23), mm - liczba minut (0-59), ss – to
liczba sekund (0-59). Podawanie sekund jest opcjonalne. Liczby (hh,mm,ss) zawsze zapisane
są za pomocą dwóch cyfr. W funkcji main należy przetestować stworzone wyrażenia regularne.
*/

/*Zadanie 10.3. Adres zamieszkania
Zdefiniuj wyrażenia regularne pozwalające na sprawdzenie:
• ulicy (nazwa może składać się tylko z liter alfabetu łacińskiego oraz znaku spacji);
• kodu pocztowego (w formacie XX-XXX, gdzie X to cyfra);
• numeru domu (liczba lub liczba i litera, np. 28, 28B);
• numer mieszkania
W funkcji main należy przetestować stworzone wyrażenia regularne.*/

/*Zadanie 10.4. Kartoteka
Zdefiniuj wyrażenia regularne pozwalające na sprawdzenie:
• imienia (imię może składać się tylko z liter alfabetu łacińskiego);
• nazwisko (nazwisko może składać się z liter alfabetu łacińskiego oraz myślnika przy
nazwiskach łączonych, na przykład: Nowak-Kowalska);
• wieku (liczba od 0 do 99);
• numeru telefonu komórkowego (numer telefonu składa się z 9 cyfr, przy czym pierwsza
cyfra nie może być 0);
• emaila (email postaci u@x.y, gdzie u to nazwa użytkownika, która może składać się
z liter alfabetu łacińskiego, cyfr oraz znaków: podkreślenie, myślnik, kropka oraz nie
może zaczynać się od cyfry, znaku podkreślenia, kropki oraz myślnika, x.y to nazwa
domeny, która może składać się z liter alfabetu łacińskiego oraz cyfr);
Napisz program, który będzie wczytywał od użytkownika: imię, nazwisko, wiek, numer
telefonu komórkowego oraz email i sprawdzał za pomocą zdefiniowanych wyrażeń
regularnych czy podane dane są prawidłowe. Jeśli użytkownik podał prawidłowe dane to należy
zapisać je do pliku. Jeśli plik istnieje to dane należy dopisać na koniec. W jednej linijce powinna
zostać zapisana informacja o jednej osobie, gdzie dane powinny zostać rozdzielone średnikiem.*/

/*Zadanie 10.5. Statystyka
Wykorzystaj plik stworzony w zadaniu 10.4. i na jego podstawie wyświetl następujące
informacje:
• nazwy unikatowych domen;
• numery telefonów, które kończą się liczbą parzystą;
• nazwiska łączone;
• statystykę imion (imię + liczba wystąpień).*/

void Zadanie_10_1()
{
    regex liczba_zm("([+-]?[0-9]+\\.[0-9]+)");
    string s;
    while (true)
    {
        cout << "Podaj liczbe zmiennoprzecinkowa: ";
        cin >> s;
        if (regex_search(s, liczba_zm))
            cout << "Liczba zmiennoprzecinkowa poprawna" << endl;
        else
            cout << "Liczba zmiennoprzecinkowa niepoprawna" << endl;
    }
}

void Zadanie_10_2()
{
    regex godzina("([01][0-9]|2[0-3]):[0-5][0-9](:[0-5][0-9])?");
    string s;
    while (true)
    {
        cout << "Podaj godzine: ";
        cin >> s;
        if (regex_match(s, godzina))
            cout << "Godzina poprawna" << endl;
        else
            cout << "Godzina niepoprawna" << endl;
    }
}

void Zadanie_10_3()
{
    regex ulica("[a-zA-Z ]+");
    regex kod_pocztowy("[0-9]{2}-[0-9]{3}");
    regex numer_domu("[0-9]+[a-zA-Z]?");
    regex numer_mieszkania("[0-9]+");
    string s;
    while (true)
    {
        cout << "Podaj ulice: ";
        cin >> s;
        if (regex_match(s, ulica))
            cout << "Ulica poprawna" << endl;
        else
            cout << "Ulica niepoprawna" << endl;
        cout << "Podaj kod pocztowy: ";
        cin >> s;
        if (regex_match(s, kod_pocztowy))
            cout << "Kod pocztowy poprawny" << endl;
        else
            cout << "Kod pocztowy niepoprawny" << endl;
        cout << "Podaj numer domu: ";
        cin >> s;
        if (regex_match(s, numer_domu))
            cout << "Numer domu poprawny" << endl;
        else
            cout << "Numer domu niepoprawny" << endl;
        cout << "Podaj numer mieszkania: ";
        cin >> s;
        if (regex_match(s, numer_mieszkania))
            cout << "Numer mieszkania poprawny" << endl;
        else
            cout << "Numer mieszkania niepoprawny" << endl;
    }
}

void Zadanie_10_4(string fileName)
{
    regex imie("[a-zA-Z]+");
    regex nazwisko("[a-zA-Z]+(-[a-zA-Z]+)?");
    regex wiek("[0-9]{1,2}");
    regex telefon("[1-9][0-9]+");
    regex email("[a-zA-Z][a-zA-Z0-9_.-]*@[a-zA-Z0-9_.-]+\\.[a-zA-Z]{2,3}");
    string s;
    string dane;
    fstream file = fstream(fileName, ios::out | ios::app);

    while (true)
    {
        bool poprawne = true;
        cout << "Podaj imie: ";
        cin >> s;
        if (regex_match(s, imie))
        {
            cout << "Imie poprawne" << endl;
            dane += s + ";";
        }
        else
        {
            cout << "Imie niepoprawne" << endl;
            poprawne = false;
        }
        cout << "Podaj nazwisko: ";
        cin >> s;
        if (regex_match(s, nazwisko))
        {
            cout << "Nazwisko poprawne" << endl;
            dane += s + ";";
        }
        else
        {
            cout << "Nazwisko niepoprawne" << endl;
            poprawne = false;
        }
        cout << "Podaj wiek: ";
        cin >> s;
        if (regex_match(s, wiek))
        {
            cout << "Wiek poprawny" << endl;
            dane += s + ";";
        }
        else
        {
            cout << "Wiek niepoprawny" << endl;
            poprawne = false;
        }
        cout << "Podaj numer telefonu: ";
        cin >> s;
        if (regex_match(s, telefon))
        {
            cout << "Numer telefonu poprawny" << endl;
            dane += s + ";";
        }
        else
        {
            cout << "Numer telefonu niepoprawny" << endl;
            poprawne = false;
        }
        cout << "Podaj email: ";
        cin >> s;
        if (regex_match(s, email))
        {
            cout << "Email poprawny" << endl;
            dane += s + ";";
        }
        else
        {
            cout << "Email niepoprawny" << endl;
            poprawne = false;
        }

        if (poprawne)
        {
            cout << "Dane poprawne" << endl;
            file << dane << ";\n";
            file.close();
            break;
        }
        else
        {
            cout << "Dane niepoprawne" << endl;
        }
    }
}

void Zadanie_10_5(string fileName)
{
    regex domena("[a-zA-Z0-9_.-]+\\.[a-zA-Z]{2,3}");
    regex telefon("[1-9][0-9]+[02468]");
    regex nazwisko("[a-zA-Z]+-[a-zA-Z]+");
    regex imie("[a-zA-Z]+");
    regex dane(
        "([a-zA-Z]+);([a-zA-Z]+);([0-9]{1,2});([1-9][0-9]{8}[02468]);([a-zA-Z][a-zA-Z0-9_.-]*@[a-zA-Z0-9_.-]+\\.[a-zA-Z]{2,3})");
    string s;
    fstream file = fstream(fileName, ios::in);

    set<string> domeny;
    set<string> telefony;
    set<string> nazwiska;
    map<string, int> imiona;

    smatch match;

    while (getline(file, s))
    {
        // find all domains
        if (regex_search(s, match, domena))
        {
            domeny.insert(match[0].str());
        }
        // find all phone numbers ending with even number
        if (regex_search(s, match, telefon))
        {
            telefony.insert(match[0].str());
        }
        // find all surnames with dash
        if (regex_search(s, match, nazwisko) && match[0].str().find('-') != string::npos)
        {
            nazwiska.insert(match[0].str());
        }
        // find all names
        if (regex_search(s, match, imie))
        {
            imiona[match[0].str()]++;
        }
    }

    cout << "Domeny: ";
    for (auto domena : domeny)
    {
        cout << domena << " ";
    }
    cout << endl;

    cout << "Telefony: ";
    for (auto telefon : telefony)
    {
        cout << telefon << " ";
    }
    cout << endl;

    cout << "Nazwiska: ";
    for (auto nazwisko : nazwiska)
    {
        cout << nazwisko << " ";
    }
    cout << endl;

    cout << "Imiona: ";
    for (auto imie : imiona)
    {
        cout << imie.first << " (" << imie.second << ") ";
    }
    cout << endl;
}

void cutFromString(string &s, regex r)
{
    smatch match;
    string result;
//    while (regex_search(s, match, r))
//    {
//        s = match.prefix().str() + match.suffix().str();
//    }
//using boost
    s = regex_replace(s, r, "");

}

void getAllMatches(string s, regex r)
{
    smatch match;
    string result;

    while (regex_search(s, match, r))
    {
        result += match[0].str() + " ";
        s = match.suffix().str();
    }
    cout << result << endl;
}

int main()
{
    // Zadanie_10_4("dane.txt");
    // Zadanie_10_5("dane.txt");
    string s = "Al1a1123421 ma1234324 kot2131a";
    regex r = regex ("[0-9]");
    cutFromString(s, r);
    cout << s << endl;
    //getAllMatches(s, r);

    return 0;
}
