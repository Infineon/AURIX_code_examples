/**
 * \file IfxSdmmc_cfg_TC4Dx.h
 * \brief SDMMC on-chip implementation data
 * \ingroup IfxLld_Sdmmc
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
 * \defgroup IfxLld_Sdmmc SDMMC
 * \ingroup IfxLld
 * \defgroup IfxLld_Sdmmc_Impl Implementation
 * \ingroup IfxLld_Sdmmc
 * \defgroup IfxLld_Sdmmc_Std Standard Driver
 * \ingroup IfxLld_Sdmmc
 */

#ifndef IFXSDMMC_CFG_TC4DX_H
#define IFXSDMMC_CFG_TC4DX_H 1

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include "Ifx_Types.h"
#include "IfxSdmmc_reg.h"

/******************************************************************************/
/*-----------------------------------Macros-----------------------------------*/
/******************************************************************************/

/** \brief Number of Modules
 */
#define IFXSDMMC_NUM_MODULES            (1)

/** \brief Maximum number of Commands
 */
#define IFXSDMMC_NUM_COMMANDS           (65)

#ifndef IFXSDMMC_SD_CLOCK_DISABLE_DELAY
/** \brief Delay in micro seconds post disable of clock using SDMMC_CLK_CTRL.SD_CLK_EN
 */
#define IFXSDMMC_SD_CLOCK_DISABLE_DELAY (600)
#endif

/******************************************************************************/
/*-------------------------------Enumerations---------------------------------*/
/******************************************************************************/

/** \brief List of the available Sdmmc resources
 */
typedef enum
{
    IfxSdmmc_Index_none = -1,  /**< \brief Not Selected */
    IfxSdmmc_Index_0    = 0    /**< \brief Sdmmc index 0 */
} IfxSdmmc_Index;

/******************************************************************************/
/*-------------------Global Exported Variables/Constants----------------------*/
/******************************************************************************/
IFX_EXTERN IFX_CONST IfxModule_IndexMap IfxSdmmc_cfg_indexMap[IFXSDMMC_NUM_MODULES];

#endif /* IFXSDMMC_CFG_TC4DX_H */
