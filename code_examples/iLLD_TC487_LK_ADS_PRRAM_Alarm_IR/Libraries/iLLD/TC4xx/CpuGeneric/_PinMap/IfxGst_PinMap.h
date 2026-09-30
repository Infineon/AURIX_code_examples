/**
 * \file IfxGst_PinMap.h
 * \brief GST  details
 * \ingroup IfxLld_Gst
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
 * \defgroup IfxLld_Gst_Pinmap Gst Pinmap Structure
 * \ingroup IfxLld_Gst
 */

#ifndef IFXGST_PINMAP_H
#define IFXGST_PINMAP_H 1

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include "Ifx_PinMap.h"
#include "IfxGst_reg.h"
#include "Port/Std/IfxPort.h"

/******************************************************************************/
/*-----------------------------Data Structures--------------------------------*/
/******************************************************************************/

/** \brief
 */
typedef const struct
{
    Ifx_GST    *module;       /**< \brief Base address */
    IfxPort_Pin pin;          /**< \brief Port pin */
    Ifx_RxSel   select;       /**< \brief Input multiplexer value */
} IfxGst_Hwcap_In;

/** \brief
 */
typedef const struct
{
    Ifx_GST          *module;       /**< \brief Base address */
    IfxPort_Pin       pin;          /**< \brief Port pin */
    IfxPort_OutputIdx select;       /**< \brief Port control code */
} IfxGst_Hwtrg_Out;

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#if defined(DEVICE_TC45X)
#if defined(IFX_PIN_PACKAGE_BGA292_RDR)
#include "TC45x/IfxGst_PinMap_TC45x_BGA292_RDR.h"
#endif /* #if defined(IFX_PIN_PACKAGE_BGA292_RDR) */
#endif /* #if defined(DEVICE_TC45X) */

#endif /* IFXGST_PINMAP_H */
