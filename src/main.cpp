#include <iostream>
#include "vehicle_command.hpp"

int main(){
    VehicleCommand command, safeCommand;
    std::string serializedCommand;
    
    command.speed = -2.5;
    command.steeringAngle = 32.5;

    safeCommand = validateCommand(command);
    serializedCommand = serializeCommand(safeCommand);

    //print to see output
    std::cout << "Validated speed: "<< safeCommand.speed << std::endl <<
                 "Validated steeringAngle: "<< safeCommand.steeringAngle <<"\n"
                << serializedCommand << std::endl;
                 
    return 0;
}