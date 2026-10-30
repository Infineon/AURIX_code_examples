/**
 * \file IfxGtm_Atom_Pwm.c
 * \brief GTM PWM details
 *
 * \version iLLD_1_22_0
 * \copyright Copyright (c) 2026 Infineon Technologies AG. All rights reserved.
 *
 *
 *
 *                                 IMPORTANT NOTICE
 *
 * Infineon Technologies AG (Infineon) licenses this file to you under the
 * Infineon Automotive SW Lab License v2025-01 (IFASLL). You may not use
 * this file except in compliance with IFASLL.
 *
 * The full license text is contained in IFASLL202501.pdf delivered with this SW.
 * Unless required by applicable law or agreed to in writing, software distributed
 * under this license is distributed "AS IS" without any warranty or liability of any
 * kind and Infineon hereby expressly disclaims any warranties or representations,
 * whether express, implied, statutory or otherwise, including but not limited to
 * warranties of workmanship, merchantability, fitness for a particular purpose,
 * defects in the licensed items, or non-infringement of third parties'
 * intellectual property rights. See the full license text for the specific
 * language governing permissions and limitations under IFASLL.
 *
 *
 */

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include "Ifx_Cfg.h"
#if defined (__TASKING__)
#pragma warning 508		/* To suppress empty file warning */
#endif
#if defined (__ghs__)
#pragma diag_suppress 96		/* To suppress empty file warning */
#endif
#if !defined(DEVICE_TC33XED) && !defined (DEVICE_TC35X)
#include "IfxGtm_Atom_Pwm.h"

/******************************************************************************/
/*-------------------------Function Implementations---------------------------*/
/******************************************************************************/

boolean IfxGtm_Atom_Pwm_init(IfxGtm_Atom_Pwm_Driver *driver, const IfxGtm_Atom_Pwm_Config *config)
{
    boolean result = TRUE;

    driver->gtm       = config->gtm;
    driver->atomIndex = config->atom;
    driver->synchronousUpdateEnabled = config->synchronousUpdateEnabled;

    Ifx_GTM_ATOM     *atomSFR = &config->gtm->ATOM[config->atom];
    driver->atom        = atomSFR;
    driver->atomChannel = config->atomChannel;

    Ifx_GTM_ATOM_AGC *agc = &atomSFR->AGC;
    driver->agc = agc;


    /* Set ATOM channel clock source */
    IfxGtm_Atom_Ch_setClockSource(atomSFR, config->atomChannel, config->clock);

    /* Set Signal Polarity value here */
    IfxGtm_Atom_Ch_setSignalLevel(atomSFR, config->atomChannel, config->signalLevel);

    IfxGtm_Atom_Agc_setChannelForceUpdate(agc, config->atomChannel, TRUE, TRUE);


    /* Set ATOM signal output mode as PWM */
    IfxGtm_Atom_Ch_setMode(atomSFR, config->atomChannel, config->mode);

    /* Set channel to start counter when trigger is received */
    IfxGtm_Atom_Agc_enableChannel(agc, config->atomChannel, TRUE, FALSE);

    /* Set channel to start PWM output when trigger is received */
    IfxGtm_Atom_Agc_enableChannelOutput(agc, config->atomChannel, TRUE, FALSE);

    /* Enable and initialize interrupts if chosen */
    if ((config->interrupt.ccu0Enabled == TRUE) || (config->interrupt.ccu1Enabled == TRUE))
    {
        volatile Ifx_SRC_SRCR *src;
        IfxGtm_Atom_Ch_setNotification(atomSFR, config->atomChannel, config->interrupt.mode, config->interrupt.ccu0Enabled, config->interrupt.ccu1Enabled);

        src = IfxGtm_Atom_Ch_getSrcPointer(config->gtm, config->atom, config->atomChannel);
        IfxSrc_init(src, config->interrupt.isrProvider, config->interrupt.isrPriority);
        IfxSrc_enable(src);
    }

    if (config->synchronousUpdateEnabled == 1)
    {
    	IfxGtm_Atom_Agc_enableChannelUpdate(agc, config->atomChannel, FALSE);
        IfxGtm_Atom_Ch_setCompareZeroShadow(atomSFR, config->atomChannel, config->period);
        IfxGtm_Atom_Ch_setCompareOneShadow(atomSFR, config->atomChannel, config->dutyCycle);
        IfxGtm_Atom_Agc_enableChannelUpdate(agc, config->atomChannel, TRUE);
    }
    else
    {
    	IfxGtm_Atom_Agc_setChannelForceUpdate(agc, config->atomChannel, TRUE, FALSE);
        IfxGtm_Atom_Ch_setCompareZeroShadow(atomSFR, config->atomChannel, config->period);
    	IfxGtm_Atom_Ch_setCompareOneShadow(atomSFR, config->atomChannel, config->dutyCycle);
    	if( IfxGtm_Atom_Ch_getCompareZero(atomSFR, config->atomChannel) && IfxGtm_Atom_Ch_getCompareOne(atomSFR, config->atomChannel) )
		{
    		IfxGtm_Atom_Agc_trigger(driver->agc);
		}
    }

 	/* Connect output pin to Atom channel */
    if (config->pin.outputPin != NULL_PTR)
    {
    	IfxGtm_PinMap_setAtomTout(config->pin.outputPin, config->pin.outputMode, config->pin.padDriver);
    }

    if (config->immediateStartEnabled == TRUE)
    {
        IfxGtm_Atom_Agc_trigger(driver->agc);
    }

    return result;
}


