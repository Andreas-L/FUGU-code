#include "conf.h"
#include "AccelStepper.h"
AccelStepper stepper1(AccelStepper::FULL2WIRE, pinstepm1, pindirm1); 

#define maxSpeed 18000*microstep


void setup()
{  
    // initialize serial communication at 9600 bits per second:
    Serial.begin(9600);
    stepper1.setMaxSpeed(maxSpeed);
    stepper1.setSpeed(maxSpeed);
    stepper1.setAcceleration(maxSpeed);
    stepper1.moveTo(200*microstep);
    ;
}

void loop()
{
    // Change direction at the limits
    if (stepper1.distanceToGo() == 0)
	stepper1.moveTo(-stepper1.currentPosition());
    stepper1.run();
    
    // read the input on analog pin 0:
    int sensorValue = analogRead(pinpot1);
    // print out the value you read:
    Serial.println(sensorValue);
    int val_speed = map(sensorValue, 0, 1023, 0, maxSpeed);
    stepper1.setSpeed(val_speed);
}





