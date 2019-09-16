/**
 * \file IfxMtu_cfg.h
 * \brief Mtu on-chip implementation data
 * \ingroup IfxLld_Mtu
 *
 * \version iLLD_1_0_1_9_0
 * \copyright Copyright (c) 2016 Infineon Technologies AG. All rights reserved.
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
 * \defgroup IfxLld_Mtu MTU
 * \ingroup IfxLld
 * \defgroup IfxLld_Mtu_Impl Implementation
 * \ingroup IfxLld_Mtu
 * \defgroup IfxLld_Mtu_Std Standard Driver
 * \ingroup IfxLld_Mtu
 */

#ifndef IFXMTU_CFG_H
#define IFXMTU_CFG_H 1

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include "Cpu/Std/IfxCpu.h"
#include "Cpu/Std/IfxCpu_Intrinsics.h"
#include "IfxMtu_reg.h"
#include "IfxMc_reg.h"

/******************************************************************************/
/*-----------------------------------Macros-----------------------------------*/
/******************************************************************************/

/** \brief Base address of first MBIST Control Block
 */
#define IFXMTU_MC_ADDRESS_BASE       (0xF0061000u)

/** \brief Number of MBIST Table items
 */
#define IFXMTU_NUM_MBIST_TABLE_ITEMS (88)

/** \brief Maximum number of tracked SRAM addresses (ETTR)
 */
#define IFXMTU_MAX_TRACKED_ADDRESSES (5)

/******************************************************************************/
/*-------------------------------Enumerations---------------------------------*/
/******************************************************************************/

/** \brief MBIST Selection
 */
typedef enum
{
    IfxMtu_MbistSel_none        = -1,
    IfxMtu_MbistSel_cpu2Dspr0   = 0,
    IfxMtu_MbistSel_cpu2Dtag    = 2,
    IfxMtu_MbistSel_cpu2Pspr    = 3,
    IfxMtu_MbistSel_cpu2Ptag    = 5,
    IfxMtu_MbistSel_cpu1Dspr0   = 6,
    IfxMtu_MbistSel_cpu1Dtag    = 8,
    IfxMtu_MbistSel_cpu1Pspr    = 9,
    IfxMtu_MbistSel_cpu1Ptag    = 11,
    IfxMtu_MbistSel_miniMcds    = 13,
    IfxMtu_MbistSel_cpu0Dspr    = 14,
    IfxMtu_MbistSel_cpu0Pspr    = 16,
    IfxMtu_MbistSel_cpu0Ptag    = 17,
    IfxMtu_MbistSel_cpu0Dtag    = 19,
    IfxMtu_MbistSel_cpu1Dspr1   = 20,
    IfxMtu_MbistSel_cpu2Dspr1   = 21,
    IfxMtu_MbistSel_ethermac    = 22,
    IfxMtu_MbistSel_mod1        = 23,
    IfxMtu_MbistSel_mod2        = 24,
    IfxMtu_MbistSel_mod3        = 25,
    IfxMtu_MbistSel_mod4        = 26,
    IfxMtu_MbistSel_gtmFifo     = 28,
    IfxMtu_MbistSel_gtmMcs0     = 29,
    IfxMtu_MbistSel_gtmMcs1     = 30,
    IfxMtu_MbistSel_gtmDpll1a   = 31,
    IfxMtu_MbistSel_gtmDpll1b   = 32,
    IfxMtu_MbistSel_gtmDpll2    = 33,
    IfxMtu_MbistSel_psi5        = 34,
    IfxMtu_MbistSel_mcan        = 36,
    IfxMtu_MbistSel_mcan1       = 37,
    IfxMtu_MbistSel_erayObf     = 38,
    IfxMtu_MbistSel_erayIbfTbf  = 39,
    IfxMtu_MbistSel_erayMbf     = 40,
    IfxMtu_MbistSel_eray1Obf    = 41,
    IfxMtu_MbistSel_eray1IbfTbf = 42,
    IfxMtu_MbistSel_eray1Mbf    = 43,
    IfxMtu_MbistSel_mcds        = 45,
    IfxMtu_MbistSel_emem0       = 46,
    IfxMtu_MbistSel_emem1       = 47,
    IfxMtu_MbistSel_emem2       = 48,
    IfxMtu_MbistSel_emem3       = 49,
    IfxMtu_MbistSel_emem4       = 50,
    IfxMtu_MbistSel_emem5       = 51,
    IfxMtu_MbistSel_emem6       = 52,
    IfxMtu_MbistSel_emem7       = 53,
    IfxMtu_MbistSel_emem8       = 54,
    IfxMtu_MbistSel_emem9       = 55,
    IfxMtu_MbistSel_emem10      = 56,
    IfxMtu_MbistSel_emem11      = 57,
    IfxMtu_MbistSel_emem12      = 58,
    IfxMtu_MbistSel_emem13      = 59,
    IfxMtu_MbistSel_emem14      = 60,
    IfxMtu_MbistSel_emem15      = 61,
    IfxMtu_MbistSel_ememUpper0  = 62,
    IfxMtu_MbistSel_ememUpper1  = 63,
    IfxMtu_MbistSel_ememUpper2  = 64,
    IfxMtu_MbistSel_ememUpper3  = 65,
    IfxMtu_MbistSel_ememUpper4  = 66,
    IfxMtu_MbistSel_ememUpper5  = 67,
    IfxMtu_MbistSel_ememUpper6  = 68,
    IfxMtu_MbistSel_ememUpper7  = 69,
    IfxMtu_MbistSel_ememUpper8  = 70,
    IfxMtu_MbistSel_ememUpper9  = 71,
    IfxMtu_MbistSel_ememUpper10 = 72,
    IfxMtu_MbistSel_ememUpper11 = 73,
    IfxMtu_MbistSel_ememUpper12 = 74,
    IfxMtu_MbistSel_ememUpper13 = 75,
    IfxMtu_MbistSel_ememUpper14 = 76,
    IfxMtu_MbistSel_ememUpper15 = 77,
    IfxMtu_MbistSel_cifJpeg1_4  = 78,
    IfxMtu_MbistSel_lmu         = 79,
    IfxMtu_MbistSel_cifJpeg3    = 80,
    IfxMtu_MbistSel_cifCif      = 81,
    IfxMtu_MbistSel_dma         = 83,
    IfxMtu_MbistSel_ememXtm0    = 84,
    IfxMtu_MbistSel_ememXtm1    = 85,
    IfxMtu_MbistSel_fft0        = 86,
    IfxMtu_MbistSel_fft1        = 87
} IfxMtu_MbistSel;

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
    uint32 mbistDelay;     /**< \brief Mbist Delay  */
} IfxMtu_SramItem;

/******************************************************************************/
/*-------------------Global Exported Variables/Constants----------------------*/
/******************************************************************************/

IFX_EXTERN const IfxMtu_SramItem IfxMtu_sramTable[IFXMTU_NUM_MBIST_TABLE_ITEMS];

#endif /* IFXMTU_CFG_H */
