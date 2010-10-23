################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../old/HardwareSerial.cpp \
../old/Print.cpp \
../old/Tone.cpp \
../old/WMath.cpp 

C_SRCS += \
../old/WInterrupts.c \
../old/pins_arduino.c \
../old/wiring.c \
../old/wiring_analog.c \
../old/wiring_digital.c \
../old/wiring_pulse.c \
../old/wiring_shift.c 

OBJS += \
./old/HardwareSerial.o \
./old/Print.o \
./old/Tone.o \
./old/WInterrupts.o \
./old/WMath.o \
./old/pins_arduino.o \
./old/wiring.o \
./old/wiring_analog.o \
./old/wiring_digital.o \
./old/wiring_pulse.o \
./old/wiring_shift.o 

C_DEPS += \
./old/WInterrupts.d \
./old/pins_arduino.d \
./old/wiring.d \
./old/wiring_analog.d \
./old/wiring_digital.d \
./old/wiring_pulse.d \
./old/wiring_shift.d 

CPP_DEPS += \
./old/HardwareSerial.d \
./old/Print.d \
./old/Tone.d \
./old/WMath.d 


# Each subdirectory must supply rules for building sources it contributes
old/%.o: ../old/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: AVR C++ Compiler'
	avr-g++ -I/usr/share/arduino/hardware/arduino/cores/arduino/ -Wall -Os -fpack-struct -fshort-enums -funsigned-char -funsigned-bitfields -fno-exceptions -mmcu=atmega328p -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -c -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

old/%.o: ../old/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I/usr/share/arduino/hardware/arduino/cores/arduino/ -Wall -Os -fpack-struct -fshort-enums -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega328p -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -c -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


