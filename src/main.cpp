#include <iostream>
#include "vehicle_command.hpp"

int main(){
    VehicleCommand command, safeCommand;
    
    command.speed = -2.5;
    command.steeringAngle = 32.5;

    safeCommand = validateCommand(command);
    //print to see output
    std::cout << "Validated speed: "<< safeCommand.speed << std::endl <<
                 "Validated steeringAngle: "<< safeCommand.steeringAngle << std::endl;
    return 0;
}