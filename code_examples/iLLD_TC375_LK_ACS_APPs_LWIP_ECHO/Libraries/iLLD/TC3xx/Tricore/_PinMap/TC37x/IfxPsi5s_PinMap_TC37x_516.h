/**
 * \file IfxPsi5s_PinMap_TC37x_516.h
 * \brief PSI5S I/O map
 * \ingroup IfxLld_Psi5s
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
 * \defgroup IfxLld_Psi5s_pinmap PSI5S Pin Mapping
 * \ingroup IfxLld_Psi5s
 */

#ifndef IFXPSI5S_PINMAP_TC37X_516_H
#define IFXPSI5S_PINMAP_TC37X_516_H 1

#include <IfxPsi5s_reg.h>
#include <_Impl/IfxPsi5s_cfg.h>
#include <Port/Std/IfxPort.h>
#include "Ifx_PinMap.h"

/** \addtogroup IfxLld_Psi5s_pinmap
 * \{ */

/** \brief RX pin mapping structure */
typedef const struct
{
    Ifx_PSI5S*         module;    /**< \brief Base address */
    IfxPort_Pin        pin;       /**< \brief Port pin */
    Ifx_RxSel          select;    /**< \brief Input multiplexer value */
} IfxPsi5s_Rx_In;

/** \brief TX pin mapping structure */
typedef const struct
{
    Ifx_PSI5S*         module;    /**< \brief Base address */
    IfxPort_Pin        pin;       /**< \brief Port pin */
    IfxPort_OutputIdx  select;    /**< \brief Port control code */
} IfxPsi5s_Tx_Out;

/** \brief CLK pin mapping structure */
typedef const struct
{
    Ifx_PSI5S*         module;    /**< \brief Base address */
    IfxPort_Pin        pin;       /**< \brief Port pin */
    IfxPort_OutputIdx  select;    /**< \brief Port control code */
} IfxPsi5s_Clk_Out;


IFX_EXTERN IfxPsi5s_Clk_Out IfxPsi5s_CLK_P02_4_OUT;  /**< \brief PSI5S CLK is a clock that can be used on a pin to drive the external PHY. */
IFX_EXTERN IfxPsi5s_Clk_Out IfxPsi5s_CLK_P33_10_OUT;  /**< \brief PSI5S CLK is a clock that can be used on a pin to drive the external PHY. */
IFX_EXTERN IfxPsi5s_Rx_In IfxPsi5s_RXA_P00_3_IN;  /**< \brief RX data input */
IFX_EXTERN IfxPsi5s_Rx_In IfxPsi5s_RXB_P02_5_IN;  /**< \brief RX data input */
IFX_EXTERN IfxPsi5s_Rx_In IfxPsi5s_RXC_P33_5_IN;  /**< \brief RX data input */
IFX_EXTERN IfxPsi5s_Tx_Out IfxPsi5s_TX_P00_4_OUT;  /**< \brief TX data output */
IFX_EXTERN IfxPsi5s_Tx_Out IfxPsi5s_TX_P02_6_OUT;  /**< \brief TX data output */
IFX_EXTERN IfxPsi5s_Tx_Out IfxPsi5s_TX_P33_6_OUT;  /**< \brief TX data output */

/** \brief Table dimensions */
#define IFXPSI5S_PINMAP_NUM_MODULES 1
#define IFXPSI5S_PINMAP_CLK_OUT_NUM_ITEMS 2
#define IFXPSI5S_PINMAP_RX_IN_NUM_ITEMS 3
#define IFXPSI5S_PINMAP_TX_OUT_NUM_ITEMS 3


/** \brief IfxPsi5s_Clk_Out table */
IFX_EXTERN const IfxPsi5s_Clk_Out *IfxPsi5s_Clk_Out_pinTable[IFXPSI5S_PINMAP_NUM_MODULES][IFXPSI5S_PINMAP_CLK_OUT_NUM_ITEMS];

/** \brief IfxPsi5s_Rx_In table */
IFX_EXTERN const IfxPsi5s_Rx_In *IfxPsi5s_Rx_In_pinTable[IFXPSI5S_PINMAP_NUM_MODULES][IFXPSI5S_PINMAP_RX_IN_NUM_ITEMS];

/** \brief IfxPsi5s_Tx_Out table */
IFX_EXTERN const IfxPsi5s_Tx_Out *IfxPsi5s_Tx_Out_pinTable[IFXPSI5S_PINMAP_NUM_MODULES][IFXPSI5S_PINMAP_TX_OUT_NUM_ITEMS];

/** \} */

#endif /* IFXPSI5S_PINMAP_TC37X_516_H */
