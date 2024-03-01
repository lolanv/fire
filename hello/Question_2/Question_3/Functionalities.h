#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include "Vehicle.h"
#include <vector>
#include <memory>

void CreateVehicles(std::vector<std::shared_ptr<Vehicle>>& vehicles);
void PrintServiceCost(const std::vector<std::shared_ptr<Vehicle>>& vehicles);
void PrintTaxExemptionAmount(const std::vector<std::shared_ptr<Vehicle>>& vehicles);
void DisplayVehicleInfo(const std::vector<std::shared_ptr<Vehicle>>& vehicles, const std::string& reg_number);
void DestroyVehicles(std::vector<std::shared_ptr<Vehicle>>& vehicles);

#endif // FUNCTIONALITIES_H
