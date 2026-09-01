/**
 * \file IfxSdmmc_Emmc.h
 * \brief SDMMC EMMC details
 * \ingroup IfxLld_Sdmmc
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
 * \subsection  IfxLld_Sdmmc_Sd_DataTransfers_adma3 ADMA3 data transfers
 *
 * after selecting the DMA type as ADMA3 in the module initialisation phase,
 * data transfers an be done as follows
 * \code
 * // the data buffers are assumed to be defined globally
 * // NUM_ADMA3_DESCRIPTORS and BUFF_LENGTH are also assumed to be defined globally
 * //uint32 txdata[NUM_ADMA3_DESCRIPTORS][BUFF_LENGTH];
 * //uint32 rxdata[NUM_ADMA3_DESCRIPTORS][BUFF_LENGTH];
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
 * // specify the sector number of the card for data transfers
 * sectorNumber = 10;
 *
 * // prepare ADMA3 descriptor table
 *
 * IfxSdmmc_Adma3Descriptor adma3TxDescr[NUM_ADMA3_DESCRIPTORS];
 * IfxSdmmc_Adma3Descriptor adma3RxDescr[NUM_ADMA3_DESCRIPTORS];
 *
 * uint32 writeDataCmd, readDataCmd;
 * Ifx_SDMMC_CMD   cmd;
 * Ifx_SDMMC_XFER_MODE xferMode;
 *
 * // write data command for Adma3
 * cmd.B = IfxSdmmc_CMD[IfxSdmmc_Command_writeBlock];
 * xferMode.B.DMA_ENABLE = 1;
 * xferMode.B.DATA_XFER_DIR = IfxSdmmc_TransferDirection_write;
 *
 * writeDataCmd = (uint32) (cmd.U << 16 | xferMode.U);
 *
 * // read data command for Adma3
 * cmd.B = IfxSdmmc_CMD[IfxSdmmc_Command_readSingleBlock];
 * xferMode.B.DMA_ENABLE = 1;
 * xferMode.B.DATA_XFER_DIR = IfxSdmmc_TransferDirection_read;
 *
 * readDataCmd = (uint32) (cmd.U << 16 | xferMode.U);
 *
 * // TX
 * int i, j;
 * for (i=0; i<NUM_ADMA3_DESCRIPTORS; i++)
 * {
 *     // command descriptors
 *     for (j = 0; j < 4; j++)
 *     {
 *          adma3TxDescr[i].cmdDescr[j].valid = 1;
 *          adma3TxDescr[i].cmdDescr[j].act = IfxSdmmc_AdmaActionSymbol_cmd;
 *     }
 *     adma3TxDescr[i].cmdDescr[0].value = 1;  // block count
 *     adma3TxDescr[i].cmdDescr[1].value = IFXSDMMC_BLOCK_SIZE_DEFAULT;  // block size
 *     adma3TxDescr[i].cmdDescr[2].value = sectorNumber;  // argument
 *     adma3TxDescr[i].cmdDescr[3].value = writeDataCmd;  // command + transfer mode
 *     adma3TxDescr[i].cmdDescr[3].end = 1; // set the END attribute for last command descriptor line
 *
 *     // adma2 descriptor
 *     adma3TxDescr[i].adma2Descr.valid = 1;
 *     adma3TxDescr[i].adma2Descr.act = IfxSdmmc_AdmaActionSymbol_tran;
 *     adma3TxDescr[i].adma2Descr.length = IFXSDMMC_BLOCK_SIZE_DEFAULT;
 *     adma3TxDescr[i].adma2Descr.address = (uint32)&txData[i][0];
 *     adma3TxDescr[i].adma2Descr.end = 1; // set the END attribute
 * }
 *
 * // RX
 * for (i=0; i<NUM_ADMA3_DESCRIPTORS; i++)
 * {
 *     // command descriptors
 *     for (j = 0; j < 4; j++)
 *     {
 *          adma3RxDescr[i].cmdDescr[j].valid = 1;
 *          adma3RxDescr[i].cmdDescr[j].act = IfxSdmmc_AdmaActionSymbol_cmd;
 *     }
 *     adma3RxDescr[i].cmdDescr[0].value = 1;  // block count
 *     adma3RxDescr[i].cmdDescr[1].value = IFXSDMMC_BLOCK_SIZE_DEFAULT;  // block size
 *     adma3RxDescr[i].cmdDescr[2].value = sectorNumber;  // argument
 *     adma3RxDescr[i].cmdDescr[3].value = readDataCmd;  // command + transfer mode
 *     adma3RxDescr[i].cmdDescr[3].end = 1; // set the END attribute for last command descriptor line
 *
 *     // adma2 descriptor
 *     adma3RxDescr[i].adma2Descr.valid = 1;
 *     adma3RxDescr[i].adma2Descr.act = IfxSdmmc_AdmaActionSymbol_tran;
 *     adma3RxDescr[i].adma2Descr.length = IFXSDMMC_BLOCK_SIZE_DEFAULT;
 *     adma3RxDescr[i].adma2Descr.address = (uint32)&rxData[i][0];
 *     adma3RxDescr[i].adma2Descr.end = 1; // set the END attribute
 * }
 *
 * // prepare integrated descriptor table
 * IfxSdmmc_IntegratedDescriptor integratedTxDescr[NUM_ADMA3_DESCRIPTORS];
 * IfxSdmmc_IntegratedDescriptor integratedRxDescr[NUM_ADMA3_DESCRIPTORS];
 *
 * // TX
 * for (i=0; i<NUM_ADMA3_DESCRIPTORS; i++)
 * {
 *     integratedTxDescr[i].valid = 1;
 *     integratedTxDescr[i].act = IfxSdmmc_AdmaActionSymbol_integrated;
 *     integratedTxDescr[i].cmdDescrAddress = (uint32)&adma3TxDescr;
 *
 *     if(i == NUM_ADMA3_DESCRIPTORS -1)
 *     {
 *         integratedTxDescr[i].end = 1;   // set the END attribute for last integrated descriptor line
 *     }
 * }
 *
 *
 * // RX
 * for (i=0; i<NUM_ADMA3_DESCRIPTORS; i++)
 * {
 *     integratedRxDescr[i].valid = 1;
 *     integratedRxDescr[i].act = IfxSdmmc_AdmaActionSymbol_integrated;
 *     integratedRxDescr[i].cmdDescrAddress = (uint32)&adma3RxDescr;
 *
 *     if(i == NUM_ADMA3_DESCRIPTORS -1)
 *     {
 *         integratedRxDescr[i].end = 1;   // set the END attribute for last integrated descriptor line
 *     }
 * }
 *
 * IfxSdmmc_Emmc_singleBlockAdma3Transfer(&handle, (uint32)&integratedTxDescr[0]);
 * IfxSdmmc_Emmc_singleBlockAdma3Transfer(&handle, (uint32)&integratedRxDescr[0]);
 *
 * \endcode
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
     	 	 	 	 	 	 	 	 	 	 	 	 * - Range: TRUE Use SDCLK frequency and Driver strength Preset Value registers. FALSE No SDCLK frequency and Driver strength preset Value registers are used */
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
    boolean           flagF8;              /**< \brief f8 flag used during initialisation. Range: TRUE - Set the f8 flag, FALSE - Reset the flag f8. */
    IfxSdmmc_CardInfo cardInfo;            /**< \brief Card information */
    uint8             cardCapacity;        /**< \brief Card Capacity.
     	 	 	 	 	 	 	 	 	 	* - Range: \ref IfxSdmmc_EmmcCardCapacity_byteAddressing (0) - less than 2GB: Byte Addressing.
     	 	 	 	 	 	 	 	 	 	 	\ref IfxSdmmc_EmmcCardCapacity_sectorAddressing (1) - More than 2GB : Sector Addressing. */
    uint8             cardState;           /**< \brief State of the card. Range: \ref IfxSdmmc_CardState */
    boolean           dmaUsed;             /**< \brief Status of selection whether to use DMA for data transfers or not. Range: TRUE Use Dma for data transfers, FALSE No Dma is used for data transfers. */
    IfxSdmmc_DmaType  dmaType;             /**< \brief Type of DMA used for data transfers */
    uint32            userFrequency;       /**< \brief Frequency of usage set by the user. Range: 0 to 0x2FAF080 (0 Hz to 50 MHz). */
} IfxSdmmc_Emmc;

