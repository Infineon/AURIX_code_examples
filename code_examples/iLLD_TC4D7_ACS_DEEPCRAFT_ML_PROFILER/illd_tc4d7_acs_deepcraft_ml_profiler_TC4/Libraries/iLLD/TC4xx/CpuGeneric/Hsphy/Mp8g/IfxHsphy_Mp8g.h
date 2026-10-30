/**
 * \file IfxHsphy_Mp8g.h
 * \brief HSPHY MP8G details
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
 * \defgroup IfxLld_Hsphy_Mp8g MP8G
 * \ingroup IfxLld_Hsphy
 * \defgroup IfxLld_Hsphy_Mp8g_Enumerations Enumerations
 * \ingroup IfxLld_Hsphy_Mp8g
 * \defgroup IfxLld_Hsphy_Mp8g_Data Structures Data Structures
 * \ingroup IfxLld_Hsphy_Mp8g
 * \defgroup IfxLld_Hsphy_Mp8g_Config Variable Config Variable
 * \ingroup IfxLld_Hsphy_Mp8g
 * \defgroup IfxLld_Hsphy_Mp8g_Functions Functions
 * \ingroup IfxLld_Hsphy_Mp8g
 */

#ifndef IFXHSPHY_MP8G_H
#define IFXHSPHY_MP8G_H 1

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include "Hsphy/Std/IfxHsphy.h"

/** \addtogroup IfxLld_Hsphy_Mp8g_Functions
 * \{ */

/******************************************************************************/
/*-------------------------Global Function Prototypes-------------------------*/
/******************************************************************************/

/** \brief Resets the HSPHY module and waits for the reset to complete.
 * \param[inout] hsphyRegPtr Pointer to the HSPHY register structure.
 * \retval TRUE Indicates a timeout error occurred during the reset process, else FALSE.
 */
IFX_EXTERN boolean IfxHsphy_Mp8g_resetModule(Ifx_HSPHY *hsphyRegPtr);

/** \brief Sets the reference clock selection for the specified PHY device.
 * \param[inout] hsphyRegPtr Pointer to the HSPHY register structure.
 * \param[in] phyIndex PHY index. Range \ref IfxHsphy_PhyIndex
 * \param[in] device The target device type for which the reference clock is being set. Range \ref IfxHsphy_TrgtDevice
 * \retval TRUE The reference clock selection was successfully configured.
 */
IFX_EXTERN boolean IfxHsphy_Mp8g_setPhyRefClockSel(Ifx_HSPHY *hsphyRegPtr, IfxHsphy_PhyIndex phyIndex, IfxHsphy_TrgtDevice device);

/** \brief Select the function of operation
 * \param[inout] hsphyRegPtr Pointer to the HSPHY register structure.
 * \param[in] phyIndex PHY index. range \ref IfxHsphy_PhyIndex
 * \param[in] device Target device type to configure the HSPHY module for. Range \ref IfxHsphy_TrgtDevice
 * \retval TRUE if Configuration was successful else FALSE.
 */
IFX_EXTERN boolean IfxHsphy_Mp8g_selFunction(Ifx_HSPHY *hsphyRegPtr, IfxHsphy_PhyIndex phyIndex, IfxHsphy_TrgtDevice device);

/** \brief Check if the PHY is ready after reset
 * \param[in] hsphyRegPtr Pointer to the HSPHY register structure.
 * \param[in] phyIndex PHY index. Range \ref IfxHsphy_PhyIndex
 * \retval TRUE if the PHY is ready	else FALSE
 */
IFX_EXTERN boolean IfxHsphy_Mp8g_isPhyReady(Ifx_HSPHY *hsphyRegPtr, IfxHsphy_PhyIndex phyIndex);

/** \brief Check if the external loading of the application into SRAM is complete
 * \param[inout] hsphyRegPtr Pointer to the HSPHY register structure.
 * \param[in] phyIndex PHY index. Range \ref IfxHsphy_PhyIndex
 * \retval TRUE ifthe application SRAM loading complete, else FALSE
 */
IFX_EXTERN boolean IfxHsphy_Mp8g_setExtLdDone(Ifx_HSPHY *hsphyRegPtr, IfxHsphy_PhyIndex phyIndex);

/** \brief Power Down PHY
 * \param[inout] hsphySFR HPSHY pointer
 * \param[in] phyIndex PHY index. Range \ref IfxHsphy_PhyIndex
 * \param[in] phyPowerMode 0: PHY power up 1: PHY power down. Range \ref IfxHsphy_PhyPowerMode
 * \retval None
 */
IFX_EXTERN void IfxHsphy_Mp8g_PowerDownReset(Ifx_HSPHY *hsphySFR, IfxHsphy_PhyIndex phyIndex, IfxHsphy_PhyPowerMode phyPowerMode);

/** \} */

#endif /* IFXHSPHY_MP8G_H */
