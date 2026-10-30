/**
 * \file IfxQspi_SpiSlave.h
 * \brief QSPI SPISLAVE details
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
 * \defgroup IfxLld_Qspi_SpiSlave_Usage How to use the SPI Slave Interface driver?
 * \ingroup IfxLld_Qspi
 *
 * The SPI Slave interface driver provides a default QSPI configuration for a bidirectional serial communication of data words.
 *
 * Data transactions are buffered by the hardware based FIFOs. Incoming and outgoing data is transfered in background from/to the QSPI peripheral by interrupt service handlers, which are part of this driver as well. This allows a nonblocking communication without stalling the thread(s) from where data is sent and received.
 * Optionally Dma can be used for data transfers. Only the interrupt configuration and Module initialisation are different when dma is used.
 *
 * Clock polarity, Clock Phase for slave mode are fixed. Overriding them will cause unexpected behaviour
 * Baudrate on slave is adopted from the master clock. User configuration will not take effect.
 * The enum IfxQspi_ShiftClock_shiftTransmitDataOnLeadingEdge corresponds to a CPH value of 1 and IfxQspi_ShiftClock_shiftTransmitDataOnTrailingEdge
 * corresponds to a CPH value of 0, while setting the clock phase in the ECON register.
 *
 * In the following sections it will be described, how to integrate the driver into the application framework.
 *
 * \section IfxLld_Qspi_SpiSlave_Preparation Preparation
 * \subsection IfxLld_Qspi_SpiSlave_Include Include Files
 *
 * Include following header file into your C code:
 * \code
 * #include <Qspi/SpiSlave/IfxQspi_SpiSlave.h>
 * \endcode
 *
 * \subsection IfxLld_Qspi_SpiSlave_Variables Variables
 *
 * Declare QSPI module handle:
 *
 * \code
 * IfxQspi_SpiSlave spi;
 * \endcode
 *
 * In addition, declare global transmit and receive buffers for the data transfers:
 * \code
 * #define SPI_BUFFER_SIZE 8
 * uint8	spiTxBuffer[SPI_BUFFER_SIZE];
 * uint8	spiRxBuffer[SPI_BUFFER_SIZE];
 * \endcode
 *
 * \subsection IfxLld_Qspi_SpiSlave_Interrupt Interrupt Handler Installation (without dma use)
 *
 * See also \ref IfxLld_Cpu_Irq_Usage
 *
 * Define priorities for the Interrrupt handlers. This is normally done in the Ifx_IntPrioDef.h file:
 * \code
 * // priorities are normally defined in Ifx_IntPrioDef.h
 *  #define IFX_INTPRIO_QSPI2_TX  1
 *  #define IFX_INTPRIO_QSPI2_RX  2
 *  #define IFX_INTPRIO_QSPI2_ER  5
 * \endcode
 *
 * Add the interrupt service routines to your C code. They have to call the QSPI interrupt handlers by passing the spi handle:
 * \code
 * IFX_INTERRUPT(qspi2TxISR, 0, IFX_INTPRIO_QSPI2_TX)
 * {
 *     IfxQspi_SpiSlave_isrTransmit(&spi);
 * }
 *
 * IFX_INTERRUPT(qspi2RxISR, 0, IFX_INTPRIO_QSPI2_RX)
 * {
 *     IfxQspi_SpiSlave_isrReceive(&spi);
 * }
 *
 * IFX_INTERRUPT(qspi2ErISR, 0, IFX_INTPRIO_QSPI2_ER)
 * {
 *     IfxQspi_SpiSlave_isrError(&spi);
 *     // Process errors. Eg: parity Error is checked below
 *     if( spi.errorFlags.parityError == 1)
 *     {
 *         // Parity Error
 *     }
 * }
 * \endcode
 *
 * Finally install the interrupt handlers in your initialisation function:
 * \code
 *     // install interrupt handlers
 *     IfxCpu_Irq_installInterruptHandler(&qspi2TxISR, IFX_INTPRIO_QSPI2_TX);
 *     IfxCpu_Irq_installInterruptHandler(&qspi2RxISR, IFX_INTPRIO_QSPI2_RX);
 *     IfxCpu_Irq_installInterruptHandler(&qspi2ErISR, IFX_INTPRIO_QSPI2_ER);
 *     IfxCpu_enableInterrupts();
 * \endcode
 *
 * \subsection IfxLld_Qspi_SpiSlave_Interrupt_dma Interrupt Handler Installation (with dma use)
 *
 * See also \ref IfxLld_Cpu_Irq_Usage
 *
 * Define priorities for the Interrrupt handlers. This is normally done in the Ifx_IntPrioDef.h file:
 * \code
 * // priorities are normally defined in Ifx_IntPrioDef.h
 * // qspi priorities
 * #define IFX_INTPRIO_QSPI2_TX  3 // DMA channel 3
 * #define IFX_INTPRIO_QSPI2_RX  4 // DMA channel 4
 * #define IFX_INTPRIO_QSPI2_ER  0x31
 * // dma priorities
 * #define IFX_INTPRIO_DMA_CH3  12
 * #define IFX_INTPRIO_DMA_CH4  13
 * \endcode
 *
 * Add the interrupt service routines to your C code. They have to call the QSPI interrupt handlers by passing the spi handle:
 * \code
 * IFX_INTERRUPT(qspi2DmaTxISR, 0, IFX_INTPRIO_DMA_CH3)
 * {
 *   IfxQspi_SpiSlave_isrDmaTransmit(&spi);
 *
 * }
 *
 * IFX_INTERRUPT(qspi2DmaRxISR, 0, IFX_INTPRIO_DMA_CH4)
 * {
 *   IfxQspi_SpiSlave_isrDmaReceive(&spi);
 * }
 *
 * IFX_INTERRUPT(qspi2ErISR, 0, IFX_INTPRIO_QSPI2_ER)
 * {
 *     IfxQspi_SpiSlave_isrError(&spi);
 *     // Process errors. Eg: parity Error is checked below
 *     if( spi.errorFlags.parityError == 1)
 *     {
 *         // Parity Error
 *     }
 *
 * }
 * \endcode
 *
 * Finally install the interrupt handlers in your initialisation function:
 * \code
 *     // install interrupt handlers
 *     IfxCpu_Irq_installInterruptHandler(&qspi2DmaTxISR, IFX_INTPRIO_DMA_CH3);
 *     IfxCpu_Irq_installInterruptHandler(&qspi2DmaRxISR, IFX_INTPRIO_DMA_CH4);
 *     IfxCpu_Irq_installInterruptHandler(&qspi2ErISR, IFX_INTPRIO_QSPI2_ER);
 *     IfxCpu_enableInterrupts();
 * \endcode
 *
 * \subsection IfxLld_Qspi_SpiSlave_Init Module Initialisation (without dma use)
 *
 * The module initialisation can be done in the same function.
 *
 * Here an example for slave mode:
 * \code
 *     // create module config
 *     // Clock polarity, Clock Phase for slave mode are fixed. Overriding them will cause unexpected behaviour
 * 	   // Baudrate on slave is adopted from the master clock. User configuration will not take effect.
 *     IfxQspi_SpiSlave_Config spiSlaveConfig;
 *     IfxQspi_SpiSlave_initModuleConfig(&spiSlaveConfig, &MODULE_QSPI2);
 *
 *     // set the maximum baudrate
 *     spiSlaveConfig.maximumBaudrate  = 10000000;
 *
 *     // ISR priorities and interrupt target
 *     spiSlaveConfig.txPriority       = IFX_INTPRIO_QSPI2_TX;
 *     spiSlaveConfig.rxPriority       = IFX_INTPRIO_QSPI2_RX;
 *     spiSlaveConfig.erPriority       = IFX_INTPRIO_QSPI2_ER;
 *     spiSlaveConfig.isrProvider      = IfxCpu_Irq_getTos(IfxCpu_getCoreIndex());
 *
 *     // pin configuration
 *     const IfxQspi_SpiSlave_Pins slavePins = {
 *         &IfxQspi2_SCLKA_P15_3_IN, IfxPort_InputMode_pullDown,   // SCLK Pin
 *         &IfxQspi2_MTSRA_P15_5_IN, IfxPort_InputMode_pullDown,   // MTSR Pin
 *         &IfxQspi2_MRST_P15_7_OUT, IfxPort_OutputMode_pushPull,  // MRST Pin
 *         &IfxQspi2_SLSIA_P15_2_IN, IfxPort_InputMode_pullDown,   // SLSI Pin
 *         IfxPort_PadDriver_cmosAutomotiveSpeed3 // pad driver mode
 *     };
 *     spiSlaveConfig.pins = &slavePins;
 *
 *     // initialize module
 *     //IfxQspi_Spi spi; // defined globally
 *     IfxQspi_SpiSlave_initModule(&spi, &spiSlaveConfig);
 * \endcode
 *
 * \subsection IfxLld_Qspi_SpiSlave_Init_dma Module Initialisation (with dma use)
 *
 * The module initialisation can be done in the same function.
 *
 * Here an example for slave mode:
 * \code
 *     // create module config
 *     // Clock polarity, Clock Phase for slave mode are fixed. Overriding them will cause unexpected behaviour
 *	   // Baudrate on slave is adopted from the master clock. User configuration will not take effect.
 *     IfxQspi_SpiSlave_Config spiSlaveConfig;
 *     IfxQspi_SpiSlave_initModuleConfig(&spiSlaveConfig, &MODULE_QSPI2);
 *
 *     // set the maximum baudrate
 *     spiSlaveConfig.maximumBaudrate  = 10000000;
 *
 *     // ISR priorities and interrupt target (with dma usage)
 *     spiSlaveConfig.txPriority       = IFX_INTPRIO_DMA_CH3;
 *     spiSlaveConfig.rxPriority       = IFX_INTPRIO_DMA_CH4;
 *     spiSlaveConfig.erPriority       = IFX_INTPRIO_QSPI2_ER;
 *
 *       spiSlaveConfig.dma.txDmaChannelId = IfxDma_ChannelId_3;
 *        spiSlaveConfig.dma.rxDmaChannelId = IfxDma_ChannelId_4;
 *        spiSlaveConfig.dma.useDma = 1;
 *
 *     // pin configuration
 *     const IfxQspi_SpiSlave_Pins slavePins = {
 *         &IfxQspi2_SCLKA_P15_3_IN, IfxPort_InputMode_pullDown,   // SCLK Pin
 *         &IfxQspi2_MTSRA_P15_5_IN, IfxPort_InputMode_pullDown,   // MTSR Pin
 *         &IfxQspi2_MRST_P15_7_OUT, IfxPort_OutputMode_pushPull,  // MRST Pin
 *         &IfxQspi2_SLSIA_P15_2_IN, IfxPort_InputMode_pullDown,   // SLSI Pin
 *         IfxPort_PadDriver_cmosAutomotiveSpeed3 // pad driver mode
 *     };
 *     spiSlaveConfig.pins = &slavePins;
 *
 *     // initialize module
 *     //IfxQspi_Spi spi; // defined globally
 *     IfxQspi_SpiSlave_initModule(&spi, &spiSlaveConfig);
 * \endcode
 *
 * The QSPI is ready for use now!
 *
 *
 * \section IfxLld_Qspi_SpiSlave_DataTransfers Data Transfers
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
 *      int i = 0;
 *     // wait until transfer of previous data stream is finished
 *     while( IfxQspi_SpiSlave_getStatus(&spi) == IfxQspi_Status_busy );
 *
 *     // send/receive new stream
 *     IfxQspi_SpiSlave_exchange(&spi, &spiTxBuffer[i], &spiRxBuffer[i], SPI_BUFFER_SIZE);
 * \endcode
 *
 * Send only, discard received data:
 * \code
 *
 *     // wait until transfer of previous data stream is finished
 *     while( IfxQspi_SpiSlave_getStatus(&spi) == IfxQspi_Status_busy );
 *
 *     // send new stream
 *     IfxQspi_SpiSlave_exchange(&spi, &spiTxBuffer[i], NULL_PTR, SPI_BUFFER_SIZE);
 * \endcode
 *
 * Receive only, send all-1
 * \code
 *     // wait until transfer of previous data stream is finished
 *     while( IfxQspi_SpiSlave_getStatus(&spi) == IfxQspi_Status_busy );
 *
 *     // receive new stream
 *     IfxQspi_SpiSlave_exchange(&spi, NULL_PTR, &spiRxBuffer[i], SPI_BUFFER_SIZE);
 * \endcode
 *
 * \defgroup IfxLld_Qspi_SpiSlave SPI Slave Driver
 * \ingroup IfxLld_Qspi
 * \defgroup IfxLld_Qspi_SpiSlave_DataStructures Data Structures
 * \ingroup IfxLld_Qspi_SpiSlave
 * \defgroup IfxLld_Qspi_SpiSlave_Module Module Functions
 * \ingroup IfxLld_Qspi_SpiSlave
 * \defgroup IfxLld_Qspi_SpiSlave_Support Support Functions
 * \ingroup IfxLld_Qspi_SpiSlave
 * \defgroup IfxLld_Qspi_SpiSlave_Com Communication
 * \ingroup IfxLld_Qspi_SpiSlave
 * \defgroup IfxLld_Qspi_SpiSlave_InterruptFunctions Interrupt Functions
 * \ingroup IfxLld_Qspi_SpiSlave
 * \defgroup IfxLld_Qspi_SpiSlave_DirectFifo Direct FIFO Access
 * \ingroup IfxLld_Qspi_SpiSlave
 */

