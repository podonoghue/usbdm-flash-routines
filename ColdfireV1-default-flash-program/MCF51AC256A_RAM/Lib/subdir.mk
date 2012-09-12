################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"../Lib/mcf51ac256a.c" \

C_SRCS += \
../Lib/mcf51ac256a.c \

OBJS += \
./Lib/mcf51ac256a_c.obj \

OBJS_QUOTED += \
"./Lib/mcf51ac256a_c.obj" \

C_DEPS += \
./Lib/mcf51ac256a_c.d \

OBJS_OS_FORMAT += \
./Lib/mcf51ac256a_c.obj \

C_DEPS_QUOTED += \
"./Lib/mcf51ac256a_c.d" \


# Each subdirectory must supply rules for building sources it contributes
Lib/mcf51ac256a_c.obj: ../Lib/mcf51ac256a.c
	@echo 'Building file: $<'
	@echo 'Executing target #3 $<'
	@echo 'Invoking: ColdFire Compiler'
	"$(CF_ToolsDirEnv)/mwccmcf" @@"Lib/mcf51ac256a.args" -o "Lib/mcf51ac256a_c.obj" "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

Lib/%.d: ../Lib/%.c
	@echo 'Regenerating dependency file: $@'
	
	@echo ' '


