#include <Servo.h>                           // Include servo library



Servo servoLeft;                             // Declare left servo signal
Servo servoRight;                            // Declare right servo signal

void setup()
{
	Serial.begin(9600);  
pinMode(8,OUTPUT);
pinMode(9,OUTPUT);
digitalWrite(8,LOW);
digitalWrite(9,LOW);
servoLeft.attach(13);
	servoRight.attach(12);
}

void carShiftsRight()                                 // Built in initialization block
{ 
  servoLeft.writeMicroseconds(1700);         // 1.7 ms -> counterclockwise
  servoRight.writeMicroseconds(1700);        // 1.3 ms -> clockwise
}  											


void carShiftsLeft()                                 // Built in initialization block
{ 
  servoLeft.writeMicroseconds(1300);         // 1.7 ms -> counterclockwise
  servoRight.writeMicroseconds(1300);        // 1.3 ms -> clockwise
}  											


void carTurnsRight()                                 // Built in initialization block
{ 
  servoLeft.writeMicroseconds(1300);         // 1.7 ms -> counterclockwise
  servoRight.writeMicroseconds(1500);        // 1.3 ms -> clockwise
}  											


void carTurnsLeft()                                 // Built in initialization block
{ 
  servoLeft.writeMicroseconds(1500);         // 1.7 ms -> counterclockwise
  servoRight.writeMicroseconds(1700);        // 1.3 ms -> clockwise
}  											


void stopsCar()                                 // Built in initialization block
{ 
  servoLeft.writeMicroseconds(1500);         // 1.7 ms -> counterclockwise
  servoRight.writeMicroseconds(1500);        // 1.3 ms -> clockwise
}  											


void movesCarForward()                                 // Built in initialization block
{ 
  servoLeft.writeMicroseconds(1300);         // 1.7 ms -> counterclockwise
  servoRight.writeMicroseconds(1700);        // 1.3 ms -> clockwise
}  											
//moves car forward

void movesCarBackward()                                 // Built in initialization block
{ 
  servoLeft.writeMicroseconds(1700);         // 1.7 ms -> counterclockwise
  servoRight.writeMicroseconds(1300);        // 1.3 ms -> clockwise
}  											

void leftWheelBack()                                 // Built in initialization block
{ 
  servoLeft.writeMicroseconds(1700);         // 1.7 ms -> counterclockwise
  servoRight.writeMicroseconds(1500);        // 1.3 ms -> clockwise
}  											


void rightWheelBack()                                 // Built in initialization block
{ 
  servoLeft.writeMicroseconds(1300);         // 1.7 ms -> counterclockwise
  servoRight.writeMicroseconds(1500);        // 1.3 ms -> clockwise
} 

void loop()                                  // Main loop auto-repeats
{
  int drive_command = 0;
  if (!Serial.available() ){
    stopsCar();
  }
  else { 
    drive_command = Serial.read();
    Serial.print("I received: ");
    Serial.println(drive_command);
  
  switch (drive_command) {
    case 'F':
    digitalWrite(8,LOW);
digitalWrite(9,LOW);
        movesCarForward();
        delay(1000);
        break;
    case 'B':
    digitalWrite(8,HIGH);
digitalWrite(9,HIGH);
        movesCarBackward();
        delay(1000);
        break;
    case 'L':
        carTurnsLeft();
        delay(500);
        break;
    case 'R':
        carTurnsRight();
        delay(500);
        break;
    case 'l':
        carShiftsLeft();
        delay(500);
        break;
    case 'r':
        carShiftsRight();
        delay(500);
        break;
    case 'k':
        leftWheelBack();
        delay(500);
        break;
    case 'e':
        rightWheelBack();
        delay(500);
        break;
    case 'S':
        stopsCar();
        delay(1000);
    default: 
        stopsCar();
        delay(2000);
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

