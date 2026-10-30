/**
 * \file IfxGeth_Eth.h
 * \brief GETH ETH details
 * \ingroup IfxLld_Geth
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
 *
 * \defgroup IfxLld_Geth_Eth_Usage How to use the Geth Eth Interface driver?
 * \ingroup IfxLld_Geth
 *
 * In the following sections it will be described, how to integrate the driver into the application framework.
 *
 * \section IfxLld_Geth_Eth_Preparation Preparation
 * \subsection IfxLld_Geth_Eth_Include Include Files
 *
 * Include following header file into your C code:
 * \code
 * #include <Geth/Eth/IfxGeth_Eth.h>
 * \endcode
 *
 * \subsection IfxLld_Geth_Eth_Variables Variables
 *
 * Declare the Geth handle and the Data buffers as global variables in your C code:
 *
 * Note: MAC addds 4 bytes FCS at the end of each packet which will be reflected in RX Buffer.
 * If the frame size is equal to buffer size then Rx buffer declaration should be as below
 * \code
 * uint8 channel0RxBuffer1[IFXGETH_MAX_RX_BUFFER_SIZE+4];
 * \endcode
 *
 *
 * \code
 * // used globally
 * IfxGeth_Eth geth;
 *
 * #define IFXGETH_MAX_TX_DESCRIPTORS 4
 * #define IFXGETH_MAX_RX_DESCRIPTORS 4
 *
 * #define IFXGETH_MAX_TX_BUFFER_SIZE 256 // bytes
 * #define IFXGETH_MAX_RX_BUFFER_SIZE 256 // bytes
 * #define IFXGETH_HEADER_LENGTH 14 // words
 *
 * uint8 channel0TxBuffer1[IFXGETH_MAX_TX_BUFFER_SIZE];
 * uint8 channel0RxBuffer1[IFXGETH_MAX_RX_BUFFER_SIZE];
 *
 * const uint8 myMacAddress[6] = {0x00, 0x11, 0x22, 0x33, 0x44, 0x55};
 * \endcode
 *
 * \subsection IfxLld_Geth_Eth_Init Module Initialisation
 *
 * The module initialisation can be done in the same function. Here an example:
 * \code
 * // create module config
 * IfxGeth_Eth_Config config;
 * // Geth instance index
 * IfxGeth_Index gethInst;
 *
 * // Initialise configuration of module
 * IfxGeth_Eth_initModuleConfig(&config, &MODULE_GETH);
 *
 * // Get the Geth instance from Module address
 * gethInst = IfxGeth_getIndex(geth[geth_inst].gethSFR);
 *
 * config.phyInterfaceMode = IfxGeth_PhyInterfaceMode_rmii;
 *
 * // MAC core configuration
 * config.macConfig.lineSpeed = IfxGeth_LineSpeed_100Mbps;
 * config.macConfig.loopbackMode = IfxGeth_LoopbackMode_disable;
 * config.macConfig.macAddress[0] = myMacAddress[0];
 * config.macConfig.macAddress[1] = myMacAddress[1];
 * config.macConfig.macAddress[2] = myMacAddress[2];
 * config.macConfig.macAddress[3] = myMacAddress[3];
 * config.macConfig.macAddress[4] = myMacAddress[4];
 * config.macConfig.macAddress[5] = myMacAddress[5];
 *
 * // MTL configuration
 * config.mtlConfig.numOfTxQueues                =    1;
 * config.mtlConfig.numOfRxQueues                =    1;
 * config.mtlConfig.txQueueConfig[0].txQueueSize                  =    IfxGeth_QueueSize_256Bytes;
 * config.mtlConfig.rxQueueConfig[0].rxQueueSize                  =    IfxGeth_QueueSize_256Bytes;
 * config.mtlConfig.rxQueueConfig[0].rxDmaChannelMap        =    IfxEth_RxDmaChannel_0;
 *
 * config.dmaConfig.numOfTxChannels = 1;
 * config.dmaConfig.numOfRxChannels = 1;
 * config.dmaConfig.txChannel[0].channelId = IfxGeth_TxDmaChannel_0;
 * config.dmaConfig.txChannel[0].txDescrList = &IfxGeth_txDescrList[gethInst][0]; //Initialise tx desc list for the Geth instance
 * config.dmaConfig.txChannel[0].txBuffer1StartAddress = &channel0TxBuffer1[0]; // user buffer
 * config.dmaConfig.txChannel[0].txBuffer1Size = IFXGETH_MAX_TX_BUFFER_SIZE; // used to calculate the next descriptor  buffer offset
 *
 * config.dmaConfig.rxChannel[0].channelId = IfxGeth_RxDmaChannel_0;
 * config.dmaConfig.rxChannel[0].rxDescrList = &IfxGeth_rxDescrList[gethInst][0]; //Initialise rx desc list for the Geth instance
 * config.dmaConfig.rxChannel[0].rxBuffer1StartAddress = &channel0RxBuffer1[0]; // user buffer
 * config.dmaConfig.rxChannel[0].rxBuffer1Size = IFXGETH_MAX_RX_BUFFER_SIZE; // user defined variable
 *
 * config.dmaConfig.txInterrupt[0].channelId = IfxGeth_DmaChannel_0;
 * config.dmaConfig.txInterrupt[0].priority = 10;  // priority
 * config.dmaConfig.txInterrupt[0].provider = IfxSrc_Tos_cpu0;
 * config.dmaConfig.rxInterrupt[0].channelId = IfxGeth_DmaChannel_0;
 * config.dmaConfig.rxInterrupt[0].priority = 11;  // priority
 * config.dmaConfig.rxInterrupt[0].provider = IfxSrc_Tos_cpu0;
 *
 * // initialise themodule
 * IfxGeth_Eth_initModule(&geth, &config);
 *
 * // and enable transmitter/receiver
 * IfxGeth_Eth_startTransmitters(&geth, 1);
 * IfxGeth_Eth_startReceivers(&geth, 1);
 * \endcode
 *
 *
 * Note: Application should explicitly configure the system DMA, if system DMA is selected as the service provider for the interrupt.
 *
 * The ETH is ready for use now!
 *
 *
 * \section IfxLld_Geth_Eth_DataTransfers Data Transfers
 * \subsection  IfxLld_Geth_Eth_DataTransfers_Transmit Transmission
 * \code
 * uint32 payloadLength = 8; // 8 bytes
 * uint32 packetLength = IFXGETH_HEADER_LENGTH + payloadLength;
 *
 * // get free buffer
 * uint8 *pTxBuf = (uint8*) IfxGeth_Eth_waitTransmitBuffer(&geth, IfxGeth_TxDmaChannel_0);
 * // write the header
 * IfxGeth_Eth_writeHeader(&geth, pTxBuf, (uint8 *)myMacAddress, (uint8 *)myMacAddress, payloadLength);
 * // write the payload
 * uint32 i;
 * for(i = IFXGETH_HEADER_LENGTH; i < packetLength; ++i) {
 *     pTxBuf[i] = i - 13;
 * }
 *
 * // clear the TX interrupt status
 * IfxGeth_dma_clearInterruptFlag(geth->gethSFR, IfxGeth_DmaChannel_0,IfxGeth_DmaInterruptFlag_transmitInterrupt) ;
 *
 * IfxGeth_Eth_sendTransmitBuffer(&geth, packetLength, IfxGeth_TxDmaChannel_0);
 *
 * // wait until buffer has been transmitted
 * while( IfxGeth_dma_isInterruptFlagSet(geth->gethSFR, IfxGeth_DmaChannel_0, IfxGeth_DmaInterruptFlag_transmitInterrupt) == FALSE );
 *
 * // clear the TX interrupt status for the next interrupt to come
 * IfxGeth_dma_clearInterruptFlag(geth->gethSFR, IfxGeth_DmaChannel_0, IfxGeth_DmaInterruptFlag_transmitInterrupt) ;
 * \endcode
 *
 * \subsection  IfxLld_Geth_Eth_DataTransfers_Receive Receive
 * \code
 * // wait until data is been received
 * while(IfxGeth_Eth_isRxDataAvailable(&geth, IfxGeth_RxDmaChannel_0)!= TRUE);
 *
 * // wake up the receiver and get the recieve buffer
 * uint8 *pRxBuf = (uint8*)IfxGeth_Eth_getReceiveBuffer(&geth, IfxGeth_RxDmaChannel_0);
 *
 * // update the descreptor pointer for next packet
 * // Free the receive buffer, enabling it for the further reception
 * IfxGeth_Eth_freeReceiveBuffer(&geth, IfxGeth_RxDmaChannel_0);
 *
 * // data is available in pRxBuf
 * \endcode
 *
 * \subsection  IfxLld_Geth_Eth_DataTransfers_GiantFrame Giant Frame Transmission
 * Giant frames are supported by ethernet driver.
 * By default any frames greater than 1518 bytes are considered as giant frames in the code.
 * Giant frames of length 16376 bytes can be transmitted.
 * Giant frames of length 16380 bytes can be received by the MAC.(Including the 4 bytes of FCS added by transmitter MAC).
 *
 * The minimum allowed packet size above which the frame is indicated as giant frame is configured as below
 *
 * In the module initialisation section, make changes
 * \code
 * IfxGeth_Eth_Config config;
 *
 * IfxGeth_Eth_initModuleConfig(&config, &MODULE_GETH);
 * config.macConfig.maxPacketSize = 2000;
 *
 * \endcode
 *
 * The above code ensures that any frame of frame size greater than 2000 bytes are set as giant frame in Rx descriptor status.
 * Note: This frame size includes the 4 bytes FCS added by the transmitter MAC. Make sure that an Rx buffer has enough space to recieve the giant frame.
 *
 * There are 3 categories under which giant frames can be categoried:
 * 1. Frame size = 1518 -  If frame size greater than 1518 is marked as giant frame
 * 2. Frame size = 2000 -  If frame size greater than 2000 is marked as giant frame
 * 3. Frame size = 9018 -  If frame size greater than 9018 is marked as giant frame
 * 4. Any other value Frame size < 16380  - If packet size greater than configured bytes is marked as giant frame
 *
 * \subsection  IfxLld_Geth_Eth_Miilite MII lite mode
 *  MII lite mode is supported .
 *  Application should set the below pins to NULL_PTR to enable the MII lite mode.
 *  IfxGeth_Crs_In     *crs
 *  IfxGeth_Col_In     *col
 *  IfxGeth_Rxer_In    *rxEr
 *  IfxGeth_Txer_Out   *txEr;
 *
 * \defgroup IfxLld_Geth_Eth ETH
 * \ingroup IfxLld_Geth
 * \defgroup IfxLld_Geth_Eth_DataStructures DataStructures
 * \ingroup IfxLld_Geth_Eth
 * \defgroup IfxLld_Geth_Eth_MAC_Functions MAC Functions
 * \ingroup IfxLld_Geth_Eth
 * \defgroup IfxLld_Geth_Eth_Module_Functions Module Functions
 * \ingroup IfxLld_Geth_Eth
 * \defgroup IfxLld_Geth_Eth_MTL_Functions MTL Functions
 * \ingroup IfxLld_Geth_Eth
 * \defgroup IfxLld_Geth_Eth_DMA_Functions DMA Functions
 * \ingroup IfxLld_Geth_Eth
 * \defgroup IfxLld_Geth_Eth_Variables Variables
 * \ingroup IfxLld_Geth_Eth
 */

