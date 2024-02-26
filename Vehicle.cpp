#include "Vehicle.h"

Vehicle::Vehicle(const std::string& reg_number, const std::string& brand, float price)
    : _registration_number(reg_number), _brand(brand), _price(price) {}

float Vehicle::TaxExemptionAmount() const {
    return 0.05f * _price;
}
