#include <iostream>
#include <cstdlib>
#include "zlab02.h"
#include "zlab03.h"
#include "organizm.h"
#include "ustawienia.h"
#include "generatorlosowy.h"
#include "sasiedztwo.h"
#include "zlab06.h"
#include "nisza.h"
#include "osobniki.h"
#include "zlab09.h"

using namespace std;


int main(){
    ZLab09 z;
    //z.rozmiary();
    //z.skalar();
    //z.tablica1D();
    //z.tablica2D(4,6);
    z.referencja();
}



//int main(){

//Nisza nisza;
//nisza.przyjmijLokatora(new Bakteria());

//cout << "Kto w niszy: "
//<< nisza.ktoTuMieszka() << endl;
//cout << "Czy żywy: "
//<< nisza.lokatorZywy() << endl;

//Sasiedztwo sasiedztwo;
//sasiedztwo.okreslSasiada(P,GLON);
//sasiedztwo.okreslSasiada(PG,GRZYB);
//sasiedztwo.okreslSasiada(G,GRZYB);
//sasiedztwo.okreslSasiada(LG,GLON);
//sasiedztwo.okreslSasiada(L,BAKTERIA);
//sasiedztwo.okreslSasiada(LD,BAKTERIA);
//sasiedztwo.okreslSasiada(D,GLON);
//sasiedztwo.okreslSasiada(PD,PUSTKA);

//ZamiarMieszkanca* zamiar = new ZamiarMieszkanca(NIC, NIGDZIE);
////nisza.aktywujLokatora(sasiedztwo);

//cout << "Akjca: " << zamiar->akcja << " gdzie: "
//<< zamiar->gdzie << endl;

//cout << endl;
//return 0;
//}


//static Nisza n1, n2, n3;
//static char sep = UstawieniaSymulacji::
//pobierzUstawienia().znakSeparator;

//void wyswietlNisze()
//{
//cout << n1.jakiSymbol() << sep
//<< n2.jakiSymbol() << sep
//<< n3.jakiSymbol() << endl;
//}

//int main()
//{
//    cout << "Puste nisze: ";
//    wyswietlNisze();

//    cout << "Lokowanie mieszkańców: ";
//    n1.przyjmijLokatora(new Glon());
//    n3.przyjmijLokatora(new Grzyb());
//    wyswietlNisze();

//    cout << "Przesuwanie lokatorów: ";
//    n2 = n1;
//    wyswietlNisze();

//    cout << "Przesuwanie lokatorów:";
//    n3 = n2;
//    wyswietlNisze();

//    cout << endl;
//    return 0;
//}

//Kwadrat kwadrat("Kwadrek",4);

//Kwadrat & refDoKwadrat = kwadrat;

//double r0 = refDoKwadrat.promienKolaWgPola();
//double r1 = refDoKwadrat.promenOkreguWgObwodu();

//cout << "ro=" << r0 << endl
//<< "r1=" << r1 << endl;

//return 0;
//}

////void drukujOrganizm(const Organizm & o)
////{
////    cout << "licznikZycia: "
////    << o.stanLicznikaZycia()
////    << " licznikPosilkow: "
////    << o.stanLicznikaPosilkow() << endl
////    << "limitPosilkow: "
////    << o.limitPosilkow
////    << " kosztPotomka: "
////    << o.kosztPotomka << endl
////    << "głodny: " << o.glodny()
////    << " pączkujący: "
////    << o.paczkujacy() << endl << endl;
////}

////void wyswietl(UstawieniaSymulacji & UST){
////cout << "Znak glon:" << UST.znakGlon
////<< " zycieMin=" << UST.glonZycieMin
////<< " zycieMax=" << UST.glonZycieMax << endl;
////}