#ifndef IFXGETH_ET_H
#define IFXGETH_ET_H 1

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include "_Utilities/Ifx_Assert.h"
#include "Geth/Std/IfxGeth.h"
#include "_PinMap/IfxGeth_PinMap.h"
#include "IfxPort_reg.h"
#include "IfxPort_bf.h"

/******************************************************************************/
/*-----------------------------------Macros-----------------------------------*/
/******************************************************************************/

#define IFXGETH_QUEUE_INTERRUPT_MASK  ((1 << IfxGeth_MtlInterruptFlag_txQueueUnderflow) | (1 << IfxGeth_MtlInterruptFlag_averageBitsPerSlot) | (1 << IfxGeth_MtlInterruptFlag_rxQueueOverflow))
#define IFXGETH_TXQUEUE_INTERRUPT_VALUE (1 << (IfxGeth_MtlInterruptFlag_txQueueUnderflow + 8))
#define IFXGETH_RXQUEUE_INTERRUPT_VALUE (1 << (IfxGeth_MtlInterruptFlag_rxQueueOverflow + 8))

/******************************************************************************/
/*-----------------------------Data Structures--------------------------------*/
/******************************************************************************/

/** \addtogroup IfxLld_Geth_Eth_DataStructures
 * \{ */
/** \brief Interrupt configuration structure for DMA Channel
 */
typedef struct
{
    IfxGeth_DmaChannel channelId;       /**< \brief DMA channel ID (irrespective of TX and Rx for interrupt configuration) */
    Ifx_Priority       priority;        /**< \brief Interrupt service priority */
    IfxSrc_Tos         provider;        /**< \brief Interrupt service provider */
} IfxGeth_Eth_DmaInterruptConfig;

/** \brief Port pins for MII mode configuration
 */
typedef struct
{
    IfxGeth_Crs_In     *crs;         /**< \brief pointer to CRS input pin config */
    IfxGeth_Col_In     *col;         /**< \brief pointer to COL input pin config */
    IfxGeth_Txclk_In   *txClk;       /**< \brief Pointer to TXCLK input pin config */
    IfxGeth_Rxclk_In   *rxClk;       /**< \brief Pointer to RXCLK input pin config */
    IfxGeth_Rxdv_In    *rxDv;        /**< \brief Pointer to RXDV input pin config */
    IfxGeth_Rxer_In    *rxEr;        /**< \brief Pointer to RXER input pin config */
    IfxGeth_Rxd_In     *rxd0;        /**< \brief Pointer to RXD0 input pin config */
    IfxGeth_Rxd_In     *rxd1;        /**< \brief Pointer to RXD1 input pin config */
    IfxGeth_Rxd_In     *rxd2;        /**< \brief Pointer to RXD2 input pin config */
    IfxGeth_Rxd_In     *rxd3;        /**< \brief Pointer to RXD3 input pin config */
    IfxGeth_Txen_Out   *txEn;        /**< \brief Pointer to TXEN output pin config */
    IfxGeth_Txer_Out   *txEr;        /**< \brief Pointer to TXER output pin config */
    IfxGeth_Txd_Out    *txd0;        /**< \brief Pointer to TXD0 output pin config */
    IfxGeth_Txd_Out    *txd1;        /**< \brief Pointer to TXD1 output pin config */
    IfxGeth_Txd_Out    *txd2;        /**< \brief Pointer to TXD2 output pin config */
    IfxGeth_Txd_Out    *txd3;        /**< \brief Pointer to TXD3 output pin config */
    IfxGeth_Mdc_Out    *mdc;         /**< \brief Pointer to MDC output pin config */
    IfxGeth_Mdio_InOut *mdio;        /**< \brief Pointer to MDIO pin config */
} IfxGeth_Eth_MiiPins;

/** \brief Interrupt configuration structure for MTL block
 */
typedef struct
{
    IfxGeth_ServiceRequest serviceRequest;       /**< \brief Service Request node for MTL interrupt */
    Ifx_Priority           priority;             /**< \brief Interrupt service priority */
    IfxSrc_Tos             provider;             /**< \brief Interrupt service provider */
} IfxGeth_Eth_MtlInterruptConfig;

/** \brief Port pins for RGMII mode configuration
 */
typedef struct
{
    IfxGeth_Txclk_Out  *txClk;         /**< \brief Pointer to TXCLK input pin config */
    IfxGeth_Txd_Out    *txd0;          /**< \brief Pointer to TXD0 output pin config */
    IfxGeth_Txd_Out    *txd1;          /**< \brief Pointer to TXD1 output pin config */
    IfxGeth_Txd_Out    *txd2;          /**< \brief Pointer to TXD2 output pin config */
    IfxGeth_Txd_Out    *txd3;          /**< \brief Pointer to TXD3 output pin config */
    IfxGeth_Txctl_Out  *txCtl;         /**< \brief Pointer to TXCTL output pin config */
    IfxGeth_Rxclk_In   *rxClk;         /**< \brief Pointer to RXCLK input pin config */
    IfxGeth_Rxd_In     *rxd0;          /**< \brief Pointer to RXD0 input pin config */
    IfxGeth_Rxd_In     *rxd1;          /**< \brief Pointer to RXD1 input pin config */
    IfxGeth_Rxd_In     *rxd2;          /**< \brief Pointer to RXD2 input pin config */
    IfxGeth_Rxd_In     *rxd3;          /**< \brief Pointer to RXD3 input pin config */
    IfxGeth_Rxctl_In   *rxCtl;         /**< \brief Pointer to RXCTL input pin config */
    IfxGeth_Mdc_Out    *mdc;           /**< \brief Pointer to MDC output pin config */
    IfxGeth_Mdio_InOut *mdio;          /**< \brief Pointer to MDIO pin config */
    IfxGeth_Grefclk_In *grefClk;       /**< \brief Pointer to GREFCLK input pin config */
} IfxGeth_Eth_RgmiiPins;

/** \brief Port pins for RMII mode configuration
 */
