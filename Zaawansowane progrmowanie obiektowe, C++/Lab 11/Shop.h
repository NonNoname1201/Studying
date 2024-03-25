//
// Created by User on 12.01.2024.
//

#ifndef LAB_11_SHOP_H
#define LAB_11_SHOP_H

#include <iostream>
#include <vector>
#include "Warehouse.h"

class Shop
{
private:
    std::string name;
    std::vector<Warehouse> warehouses;

public:
    Shop(const std::string &name);

    void addWarehouse(Warehouse warehouse);

    string sell(const std::string &name, int amount);

    void printWarehouses();

    void printName();

    ~Shop();
};

#endif // LAB_11_SHOP_H
