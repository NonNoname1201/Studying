#include "MaxBufor.h"

MaxBufor::MaxBufor()
{
}

MaxBufor::MaxBufor(int size) : Bufor(size)
{
}

MaxBufor::~MaxBufor()
{
}

double MaxBufor::calculate()
{
    double max = this->getTab(0);
    for (int i = 1; i < this->getIndex(); i++)
    {
        if (this->getTab(i) > max)
        {
            max = this->getTab(i);
        }
    }
    return max;
}

void MaxBufor ::add(int value)
{
    if (this->getIndex() < this->getSize())
    {
        Bufor::add(value);
    }
    else
    {
        std::cout << "Nie ma juz miejsca w tablicy" << std::endl;
    }
}