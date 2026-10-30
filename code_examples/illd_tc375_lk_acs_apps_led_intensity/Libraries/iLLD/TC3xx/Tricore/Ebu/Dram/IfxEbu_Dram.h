/**
 * \file IfxEbu_Dram.h
 * \brief EBU DRAM details
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
 * \defgroup IfxLld_Ebu_Dram_Usage How to use the DRAM Driver?
 * \ingroup IfxLld_Ebu
 *
 * The DRAM interface driver provides a default EBU configuration for communicating with external SDRAM devices such as MT48H8M32LF and HY52V651620B.
 *
 * \section IfxLld_Ebu_Dram_Preparation Preparation
 * \subsection IfxLld_Ebu_Dram_Include Include Files
 *
 * Include following header file into your C code:
 * \code
 * #include <Ebu/Dram/IfxEbu_Dram.h>
 * \endcode
 *
 * \subsection IfxLld_Ebu_Dram_Init_MT48 MT48H8M32LF Initialisation
 * The module initialisation can be done as shown in the example
 *
 * This will configure EBU for MT48H8M32LF device
 *
 * \code
 *     IfxEbu_Dram_Config cfg;
 *     IfxEbu_Dram_initMemoryConfig(&cfg, &MODULE_EBU0);
 *     cfg.memoryRegionConfig.baseAddress = 0xa4000000; // specify noncached segment A, driver will also enable the cached segment 8
 * \endcode
 *
 * The device is used as 16bit device
 * \code
 *     cfg.sdramDevice = IfxEbu_Dram_SDRAMDevice_8Mx16;
 * \endcode
 *
 * By default Mobile SDRAM settings are not configured hence we need to configure them
 * \code
 *     cfg.sdramModConfig.extendedBankSelect = IfxEbu_ExtendedOperationBankSelect_2;
 *     cfg.sdramModConfig.extendedOperationMode = 0x18;
 *     IfxEbu_Dram dram;
 *     IfxEbu_Dram_initMemory(&dram, &cfg);
 * \endcode
 *
 * \subsection IfxLld_Ebu_Dram_Init_HY52 HY52V65120B Initialisation
 *
 * Inoder to configure HY52V65120B on CS0 instead of MT48H8M32LF then do the following
 * \code
 *     IfxEbu_Dram_Config cfg;
 *     IfxEbu_Dram_initMemoryConfig(&cfg, &MODULE_EBU0);
 *     cfg.memoryRegionConfig.baseAddress = 0xa4000000; // specify noncached segment A, driver will also enable the cached segment 8
 *     cfg.sdramDevice = IfxEbu_Dram_SDRAMDevice_4Mx16;
 *     IfxEbu_Dram dram;
 *     IfxEbu_Dram_initMemory(&dram, &cfg);
 * \endcode
 *
 * SDRAM interface layer will configure the BANK and AWIDTH settings based on the size of the MEMORY device.
 *
 * \defgroup IfxLld_Ebu_Dram DRAM Driver
 * \ingroup IfxLld_Ebu
 * \defgroup IfxLld_Ebu_Dram_DataStructures Data Structures
 * \ingroup IfxLld_Ebu_Dram
 * \defgroup IfxLld_Ebu_Dram_Module Module Functions
 * \ingroup IfxLld_Ebu_Dram
 * \defgroup IfxLld_Ebu_Dram_Enum Enumerations
 * \ingroup IfxLld_Ebu_Dram
 */

#ifndef IFXEBU_DRAM_H
#define IFXEBU_DRAM_H 1

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include "Ebu/Std/IfxEbu.h"
#include "Stm/Std/IfxStm.h"
#include "Port/Std/IfxPort.h"
#include "Scu/Std/IfxScuWdt.h"

/******************************************************************************/
/*--------------------------------Enumerations--------------------------------*/
/******************************************************************************/

/** \addtogroup IfxLld_Ebu_Dram_Enum
 * \{ */
/** \brief SDRAMD device configuration
 */
typedef enum
{
    IfxEbu_Dram_SDRAMDevice_64Mx16bit = 0,  /**< \brief SDRAMD device configuration for 64Mx16bit */
    IfxEbu_Dram_SDRAMDevice_32Mx16bit,      /**< \brief SDRAMD device configuration for 32Mx16bit */
    IfxEbu_Dram_SDRAMDevice_16Mx16,			/**< \brief SDRAMD device configuration for 16Mx16 */
    IfxEbu_Dram_SDRAMDevice_8Mx16,			/**< \brief SDRAMD device configuration for 8Mx16 */
    IfxEbu_Dram_SDRAMDevice_4Mx16,			/**< \brief SDRAMD device configuration for 4Mx16 */
    IfxEbu_Dram_SDRAMDevice_1Mx16,          /**< \brief SDRAMD device configuration for 1Mx16. In this case only one Bank Address will be used by the External Device */
    IfxEbu_Dram_SDRAMDevice_32Mx32,			/**< \brief SDRAMD device configuration for 32Mx32 */
    IfxEbu_Dram_SDRAMDevice_16Mx32,			/**< \brief SDRAMD device configuration for 16Mx32 */
    IfxEbu_Dram_SDRAMDevice_8Mx32,			/**< \brief SDRAMD device configuration for 8Mx32 */
    IfxEbu_Dram_SDRAMDevice_4Mx32			/**< \brief SDRAMD device configuration for 4Mx32 */
} IfxEbu_Dram_SDRAMDevice;

