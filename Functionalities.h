#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include "Automobile.h"
#include <vector>
#include <memory>

std::vector<std::shared_ptr<Automobile>> createAutomobiles();

//for calculating avg mileage

float calculateAverageMileage(const std::vector<std::shared_ptr<Automobile>>& automobiles); 

//priavte or transport 
int selectType(const std::vector<std::shared_ptr<Automobile>>& automobiles, AutomobileType type);

//price abv 20000

bool hasPriceAbove(const std::vector<std::shared_ptr<Automobile>>& automobiles, float priceThreshold);

//deallocation

void destroyAutomobiles(std::vector<std::shared_ptr<Automobile>>& automobiles);

#endif // FUNCTIONALITIES_H