typedef struct
{
    IfxGeth_Crsdv_In   *crsDiv;       /**< \brief pointer to CRSDIV input pin config */
    IfxGeth_Refclk_In  *refClk;       /**< \brief Pointer to REFCLK input pin config */
    IfxGeth_Rxd_In     *rxd0;         /**< \brief Pointer to RXD0 input pin config */
    IfxGeth_Rxd_In     *rxd1;         /**< \brief Pointer to RXD1 input pin config */
    IfxGeth_Mdio_InOut *mdio;         /**< \brief Pointer to MDIO pin config */
    IfxGeth_Txd_Out    *txd0;         /**< \brief Pointer to TXD0 output pin config */
    IfxGeth_Mdc_Out    *mdc;          /**< \brief Pointer to MDC output pin config */
    IfxGeth_Txd_Out    *txd1;         /**< \brief Pointer to TXD1 output pin config */
    IfxGeth_Txen_Out   *txEn;         /**< \brief Pointer to TXEN output pin config */
} IfxGeth_Eth_RmiiPins;

/** \brief Configuration sturcture for DMA rx channel
 */
typedef struct
{
    boolean                channelEnable;               /**< \brief Rx DMA channel Enable. Range: TRUE Enable Rx DMA channel, FLASE Disable Rx DMA channel */
    IfxGeth_RxDmaChannel   channelId;                   /**< \brief Rx DMA channel Index */
    IfxGeth_DmaBurstLength maxBurstLength;              /**< \brief Maximum burst length of the channel */
    IfxGeth_RxDescrList   *rxDescrList;                 /**< \brief pointer to RX descriptors RAM */
    uint32                *rxBuffer1StartAddress;       /**< \brief Start address of Rx Buffer 1 */
    uint16                 rxBuffer1Size;               /**< \brief Size of Rx Buffer 1. Range: 0 to 0x3FFF */
} IfxGeth_Eth_RxChannelConfig;

/** \brief Rx Queue Configuration
 */
typedef struct
{
    boolean              queueEnable;                           /**< \brief Rx Queue enable/disable field. Range: TRUE Enable Rx Queue,  FLASE Disable Rx Queue */
    boolean              storeAndForward;                       /**< \brief Receive Store and Forward Enable/Disable. Range: TRUE Enable store and forward, FLASE Disable store and forward */
    IfxGeth_QueueSize    rxQueueSize;                           /**< \brief Rx Queue size */
    boolean              forwardErrorPacket;                    /**< \brief Error Packet Forwarding Enable/Disable. Range: TRUE Enable Rx Forward Error packet, FLASE Disable Rx Forward Error packet */
    boolean              forwardUndersizedGoodPacket;           /**< \brief Undersized Good Packet Forwarding Enable/Disable. Range: TRUE Enable Rx Forward undersized good packet, FALSE Disable Rx Forward undersized good packet */
    boolean              daBasedDmaChannelEnabled;              /**< \brief DA-based DMA Channel Selection Enable/Disable. Range: TRUE Enable DA-based DMA Channel Selection, FALSE- Disable DA-based DMA Channel Selection */
    IfxGeth_RxDmaChannel rxDmaChannelMap;                       /**< \brief Mapped DMA Channel of Rx Queue */
    boolean              rxQueueOverflowInterruptEnabled;       /**< \brief Enable/Disable Rx Queue Overflow Interrupt. Range: TRUE Enable Rx Queue Overflow Interrupt, FALSE- Disable Rx Queue Overflow Interrupt */
} IfxGeth_Eth_RxQueueConfig;

/** \brief Configuration sturcture for DMA tx channel
 */
typedef struct
{
    boolean                channelEnable;               /**< \brief Tx DMA channel Enable. Range: TRUE Enable Tx DMA channel, FLASE Disable Tx DMA channel */
    IfxGeth_TxDmaChannel   channelId;                   /**< \brief Tx DMA channel Index */
    IfxGeth_DmaBurstLength maxBurstLength;              /**< \brief Maximum burst length of the channel */
    IfxGeth_TxDescrList   *txDescrList;                 /**< \brief pointer to TX descriptors RAM */
    uint32                *txBuffer1StartAddress;       /**< \brief Start address of Tx Buffer 1 */
    uint16                 txBuffer1Size;               /**< \brief Size of Tx Buffer 1. Range: 0 to 0x3FFF */
    boolean                enableOSF;                   /**< \brief Operate on Second Frame. Range: TRUE Enabled, FALSE Disabled */
} IfxGeth_Eth_TxChannelConfig;

/** \brief Tx Queue Configuration
 */
typedef struct
{
    boolean           queueEnable;                            /**< \brief Tx Queue enable/disable field. Range: TRUE Enable Tx Queue, FLASE Disable Tx Queue */
    boolean           storeAndForward;                        /**< \brief Transmit Store and Forward Enable/Disable. Range: TRUE- Enable store and forward, FLASE Disable store and forward */
    IfxGeth_QueueSize txQueueSize;                            /**< \brief Tx Queue size */
    boolean           txQueueUnderflowInterruptEnabled;       /**< \brief Enable/Disable Tx Queue Underflow Interrupt. Range: TRUE Enable Tx Queue Overflow Interrupt, FALSE- Disable Tx Queue Overflow Interrupt */
} IfxGeth_Eth_TxQueueConfig;

/** \} */

/** \addtogroup IfxLld_Geth_Eth_DataStructures
 * \{ */
/** \brief Configuration Structure for the DMA initialisation
 */
typedef struct
{
    uint32                         numOfTxChannels;                             /**< \brief Number of Tx Dma channels. Range: 1 to 4 */
    uint32                         numOfRxChannels;                             /**< \brief Number of Rx Dma channels. Range: 1 to 4 */
    boolean                        addressAlignedBeatsEnabled;                  /**< \brief Enable/Disable Address Aligned Beats. Range: TRUE Enable Address Aligned Beats, FALSE- Disable Address Aligned Beats */
    boolean                        fixedBurstEnabled;                           /**< \brief Enable/Disable Fixed Burst length. Range: TRUE Enable Fixed Burst length, FALSE Disable Fixed Burst length */
    boolean                        mixedBurstEnabled;                           /**< \brief Enable/Disable Mixed Burst length. Range: TRUE Enable Mixed Burst length, FALSE Disable Mixed Burst length */
    IfxGeth_Eth_TxChannelConfig    txChannel[IFXGETH_NUM_TX_CHANNELS];          /**< \brief Tx Channels configurations of selected Channels */
    IfxGeth_Eth_RxChannelConfig    rxChannel[IFXGETH_NUM_RX_CHANNELS];          /**< \brief Rx Channels configurations of selected Channels */
    IfxGeth_Eth_DmaInterruptConfig txInterrupt[IFXGETH_NUM_DMA_CHANNELS];       /**< \brief Transmit Interrupt configuration structure for DMA Channel */
    IfxGeth_Eth_DmaInterruptConfig rxInterrupt[IFXGETH_NUM_DMA_CHANNELS];       /**< \brief Receive Interrupt configuration structure for DMA Channel */
} IfxGeth_Eth_DmaConfig;

/** \brief Configuration Structure for the MAC initialisation
 */
typedef struct
{
    IfxGeth_DuplexMode   duplexMode;          /**< \brief Duplex Mode */
    IfxGeth_LineSpeed    lineSpeed;           /**< \brief Ethernet Line Speed */
    IfxGeth_LoopbackMode loopbackMode;        /**< \brief Loopback mode enable/disable */
    uint8                macAddress[6];       /**< \brief MAC address for the ethernet, should be unique in the network. Range: 0 to 0xFF */
    uint16               maxPacketSize;       /**< \brief Maximum size of the ethernet packet. Range: 0 to 0x3FFF */
} IfxGeth_Eth_MacConfig;

/** \brief Configuration Structure for the MTL initialisation
 */
typedef struct
{
    uint32                         numOfTxQueues;                        /**< \brief Number of Tx Queues, will also be used to enable the selected number of queues. Range: 1 to 4 */
    IfxGeth_TxSchedulingAlgorithm  txSchedulingAlgorithm;                /**< \brief Tx Scheduling Algorithm for Tx queues when no of queues are more than 1 */
    uint32                         numOfRxQueues;                        /**< \brief Number of Rx Queues. Range: 1 to 4 */
    IfxGeth_RxArbitrationAlgorithm rxArbitrationAlgorithm;               /**< \brief Rx Arbitration Algorithm for Rx queues when no of queues are more than 1 */
    IfxGeth_Eth_TxQueueConfig      txQueue[IFXGETH_NUM_TX_QUEUES];       /**< \brief Tx queue configurations of selected queues */
    IfxGeth_Eth_RxQueueConfig      rxQueue[IFXGETH_NUM_RX_QUEUES];       /**< \brief Rx queue configurations of selected queues */
    IfxGeth_Eth_MtlInterruptConfig interrupt;                            /**< \brief Interrupt configuration structure for MTL block */
} IfxGeth_Eth_MtlConfig;

