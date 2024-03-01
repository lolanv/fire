#ifndef VEHICLE_H
#define VEHICLE_H

#include <string>

class Vehicle {
protected:
    std::string _registration_number;
    std::string _brand;
    float _price;
public:
    Vehicle(const std::string& reg_number, const std::string& brand, float price);
    virtual ~Vehicle() = default;

    virtual float CalculateServicingCost() const = 0;
    virtual float TaxExemptionAmount() const;
    
    const std::string& GetRegistrationNumber() const { return _registration_number; }
    const std::string& GetBrand() const { return _brand; }
    float GetPrice() const { return _price; }

    //Vehicle()=delete;
    Vehicle(const Vehicle&) = delete;
    Vehicle& operator=(const Vehicle&) = delete;
    Vehicle(Vehicle&&) = delete;
    Vehicle& operator=(Vehicle&&) = delete;
    //~Vehicle()=default;
};

#endif // VEHICLE_H
