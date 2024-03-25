#include "City.h"

using namespace std;

City::City(string city_name)
{
    this->city_name = city_name;
}

void City::addCitizen(Citizen citizen)
{
    citizens.push_back(citizen);

    if (postalIndex.find(stoi(citizen.getPostalCode().substr(0, 2) + citizen.getPostalCode().substr(3, 3))) == postalIndex.end())
    {
        PostalIndex newPostalIndex(citizen.getPostalCode());
        newPostalIndex.addCitizen();
        this->postalIndex.insert({stoi(citizen.getPostalCode().substr(0, 2) + citizen.getPostalCode().substr(3, 3)), newPostalIndex});
    }
    else
    {
        postalIndex[stoi(citizen.getPostalCode().substr(0, 2) + citizen.getPostalCode().substr(3, 3))].addCitizen();
    }
}

void City::deleteCitizen(string surname, int age)
{
    for (int i = 0; i < citizens.size(); i++)
    {
        if (citizens[i].getSurname() == surname && citizens[i].getAge() == age)
        {
            citizens.erase(citizens.begin() + i);
            postalIndex[stoi(citizens[i].getPostalCode().substr(0, 2) + citizens[i].getPostalCode().substr(3, 3))].deleteCitizen();
        }
    }
}

void City::show_citizens()
{
    cout << "City: " << city_name << endl;
    for (int i = 0; i < citizens.size(); i++)
    {
        cout << "Citizen " << i + 1 << endl;
        citizens[i].show();
        cout << endl;
    }
}

void City::showPostalIndex()
{
    cout << "City: " << city_name << endl;
    for (auto it = postalIndex.begin(); it != postalIndex.end(); it++)
    {
        cout << "Postal Code: " << it->first << endl;
        it->second.show();
        cout << endl;
    }
}

int City::getCitizensInPostalCode(string postal_code)
{
    return postalIndex[stoi(postal_code.substr(0, 2) + postal_code.substr(3, 3))].getCitizens();
}

int City::city_citizens()
{
    return citizens.size();
}

int City::adults()
{
    int adults = 0;
    for (int i = 0; i < citizens.size(); i++)
    {
        if (citizens[i].getAge() >= 18)
            adults++;
    }
    return adults;
}

int City::women()
{
    int women = 0;
    for (int i = 0; i < citizens.size(); i++)
    {
        if (citizens[i].getSex() == 'F')
            women++;
    }
    return women;
}