/** \brief Configuration Structure of SDMMC driver
 */
typedef struct
{
    Ifx_SDMMC               	*sdmmcSFR;              /**< \brief pointer to register base address of SDMMC */
    IfxSdmmc_Emmc_HostConfig 	hostConfig;             /**< \brief Configuration structure for Host */
    IfxSdmmc_InterruptConfig 	interruptConfig;        /**< \brief Configuration structure for Normal and Error interrupts */
    IfxSdmmc_dmaInterruptConfig dmaInterruptConfig; 	/**< \brief Configuration structure for Wakeup Card detection/removal interrupts */
    IfxSdmmc_Emmc_Pins      	*pins;                  /**< \brief Configuration structure for SD card pins */
    IfxSdmmc_Emmc_CardConfig 	cardConfig;             /**< \brief Configuration structure for SD card */
    boolean                  	useDma;                 /**< \brief selection of whether to use DMA for transfers or not. Range: TRUE Use Dma for data transfers, FALSE Dma is not used for data transfers. */
    IfxSdmmc_Emmc_DmaConfig  	dmaConfig;              /**< \brief Configuration structure for ADMA */
} IfxSdmmc_Emmc_Config;

/** \} */

/** \addtogroup IfxLld_Sdmmc_Emmc_InitFunctions
 * \{ */

