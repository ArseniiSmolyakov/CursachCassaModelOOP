#pragma once
#include "PaymentMethod.h"
#include <memory>

class Payment {
    std::unique_ptr<PaymentMethod> method;
    double amount;
    bool isPaid;
public:
    Payment(PaymentMethod* method, double amount);
    bool processPayment();
    std::string getMethodName();
    double getAmount();
    bool getIsPaid();
};