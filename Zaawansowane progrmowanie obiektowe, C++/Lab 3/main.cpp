#include <iostream>
#include <limits>
// #include "Array.h"

using namespace std;

template <typename T>
void checkType(T a)
{
    T val = numeric_limits<T>::max();
    cout << val << endl;
}

template <typename T>
T minElement(T tab[], int size)
{
    T min = tab[0];
    for (int i = 1; i < size; i++)
    {
        if (tab[i] < min)
        {
            min = tab[i];
        }
    }
    return min;
}

template <typename T, int divider>
void showConvertingFromGrams(T elem)
{
    cout << elem << " is not an int/float" << endl;
}

template <int divider>
void showConvertingFromGrams(float elem)
{
    switch (divider)
    {
    case 1000000:
        cout << elem / divider << " t" << endl;
        break;
    case 1000:
        cout << elem / divider << " kg" << endl;
        break;
    case 10:
        cout << elem / divider << " dag" << endl;
        break;
    case 1:
        cout << elem / divider << " g" << endl;
        break;
    default:
        cout << "Wrong divider" << endl;
    }
}

template <int divider>
void showConvertingFromGrams(double elem)
{
    switch (divider)
    {
    case 1000000:
        cout << elem / divider << " t" << endl;
        break;
    case 1000:
        cout << elem / divider << " kg" << endl;
        break;
    case 10:
        cout << elem / divider << " dag" << endl;
        break;
    case 1:
        cout << elem / divider << " g" << endl;
        break;
    default:
        cout << "Wrong divider" << endl;
    }
}

int main()
{
    //    srand(time(NULL));
    //    int size = 100;
    //    auto *tab = new Array<string>[size];
    //
    //    for (int i = 0; i < size; i++)
    //    {
    //        tab->add(to_string(rand() % 1000));
    //    }
    //
    //    cout << tab->getMax() << endl;

    showConvertingFromGrams<float, 1000>(4593);
    return 0;
}