/**
 * \file IfxEgtm_Input.h
 * \brief EGTM INPUT details
 * \ingroup IfxLld_Egtm
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
 * \defgroup IfxLld_Egtm_Input_Usage How to use the Input Interface layer?
 * \ingroup IfxLld_Egtm_Input
 * \section IfxLld_Egtm_Input_Overview Overview
 *
 * This layers is used to select a peripheral signal as an input to TIM or DTM submodule.\n
 * E.g Adc to Tim, Adc to DtmAux, Canxl to Tim, etc.
 *
 * \defgroup IfxLld_Egtm_Input Input Interface
 * \ingroup IfxLld_Egtm
 * \defgroup IfxLld_Egtm_Input_TIM_connections TIM connection functions
 * \ingroup IfxLld_Egtm_Input
 * \defgroup IfxLld_Egtm_Input_DTMAUX_connections DTMAUX connection functions
 * \ingroup IfxLld_Egtm_Input
 */

#ifndef IFXEGTM_INPUT_H
#define IFXEGTM_INPUT_H 1

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include "_Impl/IfxEgtm_cfg.h"
#if !defined(IFX_ILLD_PPU_USAGE)
#include "Cpu/Std/IfxCpu_Intrinsics.h"
#endif
#if defined(IFX_ILLD_PPU_USAGE)
#include "Ppu/Std/IfxPpu_Intrinsics.h"
#endif
#include "IfxEgtm_bf.h"

/** \addtogroup IfxLld_Egtm_Input_TIM_connections
 * \{ */

/******************************************************************************/
/*-------------------------Global Function Prototypes-------------------------*/
/******************************************************************************/

/** \brief Select ADC signal as input to TIM submodule.
 *
 * \param[in] input   Input ADC signal
 *                    Range: \ref: IfxEgtm_AdcTimInput
 * \param[in] cluster TIM cluster number
 *                    Range: \ref: IfxEgtm_Tim
 * \param[in] channel TIM channel number
 *                    Range: \ref: IfxEgtm_Tim_Ch
 *
 * \retval TRUE on success. FALSE: Input cannot be connected to specified TIM channel in cluster
 */
IFX_EXTERN boolean IfxEgtm_Input_selectAdcTimInput(IfxEgtm_AdcTimInput input, IfxEgtm_Tim cluster, IfxEgtm_Tim_Ch channel);

/** \brief Select CAN signal as input to TIM submodule.
 *
 * \param[in] input   Input CAN signal
 *                    Range: \ref: IfxEgtm_CanTimInput
 * \param[in] cluster TIM cluster number
 *                    Range: \ref: IfxEgtm_Tim
 * \param[in] channel TIM channel number
 *                    Range: \ref: IfxEgtm_Tim_Ch
 *
 * \retval TRUE on success. FALSE: Input cannot be connected to specified TIM channel in cluster
 */
IFX_EXTERN boolean IfxEgtm_Input_selectCanTimInput(IfxEgtm_CanTimInput input, IfxEgtm_Tim cluster, IfxEgtm_Tim_Ch channel);

/** \brief Select CAN-XL signal as input to TIM submodule.
 *
 * \param[in] input   Input CAN-XL signal
 *                    Range: \ref: IfxEgtm_CanxlTimInput
 * \param[in] cluster TIM cluster number
 *                    Range: \ref: IfxEgtm_Tim
 * \param[in] channel TIM channel number
 *                    Range: \ref: IfxEgtm_Tim_Ch
 *
 * \retval TRUE on success. FALSE: Input cannot be connected to specified TIM channel in cluster
 */
IFX_EXTERN boolean IfxEgtm_Input_selectCanxlTimInput(IfxEgtm_CanxlTimInput input, IfxEgtm_Tim cluster, IfxEgtm_Tim_Ch channel);

#if IFXEGTM_INPUT_GETH_SIGNAL_IS_AVAILABLE
/** \brief Select GETH signal as input to TIM submodule.
 *
 * \param[in] input   Input GETH signal
 *                    Range: \ref: IfxEgtm_GethTimInput
 * \param[in] cluster TIM cluster number
 *                    Range: \ref: IfxEgtm_Tim
 * \param[in] channel TIM channel number
 *                    Range: \ref: IfxEgtm_Tim_Ch
 *
 * \retval TRUE on success. FALSE: Input cannot be connected to specified TIM channel in cluster
 */
IFX_EXTERN boolean IfxEgtm_Input_selectGethTimInput(IfxEgtm_GethTimInput input, IfxEgtm_Tim cluster, IfxEgtm_Tim_Ch channel);
#endif /* #if IFXEGTM_INPUT_GETH_SIGNAL_IS_AVAILABLE*/

