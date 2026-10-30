/**
 * \file IfxSdmmc_Emmc.h
 * \brief SDMMC EMMC details
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
 * \defgroup IfxLld_Sdmmc_Emmc_Usage How to use the Sdmmc Driver Interface driver?
 * \ingroup IfxLld_Sdmmc_Emmc
 *
 * In the following sections it will be described, how to integrate the driver into the application framework.
 *
 * \section IfxLld_Sdmmc_Emmc_Preparation Preparation
 * \subsection IfxLld_Sdmmc_Emmc_Include Include Files
 *
 * Include following header file into your C code:
 * \code
 * #include <Sdmmc/Emmc/IfxSdmmc_Emmc.h>
 * \endcode
 *
 * \subsection IfxLld_Sdmmc_Emmc_Variables Variables
 *
 * Declare the Sdmmc handle and the Data buffers as global variables in your C code:
 *
 * \code
 * IfxSdmmc_Emmc handle;
 *
 * uint32 txData[8];
 * uint32 rxData[8];
 * uint32 sectorNumber;
 * \endcode
 *
 * \subsection IfxLld_Sdmmc_Emmc_Init Module Initialisation
 *
 * The module initialisation can be done as followed:
 * \code
 * // create config structure
 * IfxSdmmc_Emmc_Config config;
 * // fill the config structure with default values
 * IfxSdmmc_Emmc_initModuleConfig(&config, &MODULE_SDMMC0);
 *
 * {
 *     IfxSdmmc_Emmc_Pins pins;
 *     pins.clk = &IfxSdmmc0_CLK_P15_1_OUT;
 *     pins.cmd = &IfxSdmmc0_CMD_P15_3_INOUT;
 *     pins.dat0 = &IfxSdmmc0_DAT0_P20_7_INOUT;
 *     pins.dat1 = &IfxSdmmc0_DAT1_P20_8_INOUT;
 *     pins.dat2 = &IfxSdmmc0_DAT2_P20_10_INOUT;
 *     pins.dat3 = &IfxSdmmc0_DAT3_P20_11_INOUT;
 *     pins.dat4 = &IfxSdmmc0_DAT4_P20_12_INOUT;
 *     pins.dat5 = &IfxSdmmc0_DAT5_P20_13_INOUT;
 *     pins.dat6 = &IfxSdmmc0_DAT6_P20_14_INOUT;
 *     pins.dat7 = &IfxSdmmc0_DAT7_P15_0_INOUT;
 *     inputMode = IfxPort_InputMode_pullUp;
 *     pinDriver = IfxPort_PadDriver_cmosAutomotiveSpeed1;
 * }
 *
 * config.pins = &pins;
 *
 * // change bus width
 * config.cardConfig.dataWidth = IfxSdmmc_EmmcDataTransferWidth_1Bit;
 * // change speed mode
 * config.cardConfig.speedMode = IfxSdmmc_EmmcSpeedMode_legacy;
 *
 * config.useDma = FALSE;
 * // select DMA type if DMA is used
 * // config.dmaConfig.dmaType = IfxSdmmc_DmaType_sdma;
 *
 * // initialise the module
 * IfxSdmmc_Emmc_initModule(&handle, &config);
 * \endcode
 *
 * The SDMMC is ready for use now!
 *
 * \section IfxLld_Sdmmc_Emmc_DataTransfers Data Transfers
 * \subsection  IfxLld_Sdmmc_Emmc_DataTransfers_nonDma non DMA data transfers
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
 * IfxSdmmc_Emmc_writeBlock(&handle, sectorNumber, txData);
 * IfxSdmmc_Emmc_readBlock(&handle, sectorNumber, rxData);
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
 * IfxSdmmc_Emmc_writeBlock(&handle, sectorNumber, txData);
 * IfxSdmmc_Emmc_readBlock(&handle, sectorNumber, rxData);
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
 * IfxSdmmc_Emmc_writeBlock(&handle, sectorNumber, adma2Descr);
 * IfxSdmmc_Emmc_readBlock(&handle, sectorNumber, adma2Descr);
 * \endcode
 *
 *
 * \defgroup IfxLld_Sdmmc_Emmc EMMC
 * \ingroup IfxLld_Sdmmc
 * \defgroup IfxLld_Sdmmc_Emmc_Data_Structures Data Structures
 * \ingroup IfxLld_Sdmmc_Emmc
 * \defgroup IfxLld_Sdmmc_Emmc_InitFunctions Initialisation Functions
 * \ingroup IfxLld_Sdmmc_Emmc
 * \defgroup IfxLld_Sdmmc_Emmc_CommandFunctions Command Functions
 * \ingroup IfxLld_Sdmmc_Emmc
 * \defgroup IfxLld_Sdmmc_Emmc_DataTransferFunctions Data Transfer Functions
 * \ingroup IfxLld_Sdmmc_Emmc
 * \defgroup IfxLld_Sdmmc_Emmc_supportFunctions Support Functions
 * \ingroup IfxLld_Sdmmc_Emmc
 */

