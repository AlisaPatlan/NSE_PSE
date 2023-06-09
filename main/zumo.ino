// #include <Zumo32U4.h>
// #include <Wire.h>

// // Initialize Zumo Motors object
// Zumo32U4Motors motors;

// void setup() {
//   // Set up serial communication with XBEE
//   Serial1.begin(9600);
//   // buzzer.play("!O5 D.. E.. <A E.. F#.. A16 G16 F#8 D.. E.. <A2 <A16 <A16 <B16 D8 D16 R L8 <B C# D D E C#.. <B16 <A2");

//     // Enable Timer4 for motor control
//   TCCR4A = 0;
//   TCCR4B = 1 << CS41;
//   TCCR4D = 1 << WGM40;

//   // Set up Zumo Motors
//   // motors.flipLeftMotor(true);  // Adjust the motor direction if necessary
//   // motors.flipRightMotor(true); // Adjust the motor direction if necessary
// }

//  void loop() {
//   if (Serial1.available()) {
//     char command = Serial1.read();
//     Serial1.write(command);
//      switch (command) {
//       case 'W': // Forward
//         motors.setSpeeds(200, 200); // Adjust the motor speeds as needed
//         break;
      
//       case 'S': // Backward
//         motors.setSpeeds(-200, -200); // Adjust the motor speeds as needed
//         break;
      
//       case 'A': // Turn left
//         motors.setSpeeds(-200, 200); // Adjust the motor speeds as needed
//         break;
      
//       case 'D': // Turn right
//         motors.setSpeeds(200, -200); // Adjust the motor speeds as needed
//         break;
      
//       case 'X': // Stop
//         motors.setSpeeds(0, 0);
//         break;
//     }
//   }
// }
