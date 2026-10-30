/**
 * \file IfxSent_cfg_TC37x.h
 * \brief SENT on-chip implementation data
 * \ingroup IfxLld_Sent
 *
 * \version iLLD_1_22_0
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
 * \defgroup IfxLld_Sent SENT
 * \ingroup IfxLld
 * \defgroup IfxLld_Sent_Impl Implementation
 * \ingroup IfxLld_Sent
 * \defgroup IfxLld_Sent_Std Standard Driver
 * \ingroup IfxLld_Sent
 */

#ifndef IFXSENT_CFG_TC37X_H
#define IFXSENT_CFG_TC37X_H 1

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

#define IFXSENT_NUM_CHANNELS      (25)

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
    IfxSent_ChannelId_15   = 15, /**< \brief Specifies the channel Id 15 */
    IfxSent_ChannelId_16   = 16, /**< \brief Specifies the channel Id 16 */
    IfxSent_ChannelId_17   = 17, /**< \brief Specifies the channel Id 17 */
    IfxSent_ChannelId_18   = 18, /**< \brief Specifies the channel ID 18 */
    IfxSent_ChannelId_19   = 19, /**< \brief Specifies the Channel ID 19 */
    IfxSent_ChannelId_20   = 20, /**< \brief Specifies the Channel ID 20 */
    IfxSent_ChannelId_21   = 21, /**< \brief Specifies the Channel ID 21 */
    IfxSent_ChannelId_22   = 22, /**< \brief Specifies the Channel ID 22 */
    IfxSent_ChannelId_23   = 23, /**< \brief Specifies the Channel ID 23 */
    IfxSent_ChannelId_24   = 24, /**< \brief Specifies the Channel ID 24 */
    IfxSent_ChannelId_none = -1  /**< \brief None Sent channels */
} IfxSent_ChannelId;

#endif /* IFXSENT_CFG_TC37X_H */
