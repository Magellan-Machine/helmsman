/*
 * servos.h
 * 
 * Interface to Circumsail servo functions
 */
 
#ifndef CIRCUMSAIL_SERVOS_H
#define CIRCUMSAIL_SERVOS_H

void servos_setup();
int servos_rudder_getPosition();
int servos_sail_getPosition();

/**
 * TODO: Document range of input values
 */
void servos_rudder_setPosition( int newPosition );

/**
 * TODO: Document range of input values 
 */
void servos_sail_setPosition( int newPosition );

#endif
