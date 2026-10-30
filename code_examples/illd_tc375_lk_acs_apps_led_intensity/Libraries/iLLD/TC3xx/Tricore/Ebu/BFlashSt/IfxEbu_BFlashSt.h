/**
 * \file IfxEbu_BFlashSt.h
 * \brief EBU BFLASHST details
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
 * \defgroup IfxLld_Ebu_BFlashSt_Usage How to use the ST Burst Flash Driver?
 * \ingroup IfxLld_Ebu
 *
 * The BFlashSt interface driver provides a default EBU configuration to access external Burst Flash devices from ST (e.g. M58BW032)
 *
 * In the following sections it will be described, how to integrate the driver into the application framework.
 *
 * \section IfxLld_Ebu_BFlashSt_Preparation Preparation
 * \subsection IfxLld_Ebu_BFlashSt_Include Include Files
 *
 * Include following header file into your C code:
 * \code
 * #include <Ebu/BFlashSt/IfxEbu_BFlashSt.h>
 * \endcode
 *
 * \subsection IfxLld_Ebu_BFlashSt_Init Module Initialisation
 *
 * The EBU and external device initialisation can be done as shown in following example.
 * This will configure EBU for 32bit BFlashSt device with BurstLength of 8:
 *
 * \code
 *     IfxEbu_BFlashSt_Config cfg;
 *     IfxEbu_BFlashSt_initMemoryConfig(&cfg, &MODULE_EBU0);
 *     cfg.memoryRegionConfig.baseAddress = 0xa4000000; // specify noncached segment A, driver will also enable the cached segment 8
 *     IfxEbu_BFlashSt bflash;
 *     IfxEbu_BFlashSt_initMemory(&bflash, &cfg);
 * \endcode
 *
 * After these functions have been executed, it's possible to fetch data and code from the external device.
 *
 * \subsection IfxLld_Ebu_BFlashSt_Operations Erase and Program
 *
 * This driver also allows to erase and program the burst flash.
 *
 * Example for erasing the first block:
 * \code
 *     IfxEbu_BFlashSt_eraseBlock(&bflash, 0xa4000000);
 * \endcode
 *
 * Example for programming some 32bit words:
 * \code
 *     IfxEbu_BFlashSt_programWord(&bflash, 0xa4000000 +  0, 0x11111111);
 *     IfxEbu_BFlashSt_programWord(&bflash, 0xa4000000 +  4, 0x22222222);
 *     IfxEbu_BFlashSt_programWord(&bflash, 0xa4000000 +  8, 0x33333333);
 *     IfxEbu_BFlashSt_programWord(&bflash, 0xa4000000 + 12, 0x44444444);
 * \endcode
 *
 * \subsection IfxLld_Ebu_BFlashSt_Commands Flash Command Sequences
 *
 * Functions are available for various command sequences of the M58BW032 device.
 *
 * E.g. with following commands it's possible to retrieve device informations:
 * \code
 *     uint32 manufacturerCode = IfxEbu_BFlashSt_cmdReadElectronicSignature(&bflash, 0);
 *     uint32 deviceCode       = IfxEbu_BFlashSt_cmdReadElectronicSignature(&bflash, 1);
 *     uint32 burstCfg         = IfxEbu_BFlashSt_cmdReadElectronicSignature(&bflash, 5);
 * \endcode
 *
 * \defgroup IfxLld_Ebu_BFlashSt ST Burst Flash Driver
 * \ingroup IfxLld_Ebu
 * \defgroup IfxLld_Ebu_BFlashSt_DataStructures Data Structures
 * \ingroup IfxLld_Ebu_BFlashSt
 * \defgroup IfxLld_Ebu_BFlashSt_Module Module Functions
 * \ingroup IfxLld_Ebu_BFlashSt
 * \defgroup IfxLld_Ebu_BFlashSt_Operations Flash Operations
 * \ingroup IfxLld_Ebu_BFlashSt
 * \defgroup IfxLld_Ebu_BFlashSt_Commands Flash Command Sequences
 * \ingroup IfxLld_Ebu_BFlashSt
 */

#ifndef IFXEBU_BFLASHST_H
#define IFXEBU_BFLASHST_H 1

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include "Ebu/Std/IfxEbu.h"
#include "Scu/Std/IfxScuWdt.h"
#include "Scu/Std/IfxScuCcu.h"

/******************************************************************************/
/*-----------------------------Data Structures--------------------------------*/
/******************************************************************************/

/** \addtogroup IfxLld_Ebu_BFlashSt_DataStructures
 * \{ */
/** \brief Bit Fields of BFlashSt burst configuration bits
 */
