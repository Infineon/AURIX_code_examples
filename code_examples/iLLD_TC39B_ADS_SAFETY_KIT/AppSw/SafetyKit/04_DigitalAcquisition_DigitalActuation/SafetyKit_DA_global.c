/**********************************************************************************************************************
 * \file SafetyKit_DA_global.c
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

/*********************************************************************************************************************/
/*-----------------------------------------------------Includes------------------------------------------------------*/
/*********************************************************************************************************************/
#include "SafetyKit_DA_global.h"
#include "SafetyKit_GtmConfigReadback.h"
#include "SafetyKit_Main.h"
#include "SafetyKit_Cfg.h"

#include "IfxPort.h"
#include "IfxGtm_Cmu.h"
#include "IfxGtm_PinMap.h"
#include "IfxGtm.h"

#include "IfxGtm_Tim.h"
#include "IfxGtm_Tim_In.h"

#include "IfxGtm_Tom.h"
#include "IfxGtm_Tom_Pwm.h"

#include "IfxGtm_Atom_Pwm.h"
#include "IfxCcu6_TPwm.h"

#include "IfxIom.h"

#include "IfxCpu_Irq.h"
#include "conio_tft.h"

/*********************************************************************************************************************/
/*------------------------------------------------------Macros-------------------------------------------------------*/
/*********************************************************************************************************************/
#define REF_MODIFY_VALUE   100
/*********************************************************************************************************************/
/*-------------------------------------------------Data Structures---------------------------------------------------*/
/*********************************************************************************************************************/

/*********************************************************************************************************************/
/*-------------------------------------------------Global variables--------------------------------------------------*/
/*********************************************************************************************************************/
IfxGtm_Tim_In                   g_eclkTimHandler;              /* Handler for TIM ECLK configuration                 */
IfxGtm_Tom_Pwm_Driver           g_tomPwmMissionHandler;        /* Handler for TOM PWM mission signal configuration   */
IfxGtm_Tom_Pwm_Driver           g_tomPwmReferenceHandler;      /* Handler for TOM PWM reference signal configuration */
IfxGtm_Tim_In                   g_timPwmMissionHandler;         /* Handler for TIM PWM mission configuration         */
IfxGtm_Tim_In                   g_timPwmMonitorHandler;         /* Handler for TIM PWM monitor configuration         */

IfxGtm_Atom_Pwm_Driver          g_atomPwmMissionHandler;        /* Handler for ATOM PWM mission signal configuration */
IfxCcu6_TPwm                    g_ccu61PwmReferenceHandler;     /* Handler for CCU6 PWM reference signal config      */

DigitalAcqActStatusDatatype     g_digitalAcqActStatus;

/*********************************************************************************************************************/
/*------------------------------------------------Function Prototypes------------------------------------------------*/
/*********************************************************************************************************************/
/* Declarations of the ISR functions */
IFX_INTERRUPT(gtmTimEclkMonitoringISR, ISR_PROVIDER_GTM_TIM_ECLK_MON, ISR_PRIORITY_GTM_TIM_ECLK_MON_DA);

/*********************************************************************************************************************/
/*---------------------------------------------Function Implementations----------------------------------------------*/
/*********************************************************************************************************************/
/* ECLK monitor ISR */
void gtmTimEclkMonitoringISR(void)
{
    IfxCpu_enableInterrupts();
    IfxGtm_Tim_In_onIsr(&g_eclkTimHandler);

    /* Corner case not covered by IfxGtm_Tim_In_update(driver); --> overflow without NEWVAL notification */
    if(!g_eclkTimHandler.newData)
    {
        g_eclkTimHandler.overflowCnt = IfxGtm_Tim_Ch_isCntOverflowEvent(g_eclkTimHandler.channel);
        if (g_eclkTimHandler.overflowCnt )
        {
            softwareCoreAlarmTriggerSMU(SOFT_SMU_ALM_GTM_ECKL);
            g_eclkTimHandler.overflowCnt = FALSE;
        }
    }
    else
    {
        if(g_eclkTimHandler.dataCoherent == FALSE)
        {
            /* Duty and period values were not measured from the same period */
            softwareCoreAlarmTriggerSMU(SOFT_SMU_ALM_GTM_ECKL);
        }

        /* Process data */
        uint32 expectedPeriodTick = (uint32) g_eclkTimHandler.captureClockFrequency / EXT_CLK0_FREQ;
        uint32 periodTickDifference =
                g_eclkTimHandler.periodTick > expectedPeriodTick ?
                        g_eclkTimHandler.periodTick - expectedPeriodTick :
                        expectedPeriodTick - g_eclkTimHandler.periodTick;

        /* Trigger an SMU alarm if the tick difference is higher than the allowed tolerance */
        if(periodTickDifference > TICK_TOLERANCE)
        {
            softwareCoreAlarmTriggerSMU(SOFT_SMU_ALM_GTM_ECKL);
        }
    }
}

