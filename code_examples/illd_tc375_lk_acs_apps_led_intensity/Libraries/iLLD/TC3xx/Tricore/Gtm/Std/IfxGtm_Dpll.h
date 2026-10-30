/**
 * \file IfxGtm_Dpll.h
 * \brief GTM  basic functionality
 * \ingroup IfxLld_Gtm
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
 * \defgroup IfxLld_Gtm_Std_Dpll Dpll Basic Functionality
 * \ingroup IfxLld_Gtm_Std
 * \defgroup IfxLld_Gtm_Std_Dpll_Basic_Functions DPLL Basic Functions
 * \ingroup IfxLld_Gtm_Std_Dpll
 */

#ifndef IFXGTM_DPLL_H
#define IFXGTM_DPLL_H 1

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include "_Impl/IfxGtm_cfg.h"

/** \addtogroup IfxLld_Gtm_Std_Dpll_Basic_Functions
 * \{ */

/******************************************************************************/
/*-------------------------Global Function Prototypes-------------------------*/
/******************************************************************************/

/**
 * \brief Dummy Function, returns 0.0F.
 *
 * \param[in] gtm   Pointer to the GTM module instance.
 * \param[in] index The Dpll subincrement index. Range: \ref IfxGtm_Dpll_SubInc
 *
 * \retval float32 The frequency value in Hz.
 *
 * \note The current implementation is a placeholder and always returns 0.0F.
 */
IFX_EXTERN float32 IfxGtm_Dpll_getSubIncFrequency(Ifx_GTM *gtm, IfxGtm_Dpll_SubInc index);

/** \} */

#endif /* IFXGTM_DPLL_H */
