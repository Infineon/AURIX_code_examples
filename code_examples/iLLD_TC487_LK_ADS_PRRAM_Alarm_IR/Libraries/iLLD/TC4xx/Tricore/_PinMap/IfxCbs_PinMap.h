/**
 * \file IfxCbs_PinMap.h
 * \brief CBS  details
 * \ingroup IfxLld_Cbs
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
 * \defgroup IfxLld_Cbs_Pinmap Cbs Pinmap Structure
 * \ingroup IfxLld_Cbs
 */

#ifndef IFXCBS_PINMAP_H
#define IFXCBS_PINMAP_H 1

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

typedef enum
{
    IfxCbs_TriggerPin_0 = 0,
    IfxCbs_TriggerPin_1 = 1,
    IfxCbs_TriggerPin_2 = 2,
    IfxCbs_TriggerPin_3 = 3,
    IfxCbs_TriggerPin_4 = 4,
    IfxCbs_TriggerPin_5 = 5,
    IfxCbs_TriggerPin_6 = 6,
    IfxCbs_TriggerPin_7 = 7
} IfxCbs_TriggerPin;
#include "Ifx_PinMap.h"
#include "IfxCbs_reg.h"
#include "Port/Std/IfxPort.h"

/******************************************************************************/
/*-----------------------------Data Structures--------------------------------*/
/******************************************************************************/

/** \brief
 */
typedef const struct
{
    Ifx_CBS          *module;       /**< \brief Base address */
    IfxCbs_TriggerPin pinId;        /**< \brief Channel ID */
    IfxPort_Pin       pin;          /**< \brief Port pin */
    Ifx_RxSel         select;       /**< \brief Input multiplexer value */
} IfxCbs_Tgi_In;

/** \brief
 */
typedef const struct
{
    Ifx_CBS          *module;       /**< \brief Base address */
    IfxCbs_TriggerPin pinId;        /**< \brief Channel ID */
    IfxPort_Pin       pin;          /**< \brief Port pin */
    IfxPort_OutputIdx select;       /**< \brief Port control code */
} IfxCbs_Tgo_Out;

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#if defined(DEVICE_TC4DX)
#if defined(IFX_PIN_PACKAGE_BGA436_COM)
#include "TC4Dx/IfxCbs_PinMap_TC4Dx_BGA436_COM.h"
#elif defined(IFX_PIN_PACKAGE_BGA292_COM)
#include "TC4Dx/IfxCbs_PinMap_TC4Dx_BGA292_COM.h"
#endif

#elif defined(DEVICE_TC49XN)
#if defined(IFX_PIN_PACKAGE_BGA436_STD)
#include "TC49xN/IfxCbs_PinMap_TC49xN_BGA436_STD.h"
#elif defined(IFX_PIN_PACKAGE_BGA292_STD)
#include "TC49xN/IfxCbs_PinMap_TC49xN_BGA292_STD.h"
#endif

#elif defined(DEVICE_TC48XAA)
#if defined(IFX_PIN_PACKAGE_BGA436_COM)
#include "TC48xAA/IfxCbs_PinMap_TC48xAA_BGA436_COM.h"
#elif defined(IFX_PIN_PACKAGE_BGA292_COM)
#include "TC48xAA/IfxCbs_PinMap_TC48xAA_BGA292_COM.h"
#elif defined(IFX_PIN_PACKAGE_BGA292_STD)
#include "TC48xAA/IfxCbs_PinMap_TC48xAA_BGA292_STD.h"
#elif defined(IFX_PIN_PACKAGE_BGA224_STD)
#include "TC48xAA/IfxCbs_PinMap_TC48xAA_BGA224_STD.h"
#endif

#elif defined(DEVICE_TC48X)
#if defined(IFX_PIN_PACKAGE_BGA436_COM)
#include "TC48x/IfxCbs_PinMap_TC48x_BGA436_COM.h"
#elif defined(IFX_PIN_PACKAGE_BGA292_COM)
#include "TC48x/IfxCbs_PinMap_TC48x_BGA292_COM.h"
#elif defined(IFX_PIN_PACKAGE_BGA292_STD)
#include "TC48x/IfxCbs_PinMap_TC48x_BGA292_STD.h"
#elif defined(IFX_PIN_PACKAGE_BGA224_STD)
#include "TC48x/IfxCbs_PinMap_TC48x_BGA224_STD.h"
#endif

#elif defined(DEVICE_TC46X)
#if defined(IFX_PIN_PACKAGE_BGA436_STD)
#include "TC46x/IfxCbs_PinMap_TC46x_BGA436_STD.h"
#elif defined(IFX_PIN_PACKAGE_BGA292_STD)
#include "TC46x/IfxCbs_PinMap_TC46x_BGA292_STD.h"
#elif defined(IFX_PIN_PACKAGE_BGA224_STD)
#include "TC46x/IfxCbs_PinMap_TC46x_BGA224_STD.h"
#endif

#elif defined(DEVICE_TC45X)
#if defined(IFX_PIN_PACKAGE_BGA292_RDR)
#include "TC45x/IfxCbs_PinMap_TC45x_BGA292_RDR.h"
#endif

#elif defined(DEVICE_TC44X)
#if defined(IFX_PIN_PACKAGE_BGA292_STD)
#include "TC44x/IfxCbs_PinMap_TC44x_BGA292_STD.h"
#elif defined(IFX_PIN_PACKAGE_BGA292_COM)
#include "TC44x/IfxCbs_PinMap_TC44x_BGA292_COM.h"
#elif defined(IFX_PIN_PACKAGE_BGA224_STD)
#include "TC44x/IfxCbs_PinMap_TC44x_BGA224_STD.h"
#elif defined(IFX_PIN_PACKAGE_BGA188_STD)
#include "TC44x/IfxCbs_PinMap_TC44x_BGA188_STD.h"
#endif

#elif defined(DEVICE_TC4ZX)
#if defined(IFX_PIN_PACKAGE_BGA436_COM)
#include "TC4Zx/IfxCbs_PinMap_TC4Zx_BGA436_COM.h"
#elif defined(IFX_PIN_PACKAGE_BGA292_COM)
#include "TC4Zx/IfxCbs_PinMap_TC4Zx_BGA292_COM.h"
#endif

#elif defined(DEVICE_TC4EX)
#if defined(IFX_PIN_PACKAGE_BGA292_STD)
#include "TC4Ex/IfxCbs_PinMap_TC4Ex_BGA292_STD.h"
#elif defined(IFX_PIN_PACKAGE_BGA224_STD)
#include "TC4Ex/IfxCbs_PinMap_TC4Ex_BGA224_STD.h"
#endif

#elif defined(DEVICE_TC4PX)
#if defined(IFX_PIN_PACKAGE_BGA292_STD)
#include "TC4Px/IfxCbs_PinMap_TC4Px_BGA292_STD.h"
#elif defined(IFX_PIN_PACKAGE_BGA224_STD)
#include "TC4Px/IfxCbs_PinMap_TC4Px_BGA224_STD.h"
#elif defined(IFX_PIN_PACKAGE_BGA188_STD)
#include "TC4Px/IfxCbs_PinMap_TC4Px_BGA188_STD.h"
#endif

#endif /* #if defined(DEVICE_TC4DX) */

#endif /* IFXCBS_PINMAP_H */
