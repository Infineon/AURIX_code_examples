/**
 * \file IfxEray_PinMap_TC37x_516.h
 * \brief ERAY I/O map
 * \ingroup IfxLld_Eray
 *
 * \version iLLD_1_22_0
 * \copyright Copyright (c) 2026 Infineon Technologies AG. All rights reserved.
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
 * \defgroup IfxLld_Eray_pinmap ERAY Pin Mapping
 * \ingroup IfxLld_Eray
 */

#ifndef IFXERAY_PINMAP_TC37X_516_H
#define IFXERAY_PINMAP_TC37X_516_H 1

#include <IfxEray_reg.h>
#include <_Impl/IfxEray_cfg.h>
#include <Port/Std/IfxPort.h>
#include "Ifx_PinMap.h"

/** \addtogroup IfxLld_Eray_pinmap
 * \{ */

/** \brief RXD pin mapping structure */
typedef const struct
{
    Ifx_ERAY*         module;   /**< \brief Base address */
    IfxEray_NodeId    nodeId;   /**< \brief Node ID */
    IfxPort_Pin       pin;      /**< \brief Port pin */
    Ifx_RxSel         select;   /**< \brief Input multiplexer value */
} IfxEray_Rxd_In;

/** \brief TXD pin mapping structure */
typedef const struct
{
    Ifx_ERAY*         module;   /**< \brief Base address */
    IfxEray_NodeId    nodeId;   /**< \brief Node ID */
    IfxPort_Pin       pin;      /**< \brief Port pin */
    IfxPort_OutputIdx select;   /**< \brief Port control code */
} IfxEray_Txd_Out;

/** \brief TXEN pin mapping structure */
typedef const struct
{
    Ifx_ERAY*         module;   /**< \brief Base address */
    IfxEray_NodeId    nodeId;   /**< \brief Node ID */
    IfxPort_Pin       pin;      /**< \brief Port pin */
    IfxPort_OutputIdx select;   /**< \brief Port control code */
} IfxEray_Txen_Out;

IFX_EXTERN IfxEray_Rxd_In IfxEray0_RXDA0_P14_8_IN;  /**< \brief Receive Channel A0 */
IFX_EXTERN IfxEray_Rxd_In IfxEray0_RXDA1_P11_9_IN;  /**< \brief Receive Channel A1 */
IFX_EXTERN IfxEray_Rxd_In IfxEray0_RXDA2_P02_1_IN;  /**< \brief Receive Channel A2 */
IFX_EXTERN IfxEray_Rxd_In IfxEray0_RXDA3_P14_1_IN;  /**< \brief Receive Channel A3 */
IFX_EXTERN IfxEray_Rxd_In IfxEray0_RXDB0_P14_7_IN;  /**< \brief Receive Channel B0 */
IFX_EXTERN IfxEray_Rxd_In IfxEray0_RXDB1_P11_10_IN;  /**< \brief Receive Channel B1 */
IFX_EXTERN IfxEray_Rxd_In IfxEray0_RXDB2_P02_3_IN;  /**< \brief Receive Channel B2 */
IFX_EXTERN IfxEray_Rxd_In IfxEray0_RXDB3_P14_1_IN;  /**< \brief Receive Channel B3 */
IFX_EXTERN IfxEray_Txd_Out IfxEray0_TXDA_P02_0_OUT;  /**< \brief Transmit Channel A */
IFX_EXTERN IfxEray_Txd_Out IfxEray0_TXDA_P11_3_OUT;  /**< \brief Transmit Channel A */
IFX_EXTERN IfxEray_Txd_Out IfxEray0_TXDA_P14_0_OUT;  /**< \brief Transmit Channel A */
IFX_EXTERN IfxEray_Txd_Out IfxEray0_TXDA_P14_10_OUT;  /**< \brief Transmit Channel A */
IFX_EXTERN IfxEray_Txd_Out IfxEray0_TXDB_P02_2_OUT;  /**< \brief Transmit Channel B */
IFX_EXTERN IfxEray_Txd_Out IfxEray0_TXDB_P11_12_OUT;  /**< \brief Transmit Channel B */
IFX_EXTERN IfxEray_Txd_Out IfxEray0_TXDB_P14_0_OUT;  /**< \brief Transmit Channel B */
IFX_EXTERN IfxEray_Txd_Out IfxEray0_TXDB_P14_5_OUT;  /**< \brief Transmit Channel B */
IFX_EXTERN IfxEray_Txen_Out IfxEray0_TXENA_P02_4_OUT;  /**< \brief Transmit Enable Channel A */
IFX_EXTERN IfxEray_Txen_Out IfxEray0_TXENA_P11_6_OUT;  /**< \brief Transmit Enable Channel A */
IFX_EXTERN IfxEray_Txen_Out IfxEray0_TXENA_P14_9_OUT;  /**< \brief Transmit Enable Channel A */
IFX_EXTERN IfxEray_Txen_Out IfxEray0_TXENB_P02_5_OUT;  /**< \brief Transmit Enable Channel B */
IFX_EXTERN IfxEray_Txen_Out IfxEray0_TXENB_P11_11_OUT;  /**< \brief Transmit Enable Channel B */
IFX_EXTERN IfxEray_Txen_Out IfxEray0_TXENB_P11_6_OUT;  /**< \brief Transmit Enable Channel B */
IFX_EXTERN IfxEray_Txen_Out IfxEray0_TXENB_P14_6_OUT;  /**< \brief Transmit Enable Channel B */
IFX_EXTERN IfxEray_Txen_Out IfxEray0_TXENB_P14_9_OUT;  /**< \brief Transmit Enable Channel B */

/** \brief Table dimensions */
#define IFXERAY_PINMAP_NUM_MODULES 1
#define IFXERAY_PINMAP_NUM_NODES 2
#define IFXERAY_PINMAP_RXD_IN_NUM_ITEMS 4
#define IFXERAY_PINMAP_TXD_OUT_NUM_ITEMS 4
#define IFXERAY_PINMAP_TXEN_OUT_NUM_ITEMS 5


/** \brief IfxEray_Rxd_In table */
IFX_EXTERN const IfxEray_Rxd_In *IfxEray_Rxd_In_pinTable[IFXERAY_PINMAP_NUM_MODULES][IFXERAY_PINMAP_NUM_NODES][IFXERAY_PINMAP_RXD_IN_NUM_ITEMS];

/** \brief IfxEray_Txd_Out table */
IFX_EXTERN const IfxEray_Txd_Out *IfxEray_Txd_Out_pinTable[IFXERAY_PINMAP_NUM_MODULES][IFXERAY_PINMAP_NUM_NODES][IFXERAY_PINMAP_TXD_OUT_NUM_ITEMS];

/** \brief IfxEray_Txen_Out table */
IFX_EXTERN const IfxEray_Txen_Out *IfxEray_Txen_Out_pinTable[IFXERAY_PINMAP_NUM_MODULES][IFXERAY_PINMAP_NUM_NODES][IFXERAY_PINMAP_TXEN_OUT_NUM_ITEMS];

/** \} */

#endif /* IFXERAY_PINMAP_TC37X_516_H */
