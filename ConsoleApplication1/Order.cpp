#include "Order.h"
#include <iostream>
#include <iomanip>

Order::Order() : isCompleted(false) {
    orderTime = time(nullptr);
}

void Order::setCart(const Cart& cart) { this->cart = cart; }
void Order::setDiscount(Discount* discount) { this->discount.reset(discount); }

double Order::getTotal() const {
    double total = cart.getTotal();
    if (discount) {
        total = discount->apply(total);
    }
    return total;
}

void Order::setPayment(PaymentMethod* method) {
    payment = std::make_unique<Payment>(method, getTotal());
}

bool Order::completeOrder() {
    if (!payment) {
        notify("Ошибка: способ оплаты не выбран");
        return false;
    }

    if (payment->processPayment()) {
        isCompleted = true;
        notify("Заказ успешно завершен");
        return true;
    }
    notify("Ошибка оплаты");
    return false;
}

void Order::display() const {
    char buffer[26];
    ctime_s(buffer, sizeof(buffer), &orderTime);
    std::cout << "Заказ от " << buffer;
    cart.display();
    if (discount) {
        std::cout << "Применена скидка: " << discount->getDescription()
            << "\nИтого со скидкой: " << getTotal() << std::endl;
    }
    if (payment) {
        std::cout << "Способ оплаты: " << payment->getMethodName()
            << "\nСтатус оплаты: " << (payment->getIsPaid() ? "Оплачено" : "Не оплачено") << std::endl;
    }
    std::cout << "Статус заказа: " << (isCompleted ? "Завершен" : "В процессе") << std::endl;
}