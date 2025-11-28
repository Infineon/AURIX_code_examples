################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
"../Libraries/Infra/Platform/Tricore/Compilers/CompilerDcc.c" \
"../Libraries/Infra/Platform/Tricore/Compilers/CompilerGcc.c" \
"../Libraries/Infra/Platform/Tricore/Compilers/CompilerGhs.c" \
"../Libraries/Infra/Platform/Tricore/Compilers/CompilerGnuc.c" \
"../Libraries/Infra/Platform/Tricore/Compilers/CompilerTasking.c" 

COMPILED_SRCS += \
"Libraries/Infra/Platform/Tricore/Compilers/CompilerDcc.src" \
"Libraries/Infra/Platform/Tricore/Compilers/CompilerGcc.src" \
"Libraries/Infra/Platform/Tricore/Compilers/CompilerGhs.src" \
"Libraries/Infra/Platform/Tricore/Compilers/CompilerGnuc.src" \
"Libraries/Infra/Platform/Tricore/Compilers/CompilerTasking.src" 

C_DEPS += \
"./Libraries/Infra/Platform/Tricore/Compilers/CompilerDcc.d" \
"./Libraries/Infra/Platform/Tricore/Compilers/CompilerGcc.d" \
"./Libraries/Infra/Platform/Tricore/Compilers/CompilerGhs.d" \
"./Libraries/Infra/Platform/Tricore/Compilers/CompilerGnuc.d" \
"./Libraries/Infra/Platform/Tricore/Compilers/CompilerTasking.d" 

OBJS += \
"Libraries/Infra/Platform/Tricore/Compilers/CompilerDcc.o" \
"Libraries/Infra/Platform/Tricore/Compilers/CompilerGcc.o" \
"Libraries/Infra/Platform/Tricore/Compilers/CompilerGhs.o" \
"Libraries/Infra/Platform/Tricore/Compilers/CompilerGnuc.o" \
"Libraries/Infra/Platform/Tricore/Compilers/CompilerTasking.o" 


# Each subdirectory must supply rules for building sources it contributes
"Libraries/Infra/Platform/Tricore/Compilers/CompilerDcc.src":"../Libraries/Infra/Platform/Tricore/Compilers/CompilerDcc.c" "Libraries/Infra/Platform/Tricore/Compilers/subdir.mk"
	cctc -cs --dep-file="$*.d" --misrac-version=2004 -D__CPU__=tc38x "-fC:/Workspaces/AURIX_TC3x_Motor_Control_SDK_Workspace/iLLD_TC387_ADS_GTM_TOM_EVADC_3_Phase_Inverter_PWM_Multiple_Adc_Channels_1/TriCore Debug (TASKING)/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O3 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc38x -Y0 -N0 -Z0 -o "$@" "$<"
"Libraries/Infra/Platform/Tricore/Compilers/CompilerDcc.o":"Libraries/Infra/Platform/Tricore/Compilers/CompilerDcc.src" "Libraries/Infra/Platform/Tricore/Compilers/subdir.mk"
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
"Libraries/Infra/Platform/Tricore/Compilers/CompilerGcc.src":"../Libraries/Infra/Platform/Tricore/Compilers/CompilerGcc.c" "Libraries/Infra/Platform/Tricore/Compilers/subdir.mk"
	cctc -cs --dep-file="$*.d" --misrac-version=2004 -D__CPU__=tc38x "-fC:/Workspaces/AURIX_TC3x_Motor_Control_SDK_Workspace/iLLD_TC387_ADS_GTM_TOM_EVADC_3_Phase_Inverter_PWM_Multiple_Adc_Channels_1/TriCore Debug (TASKING)/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O3 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc38x -Y0 -N0 -Z0 -o "$@" "$<"
"Libraries/Infra/Platform/Tricore/Compilers/CompilerGcc.o":"Libraries/Infra/Platform/Tricore/Compilers/CompilerGcc.src" "Libraries/Infra/Platform/Tricore/Compilers/subdir.mk"
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
"Libraries/Infra/Platform/Tricore/Compilers/CompilerGhs.src":"../Libraries/Infra/Platform/Tricore/Compilers/CompilerGhs.c" "Libraries/Infra/Platform/Tricore/Compilers/subdir.mk"
	cctc -cs --dep-file="$*.d" --misrac-version=2004 -D__CPU__=tc38x "-fC:/Workspaces/AURIX_TC3x_Motor_Control_SDK_Workspace/iLLD_TC387_ADS_GTM_TOM_EVADC_3_Phase_Inverter_PWM_Multiple_Adc_Channels_1/TriCore Debug (TASKING)/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O3 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc38x -Y0 -N0 -Z0 -o "$@" "$<"
