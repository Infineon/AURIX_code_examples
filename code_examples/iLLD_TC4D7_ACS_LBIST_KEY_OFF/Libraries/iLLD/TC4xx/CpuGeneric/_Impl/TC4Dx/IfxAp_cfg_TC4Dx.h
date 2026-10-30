/**
 * \file IfxAp_cfg_TC4Dx.h
 * \brief AP on-chip implementation data
 * \ingroup IfxLld_Ap
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
 * \defgroup IfxLld_Ap AP
 * \ingroup IfxLld
 * \defgroup IfxLld_Ap_Impl Implementation
 * \ingroup IfxLld_Ap
 * \defgroup IfxLld_Ap_Std Standard Driver
 * \ingroup IfxLld_Ap
 * \defgroup IfxLld_Ap_Impl_Default Constant Variable
 * \ingroup IfxLld_Ap_Impl
 */

#ifndef IFXAP_CFG_TC4DX_H
#define IFXAP_CFG_TC4DX_H 1

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include "Ifx_Types.h"
#if !defined(IFX_ILLD_PPU_USAGE)
#include "Cpu/Std/IfxCpu_Intrinsics.h"
#endif
#if defined(IFX_ILLD_PPU_USAGE)
#include "Ppu/Std/IfxPpu_Intrinsics.h"
#endif
#include "IfxCpu_reg.h"
#include "IfxLmu_reg.h"

/******************************************************************************/
/*-----------------------------------Macros-----------------------------------*/
/******************************************************************************/

#define IFXAP_NUM_DSPR (6)

#define IFXAP_NUM_PSPR (6)

#define IFXAP_NUM_DLMU (6)

#define IFXAP_NUM_LMU  (10)

/******************************************************************************/
/*-----------------------------Data Structures--------------------------------*/
/******************************************************************************/

/** \addtogroup IfxLld_Ap_Impl_Default
 * \{ */
/** \brief Configuration data structure of the memory Region
 */
typedef struct
{
    void *moduleAddress;         /**< \brief Module Address */
    void *memStartAddress;       /**< \brief Memory Start Address */
    void *memEndAddress;         /**< \brief Memory End Address */
} IfxAp_memoryRegion;

/******************************************************************************/
/*-------------------------------Enumerations---------------------------------*/
/******************************************************************************/

/** \brief PROT tagId definition
 */
typedef enum
{
    IfxApProt_TagId_cpu0d = 0,
    IfxApProt_TagId_cpu0ds,
    IfxApProt_TagId_cpu1d,
    IfxApProt_TagId_cpu1ds,
    IfxApProt_TagId_cpu2d,
    IfxApProt_TagId_cpu2ds,
    IfxApProt_TagId_cpu3d,
    IfxApProt_TagId_cpu3ds,
    IfxApProt_TagId_cpu4d,
    IfxApProt_TagId_cpu4ds,
    IfxApProt_TagId_cpu5d,
    IfxApProt_TagId_cpu5ds,
    IfxApProt_TagId_cpucsd,
    IfxApProt_TagId_cpucsds,
    IfxApProt_TagId_reserved14,
    IfxApProt_TagId_reserved15,
    IfxApProt_TagId_dma0t0,
    IfxApProt_TagId_dma0t1,
    IfxApProt_TagId_dma0t2,
    IfxApProt_TagId_dma0t3,
    IfxApProt_TagId_dma0t4,
    IfxApProt_TagId_dma0t5,
    IfxApProt_TagId_dma0t6,
    IfxApProt_TagId_dma0t7,
    IfxApProt_TagId_hssl0,
    IfxApProt_TagId_hssl1,
    IfxApProt_TagId_ppu0cbu,
    IfxApProt_TagId_gtm,
    IfxApProt_TagId_cbs,
    IfxApProt_TagId_pcie,
    IfxApProt_TagId_dret0,
    IfxApProt_TagId_dret1,
    IfxApProt_TagId_dma1t0,
    IfxApProt_TagId_dma1t1,
    IfxApProt_TagId_dma1t2,
    IfxApProt_TagId_dma1t3,
    IfxApProt_TagId_dma1t4,
    IfxApProt_TagId_dma1t5,
    IfxApProt_TagId_dma1t6,
    IfxApProt_TagId_dma1t7,
    IfxApProt_TagId_cpu0p,
    IfxApProt_TagId_cpu1p,
    IfxApProt_TagId_cpu2p,
    IfxApProt_TagId_cpu3p,
    IfxApProt_TagId_cpu4p,
    IfxApProt_TagId_cpu5p,
    IfxApProt_TagId_cpucsp,
    IfxApProt_TagId_reserved47,
    IfxApProt_TagId_gethc0,
    IfxApProt_TagId_gethc1,
    IfxApProt_TagId_gethc2,
    IfxApProt_TagId_gethc3,
    IfxApProt_TagId_gethc4,
    IfxApProt_TagId_gethc5,
    IfxApProt_TagId_gethc6,
    IfxApProt_TagId_gethc7,
    IfxApProt_TagId_ppu0stu,
    IfxApProt_TagId_sdmmc,
    IfxApProt_TagId_xspi,
    IfxApProt_TagId_reserved59,
    IfxApProt_TagId_reserved60,
    IfxApProt_TagId_reserved61,
    IfxApProt_TagId_trif,
    IfxApProt_TagId_reserved63
} IfxApProt_TagId;

/** \} */

/** \addtogroup IfxLld_Ap_Impl_Default
 * \{ */

/******************************************************************************/
/*-------------------Global Exported Variables/Constants----------------------*/
/******************************************************************************/
/** \brief DLMU Modules base address
 */
IFX_EXTERN IFX_CONST IfxAp_memoryRegion IfxAp_dlmuRegions[IFXAP_NUM_DLMU];

/** \brief DSPR Modules base address
 */
IFX_EXTERN IFX_CONST IfxAp_memoryRegion IfxAp_dsprRegions[IFXAP_NUM_DSPR];

/** \brief LMU Modules base address
 */
IFX_EXTERN IFX_CONST IfxAp_memoryRegion IfxAp_lmuRegions[IFXAP_NUM_LMU];

/** \brief PSPR Modules base address
 */
IFX_EXTERN IFX_CONST IfxAp_memoryRegion IfxAp_psprRegions[IFXAP_NUM_PSPR];

/** \} */

#endif /* IFXAP_CFG_TC4DX_H */
