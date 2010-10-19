#include <WProgram.h> // Arduino standard definitions

#include "globalConstants.h"
#include "globalVariables.h"
#include "servos.h"

void ai_setup() {
}

void ai_pilot() {
  if( servos_rudder_getPosition() == MAX_SERVO_RUDDER) {
    servos_rudder_setPosition( MIN_SERVO_RUDDER );
    servos_sail_setPosition( MIN_SERVO_SAIL );
  }
  else {
    servos_rudder_setPosition( MAX_SERVO_RUDDER );
    servos_sail_setPosition( MAX_SERVO_SAIL );
  }
  // delay(1000);  // No delay function here! Change to test if time passed
}
