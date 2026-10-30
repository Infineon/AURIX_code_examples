/**
 * \file IfxMtu_cfg_TC37x.h
 * \brief Mtu on-chip implementation data
 * \ingroup IfxLld_Mtu
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
 * \defgroup IfxLld_Mtu MTU
 * \ingroup IfxLld
 * \defgroup IfxLld_Mtu_Impl Implementation
 * \ingroup IfxLld_Mtu
 * \defgroup IfxLld_Mtu_Std Standard Driver
 * \ingroup IfxLld_Mtu
 */

#ifndef IFXMTU_CFG_TC37X_H
#define IFXMTU_CFG_TC37X_H 1

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include "Cpu/Std/IfxCpu.h"
#include "Cpu/Std/IfxCpu_Intrinsics.h"
#include "IfxMtu_reg.h"

/******************************************************************************/
/*-----------------------------------Macros-----------------------------------*/
/******************************************************************************/

/** \brief Base address of first MBIST Control Block
 */
#define IFXMTU_MC_ADDRESS_BASE       (0xF0061000u)

/** \brief Number of MBIST Table items
 */
#define IFXMTU_NUM_MBIST_TABLE_ITEMS (96)

/** \brief Maximum number of tracked SRAM addresses (ETTR)
 */
#define IFXMTU_MAX_TRACKED_ADDRESSES (5)

/**
 * Conversion to SRAM address from Memory Mapped address
 */
#define IFXMTU_SCRAMBLED_RANGE_ADDR_DSPR0(memoryMapedAddr) (uint8)((memoryMapedAddr - 0x70000000) / (16 * 64))
#define IFXMTU_SCRAMBLED_RANGE_ADDR_DSPR1(memoryMapedAddr) (uint8)((memoryMapedAddr - 0x60000000) / (16 * 64))
#define IFXMTU_SCRAMBLED_RANGE_ADDR_DSPR2(memoryMapedAddr) (uint8)((memoryMapedAddr - 0x50000000) / (16 * 64))
#define IFXMTU_SCRAMBLED_RANGE_ADDR_PSPR0(memoryMapedAddr) (uint8)((memoryMapedAddr - 0x70100000) / (16 * 64))
#define IFXMTU_SCRAMBLED_RANGE_ADDR_PSPR1(memoryMapedAddr) (uint8)((memoryMapedAddr - 0x60100000) / (16 * 64))
#define IFXMTU_SCRAMBLED_RANGE_ADDR_PSPR2(memoryMapedAddr) (uint8)((memoryMapedAddr - 0x50100000) / (16 * 64))
#define IFXMTU_SCRAMBLED_RANGE_ADDR_DLMU0(memoryMapedAddr) (uint8)((memoryMapedAddr - 0x90000000) / (16 * 64))
#define IFXMTU_SCRAMBLED_RANGE_ADDR_DLMU1(memoryMapedAddr) (uint8)((memoryMapedAddr - 0x90010000) / (16 * 64))
#define IFXMTU_SCRAMBLED_RANGE_ADDR_DLMU2(memoryMapedAddr) (uint8)((memoryMapedAddr - 0x90020000) / (16 * 64))
/******************************************************************************/
/*-------------------------------Enumerations---------------------------------*/
/******************************************************************************/

/** \brief MBIST Selection
 */

typedef enum
{
    IfxMtu_MbistSel_none        = -1,
    IfxMtu_MbistSel_cpu0Dspr    = 0,
    IfxMtu_MbistSel_cpu0Dtag    = 1,
    IfxMtu_MbistSel_cpu0Pspr    = 2,
    IfxMtu_MbistSel_cpu0Ptag    = 3,
    IfxMtu_MbistSel_cpu0Dlmu    = 4,
    IfxMtu_MbistSel_cpu1Dspr    = 5,
    IfxMtu_MbistSel_cpu1Dtag    = 6,
    IfxMtu_MbistSel_cpu1Pspr    = 7,
    IfxMtu_MbistSel_cpu1Ptag    = 8,
    IfxMtu_MbistSel_cpu1Dlmu    = 9,
    IfxMtu_MbistSel_cpu2Dspr    = 10,
    IfxMtu_MbistSel_cpu2Dtag    = 11,
    IfxMtu_MbistSel_cpu2Pspr    = 12,
    IfxMtu_MbistSel_cpu2Ptag    = 13,
    IfxMtu_MbistSel_cpu2Dlmu    = 14,
    IfxMtu_MbistSel_cpu0Dspr1   = 34,
    IfxMtu_MbistSel_cpu1Dspr1   = 35,
    IfxMtu_MbistSel_dam0        = 38,
    IfxMtu_MbistSel_dma         = 41,
    IfxMtu_MbistSel_miniMcds    = 42,
    IfxMtu_MbistSel_gtmFifo     = 53,
    IfxMtu_MbistSel_gtmMcs0Fast = 55,
    IfxMtu_MbistSel_gtmMcs1Fast = 57,
    IfxMtu_MbistSel_gtmDpll1a   = 58,
    IfxMtu_MbistSel_gtmDpll1b   = 59,
    IfxMtu_MbistSel_gtmDpll2    = 60,
    IfxMtu_MbistSel_mcan0       = 62,
    IfxMtu_MbistSel_mcan1       = 63,
    IfxMtu_MbistSel_psi5        = 65,
    IfxMtu_MbistSel_eray0Obf    = 66,
    IfxMtu_MbistSel_eray0IbfTbf = 68,
    IfxMtu_MbistSel_eray0Mbf    = 70,
    IfxMtu_MbistSel_scrXram     = 77,
    IfxMtu_MbistSel_scrIram     = 78,
    IfxMtu_MbistSel_ethermacRx  = 82,
    IfxMtu_MbistSel_ethermacTx  = 83
}IfxMtu_MbistSel;

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
} IfxMtu_SramItem;

/******************************************************************************/
/*-------------------Global Exported Variables/Constants----------------------*/
/******************************************************************************/

IFX_EXTERN const IfxMtu_SramItem IfxMtu_sramTable[IFXMTU_NUM_MBIST_TABLE_ITEMS];

#endif /* IFXMTU_CFG_TC37X_H */
