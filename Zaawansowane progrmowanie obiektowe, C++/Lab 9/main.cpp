/*
 Biblioteka
iostream zawiera definicję czterech strumieni:
• cin – standardowy strumień wejściowy;
• cout – standardowy strumień wyjściowy;
• cerr – standardowy strumień komunikatach o błędach (niebuforowany);
• clog – standardowy strumień komunikatach o błędach (buforowany).

• get – czytanie jednego bajtu. Jeśli czytanie nie powiodło się to zostanie zwrócony znak
końca EOF;
• getline – czytanie do przekazanego bufora całej linijki, domyślnie do końca linijki (ale
bez znaku końca). Można również określić rozmiar bufora i znak do którego ma się
odbywać czytanie;
• read – umożliwia przeczytanie określonej liczby bajtów do bufora. Używana jest
głównie do plików binarnych;
• ignore – wczytuje określoną liczbę znaków, domyślnie jeden, i nigdzie ich nie zapisuje;
• put – wstawia znak do strumienia;
• write – umożliwia zapis określonej liczby bajtów do strumienia. Używana jest głównie
do plików binarnych;

Do manipulatorów bezargumentowych należą między innymi:
• hex, oct, dec – umożliwiają wyświetlenie liczby w systemie 16,8 lub 10;
• left, internal, right – umożliwiają wyrównanie do lewej, środka i prawej strony;
• scientific – umożliwiają wyświetlenie liczby w postaci naukowej;
• endl – wysłanie do strumienia wyjściowego znaku końca linii;
• showbase, noshowbase – umożliwiają wyświetlenie liczby z podstawą (0 lub 0x)
• showpos – umożliwiają wyświetlenie liczby dodatniej ze znakiem +;
Z kolei do manipulatorów argumentowych należą między innymi:
• setw – umożliwia ustawienie szerokości pola dla najbliższej operacji w strumieniu;
• setfill – umożliwia ustawienie znaku, którym będą wypełnione puste miejsca, jeśli
szerokość pola jest większa niż liczba znaków;
• setprecision – umożliwia ustawienie precyzji;
• setiosflags – ustawienie flagi;
• resetiosflags – wyłączenie flagi.

Strumienie napisowe umożliwiają wykonywanie operacji na napisach traktując je jak
strumienie. Strumienie napisowe tworzą trzy klasy:
• ostringstream – strumień umożliwiający zapis;
• istringstream – strumień umożliwiający odczyt;
• stringstream – strumień umożliwiający zapis i odczyt.

Plik można otworzyć, określając tryb
otwarcia, na przykład:
• ios::in – odczyt ze strumienia;
• ios::out – zapis do strumienia. Jeśli pliku nie ma, zostanie utworzony nowy,
w przeciwnym wypadku zawartość pliku zostanie nadpisana;
• ios::app – zapis do strumienia dołączając do istniejącej zawartości
*/

#include <iostream>
#include <fstream>

#include "Kartoteka.h"

using namespace std;

/*Zadanie 9.1. Kod programu
Napisz program, który wyświetli kod programu w języku C++ usuwając komentarze, które
są poprzedzone // wraz z tymi znakami. Aby usunąć komentarze można użyć metody ignore.
Należy skorzystać z pliku kod.txt. W programie należy obsłużyć sytuację, kiedy plik nie będzie
istniał poprzez złapanie odpowiedniego wyjątku.
Podpowiedź: Metoda peek umożliwia podgląd kolejnego znaku. Można ją użyć aby
sprawdzić czy występują po sobie dwa znaki //.*/

void Zadanie1()
{
    ifstream file("../main.cpp");
    if (!file.is_open())
    {
        cout << "File not found" << endl;
        return;
    }
    char c;
    while (file.get(c))
    {
        if (c == '/')
        {
            if (file.peek() == '/')
            {
                file.ignore(256, '\n');
                cout << endl;
                continue;
            }
        }
        cout << c;
    }
    file.close();
}

/*Zadanie 9.2. Oczko
Napisz program, w którym użytkownik będzie podawał dodatnią liczbę całkowitą do
momentu aż suma podanych przez użytkownika liczb będzie mniejsza niż oczko (21). Jeśli
suma będzie równa 21 wtedy należy wyświetlić odpowiedni komunikat i zakończyć program.
Jeśli suma przekroczy 21 należy rzucić wyjątek informujący, że suma została przekroczona.
Wyjątek należy obsłużyć umożliwiając ponowne podanie ostatniej liczby. W programie
powinna zostać obsłużona sytuacja, kiedy użytkownik zamiast liczby podaje inny typ danych.
Wtedy użytkownik powinien zostać poproszony o ponowne podanie liczby. Program powinien
wyświetlić po ilu próbach (udanych i nieudanych) udało się osiągnąć oczko.*/

void Zadanie2()
{
    int oczko = 21;
    int suma = 0;
    int liczba;
    int proba = 0;
    while (suma != oczko)
    {
        cout << "Podaj liczbe: ";
        cin >> liczba;
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(256, '\n');
            cout << "Podaj liczbe!" << endl;
            continue;
        }
        try{
            suma += liczba;
            proba++;
            if (suma == oczko)
            {
                cout << "Oczko!" << endl;
            }
            else if(suma > oczko)
            {
                throw "Suma przekroczona!";
            }
        }
        catch (const char* msg)
        {
            cout << msg << endl;
            continue;
        }

    }

    cout << "Proba: " << proba << endl;
}


int main()
{
    Kartoteka kartoteka("../dane.csv");
    kartoteka.menu();
    return 0;
}
