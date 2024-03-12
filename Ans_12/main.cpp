#include <iostream>
#include <memory>
#include <array>
#include <thread>
#include "Functionalities.h"

int main()
{
    std::array<std::shared_ptr<TransportVehicle>, 4> vehicles;
    vehicles[0] = std::make_shared<TransportVehicle>(std::make_shared<Permit>("123", 6), VehicleType::BUS, 50, 10);
    vehicles[1] = std::make_shared<TransportVehicle>(std::make_shared<Permit>("456", 8), VehicleType::CAB, 4, 5);
    vehicles[2] = std::make_shared<TransportVehicle>(std::make_shared<Permit>("789", 5), VehicleType::MINI_VAN, 8, 8);
    vehicles[3] = std::make_shared<TransportVehicle>(std::make_shared<Permit>("101", 9), VehicleType::BUS, 40, 12);

    Functionalities functionalities(vehicles);

    std::thread thread1([&]()
                        { functionalities.displayPermitNumber(1); });

    std::thread thread2([&]()
                        { functionalities.displayAverageSeatCount(VehicleType::BUS); });

    std::thread thread3([&]()
                        { functionalities.checkAllSameVehicleType(); });

    thread1.join();
    thread2.join();
    thread3.join();

    return 0;
}
