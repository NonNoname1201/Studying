//
// Created by User on 12.01.2024.
//

#include "Warehouse.h"

Warehouse::Warehouse(std::string name, int currentAmount, int price, int productType)
    : name(name), currentAmount(currentAmount),
      price(price),
      productType(productType) {}

std::string Warehouse::getName()
{
    return name;
}

int Warehouse::getCurrentAmount()
{
    return currentAmount;
}

int Warehouse::getPrice()
{
    return price;
}

int Warehouse::getProductType()
{
    return productType;
}

void Warehouse::setName(std::string name)
{
    Warehouse::name = name;
}

void Warehouse::setCurrentAmount(int currentAmount)
{
    Warehouse::currentAmount = currentAmount;
}

void Warehouse::setPrice(int price)
{
    Warehouse::price = price;
}

void Warehouse::setProductType(int productType)
{
    Warehouse::productType = productType;
}

void Warehouse::print()
{
    std::cout << "Name: " << name << std::endl;
    std::cout << "Quantity: " << currentAmount << std::endl;
    std::cout << "Price: " << price << std::endl;
    std::cout << "Product type: " << productType << std::endl;
}

Warehouse::~Warehouse()
{
    std::cout << "Warehouse destructor" << std::endl;
}