/*
 * SM:TIM_CLOCK_MONITORING
 * */
void initEclkMonitoring(void)
{
    /*---------------------------------------------------------------------------------------------*/
    /*                Part 1: Configure ECLK and its output on an external pin                     */
    /*---------------------------------------------------------------------------------------------*/
    /* Disable ECLK for configuration */
    IfxGtm_Cmu_enableClocks(&MODULE_GTM, IFXGTM_CMU_CLKDIS_ECLK0);

    /* Setup ECLK0 external pin, configure as alternative output pin 4, GTM_CLK0 or cmu_eclk0,
     * refer to the table "GTM External Clock to Port Mapping" in the User Manual */
    IfxPort_setPinPadDriver(GTM_ECLK_OUTPUT_PIN.port, GTM_ECLK_OUTPUT_PIN.pinIndex,
            IfxPort_PadDriver_cmosAutomotiveSpeed1);
    IfxPort_setPinModeOutput(GTM_ECLK_OUTPUT_PIN.port, GTM_ECLK_OUTPUT_PIN.pinIndex, IfxPort_OutputMode_pushPull,
            IfxPort_OutputIdx_alt4);

    /* Setup frequency */
    /* Following code is copied from the function IfxGtm_Cmu_setEclkFrequency()
     * As IfxGtm_Cmu_setEclkFrequency() takes very long to acquire the Numerator and Denominator it is hard coded */
    uint16 psw = IfxScuWdt_getCpuWatchdogPassword();
    IfxScuWdt_clearCpuEndinit(psw);

    /* write ECLK_NUM twice to be sure i.e. recommended by user manual */
    MODULE_GTM.CMU.ECLK[IfxGtm_Cmu_Eclk_0].NUM.B.ECLK_NUM = (uint32) (IfxGtm_Cmu_getGclkFrequency(&MODULE_GTM)
            / EXT_CLK0_FREQ);
    MODULE_GTM.CMU.ECLK[IfxGtm_Cmu_Eclk_0].NUM.B.ECLK_NUM = (uint32) (IfxGtm_Cmu_getGclkFrequency(&MODULE_GTM)
            / EXT_CLK0_FREQ);
    MODULE_GTM.CMU.ECLK[IfxGtm_Cmu_Eclk_0].DEN.B.ECLK_DEN = 0x1;
    IfxScuWdt_setCpuEndinit(psw);

    /* Enable ECLK again */
    IfxGtm_Cmu_enableClocks(&MODULE_GTM, IFXGTM_CMU_CLKEN_ECLK0);

    /* Verify ECLK configuration by reading it back */
    float32 configuredFreq = EXT_CLK_MULTIPLIER * IfxGtm_Cmu_getEclkFrequency(&MODULE_GTM, IfxGtm_Cmu_Eclk_0, FALSE);
    if(configuredFreq != EXT_CLK0_FREQ)
    {
        softwareCoreAlarmTriggerSMU(SOFT_SMU_ALM_GTM_ECKL);
    }
    /*---------------------------------------------------------------------------------------------*/
    /*    Part 2: Configure a TIM channel for monitoring the externally looped back ECKL signal    */
    /*---------------------------------------------------------------------------------------------*/
    IfxGtm_Tim_In_Config timEclkConfig;
    IfxGtm_Tim_In_initConfig(&timEclkConfig, &MODULE_GTM); /* Initialize default parameters */

    /* Configure input pin */
    timEclkConfig.filter.inputPin               = &GTM_TIM_ECKL_INPUT;

    /* Configure clocks */
    timEclkConfig.capture.clock                 = DA_TIM_CLOCK_SOURCE;
    timEclkConfig.timeout.clock                 = DA_TIM_CLOCK_SOURCE;

    /* ISR configuration */
    timEclkConfig.capture.irqOnNewVal           = TRUE; /* Trigger interrupt on new value */
    timEclkConfig.capture.irqOnCntOverflow      = TRUE; /* Trigger interrupt on counter overflow */
    timEclkConfig.isrProvider                   = IRQ_GET_TOS(ISR_PROVIDER_GTM_TIM_ECLK_MON);
    timEclkConfig.isrPriority                   = ISR_PRIORITY_GTM_TIM_ECLK_MON_DA;

    /* Initialize the TIM */
    boolean success = IfxGtm_Tim_In_init(&g_eclkTimHandler, &timEclkConfig);
    if(!success)
    {
        softwareCoreAlarmTriggerSMU(SOFT_SMU_ALM_GTM_ECKL);
    }

    safetyKitTimInConfigReadback(&timEclkConfig, SOFT_SMU_ALM_GTM_ECKL);
}

