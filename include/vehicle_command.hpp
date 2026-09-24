#ifndef VEHICLE_COMMAND_HPP
#define VEHICLE_COMMAND_HPP

struct VehicleCommand 
{
    double speed;
    double steeringAngle;
};

VehicleCommand validateCommand(const VehicleCommand& command);

#endif