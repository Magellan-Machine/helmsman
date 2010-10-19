#include "WProgram.h" // Arduino standard definitions
#include "globalConstants.h"
#include "globalVariables.h"
#include "windMagneto.h"
#include "magneto3d.h"
#include "servos.h"

/*
 * Global variables 
 */
unsigned long logging_interval = 0;       // Milliseconds between two logging signals

static unsigned long log_timestamp;
static unsigned long millis_last_log  = 0;       // Milliseconds of last logging info dispatch

void logging_setup()
{
  Serial.begin(115200);
  log_timestamp = millis();
}


// Send all available data for logging if enough time has passed since the last packet of information.
void logging_do(byte single_pulse=false) {
  if (!single_pulse && (logging_interval == 0 || abs(millis() - millis_last_log) < logging_interval)) {
    // The abs() is due to the fact the millis() reset itself to zero after ~50 days.
    return;
  }
  Serial.print("!R:");                      // Leading exclamation mark for logging information!
  Serial.print( constrain(map(servos_rudder_getPosition(), MIN_SERVO_RUDDER, MAX_SERVO_RUDDER, -100, +100), -100, 100) );
  Serial.print(" S:");
  Serial.print( constrain(map(servos_sail_getPosition(), MIN_SERVO_SAIL, MAX_SERVO_SAIL, 0, +100), 0, 100) );
  Serial.print(" P:");
  Serial.print(pilot_mode);
  Serial.print(" H:");
  Serial.print(desired_heading);
  Serial.print(" C:"); // 3D compass vector
  Serial.print( m3d_X );
  Serial.print( "," );
  Serial.print( m3d_Y );
  Serial.print( "," );
  Serial.print( m3d_Z );
  Serial.print( " W:"); // Relative wind direction
  Serial.print( windDirection );
  Serial.println();                         // Return Carriage for closing the message!
  millis_last_log = millis();
}

/*
void logging_do()
{
   if( millis() > log_timestamp + 200 ) // one log line per second
   {
     Serial.print( "M3D X=" );
     Serial.print( m3d_X );
     Serial.print( ", Y=" );
     Serial.print( m3d_Y );
     Serial.print( ", Z=" );
     Serial.print( m3d_Z );
     
     Serial.print( " Wind=" );
     Serial.println( windDirection );
     
     log_timestamp = millis();
   }
}
*/
