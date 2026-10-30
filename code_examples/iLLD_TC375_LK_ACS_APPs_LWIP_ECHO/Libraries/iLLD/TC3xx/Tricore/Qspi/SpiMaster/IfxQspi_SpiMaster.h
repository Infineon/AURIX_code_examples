/**
 * \file IfxQspi_SpiMaster.h
 * \brief QSPI SPIMASTER details
 * \ingroup IfxLld_Qspi
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
 * \defgroup IfxLld_Qspi_SpiMaster_Usage How to use the SPI Master Interface driver?
 * \ingroup IfxLld_Qspi
 *
 * The SPI Master interface driver provides a default QSPI configuration for a bidirectional serial communication of data words.
 *
 * Data transactions are buffered by the hardware based FIFOs. Incoming and outgoing data is transfered in background from/to the QSPI peripheral by interrupt service handlers, which are part of this driver as well. This allows a nonblocking communication without stalling the thread(s) from where data is sent and received.
 * Optionally Dma can be used for data transfers. Only the interrupt configuration and Module initialisation are different when dma is used.
 *
 * In the following sections it will be described, how to integrate the driver into the application framework.
 *
 * \section IfxLld_Qspi_SpiMaster_Preparation Preparation
 * \subsection IfxLld_Qspi_SpiMaster_Include Include Files
 *
 * Include following header file into your C code:
 * \code
 * #include <Qspi/SpiMaster/IfxQspi_SpiMaster.h>
 * \endcode
 *
 * \subsection IfxLld_Qspi_SpiMaster_Variables Variables
 *
 * Declare QSPI module and channel handles:
 *
 * \code
 * IfxQspi_SpiMaster spi;
 * IfxQspi_SpiMaster_Channel spiChannel;
 * \endcode
 *
 * In addition, declare global transmit and receive buffers for the data transfers:
 * \code
 * #define SPI_BUFFER_SIZE 8
 * uint8	spiTxBuffer[SPI_BUFFER_SIZE];
 * uint8	spiRxBuffer[SPI_BUFFER_SIZE];
 * \endcode
 *
 * \subsection IfxLld_Qspi_SpiMaster_Interrupt Interrupt Handler Installation (without dma use)
 *
 * See also \ref IfxLld_Cpu_Irq_Usage
 *
 * Define priorities for the Interrrupt handlers. This is normally done in the Ifx_IntPrioDef.h file:
 * \code
 * // priorities are normally defined in Ifx_IntPrioDef.h
 * #define IFX_INTPRIO_QSPI0_TX  1
 * #define IFX_INTPRIO_QSPI0_RX  2
 * #define IFX_INTPRIO_QSPI0_ER  5
 * \endcode
 *
 * Add the interrupt service routines to your C code. They have to call the QSPI interrupt handlers by passing the spi handle:
 * \code
 * IFX_INTERRUPT(qspi0TxISR, 0, IFX_INTPRIO_QSPI0_TX)
 * {
 *     IfxQspi_SpiMaster_isrTransmit(&spi);
 * }
 *
 * IFX_INTERRUPT(qspi0RxISR, 0, IFX_INTPRIO_QSPI0_RX)
 * {
 *     IfxQspi_SpiMaster_isrReceive(&spi);
 * }
 *
 * IFX_INTERRUPT(qspi0ErISR, 0, IFX_INTPRIO_QSPI0_ER)
 * {
 *     IfxQspi_SpiMaster_isrError(&spi);
 *
 *     // Process errors. Eg: parity Error is checked below
 *     IfxQspi_SpiMaster_Channel *chHandle   = IfxQspi_SpiMaster_activeChannel(&spi);
 *     if( chHandle->errorFlags.parityError == 1)
 *     {
 *         // Parity Error
 *     }
 * }
 * \endcode
 *
 * Finally install the interrupt handlers in your initialisation function:
 * \code
 *     // install interrupt handlers
 *     IfxCpu_Irq_installInterruptHandler(&qspi0TxISR, IFX_INTPRIO_QSPI0_TX);
 *     IfxCpu_Irq_installInterruptHandler(&qspi0RxISR, IFX_INTPRIO_QSPI0_RX);
 *     IfxCpu_Irq_installInterruptHandler(&qspi0ErISR, IFX_INTPRIO_QSPI0_ER);
 *     IfxCpu_enableInterrupts();
 * \endcode
 *
 * \subsection IfxLld_Qspi_SpiMaster_Interrupt_dma Interrupt Handler Installation (with dma use)
 *
 * See also \ref IfxLld_Cpu_Irq_Usage
 *
 * Define priorities for the Interrrupt handlers. This is normally done in the Ifx_IntPrioDef.h file:
 * \code
 * // qspi priorities
 * #define IFX_INTPRIO_QSPI0_TX  1 // DMA channel 1
 * #define IFX_INTPRIO_QSPI0_RX  2 // DMA channel 2
 * #define IFX_INTPRIO_QSPI0_ER  0x30
 *
 * // dma priorities
 * #define IFX_INTPRIO_DMA_CH1  10
 * #define IFX_INTPRIO_DMA_CH2  11
 * \endcode
 *
 * Add the interrupt service routines to your C code. They have to call the QSPI interrupt handlers by passing the spi handle:
 * \code
 * IFX_INTERRUPT(qspi0DmaTxISR, 0, IFX_INTPRIO_DMA_CH1 )
 * {
 *     IfxQspi_SpiMaster_isrDmaTransmit(&spi);
 * }
 *
 * IFX_INTERRUPT(qspi0DmaRxISR, 0, IFX_INTPRIO_DMA_CH2)
 * {
 *    IfxQspi_SpiMaster_isrDmaReceive(&spi);
 * }
 *
 * IFX_INTERRUPT(qspi0ErISR, 0, IFX_INTPRIO_QSPI0_ER)
 * {
 *     IfxQspi_SpiMaster_isrError(&spi);
 *
 *     // Process errors. Eg: parity Error is checked below
 *     IfxQspi_SpiMaster_Channel *chHandle   = IfxQspi_SpiMaster_activeChannel(&spi);
 *     if( chHandle->errorFlags.parityError == 1)
 *     {
 *         // Parity Error
 *     }
 * }
 * \endcode
 *
 * Finally install the interrupt handlers in your initialisation function:
 * \code
 *     // install interrupt handlers
 *     IfxCpu_Irq_installInterruptHandler(&qspi0DmaTxISR, IFX_INTPRIO_DMA_CH1);
 *     IfxCpu_Irq_installInterruptHandler(&qspi0DmaRxISR, IFX_INTPRIO_DMA_CH2);
 *     IfxCpu_Irq_installInterruptHandler(&qspi0ErISR,    IFX_INTPRIO_QSPI0_ER);
 *     IfxCpu_enableInterrupts();
 * \endcode
 *
 *
 * \subsection IfxLld_Qspi_SpiMaster_Init Module Initialisation (without dma use)
 *
 * The module initialisation can be done in the same function.
 *
 * Here an example for master mode:
 * \code
 *     // create module config
 *     IfxQspi_SpiMaster_Config spiMasterConfig;
 *     IfxQspi_SpiMaster_initModuleConfig(&spiMasterConfig, &MODULE_QSPI0);
 *
 *     // set the desired mode and maximum baudrate
 *     spiMasterConfig.mode             = IfxQspi_Mode_master;
 *     spiMasterConfig.maximumBaudrate  = 10000000;
 *
 *     // ISR priorities and interrupt target
 *     spiMasterConfig.txPriority       = IFX_INTPRIO_QSPI0_TX;
 *     spiMasterConfig.rxPriority       = IFX_INTPRIO_QSPI0_RX;
 *     spiMasterConfig.erPriority       = IFX_INTPRIO_QSPI0_ER;
 *     spiMasterConfig.isrProvider      = IfxCpu_Irq_getTos(IfxCpu_getCoreIndex());
 *
 *     // pin configuration
 *     const IfxQspi_SpiMaster_Pins pins = {
 *         &IfxQspi0_SCLK_P20_11_OUT, IfxPort_OutputMode_pushPull, // SCLK
 *         &IfxQspi0_MTSR_P20_14_OUT, IfxPort_OutputMode_pushPull, // MTSR
 *         &IfxQspi0_MRSTA_P20_12_IN, IfxPort_InputMode_pullDown,  // MRST
 *         IfxPort_PadDriver_cmosAutomotiveSpeed3 // pad driver mode
 *     };
 *     spiMasterConfig.pins = &pins;
 *
 *     // initialize module
 *     //IfxQspi_SpiMaster spi; // defined globally
 *     IfxQspi_SpiMaster_initModule(&spi, &spiMasterConfig);
 * \endcode
 *
 * \subsection IfxLld_Qspi_SpiMaster_Init_dma Module Initialisation (with dma use)
 *
 * The module initialisation can be done in the same function.
 *
 * Here an example for master mode:
 * \code
 *     // create module config
 *     IfxQspi_SpiMaster_Config spiMasterConfig;
 *     IfxQspi_SpiMaster_initModuleConfig(&spiMasterConfig, &MODULE_QSPI0);
 *
 *     // set the desired mode and maximum baudrate
 *     spiMasterConfig.mode             = IfQspi_Mode_master;
 *     spiMasterConfig.maximumBaudrate  = 10000000;
 *
 *     // ISR priorities and interrupt target (with Dma usage)
 *     spiMasterConfig.txPriority       = IFX_INTPRIO_DMA_CH1;
 *     spiMasterConfig.rxPriority       = IFX_INTPRIO_DMA_CH2;
 *     spiMasterConfig.erPriority       = IFX_INTPRIO_QSPI0_ER;
 *
 *     // dma configuration.
 *     spiMasterConfig.dma.txDmaChannelId = IfxDma_ChannelId_1;
 *     spiMasterConfig.dma.rxDmaChannelId = IfxDma_ChannelId_2;
 *     spiMasterConfig.dma.useDma = 1;
 *
 *     // pin configuration
 *     const IfxQspi_SpiMaster_Pins pins = {
 *         &IfxQspi0_SCLK_P20_11_OUT, IfxPort_OutputMode_pushPull, // SCLK
 *         &IfxQspi0_MTSR_P20_14_OUT, IfxPort_OutputMode_pushPull, // MTSR
 *         &IfxQspi0_MRSTA_P20_12_IN, IfxPort_InputMode_pullDown,  // MRST
 *         IfxPort_PadDriver_cmosAutomotiveSpeed3 // pad driver mode
 *     };
 *     spiMasterConfig.pins = &Pins;
 *
 *
 *     // initialize module
 *     //IfxQspi_SpiMaster spi; // defined globally
 *     IfxQspi_SpiMaster_initModule(&spi, &spiMasterConfig);
 * \endcode
 *
 *
 * \subsection IfxLld_Qspi_SpiMaster_ChannelInit SPI Channel Initialisation
 *
 * After the module has been initialized, one or more SPI channels can be configured.
 * Each channel has a dedicated select line.
 *
 * Here an example for a SPI channel in master mode:
 * \code
 *     // create channel config
 *     IfxQspi_SpiMaster_ChannelConfig spiMasterChannelConfig;
 *     IfxQspi_SpiMaster_initChannelConfig(&spiMasterChannelConfig, &spi);
 *
 *     // set the baudrate for this channel
 *     spiMasterChannelConfig.ch.baudrate = 5000000;
 *
 *     // select pin configuration
 *     const IfxQspi_SpiMaster_Output slsOutput = {
 *         &IfxQspi0_SLSO7_P33_5_OUT,
 *         IfxPort_OutputMode_pushPull,
 *         IfxPort_PadDriver_cmosAutomotiveSpeed1
 *     };
 *     spiMasterChannelConfig.sls.output = (IfxQspi_SpiMaster_Output)slsOutput;
 *
 *     // initialize channel
 *     //IfxQspi_SpiMaster_Channel spiChannel; // defined globally
 *     IfxQspi_SpiMaster_initChannel(&spiChannel, &spiMasterChannelConfig);
 * \endcode
 *
 * The QSPI is ready for use now!
 *
 *
 * \section IfxLld_Qspi_SpiMaster_DataTransfers Data Transfers
 *
 * In following examples we assume, that following buffers are declared globally:
 * \code
 * // declared somewhere globally
 * #define SPI_BUFFER_SIZE 8
 * uint8 spiTxBuffer[SPI_BUFFER_SIZE] = { 1, 2, 3, 4, 5, 6, 7, 8 };
 * uint8 spiRxBuffer[SPI_BUFFER_SIZE] = { 0, 0, 0, 0, 0, 0, 0, 0 };
 * \endcode
 *
 * Sending and Receiving a data stream:
 * \code
 *      int i=0;
 *     // wait until transfer of previous data stream is finished
 *     while( IfxQspi_SpiMaster_getStatus(&spiChannel) == IfxQspi_Status_busy );
 *
 *     // send/receive new stream
 *     IfxQspi_SpiMaster_exchange(&spiChannel, &spiTxBuffer[i], &spiRxBuffer[i], SPI_BUFFER_SIZE);
 * \endcode
 *
 * Send only, discard received data:
 * \code
 *
 *     // wait until transfer of previous data stream is finished
 *     while( IfxQspi_SpiMaster_getStatus(&spiChannel) == IfxQspi_Status_busy );
 *
 *     // send new stream
 *     IfxQspi_SpiMaster_exchange(&spiChannel, &spiTxBuffer[i], NULL_PTR, SPI_BUFFER_SIZE);
 * \endcode
 *
 * Receive only, send all-1
 * \code
 *     // wait until transfer of previous data stream is finished
 *     while( IfxQspi_SpiMaster_getStatus(&spiChannel) == IfxQspi_Status_busy );
 *
 *     // receive new stream
 *     IfxQspi_SpiMaster_exchange(&spiChannel, NULL_PTR, &spiRxBuffer[i], SPI_BUFFER_SIZE);
 * \endcode
 *
 * \section IfxLld_Qspi_SpiMaster_PhaseTransition Phase transition and User Interrupt usage
 *
 * Phase transition and user defined interrupts are not configured internal to Driver.
 *
 * Example usage of Phase transition interrupt is given below
 * \code
 *     IfxCpu_Irq_installInterruptHandler(&qspi0PtISR,    IFX_INTPRIO_QSPI0_PT);
 * IfxQspi_pause(&MODULE_QSPI0);
 * IfxQspi_configPT1Event(&MODULE_QSPI0, IfxQspi_PhaseTransitionEvent_startOfFrame); // Configured for PT1 SOF event
 * IfxQspi_enablePT1Event(&MODULE_QSPI0,TRUE);
 * IfxQspi_run(&MODULE_QSPI0);
 * \endcode
 *
 * Add the interrupt service routines to your C code. They have to call the QSPI interrupt handlers by passing the spi handle:
 * \code
 * IFX_INTERRUPT(qspi0PtISR, 0, IFX_INTPRIO_QSPI0_PT )
 * {
 *     IfxQspi_PhaseTransitionEvent event;
 *     event = IfxQspi_SpiMaster_isrPhaseTransition(&spiMaster);
 *     // process event
 *     switch (event)
 *     {
 *       case IfxQspi_PhaseTransitionEvent_startOfFrame:
 *       //  SOF event
 *       break;
 *      // add other events if needed.
 *     }
 * }
 * \endcode
 *
 * \section IfxLld_Qspi_SpiMaster_XXLMode How to use XXL Mode with Dma
 *
 * The Qspi XXL mode is similar to Short mode with the exception to configure mode to xxl before calling IfxQspi_SpiMaster_initChannel() function. The remaining usage is similar to Short / ShortContinuous Mode (default one) with Dma
 *
 * \code
 * spiMasterChannelConfig.mode = IfxQspi_SpiMaster_Mode_xxl;
 * \endcode
 *
 *
 * \section IfxLld_Qspi_SpiMaster_LongMode How to use Long / Long Continuous Mode with Dma
 *
 * The qspi Long mode is similar to short mode Except for below additional changes.
 * 1. Transmit buffer need to be defined (this is in addition to source/TX data buffer. This buffer is used to store the DATA + CONFIG for dma usage).
 * 2. Configure the Spi Channel configuration mode (new one) to long or longContinuous mode
 * 3. Preparing Transmit buffer content for long/long Continuous mode
 *
 * Example Code is provided below.
 *
 * \subsection IfxLld_Qspi_SpiMaster_Include Include Files
 *
 * Include following header file into your C code:
 * \code
 * #include <Qspi/SpiMaster/IfxQspi_SpiMaster.h>
 * \endcode
 *
 * \subsection IfxLld_Qspi_SpiMaster_Variables Variables
 *
 * Declare QSPI module and channel handles:
 *
 * \code
 * IfxQspi_SpiMaster spi;
 * IfxQspi_SpiMaster_Channel spiChannel;
 * \endcode
 *
 * In addition, declare global transmit and receive buffers for the data transfers:
 * \code
 * #define SPI_BUFFER_SIZE    50
 * #define BACON_SIZE IFXQSPI_BACONSIZE(SPI_BUFFER_SIZE)
 * #define FIFO_SIZE IFXQSPI_FIFO32BITSIZE(SPI_BUFFER_SIZE)
 * // This should be 32 bit ; use addition of macros as shown
 * __attribute__ ((aligned(64))) uint32       spi0TxLongBuffer[BACON_SIZE + FIFO_SIZE];
 *
 * uint8	spiTxBuffer[SPI_BUFFER_SIZE];
 * uint8	spiRxBuffer[SPI_BUFFER_SIZE];
 * \endcode
 *
 * \subsection IfxLld_Qspi_SpiMaster_Init_dma Module Initialisation (with dma use)
 *
 * The module initialisation can be done in the same function.
 *
 * Here an example for master mode:
 * \code
 *     // create module config
 *     IfxQspi_SpiMaster_Config spiMasterConfig;
 *     IfxQspi_SpiMaster_initModuleConfig(&spiMasterConfig, &MODULE_QSPI0);
 *
 *     // set the desired mode and maximum baudrate
 *     spiMasterConfig.mode             = IfxQspi_Mode_master;
 *     spiMasterConfig.maximumBaudrate  = 10000000;
 *
 *     // ISR priorities and interrupt target (with Dma usage)
 *     spiMasterConfig.txPriority       = IFX_INTPRIO_DMA_CH1;
 *     spiMasterConfig.rxPriority       = IFX_INTPRIO_DMA_CH2;
 *     spiMasterConfig.erPriority       = IFX_INTPRIO_QSPI0_ER;
 *
 *     // dma configuration.
 *     spiMasterConfig.dma.txDmaChannelId = IfxDma_ChannelId_1;
 *     spiMasterConfig.dma.rxDmaChannelId = IfxDma_ChannelId_2;
 *     spiMasterConfig.dma.useDma = 1;
 *
 *     // pin configuration
 *     const IfxQspi_SpiMaster_Pins pins = {
 *         &IfxQspi0_SCLK_P20_11_OUT, IfxPort_OutputMode_pushPull, // SCLK
 *         &IfxQspi0_MTSR_P20_14_OUT, IfxPort_OutputMode_pushPull, // MTSR
 *         &IfxQspi0_MRSTA_P20_12_IN, IfxPort_InputMode_pullDown,  // MRST
 *         IfxPort_PadDriver_cmosAutomotiveSpeed3 // pad driver mode
 *     };
 *     spiMasterConfig.pins = &Pins;
 *
 *
 *     // initialize module
 *     //IfxQspi_SpiMaster spi; // defined globally
 *     IfxQspi_SpiMaster_initModule(&spi, &spiMasterConfig);
 * \endcode
 *
 *
 * \subsection IfxLld_Qspi_SpiMaster_ChannelInit SPI Channel Initialisation
 *
 * After the module has been initialized, one or more SPI channels can be configured.
 * Each channel has a dedicated select line.
 *
 * Here an example for a SPI channel in master mode:
 * \code
 *     // create channel config
 *     IfxQspi_SpiMaster_ChannelConfig spiMasterChannelConfig;
 *     IfxQspi_SpiMaster_initChannelConfig(&spiMasterChannelConfig, &spi);
 *
 *     // set the baudrate for this channel
 *     spiMasterChannelConfig.ch.baudrate = 5000000;
 *
 *     // select pin configuration
 *     const IfxQspi_SpiMaster_Output slsOutput = {
 *         &IfxQspi0_SLSO7_P33_5_OUT,
 *         IfxPort_OutputMode_pushPull,
 *         IfxPort_PadDriver_cmosAutomotiveSpeed1
 *     };
 *     spiMasterChannelConfig.sls.output = (IfxQspi_SpiMaster_Output)slsOutput;
 *
 *     spiMasterChannelConfig.mode = IfxQspi_SpiMaster_Mode_longContinuous; // Select Long Continuous Mode
 *
 *     // initialize channel
 *     //IfxQspi_SpiMaster_Channel spiChannel; // defined globally
 *     IfxQspi_SpiMaster_initChannel(&spiChannel, &spiMasterChannelConfig);
 * \endcode
 *
 * Sending and Receiving a Long data stream:
 * \code
 *      int i=0;
 *     // Pack data and Configuration to Transmit buffer (Only for Long / Long Continuous Mode(s))
 *     IfxQspi_SpiMaster_packLongModeBuffer(&spiMasterChannel, spi0TxBuffer, spi0TxLongBuffer, SPI_BUFFER_SIZE);
 *
 *     // wait until transfer of previous data stream is finished
 *     while( IfxQspi_SpiMaster_getStatus(&spiChannel) == IfxQspi_Status_busy );
 *
 *     // send/receive new stream
 *     IfxQspi_SpiMaster_exchange(&spiChannel, &spiTxBuffer[i], &spiRxBuffer[i], SPI_BUFFER_SIZE);
 * \endcode
 *
 * ** NOTE for loopback mode **
 * In case you want to configure and test a SPI channel in loopback, you have to
 * select:
 * spiMasterChannelConfig.ch.mode.loopback = 1
 *
 * If an output pin is configured in loopback mode, the  SPI channel number will be extracted from the pin map configuration.
 *
 * If an output pin is not configured in loopback, the default SPI channel selected
 * will be 0.
 *
 * \defgroup IfxLld_Qspi_SpiMaster SPI Master Driver
 * \ingroup IfxLld_Qspi
 * \defgroup IfxLld_Qspi_SpiMaster_DataStructures Data Structures
 * \ingroup IfxLld_Qspi_SpiMaster
 * \defgroup IfxLld_Qspi_SpiMaster_Module Module Functions
 * \ingroup IfxLld_Qspi_SpiMaster
 * \defgroup IfxLld_Qspi_SpiMaster_Channel Channel Functions
 * \ingroup IfxLld_Qspi_SpiMaster
 * \defgroup IfxLld_Qspi_SpiMaster_Support Support Functions
 * \ingroup IfxLld_Qspi_SpiMaster
 * \defgroup IfxLld_Qspi_SpiMaster_Com Communication
 * \ingroup IfxLld_Qspi_SpiMaster
 * \defgroup IfxLld_Qspi_SpiMaster_InterruptFunctions Interrupt Functions
 * \ingroup IfxLld_Qspi_SpiMaster
 * \defgroup IfxLld_Qspi_SpiMaster_DirectFifo Direct FIFO Access
 * \ingroup IfxLld_Qspi_SpiMaster
 */

