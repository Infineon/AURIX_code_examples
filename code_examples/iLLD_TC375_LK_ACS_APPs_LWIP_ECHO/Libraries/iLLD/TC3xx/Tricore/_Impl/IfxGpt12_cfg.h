/**
 * \file IfxGpt12_cfg.h
 * \brief GPT12 on-chip implementation data
 * \ingroup IfxLld_Gpt12
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
 * \defgroup IfxLld_Gpt12 GPT12
 * \ingroup IfxLld
 * \defgroup IfxLld_Gpt12_Impl Implementation
 * \ingroup IfxLld_Gpt12
 * \defgroup IfxLld_Gpt12_Std Standard Driver
 * \ingroup IfxLld_Gpt12
 */

#ifndef IFXGPT12_CFG_H
#define IFXGPT12_CFG_H 1

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include "Ifx_Cfg.h"

#if defined DEVICE_TC39XB
#include "TC39xB/IfxGpt12_cfg_TC39xB.h"
#elif defined DEVICE_TC38X
#include "TC38x/IfxGpt12_cfg_TC38x.h"
#elif defined DEVICE_TC38EVOX
#include "TC38EVOx/IfxGpt12_cfg_TC38EVOx.h"
#elif defined DEVICE_TC37XED
#include "TC37xED/IfxGpt12_cfg_TC37xED.h"
#elif defined DEVICE_TC37X
#include "TC37x/IfxGpt12_cfg_TC37x.h"
#elif defined DEVICE_TC36X
#include "TC36x/IfxGpt12_cfg_TC36x.h"
#elif defined DEVICE_TC35X
#include "TC35x/IfxGpt12_cfg_TC35x.h"
#elif defined DEVICE_TC33XED
#include "TC33xED/IfxGpt12_cfg_TC33xED.h"
#elif defined DEVICE_TC33X
#include "TC33x/IfxGpt12_cfg_TC33x.h"
#endif

#endif /* IFXGPT12_CFG_H */
