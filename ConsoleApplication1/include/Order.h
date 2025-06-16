#pragma once
#include "Subject.h"
#include "Cart.h"
#include "Discount.h"
#include "Payment.h"
#include <ctime>
#include <memory>

class Order : public Subject {
    time_t orderTime;
    Cart cart;
    std::unique_ptr<Discount> discount;
    std::unique_ptr<Payment> payment;
    bool isCompleted;
public:
    Order();
    void setCart(const Cart& cart);
    void setDiscount(Discount* discount);
    double getTotal() const;
    void setPayment(PaymentMethod* method);
    bool completeOrder();
    void display() const;
};