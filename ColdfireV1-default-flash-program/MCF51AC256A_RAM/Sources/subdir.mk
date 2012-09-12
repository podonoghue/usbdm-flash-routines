################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"../Sources/exceptions.c" \
"../Sources/main.c" \

C_SRCS += \
../Sources/exceptions.c \
../Sources/main.c \

OBJS += \
./Sources/exceptions_c.obj \
./Sources/main_c.obj \

OBJS_QUOTED += \
"./Sources/exceptions_c.obj" \
"./Sources/main_c.obj" \

C_DEPS += \
./Sources/exceptions_c.d \
./Sources/main_c.d \

OBJS_OS_FORMAT += \
./Sources/exceptions_c.obj \
./Sources/main_c.obj \

C_DEPS_QUOTED += \
"./Sources/exceptions_c.d" \
"./Sources/main_c.d" \


# Each subdirectory must supply rules for building sources it contributes
Sources/exceptions_c.obj: ../Sources/exceptions.c
	@echo 'Building file: $<'
	@echo 'Executing target #1 $<'
	@echo 'Invoking: ColdFire Compiler'
	"$(CF_ToolsDirEnv)/mwccmcf" @@"Sources/exceptions.args" -o "Sources/exceptions_c.obj" "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

Sources/%.d: ../Sources/%.c
	@echo 'Regenerating dependency file: $@'
	
	@echo ' '

Sources/main_c.obj: ../Sources/main.c
	@echo 'Building file: $<'
	@echo 'Executing target #2 $<'
	@echo 'Invoking: ColdFire Compiler'
	"$(CF_ToolsDirEnv)/mwccmcf" @@"Sources/main.args" -o "Sources/main_c.obj" "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '


