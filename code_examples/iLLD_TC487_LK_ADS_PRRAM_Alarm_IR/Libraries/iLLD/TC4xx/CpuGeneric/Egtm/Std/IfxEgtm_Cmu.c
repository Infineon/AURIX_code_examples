/**
 * \file IfxEgtm_Cmu.c
 * \brief EGTM  basic functionality
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
#pragma warning 508 /* To suppress empty file warning */
#endif
#if defined (__ghs__)
#pragma diag_suppress 96 /* To suppress empty file warning */
#endif

#if !defined(DEVICE_TC45X)
#include "IfxEgtm_Cmu.h"
#include "math.h"

/******************************************************************************/
/*-------------------------Function Implementations---------------------------*/
/******************************************************************************/

float32 IfxEgtm_Cmu_getClkFrequency(Ifx_EGTM *egtm, IfxEgtm_Cmu_Clk clkIndex, boolean assumeEnabled)
{
    float32 frequency;

    if ((IfxEgtm_Cmu_isClkClockEnabled(egtm, clkIndex) != FALSE) || (assumeEnabled != FALSE))
    {
        switch (clkIndex)
        {
        case IfxEgtm_Cmu_Clk_0:
            frequency = (float32)(IfxEgtm_Cmu_getGclkFrequency(egtm) / ((float32)egtm->CLS->CMU.CLK0.CTRL.B.CLK_CNT + 1.0f));
            break;
        case IfxEgtm_Cmu_Clk_1:
            frequency = (float32)(IfxEgtm_Cmu_getGclkFrequency(egtm) / ((float32)egtm->CLS->CMU.CLK1.CTRL.B.CLK_CNT + 1.0f));
            break;
        case IfxEgtm_Cmu_Clk_2:
            frequency = (float32)(IfxEgtm_Cmu_getGclkFrequency(egtm) / ((float32)egtm->CLS->CMU.CLK2.CTRL.B.CLK_CNT + 1.0f));
            break;
        case IfxEgtm_Cmu_Clk_3:
            frequency = (float32)(IfxEgtm_Cmu_getGclkFrequency(egtm) / ((float32)egtm->CLS->CMU.CLK3.CTRL.B.CLK_CNT + 1.0f));
            break;
        case IfxEgtm_Cmu_Clk_4:
            frequency = (float32)(IfxEgtm_Cmu_getGclkFrequency(egtm) / ((float32)egtm->CLS->CMU.CLK4.CTRL.B.CLK_CNT + 1.0f));
            break;
        case IfxEgtm_Cmu_Clk_5:
            frequency = (float32)(IfxEgtm_Cmu_getGclkFrequency(egtm) / ((float32)egtm->CLS->CMU.CLK5.CTRL.B.CLK_CNT + 1.0f));
            break;
        case IfxEgtm_Cmu_Clk_6:

            if (egtm->CLS->CMU.CLK_6_CTRL.B.CLK_SEL == 0u)
            {
                frequency = (float32)(IfxEgtm_Cmu_getGclkFrequency(egtm) / ((float32)egtm->CLS->CMU.CLK_6_CTRL.B.CLK_CNT + 1.0f));
            }

            else    /* input tied to low, no dpll present */
            {
                frequency = 0.0f;
                /* TODO: Use signal of sub-module CCM0 for 11B (CCM0_CMU_CLK6) */
            }

            break;
        case IfxEgtm_Cmu_Clk_7:

            if (egtm->CLS->CMU.CLK_7_CTRL.B.CLK_SEL == 0u)
            {
                frequency = (float32)(IfxEgtm_Cmu_getGclkFrequency(egtm) / ((float32)egtm->CLS->CMU.CLK_7_CTRL.B.CLK_CNT + 1.0f));
            }

            else    /* input tied to low, no dpll present */
            {
                frequency = 0.0f;
            }

            break;
        default:
            frequency = (float32)0.0f;
            break;
        }
    }
    else
    {
        frequency = (float32)0.0f;
    }

    return frequency;
}