/******************************************************************************/
/*-------------------------Global Function Prototypes-------------------------*/
/******************************************************************************/

/**
 * \brief Initializes the eMMC card for communication.
 *
 * \param[inout] emmc Handle for eMMC interface.
 * \param[in]    card Config Pointer to the configuration structure containing initialization parameters.
 *
 * \retval IfxSdmmc_Status Status. Range: \ref IfxSdmmc_Status
 */
IFX_EXTERN IfxSdmmc_Status IfxSdmmc_Emmc_initCard(IfxSdmmc_Emmc *emmc, IfxSdmmc_Emmc_CardConfig *cardConfig);

/**
 * \brief Initializes the SD/MMC host controller with the specified configuration.
 *
 * \param[inout] emmc 		Handle for eMMC interface.
 * \param[in] 	 hostConfig Pointer to the host configuration settings.
 *
 * \retval IfxSdmmc_Status Status. Range: \ref IfxSdmmc_Status
 */
IFX_EXTERN IfxSdmmc_Status IfxSdmmc_Emmc_initHostController(IfxSdmmc_Emmc *emmc, IfxSdmmc_Emmc_HostConfig *hostConfig);

/**
 * \brief Initializes the eMMC module according to the provided configuration.
 *
 * \param[inout] emmc   Handle for eMMC interface.
 * \param[in]    config Pointer to the configuration structure containing the settings for the eMMC module.
 *
 * \retval IfxSdmmc_Status Status. Range: \ref IfxSdmmc_Status
 */
IFX_EXTERN IfxSdmmc_Status IfxSdmmc_Emmc_initModule(IfxSdmmc_Emmc *emmc, IfxSdmmc_Emmc_Config *config);

/**
 * \brief Filld the configuration structure with default values.
 *
 * \param[inout] config   Configuration structure of Emmc driver.
 * \param[in] 	 sdmmcSFR Pointer to register base address of SDMMC.
 *
 * \retval None
 */
IFX_EXTERN void IfxSdmmc_Emmc_initModuleConfig(IfxSdmmc_Emmc_Config *config, Ifx_SDMMC *sdmmcSFR);

/**
 * \brief Configures the pin settings for the eMMC interface.
 *
 * \param[in] emmc Handle for eMMC interface.
 * \param[in] pins Pointer to the pin configuration structure containing the pin settings.
 *
 * \retval None
 */
IFX_EXTERN void IfxSdmmc_Emmc_setupPins(IfxSdmmc_Emmc *emmc, IfxSdmmc_Emmc_Pins *pins);

/**
 * \brief Switches the bus width of the eMMC interface.
 *
 * \param[in] emmc     Handle for eMMC interface.
 * \param[in] busWidth Desired bus width for data transfer.
 *
 * \retval IfxSdmmc_Status Status. Range: \ref IfxSdmmc_Status
 */
IFX_EXTERN IfxSdmmc_Status IfxSdmmc_Emmc_switchBusWidth(IfxSdmmc_Emmc *emmc, IfxSdmmc_EmmcDataTransferWidth busWidth);

/**
 * \brief Switches the eMMC interface to high-speed mode.
 *
 * \param[in] emmc Handle for eMMC interface.
 *
 * \retval IfxSdmmc_Status Status. Range: \ref IfxSdmmc_Status
 */
