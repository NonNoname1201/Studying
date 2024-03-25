//
// Created by User on 12.01.2024.
//

#ifndef LAB_11_WAREHOUSE_H
#define LAB_11_WAREHOUSE_H

#include <string>
#include <iostream>

using std::string;

class Warehouse
{
private:
    string name;
    int currentAmount;
    int price;
    int productType;

public:
    Warehouse(string name, int currentAmount, int price, int productType);

    string getName();

    int getCurrentAmount();

    int getPrice();

    int getProductType();

    void setName(string name);

    void setCurrentAmount(int currentAmount);

    void setPrice(int price);

    void setProductType(int productType);

    void print();

    ~Warehouse();
};

#endif // LAB_11_WAREHOUSE_H
