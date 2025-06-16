#pragma once
#include "Observer.h"
#include "Order.h"
#include <string>
#include <vector>

class Customer : public Observer {
    std::string name;
    std::vector<Order*> orderHistory;
public:
    explicit Customer(const std::string& name);
    void addToOrderHistory(Order* order);
    void displayOrderHistory();
    void update(const std::string& message) override;
};