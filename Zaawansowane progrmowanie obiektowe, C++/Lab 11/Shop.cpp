//
// Created by User on 12.01.2024.
//

#include "Shop.h"

Shop::Shop(const std::string &name) : name(name) {}

void Shop::addWarehouse(Warehouse warehouse)
{
    warehouses.push_back(warehouse);
}

string Shop::sell(const std::string &name, int amount)
{
    for (auto &warehouse : warehouses)
    {
        if (warehouse.getName() == name)
        {
            if (warehouse.getCurrentAmount() >= amount)
            {
                warehouse.setCurrentAmount(warehouse.getCurrentAmount() - amount);
                return "Sold, total price: " + std::to_string(amount * warehouse.getPrice()) + " PLN";
            }
            else
            {
                return "Not enough products";
            }
        }
    }
    return "No such product";
}

void Shop::printWarehouses()
{
    for (auto &warehouse : warehouses)
    {
        warehouse.print();
    }
}

void Shop::printName()
{
    std::cout << "Name: " << name << std::endl;
}

Shop::~Shop()
{
    std::cout << "Shop destructor" << std::endl;
}