################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Circle.cpp \
../src/Cone.cpp \
../src/Cube.cpp \
../src/GDV3.cpp \
../src/Ring.cpp \
../src/RingSide.cpp \
../src/RingTop.cpp \
../src/Rocket.cpp 

OBJS += \
./src/Circle.o \
./src/Cone.o \
./src/Cube.o \
./src/GDV3.o \
./src/Ring.o \
./src/RingSide.o \
./src/RingTop.o \
./src/Rocket.o 

CPP_DEPS += \
./src/Circle.d \
./src/Cone.d \
./src/Cube.d \
./src/GDV3.d \
./src/Ring.d \
./src/RingSide.d \
./src/RingTop.d \
./src/Rocket.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I../include -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


