/**
 * \file IfxPsi5s_Psi5s.h
 * \brief PSI5S PSI5S details
 * \ingroup IfxLld_Psi5s
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
 * \defgroup IfxLld_Psi5s_Psi5s_Usage How to use the PSI5S PSI5S Interface driver?
 * \ingroup IfxLld_Psi5s
 *
 * PSI5S defines a current loop based serial communication link typically used to connect airbag sensors or other peripheral devices.Data transmission and configuration of the sensor can be done by modulation of the Sync Pulses.
 *
 * In the following sections it will be described, how to integrate the driver into the application framework.
 *
 * \section IfxLld_Psi5s_Psi5s_Preparation Preparation
 * \subsection IfxLld_Psi5s_Psi5s_Include Include Files
 *
 * Include following header file into your C code:
 * \code
 *
 * #include <Psi5s/Psi5s/IfxPsi5s_Psi5s.h>
 *
 * \endcode
 *
 * \subsection IfxLld_Psi5s_Psi5s_Variables Variables
 *
 * \code
 *
 * // PSI5S handle
 * IfxPsi5s_Psi5s psi5s;
 *
 * \endcode
 *
 * \subsection IfxLld_Psi5s_Psi5s_initModule Module Initialisation
 * \code
 *
 * // create module config
 * IfxPsi5s_Psi5s_Config psi5sModuleConfig;
 * IfxPsi5s_Psi5s_initModuleConfig(&psi5sModuleConfig, &MODULE_PSI5S);
 * IfxPsi5s_Psi5s_initModule(&psi5s, &psi5sModuleConfig);
 *
 * \endcode
 *
 * \subsection IfxLld_Psi5s_Psi5s_initChannel Channel Initialisation
 * \code
 *
 * // create channel config
 * IfxPsi5s_Psi5s_ChannelConfig psi5sChannelConfig;
 * IfxPsi5s_Psi5s_initChannelConfig(&psi5sChannelConfig, &psi5s);
 * // change channel (default is channel 0, change to channel 4)
 * psi5sChannelConfig.channelId = IfxPsi5s_ChannelId_4;
 *
 * // change payloadlength (default is 0, i.e., no frame expecte; change to 8)
 * for(int slot=0; slot<6; ++slot)
 * {
 *    psi5sChannelConfig.receiveControl.payloadLength[slot] = 8;
 * }
 * // change channel (default is channel 0, change to channel 4)
 * psi5sChannelConfig.channelId = IfxPsi5s_ChannelId_4;
 *
 * // initialize the channel
 * IfxPsi5s_Psi5s_Channel psi5sChannel;
 * IfxPsi5s_Psi5s_initChannel(&psi5sChannel, &psi5sChannelConfig);
 *
 * \endcode
 *
 * Now, PSI5S is ready.  Then, call the below APIs to do operation.
 *
 * \subsection IfxLld_Psi5s_Psi5s_sendChannelData   Send Channel Data
 * \code
 * uint32 channels = (1 << IfxPsi5s_ChannelId_4); // enable channel 4
 * uint32 mask = (1 << IfxPsi5s_ChannelId_4); // modify the selection for channel 4
 *
 * // enable the channel trigger counter
 * IfxPsi5s_Psi5s_enableDisableChannelTriggerCounters(&psi5s, channels, mask);
 *
 * // enable the channel
 * IfxPsi5s_Psi5s_enableDisableChannels(&psi5s, channels, mask);
 *
 * // start ASC interface
 * IfxPsi5s_Psi5s_startAscTransactions(&psi5s);
 *
 * uint32 data = 0x5;
 * // send data
 * if(IfxPsi5s_Psi5s_sendChannelData(&psi5sChannel, data))
 * {
 * // wait till data transfer is completed
 * while(psi5s.psi5s->INTSTAT[IfxPsi5s_ChannelId_4].B.TPI == 0);
 * }
 *
 * \endcode
 *
 * \subsection IfxLld_Psi5s_Psi5s_readFrame  Read Channel Frame
 * \code
 * // enable ASC receiver
 * IfxPsi5s_Psi5s_enableAscReceiver(&psi5s);
 *
 * // start ASC interface
 * IfxPsi5s_Psi5s_startAscTransactions(&psi5s);
 *
 * // add the code below to initiate the sensor to transmit frames
 * // end of code to initiate the sensor to transmit frames
 *
 * IfxPsi5s_Psi5s_Frame frame;
 *
 * while(!IfxPsi5s_Psi5s_getReadFrameStatus(psi5,IfxPsi5s_ChannelId_4));
 *
 * IfxPsi5s_Psi5s_readFrame(&psi5sChannel, &frame))
 *
 * \endcode
 *
 * \defgroup IfxLld_Psi5s_Psi5s PSI5S
 * \ingroup IfxLld_Psi5s
 * \defgroup IfxLld_Psi5s_Psi5s_Structures Data Structures
 * \ingroup IfxLld_Psi5s_Psi5s
 * \defgroup IfxLld_Psi5s_Psi5s_Module Module Initialise Functions
 * \ingroup IfxLld_Psi5s_Psi5s
 * \defgroup IfxLld_Psi5s_Psi5s_Channel Channel Functions
 * \ingroup IfxLld_Psi5s_Psi5s
 * \defgroup IfxLld_Psi5s_Psi5s_Utility Utility Functions
 * \ingroup IfxLld_Psi5s_Psi5s
 * \defgroup IfxLld_Psi5s_Psi5s_Interrupt Interrupt configuration Function
 * \ingroup IfxLld_Psi5s_Psi5s
 */

