#include "Functionalities.h"

void CreateObject(Container &data)
{
    data.push_back(new Order("101", 100.0f, OrderType::COD, 10.0f));
    data.push_back(new Order("102", 200.0f, OrderType::PAID, 50.0f));
    data.push_back(new Order("103", 300.0f, OrderType::COD, 40.0f));
    data.push_back(new Order("104", 400.0f, OrderType::PROMOTION, 30.0f));
    data.push_back(new Order("105", 500.0f, OrderType::PAID, 20.0f));
}

// Find Id

std::string FindId(Container &data)
{
    if (data.empty())
    {
        throw std::runtime_error("Data is invalid");
    }

    float minvalue = data[0]->discount();

    for (Order *ptr : data)
    {
        minvalue = std::min(minvalue, ptr->discount());
    }

    for (Order *ptr : data)
    {
        if (minvalue == ptr->discount())
        {
            return ptr->id();
        }
    }
    return nullptr;
}

// Find Type
std::string FindType(Container &data, std::string idd)
{
    if (data.empty())
    {
        throw std::runtime_error("Data is Empty");
    }

    for (const auto &ptr : data)
    {
        if (ptr->id() == idd)
        {
            switch (ptr->type())
            {
            case OrderType::PAID:
                return "PAID";
            case OrderType::COD:
                return "COD";
            case OrderType::PROMOTION:
                return "PROMOTION";
            }
        }
    }
    throw std::runtime_error("Id not Found");
};

// Find Average

float Average(Container &data)
{
    if (data.empty())
    {
        throw std::runtime_error("Data is empty");
    }

    float total = 0.0f;

    for (Order *ptr : data)
    {
        total = total + ptr->value();
    }

    if (total < 0)
    {
        throw std::runtime_error("Invalid Data");
    }

    return total / data.size();
}

// Find last N instance
Container lastNinstance(Container &data, int N)
{

    Container res;
    if (data.empty())
    {
        throw std::runtime_error("Data is Empty");
    }
    else if (N <= 0 || N > data.size())
    {
        throw std::runtime_error("N is invalid");
    }
    int count = data.size() - 1;
    while (N > 0)
    {
        res.push_back(data[count]);
        N--;
        count--;
    }
    if (res.empty())
    {
        throw std::runtime_error("None of the object satisfy the condition");
    }

    if (res.size() < N)
    {
        throw std::runtime_error("Data is less than given N value");
    }
    return res;
}

void DeleteObject(Container &data)
{
    if (data.empty())
    {
        throw std::runtime_error("Data is empty");
    }

    for (Order *ptr : data)
    {
        delete ptr;
    }
    data.clear();
};