#include "zlab06.h"
#include <cmath>

Obliczenia::~Obliczenia()
{

}

double Kwadrat::promienKolaWgPola()
{
return sqrt(pole / pi);
}

double Kwadrat::promenOkreguWgObwodu()
{
return obwod / (2*pi);
}
