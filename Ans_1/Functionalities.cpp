#include "Functionalities.h"
#include "TransportVehicle.h"

#include <algorithm>
#include <numeric>
#include <iostream>

void createTransportVehicles(std::vector<std::shared_ptr<TransportVehicle>> &vehicles)
{
    // Create permits
    auto permit1 = std::make_shared<Permit>("P1", 12);
    auto permit2 = std::make_shared<Permit>("P2", 6);
    auto permit3 = std::make_shared<Permit>("P3", 9);
    auto permit4 = std::make_shared<Permit>("P4", 8);

    // Create transport vehicles
    vehicles.push_back(std::make_shared<TransportVehicle>(permit1, "BUS", 50, 10));
    vehicles.push_back(std::make_shared<TransportVehicle>(permit2, "CAB", 4, 5));
    vehicles.push_back(std::make_shared<TransportVehicle>(permit3, "MINI_VAN", 8, 7));
    vehicles.push_back(std::make_shared<TransportVehicle>(permit4, "BUS", 40, 8));
}

void findAndDisplayPermitNumber(const std::vector<std::shared_ptr<TransportVehicle>> &vehicles, int index)
{
    if (index >= 0 && index < vehicles.size())
    {
        std::cout << "Permit number at index " << index << ": " << vehicles[index]->getPermit()->getPermitNumber() << std::endl;
    }
    else
    {
        std::cout << "Invalid index." << std::endl;
    }
}

void findAndPrintAverageSeatCount(const std::vector<std::shared_ptr<TransportVehicle>> &vehicles, const std::string &vehicle_type)
{
    std::vector<int> seat_counts;
    for (const auto &vehicle : vehicles)
    {
        if (vehicle->getVehicleType() == vehicle_type)
        {
            seat_counts.push_back(vehicle->getSeatCount());
        }
    }

    if (!seat_counts.empty())
    {
        double average_seat_count = std::accumulate(seat_counts.begin(), seat_counts.end(), 0.0) / seat_counts.size();
        std::cout << "Average seat count for " << vehicle_type << ": " << average_seat_count << std::endl;
    }
    else
    {
        std::cout << "No vehicles of type " << vehicle_type << " found." << std::endl;
    }
}

void findAndPrintSameVehicleType(const std::vector<std::shared_ptr<TransportVehicle>> &vehicles)
{
    if (vehicles.empty())
    {
        std::cout << "No vehicles found." << std::endl;
        return;
    }

    std::string first_vehicle_type = vehicles[0]->getVehicleType();
    bool all_same = std::all_of(vehicles.begin() + 1, vehicles.end(),
                                [&first_vehicle_type](const auto &vehicle)
                                {
                                    return vehicle->getVehicleType() == first_vehicle_type;
                                });

    std::cout << "All vehicles have the same vehicle type: " << std::boolalpha << all_same << std::endl;
}