#ifndef IFXPSI5S_PSI5S_H
#define IFXPSI5S_PSI5S_H 1

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include "Psi5s/Std/IfxPsi5s.h"
#include "Scu/Std/IfxScuWdt.h"

/******************************************************************************/
/*-----------------------------Data Structures--------------------------------*/
/******************************************************************************/

/** \addtogroup IfxLld_Psi5s_Psi5s_Structures
 * \{ */
/** \brief Clock configuration data structure
 */
typedef struct
{
    uint32               frequency;       /**< \brief Specifies the frequency for the clock. Range 20MHz to 20 MHz */
    IfxPsi5s_DividerMode mode;            /**< \brief Specifies the mode of division for the clock */
    IfxPsi5s_ClockType   type;            /**< \brief Specifies the type of clock (fracDiv / timestamp) */
} IfxPsi5s_Psi5s_Clock;

/** \brief Received individual bits
 */
typedef struct
{
    uint8 xcrc : 6;                            /**< \brief Received XCRC. Range 0 to 32 */
    uint8 xcrcError : 1;                       /**< \brief XCRC error flag. Range 0: correct XCRC , 1: wrong XCRC */
    uint8 crc : 3;                             /**< \brief Received CRC. Range 0 to 7 */
    uint8 crcError : 1;                        /**< \brief CRC error flag. Range 0: correct CRC/Parit, 1: wrong CRC/Parit  */
    uint8 errorFlag0 : 1;                      /**< \brief Error signalling flag 0. Range 0: No error occured, 1: Error occured */
    uint8 errorFlag1 : 1;                      /**< \brief Error signalling flag 1. Range 0: No error occured, 1: Error occured  */
    uint8 headerErrorFlag : 1;                 /**< \brief Header error signalling flag. Range 0: No error occured, 1: Error occured  */
    uint8 ascParityErrorFlag : 1;              /**< \brief ASC parity error flag. Range 0: No parity error occured, 1: parity error occured */
    uint8 ascFramingErrorFlag : 1;             /**< \brief ASC framing error flag. Range 0: No framing error error occured, 1: framing error occured  */
    uint8 ascOverrunErrorFlag : 1;             /**< \brief ASC overrun error flag  Range 0: No overrun error occured, 1: overrun error occured */
    uint8 watchdogTimeoutErrorFlag : 1;        /**< \brief Watchdog timeout error flag. Range 0: No error, 1: error */
    uint8 receiveBufferOverflowFlag : 1;       /**< \brief Receive buffer overflow flag. Range 0: No overflow, 1: overflow*/
    uint8 frameId : 3;                         /**< \brief Frame ID. Range 0 to 5 */
    uint8 channelId : 3;                       /**< \brief Channel ID. Range 0 to 7*/
    uint8 actualUartFrameCount : 3;            /**< \brief UART frames actually received. Range 0 to 7 */
    uint8 packetFrameCount : 4;                /**< \brief Packet frame count. Range 0 to 15 */
} IfxPsi5s_Psi5s_ReceivedBits;

