/**
 * \file IfxGeth_PinMap.h
 * \brief GETH  details
 * \ingroup IfxLld_Geth
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
 * \defgroup IfxLld_Geth_Pinmap Geth Pinmap Structure
 * \ingroup IfxLld_Geth
 */

#ifndef IFXGETH_PINMAP_H
#define IFXGETH_PINMAP_H 1

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include "Geth/Std/IfxGeth.h"
#include "Ifx_PinMap.h"
#include "IfxGeth_reg.h"
#include "Port/Std/IfxPort.h"

/******************************************************************************/
/*-----------------------------Data Structures--------------------------------*/
/******************************************************************************/

/** \brief
 */
typedef const struct
{
    Ifx_GETH         *module;          /**< \brief Base address */
    IfxGeth_PortIndex portIndex;       /**< \brief GETH PORT index */
    IfxPort_Pin       pin;             /**< \brief Port pin */
    Ifx_RxSel         select;          /**< \brief Input multiplexer value */
} IfxGeth_Col_In;

/** \brief
 */
typedef const struct
{
    Ifx_GETH         *module;          /**< \brief Base address */
    IfxGeth_PortIndex portIndex;       /**< \brief GETH PORT index */
    IfxPort_Pin       pin;             /**< \brief Port pin */
    Ifx_RxSel         select;          /**< \brief Input multiplexer value */
} IfxGeth_Crs_In;

/** \brief
 */
typedef const struct
{
    Ifx_GETH         *module;          /**< \brief Base address */
    IfxGeth_PortIndex portIndex;       /**< \brief GETH PORT index */
    IfxPort_Pin       pin;             /**< \brief Port pin */
    Ifx_RxSel         select;          /**< \brief Input multiplexer value */
} IfxGeth_Crsdv_In;

/** \brief
 */
typedef const struct
{
    Ifx_GETH         *module;          /**< \brief Base address */
    IfxGeth_PortIndex portIndex;       /**< \brief GETH PORT index */
    IfxPort_Pin       pin;             /**< \brief Port pin */
    Ifx_RxSel         select;          /**< \brief Input multiplexer value */
} IfxGeth_Grefclk_In;

/** \brief
 */
typedef const struct
{
    Ifx_GETH         *module;          /**< \brief Base address */
    IfxGeth_PortIndex portIndex;       /**< \brief GETH PORT index */
    IfxPort_Pin       pin;             /**< \brief Port pin */
    IfxPort_OutputIdx select;          /**< \brief Port control code */
} IfxGeth_Mdc_Out;

#if defined(DEVICE_TC48XAA) || defined(DEVICE_TC48X) || defined(DEVICE_TC44X)
/** \brief
 */
typedef const struct
{
    Ifx_GETH   *module;       /**< \brief Base address */
    IfxPort_Pin pin;          /**< \brief Port pin */
    Ifx_RxSel   select;       /**< \brief Input multiplexer value */
} IfxGeth_Mdio_In;
#endif /* #if defined(DEVICE_TC48XAA) || defined(DEVICE_TC48X) || defined(DEVICE_TC44X) */

/** \brief
 */
typedef const struct
{
    Ifx_GETH         *module;          /**< \brief Base address */
    IfxPort_Pin       pin;             /**< \brief Port pin */
    Ifx_RxSel         inSelect;        /**< \brief Input multiplexer value */
    IfxPort_OutputIdx outSelect;       /**< \brief Port control code */
} IfxGeth_Mdio_InOut;

#if defined(DEVICE_TC44X) || defined(DEVICE_TC4ZX) || defined(DEVICE_TC48X)
/** \brief   
*/
typedef const struct
{
    Ifx_GETH*             module;      /**< \brief Base address */
    IfxGeth_PortIndex     portIndex;   /**< \brief GETH PORT index */
    IfxPort_Pin           pin;         /**< \brief Port pin */
    Ifx_RxSel             select;      /**< \brief Input multiplexer value */
} IfxGeth_P_In;
#endif /* #if defined(DEVICE_TC44X) || defined(DEVICE_TC4ZX) || defined(DEVICE_TC48X)*/

/** \brief
 */
