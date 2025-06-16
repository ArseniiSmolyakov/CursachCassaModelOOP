#pragma once
#include <vector>
#include "Observer.h"

class Subject {
    std::vector<Observer*> observers;
public:
    void attach(Observer* observer);
    void notify(const std::string& message);
    virtual ~Subject() = default;
};