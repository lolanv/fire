#include <iostream>
#include <stdexcept>
#include "functionalties.h"

int main() {
    try {
        // Execute the functionalities without using adaptor function
        std::vector<Product*> products = Functionalities::createProductsOnHeap();
        std::cout << "Average Product Price (FOOD): " << Functionalities::averageProductPriceByType(products, "FOOD") << std::endl;
        Functionalities::DisplayNTaxAmounts(products, 3);
        Functionalities::checkTaxAmountsBelow500(products);
        Functionalities::countProductTypeOriginCombinations(products);

        // Execute the functionalities using adaptor function
        std::function<void(const std::vector<Product*>&)> boundDisplayNTaxAmounts = Functionalities::bindedDisplayNTaxAmounts(3);
        boundDisplayNTaxAmounts(products);

        // Clean up allocated memory
        for (Product* p : products) {
            delete p;
        }
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
