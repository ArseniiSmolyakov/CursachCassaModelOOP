#include "Inventory.h"
#include <iostream>

void Inventory::addProduct(Product* product) {
    products.push_back(product);
}

void Inventory::updateStock(Product* product, int quantity) {
    product->setStockQuantity(quantity);
}

void Inventory::displayInventory() const {
    std::cout << "Инвентарь:\n";
    for (auto product : products) {
        std::cout << product->getName() << ": " << product->getStockQuantity() << " шт.\n";
    }
}