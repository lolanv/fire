#pragma once

#include <string>

class Permit
{
public:
    Permit(std::string permit_number, int permit_duration_remaining);

    std::string getPermitNumber() const;
    int getPermitDurationRemaining() const;

private:
    std::string _permit_number;
    int _permit_duration_remaining;
};