"Libraries/Infra/Platform/Tricore/Compilers/CompilerGhs.o":"Libraries/Infra/Platform/Tricore/Compilers/CompilerGhs.src" "Libraries/Infra/Platform/Tricore/Compilers/subdir.mk"
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
"Libraries/Infra/Platform/Tricore/Compilers/CompilerGnuc.src":"../Libraries/Infra/Platform/Tricore/Compilers/CompilerGnuc.c" "Libraries/Infra/Platform/Tricore/Compilers/subdir.mk"
	cctc -cs --dep-file="$*.d" --misrac-version=2004 -D__CPU__=tc38x "-fC:/Workspaces/AURIX_TC3x_Motor_Control_SDK_Workspace/iLLD_TC387_ADS_GTM_TOM_EVADC_3_Phase_Inverter_PWM_Multiple_Adc_Channels_1/TriCore Debug (TASKING)/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O3 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc38x -Y0 -N0 -Z0 -o "$@" "$<"
"Libraries/Infra/Platform/Tricore/Compilers/CompilerGnuc.o":"Libraries/Infra/Platform/Tricore/Compilers/CompilerGnuc.src" "Libraries/Infra/Platform/Tricore/Compilers/subdir.mk"
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
"Libraries/Infra/Platform/Tricore/Compilers/CompilerTasking.src":"../Libraries/Infra/Platform/Tricore/Compilers/CompilerTasking.c" "Libraries/Infra/Platform/Tricore/Compilers/subdir.mk"
	cctc -cs --dep-file="$*.d" --misrac-version=2004 -D__CPU__=tc38x "-fC:/Workspaces/AURIX_TC3x_Motor_Control_SDK_Workspace/iLLD_TC387_ADS_GTM_TOM_EVADC_3_Phase_Inverter_PWM_Multiple_Adc_Channels_1/TriCore Debug (TASKING)/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O3 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc38x -Y0 -N0 -Z0 -o "$@" "$<"
"Libraries/Infra/Platform/Tricore/Compilers/CompilerTasking.o":"Libraries/Infra/Platform/Tricore/Compilers/CompilerTasking.src" "Libraries/Infra/Platform/Tricore/Compilers/subdir.mk"
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"

clean: clean-Libraries-2f-Infra-2f-Platform-2f-Tricore-2f-Compilers

clean-Libraries-2f-Infra-2f-Platform-2f-Tricore-2f-Compilers:
	-$(RM) ./Libraries/Infra/Platform/Tricore/Compilers/CompilerDcc.d ./Libraries/Infra/Platform/Tricore/Compilers/CompilerDcc.o ./Libraries/Infra/Platform/Tricore/Compilers/CompilerDcc.src ./Libraries/Infra/Platform/Tricore/Compilers/CompilerGcc.d ./Libraries/Infra/Platform/Tricore/Compilers/CompilerGcc.o ./Libraries/Infra/Platform/Tricore/Compilers/CompilerGcc.src ./Libraries/Infra/Platform/Tricore/Compilers/CompilerGhs.d ./Libraries/Infra/Platform/Tricore/Compilers/CompilerGhs.o ./Libraries/Infra/Platform/Tricore/Compilers/CompilerGhs.src ./Libraries/Infra/Platform/Tricore/Compilers/CompilerGnuc.d ./Libraries/Infra/Platform/Tricore/Compilers/CompilerGnuc.o ./Libraries/Infra/Platform/Tricore/Compilers/CompilerGnuc.src ./Libraries/Infra/Platform/Tricore/Compilers/CompilerTasking.d ./Libraries/Infra/Platform/Tricore/Compilers/CompilerTasking.o ./Libraries/Infra/Platform/Tricore/Compilers/CompilerTasking.src

.PHONY: clean-Libraries-2f-Infra-2f-Platform-2f-Tricore-2f-Compilers

