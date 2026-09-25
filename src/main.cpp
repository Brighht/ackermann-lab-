#include <iostream>
#include "vehicle_command.hpp"

int main(){
    VehicleCommand command, safeCommand;
    std::string serializedCommand,expected;
    
    command.speed = -2.5;
    command.steeringAngle = 32.5;

    safeCommand = validateCommand(command);
    serializedCommand = serializeCommand(safeCommand);
    expected = "CMD,-1,25\n";
    
    //print to see output
    std::cout << "Validated speed: "<< safeCommand.speed << std::endl <<
                 "Validated steeringAngle: "<< safeCommand.steeringAngle <<"\n"
                << serializedCommand << std::endl;
    
    if(serializedCommand == expected){
        std::cout << "PASS\n";
    }
    else{
        std::cout <<"FAIL\n";
    }

    return 0;
}