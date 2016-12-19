################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Sources/kinetis_sysinit.c \
../Sources/main.c 

OBJS += \
./Sources/kinetis_sysinit.o \
./Sources/main.o 

C_DEPS += \
./Sources/kinetis_sysinit.d \
./Sources/main.d 


# Each subdirectory must supply rules for building sources it contributes
Sources/%.o: ../Sources/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m0plus -mthumb -g3 -Os -fshort-enums -ffunction-sections -fdata-sections -Wall -Wextra -I"C:/Users/podonoghue/Documents/Development/workspace.kds/Kinetis-M0-FTFA-MCM-WDOG-flash-program-gcc/Sources" -I"C:/Users/podonoghue/Documents/Development/workspace.kds/Kinetis-M0-FTFA-MCM-WDOG-flash-program-gcc/Project_Headers" -std=c11 -c -fmessage-length=0 -MT"$@" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)"  -o "$@" $<
	@echo 'Finished building: $<'
	@echo ' '


