#ifndef ZLAB09_H
#define ZLAB09_H
#include <iostream>
#include <osobniki.h>
using namespace std;


class ZLab09
{
public:
    int* wskInt1D = nullptr;
    int** wskInt2D = nullptr;
    void skalar();
    ZLab09();
    void rozmiary();
    void tablica1D();
    void tablica2D(int w, int k);
    void referencja();
};

#endif // ZLAB09_H
