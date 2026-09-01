/**
 * \file IfxNvmr_cfg_TC48x.h
 * \brief NVMR on-chip implementation data
 * \ingroup IfxLld_Nvmr
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
 * \defgroup IfxLld_Nvmr NVMR
 * \ingroup IfxLld
 * \defgroup IfxLld_Nvmr_Impl Implementation
 * \ingroup IfxLld_Nvmr
 * \defgroup IfxLld_Nvmr_Std Standard Driver
 * \ingroup IfxLld_Nvmr
 * \defgroup IfxLld_Nvmr_Impl_Enum Enumerations
 * \ingroup IfxLld_Nvmr_Impl
 */

#ifndef IFXNVMR_CFG_TC48X_H
#define IFXNVMR_CFG_TC48X_H 1

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include "Ifx_Types.h"
#include "IfxPmur_reg.h"
#include "IfxDmur_reg.h"

/******************************************************************************/
/*-----------------------------------Macros-----------------------------------*/
/******************************************************************************/

/** \brief number of NVM RRAM modules.
 */
#define IFXNVMR_NUM_MODULES               (1)

/** \brief NVM DNVM Size (includes EEPROM, ICB, and UCB)
 */
#define IFXNVMR_DNVM_SIZE                 (0x20000)

/** \brief NVM PNVM Size
 */
#define IFXNVMR_PNVM_SIZE                 (0x200000)

/** \brief Number of DNVM Banks
 */
#define IFXNVMR_DNVM_BANKS                (1)

/** \brief Number of PNVM Banks
 */
#define IFXNVMR_PNVM_BANKS                (8u)

/** \brief DNVM page length: 8 bytes
 */
#define IFXNVMR_DNVM_PAGE_LENGTH          (8)

/** \brief Page length in bytes
 */
#define IFXNVMR_PNVM_PAGE_LENGTH          (32)

/** \brief Number of DNVM Physical sector
 */
#define IFXNVMR_DNVM_NUM_PHYSICAL_SECTORS (1)

/** \brief Number of PNVM Physical sector
 */
#define IFXNVMR_PNVM_NUM_PHYSICAL_SECTORS (4)

/** \brief PNVM Physical sector Size in bytes
 */
#define IFXNVMR_PNVM_PHYSICAL_SECTOR_SIZE (0x80000)

/** \brief DNVM UCB sector size in bytes
 */
#define IFXNVMR_DNVM_UCB_SECTOR_SIZE      (0x8000)

/** \brief DNVM EEPROM size in bytes
 */
#define IFXNVMR_DNVM_EEPROM_SIZE          (0x40000u)

/** \brief DNVM Start Address
 */
#define IFXNVMR_DNVM_START                (0xAE000000)

/** \brief PNVM00 start address
 */
#define IFXNVMR_PNVM00_START              (0xA0000000)

/** \brief PNVM00 end address
 */
#define IFXNVMR_PNVM00_END                (IFXNVMR_PNVM00_START + IFXNVMR_PNVM_SIZE - 1)

/** \brief PNVM10 start address
 */
#define IFXNVMR_PNVM10_START              (0xA0400000u)

/** \brief PNVM00 end address
 */
#define IFXNVMR_PNVM10_END                (IFXNVMR_PNVM10_START + IFXNVMR_PNVM_SIZE - 1)

/** \brief PNVM access delay is 20ns
 */
#define IFXNVMR_PNVM_ACCESS_DELAY         (50.0e6)

/** \brief DNVM access delay in 50ns
 */
#define IFXNVMR_DNVM_ACCESS_DELAY         (20.0e6)

/** \brief DNVM Start Address
 */
#define IFXNVMR_DNVM_EEPROM_START         (IFXNVMR_DNVM_START)

/** \brief DNVM EEPROM0 END Address
 */
#define IFXNVMR_DNVM_EEPROM_END           (IFXNVMR_DNVM_EEPROM_START + IFXNVMR_DNVM_EEPROM_SIZE - 1u)

/** \brief DNVM UCB0 START Address
 */
#define IFXNVMR_DNVM_UCB0_START           (0xAE400000)

/** \brief DNVM UCB0 END Address
 */
#define IFXNVMR_DNVM_UCB0_END             (IFXNVMR_DNVM_UCB0_START + (IFXNVMR_DNVM_UCB_SECTOR_SIZE - 1U))

/** \brief Program memory write page timeout.
 */
#ifndef IFXNVMR_PNVM_WRITE_PAGE_TIMEOUT
#define IFXNVMR_PNVM_WRITE_PAGE_TIMEOUT   ((uint32)(100e-6f * IFX_CFG_CLOCK_SYSPLL_FREQUENCY))
#endif

/** \brief Data memory write page timeout.
 */
#ifndef IFXNVMR_DNVM_WRITE_PAGE_TIMEOUT
#define IFXNVMR_DNVM_WRITE_PAGE_TIMEOUT   ((uint32)(200e-6f * IFX_CFG_CLOCK_SYSPLL_FREQUENCY))
#endif

/** \brief Tight Margin read timeout
 */
#ifndef IFXNVMR_TIGHT_MARGIN_READ_TIMEOUT
#define IFXNVMR_TIGHT_MARGIN_READ_TIMEOUT ((uint32)(1.5e-6f * IFX_CFG_CLOCK_SYSPLL_FREQUENCY))
#endif

