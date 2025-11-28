################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
"../Libraries/iLLD/TC38A/Tricore/Gtm/Std/IfxGtm.c" \
"../Libraries/iLLD/TC38A/Tricore/Gtm/Std/IfxGtm_Atom.c" \
"../Libraries/iLLD/TC38A/Tricore/Gtm/Std/IfxGtm_Cmu.c" \
"../Libraries/iLLD/TC38A/Tricore/Gtm/Std/IfxGtm_Dpll.c" \
"../Libraries/iLLD/TC38A/Tricore/Gtm/Std/IfxGtm_Dtm.c" \
"../Libraries/iLLD/TC38A/Tricore/Gtm/Std/IfxGtm_Psm.c" \
"../Libraries/iLLD/TC38A/Tricore/Gtm/Std/IfxGtm_Spe.c" \
"../Libraries/iLLD/TC38A/Tricore/Gtm/Std/IfxGtm_Tbu.c" \
"../Libraries/iLLD/TC38A/Tricore/Gtm/Std/IfxGtm_Tim.c" \
"../Libraries/iLLD/TC38A/Tricore/Gtm/Std/IfxGtm_Tom.c" 

COMPILED_SRCS += \
"Libraries/iLLD/TC38A/Tricore/Gtm/Std/IfxGtm.src" \
"Libraries/iLLD/TC38A/Tricore/Gtm/Std/IfxGtm_Atom.src" \
"Libraries/iLLD/TC38A/Tricore/Gtm/Std/IfxGtm_Cmu.src" \
"Libraries/iLLD/TC38A/Tricore/Gtm/Std/IfxGtm_Dpll.src" \
"Libraries/iLLD/TC38A/Tricore/Gtm/Std/IfxGtm_Dtm.src" \
"Libraries/iLLD/TC38A/Tricore/Gtm/Std/IfxGtm_Psm.src" \
"Libraries/iLLD/TC38A/Tricore/Gtm/Std/IfxGtm_Spe.src" \
"Libraries/iLLD/TC38A/Tricore/Gtm/Std/IfxGtm_Tbu.src" \
"Libraries/iLLD/TC38A/Tricore/Gtm/Std/IfxGtm_Tim.src" \
"Libraries/iLLD/TC38A/Tricore/Gtm/Std/IfxGtm_Tom.src" 

C_DEPS += \
"./Libraries/iLLD/TC38A/Tricore/Gtm/Std/IfxGtm.d" \
"./Libraries/iLLD/TC38A/Tricore/Gtm/Std/IfxGtm_Atom.d" \
"./Libraries/iLLD/TC38A/Tricore/Gtm/Std/IfxGtm_Cmu.d" \
"./Libraries/iLLD/TC38A/Tricore/Gtm/Std/IfxGtm_Dpll.d" \
"./Libraries/iLLD/TC38A/Tricore/Gtm/Std/IfxGtm_Dtm.d" \
"./Libraries/iLLD/TC38A/Tricore/Gtm/Std/IfxGtm_Psm.d" \
"./Libraries/iLLD/TC38A/Tricore/Gtm/Std/IfxGtm_Spe.d" \
"./Libraries/iLLD/TC38A/Tricore/Gtm/Std/IfxGtm_Tbu.d" \
"./Libraries/iLLD/TC38A/Tricore/Gtm/Std/IfxGtm_Tim.d" \
"./Libraries/iLLD/TC38A/Tricore/Gtm/Std/IfxGtm_Tom.d" 

OBJS += \
"Libraries/iLLD/TC38A/Tricore/Gtm/Std/IfxGtm.o" \
"Libraries/iLLD/TC38A/Tricore/Gtm/Std/IfxGtm_Atom.o" \
"Libraries/iLLD/TC38A/Tricore/Gtm/Std/IfxGtm_Cmu.o" \
"Libraries/iLLD/TC38A/Tricore/Gtm/Std/IfxGtm_Dpll.o" \
"Libraries/iLLD/TC38A/Tricore/Gtm/Std/IfxGtm_Dtm.o" \
"Libraries/iLLD/TC38A/Tricore/Gtm/Std/IfxGtm_Psm.o" \
"Libraries/iLLD/TC38A/Tricore/Gtm/Std/IfxGtm_Spe.o" \
"Libraries/iLLD/TC38A/Tricore/Gtm/Std/IfxGtm_Tbu.o" \
"Libraries/iLLD/TC38A/Tricore/Gtm/Std/IfxGtm_Tim.o" \
"Libraries/iLLD/TC38A/Tricore/Gtm/Std/IfxGtm_Tom.o" 


