/**
 * \file IfxHsphy_Xpcs.h
 * \brief HSPHY XPCS details
 * \ingroup IfxLld_Hsphy
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
 * \defgroup IfxLld_Hsphy_Xpcs XPCS
 * \ingroup IfxLld_Hsphy
 * \defgroup IfxLld_Hsphy_Xpcs_Enumerations Enumerations
 * \ingroup IfxLld_Hsphy_Xpcs
 * \defgroup IfxLld_Hsphy_Xpcs_Data Structures Data Structures
 * \ingroup IfxLld_Hsphy_Xpcs
 * \defgroup IfxLld_Hsphy_Xpcs_Config Variable Config Variable
 * \ingroup IfxLld_Hsphy_Xpcs
 * \defgroup IfxLld_Hsphy_Xpcs_Functions Functions
 * \ingroup IfxLld_Hsphy_Xpcs
 */

#ifndef IFXHSPHY_XPCS_H
#define IFXHSPHY_XPCS_H 1

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include "Hsphy/Std/IfxHsphy.h"

/** \addtogroup IfxLld_Hsphy_Xpcs_Functions
 * \{ */

/******************************************************************************/
/*-------------------------Global Function Prototypes-------------------------*/
/******************************************************************************/

/** \brief Initialize XPCS data path for the specified XPCS instance.
 * \param[inout] hsphyRegPtr Pointer to the HSPHY register structure.
 * \param[in] xpcsIndex xpcsIndex XPCS index, Range \ref IfxHsphy_XpcsIndex
 * \retval TRUE Timeout error occurred during initialization else FALSE.
 */
IFX_EXTERN boolean IfxHsphy_Xpcs_sgmiiDataPathInit(Ifx_HSPHY *hsphyRegPtr, IfxHsphy_XpcsIndex xpcsIndex);

/** \} */

/******************************************************************************/
/*-------------------------Global Function Prototypes-------------------------*/
/******************************************************************************/

/** \brief Resets the xpcs
 * \param[inout] hsphyRegPtr HPSHY register pointer
 * \param[in] xpcs Target device id. Range \ref IfxHsphy_GethXpcsParams or \ref IfxHsphy_XpcsParams
 * \retval TRUE if time out error occurs else FALSE
 */
#if IFXHSPHY_IS_GETH_AVAILABLE
IFX_EXTERN boolean IfxHsphy_Xpcs_reset(Ifx_HSPHY *hsphyRegPtr, const IfxHsphy_GethXpcsParams *xpcs);
#else 
IFX_EXTERN boolean IfxHsphy_Xpcs_reset(Ifx_HSPHY *hsphyRegPtr, const IfxHsphy_XpcsParams *xpcs);
#endif /* #if IFXHSPHY_IS_GETH_AVAILABLE */

/** \brief API for configuring the speed selected
 * \param[inout] hsphyRegPtr HPSHY register pointer
 * \param[in] trgtSpeed target device speed selected. Range \ref IfxHsphy_TrgtDeviceSpeed
 * \param[in] xpcs Target device id
 * \retval the status as success/ time out /invalid config error. Range \ref IfxHsphy_SgmiiSpeedConfigStatus or \ref IfxHsphy_GethSgmiiSpeedConfigStatus
 */
#if IFXHSPHY_IS_GETH_AVAILABLE
IFX_EXTERN IfxHsphy_Geth_SgmiiSpeedConfigStatus IfxHsphy_Xpcs_setSgmiiSpeedMode(Ifx_HSPHY *hsphyRegPtr, IfxHsphy_TrgtDeviceSpeed trgtSpeed, const IfxHsphy_GethXpcsParams *xpcs); 
#else 
IFX_EXTERN IfxHsphy_SgmiiSpeedConfigStatus IfxHsphy_Xpcs_setSgmiiSpeedMode(Ifx_HSPHY *hsphyRegPtr, IfxHsphy_TrgtDeviceSpeed trgtSpeed, const IfxHsphy_XpcsParams *xpcs);
#endif /* #if IFXHSPHY_IS_GETH_AVAILABLE */

#if IFXHSPHY_IS_PADINTERFACE_USXSGMII_AVAILABLE
/** \brief API for configuring the speed selected
 * \param[inout] hsphyRegPtr hsphy register pointer
 * \param[in] trgtSpeed target device speed selected. Range \ref IfxHsphy_TrgtDeviceSpeed
 * \param[in] xpcs xpcs reference
 * \retval returns TRUE if time out error occurs, else FALSE.
 */
IFX_EXTERN boolean IfxHsphy_Xpcs_setUsxgmiiSpeedMode(Ifx_HSPHY *hsphyRegPtr, IfxHsphy_TrgtDeviceSpeed trgtSpeed, const IfxHsphy_GethXpcsParams *xpcs);
#endif /* #if IFXHSPHY_IS_PADINTERFACE_USXSGMII_AVAILABLE */

#endif /* IFXHSPHY_XPCS_H */
