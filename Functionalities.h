#include <iostream>
#include <vector>
#include "Order.h"
#include "OrderType.h"

using Container = std::vector<Order *>;

void CreateObject(Container &data);

std::string FindId(Container &data);

std::string FindType(Container &data,std::string idd);

float Average(Container &data);

Container lastNinstance(Container &data, int N);

void DeleteObject(Container &data);