# Each subdirectory must supply rules for building sources it contributes
"Libraries/iLLD/TC38A/Tricore/Gtm/Std/IfxGtm.src":"../Libraries/iLLD/TC38A/Tricore/Gtm/Std/IfxGtm.c" "Libraries/iLLD/TC38A/Tricore/Gtm/Std/subdir.mk"
	cctc -cs --dep-file="$*.d" --misrac-version=2004 -D__CPU__=tc38x "-fC:/Workspaces/AURIX_TC3x_Motor_Control_SDK_Workspace/iLLD_TC387_ADS_GTM_TOM_EVADC_3_Phase_Inverter_PWM_Multiple_Adc_Channels_1/TriCore Debug (TASKING)/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O3 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc38x -Y0 -N0 -Z0 -o "$@" "$<"
"Libraries/iLLD/TC38A/Tricore/Gtm/Std/IfxGtm.o":"Libraries/iLLD/TC38A/Tricore/Gtm/Std/IfxGtm.src" "Libraries/iLLD/TC38A/Tricore/Gtm/Std/subdir.mk"
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
"Libraries/iLLD/TC38A/Tricore/Gtm/Std/IfxGtm_Atom.src":"../Libraries/iLLD/TC38A/Tricore/Gtm/Std/IfxGtm_Atom.c" "Libraries/iLLD/TC38A/Tricore/Gtm/Std/subdir.mk"
	cctc -cs --dep-file="$*.d" --misrac-version=2004 -D__CPU__=tc38x "-fC:/Workspaces/AURIX_TC3x_Motor_Control_SDK_Workspace/iLLD_TC387_ADS_GTM_TOM_EVADC_3_Phase_Inverter_PWM_Multiple_Adc_Channels_1/TriCore Debug (TASKING)/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O3 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc38x -Y0 -N0 -Z0 -o "$@" "$<"
"Libraries/iLLD/TC38A/Tricore/Gtm/Std/IfxGtm_Atom.o":"Libraries/iLLD/TC38A/Tricore/Gtm/Std/IfxGtm_Atom.src" "Libraries/iLLD/TC38A/Tricore/Gtm/Std/subdir.mk"
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
"Libraries/iLLD/TC38A/Tricore/Gtm/Std/IfxGtm_Cmu.src":"../Libraries/iLLD/TC38A/Tricore/Gtm/Std/IfxGtm_Cmu.c" "Libraries/iLLD/TC38A/Tricore/Gtm/Std/subdir.mk"
	cctc -cs --dep-file="$*.d" --misrac-version=2004 -D__CPU__=tc38x "-fC:/Workspaces/AURIX_TC3x_Motor_Control_SDK_Workspace/iLLD_TC387_ADS_GTM_TOM_EVADC_3_Phase_Inverter_PWM_Multiple_Adc_Channels_1/TriCore Debug (TASKING)/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O3 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc38x -Y0 -N0 -Z0 -o "$@" "$<"
"Libraries/iLLD/TC38A/Tricore/Gtm/Std/IfxGtm_Cmu.o":"Libraries/iLLD/TC38A/Tricore/Gtm/Std/IfxGtm_Cmu.src" "Libraries/iLLD/TC38A/Tricore/Gtm/Std/subdir.mk"
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
"Libraries/iLLD/TC38A/Tricore/Gtm/Std/IfxGtm_Dpll.src":"../Libraries/iLLD/TC38A/Tricore/Gtm/Std/IfxGtm_Dpll.c" "Libraries/iLLD/TC38A/Tricore/Gtm/Std/subdir.mk"
	cctc -cs --dep-file="$*.d" --misrac-version=2004 -D__CPU__=tc38x "-fC:/Workspaces/AURIX_TC3x_Motor_Control_SDK_Workspace/iLLD_TC387_ADS_GTM_TOM_EVADC_3_Phase_Inverter_PWM_Multiple_Adc_Channels_1/TriCore Debug (TASKING)/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O3 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc38x -Y0 -N0 -Z0 -o "$@" "$<"
"Libraries/iLLD/TC38A/Tricore/Gtm/Std/IfxGtm_Dpll.o":"Libraries/iLLD/TC38A/Tricore/Gtm/Std/IfxGtm_Dpll.src" "Libraries/iLLD/TC38A/Tricore/Gtm/Std/subdir.mk"
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
"Libraries/iLLD/TC38A/Tricore/Gtm/Std/IfxGtm_Dtm.src":"../Libraries/iLLD/TC38A/Tricore/Gtm/Std/IfxGtm_Dtm.c" "Libraries/iLLD/TC38A/Tricore/Gtm/Std/subdir.mk"
	cctc -cs --dep-file="$*.d" --misrac-version=2004 -D__CPU__=tc38x "-fC:/Workspaces/AURIX_TC3x_Motor_Control_SDK_Workspace/iLLD_TC387_ADS_GTM_TOM_EVADC_3_Phase_Inverter_PWM_Multiple_Adc_Channels_1/TriCore Debug (TASKING)/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O3 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc38x -Y0 -N0 -Z0 -o "$@" "$<"
