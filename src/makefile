CFLAGS = -mmcu=atmega168 -g -I../external/ArduinoCore -I../external/Servo -I../external/Wire -I../external/MEssenger
CPPFLAGS = -mmcu=atmega168 -g -I../external/ArduinoCore -I../external/Servo -I../external/Wire -I../external/MEssenger
CC = avr-gcc
CXX = avr-g++
LD = avr-g++
LDFLAGS = -nostdlib

helmsman: main.o arduinoMain.o ai.o listener.o logging.o magneto3d.o rc.o servos.o windMagneto.o
	$(LD) -o $($@) $^