#ifndef IFXQSPI_SPISLAVE_H
#define IFXQSPI_SPISLAVE_H 1

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include "Cpu/Irq/IfxCpu_Irq.h"
#include "Dma/Dma/IfxDma_Dma.h"
#include "Qspi/Std/IfxQspi.h"
#include "Scu/Std/IfxScuWdt.h"

/******************************************************************************/
/*-----------------------------Data Structures--------------------------------*/
/******************************************************************************/

/** \addtogroup IfxLld_Qspi_SpiSlave_DataStructures
 * \{ */
/** \brief Slave Lvds pins configuration
 */
typedef struct
{
    IfxPort_LvdsConfig sclkInLvdsCfg;        /**< \brief SCLK_in LVDS P/N Pin configuration structure */
    IfxPort_LvdsConfig mtsrInLvdsCfg;        /**< \brief MTSR_in LVDS P/N Pin configuration structure */
    IfxPort_LvdsConfig mrstOutLvdsCfg;       /**< \brief MRST_out LVDS P/N Pin configuration structure */
} IfxQspi_SpiSlave_LvdsProperties;

/** \brief Dma handle
 */
typedef struct
{
    IfxDma_Dma_Channel rxDmaChannel;         /**< \brief receive DMA channel handle */
    IfxDma_Dma_Channel txDmaChannel;         /**< \brief transmit DMA channel handle */
    IfxDma_ChannelId   rxDmaChannelId;       /**< \brief DMA channel no for the Spi recieve */
    IfxDma_ChannelId   txDmaChannelId;       /**< \brief DMA channel no for the Spi transmit */
    boolean            useDma;               /**< \brief use Dma for Data transfers. Range: TRUE enable Data transfer, FALSE disable Data transfer. */
} IfxQspi_SpiSlave_Dma;

