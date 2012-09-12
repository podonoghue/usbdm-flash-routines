################################################################################
# Automatically-generated file. Do not edit!
################################################################################

#Progress monitor hint: 1
first : all
-include ../makefile.init

# This file contains definitions of environment variables used in the makefiles and .args files if exist.
-include makefile.local

RM := "$(Gnu_Make_Install_DirEnv)/rm" -f

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir.mk
-include Sources/subdir.mk
-include Project_Settings/Linker_Files/subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
HCS08-default-0xB0-flash-program.abs \

EXECUTABLES_QUOTED += \
"HCS08-default-0xB0-flash-program.abs" \

EXECUTABLES_OS_FORMAT += \
HCS08-default-0xB0-flash-program.abs \

BURNER_OUTPUT_OUTPUTS += \
HCS08-default-0xB0-flash-program.abs.s19 \

BURNER_OUTPUT_OUTPUTS_QUOTED += \
"HCS08-default-0xB0-flash-program.abs.s19" \

BURNER_OUTPUT_OUTPUTS_OS_FORMAT += \
HCS08-default-0xB0-flash-program.abs.s19 \


# All Target
call-burner := 0
ifneq ($(strip $(EXECUTABLES)),)
ifneq ($(strip $(BBL_SRCS_QUOTED)),)
call-burner := 1
endif
endif
ifeq ($(call-burner),1)
all: HCS08-default-0xB0-flash-program.abs HCS08-default-0xB0-flash-program.abs.s19
else
all: HCS08-default-0xB0-flash-program.abs
endif

# Tool invocations
HCS08-default-0xB0-flash-program.abs: $(OBJS) $(USER_OBJS) ../Project_Settings/Linker_Files/Project@0xB0.prm
	@echo 'Building target: $@'
	@echo 'Executing target #2 $@'
	@echo 'Invoking: S08 Linker'
	"$(HC08ToolsEnv)/linker" -ArgFile"HCS08-default-0xB0-flash-program.args" -O"HCS08-default-0xB0-flash-program.abs"
	@echo 'Finished building target: $@'
	@echo ' '

HCS08-default-0xB0-flash-program.abs.s19: $(BBL_SRCS) $(EXECUTABLES)
	@echo 'Executing target #3 $@'
	@echo 'Invoking: S08 Burner'
	"$(HC08ToolsEnv)/burner" -ArgFile"HCS08-default-0xB0-flash-program.abs.args" -f="$<" -env"ABS_FILE=$(strip $(EXECUTABLES_OS_FORMAT))"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) "./*/*.obj"  $(CPP_DEPS_QUOTED) $(CC_DEPS_QUOTED) $(CXX_DEPS_QUOTED) $(BURNER_OUTPUT_OUTPUTS_QUOTED) $(C_UPPER_DEPS_QUOTED) $(C++_DEPS_QUOTED) $(EXECUTABLES_QUOTED) $(C_DEPS_QUOTED) HCS08-default-0xB0-flash-program.abs
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
