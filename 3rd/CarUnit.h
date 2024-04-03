#ifndef CARUNIT_H
#define CARUNIT_H

#include <iostream>
#include "CarType.h"
#include "CarGear.h"

class CarUnit
{
private:
    /* data */
    std::string m_car_brand;
    float m_car_price;
    CarType m_car_type;
    int m_car_top_speed;
    int m_car_rpm;
    CarGear m_car_gear_system;

public:
    CarUnit() = default;                     // default constructor is defaulted
    CarUnit(CarUnit &) = delete;             // copy constructor is deleted
    CarUnit(CarUnit &&) = default;           // move constructor is defaulted
    CarUnit &operator=(CarUnit &) = delete;  // Copy Assignment Operator
    CarUnit &operator=(CarUnit &&) = delete; // Move Assignment Operator
    ~CarUnit() = default;                    // destructor is defaulted

    CarUnit(std::string car_brand,
            float car_price,
            CarType car_type,
            int car_top_speed,
            int car_rpm,
            CarGear car_gear_system);

    std::string carBrand() const { return m_car_brand; }
    void setCarBrand(const std::string &car_brand) { m_car_brand = car_brand; }

    float carPrice() const { return m_car_price; }
    void setCarPrice(float car_price) { m_car_price = car_price; }

    CarType carType() const { return m_car_type; }
    void setCarType(const CarType &car_type) { m_car_type = car_type; }

    int carTopSpeed() const { return m_car_top_speed; }
    void setCarTopSpeed(int car_top_speed) { m_car_top_speed = car_top_speed; }

    int carRpm() const { return m_car_rpm; }
    void setCarRpm(int car_rpm) { m_car_rpm = car_rpm; }

    CarGear carGearSystem() const { return m_car_gear_system; }
    void setCarGearSystem(const CarGear &car_gear_system) { m_car_gear_system = car_gear_system; }

    friend std::ostream &operator<<(std::ostream &os, const CarUnit &rhs);
};

#endif // CARUNIT_H
