/**
 * \file IfxGtm_Dtm.c
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
#include "IfxGtm_Dtm.h"

/******************************************************************************/
/*-------------------------Function Implementations---------------------------*/
/******************************************************************************/

Ifx_GTM_CDTM_DTM *IfxGtm_Dtm_getDtmPointer(Ifx_GTM *gtm, IfxGtm_Cdtm cdtmIndex, IfxGtm_Dtm dtmIndex)
{
    Ifx_GTM_CDTM_DTM *dtmSFR;

    if ((cdtmIndex > IfxGtm_Cdtm_none) && (cdtmIndex <= IfxGtm_Cdtm_6))
    {
    	/* Get the base address of the specified DTM */
        dtmSFR = &(gtm->CDTM[cdtmIndex].DTM[dtmIndex]);
    }
    else
    {
    	/* NULL_PTR if the indices are out of range */
        dtmSFR = NULL_PTR;
    }

    return dtmSFR;
}


float32 IfxGtm_Dtm_getClockFrequency(Ifx_GTM *gtm, IfxGtm_Cdtm cdtmIndex, IfxGtm_Dtm dtmIndex)
{
    Ifx_GTM_CDTM_DTM *dtm;
    float32           frequency = 0.0f;

    /* Get the pointer to the DTM base address */
    dtm = IfxGtm_Dtm_getDtmPointer(gtm, cdtmIndex, dtmIndex);

    if (dtm != NULL_PTR)
    {
    	/* Get the clock source of the DTM object */
        IfxGtm_Dtm_ClockSource clockSource;
        clockSource = IfxGtm_Dtm_getClockSource(dtm);

        if (dtmIndex <= IfxGtm_Dtm_3)
        {
        	/* Connected to TOMs */
            switch (clockSource)
            {
            case IfxGtm_Dtm_ClockSource_systemClock:
                frequency = IfxScuCcu_getGtmFrequency();
                break;
            case IfxGtm_Dtm_ClockSource_cmuClock0:
                frequency = IfxGtm_Cmu_getClkFrequency(gtm, IfxGtm_Cmu_Clk_0, TRUE);
                break;
            case IfxGtm_Dtm_ClockSource_cmuClock1:
                frequency = IfxGtm_Cmu_getFxClkFrequency(gtm, IfxGtm_Cmu_Fxclk_0, TRUE);
                break;
            case IfxGtm_Dtm_ClockSource_cmuClock2:
                frequency = IfxGtm_Cmu_getFxClkFrequency(gtm, IfxGtm_Cmu_Fxclk_1, TRUE);
                break;
            default:
                break;
            }
        }
        else
        {
        	/* Connected to ATOMs */
            switch (clockSource)
            {
            case IfxGtm_Dtm_ClockSource_systemClock:
                frequency = IfxScuCcu_getGtmFrequency();
                break;
            case IfxGtm_Dtm_ClockSource_cmuClock0:
                frequency = IfxGtm_Cmu_getClkFrequency(gtm, IfxGtm_Cmu_Clk_0, TRUE);
                break;
            case IfxGtm_Dtm_ClockSource_cmuClock1:
                frequency = IfxGtm_Cmu_getClkFrequency(gtm, IfxGtm_Cmu_Clk_1, TRUE);
                break;
            case IfxGtm_Dtm_ClockSource_cmuClock2:
                frequency = IfxGtm_Cmu_getClkFrequency(gtm, IfxGtm_Cmu_Clk_2, TRUE);
                break;
            default:
                break;
            }
        }
    }

    return frequency;
}
#endif

#if defined (_TASKING_) || defined (_ghs_)
#pragma restore
#endif
