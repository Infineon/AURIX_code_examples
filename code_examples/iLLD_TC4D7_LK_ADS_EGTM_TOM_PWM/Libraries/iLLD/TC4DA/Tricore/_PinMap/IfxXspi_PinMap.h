/**
 * \file IfxXspi_PinMap.h
 * \brief XSPI  details
 * \ingroup IfxLld_Xspi
 *
 * \version iLLD-TC4-v2.2.0
 * \copyright Copyright (c) 2023 Infineon Technologies AG. All rights reserved.
 *
 *
 *
 *                                 IMPORTANT NOTICE
 *
 * Use of this file is subject to the terms of use agreed between (i) you or
 * the company in which ordinary course of business you are acting and (ii)
 * Infineon Technologies AG or its licensees. If and as long as no such terms
 * of use are agreed, use of this file is subject to following:
 *
 * Boost Software License - Version 1.0 - August 17th, 2003
 *
 * Permission is hereby granted, free of charge, to any person or organization
 * obtaining a copy of the software and accompanying documentation covered by
 * this license (the "Software") to use, reproduce, display, distribute,
 * execute, and transmit the Software, and to prepare derivative works of the
 * Software, and to permit third-parties to whom the Software is furnished to
 * do so, all subject to the following:
 *
 * The copyright notices in the Software and this entire statement, including
 * the above license grant, this restriction and the following disclaimer, must
 * be included in all copies of the Software, in whole or in part, and all
 * derivative works of the Software, unless such copies or derivative works are
 * solely in the form of machine-executable object code generated by a source
 * language processor.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT
 * SHALL THE COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE
 * FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN CONTRACT, TORT OR OTHERWISE,
 * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 *
 *
 * Version: MC_ACE_A3G_HWA_Ports/Unknown
 * Document: TC4Dx_Pin_Assignment_v0.45_LETH_patched.xls
 *
 * \defgroup IfxLld_Xspi_Pinmap Xspi Pinmap Structure
 * \ingroup IfxLld_Xspi
 */

#ifndef IFXXSPI_PINMAP_H
#define IFXXSPI_PINMAP_H 1

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include "Ifx_PinMap.h"
#include "IfxXspi_reg.h"
#include "Port/Std/IfxPort.h"

/******************************************************************************/
/*-----------------------------Data Structures--------------------------------*/
/******************************************************************************/

/** \brief
 */
typedef const struct
{
    Ifx_XSPI         *module;       /**< \brief Base address */
    IfxPort_Pin       pin;          /**< \brief Port pin */
    IfxPort_OutputIdx select;       /**< \brief Port control code */
} IfxXspi_Clk_Out;

/** \brief
 */
typedef const struct
{
    Ifx_XSPI         *module;       /**< \brief Base address */
    IfxPort_Pin       pin;          /**< \brief Port pin */
    IfxPort_OutputIdx select;       /**< \brief Port control code */
} IfxXspi_Cs_Out;

/** \brief
 */
typedef const struct
{
    Ifx_XSPI         *module;          /**< \brief Base address */
    IfxPort_Pin       pin;             /**< \brief Port pin */
    Ifx_RxSel         inSelect;        /**< \brief Input multiplexer value */
    IfxPort_OutputIdx outSelect;       /**< \brief Port control code */
} IfxXspi_Dm_InOut;

/** \brief
 */
typedef const struct
{
    Ifx_XSPI         *module;          /**< \brief Base address */
    IfxPort_Pin       pin;             /**< \brief Port pin */
    Ifx_RxSel         inSelect;        /**< \brief Input multiplexer value */
    IfxPort_OutputIdx outSelect;       /**< \brief Port control code */
} IfxXspi_Txd0_InOut;

/** \brief
 */
typedef const struct
{
    Ifx_XSPI         *module;          /**< \brief Base address */
    IfxPort_Pin       pin;             /**< \brief Port pin */
    Ifx_RxSel         inSelect;        /**< \brief Input multiplexer value */
    IfxPort_OutputIdx outSelect;       /**< \brief Port control code */
} IfxXspi_Txd1_InOut;

/** \brief
 */
typedef const struct
{
    Ifx_XSPI         *module;          /**< \brief Base address */
    IfxPort_Pin       pin;             /**< \brief Port pin */
    Ifx_RxSel         inSelect;        /**< \brief Input multiplexer value */
    IfxPort_OutputIdx outSelect;       /**< \brief Port control code */
} IfxXspi_Txd2_InOut;

/** \brief
 */
typedef const struct
{
    Ifx_XSPI         *module;          /**< \brief Base address */
    IfxPort_Pin       pin;             /**< \brief Port pin */
    Ifx_RxSel         inSelect;        /**< \brief Input multiplexer value */
    IfxPort_OutputIdx outSelect;       /**< \brief Port control code */
} IfxXspi_Txd3_InOut;

/** \brief
 */
typedef const struct
{
    Ifx_XSPI         *module;          /**< \brief Base address */
    IfxPort_Pin       pin;             /**< \brief Port pin */
    Ifx_RxSel         inSelect;        /**< \brief Input multiplexer value */
    IfxPort_OutputIdx outSelect;       /**< \brief Port control code */
} IfxXspi_Txd4_InOut;

/** \brief
 */
typedef const struct
{
    Ifx_XSPI         *module;          /**< \brief Base address */
    IfxPort_Pin       pin;             /**< \brief Port pin */
    Ifx_RxSel         inSelect;        /**< \brief Input multiplexer value */
    IfxPort_OutputIdx outSelect;       /**< \brief Port control code */
} IfxXspi_Txd5_InOut;

/** \brief
 */
typedef const struct
{
    Ifx_XSPI         *module;          /**< \brief Base address */
    IfxPort_Pin       pin;             /**< \brief Port pin */
    Ifx_RxSel         inSelect;        /**< \brief Input multiplexer value */
    IfxPort_OutputIdx outSelect;       /**< \brief Port control code */
} IfxXspi_Txd6_InOut;

/** \brief
 */
typedef const struct
{
    Ifx_XSPI         *module;          /**< \brief Base address */
    IfxPort_Pin       pin;             /**< \brief Port pin */
    Ifx_RxSel         inSelect;        /**< \brief Input multiplexer value */
    IfxPort_OutputIdx outSelect;       /**< \brief Port control code */
} IfxXspi_Txd7_InOut;

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#if defined(IFX_PIN_PACKAGE_BGA436_COM)
#include "IfxXspi_PinMap_BGA436_COM.h"
#elif defined(IFX_PIN_PACKAGE_BGA292_COM)
#include "IfxXspi_PinMap_BGA292_COM.h"
#endif

#endif /* IFXXSPI_PINMAP_H */