typedef const struct
{
    Ifx_GETH         *module;          /**< \brief Base address */
    IfxGeth_PortIndex portIndex;       /**< \brief GETH PORT index */
    IfxPort_Pin       pin;             /**< \brief Port pin */
    IfxPort_OutputIdx select;          /**< \brief Port control code */
} IfxGeth_Pps_Out;

#if defined(DEVICE_TC44X)
/** \brief   
*/
typedef const struct
{
    Ifx_GETH*             module;   /**< \brief Base address */
    IfxPort_Pin           pin;      /**< \brief Port pin */
    IfxPort_OutputIdx     select;   /**< \brief Port control code */
} IfxGeth_Px_Out;
#endif /* #if defined(DEVICE_TC44X) */

/** \brief
 */
typedef const struct
{
    Ifx_GETH         *module;          /**< \brief Base address */
    IfxGeth_PortIndex portIndex;       /**< \brief GETH PORT index */
    IfxPort_Pin       pin;             /**< \brief Port pin */
    Ifx_RxSel         select;          /**< \brief Input multiplexer value */
} IfxGeth_Refclk_In;

/** \brief
 */
typedef const struct
{
    Ifx_GETH         *module;          /**< \brief Base address */
    IfxGeth_PortIndex portIndex;       /**< \brief GETH PORT index */
    IfxPort_Pin       pin;             /**< \brief Port pin */
    Ifx_RxSel         select;          /**< \brief Input multiplexer value */
} IfxGeth_Rxclk_In;

/** \brief
 */
typedef const struct
{
    Ifx_GETH         *module;          /**< \brief Base address */
    IfxGeth_PortIndex portIndex;       /**< \brief GETH PORT index */
    IfxPort_Pin       pin;             /**< \brief Port pin */
    Ifx_RxSel         select;          /**< \brief Input multiplexer value */
} IfxGeth_Rxctl_In;

/** \brief
 */
typedef const struct
{
    Ifx_GETH         *module;          /**< \brief Base address */
    IfxGeth_PortIndex portIndex;       /**< \brief GETH PORT index */
    IfxPort_Pin       pin;             /**< \brief Port pin */
    Ifx_RxSel         select;          /**< \brief Input multiplexer value */
} IfxGeth_Rxd_In;

/** \brief
 */
typedef const struct
{
    Ifx_GETH         *module;          /**< \brief Base address */
    IfxGeth_PortIndex portIndex;       /**< \brief GETH PORT index */
    IfxPort_Pin       pin;             /**< \brief Port pin */
    Ifx_RxSel         select;          /**< \brief Input multiplexer value */
} IfxGeth_Rxdv_In;

/** \brief
 */
typedef const struct
{
    Ifx_GETH         *module;          /**< \brief Base address */
    IfxGeth_PortIndex portIndex;       /**< \brief GETH PORT index */
    IfxPort_Pin       pin;             /**< \brief Port pin */
    Ifx_RxSel         select;          /**< \brief Input multiplexer value */
} IfxGeth_Rxer_In;

/** \brief
 */
typedef const struct
{
    Ifx_GETH         *module;          /**< \brief Base address */
    IfxGeth_PortIndex portIndex;       /**< \brief GETH PORT index */
    IfxPort_Pin       pin;             /**< \brief Port pin */
    Ifx_RxSel         select;          /**< \brief Input multiplexer value */
} IfxGeth_Txclk_In;

/** \brief
 */
typedef const struct
{
    Ifx_GETH         *module;          /**< \brief Base address */
    IfxGeth_PortIndex portIndex;       /**< \brief GETH PORT index */
    IfxPort_Pin       pin;             /**< \brief Port pin */
    IfxPort_OutputIdx select;          /**< \brief Port control code */
} IfxGeth_Txclk_Out;

/** \brief
 */
typedef const struct
{
    Ifx_GETH         *module;          /**< \brief Base address */
    IfxGeth_PortIndex portIndex;       /**< \brief GETH PORT index */
    IfxPort_Pin       pin;             /**< \brief Port pin */
    IfxPort_OutputIdx select;          /**< \brief Port control code */
} IfxGeth_Txctl_Out;

/** \brief
 */