#ifndef IFXQSPI_SPIMASTER_H
#define IFXQSPI_SPIMASTER_H 1

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include "Cpu/Irq/IfxCpu_Irq.h"
#include "Dma/Dma/IfxDma_Dma.h"
#include "Qspi/Std/IfxQspi.h"
#include "Scu/Std/IfxScuWdt.h"

/******************************************************************************/
/*------------------------------Type Definitions------------------------------*/
/******************************************************************************/


/******************************************************************************/
/*--------------------------------Enumerations--------------------------------*/
/******************************************************************************/

/** \addtogroup IfxLld_Qspi_SpiMaster_DataStructures
 * \{ */
typedef enum
{
    IfxQspi_SpiMaster_ChannelBasedCs_disabled = 0,  /**< \brief Slso will be low for complete frame */
    IfxQspi_SpiMaster_ChannelBasedCs_enabled  = 1   /**< \brief Slso will toggle with every byte */
} IfxQspi_SpiMaster_ChannelBasedCs;

typedef enum
{
    IfxQspi_SpiMaster_Mode_short           = 0,  /**< \brief Short Mode */
    IfxQspi_SpiMaster_Mode_long            = 1,  /**< \brief Long Mode */
    IfxQspi_SpiMaster_Mode_shortContinuous = 2,  /**< \brief Short Continous Mode */
    IfxQspi_SpiMaster_Mode_longContinuous  = 3,  /**< \brief Long Continous Mode */
    IfxQspi_SpiMaster_Mode_xxl             = 4   /**< \brief XXL Mode */
} IfxQspi_SpiMaster_Mode;

