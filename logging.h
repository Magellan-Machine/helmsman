#ifndef CIRCUMSAIL_LOGGING_H
#define CIRCUMSAIL_LOGGING_H

#include <WProgram.h>

void logging_setup();
void logging_do(byte single_pulse=false);
void logging_set_interval(int interval);

#endif
