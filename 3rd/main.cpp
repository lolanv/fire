#include <iostream>
#include "Functionalities.h"

int main()
{
    MapContainer data;
    CreateObjects(data);

    try
    {
        /* code */
        bool sameGearSystem = CheckSameGearSystem(data);
        if (sameGearSystem)
        {
            std::cout << "All instances have the same gear system are True" << std::endl<< std::endl;
        }
        else
        {
            std::cout << "All instances have the same gear system are False" << std::endl<< std::endl;
        }

        std::cout << "-----------------------------" << std::endl;

        MapContainer sedans = FindCarsByType(data, CarType::SEDAN);

        for (const auto &ptr : sedans)
        {
            std::cout << (*ptr.second) << std::endl<< std::endl;
        }

        std::cout << "-----------------------------" << std::endl;

        auto lowestPrice = FindLowestPrice(data);
        if (lowestPrice.has_value())
        {
            std::cout << "Lowest price: " << lowestPrice.value() << std::endl<< std::endl;
        }
        else
        {
            std::cout << "No cars found" << std::endl;
        }

        std::cout << "-----------------------------" << std::endl;

        std::string idToSearch = "car3";
        auto rpm = FindRpmById(data, idToSearch);
        if (rpm.has_value())
        {
            std::cout << "RPM : " << rpm.value() << std::endl<< std::endl;
        }
        else
        {
            std::cout << "ID not found" << std::endl<< std::endl;
        }

        std::cout << "-----------------------------" << std::endl;

        float threshold = 26000.0f;
        int countAboveThreshold = CountCarsAbovePrice(data, threshold);
        std::cout << "Number of cars above : " << countAboveThreshold << std::endl<< std::endl;
    }

    catch (Exception &e)
    {
        std::cerr << e.what() << '\n';
    }
}