////string nazwaRodzaju(RodzajMieszkanca rodzaj){
////    switch (rodzaj) {
////        case GLON: return "GLON";
////        case GRZYB: return "GRZYB";
////        case BAKTERIA: return "BAKTERIA";
////        case PUSTKA: return "PUSTKA";
////        case SCIANA: return "ŚCIANA";
////        case TRUP: return "TRUP";
////        case NIEZNANE: return "NIEZNANE";
////    }
////}

////int main()
////{
////    Sasiedztwo sasiedztwo;

////    sasiedztwo.okreslSasiada(P,GLON);
////    sasiedztwo.okreslSasiada(PG,GRZYB);
////    sasiedztwo.okreslSasiada(G,GRZYB);
////    sasiedztwo.okreslSasiada(LG,GLON);
////    sasiedztwo.okreslSasiada(L,BAKTERIA);
////    sasiedztwo.okreslSasiada(LD,BAKTERIA);
////    sasiedztwo.okreslSasiada(D,GLON);
////    sasiedztwo.okreslSasiada(PD,PUSTKA);

////    cout << "Przegląd sąsiedztwa:" << endl;

////    for(int i=0; i<8; i++){

////    Polozenie p = static_cast<Polozenie>(i);

////    RodzajMieszkanca  r = sasiedztwo.ktoJestSasiadem(p);

////    cout << "polozenie=" << p << " rodzaj="
////    << nazwaRodzaju(r) << endl;
////    }

////    cout << endl << "Policzenie sasiadów"
////    << "określonego rodzaju:" << endl
////    << " glony=" << sasiedztwo.ile(GLON) << endl
////    << " grzyby=" << sasiedztwo.ile(GRZYB) << endl
////    << " trupy=" << sasiedztwo.ile(TRUP) << endl;

////    cout << endl << "Wylosowanie sasiada:" << endl
////    << " glon -> "
////    << sasiedztwo.losujSasiada(GLON) << endl
////    << " pustka -> "
////    << sasiedztwo.losujSasiada(PUSTKA) << endl
////    << " trup -> "
////    << sasiedztwo.losujSasiada(TRUP) << endl;


////    long wiersz, kolumna;
////    cout << endl
////    << "Zmiana indeksów [5][7]"
////    << "wg polozenia:" << endl;

////    for(int i=0; i<8; i++){

////    Polozenie p = static_cast<Polozenie>(i);
////    wiersz = 5; kolumna = 7;

////    Sasiedztwo::
////    zmienIdeksyWgPolozenia(p,wiersz,kolumna);

////    cout << " położenie: " << p << " ->[" << wiersz
////    << "][" << kolumna << "]" << endl;
////    }

////    cout << endl;







//////    UstawieniaSymulacji & UST1
//////    = UstawieniaSymulacji::pobierzUstawienia();
//////    UstawieniaSymulacji & UST2
//////    = UstawieniaSymulacji::pobierzUstawienia();
//////    UstawieniaSymulacji & UST3
//////    = UstawieniaSymulacji::pobierzUstawienia();

//////    cout << "Pobranie ustawien 3x" << endl;
//////    cout << "UST1: "; wyswietl(UST1);
//////    cout << "UST2: "; wyswietl(UST2);
//////    cout << "UST3: "; wyswietl(UST3);

//////    cout << endl << "Zmiana wartości tylko 1x" << endl;
//////    UST2.glonZycieMax = 100;
//////    cout << "UST1: "; wyswietl(UST1);
//////    cout << "UST2: "; wyswietl(UST2);
//////    cout << "UST3: "; wyswietl(UST3);

//////    cout << "\n\n";

//////    cout << "Liczby losowe typu int:" << endl;
//////    cout << " od 0 do 5: ";
//////    for(int i=0; i<10; i++)
//////    cout << GEN::losujOdZeraDo(5) << " ";
//////    cout << endl << " od 0 do 3: ";
//////    for(int i=0; i<10; i++)
//////    cout << GEN::losujOdZeraDo(3) << " ";
//////    cout << endl << " od 0 do 20: ";
//////    for(int i=0; i<10; i++)
//////    cout << GEN::losujOdZeraDo(20) << " ";

