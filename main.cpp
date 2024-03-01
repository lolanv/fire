// main.cpp

#include "functions.h"

int main() {
    std::vector<void(*)(const std::string&)> functions = {
        function2,
        function3,
        function4,
        function5,
        function6
    };

    std::vector<std::string> data = {
        "Hello, world!",
        "C++ is awesome",
        "abcdef",
        " invalid string",
        "abccdda"
    };

    adaptorFunction(functions, data);

    return 0;
}
