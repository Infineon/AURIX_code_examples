/**
 * \file IfxPsi5s_PinMap.h
 * \brief PSI5S I/O map
 * \ingroup IfxLld_Psi5s
 *
 * \version iLLD_1_0_1_9_0
 * \copyright Copyright (c) 2013 Infineon Technologies AG. All rights reserved.
 *
 *
 *                                 IMPORTANT NOTICE
 *
 *
 * Infineon Technologies AG (Infineon) is supplying this file for use
 * exclusively with Infineon's microcontroller products. This file can be freely
 * distributed within development tools that are supporting such microcontroller
 * products.
 *
 * THIS SOFTWARE IS PROVIDED "AS IS".  NO WARRANTIES, WHETHER EXPRESS, IMPLIED
 * OR STATUTORY, INCLUDING, BUT NOT LIMITED TO, IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE APPLY TO THIS SOFTWARE.
 * INFINEON SHALL NOT, IN ANY CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL,
 * OR CONSEQUENTIAL DAMAGES, FOR ANY REASON WHATSOEVER.
 *
 * \defgroup IfxLld_Psi5s_pinmap PSI5S Pin Mapping
 * \ingroup IfxLld_Psi5s
 */

#ifndef IFXPSI5S_PINMAP_H
#define IFXPSI5S_PINMAP_H

#include <IfxPsi5s_reg.h>
#include <_Impl/IfxPsi5s_cfg.h>
#include <Port/Std/IfxPort.h>

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

IFX_EXTERN IfxPsi5s_Clk_Out IfxPsi5s_CLK_P02_4_OUT;  /**< \brief PSI5S_CLK: PSI5-S output */
IFX_EXTERN IfxPsi5s_Clk_Out IfxPsi5s_CLK_P33_10_OUT;  /**< \brief PSI5S_CLK: PSI5-S output */
IFX_EXTERN IfxPsi5s_Rx_In IfxPsi5s_RXA_P00_3_IN;  /**< \brief PSI5S_RXA: PSI5-S input */
IFX_EXTERN IfxPsi5s_Rx_In IfxPsi5s_RXB_P02_5_IN;  /**< \brief PSI5S_RXB: PSI5-S input */
IFX_EXTERN IfxPsi5s_Rx_In IfxPsi5s_RXC_P33_5_IN;  /**< \brief PSI5S_RXC: PSI5-S input */
IFX_EXTERN IfxPsi5s_Tx_Out IfxPsi5s_TX_P00_4_OUT;  /**< \brief PSI5S_TX: PSI5-S output */
IFX_EXTERN IfxPsi5s_Tx_Out IfxPsi5s_TX_P02_6_OUT;  /**< \brief PSI5S_TX: PSI5-S output */
IFX_EXTERN IfxPsi5s_Tx_Out IfxPsi5s_TX_P33_6_OUT;  /**< \brief PSI5S_TX: PSI5-S output */

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

#endif /* IFXPSI5S_PINMAP_H */
