/**
 * \file IfxFlash_cfg.h
 * \brief FLASH on-chip implementation data
 * \ingroup IfxLld_Flash
 *
 * \version iLLD-TC4-v2.1.1
 * \copyright Copyright (c) 2024 Infineon Technologies AG. All rights reserved.
 *
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
 *
 * \defgroup IfxLld_Flash FLASH
 * \ingroup IfxLld
 * \defgroup IfxLld_Flash_Impl Implementation
 * \ingroup IfxLld_Flash
 * \defgroup IfxLld_Flash_Std Standard Driver
 * \ingroup IfxLld_Flash
 */

#ifndef IFXFLASH_CFG_H
#define IFXFLASH_CFG_H 1

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include "Cpu/Std/Ifx_Types.h"

/******************************************************************************/
/*-----------------------------------Macros-----------------------------------*/
/******************************************************************************/

/** \brief number of flash modules.
 * This macro may be deprecated in future. Use IFXFLASH_NUM_MODULES instead.
 */
#define IFXFLASH_NUM_FLASH_MODULES                       (1)

/** \brief base address for general command sequences
 */
#define IFXFLASH_CMD_BASE_ADDRESS                        (0xF8080000)

/** \brief offset between command areas (in DFlash range)
 */
#define IFXFLASH_CMD_BASE_OFFSET                         (0x00040000)

/** \brief Number of DFLASH Banks
 */
#define IFXFLASH_DFLASH_BANKS                            (2)

/** \brief Dflash burst length in byte
 */
#define IFXFLASH_DFLASH_BURST_LENGTH                     (0x20)

/** \brief HOST DFLASH end address
 */
#define IFXFLASH_DFLASH_END                              (IFXFLASH_DFLASH_START + IFXFLASH_DFLASH_SIZE - 1)

/** \brief HOST DFLASH CFS logical sector count
 */
#define IFXFLASH_DFLASH_NUM_CFS_LOG_SECTORS              (40)

/** \brief HOST DFLASH logical sector count
 */
#define IFXFLASH_DFLASH_NUM_LOG_SECTORS                  (512)

/** \brief HOST DFLASH Physical sector
 */
#define IFXFLASH_DFLASH_NUM_PHYSICAL_SECTORS             (8)

/** \brief HOST DFLASH UCB logical sector
 */
#define IFXFLASH_DFLASH_NUM_UCB_LOG_SECTORS              (40)

/** \brief HOST DFLASH page length: 8 bytes
 */
#define IFXFLASH_DFLASH_PAGE_LENGTH                      (8)

/** \brief Host DFLASH Size
 */
#define IFXFLASH_DFLASH_SIZE                             (IFXFLASH_DFLASH_NUM_LOG_SECTORS * 0x800)

/** \brief Host DFLASH Start Address
 */
#define IFXFLASH_DFLASH_START                            (0xAE000000)

/** \brief DFLASH Word line length : 512 bytes
 */
#define IFXFLASH_DFLASH_WORDLINE_LENGTH                  (512)

/** \brief
 */
#define IFXFLASH_ERROR_TRACKING_MAX_CORRECTABLE_ERRORS   (10 /* A3G changes to be done */)

/** \brief
 */
#define IFXFLASH_ERROR_TRACKING_MAX_UNCORRECTABLE_ERRORS (1 /* A3G changes to be done */)

/** \brief number of flash modules
 */
#define IFXFLASH_NUM_MODULES                             (1)

/** \brief Total Host PFLASH Banks : (PF00 -PF51)
 */
#define IFXFLASH_PFLASH_BANKS                            (12)

/** \brief P flash burst length
 */
#define IFXFLASH_PFLASH_BURST_LENGTH                     (0x200)

/** \brief HOST Pflash end
 */
#define IFXFLASH_PFLASH_END                              (IFXFLASH_PFLASH_START + IFXFLASH_PFLASH_SIZE - 1)

/** \brief HOST PFLASH Logical sector count
 * 8 PFLASH bank of 2 MB size --> 128 Logical sector
 * 4 PFLASH bank of 1 MB size --> 64 logical sector
 */
#define IFXFLASH_PFLASH_NUM_LOG_SECTORS                  ((128 * 8) + (64 * 4))

/** \brief HOST PFLASH Physical sector count
 * 8 PFLASH bank of 2 MB size --> 4 Physical sector
 * 4 PFLASH bank of 1 MB size --> 2 Physical sector
 */
#define IFXFLASH_PFLASH_NUM_PHYSICAL_SECTORS             ((4 * 8) + (2 * 4))

/** \brief offset between PMU PFlash ranges
 */
#define IFXFLASH_PFLASH_OFFSET                           (0x00800000 /* TODO for A3G */)

/** \brief Page length in bytes
 */
