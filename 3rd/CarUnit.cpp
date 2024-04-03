#include "CarUnit.h"

std::ostream &operator<<(std::ostream &os, const CarUnit &rhs)
{
    os << "m_car_brand: " << rhs.m_car_brand
       << " m_car_price: " << rhs.m_car_price
       << " m_car_type: " << static_cast<int>(rhs.m_car_type)
       << " m_car_top_speed: " << rhs.m_car_top_speed
       << " m_car_rpm: " << rhs.m_car_rpm
       << " m_car_gear_system: " << static_cast<int>(rhs.m_car_gear_system);
    return os;
}

CarUnit::CarUnit(std::string car_brand, float car_price, CarType car_type, int car_top_speed, int car_rpm, CarGear car_gear_system)
    : m_car_brand(car_brand), m_car_price(car_price), m_car_type(car_type), m_car_top_speed(car_top_speed), m_car_rpm(car_rpm), m_car_gear_system(car_gear_system)
{
}