#ifndef IFXSDMMC_EMMC_H
#define IFXSDMMC_EMMC_H 1

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include "Sdmmc/Std/IfxSdmmc.h"
#include "_PinMap/IfxSdmmc_PinMap.h"
#include "Scu/Std/IfxScuCcu.h"

/******************************************************************************/
/*-----------------------------Data Structures--------------------------------*/
/******************************************************************************/

/** \addtogroup IfxLld_Sdmmc_Emmc_Data_Structures
 * \{ */
/** \brief Configuration structure for SD Card
 */
typedef struct
{
    IfxSdmmc_EmmcDataTransferWidth dataWidth;       /**< \brief Data width for SD card transfers */
    IfxSdmmc_EmmcSpeedMode         speedMode;       /**< \brief Speed Mode for SD card transfers */
} IfxSdmmc_Emmc_CardConfig;

/** \brief Configuration structure for ADMA
 */
typedef struct
{
    IfxSdmmc_DmaType dmaType;       /**< \brief Type of DMA used for data transfers */
} IfxSdmmc_Emmc_DmaConfig;

/** \brief Configuration structure for Host
 */
typedef struct
{
    IfxSdmmc_DataLineTimeout timeoutValue;          /**< \brief The interval by which DAT line timeouts are detected */
    boolean                  usePresetValues;       /**< \brief Selection of whether to use automatic selection of SDCLK frequency and Driver strength Preset Value registers.
    												 * - Range: TRUE Use SDCLK frequency and Driver strength Preset Value registers. FALSE No SDCLK frequency and Driver strength Preset Value registers are used */
    uint32                   frequency;             /**< \brief frequency select, clock divider will be calculated based on this. Range: 0 to 0x2FAF080 (0 Hz to 50 MHz ) */
} IfxSdmmc_Emmc_HostConfig;

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
    IfxSdmmc_Dat4_InOut *dat4;            /**< \brief Dat 4 */
    IfxSdmmc_Dat5_InOut *dat5;            /**< \brief Dat 5 */
    IfxSdmmc_Dat6_InOut *dat6;            /**< \brief Dat 6 */
    IfxSdmmc_Dat7_InOut *dat7;            /**< \brief Dat 7 */
    IfxPort_InputMode    inputMode;       /**< \brief Input Mod efor the IN pins */
    IfxPort_PadDriver    pinDriver;       /**< \brief Speed grade of the pins */
} IfxSdmmc_Emmc_Pins;

/** \} */

/** \addtogroup IfxLld_Sdmmc_Emmc_Data_Structures
 * \{ */
/** \brief handle of eMMC interface
 */
