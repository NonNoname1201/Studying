#include <iostream>
#include <vector>
#include <memory>
#include "Warehouse.h"
#include "TwoWay.h"
#include "Shop.h"

/*Zadanie 11.2. Sklepy
W zadaniu wykorzystaj inteligentne wskaźniki. Zdefiniuj klasę Warehouse, która będzie
reprezentować magazyn. Klasa będzie posiadać:
• prywatne pola przechowujące nazwę towaru, który jest przechowywany w magazynie
(dla uproszczenia na przykład: książki, komputery, łóżka, itd.) oraz liczbę sztuk;
• konstruktor inicjalizujący pola w klasie;
• odpowiednie setery oraz gettery do pól;
• metodę wyświetlającą informację o magazynie (nazwa towaru oraz liczba sztuk
towaru).
Następnie stwórz klasę Shop, która będzie reprezentować sklep i posiadać:
• prywatne pole: nazwa sklepu, listę magazynów (vector), z których korzysta sklep;
• konstruktor jednoparametrowy pozwalający na inicjalizację nazwy sklepu;
• metodę dodającą magazyn do listy;
• metodę, która umożliwi sprzedaż towaru, którego nazwa i liczba sztuk została podana
w argumencie (zakładamy, że nazwa artykułu jest taka sama jak nazwa towaru
w magazynie). Jeśli w danym magazynie znajduje się odpowiednia liczba sztuk danego
towaru, to towar powinien zostać sprzedany;
• metodę wyświetlającą z jakich magazynów korzysta sklep;
• metodę wyświetlającą nazwę sklepu.
W destruktorach stworzonych klas należy wyświetlić komunikat identyfikujący te
destruktory.
W funkcji main stwórz listę unikatowych sklepów. Sklepy mogą korzystać z tych samych
magazynów. Przetestuj stworzone klasy.
*/

/*Zadanie 11.3. Lista dwukierunkowa
Napisz program, który w oparciu o inteligentne wskaźniki będzie realizować uproszczoną
listę dwukierunkową. Operacje, które będzie można wykonać na liście, to dodawanie na
początek oraz na koniec listy, usuwanie z początku i z końca, wyświetlenie zawartości listy,
sprawdzenie czy jest pusta. Program należy przetestować. W destruktorach stworzonych klas
należy wyświetlić komunikat identyfikujący te destruktory.*/

int main()
{
    std::vector<std::unique_ptr<Shop>> shops;
    std::vector<std::unique_ptr<Warehouse>> warehouses;

    warehouses.push_back(std::make_unique<Warehouse>("Books", 100, 20, 1));
    warehouses.push_back(std::make_unique<Warehouse>("Computers", 50, 2000, 2));
    warehouses.push_back(std::make_unique<Warehouse>("Beds", 10, 500, 3));

    shops.push_back(std::make_unique<Shop>("Shop1"));
    shops.push_back(std::make_unique<Shop>("Shop2"));

    shops[0]->addWarehouse(*warehouses[0]);
    shops[0]->addWarehouse(*warehouses[1]);
    shops[1]->addWarehouse(*warehouses[1]);
    shops[1]->addWarehouse(*warehouses[2]);

    shops[0]->printName();
    shops[0]->printWarehouses();
    std::cout << shops[0]->sell("Books", 10) << std::endl;
    std::cout << shops[0]->sell("Books", 100) << std::endl;

    shops[1]->printName();
    shops[1]->printWarehouses();
    std::cout << shops[1]->sell("Beds", 10) << std::endl;
    std::cout << shops[1]->sell("Beds", 100) << std::endl;

    TwoWayList<int> list;
    list.push_front(1);
    list.push_front(2);
    list.push_front(3);
    list.push_back(4);
    list.push_back(5);

    list.printList();
    list.pop_front();

    list.printList();
    list.pop_back();

    list.printList();

    list.clear();
    list.printList();
    if(list.isEmpty())
    {
        std::cout << "List is empty" << std::endl;
    }
    else
    {
        std::cout << "List is not empty" << std::endl;
    }

    return 0;
}