IFX_EXTERN IfxSdmmc_Status IfxSdmmc_Emmc_switchToHighSpeed(IfxSdmmc_Emmc *emmc);

/** \} */

/** \addtogroup IfxLld_Sdmmc_Emmc_DataTransferFunctions
 * \{ */

/******************************************************************************/
/*-------------------------Global Function Prototypes-------------------------*/
/******************************************************************************/

/**
 * \brief Reads a block of data from the eMMC memory.
 *
 * \param[in] 	 emmc 	 Handle for eMMC interface.
 * \param[in] 	 address The memory address in the eMMC to read from.
 *  					 Range: 0 to 0xFFFFFFFF
 * \param[inout] data 	 Pointer to the buffer where the read data will be stored.
 *
 * \retval IfxSdmmc_Status Status. Range: \ref IfxSdmmc_Status
 */
IFX_EXTERN IfxSdmmc_Status IfxSdmmc_Emmc_readBlock(IfxSdmmc_Emmc *emmc, uint32 address, uint32 *data);

/**
 * \brief Performs a single-block ADMA2 transfer for SDMMC operations.
 *
 * \param[in] emmc 		   Handle for eMMC interface.
 * \param[in] command      The SDMMC command to be executed.
 *  					   Range: \ref IfxSdmmc_Emmc_singleBlockAdma2Transfer
 * \param[in] address      The logical block address on the SDMMC card.
 *  					   Range: 0 to 0xFFFFFFFF
 * \param[in] blockSize    The size of each block in bytes.
 *  					   Range: 0 to 0xFFF
 * \param[in] descrAddress The starting address of the ADMA2 descriptor in system memory.
 * \param[in] direction    The direction of the data transfer (to or from the SDMMC card).
 *  					   Range: \ref IfxSdmmc_TransferDirection
 *
 * \retval IfxSdmmc_Status Status. Range: \ref IfxSdmmc_Status
 */
IFX_EXTERN IfxSdmmc_Status IfxSdmmc_Emmc_singleBlockAdma2Transfer(IfxSdmmc_Emmc *emmc, IfxSdmmc_Command command, uint32 address, uint16 blockSize, uint32 *descrAddress, IfxSdmmc_TransferDirection direction);

/**
 * \brief Performs a single-block ADMA3 transfer for eMMC operations.
 *
 * \param[in] emmc 				     Handle for eMMC interface.
 * \param[in] integratedDescrAddress Pointer to the integrated descriptor address used for the ADMA3 transfer.
 *
 * \retval IfxSdmmc_Status Status. Range: \ref IfxSdmmc_Status
 */
IFX_EXTERN IfxSdmmc_Status IfxSdmmc_Emmc_singleBlockAdma3Transfer(IfxSdmmc_Emmc *emmc, uint32 *integratedDescrAddress);

/**
 * \brief Performs a single-block DMA transfer for eMMC operations.
 *
 * \param[in] emmc      Handle for eMMC interface.
 * \param[in] command   The SDMMC command to be executed.
 *  					Range: \ref IfxSdmmc_Command
 * \param[in] address   The memory address for the data transfer.
 *  					Range: 0 to 0xFFFFFFFF
 * \param[in] blockSize The size of the data block to be transferred.
 *  					Range: 0 to 0xFFF
 * \param[in] data 	    Pointer to the data buffer for the transfer.
 * \param[in] direction The direction of the data transfer (read/write).
 *  					Range: \ref IfxSdmmc_TransferDirection
 *
 * \retval IfxSdmmc_Status Status. Range: \ref IfxSdmmc_Status
 */
IFX_EXTERN IfxSdmmc_Status IfxSdmmc_Emmc_singleBlockDmaTransfer(IfxSdmmc_Emmc *emmc, IfxSdmmc_Command command, uint32 address, uint16 blockSize, uint32 *data, IfxSdmmc_TransferDirection direction);

/**
 * \brief Transfers one block of data from Hostcontroller to Card or Vice versa
 *
 * \param[in]    emmc      Handle for eMMC interface.
 * \param[in]    command   Command to send
 *  				       Range: \ref IfxSdmmc_Command
 * \param[in]    address   Address where to send the data.
 *  					   Range: 0 to 0xFFFFFFFF
 * \param[in]    blockSize Size of the block.
 *  				       Range: 0 to 0xFFF
 * \param[inout] data      Pointer of the buffer containing data to write.
 * \param[in] 	 direction Transfer direction.
 *  					   Range: \ref IfxSdmmc_TransferDirection
 *
 * \retval IfxSdmmc_Status Status. Range: \ref IfxSdmmc_Status
 */
