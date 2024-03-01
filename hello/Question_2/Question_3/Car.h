#ifndef CAR_H
#define CAR_H

#include "Vehicle.h"
#include "Enum.h"

//enum class CarType { COMMUTE, COMMERCIAL, TRANSPORT };

class Car : public Vehicle {
    CarType _car_type;
public:
    Car(const std::string& reg_number, const std::string& brand, float price, CarType car_type);

    float CalculateServicingCost() const override;
    float TaxExemptionAmount() const override;

    // Disable copy and move operations
    Car(const Car&) = delete;
    Car& operator=(const Car&) = delete;
    Car(Car&&) = delete;
    Car& operator=(Car&&) = delete;
};

#endif // CAR_H
