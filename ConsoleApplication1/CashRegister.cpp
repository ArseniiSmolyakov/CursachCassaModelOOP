#include "CashRegister.h"
#include <iostream>
#include <algorithm>

void CashRegister::addProduct(Product* product) { products.push_back(product); }
const std::vector<Product*>& CashRegister::getProducts() const { return products; }
Product* CashRegister::findProductByName(const std::string& name) {
    for (auto product : products) {
        if (product->getName() == name) return product;
    }
    return nullptr;
}

void CashRegister::addCategory(Category* category) { categories.push_back(category); }
const std::vector<Category*>& CashRegister::getCategories() const { return categories; }
Category* CashRegister::findCategoryByName(const std::string& name) {
    for (auto category : categories) {
        if (category->getName() == name) return category;
    }
    return nullptr;
}

const std::vector<Order*>& CashRegister::getOrders() const { return orders; }
void CashRegister::addOrder(Order* order) { orders.push_back(order); }

void CashRegister::addToCart(Product* product, int quantity) {
    if (product->getStockQuantity() >= quantity) {
        currentCart.addItem(product, quantity);
        product->setStockQuantity(product->getStockQuantity() - quantity);
        std::cout << "Товар добавлен в корзину\n";
    }
    else {
        std::cout << "Недостаточно товара на складе\n";
    }
}

void CashRegister::removeFromCart(Product* product) {
    for (auto& item : currentCart.getItems()) {
        if (item.first == product) {
            product->setStockQuantity(product->getStockQuantity() + item.second);
            break;
        }
    }
    currentCart.removeItem(product);
    std::cout << "Товар удален из корзины\n";
}

const Cart& CashRegister::getCurrentCart() const { return currentCart; }
void CashRegister::clearCart() { currentCart.clear(); }

void CashRegister::setCurrentCustomer(Customer* customer) { currentCustomer = customer; }
Customer* CashRegister::getCurrentCustomer() const { return currentCustomer; }

void CashRegister::displayProducts() const {
    std::cout << "Доступные товары:\n";
    for (auto product : products) {
        product->display();
        std::cout << "-------------------\n";
    }
}

void CashRegister::displayCategories() const {
    std::cout << "Категории товаров:\n";
    for (auto category : categories) {
        category->display();
        std::cout << "-------------------\n";
    }
}

void CashRegister::displayCart() const { currentCart.display(); }

void CashRegister::createOrder(Discount* discount, PaymentMethod* paymentMethod) {
    Order* order = new Order();
    order->setCart(currentCart);
    if (discount) order->setDiscount(discount);
    if (paymentMethod) order->setPayment(paymentMethod);

    if (currentCustomer) {
        order->attach(currentCustomer);
        currentCustomer->addToOrderHistory(order);
    }

    orders.push_back(order);
    currentCart.clear();

    if (order->completeOrder()) {
        std::cout << "Заказ успешно создан и оплачен\n";
    }
    else {
        std::cout << "Ошибка при создании заказа\n";
    }
}

CashRegister::~CashRegister() {
    for (auto product : products) delete product;
    for (auto category : categories) delete category;
    for (auto order : orders) delete order;
}