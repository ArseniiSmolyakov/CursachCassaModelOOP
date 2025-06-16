#pragma once
#include "Product.h"
#include <vector>

class Inventory {
    std::vector<Product*> products;
public:
    void addProduct(Product* product);
    void updateStock(Product* product, int quantity);
    void displayInventory() const;
};