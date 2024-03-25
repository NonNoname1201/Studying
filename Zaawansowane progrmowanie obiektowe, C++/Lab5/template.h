#include <set>
#include <algorithm>

/*Zadanie 5.2. Alternatywa wykluczająca
Napisz funkcję szablonową, która jako argument przyjmuje dwa zbiory. Funkcja powinna
wyświetlić elementy, które znajdują się tylko w pierwszym lub tylko w drugim zbiorze.
Podpowiedź: Należy zwrócić uwagę z jakim typem wywoływane są algorytmy i iteratory*/

template <typename T>
void exclusive_or(const std::set<T> &s1, const std::set<T> &s2)
{
    std::set<T> result;
    std::set_symmetric_difference(s1.begin(), s1.end(), s2.begin(), s2.end(), std::inserter(result, result.begin()));

    for (const auto &element : result)
    {
        std::cout << element << " ";
    }
}