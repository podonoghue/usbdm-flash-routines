################################################################################
# Automatically-generated file. Do not edit!
################################################################################

#Progress monitor hint: 3
first : all
-include ../makefile.init

# This file contains definitions of environment variables used in the makefiles and .args files if exist.
-include makefile.local

RM := "$(Gnu_Make_Install_DirEnv)/rm" -f

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir.mk
-include Sources/subdir.mk
-include Lib/subdir.mk
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
ColdfireV1-default-flash-program.elf \

EXECUTABLES_QUOTED += \
"ColdfireV1-default-flash-program.elf" \

EXECUTABLES_OS_FORMAT += \
ColdfireV1-default-flash-program.elf \

_OUTPUTTYPE_NAME_BURNER_OUTPUT_OUTPUTS += \
ColdfireV1-default-flash-program.elf.s19 \

_OUTPUTTYPE_NAME_BURNER_OUTPUT_OUTPUTS_QUOTED += \
"ColdfireV1-default-flash-program.elf.s19" \

_OUTPUTTYPE_NAME_BURNER_OUTPUT_OUTPUTS_OS_FORMAT += \
ColdfireV1-default-flash-program.elf.s19 \


# All Target
call-burner := 0
ifneq ($(strip $(EXECUTABLES)),)
ifneq ($(strip $(BBL_SRCS_QUOTED)),)
call-burner := 1
endif
endif
ifeq ($(call-burner),1)
all: ColdfireV1-default-flash-program.elf ColdfireV1-default-flash-program.elf.s19
else
all: ColdfireV1-default-flash-program.elf
endif

# Tool invocations
ColdfireV1-default-flash-program.elf: $(OBJS) $(USER_OBJS) ../Project_Settings/Linker_Files/Project.lcf
	@echo 'Building target: $@'
	@echo 'Executing target #4 $@'
	@echo 'Invoking: ColdFire Linker'
	"$(CF_ToolsDirEnv)/mwldmcf" @@"ColdfireV1-default-flash-program.args" -o "ColdfireV1-default-flash-program.elf"  $(USER_OBJS_QUOTED) $(LIBS_QUOTED)
	@echo 'Finished building target: $@'
	@echo ' '

ColdfireV1-default-flash-program.elf.s19: $(BBL_SRCS) $(EXECUTABLES)
	@echo 'Executing target #5 $@'
	@echo 'Invoking: Burner'
	"$(HC08ToolsEnv)/burner.exe"  -f="$<" -env"ABS_FILE=$(strip $(EXECUTABLES_OS_FORMAT))"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) "./*/*.obj"  $(CPP_DEPS_QUOTED) $(CC_DEPS_QUOTED) $(_OUTPUTTYPE_NAME_BURNER_OUTPUT_OUTPUTS_QUOTED) $(CXX_DEPS_QUOTED) $(C_UPPER_DEPS_QUOTED) $(C++_DEPS_QUOTED) $(EXECUTABLES_QUOTED) "./*/*.d"  ColdfireV1-default-flash-program.elf
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
