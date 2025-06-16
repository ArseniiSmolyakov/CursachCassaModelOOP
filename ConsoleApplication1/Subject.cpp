#include "Subject.h"

void Subject::attach(Observer* observer) {
    observers.push_back(observer);
}

void Subject::notify(const std::string& message) {
    for (auto observer : observers) {
        observer->update(message);
    }
}