/**
 * \file IfxGtm_Psm.c
 * \brief GTM  basic functionality
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

#if defined(DEVICE_TC49XN) || defined(DEVICE_TC46X) || defined(DEVICE_TC4EX)
#include "IfxGtm_Psm.h"

/******************************************************************************/
/*-------------------------Function Implementations---------------------------*/
/******************************************************************************/

IfxGtm_Psm_FifoChannelStatus IfxGtm_Psm_Fifo_getChannelStatus(IfxGtm_Cluster clsIndex, IfxGtm_Psm_FifoChannel channel)
{
	/* Gets the Pointer to the Fifo Channel SFR */
    Ifx_GTM_CLS_PSM_FIFO_CH     *fifoCh     = IfxGtm_Psm_Fifo_getChannelPointer(clsIndex, channel);
    IfxGtm_Psm_FifoChannelStatus status     = IfxGtm_Psm_FifoChannelStatus_normal;
    uint32                       status_reg = (uint32)fifoCh->STATUS.U;
    uint8                        idx        = 0;

    /* Gets the status of the fifo channel */
    while (idx < (uint8)IfxGtm_Psm_FifoChannelStatus_normal)
    {
        if (((status_reg >> idx) & (uint32)1) == (uint32)1)
        {
            status = (IfxGtm_Psm_FifoChannelStatus)idx;
            break;
        }

        idx++;
    }

    return status;
}

#endif /* #if defined(DEVICE_TC49XN) || defined(DEVICE_TC46X) || defined(DEVICE_TC4EX) */

#if defined (_TASKING_) || defined (_ghs_)
#pragma restore
#endif