typedef struct
{
    Ifx_SDMMC        *sdmmcSFR;            /**< \brief pointer to register base address of SDMMC */
    boolean           flagF8;              /**< \brief f8 flag used during initialization. Range: TRUE - Set the f8 flag, FALSE - Reset the flag f8. */
    IfxSdmmc_CardInfo cardInfo;            /**< \brief Card information. */
    uint8             cardCapacity;        /**< \brief Card Capacity.
    										* - Range: \ref IfxSdmmc_EmmcCardCapacity_byteAddressing (0) - less than 2GB: Byte Addressing. \ref IfxSdmmc_EmmcCardCapacity_sectorAddressing (1) - More than 2GB : Sector Addressing. */
    uint8             cardState;           /**< \brief State of the card, Range: \ref IfxSdmmc_CardState */
    boolean           dmaUsed;             /**< \brief Status of selection whether to use DMA for data transfers or not. Range: TRUE Use Dma for data transfers, FALSE No Dma is used for data transfers.*/
    IfxSdmmc_DmaType  dmaType;             /**< \brief Type of DMA used for data transfers */
    uint32            userFrequency;       /**< \brief Frequency of usage set by the user. Range: 0 to 0x2FAF080 (0 Hz to 50 MHz) */
} IfxSdmmc_Emmc;

/** \brief Configuration Structure of SDMMC driver
 */
typedef struct
{
    Ifx_SDMMC                  *sdmmcSFR;                 /**< \brief pointer to register base address of SDMMC */
    IfxSdmmc_Emmc_HostConfig    hostConfig;               /**< \brief Configuration structure for Host */
    IfxSdmmc_InterruptConfig    interruptConfig;          /**< \brief Configuration structure for Normal and Error interrupts */
    IfxSdmmc_Emmc_Pins         *pins;                     /**< \brief Configuration structure for SD card pins */
    IfxSdmmc_Emmc_CardConfig    cardConfig;               /**< \brief Configuration structure for SD card */
    boolean                     useDma;                   /**< \brief selection of whether to use DMA for transfers or not. Range: TRUE Use Dma for data transfers, FALSE Dma is not used for data transfers. */
    IfxSdmmc_Emmc_DmaConfig     dmaConfig;                /**< \brief Configuration structure for ADMA */
} IfxSdmmc_Emmc_Config;

/** \} */

/** \addtogroup IfxLld_Sdmmc_Emmc_InitFunctions
 * \{ */

/******************************************************************************/
/*-------------------------Global Function Prototypes-------------------------*/
/******************************************************************************/

/**
 * \brief Initializes the eMMC card and prepares it for operation.
 *
 * \param[inout] emmc       Pointer to the eMMC interface handle.
 * \param[in]    cardConfig Configuration structure for the eMMC card. This includes settings such as data transfer width and speed mode.
 *
 * \retval IfxSdmmc_Status The status of eMMC card initialization. A return value of 0 indicates success, while any non-zero value indicates an error.
 * 						   Range: \ref IfxSdmmc_Status
 */
IFX_EXTERN IfxSdmmc_Status IfxSdmmc_Emmc_initCard(IfxSdmmc_Emmc *emmc, IfxSdmmc_Emmc_CardConfig *cardConfig);

/**
 * \brief Identifies the eMMC card and retrieves card-specific information.
 *
 * \param[inout] emmc       Pointer to the eMMC interface handle.
 * \param[in]    cardConfig Configuration structure for the eMMC card. This includes settings such as data transfer width and speed mode.
 *
 * \retval IfxSdmmc_Status The status of identification operation. A return value of 0 indicates success, while any non-zero value indicates an error.
 * 						   Range: \ref IfxSdmmc_Status
 */
IFX_EXTERN IfxSdmmc_Status IfxSdmmc_Emmc_identifyCard(IfxSdmmc_Emmc *emmc, IfxSdmmc_Emmc_CardConfig *cardConfig);

/**
 * \brief Configures the speed mode and data transfer width for the eMMC interface based on the provided card configuration.
 *
 * \param[inout] emmc 		Pointer to the eMMC interface handle.
 * \param[in]    cardConfig Configuration structure for the eMMC card. This includes settings such as data transfer width and speed mode.
 *
 * \retval IfxSdmmc_Status The status of speed and bus width configuration. A return value of 0 indicates success, while any non-zero value indicates an error.
 * 						   Range: \ref IfxSdmmc_Status
 */
