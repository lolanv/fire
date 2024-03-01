#include "Functionalities.h"

std::vector<Employee*> createEmployeesOnHeap() {
    std::vector<Employee*> employees;
    try {
        
        employees.push_back(new Employee(
            "21",
             "Dhyey", 2100000.0f));
        employees.push_back(new Employee(
            "19", 
             "Virat Kohli", 910000.0f));
        employees.push_back(new Employee(
            "3",
             "Dhoni", 7400000.0f));
        employees.push_back(new Employee(
            "4", 
            "Sachin", 720000.0f));
    } catch (std::bad_alloc& e) {
        std::cout << "No memory allocated " << e.what() << std::endl;
        throw;
    }
    return employees;
}

int budgetProjects(const std::vector<Employee*>& employees) {
    int count = 0;
    for (const auto& emp : employees) {
        if (emp && emp->getProject() && emp->getProject()->getBudget() > 5000.0f)
            count++;
    }
    return count;
}

bool allEmployeesSalary(const std::vector<Employee*>& employees) {
    if (employees.empty()) //empty case
        return false;

    for (const auto& emp : employees) {
        if (emp && emp->getSalary() <= 10000.0f)
            return false;
    }
    return true;
}

float averageTaxExemptionAmount(const std::vector<Employee*>& employees) {
    if (employees.empty())
        return 0.0f;

    float total = 0.0f;
    int validEmployeeCount = 0; //no division by 0
    for (const auto& emp : employees) {
        if (emp) {
            total += emp->TaxExemptionAmount();
            validEmployeeCount++;
        }
    }
    if (validEmployeeCount == 0) //no employee found
        return 0.0f;

    return total / validEmployeeCount;
}


void displayNProjectDetails(const std::vector<Employee*>& employees, int N) {
    if (employees.empty() || N <= 0)
        return;

    for (int i = 0; i < N && i < employees.size(); ++i) {
        auto emp = employees[i];
        if (emp) {
            auto project = emp->getProject();
            if (project) {
                std::cout << "Employee Id: " << emp->getId() << ", Project Name: " << project->getName() << ", Budget: " << project->getBudget() << std::endl;
            }
        }
    }
}

void destroyEmployees(std::vector<Employee*>& employees) {
    for (auto& emp : employees) {
        delete emp;
        emp = nullptr;
    }
    employees.clear();
}