/** \} */

/******************************************************************************/
/*-----------------------------Data Structures--------------------------------*/
/******************************************************************************/

/** \addtogroup IfxLld_Ebu_Dram_DataStructures
 * \{ */
/** \brief Structure containing the Dram configuration
 */
typedef struct
{
    Ifx_EBU          *ebu;				/**< \brief Pointer to the base of EBU registers */
    IfxEbu_ChipSelect chipSelect;		/**< \brief Chip select control */
    uint32            baseAddress;		/**< \brief EBU base address. Range: 0x82000000 to 0x87FFFFFF For Access to External Memory via cached address range\n
                                                                             0xA2000000 to 0xA7FFFFFF For Access to external memory via non-cached address range\n
                                                                             0xF8400000 to 0xF840FFFF For sri slave interface */
} IfxEbu_Dram;

/** \brief Dram configuration
 */
typedef struct
{
    Ifx_EBU                    *module;							/**< \brief Pointer to the base of EBU registers */
    IfxEbu_ChipSelect           chipSelect;						/**< \brief Chip select control configuration */
    IfxEbu_ReadConfig           syncReadConfig;					/**< \brief Synchronous read configuration */
    IfxEbu_WriteConfig          syncWriteConfig;				/**< \brief Synchronous write configuration */
    IfxEbu_ReadConfig           asyncReadConfig;				/**< \brief Asynchronous read configuration */
    IfxEbu_WriteConfig          asyncWriteConfig;				/**< \brief Asynchronous write configuration */
    IfxEbu_ReadAccessParameter  syncReadAccessParameter;		/**< \brief Synchronous read access parameter configuration */
    IfxEbu_WriteAccessParameter syncWriteAccessParameter;		/**< \brief Synchronous write access parameter configuration */
    IfxEbu_ReadAccessParameter  asyncReadAccessParameter;		/**< \brief Asynchronous read Access Parameter configuration */
    IfxEbu_WriteAccessParameter asyncWriteAccessParameter;		/**< \brief Asynchronous write Access Parameter configuration */
    IfxEbu_Dram_SDRAMDevice     sdramDevice;
    IfxEbu_SDRAMModConfig       sdramModConfig;					/**< \brief SDARM module configuration settings */
    IfxEbu_SDRAMRefreshConfig   sdramRefreshConfig;				/**< \brief SDARAM refresh configuration structure */
    IfxEbu_SDRAMControlConfig   sdramControlConfig;				/**< \brief SDARM control configuration structure */
    IfxEbu_MemoryRegionConfig   memoryRegionConfig;				/**< \brief Memory region configuration settings */
    IfxEbu_ExternalClockRatio   externalClockRatio;				/**< \brief Structure containing the External Clock Ratio */
    IfxEbu_ModuleConfig         moduleConfig;					/**< \brief Structure containing the Module configuration */
} IfxEbu_Dram_Config;

/** \} */

/** \addtogroup IfxLld_Ebu_Dram_Module
 * \{ */

/******************************************************************************/
/*-------------------------Global Function Prototypes-------------------------*/
/******************************************************************************/

/**
 * \brief Initializes the DRAM instance with the provided configuration.
 *
 * \param[inout] dram    Pointer to the DRAM instance to be initialized.
 * \param[in]    config  Pointer to the configuration structure containing DRAM settings.
 *
 * \retval None
 */
IFX_EXTERN void IfxEbu_Dram_initMemory(IfxEbu_Dram *dram, const IfxEbu_Dram_Config *config);

/**
 * \brief Initializes the memory configuration for the EBU DRAM module.
 *
 * \param[inout] config  Pointer to the IfxEbu_Dram_Config structure that will be initialized.
 * \param[in]    ebu     Pointer to the Ifx_EBU instance to be used for configuration.
 *
 * \retval None
 */
IFX_EXTERN void IfxEbu_Dram_initMemoryConfig(IfxEbu_Dram_Config *config, Ifx_EBU *ebu);

/** \} */

#endif /* IFXEBU_DRAM_H */