float32 IfxEgtm_Cmu_getEclkFrequency(Ifx_EGTM *egtm, IfxEgtm_Cmu_Eclk clkIndex, boolean assumeEnabled)
{
    float32 frequency;

    if ((IfxEgtm_Cmu_isEclkClockEnabled(egtm, clkIndex) == TRUE) || (assumeEnabled != FALSE))
    {
        float32 Z = 0.0f;
        float32 N = 0.0f;
        Z = (float32)egtm->CLS->CMU.ECLK[clkIndex].NUM.B.ECLK_NUM;
        N = (float32)egtm->CLS->CMU.ECLK[clkIndex].DEN.B.ECLK_DEN;

        float32 multiplier = N / Z / 2.0f;
        frequency = IfxEgtm_Cmu_getGclkFrequency(egtm) * multiplier;
    }
    else
    {
        frequency = (float32)0.0f;
    }

    return frequency;
}


float32 IfxEgtm_Cmu_getFxClkFrequency(Ifx_EGTM *egtm, IfxEgtm_Cmu_Fxclk clkIndex, boolean assumeEnabled)
{
    float32 frequency;
    uint8   fxSelect;

    if ((IfxEgtm_Cmu_isFxClockEnabled(egtm) == TRUE) || (assumeEnabled != FALSE))
    {
    	/* Gets the current Fx clock selection */
        fxSelect = egtm->CLS->CMU.FXCLK_CTRL.B.FXCLK_SEL;

        if (fxSelect == 0u)
        {
        	/* Get the EGTM global clock frequency */
            frequency = IfxEgtm_Cmu_getGclkFrequency(egtm);
        }
        else if (fxSelect <= 8u)
        {
            frequency = IfxEgtm_Cmu_getClkFrequency(egtm, (IfxEgtm_Cmu_Clk)(fxSelect - 1u), assumeEnabled);
        }
        else
        {
            frequency = IfxEgtm_Cmu_getGclkFrequency(egtm);
        }

        switch (clkIndex)
        {
        case IfxEgtm_Cmu_Fxclk_0:
        	/* Fx clock 0: no divider */
            frequency = frequency / (float32)1.0f;
            break;
        case IfxEgtm_Cmu_Fxclk_1:
        	/* Fx clock 1: divide by 16 */
            frequency = frequency / (float32)16.0f;
            break;
        case IfxEgtm_Cmu_Fxclk_2:
        	/* Fx clock 1: divide by 256 */
            frequency = frequency / (float32)256.0f;
            break;
        case IfxEgtm_Cmu_Fxclk_3:
        	/* Fx clock 1: divide by 4096 */
            frequency = frequency / (float32)4096.0f;
            break;
        case IfxEgtm_Cmu_Fxclk_4:
        	/* Fx clock 1: divide by 65536 */
            frequency = frequency / (float32)65536.0f;
            break;
        default:
        	/* Invalid clkIndex: return 0 */
            frequency = (float32)0.0f;
            break;
        }
    }
    else
    {
        frequency = (float32)0.0f;
    }

    /* Returns the calculated frequency */
    return frequency;
}


