#include "Cart.h"
#include <algorithm>

void Cart::addItem(Product* product, int quantity) {
    for (auto& item : items) {
        if (item.first == product) {
            item.second += quantity;
            return;
        }
    }
    items.emplace_back(product, quantity);
}

void Cart::removeItem(Product* product) {
    items.erase(std::remove_if(items.begin(), items.end(),
        [product](const std::pair<Product*, int>& item) { return item.first == product; }),
        items.end());
}

void Cart::clear() { items.clear(); }

const std::vector<std::pair<Product*, int>>& Cart::getItems() const { return items; }

double Cart::getTotal() const {
    double total = 0;
    for (const auto& item : items) {
        total += item.first->getPrice() * item.second;
    }
    return total;
}

void Cart::display() const {
    std::cout << "Содержимое корзины:\n";
    for (const auto& item : items) {
        std::cout << item.first->getName() << " x " << item.second
            << " = " << item.first->getPrice() * item.second << std::endl;
    }
    std::cout << "Итого: " << getTotal() << std::endl;
}