/** \brief Dma configuration
 */
typedef struct
{
    IfxDma_ChannelId rxDmaChannelId;       /**< \brief DMA channel no for the Spi receive */
    IfxDma_ChannelId txDmaChannelId;       /**< \brief DMA channel no for the Spi transmit */
    boolean          useDma;               /**< \brief use Dma for Data transfers. Range: TRUE enable Data transfer, FALSE disable Data transfer. */
} IfxQspi_SpiSlave_DmaConfig;

/** \brief Qspi Slave Mode Error Flags
 */
typedef struct
{
    boolean parityError;                   /**< \brief [0:0] Parity Error. Range: TRUE Parity Error occurred, FALSE Parity Error not occurred. */
    boolean configurationError;            /**< \brief [1:1] Configuration Error. Range: TRUE Configuration Error occurred, FALSE Configuration Error not occurred. */
    boolean baudrateError;                 /**< \brief [2:2] baudrate Error. Range: TRUE baudrate Error occurred, FALSE baudrate Error not occurred. */
    boolean txFifoOverflowError;           /**< \brief [3:3] TxFifo Overflow Error. Range: TRUE TxFifo Overflow Error occurred, FALSE disable TxFifo Overflow Error not occurred. */
    boolean txFifoUnderflowError;          /**< \brief [4:4] TxFifo underflow Error. Range: TRUE TxFifo underflow Error occurred, FALSE disable TxFifo underflow Error not occurred. */
    boolean rxFifoOverflowError;           /**< \brief [5:5] RxFifo Overflow Error. Range: TRUE RxFifo Overflow Error occurred, FALSE disable RxFifo Overflow Error not occurred. */
    boolean rxFifoUnderflowError;          /**< \brief [6:6] RxFifo underflow Error. Range: TRUE RxFifo underflow Error occurred, FALSE RxFifo underflow Error not occurred. */
    boolean expectTimeoutError;            /**< \brief [7:7] Expect Timeout Error. Range: TRUE Expect Timeout Error occurred, FALSE Expect Timeout Error not occurred. */
    boolean slsiMisplacedInactivation;     /**< \brief [8:8] SLSI misplaced inactivation (slave mode). Range: TRUE SLSI misplaced inactivation Error occurred, FALSE SLSI misplaced inactivation Error not occurred. */
} IfxQspi_SpiSlave_ErrorFlags;

