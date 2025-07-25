/**
 * \file IfxSdmmc_Sd.h
 * \brief SDMMC SD details
 * \ingroup IfxLld_Sdmmc
 *
 * \version iLLD-TC4-v2.1.1
 * \copyright Copyright (c) 2023 Infineon Technologies AG. All rights reserved.
 *
 *
 *
 *                                 IMPORTANT NOTICE
 *
 * Use of this file is subject to the terms of use agreed between (i) you or
 * the company in which ordinary course of business you are acting and (ii)
 * Infineon Technologies AG or its licensees. If and as long as no such terms
 * of use are agreed, use of this file is subject to following:
 *
 * Boost Software License - Version 1.0 - August 17th, 2003
 *
 * Permission is hereby granted, free of charge, to any person or organization
 * obtaining a copy of the software and accompanying documentation covered by
 * this license (the "Software") to use, reproduce, display, distribute,
 * execute, and transmit the Software, and to prepare derivative works of the
 * Software, and to permit third-parties to whom the Software is furnished to
 * do so, all subject to the following:
 *
 * The copyright notices in the Software and this entire statement, including
 * the above license grant, this restriction and the following disclaimer, must
 * be included in all copies of the Software, in whole or in part, and all
 * derivative works of the Software, unless such copies or derivative works are
 * solely in the form of machine-executable object code generated by a source
 * language processor.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT
 * SHALL THE COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE
 * FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN CONTRACT, TORT OR OTHERWISE,
 * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
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
    boolean f8;                  /**< \brief F8 flag status */
    boolean f2;                  /**< \brief F2 flag status */
    boolean memInit;             /**< \brief Memory Init status */
    boolean ioInit;              /**< \brief IO init status */
    boolean supportIO;           /**< \brief Support for IO mode */
    boolean supportMEM;          /**< \brief support for MEM mode */
    boolean memoryPresent;       /**< \brief Memory present in card */
} IfxSdmmc_Sd_Flags;

/** \brief Configuration structure for Host
 */
typedef struct
{
    IfxSdmmc_DataLineTimeout timeoutValue;          /**< \brief The interval by which DAT line timeouts are detected */
    boolean                  usePresetValues;       /**< \brief Selection of whether to use automatic selection of SDCLK frequency and Driver strength Preset Value registers. */
    uint32                   frequency;             /**< \brief clock frequency select */
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
    uint8               cardCapacity;        /**< \brief Card Capacity */
    uint8               cardState;           /**< \brief State of the card */
    boolean             dmaUsed;             /**< \brief Status of selection whether to use DMA for data transfers or not */
    IfxSdmmc_DmaType    dmaType;             /**< \brief Type of DMA used for data transfers */
    IfxSdmmc_SdCardType cardType;            /**< \brief Type of Card */
    IfxSdmmc_Sd_Flags   flags;               /**< \brief Flags */
    boolean             presetMode;          /**< \brief Flag to identify for Preset Mode setting */
    uint32              userFrequency;       /**< \brief Frequency of operation set by user */
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
    boolean                  useDma;                /**< \brief selection of whether to use DMA for transfers or not */
    IfxSdmmc_Sd_DmaConfig    dmaConfig;             /**< \brief Configuration structure for ADMA */
} IfxSdmmc_Sd_Config;

/** \} */

/** \addtogroup IfxLld_Sdmmc_Sd_InitFunctions
 * \{ */

/******************************************************************************/
/*-------------------------Global Function Prototypes-------------------------*/
/******************************************************************************/

/** \brief Initialises the SD card
 * \param sd Handle for SD interface
 * \param cardConfig Configuration dtructure for SD card
 * \return Status
 */
IFX_EXTERN IfxSdmmc_Status IfxSdmmc_Sd_initCard(IfxSdmmc_Sd *sd, IfxSdmmc_Sd_CardConfig *cardConfig);

/** \brief Initialises the Host controller
 * \param sd Handle for SD interface
 * \param hostConfig Configuration dtructure for Host Controller
 * \return Status
 */
IFX_EXTERN IfxSdmmc_Status IfxSdmmc_Sd_initHostController(IfxSdmmc_Sd *sd, IfxSdmmc_Sd_HostConfig *hostConfig);

/** \brief initialises the SDMMC module, both host interface and card
 * \param sd handle of SD interface
 * \param config Configuration structure of SDMMC driver
 * \return Status
 */
