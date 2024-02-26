#include "functionalities.h"
#include <stdexcept>

std::vector<std::unique_ptr<Automobile>> createAutomobiles() {
    std::vector<std::unique_ptr<Automobile>> automobiles;
    automobiles.push_back(std::make_unique<Automobile>("Toyota", "private", 25000, 20));
    automobiles.push_back(std::make_unique<Automobile>("Honda", "TRANSPORT", 18000, 25));
    automobiles.push_back(std::make_unique<Automobile>("BMW", "private", 30000, 18));
    automobiles.push_back(std::make_unique<Automobile>("Tesla", "TRANSPORT", 40000, 30));
    return automobiles;
}

float averageMileage(const std::vector<std::unique_ptr<Automobile>>& automobiles) {
    if (automobiles.empty()) {
        throw std::invalid_argument("No automobiles in the container");
    }

    float totalMileage = 0;
    for (const auto& auto_ptr : automobiles) {
        totalMileage += auto_ptr->getAutomobileMileage();
    }

    return totalMileage / automobiles.size();
}

int countAutomobileType(const std::vector<std::unique_ptr<Automobile>>& automobiles, const std::string& type) {
    int count = 0;
    for (const auto& auto_ptr : automobiles) {
        if (auto_ptr->getAutomobileType() == type) {
            count++;
        }
    }
    return count;
}

bool hasPriceAbove(const std::vector<std::unique_ptr<Automobile>>& automobiles, float priceThreshold) {
    for (const auto& auto_ptr : automobiles) {
        if (auto_ptr->getAutomobilePrice() > priceThreshold) {
            return true;
        }
    }
    return false;
}

void destroyAutomobiles(std::vector<std::unique_ptr<Automobile>>& automobiles) {
    automobiles.clear(); // Automatically deallocate memory
}