void IfxEgtm_Cmu_setClkFrequency(Ifx_EGTM *egtm, IfxEgtm_Cmu_Clk clkIndex, float32 frequency)
{
    float32 t   = (IfxEgtm_Cmu_getGclkFrequency(egtm) / frequency) - (float32)1.0f;
    uint32  cnt = (uint32)t;

    if ((t - (float32)cnt) > (float32)0.5f)
    {
    	/* Round to nearest */
        cnt++;
    }

    /* Updates the clock control register based on the clock index */
    switch (clkIndex)
    {
    case IfxEgtm_Cmu_Clk_0:
    	/* Updates the clock control register for clock 0 */
        egtm->CLS->CMU.CLK0.CTRL.B.CLK_CNT = cnt;
        break;
    case IfxEgtm_Cmu_Clk_1:
    	/* Updates the clock control register for clock 1 */
        egtm->CLS->CMU.CLK1.CTRL.B.CLK_CNT = cnt;
        break;
    case IfxEgtm_Cmu_Clk_2:
    	/* Updates the clock control register for clock 2 */
        egtm->CLS->CMU.CLK2.CTRL.B.CLK_CNT = cnt;
        break;
    case IfxEgtm_Cmu_Clk_3:
    	/* Updates the clock control register for clock 3 */
        egtm->CLS->CMU.CLK3.CTRL.B.CLK_CNT = cnt;
        break;
    case IfxEgtm_Cmu_Clk_4:
    	/* Updates the clock control register for clock 4 */
        egtm->CLS->CMU.CLK4.CTRL.B.CLK_CNT = cnt;
        break;
    case IfxEgtm_Cmu_Clk_5:
    	/* Update the clock control register for clock 5 */
        egtm->CLS->CMU.CLK5.CTRL.B.CLK_CNT = cnt;
        break;
    case IfxEgtm_Cmu_Clk_6:
    	/* Updates the clock control register for clock 6 */
        egtm->CLS->CMU.CLK_6_CTRL.B.CLK_CNT = cnt;
        break;
    case IfxEgtm_Cmu_Clk_7:
    	/* Updates the clock control register for clock 7 */
        egtm->CLS->CMU.CLK_7_CTRL.B.CLK_CNT = cnt;
        break;
    default:
        /* do nothing */
        break;
    }
}


void IfxEgtm_Cmu_setEclkFrequency(Ifx_EGTM *egtm, IfxEgtm_Cmu_Eclk clkIndex, float32 frequency)
{
    float32 f;
    float32 bestDistance = frequency;
    float32 fIn          = IfxEgtm_Cmu_getGclkFrequency(egtm);
    uint32  z, n, nBest = 1u, zBest = 1u;
    float32 t;

    for (z = 1u; z < 0xFFFFFFu; z++)
    {
        boolean endLoop = FALSE;
        t = fIn / z;

        for (n = z; n > 0u; n--)
        {
            float32 distance;
            f        = t * n / 2.0f;
            distance = fabsf(frequency - f);

            if (distance < bestDistance)
            {
                bestDistance = distance;
                nBest        = n;
                zBest        = z;
            }

            if (bestDistance < 0.1f)
            {
                endLoop = TRUE;
                break;
            }
        }

        if (endLoop)
        {
            break;
        }
    }

    egtm->CLS->CMU.ECLK[clkIndex].NUM.B.ECLK_NUM = zBest;
    egtm->CLS->CMU.ECLK[clkIndex].NUM.B.ECLK_NUM = zBest; /* Write twice to be sure */
    egtm->CLS->CMU.ECLK[clkIndex].DEN.B.ECLK_DEN = nBest;
}


void IfxEgtm_Cmu_setGclkFrequency(Ifx_EGTM *egtm, float32 frequency)
{
    float32 f;
    float32 bestDistance = frequency;

    float32 fIn          = IfxEgtm_Cmu_getModuleFrequency(egtm);
    uint32  z, n, nBest = 1u, zBest = 1u;
    float32 t;

    for (z = 1u; z < 0xFFFFFFu; z++)
    {
        boolean endLoop = FALSE;
        t = fIn / z;

        for (n = z; n > 0u; n--)
        {
            float32 distance;
            f        = t * n;
            distance = fabsf(frequency - f);

            if (distance < bestDistance)
            {
                bestDistance = distance;
                nBest        = n;
                zBest        = z;
            }

            if (bestDistance < 0.1f)
            {
                endLoop = TRUE;
                break;
            }
        }

        if (endLoop)
        {
            break;
        }
    }

    egtm->CLS->CMU.GCLK_NUM.B.GCLK_NUM = zBest;
    egtm->CLS->CMU.GCLK_NUM.B.GCLK_NUM = zBest;   /* Write twice to be sure */
    egtm->CLS->CMU.GCLK_DEN.B.GCLK_DEN = nBest;
}

#endif /* !defined(DEVICE_TC45X) */

#if defined (_TASKING_) || defined (_ghs_)
#pragma restore
#endif
