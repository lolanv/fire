#include "Functionalities.h"
#include <thread>
#include<iostream>

int main() {
    // Create instances of TransportVehicle on the heap
    std::vector<Functionalities::SharedTransportVehicle> vehicles;
    vehicles.push_back(std::make_shared<TransportVehicle>(
        std::make_shared<Permit>("P001", 6), "BUS", 50, 10));
    vehicles.push_back(std::make_shared<TransportVehicle>(
        std::make_shared<Permit>("P002", 8), "CAB", 4, 5));
    vehicles.push_back(std::make_shared<TransportVehicle>(
        std::make_shared<Permit>("P003", 4), "MINI_VAN", 8, 8));
    vehicles.push_back(std::make_shared<TransportVehicle>(
        std::make_shared<Permit>("P004", 10), "BUS", 40, 12));

    // Create an instance of Functionalities
    Functionalities functionalities(vehicles);

    // Execute each functionality in a separate thread
    std::thread thread1([&functionalities]() {
        std::optional<std::string> permitNumber = functionalities.findPermitNumberAtIndex(2);
        if (permitNumber) {
            std::cout << "Permit number at index 2: " << *permitNumber << std::endl;
        } else {
            std::cout << "Invalid index." << std::endl;
        }
    });

    std::thread thread2([&functionalities]() {
        std::optional<double> averageSeatCount = functionalities.calculateAverageSeatCount("BUS");
        if (averageSeatCount) {
            std::cout << "Average seat count for BUS: " << *averageSeatCount << std::endl;
        } else {
            std::cout << "No vehicles of type BUS found." << std::endl;
        }
    });

    std::thread thread3([&functionalities]() {
        bool allSame = functionalities.areAllVehicleTypesSame();
        std::cout << "All vehicle types are the same: " << std::boolalpha << allSame << std::endl;
    });

    // Join threads
    thread1.join();
    thread2.join();
    thread3.join();

    return 0;
}
