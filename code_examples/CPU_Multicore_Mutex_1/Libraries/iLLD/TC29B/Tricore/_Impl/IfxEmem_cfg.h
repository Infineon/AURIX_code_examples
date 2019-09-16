/**
 * \file IfxEmem_cfg.h
 * \brief EMEM on-chip implementation data
 * \ingroup IfxLld_Emem
 *
 * \version iLLD_1_0_1_9_0
 * \copyright Copyright (c) 2017 Infineon Technologies AG. All rights reserved.
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
 * \defgroup IfxLld_Emem EMEM
 * \ingroup IfxLld
 * \defgroup IfxLld_Emem_Impl Implementation
 * \ingroup IfxLld_Emem
 * \defgroup IfxLld_Emem_Std Standard Driver
 * \ingroup IfxLld_Emem
 */

#ifndef IFXEMEM_CFG_H
#define IFXEMEM_CFG_H 1

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include "Cpu/Std/Ifx_Types.h"
#include "IfxEmem_reg.h"

/******************************************************************************/
/*-----------------------------------Macros-----------------------------------*/
/******************************************************************************/

#define IFXEMEM_START_ADDR_CPU_CACHED     0x9F000000UL

#define IFXEMEM_START_ADDR_CPU            0xBF000000UL

#define IFXEMEM_START_ADDR_BBB            (0xAF000000UL)

#define IFXEMEM_SIZE                      (0x200000UL)

#define IFXEMEM_XAM_START_ADDR_CPU_CACHED (0x9F100000UL)

#define IFXEMEM_XAM_START_ADDR_CPU        (0xBF100000UL)

#define IFXEMEM_XAM_START_ADDR_BBB        (0xAF100000UL)

#define IFXEMEM_NUM_MODULES               (1)

/******************************************************************************/
/*-------------------------------Enumerations---------------------------------*/
/******************************************************************************/

#endif /* IFXEMEM_CFG_H */
