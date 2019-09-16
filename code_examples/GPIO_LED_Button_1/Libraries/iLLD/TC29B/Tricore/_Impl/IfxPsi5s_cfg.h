/**
 * \file IfxPsi5s_cfg.h
 * \brief PSI5S on-chip implementation data
 * \ingroup IfxLld_Psi5s
 *
 * \version iLLD_1_0_1_9_0
 * \copyright Copyright (c) 2018 Infineon Technologies AG. All rights reserved.
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
 * \defgroup IfxLld_Psi5s PSI5S
 * \ingroup IfxLld
 * \defgroup IfxLld_Psi5s_Impl Implementation
 * \ingroup IfxLld_Psi5s
 * \defgroup IfxLld_Psi5s_Std Standard Driver
 * \ingroup IfxLld_Psi5s
 */

#ifndef IFXPSI5S_CFG_H
#define IFXPSI5S_CFG_H 1

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

/******************************************************************************/
/*-----------------------------------Macros-----------------------------------*/
/******************************************************************************/

#define IFXPSI5S_NUM_CHANNELS                                     8

#define IFXPSI5S_STEP_RANGE                                       1024

#define IFXPSI5S_NUM_WDTS                                         7

#define IFXPSI5S_NUM_SLOTS                                        6

#define IFXPSI5S_ENABLE_CHANNELTRIGGER                            (1 << 8)

#define IFXPSI5S_ENABLE_CHANNEL                                   (1 << 16)

#define IFXPSI5S_BG_RANGE                                         8192

#define IFXPSI5S_FDV_RANGE                                        2048

#define IFXPSI5S_BAUDRATE_1562500                                 1562500

/** \brief //0x00FF0000
 */
#define IFXPSI5S_GCR_CHANNELS_ENABLE_MASK                         ((1 << IFXPSI5S_NUM_CHANNELS) - 1) << 16

        #define IFXPSI5S_GCR_CHANNEL_TRIGGER_COUNTERS_ENABLE_MASK ((1 << IFXPSI5S_NUM_CHANNELS) - 1) << 8

        #define IFXPSI5S_DEFAULT_SLOWCLOCK_FREQ                   4000000

        #define IFXPSI5S_DEFAULT_FASTCLOCK_FREQ                   6000000

        #define IFXPSI5S_DEFAULT_TIMESTAMP_FREQ                   1000000

        #define IFXPSI5S_NUM_MODULES                              (1)

#endif /* IFXPSI5S_CFG_H */
