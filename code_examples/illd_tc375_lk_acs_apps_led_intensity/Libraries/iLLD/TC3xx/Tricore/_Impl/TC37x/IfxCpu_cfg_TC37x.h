/**
 * \file IfxCpu_cfg_TC37x.h
 * \brief CPU on-chip implementation data
 * \ingroup IfxLld_Cpu
 *
 * \version iLLD_1_22_0
 * \copyright Copyright (c) 2026 Infineon Technologies AG. All rights reserved.
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
 * \defgroup IfxLld_Cpu CPU
 * \ingroup IfxLld
 * \defgroup IfxLld_Cpu_Impl Implementation
 * \ingroup IfxLld_Cpu
 * \defgroup IfxLld_Cpu_Std Standard Driver
 * \ingroup IfxLld_Cpu
 */

#ifndef IFXCPU_CFG_TC37X_H
#define IFXCPU_CFG_TC37X_H 1

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include "Cpu/Std/IfxCpu_Intrinsics.h"
#include "IfxCpu_reg.h"

/******************************************************************************/
/*-----------------------------------Macros-----------------------------------*/
/******************************************************************************/

/** \brief CPU count
 */
#define IFXCPU_NUM_MODULES            (3)

/** \brief Segment number of cachable flash region
 */
#define IFXCPU_CACHABLE_FLASH_SEGMENT (8)

/** \brief Segment number of cachable LMU region
 */
#define IFXCPU_CACHABLE_LMU_SEGMENT   (9)

/** \brief All cores (coreIDs) mask. This macro can be defined by the user according to the number of core being enabled.
 * So that can be used for syncronisation among multiple cores. In case user didn't define this macro, by default this
 * mask will be generated for all the available cores of the device.
 * e.g:
 * 1. Check for synchronisation between core 0 and core 5
 * # define 0x41U
 * 2. Check for synchronisation between core 0 to core 5
 * # define 0x5FU
 *
 * Note:
 * Core id values read from CORE_ID register will be as shown below. The value
 * indicates the position of the bit needs to be set while building the macro.
 * Core 0: 0
 * Core 1: 1
 * Core 2: 2
 * Core 3: 3
 * Core 4: 4
 * Core 5: 6
 */
#ifndef IFXCPU_CFG_ALLCORE_DONE
#define IFXCPU_CFG_ALLCORE_DONE       (0x7)
#endif

/** \brief
 */
#ifndef IFXCPU_ALLCORE_DONE
#define IFXCPU_ALLCORE_DONE           IFXCPU_CFG_ALLCORE_DONE
#else
#ifdef __TASKING__
# pragma message("IFXCPU_ALLCORE_DONE macro is going to be deprecated. Use IFXCPU_CFG_ALLCORE_DONE instead.")
#else
# warning IFXCPU_ALLCORE_DONE macro is going to be deprecated. Use IFXCPU_CFG_ALLCORE_DONE instead.
#endif
#endif

/******************************************************************************/
/*-------------------------------Enumerations---------------------------------*/
/******************************************************************************/

/** \brief Halt status
 */
typedef enum
{
    IfxCpu_DBGST_HALT_run  = 0,
    IfxCpu_DBGST_HALT_halt = 1
} IfxCpu_DBGST_HALT;

/** \brief List of the available CPU ids
 */
typedef enum
{
    IfxCpu_Id_0 = 0,  /**< \brief CPU 0 */
    IfxCpu_Id_1 = 1,  /**< \brief CPU 1 */
    IfxCpu_Id_2 = 2,  /**< \brief CPU 2 */
    IfxCpu_Id_none    /**< \brief None of the CPU */
} IfxCpu_Id;

/** \brief List of the available CPU resources
 */
typedef enum
{
    IfxCpu_Index_0 = 0,  /**< \brief CPU 0 */
    IfxCpu_Index_1 = 1,  /**< \brief CPU 1 */
    IfxCpu_Index_2 = 2,  /**< \brief CPU 2 */
    IfxCpu_Index_none    /**< \brief None of the CPU */
} IfxCpu_Index;

/** \brief Power management status
 */
typedef enum
{
    IfxCpu_PMCSR_PMST_normalMode         = 1,
    IfxCpu_PMCSR_PMST_idleModeRequest    = 2,
    IfxCpu_PMCSR_PMST_idleMode           = 3,
    IfxCpu_PMCSR_PMST_sleepModeRequest   = 4,
    IfxCpu_PMCSR_PMST_standbyModeRequest = 6
} IfxCpu_PMCSR_PMST;

/** \brief List of the available CPU resources
 */
typedef enum
{
    IfxCpu_ResourceCpu_0    = IfxCpu_Index_0,    /**< \brief CPU 0 */
    IfxCpu_ResourceCpu_1    = IfxCpu_Index_1,    /**< \brief CPU 1 */
    IfxCpu_ResourceCpu_2    = IfxCpu_Index_2,    /**< \brief CPU 2 */
    IfxCpu_ResourceCpu_none = IfxCpu_Index_none  /**< \brief None of the CPU */
} IfxCpu_ResourceCpu;

/******************************************************************************/
/*-------------------Global Exported Variables/Constants----------------------*/
/******************************************************************************/

IFX_EXTERN IFX_CONST IfxModule_IndexMap IfxCpu_cfg_indexMap[IFXCPU_NUM_MODULES];

#endif /* IFXCPU_CFG_TC37X_H */
