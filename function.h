// function.h
#ifndef FUNCTION_H
#define FUNCTION_H

#include <iostream>
#include <vector>
#include <cmath>

// Function declarations

// Adaptor function
void applyFunctions(const std::vector<void (*)(int)>& functions, const std::vector<int>& data);

// Function to check if a number is prime
void checkPrime(int num);

// Function to check if a number is divisible by both 7 and 11
void checkDivisibility(int num);

// Function to print all even numbers between 2 and the input number
void printEvenNumbers(int num);

// Function to handle various cases for a given number
void handleNumber(int num);

// Function to print Fibonacci series or perform other operations based on input
void printOperations(int N);

#endif
