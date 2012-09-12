################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"../Sources/kinetis_sysinit.c" \
"../Sources/main.c" \

C_SRCS += \
../Sources/kinetis_sysinit.c \
../Sources/main.c \

OBJS += \
./Sources/kinetis_sysinit.obj \
./Sources/main.obj \

OBJS_QUOTED += \
"./Sources/kinetis_sysinit.obj" \
"./Sources/main.obj" \

C_DEPS += \
./Sources/kinetis_sysinit.d \
./Sources/main.d \

C_DEPS_QUOTED += \
"./Sources/kinetis_sysinit.d" \
"./Sources/main.d" \

OBJS_OS_FORMAT += \
./Sources/kinetis_sysinit.obj \
./Sources/main.obj \


# Each subdirectory must supply rules for building sources it contributes
Sources/kinetis_sysinit.obj: ../Sources/kinetis_sysinit.c
	@echo 'Building file: $<'
	@echo 'Executing target #1 $<'
	@echo 'Invoking: ARM Compiler'
	"$(ARM_ToolsDirEnv)/mwccarm" -gccinc @@"Sources/kinetis_sysinit.args" -o "Sources/kinetis_sysinit.obj" -c "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

Sources/%.d: ../Sources/%.c
	@echo 'Regenerating dependency file: $@'
	
	@echo ' '

Sources/main.obj: ../Sources/main.c
	@echo 'Building file: $<'
	@echo 'Executing target #2 $<'
	@echo 'Invoking: ARM Compiler'
	"$(ARM_ToolsDirEnv)/mwccarm" -gccinc @@"Sources/main.args" -o "Sources/main.obj" -c "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '


