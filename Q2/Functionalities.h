#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include <future>
#include <iostream>
#include "Operations.h"

namespace Functionalities
{
    void createEnginesAsync()
    {
        std::future<void> createEngine1 = std::async(std::launch::async, []()
                                                     { Operations::getInstance().createEngine(TURBOCHARGED, 300.0f, CYLINDER_4, 400.0f); });

        std::future<void> createEngine2 = std::async(std::launch::async, []()
                                                     { Operations::getInstance().createEngine(REGULAR, 250.0f, CYLINDER_6, 350.0f); });

        // Wait for engine creation threads to finish
        createEngine1.get();
        createEngine2.get();
    }

    void findMaxHorsepowerEngineNumberAsync()
    {
        std::future<std::string> maxHorsepowerEngineNumber = std::async(std::launch::async, []()
                                                                        { return Operations::getInstance().findMaxHorsepowerEngineNumber(); });

        std::cout << "Engine with maximum horsepower: " << maxHorsepowerEngineNumber.get() << std::endl;
    }

    void getFirstLastTorqueAsync()
    {
        std::future<std::array<float, 2>> firstLastTorque = std::async(std::launch::async, []()
                                                                       { return Operations::getInstance().getFirstLastTorque(); });

        auto torqueArray = firstLastTorque.get();
        std::cout << "First Torque: " << torqueArray[0] << ", Last Torque: " << torqueArray[1] << std::endl;
    }

    void getAverageTorqueAsync()
    {
        std::future<float> averageTorque = std::async(std::launch::async, []()
                                                      { return Operations::getInstance().getAverageTorque(); });

        std::cout << "Average Torque: " << averageTorque.get() << std::endl;
    }

    void setUserInputAsync()
    {
        Operations::getInstance().setUserInput();
    }

    void getEngineTypesForFirstNAsync()
    {
        std::future<std::vector<EngineType>> engineTypesForFirstN = std::async(std::launch::async, []()
                                                                               { return Operations::getInstance().getEngineTypesForFirstN(); });

        auto typesForFirstN = engineTypesForFirstN.get();
        std::cout << "Engine types for first " << Operations::getInstance().getN() << " instances: ";
        for (const auto &type : typesForFirstN)
        {
            std::cout << type << " ";
        }
        std::cout << std::endl;
    }
}

#endif // FUNCTIONALITIES_H
