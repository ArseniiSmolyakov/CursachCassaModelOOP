#pragma once
#include <string>

class PaymentMethod {
public:
    virtual bool pay(double amount) = 0;
    virtual std::string getName() = 0;
    virtual ~PaymentMethod() = default;
};