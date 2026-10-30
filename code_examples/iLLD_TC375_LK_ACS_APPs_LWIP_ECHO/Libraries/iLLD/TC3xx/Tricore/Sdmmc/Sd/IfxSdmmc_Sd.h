/**
 * \file IfxSdmmc_Sd.h
 * \brief SDMMC SD details
 * \ingroup IfxLld_Sdmmc
 *
 * \version iLLD_1_22_0
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
 * \defgroup IfxLld_Sdmmc_Sd_Usage How to use the Sdmmc Driver Interface driver?
 * \ingroup IfxLld_Sdmmc_Sd
 *
 * In the following sections it will be described, how to integrate the driver into the application framework.
 *
 * \section IfxLld_Sdmmc_Sd_Preparation Preparation
 * \subsection IfxLld_Sdmmc_Sd_Include Include Files
 *
 * Include following header file into your C code:
 * \code
 * #include <Sdmmc/Sd/IfxSdmmc_Sd.h>
 * \endcode
 *
 * \subsection IfxLld_Sdmmc_Sd_Variables Variables
 *
 * Declare the Sdmmc handle and the Data buffers as global variables in your C code:
 *
 * \code
 * IfxSdmmc_Sd handle;
 *
 * uint32 txData[8];
 * uint32 rxData[8];
 * uint32 sectorNumber;
 * uint16 blockCount = 10;
 * \endcode
 *
 * \subsection IfxLld_Sdmmc_Sd_Init Module Initialisation
 *
 * The module initialisation can be done as followed:
 * \code
 * // create a config structure
 * IfxSdmmc_Sd_Config config;
 * // fill the config structure with default values
 * IfxSdmmc_Sd_initModuleConfig(&config, &MODULE_SDMMC0);
 *
 * {
 *     IfxSdmmc_Sd_Pins pins;
 *     pins.clk = &IfxSdmmc0_CLK_P15_1_OUT;
 *     pins.cmd = &IfxSdmmc0_CMD_P15_3_INOUT;
 *     pins.dat0 = &IfxSdmmc0_DAT0_P20_7_INOUT;
 *     pins.dat1 = &IfxSdmmc0_DAT1_P20_8_INOUT;
 *     pins.dat2 = &IfxSdmmc0_DAT2_P20_10_INOUT;
 *     pins.dat3 = &IfxSdmmc0_DAT3_P20_11_INOUT;
 *     inputMode = IfxPort_InputMode_pullUp;
 *     pinDriver = IfxPort_PadDriver_cmosAutomotiveSpeed1;
 * }
 *
 * config.pins = &pins;
 * // change bus width
 * config.cardConfig.dataWidth = IfxSdmmc_SdDataTransferWidth_1Bit;
 * // change speed mode
 * config.cardConfig.speedMode = IfxSdmmc_SdSpeedMode_normal;
 *
 * config.useDma = FALSE;
 * // select DMA type if DMA is used
 * // config.dmaConfig.dmaType = IfxSdmmc_DmaType_sdma;
 *
 * // initialise the module
 * IfxSdmmc_Sd_initModule(&handle, &config);
 * \endcode
 *
 * The SDMMC is ready for use now!
 *
 * \section IfxLld_Sdmmc_Sd_DataTransfers Data Transfers
 * \subsection  IfxLld_Sdmmc_Sd_DataTransfers_nonDma non DMA data transfers
 * \code
 * // prepare the data buffers
 * int i;
 * for (i = 0; i < 8; ++i)
 * {
 *     txData[i] = 0x1234000 + i;
 *     rxData[i] = 0;
 * }
 *
 * // specify the sector number of the card for data transfers
 * sectorNumber = 10;
 *
 * IfxSdmmc_Sd_writeBlock(&handle, sectorNumber, txData);
 * IfxSdmmc_Sd_readBlock(&handle, sectorNumber, rxData);
 * \endcode
 *
 * \subsection  IfxLld_Sdmmc_Sd_DataTransfers_sdma SDMA data transfers
 *
 * after selecting the DMA type in the module initialisation phase,
 * data transfers an be done as follows
 * \code
 * // prepare the data buffers
 * int i;
 * for (i = 0; i < 8; ++i)
 * {
 *     txData[i] = 0x1234000 + i;
 *     rxData[i] = 0;
 * }
 *
 * // specify the sector number of the card for data transfers
 * sectorNumber = 10;
 *
 * IfxSdmmc_Sd_writeBlock(&handle, sectorNumber, txData);
 * IfxSdmmc_Sd_readBlock(&handle, sectorNumber, rxData);
 * \endcode
 *
 * \subsection  IfxLld_Sdmmc_Sd_DataTransfers_adma2 ADMA2 data transfers
 *
 * after selecting the DMA type as ADMA2 in the module initialisation phase,
 * data transfers an be done as follows
 * \code
 * // the data buffers are assumed to be defined globally
 * // NUM_ADMA2_DESCRIPTORS and BUFF_LENGTH are also assumed to be defined globally
 * //uint32 txdata[NUM_ADMA2_DESCRIPTORS][BUFF_LENGTH];
 * //uint32 rxdata[NUM_ADMA2_DESCRIPTORS][BUFF_LENGTH];
 *
 * // prepare the data buffers
 * int i, j;
 * for (i = 0; i < NUM_ADMA2_DESCRIPTORS; ++i)
 * {
 *     for (j = 0; j < BUFF_LENGTH; ++i)
 *     {
 *         txData[i][j] = 0x1234000 + j;
 *         rxData[i][j] = 0;
 *     }
 * }
 *
 * // prepare ADMA2 descriptor table
 * // TX
 * IfxSdmmc_Adma2Descriptor adma2TxDescr[NUM_ADMA2_DESCRIPTORS];
 *
 * int i;
 * for (i=0; i<NUM_ADMA2_DESCRIPTORS; i++)
 * {
 *     adma2TxDescr[i].valid = 1;
 *     adma2TxDescr[i].act = IfxSdmmc_AdmaActionSymbol_tran;
 *     adma2TxDescr[i].length = IFXSDMMC_BLOCK_SIZE_DEFAULT;
 *     adma2TxDescr[i].address = (uint32)&txData[i][0];
 *
 *     // for the last descriptor line in table
 *     if (i == NUM_ADMA2_DESCRIPTORS - 1)
 *     {
 *         adma2TxDescr[i].end = 1; // set the END attribute
 *  adma2TxDescr[i].intEn = 1; // enable Interrupt after completion
 *     }
 * }
 *
 * // RX
 * IfxSdmmc_Adma2Descriptor adma2RxDescr[NUM_ADMA2_DESCRIPTORS];
 *
 * int i;
 * for (i=0; i<NUM_ADMA2_DESCRIPTORS; i++)
 * {
 *     adma2RxDescr[i].valid = 1;
 *     adma2RxDescr[i].act = IfxSdmmc_AdmaActionSymbol_tran;
 *     adma2RxDescr[i].length = IFXSDMMC_BLOCK_SIZE_DEFAULT;
 *     adma2RxDescr[i].address = (uint32)&rxData[i][0];
 *
 *     // for the last descriptor line in table
 *     if (i == NUM_ADMA2_DESCRIPTORS - 1)
 *     {
 *         adma2RxDescr[i].end = 1; // set the END attribute
 *  adma2RxDescr[i].intEn = 1; // enable Interrupt after completion
 *     }
 * }
 *
 * // specify the sector number of the card for data transfers
 * sectorNumber = 10;
 *
 * IfxSdmmc_Sd_writeBlock(&handle, sectorNumber, adma2Descr);
 * IfxSdmmc_Sd_readBlock(&handle, sectorNumber, adma2Descr);
 * \endcode
 *
 *
 * \defgroup IfxLld_Sdmmc_Sd SD
 * \ingroup IfxLld_Sdmmc
 * \defgroup IfxLld_Sdmmc_Sd_Data_Structures Data Structures
 * \ingroup IfxLld_Sdmmc_Sd
 * \defgroup IfxLld_Sdmmc_Sd_InitFunctions Initialisation Functions
 * \ingroup IfxLld_Sdmmc_Sd
 * \defgroup IfxLld_Sdmmc_Sd_CommandFunctions Command Functions
 * \ingroup IfxLld_Sdmmc_Sd
 * \defgroup IfxLld_Sdmmc_Sd_DataTransferFunctions Data Transfer Functions
 * \ingroup IfxLld_Sdmmc_Sd
 * \defgroup IfxLld_Sdmmc_Sd_SupportFunctions Support Functions
 * \ingroup IfxLld_Sdmmc_Sd
 */

