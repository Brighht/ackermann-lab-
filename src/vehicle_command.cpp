#include "vehicle_command.hpp"
#include <algorithm>
#include <sstream>


VehicleCommand validateCommand(const VehicleCommand& command){
    VehicleCommand validatedCommand;

    validatedCommand.speed = std::clamp(command.speed, -1.0, 1.0);

    validatedCommand.steeringAngle = std::clamp(command.steeringAngle, -25.0, 25.0);

    return validatedCommand; 
}

// this is going to take the safe command then serialize it
std::string serializeCommand(const VehicleCommand& command){
    std::stringstream serializedCommandStream;
    std::string serializedCommand;

    serializedCommandStream << "CMD,"
                     << command.speed << ","
                     << command.steeringAngle;

    serializedCommand = serializedCommandStream.str();
    
    return serializedCommand;
}

