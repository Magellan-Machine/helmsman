/**
 * Circumsail control of Wind direction sensor magnetometer
 * HMC6352 chip
 */
#include <WProgram.h>
#include <Wire.h>

/*
 * global vars
 */
int windDirection;
unsigned long windDirection_timestamp;

static const int slaveAddress = 0x42 >> 1;

void windMagneto_setup()
{
  Wire.begin();
}

void windMagneto_do()
{
  byte headingData[2];
  int i;
  
  // Send a "A" command to the HMC6352
  // This requests the current heading data
  Wire.beginTransmission(slaveAddress);
  Wire.send("A");              // The "Get Data" command
  Wire.endTransmission();
  delayMicroseconds(70);                   // The HMC6352 needs at least a 70us (microsecond) delay
  // after this command.  Using 10ms just makes it safe
  // Read the 2 heading bytes, MSB first
  // The resulting 16bit word is the compass heading in 10th's of a degree
  // For example: a heading of 1345 would be 134.5 degrees
  Wire.requestFrom(slaveAddress, 2);        // Request the 2 byte heading (MSB comes first)
  i = 0;
  while(Wire.available() && i < 2)
  { 
    headingData[i] = Wire.receive();
    i++;
  }
  windDirection = headingData[0]*256 + headingData[1];  // Put the MSB and LSB together
  windDirection_timestamp = micros();
}
