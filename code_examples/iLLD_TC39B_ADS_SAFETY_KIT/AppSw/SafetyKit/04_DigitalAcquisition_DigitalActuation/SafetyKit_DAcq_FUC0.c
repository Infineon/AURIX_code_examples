/**********************************************************************************************************************
 * \file SafetyKit_DAcq_FUC0.c
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

/* Digital Acquisition with redundant TIM/TIM channels
 * The MCU receives redundant signals and each signal is acquired
 * by redundant GTM timer input resources (TIM).
 * The signal measurement results shall be read and compared by the CPU.
 * Following SMs are required:
 * SM:GTM_TIM_REDUNDANCY
 * SM:TIM_CLOCK_MONITORING
 *
 * GTM TOM0 Ch4 TOUT9 on pin P00.0 (GTM_TOM_SAFE_SIGNAL) is used for the generation of an dummy output PWM signal
 * GTM TIM3 Ch1 on pin P33.1 (GTM_TIM_MISSION) is used as the TIM mission channel
 * GTM TIM2 Ch0 on pin P33.12 (GTM_TIM_MONITOR) is used as the TIM monitoring channel
 * both TIMs are redundantly measuring and comparing the period and the duty cycle of the generated dummy PWM signal.
 *
 * This example is also referred as "TIMTIM in" example
 * */
/*********************************************************************************************************************/
/*-----------------------------------------------------Includes------------------------------------------------------*/
/*********************************************************************************************************************/
#include "SafetyKit_DA_global.h"
#include "SafetyKit_GtmConfigReadback.h"
#include "SafetyKit_GtmConfigReadback.h"
#include "SafetyKit_DAcq_FUC0.h"
#include "SafetyKit_Main.h"
#include "SafetyKit_Cfg.h"
#include "IfxGtm_Tom_Pwm.h"
#include "IfxGtm_Tim_In.h"

/*********************************************************************************************************************/
/*------------------------------------------------------Macros-------------------------------------------------------*/
/*********************************************************************************************************************/

/*********************************************************************************************************************/
/*-------------------------------------------------Data Structures---------------------------------------------------*/
/*********************************************************************************************************************/

/*********************************************************************************************************************/
/*-------------------------------------------------Global variables--------------------------------------------------*/
/*********************************************************************************************************************/
IFX_EXTERN IfxGtm_Tom_Pwm_Driver            g_tomPwmMissionHandler; /* Handler for TOM PWM configuration */
IFX_EXTERN IfxGtm_Tim_In                    g_timPwmMissionHandler; /* Handler for TIM PWM mission configuration*/
IFX_EXTERN IfxGtm_Tim_In                    g_timPwmMonitorHandler; /* Handler for TIM PWM monitor configuration*/
IFX_EXTERN DigitalAcqActStatusDatatype      g_digitalAcqActStatus;


/*********************************************************************************************************************/
/*------------------------------------------------Function Prototypes------------------------------------------------*/
/*********************************************************************************************************************/
void checkRedundancyGTMTIM(void);

/* Declarations of the ISR functions */
IFX_INTERRUPT(gtmTimPwmMissionIsrDAcqFuc0, ISR_PROVIDER_GTM_TIM_MISSION_DACQ_FUC0,
        ISR_PRIORITY_GTM_TIM_MISSION_DACQ_FUC0);
IFX_INTERRUPT(gtmTimPwmMonitorIsrDAcqFuc0, ISR_PROVIDER_GTM_TIM_MONITOR_DACQ_FUC0,
        ISR_PRIORITY_GTM_TIM_MONITOR_DACQ_FUC0);

