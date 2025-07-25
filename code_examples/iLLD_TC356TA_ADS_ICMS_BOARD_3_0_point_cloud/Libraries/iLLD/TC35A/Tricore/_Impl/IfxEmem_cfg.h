/**
 * \file IfxEmem_cfg.h
 * \brief EMEM on-chip implementation data
 * \ingroup IfxLld_Emem
 *
 * \version iLLD_1_0_1_16_1
 * \copyright Copyright (c) 2018 Infineon Technologies AG. All rights reserved.
 *
 *
 *                                 IMPORTANT NOTICE
 *
 * Use of this file is subject to the terms of use agreed between (i) you or
 * the company in which ordinary course of business you are acting and (ii)
 * Infineon Technologies AG or its licensees. If and as long as no such terms
 * of use are agreed, use of this file is subject to following:
 *
 * Boost Software License - Version 1.0 - August 17th, 2003
 *
 * Permission is hereby granted, free of charge, to any person or organization
 * obtaining a copy of the software and accompanying documentation covered by
 * this license (the "Software") to use, reproduce, display, distribute,
 * execute, and transmit the Software, and to prepare derivative works of the
 * Software, and to permit third-parties to whom the Software is furnished to
 * do so, all subject to the following:
 *
 * The copyright notices in the Software and this entire statement, including
 * the above license grant, this restriction and the following disclaimer, must
 * be included in all copies of the Software, in whole or in part, and all
 * derivative works of the Software, unless such copies or derivative works are
 * solely in the form of machine-executable object code generated by a source
 * language processor.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT
 * SHALL THE COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE
 * FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN CONTRACT, TORT OR OTHERWISE,
 * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
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
#include "IfxEmem_mpu_reg.h"
#include "IfxEmem_reg.h"

/******************************************************************************/
/*-----------------------------------Macros-----------------------------------*/
/******************************************************************************/

#define IFXEMEM_START_ADDR_CPU_CACHED     0x99000000UL

#define IFXEMEM_START_ADDR_CPU            0xB9000000UL

#define IFXEMEM_START_ADDR_BBB            (0xB9000000UL)

#define IFXEMEM_SIZE                      (0x200000UL)

#define IFXEMEM_XAM_START_ADDR_CPU_CACHED (0x9F100000UL)

#define IFXEMEM_XAM_START_ADDR_CPU        (0xBF100000UL)

#define IFXEMEM_XAM_START_ADDR_BBB        (0xAF100000UL)

#define IFXEMEM_NUM_MODULES               (1)

#define IFXEMEM_NUM_MPU_MODULES           (2)

/** \brief Emem bus size in bytes
 */
#define IFXEMEM_BUS_SIZE                  (256 / 8)

/******************************************************************************/
/*-------------------------------Enumerations---------------------------------*/
/******************************************************************************/

/** \brief List of the available EMEM MPU instances
 */
typedef enum
{
    IfxEmem_MpuIndex_0    = 0,  /**< \brief EMEM Module MPU 0 */
    IfxEmem_MpuIndex_1    = 1,  /**< \brief EMEM Module MPU 1 */
    IfxEmem_MpuIndex_none = -1  /**< \brief Not selected */
} IfxEmem_MpuIndex;

/******************************************************************************/
/*-------------------Global Exported Variables/Constants----------------------*/
/******************************************************************************/

IFX_EXTERN IFX_CONST IfxModule_IndexMap IfxEmem_cfg_indexMap[IFXEMEM_NUM_MPU_MODULES];

#endif /* IFXEMEM_CFG_H */
