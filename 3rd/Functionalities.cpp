#include "Functionalities.h"

void CreateObjects(MapContainer &data)
{
    data["car1"] = std::make_shared<CarUnit>("Car1", 25000.0f, CarType::SEDAN, 180, 3000, CarGear::PRNDL);
    data["car2"] = std::make_shared<CarUnit>("Car2", 27000.0f, CarType::SEDAN, 190, 3200, CarGear::PRNDL);
    data["car3"] = std::make_shared<CarUnit>("Car3", 30000.0f, CarType::SUV, 200, 2800, CarGear::TIPTRONIC);
    data["car4"] = std::make_shared<CarUnit>("Car4", 22000.0f, CarType::HATCHBACK, 170, 2700, CarGear::CLASSIC);
    data["car5"] = std::make_shared<CarUnit>("Car5", 26000.0f, CarType::SEDAN, 185, 3100, CarGear::PRNDL);
}

bool CheckSameGearSystem(const MapContainer &data)
{
    if (data.empty())
        return false;

    auto firstGearSystem = data.begin()->second->carGearSystem();

    return std::all_of(
        data.begin(),
        data.end(), [&](const auto &ptr)
        { return ptr.second->carGearSystem() == firstGearSystem; });
}

MapContainer FindCarsByType(const MapContainer &data, CarType carType)
{
    if (data.empty())
    {
        throw std::runtime_error("Data is empty");
    }

    MapContainer result;
    std::copy_if(
        data.begin(),
        data.end(),
        std::inserter(result, result.end()),
        [&](const auto &ptr)
        { return ptr.second->carType() == carType; });

    if (result.empty())
    {
        throw std::runtime_error("Car type not found");
    }

    return result;
}

std::optional<float> FindLowestPrice(const MapContainer &data)
{
    if (data.empty())
    {
        return std::nullopt;
    }

    auto minElement = std::min_element(
        data.begin(),
        data.end(),
        [](const auto &a, const auto &b)
        { return a.second->carPrice() < b.second->carPrice(); });

    return minElement->second->carPrice();
}

std::optional<int> FindRpmById(const MapContainer &data, const std::string &id)
{

    if (data.empty())
    {
        return std::nullopt;
    }

    auto it = data.find(id);
    if (it != data.end())
    {
        return it->second->carRpm();
    }

    return std::nullopt;
}

int CountCarsAbovePrice(const MapContainer &data, float threshold)
{

    if (data.empty())
    {
        throw Exception("Data is Empty");
    }

    size_t CountValue = std::count_if(
        data.begin(),
        data.end(),
        [&](const auto &ptr)
        { return ptr.second->carPrice() > threshold; });

    if (CountValue < 0)
    {
        throw Exception("Invalid Count");
    }
    return 0;
}