/*********************************************************************************************************************/
/*---------------------------------------------Function Implementations----------------------------------------------*/
/*********************************************************************************************************************/
/* Mission TIM ISR handler */
void gtmTimPwmMissionIsrDAcqFuc0(void)
{
    IfxCpu_enableInterrupts();

    IfxGtm_Tim_In_onIsr(&g_timPwmMissionHandler);

    /* Corner case not covered by IfxGtm_Tim_In_update(driver); --> overflow without NEWVAL notification */
    if(!g_timPwmMissionHandler.newData)
    {
        g_timPwmMissionHandler.overflowCnt = IfxGtm_Tim_Ch_isCntOverflowEvent(g_timPwmMissionHandler.channel);
        if (g_timPwmMissionHandler.overflowCnt )
        {
            softwareCoreAlarmTriggerSMU(SOFT_SMU_ALM_GTM_TIM_TIM);
            g_timPwmMissionHandler.overflowCnt = FALSE;
        }
    }
    else
    {
        if(g_timPwmMissionHandler.dataCoherent == FALSE)
        {
            /* Duty and period values were not measured from the same period */
            softwareCoreAlarmTriggerSMU(SOFT_SMU_ALM_GTM_TIM_TIM);
        }

        /* Process data */
        g_digitalAcqActStatus.timMissionMeasDoneFlag        = TRUE;
        g_digitalAcqActStatus.timMissionPeriodTick          = g_timPwmMissionHandler.periodTick;
        g_digitalAcqActStatus.timMissionpulseLengthTick     = g_timPwmMissionHandler.pulseLengthTick;

        /* Execute SM:GTM_TIM_REDUNDANCY by calling checkRedundancyGTMTIM only from mission TIM channel */
        checkRedundancyGTMTIM();
    }
}

/* Monitor on TIM ISR handler */
void gtmTimPwmMonitorIsrDAcqFuc0(void)
{
    IfxCpu_enableInterrupts();

    IfxGtm_Tim_In_onIsr(&g_timPwmMonitorHandler);

    /* Corner case not covered by IfxGtm_Tim_In_update(driver); --> overflow without NEWVAL notification */
    if(!g_timPwmMonitorHandler.newData)
    {
        g_timPwmMonitorHandler.overflowCnt = IfxGtm_Tim_Ch_isCntOverflowEvent(g_timPwmMonitorHandler.channel);
        if (g_timPwmMonitorHandler.overflowCnt )
        {
            softwareCoreAlarmTriggerSMU(SOFT_SMU_ALM_GTM_TIM_TIM);
            g_timPwmMonitorHandler.overflowCnt = FALSE;
        }
    }
    else
    {
        if(g_timPwmMonitorHandler.dataCoherent == FALSE)
        {
            /* Duty and period values were not measured from the same period */
            softwareCoreAlarmTriggerSMU(SOFT_SMU_ALM_GTM_TIM_TIM);
        }

        /* Process data */
        g_digitalAcqActStatus.timMonitorMeasDoneFlag        = TRUE;
        g_digitalAcqActStatus.timMonitorPeriodTick          = g_timPwmMonitorHandler.periodTick;
        g_digitalAcqActStatus.timMonitorpulseLengthTick     = g_timPwmMonitorHandler.pulseLengthTick;
    }
}

/*
 * initial Digital Acquisition FUC0
 * */
