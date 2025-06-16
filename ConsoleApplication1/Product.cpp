#include "Product.h"

Product::Product(const std::string& name, double price, Category* category, int stockQuantity)
    : name(name), price(price), category(category), stockQuantity(stockQuantity) {
}

std::string Product::getName() const { return name; }
double Product::getPrice() const { return price; }
Category* Product::getCategory() const { return category; }
int Product::getStockQuantity() const { return stockQuantity; }

void Product::setStockQuantity(int quantity) { stockQuantity = quantity; }

void Product::display() const {
    std::cout << "Товар: " << name << "\nЦена: " << price
        << "\nКоличество на складе: " << stockQuantity << std::endl;
    category->display();
}