#ifndef IFXSDMMC_SD_H
#define IFXSDMMC_SD_H 1

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include "Sdmmc/Std/IfxSdmmc.h"
#include "_PinMap/IfxSdmmc_PinMap.h"
#include "Cpu/Std/IfxCpu.h"
#include "Scu/Std/IfxScuCcu.h"

/******************************************************************************/
/*-----------------------------Data Structures--------------------------------*/
/******************************************************************************/

/** \addtogroup IfxLld_Sdmmc_Sd_Data_Structures
 * \{ */
/** \brief Configuration structure for SD Card
 */
typedef struct
{
    IfxSdmmc_SdDataTransferWidth dataWidth;       /**< \brief Data width for SD card transfers */
    IfxSdmmc_SdSpeedMode         speedMode;       /**< \brief Speed Mode for SD card transfers */
} IfxSdmmc_Sd_CardConfig;

/** \brief Configuration structure for ADMA
 */
typedef struct
{
    IfxSdmmc_DmaType dmaType;       /**< \brief Type of DMA used for data transfers */
} IfxSdmmc_Sd_DmaConfig;

/** \brief Individual Flags for SD card
 */
typedef struct
{
    boolean f8;                  /**< \brief F8 flag status. Range: TRUE - Set the f8 flag, FALSE - Reset the flag f8. */
    boolean f2;                  /**< \brief F2 flag status. Range: TRUE - Set the F2 flag, FALSE - Reset the flag F2. */
    boolean memInit;             /**< \brief Memory Init status. Range: TRUE - Set the memInit flag, FALSE - Reset the memInit flag. */
    boolean ioInit;              /**< \brief IO init status. Range: TRUE - Set the ioInit flag, FALSE - Reset the ioInit flag. */
    boolean supportIO;           /**< \brief Support for IO mode. Range: TRUE - Set the supportIO flag, FALSE - Reset the supportIO flag. */
    boolean supportMEM;          /**< \brief support for MEM mode. Range: TRUE - Set the supportMEM flag, FALSE - Reset the supportMEM flag. */
    boolean memoryPresent;       /**< \brief Memory present in card. Range: TRUE - Set the memoryPresent flag, FALSE - Reset the memoryPresent flag. */
} IfxSdmmc_Sd_Flags;

/** \brief Configuration structure for Host
 */
typedef struct
{
    IfxSdmmc_DataLineTimeout timeoutValue;          /**< \brief The interval by which DAT line timeouts are detected */
    boolean                  usePresetValues;       /**< \brief Selection of whether to use automatic selection of SDCLK frequency and Driver strength Preset Value registers.
    												 * - Range: TRUE Use SDCLK frequency and Driver strength Preset Value registers. FALSE No SDCLK frequency and Driver strength Preset Value registers are used */
    uint32                   frequency;             /**< \brief clock frequency select. Range: 0 to 0x2FAF080 (0 Hz to 50 MHz) */
    IfxSdmmc_SdModes         supportedModes;        /**< \brief supported modes of SD card */
} IfxSdmmc_Sd_HostConfig;

/** \brief Configuration structure for SD card pins
 */
typedef struct
{
    IfxSdmmc_Clk_Out    *clk;             /**< \brief Clock out */
    IfxSdmmc_Cmd_InOut  *cmd;             /**< \brief Command */
    IfxSdmmc_Dat0_InOut *dat0;            /**< \brief Dat 0 */
    IfxSdmmc_Dat1_InOut *dat1;            /**< \brief Dat 1 */
    IfxSdmmc_Dat2_InOut *dat2;            /**< \brief Dat 2 */
    IfxSdmmc_Dat3_InOut *dat3;            /**< \brief Dat 3 */
    IfxPort_InputMode    inputMode;       /**< \brief Input Mod efor the IN pins */
    IfxPort_PadDriver    pinDriver;       /**< \brief Speed grade of the pins */
} IfxSdmmc_Sd_Pins;

/** \} */

/** \addtogroup IfxLld_Sdmmc_Sd_Data_Structures
 * \{ */
/** \brief handle of SD interface
 */
typedef struct
{
    Ifx_SDMMC          *sdmmcSFR;            /**< \brief pointer to register base address of SDMMC */
    IfxSdmmc_CardInfo   cardInfo;            /**< \brief Card information */
    uint8               cardCapacity;        /**< \brief Card Capacity.
    										  * - Range: \ref IfxSdmmc_EmmcCardCapacity_byteAddressing (0) - less than 2GB: Byte Addressing. \ref IfxSdmmc_EmmcCardCapacity_sectorAddressing (1) - More than 2GB : Sector Addressing. */
    uint8               cardState;           /**< \brief State of the card. Range: \ref IfxSdmmc_CardState */
    boolean             dmaUsed;             /**< \brief Status of selection whether to use DMA for data transfers or not. Range: TRUE - Use Dma for data transfers, FALSE - Dma is not used for data transfers. */
    IfxSdmmc_DmaType    dmaType;             /**< \brief Type of DMA used for data transfers */
    IfxSdmmc_SdCardType cardType;            /**< \brief Type of Card */
    IfxSdmmc_Sd_Flags   flags;               /**< \brief Flags */
    boolean             presetMode;          /**< \brief Flag to identify for Preset Mode setting. Range: TRUE - Set the presetMode flag, FALSE - Reset the presetMode flag. */
    uint32              userFrequency;       /**< \brief Frequency of operation set by user. Range: 0 to 0x2FAF080 (0 Hz to 50 MHz) */
} IfxSdmmc_Sd;

