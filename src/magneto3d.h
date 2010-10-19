/*
 * Public functions of the 3D Magnetometer
 */
extern "C" {
  
extern int m3d_X;
extern int m3d_Y;
extern int m3d_Z;
extern unsigned long m3d_timestamp;

void m3d_setup();
void m3d_do();
}
