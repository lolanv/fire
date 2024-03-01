#ifndef AUTOMOBILE_H
#define AUTOMOBILE_H

#include <string>

class Automobile {
private:
    std::string _model_name;
    std::string _automobile_type;
    float _automobile_price;
    float _automobile_mileage;

public:
    // Parameterized Constructor
    Automobile(std::string model_name, std::string automobile_type, float automobile_price, float automobile_mileage);

    // Disabled copy constructor
    Automobile(const Automobile&) = delete;

    // Disabled copy assignment operator
    Automobile& operator=(const Automobile&) = delete;

    // Disabled move constructor    
    Automobile(Automobile&&) = delete;

    // Disabled move assignment operator
    Automobile& operator=(Automobile&&) = delete;

    // Getter for automobile price
    float getAutomobilePrice() const;

    // Getter for automobile type
    std::string getAutomobileType() const;

    // Getter for automobile mileage
    float getAutomobileMileage() const;
};

#endif /* AUTOMOBILE_H */
