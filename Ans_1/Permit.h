#ifndef PERMIT_H
#define PERMIT_H

#include <string>

class Permit {
public:
    Permit(std::string permitNumber, int durationRemaining);

    std::string getPermitNumber() const;
    int getPermitDurationRemaining() const;

private:
    std::string _permit_number;
    int _permit_duration_remaining;
};

#endif // PERMIT_H
