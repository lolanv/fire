#include "Functionalities.h"
#include <iostream>

int main() {
    try {
        auto automobiles = createAutomobiles();

        std::cout << "Avg. Mileage: " << calculateAverageMileage(automobiles) << std::endl;

        std::cout << "PRIVATE automobiles: " << selectType(automobiles, AutomobileType::PRIVATE) << std::endl;

        std::cout << "Atleast one automobile with price above 2000? " << std::boolalpha
                  << hasPriceAbove(automobiles, 2000.0f) << std::endl;

        destroyAutomobiles(automobiles);
    } catch (const std::exception& ex) {
        std::cerr << "Exception occurred: " << ex.what() << std::endl;
    }

    return 0;
}
