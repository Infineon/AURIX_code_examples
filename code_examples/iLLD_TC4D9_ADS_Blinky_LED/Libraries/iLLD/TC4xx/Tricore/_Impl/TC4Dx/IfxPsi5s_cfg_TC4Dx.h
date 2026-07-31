/**
 * \file IfxPsi5s_cfg_TC4Dx.h
 * \brief PSI5S on-chip implementation data
 * \ingroup IfxLld_Psi5s
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
 * \defgroup IfxLld_Psi5s PSI5S
 * \ingroup IfxLld
 * \defgroup IfxLld_Psi5s_Impl Implementation
 * \ingroup IfxLld_Psi5s
 * \defgroup IfxLld_Psi5s_Std Standard Driver
 * \ingroup IfxLld_Psi5s
 */

#ifndef IFXPSI5S_CFG_TC4DX_H
#define IFXPSI5S_CFG_TC4DX_H 1

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include "Ifx_Types.h"
#include "IfxPsi5s_reg.h"

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

#define IFXPSI5S_GCR_CHANNEL_TRIGGER_COUNTERS_ENABLE_MASK         ((1 << IFXPSI5S_NUM_CHANNELS) - 1) << 8

#define IFXPSI5S_DEFAULT_SLOWCLOCK_FREQ                   		  4000000

#define IFXPSI5S_DEFAULT_FASTCLOCK_FREQ                   		  6000000

#define IFXPSI5S_DEFAULT_TIMESTAMP_FREQ                   		  1000000

#define IFXPSI5S_NUM_MODULES                              		  (1)

/******************************************************************************/
/*-------------------------------Enumerations---------------------------------*/
/******************************************************************************/

/** \brief List of the available Psi5s resources
 */
typedef enum
{
    IfxPsi5s_Index_none = -1,  /**< \brief Not Selected */
    IfxPsi5s_Index_0    = 0,   /**< \brief Psi5s index 0  */
} IfxPsi5s_Index;

/******************************************************************************/
/*-------------------Global Exported Variables/Constants----------------------*/
/******************************************************************************/
IFX_EXTERN IFX_CONST IfxModule_IndexMap IfxPsi5s_cfg_indexMap[IFXPSI5S_NUM_MODULES];

#endif /* IFXPSI5S_CFG_TC4DX_H */