#if IFXEGTM_INPUT_GPT12_SIGNAL_IS_AVAILABLE
/** \brief Select GPT12 signal as input to TIM submodule.
 *
 * \param[in] input   Input GPT12 signal
 *                    Range: \ref: IfxEgtm_Gpt12TimInput
 * \param[in] cluster TIM cluster number
 *                    Range: \ref: IfxEgtm_Tim
 * \param[in] channel TIM channel number
 *                    Range: \ref: IfxEgtm_Tim_Ch
 *
 * \retval TRUE on success. FALSE: Input cannot be connected to specified TIM channel in cluster
 */
IFX_EXTERN boolean IfxEgtm_Input_selectGpt12TimInput(IfxEgtm_Gpt12TimInput input, IfxEgtm_Tim cluster, IfxEgtm_Tim_Ch channel);
#endif /* #if IFXEGTM_INPUT_GPT12_SIGNAL_IS_AVAILABLE */

/** \brief Select LETH signal as input to TIM submodule.
 *
 * \param[in] input   Input LETH signal
 *                    Range: \ref: IfxEgtm_LethTimInput
 * \param[in] cluster TIM cluster number
 *                    Range: \ref: IfxEgtm_Tim
 * \param[in] channel TIM channel number
 *                    Range: \ref: IfxEgtm_Tim_Ch
 *
 * \retval TRUE on success. FALSE: Input cannot be connected to specified TIM channel in cluster
 */
IFX_EXTERN boolean IfxEgtm_Input_selectLethTimInput(IfxEgtm_LethTimInput input, IfxEgtm_Tim cluster, IfxEgtm_Tim_Ch channel);

/** \brief Select ERAY signal as input to TIM submodule.
 *
 * \param[in] input   Input ERAY signal
 *                    Range: \ref: IfxEgtm_ErayTimInput
 * \param[in] cluster TIM cluster number
 *                    Range: \ref: IfxEgtm_Tim
 * \param[in] channel TIM channel number
 *                    Range: \ref: IfxEgtm_Tim_Ch
 *
 * \retval TRUE on success. FALSE: Input cannot be connected to specified TIM channel in cluster
 */
IFX_EXTERN boolean IfxEgtm_Input_selectErayTimInput(IfxEgtm_ErayTimInput input, IfxEgtm_Tim cluster, IfxEgtm_Tim_Ch channel);

/** \brief Select PMS signal as input to TIM submodule.
 *
 * \param[in] input   Input PMS signal
 *                    Range: \ref: IfxEgtm_PmsTimInput
 * \param[in] cluster TIM cluster number
 *                    Range: \ref: IfxEgtm_Tim
 * \param[in] channel TIM channel number
 *                    Range: \ref: IfxEgtm_Tim_Ch
 *
 * \retval TRUE on success. FALSE: Input cannot be connected to specified TIM channel in cluster
 */
IFX_EXTERN boolean IfxEgtm_Input_selectPmsTimInput(IfxEgtm_PmsTimInput input, IfxEgtm_Tim cluster, IfxEgtm_Tim_Ch channel);

/** \brief Select SCU signal as input to TIM submodule.
 *
 * \param[in] input   Input SCU signal
 *                    Range: \ref: IfxEgtm_ScuTimInput
 * \param[in] cluster TIM cluster number
 *                    Range: \ref: IfxEgtm_Tim
 * \param[in] channel TIM channel number
 *                    Range: \ref: IfxEgtm_Tim_Ch
 *
 * \retval TRUE on success. FALSE: Input cannot be connected to specified TIM channel in cluster
 */
IFX_EXTERN boolean IfxEgtm_Input_selectScuTimInput(IfxEgtm_ScuTimInput input, IfxEgtm_Tim cluster, IfxEgtm_Tim_Ch channel);

/** \} */

/** \addtogroup IfxLld_Egtm_Input_DTMAUX_connections
 * \{ */

/******************************************************************************/
/*-------------------------Global Function Prototypes-------------------------*/
/******************************************************************************/

/** \brief Select ADC signal to be used as DTM_AUX_IN0/1
 *
 * \param[in] input       Input ADC signal
 *                        Range: \ref: IfxEgtm_AdcDtmAuxInput
 * \param[in] cdtm        CDTM cluster
 *                        Range: \ref: IfxEgtm_Cdtm
 * \param[in] dtm         DTM index
 *                        Range: \ref: IfxEgtm_Dtm
 * \param[in] dtmAuxInput Connect input signal to DTM_AUX_IN0 or DTM_AUX_IN1
 *                        Range: \ref: IfxEgtm_DtmAuxInput
 *
 * \retval TRUE on success. FALSE: Input cannot be connected to specified CDTM/DTM
 */
IFX_EXTERN boolean IfxEgtm_Input_selectAdcDtmAuxInput(IfxEgtm_AdcDtmAuxInput input, IfxEgtm_Cdtm cdtm, IfxEgtm_Dtm dtm, IfxEgtm_DtmAuxInput dtmAuxInput);

/** \} */

#endif /* IFXEGTM_INPUT_H */
