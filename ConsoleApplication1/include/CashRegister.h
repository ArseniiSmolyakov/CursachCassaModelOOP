#pragma once
#include "Product.h"
#include "Category.h"
#include "Order.h"
#include "Cart.h"
#include "Customer.h"
#include <vector>

class CashRegister {
    std::vector<Product*> products;
    std::vector<Category*> categories;
    std::vector<Order*> orders;
    Cart currentCart;
    Customer* currentCustomer;
public:
    // Методы для работы с продуктами
    void addProduct(Product* product);
    const std::vector<Product*>& getProducts() const;
    Product* findProductByName(const std::string& name);

    // Методы для работы с категориями
    void addCategory(Category* category);
    const std::vector<Category*>& getCategories() const;
    Category* findCategoryByName(const std::string& name);

    // Методы для работы с заказами
    const std::vector<Order*>& getOrders() const;
    void addOrder(Order* order);

    // Методы для работы с корзиной
    void addToCart(Product* product, int quantity);
    void removeFromCart(Product* product);
    const Cart& getCurrentCart() const;
    void clearCart();

    // Методы для работы с покупателем
    void setCurrentCustomer(Customer* customer);
    Customer* getCurrentCustomer() const;

    // Методы отображения
    void displayProducts() const;
    void displayCategories() const;
    void displayCart() const;

    // Метод создания заказа
    void createOrder(Discount* discount = nullptr, PaymentMethod* paymentMethod = nullptr);

    ~CashRegister();
};