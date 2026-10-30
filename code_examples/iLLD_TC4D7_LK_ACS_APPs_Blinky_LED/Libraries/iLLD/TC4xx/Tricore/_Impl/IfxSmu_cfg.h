/**
 * \file IfxSmu_cfg.h
 * \brief SMU on-chip implementation data
 * \ingroup IfxLld_Smu
 *
 * \version iLLD-TC4-v2.6.0
 * \copyright Copyright (c) 2026 Infineon Technologies AG. All rights reserved.
 *
 * Date: 2025-10-09 08:35:30
 *
 * Version: MC_ACE_A3G_HWA_SMU/V0.4.1.1.0
 *                                 IMPORTANT NOTICE
 *
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
 *
 * \defgroup IfxLld_Smu SMU
 * \ingroup IfxLld
 * \defgroup IfxLld_Smu_Impl Implementation
 * \ingroup IfxLld_Smu
 * \defgroup IfxLld_Smu_Std Standard Driver
 * \ingroup IfxLld_Smu
 * \defgroup IfxLld_Smu_Impl_Enum_AlarmGroup Alarm Group Enumeration
 * \ingroup IfxLld_Smu_Impl
 * \defgroup IfxLld_Smu_Impl_Enum_ListAlarms List of Alarms Enumeration
 * \ingroup IfxLld_Smu_Impl
 */

#ifndef IFXSMU_CFG_H
#define IFXSMU_CFG_H 1

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include "Ifx_Cfg.h"

#if defined DEVICE_TC4DX
#include "TC4Dx/IfxSmu_cfg_TC4Dx.h"
#elif defined DEVICE_TC49XN
#include "TC49xN/IfxSmu_cfg_TC49xN.h"
#elif defined DEVICE_TC44X
#include "TC44x/IfxSmu_cfg_TC44x.h"
#elif defined DEVICE_TC45X
#include "TC45x/IfxSmu_cfg_TC45x.h"
#elif defined DEVICE_TC46X
#include "TC46x/IfxSmu_cfg_TC46x.h"
#elif defined DEVICE_TC48XAA
#include "TC48xAA/IfxSmu_cfg_TC48xAA.h"
#elif defined DEVICE_TC48X
#include "TC48x/IfxSmu_cfg_TC48x.h"
#elif defined DEVICE_TC4ZX
#include "TC4Zx/IfxSmu_cfg_TC4Zx.h"
#elif defined DEVICE_TC4EX
#include "TC4Ex/IfxSmu_cfg_TC4Ex.h"
#elif defined DEVICE_TC4PX
#include "TC4Px/IfxSmu_cfg_TC4Px.h"
#endif

#endif /* IFXSMU_CFG_H */
