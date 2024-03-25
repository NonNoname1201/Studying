#include "MeanBufor.h"

MeanBufor::MeanBufor()
{
}

MeanBufor::MeanBufor(int size) : Bufor(size)
{
}

MeanBufor::~MeanBufor()
{
}

double MeanBufor::calculate()
{
    double sum = 0;
    for (int i = 0; i < this->getIndex(); i++)
    {
        sum += this->getTab(i);
    }
    return sum / this->getIndex();
}
