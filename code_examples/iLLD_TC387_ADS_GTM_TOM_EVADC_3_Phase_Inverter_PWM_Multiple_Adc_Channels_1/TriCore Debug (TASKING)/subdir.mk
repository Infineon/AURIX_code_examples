################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
"../Cpu0_Main.c" \
"../Cpu1_Main.c" \
"../Cpu2_Main.c" \
"../Cpu3_Main.c" \
"../Evadc_Multiple_Channels.c" \
"../GTM_TOM_3_Phase_Inverter_PWM.c" \
"../Interrupts.c" 

COMPILED_SRCS += \
"Cpu0_Main.src" \
"Cpu1_Main.src" \
"Cpu2_Main.src" \
"Cpu3_Main.src" \
"Evadc_Multiple_Channels.src" \
"GTM_TOM_3_Phase_Inverter_PWM.src" \
"Interrupts.src" 

C_DEPS += \
"./Cpu0_Main.d" \
"./Cpu1_Main.d" \
"./Cpu2_Main.d" \
"./Cpu3_Main.d" \
"./Evadc_Multiple_Channels.d" \
"./GTM_TOM_3_Phase_Inverter_PWM.d" \
"./Interrupts.d" 

OBJS += \
"Cpu0_Main.o" \
"Cpu1_Main.o" \
"Cpu2_Main.o" \
"Cpu3_Main.o" \
"Evadc_Multiple_Channels.o" \
"GTM_TOM_3_Phase_Inverter_PWM.o" \
"Interrupts.o" 


# Each subdirectory must supply rules for building sources it contributes
"Cpu0_Main.src":"../Cpu0_Main.c" "subdir.mk"
	cctc -cs --dep-file="$*.d" --misrac-version=2004 -D__CPU__=tc38x "-fC:/Workspaces/AURIX_TC3x_Motor_Control_SDK_Workspace/iLLD_TC387_ADS_GTM_TOM_EVADC_3_Phase_Inverter_PWM_Multiple_Adc_Channels_1/TriCore Debug (TASKING)/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O3 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc38x -Y0 -N0 -Z0 -o "$@" "$<"
"Cpu0_Main.o":"Cpu0_Main.src" "subdir.mk"
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
"Cpu1_Main.src":"../Cpu1_Main.c" "subdir.mk"
	cctc -cs --dep-file="$*.d" --misrac-version=2004 -D__CPU__=tc38x "-fC:/Workspaces/AURIX_TC3x_Motor_Control_SDK_Workspace/iLLD_TC387_ADS_GTM_TOM_EVADC_3_Phase_Inverter_PWM_Multiple_Adc_Channels_1/TriCore Debug (TASKING)/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O3 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc38x -Y0 -N0 -Z0 -o "$@" "$<"
"Cpu1_Main.o":"Cpu1_Main.src" "subdir.mk"
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
"Cpu2_Main.src":"../Cpu2_Main.c" "subdir.mk"
	cctc -cs --dep-file="$*.d" --misrac-version=2004 -D__CPU__=tc38x "-fC:/Workspaces/AURIX_TC3x_Motor_Control_SDK_Workspace/iLLD_TC387_ADS_GTM_TOM_EVADC_3_Phase_Inverter_PWM_Multiple_Adc_Channels_1/TriCore Debug (TASKING)/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O3 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc38x -Y0 -N0 -Z0 -o "$@" "$<"
"Cpu2_Main.o":"Cpu2_Main.src" "subdir.mk"
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
"Cpu3_Main.src":"../Cpu3_Main.c" "subdir.mk"
	cctc -cs --dep-file="$*.d" --misrac-version=2004 -D__CPU__=tc38x "-fC:/Workspaces/AURIX_TC3x_Motor_Control_SDK_Workspace/iLLD_TC387_ADS_GTM_TOM_EVADC_3_Phase_Inverter_PWM_Multiple_Adc_Channels_1/TriCore Debug (TASKING)/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O3 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc38x -Y0 -N0 -Z0 -o "$@" "$<"
"Cpu3_Main.o":"Cpu3_Main.src" "subdir.mk"
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
"Evadc_Multiple_Channels.src":"../Evadc_Multiple_Channels.c" "subdir.mk"
	cctc -cs --dep-file="$*.d" --misrac-version=2004 -D__CPU__=tc38x "-fC:/Workspaces/AURIX_TC3x_Motor_Control_SDK_Workspace/iLLD_TC387_ADS_GTM_TOM_EVADC_3_Phase_Inverter_PWM_Multiple_Adc_Channels_1/TriCore Debug (TASKING)/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O3 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc38x -Y0 -N0 -Z0 -o "$@" "$<"
"Evadc_Multiple_Channels.o":"Evadc_Multiple_Channels.src" "subdir.mk"
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
"GTM_TOM_3_Phase_Inverter_PWM.src":"../GTM_TOM_3_Phase_Inverter_PWM.c" "subdir.mk"
	cctc -cs --dep-file="$*.d" --misrac-version=2004 -D__CPU__=tc38x "-fC:/Workspaces/AURIX_TC3x_Motor_Control_SDK_Workspace/iLLD_TC387_ADS_GTM_TOM_EVADC_3_Phase_Inverter_PWM_Multiple_Adc_Channels_1/TriCore Debug (TASKING)/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O3 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc38x -Y0 -N0 -Z0 -o "$@" "$<"
"GTM_TOM_3_Phase_Inverter_PWM.o":"GTM_TOM_3_Phase_Inverter_PWM.src" "subdir.mk"
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
"Interrupts.src":"../Interrupts.c" "subdir.mk"
	cctc -cs --dep-file="$*.d" --misrac-version=2004 -D__CPU__=tc38x "-fC:/Workspaces/AURIX_TC3x_Motor_Control_SDK_Workspace/iLLD_TC387_ADS_GTM_TOM_EVADC_3_Phase_Inverter_PWM_Multiple_Adc_Channels_1/TriCore Debug (TASKING)/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O3 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc38x -Y0 -N0 -Z0 -o "$@" "$<"
"Interrupts.o":"Interrupts.src" "subdir.mk"
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"

clean: clean--2e-

clean--2e-:
	-$(RM) ./Cpu0_Main.d ./Cpu0_Main.o ./Cpu0_Main.src ./Cpu1_Main.d ./Cpu1_Main.o ./Cpu1_Main.src ./Cpu2_Main.d ./Cpu2_Main.o ./Cpu2_Main.src ./Cpu3_Main.d ./Cpu3_Main.o ./Cpu3_Main.src ./Evadc_Multiple_Channels.d ./Evadc_Multiple_Channels.o ./Evadc_Multiple_Channels.src ./GTM_TOM_3_Phase_Inverter_PWM.d ./GTM_TOM_3_Phase_Inverter_PWM.o ./GTM_TOM_3_Phase_Inverter_PWM.src ./Interrupts.d ./Interrupts.o ./Interrupts.src

.PHONY: clean--2e-

