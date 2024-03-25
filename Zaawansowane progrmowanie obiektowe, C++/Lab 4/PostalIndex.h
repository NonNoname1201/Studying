#ifndef LAB_4_POSTALINDEX_H
#define LAB_4_POSTALINDEX_H

#include <iostream>
#include <string>
#include <vector>
#include "Citizen.h"

using namespace std;

class PostalIndex
{
private:
    int postal_code;
    int citizens;

public:
    PostalIndex(string);
    PostalIndex();
    void addCitizen();
    void deleteCitizen();
    void show();
    int getPostalCode();
    int getCitizens();
};
#endif // LAB_4_POSTALINDEX_H
