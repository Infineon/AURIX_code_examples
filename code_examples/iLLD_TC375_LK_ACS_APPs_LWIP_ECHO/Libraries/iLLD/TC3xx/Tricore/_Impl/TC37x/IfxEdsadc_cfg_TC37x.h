/**
 * \file IfxEdsadc_cfg_TC37x.h
 * \brief EDSADC on-chip implementation data
 * \ingroup IfxLld_Edsadc
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
 * \defgroup IfxLld_Edsadc EDSADC
 * \ingroup IfxLld
 * \defgroup IfxLld_Edsadc_Impl Implementation
 * \ingroup IfxLld_Edsadc
 * \defgroup IfxLld_Edsadc_Std Standard Driver
 * \ingroup IfxLld_Edsadc
 */

#ifndef IFXEDSADC_CFG_TC37X_H
#define IFXEDSADC_CFG_TC37X_H 1

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

/******************************************************************************/
/*-----------------------------------Macros-----------------------------------*/
/******************************************************************************/

#define IFXEDSADC_NUM_CHANNELS 6

#define IFXEDSADC_NUM_MODULES  (1)

/******************************************************************************/
/*-------------------------------Enumerations---------------------------------*/
/******************************************************************************/

/** \brief Specifies the channel Index
 */
typedef enum
{
    IfxEdsadc_ChannelId_0  = 0,   /**< \brief Specifies the channel Index 0 */
    IfxEdsadc_ChannelId_1  = 1,   /**< \brief Specifies the channel Index 1 */
    IfxEdsadc_ChannelId_2  = 2,   /**< \brief Specifies the channel Index 2 */
    IfxEdsadc_ChannelId_3  = 3,   /**< \brief Specifies the channel Index 3 */
    IfxEdsadc_ChannelId_4  = 4,   /**< \brief Specifies the channel Index 4 */
    IfxEdsadc_ChannelId_5  = 5   /**< \brief Specifies the channel Index 5 */
} IfxEdsadc_ChannelId;

#endif /* IFXEDSADC_CFG_TC37X_H */
