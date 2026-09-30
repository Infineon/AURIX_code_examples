/**
 * \file IfxGtm_Atom.c
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
#include "IfxGtm_Atom.h"

/******************************************************************************/
/*-------------------------Function Implementations---------------------------*/
/******************************************************************************/

uint32 IfxGtm_Atom_Agc_buildFeature(uint16 enableMask, uint16 disableMask, uint8 bitfieldOffset)
{
    uint8  i;
    uint32 reg  = 0u;
    uint32 mask = (uint32)((uint32)enableMask | ((uint32)disableMask << 16u));

    for (i = 0u; i < IFXGTM_ATOM_NUM_AGC_CHANNELS; i++)
    {
        /* Bitfield length is 2 bits */
        uint8 shift = (i << 1u) + bitfieldOffset;

        if ((mask & 0x1u) == 0x1u)
        {
            reg |= (uint32)IfxGtm_FeatureControl_enable << shift;
        }

        if ((mask & 0x10000u) == 0x10000u)
        {
            reg |= (uint32)IfxGtm_FeatureControl_disable << shift;
        }

        mask = mask >> 1;
    }

    return reg;
}


uint32 IfxGtm_Atom_Agc_buildFeatureForChannel(IfxGtm_Atom_Ch channel, boolean enabled, uint8 bitfieldOffset)
{
    uint32 reg = 0u;

    /* Bitfield length is 2 bits */
    uint8  shift = (((uint8)channel & 0x7u) << 1u) + bitfieldOffset;

    if (enabled == 1u)
    {
        reg = (uint32)IfxGtm_FeatureControl_enable << shift;
    }
    else
    {
        reg = (uint32)IfxGtm_FeatureControl_disable << shift;
    }

    return reg;
}


float32 IfxGtm_Atom_Ch_getFrequency(Ifx_GTM_CLS_ATOM *atom, IfxGtm_Atom_Ch channel)
{
    float32                   frequency         = 0.0f, sourceFrequency;
    uint32                    periodTicks       = 0u;
    IfxGtm_Atom_Ch_ResetEvent counterResetEvent = (IfxGtm_Atom_Ch_ResetEvent)atom->CH[channel].CTRL.B.RST_CCU0;

    while ((counterResetEvent != IfxGtm_Atom_Ch_ResetEvent_onCm0) &&
           (channel > IfxGtm_Atom_Ch_0))       /* Counter is reset from previous channel */
    {
        channel           = (IfxGtm_Atom_Ch)((uint8)channel - 1u);
        counterResetEvent = (IfxGtm_Atom_Ch_ResetEvent)atom->CH[channel].CTRL.B.RST_CCU0;
    }

    if (counterResetEvent == IfxGtm_Atom_Ch_ResetEvent_onCm0)  /* Counter is reset from own channel */
    {
        /* 1. Get channel input frequency */
        sourceFrequency = IfxGtm_Atom_Ch_getClockFrequency(&MODULE_GTM, atom, channel);

        /* 2. Calculate Period Ticks */
        if (atom->CH[channel].CTRL.B.UDMODE == 0u)  /* Channel counter running in continuous counting up mode */
        {
            periodTicks = atom->CH[channel].CM0.U;
        }
        else /* Channel counter running in continuous counting up and down mode. Therefore, multiply by 2 */
        {
            periodTicks = (atom->CH[channel].CM0.U - 1u) << 1u;
        }

        /* 3. Calculate PWM frequency */
        frequency = sourceFrequency / (float32)periodTicks;
    }

    return frequency;
}


float32 IfxGtm_Atom_Ch_getDuty(Ifx_GTM_CLS_ATOM *atom, IfxGtm_Atom_Ch channel)
{
    float32                   duty = 0.0f;
    uint32                    cm0Reg, cm1Reg, periodReg;
    IfxGtm_Atom_Ch_ResetEvent counterResetEvent;

    /* 1. Read counter reset event */
    counterResetEvent = (IfxGtm_Atom_Ch_ResetEvent)atom->CH[channel].CTRL.B.RST_CCU0;

    /* 2. Read register content */
    cm0Reg = atom->CH[channel].CM0.U;
    cm1Reg = atom->CH[channel].CM1.U;

    /* 3. Find out the period register value */
    if (counterResetEvent == IfxGtm_Atom_Ch_ResetEvent_onCm0)  /* Period is determined by own channel */
    {
        periodReg = cm0Reg;
    }
    else    /* Period is determined by some previous channel */
    {
        uint8 tempChannel = (uint8)channel - 1u;

        while ((tempChannel > 0) &&
               (atom->CH[tempChannel].CTRL.B.RST_CCU0 != (uint8)IfxGtm_Atom_Ch_ResetEvent_onCm0))
        {
            tempChannel--;
        }

        periodReg = atom->CH[tempChannel].CM0.U;
    }

    /* 4. Calculate Duty percentage */
    if (atom->CH[channel].CTRL.B.UDMODE == 0u)                    /* Channel counter running in continuous counting up mode */
    {
        if (counterResetEvent == IfxGtm_Atom_Ch_ResetEvent_onCm0) /* Duty exists during CN0 = [0, CM1] */
        {
            duty = ((float32)cm1Reg / (float32)periodReg) * 100.0f;
        }
        else    /* Duty exists during CN0 = [CM0, CM1] */
        {
            if (cm1Reg > cm0Reg)
            {
                duty = ((float32)(cm1Reg - cm0Reg) / (float32)periodReg) * 100.0f;
            }
            else
            {
                duty = ((float32)(cm0Reg - cm1Reg) / (float32)periodReg) * 100.0f;
            }
        }
    }
    else  /* Channel counter running in continuous counting up and down mode */
    {
        /* Duty exists during CN0 = [CM1, CM0] */
        duty = ((float32)(periodReg - cm1Reg) / (float32)periodReg) * 100.0f;
    }

    return duty;
}

#endif /* #if defined(DEVICE_TC49XN) || defined(DEVICE_TC46X) || defined(DEVICE_TC4EX) */

#if defined (_TASKING_) || defined (_ghs_)
#pragma restore
#endif

