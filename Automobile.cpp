#include "Automobile.h"

// Parameterized Constructor
Automobile::Automobile(std::string model_name, std::string automobile_type, float automobile_price, float automobile_mileage)
    : _model_name(model_name), _automobile_type(automobile_type), _automobile_price(automobile_price), _automobile_mileage(automobile_mileage) {}

// Getter for automobile price
float Automobile::getAutomobilePrice() const {
    return _automobile_price;
}

// Getter for automobile type
std::string Automobile::getAutomobileType() const {
    return _automobile_type;
}

// Getter for automobile mileage
float Automobile::getAutomobileMileage() const {
    return _automobile_mileage;
}
