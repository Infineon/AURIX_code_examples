/**
 * \file IfxGtm_Cmu.c
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
#include "IfxGtm_Cmu.h"
#include "IfxGtm_Dpll.h"
#include "Scu/Std/IfxScuCcu.h"
#include "Scu/Std/IfxScuWdt.h"
#include "math.h"
#include "IfxGtm_bf.h"
#include "IfxGtm.h"

/******************************************************************************/
/*-------------------------Function Implementations---------------------------*/
/******************************************************************************/

void IfxGtm_Cmu_enableClocks(Ifx_GTM *gtm, uint32 clkMask)
{
    gtm->CMU.CLK_EN.U = clkMask;
}


float32 IfxGtm_Cmu_getClkFrequency(Ifx_GTM *gtm, IfxGtm_Cmu_Clk clkIndex, boolean assumeEnabled)
{
    float32 frequency;

    /* Retrieves the frequency of the specified CMU clock */
    if ((IfxGtm_Cmu_isClkClockEnabled(gtm, clkIndex) != FALSE) || (assumeEnabled != FALSE))
    {
        switch (clkIndex)
        {
        case IfxGtm_Cmu_Clk_0:
        case IfxGtm_Cmu_Clk_1:
        case IfxGtm_Cmu_Clk_2:
        case IfxGtm_Cmu_Clk_3:
        case IfxGtm_Cmu_Clk_4:
        case IfxGtm_Cmu_Clk_5:
            frequency = IfxGtm_Cmu_getGclkFrequency(gtm) / (gtm->CMU.CLK[clkIndex].CTRL.B.CLK_CNT + 1);
            break;
        case IfxGtm_Cmu_Clk_6:

        	/* Determine the clock source and calculates the frequency */
            if (gtm->CMU.CLK[clkIndex].CTRL.B.CLK_SEL == 0)
            {
                frequency = IfxGtm_Cmu_getGclkFrequency(gtm) / (gtm->CMU.CLK[clkIndex].CTRL.B.CLK_CNT + 1);
            }
            else
            {
#ifndef DEVICE_TC33X
                frequency = IfxGtm_Dpll_getSubIncFrequency(gtm, IfxGtm_Dpll_SubInc_2);
#else
                frequency = 0.0f;
#endif
            }

            break;
        case IfxGtm_Cmu_Clk_7:

        	/* Determine the clock source and calculates the frequency */
            if (gtm->CMU.CLK[clkIndex].CTRL.B.CLK_SEL == 0)
            {
                frequency = IfxGtm_Cmu_getGclkFrequency(gtm) / (gtm->CMU.CLK[clkIndex].CTRL.B.CLK_CNT + 1);
            }
            else
            {
#ifndef DEVICE_TC33X
                frequency = IfxGtm_Dpll_getSubIncFrequency(gtm, IfxGtm_Dpll_SubInc_1);
#else
                frequency = 0.0f;
#endif
            }

            break;
        default:
        	/* Returns 0.0f for unsupported clock indices */
            frequency = 0.0f;
            break;
        }
    }
    else
    {
    	/* Clock is disabled and assumeEnabled is FALSE - return 0 */
        frequency = 0.0f;
    }

    return frequency;
}


float32 IfxGtm_Cmu_getEclkFrequency(Ifx_GTM *gtm, IfxGtm_Cmu_Eclk clkIndex, boolean assumeEnabled)
{
    float32 frequency;

    /* Retrieves the frequency of the specified external clock (ECLK) */
    if (IfxGtm_Cmu_isEclkClockEnabled(gtm, clkIndex) || (assumeEnabled != FALSE))
    {
    	/* Calculates the ECLK frequency using the numerator and denominator values */
        float32 Z          = gtm->CMU.ECLK[clkIndex].NUM.B.ECLK_NUM;
        float32 N          = gtm->CMU.ECLK[clkIndex].DEN.B.ECLK_DEN;
        float32 multiplier = N / Z / 2;
        frequency = IfxGtm_Cmu_getGclkFrequency(gtm) * multiplier;
    }
    else
    {
    	/* External clock is disabled and assumeEnabled is FALSE - return 0 */
        frequency = 0.0f;
    }

    return frequency;
}


