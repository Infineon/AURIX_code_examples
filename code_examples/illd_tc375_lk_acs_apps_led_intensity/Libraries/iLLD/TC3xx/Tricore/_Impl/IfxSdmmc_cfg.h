/**
 * \file IfxSdmmc_cfg.h
 * \brief SDMMC on-chip implementation data
 * \ingroup IfxLld_Sdmmc
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
 * \defgroup IfxLld_Sdmmc SDMMC
 * \ingroup IfxLld
 * \defgroup IfxLld_Sdmmc_Impl Implementation
 * \ingroup IfxLld_Sdmmc
 * \defgroup IfxLld_Sdmmc_Std Standard Driver
 * \ingroup IfxLld_Sdmmc
 */

#ifndef IFXSDMMC_CFG_H
#define IFXSDMMC_CFG_H 1

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include "Ifx_Cfg.h"

#if defined DEVICE_TC39XB
#include "TC39xB/IfxSdmmc_cfg_TC39xB.h"
#elif defined DEVICE_TC38EVOX
#include "TC38EVOx/IfxSdmmc_cfg_TC38EVOx.h"
#elif defined DEVICE_TC37XED
#include "TC37xED/IfxSdmmc_cfg_TC37xED.h"
#elif defined DEVICE_TC33XED
#include "TC33xED/IfxSdmmc_cfg_TC33xED.h"
#endif

#endif /* IFXSDMMC_CFG_H */
