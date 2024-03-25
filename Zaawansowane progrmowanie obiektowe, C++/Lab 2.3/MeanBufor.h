#ifndef LAB_2_3_MEANBUFOR_H
#define LAB_2_3_MEANBUFOR_H

#include <iostream>
#include "Bufor.h"

class MeanBufor : public Bufor
{
public:
    MeanBufor();
    MeanBufor(int size);
    virtual ~MeanBufor();
    double calculate();
};

#endif // LAB_2_3_MEANBUFOR_H
