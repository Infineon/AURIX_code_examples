/**
 * \file IfxPsi5s_PinMap.h
 * \brief PSI5S  details
 * \ingroup IfxLld_Psi5s
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
 * \defgroup IfxLld_Psi5s_Pinmap Psi5s Pinmap Structure
 * \ingroup IfxLld_Psi5s
 */

#ifndef IFXPSI5S_PINMAP_H
#define IFXPSI5S_PINMAP_H 1

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include "Ifx_PinMap.h"
#include "IfxPsi5s_reg.h"
#include "Port/Std/IfxPort.h"

/******************************************************************************/
/*-----------------------------Data Structures--------------------------------*/
/******************************************************************************/

/** \brief
 */
typedef const struct
{
    Ifx_PSI5S        *module;       /**< \brief Base address */
    IfxPort_Pin       pin;          /**< \brief Port pin */
    IfxPort_OutputIdx select;       /**< \brief Port control code */
} IfxPsi5s_Clk_Out;

/** \brief
 */
typedef const struct
{
    Ifx_PSI5S  *module;       /**< \brief Base address */
    IfxPort_Pin pin;          /**< \brief Port pin */
    Ifx_RxSel   select;       /**< \brief Input multiplexer value */
} IfxPsi5s_Rx_In;

/** \brief
 */
typedef const struct
{
    Ifx_PSI5S        *module;       /**< \brief Base address */
    IfxPort_Pin       pin;          /**< \brief Port pin */
    IfxPort_OutputIdx select;       /**< \brief Port control code */
} IfxPsi5s_Tx_Out;

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#if defined(DEVICE_TC4DX)
#if defined(IFX_PIN_PACKAGE_BGA436_COM)
#include "TC4Dx/IfxPsi5s_PinMap_TC4Dx_BGA436_COM.h"
#elif defined(IFX_PIN_PACKAGE_BGA292_COM)
#include "TC4Dx/IfxPsi5s_PinMap_TC4Dx_BGA292_COM.h"
#endif

#elif defined(DEVICE_TC49XN)
#if defined(IFX_PIN_PACKAGE_BGA436_STD)
#include "TC49xN/IfxPsi5s_PinMap_TC49xN_BGA436_STD.h"
#elif defined(IFX_PIN_PACKAGE_BGA292_STD)
#include "TC49xN/IfxPsi5s_PinMap_TC49xN_BGA292_STD.h"
#endif

#elif defined(DEVICE_TC48XAA)
#if defined(IFX_PIN_PACKAGE_BGA436_COM)
#include "TC48xAA/IfxPsi5s_PinMap_TC48xAA_BGA436_COM.h"
#elif defined(IFX_PIN_PACKAGE_BGA292_COM)
#include "TC48xAA/IfxPsi5s_PinMap_TC48xAA_BGA292_COM.h"
#elif defined(IFX_PIN_PACKAGE_BGA292_STD)
#include "TC48xAA/IfxPsi5s_PinMap_TC48xAA_BGA292_STD.h"
#elif defined(IFX_PIN_PACKAGE_BGA224_STD)
#include "TC48xAA/IfxPsi5s_PinMap_TC48xAA_BGA224_STD.h"
#endif

#elif defined(DEVICE_TC48X)
#if defined(IFX_PIN_PACKAGE_BGA436_COM)
#include "TC48x/IfxPsi5s_PinMap_TC48x_BGA436_COM.h"
#elif defined(IFX_PIN_PACKAGE_BGA292_COM)
#include "TC48x/IfxPsi5s_PinMap_TC48x_BGA292_COM.h"
#elif defined(IFX_PIN_PACKAGE_BGA292_STD)
#include "TC48x/IfxPsi5s_PinMap_TC48x_BGA292_STD.h"
#elif defined(IFX_PIN_PACKAGE_BGA224_STD)
#include "TC48x/IfxPsi5s_PinMap_TC48x_BGA224_STD.h"
#endif

#elif defined(DEVICE_TC46X)
#if defined(IFX_PIN_PACKAGE_BGA436_STD)
#include "TC46x/IfxPsi5s_PinMap_TC46x_BGA436_STD.h"
#elif defined(IFX_PIN_PACKAGE_BGA292_STD)
#include "TC46x/IfxPsi5s_PinMap_TC46x_BGA292_STD.h"
#elif defined(IFX_PIN_PACKAGE_BGA224_STD)
#include "TC46x/IfxPsi5s_PinMap_TC46x_BGA224_STD.h"
#endif

#elif defined(DEVICE_TC4ZX)
#if defined(IFX_PIN_PACKAGE_BGA436_COM)
#include "TC4Zx/IfxPsi5s_PinMap_TC4Zx_BGA436_COM.h"
#elif defined(IFX_PIN_PACKAGE_BGA292_COM)
#include "TC4Zx/IfxPsi5s_PinMap_TC4Zx_BGA292_COM.h"
#endif

#endif /* #if defined(DEVICE_TC4DX) */

#endif /* IFXPSI5S_PINMAP_H */
