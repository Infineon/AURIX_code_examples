/**
 * \file IfxScu_PinMap.h
 * \brief SCU  details
 * \ingroup IfxLld_Scu
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
 * \defgroup IfxLld_Scu_Pinmap Scu Pinmap Structure
 * \ingroup IfxLld_Scu
 */

#ifndef IFXSCU_PINMAP_H
#define IFXSCU_PINMAP_H 1

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include "Ifx_PinMap.h"
#include "IfxScu_reg.h"
#include "Port/Std/IfxPort.h"

/******************************************************************************/
/*-----------------------------Data Structures--------------------------------*/
/******************************************************************************/

/** \brief
 */
typedef const struct
{
    Ifx_SCU    *module;          /**< \brief Base address */
    uint8       channelId;       /**< \brief ERU Channel ID */
    IfxPort_Pin pin;             /**< \brief Port pin */
    Ifx_RxSel   select;          /**< \brief Input multiplexer value */
} IfxScu_Req_In;

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#if defined(DEVICE_TC4DX)
#if defined(IFX_PIN_PACKAGE_BGA436_COM)
#include "TC4Dx/IfxScu_PinMap_TC4Dx_BGA436_COM.h"
#elif defined(IFX_PIN_PACKAGE_BGA292_COM)
#include "TC4Dx/IfxScu_PinMap_TC4Dx_BGA292_COM.h"
#endif

#elif defined(DEVICE_TC49XN)
#if defined(IFX_PIN_PACKAGE_BGA436_STD)
#include "TC49xN/IfxScu_PinMap_TC49xN_BGA436_STD.h"
#elif defined(IFX_PIN_PACKAGE_BGA292_STD)
#include "TC49xN/IfxScu_PinMap_TC49xN_BGA292_STD.h"
#endif

#elif defined(DEVICE_TC48XAA)
#if defined(IFX_PIN_PACKAGE_BGA436_COM)
#include "TC48xAA/IfxScu_PinMap_TC48xAA_BGA436_COM.h"
#elif defined(IFX_PIN_PACKAGE_BGA292_COM)
#include "TC48xAA/IfxScu_PinMap_TC48xAA_BGA292_COM.h"
#elif defined(IFX_PIN_PACKAGE_BGA292_STD)
#include "TC48xAA/IfxScu_PinMap_TC48xAA_BGA292_STD.h"
#elif defined(IFX_PIN_PACKAGE_BGA224_STD)
#include "TC48xAA/IfxScu_PinMap_TC48xAA_BGA224_STD.h"
#endif

#elif defined(DEVICE_TC48X)
#if defined(IFX_PIN_PACKAGE_BGA436_COM)
#include "TC48x/IfxScu_PinMap_TC48x_BGA436_COM.h"
#elif defined(IFX_PIN_PACKAGE_BGA292_COM)
#include "TC48x/IfxScu_PinMap_TC48x_BGA292_COM.h"
#elif defined(IFX_PIN_PACKAGE_BGA292_STD)
#include "TC48x/IfxScu_PinMap_TC48x_BGA292_STD.h"
#elif defined(IFX_PIN_PACKAGE_BGA224_STD)
#include "TC48x/IfxScu_PinMap_TC48x_BGA224_STD.h"
#endif

#elif defined(DEVICE_TC46X)
#if defined(IFX_PIN_PACKAGE_BGA436_STD)
#include "TC46x/IfxScu_PinMap_TC46x_BGA436_STD.h"
#elif defined(IFX_PIN_PACKAGE_BGA292_STD)
#include "TC46x/IfxScu_PinMap_TC46x_BGA292_STD.h"
#elif defined(IFX_PIN_PACKAGE_BGA224_STD)
#include "TC46x/IfxScu_PinMap_TC46x_BGA224_STD.h"
#endif

#elif defined(DEVICE_TC45X)
#if defined(IFX_PIN_PACKAGE_BGA292_RDR)
#include "TC45x/IfxScu_PinMap_TC45x_BGA292_RDR.h"
#endif

#elif defined(DEVICE_TC44X)
#if defined(IFX_PIN_PACKAGE_BGA292_STD)
#include "TC44x/IfxScu_PinMap_TC44x_BGA292_STD.h"
#elif defined(IFX_PIN_PACKAGE_BGA292_COM)
#include "TC44x/IfxScu_PinMap_TC44x_BGA292_COM.h"
#elif defined(IFX_PIN_PACKAGE_BGA224_STD)
#include "TC44x/IfxScu_PinMap_TC44x_BGA224_STD.h"
#elif defined(IFX_PIN_PACKAGE_BGA188_STD)
#include "TC44x/IfxScu_PinMap_TC44x_BGA188_STD.h"
#endif

#elif defined(DEVICE_TC4ZX)
#if defined(IFX_PIN_PACKAGE_BGA436_COM)
#include "TC4Zx/IfxScu_PinMap_TC4Zx_BGA436_COM.h"
#elif defined(IFX_PIN_PACKAGE_BGA292_COM)
#include "TC4Zx/IfxScu_PinMap_TC4Zx_BGA292_COM.h"
#endif

#elif defined(DEVICE_TC4EX)
#if defined(IFX_PIN_PACKAGE_BGA292_STD)
#include "TC4Ex/IfxScu_PinMap_TC4Ex_BGA292_STD.h"
#elif defined(IFX_PIN_PACKAGE_BGA224_STD)
#include "TC4Ex/IfxScu_PinMap_TC4Ex_BGA224_STD.h"
#endif

#elif defined(DEVICE_TC4PX)
#if defined(IFX_PIN_PACKAGE_BGA292_STD)
#include "TC4Px/IfxScu_PinMap_TC4Px_BGA292_STD.h"
#elif defined(IFX_PIN_PACKAGE_BGA224_STD)
#include "TC4Px/IfxScu_PinMap_TC4Px_BGA224_STD.h"
#elif defined(IFX_PIN_PACKAGE_BGA188_STD)
#include "TC4Px/IfxScu_PinMap_TC4Px_BGA188_STD.h"
#endif

#endif /* #if defined(DEVICE_TC4DX) */

#endif /* IFXSCU_PINMAP_H */