/** \} */

/******************************************************************************/
/*-----------------------------Data Structures--------------------------------*/
/******************************************************************************/

/** \addtogroup IfxLld_Qspi_SpiMaster_DataStructures
 * \{ */
/** \brief SLSI  pin configuration structure
 */
typedef struct
{
    IFX_CONST IfxQspi_Slsi_In *pin;        /**< \brief Pointer to SLSI in pin */
    IfxPort_InputMode          mode;       /**< \brief The SLSI pin input mode */
} IfxQspi_SpiMaster_Input;

/** \brief Master Lvds pins configuration
 */
typedef struct
{
    IfxPort_LvdsConfig sclkOutLvdsCfg;       /**< \brief SCLK_out LVDS Configuration structure */
    IfxPort_LvdsConfig mtsrOutLvdsCfg;       /**< \brief MTSR_out LVDS Configuration structure */
    IfxPort_LvdsConfig mrstInLvdsCfg;        /**< \brief MRST_in LVDS Configuration structure */
} IfxQspi_SpiMaster_LvdsProperties;

/** \brief SLSO  pin configuration structure
 */
typedef struct
{
    IFX_CONST IfxQspi_Slso_Out *pin;          /**< \brief Pointer to SLSO out pin */
    IfxPort_OutputMode          mode;         /**< \brief The SLSO pin output mode */
    IfxPort_PadDriver           driver;       /**< \brief The pad driver mode which should be configured */
} IfxQspi_SpiMaster_Output;