/** \brief Configuration Structure of SDMMC driver
 */
typedef struct
{
    Ifx_SDMMC               *sdmmcSFR;              /**< \brief pointer to register base address of SDMMC */
    IfxSdmmc_Sd_HostConfig   hostConfig;            /**< \brief Configuration structure for Host */
    IfxSdmmc_InterruptConfig interruptConfig;       /**< \brief Configuration structure for Normal and Error interrupts */
    IfxSdmmc_Sd_Pins        *pins;                  /**< \brief Configuration structure for SD card pins */
    IfxSdmmc_Sd_CardConfig   cardConfig;            /**< \brief Configuration structure for SD card */
    boolean                  useDma;                /**< \brief selection of whether to use DMA for transfers or not Range: TRUE Use Dma for data transfers, FALSE Dma is not used for data transfers */
    IfxSdmmc_Sd_DmaConfig    dmaConfig;             /**< \brief Configuration structure for ADMA */
} IfxSdmmc_Sd_Config;

/** \} */

/** \addtogroup IfxLld_Sdmmc_Sd_InitFunctions
 * \{ */

/******************************************************************************/
/*-------------------------Global Function Prototypes-------------------------*/
/******************************************************************************/

/**
 * \brief Initializes the SD card using the provided handle and configuration structure.
 *
 * \param[inout] sd         Pointer to the SD interface handle.
 * \param[in]    cardConfig Configuration structure containing settings for the SD card, such as data width and speed mode.
 *
 * \retval IfxSdmmc_Status The status of SD card Initialisation, A return value of 0 indicates success,
 * 						   while any non-zero value indicates an error.
 * 						   Range: \ref IfxSdmmc_Status
 */
IFX_EXTERN IfxSdmmc_Status IfxSdmmc_Sd_initCard(IfxSdmmc_Sd *sd, IfxSdmmc_Sd_CardConfig *cardConfig);

/**
 * \brief Initialises IO mode of SD card
 *
 * \param[inout] sd         Pointer to the SD interface handle.
 * \param[in]    cardConfig Configuration structure for SD card. This includes settings like data width and speed mode for the card transfers.
 *
 * \retval IfxSdmmc_Status The status of SD IO initialisation, A return value of 0 indicates success, while any non-zero value indicates an error.
 * 						   Range: \ref IfxSdmmc_Status
 */
IFX_EXTERN IfxSdmmc_Status IfxSdmmc_Sd_ioInit(IfxSdmmc_Sd *sd, IfxSdmmc_Sd_CardConfig *cardConfig);

/**
 * \brief Configures the speed and bus width for the SD card interface.
 *
 * \param[inout] sd 		Pointer to the SD interface handle.
 * \param[in]    cardConfig Configuration structure for SD card. This includes settings like data width and speed mode for the card transfers.
 *
 * \retval IfxSdmmc_Status The status of Speed and Bus Width configuration, A return value of 0 indicates success,
 * 						   while any non-zero value indicates an error.
 * 						   Range: \ref IfxSdmmc_Status
 */
IFX_EXTERN IfxSdmmc_Status IfxSdmmc_Sd_configureSpeedAndBusWidth(IfxSdmmc_Sd *sd, IfxSdmmc_Sd_CardConfig *cardConfig);

/**
 * \brief Initializes the Host controller for the SD interface.
 *
 * \param[inout] sd         Pointer to the SD interface handle.
 * \param[in]    hostConfig Configuration structure for the Host controller. This includes settings such as timeout values,
 *                          clock frequency, usePresetValues and supported operation modes.
 *
 * \retval IfxSdmmc_Status The status of Host controller Initialisation, A return value of 0 indicates success,
 * 						   while any non-zero value indicates an error.
 * 						   Range: \ref IfxSdmmc_Status
 */
IFX_EXTERN IfxSdmmc_Status IfxSdmmc_Sd_initHostController(IfxSdmmc_Sd *sd, IfxSdmmc_Sd_HostConfig *hostConfig);

/**
 * \brief Initialises the SDMMC module, configuring both the host interface and the card.
 *
 * \param[inout] sd  	Pointer to the SD interface handle.
 * \param[inout] config Configuration structure for the SDMMC driver. This includes settings for the host, interrupts, pins,
 * 						card configuration, and DMA usage.
 *
 * \retval IfxSdmmc_Status The status of Module Initialisation, A return value of 0 indicates success,
 * 						   while any non-zero value indicates an error.
 * 						   Range: \ref IfxSdmmc_Status
 */
IFX_EXTERN IfxSdmmc_Status IfxSdmmc_Sd_initModule(IfxSdmmc_Sd *sd, IfxSdmmc_Sd_Config *config);

/**
 * \brief Configures interrupt settings for the SD interface.
 *
 * \param[inout] sd 			 Pointer to the SD interface handle.
 * \param[in]    interruptConfig Configuration structure for SD interrupts. This includes settings for enabling/disabling interrupts,
 * 								 priority levels and specific interrupt sources.
 *
 * \retval None
 */
IFX_EXTERN void IfxSdmmc_Sd_configureInterrupt(IfxSdmmc_Sd *sd, IfxSdmmc_InterruptConfig *interruptConfig);

/**
 * \brief Initialises the SDMMC driver configuration structure with default values.
 *
 * \param[inout] config   Configuration structure for the SDMMC driver. This includes settings for the host, interrupts, pins,
 * 						  card configuration and DMA usage.
 * \param[in]    sdmmcSFR Pointer to the register base address of the SDMMC module.
 *
 * \retval None
 */
IFX_EXTERN void IfxSdmmc_Sd_initModuleConfig(IfxSdmmc_Sd_Config *config, Ifx_SDMMC *sdmmcSFR);

/**
 * \brief Configures the SD card pins according to the specified pin configuration.
 *
 * \param[in] sd   Pointer to the SD interface handle.
 * \param[in] pins Configuration structure for SD card pins. This includes settings for clock, command, data lines,
 * 				   inputMode and pin driver configurations.
 *
 * \retval None
 */
IFX_EXTERN void IfxSdmmc_Sd_setupPins(IfxSdmmc_Sd *sd, IfxSdmmc_Sd_Pins *pins);

