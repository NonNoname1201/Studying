//
// Created by User on 08.12.2023.
//

#ifndef LAB_9_KARTOTEKA_H
#define LAB_9_KARTOTEKA_H

/*Zadanie 9.3. Kartoteka studentów
Napisz program do obsługi kartoteki studentów. Dane do zadania znajdują się w pliku
„dane.csv”, gdzie w pierwszej linijce zapisane są nagłówki poszczególnych kolumn: imię,
nazwisko, płeć, ocena oraz opcjonalnie email. W kolejnych linijkach znajdują się dane
studentów. Każda linijka zawiera informację o jednej osobie. Dane rozdzielone są między sobą
średnikiem. Użytkownik podaje ścieżkę do pliku w celu wczytania danych do programu
(książka adresowa) i ma do wyboru następujące opcje:
1. Wyświetlenie książki adresowej na konsolę w postaci tabelki bez konturów z
podziałem na imię, nazwisko, płeć, ocenę oraz ewentualnie email. Powinny zostać
zastosowane stałe odstępy (na przykład 20) między kolejnymi kolumnami, puste
miejsca powinny zostać wypełnione znakiem _;
2. Zapisanie do książki adresowej kolejnej osoby. Imię oraz nazwisko mają zaczynać się
dużą literą alfabetu, w imieniu i nazwisku mogą występować tylko litery alfabetu
łacińskiego. Płeć to K lub M, a email musi zawierać znak @. Należy obsłużyć sytuację
w której którakolwiek z danych jest niepoprawna;
3. Wyświetlenie osób o podanym nazwisku na konsolę;
4. Stworzenie plików k.csv oraz m.csv. Plik k.csv będzie zawierać dane kobiet a plik
m.csv dane mężczyzn. Należy pamiętać aby do plików dodać nagłówek;
5. Wyświetlenie X pierwszych studentów, liczbę X podaje użytkownik. Należy obsłużyć
sytuację, w której jest mniej studentów niż podana liczba X;
6. Posortowanie studentów względem oceny rosnąco;
7. Wyjście z programu.
Należy zapewnić kontrolę błędów, jakie mogą pojawić się przy wprowadzaniu danych przez
użytkownika z konsoli. Dodatkowo należy rozpatrzeć przypadek, że plik o podanej nazwie nie
istnieje.
Wczytane z pliku dane studentów należy przechowywać w wybranym przez siebie
kontenerze z biblioteki STL. Informacje o pojedynczym studencie należy przechowywać jako
obiekt klasy. Po zakończeniu programu dane wszystkich dopisanych studentów powinny zostać
dopisane do istniejącego pliku „dane.csv”.*/

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <iomanip>

#include "Student.h"

using namespace std;

class Kartoteka {
private:
    fstream plik;
    string sciezka;
    vector<Student> studenci;
public:
    Kartoteka(string sciezka);
    void menu();
    void wyswietl();
    void dodaj();
    void wyswietlNazwisko();
    void zapisz();
    void wyswietlX();
    void sortuj();
    void wczytaj();
};


#endif //LAB_9_KARTOTEKA_H
