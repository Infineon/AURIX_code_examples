/**
 * \file IfxSdmmc_PinMap.h
 * \brief SDMMC  details
 * \ingroup IfxLld_Sdmmc
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
 * \defgroup IfxLld_Sdmmc_Pinmap Sdmmc Pinmap Structure
 * \ingroup IfxLld_Sdmmc
 */

#ifndef IFXSDMMC_PINMAP_H
#define IFXSDMMC_PINMAP_H 1

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include "Ifx_PinMap.h"
#include "IfxSdmmc_reg.h"
#include "Port/Std/IfxPort.h"

/******************************************************************************/
/*-----------------------------Data Structures--------------------------------*/
/******************************************************************************/

/** \brief
 */
typedef const struct
{
    Ifx_SDMMC        *module;       /**< \brief Base address */
    IfxPort_Pin       pin;          /**< \brief Port pin */
    IfxPort_OutputIdx select;       /**< \brief Port control code */
} IfxSdmmc_Clk_Out;

/** \brief
 */
typedef const struct
{
    Ifx_SDMMC  *module;       /**< \brief Base address */
    IfxPort_Pin pin;          /**< \brief Port pin */
    Ifx_RxSel   select;       /**< \brief Input multiplexer value */
} IfxSdmmc_Clkrx_In;

/** \brief
 */
typedef const struct
{
    Ifx_SDMMC        *module;          /**< \brief Base address */
    IfxPort_Pin       pin;             /**< \brief Port pin */
    Ifx_RxSel         inSelect;        /**< \brief Input multiplexer value */
    IfxPort_OutputIdx outSelect;       /**< \brief Port control code */
} IfxSdmmc_Cmd_InOut;

/** \brief
 */
typedef const struct
{
    Ifx_SDMMC        *module;          /**< \brief Base address */
    IfxPort_Pin       pin;             /**< \brief Port pin */
    Ifx_RxSel         inSelect;        /**< \brief Input multiplexer value */
    IfxPort_OutputIdx outSelect;       /**< \brief Port control code */
} IfxSdmmc_Dat0_InOut;

/** \brief
 */
typedef const struct
{
    Ifx_SDMMC        *module;          /**< \brief Base address */
    IfxPort_Pin       pin;             /**< \brief Port pin */
    Ifx_RxSel         inSelect;        /**< \brief Input multiplexer value */
    IfxPort_OutputIdx outSelect;       /**< \brief Port control code */
} IfxSdmmc_Dat1_InOut;

/** \brief
 */
typedef const struct
{
    Ifx_SDMMC        *module;          /**< \brief Base address */
    IfxPort_Pin       pin;             /**< \brief Port pin */
    Ifx_RxSel         inSelect;        /**< \brief Input multiplexer value */
    IfxPort_OutputIdx outSelect;       /**< \brief Port control code */
} IfxSdmmc_Dat2_InOut;

/** \brief
 */
typedef const struct
{
    Ifx_SDMMC        *module;          /**< \brief Base address */
    IfxPort_Pin       pin;             /**< \brief Port pin */
    Ifx_RxSel         inSelect;        /**< \brief Input multiplexer value */
    IfxPort_OutputIdx outSelect;       /**< \brief Port control code */
} IfxSdmmc_Dat3_InOut;

/** \brief
 */
typedef const struct
{
    Ifx_SDMMC        *module;          /**< \brief Base address */
    IfxPort_Pin       pin;             /**< \brief Port pin */
    Ifx_RxSel         inSelect;        /**< \brief Input multiplexer value */
    IfxPort_OutputIdx outSelect;       /**< \brief Port control code */
} IfxSdmmc_Dat4_InOut;

/** \brief
 */
typedef const struct
{
    Ifx_SDMMC        *module;          /**< \brief Base address */
    IfxPort_Pin       pin;             /**< \brief Port pin */
    Ifx_RxSel         inSelect;        /**< \brief Input multiplexer value */
    IfxPort_OutputIdx outSelect;       /**< \brief Port control code */
} IfxSdmmc_Dat5_InOut;

/** \brief
 */
typedef const struct
{
    Ifx_SDMMC        *module;          /**< \brief Base address */
    IfxPort_Pin       pin;             /**< \brief Port pin */
    Ifx_RxSel         inSelect;        /**< \brief Input multiplexer value */
    IfxPort_OutputIdx outSelect;       /**< \brief Port control code */
} IfxSdmmc_Dat6_InOut;

/** \brief
 */
typedef const struct
{
    Ifx_SDMMC        *module;          /**< \brief Base address */
    IfxPort_Pin       pin;             /**< \brief Port pin */
    Ifx_RxSel         inSelect;        /**< \brief Input multiplexer value */
    IfxPort_OutputIdx outSelect;       /**< \brief Port control code */
} IfxSdmmc_Dat7_InOut;

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#if defined(DEVICE_TC4DX)
#if defined(IFX_PIN_PACKAGE_BGA436_COM)
#include "TC4Dx/IfxSdmmc_PinMap_TC4Dx_BGA436_COM.h"
#elif defined(IFX_PIN_PACKAGE_BGA292_COM)
#include "TC4Dx/IfxSdmmc_PinMap_TC4Dx_BGA292_COM.h"
#endif

#elif defined(DEVICE_TC49XN)
#if defined(IFX_PIN_PACKAGE_BGA436_STD)
#include "TC49xN/IfxSdmmc_PinMap_TC49xN_BGA436_STD.h"
#elif defined(IFX_PIN_PACKAGE_BGA292_STD)
#include "TC49xN/IfxSdmmc_PinMap_TC49xN_BGA292_STD.h"
#endif

#elif defined(DEVICE_TC46X)
#if defined(IFX_PIN_PACKAGE_BGA436_STD)
#include "TC46x/IfxSdmmc_PinMap_TC46x_BGA436_STD.h"
#elif defined(IFX_PIN_PACKAGE_BGA292_STD)
#include "TC46x/IfxSdmmc_PinMap_TC46x_BGA292_STD.h"
#elif defined(IFX_PIN_PACKAGE_BGA224_STD)
#include "TC46x/IfxSdmmc_PinMap_TC46x_BGA224_STD.h"
#endif

#elif defined(DEVICE_TC44X)
#if defined(IFX_PIN_PACKAGE_BGA292_STD)
#include "TC44x/IfxSdmmc_PinMap_TC44x_BGA292_STD.h"
#elif defined(IFX_PIN_PACKAGE_BGA292_COM)
#include "TC44x/IfxSdmmc_PinMap_TC44x_BGA292_COM.h"
#elif defined(IFX_PIN_PACKAGE_BGA224_STD)
#include "TC44x/IfxSdmmc_PinMap_TC44x_BGA224_STD.h"
#elif defined(IFX_PIN_PACKAGE_BGA188_STD)
#include "TC44x/IfxSdmmc_PinMap_TC44x_BGA188_STD.h"
#endif

#elif defined(DEVICE_TC4ZX)
#if defined(IFX_PIN_PACKAGE_BGA436_COM)
#include "TC4Zx/IfxSdmmc_PinMap_TC4Zx_BGA436_COM.h"
#elif defined(IFX_PIN_PACKAGE_BGA292_COM)
#include "TC4Zx/IfxSdmmc_PinMap_TC4Zx_BGA292_COM.h"
#endif

#endif /* #if defined(DEVICE_TC4DX) */

#endif /* IFXSDMMC_PINMAP_H */