/** \} */

/** \addtogroup IfxLld_Qspi_SpiMaster_DataStructures
 * \{ */
/** \brief Dma handle
 */
typedef struct
{
    IfxDma_Dma_Channel rxDmaChannel;         /**< \brief receive DMA channel handle */
    IfxDma_Dma_Channel txDmaChannel;         /**< \brief transmit DMA channel handle */
    IfxDma_ChannelId   rxDmaChannelId;       /**< \brief DMA channel no for the Spi recieve */
    IfxDma_ChannelId   txDmaChannelId;       /**< \brief DMA channel no for the Spi transmit */
    boolean            useDma;               /**< \brief use Dma for Data transfer/s. Range: TRUE enable Data transfer, FALSE disable Data transfer. */
} IfxQspi_SpiMaster_Dma;

/** \brief Dma configuration
 */
typedef struct
{
    IfxDma_ChannelId rxDmaChannelId;       /**< \brief DMA channel no for the Spi recieve */
    IfxDma_ChannelId txDmaChannelId;       /**< \brief DMA channel no for the Spi transmit */
    boolean          useDma;               /**< \brief use Dma for Data transfer/s. Range: TRUE enable Data transfer, FALSE disable Data transfer. */
} IfxQspi_SpiMaster_DmaConfig;

/** \brief Qspi Master Mode Error Flags
 */
typedef struct
{
    boolean parityError;              /**< \brief [0:0] Parity Error. Range: TRUE Parity Error occurred, FALSE Parity Error not occurred. */
    boolean configurationError;       /**< \brief [1:1] Configuration Error. Range: TRUE Configuration Error occurred, FALSE Configuration Error not occurred. */
    boolean baudrateError;            /**< \brief [2:2] baudrate Error. Range: TRUE baudrate Error occurred, FALSE baudrate Error not occurred. */
    boolean txFifoOverflowError;      /**< \brief [3:3] TxFifo Overflow Error. Range: TRUE TxFifo Overflow Error occurred, FALSE disable TxFifo Overflow Error not occurred. */
    boolean txFifoUnderflowError;     /**< \brief [4:4] TxFifo underflow Error. Range: TRUE TxFifo underflow Error occurred, FALSE disable TxFifo underflow Error not occurred. */
    boolean rxFifoOverflowError;      /**< \brief [5:5] RxFifo Overflow Error. Range: TRUE RxFifo Overflow Error occurred, FALSE disable RxFifo Overflow Error not occurred. */
    boolean rxFifoUnderflowError;     /**< \brief [6:6] RxFifo underflow Error. Range: TRUE RxFifo underflow Error occurred, FALSE RxFifo underflow Error not occurred. */
    boolean expectTimeoutError;       /**< \brief [7:7] Expect Timeout Error. Range: TRUE Expect Timeout Error occurred, FALSE Expect Timeout Error not occurred. */
} IfxQspi_SpiMaster_ErrorFlags;

/** \brief Union of Slave Select pins
 */
typedef union
{
    IfxQspi_SpiMaster_Input  input;        /**< \brief SLSI  pin configuration structure */
    IfxQspi_SpiMaster_Output output;       /**< \brief SLSO  pin configuration structure */
} IfxQspi_SpiMaster_InputOutput;

