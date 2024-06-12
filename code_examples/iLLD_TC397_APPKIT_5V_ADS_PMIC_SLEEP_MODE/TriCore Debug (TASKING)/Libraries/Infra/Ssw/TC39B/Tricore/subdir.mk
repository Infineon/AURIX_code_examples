################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Libraries/Infra/Ssw/TC39B/Tricore/Ifx_Ssw_Infra.c \
../Libraries/Infra/Ssw/TC39B/Tricore/Ifx_Ssw_Tc0.c \
../Libraries/Infra/Ssw/TC39B/Tricore/Ifx_Ssw_Tc1.c \
../Libraries/Infra/Ssw/TC39B/Tricore/Ifx_Ssw_Tc2.c \
../Libraries/Infra/Ssw/TC39B/Tricore/Ifx_Ssw_Tc3.c \
../Libraries/Infra/Ssw/TC39B/Tricore/Ifx_Ssw_Tc4.c \
../Libraries/Infra/Ssw/TC39B/Tricore/Ifx_Ssw_Tc5.c 

COMPILED_SRCS += \
./Libraries/Infra/Ssw/TC39B/Tricore/Ifx_Ssw_Infra.src \
./Libraries/Infra/Ssw/TC39B/Tricore/Ifx_Ssw_Tc0.src \
./Libraries/Infra/Ssw/TC39B/Tricore/Ifx_Ssw_Tc1.src \
./Libraries/Infra/Ssw/TC39B/Tricore/Ifx_Ssw_Tc2.src \
./Libraries/Infra/Ssw/TC39B/Tricore/Ifx_Ssw_Tc3.src \
./Libraries/Infra/Ssw/TC39B/Tricore/Ifx_Ssw_Tc4.src \
./Libraries/Infra/Ssw/TC39B/Tricore/Ifx_Ssw_Tc5.src 

C_DEPS += \
./Libraries/Infra/Ssw/TC39B/Tricore/Ifx_Ssw_Infra.d \
./Libraries/Infra/Ssw/TC39B/Tricore/Ifx_Ssw_Tc0.d \
./Libraries/Infra/Ssw/TC39B/Tricore/Ifx_Ssw_Tc1.d \
./Libraries/Infra/Ssw/TC39B/Tricore/Ifx_Ssw_Tc2.d \
./Libraries/Infra/Ssw/TC39B/Tricore/Ifx_Ssw_Tc3.d \
./Libraries/Infra/Ssw/TC39B/Tricore/Ifx_Ssw_Tc4.d \
./Libraries/Infra/Ssw/TC39B/Tricore/Ifx_Ssw_Tc5.d 

OBJS += \
./Libraries/Infra/Ssw/TC39B/Tricore/Ifx_Ssw_Infra.o \
./Libraries/Infra/Ssw/TC39B/Tricore/Ifx_Ssw_Tc0.o \
./Libraries/Infra/Ssw/TC39B/Tricore/Ifx_Ssw_Tc1.o \
./Libraries/Infra/Ssw/TC39B/Tricore/Ifx_Ssw_Tc2.o \
./Libraries/Infra/Ssw/TC39B/Tricore/Ifx_Ssw_Tc3.o \
./Libraries/Infra/Ssw/TC39B/Tricore/Ifx_Ssw_Tc4.o \
./Libraries/Infra/Ssw/TC39B/Tricore/Ifx_Ssw_Tc5.o 


# Each subdirectory must supply rules for building sources it contributes
Libraries/Infra/Ssw/TC39B/Tricore/%.src: ../Libraries/Infra/Ssw/TC39B/Tricore/%.c Libraries/Infra/Ssw/TC39B/Tricore/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING C/C++ Compiler'
	cctc -cs --dep-file="$(basename $@).d" --misrac-version=2004 -D__CPU__=tc39xb "-fC:/Users/Laprais/AURIX-v1.9.20-workspace/PMIC_SLEEP_AK/TriCore Debug (TASKING)/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc39xb -Y0 -N0 -Z0 -o "$@" "$<" && \
	if [ -f "$(basename $@).d" ]; then sed.exe -r  -e 's/\b(.+\.o)\b/Libraries\/Infra\/Ssw\/TC39B\/Tricore\/\1/g' -e 's/\\/\//g' -e 's/\/\//\//g' -e 's/"//g' -e 's/([a-zA-Z]:\/)/\L\1/g' -e 's/\d32:/@TARGET_DELIMITER@/g; s/\\\d32/@ESCAPED_SPACE@/g; s/\d32/\\\d32/g; s/@ESCAPED_SPACE@/\\\d32/g; s/@TARGET_DELIMITER@/\d32:/g' "$(basename $@).d" > "$(basename $@).d_sed" && cp "$(basename $@).d_sed" "$(basename $@).d" && rm -f "$(basename $@).d_sed" 2>/dev/null; else echo 'No dependency file to process';fi
	@echo 'Finished building: $<'
	@echo ' '

