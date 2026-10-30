/**
 * \file IfxEbu_BFlashSpansion.h
 * \brief EBU BFLASHSPANSION details
 * \ingroup IfxLld_Ebu
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
 * \defgroup IfxLld_Ebu_BFlashSpansion_Usage How to use the Spansion Burst Flash Driver?
 * \ingroup IfxLld_Ebu
 *
 * The BFlashSpansion interface driver provides a default EBU configuration to access external Burst Flash devices from Spansion (e.g. S29CD032G)
 *
 * In the following sections it will be described, how to integrate the driver into the application framework.
 *
 * \section IfxLld_Ebu_BFlashSpansion_Preparation Preparation
 * \subsection IfxLld_Ebu_BFlashSpansion_Include Include Files
 *
 * Include following header file into your C code:
 * \code
 * #include <Ebu/BFlashSpansion/IfxEbu_BFlashSpansion.h>
 * \endcode
 *
 * \subsection IfxLld_Ebu_BFlashSpansion_Init Module Initialisation
 *
 * The EBU and external device initialisation can be done as shown in following example.
 * This will configure EBU for 32bit BFlashSpansion device with BurstLength of 8:
 *
 * \code
 *     IfxEbu_BFlashSpansion_Config cfg;
 *     IfxEbu_BFlashSpansion_initMemoryConfig(&cfg, &MODULE_EBU0);
 *     cfg.memoryRegionConfig.baseAddress = 0xa4000000; // specify noncached segment A, driver will also enable the cached segment 8
 *     IfxEbu_BFlashSpansion bflash;
 *     IfxEbu_BFlashSpansion_initMemory(&bflash, &cfg);
 * \endcode
 *
 * After these functions have been executed, it's possible to fetch data and code from the external device.
 *
 * \subsection IfxLld_Ebu_BFlashSpansion_Operations Erase and Program
 *
 * This driver also allows to erase and program the burst flash.
 *
 * Example for erasing the first block:
 * \code
 *     IfxEbu_BFlashSpansion_eraseBlock(&bflash, 0xa4000000);
 * \endcode
 *
 * Example for programming some 32bit words:
 * \code
 *     IfxEbu_BFlashSpansion_programWord(&bflash, 0xa4000000 +  0, 0x11111111);
 *     IfxEbu_BFlashSpansion_programWord(&bflash, 0xa4000000 +  4, 0x22222222);
 *     IfxEbu_BFlashSpansion_programWord(&bflash, 0xa4000000 +  8, 0x33333333);
 *     IfxEbu_BFlashSpansion_programWord(&bflash, 0xa4000000 + 12, 0x44444444);
 * \endcode
 *
 * \defgroup IfxLld_Ebu_BFlashSpansion Spansion Burst Flash Driver
 * \ingroup IfxLld_Ebu
 * \defgroup IfxLld_Ebu_BFlashSpansion_DataStructures Data Structures
 * \ingroup IfxLld_Ebu_BFlashSpansion
 * \defgroup IfxLld_Ebu_BFlashSpansion_Module Module Functions
 * \ingroup IfxLld_Ebu_BFlashSpansion
 * \defgroup IfxLld_Ebu_BFlashSpansion_Operations Flash Operations
 * \ingroup IfxLld_Ebu_BFlashSpansion
 * \defgroup IfxLld_Ebu_BFlashSpansion_Commands Flash Command Sequences
 * \ingroup IfxLld_Ebu_BFlashSpansion
 */

#ifndef IFXEBU_BFLASHSPANSION_H
#define IFXEBU_BFLASHSPANSION_H 1

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include "Ebu/Std/IfxEbu.h"
#include "Scu/Std/IfxScuWdt.h"
#include "Scu/Std/IfxScuCcu.h"

/******************************************************************************/
/*-----------------------------Data Structures--------------------------------*/
/******************************************************************************/
/** \brief Bit Fields of BFlashSpansion burst configuration bits
 */
typedef struct
{
    uint16 burstLength : 3;					/**< \brief Burst length */
    uint16 reserved_1 : 3;					/**< \brief Reserved */
    uint16 clockConfiguration : 1;			/**< \brief Clock Configuration */
    uint16 burstSequence : 1;				/**< \brief Burst sequence */
    uint16 waitConfiguration : 1;			/**< \brief Wait Configuration */
    uint16 dataOutputConfiguration : 1;		/**< \brief Data Output Configuration */
    uint16 automaticSleepModeDisable : 4;	/**< \brief Automatic Sleep Mode Disable */
    uint16 reserved : 1;					/**< \brief Reserved */
    uint16 readMode : 1;					/**< \brief Read mode */
} IfxEbu_BFlashSpansion_BurstCfgBits;

/** \brief BFlashSpansion burst configuration
 */
typedef union
{
    uint16                             U;       /**< \brief Unsigned access */
    IfxEbu_BFlashSpansion_BurstCfgBits B;       /**< \brief Bitfield access */
} IfxEbu_BFlashSpansion_BurstCfg;

/** \brief Structure containing the BFlashSpansion configuration
 */
typedef struct
{
    Ifx_EBU                       *ebu;           /**< \brief Pointer to the base of EBU registers */
    IfxEbu_ChipSelect              chipSelect;    /**< \brief Chip Select Control */
    uint32                         baseAddress;   /**< \brief EBU base address. Range: 0x82000000 to 0x87FFFFFF For Access to External Memory via cached address range\n
                                                                                       0xA2000000 to 0xA7FFFFFF For Access to external memory via non-cached address range\n
                                                                                       0xF8400000 to 0xF840FFFF For sri slave interface */
    IfxEbu_BFlashSpansion_BurstCfg burstCfg;	  /** \brief BFlashSpansion burst configuration */
} IfxEbu_BFlashSpansion;

