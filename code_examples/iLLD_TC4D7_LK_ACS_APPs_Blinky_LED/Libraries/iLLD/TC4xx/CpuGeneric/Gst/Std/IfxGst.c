/**
 * \file IfxGst.c
 * \brief GST  basic functionality
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

#if defined(DEVICE_TC45X)
#include "IfxGst.h"

/******************************************************************************/
/*-------------------------Function Implementations---------------------------*/
/******************************************************************************/

void IfxGst_initTriggerOutPin(const IfxGst_Hwtrg_Out *trigPin, IfxPort_OutputMode pinMode, IfxPort_PadDriver padDriver)
{
    if ((trigPin != NULL_PTR) && (trigPin->pin.port != NULL_PTR))
    {
        IfxPort_setPinModeOutput(trigPin->pin.port, trigPin->pin.pinIndex, pinMode, trigPin->select);
        IfxPort_setPinPadDriver(trigPin->pin.port, trigPin->pin.pinIndex, padDriver);
    }
}


void IfxGst_initCaptureInPin(const IfxGst_Hwcap_In *capturePin, IfxPort_InputMode pinMode, IfxPort_PadDriver padDriver)
{
    if ((capturePin != NULL_PTR) && (capturePin->pin.port != NULL_PTR))
    {
        IfxPort_setPinModeInput(capturePin->pin.port, capturePin->pin.pinIndex, pinMode);
        IfxPort_setPinPadDriver(capturePin->pin.port, capturePin->pin.pinIndex, padDriver);
    }
}


void IfxGst_configureAccessToGsts(IfxApApu_ApuConfig *apConfig)
{
    IfxApApu_init((Ifx_ACCEN_ACCEN *)&MODULE_GST0.ACCEN, apConfig);
}

#endif /* #if defined(DEVICE_TC45X) */

#if defined (_TASKING_) || defined (_ghs_)
#pragma restore
#endif