IFX_EXTERN IfxSdmmc_Status IfxSdmmc_Emmc_configureSpeedAndBusWidth(IfxSdmmc_Emmc *emmc, IfxSdmmc_Emmc_CardConfig *cardConfig);

/**
 * \brief Initializes the Host controller for the eMMC interface.
 * 
 * \param[inout] emmc 		Pointer to the eMMC interface handle.
 * \param[in]    hostConfig Configuration structure for the Host controller. This includes settings such as timeout values, frequency selection,
 * 							and other controller-specific parameters.
 *
 * \retval IfxSdmmc_Status The status of Host controller initialization. A return value of 0 indicates success, while any non-zero value indicates an error.
 * 						   Range: \ref IfxSdmmc_Status
 */
IFX_EXTERN IfxSdmmc_Status IfxSdmmc_Emmc_initHostController(IfxSdmmc_Emmc *emmc, IfxSdmmc_Emmc_HostConfig *hostConfig);

/**
 * \brief Initializes the SDMMC module, both the Host interface and the eMMC card.
 *
 * \param[inout] emmc   Pointer to the eMMC interface handle.
 * \param[in]    config Configuration structure for the SDMMC driver. This includes settings for the host interface, interrupt configuration,
 * 						pin configuration, card configuration, and DMA usage.
 *
 * \retval IfxSdmmc_Status The status of module initialization. A return value of 0 indicates success, while any non-zero value indicates an error.
 * 						   Range: \ref IfxSdmmc_Status
 */
IFX_EXTERN IfxSdmmc_Status IfxSdmmc_Emmc_initModule(IfxSdmmc_Emmc *emmc, IfxSdmmc_Emmc_Config *config);

/**
 * \brief Configures the interrupt settings for the eMMC interface.
 *
 * \param[in] emmc 			  Pointer to the eMMC interface handle.
 * \param[in] interruptConfig Configuration structure for the SDMMC driver. This includes settings for the host interface, interrupt configuration,
 * 						      pin configuration, card configuration, and DMA usage.
 *
 * \retval None
 */
IFX_EXTERN void IfxSdmmc_Emmc_configureInterrupt(IfxSdmmc_Emmc *emmc, IfxSdmmc_InterruptConfig *interruptConfig);

/**
 * \brief Initializes the Emmc driver configuration structure with default values.
 *
 * \param[inout] config   Configuration structure for the SDMMC driver. This includes settings for the host interface, interrupt configuration,
 * 						  pin configuration, card configuration, and DMA usage.
 * \param[in]    sdmmcSFR Pointer to the register base address of SDMMC.
 *
 * \retval None
 */
IFX_EXTERN void IfxSdmmc_Emmc_initModuleConfig(IfxSdmmc_Emmc_Config *config, Ifx_SDMMC *sdmmcSFR);

/**
 * \brief Configures the eMMC card pins according to the provided pin configuration.
 *
 * \param[in] emmc Pointer to the eMMC interface handle.
 * \param[in] pins Configuration structure defining the pin settings, including clock, command, and data lines,
 * 				   as well as their input modes and driver strengths.
 *
 * \retval None
 */
IFX_EXTERN void IfxSdmmc_Emmc_setupPins(IfxSdmmc_Emmc *emmc, IfxSdmmc_Emmc_Pins *pins);

/**
 * \brief Switches the transfer bus width of the eMMC interface.
 *
 * \param[in] emmc 	   Pointer to the eMMC interface handle.
 * \param[in] busWidth The desired data transfer width for the eMMC interface.
 * 					   Range: \ref IfxSdmmc_EmmcDataTransferWidth
 *
 * \retval IfxSdmmc_Status The status of switching the transfer bus width operation. A return value of 0 indicates success,
 *  					   while any non-zero value indicates an error.
 * 						   Range: \ref IfxSdmmc_Status
 */
