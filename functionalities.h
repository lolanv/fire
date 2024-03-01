#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include <vector>
#include <memory>
#include "Automobile.h"

std::vector<std::unique_ptr<Automobile>> createAutomobiles();
float averageMileage(const std::vector<std::unique_ptr<Automobile>>& automobiles);
int countAutomobileType(const std::vector<std::unique_ptr<Automobile>>& automobiles, const std::string& type);
bool hasPriceAbove(const std::vector<std::unique_ptr<Automobile>>& automobiles, float priceThreshold);
void destroyAutomobiles(std::vector<std::unique_ptr<Automobile>>& automobiles);

#endif /* FUNCTIONALITIES_H */
