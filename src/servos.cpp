/*
 * Servos.cpp
 *
 * Module to isolate Circumsail servo functios
 */

#include <WProgram.h>
#include <Servo.h>

#include "globalConstants.h"

// Objects
static Servo rudder_servo;
static Servo sail_servo;

void servos_setup()
{
  // Set pin modes
  pinMode(PIN_SERVO_RUDDER, OUTPUT);
  pinMode(PIN_SERVO_SAIL, OUTPUT);
  
  // Pin-object attachments
  rudder_servo.attach(PIN_SERVO_RUDDER);
  sail_servo.attach(PIN_SERVO_SAIL);
}

int servos_rudder_getPosition()
{
  return rudder_servo.read();
}

int servos_sail_getPosition()
{
  return sail_servo.read();
}

/* Please document the range of input values */
void servos_rudder_setPosition( int newPosition )
{
    rudder_servo.write( newPosition );
}

/* Please document the range of input values */
void servos_sail_setPosition( int newPosition )
{
    sail_servo.write( newPosition );
}