IFX_EXTERN IfxSdmmc_Status IfxSdmmc_Sd_initModule(IfxSdmmc_Sd *sd, IfxSdmmc_Sd_Config *config);

/** \brief Filld the configuration structure with default values
 * \param config configuration strcture of SDMMC driver
 * \param sdmmcSFR pointer to register base address of SDMMC
 * \return None
 */
IFX_EXTERN void IfxSdmmc_Sd_initModuleConfig(IfxSdmmc_Sd_Config *config, Ifx_SDMMC *sdmmcSFR);

/** \brief Sets up the SD card pins
 * \param sd Handle for SD interface
 * \param pins Configuration dtructure for SD card Pins
 * \return None
 */
IFX_EXTERN void IfxSdmmc_Sd_setupPins(IfxSdmmc_Sd *sd, IfxSdmmc_Sd_Pins *pins);

/** \brief Validate Op Condition of the SDIO card
 * \param sd Pointer to Sd device handle
 * \return status
 */
IFX_EXTERN IfxSdmmc_Status IfxSdmmc_Sd_ioValidateOperatingCondition(IfxSdmmc_Sd *sd);

/** \brief Set voltage window
 * \param sd Pointer to SD device handle
 * \return Status
 */
IFX_EXTERN IfxSdmmc_Status IfxSdmmc_Sd_ioSetVoltageWindow(IfxSdmmc_Sd *sd);

/** \} */

/** \addtogroup IfxLld_Sdmmc_Sd_DataTransferFunctions
 * \{ */

/******************************************************************************/
/*-------------------------Global Function Prototypes-------------------------*/
/******************************************************************************/

/** \brief Reads data from Card
 * \param sd Handle for SD interface
 * \param address Address where to read the data from
 * \param data Pointer of the buffer to read the data into
 * \return Status
 */
IFX_EXTERN IfxSdmmc_Status IfxSdmmc_Sd_readBlock(IfxSdmmc_Sd *sd, uint32 address, uint32 *data);

/** \brief Transfers one block of data from Hostcontroller to Card or Vice versa using ADMA2
 * \param sd Handle for SD interface
 * \param command Command to send
 * \param address Address where to send the data
 * \param blockSize Size of the block
 * \param descrAddress Pointer to the descriptor containing data to read/write
 * \param direction Transfer direction
 * \return Status
 */
IFX_EXTERN IfxSdmmc_Status IfxSdmmc_Sd_singleBlockAdma2Transfer(IfxSdmmc_Sd *sd, IfxSdmmc_Command command, uint32 address, uint16 blockSize, uint32 *descrAddress, IfxSdmmc_TransferDirection direction);

/** \brief Transfers one block of data from Hostcontroller to Card or Vice versa using SDMA
 * \param sd Handle for SD interface
 * \param command Command to send
 * \param address Address where to send the data
 * \param blockSize Size of the block
 * \param data Pointer of the buffer containing data to read/write
 * \param direction Transfer direction
 * \return Status
 */
IFX_EXTERN IfxSdmmc_Status IfxSdmmc_Sd_singleBlockDmaTransfer(IfxSdmmc_Sd *sd, IfxSdmmc_Command command, uint32 address, uint16 blockSize, uint32 *data, IfxSdmmc_TransferDirection direction);

/** \brief Transfers one block of data from Hostcontroller to Card or Vice versa
 * \param sd Handle for SD interface
 * \param command Command to send
 * \param address Address where to send the data
 * \param blockSize Size of the block
 * \param data Pointer of the buffer containing data to read/write
 * \param direction Transfer direction
 * \return Status
 */
IFX_EXTERN IfxSdmmc_Status IfxSdmmc_Sd_singleBlockTransfer(IfxSdmmc_Sd *sd, IfxSdmmc_Command command, uint32 address, uint16 blockSize, uint32 *data, IfxSdmmc_TransferDirection direction);

/** \brief Sends data from Hostcontroller to Card
 * \param sd Handle for SD interface
 * \param address Address where to send the data
 * \param data Pointer of the buffer containing data to write
 * \return Status
 */
IFX_EXTERN IfxSdmmc_Status IfxSdmmc_Sd_writeBlock(IfxSdmmc_Sd *sd, uint32 address, uint32 *data);

