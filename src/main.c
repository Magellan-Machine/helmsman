/**
 *  main.cpp
 *
 * Contains main function, which is only neccessary when building the project
 * outside the Arduino IDE.
 *
 */
#include <WProgram.h>
#include "arduinoMain.h"

int main(void) {

  /* Must call init for arduino to work properly */
  init();
  setup();

  for (;;) {
	  loop();
  } // end for
} // end main

void __cxa_pure_virtual()
{
  cli();
  for (;;);
}