/** \brief Slave pin IO configuration structure
 */
typedef struct
{
    IFX_CONST IfxQspi_Sclk_In       *sclk;            /**< \brief Pointer to SLCK in pin */
    IfxPort_InputMode                sclkMode;        /**< \brief The SCLK pin input mode */
    IFX_CONST IfxQspi_Mtsr_In       *mtsr;            /**< \brief Pointer to MTSR in pin */
    IfxPort_InputMode                mtsrMode;        /**< \brief The MTSR pin input mode */
    IFX_CONST IfxQspi_Mrst_Out      *mrst;            /**< \brief Pointer to MRST out pin */
    IfxPort_OutputMode               mrstMode;        /**< \brief The MRST pin output mode */
    IFX_CONST IfxQspi_Slsi_In       *slsi;            /**< \brief Pointer to SLSI in pin */
    IfxPort_InputMode                slsiMode;        /**< \brief The SLSI pin input mode */
    IfxPort_PadDriver                pinDriver;       /**< \brief The pad driver mode which should be configured */
    IfxQspi_SpiSlave_LvdsProperties *lvdsProperties;  /**< \brief LVDS config structure for Slave's P or N pins */
} IfxQspi_SpiSlave_Pins;

/** \brief Configures the SPI Protocol
 */
typedef struct
{
    IfxQspi_ClockPolarity clockPolarity;       /**< \brief Specifies the clock polarity */
    IfxQspi_ShiftClock    shiftClock;          /**< \brief Specifies the clock phase */
    IfxQspi_DataHeading   dataHeading;         /**< \brief Specifies MSB or LSB first */
    uint8                 dataWidth;           /**< \brief range 2 .. 32 bits (note 2 = 2-bits, 3 = 3-bits ... */
    IfxQspi_ParityMode    parityMode;          /**< \brief Specifies the parity mode */
} IfxQspi_SpiSlave_Protocol;

