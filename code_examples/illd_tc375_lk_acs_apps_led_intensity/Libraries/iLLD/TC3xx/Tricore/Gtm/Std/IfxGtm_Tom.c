/**
 * \file IfxGtm_Tom.c
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
#include "IfxGtm_Tom.h"

/******************************************************************************/
/*-------------------------Function Implementations---------------------------*/
/******************************************************************************/

uint32 IfxGtm_Tom_Tgc_buildFeature(uint16 enableMask, uint16 disableMask, uint8 bitfieldOffset)
{
    uint8  i;
    uint32 reg  = 0;
    uint32 mask = enableMask | (disableMask << 16);

    /* Build the register value for the feature enable or disable for multiple channels */
    for (i = 0; i < IFXGTM_TOM_NUM_TGC_CHANNELS; i++)
    {
        /* Bitfield length is 2 bits */
        uint8 shift = (i * 2) + bitfieldOffset;

        if (mask & 0x1)
        {
            reg |= IfxGtm_FeatureControl_enable << shift;
        }

        if (mask & 0x10000)
        {
            reg |= IfxGtm_FeatureControl_disable << shift;
        }

        mask = mask >> 1;
    }

    return reg;
}


uint32 IfxGtm_Tom_Tgc_buildFeatureForChannel(IfxGtm_Tom_Ch channel, boolean enabled, uint8 bitfieldOffset)
{
    uint32 reg = 0;

    /* Bitfield length is 2 bits */
    uint8  shift = ((channel % 8) * 2) + bitfieldOffset;

    /* Build the register value for the feature enable or disable for a single channel */
    if (enabled == 1)
    {
        reg = IfxGtm_FeatureControl_enable << shift;
    }
    else
    {
        reg = IfxGtm_FeatureControl_disable << shift;
    }

    return reg;
}


void IfxGtm_Tom_Tgc_resetChannels(Ifx_GTM_TOM_TGC *tgc, uint32 resetMask)
{
    uint8  i;
    uint32 reg = 0;

    for (i = 0; i < IFXGTM_TOM_NUM_TGC_CHANNELS; i++)
    {
        if (resetMask & 0x1)
        {
            reg |= 1 << i;
        }

        resetMask = resetMask >> 1;
    }

    tgc->GLB_CTRL.U = reg << IFX_GTM_TOM_TGC_GLB_CTRL_RST_CH0_OFF;
}
#endif

#if defined (_TASKING_) || defined (_ghs_)
#pragma restore
#endif
