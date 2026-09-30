/**
 * \file Ifx_InternalMux.c
 * \brief Mux configuration functions
 *
 * \version iLLD-TC4-v2.6.0
 * \copyright Copyright (c) 2026 Infineon Technologies AG. All rights reserved.
 *
 *
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
 */

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include "Ifx_InternalMux.h"
#if !defined(IFX_ILLD_PPU_USAGE)
#include "Cpu/Std/IfxCpu_Intrinsics.h"
#endif
#if defined(IFX_ILLD_PPU_USAGE)
#include "Ppu/Std/IfxPpu_Intrinsics.h"
#endif

/******************************************************************************/
/*-------------------------Function Implementations---------------------------*/
/******************************************************************************/

void Ifx_InternalMux_init(const Ifx_InternalMux_Config *cfg)
{
    int i;

    for (i = 0; i < cfg->size; i++)
    {
        Ifx_InternalMux_MuxConfig muxCfg = cfg->muxConfig[i];

        /*Load modify store operation done to insert the value to the register bit field*/
        Ifx__ldmst((volatile void *)(muxCfg.regAddr), muxCfg.mask, muxCfg.value);
    }
}
