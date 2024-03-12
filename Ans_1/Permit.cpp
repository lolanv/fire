#include "Permit.h"

Permit::Permit(std::string permitNumber, int durationRemaining)
    : _permit_number(std::move(permitNumber)), _permit_duration_remaining(durationRemaining) {}

std::string Permit::getPermitNumber() const {
    return _permit_number;
}

int Permit::getPermitDurationRemaining() const {
    return _permit_duration_remaining;
}
