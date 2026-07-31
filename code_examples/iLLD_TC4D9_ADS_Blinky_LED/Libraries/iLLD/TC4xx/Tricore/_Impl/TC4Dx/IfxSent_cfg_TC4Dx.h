/**
 * \file IfxSent_cfg_TC4Dx.h
 * \brief SENT on-chip implementation data
 * \ingroup IfxLld_Sent
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
 * \defgroup IfxLld_Sent SENT
 * \ingroup IfxLld
 * \defgroup IfxLld_Sent_Impl Implementation
 * \ingroup IfxLld_Sent
 * \defgroup IfxLld_Sent_Std Standard Driver
 * \ingroup IfxLld_Sent
 */

#ifndef IFXSENT_CFG_TC4DX_H
#define IFXSENT_CFG_TC4DX_H 1

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include "Ifx_Types.h"
#include "IfxSent_reg.h"

/******************************************************************************/
/*-----------------------------------Macros-----------------------------------*/
/******************************************************************************/

/** \brief Number of Modules
 */
#define IFXSENT_NUM_MODULES       (2)

/** \brief Number of Channels
 */
#define IFXSENT_NUM_CHANNELS      (15)

/** \brief Specifies all interrupt events
 */
#define IFXSENT_CFG_CHANNEL_INTEN (0x1FEDU)

/** \brief Specifies the step range for calculating module clock
 */
#define IFXSENT_CFG_STEP_RANGE    (1024)

/** \brief Specifies timeout value in transmission
 */
#define IFXSENT_CFG_TIMEOUT_VALUE ((uint16)0xFFFFU)

/******************************************************************************/
/*-------------------------------Enumerations---------------------------------*/
/******************************************************************************/

/** \brief Specifies the channel Id
 */
typedef enum
{
    IfxSent_ChannelId_none = -1, /**< \brief None Sent channels */
    IfxSent_ChannelId_0,         /**< \brief Specifies the channel Id 0  */
    IfxSent_ChannelId_1,         /**< \brief Specifies the channel Id 1  */
    IfxSent_ChannelId_2,         /**< \brief Specifies the channel Id 2  */
    IfxSent_ChannelId_3,         /**< \brief Specifies the channel Id 3  */
    IfxSent_ChannelId_4,         /**< \brief Specifies the channel Id 4  */
    IfxSent_ChannelId_5,         /**< \brief Specifies the channel Id 5  */
    IfxSent_ChannelId_6,         /**< \brief Specifies the channel Id 6  */
    IfxSent_ChannelId_7,         /**< \brief Specifies the channel Id 7  */
    IfxSent_ChannelId_8,         /**< \brief Specifies the channel Id 8  */
    IfxSent_ChannelId_9,         /**< \brief Specifies the channel Id 9  */
    IfxSent_ChannelId_10,        /**< \brief Specifies the channel Id 10  */
    IfxSent_ChannelId_11,        /**< \brief Specifies the channel Id 11  */
    IfxSent_ChannelId_12,        /**< \brief Specifies the channel Id 12  */
    IfxSent_ChannelId_13,        /**< \brief Specifies the channel Id 13  */
    IfxSent_ChannelId_14         /**< \brief Specifies the channel Id 14  */
} IfxSent_ChannelId;

/** \brief List of the available Sent resources
 */
typedef enum
{
    IfxSent_Index_none = -1,  /**< \brief Not Selected */
    IfxSent_Index_0    = 0,   /**< \brief Sent index 0 */
    IfxSent_Index_1    = 1    /**< \brief Sent index 1 */
} IfxSent_Index;

/******************************************************************************/
/*-------------------Global Exported Variables/Constants----------------------*/
/******************************************************************************/
IFX_EXTERN IFX_CONST IfxModule_IndexMap IfxSent_cfg_indexMap[IFXSENT_NUM_MODULES];

#endif /* IFXSENT_CFG_TC4DX_H */
