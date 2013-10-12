#include <Servo.h>                           // Include servo library



Servo servoLeft;                             // Declare left servo signal
Servo servoRight;                            // Declare right servo signal

void setup()
{
	Serial.begin(9600); 

  Serial.println("Beep!");  

  tone(4, 3000, 1000);                       // Play tone for 1 second
  delay(1000);  

pinMode(8,OUTPUT);
pinMode(9,OUTPUT);
digitalWrite(8,LOW);
digitalWrite(9,LOW);
servoLeft.attach(13);
	servoRight.attach(12);
}

void carShiftsRight()                                 // Built in initialization block
{ 
  servoLeft.writeMicroseconds(1600);         // 1.7 ms -> counterclockwise
  servoRight.writeMicroseconds(1600);        // 1.3 ms -> clockwise
}  											


void carShiftsLeft()                                 // Built in initialization block
{ 
  servoLeft.writeMicroseconds(1400);         // 1.7 ms -> counterclockwise
  servoRight.writeMicroseconds(1400);        // 1.3 ms -> clockwise
}  											


void carTurnsRight()                                 // Built in initialization block
{ 
  servoLeft.writeMicroseconds(1400);         // 1.7 ms -> counterclockwise
  servoRight.writeMicroseconds(1500);        // 1.3 ms -> clockwise
}  											


void carTurnsLeft()                                 // Built in initialization block
{ 
  servoLeft.writeMicroseconds(1500);         // 1.7 ms -> counterclockwise
  servoRight.writeMicroseconds(1600);        // 1.3 ms -> clockwise
}  											


void stopsCar()                                 // Built in initialization block
{ 
  servoLeft.writeMicroseconds(1500);         // 1.7 ms -> counterclockwise
  servoRight.writeMicroseconds(1500);        // 1.3 ms -> clockwise
}  											


void movesCarForward()                                 // Built in initialization block
{ 
  servoLeft.writeMicroseconds(1400);         // 1.7 ms -> counterclockwise
  servoRight.writeMicroseconds(1600);        // 1.3 ms -> clockwise
}  											


void movesCarBackward()                                 // Built in initialization block
{ 
  servoLeft.writeMicroseconds(1600);         // 1.7 ms -> counterclockwise
  servoRight.writeMicroseconds(1400);        // 1.3 ms -> clockwise
}  											

void leftWheelBack()                                 // Built in initialization block
{ 
  servoLeft.writeMicroseconds(1600);         // 1.7 ms -> counterclockwise
  servoRight.writeMicroseconds(1500);        // 1.3 ms -> clockwise
}  											


void rightWheelBack()                                 // Built in initialization block
{ 
  servoLeft.writeMicroseconds(1400);         // 1.7 ms -> counterclockwise
  servoRight.writeMicroseconds(1500);        // 1.3 ms -> clockwise
} 

void loop()                                  // Main loop - seeks serial input and activates drive functions
{
  int drive_command = 0;                     // Default drive command to to 0
  if (!Serial.available() ){                 // Car doesn't drive if serial not available
    //stopsCar();
  }
  else { 
    drive_command = Serial.read();           // Reads serial input
    Serial.print("I received: ");
    Serial.println(drive_command);           // Outputs ASCII value
  
  switch (drive_command) {                   
    case 'F':                                // Forward
    digitalWrite(8,LOW);
digitalWrite(9,LOW);
        movesCarForward();
        //delay(1000);
        break;
    case 'B':                                // Backward
    digitalWrite(8,HIGH);
digitalWrite(9,HIGH);
        movesCarBackward();
        //delay(1000);
        break;
    case 'L':                                 //Left
        carTurnsLeft();
        //delay(1100);
        break;
    case 'R':                                // Right
        carTurnsRight();
        //delay(1100);
        break;
    case 'l':                               // Shift left
        carShiftsLeft();
        //delay(500);
        break;
    case 'r':                               // Shift right
        carShiftsRight();
        //delay(500);
        break;
    case 'S':                               // Stop
        stopsCar();
        //delay(1000);
    default: 
      break;
        //stopsCar();
        //delay(2000);
      }
    }
  
        //stopsCar();
        //delay(10000);
        //movesCarForward();
	//delay(5000);
	//carTurnsRight();
	//delay(500);
        //movesCarForward();
        //delay(7000);
        //stopsCar();
        //delay(2000);
        //movesCarBackward();
        //delay(7000);
        //leftWheelBack();
        //delay(500);
        //movesCarBackward();
        //delay(5000);											// Empty, nothing needs repeating
}											

