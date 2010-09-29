#ifndef CIRCUMSAIL_VARIABLES_H
#define CIRCUMSAIL_VARIABLES_H

///////////////////////////////////////////
//       PROGRAM-WIDE VARIABLES          //
///////////////////////////////////////////

// Logical value
extern int pilot_mode;
extern int desired_heading;
extern int true_wind;        // direction from which the wind is blowing (according to compass)

// Boat
extern int boat_heading;
extern int boat_heeling;     // healing of the boat (degrees from vertical, port [left] < 0 < starboard [right]
extern int boat_speed;

// Environment
extern int north;
extern int m3d_X;            // TODO: remove x, y, z when tested
extern int m3d_Y;
extern int m3d_Z;

#endif
