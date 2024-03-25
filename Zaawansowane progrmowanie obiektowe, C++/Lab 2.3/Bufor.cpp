#include "Bufor.h"

Bufor::Bufor()
{
    this->size = 10;
    this->first = 0;
    this->tab = new int[this->size];
}

Bufor::Bufor(int size)
{
    this->size = size;
    this->first = 0;
    this->tab = new int[this->size];
}

Bufor::~Bufor()
{
    delete[] this->tab;
}

void Bufor::add(int value)
{
    this->tab[this->first] = value;
    this->first++;
}

int Bufor::getIndex()
{
    return this->first;
}

int Bufor::getSize()
{
    return this->size;
}

int Bufor::getTab(int i)
{
    return this->tab[i];
}

int Bufor::getFirst()
{
    return this->first;
}

void Bufor::setFirst(int value)
{
    this->first = value;
}

void Bufor::setTab(int pos, int value)
{
    this->tab[pos] = value;
}

void Bufor::show()
{
    for (int i = 0; i < this->first; i++)
    {
        std::cout << this->tab[i] << " ";
    }
    std::cout << std::endl;
}