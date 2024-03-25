#include <string>
#include <iostream>
#include "Student.h"

#include "boost/multi_index_container.hpp"
#include "boost/multi_index/ordered_index.hpp"
#include "boost/multi_index/member.hpp"
#include "boost/multi_index/hashed_index.hpp"

using namespace std;
using namespace boost::multi_index;

typedef multi_index_container<
    Student,
    indexed_by<
        ordered_non_unique<member<Student, string, &Student::nazwisko>>,
        ordered_non_unique<member<Student, int, &Student::indeks>>,
        hashed_non_unique<member<Student, string, &Student::plec>>>>
    student_multi;

int main()
{
    student_multi students;

    students.insert({"Ewa", "Kowalska", 1, "Kobieta"});
    students.insert({"Jan", "Wojcik", 3, "Mezczyzna"});
    students.insert({"Zofia", "Wojcik", 4, "Kobieta"});
    students.insert({"Adam", "Nowak", 2, "Mezczyzna"});

    // W funkcji main() wyświetl wg. każdego z typów indeksów dane 4 studentów.
    cout << endl
         << "wg. :nazwiska " << endl;
    for (auto &s : students.get<0>())
        s.show();

    cout << endl
         << "wg. :indeksu " << endl;
    for (auto &s : students.get<1>())
        s.show();

    cout << endl
         << "wg. :plec " << endl;
    for (auto &s : students.get<2>())
        s.show();

    return 0;
}