/** \brief Function to read a single register directly in SDIO mode (CMD52)
 * \param sd Pointer to SD device handle
 * \param func Function
 * \param addr Address of register
 * \param reg destination pointer
 * \return status
 */
IFX_EXTERN IfxSdmmc_Status IfxSdmmc_Sd_ioReadRegister(IfxSdmmc_Sd *sd, IfxSdmmc_SdIoFunction func, uint32 addr, uint8 *reg);

/** \brief Function to write a single register directly in SDIO mode (CMD52)
 * \param sd Pointer to SD device handle
 * \param func Function
 * \param addr Address of register
 * \param reg data to be written
 * \return status
 */
IFX_EXTERN IfxSdmmc_Status IfxSdmmc_Sd_ioWriteRegister(IfxSdmmc_Sd *sd, IfxSdmmc_SdIoFunction func, uint32 addr, uint8 reg);

/** \} */

/** \addtogroup IfxLld_Sdmmc_Sd_SupportFunctions
 * \{ */

/******************************************************************************/
/*-------------------------Global Function Prototypes-------------------------*/
/******************************************************************************/

/** \brief Reads RCA register of the card
 * \param sd Handle for SD interface
 * \param lockStatus Lock status
 * \return Status
 */
IFX_EXTERN IfxSdmmc_Status IfxSdmmc_Sd_getLockStatus(IfxSdmmc_Sd *sd, IfxSdmmc_CardLockStatus *lockStatus);

/** \brief Reads CID register of the card
 * \param sd Handle for SD interface
 * \return Status
 */
IFX_EXTERN IfxSdmmc_Status IfxSdmmc_Sd_readCid(IfxSdmmc_Sd *sd);

/** \brief Reads RCA register of the card
 * \param sd Handle for SD interface
 * \return Status
 */
IFX_EXTERN IfxSdmmc_Status IfxSdmmc_Sd_readRca(IfxSdmmc_Sd *sd);

/** \brief Reads SCR register of the card
 * \param sd Handle for SD interface
 * \return Status
 */
IFX_EXTERN IfxSdmmc_Status IfxSdmmc_Sd_readScr(IfxSdmmc_Sd *sd);

/** \brief Switches the transfer bus width to 4bit wide
 * \param sd Handle for SD interface
 * \return Status
 */
IFX_EXTERN IfxSdmmc_Status IfxSdmmc_Sd_switchToBusWidth4(IfxSdmmc_Sd *sd);

/** \brief Switches the Speed mode from normal to HIgh speed
 * \param sd Handle for SD interface
 * \return Status
 */
IFX_EXTERN IfxSdmmc_Status IfxSdmmc_Sd_switchToHighSpeed(IfxSdmmc_Sd *sd);

/** \brief Switches the card state to transferring state
 * \param sd Handle for SD interface
 * \return Status
 */
IFX_EXTERN IfxSdmmc_Status IfxSdmmc_Sd_switchToTransferState(IfxSdmmc_Sd *sd);

/** \} */

/******************************************************************************/
/*-------------------------Global Function Prototypes-------------------------*/
/******************************************************************************/

/** \brief Function to check if Multiple Block Transfer is supported
 * \param sd Pointer to SD device handle
 * \return status
 */
IFX_EXTERN boolean IfxSdmmc_Sd_ioIsMultiBlockSupported(IfxSdmmc_Sd *sd);

/** \brief Set Block Size of a function
 * \param sd Pointer to SD device handle
 * \param func function
 * \param blockSize block Size in bytes
 * \return status
 */
IFX_EXTERN IfxSdmmc_Status IfxSdmmc_Sd_ioSetFuncBlockSize(IfxSdmmc_Sd *sd, IfxSdmmc_SdIoFunction func, uint16 blockSize);

/** \brief Function to read register blocks (of upto 512 registers / block)
 * \param sd Pointer to SD device handle
 * \param func function
 * \param startAddr Start Address of the register
 * \param regptr pointer to destination
 * \param blocksize block size in bytes
 * \param blockCount Number of blocks
 * \return status
 */
IFX_EXTERN IfxSdmmc_Status IfxSdmmc_Sd_ioReadRegisterBlocks(IfxSdmmc_Sd *sd, IfxSdmmc_SdIoFunction func, uint32 startAddr, uint8 *regptr, uint16 blocksize, uint32 blockCount);