float32 IfxGtm_Cmu_getFxClkFrequency(Ifx_GTM *gtm, IfxGtm_Cmu_Fxclk clkIndex, boolean assumeEnabled)
{
    float32 frequency;
    uint8   fxSelect;

    /* Retrieves the frequency of the specified fixed clock (FXCLK) */
    if (IfxGtm_Cmu_isFxClockEnabled(gtm) || (assumeEnabled != FALSE))
    {
        fxSelect = gtm->CMU.FXCLK.CTRL.B.FXCLK_SEL;

        if (fxSelect == 0u)
        {
            frequency = IfxGtm_Cmu_getGclkFrequency(gtm);
        }
        else if (fxSelect <= 8u)
        {
            frequency = IfxGtm_Cmu_getClkFrequency(gtm, (IfxGtm_Cmu_Clk)(fxSelect - 1u), assumeEnabled);
        }
        else
        {
            frequency = IfxGtm_Cmu_getGclkFrequency(gtm);
        }

        switch (clkIndex)
        {
        case IfxGtm_Cmu_Fxclk_0:
            frequency = frequency / 1;
            break;
        case IfxGtm_Cmu_Fxclk_1:
            frequency = frequency / 16;
            break;
        case IfxGtm_Cmu_Fxclk_2:
            frequency = frequency / 256;
            break;
        case IfxGtm_Cmu_Fxclk_3:
            frequency = frequency / 4096;
            break;
        case IfxGtm_Cmu_Fxclk_4:
            frequency = frequency / 65536;
            break;
        default:
            frequency = 0.0f;
            break;
        }
    }
    else
    {
    	/* Fixed clock generation is disabled and assumeEnabled is FALSE - return 0 */
        frequency = 0.0f;
    }

    return frequency;
}


float32 IfxGtm_Cmu_getGclkFrequency(Ifx_GTM *gtm)
{
    float32 N          = gtm->CMU.GCLK_DEN.B.GCLK_DEN;
    float32 Z          = gtm->CMU.GCLK_NUM.B.GCLK_NUM;
    float32 multiplier = N / Z;

    return IfxGtm_Cmu_getModuleFrequency(gtm) * multiplier;
}


float32 IfxGtm_Cmu_getModuleFrequency(Ifx_GTM *gtm)
{
	/* CMU module frequency is cluster 0 clock frequency */
    return IfxGtm_getClusterFrequency(gtm, IfxGtm_Cluster_0);
}


boolean IfxGtm_Cmu_isClkClockEnabled(Ifx_GTM *gtm, IfxGtm_Cmu_Clk clkIndex)
{
    return ((gtm->CMU.CLK_EN.U >> (2 * clkIndex)) & IFX_GTM_CMU_CLK_EN_EN_CLK0_MSK) == 0x3;
}


boolean IfxGtm_Cmu_isEclkClockEnabled(Ifx_GTM *gtm, IfxGtm_Cmu_Eclk clkIndex)
{
    return ((gtm->CMU.CLK_EN.U >> (2 * clkIndex + 16)) & IFX_GTM_CMU_CLK_EN_EN_CLK0_MSK) == 0x3;
}


boolean IfxGtm_Cmu_isFxClockEnabled(Ifx_GTM *gtm)
{
    return gtm->CMU.CLK_EN.B.EN_FXCLK == 0x3;
}


void IfxGtm_Cmu_selectClkInput(Ifx_GTM *gtm, IfxGtm_Cmu_Clk clkIndex, boolean useGlobal)
{
    switch (clkIndex)
    {
    case IfxGtm_Cmu_Clk_6:
        gtm->CMU.CLK[clkIndex].CTRL.B.CLK_SEL = useGlobal ? 0 : 1;
        break;
    case IfxGtm_Cmu_Clk_7:
        gtm->CMU.CLK[clkIndex].CTRL.B.CLK_SEL = useGlobal ? 0 : 1;
        break;
    default:
        break;
    }
}