/**
 * \brief Validates the operating conditions of the SDIO card to ensure proper functionality.
 *
 * \param[in] sd Pointer to the SD interface handle.
 *
 * \retval IfxSdmmc_Status The status of Operating Conditions validation, indicating success or failure. A return value of 0 indicates success,
 * 						   while any non-zero value indicates an error.
 * 						   Range: \ref IfxSdmmc_Status
 */
IFX_EXTERN IfxSdmmc_Status IfxSdmmc_Sd_ioValidateOperatingCondition(IfxSdmmc_Sd *sd);

/**
 * \brief Configures the voltage window for the SD interface.
 *
 * \param[inout] sd Pointer to the SD interface handle.
 *
 * \retval IfxSdmmc_Status The status of Voltage Window configuration, indicating success or failure. A return value of 0 indicates success,
 *                         while any non-zero value indicates an error.
 *                         Range: \ref IfxSdmmc_Status
 */
IFX_EXTERN IfxSdmmc_Status IfxSdmmc_Sd_ioSetVoltageWindow(IfxSdmmc_Sd *sd);

/** \} */

/** \addtogroup IfxLld_Sdmmc_Sd_DataTransferFunctions
 * \{ */

/******************************************************************************/
/*-------------------------Global Function Prototypes-------------------------*/
/******************************************************************************/

/**
 * \brief Reads a block of data from the specified address on the SD card into the provided data buffer.
 *
 * \param[in] sd      Pointer to the SD interface handle.
 * \param[in] address The logical address on the SD card from which to read data.
 * 					  Range: 0 to 0xFFFFFFFF
 * \param[in] data    Pointer to the buffer where the read data will be stored.
 *
 * \retval IfxSdmmc_Status The status of read Block operation, indicating success or failure. A return value of 0 indicates success,
 *                         while any non-zero value indicates an error.
 *                         Range: \ref IfxSdmmc_Status
 */
IFX_EXTERN IfxSdmmc_Status IfxSdmmc_Sd_readBlock(IfxSdmmc_Sd *sd, uint32 address, uint32 *data);

/**
 * \brief Transfers one block of data using ADMA2 between the host and the SD card.
 *
 * \param[in] sd 	       Pointer to the SD interface handle.
 * \param[in] command      The command to send to the SD card.
 * 						   Range: \ref IfxSdmmc_Command
 * \param[in] address      The memory address where the data block is located.
 * 						   Range: 0 to 0xFFFFFFFF
 * \param[in] blockSize    The size of the data block to be transferred, specified as a 16-bit unsigned integer.
 * 						   Range: 0 to 0xFFF
 * \param[in] descrAddress Pointer to the descriptor containing the data to be read or written.
 * \param[in] direction    The direction of the data transfer (Write, Host to Card) (Read, Card to Host).
 * 						   Range: \ref IfxSdmmc_TransferDirection
 *
 * \retval IfxSdmmc_Status The status of single Block ADMA2 Transfer, indicating success or failure. A return value of 0 indicates success,
 *                         while any non-zero value indicates an error.
 *                         Range: \ref IfxSdmmc_Status
 */
IFX_EXTERN IfxSdmmc_Status IfxSdmmc_Sd_singleBlockAdma2Transfer(IfxSdmmc_Sd *sd, IfxSdmmc_Command command, uint32 address, uint16 blockSize, uint32 *descrAddress, IfxSdmmc_TransferDirection direction);

/**
 * \brief Transfers a single block of data between the host controller and the SD card using SDMA.
 *
 * \param[in] sd        Pointer to the SD interface handle.
 * \param[in] command   The command to send to the SD card.
 * 						Range: \ref IfxSdmmc_Command
 * \param[in] address   The address in the SD card where the data will be read from or written to.
 * 						Range: 0 to 0xFFFFFFFF
 * \param[in] blockSize The size of the block to be transferred.
 * 						Range: 0 to 0xFFF
 * \param[in] data      Pointer to the buffer containing the data to be read or written.
 * 						The direction of data flow is determined by the direction parameter.
 * \param[in] direction The direction of the data transfer (Write, Host to Card) (Read, Card to Host).
 * 						Range: \ref IfxSdmmc_TransferDirection
 *
 * \retval IfxSdmmc_Status The status of single Block DMA Transfer, indicating success or failure. A return value of 0 indicates success,
 *                         while any non-zero value indicates an error.
 *                         Range: \ref IfxSdmmc_Status
 */
IFX_EXTERN IfxSdmmc_Status IfxSdmmc_Sd_singleBlockDmaTransfer(IfxSdmmc_Sd *sd, IfxSdmmc_Command command, uint32 address, uint16 blockSize, uint32 *data, IfxSdmmc_TransferDirection direction);

/**
 * \brief Transfers one block of data between the host controller and the SD card.
 *
 * \param[in] 	 sd        Pointer to the SD interface handle.
 * \param[in]    command   The command to be sent to the SD card.
 * 						   Range: \ref IfxSdmmc_Command
 * \param[in]    address   The memory address where the data will be read from or written to.
 * 						   Range: 0 to 0xFFFFFFFF
 * \param[in]    blockSize The size of the data block to be transferred.
 * 						   Range: 0 to 0xFFF
 * \param[in]    data      Pointer to the data buffer containing the data to be read or written.
 * 						   The direction of data flow is determined by the direction parameter.
 * \param[in]    direction The direction of the data transfer (Write, Host to Card) (Read, Card to Host).
 * 				           Range: \ref IfxSdmmc_TransferDirection
 *
 * \retval IfxSdmmc_Status The status of single Block Transfer, indicating success or failure. A return value of 0 indicates success,
 *                         while any non-zero value indicates an error.
 *                         Range: \ref IfxSdmmc_Status
 */
IFX_EXTERN IfxSdmmc_Status IfxSdmmc_Sd_singleBlockTransfer(IfxSdmmc_Sd *sd, IfxSdmmc_Command command, uint32 address, uint16 blockSize, uint32 *data, IfxSdmmc_TransferDirection direction);

/**
 * \brief Writes data from the host controller to the specified address on the SD card.
 *
 * \param[in]    sd      Pointer to the SD interface handle.
 * \param[in]    address Destination address on the SD card where the data will be written.
 * 					     Range: 0 to 0xFFFFFFFF
 * \param[in]    data    Pointer to the data buffer to be written to the SD card.
 *
 * \retval IfxSdmmc_Status The status of write Block operation, indicating success or failure. A return value of 0 indicates success,
 *                         while any non-zero value indicates an error.
 *                         Range: \ref IfxSdmmc_Status
 */
IFX_EXTERN IfxSdmmc_Status IfxSdmmc_Sd_writeBlock(IfxSdmmc_Sd *sd, uint32 address, uint32 *data);

