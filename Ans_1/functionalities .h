//functionalities.h
#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include "TransportVehicle.h"
#include <vector>
#include <thread>

// Find and display the permit number for the instance at index position N on console
void findPermitNumber(const std::vector<std::shared_ptr<TransportVehicle>>& vehicles, int index);

// Find and print average seat count for the specified vehicle type
void printAverageSeatCount(const std::vector<std::shared_ptr<TransportVehicle>>& vehicles, VehicleType type);

// Find and print true or false indicating whether all instances have the same vehicle type
void checkAllSameVehicleType(const std::vector<std::shared_ptr<TransportVehicle>>& vehicles);

#endif // FUNCTIONALITIES_H