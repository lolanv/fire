#include "TransportVehicle.h"

TransportVehicle::TransportVehicle(std::shared_ptr<Permit> permit, std::string vehicleType, int seatCount, int stopsCount)
    : _permit(std::move(permit)), _vehicle_type(std::move(vehicleType)), _seat_count(seatCount), _stops_count(stopsCount) {}

std::shared_ptr<Permit> TransportVehicle::getPermit() const {
    return _permit;
}

std::string TransportVehicle::getVehicleType() const {
    return _vehicle_type;
}

int TransportVehicle::getSeatCount() const {
    return _seat_count;
}

int TransportVehicle::getStopsCount() const {
    return _stops_count;
}