/** \brief Configuration structure for pins
 */
typedef struct
{
    IFX_CONST IfxGeth_Eth_RmiiPins  *rmiiPins;        /**< \brief Structure for RMII pins */
    IFX_CONST IfxGeth_Eth_RgmiiPins *rgmiiPins;       /**< \brief Structure for RGMII pins */
    IFX_CONST IfxGeth_Eth_MiiPins   *miiPins;         /**< \brief Structure for MII pins */
} IfxGeth_Eth_PinConfig;

/** \brief Handle sturcture for DMA rx channel
 */
typedef struct
{
    IfxGeth_RxDmaChannel      channelId;         /**< \brief Rx DMA channel Index */
    IfxGeth_RxDescrList      *rxDescrList;       /**< \brief pointer to RX descriptors RAM */
    volatile IfxGeth_RxDescr *rxDescrPtr;        /**< \brief Pointer to Rx Descriptor (current descriptor) */
    uint32                    rxCount;           /**< \brief Number of frames received. Range: 0 to 0xFFFFFFFF */
} IfxGeth_Eth_RxChannel;

/** \brief handle sturcture for DMA tx channel
 */
typedef struct
{
    IfxGeth_TxDmaChannel      channelId;         /**< \brief Tx DMA channel Index */
    IfxGeth_TxDescrList      *txDescrList;       /**< \brief pointer to TX descriptors RAM */
    volatile IfxGeth_TxDescr *txDescrPtr;        /**< \brief Pointer to Tx Descriptor (current descriptor) */
    uint32                    txCount;           /**< \brief Number of frames transmitted. Range: 0 to 0xFFFFFFFF */
    uint16                    txBuf1Size;        /**< \brief configured tx buffer 1 size. Range: 0 to 0x3FFF */
} IfxGeth_Eth_TxChannel;

/** \} */

/** \addtogroup IfxLld_Geth_Eth_DataStructures
 * \{ */
/** \brief GETH driver Handle
 */
typedef struct
{
    Ifx_GETH             *gethSFR;                                  /**< \brief Pointer to GETH register base address */
    uint32                numOfTxChannels;                          /**< \brief Number of Tx Dma channels. Range: 1 to 4 */
    uint32                numOfRxChannels;                          /**< \brief Number of Rx Dma channels. Range: 1 to 4 */
    IfxGeth_Eth_TxChannel txChannel[IFXGETH_NUM_TX_CHANNELS];       /**< \brief Tx Channels handle of selected Channels */
    IfxGeth_Eth_RxChannel rxChannel[IFXGETH_NUM_RX_CHANNELS];       /**< \brief Rx Channels handle of selected Channels */
} IfxGeth_Eth;

/** \brief Configuration Structure for the Module initialisation
 */
typedef struct
{
    Ifx_GETH                *gethSFR;                  /**< \brief Pointer to GETH register base address */
    IfxGeth_PhyInterfaceMode phyInterfaceMode;         /**< \brief External Phy Interface Mode */
    IfxGeth_Eth_PinConfig    pins;                     /**< \brief COnfiguration structure for Pins */
    IfxGeth_Eth_MacConfig    mac;                      /**< \brief Configuration Structure for the the MAC initialisation */
    IfxGeth_Eth_MtlConfig    mtl;                      /**< \brief Configuration Structure for the MTL initialisation */
    IfxGeth_Eth_DmaConfig    dma;                      /**< \brief Configuration Structure for the DMA initialisation */
    uint8                    rgmiiTxSkewControl;       /**< \brief TX Clock delay control for RGMII Mode - TXCFG. Refer to SKEWCTL.B.TXCFG. Range: 0 to 0xF */
    uint8                    rgmiiRxSkewControl;       /**< \brief RX Clock delay control for RGMII Mode - RXCFG. Refer to SKEWCTL.B.RXCFG. Range: 0 to 0xF */
} IfxGeth_Eth_Config;

/** \} */

/** \brief Configuration Structure for TX Frame
 */
typedef struct
{
    IfxGeth_TxDmaChannel channelId;          /**< \brief Tx DMA channel Index */
    uint32               packetLength;       /**< \brief The length of the packet to be transmitted in bytes. Range: 0 to 0x3FFF */
} IfxGeth_Eth_FrameConfig;

/** \addtogroup IfxLld_Geth_Eth_MAC_Functions
 * \{ */

/******************************************************************************/
/*-------------------------Global Function Prototypes-------------------------*/
/******************************************************************************/

/**
 * \brief Configures the MAC core with specified settings.
 *
 * \param[inout] geth      Pointer to the GETH driver handle.
 * \param[in]    macConfig Pointer to the MAC configuration structure.
 *
 * \retval None
 *
 * \code
 * // IfxGeth_Eth geth; // assumed to be defined globally
 *
 * IfxGeth_Eth_MacConfig macConfig;
 * macConfig.duplexMode = IfxGeth_DuplexMode_fullDuplex;
 * macConfig.lineSpeed = IfxGeth_LineSpeed_100Mbps;
 * macConfig.loopbackMode = IfxGeth_LoopbackMode_disable;
 * macConfig.macAddress =  {0x00, 0x11, 0x22, 0x33, 0x44, 0x55};
 *
 * IfxGeth_Eth_configureMacCore(&geth, &macConfig);
 * \endcode
 *
 */
IFX_EXTERN void IfxGeth_Eth_configureMacCore(IfxGeth_Eth *geth, IfxGeth_Eth_MacConfig *macConfig);

/** \} */

/** \addtogroup IfxLld_Geth_Eth_Module_Functions
 * \{ */

/******************************************************************************/
/*-------------------------Inline Function Prototypes-------------------------*/
/******************************************************************************/

/**
 * \brief Waits for a transmit buffer to become available for use.
 *
 * \param[in] geth      Pointer to the GETH driver handle.
 * \param[in] channelId The TX DMA channel ID.
 *                      Range: \ref IfxGeth_TxDmaChannel
 *
 * \retval Non NULL_PTR TX buffer is available at the address pointed by the returned value.
 *         NULL_PTR TX buffer is busy.
 *
 * \code
 *
 * // get free buffer
 * uint8 *pTxBuf = (uint8*) IfxGeth_Eth_waitTransmitBuffer(&geth, IfxGeth_TxDmaChannel_0);
 * \endcode
 *
 */
IFX_INLINE void *IfxGeth_Eth_waitTransmitBuffer(IfxGeth_Eth *geth, IfxGeth_TxDmaChannel channelId);

/******************************************************************************/
/*-------------------------Global Function Prototypes-------------------------*/
/******************************************************************************/

/**
 * \brief Retrieves the receive buffer for a specified RX DMA channel.
 *
 * \note: IfxEth_freeReceiveBuffer() shall be called after the data from the RX buffer has been processed
 *
 * \param[inout] geth      Handle to the GETH driver instance, containing configuration and state information.
 * \param[in]    channelId The RX DMA channel identifier.
 *                         Range: \ref IfxGeth_RxDmaChannel
 *
 * \retval NULL_PTR No frame has been received in the buffer.
 *         !NULL_PTR Frame has been received, and the pointer to the buffer is returned.
 *
 * \code
 * // IfxGeth_Eth geth; // assumed to be defined globally
 *
 * uint8 *pRxBuf = (uint8*)IfxGeth_Eth_getReceiveBuffer(&geth, IfxGeth_RxDmaChannel_0);
 * \endcode
 *
 */
IFX_EXTERN void *IfxGeth_Eth_getReceiveBuffer(IfxGeth_Eth *geth, IfxGeth_RxDmaChannel channelId);

/**
 * \brief Retrieves a pointer to a free transmit buffer for the specified DMA channel.
 *
 * \param[in] geth      Pointer to the GETH driver handle.
 * \param[in] channelId The TX DMA channel ID.
 *                      Range: \ref IfxGeth_TxDmaChannel
 *
 * \retval NULL_PTR No free transmit buffer is available for the specified channel.
 *         !NULL_PTR A pointer to a free transmit buffer is available for use.
 */
IFX_EXTERN void *IfxGeth_Eth_getTransmitBuffer(IfxGeth_Eth *geth, IfxGeth_TxDmaChannel channelId);

/**
 * \brief Initialises the GETH Module with the provided configuration.
 *
 * \param[inout] geth    Pointer to the GETH driver handle structure.
 * \param[in]    config  Configuration Structure for the Module initialization.
 *
 * \retval None
 *
 * \code
 * // IfxGeth_Eth geth; // assumed to be defined globally
 * IfxGeth_Eth_Config config;
 *
 * IfxGeth_Eth_initModuleConfig(&config, &MODULE_GETH);
 * IfxGeth_Eth_initModule(&geth, &config);
 * \endcode
 *
 */
