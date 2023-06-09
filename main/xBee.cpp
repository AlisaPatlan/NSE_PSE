#include "xBee.h"

ZumoRobot::ZumoRobot() {
  // Set up serial communication with XBEE
  Serial1.begin(9600);
}

void ZumoRobot::handleCommands() {
  if (Serial1.available()) {
    char command = Serial1.read();
    Serial1.write(command);
    switch (command) {
      case 'W': // Forward
        motors.setSpeeds(200, 200); // Adjust the motor speeds as needed
        break;

      case 'S': // Backward
        motors.setSpeeds(-200, -200); // Adjust the motor speeds as needed
        break;

      case 'A': // Turn left
        motors.setSpeeds(-200, 200); // Adjust the motor speeds as needed
        break;

      case 'D': // Turn right
        motors.setSpeeds(200, -200); // Adjust the motor speeds as needed
        break;

      case 'X': // Stop
        motors.setSpeeds(0, 0);
        break;
    }
  }
}
