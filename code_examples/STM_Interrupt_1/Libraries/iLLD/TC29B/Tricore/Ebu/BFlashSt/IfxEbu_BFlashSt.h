/**
 * \file IfxEbu_BFlashSt.h
 * \brief EBU BFLASHST details
 * \ingroup IfxLld_Ebu
 *
 * \version iLLD_1_0_1_9_0
 * \copyright Copyright (c) 2018 Infineon Technologies AG. All rights reserved.
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
typedef struct
{
    uint16 burstLength : 3;
    uint16 wrapping : 1;
    uint16 reserved_2 : 2;
    uint16 validClockEdge : 1;
    uint16 burstType : 1;
    uint16 validDataReady : 1;
    uint16 ylat : 1;
    uint16 reserved_1 : 1;
    uint16 xlat : 3;
    uint16 reserved : 1;
    uint16 readSelect : 1;
} IfxEbu_BFlashSt_BurstCfgBits;

/** \} */

/** \addtogroup IfxLld_Ebu_BFlashSt_DataStructures
 * \{ */
typedef union
{
    uint16                       U;
    IfxEbu_BFlashSt_BurstCfgBits B;
} IfxEbu_BFlashSt_BurstCfg;

/** \} */

/** \addtogroup IfxLld_Ebu_BFlashSt_DataStructures
 * \{ */
typedef struct
{
    Ifx_EBU          *ebu;
    IfxEbu_ChipSelect chipSelect;
    uint32            baseAddress;
    uint32            passwordLower;
    uint32            passwordUpper;
    boolean           hasTuningProtection;
} IfxEbu_BFlashSt;

typedef struct
{
    Ifx_EBU                    *module;
    IfxEbu_ExternalClockRatio   externalClockRatio;
    IfxEbu_ChipSelect           chipSelect;
    IfxEbu_ReadConfig           syncReadConfig;
    IfxEbu_WriteConfig          asyncWriteConfig;
    IfxEbu_ReadAccessParameter  syncReadAccessParameter;
    IfxEbu_WriteAccessParameter asyncWriteAccessParameter;
    IfxEbu_ModuleConfig         moduleConfig;
    IfxEbu_MemoryRegionConfig   memoryRegionConfig;
    IfxEbu_ReadConfig           asyncReadConfig;
    IfxEbu_ReadAccessParameter  asyncReadAccessParameter;
    IfxEbu_BFlashSt_BurstCfg    burstCfg;
    uint32                      passwordLower;
    uint32                      passwordUpper;
    boolean                     hasTuningProtection;
} IfxEbu_BFlashSt_Config;

/** \} */

/** \addtogroup IfxLld_Ebu_BFlashSt_Module
 * \{ */

/******************************************************************************/
/*-------------------------Global Function Prototypes-------------------------*/
/******************************************************************************/

/**
 * \param bflash burst flash handle
 * \param config EBU memory configuration
 * \return None
 */
IFX_EXTERN void IfxEbu_BFlashSt_initMemory(IfxEbu_BFlashSt *bflash, const IfxEbu_BFlashSt_Config *config);

/**
 * \param config EBU memory configuration
 * \param ebu pointer to the base of EBU registers
 * \return None
 */
IFX_EXTERN void IfxEbu_BFlashSt_initMemoryConfig(IfxEbu_BFlashSt_Config *config, Ifx_EBU *ebu);

/** \} */

/** \addtogroup IfxLld_Ebu_BFlashSt_Operations
 * \{ */

/******************************************************************************/
/*-------------------------Global Function Prototypes-------------------------*/
/******************************************************************************/

/**
 * \param bflash burst flash handle
 * \param blockAddress the block address which should be erased
 * \return None
 */
IFX_EXTERN void IfxEbu_BFlashSt_eraseBlock(const IfxEbu_BFlashSt *bflash, uint32 blockAddress);

/**
 * \param bflash burst flash handle
 * \param address the address which should be programmed
 * \param data the data word which should be programmed
 * \return None
 */
IFX_EXTERN void IfxEbu_BFlashSt_programWord(const void *bflash, uint32 address, uint32 data);

/**
 * \param bflash burst flash handle
 * \return TRUE if ready was notified, (planned, not implemented) FALSE on timeout: device not ready
 */