IFX_EXTERN void IfxGeth_Eth_initModule(IfxGeth_Eth *geth, IfxGeth_Eth_Config *config);

/**
 * \brief Initializes the Ethernet module configuration structure with default values.
 *
 * \param[inout] config  Pointer to configuration structure to be initialized.
 * \param[in]    gethSFR Pointer to the GETH register base address.
 *
 * \retval None
 *
 * \code
 * IfxGeth_Eth_Config config;
 * IfxGeth_Eth_initModuleConfig(&config, &MODULE_GETH);
 * \endcode
 *
 */
IFX_EXTERN void IfxGeth_Eth_initModuleConfig(IfxGeth_Eth_Config *config, Ifx_GETH *gethSFR);

/**
 * \brief Configures the MII mode input pins for the Ethernet controller.
 *
 * \param[inout] geth    Pointer to the GETH driver handle structure.
 * \param[in]    miiPins Pointer to a structure containing configurations for MII-related input and output pins.
 *
 * \retval None
 */
IFX_EXTERN void IfxGeth_Eth_setupMiiInputPins(IfxGeth_Eth *geth, const IfxGeth_Eth_MiiPins *miiPins);

/**
 * \brief Configures the MII mode output pins for the GETH driver.
 *
 * \param[in] geth    Pointer to the GETH driver handle structure.
 * \param[in] miiPins Pointer to a structure containing configurations for MII-related input and output pins.
 *
 * \retval None
 */
IFX_EXTERN void IfxGeth_Eth_setupMiiOutputPins(IfxGeth_Eth *geth, const IfxGeth_Eth_MiiPins *miiPins);

/**
 * \brief Configures and initializes the RGMII mode input pins for Ethernet operation.
 *
 * \param[inout] geth      Pointer to the GETH driver handle structure.
 * \param[in]    rgmiiPins RGMII pin configuration structure containing pointers to input pin configurations.
 *
 * \retval None
 */
IFX_EXTERN void IfxGeth_Eth_setupRgmiiInputPins(IfxGeth_Eth *geth, const IfxGeth_Eth_RgmiiPins *rgmiiPins);

/**
 * \brief Configures the output pins for RGMII mode operation.
 *
 * \param[in] geth      Pointer to the GETH driver handle structure.
 * \param[in] rgmiiPins RGMII pin configuration structure containing pointers to output pin configurations.
 *
 * \retval None
 */
IFX_EXTERN void IfxGeth_Eth_setupRgmiiOutputPins(IfxGeth_Eth *geth, const IfxGeth_Eth_RgmiiPins *rgmiiPins);

/**
 * \brief Configures the input pins for RMII mode operation.
 *
 * \param[inout] geth     Pointer to the GETH driver handle structure.
 * \param[in]    rmiiPins Pointer to Rmii pin configurations.
 *
 * \retval None
 */
IFX_EXTERN void IfxGeth_Eth_setupRmiiInputPins(IfxGeth_Eth *geth, const IfxGeth_Eth_RmiiPins *rmiiPins);

/**
 * \brief Configures the output pins for RMII mode operation.
 *
 * \param[in] geth     Pointer to the GETH driver handle structure.
 * \param[in] rmiiPins Pointer to Rmii pin configurations.
 *
 * \retval None
 */
IFX_EXTERN void IfxGeth_Eth_setupRmiiOutputPins(IfxGeth_Eth *geth, const IfxGeth_Eth_RmiiPins *rmiiPins);

/**
 * \brief Constructs and writes an Ethernet header into the provided transmit buffer.
 *
 * \param[in]    geth                Pointer to the GETH driver handle structure.
 * \param[inout] txBuffer            Pointer to the transmit buffer where the Ethernet header will be written.
 * \param[in]    destinationAddress  Pointer to destination address.
 * \param[in]    sourceAddress       Pointer to source address.
 * \param[in]    payloadLength       The length of the payload that follows the header.
 *                                   Range: 0 to 0xFFFF
 *
 * \retval None
 *
 * \code
 * // IfxGeth_Eth geth; // assumed to be defined globally
 * //const uint8 myMacAddress[6] = {0x00, 0x11, 0x22, 0x33, 0x44, 0x55};   // assumed to be defined globally
 * //#define IFXGETH_MAX_TX_BUFFER_SIZE 256   // assumed to be defined globally
 * //uint8 txBuffer1[IFXGETH_MAX_TX_BUFFER_SIZE];  // assumed to be defined globally
 *
 * // get free buffer
 * uint8 *pTxBuf = (uint8*) IfxGeth_Eth_waitTransmitBuffer(&geth, IfxGeth_TxDmaChannel_0);
 *
 * IfxGeth_Eth_writeHeader(&geth, &pTxBuf, (uint8 *)myMacAddress, (uint8 *)myMacAddress, payloadLength);
 * \endcode
 *
 */
IFX_EXTERN void IfxGeth_Eth_writeHeader(IfxGeth_Eth *geth, uint8 *txBuffer, uint8 *destinationAddress, uint8 *sourceAddress, uint32 payloadLength);

/** \} */

/** \addtogroup IfxLld_Geth_Eth_MTL_Functions
 * \{ */

/******************************************************************************/
/*-------------------------Global Function Prototypes-------------------------*/
/******************************************************************************/

 /**
 * \brief Configures the MTL with specified parameters.
 *
 * \param[inout] geth        Pointer to the GETH driver handle structure.
 * \param[in]    mtlConfig   Pointer to the MTL configuration structure.
 *
 * \retval None
 *
 * \code
 * // IfxGeth_Eth geth; // assumed to be defined globally
 *
 * IfxGeth_Eth_MtlConfig mtlConfig;
 *
 * mtlConfig.numOfTxQueues                =    1;
 * mtlConfig.txSchedulingAlgorithm        =    IfxGeth_TxSchedulingAlgorithm_wrr;
 * mtlConfig.numOfRxQueues                =    1;
 * mtlConfig.rxArbitrationAlgorithm       =    IfxGeth_RxArbitrationAlgorithm_sp;
 * mtlConfig.txQueueConfig[0].storeAndForward              =    FALSE;
 * mtlConfig.txQueueConfig[0].txQueueSize                  =    IfxGeth_QueueSize_256Bytes;
 * mtlConfig.txQueueConfig[0].txQueueUnderflowInterruptEnabled = FLASE;  // enable if required
 *
 * mtlConfig.rxQueueConfig[0].storeAndForward              =    FALSE;
 * mtlConfig.rxQueueConfig[0].rxQueueSize                  =    IfxGeth_QueueSize_256Bytes;
 * mtlConfig.rxQueueConfig[0].forwardErrorPacket           =    FALSE;
 * mtlConfig.rxQueueConfig[0].forwardUndersizeedGoodPacket    =    FALSE;
 * mtlConfig.rxQueueConfig[0].daBasedDmaChannelEnabled     =    FALSE;
 * mtlConfig.rxQueueConfig[0].rxDmaChannelMap              =    IfxEth_RxDmaChannel_0;
 * mtlConfig.rxQueueConfig[0].rxQueueOverflowInterruptEnabled = FALSE; // enable if required
 *
 * mtlConfig.interrupt.serviceRequest = IfxGeth_ServiceRequest_1;
 * mtlConfig.interrupt.priority = 0; // choose priority
 * mtlConfig.interrupt.provider = IfxSrc_Tos_cpu0;
 *
 * IfxGeth_Eth_configureMTL(&geth, &mtlConfig);
 * \endcode
 *
 */
IFX_EXTERN void IfxGeth_Eth_configureMTL(IfxGeth_Eth *geth, IfxGeth_Eth_MtlConfig *mtlConfig);

/** \} */

/** \addtogroup IfxLld_Geth_Eth_DMA_Functions
 * \{ */

/******************************************************************************/
/*-------------------------Inline Function Prototypes-------------------------*/
/******************************************************************************/

/**
 * \brief Returns the pointer to the current RX descriptor for the specified channel.
 *
 * \param[in] geth      Pointer to the GETH driver handle structure.
 * \param[in] channelId The RX DMA channel identifier.
 *                      Range: \ref IfxGeth_RxDmaChannel
 *
 * \retval  IfxGeth_RxDescr* Pointer to base RX descriptor in the list.
 *
 * \code
 * // IfxGeth_Eth geth; // assumed to be defined globally
 *
 * IfxGeth_RxDescr *descr = IfxGeth_Eth_getActualRxDescriptor(&geth, IfxGeth_RxDmaChannel_0);
 * \endcode
 *
 */
IFX_INLINE volatile IfxGeth_RxDescr *IfxGeth_Eth_getActualRxDescriptor(IfxGeth_Eth *geth, IfxGeth_RxDmaChannel channelId);

