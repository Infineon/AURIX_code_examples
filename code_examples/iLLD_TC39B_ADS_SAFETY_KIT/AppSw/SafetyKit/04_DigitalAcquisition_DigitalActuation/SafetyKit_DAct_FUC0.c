/**********************************************************************************************************************
 * \file SafetyKit_DAct_FUC0.c
 * \copyright Copyright (C) Infineon Technologies AG 2019
 *
 * Use of this file is subject to the terms of use agreed between (i) you or the company in which ordinary course of
 * business you are acting and (ii) Infineon Technologies AG or its licensees. If and as long as no such terms of use
 * are agreed, use of this file is subject to following:
 *
 * Boost Software License - Version 1.0 - August 17th, 2003
 *
 * Permission is hereby granted, free of charge, to any person or organization obtaining a copy of the software and
 * accompanying documentation covered by this license (the "Software") to use, reproduce, display, distribute, execute,
 * and transmit the Software, and to prepare derivative works of the Software, and to permit third-parties to whom the
 * Software is furnished to do so, all subject to the following:
 *
 * The copyright notices in the Software and this entire statement, including the above license grant, this restriction
 * and the following disclaimer, must be included in all copies of the Software, in whole or in part, and all
 * derivative works of the Software, unless such copies or derivative works are solely in the form of
 * machine-executable object code generated by a source language processor.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE
 * WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT SHALL THE
 * COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN
 * CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
 * IN THE SOFTWARE.
 *********************************************************************************************************************/

/* Digital Actuation with redundant TOM channels and IOM comparison
 * The CPU or DMA generates an output digital signal request, e.g. PWM period and duty cycle.
 * The GTM output resource (TOM or ATOM) is used to generate the PWM signal which shall be
 * fed back from the external actuator to an MCU input port.
 * Another GTM output resource (TOM or ATOM) is used to generate the internal reference
 * PWM signal to be compared by the IOM against received PWM signal from the external actuator.
 * Following SMs are required:
 * SM:IOM_ALARM_CHECK
 * SM:TIM_CLOCK_MONITORING
 *
 * SM:IOM_CONFIG_FOR_GTM
 * SM:GTM_CONFIG_FOR ATOM
 *
 * GTM TOM0 Ch4  TOUT9 on pin P00.0 (GTM_TOM_SAFE_SIGNAL) is used for the generation of the output PWM mission signal
 * which is connected as monitoring input to the IOM
 * GTM TOM0 Ch10 TOUT2 on pin P02.2 (GTM_TOM_REF_PIN) is used for the redundant output PWM signal which is connected
 * as reference input to the IOM
 * Pin P33.1 (IOM_MONITOR_INPUT) which is connected to the PWM output signal is used as the IOM monitoring input
 * GTM TOUT2 (IOM_REFERENCE_INPUT) which is connected to the PWM reference signal is used as the IOM reference input
 *
 * This example is also referred as "TOM IOM out" example
 * */

/*********************************************************************************************************************/
/*-----------------------------------------------------Includes------------------------------------------------------*/
/*********************************************************************************************************************/
#include "SafetyKit_DA_global.h"
#include "SafetyKit_GtmConfigReadback.h"
#include "SafetyKit_DAct_FUC0.h"
#include "SafetyKit_Main.h"
#include "SafetyKit_Cfg.h"
#include "IfxGtm_Tom_Pwm.h"
#include "IfxIom.h"
#include "IfxIom_Driver.h"
#include "IfxSmu.h"

/*********************************************************************************************************************/
/*------------------------------------------------------Macros-------------------------------------------------------*/
/*********************************************************************************************************************/

/*********************************************************************************************************************/
/*-------------------------------------------------Data Structures---------------------------------------------------*/
/*********************************************************************************************************************/

/*********************************************************************************************************************/
/*-------------------------------------------------Global variables--------------------------------------------------*/
/*********************************************************************************************************************/
IFX_EXTERN IfxGtm_Tom_Pwm_Driver    g_tomPwmMissionHandler;    /* Handler for TOM PWM mission signal configuration   */
IFX_EXTERN IfxGtm_Tom_Pwm_Driver    g_tomPwmReferenceHandler;  /* Handler for TOM PWM reference signal configuration */

IfxIom_Driver                       g_iomDriver;                /* IOM driver handle */
IfxIom_Driver_Lam                   g_iomLam;                   /* IOM LAM driver handle */
IfxIom_Driver_Config                g_iomConfigDriver;          /* IOM driver configuration */
IfxIom_Driver_LamConfig             g_iomConfigLam;             /* IOM LAM configuration */

/*********************************************************************************************************************/
/*------------------------------------------------Function Prototypes------------------------------------------------*/
/*********************************************************************************************************************/

