/**
 * \file IfxNvmrCsrm_cfg_TC48x.h
 * \brief NVMRCSRM on-chip implementation data
 * \ingroup IfxLld_NvmrCsrm
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
 * \defgroup IfxLld_NvmrCsrm NVMRCSRM
 * \ingroup IfxLld
 * \defgroup IfxLld_NvmrCsrm_Impl Implementation
 * \ingroup IfxLld_NvmrCsrm
 * \defgroup IfxLld_NvmrCsrm_Std Standard Driver
 * \ingroup IfxLld_NvmrCsrm
 */

#ifndef IFXNVMRCSRM_CFG_TC48X_H
#define IFXNVMRCSRM_CFG_TC48X_H 1

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
#define IFXNVMRCSRM_NUM_MODULES                  (1)

/** \brief NVM DNVM Size (includes EEPROM, ICB, and UCB)
 */
#define IFXNVMRCSRM_DNVM_SIZE                    (0x20000)

/** \brief NVM PNVM Size
 */
#define IFXNVMRCSRM_PNVM_SIZE                    (0x200000)

/** \brief Number of DNVM Banks
 */
#define IFXNVMRCSRM_DNVM_BANKS                   (1)

/** \brief Number of PNVM Banks
 */
#define IFXNVMRCSRM_PNVM_BANKS                   (1)

/** \brief DNVM page length: 8 bytes
 */
#define IFXNVMRCSRM_DNVM_PAGE_LENGTH             (8)

/** \brief Page length in bytes
 */
#define IFXNVMRCSRM_PNVM_PAGE_LENGTH             (32)

/** \brief Number of DNVM Physical sector
 */
#define IFXNVMRCSRM_DNVM_NUM_PHYSICAL_SECTORS    (1)

/** \brief Number of PNVM Physical sector
 */
#define IFXNVMRCSRM_PNVM_NUM_PHYSICAL_SECTORS    (4)

/** \brief PNVM Physical sector Size in bytes
 */
#define IFXNVMRCSRM_PNVM_PHYSICAL_SECTOR_SIZE    (0x80000)

/** \brief DNVM UCB sector size in bytes
 */
#define IFXNVMRCSRM_DNVM_UCB_SECTOR_SIZE         (0x8000)

/** \brief DNVM EEPROM size in bytes
 */
#define IFXNVMRCSRM_DNVM_EEPROM_SIZE             (0x20000u)

/** \brief DNVM Start Address
 */
#define IFXNVMRCSRM_DNVM_START                   (0xAE800000)

/** \brief PNVM00 start address
 */
#define IFXNVMRCSRM_PNVM00_START                 (0xA0000000)

/** \brief PNVM00 end address
 */
#define IFXNVMRCSRM_PNVM00_END                   (IFXNVMRCSRM_PNVM00_START + IFXNVMRCSRM_PNVM_SIZE - 1u)

/** \brief PNVM access delay is 20ns
 */
#define IFXNVMRCSRM_PNVM_ACCESS_DELAY            (50.0e6)

/** \brief DNVM access delay in 50ns
 */
#define IFXNVMRCSRM_DNVM_ACCESS_DELAY            (20.0e6)

/** \brief DNVM Start Address
 */
#define IFXNVMRCSRM_DNVM_EEPROM_START            (IFXNVMRCSRM_DNVM_START)

/** \brief DNVM EEPROM0 END Address
 */
#define IFXNVMRCSRM_DNVM_EEPROM_END              (IFXNVMRCSRM_DNVM_EEPROM_START + IFXNVMRCSRM_DNVM_EEPROM_SIZE - 1u)

/** \brief DNVM UCB0 START Address
 */
#define IFXNVMRCSRM_DNVM_UCB1_START              (0xAEC00000)

/** \brief DNVM UCB0 END Address
 */
#define IFXNVMRCSRM_DNVM_UCB1_END                (IFXNVMRCSRM_DNVM_UCB1_START + (IFXNVMRCSRM_DNVM_UCB_SECTOR_SIZE - 1U))

/** \brief Program memory write page timeout.
 */
#ifndef IFXNVMRCSRM_PNVM_WRITE_PAGE_TIMEOUT
#define IFXNVMRCSRM_PNVM_WRITE_PAGE_TIMEOUT      ((uint32)(100e-6f * IFX_CFG_CLOCK_SYSPLL_FREQUENCY))
#endif

/** \brief Data memory write page timeout.
 */
#ifndef IFXNVMRCSRM_DNVM_WRITE_PAGE_TIMEOUT
#define IFXNVMRCSRM_DNVM_WRITE_PAGE_TIMEOUT      ((uint32)(200e-6f * IFX_CFG_CLOCK_SYSPLL_FREQUENCY))
#endif

/** \brief Tight Margin read timeout
 */
#ifndef IFXNVMRCSRM_TIGHT_MARGIN_READ_TIMEOUT
#define IFXNVMRCSRM_TIGHT_MARGIN_READ_TIMEOUT    ((uint32)(1.5e-6f * IFX_CFG_CLOCK_SYSPLL_FREQUENCY))
#endif

/** \brief NMVR Operation timeout
 */
#ifndef IFXNVMRCSRM_OPERATION_TIMEOUT
#define IFXNVMRCSRM_OPERATION_TIMEOUT            ((uint32)0xFFFFFF)
#endif

/** \brief PNVM00 start address
 */
#define IFXNVMRCSRM_PNVMCS_START                 (0xA4000000u)

/** \brief PNVMCS End address
 */
#define IFXNVMRCSRM_PNVMCS_END                   (IFXNVMRCSRM_PNVMCS_START + IFXNVMRCSRM_PNVMCS_SIZE - 1u)

/** \brief NVM PNVM CS Size
 */
#define IFXNVMRCSRM_PNVMCS_SIZE                  (0x80000u)

/** \brief PMURCS number of bits to be shifted to get a bank index
 */
#define IFXNVMRCSRM_PMURCS_BANK_OFFSET_BIT_SHIFT (19u)

/** \brief Injects a PNVM and DNVM ECC error into the NVMR module.
 */
#define IFXNVMRCSRM_INJECT_PNVM_DNVM_ECC_ERROR   (FALSE)

/** \brief PNVM request operations sleep, wait.
 */
#define IFXNVMRCSRM_PNVM_REQUEST_OPERATION       (TRUE)

/** \brief DNVM request operations sleep, wait.
 */
#define IFXNVMRCSRM_DNVM_REQUEST_OPERATION       (TRUE)

/** \brief Gets the PNVM tight margin read error status.
 */
#define IFXNVMRCSRM_PNVM_GET_ERROR_STATUS        (TRUE)

/** \brief Gets the DNVM tight margin read error status.
 */
#define IFXNVMRCSRM_DNVM_GET_ERROR_STATUS        (TRUE)

#endif /* IFXNVMRCSRM_CFG_TC48X_H */