/**
 * \brief Reads a single register directly in SDIO mode using CMD52.
 *
 * \param[in]    sd   Pointer to the SD interface handle.
 * \param[in]    func The function number to access.
 * 				      Range: \ref IfxSdmmc_SdIoFunction
 * \param[in]    addr The address of the register to read from.
 * 				      Range: 0 to 0x1FFFF
 * \param[inout] reg  Pointer to the destination where the read value will be stored.
 *
 * \retval IfxSdmmc_Status The status of Sdio Read Register operation, indicating success or failure. A return value of 0 indicates success,
 *                         while any non-zero value indicates an error.
 *                         Range: \ref IfxSdmmc_Status
 */
IFX_EXTERN IfxSdmmc_Status IfxSdmmc_Sd_ioReadRegister(IfxSdmmc_Sd *sd, IfxSdmmc_SdIoFunction func, uint32 addr, uint8 *reg);

/**
 * \brief Writes a single register directly in SDIO mode using CMD52 command.
 *
 * \param[in] sd   Pointer to the SD interface handle.
 * \param[in] func The function number to which the register write operation is directed.
 * 				   Range: \ref IfxSdmmc_SdIoFunction
 * \param[in] addr The address of the register to write to.
 * 				   Range: 0 to 0x1FFFF
 * \param[in] reg  Data value to be written to the specified register.
 * 				   Range: 0 to 0xFF
 *
 * \retval IfxSdmmc_Status The status of Sdio Write Register operation, indicating success or failure. A return value of 0 indicates success,
 *                         while any non-zero value indicates an error.
 *                         Range: \ref IfxSdmmc_Status
 */
IFX_EXTERN IfxSdmmc_Status IfxSdmmc_Sd_ioWriteRegister(IfxSdmmc_Sd *sd, IfxSdmmc_SdIoFunction func, uint32 addr, uint8 reg);

/**
 * \brief Reads multiple blocks of data from the SD card into a buffer.
 *
 * \param[in]    sd 	       Pointer to the SD interface handle.
 * \param[in]    address       The starting address on the SD card from where data will be read.
 * 							   Range: 0 to 0xFFFFFFFF
 * \param[in]    data          Pointer to the buffer where the read data will be stored.
 * \param[in]    blockCount    The number of blocks to read from the SD card.
 * 							   Range: 0 to 0xFFFFFFFF
 * \param[in]    blockBoundary The size of each block boundary for DMA transfers.
 * 							   Range: \ref IfxSdmmc_BlockBoundarySize
 *
 * \retval IfxSdmmc_Status The status of read Multi Block operation, indicating success or failure. A return value of 0 indicates success,
 *                         while any non-zero value indicates an error.
 *                         Range: \ref IfxSdmmc_Status
 */
IFX_EXTERN IfxSdmmc_Status IfxSdmmc_Sd_readMultiBlock(IfxSdmmc_Sd *sd, uint32 address, uint32 *data, uint32 blockCount, IfxSdmmc_BlockBoundarySize blockBoundarySize);

/**
 * \brief Transfers multiple blocks of data between the Hostcontroller and the SD card using ADMA2.
 * 
 * \param[in] sd 		   Pointer to the SD interface handle.
 * \param[in] command      The command to be sent to the SD card.
 * 						   Range: \ref IfxSdmmc_Command
 * \param[in] address      The memory address where the data will be sent or read from.
 * 						   Range: 0 to 0xFFFFFFFF
 * \param[in] blockSize    The size of each block to be transferred, specified in bytes.
 * 						   Range: 0 to 0xFFF
 * \param[in] descrAddress Pointer to the descriptor containing the data to be read or written.
 * \param[in] direction    The direction of the data transfer (Write, Host to Card) (Read, Card to Host).
 * 						   Range: \ref IfxSdmmc_TransferDirection
 * \param[in] blockCount   The number of blocks to be transferred.
 * 						   Range: 0 to 0xFFFFFFFF
 * 
 * \retval IfxSdmmc_Status The status of multiple Blocks Adma2 Transfer, indicating success or failure. A return value of 0 indicates success,
 *                         while any non-zero value indicates an error.
 *                         Range: \ref IfxSdmmc_Status
 */
IFX_EXTERN IfxSdmmc_Status IfxSdmmc_Sd_multiBlockAdma2Transfer(IfxSdmmc_Sd *sd, IfxSdmmc_Command command, uint32 address, uint16 blockSize, uint32 *descrAddress, IfxSdmmc_TransferDirection direction, uint32 blockCount);

/**
 * \brief Transfers multiple blocks of data between the host controller and the SD card using SDMA.
 *
 * \param[in] sd         	    Pointer to the SD interface handle.
 * \param[in] command 		    The command to be sent to the SD card.
 * 								Range: \ref IfxSdmmc_Command
 * \param[in] address 		    The memory address where the data will be read from or written to.
 * 								Range: 0 to 0xFFFFFFFF
 * \param[in] blockSize 		The size of each block to be transferred, in bytes.
 * 								Range: Range: 0 to 0xFFF
 * \param[in] data       	    Pointer to the buffer containing the data to be read or written.
 * 								The direction of data flow is determined by the direction parameter.
 * \param[in] direction  	    The direction of the data transfer (Write, Host to Card) (Read, Card to Host).
 * 								Range: \ref IfxSdmmc_TransferDirection
 * \param[in] blockCount 	    The number of blocks to be transferred.
 * 								Range: 0 to 0xFFFFFFFF
 * \param[in] blockBoundarySize The boundary size for the DMA block transfer.
 * 								Range: \ref IfxSdmmc_BlockBoundarySize
 *
 * \retval IfxSdmmc_Status The status of MultiBlock Dma Transfer, indicating success or failure. A return value of 0 indicates success,
 *                         while any non-zero value indicates an error.
 *                         Range: \ref IfxSdmmc_Status
 */
IFX_EXTERN IfxSdmmc_Status IfxSdmmc_Sd_multiBlockDmaTransfer(IfxSdmmc_Sd *sd, IfxSdmmc_Command command, uint32 address, uint16 blockSize, uint32 *data, IfxSdmmc_TransferDirection direction, uint32 blockCount, IfxSdmmc_BlockBoundarySize blockBoundarySize);

/**
 * \brief Sends multiple blocks of data from the host controller to the SD card.
 *
 * \param[in] sd 				Pointer to the SD interface handle.
 * \param[in] address 			The starting address on the SD card where the data will be written.
 * 							    Range: 0 to 0xFFFFFFFF
 * \param[in] data 				Pointer to the buffer containing the data to be written.
 * \param[in] blockCount 		The number of data blocks to be written.
 * 								Range: 0 to 0xFFFFFFFF
 * \param[in] blockBoundarySize The size of each data block, determining the boundary for DMA transfers.
 * 								Range: \ref IfxSdmmc_BlockBoundarySize
 *
 * \retval IfxSdmmc_Status The status of write Multi Blocks operation, indicating success or failure. A return value of 0 indicates success,
 *                         while any non-zero value indicates an error.
 *                         Range: \ref IfxSdmmc_Status
 */