IFX_EXTERN IfxSdmmc_Status IfxSdmmc_Emmc_singleBlockTransfer(IfxSdmmc_Emmc *emmc, IfxSdmmc_Command command, uint32 address, uint16 blockSize, uint32 *data, IfxSdmmc_TransferDirection direction);

/**
 * \brief Switches the card state to transferring state.
 *
 * \param[in] emmc Handle for eMMC interface.
 *
 * \retval IfxSdmmc_Status Status. Range: \ref IfxSdmmc_Status
 */
IFX_EXTERN IfxSdmmc_Status IfxSdmmc_Emmc_switchToTransferState(IfxSdmmc_Emmc *emmc);

/**
 * \brief Writes a block of data to the specified address on the eMMC device.
 *
 * \param[in]    emmc    Handle for eMMC interface.
 * \param[inout] address Destination address on the eMMC device where the data will be written.
 * 						 Range: 0 to 0xFFFFFFFF
 * \param[in]    data    Pointer to the data to be written to the eMMC device.
 *
 * \retval IfxSdmmc_Status Status. Range: \ref IfxSdmmc_Status
 */
IFX_EXTERN IfxSdmmc_Status IfxSdmmc_Emmc_writeBlock(IfxSdmmc_Emmc *emmc, uint32 address, uint32 *data);

/**
 * \brief Reads multiple blocks of data from the specified address in the eMMC device.
 *
 * \param[in]    emmc      Handle for eMMC interface.
 * \param[inout] address   Starting address in the eMMC to read data from.
 * 						   Range: 0 to 0xFFFFFFFF
 * \param[in] 	 data      Pointer to the buffer where the read data will be stored.
 * \param[in]    numBlocks Number of blocks to be read.
 *
 * \retval IfxSdmmc_Status status of write. Range: \ref IfxSdmmc_Status
 */
IFX_EXTERN IfxSdmmc_Status IfxSdmmc_Emmc_readMultiBlock(IfxSdmmc_Emmc *emmc, uint32 address, uint32 *data, uint32 numBlocks);

/**
 * \brief Writes multiple blocks of data to the eMMC device starting from the specified address.
 *
 * \param[in] emmc 	    Handle for eMMC interface.
 * \param[in] address   The starting address in the eMMC where the data will be written.
 * 						Range: 0 to 0xFFFFFFFF
 * \param[in] data	    A pointer to the data buffer containing the data to be written.
 * \param[in] numBlocks The number of blocks to be written.
 *  					Range: 0 to 0xFFFFFFFF
 *
 * \retval IfxSdmmc_Status status of read. Range: \ref IfxSdmmc_Status
 */
IFX_EXTERN IfxSdmmc_Status IfxSdmmc_Emmc_writeMultiBlock(IfxSdmmc_Emmc *emmc, uint32 address, uint32 *data, uint32 numBlocks);

/**
 * \brief API to transfer multiblocks between system memory and card. (polling method)
 *
 * \param[in]   emmc       Pointer to emmc device handle.
 * \param[in]   command    Command to be sent to card.
 *  					   Range: \ref IfxSdmmc_Command
 * \param[in]   address    Address of card for data rx/tx.
 *  					   Range: 0 to 0xFFFFFFFF
 * \param[in]   blockSize  size of block to be transferred.
 *  					   Range: 0 to 0xFFF
 * \param[in]   numBlocks  Number of blocks to be transferred.
 *  					   Range: 0 to 0xFFFF
 * \param[inout] data      Pointer to data.
 * \param[in]    direction Direction (write/read).
 *  					   Range: \ref IfxSdmmc_TransferDirection
 *
 * \retval IfxSdmmc_Status Status of data transfer. Range: \ref IfxSdmmc_Status
 */
IFX_EXTERN IfxSdmmc_Status IfxSdmmc_Emmc_multiBlockTransfer(IfxSdmmc_Emmc *emmc, IfxSdmmc_Command command, uint32 address, uint16 blockSize, uint16 numBlocks, uint32 *data, IfxSdmmc_TransferDirection direction);