typedef struct
{
    uint16 burstLength : 3;		/**< \brief Burst length */
    uint16 wrapping : 1;        /**< \brief Wrapping */
    uint16 reserved_2 : 2;		/**< \brief Reserved */
    uint16 validClockEdge : 1;	/**< \brief Valid clock edge */
    uint16 burstType : 1;		/**< \brief Burst type */
    uint16 validDataReady : 1;	/**< \brief Reserved */
    uint16 ylat : 1;			/**< \brief Y-Latency */
    uint16 reserved_1 : 1;		/**< \brief Burst length */
    uint16 xlat : 3;			/**< \brief X-Latency */
    uint16 reserved : 1;		/**< \brief Reserved */
    uint16 readSelect : 1;		/**< \brief Read select */
} IfxEbu_BFlashSt_BurstCfgBits;

/** \} */

/** \addtogroup IfxLld_Ebu_BFlashSt_DataStructures
 * \{ */
/** \brief BFlashSt burst configuration
 */
typedef union
{
    uint16                       U;		/**< \brief Unsigned access */
    IfxEbu_BFlashSt_BurstCfgBits B;		/**< \brief Bitfield access */
} IfxEbu_BFlashSt_BurstCfg;

/** \} */

/** \addtogroup IfxLld_Ebu_BFlashSt_DataStructures
 * \{ */
/** \brief Structure containing the BFlashSt configuration
 */
typedef struct
{
    Ifx_EBU          *ebu;						/**< \brief Pointer to the base of EBU registers */
    IfxEbu_ChipSelect chipSelect;				/**< \brief Chip select control */
    uint32            baseAddress;				/**< \brief EBU base address. Range: 0x82000000 to 0x87FFFFFF For Access to External Memory via cached address range\n
                                                                                     0xA2000000 to 0xA7FFFFFF For Access to external memory via non-cached address range\n
                                                                                     0xF8400000 to 0xF840FFFF For sri slave interface */
    uint32            passwordLower;			/**< \brief Lower password for block protection. Range: 0 to 0xFFFFFFFF */
    uint32            passwordUpper;			/**< \brief Upper password for block protection. Range: 0 to 0xFFFFFFFF */
    boolean           hasTuningProtection;		/**< \brief Tuning Protection Status. Range: when '1' Tuning Protection enabled, when '0' Tuning Protection Disabled */
} IfxEbu_BFlashSt;

/** \brief BFlashSt configuration
 */
typedef struct
{
    Ifx_EBU                    *module;							/**< \brief Pointer to the base of EBU registers */
    IfxEbu_ExternalClockRatio   externalClockRatio;				/**< \brief External clock ratio configuration */
    IfxEbu_ChipSelect           chipSelect;						/**< \brief Chip select control configuration */
    IfxEbu_ReadConfig           syncReadConfig;					/**< \brief Synchronous read configuration */
    IfxEbu_WriteConfig          asyncWriteConfig;				/**< \brief Asynchronous write configuration */
    IfxEbu_ReadAccessParameter  syncReadAccessParameter;		/**< \brief Synchronous read access parameter configuration */
    IfxEbu_WriteAccessParameter asyncWriteAccessParameter;		/**< \brief Asynchronous write access parameter configuration */
    IfxEbu_ModuleConfig         moduleConfig;					/**< \brief Module configuration settings */
    IfxEbu_MemoryRegionConfig   memoryRegionConfig;				/**< \brief Memory region configuration settings */
    IfxEbu_ReadConfig           asyncReadConfig;				/**< \brief Asynchronous read configuration */
    IfxEbu_ReadAccessParameter  asyncReadAccessParameter;		/**< \brief Asynchronous read access parameter structure configuration */
    IfxEbu_BFlashSt_BurstCfg    burstCfg;						/**< \brief BFlashSt burst configuration structure */
    uint32                      passwordLower;					/**< \brief Lower password for block protection. Range: 0 to 0xFFFFFFFF */
    uint32                      passwordUpper;					/**< \brief Upper password for block protection. Range: 0 to 0xFFFFFFFF */
    boolean                     hasTuningProtection;			/**< \brief Tuning Protection Status. Range: when '1' Tuning Protection enabled, when '0' Tuning Protection Disabled */
} IfxEbu_BFlashSt_Config;

/** \} */

/** \addtogroup IfxLld_Ebu_BFlashSt_Module
 * \{ */

/******************************************************************************/
/*-------------------------Global Function Prototypes-------------------------*/
/******************************************************************************/

/**
 * \brief Initializes the burst flash memory with the specified configuration.
 *
 * \param[inout] bflash  Pointer to the burst flash handle structure.
 * \param[in]    config  Pointer to the configuration structure.
 *
 * \retval None
 */
IFX_EXTERN void IfxEbu_BFlashSt_initMemory(IfxEbu_BFlashSt *bflash, const IfxEbu_BFlashSt_Config *config);

