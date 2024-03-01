#include "Functionalities.h"
#include "Car.h"
#include "Bike.h"
#include <iostream>

void CreateVehicles(std::vector<std::shared_ptr<Vehicle>>& vehicles) {
    vehicles.push_back(std::make_shared<Car>(
    "Nexon", 
    "Tata", 
    10000,
     CarType::COMMUTE));
    vehicles.push_back(std::make_shared<Car>(
      "XYZ",
     "Honda", 
     310000,
      CarType::COMMERCIAL));
    vehicles.push_back(std::make_shared<Bike>(
    "Activa", "Honda", 110000, BrakingSystem::ABS));
    vehicles.push_back(std::make_shared<Bike>(
    "BIKE002",
     "Suzuki", 
     15000, 
     BrakingSystem::TRADITIONAL));
}

void PrintServiceCost(const std::vector<std::shared_ptr<Vehicle>>& vehicles) {
    if (vehicles.empty()) {
        std::cout << "No vehicles" << std::endl;
        return;
    }
    std::cout << "Service Cost for First Vehicle: " << vehicles.front()->CalculateServicingCost() << std::endl;
    std::cout << "Service Cost for Last Vehicle: " << vehicles.back()->CalculateServicingCost() << std::endl;
}


void PrintServiceCost(const std::vector<std::shared_ptr<Vehicle>>& vehicles) {
    if (vehicles.empty()) {
        std::cout << "No vehicles" << std::endl;
        return;
    }
    std::cout << "Service Cost for First Vehicle: " << vehicles.front()->CalculateServicingCost() << std::endl;
    std::cout << "Service Cost for Last Vehicle: " << vehicles.back()->CalculateServicingCost() << std::endl;
}

void PrintTaxExemptionAmount(const std::vector<std::shared_ptr<Vehicle>>& vehicles) {
    if (vehicles.empty()) {
        std::cout << "No vehicles found for tax exemption" << std::endl;
        return;
    }
    for (const auto& vehicle : vehicles) {
        std::shared_ptr<Car> car = std::dynamic_pointer_cast<Car>(vehicle);
        if (car) {
            std::cout << "Tax Exemption Amount for Car: " << car->TaxExemptionAmount() << std::endl;
        }
    }
}

void DisplayVehicleInfo(const std::vector<std::shared_ptr<Vehicle>>& vehicles, const std::string& reg_number) {
    if (vehicles.empty()) {
        std::cout << "No vehicles to display information." << std::endl;
        return;
    }
    bool found = false;
    for (const auto& vehicle : vehicles) {
        if (vehicle->GetRegistrationNumber() == reg_number) {
            std::shared_ptr<Car> car = std::dynamic_pointer_cast<Car>(vehicle);
            if (car) {
                std::cout << "Type: Car, Brand: " << car->GetBrand() << ", Registration Number: " << car->GetRegistrationNumber() << ", Price: " << car->GetPrice() << std::endl;
                std::cout << "Tax Exemption Amount: " << car->TaxExemptionAmount() << std::endl;
            } else {
                std::shared_ptr<Bike> bike = std::dynamic_pointer_cast<Bike>(vehicle);
                if (bike) {
                    std::cout << "Type: Bike, Brand: " << bike->GetBrand() << ", Registration Number: " << bike->GetRegistrationNumber() << ", Price: " << bike->GetPrice() << std::endl;
                    std::cout << "Servicing Cost: " << bike->CalculateServicingCost() << std::endl;
                }
            }
            found = true;
            break;
        }
    }
    if (!found) {
        std::cout << "Vehicle with registration number " << reg_number << " not found." << std::endl;
    }
}

void DestroyVehicles(std::vector<std::shared_ptr<Vehicle>>& vehicles) {
    std::cout << "Destroying vehicles..." << std::endl;
    vehicles.clear(); 
    std::cout << "All vehicles destroyed." << std::endl;
}