//////    cout << endl << endl;

//////    cout << "Liczby losowe typu long: " << endl;
//////    cout << " od -2 do 2:";
//////    for(int i=0; i<10; i++)
//////    cout << GEN::losujPomiedzy(-2L, 2L) <<" ";

//////    cout << endl << endl
//////    << "Liczby losowe typu unsigned short: " << endl;
//////    cout << " od 2 do 6: ";
//////    unsigned short min=2, max=6;

//////    for(int i=0; i<10; i++)
//////    cout << GEN::losujPomiedzy(max, min) <<" ";

//////    cout << endl << endl;

//////    return 0;





//////    int state = 0;
//////    while(true){
//////        switch (state) {
//////        case 0:
//////            cout << "\n\nPodaj numer Laboratorium: ";
//////            cin >> state;
//////        break;
//////        case 2:
//////        {
//////            cout << "Laboratorium 02" << endl;
//////            ZLab02 lab02;
//////            lab02.menu();
//////            state = 0;
//////        }
//////        break;
//////        case 3:
//////        {
//////            cout << "Laboratorium 03" << endl;

//////            Prostokat p1;
//////            Prostokat p2("koc",1.4,2.2);
//////            Prostokat p3("pułapka",-2,-3);

//////            cout.precision(2);
//////            cout << p1.doTekstu() << endl;
//////            cout << p2.doTekstu() << endl;
//////            cout << p3.doTekstu() << endl;

//////            p3.zmienBoki(2,3);
//////            cout << endl << p3.doTekstu() << endl;

//////            cout << endl << "Użycie metod obiektu:" << endl;
//////            cout << "Nazwa: " << p2.jakaNazwa() << endl
//////            << "Poprawny: " << p2.czyPoprawny() << endl
//////            << "Obwód=:" << p2.podajObwod() << endl
//////            << "Pole=" << p2.podajPole() << endl;
//////            state = 0;


//////            //1. Test kreacji obiektów
//////            Organizm organizm1(8,3,2);
//////            Organizm organizm2 = organizm1;
//////            Organizm organizm3(organizm1);

//////            cout << "Wynik testu kreacji obiektów:"
//////            << endl << endl;
//////            cout << "Organizm1:" << endl;
//////            drukujOrganizm(organizm1);
//////            cout << "Organizm2" << endl;
//////            drukujOrganizm(organizm1);
//////            cout << "Organizm3" << endl;
//////            drukujOrganizm(organizm2);

//////            //2. Test niezależności obiektów
//////            organizm1.posilek();
//////            organizm1.posilek();
//////            organizm2.posilek();
//////            organizm3.krokSymulacji();

//////            cout << "Wynik testu niezależności obiektów:"
//////            << endl << endl;
//////            cout << "Organizm1:" << endl;
//////            drukujOrganizm(organizm1);
//////            cout << "Organizm2" << endl;
//////            drukujOrganizm(organizm2);
//////            cout << "Organizm3" << endl;
//////            drukujOrganizm(organizm3);

//////            //3. Test symulacji
//////            Organizm organizm4(8,3,2);

//////            cout << "Wynik testu symulacji:"
//////            << endl << endl;
//////            cout << "Stan początkowy:" << endl;
//////            drukujOrganizm(organizm4);

//////            for(int i=1; i<11; i++){

//////            organizm4.krokSymulacji();

//////            if(organizm4.paczkujacy()){
//////            organizm4.potomek();
//////            cout << "---> Potomek" << endl;
//////            } else organizm4.posilek();

//////            cout << "Po wykonaniu kroku symulacji: "
//////            << i << endl;
//////            drukujOrganizm(organizm4);
//////            }

//////            return 0;
//////            }
//////        break;
//////        default:
//////            cout << "Laboratorium " << state << " nie istnieje\n\n";
//////            state = 0;
//////        break;

//////        }
//////    }

////return 0;
////}
