#ifndef TRANSPORTVEHICLE_H
#define TRANSPORTVEHICLE_H

#include "Permit.h"
#include <memory>

class TransportVehicle {
public:
    TransportVehicle(std::shared_ptr<Permit> permit, std::string vehicleType, int seatCount, int stopsCount);

    std::shared_ptr<Permit> getPermit() const;
    std::string getVehicleType() const;
    int getSeatCount() const;
    int getStopsCount() const;

private:
    std::shared_ptr<Permit> _permit;
    std::string _vehicle_type;
    int _seat_count;
    int _stops_count;
};

#endif // TRANSPORTVEHICLE_H