typedef const struct
{
    Ifx_GETH         *module;          /**< \brief Base address */
    IfxGeth_PortIndex portIndex;       /**< \brief GETH PORT index */
    IfxPort_Pin       pin;             /**< \brief Port pin */
    IfxPort_OutputIdx select;          /**< \brief Port control code */
} IfxGeth_Txd_Out;

/** \brief
 */
typedef const struct
{
    Ifx_GETH         *module;          /**< \brief Base address */
    IfxGeth_PortIndex portIndex;       /**< \brief GETH PORT index */
    IfxPort_Pin       pin;             /**< \brief Port pin */
    IfxPort_OutputIdx select;          /**< \brief Port control code */
} IfxGeth_Txen_Out;

/** \brief
 */
typedef const struct
{
    Ifx_GETH         *module;          /**< \brief Base address */
    IfxGeth_PortIndex portIndex;       /**< \brief GETH PORT index */
    IfxPort_Pin       pin;             /**< \brief Port pin */
    IfxPort_OutputIdx select;          /**< \brief Port control code */
} IfxGeth_Txer_Out;

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#if defined(DEVICE_TC4DX)
#if defined(IFX_PIN_PACKAGE_BGA436_COM)
#include "TC4Dx/IfxGeth_PinMap_TC4Dx_BGA436_COM.h"
#elif defined(IFX_PIN_PACKAGE_BGA292_COM)
#include "TC4Dx/IfxGeth_PinMap_TC4Dx_BGA292_COM.h"
#endif

#elif defined(DEVICE_TC48XAA)
#if defined(IFX_PIN_PACKAGE_BGA436_COM)
#include "TC48xAA/IfxGeth_PinMap_TC48xAA_BGA436_COM.h"
#elif defined(IFX_PIN_PACKAGE_BGA292_COM)
#include "TC48xAA/IfxGeth_PinMap_TC48xAA_BGA292_COM.h"
#elif defined(IFX_PIN_PACKAGE_BGA292_STD)
#include "TC48xAA/IfxGeth_PinMap_TC48xAA_BGA292_STD.h"
#elif defined(IFX_PIN_PACKAGE_BGA224_STD)
#include "TC48xAA/IfxGeth_PinMap_TC48xAA_BGA224_STD.h"
#endif

#elif defined(DEVICE_TC48X)
#if defined(IFX_PIN_PACKAGE_BGA436_COM)
#include "TC48x/IfxGeth_PinMap_TC48x_BGA436_COM.h"
#elif defined(IFX_PIN_PACKAGE_BGA292_COM)
#include "TC48x/IfxGeth_PinMap_TC48x_BGA292_COM.h"
#elif defined(IFX_PIN_PACKAGE_BGA292_STD)
#include "TC48x/IfxGeth_PinMap_TC48x_BGA292_STD.h"
#elif defined(IFX_PIN_PACKAGE_BGA224_STD)
#include "TC48x/IfxGeth_PinMap_TC48x_BGA224_STD.h"
#endif

#elif defined(DEVICE_TC44X)
#if defined(IFX_PIN_PACKAGE_BGA292_STD)
#include "TC44x/IfxGeth_PinMap_TC44x_BGA292_STD.h"
#elif defined(IFX_PIN_PACKAGE_BGA292_COM)
#include "TC44x/IfxGeth_PinMap_TC44x_BGA292_COM.h"
#elif defined(IFX_PIN_PACKAGE_BGA224_STD)
#include "TC44x/IfxGeth_PinMap_TC44x_BGA224_STD.h"
#elif defined(IFX_PIN_PACKAGE_BGA188_STD)
#include "TC44x/IfxGeth_PinMap_TC44x_BGA188_STD.h"
#endif

#elif defined(DEVICE_TC4ZX)
#if defined(IFX_PIN_PACKAGE_BGA436_COM)
#include "TC4Zx/IfxGeth_PinMap_TC4Zx_BGA436_COM.h"
#elif defined(IFX_PIN_PACKAGE_BGA292_COM)
#include "TC4Zx/IfxGeth_PinMap_TC4Zx_BGA292_COM.h"
#endif

#endif /* #if defined(DEVICE_TC4DX) */

#endif /* IFXGETH_PINMAP_H */
