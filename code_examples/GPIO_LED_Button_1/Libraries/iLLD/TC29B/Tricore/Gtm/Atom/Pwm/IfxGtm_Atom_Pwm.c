/**
 * \file IfxGtm_Atom_Pwm.c
 * \brief GTM PWM details
 *
 * \version iLLD_1_0_1_9_0
 * \copyright Copyright (c) 2018 Infineon Technologies AG. All rights reserved.
 *
 *
 *                                 IMPORTANT NOTICE
 *
 *
 * Infineon Technologies AG (Infineon) is supplying this file for use
 * exclusively with Infineon's microcontroller products. This file can be freely
 * distributed within development tools that are supporting such microcontroller
 * products.
 *
 * THIS SOFTWARE IS PROVIDED "AS IS".  NO WARRANTIES, WHETHER EXPRESS, IMPLIED
 * OR STATUTORY, INCLUDING, BUT NOT LIMITED TO, IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE APPLY TO THIS SOFTWARE.
 * INFINEON SHALL NOT, IN ANY CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL,
 * OR CONSEQUENTIAL DAMAGES, FOR ANY REASON WHATSOEVER.
 *
 */

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include "IfxGtm_Atom_Pwm.h"

/******************************************************************************/
/*-------------------------Function Implementations---------------------------*/
/******************************************************************************/

boolean IfxGtm_Atom_Pwm_init(IfxGtm_Atom_Pwm_Driver *driver, const IfxGtm_Atom_Pwm_Config *config)
{
    boolean result = TRUE;

    driver->gtm       = config->gtm;
    driver->atomIndex = config->atom;

    Ifx_GTM_ATOM     *atomSFR = &config->gtm->ATOM[config->atom];
    driver->atom        = atomSFR;
    driver->atomChannel = config->atomChannel;
    Ifx_GTM_ATOM_AGC *agc = &atomSFR->AGC;
    driver->agc         = agc;

    /* Initialize the timer part */
    if (config->synchronousUpdateEnabled == 1)
    {
        IfxGtm_Atom_Agc_enableChannelUpdate(agc, config->atomChannel, TRUE);
    }

    IfxGtm_Atom_Agc_setChannelForceUpdate(agc, config->atomChannel, TRUE, TRUE);

    IfxGtm_Atom_Ch_setSignalLevel(atomSFR, config->atomChannel, config->signalLevel);

    IfxGtm_Atom_Ch_setMode(atomSFR, config->atomChannel, config->mode);

    if (config->pin.outputPin != NULL_PTR)
    {
        IfxGtm_PinMap_setAtomTout(config->pin.outputPin, config->pin.outputMode, config->pin.padDriver);
    }

    // enable and initialise interrupts if chosen
    if ((config->interrupt.ccu0Enabled == 1) || (config->interrupt.ccu1Enabled == 1))
    {
        IfxGtm_Atom_Ch_setNotification(atomSFR, config->atomChannel, config->interrupt.mode, config->interrupt.ccu0Enabled, config->interrupt.ccu1Enabled);

        volatile Ifx_SRC_SRCR *src;
        src = IfxGtm_Atom_Ch_getSrcPointer(config->gtm, config->atom, config->atomChannel);
        IfxSrc_init(src, config->interrupt.isrProvider, config->interrupt.isrPriority);
        IfxSrc_enable(src);
    }

    if (config->synchronousUpdateEnabled == 1)
    {
        IfxGtm_Atom_Ch_setCompareZeroShadow(atomSFR, config->atomChannel, config->period);
        IfxGtm_Atom_Ch_setCompareOneShadow(atomSFR, config->atomChannel, config->dutyCycle);
    }
    else
    {
        IfxGtm_Atom_Ch_setCompareZero(atomSFR, config->atomChannel, config->period);
        IfxGtm_Atom_Ch_setCompareOne(atomSFR, config->atomChannel, config->dutyCycle);
    }

    IfxGtm_Atom_Agc_enableChannel(agc, config->atomChannel, TRUE, FALSE);
    IfxGtm_Atom_Agc_enableChannelOutput(agc, config->atomChannel, TRUE, FALSE);

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
