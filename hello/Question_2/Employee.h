#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <iostream>
#include <string>
#include "Project.h"

class Employee {
private:
    std::string _employee_id;
    std::string _employee_name;
    float _salary;
    Project* _project;

public:
    Employee(std::string id, std::string name, float salary, Project* project);
    Employee(std::string id, std::string name, float salary);


    Employee()=default;
    //copy constructor 
    Employee(const Employee&) = delete;
    //copy operator
    Employee& operator=(const Employee&) = delete;
    //move constructor
    Employee(Employee&&) = delete;
    //move operator
    Employee& operator=(Employee&&) = delete;
    ~Employee()=default;



    float TaxExemptionAmount() const;
    Project* getProject() const { return _project; }
    float getSalary() const { return _salary; }
    std::string getId() const { return _employee_id; }
    ~Employee() = default;
};

#endif // EMPLOYEE_H