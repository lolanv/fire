// functions.h
//

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <string>
#include <iostream>
#include <vector>

void function2(const std::string& input);
void function3(const std::string& input);
void function4(const std::string& input);
void function5(const std::string& input);
void function6(const std::string& input);

void adaptorFunction(const std::vector<void(*)(const std::string&)>& functions, const std::vector<std::string>& data);

#endif // FUNCTIONS_H
