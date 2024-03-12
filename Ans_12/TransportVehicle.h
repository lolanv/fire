#pragma once

#include <string>
#include "Permit.h"
#include<functional>
#include<memory>

enum class VehicleType
{
    BUS,
    CAB,
    MINI_VAN
};

class TransportVehicle
{
public:
    TransportVehicle(std::shared_ptr<Permit> permit, VehicleType vehicle_type, int seat_count, int stops_count);

    std::shared_ptr<Permit> getPermit() const;
    VehicleType getVehicleType() const;
    int getSeatCount() const;
    int getStopsCount() const;

private:
    std::shared_ptr<Permit> _permit;
    VehicleType _vehicle_type;
    int _seat_count;
    int _stops_count;
};