/**
 * \brief Returns the pointer to the current TX descriptor for the specified DMA channel.
 *
 * \param[in] geth      Pointer to the GETH driver handle structure.
 * \param[in] channelId The TX DMA channel ID.
 *                      Range: \ref IfxGeth_TxDmaChannel
 *
 * \retval IfxGeth_TxDescr* Pointer to base TX descriptor in the list.
 *
 * \code
 * // IfxGeth_Eth geth; // assumed to be defined globally
 *
 * IfxGeth_TxDescr *descr = IfxGeth_Eth_getActualTxDescriptor(&geth, IfxGeth_TxDmaChannel_0);
 * \endcode
 *
 */
IFX_INLINE volatile IfxGeth_TxDescr *IfxGeth_Eth_getActualTxDescriptor(IfxGeth_Eth *geth, IfxGeth_TxDmaChannel channelId);

/**
 * \brief Checks whether one or more RX data is available for the specified channel.
 *
 * \param[in] geth      Pointer to the GETH driver handle structure.
 * \param[in] channelId The RX DMA channel identifier.
 *                      Range: \ref IfxGeth_RxDmaChannel
 *
 * \retval TRUE  If one or more RX data is available in the specified channel.
 *         FALSE If no RX data is available in the specified channel.
 *
 * \code
 * // IfxGeth_Eth geth; // assumed to be defined globally
 *
 * boolean status = IfxGeth_Eth_isRxDataAvailable(&geth, IfxGeth_RxDmaChannel_0);
 * \endcode
 *
 */
IFX_INLINE boolean IfxGeth_Eth_isRxDataAvailable(IfxGeth_Eth *geth, IfxGeth_RxDmaChannel channelId);

/******************************************************************************/
/*-------------------------Global Function Prototypes-------------------------*/
/******************************************************************************/

/**
 * \brief Configures the DMA for the GETH driver with the specified configuration.
 *
 * \param[inout] geth      Pointer to the GETH driver handle structure.
 * \param[in]    dmaConfig Configuration Structure for the DMA initialization.
 *
 * \retval None
 *
 *
 * \code
 * // IfxGeth_Eth geth; // assumed to be defined globally
 * IfxGeth_Eth_DmaConfig dmaConfig;
 * dmaConfig.numOfTxChannels = 1;
 * dmaConfig.numOfRxChannels = 1;
 *
 * dmaConfig.txChannel[0].channelId = IfxGeth_TxDmaChannel_0;
 * dmaConfig.txChannel[0].txDescrList = &IfxGeth_txDescrList[0];
 * dmaConfig.txChannel[0].txBuffer1StartAddress = &txBuffer[0][0]; //  user buffer
 * dmaConfig.txChannel[0].txBuffer1Size = TX_BUFFER1_SIZE; // user defined variable
 *
 * dmaConfig.rxChannel[0].channelId = IfxGeth_RxDmaChannel_0;
 * dmaConfig.rxChannel[0].rxDescrList = &IfxGeth_rxDescrList[0];
 * dmaConfig.rxChannel[0].rxBuffer1StartAddress = &rxBuffer[0][0]; // user buffer
 * dmaConfig.rxChannel[0].rxBuffer1Size = RX_BUFFER1_SIZE; // user defined variable
 *
 * dmaConfig.txInterrupt[0].channelId = IfxGeth_DmaChannel_0;
 * dmaConfig.txInterrupt[0].priority = 0;  // choose priority
 * dmaConfig.txInterrupt[0].provider = IfxSrc_Tos_cpu0;
 *
 * dmaConfig.rxInterrupt[0].channelId = IfxGeth_DmaChannel_0;
 * dmaConfig.rxInterrupt[0].priority = 0;  // choose priority
 * dmaConfig.rxInterrupt[0].provider = IfxSrc_Tos_cpu0;
 *
 * IfxGeth_Eth_configureDMA(&geth, &dmaConfig);
 * \endcode
 *
 */
IFX_EXTERN void IfxGeth_Eth_configureDMA(IfxGeth_Eth *geth, IfxGeth_Eth_DmaConfig *dmaConfig);

/**
 * \brief Initializes the Rx descriptors of a single channel.
 *
 * \param[inout] geth   Pointer to the GETH driver handle structure.
 * \param[in]    config Pointer to the Rx channel configuration structure.
 *
 * \retval None
 */
IFX_EXTERN void IfxGeth_Eth_initReceiveDescriptors(IfxGeth_Eth *geth, const IfxGeth_Eth_RxChannelConfig *config);

/**
 * \brief Initializes the transmit descriptors for a single channel.
 *
 * \param[inout] geth   Pointer to the GETH driver handle structure.
 * \param[in]    config Pointer to the Tx channel configuration structure.
 *
 * \retval None
 */
IFX_EXTERN void IfxGeth_Eth_initTransmitDescriptors(IfxGeth_Eth *geth, const IfxGeth_Eth_TxChannelConfig *config);

/**
 * \brief Transmits a frame from a single channel.
 *
 * \param[inout] geth   Pointer to the GETH driver handle structure.
 * \param[in]    config Pointer to the TX frame configuration.
 *
 * \retval None
 *
 *
 * \code
 * // IfxGeth_Eth geth; // assumed to be defined globally
 * //const uint8 myMacAddress[6] = {0x00, 0x11, 0x22, 0x33, 0x44, 0x55};   // assumed to be defined globally
 *
 * uint32 payloadLength = 8; // 8 bytes
 * uint32 packetLength = IFXGETH_HEADER_LENGTH + payloadLength; // IFXGETH_HEADER_LENGTH defined by user
 * IfxGeth_FrameConfig frameConfig;
 * frameConfig.channelId = IfxGeth_TxDmaChannel_0;
 * frameConfig.packetLength = packetLength;
 *
 * // get free buffer
 * uint8 *pTxBuf = (uint8*) IfxGeth_Eth_waitTransmitBuffer(&geth, IfxGeth_TxDmaChannel_0);
 * // write the header
 * IfxGeth_Eth_writeHeader(&geth, pTxBuf, (uint8 *)myMacAddress, (uint8 *)myMacAddress, payloadLength);
 * // write the payload
 * uint32 i;
 * for(i = IFXGETH_HEADER_LENGTH; i < packetLength; ++i) {
 *     pTxBuf[i] = i - 13;
 * }
 *
 * // clear the TX interrupt status
 * IfxGeth_dma_clearInterruptFlag(geth->gethSFR, IfxGeth_DmaChannel_0, IfxGeth_DmaInterruptFlag_transmitInterrupt) ;
 *
 * IfxGeth_Eth_sendFrame(&geth, &frameConfig);
 * \endcode
 *
 */
IFX_EXTERN void IfxGeth_Eth_sendFrame(IfxGeth_Eth *geth, IfxGeth_Eth_FrameConfig *config);

/**
 * \brief Transmits a frame from a single channel using the specified TX DMA channel.
 *
 * \param[inout] geth         Pointer to the GETH driver handle structure.
 * \param[inout] packetLength Length of the packet to be transmitted in bytes.
 *                            Range: 0 to 0xFFFF
 * \param[in]    channelId    Tx channel Id.
 *                            Range: \ref IfxGeth_TxDmaChannel
 *
 * \retval None
 *
 * \code
 * // IfxGeth_Eth geth; // assumed to be defined globally
 * //const uint8 myMacAddress[6] = {0x00, 0x11, 0x22, 0x33, 0x44, 0x55};   // assumed to be defined globally
 *
 * uint32 payloadLength = 8; // 8 bytes
 * uint32 packetLength = IFXGETH_HEADER_LENGTH + payloadLength; // IFXGETH_HEADER_LENGTH defined by user
 *
 * // get free buffer
 * uint8 *pTxBuf = (uint8*) IfxGeth_Eth_waitTransmitBuffer(&geth, IfxGeth_TxDmaChannel_0);
 * // write the header
 * IfxGeth_Eth_writeHeader(&geth, pTxBuf, (uint8 *)myMacAddress, (uint8 *)myMacAddress, payloadLength);
 * // write the payload
 * uint32 i;
 * for(i = IFXGETH_HEADER_LENGTH; i < packetLength; ++i) {
 *     pTxBuf[i] = i - 13;
 * }
 *
 * // clear the TX interrupt status
 * IfxGeth_dma_clearInterruptFlag(geth->gethSFR, IfxGeth_DmaChannel_0, IfxGeth_DmaInterruptFlag_transmitInterrupt) ;
 *
 * IfxGeth_Eth_sendTransmitBuffer(&geth, packetLength, IfxGeth_TxDmaChannel_0);
 * \endcode
 *
 */
