#ifndef ORDER_H
#define ORDER_H

#include <iostream>
#include "OrderType.h"
class Order
{
private:
    /* data */
    std::string _id;
    float _value;
    OrderType _type;
    float _discount;

public:
    Order() = delete;                    // default constructor is deleted
    Order(Order &) = delete;             // copy constructor is deleted
    Order(Order &&) = default;           // move constructor is defaulted
    Order &operator=(Order &) = delete;  // Copy Assignment Operator
    Order &operator=(Order &&) = delete; // Move Assignment Operator
    ~Order() = default;                  // destructor is defaulted

    Order(std::string id, float value, OrderType type, float discount);

    float discount() const { return _discount; }

    std::string id() const { return _id; }

    OrderType type() const { return _type; }

    float value() const { return _value; }

    friend std::ostream &operator<<(std::ostream &os, const Order &rhs);
};

#endif // ORDER_H
