################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"../Sources/main.c" \

ASM_SRCS += \
../Sources/VectorTable.asm \

C_SRCS += \
../Sources/main.c \

ASM_SRCS_QUOTED += \
"../Sources/VectorTable.asm" \

OBJS += \
./Sources/VectorTable.o \
./Sources/main.o \

C_DEPS += \
./Sources/main.d \

OBJS_QUOTED += \
"./Sources/VectorTable.o" \
"./Sources/main.o" \

OBJS_OS_FORMAT += \
./Sources/VectorTable.o \
./Sources/main.o \

C_DEPS_QUOTED += \
"./Sources/main.d" \


# Each subdirectory must supply rules for building sources it contributes
Sources/VectorTable.o: ../Sources/VectorTable.asm
	@echo 'Building file: $<'
	@echo 'Executing target #1 $<'
	@echo 'Invoking: DSC Assembler'
	"$(DSC_ToolsDirEnv)/mwasm56800e" -msgstyle parseable -debug -nosyspath -data 24 -prog 21 -o "Sources/VectorTable.o" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Sources/main.o: ../Sources/main.c
	@echo 'Building file: $<'
	@echo 'Executing target #2 $<'
	@echo 'Invoking: DSC Compiler'
	"$(DSC_ToolsDirEnv)/mwcc56800e" -c -msgstyle parseable -g -DTARGET=MC56F8323 -i "$(MCUToolsBaseDirEnv)/M56800E Support/runtime_56800E/include" -i "$(MCUToolsBaseDirEnv)/M56800E Support/msl/MSL_C/MSL_Common/Include" -i "$(MCUToolsBaseDirEnv)/M56800E Support/msl/MSL_C/DSP_56800E/prefix" -i "$(MCUToolsBaseDirEnv)/M56800E Support" -w illpragmas -w possible -w extended -w extracomma -w emptydecl -w structclass -w notinlined -opt level=3 -opt space -inline nobottomup -ldata -requireprotos -o "Sources/main.o" "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

Sources/main.d: ../Sources/main.c
	@echo 'Regenerating dependency file: $@'
	
	@echo ' '


