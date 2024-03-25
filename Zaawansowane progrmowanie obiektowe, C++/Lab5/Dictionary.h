//
// Created by User on 16.11.2023.
//

#ifndef LAB5_DICTIONARY_H
#define LAB5_DICTIONARY_H

#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

/*Zadanie 5.4. Słownik
Stwórz klasę Dictionary, która będzie reprezentować słownik i będzie posiadała następuje
pola i metody:
• words – kontener map, który będzie przechowywać słowo i jego tłumaczenie.
Zakładamy, że jedno słowo ma jedno tłumaczenie;
• konstruktor bezargumentowy;
• metodę umożliwiającą dodanie słowa wraz z tłumaczeniem do słownika. Przed
dodaniem należy sprawdzić czy słowo już nie istnieje;
• metodę umożliwiającą usunięcie słowa wraz z jego tłumaczeniem ze słownika;
• metodę wyświetlającą zawartość słownika;
• metodę wyświetlającą tłumaczenie dla podanego słowa;
• metodę wyświetlającą zawartość słownika alfabetycznie od z do a względem
tłumaczenia.
Podpowiedź: Aby posortować elementy w kontenerze map należy utworzyć
pomocniczy kontener np. vector. Dodać do niego elementy i wykonać sortowanie
używając funkcji sort.*/

class Dictionary
{
private:
    std::map<std::string, std::string> words;

public:
    Dictionary() = default;

    void add_word(const std::string &word, const std::string &translation)
    {
        if (words.find(word) == words.end())
        {
            words[word] = translation;
        }
        else
        {
            std::cout << "Word already exists" << std::endl;
        }
    }

    void remove_word(const std::string &word)
    {
        if (words.find(word) != words.end())
        {
            words.erase(word);
        }
        else
        {
            std::cout << "Word doesn't exist" << std::endl;
        }
    }

    void display() const
    {
        for (const auto &element : words)
        {
            std::cout << element.first << " - " << element.second << std::endl;
        }
    }

    std::string translate(const std::string &word) const
    {
        if (words.find(word) != words.end())
        {
            return words.at(word);
        }
        else
        {
            return "Word doesn't exist";
        }
    }

    void display_alphabetically() const
    {
        std::vector<std::pair<std::string, std::string>> v;

        for (const auto &element : words)
        {
            v.emplace_back(element);
        }

        std::sort(
            v.begin(), v.end(), [](const auto &a, const auto &b)
            { return a.second > b.second; });

        for (const auto &element : v)
        {
            std::cout << element.first << " - " << element.second << std::endl;
        }
    }
};

#endif // LAB5_DICTIONARY_H
