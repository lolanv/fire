#include "TransportVehicle.h"

TransportVehicle::TransportVehicle(std::shared_ptr<Permit> permit, VehicleType vehicle_type, int seat_count, int stops_count)
    : _permit(permit), _vehicle_type(vehicle_type), _seat_count(seat_count), _stops_count(stops_count) {}

std::shared_ptr<Permit> TransportVehicle::getPermit() const
{
    return _permit;
}

VehicleType TransportVehicle::getVehicleType() const
{
    return _vehicle_type;
}

int TransportVehicle::getSeatCount() const
{
    return _seat_count;
}

int TransportVehicle::getStopsCount() const
{
    return _stops_count;
}