IFX_EXTERN IfxSdmmc_Status IfxSdmmc_Sd_writeMultiBlock(IfxSdmmc_Sd *sd, uint32 address, uint32 *data, uint32 blockCount, IfxSdmmc_BlockBoundarySize blockBoundarySize);

/** \} */

/** \addtogroup IfxLld_Sdmmc_Sd_SupportFunctions
 * \{ */

/******************************************************************************/
/*-------------------------Global Function Prototypes-------------------------*/
/******************************************************************************/

/**
 * \brief Retrieves the current lock status of the SD card.
 *
 * \param[in]    sd 		Pointer to the SD interface handle.
 * \param[inout] lockStatus Pointer to store the lock status of the card.
 * 						    Range: \ref IfxSdmmc_CardLockStatus
 *
 * \retval IfxSdmmc_Status The status of Lock operation, indicating success or failure. A return value of 0 indicates success,
 *                         while any non-zero value indicates an error.
 *                         Range: \ref IfxSdmmc_Status
 */
IFX_EXTERN IfxSdmmc_Status IfxSdmmc_Sd_getLockStatus(IfxSdmmc_Sd *sd, IfxSdmmc_CardLockStatus *lockStatus);

/**
 * \brief Reads the CID register from the SD card.
 *
 * \param[inout] sd Pointer to the SD interface handle.
 *
 * \retval IfxSdmmc_Status The status of read CID operation, indicating success or failure. A return value of 0 indicates success,
 *                         while any non-zero value indicates an error.
 *                         Range: \ref IfxSdmmc_Status
 */
IFX_EXTERN IfxSdmmc_Status IfxSdmmc_Sd_readCid(IfxSdmmc_Sd *sd);

/**
 * \brief Reads the RCA from the SD card.
 *
 * \param[inout] sd Pointer to the SD interface handle.
 *
 * \retval IfxSdmmc_Status The status of read RCA operation, indicating success or failure. A return value of 0 indicates success,
 *                         while any non-zero value indicates an error.
 *                         Range: \ref IfxSdmmc_Status
 */
IFX_EXTERN IfxSdmmc_Status IfxSdmmc_Sd_readRca(IfxSdmmc_Sd *sd);

/**
 * \brief Reads the SCR from the SD card to retrieve configuration information.
 *
 * \param[inout] sd Pointer to the SD interface handle.
 *
 * \retval IfxSdmmc_Status The status of read SCR operation, indicating success or failure. A return value of 0 indicates success,
 *                         while any non-zero value indicates an error.
 *                         Range: \ref IfxSdmmc_Status
 */
IFX_EXTERN IfxSdmmc_Status IfxSdmmc_Sd_readScr(IfxSdmmc_Sd *sd);

/**
 * \brief Switches the SD card interface to a 4-bit wide bus for data transfers.
 *
 * \param[in] sd Pointer to the SD interface handle.
 *
 * \retval IfxSdmmc_Status The status of switch Bus Width to 4-bit operation, indicating success or failure. A return value of 0 indicates success,
 *                         while any non-zero value indicates an error.
 *                         Range: \ref IfxSdmmc_Status
 */
IFX_EXTERN IfxSdmmc_Status IfxSdmmc_Sd_switchToBusWidth4(IfxSdmmc_Sd *sd);

/**
 * \brief Switches the SD interface to high-speed mode.
 *
 * \param[in] sd Pointer to the SD interface handle.
 *
 * \retval IfxSdmmc_Status The status of switch to high speed operation, indicating success or failure. A return value of 0 indicates success,
 *                         while any non-zero value indicates an error.
 *                         Range: \ref IfxSdmmc_Status
 */
IFX_EXTERN IfxSdmmc_Status IfxSdmmc_Sd_switchToHighSpeed(IfxSdmmc_Sd *sd);

/**
 * \brief Switches the SD card to the transfer state, enabling data transfer operations.
 *
 * \param[in] sd Pointer to the SD interface handle.
 *
 * \retval IfxSdmmc_Status The status of switch to Transfer State operation, indicating success or failure. A return value of 0 indicates success,
 *                         while any non-zero value indicates an error.
 *                         Range: \ref IfxSdmmc_Status
 */
IFX_EXTERN IfxSdmmc_Status IfxSdmmc_Sd_switchToTransferState(IfxSdmmc_Sd *sd);

/** \} */

/******************************************************************************/
/*-------------------------Global Function Prototypes-------------------------*/
/******************************************************************************/

/**
 * \brief Checks if the SD card supports multiple block transfers.
 *
 * \param[in] sd Pointer to the SD interface handle.
 *
 * \retval boolean TRUE  if multiple block transfers are supported by the SD card.
 * 		           FALSE if multiple block transfers are not supported by the SD card.
 */
IFX_EXTERN boolean IfxSdmmc_Sd_ioIsMultiBlockSupported(IfxSdmmc_Sd *sd);

/**
 * \brief Configures the block size for a specific I/O function associated with the SD device.
 *
 * \param[in] sd        Pointer to the SD interface handle.
 * \param[in] func      The I/O function for which the block size is to be configured.
 * 					    Range: \ref IfxSdmmc_SdIoFunction
 * \param[in] blockSize The block size in bytes to be set for the specified I/O function.
 * 					    Range: 0 to 0xFFFF
 *
 * \retval IfxSdmmc_Status The status of Set Function Block Size, indicating success or failure. A return value of 0 indicates success,
 *                         while any non-zero value indicates an error.
 *                         Range: \ref IfxSdmmc_Status
 */
IFX_EXTERN IfxSdmmc_Status IfxSdmmc_Sd_ioSetFuncBlockSize(IfxSdmmc_Sd *sd, IfxSdmmc_SdIoFunction func, uint16 blockSize);

/**
 * \brief Reads multiple blocks of registers from the SD card.
 *
 * \param[in]  sd         Pointer to the SD interface handle.
 * \param[in]  func 	  The function number to be used for the register read operation.
 * 						  Range: \ref IfxSdmmc_SdIoFunction
 * \param[in]  startAddr  The starting address of the register block to read from.
 * 						  Range: 0 to 0xFFFFFFFF
 * \param[out] regptr     Pointer to the destination buffer where the read data will be stored. The buffer must be large enough to accommodate the total data size (blocksize * blockCount).
 * \param[in]  blocksize  The size of each block in bytes.
 *						  Range: 0 to 0xFFF
 * \param[in]  blockCount The number of blocks to read.
 * 						  Range: 0 to 0xFFFFFFFF
 *
 * \retval IfxSdmmc_Status The status of read Multiple Blocks of Sdio Registers operation, indicating success or failure. A return value of 0 indicates success,
 *                         while any non-zero value indicates an error.
 *                         Range: \ref IfxSdmmc_Status
 */
