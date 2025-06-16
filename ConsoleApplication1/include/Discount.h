#pragma once
#include "DiscountStrategy.h"
#include <memory>

class Discount {
    std::unique_ptr<DiscountStrategy> strategy;
public:
    Discount(DiscountStrategy* strategy);
    double apply(double originalPrice);
    std::string getDescription();
};