void IfxGtm_Atom_Pwm_initConfig(IfxGtm_Atom_Pwm_Config *config, Ifx_GTM *gtm)
{
    config->gtm                      = gtm;
    config->atom                     = IfxGtm_Atom_0;
    config->atomChannel              = IfxGtm_Atom_Ch_0;
    config->clock 					 = IfxGtm_Cmu_Clk_0;
    config->period                   = 20;
    config->dutyCycle                = 10;
    config->signalLevel              = Ifx_ActiveState_high;
    config->mode                     = IfxGtm_Atom_Mode_outputPwm;
    config->oneShotModeEnabled       = FALSE;
    config->synchronousUpdateEnabled = FALSE;
    config->immediateStartEnabled    = TRUE;
    config->interrupt.ccu0Enabled    = FALSE;
    config->interrupt.ccu1Enabled    = FALSE;
    config->interrupt.mode           = IfxGtm_IrqMode_pulseNotify;
    config->interrupt.isrProvider    = IfxSrc_Tos_cpu0;
    config->interrupt.isrPriority    = 0;
    config->pin.outputPin            = NULL_PTR;
    config->pin.outputMode           = IfxPort_OutputMode_pushPull;
    config->pin.padDriver            = IfxPort_PadDriver_cmosAutomotiveSpeed1;
}


void IfxGtm_Atom_Pwm_start(IfxGtm_Atom_Pwm_Driver *driver, boolean immediate)
{
    /* Enable channel if not enabled already */
    IfxGtm_Atom_Agc_enableChannel(driver->agc, driver->atomChannel, TRUE, immediate);
    IfxGtm_Atom_Agc_enableChannelOutput(driver->agc, driver->atomChannel, TRUE, immediate);

    /* Trigger the start now */
    IfxGtm_Atom_Agc_trigger(driver->agc);
}


void IfxGtm_Atom_Pwm_stop(IfxGtm_Atom_Pwm_Driver *driver, boolean immediate)
{
    /* Disable channels */
    IfxGtm_Atom_Agc_enableChannel(driver->agc, driver->atomChannel, FALSE, immediate);
    IfxGtm_Atom_Agc_enableChannelOutput(driver->agc, driver->atomChannel, FALSE, immediate);

    /* Trigger the stop now */
    IfxGtm_Atom_Agc_trigger(driver->agc);
}
#endif

#if defined (_TASKING_) || defined (_ghs_)
#pragma restore
#endif
