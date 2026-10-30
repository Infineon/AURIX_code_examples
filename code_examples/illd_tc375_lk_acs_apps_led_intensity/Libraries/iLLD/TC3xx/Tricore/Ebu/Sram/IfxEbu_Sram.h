/**
 * \file IfxEbu_Sram.h
 * \brief EBU SRAM details
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
 * \defgroup IfxLld_Ebu_Sram_Usage How to use the SRAM Driver?
 * \ingroup IfxLld_Ebu
 *
 * The SRAM driver provides a default EBU configuration for communicating with external asynchronous and synchronous SRAM Devices with muxed or demuxed address/data interface.
 *
 * \section IfxLld_Ebu_Sram_Preparation Preparation
 * \subsection IfxLld_Ebu_Sram_Include Include Files
 *
 * Include following header file into your C code:
 * \code
 * #include <Ebu/Sram/IfxEbu_Sram.h>
 * \endcode
 *
 * \subsection IfxLld_Ebu_Sram_Init_demux32 2bit Demuxed Device
 *
 * This will configure EBU for 32bit demuxed device
 *
 * \code
 *     IfxEbu_Sram_Config cfg;
 *     IfxEbu_Sram_initMemoryConfig(&cfg, &MODULE_EBU0);
 *     cfg.memoryRegionConfig.baseAddress = 0xa4000000; // specify noncached segment A, driver will also enable the cached segment 8
 *     IfxEbu_Sram sram;
 *     IfxEbu_Sram_initMemory(&sram, &cfg);
 * \endcode
 *
 * In order to initialize a second Demuxed device on CS1 do the following
 * \code
 *     cfg.memoryRegionConfig.baseAddress = 0xa5000000; // specify noncached segment A, driver will also enable the cached segment 8
 *     cfg.chipselect = IfxEbu_ChipSelect_1;
 *     IfxEbu_Sram_initMemory(&sram, &cfg);
 * \endcode
 *
 * \subsection IfxLld_Ebu_Sram_Init_mux16 16bit muxed Device
 *
 * If you intend to configure a 16bit muxed device here is an example for CS1
 * \code
 *     cfg.device = IfxEbu_Sram_Device_muxedAsynchronousType;
 *     // configuring the device type for read
 *     cfg.readConfig.deviceInterface = IfxEbu_ExternalDeviceInterface_16bitMultiplexed;
 *     // configuring the device type for write
 *     cfg.writeConfig.deviceInterface = IfxEbu_ExternalDeviceInterface_16bitMultiplexed;
 *     cfg.memoryRegionConfig.baseAddress = 0xa5000000; // specify noncached segment A, driver will also enable the cached segment 8
 *     cfg.chipselect = IfxEbu_ChipSelect_1;
 *     IfxEbu_Sram_initMemory(&sram, &cfg);
 * \endcode
 *
 * Following the initialization of EBU reads and writes can be done to the external location
 *
 * \subsection IfxLld_Ebu_Sram_Init_SSRAM Synchronous SRAMs
 *
 * Configuring EBU for Synchronous Srams
 * \code
 *     IfxEbu_Sram_Config cfg;
 *     IfxEbu_Sram_initMemoryConfig(&cfg, &MODULE_EBU0);
 *     cfg.device = IfxEbu_Sram_Device_synchronousSramType;
 *     cfg.memoryRegionConfig.baseAddress = 0xa4000000; // specify noncached segment A, driver will also enable the cached segment 8
 *     IfxEbu_Sram sram;
 *     IfxEbu_Sram_initMemory(&sram, &cfg);
 * \endcode
 *
 * In order to configure second SSRAM device on CS1 do the following
 * \code
 *     cfg.memoryRegionConfig.baseAddress = 0xa5000000; // specify noncached segment A, driver will also enable the cached segment 8
 *     cfg.device = IfxEbu_Sram_Device_synchronousSramType;
 *     cfg.chipselect = IfxEbu_ChipSelect_1;
 *     IfxEbu_Sram_initMemory(&sram, &cfg);
 * \endcode
 *
 * \defgroup IfxLld_Ebu_Sram SRAM Driver
 * \ingroup IfxLld_Ebu
 * \defgroup IfxLld_Ebu_Sram_DataStructures Data Structures
 * \ingroup IfxLld_Ebu_Sram
 * \defgroup IfxLld_Ebu_Sram_Module Module Functions
 * \ingroup IfxLld_Ebu_Sram
 * \defgroup IfxLld_Ebu_Sram_Enum Enumerations
 * \ingroup IfxLld_Ebu_Sram
 */

