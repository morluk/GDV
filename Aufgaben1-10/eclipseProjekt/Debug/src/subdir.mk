################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/MeinTisch.cpp \
../src/Tisch.cpp \
../src/Tischplatte.cpp \
../src/Wuerfel.cpp 

OBJS += \
./src/MeinTisch.o \
./src/Tisch.o \
./src/Tischplatte.o \
./src/Wuerfel.o 

CPP_DEPS += \
./src/MeinTisch.d \
./src/Tisch.d \
./src/Tischplatte.d \
./src/Wuerfel.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I"/home/gugugs/HDA_git/GDV/Praktikum/1/Aufgabe/eclipseProjekt/include" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


