#ifndef BIKE_H
#define BIKE_H

#include "Vehicle.h"

enum class BrakingSystem { ABS, TRADITIONAL };

class Bike : public Vehicle {
    BrakingSystem _braking_system;
public:
    Bike(const std::string& reg_number, const std::string& brand, float price, BrakingSystem braking_system);

    float CalculateServicingCost() const override;

    // Disable copy and move operations
    Bike(const Bike&) = delete;
    Bike& operator=(const Bike&) = delete;
    Bike(Bike&&) = delete;
    Bike& operator=(Bike&&) = delete;
};

#endif // BIKE_H
