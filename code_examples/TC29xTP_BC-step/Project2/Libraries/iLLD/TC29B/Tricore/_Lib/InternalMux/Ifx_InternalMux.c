/**
 * \file Ifx_InternalMux.c
 * \brief Mux configuration functions
 *
 * \version iLLD_1_0_1_9_0
 * \copyright Copyright (c) 2015 Infineon Technologies AG. All rights reserved.
 *
 *
 *                                 IMPORTANT NOTICE
 *
 *
 * Infineon Technologies AG (Infineon) is supplying this file for use
 * exclusively with Infineon's microcontroller products. This file can be freely
 * distributed within development tools that are supporting such microcontroller
 * products.
 *
 * THIS SOFTWARE IS PROVIDED "AS IS".  NO WARRANTIES, WHETHER EXPRESS, IMPLIED
 * OR STATUTORY, INCLUDING, BUT NOT LIMITED TO, IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE APPLY TO THIS SOFTWARE.
 * INFINEON SHALL NOT, IN ANY CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL,
 * OR CONSEQUENTIAL DAMAGES, FOR ANY REASON WHATSOEVER.
 *
 */

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include "Ifx_InternalMux.h"
#include "Cpu/Std/IfxCpu_Intrinsics.h"

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
        __ldmst((volatile void *)(muxCfg.regAddr), muxCfg.mask, muxCfg.value);
    }
}
