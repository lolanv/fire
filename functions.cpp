// functions.cpp

#include "functions.h"

void function2(const std::string& input) {
    int vowelCount = 0;
    for (char ch : input) {
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ||
            ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U') {
            vowelCount++;
        }
    }

    if (vowelCount >= 3) {
        std::cout << input << " has at least 3 vowels\n";
    } else {
        std::cout << input << " does not have enough vowels\n";
    }
}

void function3(const std::string& input) {
    if (input.find("C++") == 0) {
        std::cout << input << " starts with C++\n";
    } else {
        std::cout << input << " does not have C++ prefix\n";
    }
}

void function4(const std::string& input) {
    if (input.length() < 3) {
        std::cout << "Invalid output\n";
    } else {
        std::cout << input.substr(input.length() - 3) << '\n';
    }
}

void function5(const std::string& input) {
    try {
        if (input.at(0) == ' ') {
            throw std::invalid_argument("Invalid string");
        } else if (input.at(0) == 'a' || input.at(0) == 'b') {
            std::cout << "Length of the string: " << input.length() << '\n';
        } else {
            std::cout << "First 2 characters: " << input.substr(0, 2) << '\n';
        }
    } catch (const std::exception& e) {
        std::cout << e.what() << '\n';
    }
}

void function6(const std::string& input) {
    if (input.length() <= 1) {
        std::cout << "Invalid string\n";
    } else {
        for (size_t i = 0; i < input.length() - 1; ++i) {
            if (input[i] == input[i + 1]) {
                std::cout << "Consecutively repeated characters: " << input.substr(i, 2) << '\n';
                return;
            }
        }
        std::cout << "Last 2 characters: " << input.substr(input.length() - 2) << '\n';
    }
}

void adaptorFunction(const std::vector<void(*)(const std::string&)>& functions, const std::vector<std::string>& data) {
    if (functions.size() != data.size()) {
        std::cerr << "Error: Number of functions and data values do not match\n";
        return;
    }

    for (size_t i = 0; i < functions.size(); ++i) {
        std::cout << "Function " << i + 2 << " result: ";
        functions[i](data[i]);
    }
}