/** \} */

/** \addtogroup IfxLld_Qspi_SpiSlave_DataStructures
 * \{ */
/** \brief Module handle data structure
 */
typedef struct
{
    Ifx_QSPI                   *qspi;             /**< \brief Pointer to QSPI module registers */
    uint8                       dataWidth;        /**< \brief Number of bits which will be written into the FIFO. Range: 2 to 32. */
    IfxQspi_Job                 rxJob;            /**< \brief Rx Stream which has been received */
    IfxQspi_Job                 txJob;            /**< \brief Tx Stream which should be sent */
    boolean                     onTransfer;       /**< \brief set to TRUE during ongoing transfer. Range: TRUE transfer as active, FALSE transfer as inactive. */
    IfxQspi_SpiSlave_Dma        dma;              /**< \brief Dma handle */
    IfxQspi_SpiSlave_ErrorFlags errorFlags;       /**< \brief Spi Slave Error Flags */
} IfxQspi_SpiSlave;

/** \brief Module configuration structure
 */
typedef struct
{
    IfxQspi_Mode                     mode;                             /**< \brief Specifies the interface operation mode */
    Ifx_Priority                     rxPriority;                       /**< \brief Specifies the priority of the receive interrupt */
    Ifx_Priority                     txPriority;                       /**< \brief Specifies the priority of the transmit interrupt */
    Ifx_Priority                     erPriority;                       /**< \brief Specifies the priority of the error interrupt */
    Ifx_Priority                     ptPriority;                       /**< \brief Specifies the priority of the phase transition interrupt */
    IfxSrc_Tos                       isrProvider;                      /**< \brief Specifies the handler of the interrupts */
    Ifx_SizeT                        bufferSize;                       /**< \brief Specifies the number of channels that can be buffered. If 0, buffering is disabled */
    void                            *buffer;                           /**< \brief Specifies the buffer location.The buffer parameter must point on a free memory location where the
                                                                        *          buffer object will be initialised. The Size of this area must be at least
                                                                        *          equals to "Size + sizeof(Ifx_Fifo) + 8",
                                                                        *          with "Size=config->bufferSize * Ifx_AlignOn32(sizeof(Spi_Ch*))". Not tacking
                                                                        *          this in account may result in unpredictable behaviour. */
    float32                          maximumBaudrate;                  /**< \brief Maximum baudrate used by the channels, this value is used to optimise the SPI internal clock */
    Ifx_QSPI                        *qspi;                             /**< \brief Pointer to QSPI module registers */
    boolean                          allowSleepMode;                   /**< \brief Specifies module sleep mode. Range: TRUE if sleep mode enable, FALSE if sleep mode disable. */
    boolean                          pauseOnBaudrateSpikeErrors;       /**< \brief Specifies module pause on baudrate or spike errors. Range: TRUE baud rate and spike error in slave mode enable, FALSE baud rate and spike error in slave mode disable. */
    IfxQspi_PauseRunTransition       pauseRunTransition;               /**< \brief Specifies module run or pause mode */
    IfxQspi_TxFifoInt                txFifoThreshold;                  /**< \brief Specifies the TXFIFO interrupt threshold */
    IfxQspi_RxFifoInt                rxFifoThreshold;                  /**< \brief Specifies the RXFIFO interrupt threshold */
    IFX_CONST IfxQspi_SpiSlave_Pins *pins;                             /**< \brief Config. structure for QSPI Slave pins (P Pins in LVDS mode when useLvds is TRUE) */
    IFX_CONST IfxQspi_SpiSlave_Pins *pinsN;                            /**< \brief Config. structure for QSPI Slave N pins in LVDS mode  when useLvds is TRUE. This should be NULL when useLvds is FALSE. */
    IfxQspi_SpiSlave_Protocol        protocol;                         /**< \brief structure for QSPI Slave protocol parameters */
    IfxQspi_SpiSlave_DmaConfig       dma;                              /**< \brief Dma configuration */
    IfxQspi_FifoMode                 txFifoMode;                       /**< \brief Specifies the transfer FIFO mode. */
    IfxQspi_FifoMode                 rxFifoMode;                       /**< \brief Specifies the receive FIFO mode */
    boolean 						 phaseTransition1Enable;           /**< \brief Specifies the enable/disable state of PT1 interrupt */
    IfxQspi_PhaseTransitionEvent     phaseTransition1Event;            /**< \brief Specifies the event for which PT1 interrupt is to be triggered */
    boolean 						 phaseTransition2Enable;           /**< \brief Specifies the enable/disable state of PT1 interrupt */
    IfxQspi_PhaseTransitionEvent     phaseTransition2Event;            /**< \brief Specifies the event for which PT2 interrupt is to be triggered */
    boolean                          useLvds;                          /**< \brief enables the configuration and use of LVDS pins */
} IfxQspi_SpiSlave_Config;