typedef struct
{
    uint8   trailingDelay2Prescaler;            /**< \brief Inject the trailing delay for last data. Range: 0 to 0xFF. */
    uint8   lastTrailingDelay;                  /**< \brief Last Trailing delay. Range: 0 to 0xFF. */
    boolean interruptBeforeLastEnabled;         /**< \brief Enable bit for Interrupt before last word. Range: TRUE enable the interrupt before the last byte, FALSE disable the interrupt before the last byte. */
    boolean clearInterruptBeforeLastFlag;       /**< \brief Clear Interrupt Before Last Flag. Range: TRUE if clears the interrupt flag, FALSE if does not clear the interrupt flag.*/
    boolean setInterruptBeforeLastFlag;         /**< \brief Sets the Interrupt Before Last Flag. Range: TRUE if enable interrupt before last data element, FALSE if disable interrupt before last data element. */
    boolean interruptAfterLastEnabled;          /**< \brief Enable bit for Interrupt after last word. Range: TRUE enable the interrupt after the last byte, FALSE disables the interrupt after the last byte. */
    boolean clearInterruptAfterLastFlag;        /**< \brief Clear Interrupt After Last Flag. Range: TRUE if clears the interrupt flag, FALSE if does not clear the interrupt flag. */
    boolean setInterruptAfterLastFlag;          /**< \brief Sets the Interrupt After Last Flag. Range: TRUE if enable interrupt after last flag, FALSE if disable interrupt after last flag. */
    boolean trail2InjectionEnabled;             /**< \brief Trail 2 Injection Enable. Range: TRUE if enable trail2 injection from MCCON register, FALSE if disable trail2 injection and use bacon configuration. */
    boolean moveCounterEnabled;                 /**< \brief Enable the Move Counter. Range: TRUE move counter enable. FALSE move counter disable. */
} IfxQspi_SpiMaster_MoveCounterControl;

/** \brief Master pin IO configuration structure
 */
typedef struct
{
    IFX_CONST IfxQspi_Sclk_Out       *sclk;            /**< \brief Pointer to SLCK out pin */
    IfxPort_OutputMode                sclkMode;        /**< \brief The SCLK pin output mode */
    IFX_CONST IfxQspi_Mtsr_Out       *mtsr;            /**< \brief Pointer to MTSR out pin */
    IfxPort_OutputMode                mtsrMode;        /**< \brief The MTSR pin output mode */
    IFX_CONST IfxQspi_Mrst_In        *mrst;            /**< \brief Pointer to MRST in pin */
    IfxPort_InputMode                 mrstMode;        /**< \brief The MRST pin input mode */
    IfxPort_PadDriver                 pinDriver;       /**< \brief The pad driver mode which should be configured */
    IfxQspi_SpiMaster_LvdsProperties *lvdsProperties;  /**< \brief LVDS config structure for Master's P or N pins */
} IfxQspi_SpiMaster_Pins;

/** \} */

/** \addtogroup IfxLld_Qspi_SpiMaster_DataStructures
 * \{ */

/** \brief Forward declaring spiMaster handle
 */
typedef struct IfxQspi_SpiMaster_s IfxQspi_SpiMaster;

/** \brief Module Channel handle structure
 */
typedef struct
{
    IfxQspi_SpiMaster                   *spiMaster;                /**< \brief Pointer to the master configuration */
    uint32                               txCount;                  /**< \brief keeps track of transmission. Range: 0 to 0xFFFFFFFF. */
    uint32                               rxCount;                  /**< \brief keeps track of reception. Range: 0 to 0xFFFFFFFF. */
    IfxQspi_Flags                        flags;                    /**< \brief flags */
    IfxQspi_ErrorChecks                  errorChecks;              /**< \brief Error checks */
    sint32                               baudrate;                 /**< \brief actual baud rate */
    IfxQspi_Job                          tx;                       /**< \brief transmit handle */
    IfxQspi_Job                          rx;                       /**< \brief receive handle */
    Ifx_QSPI_BACON                       bacon;                    /**< \brief basic configuration register */
    IfxPort_Pin                          slso;                     /**< \brief Defines SLSO pin */
    uint32                               dummyTxValue;             /**< \brief Dummy TX value, which will be sent for "recieve only" mode. Range: 0 to 0xFFFFFFFF. */
    uint32                               dummyRxValue;             /**< \brief Dummy Rx value, for "transmit only" modes. Range: 0 to 0xFFFFFFFF. */
    IfxQspi_ChannelId                    channelId;                /**< \brief QSPI channel Number */
    IfxQspi_SpiMaster_MoveCounterControl moveCounterControl;       /**< \brief config move counter control register */
    Ifx_ActiveState                      slsoActiveState;          /**< \brief Specifies the current state of SLSO */
    IfxQspi_SpiMaster_ChannelBasedCs     channelBasedCs;           /**< \brief define the slso behaviour */
    IfxQspi_SpiMaster_Mode               mode;                     /**< \brief Qspi Operating Mode */
    IfxQspi_SpiMaster_ErrorFlags         errorFlags;               /**< \brief Spi Master Error Flags */
    uint8                                dataWidth;                /**< \brief Number of bits which will be written into the FIFO. Range: 2 to 0x20. */
    boolean                              firstWrite;               /**< \brief Specifies whether the data id first write or not. Range: TRUE if the data id is first write, FALSE if the data id is not first write. */
    boolean                              useSlso;                  /**< \brief indicates Auto SLSO activation. Range: TRUE if Auto SLSO activation, FALSE if Auto SLSO de-activation. */
}IfxQspi_SpiMaster_Channel;


/** \brief Module handle data structure
 */
struct IfxQspi_SpiMaster_s
{
    IfxQspi_SpiMaster_Channel          *activeChannel;             /**< \brief Pointer to the active master channel configuration */
    Ifx_QSPI                           *qspi;                      /**< \brief Pointer to QSPI module registers */
    IfxQspi_SpiMaster_Dma               dma;                       /**< \brief dma handle */
    float32                             maximumBaudrate;           /**< \brief Maximum Baud Rate for the SPI Module. */
    uint32                              sending;                  /**< \brief set when there is any active transmission. Range: 0 to 0xFFFFFFFF. */
};

/** \brief Module Channel configuration structure
 */
typedef struct
{
    IfxQspi_chConfig                     ch;                       /**< \brief basic channel configuration */
    IfxQspi_SpiMaster                   *spiMaster;                /**< \brief Pointer to the master configuration */
    Ifx_QSPI                            *qspi;                     /**< \brief Pointer to QSPI module registers */
    IfxQspi_SpiMaster_Dma               *dma;                      /**< \brief dma handle */
    uint32                               dummyTxValue;             /**< \brief Dummy TX value to be sent for "recieve only" modes. Range: 0 to 0xFFFFFFFF. */
    uint32                               dummyRxValue;             /**< \brief Dummy RX value for transmit only modes. Range: 0 to 0xFFFFFFFF. */
    IfxQspi_SpiMaster_InputOutput        sls;                      /**< \brief Union of Slave Select pins */
    IfxQspi_SpiMaster_ChannelBasedCs     channelBasedCs;           /**< \brief define the slso behaviour */
    IfxQspi_SpiMaster_Mode               mode;                     /**< \brief Qspi Operating Mode */
} IfxQspi_SpiMaster_ChannelConfig;

/** \brief Module configuration structure
 */
