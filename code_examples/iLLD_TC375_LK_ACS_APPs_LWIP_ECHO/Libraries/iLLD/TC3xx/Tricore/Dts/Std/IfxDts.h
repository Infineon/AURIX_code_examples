/**
 * \file IfxDts.h
 * \brief DTS  basic functionality
 * \ingroup IfxLld_Dts
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
 * \defgroup IfxLld_Dts_Std_Control Control functions
 * \ingroup IfxLld_Dts_Std
 * \defgroup IfxLld_Dts_Std_Status Status functions
 * \ingroup IfxLld_Dts_Std
 */

#ifndef IFXDTS_H
#define IFXDTS_H 1

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include "_Impl/IfxDts_cfg.h"
#include "IfxPms_reg.h"
#include "IfxPms_bf.h"
#include "Cpu/Std/IfxCpu_Intrinsics.h"
#include "Src/Std/IfxSrc.h"

/** \addtogroup IfxLld_Dts_Std_Status
 * \{ */

/******************************************************************************/
/*-------------------------Inline Function Prototypes-------------------------*/
/******************************************************************************/

/**
 * \brief Retrieves the address of the interrupt request source register.
 *
 * \retval Ifx_SRC_SRCR Pointer to the interrupt source control register.
 */
IFX_INLINE volatile Ifx_SRC_SRCR *IfxDts_getSrcPointer(void);

/**
 * \brief Reads the temperature measurement result.
 * 
 * \retval uint16 The temperature measurement result as returned by the DTS.
 *         		  Range: 0 to 0xFFF
 */
IFX_INLINE uint16 IfxDts_getTemperatureValue(void);

/** \} */

/******************************************************************************/
/*---------------------Inline Function Implementations------------------------*/
/******************************************************************************/

IFX_INLINE volatile Ifx_SRC_SRCR *IfxDts_getSrcPointer(void)
{
    return &SRC_PMSDTS;
}


IFX_INLINE uint16 IfxDts_getTemperatureValue(void)
{
    return (uint16)MODULE_PMS.DTSSTAT.B.RESULT;
}


#endif /* IFXDTS_H */
