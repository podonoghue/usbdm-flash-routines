################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := usbdm-rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Sources/subdir.mk
-include subdir.mk
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
MAP_FILE_OUTPUTS += \
Kinetis-M0-FTFA-MCM-WDOG-flash-program-gcc.map \

ARCHIVES += \
libUSER_OBJS.a \

SIZE_FILE_OUTPUTS += \
Kinetis-M0-FTFA-MCM-WDOG-flash-program-gcc.size \

SYMBOL_LIST_FILE_OUTPUTS += \
Kinetis-M0-FTFA-MCM-WDOG-flash-program-gcc.sym \


# All Target
all: Kinetis-M0-FTFA-MCM-WDOG-flash-program-gcc.elf secondary-outputs

# Tool invocations
Kinetis-M0-FTFA-MCM-WDOG-flash-program-gcc.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: ARM C++ Linker'
	arm-none-eabi-g++ -mcpu=cortex-m0plus -mthumb -g3 -Os -Wl,--gc-sections -nostartfiles -nostdlib -L"C:/Users/podonoghue/Documents/Development/workspace.kds/Kinetis-M0-FTFA-MCM-WDOG-flash-program-gcc/Project_Settings/Linker_Files" --specs=nano.specs -T "RAM.ld" -Xlinker -Map="Kinetis-M0-FTFA-MCM-WDOG-flash-program-gcc.map"  -o "Kinetis-M0-FTFA-MCM-WDOG-flash-program-gcc.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

Kinetis-M0-FTFA-MCM-WDOG-flash-program-gcc.map: Kinetis-M0-FTFA-MCM-WDOG-flash-program-gcc.elf $(OBJS) $(USER_OBJS)

libUSER_OBJS.a: $(OBJS) $(USER_OBJS)
	@echo 'Invoking: ARM Archiver'
	arm-none-eabi-ar -r   "libUSER_OBJS.a" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building: $@'
	@echo ' '

Kinetis-M0-FTFA-MCM-WDOG-flash-program-gcc.size: Kinetis-M0-FTFA-MCM-WDOG-flash-program-gcc.elf
	@echo 'Invoking: ARM Sizer'
	arm-none-eabi-size "Kinetis-M0-FTFA-MCM-WDOG-flash-program-gcc.elf" --format=sysv --radix=10   >"Kinetis-M0-FTFA-MCM-WDOG-flash-program-gcc.size"
	@echo 'Finished building: $@'
	@echo ' '

Kinetis-M0-FTFA-MCM-WDOG-flash-program-gcc.sym: Kinetis-M0-FTFA-MCM-WDOG-flash-program-gcc.elf
	@echo 'Invoking: ARM Symbol Table'
	arm-none-eabi-nm "Kinetis-M0-FTFA-MCM-WDOG-flash-program-gcc.elf" --demangle --defined-only --extern-only --numeric-sort   >"Kinetis-M0-FTFA-MCM-WDOG-flash-program-gcc.sym"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(C++_DEPS)$(OBJS)$(C_DEPS)$(CC_DEPS)$(MAP_FILE_OUTPUTS)$(ARCHIVES)$(SYMBOL_LIST_FILE_OUTPUTS)$(CPP_DEPS)$(SIZE_FILE_OUTPUTS)$(EXECUTABLES)$(LIST_FILE_OUTPUTS)$(CXX_DEPS)$(C_UPPER_DEPS) Kinetis-M0-FTFA-MCM-WDOG-flash-program-gcc.elf
	-@echo ' '

secondary-outputs: $(LIST_FILE_OUTPUTS) $(SIZE_FILE_OUTPUTS) $(SYMBOL_LIST_FILE_OUTPUTS)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
