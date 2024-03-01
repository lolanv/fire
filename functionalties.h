#ifndef FUNCTIONALTIES_H
#define FUNCTIONALTIES_H

#include <vector>
#include <functional>

#include "product.h"

class Functionalities {
public:
    static std::vector<Product*> createProductsOnHeap();
    static float averageProductPriceByType(const std::vector<Product*>& products, const std::string& productType);
    static void DisplayNTaxAmounts(const std::vector<Product*>& products, int n);
    static void checkTaxAmountsBelow500(const std::vector<Product*>& products);
    static void countProductTypeOriginCombinations(const std::vector<Product*>& products);
    static std::vector<Product*> findProductsByBrand(const std::vector<Product*>& products, const std::string& brand);
    static std::function<void(const std::vector<Product*>&)> bindedDisplayNTaxAmounts(int n);
};

#endif
