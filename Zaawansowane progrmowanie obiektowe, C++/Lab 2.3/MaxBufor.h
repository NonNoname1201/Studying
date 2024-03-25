#ifndef LAB_2_3_MAXBUFOR_H
#define LAB_2_3_MAXBUFOR_H

#include <iostream>
#include "Bufor.h"

class MaxBufor : public Bufor
{
public:
    MaxBufor();
    MaxBufor(int size);
    virtual ~MaxBufor();
    double calculate();
    void add(int value);
};

#endif // LAB_2_3_MAXBUFOR_H
