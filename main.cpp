// main.cpp
#include "function.h"

int main() {
    std::vector<void (*)(int)> functions = {checkPrime, checkDivisibility, printEvenNumbers, handleNumber, printOperations};
    std::vector<int> data = {13, 77, 10, -5, 7};

    applyFunctions(functions, data);

    return 0;
}
