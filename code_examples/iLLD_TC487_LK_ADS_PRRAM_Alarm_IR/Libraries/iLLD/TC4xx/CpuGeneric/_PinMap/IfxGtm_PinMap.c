/**
 * \file IfxGtm_PinMap.c
 * \brief GTM  details
 *
 * \version iLLD-TC4-v2.6.0
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

#if defined(DEVICE_TC49XN) || defined(DEVICE_TC46X)  || defined(DEVICE_TC4EX)
#include "IfxGtm_PinMap.h"

/******************************************************************************/
/*-------------------------Function Implementations---------------------------*/
/******************************************************************************/

void IfxGtm_PinMap_setAtomTout(IfxGtm_Atom_ToutMap *config, IfxPort_OutputMode outputMode, IfxPort_PadDriver padDriver)
{
    uint32 outselReg = (config->toutn / 6);
    uint32 shift     = (config->toutn % 6) * 5;

    if (shift >= 15)
    {
        ++shift;
    }

    uint32 outsel = (uint32)config->toutSel << shift;
    uint32 mask   = 0x1FU << shift;

    Ifx__ldmst(&(MODULE_GTM.TOUTSEL[outselReg].U), mask, outsel);

    IfxPort_setPinModeOutput(config->pin.port, config->pin.pinIndex, outputMode, config->select);
    IfxPort_setPinPadDriver(config->pin.port, config->pin.pinIndex, padDriver);
}


void IfxGtm_PinMap_setTomTout(IfxGtm_Tom_ToutMap *config, IfxPort_OutputMode outputMode, IfxPort_PadDriver padDriver)
{
    uint32 outselReg = (config->toutn / 6);
    uint32 shift     = (config->toutn % 6) * 5;

    if (shift >= 15)
    {
        ++shift;
    }

    uint32 outsel = (uint32)config->toutSel << shift;
    uint32 mask   = 0x1FU << shift;

    Ifx__ldmst(&(MODULE_GTM.TOUTSEL[outselReg].U), mask, outsel);

    IfxPort_setPinModeOutput(config->pin.port, config->pin.pinIndex, outputMode, config->select);
    IfxPort_setPinPadDriver(config->pin.port, config->pin.pinIndex, padDriver);
}


void IfxGtm_PinMap_setCdtmPin(IfxGtm_Cdtm_InputMap *config, IfxPort_InputMode inputMode, IfxGtm_DtmAuxInput dtmAuxInput)
{
    MODULE_GTM.DTMAUX[config->cdtm].IN[dtmAuxInput].U = ((uint32)config->select) << ((config->dtm) * 4);

    if (inputMode != IfxPort_InputMode_undefined)
    {
        IfxPort_setPinModeInput(config->pin.port, config->pin.pinIndex, inputMode);
    }
}


void IfxGtm_PinMap_setTimTin(IfxGtm_Tim_TinMap *config, IfxPort_InputMode inputMode)
{
    uint32 shift = config->channel * 4;

    Ifx__ldmst(&(MODULE_GTM.TIMINSEL[config->tim].U), (0xFU << shift), ((uint32)config->select) << shift);

    if (inputMode != IfxPort_InputMode_undefined)
    {
        IfxPort_setPinModeInput(config->pin.port, config->pin.pinIndex, inputMode);
    }
}

#endif /* #if defined(DEVICE_TC49XN) || defined(DEVICE_TC46X) || defined(DEVICE_TC4EX) */

#if defined (_TASKING_) || defined (_ghs_)
#pragma restore
#endif
