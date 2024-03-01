#ifndef EXCEPTION_HANDLING_H
#define EXCEPTION_HANDLING_H

#include <stdexcept>

class InvalidCarTypeException : public std::exception {
public:
    const char* what() const noexcept override {
        return "Invalid Car Type!";
    }
};

class InvalidBrakingSystemException : public std::exception {
public:
    const char* what() const noexcept override {
        return "Invalid Braking System!";
    }
};

#endif // EXCEPTION_HANDLING_H
