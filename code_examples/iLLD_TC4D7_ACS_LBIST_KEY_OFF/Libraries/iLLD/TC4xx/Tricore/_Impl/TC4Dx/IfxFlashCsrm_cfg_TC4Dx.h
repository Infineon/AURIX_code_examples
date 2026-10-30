/**
 * \file IfxFlashCsrm_cfg_TC4Dx.h
 * \brief FLASHCSRM on-chip implementation data
 * \ingroup IfxLld_FlashCsrm
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
 * \defgroup IfxLld_FlashCsrm FLASHCSRM
 * \ingroup IfxLld
 * \defgroup IfxLld_FlashCsrm_Impl Implementation
 * \ingroup IfxLld_FlashCsrm
 * \defgroup IfxLld_FlashCsrm_Std Standard Driver
 * \ingroup IfxLld_FlashCsrm
 */

#ifndef IFXFLASHCSRM_CFG_TC4DX_H
#define IFXFLASHCSRM_CFG_TC4DX_H 1

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include "Ifx_Types.h"

/******************************************************************************/
/*-----------------------------------Macros-----------------------------------*/
/******************************************************************************/

/** \brief base address for CSCI command sequences
 */
#define IFXFLASHCSRM_CMD_BASE_ADDRESS            (0xF80C0000)

/** \brief Offset between CSRM command areas.
 */
#define IFXFLASHCSRM_CMD_BASE_OFFSET             (0x0x00040000)

/** \brief Number of CSRM DFLASH Banks
 */
#define IFXFLASHCSRM_DFLASH_BANKS                (1)

/** \brief CSRM DFLASH logical sector count
 */
#define IFXFLASHCSRM_DFLASH_NUM_LOG_SECTORS      (64)

/** \brief CSRM PFLASH Start Address
 */
#define IFXFLASHCSRM_PFLASH_START                (0xA4000000)

/** \brief CSRM PFLASH size
 */
#define IFXFLASHCSRM_PFLASH_SIZE                 (0x100000)

/** \brief CSRM PFLASH end address
 */
#define IFXFLASHCSRM_PFLASH_END                  (IFXFLASHCSRM_PFLASH_START + IFXFLASHCSRM_PFLASH_SIZE - 1)

/** \brief CSRM DFLASH CFS logical sector count
 */
#define IFXFLASHCSRM_DFLASH_NUM_CFS_LOG_SECTORS  (22)

/** \brief CSRM DFLASH UCB logical sector count
 */
#define IFXFLASHCSRM_DFLASH_NUM_UCB_LOG_SECTORS  (26)

/** \brief CSRM DFLASH Physical sector count
 */
#define IFXFLASHCSRM_DFLASH_NUM_PHYSICAL_SECTORS (2)

/** \brief CSRM PFLASH logical sector count
 */
#define IFXFLASHCSRM_PFLASH_NUM_LOG_SECTORS      (64)

/** \brief CSRM PFLASH Physical sector count
 */
#define IFXFLASHCSRM_PFLASH_NUM_PHYSICAL_SECTORS (2)

/** \brief CSRM DFLASH Start Address
 */
#define IFXFLASHCSRM_DFLASH_START                (0xAE800000)

/** \brief CSRM DFLASH Size
 */
#define IFXFLASHCSRM_DFLASH_SIZE                 (IFXFLASHCSRM_DFLASH_NUM_LOG_SECTORS * 0x800)

/** \brief CSRM DFLASH end address
 */
#define IFXFLASHCSRM_DFLASH_END                  (IFXFLASHCSRM_DFLASH_START + IFXFLASHCSRM_DFLASH_SIZE - 1)

/** \brief DFLASH page length: 8 bytes
 */
#define IFXFLASHCSRM_DFLASH_PAGE_LENGTH          (8)

/** \brief Page length in bytes
 */
#define IFXFLASHCSRM_PFLASH_PAGE_LENGTH          (32)

/** \brief UCB1 Start Address
 */
#define IFXFLASHCSRM_UCB1_START                  (0xAEC00000)

/** \brief UCB1 End Address
 */
#define IFXFLASHCSRM_UCB1_END                    (0xAEC0CFFF)

