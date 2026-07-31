/**
 * \file IfxHsphy_Dll.h
 * \brief HSPHY DLL details
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
 * \defgroup IfxLld_Hsphy_Dll DLL
 * \ingroup IfxLld_Hsphy
 * \defgroup IfxLld_Hsphy_Dll_Enumerations Enumerations
 * \ingroup IfxLld_Hsphy_Dll
 * \defgroup IfxLld_Hsphy_Dll_Data Structures Data Structures
 * \ingroup IfxLld_Hsphy_Dll
 * \defgroup IfxLld_Hsphy_Dll_Config Variable Config Variable
 * \ingroup IfxLld_Hsphy_Dll
 * \defgroup IfxLld_Hsphy_Dll_Functions Functions
 * \ingroup IfxLld_Hsphy_Dll
 */

#ifndef IFXHSPHY_DLL_H
#define IFXHSPHY_DLL_H 1

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include "Hsphy/Std/IfxHsphy.h"

/** \addtogroup IfxLld_Hsphy_Dll_Functions
 * \{ */

/******************************************************************************/
/*-------------------------Global Function Prototypes-------------------------*/
/******************************************************************************/

/** \brief Xspi init API
 * \param[inout] hsphyRegPtr hsphy register pointer
 * \param[in] config Xspi config reference pointer
 * \retval TRUE on timeout error else FALSE.
 */
IFX_EXTERN boolean IfxHsphy_Dll_xspiInit(Ifx_HSPHY *hsphyRegPtr, IfxHsphy_Xspi_XspiCfg *config);

/** \brief rgmii init api
 * \param[inout] hsphyRegPtr hsphy register pointer
 * \param[in] config config for rgmii
 * \retval TRUE on timeout error else FALSE.
 */
IFX_EXTERN boolean IfxHsphy_Dll_rgmiiInit(Ifx_HSPHY *hsphyRegPtr, IfxHsphy_Geth_RgmiiCfg *config);

/** \brief DLL De-Init api
 * \param[inout] hsphyRegPtr hsphy register pointer
 * \retval None
 */
IFX_EXTERN void IfxHsphy_Dll_xspiDeInit(Ifx_HSPHY *hsphyRegPtr);

/** \} */

#endif /* IFXHSPHY_DLL_H */
