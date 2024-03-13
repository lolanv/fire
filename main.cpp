#include <iostream>
#include "Functionalities.h"

int main()
{
    Container obj;

    CreateObject(obj);

    try
    {
        std::string order_id = FindId(obj);
        std::cout << "Order having lowest discount: " << order_id << std::endl;

        std::cout<<"Type: "<<FindType(obj,"101")<<std::endl;

        auto data = lastNinstance(obj, 3);
        std::cout << "Last N instances: "<<std::endl;
        for (const auto &order : data)
        {
            std::cout << "ID: " << order->id() << ", Value: " << order->value() << std::endl;
        }
        std::cout << "Average value: " << Average(obj) << std::endl;
    }
    catch (const std::runtime_error &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    DeleteObject(obj);

}