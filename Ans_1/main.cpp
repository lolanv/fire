#include "TransportVehicle.h"
#include "Permit.h"
#include "Functionalities.h"

#include <iostream>
#include <vector>
#include <memory>
#include <thread>

int main()
{
    std::vector<std::shared_ptr<TransportVehicle>> vehicles;
    createTransportVehicles(vehicles);

    std::thread t1(findAndDisplayPermitNumber, std::ref(vehicles), 2);
    std::thread t2(findAndPrintAverageSeatCount, std::ref(vehicles), "BUS");
    std::thread t3(findAndPrintSameVehicleType, std::ref(vehicles));

    t1.join();
    t2.join();
    t3.join();

    return 0;
}


// To run command
// g++ - std = c++ 17 - pthread *.cpp - o out && ./out