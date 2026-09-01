/**
 * \file IfxGtm_Input.h
 * \brief GTM INPUT details
 * \ingroup IfxLld_Gtm
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
 * \defgroup IfxLld_Gtm_Input INPUT
 * \ingroup IfxLld_Gtm
 */

#ifndef IFXGTM_INPUT_H
#define IFXGTM_INPUT_H 1

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include "_Impl/IfxGtm_cfg.h"
#if !defined(IFX_ILLD_PPU_USAGE)
#include "Cpu/Std/IfxCpu_Intrinsics.h"
#endif
#if defined(IFX_ILLD_PPU_USAGE)
#include "Ppu/Std/IfxPpu_Intrinsics.h"
#endif
#include "IfxGtm_bf.h"

/******************************************************************************/
/*-------------------------Global Function Prototypes-------------------------*/
/******************************************************************************/

/** \brief Select ADC signal as input to TIM submodule.
 *
 * \param[in] input   Input ADC signal. Range: \ref IfxGtm_AdcTimInput.
 * \param[in] cluster TIM cluster number. Range: \ref IfxGtm_Tim.
 * \param[in] channel TIM channel number. Range: \ref IfxGtm_Tim_Ch.
 *
 * \retval TRUE on success. FALSE: Input cannot be connected to specified TIM channel in cluster.
 */
IFX_EXTERN boolean IfxGtm_Input_selectAdcTimInput(IfxGtm_AdcTimInput input, IfxGtm_Tim cluster, IfxGtm_Tim_Ch channel);

/** \brief Select CAN signal as input to TIM submodule.
 *
 * \param[in] input   Input CAN signal. Range: \ref IfxGtm_CanTimInput.
 * \param[in] cluster TIM cluster number. Range: \ref IfxGtm_Tim.
 * \param[in] channel TIM channel number. Range: \ref IfxGtm_Tim_Ch.
 *
 * \retval TRUE on success. FALSE: Input cannot be connected to specified TIM channel in cluster.
 */
IFX_EXTERN boolean IfxGtm_Input_selectCanTimInput(IfxGtm_CanTimInput input, IfxGtm_Tim cluster, IfxGtm_Tim_Ch channel);

/** \brief Select GPT12 signal as input to TIM submodule.
 *
 * \param[in] input   Input GPT12 signal. Range: \ref IfxGtm_Gpt12TimInput.
 * \param[in] cluster TIM cluster number. Range: \ref IfxGtm_Tim.
 * \param[in] channel TIM channel number. Range: \ref IfxGtm_Tim_Ch.
 *
 * \retval TRUE on success. FALSE: Input cannot be connected to specified TIM channel in cluster.
 */
IFX_EXTERN boolean IfxGtm_Input_selectGpt12TimInput(IfxGtm_Gpt12TimInput input, IfxGtm_Tim cluster, IfxGtm_Tim_Ch channel);

/** \brief Select ERAY signal as input to TIM submodule.
 *
 * \param[in] input   Input ERAY signal. Range: \ref IfxGtm_ErayTimInput.
 * \param[in] cluster TIM cluster number. Range: \ref IfxGtm_Tim.
 * \param[in] channel TIM channel number. Range: \ref IfxGtm_Tim_Ch.
 *
 * \retval TRUE on success. FALSE: Input cannot be connected to specified TIM channel in cluster.
 */
IFX_EXTERN boolean IfxGtm_Input_selectErayTimInput(IfxGtm_ErayTimInput input, IfxGtm_Tim cluster, IfxGtm_Tim_Ch channel);

/** \brief Select PMS signal as input to TIM submodule.
 *
 * \param[in] input   Input PMS signal. Range: \ref IfxGtm_PmsTimInput.
 * \param[in] cluster TIM cluster number. Range: \ref IfxGtm_Tim.
 * \param[in] channel TIM channel number. Range: \ref IfxGtm_Tim_Ch.
 *
 * \retval TRUE on success. FALSE: Input cannot be connected to specified TIM channel in cluster.
 */
IFX_EXTERN boolean IfxGtm_Input_selectPmsTimInput(IfxGtm_PmsTimInput input, IfxGtm_Tim cluster, IfxGtm_Tim_Ch channel);

/** \brief Select SCU signal as input to TIM submodule.
 *
 * \param[in] input   Input SCU signal. Range: \ref IfxGtm_ScuTimInput.
 * \param[in] cluster TIM cluster number. Range: \ref IfxGtm_Tim.
 * \param[in] channel TIM channel number. Range: \ref IfxGtm_Tim_Ch.
 *
 * \retval TRUE on success. FALSE: Input cannot be connected to specified TIM channel in cluster.
 */
IFX_EXTERN boolean IfxGtm_Input_selectScuTimInput(IfxGtm_ScuTimInput input, IfxGtm_Tim cluster, IfxGtm_Tim_Ch channel);

/** \brief Select ADC signal to be used as DTM_AUX_IN0/1.
 *
 * \param[in] input       Input ADC signal. Range: \ref IfxGtm_AdcDtmAuxInput.
 * \param[in] cdtm        CDTM cluster. Range: \ref IfxGtm_Cdtm.
 * \param[in] dtm         DTM index. Range: \ref IfxGtm_Dtm.
 * \param[in] dtmAuxInput Connect input signal to DTM_AUX_IN0 or DTM_AUX_IN1. Range: \ref IfxGtm_DtmAuxInput.
 *
 * \retval TRUE on success. FALSE: Input cannot be connected to specified CDTM/DTM
 */
IFX_EXTERN boolean IfxGtm_Input_selectAdcDtmAuxInput(IfxGtm_AdcDtmAuxInput input, IfxGtm_Cdtm cdtm, IfxGtm_Dtm dtm, IfxGtm_DtmAuxInput dtmAuxInput);
#endif /* IFXGTM_INPUT_H */
