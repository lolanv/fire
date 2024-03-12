//Functionalities.cpp
#include "functionalities .h"
#include "Permit.h"
#include <iostream>
#include <thread>
#include <vector>
#include <algorithm>
#include <numeric>

void findPermitNumber(const std::vector<std::shared_ptr<TransportVehicle>>& vehicles, int index) {
    if (index < vehicles.size()) {
        auto permit = vehicles[index]->getPermit();
        if (permit)
            std::cout << "Permit number at index " << index << ": " << permit->getPermitNumber() << std::endl;
        else
            std::cout << "No permit found at index " << index << std::endl;
    } else {
        std::cout << "Index out of range." << std::endl;
    }
}

void printAverageSeatCount(const std::vector<std::shared_ptr<TransportVehicle>>& vehicles, VehicleType type) {
    std::vector<int> seatCounts;
    for (const auto& vehicle : vehicles) {
        if (vehicle->getVehicleType() == type) {
            seatCounts.push_back(vehicle->getSeatCount());
        }
    }

    if (!seatCounts.empty()) {
        double average = std::accumulate(seatCounts.begin(), seatCounts.end(), 0.0) / seatCounts.size();
        std::cout << "Average seat count for type \n";
        switch (type) {
            case VehicleType::BUS:
                std::cout << "BUS";
                break;
            case VehicleType::CAB:
                std::cout << "CAB";
                break;
            case VehicleType::MINI_VAN:
                std::cout << "MINI_VAN";
                break;
        }
        std::cout << ": " << average << std::endl;
    } else {
        std::cout << "No vehicles of type ";
        switch (type) {
            case VehicleType::BUS:
                std::cout << "BUS";
                break;
            case VehicleType::CAB:
                std::cout << "CAB";
                break;
            case VehicleType::MINI_VAN:
                std::cout << "MINI_VAN";
                break;
        }
        std::cout << " found." << std::endl;
    }
}

void checkAllSameVehicleType(const std::vector<std::shared_ptr<TransportVehicle>>& vehicles) {
    VehicleType firstType = vehicles[0]->getVehicleType();
    bool allSame = std::all_of(vehicles.begin() + 1, vehicles.end(),
                               [firstType](const std::shared_ptr<TransportVehicle>& vehicle) {
                                   return vehicle->getVehicleType() == firstType;
                               });
    std::cout << "All instances have the same vehicle type: " << (allSame ? "true" : "false") << std::endl;
}