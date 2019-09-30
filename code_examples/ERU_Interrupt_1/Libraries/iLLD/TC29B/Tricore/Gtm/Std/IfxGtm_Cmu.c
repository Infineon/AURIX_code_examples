/**
 * \file IfxGtm_Cmu.c
 * \brief GTM  basic functionality
 *
 * \version iLLD_1_0_1_9_0
 * \copyright Copyright (c) 2018 Infineon Technologies AG. All rights reserved.
 *
 *
 *                                 IMPORTANT NOTICE
 *
 *
 * Infineon Technologies AG (Infineon) is supplying this file for use
 * exclusively with Infineon's microcontroller products. This file can be freely
 * distributed within development tools that are supporting such microcontroller
 * products.
 *
 * THIS SOFTWARE IS PROVIDED "AS IS".  NO WARRANTIES, WHETHER EXPRESS, IMPLIED
 * OR STATUTORY, INCLUDING, BUT NOT LIMITED TO, IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE APPLY TO THIS SOFTWARE.
 * INFINEON SHALL NOT, IN ANY CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL,
 * OR CONSEQUENTIAL DAMAGES, FOR ANY REASON WHATSOEVER.
 *
 */

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

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
            frequency = IfxGtm_Cmu_getGclkFrequency(gtm) / (gtm->CMU.CLK0_5[clkIndex].CTRL.B.CLK_CNT + 1);
            break;
        case IfxGtm_Cmu_Clk_6:

            if (gtm->CMU.CLK_6.CTRL.B.CLK6_SEL == 0)
            {
                frequency = IfxGtm_Cmu_getGclkFrequency(gtm) / (gtm->CMU.CLK_6.CTRL.B.CLK_CNT + 1);
            }
            else
            {
                frequency = IfxGtm_Dpll_getSubIncFrequency(gtm, IfxGtm_Dpll_SubInc_2);
            }

            break;
        case IfxGtm_Cmu_Clk_7:

            if (gtm->CMU.CLK_7.CTRL.B.CLK7_SEL == 0)
            {
                frequency = IfxGtm_Cmu_getGclkFrequency(gtm) / (gtm->CMU.CLK_7.CTRL.B.CLK_CNT + 1);
            }
            else
            {
                frequency = IfxGtm_Dpll_getSubIncFrequency(gtm, IfxGtm_Dpll_SubInc_1);
            }

            break;
        default:
            frequency = 0.0;
            break;
        }
    }
    else
    {
        frequency = 0.0;
    }

    return frequency;
}


float32 IfxGtm_Cmu_getEclkFrequency(Ifx_GTM *gtm, IfxGtm_Cmu_Eclk clkIndex, boolean assumeEnabled)
{
    float32 frequency;

    if (IfxGtm_Cmu_isEclkClockEnabled(gtm, clkIndex) || (assumeEnabled != FALSE))
    {
        float32 Z          = gtm->CMU.ECLK[clkIndex].NUM.B.ECLK_NUM;
        float32 N          = gtm->CMU.ECLK[clkIndex].DEN.B.ECLK_DEN;
        float32 multiplier = N / Z / 2;
        frequency = IfxGtm_Cmu_getGclkFrequency(gtm) * multiplier;
    }
    else
    {
        frequency = 0.0;
    }

    return frequency;
}


