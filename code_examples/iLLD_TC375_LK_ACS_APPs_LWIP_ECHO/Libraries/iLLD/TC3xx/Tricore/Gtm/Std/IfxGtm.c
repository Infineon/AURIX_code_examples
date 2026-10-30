/**
 * \file IfxGtm.c
 * \brief GTM  basic functionality
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
#include "IfxGtm.h"
#include "Scu/Std/IfxScuWdt.h"
#include "Scu/Std/IfxScuCcu.h"

/******************************************************************************/
/*-------------------------Function Implementations---------------------------*/
/******************************************************************************/

void IfxGtm_disable(Ifx_GTM *gtm)
{
    uint16 psw = IfxScuWdt_getCpuWatchdogPassword();

    /* Clearing the endinit protection */
    IfxScuWdt_clearCpuEndinit(psw);
    /* Disabling the GTM module */
    gtm->CLC.B.DISR = 1;
    /* Setting the endinit protection back on */
    IfxScuWdt_setCpuEndinit(psw);
}


void IfxGtm_enable(Ifx_GTM *gtm)
{
    uint16 psw = IfxScuWdt_getCpuWatchdogPassword();

    /* Clearing the endinit protection */
    IfxScuWdt_clearCpuEndinit(psw);
    /* Enabling the GTM module */
    gtm->CLC.B.DISR = 0;
    /* Setting the endinit protection back on */
    IfxScuWdt_setCpuEndinit(psw);
}


float32 IfxGtm_getSysClkFrequency(void)
{
    return IfxScuCcu_getGtmFrequency();
}


float32 IfxGtm_getClusterFrequency(Ifx_GTM *gtm, IfxGtm_Cluster cluster)
{
    float32 Freq;
    uint8   clsDiv = ((gtm->CLS_CLK_CFG.U) >> (cluster * 2)) & 0x3;

    if (clsDiv == 0)
    {
    	/* Cluster is disabled - return 0 */
        Freq = 0.0f;
    }
    else
    {
        Freq = IfxGtm_getSysClkFrequency() / clsDiv;
    }

    return Freq;
}
#endif

#if defined (_TASKING_) || defined (_ghs_)
#pragma restore
#endif
