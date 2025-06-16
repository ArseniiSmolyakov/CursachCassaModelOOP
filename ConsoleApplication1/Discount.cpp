#include "Discount.h"

Discount::Discount(DiscountStrategy* strategy) : strategy(strategy) {}

double Discount::apply(double originalPrice) {
    return strategy->applyDiscount(originalPrice);
}

std::string Discount::getDescription() {
    return strategy->getDescription();
}