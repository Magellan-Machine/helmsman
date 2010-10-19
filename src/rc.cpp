#include "WProgram.h" // Arduino standard definitions

#include "globalConstants.h"
#include "globalVariables.h"
#include "servos.h"

void rc_setup() {
  pinMode(PIN_REMOTE_RUDDER, INPUT);
  pinMode(PIN_REMOTE_SAIL, INPUT);
  
}

void rc_pilot() {
  int rudder_signal = constrain(pulseIn(PIN_REMOTE_RUDDER, HIGH), MIN_RC_SIGNAL, MAX_RC_SIGNAL);
  int rudder_position = map(constrain(rudder_signal, MIN_RC_SIGNAL, MAX_RC_SIGNAL), MIN_RC_SIGNAL, MAX_RC_SIGNAL, MIN_SERVO_RUDDER, MAX_SERVO_RUDDER);
  servos_rudder_setPosition( rudder_position );

  int sail_signal = constrain(pulseIn(PIN_REMOTE_SAIL, HIGH), MIN_RC_SIGNAL, MAX_RC_SIGNAL);
  int sail_position = map(constrain(sail_signal, MIN_RC_SIGNAL, MAX_RC_SIGNAL), MIN_RC_SIGNAL, MAX_RC_SIGNAL, MIN_SERVO_SAIL, MAX_SERVO_SAIL);
  servos_sail_setPosition( sail_position );
}