IFX_EXTERN IfxSdmmc_Status IfxSdmmc_Sd_ioReadRegisterBlocks(IfxSdmmc_Sd *sd, IfxSdmmc_SdIoFunction func, uint32 startAddr, uint8 *regptr, uint16 blocksize, uint32 blockCount);

/**
 * \brief Writes multiple blocks of registers to the SD card.
 *
 * \param[in]  sd          Pointer to the SD interface handle.
 * \param[in]  func        The function number to be used for the register write operation.
 * 						   Range: \ref IfxSdmmc_SdIoFunction
 * \param[in]  startAddr   The starting address of the register where the write operation begins.
 * 						   Range: 0 to 0xFFFFFFFF
 * \param[in]  regptr      Pointer to the data that will be written to the SD card's registers.
 * \param[in]  blocksize   The size of each block in bytes. Maximum block size is 512 bytes.
 * 						   Range: 0 to 0xFFF
 * \param[in]  blockCount  The number of blocks to be written.
 *						   Range: 0 to 0xFFFFFFFF
 *
 * \retval IfxSdmmc_Status The status of write Multiple Blocks of Sdio Registers operation, indicating success or failure. A return value of 0 indicates success,
 *                         while any non-zero value indicates an error.
 *                         Range: \ref IfxSdmmc_Status
 */
IFX_EXTERN IfxSdmmc_Status IfxSdmmc_Sd_ioWriteRegisterBlocks(IfxSdmmc_Sd *sd, IfxSdmmc_SdIoFunction func, uint32 startAddr, uint8 *regptr, uint16 blocksize, uint32 blockCount);

/**
 * \brief Performs multiple block transfer operations using CMD53 for SD I/O.
 *
 * \param[in]    sd 	    Pointer to the SD device handle.
 * \param[in]    argument   Command argument for the SDMMC operation.
 * 						    Range: 0 to 0xFFFFFFFF
 * \param[in]    blockSize  Size of each block in bytes.
 * 							Range: 0 to 0xFFF
 * \param[in]    blockCount Number of blocks to transfer.
 * 							Range: 0 to 0xFFFF
 * \param[in]    data       Pointer to the data buffer.
 * 							The direction of data flow is determined by the direction parameter.
 * \param[in]    direction  The direction of the data transfer (Write, Host to Card) (Read, Card to Host).
 *							Range: \ref IfxSdmmc_TransferDirection
 *
 * \retval IfxSdmmc_Status The status of IO Multiple Blocks Transfer operation, indicating success or failure. A return value of 0 indicates success,
 *                         while any non-zero value indicates an error.
 *                         Range: \ref IfxSdmmc_Status
 */
IFX_EXTERN IfxSdmmc_Status IfxSdmmc_Sd_ioBlockTransfer(IfxSdmmc_Sd *sd, uint32 argument, uint16 blockSize, uint32 blockCount, uint32 *data, IfxSdmmc_TransferDirection direction);

/**
 * \brief Performs an ADMA2-based block transfer operation for SD I/O using CMD53.
 *
 * \param[in] sd           Pointer to the SD interface handle.
 * \param[in] argument     Command argument for the SD I/O operation. This is command-specific and typically includes address or parameter information for the operation.
 *                         Range: 0 to 0xFFFFFFFF
 * \param[in] blockSize    Size of each block in bytes.
 * 						   Range: 0 to 0xFFF
 * \param[in] blockCount   Number of blocks to transfer.
 * 						   Range: 0 to 0xFFFF
 * \param[in] descrAddress Pointer to the ADMA2 descriptor address. This parameter specifies the location of the ADMA2 descriptor table in system memory.
 * \param[in] direction    The direction of the data transfer (Write, Host to Card) (Read, Card to Host).
 *						   Range: \ref IfxSdmmc_TransferDirection
 *
 * \retval IfxSdmmc_Status The status of ADMA2 based Block Transfer operation, indicating success or failure. A return value of 0 indicates success,
 *                         while any non-zero value indicates an error.
 *                         Range: \ref IfxSdmmc_Status
 */
IFX_EXTERN IfxSdmmc_Status IfxSdmmc_Sd_ioBlockAdma2Transfer(IfxSdmmc_Sd *sd, uint32 argument, uint16 blockSize, uint32 blockCount, uint32 *descrAddress, IfxSdmmc_TransferDirection direction);

/**
 * \brief Performs a DMA-based block transfer operation for SD I/O using CMD53.
 *
 * \param[in]    sd         Pointer to the SD device handle.
 * \param[in]    argument   Command argument for the SD I/O operation. This is typically used to specify the address or parameters for the command.
 * 							Range: 0 to 0xFFFFFFFF
 * \param[in]    blockSize  Size of each block in bytes. The block size must be a value supported by the SD card (e.g., 512 bytes for standard SD cards).
 * 							Range: 0 to 0xFFF
 * \param[in] 	 blockCount Number of blocks to transfer. The maximum value is limited by the available memory and the SD card's capacity.
 * 							Range: 0 to 0xFFFF
 * \param[inout] data       Pointer to the data buffer.
 * 							The direction of data flow is determined by the direction parameter.
 * \param[in]    direction  The direction of the data transfer (Write, Host to Card) (Read, Card to Host).
 * 							Range: \ref IfxSdmmc_TransferDirection
 *
 * \retval IfxSdmmc_Status The status of DMA based Block Transfer operation, indicating success or failure. A return value of 0 indicates success,
 *                         while any non-zero value indicates an error.
 *                         Range: \ref IfxSdmmc_Status
 */
IFX_EXTERN IfxSdmmc_Status IfxSdmmc_Sd_ioBlockDmaTransfer(IfxSdmmc_Sd *sd, uint32 argument, uint16 blockSize, uint32 blockCount, uint32 *data, IfxSdmmc_TransferDirection direction);

/**
 * \brief Switches the SD card to the transfer state (CMD7) to prepare for data transfer operations.
 *
 * \param[in] sd Pointer to the SD interface handle.
 *
 * \retval IfxSdmmc_Status The status of Switching SD card to the Transfer State, indicating success or failure. A return value of 0 indicates success,
 *                         while any non-zero value indicates an error.
 *                         Range: \ref IfxSdmmc_Status
 */
IFX_EXTERN IfxSdmmc_Status IfxSdmmc_Sd_ioSwitchToTransferState(IfxSdmmc_Sd *sd);

