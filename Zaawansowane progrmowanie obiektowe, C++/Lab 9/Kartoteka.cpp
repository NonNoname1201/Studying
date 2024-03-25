//
// Created by User on 08.12.2023.
//

#include "Kartoteka.h"

Kartoteka::Kartoteka(string sciezka)
{
    this->sciezka = sciezka;
    string imie, nazwisko, plec, ocena, email;
    int temp;
    plik.open(sciezka, ios::in);
    if (plik.good())
    {
        string linia;
        while (getline(plik, linia))
        {
            stringstream ss(linia);
            getline(ss, imie, ';');
            getline(ss, nazwisko, ';');
            getline(ss, plec, ';');
            getline(ss, ocena, ';');
            getline(ss, email, ';');
            try
            {
                if (stoi(ocena) < 2 || stoi(ocena) > 5)
                {
                    throw "Niepoprawne dane oceny";
                }
                temp = stoi(ocena);
            }
            catch (const exception e)
            {
                cout << e.what() << endl;

                temp = -1;
            }
            studenci.push_back(Student(imie, nazwisko, plec, temp, email));
        }
    }
    plik.close();
}

void Kartoteka::menu()
{
    int wybor;
    do
    {
        cout << "1. Wyswietl" << endl;
        cout << "2. Dodaj" << endl;
        cout << "3. Wyswietl nazwisko" << endl;
        cout << "4. Zapisz" << endl;
        cout << "5. Wyswietl X" << endl;
        cout << "6. Sortuj" << endl;
        cout << "7. Wyjscie" << endl;
        cin >> wybor;
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(256, '\n');
            cout << "Niepoprawny wybor" << endl;
            continue;
        }
        switch (wybor)
        {
        case 1:
            wyswietl();
            break;
        case 2:
            dodaj();
            break;
        case 3:
            wyswietlNazwisko();
            break;
        case 4:
            zapisz();
            break;
        case 5:
            wyswietlX();
            break;
        case 6:
            sortuj();
            break;
        case 7:
            break;
        default:
            cout << "Nie ma takiej opcji" << endl;
            break;
        }
    } while (wybor != 7);
}

void Kartoteka::wyswietl()
{
    cout << setw(20) << left << "Imie" << setw(20) << left << "Nazwisko" << setw(20) << left << "Plec" << setw(20)
         << left << "Ocena" << setw(20) << left << "Email" << endl;
    for (Student student : studenci)
    {
        cout << setw(20) << left << student.getImie() << setw(20) << left << student.getNazwisko() << setw(20) << left
             << student.getPlec() << setw(20) << left << student.getOcena() << setw(20) << left << student.getEmail()
             << endl;
    }
}

void Kartoteka::dodaj()
{
    string imie, nazwisko, plec, email;
    int ocena;
    cout << "Podaj imie: ";
    cin >> imie;
    cout << "Podaj nazwisko: ";
    cin >> nazwisko;
    cout << "Podaj plec: ";
    cin >> plec;
    cout << "Podaj ocene: ";
    cin >> ocena;
    if (ocena < 2 || ocena > 5)
    {
        cout << "Niepoprawna ocena" << endl;
        return;
    }
    if (cin.fail())
    {
        cin.clear();
        cin.ignore(256, '\n');
        cout << "Niepoprawna ocena" << endl;
        return;
    }
    cout << "Podaj email: ";
    cin >> email;
    studenci.push_back(Student(imie, nazwisko, plec, ocena, email));
}

void Kartoteka::wyswietlNazwisko()
{
    string nazwisko;
    cout << "Podaj nazwisko: ";
    cin >> nazwisko;
    for (Student student : studenci)
    {
        if (student.getNazwisko() == nazwisko)
        {
            cout << student.toString() << endl;
        }
    }
}

void Kartoteka::zapisz()
{
    plik.open(sciezka, ios::out | ios::app);
    for (Student student : studenci)
    {
        plik << student.toString() << endl;
    }
    plik.close();
}

void Kartoteka::wyswietlX()
{
    int x;
    cout << "Podaj X: ";
    cin >> x;
    if (x > studenci.size())
    {
        cout << "Za malo studentow" << endl;
        return;
    }
    for (int i = 0; i < x; i++)
    {
        cout << studenci[i].toString() << endl;
    }
}

void Kartoteka::sortuj()
{
    sort(studenci.begin(), studenci.end(), [](Student a, Student b)
         { return a.getOcena() < b.getOcena(); });
}

void Kartoteka::wczytaj()
{
    string imie, nazwisko, plec, email;
    string ocena;
    int temp;
    plik.open(sciezka, ios::in);
    if (plik.good())
    {
        string linia;
        while (getline(plik, linia))
        {
            stringstream ss(linia);
            getline(ss, imie, ';');
            getline(ss, nazwisko, ';');
            getline(ss, plec, ';');
            getline(ss, ocena, ';');
            getline(ss, email, ';');
            try
            {
                if (stoi(ocena) < 2 || stoi(ocena) > 5)
                {
                    throw "Niepoprawne dane oceny";
                }
                temp = stoi(ocena);
            }
            catch (const exception e)
            {
                cout << e.what() << endl;
                temp = -1;
            }
            studenci.push_back(Student(imie, nazwisko, plec, temp, email));
        }
    }
    plik.close();
}
