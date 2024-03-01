#include "Functionalities.h"
#include "Car.h"
#include "Bike.h"
#include <iostream>
#include <memory>

int main() {
    std::vector<std::shared_ptr<Vehicle>> vehicles;
    CreateVehicles(vehicles);

    PrintServiceCost(vehicles);
    PrintTaxExemptionAmount(vehicles);
    DisplayVehicleInfo(vehicles, "XYZ");

    DestroyVehicles(vehicles);

    return 0;
}
