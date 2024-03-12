

#ifndef PERMIT_H
#define PERMIT_H

#include <string>

class Permit {
public:
    Permit(const std::string& permitNumber, int permitDurationRemaining)
        : _permit_number(permitNumber), _permit_duration_remaining(permitDurationRemaining) {}

    std::string getPermitNumber() const { return _permit_number; }
    int getPermitDurationRemaining() const { return _permit_duration_remaining; }

private:
    std::string _permit_number;
    int _permit_duration_remaining;
};


#endif // PERMIT_H
