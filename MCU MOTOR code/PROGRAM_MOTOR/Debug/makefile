################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include utilities/subdir.mk
-include startup/subdir.mk
-include source/subdir.mk
-include drivers/subdir.mk
-include device/subdir.mk
-include component/uart/subdir.mk
-include component/serial_manager/subdir.mk
-include component/lists/subdir.mk
-include board/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: PROGRAM_MOTOR.axf

# Tool invocations
PROGRAM_MOTOR.axf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: MCU Linker'
	arm-none-eabi-gcc -nostdlib -L"/home/abhishek/Documents/MCUXpresso_10.3.1_2233/workspace/PROGRAM_MOTOR/libs" -Xlinker -Map="PROGRAM_MOTOR.map" -Xlinker --gc-sections -Xlinker -print-memory-usage -Xlinker --sort-section=alignment -mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -T lpcxpresso54114_sctimer_multi_state_pwm_Debug.ld -o "PROGRAM_MOTOR.axf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '
	$(MAKE) --no-print-directory post-build

# Other Targets
clean:
	-$(RM) $(EXECUTABLES)$(OBJS)$(C_DEPS) PROGRAM_MOTOR.axf
	-@echo ' '

post-build:
	-@echo 'Performing post-build steps'
	-arm-none-eabi-size "PROGRAM_MOTOR.axf"; # arm-none-eabi-objcopy -v -O binary "PROGRAM_MOTOR.axf" "PROGRAM_MOTOR.bin" ; # checksum -p LPC54114J256 -d "PROGRAM_MOTOR.bin";
	-@echo ' '

.PHONY: all clean dependents post-build

-include ../makefile.targets
