#ifndef VEHICLE_COMMAND_HPP
#define VEHICLE_COMMAND_HPP
#include <string>

struct VehicleCommand 
{
    double speed;
    double steeringAngle;
};

VehicleCommand validateCommand(const VehicleCommand& command);
std::string serializeCommand(const VehicleCommand& command);

#endif