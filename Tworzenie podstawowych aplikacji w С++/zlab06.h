#ifndef ZLAB06_H
#define ZLAB06_H
#include "zlab03.h"
#include "iostream"

class Obliczenia {
protected:
const double pi = 3.14;
public:
virtual double promienKolaWgPola() = 0;
virtual double promenOkreguWgObwodu() = 0;
virtual ~Obliczenia();
};

class Kwadrat: public Prostokat, public Obliczenia
{
public:

Kwadrat(string nazwa = "?", double bok =0):Prostokat(nazwa,bok,bok){}


virtual string doTekstu()
{
string napis ="";
napis = "Kwadrat o nazwie: " + nazwa
+ " bok=" + to_string(bok1);
if(poprawny) napis += " obwod=" + to_string(obwod)
+ " pole=" + to_string(pole);
else napis +=" !Figura niepoprawna.";
return napis;
}


virtual ~Kwadrat()
{
 cout << "Kwadrat: " << nazwa <<" kończy działanie" << endl;
}

double promienKolaWgPola();
double promenOkreguWgObwodu();
};

#endif // ZLAB06_H