/* SM:GTM:IOM_ALARM_CHECK
 * This function can be used to either modify the duty cycle of the reference tom or of the reference CCU6 channel.
 * After modification an SMU alarm should get triggered, if so, error injection will be stopped and the duty cycle
 * will be set to its initial value. */
void alarmCheckGTMIOM (IfxGtm_Tom_Pwm_Driver *tomReference, Ifx_CCU6 *ccu61Reference)
{
    /* Verify that only one pointer is passed and that the other one is NULL_PTR otherwise raise alarm */
    if( (tomReference == NULL_PTR && ccu61Reference == NULL_PTR) ||
        (tomReference != NULL_PTR && ccu61Reference != NULL_PTR) )
    {
        softwareCoreAlarmTriggerSMU(SOFT_SMU_ALM_GTM_TOM_TIM);
        softwareCoreAlarmTriggerSMU(SOFT_SMU_ALM_GTM_TIM_CCU6);
    }

    /* Start error injection by modifying the duty cycle of the reference pwm signal */
    uint32 tomPwmRefPulseLengthTicks = 0;
    uint32 updatedPwmRefPulseLengthTicks = 0;
    if(tomReference != NULL_PTR)
    {
        tomPwmRefPulseLengthTicks = IfxGtm_Tom_Ch_getCompareOne(tomReference->tom, tomReference->tomChannel);
    }
    else if(ccu61Reference != NULL_PTR)
    {
        tomPwmRefPulseLengthTicks = IfxCcu6_getCaptureShadowRegisterValue(ccu61Reference, IfxCcu6_T12Channel_1);
    }

    if(tomPwmRefPulseLengthTicks > REF_MODIFY_VALUE)
    {
        if(tomReference != NULL_PTR)
        {
            updatedPwmRefPulseLengthTicks = tomPwmRefPulseLengthTicks - REF_MODIFY_VALUE;
            IfxGtm_Tom_Ch_setCompareOneShadow(tomReference->tom, tomReference->tomChannel, updatedPwmRefPulseLengthTicks);
        }
        else if(ccu61Reference != NULL_PTR)
        {
            updatedPwmRefPulseLengthTicks = tomPwmRefPulseLengthTicks - REF_MODIFY_VALUE;
            IfxCcu6_setT12CompareValue(ccu61Reference, IfxCcu6_T12Channel_1, (uint16)updatedPwmRefPulseLengthTicks);
            IfxCcu6_enableShadowTransfer(ccu61Reference, TRUE, FALSE);

        }
    }
    else
    {
        if(tomReference != NULL_PTR)
        {
            updatedPwmRefPulseLengthTicks = tomPwmRefPulseLengthTicks + REF_MODIFY_VALUE;
            IfxGtm_Tom_Ch_setCompareOneShadow(tomReference->tom, tomReference->tomChannel, updatedPwmRefPulseLengthTicks);
        }
        else if(ccu61Reference != NULL_PTR)
        {
            updatedPwmRefPulseLengthTicks = tomPwmRefPulseLengthTicks + REF_MODIFY_VALUE;
            IfxCcu6_setT12CompareValue(ccu61Reference, IfxCcu6_T12Channel_1, (uint16)updatedPwmRefPulseLengthTicks);
            IfxCcu6_enableShadowTransfer(ccu61Reference, TRUE, FALSE);
        }
    }

    /* Wait for the SMU alarm */
    uint32 timeout = 0xFFFF;
    boolean alarmIsRaised = FALSE;
    do
    {
        /* Wait for IfxSmu_Alarm_IOM_Pin_MismatchIndication alarm (ALM8[25]) */
        alarmIsRaised = IfxSmu_getAlarmStatus(IfxSmu_Alarm_IOM_Pin_MismatchIndication);
    } while(!alarmIsRaised && timeout--);

    if(alarmIsRaised)
    {
        /* Stop error injection */
        if(tomReference != NULL_PTR)
        {
            IfxGtm_Tom_Ch_setCompareOneShadow(tomReference->tom, tomReference->tomChannel, tomPwmRefPulseLengthTicks);
        }
        else if(ccu61Reference != NULL_PTR)
        {
            IfxCcu6_setT12CompareValue(ccu61Reference, IfxCcu6_T12Channel_1, (uint16)tomPwmRefPulseLengthTicks);
            IfxCcu6_enableShadowTransfer(ccu61Reference, TRUE, FALSE);
        }

        /* Clear IfxSmu_Alarm_IOM_Pin_MismatchIndication alarm (ALM8[25]) */
        IfxSmu_clearAlarmStatus(IfxSmu_Alarm_IOM_Pin_MismatchIndication);

        /* Wait for alarmCounter to be incremented in ISR afterwards it will get decremented and
         * the alarm informations are cleared */
        {
            volatile uint16 timeout = 0xFFFF;/* Note STHE: added "volatile" as it didn't work always without */
            do
            {
                __nop();
            } while(timeout-- && !g_SafetyKitStatus.smuAlarmPending.alarmCounter);

            if(g_SafetyKitStatus.smuAlarmPending.alarmCounter > 0)
            {
                /* Set alarmState to "notPending", decrement alarmCounter and close TFT POP UP window */
                g_SafetyKitStatus.smuAlarmPending.lastAlarmRaised[g_SafetyKitStatus.smuAlarmPending.alarmCounter - 1]->alarmState =
                        notPending;
                g_SafetyKitStatus.smuAlarmPending.alarmCounter--;
                conio_driver.dialogmode = DIALOGOFF;
            }
        }
    }
    else
    {
        while(1)
        {
            __debug();
            __nop();
        }
    }
}

