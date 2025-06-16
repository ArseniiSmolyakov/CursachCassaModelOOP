#include "Customer.h"
#include <iostream>

Customer::Customer(const std::string& name) : name(name) {}

void Customer::addToOrderHistory(Order* order) {
    orderHistory.push_back(order);
}

void Customer::displayOrderHistory() {
    std::cout << "История заказов покупателя " << name << ":\n";
    for (auto order : orderHistory) {
        order->display();
        std::cout << "-------------------\n";
    }
}

void Customer::update(const std::string& message) {
    std::cout << "Уведомление для " << name << ": " << message << std::endl;
}