IFX_EXTERN void IfxGeth_Eth_sendTransmitBuffer(IfxGeth_Eth *geth, uint32 packetLength, IfxGeth_TxDmaChannel channelId);

/**
 * \brief Updates the current Rx descriptor pointer in the handle to the next Rx descriptor for the specified channel.
 *
 * \param[inout] geth       Pointer to the GETH driver handle structure.
 * \param[in]    channelId  The RX DMA channel identifier.
 *                          Range: \ref IfxGeth_RxDmaChannel
 *
 * \retval None
 *
 * \code
 * // IfxGeth_Eth geth; // assumed to be defined globally
 *
 * IfxGeth_Eth_shuffleRxDescriptor(&geth, IfxGeth_RxDmaChannel_0);
 * \endcode
 *
 */
IFX_EXTERN void IfxGeth_Eth_shuffleRxDescriptor(IfxGeth_Eth *geth, IfxGeth_RxDmaChannel channelId);

/**
 * \brief Updates the current Tx descriptor pointer for the specified channel in the GETH driver handle.
 *
 * \param[inout] geth       Pointer to the GETH driver handle structure.
 * \param[in]    channelId  The TX DMA channel identifier.
 *                          Range: \ref IfxGeth_TxDmaChannel
 *
 * \retval None
 *
 * \code
 * // IfxGeth_Eth geth; // assumed to be defined globally
 *
 * IfxGeth_Eth_shuffleTxDescriptor(&geth, IfxGeth_TxDmaChannel_0);
 * \endcode
 *
 */
IFX_EXTERN void IfxGeth_Eth_shuffleTxDescriptor(IfxGeth_Eth *geth, IfxGeth_TxDmaChannel channelId);

/**
 * \brief Starts the Receiver functions of MAC and selected DMA channel.
 *
 * \param[inout] geth       Pointer to the GETH driver handle structure.
 * \param[in]    channelId  The RX DMA channel identifier.
 *                          Range: \ref IfxGeth_RxDmaChannel
 *
 * \retval None
 *
 * \code
 * // IfxGeth_Eth geth; // assumed to be defined globally
 *
 * IfxGeth_Eth_startReceiver(&geth, IfxGeth_RxDmaChannel_0);
 * \endcode
 *
 */
IFX_EXTERN void IfxGeth_Eth_startReceiver(IfxGeth_Eth *geth, IfxGeth_RxDmaChannel channelId);

/**
 * \brief Starts the Receiver functions of MAC and the specified number of DMA channels.
 *
 * \param[inout] geth          Pointer to the GETH driver handle structure.
 * \param[in]    numOfChannels Number of channels to be started for transmission (starting from channel 0).
 *                             Range: 0 to 3
 *
 * \retval None
 *
 * \code
 * // IfxGeth_Eth geth; // assumed to be defined globally
 *
 * IfxGeth_Eth_startReceivers(&geth, 1);
 * \endcode
 *
 */
IFX_EXTERN void IfxGeth_Eth_startReceivers(IfxGeth_Eth *geth, uint32 numOfChannels);

/**
 * \brief Starts the transmitter functions of the MAC and the selected DMA channel.
 *
 * \param[inout] geth      Pointer to the GETH driver handle structure.
 * \param[in]    channelId The TX DMA channel identifier.
 *                          Range: \ref IfxGeth_TxDmaChannel
 *
 * \retval None
 *
 * \code
 * // IfxGeth_Eth geth; // assumed to be defined globally
 *
 * IfxGeth_Eth_startTransmitter(&geth, IfxGeth_TxDmaChannel_0);
 * \endcode
 *
 */
IFX_EXTERN void IfxGeth_Eth_startTransmitter(IfxGeth_Eth *geth, IfxGeth_TxDmaChannel channelId);

/**
 * \brief Starts the transmitter functions of the MAC and the selected DMA channel.
 *
 * \param[inout] geth          Pointer to the GETH driver handle structure.
 * \param[in]    numOfChannels number of channels to be started for transmission (starting from channel 0).
 *                             Range: 0 to 3
 *
 * \retval None
 *
 * \code
 * // IfxGeth_Eth geth; // assumed to be defined globally
 *
 * IfxGeth_Eth_startTransmitter(&geth, 1);
 * \endcode
 *
 */
IFX_EXTERN void IfxGeth_Eth_startTransmitters(IfxGeth_Eth *geth, uint32 numOfChannels);

/**
 * \brief Stops the transmitter functions of the MAC and the selected DMA channels.
 *
 * \param[inout] geth          Pointer to the GETH driver handle structure.
 * \param[in]    numOfChannels number of channels to be started for transmission (starting from channel 0).
 *                             Range: 0 to 3
 *
 * \retval None
 *
 * \code
 * // IfxGeth_Eth geth; // assumed to be defined globally
 *
 * IfxGeth_Eth_stopTransmitter(&geth, 4);
 * \endcode
 *
 */
IFX_EXTERN void IfxGeth_Eth_stopTransmitters(IfxGeth_Eth *geth, uint32 numOfChannels);

/**
 * \brief Wakes up the Receiver functions of MAC and selected channel of DMA.
 *
 * \param[inout] geth       Pointer to the GETH driver handle structure.
 * \param[in]    channelId  The RX DMA channel identifier.
 *                          Range: \ref IfxGeth_RxDmaChannel
 *
 * \retval None
 *
 * \code
 * // IfxGeth_Eth geth; // assumed to be defined globally
 *
 * IfxGeth_Eth_wakeupReceiver(&geth, IfxGeth_RxDmaChannel_0);
 * \endcode
 *
 */
IFX_EXTERN void IfxGeth_Eth_wakeupReceiver(IfxGeth_Eth *geth, IfxGeth_RxDmaChannel channelId);

/**
 * \brief Wakes up the transmitter functions of MAC and selected channel of DMA.
 *
 * \param[inout] geth       Pointer to the GETH driver handle structure.
 * \param[in]    channelId  The RX DMA channel identifier.
 *                          Range: \ref IfxGeth_TxDmaChannel
 *
 * \retval None
 *
 * \code
 * // IfxGeth_Eth geth; // assumed to be defined globally
 *
 * IfxGeth_Eth_wakeupTransmitter(&geth, IfxGeth_TxDmaChannel_0);
 * \endcode
 *
 */
IFX_EXTERN void IfxGeth_Eth_wakeupTransmitter(IfxGeth_Eth *geth, IfxGeth_TxDmaChannel channelId);

/** \} */

/******************************************************************************/
/*-------------------------Inline Function Prototypes-------------------------*/
/******************************************************************************/

/**
 * \brief Returns the base RX descriptor pointer for the specified RX DMA channel.
 *
 * \param[in] geth       Pointer to the GETH driver handle structure.
 * \param[in] channelId  The RX DMA channel identifier.
 *                       Range: \ref IfxGeth_RxDmaChannel
 *
 * \retval IfxGeth_RxDescr* Pointer to the base RX descriptor for the specified channel.
 *
 * \code
 * // IfxGeth_Eth geth; // assumed to be defined globally
 *
 * IfxGeth_RxDescr *descr = IfxGeth_Eth_getBaseRxDescriptor(&geth, IfxGeth_RxDmaChannel_0);
 * \endcode
 *
 */
IFX_INLINE volatile IfxGeth_RxDescr *IfxGeth_Eth_getBaseRxDescriptor(IfxGeth_Eth *geth, IfxGeth_RxDmaChannel channelId);

/**
 * \brief Returns the base TX descriptor pointer for the specified RX DMA channel.
 *
 * \param[in] geth       Pointer to the GETH driver handle structure.
 * \param[in] channelId  The TX DMA channel identifier.
 *                       Range: \ref IfxGeth_TxDmaChannel
 *
 * \retval IfxGeth_RxDescr* Pointer to the base TX descriptor for the specified channel.
 *
 * \code
 * // IfxGeth_Eth geth; // assumed to be defined globally
 *
 * IfxGeth_TxDescr *descr = IfxGeth_Eth_getBaseTxDescriptor(&geth, IfxGeth_TxDmaChannel_0);
 * \endcode
 *
 */
IFX_INLINE volatile IfxGeth_TxDescr *IfxGeth_Eth_getBaseTxDescriptor(IfxGeth_Eth *geth, IfxGeth_TxDmaChannel channelId);

/******************************************************************************/
/*-------------------------Global Function Prototypes-------------------------*/
/******************************************************************************/

/**
 * \brief Frees the receive buffer for the specified Rx DMA channel, enabling it for further reception.
 *
 * \param[inout] geth       Pointer to the GETH driver handle structure.
 * \param[in]    channelId  The RX DMA channel identifier.
 *                          Range: \ref IfxGeth_RxDmaChannel
 *
 * \retval None
 *
 * \code
 * // IfxGeth_Eth geth; // assumed to be defined globally
 *
 * IfxGeth_Eth_freeReceiveBuffer(&geth, IfxGeth_RxDmaChannel_0);
 * \endcode
 *
 */
