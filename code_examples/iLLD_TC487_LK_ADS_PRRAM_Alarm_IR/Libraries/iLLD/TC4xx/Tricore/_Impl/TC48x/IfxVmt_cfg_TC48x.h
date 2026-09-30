/**
 * \file IfxVmt_cfg_TC48x.h
 * \brief VMT on-chip implementation data
 * \ingroup IfxLld_Vmt
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
 * \defgroup IfxLld_Vmt Vmt
 * \ingroup IfxLld
 * \defgroup IfxLld_Vmt_Impl Implementation
 * \ingroup IfxLld_Vmt
 * \defgroup IfxLld_Vmt_Std Standard Driver
 * \ingroup IfxLld_Vmt
 */

#ifndef IFXVMT_CFG_TC48X_H
#define IFXVMT_CFG_TC48X_H 1

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include "Cpu/Std/IfxCpu.h"
#include "_Impl/IfxSmu_cfg.h"

/******************************************************************************/
/*-----------------------------------Macros-----------------------------------*/
/******************************************************************************/

/** \brief Number of MBIST Table items
 */
#define IFXVMT_NUM_MBIST_TABLE_ITEMS (228)

/** \brief Maximum number of tracked SRAM addresses (ETTR)
 */
#define IFXVMT_MAX_TRACKED_ADDRESSES (5)

/** \brief Number of DMTUs
 */
#define IFXVMT_NUM_DMTU              (6)

/** \brief Derive fail position from rdbfls
 */
#define IFXVMT_GET_FAIL_POSITION              (FALSE)

/** \brief Vmt K1 Check
 */
#define IFXVMT_K1_CHECK                       (FALSE) 
       
/** \brief Vmt KX Test
 */
#define IFXVMT_KX_TEST                        (FALSE)

/** \brief Vmt KX Init
 */
#define IFXVMT_KX_INIT                        (FALSE)

/** \brief Vmt K3 Prepare Extract Store
 */
#define IFXVMT_K3_PREPARE_EXTRACT_STORE       (FALSE)

/******************************************************************************/
/*-------------------------------Enumerations---------------------------------*/
/******************************************************************************/

/** \brief MBIST Selection
 */