/** \brief BFlashSpansion configuration
 */
typedef struct
{
    Ifx_EBU                       *module;                      /**< \brief Pointer to the base of EBU registers */
    IfxEbu_ExternalClockRatio      externalClockRatio;			/**< \brief External clock ratio configuration */
    IfxEbu_ChipSelect              chipSelect;					/**< \brief Chip select control configuration */
    IfxEbu_ReadConfig              syncReadConfig;				/**< \brief Synchronous read configuration */
    IfxEbu_WriteConfig             asyncWriteConfig;			/**< \brief Asynchronous write configuration */
    IfxEbu_ReadAccessParameter     syncReadAccessParameter;		/**< \brief Synchronous read access parameter configuration */
    IfxEbu_WriteAccessParameter    asyncWriteAccessParameter;	/**< \brief Asynchronous write access parameter configuration */
    IfxEbu_ModuleConfig            moduleConfig;				/**< \brief Module configuration settings */
    IfxEbu_MemoryRegionConfig      memoryRegionConfig;			/**< \brief Memory region configuration settings */
    IfxEbu_ReadConfig              asyncReadConfig;				/**< \brief Asynchronous read configuration */
    IfxEbu_ReadAccessParameter     asyncReadAccessParameter;    /**< \brief Asynchronous read access parameter configuration */
    IfxEbu_BFlashSpansion_BurstCfg burstCfg;					/**< \brief BFlashSpansion burst configuration */
} IfxEbu_BFlashSpansion_Config;

/** \addtogroup IfxLld_Ebu_BFlashSpansion_Operations
 * \{ */

/******************************************************************************/
/*-------------------------Global Function Prototypes-------------------------*/
/******************************************************************************/

/**
 * \brief Erases a specified block in the Spansion flash memory.
 *
 * \param[in] bflash       Pointer to the burst flash handle.
 * \param[in] blockAddress The block address which should be erased.
 *
 * \retval None
 */
IFX_EXTERN void IfxEbu_BFlashSpansion_eraseBlock(IfxEbu_BFlashSpansion *bflash, uint32 blockAddress);

/**
 * \brief Programs a single 32-bit word into the Spansion burst flash memory at the specified address.
 *
 * \param[in] bflash  Pointer to the burst flash handle.
 * \param[in] address The target address in the flash memory where the data will be programmed.
 *                    Range: 0x82000000 to 0x87FFFFFF For Access to External Memory via cached address range\n
 *                           0xA2000000 to 0xA7FFFFFF For Access to external memory via non-cached address range\n
 *                           0xF8400000 to 0xF840FFFF For sri slave interface
 * \param[in] data    The 32-bit data word to be programmed at the specified address.
 *                    Range: 0 to 0xFFFFFFFF
 *
 * \retval None
 */
IFX_EXTERN void IfxEbu_BFlashSpansion_programWord(IfxEbu_BFlashSpansion *bflash, uint32 address, uint32 data);

/**
 * \brief Waits for the Spansion flash device to signal readiness.
 *
 * \param bflash [in] Pointer to the burst flash handle.
 *
 * \retval TRUE  The device signaled readiness.
 *         FALSE Timeout occurred, the device is not ready.
 */
IFX_EXTERN boolean IfxEbu_BFlashSpansion_waitForReady(IfxEbu_BFlashSpansion *bflash);

/** \} */

/** \addtogroup IfxLld_Ebu_BFlashSpansion_Commands
 * \{ */

/******************************************************************************/
/*-------------------------Global Function Prototypes-------------------------*/
/******************************************************************************/

/**
 * \brief Sets the burst configuration for a Spansion flash device.
 *
 * \param[in] bflash   Pointer to the burst flash handle.
 * \param[in] burstCfg The burst configuration which will be passed to the Spansion device.
 *
 * \return None
 */
IFX_EXTERN void IfxEbu_BFlashSpansion_cmdSetBurstConfig(IfxEbu_BFlashSpansion *bflash, IfxEbu_BFlashSpansion_BurstCfg burstCfg);

/** \} */

/******************************************************************************/
/*-------------------------Global Function Prototypes-------------------------*/
/******************************************************************************/

/**
 * \brief Initializes the BFlashSpansion memory module with the provided configuration.
 *
 * \param[inout] bflash Pointer to the burst flash handle.
 * \param[in]    config Pointer to BFlashSpansion's config structure.
 *
 * \retval None
 */
IFX_EXTERN void IfxEbu_BFlashSpansion_initMemory(IfxEbu_BFlashSpansion *bflash, const IfxEbu_BFlashSpansion_Config *config);

/**
 * \brief Initializes the memory configuration for the BFlashSpansion module.
 *
 * \param[inout] config Pointer to the BFlashSpansion configuration structure.
 * \param[in]    ebu    Pointer to the EBU module.
 *
 * \retval None
 */
IFX_EXTERN void IfxEbu_BFlashSpansion_initMemoryConfig(IfxEbu_BFlashSpansion_Config *config, Ifx_EBU *ebu);

#endif /* IFXEBU_BFLASHSPANSION_H */