Libraries/Infra/Ssw/TC39B/Tricore/Ifx_Ssw_Infra.o: ./Libraries/Infra/Ssw/TC39B/Tricore/Ifx_Ssw_Infra.src Libraries/Infra/Ssw/TC39B/Tricore/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING Assembler'
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Libraries/Infra/Ssw/TC39B/Tricore/Ifx_Ssw_Tc0.o: ./Libraries/Infra/Ssw/TC39B/Tricore/Ifx_Ssw_Tc0.src Libraries/Infra/Ssw/TC39B/Tricore/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING Assembler'
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Libraries/Infra/Ssw/TC39B/Tricore/Ifx_Ssw_Tc1.o: ./Libraries/Infra/Ssw/TC39B/Tricore/Ifx_Ssw_Tc1.src Libraries/Infra/Ssw/TC39B/Tricore/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING Assembler'
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Libraries/Infra/Ssw/TC39B/Tricore/Ifx_Ssw_Tc2.o: ./Libraries/Infra/Ssw/TC39B/Tricore/Ifx_Ssw_Tc2.src Libraries/Infra/Ssw/TC39B/Tricore/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING Assembler'
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Libraries/Infra/Ssw/TC39B/Tricore/Ifx_Ssw_Tc3.o: ./Libraries/Infra/Ssw/TC39B/Tricore/Ifx_Ssw_Tc3.src Libraries/Infra/Ssw/TC39B/Tricore/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING Assembler'
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Libraries/Infra/Ssw/TC39B/Tricore/Ifx_Ssw_Tc4.o: ./Libraries/Infra/Ssw/TC39B/Tricore/Ifx_Ssw_Tc4.src Libraries/Infra/Ssw/TC39B/Tricore/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING Assembler'
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Libraries/Infra/Ssw/TC39B/Tricore/Ifx_Ssw_Tc5.o: ./Libraries/Infra/Ssw/TC39B/Tricore/Ifx_Ssw_Tc5.src Libraries/Infra/Ssw/TC39B/Tricore/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING Assembler'
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-Libraries-2f-Infra-2f-Ssw-2f-TC39B-2f-Tricore

clean-Libraries-2f-Infra-2f-Ssw-2f-TC39B-2f-Tricore:
	-$(RM) ./Libraries/Infra/Ssw/TC39B/Tricore/Ifx_Ssw_Infra.d ./Libraries/Infra/Ssw/TC39B/Tricore/Ifx_Ssw_Infra.o ./Libraries/Infra/Ssw/TC39B/Tricore/Ifx_Ssw_Infra.src ./Libraries/Infra/Ssw/TC39B/Tricore/Ifx_Ssw_Tc0.d ./Libraries/Infra/Ssw/TC39B/Tricore/Ifx_Ssw_Tc0.o ./Libraries/Infra/Ssw/TC39B/Tricore/Ifx_Ssw_Tc0.src ./Libraries/Infra/Ssw/TC39B/Tricore/Ifx_Ssw_Tc1.d ./Libraries/Infra/Ssw/TC39B/Tricore/Ifx_Ssw_Tc1.o ./Libraries/Infra/Ssw/TC39B/Tricore/Ifx_Ssw_Tc1.src ./Libraries/Infra/Ssw/TC39B/Tricore/Ifx_Ssw_Tc2.d ./Libraries/Infra/Ssw/TC39B/Tricore/Ifx_Ssw_Tc2.o ./Libraries/Infra/Ssw/TC39B/Tricore/Ifx_Ssw_Tc2.src ./Libraries/Infra/Ssw/TC39B/Tricore/Ifx_Ssw_Tc3.d ./Libraries/Infra/Ssw/TC39B/Tricore/Ifx_Ssw_Tc3.o ./Libraries/Infra/Ssw/TC39B/Tricore/Ifx_Ssw_Tc3.src ./Libraries/Infra/Ssw/TC39B/Tricore/Ifx_Ssw_Tc4.d ./Libraries/Infra/Ssw/TC39B/Tricore/Ifx_Ssw_Tc4.o ./Libraries/Infra/Ssw/TC39B/Tricore/Ifx_Ssw_Tc4.src ./Libraries/Infra/Ssw/TC39B/Tricore/Ifx_Ssw_Tc5.d ./Libraries/Infra/Ssw/TC39B/Tricore/Ifx_Ssw_Tc5.o ./Libraries/Infra/Ssw/TC39B/Tricore/Ifx_Ssw_Tc5.src

.PHONY: clean-Libraries-2f-Infra-2f-Ssw-2f-TC39B-2f-Tricore

