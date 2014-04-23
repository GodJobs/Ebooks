################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/ChapServer.cpp \
../src/ChapService.cpp 

OBJS += \
./src/ChapServer.o \
./src/ChapService.o 

CPP_DEPS += \
./src/ChapServer.d \
./src/ChapService.d 


# Each subdirectory must supply rules for building sources it contributes
src/ChapServer.o: ../src/ChapServer.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/home/lizhi/source/orignal/android-4.1.1_r4/frameworks/native/include -I/home/lizhi/source/orignal/android-4.1.1_r4/system/core/include -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"src/ChapServer.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/home/lizhi/source/orignal/android-4.1.1_r4/frameworks/native/include -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