IFX_EXTERN IfxSdmmc_Status IfxSdmmc_Emmc_switchBusWidth(IfxSdmmc_Emmc *emmc, IfxSdmmc_EmmcDataTransferWidth busWidth);

/**
* \brief Switches the eMMC interface from Legacy mode to High-Speed SDR mode.
*
* \param[in] emmc Pointer to the eMMC interface handle.
*
* \retval IfxSdmmc_Status The status of switching to High-Speed mode operation. A return value of 0 indicates success,
 *  					  while any non-zero value indicates an error.
 * 						  Range: \ref IfxSdmmc_Status
*/
IFX_EXTERN IfxSdmmc_Status IfxSdmmc_Emmc_switchToHighSpeed(IfxSdmmc_Emmc *emmc);

/** \} */

/** \addtogroup IfxLld_Sdmmc_Emmc_DataTransferFunctions
 * \{ */

/******************************************************************************/
/*-------------------------Global Function Prototypes-------------------------*/
/******************************************************************************/

/**
 * \brief Reads a block of data from the specified address on the eMMC card into the provided buffer.
 *
 * \param[in]    emmc    Pointer to the eMMC interface handle.
 * \param[in]    address Memory address on the eMMC card from which to read data.
 * 					     Range: 0 to 0xFFFFFFFF
 * \param[inout] data    Pointer to the buffer where the read data will be stored.
 *
 * \retval IfxSdmmc_Status The status of read operation. A return value of 0 indicates success,
 *  					   while any non-zero value indicates an error.
 * 						   Range: \ref IfxSdmmc_Status
 */
IFX_EXTERN IfxSdmmc_Status IfxSdmmc_Emmc_readBlock(IfxSdmmc_Emmc *emmc, uint32 address, uint32 *data);

/**
 * \brief Transfers one block of data between the host controller and the eMMC card using ADMA2.
 *
 * \param[in] emmc 	       Pointer to the eMMC interface handle.
 * \param[in] command      The command to be sent to the eMMC card.
 * 						   Range: \ref IfxSdmmc_Emmc_singleBlockAdma2Transfer
 * \param[in] address      The memory address where the data will be sent or read from.
 * 						   Range: 0 to 0xFFFFFFFF
 * \param[in] blockSize    The size of the block to be transferred, specified as a 16-bit unsigned integer.
 * 						   Range: 0 to 0xFFF
 * \param[in] descrAddress Pointer to the buffer containing the data to be written to the card or where the data read from the card will be stored.
 * 						   The direction of data flow is determined by the direction parameter.
 * \param[in] direction    The direction of the data transfer (Write, Host to Card) (Read, Card to Host).
 * 						   Range: \ref IfxSdmmc_TransferDirection
 *
 * \retval IfxSdmmc_Status The status of single block Adma2 transfer. A return value of 0 indicates success,
 *  					   while any non-zero value indicates an error.
 * 						   Range: \ref IfxSdmmc_Status
 */
IFX_EXTERN IfxSdmmc_Status IfxSdmmc_Emmc_singleBlockAdma2Transfer(IfxSdmmc_Emmc *emmc, IfxSdmmc_Command command, uint32 address, uint16 blockSize, uint32 *descrAddress, IfxSdmmc_TransferDirection direction);

/**
 * \brief Transfers one block of data between the host controller and the eMMC card using DMA.
 *
 * \param[in] emmc    	Pointer to the eMMC interface handle.
 * \param[in] command 	The command to be sent to the eMMC card.
 * 					  	Rang: \ref IfxSdmmc_Command
 * \param[in] address 	The memory address where the data will be transferred to or from.
 * 						Range: 0 to 0xFFFFFFFF
 * \param[in] blockSize The size of the data block to be transferred, specified in bytes.
 * 						Range: 0 to 0xFFF
 * \param[in] data 		Pointer to the buffer containing the data to be written to the card or where the data read from the card will be stored.
 * 						The direction of data flow is determined by the direction parameter.
 * \param[in] direction The direction of the data transfer (Write, Host to Card) (Read, Card to Host).
 * 						Range: \ref IfxSdmmc_TransferDirection
 *
 * \retval IfxSdmmc_Status The status of single block dma transfer. A return value of 0 indicates success,
 *  					   while any non-zero value indicates an error.
 * 						   Range: \ref IfxSdmmc_Status
 */
