/**
 * \file IfxHsphy_EthIO.h
 * \brief HSPHY ETHIO details
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
 * \defgroup IfxLld_Hsphy_EthIO ETHIO
 * \ingroup IfxLld_Hsphy
 * \defgroup IfxLld_Hsphy_EthIO_Enumerations Enumerations
 * \ingroup IfxLld_Hsphy_EthIO
 * \defgroup IfxLld_Hsphy_EthIO_Data Structures Data Structures
 * \ingroup IfxLld_Hsphy_EthIO
 * \defgroup IfxLld_Hsphy_EthIO_Config Variable Config Variable
 * \ingroup IfxLld_Hsphy_EthIO
 * \defgroup IfxLld_Hsphy_EthIO_Functions Functions
 * \ingroup IfxLld_Hsphy_EthIO
 */

#ifndef IFXHSPHY_ETHIO_H
#define IFXHSPHY_ETHIO_H 1

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include "Hsphy/Std/IfxHsphy.h"

/** \addtogroup IfxLld_Hsphy_EthIO_Functions
 * \{ */

/******************************************************************************/
/*-------------------------Global Function Prototypes-------------------------*/
/******************************************************************************/

#if defined(DEVICE_TC4DX) || defined(DEVICE_TC48XAA) || defined(DEVICE_TC48X) || defined(DEVICE_TC44X) || defined(DEVICE_TC4ZX)
/** \brief Ethernet interface mode selection
 * \param[inout] hsphySFR HSPHY pointer
 * \param[in] ethIndex Index references to PHYs. Range \ref IfxHsphy_EthIndex
 * \param[in] ethCtrlExtPhySel ETH speed selection. Range \ref IfxHsphy_EthCtrlExtPhySel
 * \param[in] ethPort16 TRUE Enables PORT 16, FALSE Disable PORT 16. Refer CMNCFG.B.FSR
 * \retval None
 */
IFX_EXTERN void IfxHsphy_EthIO_interfaceSelect(Ifx_HSPHY *hsphySFR, IfxHsphy_EthIndex ethIndex, IfxHsphy_EthCtrlExtPhySel ethCtrlExtPhySel, boolean ethPort16);

#else

/** \brief Ethernet interface mode selection
 * \param[inout] hsphyRegPtr HSPHY pointer
 * \param[in] phyIndex Index references to PHYs. Range \ref IfxHsphy_PhyIndex
 * \param[in] device Configure the device types. Range \ref IfxHsphy_TrgtDevice
 * \retval TRUE Error in selection of phy, FALSE selection of phy Success
 */
IFX_EXTERN boolean IfxHsphy_EthIO_interfaceSelect(Ifx_HSPHY *hsphyRegPtr, IfxHsphy_PhyIndex phyIndex, IfxHsphy_TrgtDevice device);
#endif /* #if defined(DEVICE_TC4DX) || defined(DEVICE_TC48XAA) || defined(DEVICE_TC48X) || defined(DEVICE_TC44X) || defined(DEVICE_TC4ZX) */

/** \} */

#endif /* IFXHSPHY_ETHIO_H */