/** \brief Function to write register blocks (of upto 512 registers / block)
 * \param sd Pointer to SD device handle
 * \param func function
 * \param startAddr Start Address of the register
 * \param regptr pointer to destination
 * \param blocksize block size in bytes
 * \param blockCount Number of blocks
 * \return status
 */
IFX_EXTERN IfxSdmmc_Status IfxSdmmc_Sd_ioWriteRegisterBlocks(IfxSdmmc_Sd *sd, IfxSdmmc_SdIoFunction func, uint32 startAddr, uint8 *regptr, uint16 blocksize, uint32 blockCount);

/** \brief function to support Multiple block tansfer operation (with CMD53)
 * \param sd Pointer to SD device handle
 * \param argument argument of command
 * \param blockSize block Size in bytes
 * \param blockCount Number of blocks to for tx/rx
 * \param data Pointer to data
 * \param direction Transfer direction
 * \return status
 */
IFX_EXTERN IfxSdmmc_Status IfxSdmmc_Sd_ioBlockTransfer(IfxSdmmc_Sd *sd, uint32 argument, uint16 blockSize, uint32 blockCount, uint32 *data, IfxSdmmc_TransferDirection direction);

/** \brief ADMA2 based block tansfer operation (with CMD53)
 * \param sd Pointer to SD device handle
 * \param argument argument of command
 * \param blockSize block Size in bytes
 * \param blockCount Number of blocks to for tx/rx
 * \param descrAddress Pointer to data
 * \param direction Transfer direction
 * \return status
 */
IFX_EXTERN IfxSdmmc_Status IfxSdmmc_Sd_ioBlockAdma2Transfer(IfxSdmmc_Sd *sd, uint32 argument, uint16 blockSize, uint32 blockCount, uint32 *descrAddress, IfxSdmmc_TransferDirection direction);

/** \brief DMA based block tansfer operation (with CMD53)
 * \param sd Pointer to SD device handle
 * \param argument argument of command
 * \param blockSize block Size in bytes
 * \param blockCount Number of blocks to for tx/rx
 * \param data Pointer to data
 * \param direction Transfer direction
 * \return status
 */
IFX_EXTERN IfxSdmmc_Status IfxSdmmc_Sd_ioBlockDmaTransfer(IfxSdmmc_Sd *sd, uint32 argument, uint16 blockSize, uint32 blockCount, uint32 *data, IfxSdmmc_TransferDirection direction);

/** \brief function to switch to transfer state (CMD7)
 * \param sd Pointer to SD device handle
 * \return status
 */
IFX_EXTERN IfxSdmmc_Status IfxSdmmc_Sd_ioSwitchToTransferState(IfxSdmmc_Sd *sd);

/** \brief Get function Enabled / Disabled status
 * \param sd Pointer to SD device handle
 * \param func Function
 * \return IO enable status
 */
IFX_EXTERN IfxSdmmc_FunctionIO IfxSdmmc_Sd_ioIsFunctionEnabled(IfxSdmmc_Sd *sd, IfxSdmmc_SdIoFunction func);

/** \brief Enable Function
 * \param sd Pointer to SD device handle
 * \param func Function
 * \return Status
 */
IFX_EXTERN IfxSdmmc_Status IfxSdmmc_Sd_ioEnableFunction(IfxSdmmc_Sd *sd, IfxSdmmc_SdIoFunction func);

/** \brief Get Interrupt Enable Status
 * \param sd Pointer to SD device handle
 * \param func Function
 * \return Interrupt enable status
 */
IFX_EXTERN IfxSdmmc_SdIoInterruptStatus IfxSdmmc_Sd_ioGetInterruptEnableStatus(IfxSdmmc_Sd *sd, IfxSdmmc_SdIoFunction func);

/** \brief Enable function Interrupt
 * \param sd Pointer to SD device handle
 * \param func Function
 * \return Status
 */
IFX_EXTERN IfxSdmmc_Status IfxSdmmc_Sd_ioEnableFuncInterrupt(IfxSdmmc_Sd *sd, IfxSdmmc_SdIoFunction func);

/** \brief Disable Function Interrupt
 * \param sd Pointer to SD device handle
 * \param func Function
 * \return Status
 */