/** \brief Receive data structure with different segments of data
 */
typedef struct
{
    uint32 readData : 28;          /**< \brief Received data. Range 0x0000000 to 0xFFFFFFF */
    uint8  packetFrameCount;       /**< \brief Packet frame count. Range 0 to 15*/
} IfxPsi5s_Psi5s_ReceivedData;

/** \brief Received timestamp contents structure
 */
typedef struct
{
    uint8  packetFrameCount : 4;       /**< \brief Packet frame count. Range 0 to 15 */
    uint32 timestamp : 24;             /**< \brief Received data. Range 0x000000 to 0xFFFFFF*/
} IfxPsi5s_Psi5s_Timestamp;

/** \} */

/** \addtogroup IfxLld_Psi5s_Psi5s_Structures
 * \{ */
/** \brief PSI5S handle data structure
 */
typedef struct
{
    Ifx_PSI5S *psi5s;       /**< \brief Specifies the pointer to the PSI5S module registers */
} IfxPsi5s_Psi5s;

/** \brief PSI5S module configuration structure
 */
typedef struct
{
    boolean                       parityCheckEnabled;                /**< \brief Specifies whether parity check is enabled or not. True for check parity */
    boolean                       framingCheckEnabled;               /**< \brief Specifies whether framing check is enabled or not. True for check framing errors */
    boolean                       overrunCheckEnabled;               /**< \brief Specifies whether overrun check is enabled or not. True for check overrun errors */
    boolean                       fractionalDividerEnabled;          /**< \brief Specifies whether fractional divider is enabled or not. True for fractional divider is enabled */
    boolean                       receiverOddParityEnabled;          /**< \brief Specifies whether receiver parity check should be for even or odd. True for odd parity selected*/
    boolean                       transmitterOddParityEnabled;       /**< \brief Specifies whether transmit parity generation should be even or odd. True for odd parity selected*/
    uint32                        baudrateFrequency;                 /**< \brief Specifies the baudrate frequency. Range 125 kHz to 189 kHz */
    IfxPsi5s_AscStopBits          stopBits;                          /**< \brief Specifies the number of stop bits */
    IfxPsi5s_AscMode              receiveMode;                       /**< \brief Specifies the mode of operation for ASC receiver */
    IfxPsi5s_AscBaudratePrescalar baudrateSelection;                 /**< \brief Specifies whether divide-by-2 or divide-by-3 is selected for baudrate prescalar */
    IfxPsi5s_AscMode              transmitMode;                      /**< \brief Specifies the mode of operation for ASC transmitter */
    IfxPsi5s_Psi5s_Clock          clockOutput;                       /**< \brief Specifies the output clock properties */
    IfxPsi5s_LoopBackMode         loopbackEnabled;                   /**< \brief Specifies whether loopback is enabled or not */
} IfxPsi5s_Psi5s_AscConfig;

/** \brief channel trigger configuration structure
 */
typedef struct
{
    uint32 channelTriggerValue;         /**< \brief Specifies the channel trigger value CTV. Range 0x0000 to 0xFFFF */
    uint32 channelTriggerCounter;       /**< \brief Specifies the channel trigger counter. Range 0x0000 to 0xFFFF */
} IfxPsi5s_Psi5s_ChannelTrigger;

/** \brief PSI5S global control configuration structure
 */
typedef struct
{
    boolean ascOnlyMode;                              /**< \brief Specifies if the module is in ASC only mode */
    boolean crcErrorConsideredForRSI;                 /**< \brief Specifies whether CRCI is considered for RSI assertion */
    boolean xcrcErrorConsideredForRSI;                /**< \brief Specifies whether XCRCI is considered for RSI assertion */
    boolean transmitErrorConsideredForRSI;            /**< \brief Specifies whether TEI is considered for RSI assertion */
    boolean parityErrorConsideredForRSI;              /**< \brief Specifies whether PE is considered for RSI assertion */
    boolean framingErrorConsideredForRSI;             /**< \brief Specifies whether FE is considered for RSI assertion */
    boolean overrunErrorConsideredForRSI;             /**< \brief Specifies whether OE is considered for RSI assertion */
    boolean receiveBufferErrorConsideredForRSI;       /**< \brief Specifies whether RBI is considered for RSI assertion */
    boolean headerErrorConsideredForRSI;              /**< \brief Specifies whether HDI is considered for RSI assertion */
    uint32  idleTime;                                 /**< \brief Specifies the number of stop bits in addition to last UART frame that is required for start of frame detection. Range 0x0 to 0xF*/
} IfxPsi5s_Psi5s_GlobalControlConfig;

