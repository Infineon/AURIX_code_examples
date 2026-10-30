/**
 * \file IfxHspdm.c
 * \brief HSPDM  basic functionality
 *
 * \version iLLD_1_22_0
 * \copyright Copyright (c) 2026 Infineon Technologies AG. All rights reserved.
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
#pragma warning 508				/* To suppress empty file warning */
#endif
#if defined (__ghs__)
#pragma diag_suppress 96		/* To suppress empty file warning */
#endif
/* Hspdm module is not supported for derivative TC33xED with pin package LFBGA180_adas */
#if (defined(DEVICE_TC33XED) && !defined(IFX_PIN_PACKAGE_LFBGA180_ADAS)) || defined(DEVICE_TC39XB)
#include "IfxHspdm.h"

/******************************************************************************/
/*-------------------------Function Implementations---------------------------*/
/******************************************************************************/

void IfxHspdm_setStartAddress(Ifx_HSPDM *hspdm, IfxHspdm_Buffer buffer, uint32 address)
{
    if (address < IFXHSPDM_BUFFER_MAX_SIZE)
    {
        switch (buffer)
        {
        case IfxHspdm_Buffer_a:
            hspdm->BUFA0.B.STARTA = address;
            break;
        case IfxHspdm_Buffer_b:
            hspdm->BUFB0.B.STARTB = address;
            break;
        default:
            break;
        }
    }
    else
    {
        /* Do nothing */
    }
}


void IfxHspdm_setEndAddress(Ifx_HSPDM *hspdm, IfxHspdm_Buffer buffer, uint32 address)
{
    if (address < IFXHSPDM_BUFFER_MAX_SIZE)
    {
        switch (buffer)
        {
        case IfxHspdm_Buffer_a:
            hspdm->BUFA0.B.ENDA = address;
            break;
        case IfxHspdm_Buffer_b:
            hspdm->BUFB0.B.ENDB = address;
            break;
        default:
            break;
        }
    }
    else
    {
        /* Do nothing */
    }
}


void IfxHspdm_setMuteAddresses(Ifx_HSPDM *hspdm, IfxHspdm_MuteRange muteRange, uint32 startAddress, uint32 endAddress)
{
    switch (muteRange)
    {
    case IfxHspdm_MuteRange_0:
        hspdm->MUTE0.B.START0 = startAddress;
        hspdm->MUTE0.B.END0   = endAddress;
        break;
    case IfxHspdm_MuteRange_1:
        hspdm->MUTE1.B.START1 = startAddress;
        hspdm->MUTE1.B.END1   = endAddress;
        break;
    default:
        /* Do nothing */
        break;
    }
}


void IfxHspdm_enableBSB(Ifx_HSPDM *hspdm, IfxHspdm_BSB bsb, boolean enable)
{
    switch (bsb)
    {
    case IfxHspdm_BSB_0:
        hspdm->CON.B.EN0 = (uint32)enable;
        break;
    case IfxHspdm_BSB_1:
        hspdm->CON.B.EN1 = (uint32)enable;
        break;
    default:
    	/* Do nothing */
        break;
    }
}


void IfxHspdm_initBsPin(IfxHspdm_Bs_Out *bsPin, IfxPort_OutputMode outputMode, IfxPort_PadDriver padDriver)
{
    IfxPort_setPinModeOutput(bsPin->pin.port, bsPin->pin.pinIndex, outputMode, bsPin->select);
    IfxPort_setPinPadDriver(bsPin->pin.port, bsPin->pin.pinIndex, padDriver);
}


void IfxHspdm_initMutePin(IfxHspdm_Mute_Out *mutePin, IfxPort_OutputMode outputMode, IfxPort_PadDriver padDriver)
{
    IfxPort_setPinModeOutput(mutePin->pin.port, mutePin->pin.pinIndex, outputMode, mutePin->select);
    IfxPort_setPinPadDriver(mutePin->pin.port, mutePin->pin.pinIndex, padDriver);
}
#endif

#if defined (_TASKING_) || defined (_ghs_)
#pragma restore
#endif
