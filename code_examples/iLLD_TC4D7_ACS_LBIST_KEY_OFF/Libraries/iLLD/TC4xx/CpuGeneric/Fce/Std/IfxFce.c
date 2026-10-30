/**
 * \file IfxFce.c
 * \brief FCE  basic functionality
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

#if !defined(DEVICE_TC48XAA) && !defined(DEVICE_TC48X)
#include "IfxFce.h"

/******************************************************************************/
/*-------------------------Function Implementations---------------------------*/
/******************************************************************************/

uint32 IfxFce_reflectCrc32(uint32 crcStartValue, uint8 crcLength)
{
    uint32 ReversedData = 0x0U;
    uint8  inputDataCounter;

    for (inputDataCounter = 0; inputDataCounter < crcLength; ++inputDataCounter)
    {
        if (crcStartValue & 0x01)
        {
            ReversedData |= (uint32)((uint32)1 << ((crcLength - 1) - inputDataCounter));
        }

        crcStartValue = (uint32)((uint32)crcStartValue >> (uint32)1);
    }

    return ReversedData;
}


void IfxFce_resetModule(Ifx_FCE *fce)
{
#if (IFX_PROT_ENABLED == 1U)
    IfxApProt_setState((Ifx_PROT_PROT *)&fce->PROTE, IfxApProt_State_config);
#endif
    /* Only if both Kernel reset bits are set a reset is executed */
    fce->RST.CTRLA.B.KRST = 1U;
    fce->RST.CTRLB.B.KRST = 1U;

    /* Waits until reset is executed */
    while (0 == fce->RST.STAT.B.KRST)
    {}

    /* Clears Kernel reset status bit */
    fce->RST.CTRLB.B.STATCLR = 1U;
#if (IFX_PROT_ENABLED == 1U)
    IfxApProt_setState((Ifx_PROT_PROT *)&fce->PROTE, IfxApProt_State_run);
#endif
}


void IfxFce_configureAccessToFce(IfxApApu_ApuConfig *apConfig)
{
    IfxApApu_init((Ifx_ACCEN_ACCEN *)&MODULE_FCE.ACCEN, apConfig);
}

#endif /* #if !defined(DEVICE_TC48XAA) && !defined(DEVICE_TC48X) */

#if defined (_TASKING_) || defined (_ghs_)
#pragma restore
#endif