/** \brief Structure for PSI5S pin configuration
 */
typedef struct
{
    IFX_CONST IfxPsi5s_Rx_In   *rx;              /**< \brief PSI5S Rx pin */
    IfxPort_InputMode           rxMode;          /**< \brief Rx pin as input */
    IFX_CONST IfxPsi5s_Tx_Out  *tx;              /**< \brief PSI5S Tx pin */
    IfxPort_OutputMode          txMode;          /**< \brief Tx as output */
    IFX_CONST IfxPsi5s_Clk_Out *clk;             /**< \brief PSI5S Clk Pin */
    IfxPort_OutputMode          clkMode;         /**< \brief Clk as output */
    IfxPort_PadDriver           pinDriver;       /**< \brief pad driver */
} IfxPsi5s_Psi5s_Pins;

/** \brief Sync pulse generation configuration structure
 */
typedef struct
{
    uint32               codeforZero;                  /**< \brief Specifies the code used to represent '0' - referred as TXCMD. Range 0x0 to 0xF */
    uint32               codeforOne;                   /**< \brief Specifies the code used to represent '1' - referred as ATXCMD. Range 0x0 to 0x1F */
    IfxPsi5s_TimeBase    timeBaseSelect;               /**< \brief Specifies the clock source for CTV as internal or external */
    IfxPsi5s_Trigger     externalTimeBaseSelect;       /**< \brief Specifies the clock source for CTV in the case of external */
    IfxPsi5s_TriggerType periodicOrExternal;           /**< \brief Specifies whether periodic trigger or external trigger or bypass is selected */
    IfxPsi5s_Trigger     externalTriggerSelect;        /**< \brief Specifies the trigger source in case of external triggerring */
} IfxPsi5s_Psi5s_PulseGeneration;

/** \brief Receive control configuration structure - covers control fields from RCRA, RCRB and NFC registers
 */
typedef struct
{
    boolean                       timestampEnabled;                         /**< \brief Specifies whether the timestamp is enabled or not */
    uint32                        payloadLength[IFXPSI5S_NUM_SLOTS];        /**< \brief Specifies the payload length to be received for each slot. Range 0x0 to 0x1F */
    IfxPsi5s_CrcOrParity          crcOrParity[IFXPSI5S_NUM_SLOTS];          /**< \brief Specifies the crc or parity selection for the slots 0 to 5 */
    IfxPsi5s_TimestampRegister    timestampSelect;                          /**< \brief Specifies the timestamp register selection for pulses */
    IfxPsi5s_TimestampTrigger     timestampTriggerSelect;                   /**< \brief Specifies the timestamp register selection for pulses */
    IfxPsi5s_FrameId              frameIdSelect;                            /**< \brief Specifies if frame ID is updated from frame header or is a rolling number 0..5 copied from FCNT */
    IfxPsi5s_WatchdogTimerMode    watchdogTimerModeSelect;                  /**< \brief Specifies the watchdog timer restart is wrt frame or sync pulse reception */
    IfxPsi5s_UartFrameCount       uartFrameCount[IFXPSI5S_NUM_SLOTS];       /**< \brief Specifies the expected number of UART frames per packet frame for each slot */
    IfxPsi5s_NumberExpectedFrames numberOfFramesExpected;                   /**< \brief Specifies the number of psi5s frames expected */
} IfxPsi5s_Psi5s_ReceiveControl;

/** \brief "Received data" data structure
 */
typedef union
{
    uint32                      rdr;                /**< \brief received data with frame count. Range 0x0000000 to 0xFFFFFFF */
    IfxPsi5s_Psi5s_ReceivedData receivedData;       /**< \brief Receive data structure with different segments of data */
} IfxPsi5s_Psi5s_ReceiveData;

