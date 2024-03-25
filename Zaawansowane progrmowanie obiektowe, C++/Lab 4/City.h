#ifndef LAB_4_CITY_H
#define LAB_4_CITY_H

/*Stwórz klasę City, która będzie zawierać następujące pola oraz metody:
• pola prywatne: citizens - wektor przechowujący mieszkańców – obiekty z klasy Citizen,
city_name – nazwa miasta;
• konstruktor inicjalizujący nazwę miejscowości;
• metodę addCitizen, która umożliwia dodanie mieszkańca do miejscowości. Metoda ma
przyjąć obiekt klasy Citizen;
• metodę deleteCitizen, która usuwa mieszkańca o podanym nazwisku i wieku.
Zakładamy, że połączenie nazwiska i wieku jest unikatowe. Nazwisko oraz wiek
powinny zostać przekazane jako argumenty metody;
• metodę show_citizens, która wyświetla wszystkich mieszkańców miasta;
• metodę show_city, która wyświetla informację o nazwie miasta;
• metodę women(), która zwraca liczbę kobiet w mieście;
• metodę city_citizens(), która zwraca liczbę mieszkańców w mieście;
• metodę adults(), która zwraca liczbę pełnoletnich mieszkańców miasta;
• metodę postal_codes(), metoda wyświetla statystykę kodów pocztowych swoich
mieszkańców, np. : „20-389 -> 3 mieszkańców, 30-678 -> 10 mieszkańców” oraz
zwraca liczbę unikatowych kodów pocztowych;
Podpowiedź. Nie wiadomo ile jest unikatowych kodów, więc można stworzyć klasę
pomocniczą przechowując kod pocztowy oraz liczbę mieszkańców i odpowiednio zwiększać
liczbę mieszkańców. Obiekty tej klasy należy przechowywać w kontenerze. W ramach
ćwiczenia wybierz inny kontener niż wektor.
*/

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include "Citizen.h"
#include "PostalIndex.h"

using namespace std;

class City
{
private:
    vector<Citizen> citizens;
    unordered_map<int, PostalIndex> postalIndex;

    string city_name;

public:
    City(string);
    void addCitizen(Citizen);
    void deleteCitizen(string, int);
    void show_citizens();
    string show_city();
    int women();
    int city_citizens();
    int adults();
    int getCitizensInPostalCode(string);

    void showPostalIndex();
};

#endif // LAB_4_CITY_H
