#include "Employee.h"

Employee::Employee(std::string id, std::string name, float salary, Project* project) 
    : _employee_id(id), _employee_name(name), _salary(salary), _project(project) {}

Employee::Employee(std::string id, std::string name, float salary) 
    : _employee_id(id), _employee_name(name), _salary(salary), _project(nullptr) {}

float Employee::TaxExemptionAmount() const {
    if (_salary < 1000000.0f)
        return 0.05f * _salary;
    else
        return 0.10f * _salary;
}