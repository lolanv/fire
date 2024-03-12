#include "Permit.h"

Permit::Permit(std::string permit_number, int permit_duration_remaining)
    : _permit_number{permit_number}, _permit_duration_remaining{permit_duration_remaining} {}

std::string Permit::getPermitNumber() const
{
    return _permit_number;
}

int Permit::getPermitDurationRemaining() const
{
    return _permit_duration_remaining;
}
