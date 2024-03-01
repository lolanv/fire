#include <iostream>
#include "Functionalities.h"
#include "ExceptionHandling.h"

int main() {
    try {
        std::vector<Employee*> employees = createEmployeesOnHeap();

        // Demonstrate functionalities
        std::cout << "projects budget over 5000 " << budgetProjects(employees) << std::endl;
        std::cout << "employees above salary 10000: " << std::boolalpha << allEmployeesSalary(employees) << std::endl;
        std::cout << "avg. Tax Exemption: " << averageTaxExemptionAmount(employees) << std::endl;
        displayNProjectDetails(employees, 3);
        destroyEmployees(employees);
    } catch (Exception& e) {
        std::cout<< "Custom exception caught: " << e.what() << std::endl;
    } catch (std::exception& e) {
        std::cout<< "Standard exception caught: " << e.what() << std::endl;
    }

    return 0;
}