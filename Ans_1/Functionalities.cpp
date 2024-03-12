#include "Functionalities.h"
#include <iostream>
#include <algorithm>
#include <numeric>

Functionalities::Functionalities(std::vector<SharedTransportVehicle> vehicles)
    : _vehicles(std::move(vehicles)) {}

std::optional<std::string> Functionalities::findPermitNumberAtIndex(int index) {
    if (index >= 0 && index < _vehicles.size()) {
        return _vehicles[index]->getPermit()->getPermitNumber();
    }
    return std::nullopt;
}

std::optional<double> Functionalities::calculateAverageSeatCount(const std::string& vehicleType) {
    std::vector<int> seatCounts;

    // Capture the seat count of each TransportVehicle
    std::transform(_vehicles.begin(), _vehicles.end(), std::back_inserter(seatCounts),
                   [&vehicleType](const auto& vehicle) {
                       return (vehicle->getVehicleType() == vehicleType) ? vehicle->getSeatCount() : 0;
                   });

    if (seatCounts.empty()) {
        return std::nullopt;
    }

    // Calculate average seat count
    double averageSeatCount = std::accumulate(seatCounts.begin(), seatCounts.end(), 0.0) / seatCounts.size();
    return averageSeatCount;
}

bool Functionalities::areAllVehicleTypesSame() {
    if (_vehicles.size() < 2) {
        return true;
    }

    const std::string& firstVehicleType = _vehicles.front()->getVehicleType();
    return std::all_of(_vehicles.begin() + 1, _vehicles.end(),
                       [&firstVehicleType](const auto& vehicle) { return vehicle->getVehicleType() == firstVehicleType; });
}
