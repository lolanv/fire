#include "DataOperation.h"
#include <iostream>

std::mutex DataOperation::instanceMutex;
DataOperation* DataOperation::instance = nullptr;

DataOperation* DataOperation::getInstance() {
    std::lock_guard<std::mutex> lock(instanceMutex);
    if (!instance) {
        instance = new DataOperation();
    }
    return instance;
}

void DataOperation::findMax() {
    int maxVal = _dataVector.empty() ? 0 : _dataVector[0];
    for (int val : _dataVector) {
        if (val > maxVal) {
            maxVal = val;
        }
    }
    std::cout << "Maximum value in _dataVector: " << maxVal << std::endl;
}

void DataOperation::sumofFirstN(int N) {
    if (N < 0 || N > _dataVector.size()) {
        std::cerr << "Invalid value of N for sumofFirstN function." << std::endl;
        return;
    }

    int sum = 0;
    for (int i = 0; i < N; ++i) {
        sum += _dataVector[i];
    }

    std::cout << "Sum of first " << N << " values in _dataVector: " << sum << std::endl;
}

void DataOperation::FindNthValue(int N) {
    if (N < 0 || N >= _dataVector.size()) {
        std::cerr << "Invalid index for FindNthValue function." << std::endl;
        return;
    }

    std::cout << "Value at index " << N << " in _dataVector: " << _dataVector[N] << std::endl;
}

void DataOperation::findOddNumber() {
    std::cout << "Odd numbers in _dataVector: ";
    for (int val : _dataVector) {
        if (val % 2 != 0) {
            std::cout << val << " ";
        }
    }
    std::cout << std::endl;
}

void DataOperation::findFactorial() {
    for (int i = 1; i <= 10; ++i) {
        if (i == 5) {
            throw std::invalid_argument("Invalid value for factorial calculation.");
        }
        int factorial = 1;
        for (int j = 1; j <= i; ++j) {
            factorial *= j;
        }
        std::cout << "Factorial of " << i << ": " << factorial << std::endl;
    }
}

void DataOperation::Takeinput() {
    std::cout << "Enter the value for _magicNumber: ";
    std::cin >> _magicNumber;
}

void DataOperation::Checkprime() {
    if (_magicNumber <= 1) {
        std::cout << "Magic number is not a prime number." << std::endl;
        return;
    }

    bool isPrime = true;
    for (int i = 2; i <= _magicNumber / 2; ++i) {
        if (_magicNumber % i == 0) {
            isPrime = false;
            break;
        }
    }

    std::cout << (_magicNumber > 1 && isPrime ? "Magic number is a prime number." : "Magic number is not a prime number.") << std::endl;
}

DataOperation::~DataOperation() {
    instance = nullptr;
}
