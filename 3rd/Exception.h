#include <iostream>

class Exception : std::exception
{
private:
    /* data */
    std::string _msg;

public:
    explicit Exception(std::string msg) : _msg{msg} {}
    ~Exception() = default;
    Exception(const Exception &) = delete;
    Exception &operator=(const Exception &) = delete;
    Exception &operator=(Exception &&) = delete;
    Exception(Exception &&) = delete;
    Exception() = delete;
    std::string what() { return _msg; }; // Act like getter for _msg!
};