/**
 * \brief Initializes the EBU BFlash memory configuration.
 *
 * \param[inout] config Pointer to the EBU memory configuration structure.
 * \param[in]    ebu    Pointer to the base of EBU registers.
 *
 * \retval None
 */
IFX_EXTERN void IfxEbu_BFlashSt_initMemoryConfig(IfxEbu_BFlashSt_Config *config, Ifx_EBU *ebu);

/** \} */

/** \addtogroup IfxLld_Ebu_BFlashSt_Operations
 * \{ */

/******************************************************************************/
/*-------------------------Global Function Prototypes-------------------------*/
/******************************************************************************/

/**
 * \brief Erases a specified block in the burst flash memory.
 *
 * \param[in] bflash        Pointer to the burst flash handle structure.
 * \param[in] blockAddress  The address of the block to be erased.
 *                          Range: 0x82000000 to 0x87FFFFFF For Access to External Memory via cached address range\n
 *                                 0xA2000000 to 0xA7FFFFFF For Access to external memory via non-cached address range\n
 *                                 0xF8400000 to 0xF840FFFF For sri slave interface
 *
 * \retval None
 */
IFX_EXTERN void IfxEbu_BFlashSt_eraseBlock(const IfxEbu_BFlashSt *bflash, uint32 blockAddress);

/**
 * \brief Programs a 32-bit word into the burst flash memory at the specified address.
 *
 * \param[in] bflash   Pointer to the burst flash handle structure.
 * \param[in] address  The 32-bit memory address where the data will be programmed.
 *                     Range: 0x82000000 to 0x87FFFFFF For Access to External Memory via cached address range\n
 *                            0xA2000000 to 0xA7FFFFFF For Access to external memory via non-cached address range\n
 *                            0xF8400000 to 0xF840FFFF For sri slave interface
 * \param[in] data     The 32-bit data value to be written to the flash memory.
 *                     Range: 0 to 0xFFFFFFFF
 *
 * \retval None
 */
IFX_EXTERN void IfxEbu_BFlashSt_programWord(const void *bflash, uint32 address, uint32 data);

/**
 * \brief Waits for the burst flash module to become ready.
 *
 * \param[in] bflash  Pointer to the burst flash handle structure.
 *
 * \retval TRUE   The burst flash module is ready.
 *         FALSE  Timeout occurred; the module is not ready.
 */
IFX_EXTERN boolean IfxEbu_BFlashSt_waitForReady(const IfxEbu_BFlashSt *bflash);

/** \} */

/** \addtogroup IfxLld_Ebu_BFlashSt_Commands
 * \{ */

/******************************************************************************/
/*-------------------------Global Function Prototypes-------------------------*/
/******************************************************************************/

/**
 * \brief Erases a specified block in the burst flash memory.
 *
 * \param[in] bflash        Pointer to the burst flash handle structure.
 * \param[in] blockAddress  The base address of the block to be erased.
 *                          Range: 0x82000000 to 0x87FFFFFF For Access to External Memory via cached address range\n
 *                                 0xA2000000 to 0xA7FFFFFF For Access to external memory via non-cached address range\n
 *                                 0xF8400000 to 0xF840FFFF For sri slave interface
 *
 * \retval None
 */
IFX_EXTERN void IfxEbu_BFlashSt_cmdBlockErase(const IfxEbu_BFlashSt *bflash, uint32 blockAddress);

/**
 * \brief Clears the block protection for a specified block in the flash memory.
 *
 * \param[in] bflash       Pointer to the burst flash handle structure.
 * \param[in] blockAddress The base address of the block which should be unprotected.
 *                         Range: 0x82000000 to 0x87FFFFFF For Access to External Memory via cached address range\n
 *                                0xA2000000 to 0xA7FFFFFF For Access to external memory via non-cached address range\n
 *                                0xF8400000 to 0xF840FFFF For sri slave interface
 *
 * \retval None
 */
IFX_EXTERN void IfxEbu_BFlashSt_cmdClearBlockProtection(const IfxEbu_BFlashSt *bflash, uint32 blockAddress);

/**
 * \brief Clears the status register of the burst flash module.
 *
 * \param[in] bflash  Pointer to the burst flash handle structure.
 *
 * \retval None
 */
IFX_EXTERN void IfxEbu_BFlashSt_cmdClearStatusRegister(const IfxEbu_BFlashSt *bflash);

/**
 * \brief Erases all main blocks in the burst flash memory.
 *
 * \param[in] bflash  Pointer to the burst flash handle structure.
 *
 * \retval None
 */
IFX_EXTERN void IfxEbu_BFlashSt_cmdEraseAllMainBlocks(const IfxEbu_BFlashSt *bflash);

/**
 * \brief Resumes the program/erase operation for the specified burst flash handle.
 *
 * \param[in] bflash  Pointer to the burst flash handle structure.
 *
 * \retval None
 */
