#ifndef PERMIT_H
#define PERMIT_H

#include <string>

class Permit
{
private:
    std::string _permit_number;
    int _permit_duration_remaining;

public:
    Permit(std::string permit_number, int permit_duration_remaining);

    std::string getPermitNumber() const;
    int getPermitDurationRemaining() const;
};

#endif // PERMIT_H