#define IFXFLASH_PFLASH_PAGE_LENGTH                      (32)

/** \brief Host PFlash size : 20MiB
 */
#define IFXFLASH_PFLASH_SIZE                             (0x1400000)

/** \brief Host PFlash start address
 */
#define IFXFLASH_PFLASH_START                            (0xa0000000)

/** \brief Wordline size in bytes
 */
#define IFXFLASH_PFLASH_WORDLINE_LENGTH                  (1024)

/** \brief PF00 start address
 */
#define IFXFLASH_PFLASH_P00_START                        (0xA0000000)

/** \brief PF01 start address
 */
#define IFXFLASH_PFLASH_P01_START                        (IFXFLASH_PFLASH_P00_START + IFXFLASH_PFLASH_P00_SIZE)

/** \brief PF10 start address
 */
#define IFXFLASH_PFLASH_P10_START                        (IFXFLASH_PFLASH_P01_START + IFXFLASH_PFLASH_P01_SIZE)

/** \brief PF11 start address
 */
#define IFXFLASH_PFLASH_P11_START                        (IFXFLASH_PFLASH_P10_START + IFXFLASH_PFLASH_P10_SIZE)

/** \brief PF20 start address
 */
#define IFXFLASH_PFLASH_P20_START                        (IFXFLASH_PFLASH_P11_START + IFXFLASH_PFLASH_P11_SIZE)

/** \brief PF21 start address
 */
#define IFXFLASH_PFLASH_P21_START                        (IFXFLASH_PFLASH_P20_START + IFXFLASH_PFLASH_P20_SIZE)

/** \brief PF30 start address
 */
#define IFXFLASH_PFLASH_P30_START                        (IFXFLASH_PFLASH_P21_START + IFXFLASH_PFLASH_P21_SIZE)

/** \brief PF31 start address
 */
#define IFXFLASH_PFLASH_P31_START                        (IFXFLASH_PFLASH_P30_START + IFXFLASH_PFLASH_P30_SIZE)

/** \brief PF40 start address
 */
#define IFXFLASH_PFLASH_P40_START                        (IFXFLASH_PFLASH_P31_START + IFXFLASH_PFLASH_P31_SIZE)

/** \brief PF41 start address
 */
#define IFXFLASH_PFLASH_P41_START                        (IFXFLASH_PFLASH_P40_START + IFXFLASH_PFLASH_P40_SIZE)

/** \brief PF50 start address
 */
#define IFXFLASH_PFLASH_P50_START                        (IFXFLASH_PFLASH_P41_START + IFXFLASH_PFLASH_P41_SIZE)

/** \brief PF51 start address
 */
#define IFXFLASH_PFLASH_P51_START                        (IFXFLASH_PFLASH_P50_START + IFXFLASH_PFLASH_P50_SIZE)

/** \brief PF00 size
 */
#define IFXFLASH_PFLASH_P00_SIZE                         (0x200000)

/** \brief PF01 size
 */
#define IFXFLASH_PFLASH_P01_SIZE                         (0x200000)

/** \brief PF10 size
 */
#define IFXFLASH_PFLASH_P10_SIZE                         (0x200000)

/** \brief PF11 size
 */
#define IFXFLASH_PFLASH_P11_SIZE                         (0x200000)

/** \brief PF20 size
 */
#define IFXFLASH_PFLASH_P20_SIZE                         (0x100000)

/** \brief PF21 size
 */
#define IFXFLASH_PFLASH_P21_SIZE                         (0x100000)

/** \brief PF30 size
 */
#define IFXFLASH_PFLASH_P30_SIZE                         (0x200000)

/** \brief PF31 size
 */
#define IFXFLASH_PFLASH_P31_SIZE                         (0x200000)

/** \brief PF40 size
 */
#define IFXFLASH_PFLASH_P40_SIZE                         (0x200000)

/** \brief PF41 size
 */
#define IFXFLASH_PFLASH_P41_SIZE                         (0x200000)

/** \brief PF50 size
 */
#define IFXFLASH_PFLASH_P50_SIZE                         (0x100000)

/** \brief PF51 size
 */
#define IFXFLASH_PFLASH_P51_SIZE                         (0x100000)

/** \brief PF00 End Address
 */
#define IFXFLASH_PFLASH_P00_END                          (IFXFLASH_PFLASH_P00_START + IFXFLASH_PFLASH_P00_SIZE - 1)

/** \brief PF01 End Address
 */
#define IFXFLASH_PFLASH_P01_END                          (IFXFLASH_PFLASH_P01_START + IFXFLASH_PFLASH_P01_SIZE - 1)

/** \brief PF10 End Address
 */
#define IFXFLASH_PFLASH_P10_END                          (IFXFLASH_PFLASH_P10_START + IFXFLASH_PFLASH_P10_SIZE - 1)

