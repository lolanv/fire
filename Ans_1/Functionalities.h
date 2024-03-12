#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include "TransportVehicle.h"
#include <vector>
#include <thread>
#include <optional>

class Functionalities {
public:
    using SharedTransportVehicle = std::shared_ptr<TransportVehicle>;

    Functionalities(std::vector<SharedTransportVehicle> vehicles);

    std::optional<std::string> findPermitNumberAtIndex(int index);
    std::optional<double> calculateAverageSeatCount(const std::string& vehicleType);
    bool areAllVehicleTypesSame();

private:
    std::vector<SharedTransportVehicle> _vehicles;
};

#endif // FUNCTIONALITIES_H
