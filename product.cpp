#include "product.h"

Product::Product(std::string pid, std::string type, float price, std::string brand, std::string origin)
    : productid(pid), productType(type), productPrice(price), productBrand(brand), productOrigin(origin) {
    productTaxAmount = calculateTax(productPrice);
}

std::string Product::getProductID() const {
    return productid;
}

std::string Product::getProductType() const {
    return productType;
}

float Product::getProductPrice() const {
    return productPrice;
}

std::string Product::getProductBrand() const {
    return productBrand;
}

std::string Product::getProductOrigin() const {
    return productOrigin;
}

float Product::getProductTaxAmount() const {
    return productTaxAmount;
}

void Product::setProductID(std::string pid) {
    productid = pid;
}

void Product::setProductType(std::string type) {
    productType = type;
}

void Product::setProductPrice(float price) {
    productPrice = price;
    productTaxAmount = calculateTax(productPrice);
}

void Product::setProductBrand(std::string brand) {
    productBrand = brand;
}

void Product::setProductOrigin(std::string origin) {
    productOrigin = origin;
}

float Product::calculateTax(float price) {
    return 0.05 * price; // 5% tax
}

Product::~Product() {
    // Implement destructor if needed
}