IFX_EXTERN void IfxEbu_BFlashSt_cmdProgramEraseResume(const IfxEbu_BFlashSt *bflash);

/**
 * \brief Suspends an ongoing program or erase operation in the burst flash module.
 *
 * \param[in] bflash  Pointer to the burst flash handle structure.
 *
 * \retval None
 */
IFX_EXTERN void IfxEbu_BFlashSt_cmdProgramEraseSuspend(const IfxEbu_BFlashSt *bflash);

/**
 * \brief Programs the tuning protection for the flash module.
 *
 * \param[in] bflash  Pointer to the burst flash configuration structure.
 *
 * \retval None
 */
IFX_EXTERN void IfxEbu_BFlashSt_cmdProgramTuningProtection(const IfxEbu_BFlashSt *bflash);

/**
 * \brief Programs a 32-bit word at the specified address in the burst flash memory.
 *
 * \param[in] bflash  Pointer to the burst flash handle structure.
 * \param[in] address Memory address to program the data.
 *                    Range: 0x82000000 to 0x87FFFFFF For Access to External Memory via cached address range\n
 *                           0xA2000000 to 0xA7FFFFFF For Access to external memory via non-cached address range\n
 *                           0xF8400000 to 0xF840FFFF For sri slave interface
 * \param[in] data    The data word which should be programmed
 *                    Range: 0 to 0xFFFFFFFF
 *
 * \retval None
 */
IFX_EXTERN void IfxEbu_BFlashSt_cmdProgramWord(const IfxEbu_BFlashSt *bflash, uint32 address, uint32 data);

/**
 * \brief Reads the electronic signature from the burst flash module at the specified offset.
 *
 * \param[in] bflash           Pointer to the burst flash handle structure.
 * \param[in] signatureOffset  Offset within the electronic signature area where the signature is located.
 *                             Range: 0 to 0xFFFFFFFF
 *
 * \retval uint32 The signature at the given signatureOffset
 *         Range: 0 to 0xFFFFFFFF
 */
IFX_EXTERN uint32 IfxEbu_BFlashSt_cmdReadElectronicSignature(const IfxEbu_BFlashSt *bflash, uint32 signatureOffset);

/**
 * \brief Reads memory arrays from the burst flash memory.
 *
 * \param[in] bflash Pointer to the burst flash handle structure.
 *
 * \retval None
 */
IFX_EXTERN void IfxEbu_BFlashSt_cmdReadMemoryArray(const IfxEbu_BFlashSt *bflash);

/**
 * \brief Reads or queries data from the burst flash memory.
 *
 * \param[in] bflash Pointer to the burst flash handle structure.
 *
 * \retval void
 */
IFX_EXTERN void IfxEbu_BFlashSt_cmdReadQuery(const IfxEbu_BFlashSt *bflash);

/**
 * \brief Reads the current status word from the burst flash.
 *
 * \param[in] bflash Pointer to the burst flash handle structure.
 *
 * \retval uint32 The current status word of the burst flash.
 *         Range: 0 to 0xFFFFFFFF
 */
IFX_EXTERN uint32 IfxEbu_BFlashSt_cmdReadStatus(const IfxEbu_BFlashSt *bflash);

/**
 * \brief Sets protection for a specified block in the burst flash memory.
 *
 * \param[in] bflash        Pointer to the burst flash handle structure.
 * \param[in] blockAddress  The base address of the block to be protected.
 *                          Range: Range: 0x82000000 to 0x87FFFFFF For Access to External Memory via cached address range\n
 *                                        0xA2000000 to 0xA7FFFFFF For Access to external memory via non-cached address range\n
 *                                        0xF8400000 to 0xF840FFFF For sri slave interface
 *
 * \retval None
 */
IFX_EXTERN void IfxEbu_BFlashSt_cmdSetBlockProtection(const IfxEbu_BFlashSt *bflash, uint32 blockAddress);

/**
 * \brief Sets burst configuration for a specified flash memory.
 *
 * \param[in] bflash   Pointer to the burst flash handle structure.
 * \param[in] burstCfg The burst configuration which will be passed to the ST device.
 *
 * \return None
 */
IFX_EXTERN void IfxEbu_BFlashSt_cmdSetBurstConfig(const IfxEbu_BFlashSt *bflash, IfxEbu_BFlashSt_BurstCfg burstCfg);

/**
 * \brief Unlocks the tuning protection for the specified burst flash handle.
 *
 * \param[in] bflash  Pointer to the burst flash handle structure.
 *
 * \retval None
 */
IFX_EXTERN void IfxEbu_BFlashSt_cmdUnlockTuningProtection(const IfxEbu_BFlashSt *bflash);

/** \} */

#endif /* IFXEBU_BFLASHST_H */