IFX_EXTERN IfxSdmmc_Status IfxSdmmc_Emmc_singleBlockDmaTransfer(IfxSdmmc_Emmc *emmc, IfxSdmmc_Command command, uint32 address, uint16 blockSize, uint32 *data, IfxSdmmc_TransferDirection direction);

/**
 * \brief Transfers one block of data between the host controller and the eMMC card.
 *
 * \param[in]    emmc      Pointer to the eMMC interface handle.
 * \param[in]    command   The command to be sent to the eMMC card.
 * 					       Range: \ref IfxSdmmc_Command
 * \param[in]    address   The address on the eMMC card where the data will be read from or written to.
 * 					       Range: 0 to 0xFFFFFFFF
 * \param[in]    blockSize The size of the block to be transferred, in bytes. Range:
 *                         Range: 0 to 0xFFF
 * \param[inout] data      Pointer to the buffer containing the data to be written to the card or where the data read from the card will be stored.
 * 						   The direction of data flow is determined by the direction parameter.
 * \param[in]    direction The direction of the data transfer (Write, Host to Card) (Read, Card to Host).
 * 					       Range: \ref IfxSdmmc_TransferDirection
 *
 * \retval IfxSdmmc_Status The status of transfer operation. A return value of 0 indicates success, while any non-zero value indicates an error.
 * 						   Range: \ref IfxSdmmc_Status
 */
IFX_EXTERN IfxSdmmc_Status IfxSdmmc_Emmc_singleBlockTransfer(IfxSdmmc_Emmc *emmc, IfxSdmmc_Command command, uint32 address, uint16 blockSize, uint32 *data, IfxSdmmc_TransferDirection direction);

/**
 * \brief Switches the eMMC card to the transfer state, enabling data transfer operations.
 *
 * \param[in] emmc Pointer to the eMMC interface handle.
 *
 * \retval IfxSdmmc_Status The status of switch to transfer state operation. A return value of 0 indicates success, while any non-zero value indicates an error.
 * 						   Range: \ref IfxSdmmc_Status
 */
IFX_EXTERN IfxSdmmc_Status IfxSdmmc_Emmc_switchToTransferState(IfxSdmmc_Emmc *emmc);

/**
 * \brief Sends data from the Host controller to the specified address on the eMMC card.
 *
 * \param[in] 	 emmc 	 Pointer to the eMMC interface handle.
 * \param[inout] address The destination address on the eMMC card where the data will be written.
 * 						 Range: 0 to 0xFFFFFFFF
 * \param[in] 	 data 	 Pointer to the buffer containing the data to be written to the eMMC card.
 *
 * \retval IfxSdmmc_Status The status of write block operation, A return value of 0 indicates success, while any non-zero value indicates an error.
 * 						   Range: \ref IfxSdmmc_Status
 */
IFX_EXTERN IfxSdmmc_Status IfxSdmmc_Emmc_writeBlock(IfxSdmmc_Emmc *emmc, uint32 address, uint32 *data);

/**
 * \brief Reads multiple blocks of data from the eMMC card.
 *
 * \param[in]    emmc      Pointer to the eMMC interface handle.
 * \param[inout] address   Starting address on the eMMC card to read from.
 * 					       Range: 0 to 0xFFFFFFFF
 * \param[in]    data      Pointer to the buffer where the read data will be stored.
 * \param[in]    numBlocks Number of blocks to read from the eMMC card. Range: 1 to N (dependent on eMMC capacity and system limitations).
 * 						   Range: 0 to 0xFFFFFFFF
 *
 * \retval IfxSdmmc_Status The status of read multiblock operation, A return value of 0 indicates success, while any non-zero value indicates an error.
 * 						   Range: \ref IfxSdmmc_Status
 */
