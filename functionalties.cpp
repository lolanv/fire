#include "functionalties.h"
#include <algorithm>
#include <iostream>
#include <numeric>

std::vector<Product*> Functionalities::createProductsOnHeap() {
    // Implement the creation of products on the heap using smart or raw pointers
    std::vector<Product*> products;
    
    // Example data
    products.push_back(new Product("P001", "FOOD", 10.0, "Brand1", "DOMESTIC"));
    products.push_back(new Product("P002", "PERFUME", 20.0, "Brand2", "IMPORTED"));
    products.push_back(new Product("P003", "APPLIANCE", 30.0, "Brand3", "DOMESTIC"));

    return products;
}

float Functionalities::averageProductPriceByType(const std::vector<Product*>& products, const std::string& productType) {
    // Implement the calculation of average product price by type
    auto isProductType = [productType](const Product* p) { return p->getProductType() == productType; };

    auto count = std::count_if(products.begin(), products.end(), isProductType);

    if (count == 0) {
        throw std::invalid_argument("No products of the given type found.");
    }

    auto sum = std::accumulate(products.begin(), products.end(), 0.0,
                               [isProductType](double s, const Product* p) { return s + (isProductType(p) ? p->getProductPrice() : 0.0); });

    return sum / count;
}

void Functionalities::DisplayNTaxAmounts(const std::vector<Product*>& products, int n) {
    // Implement the display of product tax amounts for the first N instances
    if (n <= 0) {
        throw std::invalid_argument("Invalid value of N for DisplayNTaxAmounts function.");
    }

    int count = 0;
    for (const auto& product : products) {
        if (count == n) {
            break;
        }
        std::cout << "Product ID: " << product->getProductID() << ", Tax Amount: " << product->getProductTaxAmount() << std::endl;
        count++;
    }
}

void Functionalities::checkTaxAmountsBelow500(const std::vector<Product*>& products) {
    // Implement the check for tax amounts below 500
    auto isTaxBelow500 = [](const Product* p) { return p->getProductTaxAmount() < 500.0; };

    if (std::all_of(products.begin(), products.end(), isTaxBelow500)) {
        std::cout << "All instances have productTaxAmount below 500." << std::endl;
    } else {
        std::cout << "Not all instances have productTaxAmount below 500." << std::endl;
    }
}

void Functionalities::countProductTypeOriginCombinations(const std::vector<Product*>& products) {
    // Implement the counting of product type and origin combinations
    std::vector<std::pair<std::string, std::string>> combinations;
    for (const auto& product : products) {
        combinations.push_back({product->getProductType(), product->getProductOrigin()});
    }

    std::sort(combinations.begin(), combinations.end());

    int count = 1;
    for (size_t i = 1; i < combinations.size(); ++i) {
        if (combinations[i] != combinations[i - 1]) {
            std::cout << "Count for combination (" << combinations[i - 1].first << ", " << combinations[i - 1].second << "): " << count << std::endl;
            count = 1;
        } else {
            count++;
        }
    }

    // Print count for the last combination
    std::cout << "Count for combination (" << combinations.back().first << ", " << combinations.back().second << "): " << count << std::endl;
}

std::vector<Product*> Functionalities::findProductsByBrand(const std::vector<Product*>& products, const std::string& brand) {
    // Implement the finding of products by brand
    std::vector<Product*> result;
    std::copy_if(products.begin(), products.end(), std::back_inserter(result),
                 [brand](const Product* p) { return p->getProductBrand() == brand; });

    return result;
}

std::function<void(const std::vector<Product*>&)> Functionalities::bindedDisplayNTaxAmounts(int n) {
    // Implement the binding of DisplayNTaxAmounts function with a specific value of N
    return [n](const std::vector<Product*>& products) { DisplayNTaxAmounts(products, n); };
}
