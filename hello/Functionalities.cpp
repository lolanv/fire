#include "Functionalities.h"
#include "Exceptions.h"
#include <algorithm>

std::vector<std::shared_ptr<Automobile>> createAutomobiles()
{
    std::vector<std::shared_ptr<Automobile>> automobiles;

    automobiles.push_back(std::make_shared<Automobile>("Nexon",
                                                       AutomobileType::PRIVATE,
                                                       1500000.0f,
                                                       31.0f));


    automobiles.push_back(std::make_shared<Automobile>("VOLVO",
                                                       AutomobileType::TRANSPORT,
                                                       2500000.0f,
                                                       29.0f));


    automobiles.push_back(std::make_shared<Automobile>("XUV 400",
                                                       AutomobileType::PRIVATE,
                                                       200000.0f,
                                                       40.0f));
                                                       

    automobiles.push_back(std::make_shared<Automobile>("BUS",
                                                       AutomobileType::TRANSPORT,
                                                       2200000.0f,
                                                       54.0f));

    return automobiles;
}

float calculateAverageMileage(const std::vector<std::shared_ptr<Automobile>> &automobiles)
{
    if (automobiles.empty())
        throw NoDataException("Pls. input data for calculating the average.");

    float totalMileage = 0.0f;
    for (const auto &automobile : automobiles)
    {
        totalMileage += automobile->getMileage();
    }
    return totalMileage / automobiles.size();
}

int selectType(const std::vector<std::shared_ptr<Automobile>> &automobiles, AutomobileType type)
{
    if (automobiles.empty()) // empty case
        return 0;

    return std::count_if(automobiles.begin(), automobiles.end(),
                         [type](const auto &automobile)
                         { return automobile->getType() == type; });
}

bool hasPriceAbove(const std::vector<std::shared_ptr<Automobile>> &automobiles, float priceThreshold)
{
    if (automobiles.empty()) // empty case
        return false;

    return std::any_of(automobiles.begin(), automobiles.end(),
                       [priceThreshold](const auto &automobile)
                       { return automobile->getPrice() > priceThreshold; });
}

void destroyAutomobiles(std::vector<std::shared_ptr<Automobile>> &automobiles)
{
    for (auto &automobile : automobiles)
    {
        automobile.reset();
    }
    automobiles.clear();
}
