#include "vehicle_command.hpp"
#include <algorithm>


VehicleCommand validateCommand(const VehicleCommand& command){
    VehicleCommand validatedCommand;

    validatedCommand.speed = std::clamp(command.speed, -1.0, 1.0);

    validatedCommand.steeringAngle = std::clamp(command.steeringAngle, -25.0, 25.0);

    return validatedCommand;
}