void initDAcqFuc0(void)
{
    resetDAconfiguration();
    /*---------------------------------------------------------------------------------------------*/
    /*                  Part 1: Initialize SM:TIM_CLOCK_MONITORING                        */
    /*---------------------------------------------------------------------------------------------*/
    initEclkMonitoring();

    /*---------------------------------------------------------------------------------------------*/
    /*  Part 2: Configure GTM TOM for the dummy output PWM signal which is measured by the TOMs    */
    /*---------------------------------------------------------------------------------------------*/
    IfxGtm_Tom_Pwm_Config pwmOutputSignalConfig;
    IfxGtm_Tom_Pwm_initConfig(&pwmOutputSignalConfig, &MODULE_GTM); /* Initialize default parameters */

    pwmOutputSignalConfig.tom                      = GTM_TOM_SAFE_PIN.tom; /* Select the TOM depending on the LED */
    pwmOutputSignalConfig.tomChannel               = GTM_TOM_SAFE_PIN.channel; /* channel depending on the LED */
    pwmOutputSignalConfig.pin.outputPin            = &GTM_TOM_SAFE_PIN; /* Set the LED port pin as output */
    pwmOutputSignalConfig.clock                    = DA_TOM_CLOCK_SOURCE; /* Select the clock source*/
    pwmOutputSignalConfig.synchronousUpdateEnabled = TRUE; /* Enable synchronous update */
    pwmOutputSignalConfig.period                   = TOM_PWM_PERIOD; /* Set the timer period */
    pwmOutputSignalConfig.dutyCycle                = (uint32)(TOM_DUTY_CYCLE * 0.01 * pwmOutputSignalConfig.period);

    /* Initialize the GTM TOM */
    boolean success = IfxGtm_Tom_Pwm_init(&g_tomPwmMissionHandler, &pwmOutputSignalConfig);
    if(!success)
    {
        softwareCoreAlarmTriggerSMU(SOFT_SMU_ALM_GTM_TIM_TIM);
        return;
    }

    /* Validate if configuration was written successfully to the registers */
    safetyKitTomPwmConfigReadBack(&pwmOutputSignalConfig, SOFT_SMU_ALM_GTM_TIM_TIM);

    /* Start the PWM */
    IfxGtm_Tom_Pwm_start(&g_tomPwmMissionHandler, TRUE);

    /*---------------------------------------------------------------------------------------------*/
    /*  Part 3: Configure GTM TIM as mission channel for measuring the generated dummy PWM signal  */
    /*---------------------------------------------------------------------------------------------*/
    IfxGtm_Tim_In_Config timPwmMeasMissionConfig;
    IfxGtm_Tim_In_initConfig(&timPwmMeasMissionConfig, &MODULE_GTM); /* Initialize default parameters */

    /* Configure input pin */
    timPwmMeasMissionConfig.filter.inputPin             = &GTM_TIM_MISSION;

    /* Configure clocks */
    timPwmMeasMissionConfig.capture.clock               = DA_TIM_CLOCK_SOURCE;
    timPwmMeasMissionConfig.timeout.clock               = DA_TIM_CLOCK_SOURCE;

    /* ISR configuration */
    timPwmMeasMissionConfig.capture.irqOnNewVal         = TRUE; /* Trigger interrupt on new value */
    timPwmMeasMissionConfig.capture.irqOnCntOverflow    = TRUE; /* Trigger interrupt on counter overflow */
    timPwmMeasMissionConfig.isrProvider                 = IRQ_GET_TOS(ISR_PROVIDER_GTM_TIM_MISSION_DACQ_FUC0);
    timPwmMeasMissionConfig.isrPriority                 = ISR_PRIORITY_GTM_TIM_MISSION_DACQ_FUC0;

    /* Initialize the TIM */
    success = IfxGtm_Tim_In_init(&g_timPwmMissionHandler, &timPwmMeasMissionConfig);
    if(!success)
    {
        softwareCoreAlarmTriggerSMU(SOFT_SMU_ALM_GTM_TIM_TIM);
        return;
    }

    /* Validate if configuration was written successfully to the registers */
    safetyKitTimInConfigReadback(&timPwmMeasMissionConfig, SOFT_SMU_ALM_GTM_TIM_TIM);

    /*---------------------------------------------------------------------------------------------*/
    /*  Part 4: Configure GTM TIM as monitor channel for measuring the generated dummy PWM signal  */
    /*---------------------------------------------------------------------------------------------*/
    IfxGtm_Tim_In_Config timPwmMeasMonitorConfig;
    IfxGtm_Tim_In_initConfig(&timPwmMeasMonitorConfig, &MODULE_GTM); /* Initialize default parameters */

    /* Configure input pin */
    timPwmMeasMonitorConfig.filter.inputPin             = &GTM_TIM_MONITOR;

    /* Configure clocks */
    timPwmMeasMonitorConfig.capture.clock               = DA_TIM_CLOCK_SOURCE;
    timPwmMeasMonitorConfig.timeout.clock               = DA_TIM_CLOCK_SOURCE;

    /* ISR configuration */
    timPwmMeasMonitorConfig.capture.irqOnNewVal         = TRUE; /* Trigger interrupt on new value */
    timPwmMeasMonitorConfig.capture.irqOnCntOverflow    = TRUE; /* Trigger interrupt on counter overflow */
    timPwmMeasMonitorConfig.isrProvider                 = IRQ_GET_TOS(ISR_PROVIDER_GTM_TIM_MISSION_DACQ_FUC0);
    timPwmMeasMonitorConfig.isrPriority                 = ISR_PRIORITY_GTM_TIM_MONITOR_DACQ_FUC0;

    /* Initialize the TIM */
    success = IfxGtm_Tim_In_init(&g_timPwmMonitorHandler, &timPwmMeasMonitorConfig);
    if(!success)
    {
        softwareCoreAlarmTriggerSMU(SOFT_SMU_ALM_GTM_TIM_TIM);
        return;
    }

    /* Validate if configuration was written successfully to the registers */
    safetyKitTimInConfigReadback(&timPwmMeasMonitorConfig, SOFT_SMU_ALM_GTM_TIM_TIM);
}


