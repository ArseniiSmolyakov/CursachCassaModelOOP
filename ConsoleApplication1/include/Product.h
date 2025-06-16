#pragma once
#include "Category.h"
#include <string>

class Product {
    std::string name;
    double price;
    Category* category;
    int stockQuantity;
public:
    Product(const std::string& name, double price, Category* category, int stockQuantity);
    std::string getName() const;
    double getPrice() const;
    Category* getCategory() const;
    int getStockQuantity() const;
    void setStockQuantity(int quantity);
    void display() const;
};