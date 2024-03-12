#pragma once

#include <array>
#include <memory>
#include <thread>
#include "TransportVehicle.h"

class Functionalities
{
public:
    Functionalities(std::array<std::shared_ptr<TransportVehicle>, 4> &vehicles);

    void displayPermitNumber(int index);
    void displayAverageSeatCount(VehicleType vehicle_type);
    void checkAllSameVehicleType();

private:
    std::array<std::shared_ptr<TransportVehicle>, 4> &_vehicles;
};
