// Functionalities.h
#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include <vector>
#include "Employee.h"
#include "ExceptionHandling.h"

std::vector<Employee*> createEmployeesOnHeap();
int budgetProjects(const std::vector<Employee*>& employees);
bool allEmployeesSalary(const std::vector<Employee*>& employees);
float averageTaxExemptionAmount(const std::vector<Employee*>& employees);
void displayNProjectDetails(const std::vector<Employee*>& employees, int N);
void destroyEmployees(std::vector<Employee*>& employees);

#endif // FUNCTIONALITIES_H