typedef struct
{
    IfxQspi_Mode                      mode;                             /**< \brief Specifies the interface operation mode */
    Ifx_Priority                      rxPriority;                       /**< \brief Specifies the priority of the receive interrupt */
    Ifx_Priority                      txPriority;                       /**< \brief Specifies the priority of the transmit interrupt */
    Ifx_Priority                      erPriority;                       /**< \brief Specifies the priority of the error interrupt */
    Ifx_Priority                      ptPriority;                       /**< \brief Specifies the priority of the phase transition interrupt */
    IfxSrc_Tos                        isrProvider;                      /**< \brief Specifies the handler of the interrupts */
    Ifx_SizeT                         bufferSize;                       /**< \brief Specifies the number of channels that can be buffered. If 0, buffering is disabled */
    void                             *buffer;                           /**< \brief Specifies the buffer location.The buffer parameter must point on a free memory location where the
                                                                         *          buffer object will be initialised. The Size of this area must be at least
                                                                         *          equals to "Size + sizeof(Ifx_Fifo) + 8",
                                                                         *          with "Size=config->bufferSize * Ifx_AlignOn32(sizeof(Spi_Ch*))". Not tacking
                                                                         *          this in account may result in unpredictable behaviour. */
    float32                           maximumBaudrate;                  /**< \brief Maximum baudrate used by the channels, this value is used to optimise the SPI internal clock */
    Ifx_QSPI                         *qspi;                             /**< \brief Pointer to QSPI module registers */
    boolean                           allowSleepMode;                   /**< \brief Specifies module sleep mode. Range: TRUE if sleep mode enable, FALSE if sleep mode disable. */
    boolean                           pauseOnBaudrateSpikeErrors;       /**< \brief Specifies module pause on baudrate or spike errors. Range: TRUE baud rate and spike error in slave mode enable, FALSE baud rate and spike error in slave mode disable. */
    IfxQspi_PauseRunTransition        pauseRunTransition;               /**< \brief Specifies module run or pause mode */
    IfxQspi_TxFifoInt                 txFifoThreshold;                  /**< \brief Specifies the TXFIFO interrupt threshold */
    IfxQspi_RxFifoInt                 rxFifoThreshold;                  /**< \brief Specifies the RXFIFO interrupt threshold */
    IFX_CONST IfxQspi_SpiMaster_Pins *pins;                             /**< \brief Config. structure for QSPI Master pins (P-Pins for LVDS configuration when useLvds is TRUE ) */
    IFX_CONST IfxQspi_SpiMaster_Pins *pinsN;                            /**< \brief Config. structure for QSPI Master pins supporting LVDS-N when useLvds is TRUE. This should be NULL when useLvds is FALSE. */
    IfxQspi_SpiMaster_DmaConfig       dma;                              /**< \brief Dma configuration */
    IfxQspi_FifoMode                  txFifoMode;                       /**< \brief Specifies the transmit FIFO mode */
    IfxQspi_FifoMode                  rxFifoMode;                       /**< \brief Specifies the Receive FIFO mode */
    boolean 						  phaseTransition1Enable;           /**< \brief Specifies the enable/disable state of PT1 interrupt */
    IfxQspi_PhaseTransitionEvent      phaseTransition1Event;            /**< \brief Specifies the event for which PT1 interrupt is to be triggered */
    boolean 						  phaseTransition2Enable;           /**< \brief Specifies the enable/disable state of PT2 interrupt */
    IfxQspi_PhaseTransitionEvent      phaseTransition2Event;            /**< \brief Specifies the event for which PT2 interrupt is to be triggered */
	boolean                           useLvds;                          /**< \brief Specifies if Lvds is to be enabled for the output or not */
} IfxQspi_SpiMaster_Config;


/** \brief structure holding bit-fields data for direct used baud rate configuration
 */
typedef struct
{
    uint8 globalTQ;       /**< \brief Global Time Quantum (clock divider) value for QSPI Instance. Range: 0 to 0xFF. */
    uint8 channelQ;       /**< \brief Channel specific clock divider. Range: 0 to 0x3F. */
    uint8 aSegment;       /**< \brief Value for the A Segment of the clock. Range: 0 to 3. */
    uint8 bSegment;       /**< \brief Value for the B Segment of the clock. Range: 0 to 3. */
    uint8 cSegment;       /**< \brief Value for the C Segment of the clock. Range: 0 to 3. */
} IfxQspi_SpiMaster_BitTiming;
/** \} */

/** \addtogroup IfxLld_Qspi_SpiMaster_Module
 * \{ */

/******************************************************************************/
/*-------------------------Global Function Prototypes-------------------------*/
/******************************************************************************/

/**
 * \brief Initializes the QSPI Master module with the provided configuration.
 *
 * \param[inout] handle Pointer to the QSPI Master module handle.
 * \param[in]    config Pointer to the Configuration structure which should be initialized.
 *
 * \retval None
 *
 * Usage example: see \ref IfxLld_Qspi_SpiMaster_Usage
 *
 */
IFX_EXTERN void IfxQspi_SpiMaster_initModule(IfxQspi_SpiMaster *handle, const IfxQspi_SpiMaster_Config *config);

/**
 * \brief Initializes the SPI Master module configuration structure with default values.
 *
 * \param[inout] config Pointer to the Configuration structure which should be initialized.
 * \param[in]    qspi   Pointer to the QSPI module registers.
 *
 * \retval None
 *
 *  Usage example: see \ref IfxLld_Qspi_SpiMaster_Usage
 *
 */
IFX_EXTERN void IfxQspi_SpiMaster_initModuleConfig(IfxQspi_SpiMaster_Config *config, Ifx_QSPI *qspi);

/** \} */

/** \addtogroup IfxLld_Qspi_SpiMaster_Channel
 * \{ */

/******************************************************************************/
/*-------------------------Global Function Prototypes-------------------------*/
/******************************************************************************/

/**
 * \brief Initializes a SPI master channel with the specified configuration.
 *
 * \param[inout] chHandle  Pointer to the channel handle structure that will be initialized.
 * \param[in]    chConfig  Pointer to the channel configuration structure to be initialized.
 *
 * \retval IfxQspi_Status The status of the channel initialization, which can be busy, ok, or failure. Range: \ref IfxQspi_Status.
 *
 * Usage example: see \ref IfxLld_Qspi_SpiMaster_Usage
 *
 */
IFX_EXTERN IfxQspi_Status IfxQspi_SpiMaster_initChannel(IfxQspi_SpiMaster_Channel *chHandle, const IfxQspi_SpiMaster_ChannelConfig *chConfig);

/**
 * \brief Initializes the SPI master channel configuration structure with default values.
 *
 * \param[inout] chConfig Pointer to the channel configuration structure to be initialized.
 * \param[in]    handle   Pointer to the QSPI Master module handle.
 *
 * \retval None
 *
 * Usage example: see \ref IfxLld_Qspi_SpiMaster_Usage
 *
 */
IFX_EXTERN void IfxQspi_SpiMaster_initChannelConfig(IfxQspi_SpiMaster_ChannelConfig *chConfig, IfxQspi_SpiMaster *handle);

/** \} */

/** \addtogroup IfxLld_Qspi_SpiMaster_Com
 * \{ */

/******************************************************************************/
/*-------------------------Global Function Prototypes-------------------------*/
/******************************************************************************/

/**
 * \brief Exchanges data between source and destination in SPI master mode.
 *
 * \param[inout] chHandle Pointer to the QSPI master channel handle.
 * \param[in]    src      Source of data to be transmitted. Can be set to NULL if no data is to be transmitted (receive-only mode).
 *                        In this case, all-1s will be sent.
 * \param[in]    dest     Destination for received data. Can be set to NULL if no data is to be received (transmit-only mode).
 * \param[in]    count    Number of data items to exchange. Must be a positive integer.
 *
 * \retval IfxQspi_Status Status of the data exchange operation.
 *                        Returns a status code indicating success or failure. Range: \ref IfxQspi_Status.
 *
 * Usage example: see \ref IfxLld_Qspi_SpiMaster_Usage
 *
 */
IFX_EXTERN IfxQspi_Status IfxQspi_SpiMaster_exchange(IfxQspi_SpiMaster_Channel *chHandle, const void *src, void *dest, Ifx_SizeT count);

/**
 * \brief Retrieves the current transmission status of the specified QSPI master channel.
 *
 * \param[in] chHandle Pointer to the QSPI master channel handle.
 *
 * \retval IfxQspi_Status The transmission status, which can include states such as success,
 *                        busy, error, or other predefined statuses based on the IfxQspi_Status enumeration. Range: \ref IfxQspi_Status.
 *
 * Usage example: see \ref IfxLld_Qspi_SpiMaster_Usage
 *
 */
