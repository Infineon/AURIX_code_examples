/**
 * \file IfxCpu_cfg_TC4Dx.h
 * \brief CPU on-chip implementation data
 * \ingroup IfxLld_Cpu
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
 * \defgroup IfxLld_Cpu CPU
 * \ingroup IfxLld
 * \defgroup IfxLld_Cpu_Impl Implementation
 * \ingroup IfxLld_Cpu
 * \defgroup IfxLld_Cpu_Std Standard Driver
 * \ingroup IfxLld_Cpu
 */

#ifndef IFXCPU_CFG_TC4DX_H 
#define IFXCPU_CFG_TC4DX_H 1

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include "Ifx_Types.h"
#include "IfxCpu_reg.h"

/******************************************************************************/
/*-----------------------------------Macros-----------------------------------*/
/******************************************************************************/

/** \brief Number of Modules
 */
#define IFXCPU_NUM_MODULES            (7)

/** \brief SAFE CPU count
 */
#define IFXCPU_NUM_SAFE_MODULES       (6)

/** \brief Segment number of cachable flash region
 */
#define IFXCPU_CACHABLE_FLASH_SEGMENT (8)

/** \brief Segment number of cachable LMU region
 */
#define IFXCPU_CACHABLE_LMU_SEGMENT   (9)

/** \brief Data-Cache line size in bits
 */
#define IFXCPU_DCACHE_LINE_SIZE       (256)

/** \brief Program-Cache line size in bits
 */
#define IFXCPU_PCACHE_LINE_SIZE       (256)

/******************************************************************************/
/*-------------------------------Enumerations---------------------------------*/
/******************************************************************************/

/** \brief List of the available CPU Ids
 */
typedef enum
{
    IfxCpu_Id_none = -1,  /**< \brief None of the CPU */
    IfxCpu_Id_0    = 0,   /**< \brief CPU 0 */
    IfxCpu_Id_1    = 1,   /**< \brief CPU 1 */
    IfxCpu_Id_2    = 2,   /**< \brief CPU 2 */
    IfxCpu_Id_3    = 3,   /**< \brief CPU 3 */
    IfxCpu_Id_4    = 4,   /**< \brief CPU 4 */
    IfxCpu_Id_5    = 5,   /**< \brief CPU 5 */
    IfxCpu_Id_6    = 6    /**< \brief CPU 6 */
} IfxCpu_Id;

/** \brief List of the available CPU Resources
 */
typedef enum
{
    IfxCpu_Index_none = -1,  /**< \brief Not Selected */
    IfxCpu_Index_0    = 0,   /**< \brief CPU index 0 */
    IfxCpu_Index_1    = 1,   /**< \brief CPU index 1 */
    IfxCpu_Index_2    = 2,   /**< \brief CPU index 2 */
    IfxCpu_Index_3    = 3,   /**< \brief CPU index 3 */
    IfxCpu_Index_4    = 4,   /**< \brief CPU index 4 */
    IfxCpu_Index_5    = 5,   /**< \brief CPU index 5 */
    IfxCpu_Index_6    = 6    /**< \brief CPU index 6 */
} IfxCpu_Index;

/** \brief List of the available CPU Resources
 */
typedef enum
{
    IfxCpu_ResourceCpu_none = -1,             /**< \brief None of the CPU */
    IfxCpu_ResourceCpu_0    = IfxCpu_Index_0, /**< \brief CPU 0 */
    IfxCpu_ResourceCpu_1    = IfxCpu_Index_1, /**< \brief CPU 1 */
    IfxCpu_ResourceCpu_2    = IfxCpu_Index_2, /**< \brief CPU 2 */
    IfxCpu_ResourceCpu_3    = IfxCpu_Index_3, /**< \brief CPU 3 */
    IfxCpu_ResourceCpu_4    = IfxCpu_Index_4, /**< \brief CPU 4 */
    IfxCpu_ResourceCpu_5    = IfxCpu_Index_5, /**< \brief CPU 5 */
    IfxCpu_ResourceCpu_6    = IfxCpu_Index_6  /**< \brief CPU 6 */
} IfxCpu_ResourceCpu;

/** \brief Halt status
 */
typedef enum
{
    IfxCpu_DBGST_HALT_run  = 0,
    IfxCpu_DBGST_HALT_halt = 1
} IfxCpu_DBGST_HALT;

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

/** \brief Virtual Machine id
 */
typedef enum
{
    IfxCpu_vmId_none = -1,  /**< \brief Not Selected */
    IfxCpu_vmId_0    = 0,   /**< \brief IfxCpu_vmId0  */
    IfxCpu_vmId_1,          /**< \brief IfxCpu_vmId1  */
    IfxCpu_vmId_2,          /**< \brief IfxCpu_vmId2  */
    IfxCpu_vmId_3,          /**< \brief IfxCpu_vmId3  */
    IfxCpu_vmId_4,          /**< \brief IfxCpu_vmId4  */
    IfxCpu_vmId_5,          /**< \brief IfxCpu_vmId5  */
    IfxCpu_vmId_6,          /**< \brief IfxCpu_vmId6  */
    IfxCpu_vmId_7           /**< \brief IfxCpu_vmId7  */
} IfxCpu_vmId;

/******************************************************************************/
/*-------------------Global Exported Variables/Constants----------------------*/
/******************************************************************************/

IFX_EXTERN IFX_CONST IfxModule_IndexMap IfxCpu_cfg_indexMap[IFXCPU_NUM_MODULES];

#endif /* IFXCPU_CFG_TC4DX_H */
