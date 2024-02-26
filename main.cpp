#include <iostream>
#include "Automobile.h"
#include "functionalities.h"

int main() {
    try {
        auto automobiles = createAutomobiles();

        std::cout << "Average Mileage: " << averageMileage(automobiles) << std::endl;

        std::string typeToCount = "private";
        std::cout << "Count of automobiles with type " << typeToCount << ": " << countAutomobileType(automobiles, typeToCount) << std::endl;

        if (hasPriceAbove(automobiles, 20000)) {
            std::cout << "At least one automobile has a price above 20000." << std::endl;
        } else {
            std::cout << "No automobile has a price above 20000." << std::endl;
        }

        destroyAutomobiles(automobiles);
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
