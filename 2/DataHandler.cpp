#include "DataHandler.h"
#include <cmath>
#include <algorithm>
#include <iostream>

std::unique_ptr<DataHandler> DataHandler::instance = nullptr;
std::mutex DataHandler::mutex;

DataHandler::DataHandler() {
    for (int i = 0; i < 5; ++i) {
        _data[i] = 0;
        _square_results[i] = 0;
        _factorial_results[i] = 0;
    }
    _flag = false;
}

DataHandler* DataHandler::getInstance() {
    if (!instance) {
        std::lock_guard<std::mutex> lock(mutex);
        if (!instance) {
            instance = std::unique_ptr<DataHandler>(new DataHandler());
        }
    }
    return instance.get();
}

void DataHandler::TakeInput() {
    std::lock_guard<std::mutex> lock(mutex);
    std::cout << "Please enter 5 integers between 1 and 10:" << std::endl;
    for (int i = 0; i < 5; ++i) {
        int num;
        std::cin >> num;
        while (num < 1 || num > 10) {
            std::cout << "Number out of range. Please retry: ";
            std::cin >> num;
        }
        _data[i] = num;
    }
}


void DataHandler::ComputeSquare() {
    int count = 0;
    int num = 1;
    while (count < 5) {
        if (num % 2 != 0 && num % 3 == 0) {
            _square_results[count] = num * num;
            count++;
        }
        num++;
    }
    std::lock_guard<std::mutex> lock(mutex);
    std::cout << "Square Results: ";
    for (int i = 0; i < 5; ++i) {
        std::cout << _square_results[i] << " ";
    }
    std::cout << std::endl;
}

int Factorial(int n) {
    if (n == 0)
        return 1;
    return n * Factorial(n - 1);
}

void DataHandler::ComputeFactorial() {
    for (int i = 0; i < 5; ++i) {
        _factorial_results[i] = Factorial(_data[i]);
    }
    std::lock_guard<std::mutex> lock(mutex);
    std::cout << "Factorial Results: ";
    for (int i = 0; i < 5; ++i) {
        std::cout << _factorial_results[i] << " ";
    }
    std::cout << std::endl;
}


bool IsPrime(int num) {
    if (num <= 1) return false;
    for (int i = 2; i <= num / 2; ++i) {
        if (num % i == 0) return false;
    }
    return true;
}

void DataHandler::AverageValue() {
    std::vector<int> primes;
    int num = 2;
    while (primes.size() < 5) {
        if (IsPrime(num)) {
            primes.push_back(num);
        }
        num++;
    }
    std::lock_guard<std::mutex> lock(mutex);
    double avg = std::accumulate(primes.begin(), primes.end(), 0.0) / primes.size();
    std::cout << "Average of first 5 prime numbers: " << avg << std::endl;
}

