################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Boden.cpp \
../src/Tisch.cpp \
../src/TischleinDeckDich.cpp \
../src/Tischplatte.cpp \
../src/Wuerfel.cpp 

OBJS += \
./src/Boden.o \
./src/Tisch.o \
./src/TischleinDeckDich.o \
./src/Tischplatte.o \
./src/Wuerfel.o 

CPP_DEPS += \
./src/Boden.d \
./src/Tisch.d \
./src/TischleinDeckDich.d \
./src/Tischplatte.d \
./src/Wuerfel.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I../include -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


