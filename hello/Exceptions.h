#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <stdexcept>
#include <string>

class NoDataException : public std::runtime_error {
public:
    explicit NoDataException(const std::string& message) : std::runtime_error(message) {}
};

#endif // EXCEPTIONS_H
