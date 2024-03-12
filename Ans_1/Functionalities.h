#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include <vector>
#include <thread>
#include <string>

class TransportVehicle;

void createTransportVehicles(std::vector<std::shared_ptr<TransportVehicle>> &vehicles);

void findAndDisplayPermitNumber(const std::vector<std::shared_ptr<TransportVehicle>> &vehicles, int index);

void findAndPrintAverageSeatCount(const std::vector<std::shared_ptr<TransportVehicle>> &vehicles, const std::string &vehicle_type);

void findAndPrintSameVehicleType(const std::vector<std::shared_ptr<TransportVehicle>> &vehicles);

#endif // FUNCTIONALITIES_H
