#ifndef LAB_2_3_BUFOR_H
#define LAB_2_3_BUFOR_H

#include <iostream>

class Bufor
{
private:
    int *tab;
    int size;
    int first;

public:
    Bufor();
    Bufor(int size);
    virtual ~Bufor();
    virtual void add(int value);
    virtual double calculate() = 0;
    int getIndex();
    int getSize();
    int getTab(int i);
    int getFirst();
    void setFirst(int value);
    void setTab(int pos, int value);
    void show();
};

#endif // LAB_2_3_BUFOR_H