IFX_EXTERN IfxQspi_Status IfxQspi_SpiMaster_getStatus(IfxQspi_SpiMaster_Channel *chHandle);

/** \} */

/** \addtogroup IfxLld_Qspi_SpiMaster_InterruptFunctions
 * \{ */

/******************************************************************************/
/*-------------------------Global Function Prototypes-------------------------*/
/******************************************************************************/

/**
 * \brief Interrupt handler for DMA receive operations in QSPI master mode.
 *
 * \param[inout] qspiHandle Pointer to the QSPI master module handle.
 *
 * \retval None
 *
 */
IFX_EXTERN void IfxQspi_SpiMaster_isrDmaReceive(IfxQspi_SpiMaster *qspiHandle);

/**
 * \brief Interrupt service routine handling DMA-based transmission for the SPI master module
 *
 * \param[in] qspiHandle Pointer to the QSPI master module handle.
 *
 * \retval None
 *
 */
IFX_EXTERN void IfxQspi_SpiMaster_isrDmaTransmit(IfxQspi_SpiMaster *qspiHandle);

/**
 * \brief Handles error interrupts for the QSPI module in master mode.
 *
 * \param[in] handle Pointer to the QSPI master module handle.
 *
 * \retval None
 *
 */
IFX_EXTERN void IfxQspi_SpiMaster_isrError(IfxQspi_SpiMaster *handle);

/** \brief Get the status of a particular error.
 *  Note: This function should be called only after calling the IfxQspi_SpiMaster_isrError().
 *
 * \param[inout] handle Module handle.
 * \param[in]    error Module handle. Range: \ref IfxQspi_Error.
 *
 * \retval Returns the error status. Range 0 or 1.
 */
IFX_EXTERN boolean IfxQspi_SpiMaster_isError(IfxQspi_SpiMaster *handle, IfxQspi_Error error);

#if defined(DEVICE_TC33XED) || defined(DEVICE_TC33X) || defined(DEVICE_TC35X) || defined(DEVICE_TC39XB)

/** \brief High speed capture interrupt handler.
 *
 * \param[in] handle Pointer to the QSPI master module handle.
 *
 * \retval Latest Capture Timer value (0: if no Capture event occured; Bit15 = 1: if overflow occured). Range: 0 to 0xFFFF.
 *
 */
IFX_EXTERN uint16 IfxQspi_SpiMaster_isrHighSpeedCapure(IfxQspi_SpiMaster *handle);
#endif

/**
 * \brief Handles the phase transition interrupt and returns the associated event.
 *
 * \param[in] handle Pointer to the QSPI master module handle.
 *
 * \retval IfxQspi_PhaseTransitionEvent The phase transition event that triggered the interrupt. Range: \ref IfxQspi_PhaseTransitionEvent.
 *
 */
IFX_EXTERN IfxQspi_PhaseTransitionEvent IfxQspi_SpiMaster_isrPhaseTransition(IfxQspi_SpiMaster *handle);

/**
 * \brief Interrupt Service Routine (ISR) for handling the receive operation in the QSPI module.
 * 
 * \param[inout] handle Pointer to the QSPI master module handle.
 *
 * \retval None
 *
 */
IFX_EXTERN void IfxQspi_SpiMaster_isrReceive(IfxQspi_SpiMaster *handle);

/**
 * \brief Transmit interrupt handler for SPI master module.
 * 
 * \param[in] handle Pointer to the QSPI master module handle.
 * 
 * \retval None
 * 
 */
IFX_EXTERN void IfxQspi_SpiMaster_isrTransmit(IfxQspi_SpiMaster *handle);

/**
 * \brief User-defined interrupt handler for the SPI master module.
 *
 * \param[in] handle Pointer to the QSPI master module handle.
 * 
 * \retval IfxQspi_PhaseTransitionEvent The event indicating the phase transition status. Range: \ref IfxQspi_PhaseTransitionEvent.
 * 
 */
IFX_EXTERN IfxQspi_PhaseTransitionEvent IfxQspi_SpiMaster_isrUserDefined(IfxQspi_SpiMaster *handle);

/** \} */

/** \addtogroup IfxLld_Qspi_SpiMaster_DirectFifo
 * \{ */

/******************************************************************************/
/*-------------------------Inline Function Prototypes-------------------------*/
/******************************************************************************/

/**
 * \brief Reads a 32-bit value from the Receive FIFO (RxFIFO) of the SPI master module.
 *
 * \param[in] handle Pointer to the QSPI master module handle.
 *
 * \retval uint32 The 32-bit value read from the RxFIFO. The value represents either received data or status information.
 *                Range: 0 to 0xFFFF FFFF.
 *
 */
IFX_INLINE uint32 IfxQspi_SpiMaster_readReceiveFifo(IfxQspi_SpiMaster *handle);

/**
 * \brief Configures the basic settings for the SPI master module by writing to the Tx FIFO.
 *
 * \param[in] handle   Pointer to the QSPI master module handle.
 * \param[in] baconVal Basic configuration value to be written to the TxFIFO. This value is directly used to configure the SPI master's basic operation settings.
 *                     Range: 0 to 0xFFFF FFFF.
 * \retval None
 * 
 */
IFX_INLINE void IfxQspi_SpiMaster_writeBasicConfiguration(IfxQspi_SpiMaster *handle, uint32 baconVal);

/**
 * \brief Writes extended configuration settings for the specified QSPI channel.
 *
 * \param[in] chHandle Pointer to the QSPI channel handle structure.
 * \param[in] econVal  Channel timing configuration value. This value defines the extended
 *                     timing and operational parameters for the channel. Range: 0 to 0xC000 7FFF.
 *
 * \retval None
 *
 */
IFX_INLINE void IfxQspi_SpiMaster_writeExtendedConfiguration(IfxQspi_SpiMaster_Channel *chHandle, uint32 econVal);

/**
 * \brief Writes a mixed data and configuration value to the Tx FIFO for the QSPI module.
 *
 * \param[in] handle      Pointer to the QSPI master module handle.
 * \param[in] mixEntryVal 32-bit value combining data and configuration to be written to the Tx FIFO. Range: 0 to 0xFFFF FFFF.
 *
 * \retval None
 * 
 */
IFX_INLINE void IfxQspi_SpiMaster_writeMixedDataConfiguration(IfxQspi_SpiMaster *handle, uint32 mixEntryVal);

/**
 * \brief Writes the provided data to the Transmit FIFO (TxFIFO) for the specified QSPI channel.
 *
 * \param[in] chHandle Pointer to the QSPI channel handle structure.
 * \param[in] data     The 32-bit data value to be written into the TxFIFO for transmission. Range: 0 to 0xFFFF FFFF.
 *
 * \retval None
 * 
 */
IFX_INLINE void IfxQspi_SpiMaster_writeTransmitFifo(IfxQspi_SpiMaster_Channel *chHandle, uint32 data);

/******************************************************************************/
/*-------------------------Global Function Prototypes-------------------------*/
/******************************************************************************/

/**
 * \brief Packs data into a buffer for Long Mode operation in SPI master mode.
 * 
 * \param[inout] chHandle       Pointer to the QSPI channel handle structure.
 * \param[in]    data           Source data buffer to be packed into the FIFO buffer.
 * \param[inout] longFifoBuffer Destination buffer that will hold the packed data and configuration. Range: 0 to 0xFFFF FFFF.
 * \param[in]    dataLength     Size of the data in the source buffer (in bytes). Must be greater than 0.
 *
 * \retval None
 * 
 */
IFX_EXTERN void IfxQspi_SpiMaster_packLongModeBuffer(IfxQspi_SpiMaster_Channel *chHandle, void *data, uint32 *longFifoBuffer, Ifx_SizeT dataLength);

