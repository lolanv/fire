// function.cpp
#include "function.h"

// Adaptor function
void applyFunctions(const std::vector<void (*)(int)>& functions, const std::vector<int>& data) {
    if (functions.size() != data.size()) {
        std::cerr << "Error: Number of functions and data values do not match\n";
        return;
    }

    for (size_t i = 0; i < functions.size(); ++i) {
        functions[i](data[i]);
    }
}

// Function to check if a number is prime
void checkPrime(int num) {
    if (num <= 1) {
        std::cout << num << " is Not Prime\n";
        return;
    }

    bool isPrime = true;
    for (int i = 2; i <= sqrt(num); ++i) {
        if (num % i == 0) {
            isPrime = false;
            break;
        }
    }

    if (isPrime)
        std::cout << num << " is Prime\n";
    else
        std::cout << num << " is Not Prime\n";
}

// Function to check if a number is divisible by both 7 and 11
void checkDivisibility(int num) {
    if (num % 7 == 0 && num % 11 == 0)
        std::cout << num << " is divisible by both 7 and 11\n";
    else
        std::cout << num << " is not divisible by both 7 and 11\n";
}

// Function to print all even numbers between 2 and the input number
void printEvenNumbers(int num) {
    if (num < 2) {
        std::cout << "No even numbers to print\n";
        return;
    }

    std::cout << "Even numbers between 2 and " << num << " are: ";
    for (int i = 2; i <= num; i += 2) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}

// Function to handle various cases for a given number
void handleNumber(int num) {
    if (num < 0) {
        std::cout << "Invalid Number\n";
    } else if (num < 11) {
        int factorial = 1;
        for (int i = 1; i <= num; ++i) {
            factorial *= i;
        }
        std::cout << "Factorial of " << num << " is: " << factorial << std::endl;
    } else {
        std::cout << "Cube of " << num << " is: " << num * num * num << std::endl;
    }
}

// Function to print Fibonacci series or perform other operations based on input
void printOperations(int N) {
    if (N <= 0) {
        std::cout << "Invalid Number\n";
    } else if (N < 10) {
        int a = 0, b = 1, nextTerm;
        for (int i = 1; i <= N; ++i) {
            if (i == 1) {
                std::cout << "Fibonacci Series: " << a << ", ";
                continue;
            }
            if (i == 2) {
                std::cout << b << ", ";
                continue;
            }
            nextTerm = a + b;
            a = b;
            b = nextTerm;
            std::cout << nextTerm << (i < N ? ", " : "\n");
        }
    } else {
        std::cout << "Result: " << N * 10 << std::endl;
    }
}
