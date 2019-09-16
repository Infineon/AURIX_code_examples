/**
 * \file IfxSent_cfg.h
 * \brief SENT on-chip implementation data
 * \ingroup IfxLld_Sent
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
 *
 * \defgroup IfxLld_Sent SENT
 * \ingroup IfxLld
 * \defgroup IfxLld_Sent_Impl Implementation
 * \ingroup IfxLld_Sent
 * \defgroup IfxLld_Sent_Std Standard Driver
 * \ingroup IfxLld_Sent
 */

#ifndef IFXSENT_CFG_H
#define IFXSENT_CFG_H 1

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

/******************************************************************************/
/*-----------------------------------Macros-----------------------------------*/
/******************************************************************************/

/** \brief Specifies all interrupt events
 */
#define IFXSENT_CFG_CHANNEL_INTEN (0x1FEDU)

/** \brief Specifies the step range for calculating module clock
 */
#define IFXSENT_CFG_STEP_RANGE    (1024)

/** \brief Specifies timeout value in transmission
 */
#define IFXSENT_CFG_TIMEOUT_VALUE ((uint16)0xFFFFU)

#define IFXSENT_NUM_CHANNELS      (15)

#define IFXSENT_NUM_MODULES       (1)

/******************************************************************************/
/*-------------------------------Enumerations---------------------------------*/
/******************************************************************************/

/** \brief Specifies the channel Id
 */
typedef enum
{
    IfxSent_ChannelId_0    = 0,  /**< \brief Specifies the channel Id 0 */
    IfxSent_ChannelId_1    = 1,  /**< \brief Specifies the channel Id 1 */
    IfxSent_ChannelId_2    = 2,  /**< \brief Specifies the channel Id 2 */
    IfxSent_ChannelId_3    = 3,  /**< \brief Specifies the channel Id 3 */
    IfxSent_ChannelId_4    = 4,  /**< \brief Specifies the channel Id 4 */
    IfxSent_ChannelId_5    = 5,  /**< \brief Specifies the channel Id 5 */
    IfxSent_ChannelId_6    = 6,  /**< \brief Specifies the channel Id 6 */
    IfxSent_ChannelId_7    = 7,  /**< \brief Specifies the channel Id 7 */
    IfxSent_ChannelId_8    = 8,  /**< \brief Specifies the channel Id 8 */
    IfxSent_ChannelId_9    = 9,  /**< \brief Specifies the channel Id 9 */
    IfxSent_ChannelId_10   = 10, /**< \brief Specifies the channel Id 10 */
    IfxSent_ChannelId_11   = 11, /**< \brief Specifies the channel Id 11 */
    IfxSent_ChannelId_12   = 12, /**< \brief Specifies the channel Id 12 */
    IfxSent_ChannelId_13   = 13, /**< \brief Specifies the channel Id 13 */
    IfxSent_ChannelId_14   = 14, /**< \brief Specifies the channel Id 14 */
    IfxSent_ChannelId_none = -1  /**< \brief None Sent channels */
} IfxSent_ChannelId;

#endif /* IFXSENT_CFG_H */
