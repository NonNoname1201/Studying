#include <iostream>
#include "MaxBufor.h"
#include "MeanBufor.h"


int main()
{
    int size = 5;

    MaxBufor *maxBufor = new MaxBufor(size);
    for (int i = 0; i < size; i++)
    {
        maxBufor->add(rand() % 10);
    }

    std::cout << "Tablica: " << std::endl;

    maxBufor->show();

    std::cout << "Max: " << maxBufor->calculate() << std::endl;

    maxBufor->add(10);

    MeanBufor *meanBufor = new MeanBufor(size);
    for (int i = 0; i < size; i++)
    {
        meanBufor->add(rand() % 10);
    }

    std::cout << "Tablica: " << std::endl;

    meanBufor->show();

    std::cout << "Srednia: " << meanBufor->calculate() << std::endl;

    return 0;
}