float32 IfxGtm_Cmu_getFxClkFrequency(Ifx_GTM *gtm, IfxGtm_Cmu_Fxclk clkIndex, boolean assumeEnabled)
{
    float32 frequency;
    uint8   fxSelect;

    if (IfxGtm_Cmu_isFxClockEnabled(gtm) || (assumeEnabled != FALSE))
    {
        fxSelect = gtm->CMU.FXCLK.CTRL.B.FXCLK_SEL;

        if (fxSelect == 0)
        {
            frequency = IfxGtm_Cmu_getGclkFrequency(gtm);
        }
        else if (fxSelect <= 6)
        {
            frequency = IfxGtm_Cmu_getClkFrequency(gtm, IfxGtm_Cmu_Clk_5, assumeEnabled);
        }
        else if (fxSelect == 7)
        {
            frequency = IfxGtm_Cmu_getClkFrequency(gtm, IfxGtm_Cmu_Clk_6, assumeEnabled);
        }
        else if (fxSelect == 8)
        {
            frequency = IfxGtm_Cmu_getClkFrequency(gtm, IfxGtm_Cmu_Clk_7, assumeEnabled);
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
            frequency = 0.0;
            break;
        }
    }
    else
    {
        frequency = 0.0;
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
    return IfxGtm_getSysClkFrequency();
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
    /* FIXME is endinit required? */
    switch (clkIndex)
    {
    case IfxGtm_Cmu_Clk_6:
        gtm->CMU.CLK_6.CTRL.B.CLK6_SEL = useGlobal ? 0 : 1;
        break;
    case IfxGtm_Cmu_Clk_7:
        gtm->CMU.CLK_7.CTRL.B.CLK7_SEL = useGlobal ? 0 : 1;
        break;
    default:
        break;
    }
}


void IfxGtm_Cmu_setClkFrequency(Ifx_GTM *gtm, IfxGtm_Cmu_Clk clkIndex, float32 frequency)
{
    float32 t   = (IfxGtm_Cmu_getGclkFrequency(gtm) / frequency) - 1;
    uint32  cnt = (uint32)t;

    if ((t - (float32)cnt) > 0.5)
    {                           /* Round to nearest */
        cnt++;
    }

    uint16 psw = IfxScuWdt_getCpuWatchdogPassword();
    IfxScuWdt_clearCpuEndinit(psw);     /* FIXME is this required ? */

    switch (clkIndex)
    {
    case IfxGtm_Cmu_Clk_0:
    case IfxGtm_Cmu_Clk_1:
    case IfxGtm_Cmu_Clk_2:
    case IfxGtm_Cmu_Clk_3:
    case IfxGtm_Cmu_Clk_4:
    case IfxGtm_Cmu_Clk_5:
        gtm->CMU.CLK0_5[clkIndex].CTRL.B.CLK_CNT = cnt;
        break;
    case IfxGtm_Cmu_Clk_6:
        gtm->CMU.CLK_6.CTRL.B.CLK_CNT = cnt;
        break;
    case IfxGtm_Cmu_Clk_7:
        gtm->CMU.CLK_7.CTRL.B.CLK_CNT = cnt;
        break;
    default:
        break;
    }

    IfxScuWdt_setCpuEndinit(psw);
}


void IfxGtm_Cmu_setEclkFrequency(Ifx_GTM *gtm, IfxGtm_Cmu_Eclk clkIndex, float32 frequency)
{
    float32 f;
    float32 bestDistance = frequency;
    float32 fIn          = IfxGtm_Cmu_getGclkFrequency(gtm) * 2;
    uint32  z, n, nBest = 1, zBest = 1;
    float32 t;

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

            if (bestDistance < 0.1)
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
    IfxScuWdt_clearCpuEndinit(psw);                 /* FIXME is this required ? */
    gtm->CMU.ECLK[clkIndex].NUM.B.ECLK_NUM = zBest;
    gtm->CMU.ECLK[clkIndex].NUM.B.ECLK_NUM = zBest; /* write twice to be sure */
    gtm->CMU.ECLK[clkIndex].DEN.B.ECLK_DEN = nBest;
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

            if (bestDistance < 0.1)
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

        if (bestDistance == 0.0)
        {
            break;
        }
    }

#endif

    uint16 psw = IfxScuWdt_getCpuWatchdogPassword();
    IfxScuWdt_clearCpuEndinit(psw);         /* FIXME is this required ? */
    gtm->CMU.GCLK_NUM.B.GCLK_NUM = zBest;
    gtm->CMU.GCLK_NUM.B.GCLK_NUM = zBest;   /* write twice to be sure */
    gtm->CMU.GCLK_DEN.B.GCLK_DEN = nBest;
    IfxScuWdt_setCpuEndinit(psw);
}
