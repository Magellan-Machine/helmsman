#include "WProgram.h" // Arduino standard definitions

#include "globalConstants.h"
#include "globalVariables.h"

//static enum { STATE_START_X };

// static function prototypes
static int receiveBit();
static void sendBit(int bit);
static float readAxis(int axis);
static int Rad2Deg(double angle);

// globals
int north;
int m3d_X;            // TODO: remove x, y, z when tested
int m3d_Y;
int m3d_Z;

void m3d_setup()
{
  pinMode( PIN_M3D_SSNOT, OUTPUT); 
  pinMode( PIN_M3D_RESET, OUTPUT); 
  pinMode( PIN_M3D_MOSI, OUTPUT); 
  pinMode( PIN_M3D_SCLK, OUTPUT); 
  pinMode( PIN_M3D_MISO, INPUT); 
  pinMode( PIN_M3D_DRDY, INPUT); 
  
  digitalWrite( PIN_M3D_SSNOT, LOW);
}


void m3d_do()
{
  int x, y, z;
  
  m3d_X = x = readAxis(0);
  m3d_Y = y = readAxis(1);
  m3d_Z = z = readAxis(2);
  
  north = (Rad2Deg(atan2(x, y)) + 270) % 360;     // 270 compensate for orientation of sensor (90°) and -180°<angle<0°
}

static float readAxis(int axis)
{
   // pulse reset
   // try removing the delays when everything works
  digitalWrite( PIN_M3D_RESET, LOW); 
  delayMicroseconds(1); 
  digitalWrite( PIN_M3D_RESET, HIGH); 
  delayMicroseconds(1); 
  digitalWrite( PIN_M3D_RESET, LOW); 
  delayMicroseconds(1); 
  
  // send the command byte 
  // set the time to read the magnetic sensors (ASIC period) as /2048 
  sendBit(LOW);   // DHST
  sendBit(HIGH);  // PS2
  sendBit(HIGH);  // PS1
  sendBit(HIGH);  // PS0
  sendBit(LOW);   // ODIR
  sendBit(LOW);   // MOT
 
  // the last two bits select the axis 
  if (axis == 0){ // x axis 
    sendBit(LOW); 
    sendBit(HIGH); 
  } 
  else if (axis == 1){ // y axis 
    sendBit(HIGH); 
    sendBit(LOW); 
  } 
  else{ // z axis 
    sendBit(HIGH); 
    sendBit(HIGH); 
  } 
 
  // replace this with interrupt and/or state machine
  // wait until the DRDY line is high 
  while(digitalRead( PIN_M3D_DRDY) == LOW) { 
  } 
 
  long total = 0; 
 
  // receive result 
  // the leftmost bit mark the number as positive or negative 
  long sign = receiveBit(); 
  int i;
  
  // the remaining bits are converted to an integer 
  for ( i = 14; i >= 0; i = i - 1) {
    long thisbit = receiveBit(); 
    thisbit = thisbit << i; 
    total = total | thisbit; 
  } 
 
  if (sign == 1) { 
    total = total - 32768; 
  } 
  
  return total;
}

static void sendBit(int bit)
{ 
  // send the bit on the RISING edge of the clock 
  // decrease timings when everything works
  digitalWrite( PIN_M3D_MOSI, bit); 
  delayMicroseconds(1); 
  digitalWrite( PIN_M3D_SCLK, HIGH); 
  delayMicroseconds(1); 
  digitalWrite( PIN_M3D_SCLK, LOW); 
  delayMicroseconds(1); 
} 

static int receiveBit(){ 
  // receive the data on the FALLING edge of the clock 
  digitalWrite( PIN_M3D_SCLK, HIGH); 
  delayMicroseconds(1); 
  int bit = digitalRead( PIN_M3D_MISO); 
  delayMicroseconds(1); 
  digitalWrite( PIN_M3D_SCLK, LOW); 
  delayMicroseconds(1);
  
  return bit; 
}

int Rad2Deg (double angle) {
  static double ratio = 180.0 / 3.141592653589793238;
  return (int) (angle * ratio);
}
