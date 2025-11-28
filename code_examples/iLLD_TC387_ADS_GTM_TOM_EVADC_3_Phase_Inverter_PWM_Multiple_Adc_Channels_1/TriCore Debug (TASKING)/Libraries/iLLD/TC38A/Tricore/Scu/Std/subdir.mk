################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
"../Libraries/iLLD/TC38A/Tricore/Scu/Std/IfxScuCcu.c" \
"../Libraries/iLLD/TC38A/Tricore/Scu/Std/IfxScuEru.c" \
"../Libraries/iLLD/TC38A/Tricore/Scu/Std/IfxScuLbist.c" \
"../Libraries/iLLD/TC38A/Tricore/Scu/Std/IfxScuRcu.c" \
"../Libraries/iLLD/TC38A/Tricore/Scu/Std/IfxScuWdt.c" 

COMPILED_SRCS += \
"Libraries/iLLD/TC38A/Tricore/Scu/Std/IfxScuCcu.src" \
"Libraries/iLLD/TC38A/Tricore/Scu/Std/IfxScuEru.src" \
"Libraries/iLLD/TC38A/Tricore/Scu/Std/IfxScuLbist.src" \
"Libraries/iLLD/TC38A/Tricore/Scu/Std/IfxScuRcu.src" \
"Libraries/iLLD/TC38A/Tricore/Scu/Std/IfxScuWdt.src" 

C_DEPS += \
"./Libraries/iLLD/TC38A/Tricore/Scu/Std/IfxScuCcu.d" \
"./Libraries/iLLD/TC38A/Tricore/Scu/Std/IfxScuEru.d" \
"./Libraries/iLLD/TC38A/Tricore/Scu/Std/IfxScuLbist.d" \
"./Libraries/iLLD/TC38A/Tricore/Scu/Std/IfxScuRcu.d" \
"./Libraries/iLLD/TC38A/Tricore/Scu/Std/IfxScuWdt.d" 

OBJS += \
"Libraries/iLLD/TC38A/Tricore/Scu/Std/IfxScuCcu.o" \
"Libraries/iLLD/TC38A/Tricore/Scu/Std/IfxScuEru.o" \
"Libraries/iLLD/TC38A/Tricore/Scu/Std/IfxScuLbist.o" \
"Libraries/iLLD/TC38A/Tricore/Scu/Std/IfxScuRcu.o" \
"Libraries/iLLD/TC38A/Tricore/Scu/Std/IfxScuWdt.o" 


# Each subdirectory must supply rules for building sources it contributes
"Libraries/iLLD/TC38A/Tricore/Scu/Std/IfxScuCcu.src":"../Libraries/iLLD/TC38A/Tricore/Scu/Std/IfxScuCcu.c" "Libraries/iLLD/TC38A/Tricore/Scu/Std/subdir.mk"
	cctc -cs --dep-file="$*.d" --misrac-version=2004 -D__CPU__=tc38x "-fC:/Workspaces/AURIX_TC3x_Motor_Control_SDK_Workspace/iLLD_TC387_ADS_GTM_TOM_EVADC_3_Phase_Inverter_PWM_Multiple_Adc_Channels_1/TriCore Debug (TASKING)/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O3 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc38x -Y0 -N0 -Z0 -o "$@" "$<"
"Libraries/iLLD/TC38A/Tricore/Scu/Std/IfxScuCcu.o":"Libraries/iLLD/TC38A/Tricore/Scu/Std/IfxScuCcu.src" "Libraries/iLLD/TC38A/Tricore/Scu/Std/subdir.mk"
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
"Libraries/iLLD/TC38A/Tricore/Scu/Std/IfxScuEru.src":"../Libraries/iLLD/TC38A/Tricore/Scu/Std/IfxScuEru.c" "Libraries/iLLD/TC38A/Tricore/Scu/Std/subdir.mk"
	cctc -cs --dep-file="$*.d" --misrac-version=2004 -D__CPU__=tc38x "-fC:/Workspaces/AURIX_TC3x_Motor_Control_SDK_Workspace/iLLD_TC387_ADS_GTM_TOM_EVADC_3_Phase_Inverter_PWM_Multiple_Adc_Channels_1/TriCore Debug (TASKING)/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O3 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc38x -Y0 -N0 -Z0 -o "$@" "$<"
