/**
 * \file IfxCcu6_cfg.h
 * \brief CCU6 on-chip implementation data
 * \ingroup IfxLld_Ccu6
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
 * \defgroup IfxLld_Ccu6 CCU6
 * \ingroup IfxLld
 * \defgroup IfxLld_Ccu6_Impl Implementation
 * \ingroup IfxLld_Ccu6
 * \defgroup IfxLld_Ccu6_Std Standard Driver
 * \ingroup IfxLld_Ccu6
 * \defgroup IfxLld_Ccu6_Impl_Enumerations Enumerations
 * \ingroup IfxLld_Ccu6_Impl
 */

#ifndef IFXCCU6_CFG_H
#define IFXCCU6_CFG_H 1

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include "Ifx_Cfg.h"

#if defined DEVICE_TC39XB
#include "TC39xB/IfxCcu6_cfg_TC39xB.h"
#elif defined DEVICE_TC38X
#include "TC38x/IfxCcu6_cfg_TC38x.h"
#elif defined DEVICE_TC38EVOX
#include "TC38EVOx/IfxCcu6_cfg_TC38EVOx.h"
#elif defined DEVICE_TC37XED
#include "TC37xED/IfxCcu6_cfg_TC37xED.h"
#elif defined DEVICE_TC37X
#include "TC37x/IfxCcu6_cfg_TC37x.h"
#elif defined DEVICE_TC36X
#include "TC36x/IfxCcu6_cfg_TC36x.h"
#elif defined DEVICE_TC35X
#include "TC35x/IfxCcu6_cfg_TC35x.h"
#elif defined DEVICE_TC33XED
#include "TC33xED/IfxCcu6_cfg_TC33xED.h"
#elif defined DEVICE_TC33X
#include "TC33x/IfxCcu6_cfg_TC33x.h"
#endif

#endif /* IFXCCU6_CFG_H */
