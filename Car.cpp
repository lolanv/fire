#include "Car.h"

Car::Car(const std::string& reg_number, const std::string& brand, float price, CarType car_type)
    : Vehicle(reg_number, brand, price), _car_type(car_type) {}

float Car::CalculateServicingCost() const {
    return 0.08f * _price;
}

float Car::TaxExemptionAmount() const {
    if (_car_type == CarType::COMMUTE)
        return -0.20f * _price;
    else
        return 0.15f * _price;
}