/** \brief PF11 End Address
 */
#define IFXFLASH_PFLASH_P11_END                          (IFXFLASH_PFLASH_P11_START + IFXFLASH_PFLASH_P11_SIZE - 1)

/** \brief PF20 End Address
 */
#define IFXFLASH_PFLASH_P20_END                          (IFXFLASH_PFLASH_P20_START + IFXFLASH_PFLASH_P20_SIZE - 1)

/** \brief PF21 End Address
 */
#define IFXFLASH_PFLASH_P21_END                          (IFXFLASH_PFLASH_P21_START + IFXFLASH_PFLASH_P21_SIZE - 1)

/** \brief PF30 End Address
 */
#define IFXFLASH_PFLASH_P30_END                          (IFXFLASH_PFLASH_P30_START + IFXFLASH_PFLASH_P30_SIZE - 1)

/** \brief PF31 End Address
 */
#define IFXFLASH_PFLASH_P31_END                          (IFXFLASH_PFLASH_P31_START + IFXFLASH_PFLASH_P31_SIZE - 1)

/** \brief PF40 End Address
 */
#define IFXFLASH_PFLASH_P40_END                          (IFXFLASH_PFLASH_P40_START + IFXFLASH_PFLASH_P40_SIZE - 1)

/** \brief PF41 End Address
 */
#define IFXFLASH_PFLASH_P41_END                          (IFXFLASH_PFLASH_P41_START + IFXFLASH_PFLASH_P41_SIZE - 1)

/** \brief PF50 End Address
 */
#define IFXFLASH_PFLASH_P50_END                          (IFXFLASH_PFLASH_P50_START + IFXFLASH_PFLASH_P50_SIZE - 1)

/** \brief PF51 End Address
 */
#define IFXFLASH_PFLASH_P51_END                          (IFXFLASH_PFLASH_P51_START + IFXFLASH_PFLASH_P51_SIZE - 1)

/** \brief Mask for busy status of various banks
 */
#define IFXFLASH_MASK_FLASH_BANK_STATUS                  (0xF0FFFU)

/** \brief UCB0 Start Address
 */
#define IFXFLASH_UCB0_START                              (0xAE400000)

/** \brief UCB0 End Address
 */
#define IFXFLASH_UCB0_END                                (0xAE413FFF)

/******************************************************************************/
/*-------------------------------Enumerations---------------------------------*/
/******************************************************************************/

/** \brief Available Flash Banks
 */
typedef enum
{
    IfxFlash_FlashType_P00     = 0,   /**< \brief PFlash00 */
    IfxFlash_FlashType_P01     = 1,   /**< \brief PFlash01 */
    IfxFlash_FlashType_P10     = 2,   /**< \brief PFlash10 */
    IfxFlash_FlashType_P11     = 3,   /**< \brief PFlash11 */
    IfxFlash_FlashType_P20     = 4,   /**< \brief PFlash20 */
    IfxFlash_FlashType_P21     = 5,   /**< \brief PFlash21 */
    IfxFlash_FlashType_P30     = 6,   /**< \brief PFlash30 */
    IfxFlash_FlashType_P31     = 7,   /**< \brief PFlash31 */
    IfxFlash_FlashType_P40     = 8,   /**< \brief PFlash40 */
    IfxFlash_FlashType_P41     = 9,   /**< \brief PFlash41 */
    IfxFlash_FlashType_P50     = 10,  /**< \brief PFlash50 */
    IfxFlash_FlashType_P51     = 11,  /**< \brief PFlash51 */
    IfxFlash_FlashType_DHost   = 16,  /**< \brief host data flash */
    IfxFlash_FlashType_DCsrm   = 17,  /**< \brief csrm data flash */
    IfxFlash_FlashType_PCsrm   = 18,  /**< \brief csrm p flash */
    IfxFlash_FlashType_Invalid = 255  /**< \brief Invalid Flash */
} IfxFlash_FlashType;

/** \brief user configuration block type
 */