/** \brief Receiver status data structure
 */
typedef union
{
    uint32                      rds;                /**< \brief received status data. 0x00000000 0xFFFFFFFF*/
    IfxPsi5s_Psi5s_ReceivedBits receivedBits;       /**< \brief Received individual bits */
} IfxPsi5s_Psi5s_ReceiveStatus;

/** \brief Receiver timestamp data structure
 */
typedef union
{
    uint32                   tsm;             /**< \brief received timestamp along with frame count. Range 0x000000 to 0xFFFFFF*/
    IfxPsi5s_Psi5s_Timestamp timeStamp;       /**< \brief Received timestamp contents structure */
} IfxPsi5s_Psi5s_ReceiveTimestamp;

/** \brief Timestamp configuration data structure
 */
typedef struct
{
    IfxPsi5s_Trigger  externalTimeBaseSelect;       /**< \brief Specifies the clock base for counter CTS in the case of external */
    IfxPsi5s_TimeBase timeBaseSelect;               /**< \brief Specifies the clock source for CTS as internal or external */
} IfxPsi5s_Psi5s_TimeStampConfig;

/** \brief Transmit control configuration structure
 */
typedef struct
{
    boolean                   bitStuffControl;                      /**< \brief Specifies whether the bit stuffing is turned on or not. 0: No automatic bit stuffing, 1: Automatic bit stuffing Enabled  */
    boolean                   crcGenerationControl;                 /**< \brief Specifies whether the crc generation is turned on or not 0: CRC is not generated automatically, 1: CRC is generated automatically*/
    boolean                   startSequenceGenerationControl;       /**< \brief Specifies whether the start sequence generation is turned on or not. 0: No start sequence generated, 1: Automatically generated by HW */
    uint32                    payloadLength;                        /**< \brief Specifies the payload length to be sent. Range 0x00 to 0x1F */
    IfxPsi5s_EnhancedProtocol enhancedProtocolSelection;            /**< \brief Specifies whether the enhanced protocol is selected or not */
} IfxPsi5s_Psi5s_TransmitControl;

/** \} */

/** \addtogroup IfxLld_Psi5s_Psi5s_Structures
 * \{ */
/** \brief Channel handle data structure
 */
typedef struct
{
    IfxPsi5s_Psi5s    *module;          /**< \brief The PSI5S handle structure */
    IfxPsi5s_ChannelId channelId;       /**< \brief Specifies the channel index */
} IfxPsi5s_Psi5s_Channel;

/** \brief Channel configuration structure
 */
typedef struct
{
    IFX_CONST IfxPsi5s_Psi5s      *module;                   /**< \brief Specifies pointer to the IfxPsi5s_Psi5s module handle */
    uint32                         watchdogTimerLimit;       /**< \brief Specifies the watchdog timer limit for each of the slots 0 to 6. Range 0x000000 to 0x7FFFFF */
    IfxPsi5s_ChannelId             channelId;                /**< \brief Specifies the channel index */
    IfxPsi5s_Psi5s_PulseGeneration pulseGeneration;          /**< \brief Specifies the configuration for sync pulse generation */
    IfxPsi5s_Psi5s_ChannelTrigger  channelTrigger;           /**< \brief Specifies the configuration for channel trigger */
    IfxPsi5s_Psi5s_ReceiveControl  receiveControl;           /**< \brief Specifies the configuration for reception */
    IfxPsi5s_Psi5s_TransmitControl sendControl;              /**< \brief Specifies the configuration for transmission */
} IfxPsi5s_Psi5s_ChannelConfig;

/** \brief PSI5S module configuration structure
 */
typedef struct
{
    Ifx_PSI5S                         *module;                    /**< \brief Specifies the pointer to the PSI5S module registers */
    IfxPsi5s_Psi5s_Clock               fracDiv;                   /**< \brief Specifies fractionally divided clock properties */
    IfxPsi5s_Psi5s_Clock               timestampClock;            /**< \brief Specifies the time stamp clock properties */
    IfxPsi5s_Psi5s_TimeStampConfig     timestampCounterA;         /**< \brief Specifies the time stamp counter A properties */
    IfxPsi5s_Psi5s_TimeStampConfig     timestampCounterB;         /**< \brief Specifies the time stamp counter B properties */
    IfxPsi5s_Psi5s_AscConfig           ascConfig;                 /**< \brief Specifies the configuration for ASC */
    IfxPsi5s_Psi5s_GlobalControlConfig globalControlConfig;       /**< \brief Specifies the global control configuration */
    IFX_CONST IfxPsi5s_Psi5s_Pins     *pins;                      /**< \brief structure for PSI5S pin configuration */
} IfxPsi5s_Psi5s_Config;

