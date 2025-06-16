#include <iostream>
#include <string>
#include <memory>
#include "CashRegister.h"
#include "Inventory.h"
#include "Customer.h"
#include "Menu.h"
#include "DiscountStrategy.h"
#include "PaymentMethod.h"


class NoDiscount : public DiscountStrategy {
public:
    double applyDiscount(double originalPrice) override { return originalPrice; }
    std::string getDescription() override { return "Без скидки"; }
};

class PercentageDiscount : public DiscountStrategy {
    double percentage;
public:
    PercentageDiscount(double percentage) : percentage(percentage) {}
    double applyDiscount(double originalPrice) override {
        return originalPrice * (1 - percentage / 100);
    }
    std::string getDescription() override {
        return "Скидка " + std::to_string(percentage) + "%";
    }
};

class FixedDiscount : public DiscountStrategy {
    double amount;
public:
    FixedDiscount(double amount) : amount(amount) {}
    double applyDiscount(double originalPrice) override {
        return std::max(0.0, originalPrice - amount);
    }
    std::string getDescription() override {
        return "Фиксированная скидка " + std::to_string(amount);
    }
};

class CashPayment : public PaymentMethod {
public:
    bool pay(double amount) override {
        std::cout << "Оплачено наличными: " << amount << std::endl;
        return true;
    }
    std::string getName() override { return "Наличные"; }
};

class CardPayment : public PaymentMethod {
public:
    bool pay(double amount) override {
        std::cout << "Оплачено картой: " << amount << std::endl;
        return true;
    }
    std::string getName() override { return "Карта"; }
};

int main() {
    setlocale(LC_ALL, "RU");

    CashRegister cashRegister;
    Inventory inventory;
    Customer customer("Иван Иванов");
    cashRegister.setCurrentCustomer(&customer);

    int choice;
    do {
        displayMenu();
        std::cin >> choice;
        std::cin.ignore();

        switch (choice) {
        case 1: {
            cashRegister.displayCategories();
            break;
        }
        case 2: {
            std::string name, description;
            std::cout << "Введите название категории: ";
            std::getline(std::cin, name);
            std::cout << "Введите описание категории: ";
            std::getline(std::cin, description);

            Category* newCategory = new Category(name, description);
            cashRegister.addCategory(newCategory);
            std::cout << "Категория добавлена\n";
            break;
        }
        case 3: {
            cashRegister.displayProducts();
            break;
        }
        case 4: {
            std::string name, categoryName;
            double price;
            int quantity;

            std::cout << "Введите название товара: ";
            std::getline(std::cin, name);
            std::cout << "Введите цену товара: ";
            std::cin >> price;
            std::cin.ignore();
            std::cout << "Введите количество товара: ";
            std::cin >> quantity;
            std::cin.ignore();
            std::cout << "Введите название категории: ";
            std::getline(std::cin, categoryName);

            Category* category = cashRegister.findCategoryByName(categoryName);
            if (category) {
                Product* newProduct = new Product(name, price, category, quantity);
                cashRegister.addProduct(newProduct);
                inventory.addProduct(newProduct);
                std::cout << "Товар добавлен\n";
            }
            else {
                std::cout << "Категория не найдена\n";
            }
            break;
        }
        case 5: {
            std::string productName;
            int quantity;

            std::cout << "Введите название товара: ";
            std::getline(std::cin, productName);
            std::cout << "Введите новое количество: ";
            std::cin >> quantity;
            std::cin.ignore();

            Product* product = cashRegister.findProductByName(productName);
            if (product) {
                inventory.updateStock(product, quantity);
                std::cout << "Количество товара обновлено\n";
            }
            else {
                std::cout << "Товар не найден\n";
            }
            break;
        }
        case 6: {
            cashRegister.displayCart();
            break;
        }
        case 7: {
            std::string productName;
            int quantity;

            std::cout << "Введите название товара: ";
            std::getline(std::cin, productName);
            std::cout << "Введите количество: ";
            std::cin >> quantity;
            std::cin.ignore();

            Product* product = cashRegister.findProductByName(productName);
            if (product) {
                cashRegister.addToCart(product, quantity);
            }
            else {
                std::cout << "Товар не найден\n";
            }
            break;
        }
        case 8: {
            std::string productName;

            std::cout << "Введите название товара: ";
            std::getline(std::cin, productName);

            Product* product = cashRegister.findProductByName(productName);
            if (product) {
                cashRegister.removeFromCart(product);
            }
            else {
                std::cout << "Товар не найден\n";
            }
            break;
        }
        case 9: {
            int discountChoice, paymentChoice;
            Discount* discount = nullptr;
            PaymentMethod* paymentMethod = nullptr;

            std::cout << "Выберите скидку:\n";
            std::cout << "1. Без скидки\n";
            std::cout << "2. Процентная скидка\n";
            std::cout << "3. Фиксированная скидка\n";
            std::cout << "Ваш выбор: ";
            std::cin >> discountChoice;
            std::cin.ignore();

            if (discountChoice == 2) {
                double percentage;
                std::cout << "Введите процент скидки: ";
                std::cin >> percentage;
                std::cin.ignore();
                discount = new Discount(new PercentageDiscount(percentage));
            }
            else if (discountChoice == 3) {
                double amount;
                std::cout << "Введите сумму скидки: ";
                std::cin >> amount;
                std::cin.ignore();
                discount = new Discount(new FixedDiscount(amount));
            }
            else {
                discount = new Discount(new NoDiscount());
            }

            std::cout << "Выберите способ оплаты:\n";
            std::cout << "1. Наличные\n";
            std::cout << "2. Карта\n";
            std::cout << "Ваш выбор: ";
            std::cin >> paymentChoice;
            std::cin.ignore();

            if (paymentChoice == 1) {
                paymentMethod = new CashPayment();
            }
            else if (paymentChoice == 2) {
                paymentMethod = new CardPayment();
            }
            else {
                std::cout << "Неверный выбор, используется оплата наличными\n";
                paymentMethod = new CashPayment();
            }

            cashRegister.createOrder(discount, paymentMethod);
            break;
        }
        case 10: {
            customer.displayOrderHistory();
            break;
        }
        case 11: {
            inventory.displayInventory();
            break;
        }
        case 0: {
            std::cout << "Выход из программы\n";
            break;
        }
        default: {
            std::cout << "Неверный выбор\n";
            break;
        }
        }
    } while (choice != 0);

    return 0;
}