typedef enum
{
    IfxFlash_UcbType_ucbBmhd                 = 0,   /**< \brief UCB_RTC_BMHDn (n=0 - 3) */
    IfxFlash_UcbType_ucbUsercfg              = 1,   /**< \brief UCB_RTC_USERCFG_ORIG and UCB_RTC_USERCFG_COPY */
    IfxFlash_UcbType_ucbSwap                 = 2,   /**< \brief UCB_RTC_SWAP_ORIG and UCB_RTC_SWAP_COPY */
    IfxFlash_UcbType_ucbEcprio               = 3,   /**< \brief UCB_RTC_ECPRIO_ORIG and UCB_RTC_ECPRIO_COPY */
    IfxFlash_UcbType_ucbUserData0            = 4,   /**< \brief UCB_USER_DATA0 */
    IfxFlash_UcbType_ucbUserData1            = 5,   /**< \brief UCB_USER_DATA1 */
    IfxFlash_UcbType_ucbHostPflashHostDflash = 16,  /**< \brief Disable global read and write protection for HOST DFLASH and all HOST PFLASHs */
    IfxFlash_UcbType_ucbHostDflash           = 32,  /**< \brief Disable global read protection for HOST DFLASH */
    IfxFlash_UcbType_ucbHostPflash           = 33,  /**< \brief Disable global read protection for HOST PFLASH */
    IfxFlash_UcbType_ucbHostPflash0A         = 48,  /**< \brief Disable global read protection and sector specific write protection for HOST PFLASH0A */
    IfxFlash_UcbType_ucbHostPflash0B         = 49,  /**< \brief Disable global read protection and sector specific write protection for HOST PFLASH0B */
    IfxFlash_UcbType_ucbHostPflash1A         = 50,  /**< \brief Disable global read protection and sector specific write protection for HOST PFLASH1A */
    IfxFlash_UcbType_ucbHostPflash1B         = 51,  /**< \brief Disable global read protection and sector specific write protection for HOST PFLASH1B */
    IfxFlash_UcbType_ucbHostPflash2A         = 52,  /**< \brief Disable global read protection and sector specific write protection for HOST PFLASH2A */
    IfxFlash_UcbType_ucbHostPflash2B         = 53,  /**< \brief Disable global read protection and sector specific write protection for HOST PFLASH2B */
    IfxFlash_UcbType_ucbHostPflash3A         = 54,  /**< \brief Disable global read protection and sector specific write protection for HOST PFLASH3A */
    IfxFlash_UcbType_ucbHostPflash3B         = 55,  /**< \brief Disable global read protection and sector specific write protection for HOST PFLASH3B */
    IfxFlash_UcbType_ucbHostPflash4A         = 56,  /**< \brief Disable global read protection and sector specific write protection for HOST PFLASH4A */
    IfxFlash_UcbType_ucbHostPflash4B         = 57,  /**< \brief Disable global read protection and sector specific write protection for HOST PFLASH4B */
    IfxFlash_UcbType_ucbHostPflash5A         = 58,  /**< \brief Disable global read protection and sector specific write protection for HOST PFLASH5A */
    IfxFlash_UcbType_ucbHostPflash5B         = 59   /**< \brief Disable global read protection and sector specific write protection for HOST PFLASH5B */
} IfxFlash_UcbType;

/******************************************************************************/
/*-----------------------------Data Structures--------------------------------*/
/******************************************************************************/

/** \brief contains start and end address of sectors
 */
typedef struct
{
    uint32 start;       /**< \brief start address of sector */
    uint32 end;         /**< \brief end address of sector */
} IfxFlash_flashSector;

/******************************************************************************/
/*-------------------Global Exported Variables/Constants----------------------*/
/******************************************************************************/
/** \brief Table defining Host DFLASH CFS logical sector
 */
IFX_EXTERN IFX_CONST IfxFlash_flashSector IfxFlash_dFlashTableCfsLog[IFXFLASH_DFLASH_NUM_CFS_LOG_SECTORS];

/** \brief Table defining HOST DFLASH logical sector
 */
IFX_EXTERN IFX_CONST IfxFlash_flashSector IfxFlash_dFlashTableEepLog[IFXFLASH_DFLASH_NUM_LOG_SECTORS];

/** \brief Table defining Host DFLASH Physical sector
 */
IFX_EXTERN IFX_CONST IfxFlash_flashSector IfxFlash_dFlashTablePhys[IFXFLASH_DFLASH_NUM_PHYSICAL_SECTORS];

/** \brief Table defining Host DFLASH UCB logical sector
 */
IFX_EXTERN IFX_CONST IfxFlash_flashSector IfxFlash_dFlashTableUcbLog[IFXFLASH_DFLASH_NUM_UCB_LOG_SECTORS];

/** \brief Array defining flash sizes
 */
IFX_EXTERN IFX_CONST uint32               IfxFlash_flashSize[IFXFLASH_PFLASH_BANKS];

/** \brief Table defining Host PFLASH logical sector
 */
IFX_EXTERN IFX_CONST IfxFlash_flashSector IfxFlash_pFlashTableLog[IFXFLASH_PFLASH_NUM_LOG_SECTORS];

/** \brief Table defining Host PFLASH Physical sector
 */
IFX_EXTERN IFX_CONST IfxFlash_flashSector IfxFlash_pFlashTablePhys[IFXFLASH_PFLASH_NUM_PHYSICAL_SECTORS];

#endif /* IFXFLASH_CFG_H */