/*********************************************************************************************************************/
/*---------------------------------------------Function Implementations----------------------------------------------*/
/*********************************************************************************************************************/
/*
 * Initial Digital Actuation Function use case 0
 * */
void initDActFuc0(void)
{
    resetDAconfiguration();

    /*---------------------------------------------------------------------------------------------*/
    /*                   Part 1: Initialize SM:TIM_CLOCK_MONITORING                       */
    /*---------------------------------------------------------------------------------------------*/
    initEclkMonitoring();

    /* Disable clk0 for configuration and synchronous start of the clocks afterwards */
    IfxGtm_Cmu_enableClocks(&MODULE_GTM, IFXGTM_CMU_CLKDIS_CLK0 | IFXGTM_CMU_CLKDIS_ECLK0 | IFXGTM_CMU_CLKDIS_FXCLK);

    /*---------------------------------------------------------------------------------------------*/
    /*                   Part 2: Configure GTM TOM for the output PWM mission signal               */
    /*---------------------------------------------------------------------------------------------*/
    IfxGtm_Tom_Pwm_Config pwmOutputMissionSignalConfig;
    IfxGtm_Tom_Pwm_initConfig(&pwmOutputMissionSignalConfig, &MODULE_GTM); /* Initialize default parameters */

    pwmOutputMissionSignalConfig.tom = GTM_TOM_SAFE_PIN.tom;            /* Select the TOM depending on the LED */
    pwmOutputMissionSignalConfig.tomChannel = GTM_TOM_SAFE_PIN.channel; /*Select the channel depending on the LED*/
    pwmOutputMissionSignalConfig.pin.outputPin = &GTM_TOM_SAFE_PIN;     /* Set the LED port pin as output */
    pwmOutputMissionSignalConfig.clock = DA_TOM_CLOCK_SOURCE;           /* Select the clock source*/
    pwmOutputMissionSignalConfig.synchronousUpdateEnabled = TRUE;       /* Enable synchronous update */
    pwmOutputMissionSignalConfig.period = TOM_PWM_PERIOD;               /* Set the timer period */
    pwmOutputMissionSignalConfig.dutyCycle = (uint32) (TOM_DUTY_CYCLE * 0.01 * pwmOutputMissionSignalConfig.period);
    pwmOutputMissionSignalConfig.immediateStartEnabled = FALSE;         /* Disable immediate start */

    /* Initialize the GTM TOM */
    boolean success = IfxGtm_Tom_Pwm_init(&g_tomPwmMissionHandler, &pwmOutputMissionSignalConfig);
    if(!success)
    {
        softwareCoreAlarmTriggerSMU(SOFT_SMU_ALM_GTM_TOM_TIM);
        return;
    }

    /* Validate if configuration was written successfully to the registers */
    safetyKitTomPwmConfigReadBack(&pwmOutputMissionSignalConfig, SOFT_SMU_ALM_GTM_TOM_TIM);

    /* Start the PWM, but set immediate to FALSE to wait for the reference signal to be started */
    IfxGtm_Tom_Pwm_start(&g_tomPwmMissionHandler, FALSE);

    /*---------------------------------------------------------------------------------------------*/
    /*                    Part 3: Configure GTM TOM for the output PWM reference signal            */
    /*---------------------------------------------------------------------------------------------*/
    IfxGtm_Tom_Pwm_Config pwmOutputReferenceSignalConfig;
    IfxGtm_Tom_Pwm_initConfig(&pwmOutputReferenceSignalConfig, &MODULE_GTM); /* Initialize default parameters */

    pwmOutputReferenceSignalConfig.tom = GTM_TOM_REF_PIN.tom;            /* Select the TOM depending on the LED */
    pwmOutputReferenceSignalConfig.tomChannel = GTM_TOM_REF_PIN.channel; /*Select the channel depending on the LED*/
    pwmOutputReferenceSignalConfig.pin.outputPin = &GTM_TOM_REF_PIN;     /* Set the LED port pin as output */
    pwmOutputReferenceSignalConfig.clock = DA_TOM_CLOCK_SOURCE;          /* Select the clock source*/
    pwmOutputReferenceSignalConfig.synchronousUpdateEnabled = TRUE;      /* Enable synchronous update */
    pwmOutputReferenceSignalConfig.period = TOM_PWM_PERIOD;              /* Set the timer period */
    pwmOutputReferenceSignalConfig.dutyCycle = (uint32) (TOM_DUTY_CYCLE * 0.01 * pwmOutputReferenceSignalConfig.period);
    pwmOutputReferenceSignalConfig.immediateStartEnabled = FALSE;        /* Disable immediate start */

    /* Initialize the GTM TOM */
    success = IfxGtm_Tom_Pwm_init(&g_tomPwmReferenceHandler, &pwmOutputReferenceSignalConfig);
    if(!success)
    {
        softwareCoreAlarmTriggerSMU(SOFT_SMU_ALM_GTM_TOM_TIM);
        return;
    }

    /* Validate if configuration was written successfully to the registers */
    safetyKitTomPwmConfigReadBack(&pwmOutputReferenceSignalConfig, SOFT_SMU_ALM_GTM_TOM_TIM);

    /* Start the PWM, immediate is TRUE to start both PWMs synchronously */
    IfxGtm_Tom_Pwm_start(&g_tomPwmReferenceHandler, TRUE);

    /* Enable the clocks for synchronous start of reference and monitor (A)TOM */
    IfxGtm_Cmu_enableClocks(&MODULE_GTM, IFXGTM_CMU_CLKEN_CLK0 | IFXGTM_CMU_CLKEN_ECLK0 | IFXGTM_CMU_CLKEN_FXCLK);

    /*---------------------------------------------------------------------------------------------*/
    /*                               Part 4: Configure the IOM                                     */
    /*---------------------------------------------------------------------------------------------*/
    /* Disable interrupts */
    boolean interruptState = IfxCpu_disableInterrupts();

    /* IOM monitor input */
    IfxPort_setPinMode(IOM_MONITOR_PIN.port, IOM_MONITOR_PIN.pinIndex, IfxPort_Mode_inputPullDown);

    IfxIom_enableModule(&MODULE_IOM, 1);                        /* Initialization of the IOM module */
    IfxIom_Driver_initConfig(&g_iomConfigDriver, &MODULE_IOM);  /* Creation of the IOM default configuration */
    IfxIom_Driver_init(&g_iomDriver, &g_iomConfigDriver);       /* Apply the configuration */

    IfxIom_Driver_initLamConfig(&g_iomConfigLam, &g_iomDriver); /* Creation of a default LAM configuration */

    g_iomConfigLam.channel = IfxIom_LamId_0; /* Selection of LAM ID 0 */

    /* Configuration of the Monitor signal */
    g_iomConfigLam.mon.input = IOM_MONITOR_INPUT;                       /* IOM - Monitor signal input */
    g_iomConfigLam.mon.filter.mode = IfxIom_LamFilterMode_noFilter;     /* No filter applied on the signal */
    g_iomConfigLam.mon.inverted = FALSE;                                /* Input signal NOT inverted */

    /* Configuration of the Reference signal */
    g_iomConfigLam.ref.input = IOM_GTM_REFERENCE_INPUT;                 /* IOM - Reference signal input */
    g_iomConfigLam.ref.filter.mode = IfxIom_LamFilterMode_noFilter;     /* No filter applied on the signal */
    g_iomConfigLam.ref.inverted = FALSE;                                /* Input signal NOT inverted */

    /* Configuration of the Event Window */
    /* Event window generation determined from the reference signal */
    g_iomConfigLam.eventWindow.controlSource = IfxIom_LamEventWindowControlSource_ref;
    /* Event generation window is not gated */
    g_iomConfigLam.eventWindow.run = IfxIom_LamEventWindowRunControl_freeRunning;
    /* Window clears at any edge */
    g_iomConfigLam.eventWindow.clearEvent = IfxIom_LamEventWindowClearEvent_anyEdge;
    /* Set the threshold to 1us */
    g_iomConfigLam.eventWindow.threshold = IOM_DUTY_THRESHOLD;
    /* Window: NOT INVERTED */
    g_iomConfigLam.eventWindow.inverted = FALSE;

    /* Configuration of the IOM event. IfxSmu_Alarm_IOM_Pin_MismatchIndication will be triggered if
     * event is detected. */
    /* Signal comparison: Reference XOR Monitor */
    g_iomConfigLam.event.source = IfxIom_LamEventSource_monXorRef;
    /* Falling edge is used for event generation */
    g_iomConfigLam.event.trigger = IfxIom_LamEventTrigger_fallingEdge;
    /* Alarm generated after 1 event */
    g_iomConfigLam.systemEventTriggerThreshold = NUM_OF_LAM_EVENTS;

    IfxIom_Driver_initLam(&g_iomLam, &g_iomConfigLam);                  /* Apply the custom configuration */

    /* Accumulated counter used */
    if(g_iomConfigLam.systemEventTriggerThreshold >= 2)
    {
        g_iomLam.accumulatedCounterIndex = 1;
    }

    IfxIom_Driver_enableLamEvent(&g_iomLam);                            /* Enable LAM events */

    /* Restore interrupt state */
    IfxCpu_restoreInterrupts(interruptState);

    /* Run SM:IOM_ALARM_CHECK */
    alarmCheckGTMIOM(&g_tomPwmReferenceHandler, NULL_PTR);
}
