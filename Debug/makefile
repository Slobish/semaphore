################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include src/subdir.mk
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
all: Semaforo1.axf

# Tool invocations
Semaforo1.axf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: MCU Linker'
	arm-none-eabi-gcc -nostdlib -L/home/samsung/Documentos/Info2/MCuXpresso/workspace/bibliotecaInfoII -Xlinker -Map="Semaforo1.map" -Xlinker --gc-sections -Xlinker -print-memory-usage -mcpu=cortex-m3 -mthumb -T "Semaforo1_Debug.ld" -o "Semaforo1.axf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '
	$(MAKE) --no-print-directory post-build

# Other Targets
clean:
	-$(RM) $(EXECUTABLES)$(OBJS)$(C_DEPS) Semaforo1.axf
	-@echo ' '

post-build:
	-@echo 'Performing post-build steps'
	-arm-none-eabi-size "Semaforo1.axf"; # arm-none-eabi-objcopy -v -O binary "Semaforo1.axf" "Semaforo1.bin" ; # checksum -p LPC1769 -d "Semaforo1.bin";
	-@echo ' '

.PHONY: all clean dependents post-build

-include ../makefile.targets
