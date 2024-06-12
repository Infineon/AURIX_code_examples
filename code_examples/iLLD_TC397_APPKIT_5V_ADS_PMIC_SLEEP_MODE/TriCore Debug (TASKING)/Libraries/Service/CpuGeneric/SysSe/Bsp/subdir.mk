################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Libraries/Service/CpuGeneric/SysSe/Bsp/Assert.c \
../Libraries/Service/CpuGeneric/SysSe/Bsp/Bsp.c 

COMPILED_SRCS += \
./Libraries/Service/CpuGeneric/SysSe/Bsp/Assert.src \
./Libraries/Service/CpuGeneric/SysSe/Bsp/Bsp.src 

C_DEPS += \
./Libraries/Service/CpuGeneric/SysSe/Bsp/Assert.d \
./Libraries/Service/CpuGeneric/SysSe/Bsp/Bsp.d 

OBJS += \
./Libraries/Service/CpuGeneric/SysSe/Bsp/Assert.o \
./Libraries/Service/CpuGeneric/SysSe/Bsp/Bsp.o 


# Each subdirectory must supply rules for building sources it contributes
Libraries/Service/CpuGeneric/SysSe/Bsp/%.src: ../Libraries/Service/CpuGeneric/SysSe/Bsp/%.c Libraries/Service/CpuGeneric/SysSe/Bsp/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING C/C++ Compiler'
	cctc -cs --dep-file="$(basename $@).d" --misrac-version=2004 -D__CPU__=tc39xb "-fC:/Users/Laprais/AURIX-v1.9.20-workspace/PMIC_SLEEP_AK/TriCore Debug (TASKING)/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc39xb -Y0 -N0 -Z0 -o "$@" "$<" && \
	if [ -f "$(basename $@).d" ]; then sed.exe -r  -e 's/\b(.+\.o)\b/Libraries\/Service\/CpuGeneric\/SysSe\/Bsp\/\1/g' -e 's/\\/\//g' -e 's/\/\//\//g' -e 's/"//g' -e 's/([a-zA-Z]:\/)/\L\1/g' -e 's/\d32:/@TARGET_DELIMITER@/g; s/\\\d32/@ESCAPED_SPACE@/g; s/\d32/\\\d32/g; s/@ESCAPED_SPACE@/\\\d32/g; s/@TARGET_DELIMITER@/\d32:/g' "$(basename $@).d" > "$(basename $@).d_sed" && cp "$(basename $@).d_sed" "$(basename $@).d" && rm -f "$(basename $@).d_sed" 2>/dev/null; else echo 'No dependency file to process';fi
	@echo 'Finished building: $<'
	@echo ' '

Libraries/Service/CpuGeneric/SysSe/Bsp/Assert.o: ./Libraries/Service/CpuGeneric/SysSe/Bsp/Assert.src Libraries/Service/CpuGeneric/SysSe/Bsp/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING Assembler'
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Libraries/Service/CpuGeneric/SysSe/Bsp/Bsp.o: ./Libraries/Service/CpuGeneric/SysSe/Bsp/Bsp.src Libraries/Service/CpuGeneric/SysSe/Bsp/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING Assembler'
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-Libraries-2f-Service-2f-CpuGeneric-2f-SysSe-2f-Bsp

clean-Libraries-2f-Service-2f-CpuGeneric-2f-SysSe-2f-Bsp:
	-$(RM) ./Libraries/Service/CpuGeneric/SysSe/Bsp/Assert.d ./Libraries/Service/CpuGeneric/SysSe/Bsp/Assert.o ./Libraries/Service/CpuGeneric/SysSe/Bsp/Assert.src ./Libraries/Service/CpuGeneric/SysSe/Bsp/Bsp.d ./Libraries/Service/CpuGeneric/SysSe/Bsp/Bsp.o ./Libraries/Service/CpuGeneric/SysSe/Bsp/Bsp.src

.PHONY: clean-Libraries-2f-Service-2f-CpuGeneric-2f-SysSe-2f-Bsp

