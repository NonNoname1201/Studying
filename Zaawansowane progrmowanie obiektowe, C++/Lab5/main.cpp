#include <iostream>
#include <map>
#include <set>
#include <vector>
#include "template.h"
#include "Dictionary.h"

/*Zadanie 5.1. Duplikat
Napisz funkcję, która jako argument przyjmuje kontener vector przechowujący liczby
całkowite. Zakładamy, że vector przechowuje unikatowe wartości oprócz jednej, która została
zduplikowana. Zadaniem funkcji jest znalezienie wartości, która została zduplikowana oraz
policzenie sumy unikatowych elementów. Funkcja powinna zwrócić obiekt klasy pair.
W zadaniu należy wykorzystać kontener set. W funkcji main należy przetestować funkcję.*/

std::pair<int, int> duplicate(const std::vector<int> &v)
{
    std::set<int> unique_elements;
    int sum = 0;
    int duplicate = -1;

    for (const auto &element : v)
    {
        if (!unique_elements.insert(element).second)
        {
            duplicate = element;
        }
        else
        {
            sum += element;
        }
    }

    return {duplicate, sum}; // return {duplicate, sum - duplicate};
}

/*Zadanie 5.3. Różnica
Napisz funkcję, która dostaje jako argumenty dwa napisy typu string. Drugi napis jest o jest
o jeden znak dłuższy od pierwszego. Drugi napis zawiera te same znaki co pierwszy napis tylko
w różnej kolejności i dodatkowo jeszcze jeden znak. Zadaniem funkcji jest znalezienie znaku,
który został dodany do drugiego napisu i zwrócenie go. W zadaniu należy wykorzystać
kontener map. W main należy przetestować funkcję.*/

char difference(const std::string &s1, const std::string &s2)
{
    std::map<char, int> m1;
    std::map<char, int> m2;

    for (const auto &element : s1)
    {
        m1[element]++;
    }

    for (const auto &element : s2)
    {
        m2[element]++;
    }

    for (const auto &element : m2)
    {
        if (m1[element.first] != element.second)
        {
            return element.first;
        }
    }

    return '\0';
}

int main()
{
    //    Dictionary dictionary;
    //
    //    dictionary.add_word("hello", "hola");
    //    dictionary.add_word("goodbye", "adios");
    //    dictionary.add_word("please", "por favor");
    //
    //    std::string word = "hello";
    //    std::cout << "Translation of " << word << ": " << dictionary.translate(word) << std::endl;
    //
    //    word = "goodbye";
    //    std::cout << "Translation of " << word << ": " << dictionary.translate(word) << std::endl;
    //
    //    word = "please";
    //    std::cout << "Translation of " << word << ": " << dictionary.translate(word) << std::endl;
    //
    //    word = "nonexistent"; //"Word doesn't exist"
    //    std::cout << "Translation of " << word << ": " << dictionary.translate(word) << std::endl;
    //
    //    dictionary.display();
    //    dictionary.display_alphabetically();
    //
    //    dictionary.remove_word("please");
    //    dictionary.display();
    //
    //    dictionary.remove_word("nonexistent"); //"Word doesn't exist" 

    std::vector v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 5};
    std::pair<int, int> result = duplicate(v);
    std::cout << "Duplicate: " << result.first << std::endl;
    std::cout << "Sum: " << result.second << std::endl;
    return 0;
}