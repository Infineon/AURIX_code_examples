################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Libraries/iLLD/TC39B/Tricore/Scu/Std/IfxScuCcu.c \
../Libraries/iLLD/TC39B/Tricore/Scu/Std/IfxScuEru.c \
../Libraries/iLLD/TC39B/Tricore/Scu/Std/IfxScuLbist.c \
../Libraries/iLLD/TC39B/Tricore/Scu/Std/IfxScuRcu.c \
../Libraries/iLLD/TC39B/Tricore/Scu/Std/IfxScuWdt.c 

COMPILED_SRCS += \
./Libraries/iLLD/TC39B/Tricore/Scu/Std/IfxScuCcu.src \
./Libraries/iLLD/TC39B/Tricore/Scu/Std/IfxScuEru.src \
./Libraries/iLLD/TC39B/Tricore/Scu/Std/IfxScuLbist.src \
./Libraries/iLLD/TC39B/Tricore/Scu/Std/IfxScuRcu.src \
./Libraries/iLLD/TC39B/Tricore/Scu/Std/IfxScuWdt.src 

C_DEPS += \
./Libraries/iLLD/TC39B/Tricore/Scu/Std/IfxScuCcu.d \
./Libraries/iLLD/TC39B/Tricore/Scu/Std/IfxScuEru.d \
./Libraries/iLLD/TC39B/Tricore/Scu/Std/IfxScuLbist.d \
./Libraries/iLLD/TC39B/Tricore/Scu/Std/IfxScuRcu.d \
./Libraries/iLLD/TC39B/Tricore/Scu/Std/IfxScuWdt.d 

OBJS += \
./Libraries/iLLD/TC39B/Tricore/Scu/Std/IfxScuCcu.o \
./Libraries/iLLD/TC39B/Tricore/Scu/Std/IfxScuEru.o \
./Libraries/iLLD/TC39B/Tricore/Scu/Std/IfxScuLbist.o \
./Libraries/iLLD/TC39B/Tricore/Scu/Std/IfxScuRcu.o \
./Libraries/iLLD/TC39B/Tricore/Scu/Std/IfxScuWdt.o 


# Each subdirectory must supply rules for building sources it contributes
Libraries/iLLD/TC39B/Tricore/Scu/Std/%.src: ../Libraries/iLLD/TC39B/Tricore/Scu/Std/%.c Libraries/iLLD/TC39B/Tricore/Scu/Std/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING C/C++ Compiler'
	cctc -cs --dep-file="$(basename $@).d" --misrac-version=2004 -D__CPU__=tc39xb "-fC:/Users/Laprais/AURIX-v1.9.20-workspace/PMIC_SLEEP_AK/TriCore Debug (TASKING)/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc39xb -Y0 -N0 -Z0 -o "$@" "$<" && \
	if [ -f "$(basename $@).d" ]; then sed.exe -r  -e 's/\b(.+\.o)\b/Libraries\/iLLD\/TC39B\/Tricore\/Scu\/Std\/\1/g' -e 's/\\/\//g' -e 's/\/\//\//g' -e 's/"//g' -e 's/([a-zA-Z]:\/)/\L\1/g' -e 's/\d32:/@TARGET_DELIMITER@/g; s/\\\d32/@ESCAPED_SPACE@/g; s/\d32/\\\d32/g; s/@ESCAPED_SPACE@/\\\d32/g; s/@TARGET_DELIMITER@/\d32:/g' "$(basename $@).d" > "$(basename $@).d_sed" && cp "$(basename $@).d_sed" "$(basename $@).d" && rm -f "$(basename $@).d_sed" 2>/dev/null; else echo 'No dependency file to process';fi
	@echo 'Finished building: $<'
	@echo ' '

Libraries/iLLD/TC39B/Tricore/Scu/Std/IfxScuCcu.o: ./Libraries/iLLD/TC39B/Tricore/Scu/Std/IfxScuCcu.src Libraries/iLLD/TC39B/Tricore/Scu/Std/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING Assembler'
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Libraries/iLLD/TC39B/Tricore/Scu/Std/IfxScuEru.o: ./Libraries/iLLD/TC39B/Tricore/Scu/Std/IfxScuEru.src Libraries/iLLD/TC39B/Tricore/Scu/Std/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING Assembler'
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Libraries/iLLD/TC39B/Tricore/Scu/Std/IfxScuLbist.o: ./Libraries/iLLD/TC39B/Tricore/Scu/Std/IfxScuLbist.src Libraries/iLLD/TC39B/Tricore/Scu/Std/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING Assembler'
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Libraries/iLLD/TC39B/Tricore/Scu/Std/IfxScuRcu.o: ./Libraries/iLLD/TC39B/Tricore/Scu/Std/IfxScuRcu.src Libraries/iLLD/TC39B/Tricore/Scu/Std/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING Assembler'
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Libraries/iLLD/TC39B/Tricore/Scu/Std/IfxScuWdt.o: ./Libraries/iLLD/TC39B/Tricore/Scu/Std/IfxScuWdt.src Libraries/iLLD/TC39B/Tricore/Scu/Std/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING Assembler'
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-Libraries-2f-iLLD-2f-TC39B-2f-Tricore-2f-Scu-2f-Std

clean-Libraries-2f-iLLD-2f-TC39B-2f-Tricore-2f-Scu-2f-Std:
	-$(RM) ./Libraries/iLLD/TC39B/Tricore/Scu/Std/IfxScuCcu.d ./Libraries/iLLD/TC39B/Tricore/Scu/Std/IfxScuCcu.o ./Libraries/iLLD/TC39B/Tricore/Scu/Std/IfxScuCcu.src ./Libraries/iLLD/TC39B/Tricore/Scu/Std/IfxScuEru.d ./Libraries/iLLD/TC39B/Tricore/Scu/Std/IfxScuEru.o ./Libraries/iLLD/TC39B/Tricore/Scu/Std/IfxScuEru.src ./Libraries/iLLD/TC39B/Tricore/Scu/Std/IfxScuLbist.d ./Libraries/iLLD/TC39B/Tricore/Scu/Std/IfxScuLbist.o ./Libraries/iLLD/TC39B/Tricore/Scu/Std/IfxScuLbist.src ./Libraries/iLLD/TC39B/Tricore/Scu/Std/IfxScuRcu.d ./Libraries/iLLD/TC39B/Tricore/Scu/Std/IfxScuRcu.o ./Libraries/iLLD/TC39B/Tricore/Scu/Std/IfxScuRcu.src ./Libraries/iLLD/TC39B/Tricore/Scu/Std/IfxScuWdt.d ./Libraries/iLLD/TC39B/Tricore/Scu/Std/IfxScuWdt.o ./Libraries/iLLD/TC39B/Tricore/Scu/Std/IfxScuWdt.src

.PHONY: clean-Libraries-2f-iLLD-2f-TC39B-2f-Tricore-2f-Scu-2f-Std

