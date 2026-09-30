/**
 * \file IfxGtm_Input.c
 * \brief GTM INPUT details
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
#include "IfxGtm_Input.h"

/******************************************************************************/
/*-----------------------Private Function Prototypes--------------------------*/
/******************************************************************************/

/** \brief Select peripheral signal as input to TIM submodule
 * \param inputEntry Unique entry for peripheral input to be connected
 * \param inputTablePtr Pointer to input table for peripheral to be connected
 * \return TRUE on success. FALSE: Input cannot be connected to specified TIM channel in cluster
 */
IFX_STATIC boolean IfxGtm_Input_selectPeripheralTimInput(uint32 inputEntry, uint32 *inputTablePtr);

/** \brief Select peripheral signal as input to DTMAUX
 * \param inputEntry Unique entry for peripheral input to be connected
 * \param dtmAuxInput Connect input signal to DTM_AUX_IN0 or DTM_AUX_IN1
 * \param inputTablePtr Pointer to input table for peripheral to be connected
 * \return TRUE on success. FALSE: Input cannot be connected
 */
IFX_STATIC boolean IfxGtm_Input_selectPeripheralDtmAuxInput(uint32 inputEntry, IfxGtm_DtmAuxInput dtmAuxInput, uint32 *inputTablePtr);

/******************************************************************************/
/*-------------------------Function Implementations---------------------------*/
/******************************************************************************/

boolean IfxGtm_Input_selectAdcTimInput(IfxGtm_AdcTimInput input, IfxGtm_Tim cluster, IfxGtm_Tim_Ch channel)
{
    boolean result;
    uint32  inputEntry = IFXGTM_CFG_GETINPUTENTRY(cluster, channel, input, 0u);

    result = IfxGtm_Input_selectPeripheralTimInput(inputEntry, &IfxGtm_Cfg_AdcTimInputSel[0]);

    return result;
}


boolean IfxGtm_Input_selectCanTimInput(IfxGtm_CanTimInput input, IfxGtm_Tim cluster, IfxGtm_Tim_Ch channel)
{
    boolean result;
    uint32  inputEntry = IFXGTM_CFG_GETINPUTENTRY(cluster, channel, input, 0u);

    result = IfxGtm_Input_selectPeripheralTimInput(inputEntry, &IfxGtm_Cfg_CanTimInputSel[0]);

    return result;
}


boolean IfxGtm_Input_selectGpt12TimInput(IfxGtm_Gpt12TimInput input, IfxGtm_Tim cluster, IfxGtm_Tim_Ch channel)
{
    boolean result;
    uint32  inputEntry = IFXGTM_CFG_GETINPUTENTRY(cluster, channel, input, 0u);

    result = IfxGtm_Input_selectPeripheralTimInput(inputEntry, &IfxGtm_Cfg_Gpt12TimInputSel[0]);

    return result;
}


boolean IfxGtm_Input_selectErayTimInput(IfxGtm_ErayTimInput input, IfxGtm_Tim cluster, IfxGtm_Tim_Ch channel)
{
    boolean result;
    uint32  inputEntry = IFXGTM_CFG_GETINPUTENTRY(cluster, channel, input, 0u);

    result = IfxGtm_Input_selectPeripheralTimInput(inputEntry, &IfxGtm_Cfg_ErayTimInputSel[0]);

    return result;
}


boolean IfxGtm_Input_selectPmsTimInput(IfxGtm_PmsTimInput input, IfxGtm_Tim cluster, IfxGtm_Tim_Ch channel)
{
    boolean result;
    uint32  inputEntry = IFXGTM_CFG_GETINPUTENTRY(cluster, channel, input, 0u);

    result = IfxGtm_Input_selectPeripheralTimInput(inputEntry, &IfxGtm_Cfg_PmsTimInputSel[0]);

    return result;
}