/** \brief PF00 start address
 */
#define IFXFLASHCSRM_PFLASH_P00_START            (0xA0000000)

/** \brief PF51 End Address
 */
#define IFXFLASHCSRM_PFLASH_P51_END              (0xA13FFFFF)

/** \brief UCB0 Start Address
 */
#define IFXFLASHCSRM_UCB0_START                  (0xAE400000)

/** \brief UCB0 End Address
 */
#define IFXFLASHCSRM_UCB0_END                    (0xAE413FFF)

/** \brief Host DFLASH Start Address
 */
#define IFXFLASHCSRM_HOSTDFLASH_START            (0xAE000000)

/** \brief HOST DFLASH end address
 */
#define IFXFLASHCSRM_HOSTDFLASH_END              (0xAE0FFFFF)

/** \brief PF00 size
 */
#define IFXFLASHCSRM_PFLASH_P00_SIZE             (0x200000)

/** \brief PF01 size
 */
#define IFXFLASHCSRM_PFLASH_P01_SIZE             (0x200000)

/** \brief PF10 size
 */
#define IFXFLASHCSRM_PFLASH_P10_SIZE             (0x200000)

/** \brief PF11 size
 */
#define IFXFLASHCSRM_PFLASH_P11_SIZE             (0x200000)

/** \brief PF20 size
 */
#define IFXFLASHCSRM_PFLASH_P20_SIZE             (0x100000)

/** \brief PF21 size
 */
#define IFXFLASHCSRM_PFLASH_P21_SIZE             (0x100000)

/** \brief PF30 size
 */
#define IFXFLASHCSRM_PFLASH_P30_SIZE             (0x200000)

/** \brief PF31 size
 */
#define IFXFLASHCSRM_PFLASH_P31_SIZE             (0x200000)

/** \brief PF40 size
 */
#define IFXFLASHCSRM_PFLASH_P40_SIZE             (0x200000)

/** \brief PF41 size
 */
#define IFXFLASHCSRM_PFLASH_P41_SIZE             (0x200000)

/** \brief PF50 size
 */
#define IFXFLASHCSRM_PFLASH_P50_SIZE             (0x100000)

/** \brief PF51 size
 */
#define IFXFLASHCSRM_PFLASH_P51_SIZE             (0x100000)

/** \brief Total Host PFLASH Banks : (PF00 -PF51)
 */
#define IFXFLASHCSRM_HOSTPFLASH_BANKS            (12)

/******************************************************************************/
/*-------------------------------Enumerations---------------------------------*/
/******************************************************************************/

/** \brief Available Flash Banks
 */
typedef enum
{
    IfxFlashCsrm_FlashType_P00     = 0,   /**< \brief PFlash00 */
    IfxFlashCsrm_FlashType_P01     = 1,   /**< \brief PFlash01 */
    IfxFlashCsrm_FlashType_P10     = 2,   /**< \brief PFlash10 */
    IfxFlashCsrm_FlashType_P11     = 3,   /**< \brief PFlash11 */
    IfxFlashCsrm_FlashType_P20     = 4,   /**< \brief PFlash20 */
    IfxFlashCsrm_FlashType_P21     = 5,   /**< \brief PFlash21 */
    IfxFlashCsrm_FlashType_P30     = 6,   /**< \brief PFlash30 */
    IfxFlashCsrm_FlashType_P31     = 7,   /**< \brief PFlash31 */
    IfxFlashCsrm_FlashType_P40     = 8,   /**< \brief PFlash40 */
    IfxFlashCsrm_FlashType_P41     = 9,   /**< \brief PFlash41 */
    IfxFlashCsrm_FlashType_P50     = 10,  /**< \brief PFlash50 */
    IfxFlashCsrm_FlashType_P51     = 11,  /**< \brief PFlash51 */
    IfxFlashCsrm_FlashType_DHost   = 16,  /**< \brief host data flash */
    IfxFlashCsrm_FlashType_DCsrm   = 17,  /**< \brief csrm data flash */
    IfxFlashCsrm_FlashType_PCsrm   = 18,  /**< \brief csrm p flash */
    IfxFlashCsrm_FlashType_Invalid = 255  /**< \brief Invalid flash */
} IfxFlashCsrm_FlashType;

