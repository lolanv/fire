#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include <iostream>
#include <unordered_map>
#include <vector>
#include<algorithm>
#include"Exception.h"
#include <memory>
#include "CarUnit.h"

using CarUnitPtr = std::shared_ptr<CarUnit>;
using CarUnitContainer = std::vector<CarUnitPtr>;

using MapContainer = std::unordered_map<std::string, CarUnitPtr>;

// Create Object Using Map
void CreateObjects(MapContainer &data);

// Check Weather All instance Have Same Gear System
bool CheckSameGearSystem(const MapContainer &data);

// Return Conatiner of instance whose m_car_type matches with the value
MapContainer FindCarsByType(const MapContainer &data, CarType carType);

// Return Price those instance having Lowest m_car_top_rpm
std::optional<float> FindLowestPrice(const MapContainer &data);

// Return the m_car_price of instance by Id
std::optional<int> FindRpmById(const MapContainer &data, const std::string &id);

// Return Count of Instance having m_car_price above threashold
int CountCarsAbovePrice(const MapContainer &data, float threshold);

#endif // FUNCTIONALITIES_H