boolean IfxGtm_Input_selectScuTimInput(IfxGtm_ScuTimInput input, IfxGtm_Tim cluster, IfxGtm_Tim_Ch channel)
{
    boolean result;
    uint32  inputEntry = IFXGTM_CFG_GETINPUTENTRY(cluster, channel, input, 0u);

    result = IfxGtm_Input_selectPeripheralTimInput(inputEntry, &IfxGtm_Cfg_ScuTimInputSel[0]);

    return result;
}


boolean IfxGtm_Input_selectAdcDtmAuxInput(IfxGtm_AdcDtmAuxInput input, IfxGtm_Cdtm cdtm, IfxGtm_Dtm dtm, IfxGtm_DtmAuxInput dtmAuxInput)
{
    boolean result;
    uint32  inputEntry = IFXGTM_CFG_GETINPUTENTRY(cdtm, dtm, input, 0u);

    result = IfxGtm_Input_selectPeripheralDtmAuxInput(inputEntry, dtmAuxInput, &IfxGtm_Cfg_AdcDtmAuxInputSel[0]);

    return result;
}


IFX_STATIC boolean IfxGtm_Input_selectPeripheralTimInput(uint32 inputEntry, uint32 *inputTablePtr)
{
    boolean result = FALSE;
    uint16  idx    = 0u;

    /* Loop through all table elements */
    for (idx = 1u; idx <= inputTablePtr[0]; idx++)
    {
        /* Check if combination is present in table */
        if ((inputTablePtr[idx] & 0xFFFFFF00u) == inputEntry)
        {
            result = TRUE;
            break;
        }
    }

    if (result == TRUE)
    {
        /* Extract cluster, channel number, and chxsel values */
        uint32 cluster = (inputEntry >> 24u) & 0xFu;
        uint32 channel = (inputEntry >> 16u) & 0xFu;
        uint32 chxsel  = inputTablePtr[idx] & IFX_GTM_TIMINSEL_CH0SEL_MSK;

        /* Calculate value and mask */
        uint32 shift = channel * IFX_GTM_TIMINSEL_CH0SEL_LEN;
        uint32 value = chxsel << shift;
        uint32 mask  = (uint32)IFX_GTM_TIMINSEL_CH0SEL_MSK << shift;

        /* Write to register */
        Ifx__ldmst(&MODULE_GTM.TIMINSEL[cluster].U, mask, value);
    }

    return result;
}


IFX_STATIC boolean IfxGtm_Input_selectPeripheralDtmAuxInput(uint32 inputEntry, IfxGtm_DtmAuxInput dtmAuxInput, uint32 *inputTablePtr)
{
    boolean result = FALSE;
    uint16  idx    = 0u;

    /* Loop through all table elements */
    for (idx = 1u; idx <= inputTablePtr[0]; idx++)
    {
        /* Check if combination is present in table */
        if ((inputTablePtr[idx] & 0xFFFFFF00u) == inputEntry)
        {
            result = TRUE;
            break;
        }
    }

    if (result == TRUE)
    {
        /* Extract CDTM, DTM number, and selx values */
        uint32 cdtm = (inputEntry >> 24u) & 0xFu;
        uint32 dtm  = (inputEntry >> 16u) & 0xFu;
        uint32 selx = inputTablePtr[idx] & IFX_GTM_DTMAUX_IN_SEL0_MSK;

        /* Calculate value and mask */
        uint32 shift = dtm * (IFX_GTM_DTMAUX_IN_SEL0_LEN + 1u);
        uint32 value = selx << shift;
        uint32 mask  = (uint32)IFX_GTM_DTMAUX_IN_SEL0_MSK << shift;

        /* Write to register */
        Ifx__ldmst(&MODULE_GTM.DTMAUX[cdtm].IN[dtmAuxInput].U, mask, value);
    }

    return result;
}

#endif /* #if defined(DEVICE_TC49XN) || defined(DEVICE_TC46X) || defined(DEVICE_TC4EX) */

#if defined (_TASKING_) || defined (_ghs_)
#pragma restore
#endif