/** \} */

/** \addtogroup IfxLld_Qspi_SpiSlave_Module
 * \{ */

/******************************************************************************/
/*-------------------------Global Function Prototypes-------------------------*/
/******************************************************************************/

/**
 * \brief Initializes the QSPI Slave module with the provided configuration.
 *
 * \param[inout] handle  Pointer to the QSPI Slave module handle.
 * \param[in]    config  Pointer to the QSPI Slave configuration structure.
 *
 * \retval None
 *
 * Usage example: see \ref IfxLld_Qspi_SpiSlave_Usage
 *
 */
IFX_EXTERN void IfxQspi_SpiSlave_initModule(IfxQspi_SpiSlave *handle, const IfxQspi_SpiSlave_Config *config);

/**
 * \brief Initializes the SPI Slave module configuration structure with default values.
 *
 * \param[inout] config Pointer to the QSPI Slave configuration structure.
 * \param[in]    qspi   Pointer to the QSPI module registers.
 *
 * \retval None
 *
 * Usage example: see \ref IfxLld_Qspi_SpiSlave_Usage
 *
 */
IFX_EXTERN void IfxQspi_SpiSlave_initModuleConfig(IfxQspi_SpiSlave_Config *config, Ifx_QSPI *qspi);

/** \} */

/** \addtogroup IfxLld_Qspi_SpiSlave_Com
 * \{ */

