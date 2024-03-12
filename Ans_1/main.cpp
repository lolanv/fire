//Main.cpp
#include "TransportVehicle.h"
#include "functionalities .h"
#include "Permit.h"
#include <memory>
#include <thread>
#include <vector>

int main() {
    // Creating permits
    std::shared_ptr<Permit> permit1 = std::make_shared<Permit>("P123", 6);
    std::shared_ptr<Permit> permit2 = std::make_shared<Permit>("P456", 9);
    std::shared_ptr<Permit> permit3 = std::make_shared<Permit>("P789", 12);
    std::shared_ptr<Permit> permit4 = std::make_shared<Permit>("P012", 6);

    // Creating transport vehicles
    std::vector<std::shared_ptr<TransportVehicle>> vehicles;
    vehicles.push_back(std::make_shared<TransportVehicle>(permit1, VehicleType::BUS, 50, 10));
    vehicles.push_back(std::make_shared<TransportVehicle>(permit2, VehicleType::CAB, 4, 5));
    vehicles.push_back(std::make_shared<TransportVehicle>(permit3, VehicleType::MINI_VAN, 8, 8));
    vehicles.push_back(std::make_shared<TransportVehicle>(permit4, VehicleType::BUS, 40, 7));

    // Execute each functionality in a separate thread
    std::vector<std::thread> threads;
    threads.push_back(std::thread(findPermitNumber, std::ref(vehicles), 2)); // Find permit number at index 2
    threads.push_back(std::thread(printAverageSeatCount, std::ref(vehicles), VehicleType::CAB)); // Print average seat count for BUS
    threads.push_back(std::thread(checkAllSameVehicleType, std::ref(vehicles))); // Check if all vehicles have the same type

    // Join all threads
    for (auto& thread : threads) {
        thread.join();
    }

    return 0;
}
