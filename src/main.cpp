/*
 * main.cpp
 *
 *  Created on: Oct 17, 2010
 *      Author: erl
 */

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

  Serial.println( "The Magellan Machine Arduino Boot");

  servos_setup();

  Serial.println( "Servos set up.");

  rc_setup();
  Serial.println( "RC set up.");

  m3d_setup();
  Serial.println( "3D Magnetometer set up.");

  windMagneto_setup();
  Serial.println( "Wind magnetometer set up.");

  logging_setup();
  Serial.println( "Logging set up.");

  listener_setup();
  Serial.println( "Listener set up." );

  Serial.println( "setup done.");
}

void loop() {
  // Serial.println( "loop: before listener_do");
  listener_do();
  // Serial.println( "After listener_do");
  m3d_do();
  // Serial.println( "After m3d_do");
  windMagneto_do();
  logging_do();
  // Serial.println( "After logging_do");
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
  // Serial.println( "After pilot");
}

extern "C" {
int main( void );
}

int main(void) {

  /* Must call init for arduino to work properly */
  init();
  setup();

  for (;;) {
	  loop();
  } // end for
} // end main

extern "C" void __cxa_pure_virtual()
{
  cli();
  for (;;);
}