"Libraries/iLLD/TC38A/Tricore/Gtm/Std/IfxGtm_Dtm.o":"Libraries/iLLD/TC38A/Tricore/Gtm/Std/IfxGtm_Dtm.src" "Libraries/iLLD/TC38A/Tricore/Gtm/Std/subdir.mk"
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
"Libraries/iLLD/TC38A/Tricore/Gtm/Std/IfxGtm_Psm.src":"../Libraries/iLLD/TC38A/Tricore/Gtm/Std/IfxGtm_Psm.c" "Libraries/iLLD/TC38A/Tricore/Gtm/Std/subdir.mk"
	cctc -cs --dep-file="$*.d" --misrac-version=2004 -D__CPU__=tc38x "-fC:/Workspaces/AURIX_TC3x_Motor_Control_SDK_Workspace/iLLD_TC387_ADS_GTM_TOM_EVADC_3_Phase_Inverter_PWM_Multiple_Adc_Channels_1/TriCore Debug (TASKING)/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O3 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc38x -Y0 -N0 -Z0 -o "$@" "$<"
"Libraries/iLLD/TC38A/Tricore/Gtm/Std/IfxGtm_Psm.o":"Libraries/iLLD/TC38A/Tricore/Gtm/Std/IfxGtm_Psm.src" "Libraries/iLLD/TC38A/Tricore/Gtm/Std/subdir.mk"
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
"Libraries/iLLD/TC38A/Tricore/Gtm/Std/IfxGtm_Spe.src":"../Libraries/iLLD/TC38A/Tricore/Gtm/Std/IfxGtm_Spe.c" "Libraries/iLLD/TC38A/Tricore/Gtm/Std/subdir.mk"
	cctc -cs --dep-file="$*.d" --misrac-version=2004 -D__CPU__=tc38x "-fC:/Workspaces/AURIX_TC3x_Motor_Control_SDK_Workspace/iLLD_TC387_ADS_GTM_TOM_EVADC_3_Phase_Inverter_PWM_Multiple_Adc_Channels_1/TriCore Debug (TASKING)/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O3 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc38x -Y0 -N0 -Z0 -o "$@" "$<"
"Libraries/iLLD/TC38A/Tricore/Gtm/Std/IfxGtm_Spe.o":"Libraries/iLLD/TC38A/Tricore/Gtm/Std/IfxGtm_Spe.src" "Libraries/iLLD/TC38A/Tricore/Gtm/Std/subdir.mk"
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
"Libraries/iLLD/TC38A/Tricore/Gtm/Std/IfxGtm_Tbu.src":"../Libraries/iLLD/TC38A/Tricore/Gtm/Std/IfxGtm_Tbu.c" "Libraries/iLLD/TC38A/Tricore/Gtm/Std/subdir.mk"
	cctc -cs --dep-file="$*.d" --misrac-version=2004 -D__CPU__=tc38x "-fC:/Workspaces/AURIX_TC3x_Motor_Control_SDK_Workspace/iLLD_TC387_ADS_GTM_TOM_EVADC_3_Phase_Inverter_PWM_Multiple_Adc_Channels_1/TriCore Debug (TASKING)/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O3 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc38x -Y0 -N0 -Z0 -o "$@" "$<"
"Libraries/iLLD/TC38A/Tricore/Gtm/Std/IfxGtm_Tbu.o":"Libraries/iLLD/TC38A/Tricore/Gtm/Std/IfxGtm_Tbu.src" "Libraries/iLLD/TC38A/Tricore/Gtm/Std/subdir.mk"
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
"Libraries/iLLD/TC38A/Tricore/Gtm/Std/IfxGtm_Tim.src":"../Libraries/iLLD/TC38A/Tricore/Gtm/Std/IfxGtm_Tim.c" "Libraries/iLLD/TC38A/Tricore/Gtm/Std/subdir.mk"
	cctc -cs --dep-file="$*.d" --misrac-version=2004 -D__CPU__=tc38x "-fC:/Workspaces/AURIX_TC3x_Motor_Control_SDK_Workspace/iLLD_TC387_ADS_GTM_TOM_EVADC_3_Phase_Inverter_PWM_Multiple_Adc_Channels_1/TriCore Debug (TASKING)/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O3 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc38x -Y0 -N0 -Z0 -o "$@" "$<"