/** \brief Psi5s frame data structure
 */
typedef struct
{
    IfxPsi5s_Psi5s_ReceiveData      data;            /**< \brief Received data */
    IfxPsi5s_Psi5s_ReceiveStatus    status;          /**< \brief Receiver status */
    IfxPsi5s_Psi5s_ReceiveTimestamp timestamp;       /**< \brief Receiver timestamp */
} IfxPsi5s_Psi5s_Frame;

/** \} */

/** \addtogroup IfxLld_Psi5s_Psi5s_Module
 * \{ */

/******************************************************************************/
/*-------------------------Global Function Prototypes-------------------------*/
/******************************************************************************/

/**
 * \brief De-initializes the PSI5S module
 *
 * \param[inout] psi5s    Pointer to the PSI5S module handle structure. 
 *
 * \retval None
 */
IFX_EXTERN void IfxPsi5s_Psi5s_deInitModule(IfxPsi5s_Psi5s *psi5s);

/**
 * \brief Initializes the PSI5S module with the provided configuration.
 *
 * \param[inout] psi5s    Pointer to the PSI5S module handle structure. 
 * \param[in]    config   Pointer to the PSI5S configuration structure.
 *
 * \retval TRUE If the initialization was successful.
 *         FALSE If the initialization failed.
 *
 * A coding example can be found in \ref IfxLld_Psi5s_Psi5s_Usage
 */
IFX_EXTERN boolean IfxPsi5s_Psi5s_initModule(IfxPsi5s_Psi5s *psi5s, const IfxPsi5s_Psi5s_Config *config);

/**
 * \brief Initializes the PSI5S module configuration buffer with default values based on the provided register space.
 *
 * This function sets up the configuration structure for the PSI5S module by initializing its fields with default values.
 * The configuration includes clock properties, timestamp counter settings, ASC configuration, global control parameters,
 * and pin configurations.
 *
 * \param[inout] config   Pointer to the PSI5S module configuration buffer to be initialized.
 * \param[in]    psi5s    Pointer to the PSI5S register space used to initialize the configuration.
 * 
 * \retval None
 *
 * A coding example can be found in \ref IfxLld_Psi5s_Psi5s_Usage
 */
IFX_EXTERN void IfxPsi5s_Psi5s_initModuleConfig(IfxPsi5s_Psi5s_Config *config, Ifx_PSI5S *psi5s);

/** \} */

/** \addtogroup IfxLld_Psi5s_Psi5s_Usage
 * \{ */

/******************************************************************************/
/*-------------------------Inline Function Prototypes-------------------------*/
/******************************************************************************/

/**
 * \brief Enables the ASC receiver interface of the PSI5S module.
 *
 * This function configures and activates the ASC receiver within the PSI5S module.
 *
 * \param[inout] psi5s    Pointer to the PSI5S module handle. 
 *
 * \retval None
 *
 *
 * A coding example can be found in \ref IfxLld_Psi5s_Psi5s_Usage
 */
IFX_INLINE void IfxPsi5s_Psi5s_enableAscReceiver(IfxPsi5s_Psi5s *psi5s);

/**
 * \brief Access function to enable/disable any combination of channel trigger counters selected by mask parameter.
 *
 * \param[inout] psi5s     Pointer to the PSI5S module handle. 
 * \param[in]    channels  Specifies the channel trigger counters which should be enabled/disabled. Range: \ref IfxPsi5s_ChannelId
 * \param[in]    mask      Specifies the channel trigger counters which should be modified. Range: \ref IfxPsi5s_ChannelId
 *
 * \retval None
 *
 * A coding example can be found in \ref IfxLld_Psi5s_Psi5s_Usage
 */
