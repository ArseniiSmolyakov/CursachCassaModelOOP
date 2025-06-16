#include "Category.h"

Category::Category(const std::string& name, const std::string& description)
    : name(name), description(description) {
}

std::string Category::getName() const { return name; }
std::string Category::getDescription() const { return description; }

void Category::display() const {
    std::cout << "Категория: " << name << "\nОписание: " << description << std::endl;
}