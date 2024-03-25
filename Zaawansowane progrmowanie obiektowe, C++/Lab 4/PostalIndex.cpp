#include <iostream>
#include <string>

#include "Citizen.h"
#include "PostalIndex.h"

using namespace std;

PostalIndex::PostalIndex(string postal_code)
{
    //split string into two parts
    this->postal_code = stoi(postal_code.substr(0, 2) + postal_code.substr(3, 3));
    citizens = 0;
}

PostalIndex::PostalIndex()
{
    postal_code = 0;
    citizens = 0;
}


void PostalIndex::addCitizen()
{
    citizens++;
}

void PostalIndex::deleteCitizen()
{
    citizens--;
}

void PostalIndex::show()
{
    cout << postal_code << " -> " << citizens << " citizens" << endl;
}

int PostalIndex::getPostalCode()
{
    return postal_code;
}

int PostalIndex::getCitizens()
{
    return citizens;
}