IFX_INLINE void IfxPsi5s_Psi5s_enableDisableChannelTriggerCounters(IfxPsi5s_Psi5s *psi5s, uint32 channels, uint32 mask);

/**
 * \brief Access function to enable/disable any combination of channels selected by mask parameter
 *
 * This function allows selective modification of PSI5S channels by applying the given mask.
 * Channels are specified by their corresponding bits in the channels and mask parameters.
 *
 * \param[inout] psi5s     Pointer to the PSI5S module instance.
 * \param[in]    channels  Bitmask specifying which channels to enable or disable. Range: \ref IfxPsi5s_ChannelId
 * \param[in]    mask      Bitmask specifying which channels to modify. Range: \ref IfxPsi5s_ChannelId
 *
 * \retval None
 *
 * A coding example can be found in \ref IfxLld_Psi5s_Psi5s_Usage
 */
IFX_INLINE void IfxPsi5s_Psi5s_enableDisableChannels(IfxPsi5s_Psi5s *psi5s, uint32 channels, uint32 mask);

/**
 * \brief Starts ASC transactions for the PSI5S module
 *
 * This function initiates the ASC transactions
 * for the specified PSI5S module. It uses the provided handle to access the module
 * registers and manage the transaction process.
 *
 * \param[inout] psi5s    Pointer to the PSI5S module handle structure 
 *
 * \retval None
 *
 * A coding example can be found in \ref IfxLld_Psi5s_Psi5s_Usage
 */
IFX_INLINE void IfxPsi5s_Psi5s_startAscTransactions(IfxPsi5s_Psi5s *psi5s);

/******************************************************************************/
/*-------------------------Global Function Prototypes-------------------------*/
/******************************************************************************/

/**
 * \brief Initializes a PSI5S channel with the specified configuration.
 *
 * This function sets up the PSI5S channel according to the provided configuration parameters.
 * It validates the configuration and initializes the channel structure.
 *
 * \param[inout] channel   Pointer to the PSI5S channel handle structure to be initialized.
 * \param[in]    config    Pointer to the channel configuration structure.
 *
 * \retval TRUE If the channel was successfully initialized.
 *         FALSE If the configuration is invalid or required resources are missing.
 *
 * A coding example can be found in \ref IfxLld_Psi5s_Psi5s_Usage
 */
IFX_EXTERN boolean IfxPsi5s_Psi5s_initChannel(IfxPsi5s_Psi5s_Channel *channel, const IfxPsi5s_Psi5s_ChannelConfig *config);

/**
 * \brief Initializes a channel configuration structure with default values for the PSI5S module.
 *
 * This function sets up the provided channel configuration structure with default settings
 * for the specified PSI5S module. The configuration includes parameters such as watchdog
 * timer limits, channel ID, pulse generation, and transmission/reception controls.
 *
 * \param[inout] config    Pointer to the channel configuration structure to be initialized.
 * \param[in]    psi5s     Pointer to the PSI5S module handle.
 *
 * \retval None
 *
 *  A coding example can be found in \ref IfxLld_Psi5s_Psi5s_Usage
 */
IFX_EXTERN void IfxPsi5s_Psi5s_initChannelConfig(IfxPsi5s_Psi5s_ChannelConfig *config, IfxPsi5s_Psi5s *psi5s);

/**
 * \brief Reads the received PSI5S frame for the specified channel.
 *
 * This function retrieves the most recently received PSI5S frame for the given channel
 * and stores it in the provided frame buffer. The channel handle contains the module
 * instance and channel ID, while the frame buffer contains the received data, status,
 * and timestamp information.
 *
 * \param[inout] channel   Handle to the PSI5S channel, containing the module instance and channel ID.
 * \param[inout] frame     Buffer to store the received PSI5S frame, including data, status, and timestamp.
 * 
 * \retval None
 *
 * A coding example can be found in \ref IfxLld_Psi5s_Psi5s_Usage
 */
IFX_EXTERN void IfxPsi5s_Psi5s_readFrame(IfxPsi5s_Psi5s_Channel *channel, IfxPsi5s_Psi5s_Frame *frame);

