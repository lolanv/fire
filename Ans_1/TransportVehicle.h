#ifndef TRANSPORT_VEHICLE_H
#define TRANSPORT_VEHICLE_H

#include <memory>
#include <string>

// Forward declaration of Permit class
class Permit;

enum class VehicleType { BUS, CAB, MINI_VAN };

class TransportVehicle {
public:
    TransportVehicle(std::shared_ptr<Permit> permit, VehicleType vehicleType, int seatCount, int stopsCount)
        : _permit(permit), _vehicle_type(vehicleType), _seat_count(seatCount), _stops_count(stopsCount) {}

    VehicleType getVehicleType() const { return _vehicle_type; }
    int getSeatCount() const { return _seat_count; }
    std::shared_ptr<Permit> getPermit() const { return _permit; }

private:
    std::shared_ptr<Permit> _permit;
    VehicleType _vehicle_type;
    int _seat_count;
    int _stops_count;
};

#endif 