"Libraries/iLLD/TC38A/Tricore/Gtm/Std/IfxGtm_Tim.o":"Libraries/iLLD/TC38A/Tricore/Gtm/Std/IfxGtm_Tim.src" "Libraries/iLLD/TC38A/Tricore/Gtm/Std/subdir.mk"
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
"Libraries/iLLD/TC38A/Tricore/Gtm/Std/IfxGtm_Tom.src":"../Libraries/iLLD/TC38A/Tricore/Gtm/Std/IfxGtm_Tom.c" "Libraries/iLLD/TC38A/Tricore/Gtm/Std/subdir.mk"
	cctc -cs --dep-file="$*.d" --misrac-version=2004 -D__CPU__=tc38x "-fC:/Workspaces/AURIX_TC3x_Motor_Control_SDK_Workspace/iLLD_TC387_ADS_GTM_TOM_EVADC_3_Phase_Inverter_PWM_Multiple_Adc_Channels_1/TriCore Debug (TASKING)/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O3 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc38x -Y0 -N0 -Z0 -o "$@" "$<"
"Libraries/iLLD/TC38A/Tricore/Gtm/Std/IfxGtm_Tom.o":"Libraries/iLLD/TC38A/Tricore/Gtm/Std/IfxGtm_Tom.src" "Libraries/iLLD/TC38A/Tricore/Gtm/Std/subdir.mk"
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"

clean: clean-Libraries-2f-iLLD-2f-TC38A-2f-Tricore-2f-Gtm-2f-Std

clean-Libraries-2f-iLLD-2f-TC38A-2f-Tricore-2f-Gtm-2f-Std:
	-$(RM) ./Libraries/iLLD/TC38A/Tricore/Gtm/Std/IfxGtm.d ./Libraries/iLLD/TC38A/Tricore/Gtm/Std/IfxGtm.o ./Libraries/iLLD/TC38A/Tricore/Gtm/Std/IfxGtm.src ./Libraries/iLLD/TC38A/Tricore/Gtm/Std/IfxGtm_Atom.d ./Libraries/iLLD/TC38A/Tricore/Gtm/Std/IfxGtm_Atom.o ./Libraries/iLLD/TC38A/Tricore/Gtm/Std/IfxGtm_Atom.src ./Libraries/iLLD/TC38A/Tricore/Gtm/Std/IfxGtm_Cmu.d ./Libraries/iLLD/TC38A/Tricore/Gtm/Std/IfxGtm_Cmu.o ./Libraries/iLLD/TC38A/Tricore/Gtm/Std/IfxGtm_Cmu.src ./Libraries/iLLD/TC38A/Tricore/Gtm/Std/IfxGtm_Dpll.d ./Libraries/iLLD/TC38A/Tricore/Gtm/Std/IfxGtm_Dpll.o ./Libraries/iLLD/TC38A/Tricore/Gtm/Std/IfxGtm_Dpll.src ./Libraries/iLLD/TC38A/Tricore/Gtm/Std/IfxGtm_Dtm.d ./Libraries/iLLD/TC38A/Tricore/Gtm/Std/IfxGtm_Dtm.o ./Libraries/iLLD/TC38A/Tricore/Gtm/Std/IfxGtm_Dtm.src ./Libraries/iLLD/TC38A/Tricore/Gtm/Std/IfxGtm_Psm.d ./Libraries/iLLD/TC38A/Tricore/Gtm/Std/IfxGtm_Psm.o ./Libraries/iLLD/TC38A/Tricore/Gtm/Std/IfxGtm_Psm.src ./Libraries/iLLD/TC38A/Tricore/Gtm/Std/IfxGtm_Spe.d ./Libraries/iLLD/TC38A/Tricore/Gtm/Std/IfxGtm_Spe.o ./Libraries/iLLD/TC38A/Tricore/Gtm/Std/IfxGtm_Spe.src ./Libraries/iLLD/TC38A/Tricore/Gtm/Std/IfxGtm_Tbu.d ./Libraries/iLLD/TC38A/Tricore/Gtm/Std/IfxGtm_Tbu.o ./Libraries/iLLD/TC38A/Tricore/Gtm/Std/IfxGtm_Tbu.src ./Libraries/iLLD/TC38A/Tricore/Gtm/Std/IfxGtm_Tim.d ./Libraries/iLLD/TC38A/Tricore/Gtm/Std/IfxGtm_Tim.o ./Libraries/iLLD/TC38A/Tricore/Gtm/Std/IfxGtm_Tim.src ./Libraries/iLLD/TC38A/Tricore/Gtm/Std/IfxGtm_Tom.d ./Libraries/iLLD/TC38A/Tricore/Gtm/Std/IfxGtm_Tom.o ./Libraries/iLLD/TC38A/Tricore/Gtm/Std/IfxGtm_Tom.src

.PHONY: clean-Libraries-2f-iLLD-2f-TC38A-2f-Tricore-2f-Gtm-2f-Std

