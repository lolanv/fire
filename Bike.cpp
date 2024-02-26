#include "Bike.h"

Bike::Bike(const std::string& reg_number, const std::string& brand, float price, BrakingSystem braking_system)
    : Vehicle(reg_number, brand, price), _braking_system(braking_system) {}

float Bike::CalculateServicingCost() const {
    float servicing_cost = 0.25f * _price;
    return servicing_cost + 0.18f * servicing_cost;
}