/******************************************************************************/
/*-------------------------Global Function Prototypes-------------------------*/
/******************************************************************************/

/**
 * \brief Exchanges data between source and destination in SPI slave mode.
 *
 * \param[inout] handle Pointer to the QSPI Slave module handle.
 * \param[in]    src    Pointer to the source data to be transmitted. Can be NULL if no data is to be transmitted (receive only).
 * \param[out]   dest   Pointer to the destination where received data will be stored. Can be NULL if no data is to be received (transmit only).
 * \param[in]    count  Number of data items to exchange. Should be a positive value.
 *
 * \retval IfxQspi_Status Success or error status from the exchange operation. Range: \ref IfxQspi_Status.
 *
 * Usage example: see \ref IfxLld_Qspi_SpiSlave_Usage
 *
 */
IFX_EXTERN IfxQspi_Status IfxQspi_SpiSlave_exchange(IfxQspi_SpiSlave *handle, const void *src, void *dest, Ifx_SizeT count);

/**
 * \brief Gets the current transmission status of the SPI slave module.
 *
 * \param[in] handle Pointer to the QSPI Slave module handle.
 *
 * \retval IfxQspi_Status The current transmission status. Range: \ref IfxQspi_Status.
 *
 *  Usage example: see \ref IfxLld_Qspi_SpiSlave_Usage
 *
 */
IFX_EXTERN IfxQspi_Status IfxQspi_SpiSlave_getStatus(IfxQspi_SpiSlave *handle);

/** \} */

/** \addtogroup IfxLld_Qspi_SpiSlave_InterruptFunctions
 * \{ */

/******************************************************************************/
/*-------------------------Global Function Prototypes-------------------------*/
/******************************************************************************/

/**
 * \brief Interrupt service routine handling DMA receive events for the QSPI slave module.
 *
 * \param[inout] qspiHandle Pointer to the QSPI Slave module handle.
 *
 * \retval None
 *
 */
IFX_EXTERN void IfxQspi_SpiSlave_isrDmaReceive(IfxQspi_SpiSlave *qspiHandle);

/**
 * \brief Interrupt service routine for handling DMA-based transmit operations in SPI slave mode.
 *
 * \param[in] qspiHandle Pointer to the QSPI Slave module handle.
 *
 * \retval None
 * 
 */
IFX_EXTERN void IfxQspi_SpiSlave_isrDmaTransmit(IfxQspi_SpiSlave *qspiHandle);

/**
 * \brief Handles error interrupts for the QSPI slave module.
 *
 * \param[inout] handle Pointer to the QSPI Slave module handle.
 *
 * \retval None
 * 
 */
IFX_EXTERN void IfxQspi_SpiSlave_isrError(IfxQspi_SpiSlave *handle);

