/**
 * \file IfxPsi5_PinMap.h
 * \brief PSI5 I/O map
 * \ingroup IfxLld_Psi5
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
 * \defgroup IfxLld_Psi5_pinmap PSI5 Pin Mapping
 * \ingroup IfxLld_Psi5
 */

#ifndef IFXPSI5_PINMAP_H
#define IFXPSI5_PINMAP_H

#include <IfxPsi5_reg.h>
#include <_Impl/IfxPsi5_cfg.h>
#include <Port/Std/IfxPort.h>

/** \addtogroup IfxLld_Psi5_pinmap
 * \{ */

/** \brief RX pin mapping structure */
typedef const struct
{
    Ifx_PSI5*         module;    /**< \brief Base address */
    IfxPsi5_ChannelId channelId; /**< \brief Channel ID */
    IfxPort_Pin       pin;       /**< \brief Port pin */
    Ifx_RxSel         select;    /**< \brief Input multiplexer value */
} IfxPsi5_Rx_In;

/** \brief TX pin mapping structure */
typedef const struct
{
    Ifx_PSI5*         module;    /**< \brief Base address */
    IfxPsi5_ChannelId channelId; /**< \brief Channel ID */
    IfxPort_Pin       pin;       /**< \brief Port pin */
    IfxPort_OutputIdx select;    /**< \brief Port control code */
} IfxPsi5_Tx_Out;

IFX_EXTERN IfxPsi5_Rx_In IfxPsi5_RX0A_P00_1_IN;  /**< \brief PSI5_RX0A: PSI5 input */
IFX_EXTERN IfxPsi5_Rx_In IfxPsi5_RX0B_P02_3_IN;  /**< \brief PSI5_RX0B: PSI5 input */
IFX_EXTERN IfxPsi5_Rx_In IfxPsi5_RX0C_P33_1_IN;  /**< \brief PSI5_RX0C: PSI5 input */
IFX_EXTERN IfxPsi5_Rx_In IfxPsi5_RX1A_P00_3_IN;  /**< \brief PSI5_RX1A: PSI5 input */
IFX_EXTERN IfxPsi5_Rx_In IfxPsi5_RX1B_P02_5_IN;  /**< \brief PSI5_RX1B: PSI5 input */
IFX_EXTERN IfxPsi5_Rx_In IfxPsi5_RX1C_P33_3_IN;  /**< \brief PSI5_RX1C: PSI5 input */
IFX_EXTERN IfxPsi5_Rx_In IfxPsi5_RX2A_P00_5_IN;  /**< \brief PSI5_RX2A: PSI5 input */
IFX_EXTERN IfxPsi5_Rx_In IfxPsi5_RX2B_P02_7_IN;  /**< \brief PSI5_RX2B: PSI5 input */
IFX_EXTERN IfxPsi5_Rx_In IfxPsi5_RX2C_P33_5_IN;  /**< \brief PSI5_RX2C: PSI5 input */
IFX_EXTERN IfxPsi5_Rx_In IfxPsi5_RX3A_P13_10_IN;  /**< \brief PSI5_RX3A: PSI5 input */
IFX_EXTERN IfxPsi5_Rx_In IfxPsi5_RX3B_P13_13_IN;  /**< \brief PSI5_RX3B: PSI5 input */
IFX_EXTERN IfxPsi5_Rx_In IfxPsi5_RX3C_P10_6_IN;  /**< \brief PSI5_RX3C: PSI5 input */
IFX_EXTERN IfxPsi5_Rx_In IfxPsi5_RX4A_P13_4_IN;  /**< \brief PSI5_RX4A: PSI5 input */
IFX_EXTERN IfxPsi5_Rx_In IfxPsi5_RX4B_P22_5_IN;  /**< \brief PSI5_RX4B: PSI5 input */
IFX_EXTERN IfxPsi5_Tx_Out IfxPsi5_TX0_P00_2_OUT;  /**< \brief PSI5_TX0: PSI5 output */
IFX_EXTERN IfxPsi5_Tx_Out IfxPsi5_TX0_P02_2_OUT;  /**< \brief PSI5_TX0: PSI5 output */
IFX_EXTERN IfxPsi5_Tx_Out IfxPsi5_TX0_P33_2_OUT;  /**< \brief PSI5_TX0: PSI5 output */
IFX_EXTERN IfxPsi5_Tx_Out IfxPsi5_TX1_P00_4_OUT;  /**< \brief PSI5_TX1: PSI5 output */
IFX_EXTERN IfxPsi5_Tx_Out IfxPsi5_TX1_P02_6_OUT;  /**< \brief PSI5_TX1: PSI5 output */
IFX_EXTERN IfxPsi5_Tx_Out IfxPsi5_TX1_P33_4_OUT;  /**< \brief PSI5_TX1: PSI5 output */
IFX_EXTERN IfxPsi5_Tx_Out IfxPsi5_TX2_P00_6_OUT;  /**< \brief PSI5_TX2: PSI5 output */
IFX_EXTERN IfxPsi5_Tx_Out IfxPsi5_TX2_P02_8_OUT;  /**< \brief PSI5_TX2: PSI5 output */
IFX_EXTERN IfxPsi5_Tx_Out IfxPsi5_TX2_P33_6_OUT;  /**< \brief PSI5_TX2: PSI5 output */
IFX_EXTERN IfxPsi5_Tx_Out IfxPsi5_TX3_P10_5_OUT;  /**< \brief PSI5_TX3: PSI5 output */
IFX_EXTERN IfxPsi5_Tx_Out IfxPsi5_TX3_P13_11_OUT;  /**< \brief PSI5_TX3: PSI5 output */
IFX_EXTERN IfxPsi5_Tx_Out IfxPsi5_TX3_P13_15_OUT;  /**< \brief PSI5_TX3: PSI5 output */
IFX_EXTERN IfxPsi5_Tx_Out IfxPsi5_TX4_P14_11_OUT;  /**< \brief PSI5_TX4: PSI5 output */
IFX_EXTERN IfxPsi5_Tx_Out IfxPsi5_TX4_P22_4_OUT;  /**< \brief PSI5_TX4: PSI5 output */

/** \brief Table dimensions */
#define IFXPSI5_PINMAP_NUM_MODULES 1
#define IFXPSI5_PINMAP_NUM_CHANNELS 5
#define IFXPSI5_PINMAP_RX_IN_NUM_ITEMS 3
#define IFXPSI5_PINMAP_TX_OUT_NUM_ITEMS 3


/** \brief IfxPsi5_Rx_In table */
IFX_EXTERN const IfxPsi5_Rx_In *IfxPsi5_Rx_In_pinTable[IFXPSI5_PINMAP_NUM_MODULES][IFXPSI5_PINMAP_NUM_CHANNELS][IFXPSI5_PINMAP_RX_IN_NUM_ITEMS];

/** \brief IfxPsi5_Tx_Out table */
IFX_EXTERN const IfxPsi5_Tx_Out *IfxPsi5_Tx_Out_pinTable[IFXPSI5_PINMAP_NUM_MODULES][IFXPSI5_PINMAP_NUM_CHANNELS][IFXPSI5_PINMAP_TX_OUT_NUM_ITEMS];

/** \} */

#endif /* IFXPSI5_PINMAP_H */
