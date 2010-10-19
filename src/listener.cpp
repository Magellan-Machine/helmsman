#include <WProgram.h> // Arduino standard definitions

#include <Messenger.h>
#include "globalConstants.h"
#include "globalVariables.h"
#include "logging.h"
#include "servos.h"

// Module variables
static Messenger message = Messenger();

// Global variable
int pilot_mode                 = OFF;
int desired_heading            = 0;

// Serial messages handler.
//
// The first element of each serial message is the command code, then (if any) the arguments.
// Messages are passed around as strings, hence the need for specific methods to decode
// strings to integers, etc...
void message_completed() {
  Serial.println( "message_completed" );
  char command = message.readChar();
  int arguments[] = {
    0, 0, 0  };
  int counter = 0;
  while (message.available()) {
    arguments[counter] = message.readInt();
  }
  switch (command) {
    case SET_LOG_INTERVAL:
      logging_set_interval(arguments[0]);
      logging_do(true);
      Serial.println("Logging interval adjusted");
      break;
    case SET_PILOT_MODE:
      pilot_mode = arguments[0];
      Serial.println("Pilot mode adjusted");
      break;
    case SET_HEADING:
      desired_heading = arguments[0];
      Serial.println("Heading adjusted.");
      break;
    case SET_RUDDER:
      pilot_mode = COMPUTER;  // Automatically passes control to the computer
      servos_rudder_setPosition( map(-arguments[0], -100, 100, MIN_SERVO_RUDDER, MAX_SERVO_RUDDER));
      Serial.println("Rudder adjusted.");
      break;
    case SET_SAIL:
      pilot_mode = COMPUTER;  // Automatically passes control to the computer
      servos_sail_setPosition( map(arguments[0], 0, 100, MIN_SERVO_SAIL, MAX_SERVO_SAIL));
      Serial.println("Sail adjusted.");
      break;
    default:
      Serial.println("Unknown command!");      
  }
  logging_do(true);  //Force sending a Log packet only if logging is not happening already
}

void listener_setup() {
  message.attach(message_completed);
}

void listener_do() {
  while (Serial.available()) message.process(Serial.read());     // Feed serial data to Messenger
}