void IfxGtm_Cmu_setClkFrequency(Ifx_GTM *gtm, IfxGtm_Cmu_Clk clkIndex, float32 frequency)
{
    float32 t   = (IfxGtm_Cmu_getGclkFrequency(gtm) / frequency) - 1;
    uint32  cnt = (uint32)t;

    if ((t - (float32)cnt) > 0.5f)
    {
    	/* Round to nearest */
        cnt++;
    }

    uint16 psw = IfxScuWdt_getCpuWatchdogPassword();
    /* Clearing the endinit protection */
    IfxScuWdt_clearCpuEndinit(psw);

    switch (clkIndex)
    {
    case IfxGtm_Cmu_Clk_0:
    case IfxGtm_Cmu_Clk_1:
    case IfxGtm_Cmu_Clk_2:
    case IfxGtm_Cmu_Clk_3:
    case IfxGtm_Cmu_Clk_4:
    case IfxGtm_Cmu_Clk_5:
        gtm->CMU.CLK[clkIndex].CTRL.B.CLK_CNT = cnt;
        break;
    case IfxGtm_Cmu_Clk_6:
        gtm->CMU.CLK[clkIndex].CTRL.B.CLK_CNT = cnt;
        break;
    case IfxGtm_Cmu_Clk_7:
        gtm->CMU.CLK[clkIndex].CTRL.B.CLK_CNT = cnt;
        break;
    default:
        break;
    }

    /* Setting the endinit protection back on */
    IfxScuWdt_setCpuEndinit(psw);
}


void IfxGtm_Cmu_setEclkFrequency(Ifx_GTM *gtm, IfxGtm_Cmu_Eclk clkIndex, float32 frequency)
{
    float32 f;
    float32 bestDistance = frequency;
    float32 fIn          = IfxGtm_Cmu_getGclkFrequency(gtm);
    uint32  z, n, nBest = 1, zBest = 1;
    float32 t;

    for (z = 1; z < 0xFFFFFF; z++)
    {
        boolean endLoop = FALSE;
        t = fIn / z;

        for (n = z; n > 0; n--)
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

    uint16 psw = IfxScuWdt_getCpuWatchdogPassword();
    /* Clearing the endinit protection */
    IfxScuWdt_clearCpuEndinit(psw);
    gtm->CMU.ECLK[clkIndex].NUM.B.ECLK_NUM = zBest;
    gtm->CMU.ECLK[clkIndex].NUM.B.ECLK_NUM = zBest; /* write twice to be sure */
    gtm->CMU.ECLK[clkIndex].DEN.B.ECLK_DEN = nBest;
    /* Setting the endinit protection back on */
    IfxScuWdt_setCpuEndinit(psw);
}


void IfxGtm_Cmu_setGclkFrequency(Ifx_GTM *gtm, float32 frequency)
{
    float32 f;
    float32 bestDistance = frequency;

    float32 fIn          = IfxGtm_Cmu_getModuleFrequency(gtm);
    uint32  z, n, nBest = 1, zBest = 1;
    float32 t;

#if 1

    for (z = 1; z < 0xFFFFFF; z++)
    {
        boolean endLoop = FALSE;
        t = fIn / z;

        for (n = z; n > 0; n--)
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

#else

    for (n = 1; n < 0xFFFFFF; n++)
    {
        float32 distance;
        /* get best z */
        z = floorf(frequency * n / fIn);
        t = fIn / n;

        /* lower value */
        f        = t * z;
        distance = fabsf(frequency - f);

        if (distance < bestDistance)
        {
            bestDistance = distance;
            nBest        = n;
            zBest        = z;
        }

        /* upper value */
        f        = t * (z + 1);
        distance = fabsf(frequency - f);

        if (distance < bestDistance)
        {
            bestDistance = distance;
            nBest        = n;
            zBest        = z;
        }

        if (bestDistance == 0.0f)
        {
            break;
        }
    }

#endif

    uint16 psw = IfxScuWdt_getCpuWatchdogPassword();
    /* Clearing the endinit protection */
    IfxScuWdt_clearCpuEndinit(psw);
    gtm->CMU.GCLK_NUM.B.GCLK_NUM = zBest;
    gtm->CMU.GCLK_NUM.B.GCLK_NUM = zBest;   /* write twice to be sure */
    gtm->CMU.GCLK_DEN.B.GCLK_DEN = nBest;
    /* Setting the endinit protection back on */
    IfxScuWdt_setCpuEndinit(psw);
}
#endif

#if defined (_TASKING_) || defined (_ghs_)
#pragma restore
#endif
