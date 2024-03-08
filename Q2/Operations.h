#ifndef OPERATIONS_H
#define OPERATIONS_H

#include <vector>
#include <memory>
#include <array>

#include "Engine.h"

class Operations {
private:
    static std::unique_ptr<Operations> instance;
    int _N;
    std::vector<std::shared_ptr<Engine>> _data_container;

    Operations();

public:
    static Operations& getInstance();
    void createEngine(EngineType type, float horsepower, EngineCylinder cylinder, float torque);
    std::string findMaxHorsepowerEngineNumber() const;
    std::array<float, 2> getFirstLastTorque() const;
    float getAverageTorque() const;
    void setUserInput();
    std::vector<EngineType> getEngineTypesForFirstN() const;
    int getN() const { return _N; }
};

#endif // OPERATIONS_H
