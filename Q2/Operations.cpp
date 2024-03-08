#include "Operations.h"
#include <iostream>
#include <algorithm>
#include <numeric>

std::unique_ptr<Operations> Operations::instance = nullptr;

Operations::Operations() : _N(0) {}

Operations& Operations::getInstance() {
    if (!instance) {
        instance = std::unique_ptr<Operations>(new Operations());
    }
    return *instance;
}

void Operations::createEngine(EngineType type, float horsepower, EngineCylinder cylinder, float torque) {
    // Hardcoded engine number for uniqueness
    std::string engineNumber = "ENG" + std::to_string(_data_container.size() + 1);

    // Check if the engine number already exists
    auto existingEngine = std::find_if(_data_container.begin(), _data_container.end(),
        [engineNumber](const auto& engine) { return engine->getEngineNumber() == engineNumber; });

    if (existingEngine != _data_container.end()) {
        throw std::runtime_error("Engine with the same number already exists.");
    }

    auto newEngine = std::make_shared<Engine>(type, horsepower, engineNumber, cylinder, torque);
    _data_container.push_back(newEngine);
}

std::string Operations::findMaxHorsepowerEngineNumber() const {
    if (_data_container.empty()) {
        throw std::runtime_error("No engines in the data container.");
    }

    auto maxHorsepowerEngine = std::max_element(_data_container.begin(), _data_container.end(),
        [](const auto& a, const auto& b) {
            return a->getEngineHorsepower() < b->getEngineHorsepower();
        });

    return (*maxHorsepowerEngine)->getEngineNumber();
}

std::array<float, 2> Operations::getFirstLastTorque() const {
    if (_data_container.size() < 2) {
        throw std::runtime_error("Insufficient engines in the data container.");
    }

    return { _data_container[0]->getEngineTorque(), _data_container.back()->getEngineTorque() };
}

float Operations::getAverageTorque() const {
    if (_data_container.empty()) {
        throw std::runtime_error("No engines in the data container.");
    }

    float totalTorque = std::accumulate(_data_container.begin(), _data_container.end(), 0.0f,
        [](float sum, const auto& engine) {
            return sum + engine->getEngineTorque();
        });

    return totalTorque / _data_container.size();
}

void Operations::setUserInput() {
    std::cout << "Enter a value for _N: ";
    std::cin >> _N;
}

std::vector<EngineType> Operations::getEngineTypesForFirstN() const {
    if (_data_container.size() < _N) {
        throw std::runtime_error("_N is greater than the number of engines in the data container.");
    }

    std::vector<EngineType> engineTypes;
    for (int i = 0; i < _N; ++i) {
        engineTypes.push_back(_data_container[i]->getEngineType());
    }

    return engineTypes;
}