"Libraries/iLLD/TC38A/Tricore/Scu/Std/IfxScuEru.o":"Libraries/iLLD/TC38A/Tricore/Scu/Std/IfxScuEru.src" "Libraries/iLLD/TC38A/Tricore/Scu/Std/subdir.mk"
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
"Libraries/iLLD/TC38A/Tricore/Scu/Std/IfxScuLbist.src":"../Libraries/iLLD/TC38A/Tricore/Scu/Std/IfxScuLbist.c" "Libraries/iLLD/TC38A/Tricore/Scu/Std/subdir.mk"
	cctc -cs --dep-file="$*.d" --misrac-version=2004 -D__CPU__=tc38x "-fC:/Workspaces/AURIX_TC3x_Motor_Control_SDK_Workspace/iLLD_TC387_ADS_GTM_TOM_EVADC_3_Phase_Inverter_PWM_Multiple_Adc_Channels_1/TriCore Debug (TASKING)/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O3 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc38x -Y0 -N0 -Z0 -o "$@" "$<"
"Libraries/iLLD/TC38A/Tricore/Scu/Std/IfxScuLbist.o":"Libraries/iLLD/TC38A/Tricore/Scu/Std/IfxScuLbist.src" "Libraries/iLLD/TC38A/Tricore/Scu/Std/subdir.mk"
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
"Libraries/iLLD/TC38A/Tricore/Scu/Std/IfxScuRcu.src":"../Libraries/iLLD/TC38A/Tricore/Scu/Std/IfxScuRcu.c" "Libraries/iLLD/TC38A/Tricore/Scu/Std/subdir.mk"
	cctc -cs --dep-file="$*.d" --misrac-version=2004 -D__CPU__=tc38x "-fC:/Workspaces/AURIX_TC3x_Motor_Control_SDK_Workspace/iLLD_TC387_ADS_GTM_TOM_EVADC_3_Phase_Inverter_PWM_Multiple_Adc_Channels_1/TriCore Debug (TASKING)/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O3 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc38x -Y0 -N0 -Z0 -o "$@" "$<"
"Libraries/iLLD/TC38A/Tricore/Scu/Std/IfxScuRcu.o":"Libraries/iLLD/TC38A/Tricore/Scu/Std/IfxScuRcu.src" "Libraries/iLLD/TC38A/Tricore/Scu/Std/subdir.mk"
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
"Libraries/iLLD/TC38A/Tricore/Scu/Std/IfxScuWdt.src":"../Libraries/iLLD/TC38A/Tricore/Scu/Std/IfxScuWdt.c" "Libraries/iLLD/TC38A/Tricore/Scu/Std/subdir.mk"
	cctc -cs --dep-file="$*.d" --misrac-version=2004 -D__CPU__=tc38x "-fC:/Workspaces/AURIX_TC3x_Motor_Control_SDK_Workspace/iLLD_TC387_ADS_GTM_TOM_EVADC_3_Phase_Inverter_PWM_Multiple_Adc_Channels_1/TriCore Debug (TASKING)/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O3 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc38x -Y0 -N0 -Z0 -o "$@" "$<"
"Libraries/iLLD/TC38A/Tricore/Scu/Std/IfxScuWdt.o":"Libraries/iLLD/TC38A/Tricore/Scu/Std/IfxScuWdt.src" "Libraries/iLLD/TC38A/Tricore/Scu/Std/subdir.mk"
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"

clean: clean-Libraries-2f-iLLD-2f-TC38A-2f-Tricore-2f-Scu-2f-Std

clean-Libraries-2f-iLLD-2f-TC38A-2f-Tricore-2f-Scu-2f-Std:
	-$(RM) ./Libraries/iLLD/TC38A/Tricore/Scu/Std/IfxScuCcu.d ./Libraries/iLLD/TC38A/Tricore/Scu/Std/IfxScuCcu.o ./Libraries/iLLD/TC38A/Tricore/Scu/Std/IfxScuCcu.src ./Libraries/iLLD/TC38A/Tricore/Scu/Std/IfxScuEru.d ./Libraries/iLLD/TC38A/Tricore/Scu/Std/IfxScuEru.o ./Libraries/iLLD/TC38A/Tricore/Scu/Std/IfxScuEru.src ./Libraries/iLLD/TC38A/Tricore/Scu/Std/IfxScuLbist.d ./Libraries/iLLD/TC38A/Tricore/Scu/Std/IfxScuLbist.o ./Libraries/iLLD/TC38A/Tricore/Scu/Std/IfxScuLbist.src ./Libraries/iLLD/TC38A/Tricore/Scu/Std/IfxScuRcu.d ./Libraries/iLLD/TC38A/Tricore/Scu/Std/IfxScuRcu.o ./Libraries/iLLD/TC38A/Tricore/Scu/Std/IfxScuRcu.src ./Libraries/iLLD/TC38A/Tricore/Scu/Std/IfxScuWdt.d ./Libraries/iLLD/TC38A/Tricore/Scu/Std/IfxScuWdt.o ./Libraries/iLLD/TC38A/Tricore/Scu/Std/IfxScuWdt.src

.PHONY: clean-Libraries-2f-iLLD-2f-TC38A-2f-Tricore-2f-Scu-2f-Std

