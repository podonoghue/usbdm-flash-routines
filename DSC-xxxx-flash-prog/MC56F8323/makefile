################################################################################
# Automatically-generated file. Do not edit!
################################################################################

#Progress monitor hint: 2
first : all
-include ../makefile.init

# This file contains definitions of environment variables used in the makefiles and .args files if exist.
-include makefile.local

RM := "$(Gnu_Make_Install_DirEnv)/rm" -f

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir.mk
-include Sources/subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
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

EXECUTABLES_QUOTED += \

EXECUTABLES_OS_FORMAT += \


# All Target
all: DSC-56F8323-flash-prog.elf

# Tool invocations
DSC-56F8323-flash-prog.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Executing target #3 $@'
	@echo 'Invoking: DSC Linker'
	"$(DSC_ToolsDirEnv)/mwld56800e" -msgstyle parseable -g -nostdlib "$(ProjDirPath)/Project_Settings/Linker_Files/linker_8323.cmd" -main Fasm_entry -ldata -map -srec -sreclength 36 -o "DSC-56F8323-flash-prog.elf" $(OBJS_QUOTED) $(USER_OBJS_QUOTED) $(LIBS_QUOTED)
	@echo 'Finished building target: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(CXX_DEPS_QUOTED) $(C_UPPER_DEPS_QUOTED) "./*/*.o"  $(CPP_DEPS_QUOTED) $(CC_DEPS_QUOTED) $(EXECUTABLES_QUOTED) "./*/*.d"  DSC-56F8323-flash-prog.elf
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