/** \brief user configuration block type
 */
typedef enum
{
    IfxFlashCsrm_UcbType_csrmucbBmhd      = 128,  /**< \brief UCB_CS_BMHDn(n=0-3) */
    IfxFlashCsrm_UcbType_csrmucbUsercfg   = 129,  /**< \brief UCB_CS_USERCFG_ORIG and UCB_CS_USERCFG_COPY */
    IfxFlashCsrm_UcbType_csrmucbSwap      = 130,  /**< \brief UCB_CS_SWAP_ORIG and UCB_CS_SWAP_COPY */
    IfxFlashCsrm_UcbType_csrmucbEcprio    = 131,  /**< \brief UCB_CS_ECPRIO_ORIG and UCB_CS_ECPRIO_COPY */
    IfxFlashCsrm_UcbType_csrmucbUserData0 = 132,  /**< \brief UCB_CS_USER_DATA0 */
    IfxFlashCsrm_UcbType_csrmucbUserData1 = 133,  /**< \brief UCB_CS_USER_DATA1 */
    IfxFlashCsrm_UcbType_csrmucbDbgcs     = 141,  /**< \brief UCB_CS_BGCS_ORIG and UCB_CS_DBGCS_COPY */
    IfxFlashCsrm_UcbType_csrmucbRetest    = 143,  /**< \brief UCB_RETEST */
    IfxFlashCsrm_UcbType_csrmucbFlash     = 144,  /**< \brief UCB_CS_FLASH_ORIG and UCB_CS_FLASH_COPY */
    IfxFlashCsrm_UcbType_csrmDflash       = 160,  /**< \brief Disable sector specific write protection for CSRM DFLASH */
    IfxFlashCsrm_UcbType_csrmPflash       = 176   /**< \brief Disable sector specific write protection for CSRM PFLASH */
} IfxFlashCsrm_UcbType;

/******************************************************************************/
/*-----------------------------Data Structures--------------------------------*/
/******************************************************************************/

/** \brief contains start and end address of sectors
 */
typedef struct
{
    uint32 start;       /**< \brief start address of sector */
    uint32 end;         /**< \brief end address of sector */
} IfxFlashCsrm_flashSector;

/******************************************************************************/
/*-------------------Global Exported Variables/Constants----------------------*/
/******************************************************************************/
/** \brief Table defining CSRM DFLASH CFS logical sector
 */
IFX_EXTERN IFX_CONST IfxFlashCsrm_flashSector IfxFlashCsrm_dFlashTableCfsLog[IFXFLASHCSRM_DFLASH_NUM_CFS_LOG_SECTORS];

/** \brief Table defining CSRM DFLASH logical sector
 */
IFX_EXTERN IFX_CONST IfxFlashCsrm_flashSector IfxFlashCsrm_dFlashTableLog[IFXFLASHCSRM_DFLASH_NUM_LOG_SECTORS];

/** \brief Table defining CSRM DFLASH UCB logical sector
 */
IFX_EXTERN IFX_CONST IfxFlashCsrm_flashSector IfxFlashCsrm_dFlashTableUcbLog[IFXFLASHCSRM_DFLASH_NUM_UCB_LOG_SECTORS];

/** \brief Array defining flash sizes
 */
IFX_EXTERN IFX_CONST uint32                   IfxFlashCsrm_flashSize[IFXFLASHCSRM_HOSTPFLASH_BANKS];

/** \brief Table defining CSRM PFLASH logical sector
 */
IFX_EXTERN IFX_CONST IfxFlashCsrm_flashSector IfxFlashCsrm_pFlashTableLog[IFXFLASHCSRM_PFLASH_NUM_LOG_SECTORS];

/** \brief Table defining CSRM PFLASH Physical sector
 */
IFX_EXTERN IFX_CONST IfxFlashCsrm_flashSector IfxFlashCsrm_pFlashTablePhys[IFXFLASHCSRM_PFLASH_NUM_PHYSICAL_SECTORS];

#endif /* IFXFLASHCSRM_CFG_TC4DX_H */