/*
 * Reset every module and channel used for Digital Actuation and Digital Acquisition
 * */
void resetDAconfiguration(void)
{
    /* Reset IOM module */
    if(MODULE_IOM.CLC.B.DISS == 0)
    {
        IfxIom_resetModule(&MODULE_IOM);
    }

    /* Reset all TIM channels which are used for digital acquisition and digital actuation */
    IfxGtm_Tim_Ch_resetChannel(&MODULE_GTM.TIM[GTM_TIM_MISSION.tim], GTM_TIM_MISSION.channel);
    IfxGtm_Tim_Ch_resetChannel(&MODULE_GTM.TIM[GTM_TIM_MONITOR.tim], GTM_TIM_MONITOR.channel);
    IfxGtm_Tim_Ch_resetChannel(&MODULE_GTM.TIM[GTM_TIM_ECKL_INPUT.tim], GTM_TIM_ECKL_INPUT.channel);

    /* Reset all TOM channels which are used for digital acquisition and digital actuation */
    if(g_tomPwmMissionHandler.tgc[0] != NULL)
    {
        if(g_tomPwmMissionHandler.tomChannel < IfxGtm_Tom_Ch_8)
        {
            IfxGtm_Tom_Tgc_resetChannels(g_tomPwmMissionHandler.tgc[0], (1 << g_tomPwmMissionHandler.tomChannel));
        }
        else
        {
            IfxGtm_Tom_Tgc_resetChannels(g_tomPwmMissionHandler.tgc[0],
                    (1 << g_tomPwmMissionHandler.tomChannel - IfxGtm_Tom_Ch_8));
        }
    }

    if(g_tomPwmReferenceHandler.tgc[0] != NULL)
    {
        if(g_tomPwmReferenceHandler.tomChannel < IfxGtm_Tom_Ch_8)
        {
            IfxGtm_Tom_Tgc_resetChannels(g_tomPwmReferenceHandler.tgc[0], (1 << g_tomPwmReferenceHandler.tomChannel));
        }
        else
        {
            IfxGtm_Tom_Tgc_resetChannels(g_tomPwmReferenceHandler.tgc[0],
                    (1 << (g_tomPwmReferenceHandler.tomChannel - IfxGtm_Tom_Ch_8)));
        }
    }

    /* Reset all ATOM channels which are used for digital acquisition and digital actuation */
    if(g_atomPwmMissionHandler.agc != NULL)
    {
        IfxGtm_Atom_Agc_resetChannels(g_atomPwmMissionHandler.agc, (1 << g_atomPwmMissionHandler.atomChannel));
    }

    /* Reset CCU6 module */
    if(CCU6_REF_PIN.module->CLC.B.DISS == 0)
    {
        IfxCcu6_resetModule(CCU6_REF_PIN.module);
    }
    if(CCU6_OUTPUT_MISSION_PIN.module->CLC.B.DISS == 0)
    {
        IfxCcu6_resetModule(CCU6_OUTPUT_MISSION_PIN.module);
    }
    if(CCU6_INPUT_MISSION_PIN.module->CLC.B.DISS == 0)
    {
        IfxCcu6_resetModule(CCU6_INPUT_MISSION_PIN.module);
    }
}
