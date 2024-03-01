#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>

class Product {
private:
    std::string productid;
    std::string productType;
    float productPrice;
    std::string productBrand;
    std::string productOrigin;
    float productTaxAmount;

public:
    // Constructors
    Product(std::string pid, std::string type, float price, std::string brand, std::string origin);

    // Getters
    std::string getProductID() const;
    std::string getProductType() const;
    float getProductPrice() const;
    std::string getProductBrand() const;
    std::string getProductOrigin() const;
    float getProductTaxAmount() const;

    // Setters
    void setProductID(std::string pid);
    void setProductType(std::string type);
    void setProductPrice(float price);
    void setProductBrand(std::string brand);
    void setProductOrigin(std::string origin);

    // Other relevant member functions
    static float calculateTax(float price);

    // Destructor
    ~Product();
};

#endif
