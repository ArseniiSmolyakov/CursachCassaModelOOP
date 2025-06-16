#include "Payment.h"

Payment::Payment(PaymentMethod* method, double amount)
    : method(method), amount(amount), isPaid(false) {
}

bool Payment::processPayment() {
    isPaid = method->pay(amount);
    return isPaid;
}

std::string Payment::getMethodName() { return method->getName(); }
double Payment::getAmount() { return amount; }
bool Payment::getIsPaid() { return isPaid; }