/** \brief NMVR Operation timeout
 */
#ifndef IFXNVMR_OPERATION_TIMEOUT
#define IFXNVMR_OPERATION_TIMEOUT         ((uint32)0xFFFFFF)
#endif

/** \brief PNVM01 Start
 */
#define IFXNVMR_PNVM01_START              (0xA0200000u)

/** \brief PNVM01 END
 */
#define IFXNVMR_PNVM01_END                (IFXNVMR_PNVM01_START + IFXNVMR_PNVM_SIZE - 1u)

/** \brief PNVM11 START
 */
#define IFXNVMR_PNVM11_START              (0xA0600000u)

/** \brief PNVM11 END
 */
#define IFXNVMR_PNVM11_END                (IFXNVMR_PNVM11_START + IFXNVMR_PNVM_SIZE - 1u)

/** \brief PNVM20 START
 */
#define IFXNVMR_PNVM20_START              (0xA0800000u)

/** \brief PNVM20 END
 */
#define IFXNVMR_PNVM20_END                (IFXNVMR_PNVM20_START + IFXNVMR_PNVM_SIZE - 1u)

/** \brief PNVM21 START
 */
#define IFXNVMR_PNVM21_START              (0xA0A00000u)

/** \brief PNVM21 END
 */
#define IFXNVMR_PNVM21_END                (IFXNVMR_PNVM21_START + IFXNVMR_PNVM_SIZE - 1u)

/** \brief PNVM31 START
 */
#define IFXNVMR_PNVM30_START              (0xA0C00000u)

/** \brief PNVM30 END
 */
#define IFXNVMR_PNVM30_END                (IFXNVMR_PNVM30_START + IFXNVMR_PNVM_SIZE - 1u)

/** \brief PNVM31 START
 */
#define IFXNVMR_PNVM31_START              (0xA0E00000u)

/** \brief PNVM31 END
 */
#define IFXNVMR_PNVM31_END                (IFXNVMR_PNVM31_START + IFXNVMR_PNVM_SIZE - 1u)

/** \brief PNVM Wait state configuration
 */
#define IFXNVMR_CFG_FLASH_WAITSTATE       (8u)

/** \brief PMUR wait state configuration.
 */
#define IFXNVMR_WAIT_STATE_CONFIG            (TRUE)

/** \brief Injects a PNVM and DNVM ECC error into the NVMR module.
 */
#define IFXNVMR_INJECT_PNVM_DNVM_ECC_ERROR   (FALSE)

/** \brief PNVM request operations sleep, wait.
 */
#define IFXNVMR_PNVM_REQUEST_OPERATION       (TRUE)

/** \brief DNVM request operations sleep, wait.
 */
#define IFXNVMR_DNVM_REQUEST_OPERATION       (TRUE)

/** \brief Gets the PNVM tight margin read error status.
 */
#define IFXNVMR_PNVM_GET_ERROR_STATUS        (TRUE)

/** \brief Gets the DNVM tight margin read error status.
 */
#define IFXNVMR_DNVM_GET_ERROR_STATUS        (TRUE)

/******************************************************************************/
/*--------------------------------Enumerations--------------------------------*/
/******************************************************************************/

/** \addtogroup IfxLld_Nvmr_Impl_Enum
 * \{ */
/** \brief Enumerations for PRRAM
 */
typedef enum
{
    IfxNvmr_Pnvm_0A = 0x00,  /**< \brief PRRAM A for CPU0 */
    IfxNvmr_Pnvm_0B = 0x01,  /**< \brief PRRAM B for CPU0 */
    IfxNvmr_Pnvm_1A = 0x02,  /**< \brief PRRAM A for CPU1 */
    IfxNvmr_Pnvm_1B = 0x03,  /**< \brief PRRAM B for CPU1 */
    IfxNvmr_Pnvm_2A = 0x04,  /**< \brief PRRAM A for CPU2 */
    IfxNvmr_Pnvm_2B = 0x05,  /**< \brief PRRAM B for CPU2 */
    IfxNvmr_Pnvm_3A = 0x06,  /**< \brief PRRAM A for CPU3 */
    IfxNvmr_Pnvm_3B = 0x07   /**< \brief PRRAM B for CPU3 */
} IfxNvmr_Pnvm;

/** \brief Enumerations for PMUR bank segments  */
typedef enum
{ 
    IfxNvmr_PmurSegment_p00 = 0u,            /**< \brief PFlash00 */ 
    IfxNvmr_PmurSegment_p01 = 1u,            /**< \brief PFlash01 */ 
    IfxNvmr_PmurSegment_p10 = 2u,            /**< \brief PFlash10 */ 
    IfxNvmr_PmurSegment_p11 = 3u,            /**< \brief PFlash11 */ 
    IfxNvmr_PmurSegment_p20 = 4u,            /**< \brief PFlash20 */ 
    IfxNvmr_PmurSegment_p21 = 5u,            /**< \brief PFlash21 */ 
    IfxNvmr_PmurSegment_p30 = 6u,            /**< \brief PFlash30 */ 
    IfxNvmr_PmurSegment_p31 = 7u,            /**< \brief PFlash31 */ 
    IfxNvmr_PmurSegment_invalid = 0xFFu     /**< \brief Invalid Flash */
} IfxNvmr_PmurSegment;


/** \} */

#endif /* IFXNVMR_CFG_TC48X_H */
