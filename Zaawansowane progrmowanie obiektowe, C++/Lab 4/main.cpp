#include <iostream>
#include <vector>
#include <algorithm>

#include "City.h"
#include "Functor.h"

using namespace std;

vector<int> f1()
{
    vector<int> v;
    int n = rand() % 100 + 1;
    int num;
    for (int i = 0; i < n; i++)
    {
        num = rand() % 201 - 100;
        if (num < 0)
            v.push_back(num);
        else
            v.insert(v.begin(), num);
    }
    return v;
}

void Zadanie2()
{
    City city("Warsaw");
    city.addCitizen(Citizen("Jan", "Kowalski", 20, 'M', "00-001"));
    city.addCitizen(Citizen("Anna", "Nowak", 30, 'F', "00-001"));
    city.addCitizen(Citizen("Jan", "Nowak", 40, 'M', "00-002"));
    city.addCitizen(Citizen("Jan", "Kowalski", 50, 'M', "00-003"));
    city.addCitizen(Citizen("Anna", "Kowalska", 60, 'F', "00-003"));
    city.addCitizen(Citizen("Jan", "Nowak", 70, 'M', "00-003"));
    city.addCitizen(Citizen("Anna", "Nowak", 80, 'F', "00-003"));

    city.show_citizens();

    city.deleteCitizen("Kowalski", 20);

    city.show_citizens();

    city.showPostalIndex();

    cout << "Citizens in postal code 00-003: " << city.getCitizensInPostalCode("00-003") << endl;
    cout << "Citizens in postal code 00-001: " << city.getCitizensInPostalCode("00-001") << endl;

    cout << "Citizens in city: " << city.city_citizens() << endl;

    cout << "Adults in city: " << city.adults() << endl;

    cout << "Women in city: " << city.women() << endl;

}

void Zadanie3(){
    vector<int> v;
    int n = rand() % 100 + 1;
    int num;
    for (int i = 0; i < n; i++)
    {
        num = rand() % 1001;
        v.insert(v.begin(), num);
    }
//    for_each(v.begin(), v.end(), [](int i) { cout << i << ", "; });
//    cout << endl;
//    sort(v.begin(), v.end(), [](int a, int b) {
//        int sumaA = 0;
//        int sumaB = 0;
//        int tempA = a;
//        int tempB = b;
//        while (tempA != 0)
//        {
//            sumaA += tempA % 10;
//            tempA /= 10;
//        }
//        while (tempB != 0)
//        {
//            sumaB += tempB % 10;
//            tempB /= 10;
//        }
//        return sumaA < sumaB;
//    });
//    for_each(v.begin(), v.end(), [](int i) { cout << i << ", "; });
//    cout << endl;
//    sort(v.begin(), v.end(), [](int a, int b) {
//        int sumaA = 0;
//        int sumaB = 0;
//        int tempA = a;
//        int tempB = b;
//        while (tempA != 0)
//        {
//            sumaA++;
//            tempA /= 10;
//        }
//        while (tempB != 0)
//        {
//            sumaB++;
//            tempB /= 10;
//        }
//        return sumaA > sumaB;
//    });
//    for_each(v.begin(), v.end(), [](int i) { cout << i << ", "; });
//    cout << endl;

    sort(v.begin(), v.end(), less<int>());
    for_each(v.begin(), v.end(), [](int i) { cout << i << ", "; });
    cout << endl;


    sort(v.begin(), v.end(), Functor());
    for_each(v.begin(), v.end(), [](int i) { cout << i << ", "; });
    cout << endl;


    bool (*fun)(int, int) = [](int a, int b) {
        int sumaA = 0;
        int sumaB = 0;
        int tempA = a;
        int tempB = b;
        while (tempA != 0)
        {
            sumaA ++;
            tempA /= 10;
        }
        while (tempB != 0)
        {
            sumaB ++;
            tempB /= 10;
        }
        return sumaA > sumaB;
    };

    sort(v.begin(), v.end(), fun);
    for_each(v.begin(), v.end(), [](int i) { cout << i << ", "; });
    cout << endl;


    sort(v.begin(), v.end(), [](int a, int b) {
        return a % 3 < b % 3;
    });
    for_each(v.begin(), v.end(), [](int i) { cout << i << ", "; });
    cout << endl;

}

int main()
{
//    vector<int> v = f1();
//    vector<int> v2 = f1();
//    v.insert(v.begin(), v2.begin(), v2.end());
//
//    for (auto it = v.begin(); it != v.end(); it++)
//    {
//        cout << &(*it) << endl;
//    }

Zadanie3();

    return 0;
}
