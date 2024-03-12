#include "Functionalities.h"
#include <iostream>
#include <algorithm>
#include <numeric>

Functionalities::Functionalities(std::array<std::shared_ptr<TransportVehicle>, 4> &vehicles)
    : _vehicles(vehicles) {}

void Functionalities::displayPermitNumber(int index)
{
    if (index >= 0 && index < _vehicles.size())
    {
        auto permit = _vehicles[index]->getPermit();
        if (permit)
        {
            std::cout << "Permit number at index " << index << ": " << permit->getPermitNumber() << std::endl;
        }
        else
        {
            std::cout << "No permit found at index " << index << std::endl;
        }
    }
    else
    {
        std::cout << "Invalid index" << std::endl;
    }
}

void Functionalities::displayAverageSeatCount(VehicleType vehicle_type)
{
    int count = 0;
    int total_seat_count = 0;

    for (const auto &vehicle : _vehicles)
    {
        if (vehicle->getVehicleType() == vehicle_type)
        {
            total_seat_count += vehicle->getSeatCount();
            ++count;
        }
    }

    if (count > 0)
    {
        double average_seat_count = static_cast<double>(total_seat_count) / count;
        std::cout << "Average seat count for " << static_cast<int>(vehicle_type) << ": " << average_seat_count << std::endl;
    }
    else
    {
        std::cout << "No vehicles of type " << static_cast<int>(vehicle_type) << " found" << std::endl;
    }
}

void Functionalities::checkAllSameVehicleType()
{
    if (_vehicles.empty())
    {
        std::cout << "No vehicles found" << std::endl;
        return;
    }

    VehicleType first_vehicle_type = _vehicles[0]->getVehicleType();
    bool all_same = std::all_of(_vehicles.begin() + 1, _vehicles.end(), [&](const auto &vehicle)
                                { return vehicle->getVehicleType() == first_vehicle_type; });

    std::cout << "All vehicles have the same type: " << std::boolalpha << all_same << std::endl;
}
