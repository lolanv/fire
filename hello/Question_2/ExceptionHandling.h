// ExceptionHandling.h
#ifndef EXCEPTION_HANDLING_H
#define EXCEPTION_HANDLING_H

#include <stdexcept>

class Exception : public std::runtime_error {
public:
    Exception(const char* message) : std::runtime_error(message) {}
};

#endif // EXCEPTION_HANDLING_H
