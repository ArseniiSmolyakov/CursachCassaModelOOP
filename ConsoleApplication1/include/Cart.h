#pragma once
#include "Product.h"
#include <vector>
#include <utility>

class Cart {
    std::vector<std::pair<Product*, int>> items;
public:
    void addItem(Product* product, int quantity);
    void removeItem(Product* product);
    void clear();
    const std::vector<std::pair<Product*, int>>& getItems() const;
    double getTotal() const;
    void display() const;
};