IFX_EXTERN IfxSdmmc_Status IfxSdmmc_Emmc_readMultiBlock(IfxSdmmc_Emmc *emmc, uint32 address, uint32 *data, uint32 numBlocks);

/**
 * \brief Writes multiple blocks of data to the EMMC card.
 *
 * \param[in] emmc 	    Pointer to the eMMC interface handle.
 * \param[in] address   Starting address on the EMMC card where the data will be written.
 * 						Range: 0 to 0xFFFFFFFF
 * \param[in] data      Pointer to the data buffer in memory that contains the data to be written to the EMMC card.
 * \param[in] numBlocks Number of blocks to be written.
 * 						Range: 0 to 0xFFFFFFFF
 *
 * \retval IfxSdmmc_Status The status of write multiblock operation, A return value of 0 indicates success, while any non-zero value indicates an error.
 * 						   Range: \ref IfxSdmmc_Status
 */
IFX_EXTERN IfxSdmmc_Status IfxSdmmc_Emmc_writeMultiBlock(IfxSdmmc_Emmc *emmc, uint32 address, uint32 *data, uint32 numBlocks);

/**
 * \brief API to transfer multiple blocks between system memory and the eMMC card using the polling method.
 *
 * \param[in]    emmc 	   Pointer to the eMMC interface handle.
 * \param[in]    command   Command to be sent to the card.
 * 				           Range: \ref IfxSdmmc_Command
 * \param[in]    address   The address on the card where the data will be read from or written to.
 * 					       Range: 0 to 0xFFFFFFFF
 * \param[in]    blockSize The size of each block to be transferred, in bytes.
 * 						   Range: 0 to 0xFFF
 * \param[in]    numBlocks The number of blocks to be transferred.
 * 						   Range: 0 to 0xFFFF
 * \param[inout] data      Pointer to the system memory buffer where data will be read into or written from, depending on the direction.
 * 						   The direction of data flow is determined by the direction parameter.
 * \param[in]    direction The direction of the data transfer (Write, Host to Card) (Read, Card to Host).
 * 						   Range: \ref IfxSdmmc_TransferDirection
 *
 * \retval IfxSdmmc_Status The status of multiblock transfer operation, A return value of 0 indicates success, while any non-zero value indicates an error.
 * 						   Range: \ref IfxSdmmc_Status
 */
IFX_EXTERN IfxSdmmc_Status IfxSdmmc_Emmc_multiBlockTransfer(IfxSdmmc_Emmc *emmc, IfxSdmmc_Command command, uint32 address, uint16 blockSize, uint16 numBlocks, uint32 *data, IfxSdmmc_TransferDirection direction);

/**
 * \brief Transfers multiple blocks between system memory and the eMMC card using ADMA2.
 *
 * \param[in] emmc 	       Pointer to the eMMC interface handle.
 * \param[in] command      The command to be sent to the card. It is of type IfxSdmmc_Command, which defines various command operations (Range: 0 to 43).
 * \param[in] address      The address on the card where the data will be read from or written to
 * 						   Range: 0 to 0xFFFFFFFF
 * \param[in] blockSize    The size of each block to be transferred.
 * 						   Range: 0 to 0xFFF
 * \param[in] numBlocks    The number of blocks to be transferred.
 * 						   Range: 0 to 0xFFFF
 * \param[in] descrAddress Pointer to the descriptor entry that contains the necessary information for the ADMA2 transfer.
 * \param[in] direction    The direction of the data transfer (Write, Host to Card) (Read, Card to Host).
 * 						   Range: \ref IfxSdmmc_TransferDirection
 *
 * \retval IfxSdmmc_Status The status of multiblock Adma2 transfer operation, A return value of 0 indicates success, while any non-zero value indicates an error.
 * 						   Range: \ref IfxSdmmc_Status
 */
