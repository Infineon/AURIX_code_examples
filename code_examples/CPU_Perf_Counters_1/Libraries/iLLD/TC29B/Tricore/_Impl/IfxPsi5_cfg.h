/**
 * \file IfxPsi5_cfg.h
 * \brief PSI5 on-chip implementation data
 * \ingroup IfxLld_Psi5
 *
 * \version iLLD_1_0_1_9_0
 * \copyright Copyright (c) 2017 Infineon Technologies AG. All rights reserved.
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
 * \defgroup IfxLld_Psi5 PSI5
 * \ingroup IfxLld
 * \defgroup IfxLld_Psi5_Impl Implementation
 * \ingroup IfxLld_Psi5
 * \defgroup IfxLld_Psi5_Std Standard Driver
 * \ingroup IfxLld_Psi5
 * \defgroup IfxLld_Psi5_Impl_Enumerations Enumerations
 * \ingroup IfxLld_Psi5_Impl
 */

#ifndef IFXPSI5_CFG_H
#define IFXPSI5_CFG_H 1

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

/******************************************************************************/
/*-----------------------------------Macros-----------------------------------*/
/******************************************************************************/

#define IFXPSI5_STEP_RANGE             1024

#define IFXPSI5_NUM_WDTS               7

#define IFXPSI5_NUM_SLOTS              6

#define IFXPSI5_ENABLE_CHANNELTRIGGER  (1 << 8)

#define IFXPSI5_ENABLE_CHANNEL         (1 << 16)

#define IFXPSI5_DEFAULT_SLOWCLOCK_FREQ 4000000

#define IFXPSI5_DEFAULT_FASTCLOCK_FREQ 6000000

#define IFXPSI5_DEFAULT_TIMESTAMP_FREQ 1000000

#define IFXPSI5_NUM_CHANNELS           5

#define IFXPSI5_NUM_MODULES            (1)

/******************************************************************************/
/*-------------------------------Enumerations---------------------------------*/
/******************************************************************************/

/** \brief Channel Id
 */
typedef enum
{
    IfxPsi5_ChannelId_none = -1,  /**< \brief None of the Ifx_PSI5 Channels */
    IfxPsi5_ChannelId_0    = 0,   /**< \brief Specifies PSI5 channel 0 */
    IfxPsi5_ChannelId_1    = 1,   /**< \brief Specifies PSI5 channel 1 */
    IfxPsi5_ChannelId_2    = 2,   /**< \brief Specifies PSI5 channel 2 */
    IfxPsi5_ChannelId_3    = 3,   /**< \brief Specifies PSI5 channel 3 */
    IfxPsi5_ChannelId_4    = 4    /**< \brief Specifies PSI5 channel 4 */
} IfxPsi5_ChannelId;

#endif /* IFXPSI5_CFG_H */