IFX_EXTERN IfxSdmmc_Status IfxSdmmc_Sd_ioDisableFuncInterrupt(IfxSdmmc_Sd *sd, IfxSdmmc_SdIoFunction func);

/** \brief Enable/Disable Master Interrupt
 * \param sd Pointer to SD device handle
 * \param irqEnable Interrupt status
 * \return Status
 */
IFX_EXTERN IfxSdmmc_Status IfxSdmmc_Sd_ioSetMasterInterruptEnable(IfxSdmmc_Sd *sd, IfxSdmmc_SdIoInterruptStatus irqEnable);

/** \brief get pending interrupt status
 * \param sd Pointer to SD device handle
 * \param func Function
 * \return Interrupt pending status
 */
IFX_EXTERN IfxSdmmc_SdIoInterruptPendingStatus IfxSdmmc_Sd_ioGetInterruptPendingStatus(IfxSdmmc_Sd *sd, IfxSdmmc_SdIoFunction func);

/** \brief Clear pending function Interrupt
 * \param sd Pointer to SD device handle
 * \param func Function
 * \return Status
 */
IFX_EXTERN IfxSdmmc_Status IfxSdmmc_Sd_ioClearPendingInterrupt(IfxSdmmc_Sd *sd, IfxSdmmc_SdIoFunction func);

/** \brief Enable Multi Block Interrupt
 * \param sd Pointer to SD device handle
 * \return Status
 */
IFX_EXTERN IfxSdmmc_Status IfxSdmmc_Sd_ioEnableMultiBlockInterrupt(IfxSdmmc_Sd *sd);

/** \brief Reads multi block of data from Card
 * \param sd Handle for SD interface
 * \param address Address where to read the data from
 * \param data Pointer of the buffer to read the data into
 * \param blockCount Number of data block to read
 * \param blockBoundarySize Boundary size for DMA block
 * \return Status
 */
IFX_EXTERN IfxSdmmc_Status IfxSdmmc_Sd_readMultiBlock(IfxSdmmc_Sd *sd, uint32 address, uint32 *data, uint32 blockCount, IfxSdmmc_BlockBoundarySize blockBoundarySize);

/** \brief Transfers multi block of data from Hostcontroller to Card or Vice versa using ADMA2
 * \param sd Handle for SD interface
 * \param command Command to send
 * \param address Address where to send the data
 * \param blockSize Size of the block
 * \param descrAddress Pointer to the descriptor containing data to read/write
 * \param direction Transfer direction
 * \param blockCount Number of block to transfer
 * \return Status
 */
IFX_EXTERN IfxSdmmc_Status IfxSdmmc_Sd_multiBlockAdma2Transfer(IfxSdmmc_Sd *sd, IfxSdmmc_Command command, uint32 address, uint16 blockSize, uint32 *descrAddress, IfxSdmmc_TransferDirection direction, uint32 blockCount);

/** \brief Transfers one block of data from Hostcontroller to Card or Vice versa using SDMA
 * \param sd Handle for SD interface
 * \param command Command to send
 * \param address Address where to send the data
 * \param blockSize Size of the block
 * \param data Pointer of the buffer containing data to read/write
 * \param direction Transfer direction
 * \param blockCount Number of block to transfer
 * \param blockBoundarySize Boundary size for DMA block
 * \return Status
 */
IFX_EXTERN IfxSdmmc_Status IfxSdmmc_Sd_multiBlockDmaTransfer(IfxSdmmc_Sd *sd, IfxSdmmc_Command command, uint32 address, uint16 blockSize, uint32 *data, IfxSdmmc_TransferDirection direction, uint32 blockCount, IfxSdmmc_BlockBoundarySize blockBoundarySize);

/** \brief Sends multi block of data from Hostcontroller to Card
 * \param sd Handle for SD interface
 * \param address Address where to send the data
 * \param data Pointer of the buffer containing data to write
 * \param blockCount Number of data block to write
 * \param blockBoundarySize Boundary size for DMA block
 * \return Status
 */
IFX_EXTERN IfxSdmmc_Status IfxSdmmc_Sd_writeMultiBlock(IfxSdmmc_Sd *sd, uint32 address, uint32 *data, uint32 blockCount, IfxSdmmc_BlockBoundarySize blockBoundarySize);
#endif /* IFXSDMMC_SD_H */
