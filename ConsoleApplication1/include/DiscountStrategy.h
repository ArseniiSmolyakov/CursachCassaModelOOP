#pragma once
#include <string>

class DiscountStrategy {
public:
    virtual double applyDiscount(double originalPrice) = 0;
    virtual std::string getDescription() = 0;
    virtual ~DiscountStrategy() = default;
};