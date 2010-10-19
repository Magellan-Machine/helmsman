#ifndef CIRCUMSAIL_CONSTANTS_H
#define CIRCUMSAIL_CONSTANTS_H

///////////////////////////////////////////
//       PROGRAM-WIDE CONSTANTS          //
///////////////////////////////////////////

// Command codes
const char SET_LOG_INTERVAL       = 'I';
const char SET_PILOT_MODE         = 'P';
const char SET_HEADING            = 'H';
const char SET_RUDDER             = 'R';
const char SET_SAIL               = 'S';

// Pilot mode settings
const int OFF                     = 0;
const int AUTO                    = 1;
const int RC                      = 2;
const int COMPUTER                = 3;

// Calibration values
const int MIN_RC_SIGNAL           =  900;
const int MAX_RC_SIGNAL           = 1800;
const int MIN_SERVO_RUDDER        =    5;
const int MAX_SERVO_RUDDER        =  130;
const int MIN_SERVO_SAIL          =   30;
const int MAX_SERVO_SAIL          =  130;

// Pin assigment 
const int PIN_SERVO_RUDDER        =  3;  // Analog write is possible only on pins: 3, 5, 6, 9, 10, and 11
const int PIN_SERVO_SAIL          =  5;  // Analog write is possible only on pins: 3, 5, 6, 9, 10, and 11
const int PIN_REMOTE_RUDDER       =  6;
const int PIN_REMOTE_SAIL         =  7;
const int PIN_M3D_RESET           = 8;  // magnetometer pin 6
const int PIN_M3D_DRDY            = 9;  // magnetometer pin 5
const int PIN_M3D_SSNOT           = 10;  // magnetometer pin 4
const int PIN_M3D_MOSI            = 11;  // magnetometer pin 3
const int PIN_M3D_MISO            = 12;  // magnetometer pin 2
const int PIN_M3D_SCLK            = 13;  // magnetometer pin 1

/*
 * NOTE: Wind Magnetometer is connected to analog pins 4 & 5:
 *       SDA to Analog pin 4 and SCL to analog pin 5
 *       The Wire i2c library uses these by default.
 */
 
#endif
