CFLAGS = -mmcu=atmega168 -g -I../external/ArduinoCore -I../external/Servo -I../external/Wire -I../external/MEssenger
CPPFLAGS = -mmcu=atmega168 -g -I../external/ArduinoCore -I../external/Servo -I../external/Wire -I../external/MEssenger
CC = avr-gcc
CXX = avr-g++
LD = avr-g++
LDFLAGS = -nostdlib
COREDIR = ../external/ArduinoCore
LOADLIBES = ../external/Wire/utility/twi.o ../external/Wire/Wire.o ../external/Servo/Servo.o ../external/Messenger/Messenger.o $(COREDIR)/HardwareSerial.o $(COREDIR)/Print.o $(COREDIR)/WMath.o $(COREDIR)/wiring_digital.o $(COREDIR)/wiring_analog.o $(COREDIR)/wiring.o $(COREDIR)/wiring_pulse.o $(COREDIR)/pins_arduino.o

helmsman: ai.o listener.o logging.o magneto3d.o rc.o servos.o windMagneto.o $(LOADLIBES) main.o arduinoMain.o
	$(LD) -o $($@) $^ 





