################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Libraries/Service/CpuGeneric/StdIf/IfxStdIf_DPipe.c \
../Libraries/Service/CpuGeneric/StdIf/IfxStdIf_Pos.c \
../Libraries/Service/CpuGeneric/StdIf/IfxStdIf_PwmHl.c \
../Libraries/Service/CpuGeneric/StdIf/IfxStdIf_Timer.c 

COMPILED_SRCS += \
./Libraries/Service/CpuGeneric/StdIf/IfxStdIf_DPipe.src \
./Libraries/Service/CpuGeneric/StdIf/IfxStdIf_Pos.src \
./Libraries/Service/CpuGeneric/StdIf/IfxStdIf_PwmHl.src \
./Libraries/Service/CpuGeneric/StdIf/IfxStdIf_Timer.src 

C_DEPS += \
./Libraries/Service/CpuGeneric/StdIf/IfxStdIf_DPipe.d \
./Libraries/Service/CpuGeneric/StdIf/IfxStdIf_Pos.d \
./Libraries/Service/CpuGeneric/StdIf/IfxStdIf_PwmHl.d \
./Libraries/Service/CpuGeneric/StdIf/IfxStdIf_Timer.d 

OBJS += \
./Libraries/Service/CpuGeneric/StdIf/IfxStdIf_DPipe.o \
./Libraries/Service/CpuGeneric/StdIf/IfxStdIf_Pos.o \
./Libraries/Service/CpuGeneric/StdIf/IfxStdIf_PwmHl.o \
./Libraries/Service/CpuGeneric/StdIf/IfxStdIf_Timer.o 


# Each subdirectory must supply rules for building sources it contributes
Libraries/Service/CpuGeneric/StdIf/%.src: ../Libraries/Service/CpuGeneric/StdIf/%.c Libraries/Service/CpuGeneric/StdIf/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING C/C++ Compiler'
	cctc -cs --dep-file="$(basename $@).d" --misrac-version=2004 -D__CPU__=tc39xb "-fC:/Users/Laprais/AURIX-v1.9.20-workspace/PMIC_SLEEP_AK/TriCore Debug (TASKING)/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc39xb -Y0 -N0 -Z0 -o "$@" "$<" && \
	if [ -f "$(basename $@).d" ]; then sed.exe -r  -e 's/\b(.+\.o)\b/Libraries\/Service\/CpuGeneric\/StdIf\/\1/g' -e 's/\\/\//g' -e 's/\/\//\//g' -e 's/"//g' -e 's/([a-zA-Z]:\/)/\L\1/g' -e 's/\d32:/@TARGET_DELIMITER@/g; s/\\\d32/@ESCAPED_SPACE@/g; s/\d32/\\\d32/g; s/@ESCAPED_SPACE@/\\\d32/g; s/@TARGET_DELIMITER@/\d32:/g' "$(basename $@).d" > "$(basename $@).d_sed" && cp "$(basename $@).d_sed" "$(basename $@).d" && rm -f "$(basename $@).d_sed" 2>/dev/null; else echo 'No dependency file to process';fi
	@echo 'Finished building: $<'
	@echo ' '

Libraries/Service/CpuGeneric/StdIf/IfxStdIf_DPipe.o: ./Libraries/Service/CpuGeneric/StdIf/IfxStdIf_DPipe.src Libraries/Service/CpuGeneric/StdIf/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING Assembler'
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Libraries/Service/CpuGeneric/StdIf/IfxStdIf_Pos.o: ./Libraries/Service/CpuGeneric/StdIf/IfxStdIf_Pos.src Libraries/Service/CpuGeneric/StdIf/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING Assembler'
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Libraries/Service/CpuGeneric/StdIf/IfxStdIf_PwmHl.o: ./Libraries/Service/CpuGeneric/StdIf/IfxStdIf_PwmHl.src Libraries/Service/CpuGeneric/StdIf/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING Assembler'
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Libraries/Service/CpuGeneric/StdIf/IfxStdIf_Timer.o: ./Libraries/Service/CpuGeneric/StdIf/IfxStdIf_Timer.src Libraries/Service/CpuGeneric/StdIf/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING Assembler'
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-Libraries-2f-Service-2f-CpuGeneric-2f-StdIf

clean-Libraries-2f-Service-2f-CpuGeneric-2f-StdIf:
	-$(RM) ./Libraries/Service/CpuGeneric/StdIf/IfxStdIf_DPipe.d ./Libraries/Service/CpuGeneric/StdIf/IfxStdIf_DPipe.o ./Libraries/Service/CpuGeneric/StdIf/IfxStdIf_DPipe.src ./Libraries/Service/CpuGeneric/StdIf/IfxStdIf_Pos.d ./Libraries/Service/CpuGeneric/StdIf/IfxStdIf_Pos.o ./Libraries/Service/CpuGeneric/StdIf/IfxStdIf_Pos.src ./Libraries/Service/CpuGeneric/StdIf/IfxStdIf_PwmHl.d ./Libraries/Service/CpuGeneric/StdIf/IfxStdIf_PwmHl.o ./Libraries/Service/CpuGeneric/StdIf/IfxStdIf_PwmHl.src ./Libraries/Service/CpuGeneric/StdIf/IfxStdIf_Timer.d ./Libraries/Service/CpuGeneric/StdIf/IfxStdIf_Timer.o ./Libraries/Service/CpuGeneric/StdIf/IfxStdIf_Timer.src

.PHONY: clean-Libraries-2f-Service-2f-CpuGeneric-2f-StdIf

