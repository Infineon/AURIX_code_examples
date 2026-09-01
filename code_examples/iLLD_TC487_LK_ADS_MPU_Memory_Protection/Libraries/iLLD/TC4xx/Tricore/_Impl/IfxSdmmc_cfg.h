/**
 * \file IfxSdmmc_cfg.h
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

#ifndef IFXSDMMC_CFG_H
#define IFXSDMMC_CFG_H 1

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include "Ifx_Cfg.h"

#if defined DEVICE_TC4DX
#include "TC4Dx/IfxSdmmc_cfg_TC4Dx.h"
#elif defined DEVICE_TC49XN
#include "TC49xN/IfxSdmmc_cfg_TC49xN.h"
#elif defined DEVICE_TC46X
#include "TC46x/IfxSdmmc_cfg_TC46x.h"
#elif defined DEVICE_TC44X
#include "TC44x/IfxSdmmc_cfg_TC44x.h"
#elif defined DEVICE_TC4ZX
#include "TC4Zx/IfxSdmmc_cfg_TC4Zx.h"
#elif defined DEVICE_TC48X
#include "TC48x/IfxSdmmc_cfg_TC48x.h"
#endif

#endif /* IFXSDMMC_CFG_H */