IFX_EXTERN IfxSdmmc_Status IfxSdmmc_Emmc_multiBlockAdma2Transfer(IfxSdmmc_Emmc *emmc, IfxSdmmc_Command command, uint32 address, uint16 blockSize, uint16 numBlocks, uint32 *descrAddress, IfxSdmmc_TransferDirection direction);

/** \} */

/** \addtogroup IfxLld_Sdmmc_Emmc_supportFunctions
 * \{ */

/******************************************************************************/
/*-------------------------Global Function Prototypes-------------------------*/
/******************************************************************************/

/**
* \brief Reads the CID register from the eMMC card.
*
* \param[inout] emmc Pointer to the eMMC interface handle.
*
* \retval IfxSdmmc_Status The status of read the CID register from the eMMC card, A return value of 0 indicates success,
* 					      while any non-zero value indicates an error.
*  						  Range: \ref IfxSdmmc_Status
*/
IFX_EXTERN IfxSdmmc_Status IfxSdmmc_Emmc_readCid(IfxSdmmc_Emmc *emmc);

/**
 * \brief Reads the CSD register from the eMMC card.
 *
 * \param[inout] emmc Pointer to the eMMC interface handle.
 *
 * \retval IfxSdmmc_Status The status of read the CSD register from the eMMC card, A return value of 0 indicates success,
 * 					       while any non-zero value indicates an error.
 *  					   Range: \ref IfxSdmmc_Status
 */
IFX_EXTERN IfxSdmmc_Status IfxSdmmc_Emmc_readCsd(IfxSdmmc_Emmc *emmc);

/**
 * \brief Sets the RCA for the eMMC card.
 *
 * \param[inout] emmc Pointer to the eMMC interface handle.
 * \param[in]    rca  The Relative Card Address to be set.
 * 					  Range: 0 to 0xFFFF
 *
 * \retval IfxSdmmc_Status The status of set RCA for the eMMC card, A return value of 0 indicates success,
 * 					       while any non-zero value indicates an error.
 * 					       Range: \ref IfxSdmmc_Status
 */
IFX_EXTERN IfxSdmmc_Status IfxSdmmc_Emmc_setRca(IfxSdmmc_Emmc *emmc, uint16 rca);

/**
 * \brief Validates the access mode configuration for the eMMC interface.
 *
 * \param[inout] emmc Pointer to the eMMC interface handle.
 *
 * \retval IfxSdmmc_Status The status of Validate the Access Mode operation, A return value of 0 indicates success,
 * 					       while any non-zero value indicates an error.
 * 					       Range: \ref IfxSdmmc_Status
 */
IFX_EXTERN IfxSdmmc_Status IfxSdmmc_Emmc_validateAccessMode(IfxSdmmc_Emmc *emmc);

/** \} */

/******************************************************************************/
/*-------------------------Global Function Prototypes-------------------------*/
/******************************************************************************/

/**
 * \brief Erases specified blocks of data on the eMMC card.
 *
 * \param[in] emmc   	   Pointer to the eMMC interface handle.
 * \param[in] startAddress Starting sector address of the block to be erased.
 *                         Range: 0 to 0xFFFFFFFF
 * \param[in] endAddress   Ending sector address of the block to be erased.
 *                         Range: 0 to 0xFFFFFFFF
 *
 * \retval IfxSdmmc_Status The status of erase blocks operation, A return value of 0 indicates success,
 * 					       while any non-zero value indicates an error.
 * 					       Range: \ref IfxSdmmc_Status
 */
IFX_EXTERN IfxSdmmc_Status IfxSdmmc_Emmc_eraseBlocks(IfxSdmmc_Emmc *emmc, uint32 startAddress, uint32 endAddress);
#endif /* IFXSDMMC_EMMC_H */