/** \} */

/******************************************************************************/
/*-------------------------Global Function Prototypes-------------------------*/
/******************************************************************************/

/**
 * \brief Retrieves the current configuration of a specified QSPI channel.
 *
 * \param[in] chHandle       Pointer to the QSPI channel handle structure.
 *
 * \retval IfxQspi_chConfig The configuration structure containing the current settings of the QSPI channel.
 * 
 */
IFX_EXTERN IfxQspi_chConfig IfxQspi_SpiMaster_getChannelConfig(IfxQspi_SpiMaster_Channel *chHandle);

/**
 * \brief Configures the move counter control settings for the SPI master module.
 *
 * \param[inout] qspi        Module register handler providing access to the QSPI module registers.
 * \param[in]    moveCounter Pointer to the structure containing move counter configuration settings,
 *                           including trailing delays, interrupt enables, and flags.
 *
 * \retval None
 *
 */
IFX_EXTERN void IfxQspi_SpiMaster_moveCounterControlConfiguration(Ifx_QSPI *qspi, IfxQspi_SpiMaster_MoveCounterControl *moveCounter);

/**
 * \brief Sets the baudrate for the specified SPI master channel.
 *
 * \param[inout] chHandle Pointer to the QSPI channel handle structure.
 * \param[in]    baudrate The new baudrate value to be configured, in baud.
 *
 * \retval Status of Channel (busy or ok or failure). Range: \ref IfxQspi_Status.
 *
 */
IFX_EXTERN IfxQspi_Status IfxQspi_SpiMaster_setChannelBaudrate(IfxQspi_SpiMaster_Channel *chHandle, float32 baudrate);

/**
 * \brief Retrieves the delay parameters configured in the specified channel handle and populates them into the provided parameters structure.
 * 
 * \param[in]    chHandle Pointer to the QSPI channel handle structure.
 * \param[inout] params   Pointer to the IfxQspi_DelayParameters structure where the retrieved delay parameters (idle, leading, and trailing delays) will be stored.
 *                        This structure includes prescalar and length values for each type of delay.
 * 
 * \retval None
 * 
 */
IFX_EXTERN void IfxQspi_SpiMaster_getHandleDelayParameters(IfxQspi_SpiMaster_Channel *chHandle, IfxQspi_DelayParameters *params);

/**
 * \brief Update the delay parameters (Idle, Leading and Trailing Delays) in handle and SFR. To be called after call to IfxQspi_SpiMaster_initChannel. Used for re-configuring by application (optional).
 *
 * \param[inout] chHandle Pointer to the QSPI channel handle structure.
 * \param[in]    config   Pointer to the structure containing the delay parameters to be updated.
 *                        This includes prescalar and delay values for Idle, Leading, and Trailing delays.
 *
 * \retval None
 *
 */
IFX_EXTERN void IfxQspi_SpiMaster_updateDelayParameters(IfxQspi_SpiMaster_Channel *chHandle, IfxQspi_DelayParameters *config);

/**
 * \brief Initializes the SPI master pins based on the provided configuration. To be called in IfxQspi_SpiMaster_initChannel.
 *
 * \param[in] pins Pointer to the structure containing the pin configuration settings.
 *                 The structure includes configurations for SCLK, MTSR, MRST pins,
 *                 their respective modes, and the pad driver mode.
 *
 * \retval None
 *
 */
IFX_EXTERN void IfxQspi_SpiMaster_initPin(const IfxQspi_SpiMaster_Pins *pins);

/**
 * \brief Initializes the interrupt configuration for the SPI master module based on the provided settings. To be called in IfxQspi_SpiMaster_initChannel.
 *
 * \param[inout] qspiSFR Pointer to the SPI module's Special Function Register (SFR) handle.
 * \param[in]    config  Pointer to the configuration structure containing interrupt and operational settings.
 *                       The structure includes fields for specifying interrupt priorities, FIFO thresholds, and buffer configurations.
 *
 * \retval None
 * 
 */
IFX_EXTERN void IfxQspi_SpiMaster_initInterrupt(Ifx_QSPI *qspiSFR, const IfxQspi_SpiMaster_Config *config);

/**
 * \brief Configures the global baud rate settings for the QSPI module using the provided bit timing parameters.
 *
 * \param[in] handle          pointer to QSPI master module handle.
 * \param[in] bitTimingParams Pointer to the structure containing the bitfields for baud rate configuration.
 *                            The structure includes global and channel-specific clock dividers, as well as
 *                            clock segment values (A, B, and C segments).
 *
 * \retval None
 * 
 */
IFX_EXTERN void IfxQspi_SpiMaster_setBaudRateGlobalBitFields(IfxQspi_SpiMaster *handle, const IfxQspi_SpiMaster_BitTiming *bitTimingParams);

/**
 * \brief Configures the baud rate timing parameters for a specific QSPI channel.
 *
 * \param[in] handle          pointer to QSPI master module handle.
 * \param[in] channelId       QSPI channel identifier. Range: \ref IfxQspi_ChannelId.
 * \param[in] bitTimingParams Pointer to a structure containing bit timing configuration
 *                            parameters, including global and channel-specific clock
 *                            dividers and segment timing values.
 *
 * \retval None
 */
IFX_EXTERN void IfxQspi_SpiMaster_setBaudRateChannelBitFields(IfxQspi_SpiMaster *handle, const IfxQspi_ChannelId channelId, const IfxQspi_SpiMaster_BitTiming *bitTimingParams);

/** \brief Initialize pins based on configuration. To be called in IfxQspi_SpiMaster_initChannel
 * \param[in] pins Pointer to structure holding the pin configuration
 * \retval None
 */
IFX_EXTERN void IfxQspi_SpiMaster_initLvdsPin(const IfxQspi_SpiMaster_Pins *pins);

/******************************************************************************/
/*---------------------Inline Function Implementations------------------------*/
/******************************************************************************/

IFX_INLINE uint32 IfxQspi_SpiMaster_readReceiveFifo(IfxQspi_SpiMaster *handle)
{
    Ifx_QSPI *qspiSFR = handle->qspi;
    uint32    data    = IfxQspi_readReceiveFifo(qspiSFR);
    return data;
}


IFX_INLINE void IfxQspi_SpiMaster_writeBasicConfiguration(IfxQspi_SpiMaster *handle, uint32 baconVal)
{
    Ifx_QSPI *qspiSFR = handle->qspi;
    IfxQspi_writeBasicConfiguration(qspiSFR, baconVal);
}


IFX_INLINE void IfxQspi_SpiMaster_writeExtendedConfiguration(IfxQspi_SpiMaster_Channel *chHandle, uint32 econVal)
{
    IfxQspi_SpiMaster *spiMaster = (IfxQspi_SpiMaster *)chHandle->spiMaster;

    IfxQspi_writeExtendedConfiguration(spiMaster->qspi, chHandle->channelId, econVal);
}


IFX_INLINE void IfxQspi_SpiMaster_writeMixedDataConfiguration(IfxQspi_SpiMaster *handle, uint32 mixEntryVal)
{
    Ifx_QSPI *qspiSFR = handle->qspi;
    IfxQspi_writeMixedDataTransmitFifo(qspiSFR, mixEntryVal);
}


IFX_INLINE void IfxQspi_SpiMaster_writeTransmitFifo(IfxQspi_SpiMaster_Channel *chHandle, uint32 data)
{
    IfxQspi_SpiMaster *spiMaster = (IfxQspi_SpiMaster *)chHandle->spiMaster;

    IfxQspi_writeTransmitFifo(spiMaster->qspi, data);
}


#endif /* IFXQSPI_SPIMASTER_H */
