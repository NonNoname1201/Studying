//
// Created by User on 24.11.2023.
//

#ifndef UNTITLED_TEMPF_H
#define UNTITLED_TEMPF_H

/*Zadanie 6.3. Statystyka
Napisz funkcję szablonową o parametrze T, która jako argument będzie zawierać kontener
vector typu T. Zadaniem funkcji jest wyświetlenie:
• elementów mniejszych niż średnia arytmetyczna wszystkich elementów;
• elementów znajdujących się między średnią arytmetyczna a medianą wszystkich
elementów;
• elementów dodatnich.
Można skorzystać z elementów biblioteki functional. Wykaz operatorów można znaleźć na
stronie http://www.cplusplus.com/reference/functional/ W celu przekazania argumentów do
funkcji należy użyć funkcji bind.
*/

#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
#include <type_traits>

using namespace std;

template <typename T>
void printVectorSmAvg(vector<T> vector)
{
    double sum = 0;

    if (is_arithmetic<T>::value)
    {
        for (auto element : vector)
        {
            sum += element;
        }
        double average = sum / vector.size();

        for (auto element : vector)
        {
            if (element < average)
            {
                cout << element << " ";
            }
        }
        cout << endl;
    }
    else
    {
        cout << "Not arithmetic" << endl;
    }
}

template <typename T>
void printVectorBtwAvgMed(vector<T> vector)
{
    double sum = 0;
    double median = 0;

    if (is_arithmetic<T>::value)
    {

        for (auto element : vector)
        {
            sum += element;
        }
        double average = sum / vector.size();

        sort(vector.begin(), vector.end());

        if (vector.size() % 2 == 0)
        {
            median = (vector[vector.size() / 2 - 1] + vector[vector.size() / 2]) / 2;
        }
        else
        {
            median = vector[vector.size() / 2];
        }

        for (auto element : vector)
        {
            if (element > average && element < median)
            {
                cout << element << " ";
            }
        }
        cout << endl;
    }
    else
    {
        cout << "Not arithmetic" << endl;
    }
}

template <typename T>
void printVectorPos(vector<T> vector)
{
    if (is_arithmetic<T>::value)
    {
        for (auto element : vector)
        {
            if (element > 0)
            {
                cout << element << " ";
            }
        }
        cout << endl;
    }
    else
    {
        cout << "Not arithmetic" << endl;
    }
}

#endif // UNTITLED_TEMPF_H