typedef enum
{
    IfxVmt_MbistSel_none               = -1,
    IfxVmt_MbistSel_cpu0Dspr           = 0,
    IfxVmt_MbistSel_cpu0Dtag           = 1,
    IfxVmt_MbistSel_cpu0Pspr           = 2,
    IfxVmt_MbistSel_cpu0Ptag           = 3,
    IfxVmt_MbistSel_cpu0DlmuStby       = 4,
    IfxVmt_MbistSel_dma                = 7,
    IfxVmt_MbistSel_mcds4pTbuf         = 8,
    IfxVmt_MbistSel_mcds4pLut          = 9,
    IfxVmt_MbistSel_cssKeyattr         = 268,
    IfxVmt_MbistSel_cssKeystore        = 269,
    IfxVmt_MbistSel_cssFifo0           = 270,
    IfxVmt_MbistSel_cssFifo1           = 271,
    IfxVmt_MbistSel_cssContext         = 272,
    IfxVmt_MbistSel_mcan0              = 19,
    IfxVmt_MbistSel_mcan1              = 20,
    IfxVmt_MbistSel_mcan2              = 21,
    IfxVmt_MbistSel_cpu3Dspr           = 32,
    IfxVmt_MbistSel_cpu3Dtag           = 33,
    IfxVmt_MbistSel_cpu3Pspr           = 34,
    IfxVmt_MbistSel_cpu3Ptag           = 35,
    IfxVmt_MbistSel_cpu3Dlmu           = 36,
    IfxVmt_MbistSel_csrmDspr           = 293,
    IfxVmt_MbistSel_csrmDtag           = 294,
    IfxVmt_MbistSel_csrmPspr           = 295,
    IfxVmt_MbistSel_csrmPtag           = 296,
    IfxVmt_MbistSel_mod8               = 297,
    IfxVmt_MbistSel_mcan3              = 50,
    IfxVmt_MbistSel_mcan4              = 51,
    IfxVmt_MbistSel_canxl              = 64,
    IfxVmt_MbistSel_dreRam             = 70,
    IfxVmt_MbistSel_hsphyPcs0          = 71,
    IfxVmt_MbistSel_sdmmc              = 73,
    IfxVmt_MbistSel_leth0Port0TxFifo   = 75,
    IfxVmt_MbistSel_leth0Port1TxFifo   = 76,
    IfxVmt_MbistSel_leth0Port2TxFifo   = 77,
    IfxVmt_MbistSel_leth0Port0RxFifo   = 78,
    IfxVmt_MbistSel_leth0Port1RxFifo   = 79,
    IfxVmt_MbistSel_leth0Port2RxFifo   = 80,
    IfxVmt_MbistSel_leth0Port0RxParser = 81,
    IfxVmt_MbistSel_leth0Port1RxParser = 82,
    IfxVmt_MbistSel_leth0Port2RxParser = 83,
    IfxVmt_MbistSel_leth0Port0Gcl      = 84,
    IfxVmt_MbistSel_leth0Port1Gcl      = 85,
    IfxVmt_MbistSel_leth0Port2Gcl      = 86,
    IfxVmt_MbistSel_ethermacDmi        = 88,
    IfxVmt_MbistSel_ethermacGcl        = 90,
    IfxVmt_MbistSel_xgmacRxTx          = 91,
    IfxVmt_MbistSel_psi5               = 96,
    IfxVmt_MbistSel_eray0Obf           = 98,
    IfxVmt_MbistSel_eray0IbfTbf        = 99,
    IfxVmt_MbistSel_eray0Mbf           = 100,
    IfxVmt_MbistSel_cdsp0Data          = 102,
    IfxVmt_MbistSel_cdsp0Prog          = 103,
    IfxVmt_MbistSel_scrXraml           = 128,
    IfxVmt_MbistSel_cpu1Dspr           = 160,
    IfxVmt_MbistSel_cpu1Dtag           = 161,
    IfxVmt_MbistSel_cpu1Pspr           = 162,
    IfxVmt_MbistSel_cpu1Ptag           = 163,
    IfxVmt_MbistSel_cpu1DlmuStby       = 164,
    IfxVmt_MbistSel_cpu2Dspr           = 165,
    IfxVmt_MbistSel_cpu2Dtag           = 166,
    IfxVmt_MbistSel_cpu2Pspr           = 167,
    IfxVmt_MbistSel_cpu2Ptag           = 168,
    IfxVmt_MbistSel_cpu2DlmuStby       = 169,
    IfxVmt_MbistSel_audioTdm           = 173,
    IfxVmt_MbistSel_audioMixerIn       = 174,
    IfxVmt_MbistSel_audioMixerOut      = 175,
}IfxVmt_MbistSel;

/******************************************************************************/
/*-----------------------------Data Structures--------------------------------*/
/******************************************************************************/

/** \brief Describes physical parameters of a SRAM memory
 */
typedef struct
{
    uint8  numBlocks;      /**< \brief number of SRAM blocks */
    uint16 dataSize;       /**< \brief Data Size of each memory block */
    uint8  eccSize;        /**< \brief ECC Size of each memory block */
    uint8  eccInvPos0;     /**< \brief First ECC bit which needs to be inverted */
    uint8  eccInvPos1;     /**< \brief Second ECC bit which needs to be inverted */
} IfxVmt_SramItem;

/** \brief Describes SSH Selection Config
 */
typedef struct
{
    uint32          vmtId;    /**< \brief DMTU instance */
    IfxVmt_MbistSel mc;       /**< \brief SSH Instance */
} IfxVmt_SshSelectionConfig;

/** \brief Describes number of SSH
 */
typedef struct
{
    uint8 nosshConfig;            /**< \brief number of SSH instance */
} IfxVmt_NumberOfSsh;

/******************************************************************************/
/*-------------------Global Exported Variables/Constants----------------------*/
/******************************************************************************/

IFX_EXTERN IFX_CONST IfxVmt_SramItem IfxVmt_sramTable[IFXVMT_NUM_MBIST_TABLE_ITEMS];

#endif /* IFXVMT_CFG_TC48X_H */
