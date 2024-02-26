#ifndef AUTOMOBILE_H
#define AUTOMOBILE_H

#include <string>

enum class AutomobileType { PRIVATE, TRANSPORT };

class Automobile {
private:
    /* data */
    std::string _model_name;
    AutomobileType _automobile_type;
    float _automobile_price;
    float _automobile_mileage;
    
public:
    Automobile(const std::string& model_name, AutomobileType automobile_type, float automobile_price, float automobile_mileage)
        : _model_name(model_name), _automobile_type(automobile_type), _automobile_price(automobile_price), _automobile_mileage(automobile_mileage) {}

    Automobile(/* args */)=default;

    //copy constructor and copy assignment operator
    Automobile(const Automobile&) = delete;

    Automobile& operator=(const Automobile&) = delete;
    //move constructor and move assignment operator
    Automobile(Automobile&&) = delete;

    Automobile& operator=(Automobile&&) = delete;

    ~Automobile()=default;

    float getMileage() const { return _automobile_mileage; }
    float getPrice() const { return _automobile_price; }
    AutomobileType getType() const { return _automobile_type; }
};

#endif // AUTOMOBILE_H