IFX_EXTERN boolean IfxEbu_BFlashSt_waitForReady(const IfxEbu_BFlashSt *bflash);

/** \} */

/** \addtogroup IfxLld_Ebu_BFlashSt_Commands
 * \{ */

/******************************************************************************/
/*-------------------------Global Function Prototypes-------------------------*/
/******************************************************************************/

/**
 * \param bflash burst flash handle
 * \param blockAddress the base address of the block which should be erased
 * \return None
 */
IFX_EXTERN void IfxEbu_BFlashSt_cmdBlockErase(const IfxEbu_BFlashSt *bflash, uint32 blockAddress);

/**
 * \param bflash burst flash handle
 * \param blockAddress the base address of the block which should be unprotected
 * \return None
 */
IFX_EXTERN void IfxEbu_BFlashSt_cmdClearBlockProtection(const IfxEbu_BFlashSt *bflash, uint32 blockAddress);

/**
 * \param bflash burst flash handle
 * \return None
 */
IFX_EXTERN void IfxEbu_BFlashSt_cmdClearStatusRegister(const IfxEbu_BFlashSt *bflash);

/**
 * \param bflash burst flash handle
 * \return None
 */
IFX_EXTERN void IfxEbu_BFlashSt_cmdEraseAllMainBlocks(const IfxEbu_BFlashSt *bflash);

/**
 * \param bflash burst flash handle
 * \return None
 */
IFX_EXTERN void IfxEbu_BFlashSt_cmdProgramEraseResume(const IfxEbu_BFlashSt *bflash);

/**
 * \param bflash burst flash handle
 * \return None
 */
IFX_EXTERN void IfxEbu_BFlashSt_cmdProgramEraseSuspend(const IfxEbu_BFlashSt *bflash);

/**
 * \param bflash burst flash handle
 * \return None
 */
IFX_EXTERN void IfxEbu_BFlashSt_cmdProgramTuningProtection(const IfxEbu_BFlashSt *bflash);

/**
 * \param bflash burst flash handle
 * \param address the address which should be programmed
 * \param data the data word which should be programmed
 * \return None
 */
IFX_EXTERN void IfxEbu_BFlashSt_cmdProgramWord(const IfxEbu_BFlashSt *bflash, uint32 address, uint32 data);

/**
 * \param bflash burst flash handle
 * \param signatureOffset Signature offset
 * \return the signature at the given signatureOffset
 */
IFX_EXTERN uint32 IfxEbu_BFlashSt_cmdReadElectronicSignature(const IfxEbu_BFlashSt *bflash, uint32 signatureOffset);

/**
 * \param bflash burst flash handle
 * \return None
 */
IFX_EXTERN void IfxEbu_BFlashSt_cmdReadMemoryArray(const IfxEbu_BFlashSt *bflash);

/**
 * \param bflash burst flash handle
 * \return None
 */
IFX_EXTERN void IfxEbu_BFlashSt_cmdReadQuery(const IfxEbu_BFlashSt *bflash);

/**
 * \param bflash burst flash handle
 * \return the current status word
 */
IFX_EXTERN uint32 IfxEbu_BFlashSt_cmdReadStatus(const IfxEbu_BFlashSt *bflash);

/**
 * \param bflash burst flash handle
 * \param blockAddress the base address of the block which should be protected
 * \return None
 */
IFX_EXTERN void IfxEbu_BFlashSt_cmdSetBlockProtection(const IfxEbu_BFlashSt *bflash, uint32 blockAddress);

/**
 * \param bflash burst flash handle
 * \param burstCfg the burst configuration which will be passed to the ST device
 * \return None
 */
IFX_EXTERN void IfxEbu_BFlashSt_cmdSetBurstConfig(const IfxEbu_BFlashSt *bflash, IfxEbu_BFlashSt_BurstCfg burstCfg);

/**
 * \param bflash burst flash handle
 * \return None
 */
IFX_EXTERN void IfxEbu_BFlashSt_cmdUnlockTuningProtection(const IfxEbu_BFlashSt *bflash);

/** \} */

#endif /* IFXEBU_BFLASHST_H */