/**
 * \brief API to transfer multiblocks between system memory and card. (using ADMA2)
 *
 * \param[in] emmc 	    Pointer to emmc device handle.
 * \param[in] command   Command to be sent to card.
 * 						(Range: 0 to 43).
 * \param[in] address   Address of card for data rx/tx.
 * 						Range: 0 to 0xFFFFFFFF
 * \param[in] blockSize size of block to be transferred.
 * 						Range: 0 to 0xFFF
 * \param[in] numBlocks Number of blocks to be transferred.
 * 					    Range: 0 to 0xFFFF
 * \param[in] descr     Address Pointer to descriptor entry.
 * \param[in] direction Direction (write/read)
 * 						Range: \ref IfxSdmmc_TransferDirection
 *
 * \retval IfxSdmmc_Status Status of data transfer. Range: \ref IfxSdmmc_Status
 */
IFX_EXTERN IfxSdmmc_Status IfxSdmmc_Emmc_multiBlockAdma2Transfer(IfxSdmmc_Emmc *emmc, IfxSdmmc_Command command, uint32 address, uint16 blockSize, uint16 numBlocks, uint32 *descrAddress, IfxSdmmc_TransferDirection direction);

/** \} */

/** \addtogroup IfxLld_Sdmmc_Emmc_supportFunctions
 * \{ */

/******************************************************************************/
/*-------------------------Global Function Prototypes-------------------------*/
/******************************************************************************/

/**
 * \brief Reads the Card Identification (CID) data from the eMMC card.
 *
 * \param[inout] emmc Handle for eMMC interface.
 *
 * \retval IfxSdmmc_Status Status. Range: \ref IfxSdmmc_Status
 */
IFX_EXTERN IfxSdmmc_Status IfxSdmmc_Emmc_readCid(IfxSdmmc_Emmc *emmc);

/**
 * \brief Reads the Card Specific Data (CSD) from the eMMC device.
 *
 * \param[inout] emmc Handle for eMMC interface.
 *
 * \retval Range: \ref IfxSdmmc_Status Status. Range: \ref IfxSdmmc_Status
 */
IFX_EXTERN IfxSdmmc_Status IfxSdmmc_Emmc_readCsd(IfxSdmmc_Emmc *emmc);

/**
 * \brief Sets the Relative Card Address (RCA) for the eMMC device.
 *
 * \param[inout] emmc Handle for eMMC interface.
 * \param[in]    rca  The new Relative Card Address to be set.
 *
 * \retval IfxSdmmc_Status Status. Range: \ref IfxSdmmc_Status
 */
IFX_EXTERN IfxSdmmc_Status IfxSdmmc_Emmc_setRca(IfxSdmmc_Emmc *emmc, uint16 rca);

/**
 * \brief Validates the access mode of the eMMC device.
 *
 * \param[inout] emmc Handle for eMMC interface.
 *
 * \retval IfxSdmmc_Status Status. Range: \ref IfxSdmmc_Status
 */
IFX_EXTERN IfxSdmmc_Status IfxSdmmc_Emmc_validateAccessMode(IfxSdmmc_Emmc *emmc);

/** \} */

/******************************************************************************/
/*-------------------------Global Function Prototypes-------------------------*/
/******************************************************************************/

/**
 * \brief Erases blocks of data. Equivalent to a trim command.
 *
 * Erases the data from start address to end address specified.
 * The addresses specify the block numbers and assume sector addressing.
 * If byte Addressing scheme is used for Card, specify the address after conversion to sector (512B) units.
 * Erase is not immediate by protocol - it happens at a later time.
 *
 * \param[in] emmc 		   Handle for eMMC interface.
 * \param[in] startAddress Start Address of the block to be erased.
 * 						   Range: 0 to 0xFFFFFFFF
 * \param[in] endAddress   End Address of the block to be erased.
 * 					       Range: 0 to 0xFFFFFFFF
 *
 * \retval IfxSdmmc_Status Status of execution. Range: \ref IfxSdmmc_Status
 */
IFX_EXTERN IfxSdmmc_Status IfxSdmmc_Emmc_eraseBlocks(IfxSdmmc_Emmc *emmc, uint32 startAddress, uint32 endAddress);
#endif /* IFXSDMMC_EMMC_H */
