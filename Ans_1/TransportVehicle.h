#ifndef TRANSPORTVEHICLE_H
#define TRANSPORTVEHICLE_H

#include <memory>
#include <string>

#include "Permit.h"

class TransportVehicle
{
private:
    std::shared_ptr<Permit> _permit;
    std::string _vehicle_type;
    int _seat_count;
    int _stops_count;

public:
    TransportVehicle(std::shared_ptr<Permit> permit, std::string vehicle_type, int seat_count, int stops_count);

    std::shared_ptr<Permit> getPermit() const;
    std::string getVehicleType() const;
    int getSeatCount() const;
    int getStopsCount() const;
};

#endif // TRANSPORTVEHICLE_H