#ifndef IFXEBU_SRAM_H
#define IFXEBU_SRAM_H 1

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include "Ebu/Std/IfxEbu.h"
#include "Port/Std/IfxPort.h"
#include "Scu/Std/IfxScuWdt.h"

/******************************************************************************/
/*--------------------------------Enumerations--------------------------------*/
/******************************************************************************/

/** \addtogroup IfxLld_Ebu_Sram_Enum
 * \{ */
/** \brief Types of SRAM Device Support
 */
typedef enum
{
    IfxEbu_Sram_Device_deMuxedAsynchronousType,  /**< \brief deMuxed Asynchronous Type */
    IfxEbu_Sram_Device_muxedAsynchronousType,    /**< \brief Muxed Asynchronous Type */
    IfxEbu_Sram_Device_synchronousSramType		 /**< \brief Synchronous Sram Type */
} IfxEbu_Sram_Device;

/** \} */

/******************************************************************************/
/*-----------------------------Data Structures--------------------------------*/
/******************************************************************************/

/** \addtogroup IfxLld_Ebu_Sram_DataStructures
 * \{ */
/** \brief Structure containing the Sram configuration
 */
typedef struct
{
    Ifx_EBU          *ebu;					/**< \brief Pointer to the base of EBU registers */
    IfxEbu_ChipSelect chipSelect;			/**< \brief Chip select control */
    uint32            baseAddress;			/**< \brief EBU base address. Range: 0 to 0xFFFFF */
} IfxEbu_Sram;

/** \brief Sram configuration
 */
typedef struct
{
    Ifx_EBU                    *module;							/**< \brief Pointer to the base of EBU registers */
    IfxEbu_ExternalClockRatio   externalClockRatio;				/**< \brief External clock ratio configuration */
    IfxEbu_ReadConfig           readConfig;						/**< \brief Read configuration */
    IfxEbu_WriteConfig          writeConfig;					/**< \brief Write configuration */
    IfxEbu_ReadAccessParameter  readAccessParameter;			/**< \brief Read access parameter configuration */
    IfxEbu_WriteAccessParameter writeAccessParameter;			/**< \brief Write access parameter configuration */
    IfxEbu_ChipSelect           chipSelect;						/**< \brief Chip select control configuration */
    IfxEbu_ModuleConfig         moduleConfig;					/**< \brief Module configuration settings */
    IfxEbu_MemoryRegionConfig   memoryRegionConfig;				/**< \brief Memory region configuration settings */
    IfxEbu_Sram_Device          device;							/**< \brief Types of SRAM Device Support */
    IfxEbu_ReadConfig           syncReadConfig;					/**< \brief Synchronous read configuration */
    IfxEbu_WriteConfig          syncWriteConfig;				/**< \brief Synchronous write configuration */
    IfxEbu_ReadAccessParameter  syncReadAccessParameter;		/**< \brief Synchronous read access parameter configuration */
    IfxEbu_WriteAccessParameter syncWriteAccessParameter;		/**< \brief Synchronous write access parameter configuration */
} IfxEbu_Sram_Config;

/** \} */

/** \addtogroup IfxLld_Ebu_Sram_Module
 * \{ */

/******************************************************************************/
/*-------------------------Global Function Prototypes-------------------------*/
/******************************************************************************/

/**
 * \brief Initializes the SRAM instance with the provided configuration.
 *
 * \param[inout] sram   Pointer to the SRAM instance to be initialized.
 * \param[in]    config Pointer to the configuration structure containing initialization parameters.
 *
 * \retval None
 */
IFX_EXTERN void IfxEbu_Sram_initMemory(IfxEbu_Sram *sram, const IfxEbu_Sram_Config *config);

/**
 * \brief Initializes the memory configuration for the SRAM module.
 *
 * \param[inout] config  Pointer to the SRAM configuration structure.
 * \param[in]    ebu     Pointer to the EBU module instance.
 *
 * \retval None
 */
IFX_EXTERN void IfxEbu_Sram_initMemoryConfig(IfxEbu_Sram_Config *config, Ifx_EBU *ebu);

/** \} */

#endif /* IFXEBU_SRAM_H */
