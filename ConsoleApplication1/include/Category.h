#pragma once
#include <string>
#include <iostream>

class Category {
    std::string name;
    std::string description;
public:
    Category(const std::string& name, const std::string& description);
    std::string getName() const;
    std::string getDescription() const;
    void display() const;
};