/** \brief Get the status of a particular error.
 *  Note: This function should be called only after calling the IfxQspi_SpiSlave_isrError().
 *
 * \param[inout] handle Module handle.
 * \param[in]    error  Module handle. Range: \ref IfxQspi_Error.
 *
 * \retval Returns the error status. Range 0 or 1.
 */
boolean IfxQspi_SpiSlave_isError(IfxQspi_SpiSlave *handle, IfxQspi_Error error);

/**
 * \brief Handles the receive interrupt for the QSPI slave module.
 *
 * \param[inout] handle Pointer to the QSPI Slave module handle.
 *
 * \retval None
 *
 */
IFX_EXTERN void IfxQspi_SpiSlave_isrReceive(IfxQspi_SpiSlave *handle);

/**
 * \brief Handles the transmit interrupt for the QSPI slave module.
 * 
 * \param[in] handle Pointer to the QSPI Slave module handle.
 *
 * \retval None
 *
 */
IFX_EXTERN void IfxQspi_SpiSlave_isrTransmit(IfxQspi_SpiSlave *handle);

/** \} */

/** \addtogroup IfxLld_Qspi_SpiSlave_DirectFifo
 * \{ */

/******************************************************************************/
/*-------------------------Inline Function Prototypes-------------------------*/
/******************************************************************************/

/**
 * \brief Reads data or status from the Receive FIFO (RxFIFO) of the SPI Slave module.
 *
 * \param[in] handle Pointer to the QSPI Slave module handle.
 *
 * \retval uint32 The data or status value read from the RxFIFO. Range: 0 to 0xFFFF FFFF.
 *
 */
IFX_INLINE uint32 IfxQspi_SpiSlave_readReceiveFifo(IfxQspi_SpiSlave *handle);

/**
 * \brief Writes data to the transmit FIFO for SPI slave communication.
 *
 * \param[inout] handle Pointer to the QSPI Slave module handle.
 * \param[in]    data   Data to be written to the Tx FIFO. Range: 0 to 0xFFFF FFFF.
 *
 * \retval None
 *
 */
IFX_INLINE void IfxQspi_SpiSlave_writeTransmitFifo(IfxQspi_SpiSlave *handle, uint32 data);

/**
 * \brief Initializes the pins for SPI slave mode operation based on the provided pin configuration.
 *
 * \param[in] pins Pointer to the pin configuration structure that contains pin assignments and their respective modes for SPI slave operation.
 *
 * \retval None
 *
 */
IFX_EXTERN void IfxQspi_SpiSlave_initPin(const IfxQspi_SpiSlave_Pins *pins);

/**
 * \brief Initializes the interrupt configuration for the QSPI slave module.
 * 
 * \param[inout] qspiSFR Pointer to the QSPI module registers.
 * \param[in]    config  Pointer to the configuration structure containing interrupt priorities, buffer settings, and other module-specific parameters.
 *
 * \retval None
 * 
 */
IFX_EXTERN void IfxQspi_SpiSlave_initInterrupt(Ifx_QSPI *qspiSFR, const IfxQspi_SpiSlave_Config *config);

/** \brief Initialize the pins for the spi in slave mode
 * \param[in] pins pointer to the pin configuration table
 * \retval None
 */
IFX_EXTERN void IfxQspi_SpiSlave_initLvdsPin(const IfxQspi_SpiSlave_Pins *pins);

/** \} */

/******************************************************************************/
/*---------------------Inline Function Implementations------------------------*/
/******************************************************************************/

IFX_INLINE uint32 IfxQspi_SpiSlave_readReceiveFifo(IfxQspi_SpiSlave *handle)
{
    Ifx_QSPI *qspiSFR = handle->qspi;
    uint32    data    = IfxQspi_readReceiveFifo(qspiSFR);
    return data;
}


IFX_INLINE void IfxQspi_SpiSlave_writeTransmitFifo(IfxQspi_SpiSlave *handle, uint32 data)
{
    IfxQspi_writeTransmitFifo(handle->qspi, data);
}


#endif /* IFXQSPI_SPISLAVE_H */
