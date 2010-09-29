///////////////////////////////////////////
//                INCLUDES               //
///////////////////////////////////////////

// Standard libraries
#include <Servo.h>
// NOTE: Libraries need to be included in the main sketch file
// for them to be accessible to other files in the project.
#include <Messenger.h>
#include <Wire.h>

// Custom files
#include "globalConstants.h"
#include "globalVariables.h"
#include "listener.h"
#include "logging.h"
#include "ai.h"
#include "rc.h"
#include "magneto3d.h"
#include "windMagneto.h"
#include "servos.h"

///////////////////////////////////////////
//               ARDUINO'S               //
///////////////////////////////////////////

void setup() {
  // Initiate Serial Communication
  Serial.begin(115200);
  servos_setup();
  rc_setup();
  m3d_setup();
  windMagneto_setup();
  logging_setup();
}

void loop() {
  listener_do();
  m3d_do();
  windMagneto_do();
  logging_do();
  switch (pilot_mode) {   // The COMPUTER case is not listed as it gets processed by the Serial Messanger directly
    case AUTO:
      ai_pilot();
      break;
    case RC:
      rc_pilot();
      break;
    case OFF:
      break;
  }
}