/**
 * \brief Checks if a specific I/O function is enabled for the SD device.
 *
 * \param[in] sd   Pointer to the SD interface handle.
 * \param[in] func The I/O function to check.
 * 				   Range: \ref IfxSdmmc_SdIoFunction
 *
 * \retval IfxSdmmc_FunctionIO The status of I/O Function Enablement, indicating function disabled or enabled. A return value of 0 indicates function disabled,
 *                             while return value 1 indicates enabled and return value 2 indicates status unknown.
 *                         	   Range: \ref IfxSdmmc_FunctionIO
 */
IFX_EXTERN IfxSdmmc_FunctionIO IfxSdmmc_Sd_ioIsFunctionEnabled(IfxSdmmc_Sd *sd, IfxSdmmc_SdIoFunction func);

/**
 * \brief Enables a specific I/O function on the SD device.
 *
 * \param[in] sd   Pointer to the SD interface handle.
 * \param[in] func The I/O function to enable.
 * 				   Range: \ref IfxSdmmc_SdIoFunction
 *
 * \retval IfxSdmmc_Status The status of I/O Function Enablement, indicating success or failure. A return value of 0 indicates success,
 *                         while any non-zero value indicates an error.
 *                         Range: \ref IfxSdmmc_Status
 */
IFX_EXTERN IfxSdmmc_Status IfxSdmmc_Sd_ioEnableFunction(IfxSdmmc_Sd *sd, IfxSdmmc_SdIoFunction func);

/**
 * \brief Get the interrupt enable status for a specific SD I/O function.
 *
 * \param[in] sd   Pointer to the SD interface handle.
 * \param[in] func The SD I/O function for which to retrieve the interrupt enable status.
 * 				   Range: \ref IfxSdmmc_SdIoFunction
 *
 * \retval IfxSdmmc_SdIoInterruptStatus The status of SdIo Interrupt, A return value of 0 indicates interrupt disabled, while return value 1 indicates interrupt enabled and
 * 										interrupt status unknown return value 2 indicates.
 *                         				Range: \ref IfxSdmmc_SdIoInterruptStatus
 */
IFX_EXTERN IfxSdmmc_SdIoInterruptStatus IfxSdmmc_Sd_ioGetInterruptEnableStatus(IfxSdmmc_Sd *sd, IfxSdmmc_SdIoFunction func);

/**
 * \brief Enables the function interrupt for the specified SD I/O function.
 *
 * \param[in] sd   Pointer to the SD interface handle.
 * \param[in] func The function number to enable the interrupt for.
 * 				   Range: \ref IfxSdmmc_SdIoFunction
 *
 * \retval IfxSdmmc_Status The status of Function Interrupt Enablement, indicating success or failure. A return value of 0 indicates success,
 *                         while any non-zero value indicates an error.
 *                         Range: \ref IfxSdmmc_Status
 */
IFX_EXTERN IfxSdmmc_Status IfxSdmmc_Sd_ioEnableFuncInterrupt(IfxSdmmc_Sd *sd, IfxSdmmc_SdIoFunction func);

/**
 * \brief Disables the specified I/O function interrupt for the given SD device.
 *
 * \param[in] sd   Pointer to the SD interface handle.
 * \param[in] func The I/O function to disable the interrupt for.
 * 				   Range: \ref IfxSdmmc_SdIoFunction
 *
 * \retval IfxSdmmc_Status The status of Function Interrupt Disable, indicating success or failure. A return value of 0 indicates success,
 *                         while any non-zero value indicates an error.
 *                         Range: \ref IfxSdmmc_Status
 */
IFX_EXTERN IfxSdmmc_Status IfxSdmmc_Sd_ioDisableFuncInterrupt(IfxSdmmc_Sd *sd, IfxSdmmc_SdIoFunction func);

/**
 * \brief Enables or disables the master interrupt for the SD device.
 *
 * \param[in] sd        Pointer to the SD interface handle.
 * \param[in] irqEnable Interrupt status to be set.
 * 					    Range: \ref IfxSdmmc_SdIoInterruptStatus
 *
 *\retval IfxSdmmc_Status The status of Master Interrupt Enablement, indicating success or failure. A return value of 0 indicates success,
 *                        while any non-zero value indicates an error.
 *                        Range: \ref IfxSdmmc_Status
 */
IFX_EXTERN IfxSdmmc_Status IfxSdmmc_Sd_ioSetMasterInterruptEnable(IfxSdmmc_Sd *sd, IfxSdmmc_SdIoInterruptStatus irqEnable);

/**
 * \brief Retrieves the pending interrupt status for a specific SD I/O function.
 *
 * \param[in] sd   Pointer to the SD interface handle.
 * \param[in] func The I/O function number to check for pending interrupts.
 * 				   Range: \ref IfxSdmmc_SdIoFunction
 *
 * \retval IfxSdmmc_SdIoInterruptPendingStatus Interrupt pending status for the specified function. A return value of 0 indicates Interrupt cleared,
 *                        					   while return value of 0 indicates Interrupt is pending and return value of 2 indicates Interrupt Pending Status unknown.
 *                        					   Range: \ref IfxSdmmc_SdIoInterruptPendingStatus
 */
IFX_EXTERN IfxSdmmc_SdIoInterruptPendingStatus IfxSdmmc_Sd_ioGetInterruptPendingStatus(IfxSdmmc_Sd *sd, IfxSdmmc_SdIoFunction func);

/**
 * \brief Clears pending interrupts for a specific I/O function of the SD interface.
 *
 * \param[in] sd   Pointer to the SD interface handle.
 * \param[in] func The I/O function identifier. This parameter specifies which I/O function's pending interrupt is to be cleared.
 * 				   Range: \ref IfxSdmmc_SdIoFunction
 *
 * \retval IfxSdmmc_Status The status of Clearing Pending Interrupts, indicating success or failure. A return value of 0 indicates success,
 *                         while any non-zero value indicates an error.
 *                         Range: \ref IfxSdmmc_Status
 */
IFX_EXTERN IfxSdmmc_Status IfxSdmmc_Sd_ioClearPendingInterrupt(IfxSdmmc_Sd *sd, IfxSdmmc_SdIoFunction func);

/**
 * \brief Enables the multi-block interrupt for the specified SD device, allowing the system to handle multiple block transfers with interrupt-driven notifications.
 *
 * \param[in] sd Pointer to the SD interface handle.
 *
 * \retval IfxSdmmc_Status The status of Multi Block Interrupt Enablement, indicating success or failure. A return value of 0 indicates success,
 *                         while any non-zero value indicates an error.
 *                         Range: \ref IfxSdmmc_Status
 */
IFX_EXTERN IfxSdmmc_Status IfxSdmmc_Sd_ioEnableMultiBlockInterrupt(IfxSdmmc_Sd *sd);
#endif /* IFXSDMMC_SD_H */