/**
 * \brief Transmit the data through the specified PSI5S channel.
 *
 * \param[inout] channel   Pointer to the PSI5S channel handle. This structure contains
 *                         the necessary module and channel index information for
 *                         communication.
 * \param[in]    data      Data to be transmitted. Range: 0x000000 to 0xFFFFFF.
 *
 * \retval TRUE  Data was successfully sent.
 *         FALSE Data transmission failed.
 * 
 * A coding example can be found in \ref IfxLld_Psi5s_Psi5s_Usage
 */
IFX_EXTERN boolean IfxPsi5s_Psi5s_sendChannelData(IfxPsi5s_Psi5s_Channel *channel, uint32 data);

/** \} */

/** \addtogroup IfxLld_Psi5s_Psi5s_Utility
 * \{ */

/******************************************************************************/
/*-------------------------Global Function Prototypes-------------------------*/
/******************************************************************************/

/**
 * \brief Enables the PSI5S kernel module for operation.
 *
 * This function configures and enables the PSI5S module.
 *
 * \param[inout] psi5s    Pointer to the base of the PSI5S register space.
 *
 * \retval None 
 */
IFX_EXTERN void IfxPsi5s_Psi5s_enableModule(Ifx_PSI5S *psi5s);

/**
 * \brief Retrieves the baud rate for the PSI5S module based on the provided ASC configuration.
 *
 * \param[in]    psi5s     Pointer to the PSI5S module instance.
 * \param[in]    ascConfig Pointer to the ASC configuration structure.
 *
 * \retval float32 The calculated baud rate in Hz.
 */
IFX_EXTERN float32 IfxPsi5s_Psi5s_getBaudrate(Ifx_PSI5S *psi5s, IfxPsi5s_Psi5s_AscConfig *ascConfig);

/**
 * \brief Resets the PSI5S kernel to its initial state
 *
 * \param[inout] psi5s    Pointer to the base of PSI5S registers
 *
 * \retval None
 */
IFX_EXTERN void IfxPsi5s_Psi5s_resetModule(Ifx_PSI5S *psi5s);

/** \} */

/******************************************************************************/
/*-------------------------Inline Function Prototypes-------------------------*/
/******************************************************************************/

/**
 * \brief Retrieves the read frame status for a specific PSI5S channel.
 *
 * This function checks and returns the status of the received frame for the specified
 * PSI5S channel.
 *
 * \param[in]    psi5s     Pointer to the PSI5S module handle. This structure.
 * \param[in]    channelId Specifies the channel ID to check. Range \ref IfxPsi5s_ChannelId
 *
 * \retval TRUE A frame is available for reading on the specified channel.
 *         FALSE No frame is currently available for reading on the specified channel.
 */
IFX_INLINE boolean IfxPsi5s_Psi5s_getReadFrameStatus(IfxPsi5s_Psi5s *psi5s, IfxPsi5s_ChannelId channelId);

/******************************************************************************/
/*---------------------Inline Function Implementations------------------------*/
/******************************************************************************/

IFX_INLINE void IfxPsi5s_Psi5s_enableAscReceiver(IfxPsi5s_Psi5s *psi5s)
{
    IfxPsi5s_enableAscReceiver(psi5s->psi5s);
}


IFX_INLINE void IfxPsi5s_Psi5s_enableDisableChannelTriggerCounters(IfxPsi5s_Psi5s *psi5s, uint32 channels, uint32 mask)
{
    IfxPsi5s_enableDisableChannelTriggerCounters(psi5s->psi5s, channels, mask);
}


IFX_INLINE void IfxPsi5s_Psi5s_enableDisableChannels(IfxPsi5s_Psi5s *psi5s, uint32 channels, uint32 mask)
{
    IfxPsi5s_enableDisableChannels(psi5s->psi5s, channels, mask);
}


IFX_INLINE void IfxPsi5s_Psi5s_startAscTransactions(IfxPsi5s_Psi5s *psi5s)
{
    IfxPsi5s_startAscTransactions(psi5s->psi5s);
}


IFX_INLINE boolean IfxPsi5s_Psi5s_getReadFrameStatus(IfxPsi5s_Psi5s *psi5s, IfxPsi5s_ChannelId channelId)
{
    boolean flag = 0;
    flag = IfxPsi5s_getReadFrameStatus(psi5s->psi5s, channelId);
    return flag;
}


#endif /* IFXPSI5S_PSI5S_H */
