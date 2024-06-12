################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include serialio/subdir.mk
-include Libraries/iLLD/TC39B/Tricore/_PinMap/subdir.mk
-include Libraries/iLLD/TC39B/Tricore/_Lib/DataHandling/subdir.mk
-include Libraries/iLLD/TC39B/Tricore/_Impl/subdir.mk
-include Libraries/iLLD/TC39B/Tricore/Stm/Std/subdir.mk
-include Libraries/iLLD/TC39B/Tricore/Src/Std/subdir.mk
-include Libraries/iLLD/TC39B/Tricore/Scu/Std/subdir.mk
-include Libraries/iLLD/TC39B/Tricore/Qspi/Std/subdir.mk
-include Libraries/iLLD/TC39B/Tricore/Qspi/SpiMaster/subdir.mk
-include Libraries/iLLD/TC39B/Tricore/Port/Std/subdir.mk
-include Libraries/iLLD/TC39B/Tricore/Pms/Std/subdir.mk
-include Libraries/iLLD/TC39B/Tricore/Mtu/Std/subdir.mk
-include Libraries/iLLD/TC39B/Tricore/I2c/Std/subdir.mk
-include Libraries/iLLD/TC39B/Tricore/I2c/I2c/subdir.mk
-include Libraries/iLLD/TC39B/Tricore/Gtm/Std/subdir.mk
-include Libraries/iLLD/TC39B/Tricore/Dma/Std/subdir.mk
-include Libraries/iLLD/TC39B/Tricore/Dma/Dma/subdir.mk
-include Libraries/iLLD/TC39B/Tricore/Cpu/Trap/subdir.mk
-include Libraries/iLLD/TC39B/Tricore/Cpu/Std/subdir.mk
-include Libraries/iLLD/TC39B/Tricore/Cpu/Irq/subdir.mk
-include Libraries/iLLD/TC39B/Tricore/Asclin/Std/subdir.mk
-include Libraries/iLLD/TC39B/Tricore/Asclin/Asc/subdir.mk
-include Libraries/Service/CpuGeneric/SysSe/Bsp/subdir.mk
-include Libraries/Service/CpuGeneric/StdIf/subdir.mk
-include Libraries/Service/CpuGeneric/If/subdir.mk
-include Libraries/Infra/Ssw/TC39B/Tricore/subdir.mk
-include Libraries/Infra/Platform/Tricore/Compilers/subdir.mk
-include Configurations/Debug/subdir.mk
-include Configurations/subdir.mk
-include subdir.mk
ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
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
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
endif

-include ../makefile.defs

OPTIONAL_TOOL_DEPS := \
$(wildcard ../makefile.defs) \
$(wildcard ../makefile.init) \
$(wildcard ../makefile.targets) \


BUILD_ARTIFACT_NAME := PMIC_SLEEP_AK
BUILD_ARTIFACT_EXTENSION := elf
BUILD_ARTIFACT_PREFIX :=
BUILD_ARTIFACT := $(BUILD_ARTIFACT_PREFIX)$(BUILD_ARTIFACT_NAME)$(if $(BUILD_ARTIFACT_EXTENSION),.$(BUILD_ARTIFACT_EXTENSION),)

# Add inputs and outputs from these tool invocations to the build variables 
SECONDARY_SIZE += \
PMIC_SLEEP_AK.siz \


# All Target
all: main-build

# Main-build Target
main-build: PMIC_SLEEP_AK.elf secondary-outputs

# Tool invocations
PMIC_SLEEP_AK.elf: $(OBJS) makefile $(OPTIONAL_TOOL_DEPS)
	@echo 'Building target: $@'
	@echo 'Invoking: TASKING Linker'
	cctc --lsl-file="../Lcf_Tasking_Tricore_Tc.lsl" -Wl-Oc -Wl-OL -Wl-Ot -Wl-Ox -Wl-Oy -Wl--map-file="PMIC_SLEEP_AK.map" -Wl-mc -Wl-mf -Wl-mi -Wl-mk -Wl-ml -Wl-mm -Wl-md -Wl-mr -Wl-mu --no-warnings= -Wl--error-limit=42 --fp-model=3 -lrt --lsl-core=vtc --exceptions --strict --anachronisms --force-c++ -Ctc39xb -o"PMIC_SLEEP_AK.elf" -Wl-o"PMIC_SLEEP_AK.hex:IHEX" $(OBJS)
	@echo 'Finished building target: $@'
	@echo ' '

PMIC_SLEEP_AK.siz: PMIC_SLEEP_AK.elf makefile $(OPTIONAL_TOOL_DEPS)
	@echo 'Invoking: Print Size'
	elfsize  "PMIC_SLEEP_AK.elf"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	find . ! -name "*.mk" ! -name "makefile" ! -name "." -type f -delete 
	-@echo ' '

secondary-outputs: $(SECONDARY_SIZE)

.PHONY: all clean dependents main-build

-include ../makefile.targets