IFX_EXTERN void IfxGeth_Eth_freeReceiveBuffer(IfxGeth_Eth *geth, IfxGeth_RxDmaChannel channelId);
/** \addtogroup IfxLld_Geth_Eth_Variables
 * \{ */

/******************************************************************************/
/*-------------------Global Exported Variables/Constants----------------------*/
/******************************************************************************/
/** \brief Actual rx descriptor lists of all availabe rx channels
 */
IFX_EXTERN IfxGeth_RxDescrList IfxGeth_Eth_rxDescrList[IFXGETH_NUM_MODULES][IFXGETH_NUM_RX_CHANNELS];

/** \brief Actual tx descriptor lists of all availabe tx channels
 */
IFX_EXTERN IfxGeth_TxDescrList IfxGeth_Eth_txDescrList[IFXGETH_NUM_MODULES][IFXGETH_NUM_TX_CHANNELS];

/** \} */

/******************************************************************************/
/*---------------------Inline Function Implementations------------------------*/
/******************************************************************************/

IFX_INLINE volatile IfxGeth_RxDescr *IfxGeth_Eth_getActualRxDescriptor(IfxGeth_Eth *geth, IfxGeth_RxDmaChannel channelId)
{
    return geth->rxChannel[channelId].rxDescrPtr;
}


IFX_INLINE volatile IfxGeth_TxDescr *IfxGeth_Eth_getActualTxDescriptor(IfxGeth_Eth *geth, IfxGeth_TxDmaChannel channelId)
{
    return geth->txChannel[channelId].txDescrPtr;
}


IFX_INLINE volatile IfxGeth_RxDescr *IfxGeth_Eth_getBaseRxDescriptor(IfxGeth_Eth *geth, IfxGeth_RxDmaChannel channelId)
{
    return geth->rxChannel[channelId].rxDescrList->descr;
}


IFX_INLINE volatile IfxGeth_TxDescr *IfxGeth_Eth_getBaseTxDescriptor(IfxGeth_Eth *geth, IfxGeth_TxDmaChannel channelId)
{
    return geth->txChannel[channelId].txDescrList->descr;
}


IFX_INLINE boolean IfxGeth_Eth_isRxDataAvailable(IfxGeth_Eth *geth, IfxGeth_RxDmaChannel channelId)
{
    return IfxGeth_Eth_getActualRxDescriptor(geth, channelId)->RDES3.R.OWN == 0;
}


IFX_INLINE void *IfxGeth_Eth_waitTransmitBuffer(IfxGeth_Eth *geth, IfxGeth_TxDmaChannel channelId)
{
    void *tx;

    do
    {
        tx = IfxGeth_Eth_getTransmitBuffer(geth, channelId);
    } while (tx == NULL_PTR);

    return tx;
}

/**
 * \brief Initializes a TX DMA channel with the specified configuration.
 *
 * \param[inout] geth            Pointer to the GETH driver handle structure.
 * \param[in]    txChannelIndex  TX DMA channel index to be initialized.
 * \param[in]    txChannelConfig Pointer to the configuration structure for the TX DMA channel.
 *
 * \retval None
 *
 * \code
 * // IfxGeth_Eth geth; // assumed to be defined globally
 * // const IfxGeth_Eth_RxChannelConfig txChannelConfig; // assumed to be defined globally
 * uint32 txChannelIndex;
 * IfxGeth_Eth_initTxDmaChannel(geth, txChannelIndex, txChannelConfig);
 * \endcode
 *
 */
IFX_EXTERN void IfxGeth_Eth_initTxDmaChannel(IfxGeth_Eth *geth, uint32 txChannelIndex, const IfxGeth_Eth_TxChannelConfig *txChannelConfig);

/**
 * \brief Initializes a RX DMA channel with the specified configuration.
 *
 * \param[inout] geth            Pointer to the GETH driver handle structure.
 * \param[in]    rxChannelIndex  RX DMA channel index to be initialized.
 * \param[in]    rxChannelConfig Pointer to the configuration structure for the RX DMA channel.
 *
 * \retval None
 *
 * \code
 * // IfxGeth_Eth geth; // assumed to be defined globally
 * // const IfxGeth_Eth_RxChannelConfig rxChannelConfig; // assumed to be defined globally
 * uint32 rxChannelIndex;
 * IfxGeth_Eth_initRxDmaChannel(geth, rxChannelIndex, rxChannelConfig);
 * \endcode
 *
 */
IFX_EXTERN void IfxGeth_Eth_initRxDmaChannel(IfxGeth_Eth *geth, uint32 rxChannelIndex, const IfxGeth_Eth_RxChannelConfig *rxChannelConfig);

/**
 * \brief Initializes the interrupts for the DMA channels allocated for TX.
 *
 * \param[inout] geth               Pointer to the GETH driver handle structure.
 * \param[in]    channelIndex       TX DMA channel index to configure.
 * \param[in]    dmaInterruptConfig Configuration Structure for the Tx DMA interrupt initialization.
 *
 * \retval None
 *
 * \code
 * // IfxGeth_Eth geth; // assumed to be defined globally
 * // const IfxGeth_Eth_DmaInterruptConfig dmaInterruptConfig; // assumed to be defined globally
 * uint32 channelIndex;
 * IfxGeth_Eth_initTxDmaInterrupts(geth, channelIndex, dmaInterruptConfig);
 * \endcode
 *
 */
IFX_EXTERN void IfxGeth_Eth_initTxDmaInterrupts(IfxGeth_Eth *geth, uint32 channelIndex, const IfxGeth_Eth_DmaInterruptConfig *dmaInterruptConfig);

/**
 * \brief Initializes the interrupts for the DMA channels allocated for RX.
 *
 * \param[inout] geth               Pointer to the GETH driver handle structure.
 * \param[in]    channelIndex       RX DMA channel index to configure.
 * \param[in]    dmaInterruptConfig Configuration Structure for the Rx DMA interrupt initialization.
 *
 * \retval None
 *
 * \code
 * // IfxGeth_Eth geth; // assumed to be defined globally
 * // const IfxGeth_Eth_DmaInterruptConfig dmaInterruptConfig; // assumed to be defined globally
 * uint32 channelIndex;
 * IfxGeth_Eth_initRxDmaInterrupts(geth, channelIndex, dmaInterruptConfig);
 * \endcode
 *
 */
IFX_EXTERN void IfxGeth_Eth_initRxDmaInterrupts(IfxGeth_Eth *geth, uint32 channelIndex, const IfxGeth_Eth_DmaInterruptConfig *dmaInterruptConfig);

/**
 * \brief Configures the specified Tx queue in the MTL with the provided settings.
 *
 * \param[inout] gethSFR        Pointer to the GETH driver handle structure.
 * \param[in]    txQueueIndex   Tx queue Index
 *                              Range: 0 to 0xFFFFFFFF
 * \param[in]    txQueueConfig  Configuration Structure for the MTL Tx queue initialization.
 *
 * \retval None
 *
 * \code
 * // Ifx_GETH gethSFR; // assumed to be defined globally
 * // const IfxGeth_Eth_RxQueueConfig txQueueConfig; // assumed to be defined globally
 * uint32 txQueueIndex;
 * IfxGeth_Eth_configureTxQueue(gethSFR, txQueueIndex, txQueueConfig);
 * \endcode
 *
 */
IFX_EXTERN void IfxGeth_Eth_configureTxQueue(Ifx_GETH *gethSFR, uint32 txQueueIndex, const IfxGeth_Eth_TxQueueConfig *txQueueConfig);

/**
 * \brief Configures the specified Rx queue in the MTL with the provided settings.
 *
 * \param[inout] gethSFR        Pointer to the GETH driver handle structure.
 * \param[in]    txQueueIndex   Rx queue Index
 *                              Range: 0 to 0xFFFFFFFF
 * \param[in]    txQueueConfig  Configuration Structure for the MTL Rx queue initialization.
 *
 * \retval None
 *
 * \code
 * // Ifx_GETH gethSFR; // assumed to be defined globally
 * // const IfxGeth_Eth_RxQueueConfig rxQueueConfig; // assumed to be defined globally
 * uint32 rxQueueIndex;
 * IfxGeth_Eth_configureRxQueue(gethSFR, rxQueueIndex, rxQueueConfig);
 * \endcode
 *
 */
IFX_EXTERN void IfxGeth_Eth_configureRxQueue(Ifx_GETH *gethSFR, uint32 rxQueueIndex, const IfxGeth_Eth_RxQueueConfig *rxQueueConfig);

#endif /* IFXGETH_ET_H */