/*
 * Check redundancy of TIM TIM
 * SM:GTM_TIM_REDUNDANCY
 * */
void checkRedundancyGTMTIM(void)
{
    /* Continue only if both measurements are done */
    static uint8 notDoneCnt;
    if(!g_digitalAcqActStatus.timMissionMeasDoneFlag && !g_digitalAcqActStatus.timMonitorMeasDoneFlag)
    {
        /* Increase static not done counter */
        notDoneCnt++;
        /* If notDoneCnt is not reset frequently it means that any TIM is not successfully measured anymore */
        if(notDoneCnt > 100)
        {
            /* Trigger SMU software alarm */
            softwareCoreAlarmTriggerSMU(SOFT_SMU_ALM_GTM_TIM_TIM);

            /* Reset static notDoneCnt counter */
            notDoneCnt = 0;
        }
        return;
    }
    /* Reset static notDoneCnt counter */
    notDoneCnt = 0;

    /* Difference validation */
    uint32 periodTickDifference =
            (g_digitalAcqActStatus.timMissionPeriodTick < g_digitalAcqActStatus.timMonitorPeriodTick) ?
                    (g_digitalAcqActStatus.timMonitorPeriodTick - g_digitalAcqActStatus.timMissionPeriodTick) :
                    (g_digitalAcqActStatus.timMissionPeriodTick - g_digitalAcqActStatus.timMonitorPeriodTick);
    uint32 pulseLengthTickDifference =
            (g_digitalAcqActStatus.timMissionpulseLengthTick < g_digitalAcqActStatus.timMonitorpulseLengthTick) ?
                    (g_digitalAcqActStatus.timMonitorpulseLengthTick - g_digitalAcqActStatus.timMissionpulseLengthTick) :
                    (g_digitalAcqActStatus.timMissionpulseLengthTick - g_digitalAcqActStatus.timMonitorpulseLengthTick);

    /* Appropriate reaction if difference is higher than the limit */
    if((periodTickDifference > TIM_REDUNDANCY_MAX_DIFF) || (pulseLengthTickDifference > TIM_REDUNDANCY_MAX_DIFF))
    {
        /* Trigger SMU software alarm */
        softwareCoreAlarmTriggerSMU(SOFT_SMU_ALM_GTM_TIM_TIM);
    }

    /* Reset measurement done flags */
    g_digitalAcqActStatus.timMissionMeasDoneFlag = FALSE;
    g_digitalAcqActStatus.timMonitorMeasDoneFlag = FALSE;
}
