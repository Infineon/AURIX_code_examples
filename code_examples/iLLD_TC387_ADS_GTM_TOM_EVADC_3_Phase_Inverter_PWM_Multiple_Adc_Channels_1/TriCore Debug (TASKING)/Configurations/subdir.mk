################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
"../Configurations/Ifx_Cfg_Ssw.c" \
"../Configurations/Ifx_Cfg_SswBmhd.c" 

COMPILED_SRCS += \
"Configurations/Ifx_Cfg_Ssw.src" \
"Configurations/Ifx_Cfg_SswBmhd.src" 

C_DEPS += \
"./Configurations/Ifx_Cfg_Ssw.d" \
"./Configurations/Ifx_Cfg_SswBmhd.d" 

OBJS += \
"Configurations/Ifx_Cfg_Ssw.o" \
"Configurations/Ifx_Cfg_SswBmhd.o" 


# Each subdirectory must supply rules for building sources it contributes
"Configurations/Ifx_Cfg_Ssw.src":"../Configurations/Ifx_Cfg_Ssw.c" "Configurations/subdir.mk"
	cctc -cs --dep-file="$*.d" --misrac-version=2004 -D__CPU__=tc38x "-fC:/Workspaces/AURIX_TC3x_Motor_Control_SDK_Workspace/iLLD_TC387_ADS_GTM_TOM_EVADC_3_Phase_Inverter_PWM_Multiple_Adc_Channels_1/TriCore Debug (TASKING)/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O3 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc38x -Y0 -N0 -Z0 -o "$@" "$<"
"Configurations/Ifx_Cfg_Ssw.o":"Configurations/Ifx_Cfg_Ssw.src" "Configurations/subdir.mk"
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
"Configurations/Ifx_Cfg_SswBmhd.src":"../Configurations/Ifx_Cfg_SswBmhd.c" "Configurations/subdir.mk"
	cctc -cs --dep-file="$*.d" --misrac-version=2004 -D__CPU__=tc38x "-fC:/Workspaces/AURIX_TC3x_Motor_Control_SDK_Workspace/iLLD_TC387_ADS_GTM_TOM_EVADC_3_Phase_Inverter_PWM_Multiple_Adc_Channels_1/TriCore Debug (TASKING)/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O3 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc38x -Y0 -N0 -Z0 -o "$@" "$<"
"Configurations/Ifx_Cfg_SswBmhd.o":"Configurations/Ifx_Cfg_SswBmhd.src" "Configurations/subdir.mk"
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"

clean: clean-Configurations

clean-Configurations:
	-$(RM) ./Configurations/Ifx_Cfg_Ssw.d ./Configurations/Ifx_Cfg_Ssw.o ./Configurations/Ifx_Cfg_Ssw.src ./Configurations/Ifx_Cfg_SswBmhd.d ./Configurations/Ifx_Cfg_SswBmhd.o ./Configurations/Ifx_Cfg_SswBmhd.src

.PHONY: clean-Configurations

