/**
 * \file IfxPsi5_Psi5.h
 * \brief PSI5 PSI5 details
 * \ingroup IfxLld_Psi5
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
 * \defgroup IfxLld_Psi5_Psi5_Usage How to use the PSI5 PSI5 Interface driver?
 * \ingroup IfxLld_Psi5
 *
 * PSI5 communicates with the external world via one input/output line for each channel.
 *
 * In the following sections it will be described, how to integrate the driver into the application framework.
 *
 * \section IfxLld_Psi5_Psi5_Preparation Preparation
 * \subsection IfxLld_Psi5_Psi5_Include Include Files
 *
 * Include following header file into your C code:
 * \code
 * #include <Psi5/Psi5/IfxPsi5_Psi5.h>
 * \endcode
 *
 * \subsection IfxLld_Psi5_Psi5_Variables Variables
 * //used globally
 * \code
 * IfxPsi5_Psi5_Channel psi5Channel[IFXPSI5_PINMAP_NUM_CHANNELS];
 * \endcode
 *
 * \subsection IfxLld_Psi5_Psi5_Module Module Initialisation
 * \code
 *  // create module config
 *  IfxPsi5_Psi5_Config psi5Config;
 *  IfxPsi5_Psi5_initModuleConfig(&psi5Config, &MODULE_PSI5);
 *
 *  // initialize module
 *  IfxPsi5_Psi5 psi5;
 *  IfxPsi5_Psi5_initModule(&psi5, &psi5Config);
 * \endcode
 *
 * \subsection IfxLld_Psi5_Psi5_Channel Channel Initialisation
 * \code
 * // create channel config
 * IfxPsi5_Psi5_ChannelConfig psi5ChannelConfig;
 * IfxPsi5_Psi5_initChannelConfig(&psi5ChannelConfig, &psi5);
 *
 *     psi5ChannelConfig.watchdogTimerLimit[0] = 0x32; // initial delay before slot 0 starts
 *     psi5ChannelConfig.watchdogTimerLimit[1] = 0x90;
 *     psi5ChannelConfig.watchdogTimerLimit[2] = 0x10;
 *     psi5ChannelConfig.watchdogTimerLimit[3] = 0x10;
 *     psi5ChannelConfig.watchdogTimerLimit[4] = 0x10;
 *     psi5ChannelConfig.watchdogTimerLimit[5] = 0x10;
 *     psi5ChannelConfig.watchdogTimerLimit[6] = 0x10;
 *
 *     for(int slot=0; slot<6; ++slot) {
 *         psi5ChannelConfig.receiveControl.payloadLength[slot] = 8;
 *         if( slot == 0 )
 *             psi5ChannelConfig.receiveControl.frameExpectation[slot] = IfxPsi5_FrameExpectation_expected;
 *         else
 *             psi5ChannelConfig.receiveControl.frameExpectation[slot] = IfxPsi5_FrameExpectation_notExpected;
 *     }
 *
 *     // initialize channels
 *     for(int chn=0; chn<IFXPSI5_PINMAP_NUM_CHANNELS; ++chn) {
 *         psi5ChannelConfig.channelId = (IfxPsi5_ChannelId)chn;
 *
 *         // TODO: currently no IOCRx.ALTI config field
 *         unsigned alti = 0;
 *
 *         IfxPsi5_Psi5_PinsConfig pinsConfig;
 *         for(int module=0;module<IFXPSI5_PINMAP_NUM_MODULES;module++)
 *         {
 *          pinsConfig.in = IfxPsi5_Rx_In_pinTable[module][chn][alti];
 *          pinsConfig.inMode = IfxPort_InputMode_pullUp;
 *          pinsConfig.out = IfxPsi5_Tx_Out_pinTable[module][chn][alti];
 *         }
 *         pinsConfig.outMode = IfxPort_OutputMode_pushPull;
 *         pinsConfig.pinDriver = IfxPort_PadDriver_cmosAutomotiveSpeed1;
 *
 *         psi5ChannelConfig.pinsConfig = &pinsConfig;
 *
 *         IfxPsi5_Psi5_initChannel(&psi5Channel[chn], &psi5ChannelConfig);
 *     }
 * \endcode
 *
 * \subsection IfxLld_Psi5_Psi5_readChannelFrame read channel frame
 * \code
 *     for(int i=0; i<5; ++i) {
 *         for(int chn=0; chn<IFXPSI5_PINMAP_NUM_CHANNELS; ++chn) {
 *             IfxPsi5_Psi5_Frame frame;
 *
 *             while( !IfxPsi5_Psi5_readChannelFrame(&psi5Channel[chn], &frame) );
 *
 *         }
 *     }
 * \endcode
 *
 * \defgroup IfxLld_Psi5_Psi5 PSI5
 * \ingroup IfxLld_Psi5
 * \defgroup IfxLld_Psi5_Psi5_Structures Data Structures
 * \ingroup IfxLld_Psi5_Psi5
 * \defgroup IfxLld_Psi5_Psi5_Module Module Initialisation functions
 * \ingroup IfxLld_Psi5_Psi5
 * \defgroup IfxLld_Psi5_Psi5_Channel Channel functions
 * \ingroup IfxLld_Psi5_Psi5
 * \defgroup IfxLld_Psi5_Psi5_Clock Clock Intialisation functions
 * \ingroup IfxLld_Psi5_Psi5
 */

#ifndef IFXPSI5_PSI5_H
#define IFXPSI5_PSI5_H 1

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include "Psi5/Std/IfxPsi5.h"
#include "Scu/Std/IfxScuCcu.h"
#include "IfxPsi5_bf.h"

/******************************************************************************/
/*-----------------------------Data Structures--------------------------------*/
/******************************************************************************/

/** \addtogroup IfxLld_Psi5_Psi5_Structures
 * \{ */
/** \brief PSI5 handle data structure
 */
typedef struct
{
    Ifx_PSI5 *psi5;       /**< \brief Specifies the pointer to the PSI5 module registers */
} IfxPsi5_Psi5;

/** \brief channel trigger configuration structure
 */
typedef struct
{
    uint32 channelTriggerValue;         /**< \brief Specifies the channel trigger value CTV. Range 0 to 0xFFFF*/
    uint32 channelTriggerCounter;       /**< \brief Specifies the channel trigger counter. Range 0 to 0xFFFF */
} IfxPsi5_Psi5_ChannelTrigger;

/** \brief Clock configuration data structure
 */
typedef struct
{
    uint32              frequency;       /**< \brief Specifies the frequency for the clock 0 to 200 MHz*/
    IfxPsi5_DividerMode mode;            /**< \brief Specifies the mode of division for the clock */
    IfxPsi5_ClockType   type;            /**< \brief Specifies the type of clock (fracDiv / slow 125kHz / fast 189 kHz / timestamp) */
} IfxPsi5_Psi5_Clock;

/** \brief Psi5 frame data structure with individual members
 */
typedef struct
{
    uint8  crcError : 1;                         /**< \brief Crc error flag. Range 0: correct CRC / Parity, 1: wrong CRC / Parity */
    uint8  crc : 3;                              /**< \brief Received crc: Range 0 to 0x7 */
    uint32 readData : 28;                        /**< \brief Received data. Range 0x0000000 to 0xFFFFFFF*/
    uint32 timestamp : 24;                       /**< \brief Timestamp. Range 0x000000 to 0xFFFFFF */
    uint8  slotCounter : 3;                      /**< \brief Slot counter. Range 0 to 6 */
    uint8  timeslotError : 1;                    /**< \brief Time slot error flag. Range 0: No error, 1: Error */
    uint8  numberOfBitsError : 1;                /**< \brief Number of bits error flag. Range 0: All bits received, 1: Not all bits received*/
    uint8  messagingBitsError : 1;               /**< \brief Messaging bits error flag. Range 0: Frame is correct, 1: Frame is not correct  */
    uint8  noFrameReceivedError : 1;             /**< \brief No frame received flag. Range 0: No error, 1: Error */
    uint8  receiveMemoryOverflowError : 1;       /**< \brief Receive buffer overflow error flag. Range 0: No overflow, 1: Overflow */
} IfxPsi5_Psi5_FrameData;

/** \brief Input output configuration structure
 */
typedef struct
{
    boolean                         outputInverterEnabled;         /**< \brief Specifies the pulse polarity of the output. Range 0: Pulse polarity is not inverted, 1: Pulse polarity is inverted  */
    boolean                         inputInverterEnabled;          /**< \brief Specifies the pulse polarity of the input. Range 0: Pulse polarity is not inverted, 1: Pulse polarity is inverted */
    IfxPsi5_DigitalInputFilterDepth digitalInputFilterDepth;       /**< \brief Specifies the the number of port input samples considered for floating average */
} IfxPsi5_Psi5_InputOutputControl;

/** \brief Psi5 serial message with individual members
 */
typedef struct
{
    uint16 serialData : 16;                       /**< \brief Serial message data. Range 0 to 0xFFFF */
    uint8  messageId : 8;                         /**< \brief Serial message Id. Range 0 to 0xFF */
    uint8  crc : 6;                               /**< \brief Serial message crc. Range 0 to 0x3F */
    uint8  serialMessageCRCFailedError : 1;       /**< \brief Serial message crc error flag. Range 0: CRC of serial message is success, 1: CRC of serial message is not success */
    uint8  configuration : 1;                     /**< \brief Serial message configuration. Range 0: 12-bit data and 8-bit message ID, 1: 16-bit data and 4-bit message ID  */
} IfxPsi5_Psi5_Message;

/** \brief Sync pulse generation configuration structure
 */
typedef struct
{
    uint32              pulseLength;                      /**< \brief Specifies the standard pulse width without data coding for standard pulse width or for coding a '0'. Range 0 to 0x3F */
    uint32              delayLength;                      /**< \brief Specifies the additional length of the pulse width for coding a '1'. Range 0 to 0x3F */
    IfxPsi5_TimeBase    timeBaseSelect;                   /**< \brief Specifies the clock source for CTV as internal or external. */
    IfxPsi5_Trigger     externalTimeBaseSelect;           /**< \brief Specifies the clock source for CTV in the case of external.*/
    IfxPsi5_TriggerType periodicOrExternalOrBypass;       /**< \brief Specifies whether periodic trigger or external trigger or bypass is selected */
    IfxPsi5_Trigger     externalTriggerSelect;            /**< \brief Specifies the trigger source in case of external triggerring */
    uint32              blankoutTime;                     /**< \brief Specifies the duration of blank out period. Range 0 to 0x7F */
} IfxPsi5_Psi5_PulseGeneration;

/** \brief Psi5 frame in double word format
 */
typedef struct
{
    uint32 lowWord;        /**< \brief Lower 32 bits of the Psi5 frame */
    uint32 highWord;       /**< \brief Upper 32 bits of the Psi5 frame */
} IfxPsi5_Psi5_Rdm;

/** \brief Psi5 serial message as unsigned 32 bit value
 */
typedef struct
{
    uint32 value;       /**< \brief 32 bit value of the Psi5 serial message */
} IfxPsi5_Psi5_Rds;

/** \brief Receive control configuration structure
 */
typedef struct
{
    boolean                              asynchronousModeSelected;                       /**< \brief Specifies the asynchronous mode of operation. Range 0: ASYN Mode OFF, 1: ASYN Mode ON */
    uint32                               fifoWarningLevel;                               /**< \brief Specifies the fifo warning level. Range 0 to 0x1F */
    uint32                               payloadLength[IFXPSI5_NUM_SLOTS];               /**< \brief Specifies the payload length for the slots 0 to 5.  Range 0 to 0x1F */
    IfxPsi5_Verbose                      verboseForAsynchronousMode;                     /**< \brief Specifies the verbose mode selection in asynchronous mode of operation */
    IfxPsi5_MessagingBits                messagingBitsPresence[IFXPSI5_NUM_SLOTS];       /**< \brief Specifies the presence or absence of messaging bits in the slots 0 to 5 */
    IfxPsi5_CRCorParity                  crcOrParity[IFXPSI5_NUM_SLOTS];                 /**< \brief Specifies the crc or parity selection for the slots 0 to 5 */
    IfxPsi5_FrameExpectation             frameExpectation[IFXPSI5_NUM_SLOTS];            /**< \brief Specifies whether the frame is expected or not in the slots 0 to 5 */
    IfxPsi5_Verbose                      verbose[IFXPSI5_NUM_SLOTS];                     /**< \brief Specifies the verbose is enabled or disabled for the slots 0 to 5 */
    IfxPsi5_BaudRate                     baudrateSelect;                                 /**< \brief Specifies the baudrate selection */
    IfxPsi5_TimestampRegister            pulseTimestampSelect;                           /**< \brief Specifies the timestamp register selection for pulses */
    IfxPsi5_TimestampRegister            frameTimestampSelect;                           /**< \brief Specifies the timestamp register selection for start of frames */
    IfxPsi5_ReceiveDataRegisterTimestamp receiveDataRegisterTimestamp;                   /**< \brief Specifies the pulse or start of frame based timestamp to be stored in receive data register RDRH */
} IfxPsi5_Psi5_ReceiveControl;

/** \brief Timestamp configuration data structure
 */
typedef struct
{
    IfxPsi5_Trigger  externalTimeBaseSelect;       /**< \brief Specifies the clock base for counter CTS in the case of external */
    IfxPsi5_TimeBase timeBaseSelect;               /**< \brief Specifies the clock source for CTS as internal or external */
} IfxPsi5_Psi5_TimeStampConfig;

/** \brief Transmit control configuration structure
 */
typedef struct
{
    boolean enhancedProtocolSelected;                 /**< \brief Specifies whether the enhanced protocol is selected or not. Range 0: PSI5 V1.3. No Pulse length extension, 1: Enhanced Protocol with Pulse length extension.  */
    boolean bitStuffingEnabled;                       /**< \brief Specifies whether the bit stuffing is turned on or not. Range 0: No automatic bit stuffing, 1: Automatic bit stuffing is enabled.  */
    boolean crcGenerationEnabled;                     /**< \brief Specifies whether the crc generation is turned on or not. Range 0: CRC is not generated automatically, 1: CRC is generated automatically */
    boolean startSequenceGenerationEnabled;           /**< \brief Specifies whether the start sequence generation is turned on or not. Range 0: No start sequence generated, 1: Start sequence automatically generated */
    boolean inhibitingAutomaticTransferEnabled;       /**< \brief Specifies whether automatic transfer from the shift registers SSRL/H to SORL/H is inhibited or not. Range 0: Automatic transfer, 1: GO bit must be set before transfer */
    uint32  payloadLength;                            /**< \brief Specifies the payload length to be sent. Range 0 to 0x3F */
    uint32  ssrPayloadLength;                         /**< \brief Specifies the payload length of SSR. Range 0: Don't stop the shifting process and flushes, 1: Stop the shifting process and flushes */
    uint32  sorPayloadLength;                         /**< \brief Specifies the payload length of SOR. Range 0: Don't stop the sending process and flushes, 1: Stops the sending process and flushes */
} IfxPsi5_Psi5_TransmitControl;

/** \} */

/** \brief Pin Configuration structure
 */
typedef struct
{
    IFX_CONST IfxPsi5_Rx_In  *in;              /**< \brief The RX Pin which should be configured */
    IfxPort_InputMode         inMode;          /**< \brief The pin input mode which should be configured */
    IFX_CONST IfxPsi5_Tx_Out *out;             /**< \brief The TX Pin which should be configured */
    IfxPort_OutputMode        outMode;         /**< \brief The pin output mode which should be configured */
    IfxPort_PadDriver         pinDriver;       /**< \brief The pad driver mode which should be configured */
} IfxPsi5_Psi5_PinsConfig;

/** \addtogroup IfxLld_Psi5_Psi5_Structures
 * \{ */
/** \brief Channel handle data structure
 */
typedef struct
{
    IfxPsi5_Psi5     *module;          /**< \brief The PSI5 handle structure */
    Ifx_PSI5_CH      *channel;         /**< \brief Pointer to the channel registers */
    IfxPsi5_ChannelId channelId;       /**< \brief Specifies the channel index */
} IfxPsi5_Psi5_Channel;

/** \brief Channel configuration structure
 */
typedef struct
{
    IFX_CONST IfxPsi5_Psi5            *module;                                     /**< \brief Specifies pointer to the IfxPsi5_Psi5 module handle */
    uint32                             watchdogTimerLimit[IFXPSI5_NUM_WDTS];       /**< \brief Specifies the watchdog timer limit for each of the slots 0 to 6. Range 0 to 0xFFFF */
    IfxPsi5_ChannelId                  channelId;                                  /**< \brief Specifies the channel index */
    boolean                            enableChannel;                              /**< \brief TRUE: All channels will be enabled, FALSE: Specific channel needs to be explicitly enabled using the API IfxPsi5_enableChannel() */
    IfxPsi5_Psi5_PulseGeneration       pulseGeneration;                            /**< \brief Specifies the configuration for sync pulse generation */
    IfxPsi5_Psi5_ChannelTrigger        channelTrigger;                             /**< \brief Specifies the configuration for channel trigger */
    IfxPsi5_Psi5_ReceiveControl        receiveControl;                             /**< \brief Specifies the configuration for reception */
    IfxPsi5_Psi5_TransmitControl       sendControl;                                /**< \brief Specifies the configuration for transmission */
    IfxPsi5_Psi5_InputOutputControl    inputOutputControl;                         /**< \brief Specifies the configuration for input output control */
    IFX_CONST IfxPsi5_Psi5_PinsConfig *pinsConfig;                                 /**< \brief Pin Configuration structure */
} IfxPsi5_Psi5_ChannelConfig;

/** \brief PSI5 module configuration structure
 */
typedef struct
{
    Ifx_PSI5                    *psi5;                    /**< \brief Specifies the pointer to the PSI5 module registers */
    IfxPsi5_Psi5_Clock           fracDiv;                 /**< \brief Specifies fractionally divided clock properties */
    IfxPsi5_Psi5_Clock           slowClock;               /**< \brief Specifies the slower f125 clock properties */
    IfxPsi5_Psi5_Clock           fastClock;               /**< \brief Specifies the faster f189 clock properties */
    IfxPsi5_Psi5_Clock           timestampClock;          /**< \brief Specifies the time stamp clock properties */
    IfxPsi5_Psi5_TimeStampConfig timestampCounterA;       /**< \brief Specifies the time stamp counter A properties */
    IfxPsi5_Psi5_TimeStampConfig timestampCounterB;       /**< \brief Specifies the time stamp counter B properties */
    IfxPsi5_Psi5_TimeStampConfig timestampCounterC;       /**< \brief Specifies the time stamp counter C properties */
} IfxPsi5_Psi5_Config;

/** \brief Psi5 frame data union
 */
typedef union
{
    IfxPsi5_Psi5_Rdm       rdm;         /**< \brief Psi5 frame in double word format */
    IfxPsi5_Psi5_FrameData frame;       /**< \brief Psi5 frame data structure with individual members */
} IfxPsi5_Psi5_Frame;

/** \brief Psi5 serial message data structure
 */
typedef union
{
    IfxPsi5_Psi5_Rds     rds;           /**< \brief Psi5 serial message as unsigned 32 bit value */
    IfxPsi5_Psi5_Message message;       /**< \brief Psi5 serial message with individual members */
} IfxPsi5_Psi5_SerialMessage;

/** \brief startup related options TBD
 */
typedef struct
{
    uint8  a : 1;        /**< \brief TBD */
    uint32 b : 31;       /**< \brief TBD */
} IfxPsi5_Psi5_StartupOptions;

/** \} */

/** \addtogroup IfxLld_Psi5_Psi5_Module
 * \{ */

/******************************************************************************/
/*-------------------------Global Function Prototypes-------------------------*/
/******************************************************************************/

/**
 * \brief Deinitializes and resets the PSI5 module to its default state.
 *
 * \param[inout]    psi5        Pointer to the PSI5 handle data structure.
 *
 * \retval None
 *
 * A coding example can be found in \ref IfxLld_Psi5_Psi5_Usage
 */
IFX_EXTERN void IfxPsi5_Psi5_deInitModule(IfxPsi5_Psi5 *psi5);

/**
 * \brief Enables the PSI5 kernel module
 *
 * \param[inout]    psi5        Pointer to the base of PSI5 registers. 
 *
 * \retval None 
 */
IFX_EXTERN void IfxPsi5_Psi5_enableModule(Ifx_PSI5 *psi5);

/**
 * \brief Initializes the PSI5 module with the provided configuration.
 *
 * \param[inout]    psi5        Pointer to the PSI5 module handle data structure.
 * \param[in]       config      Pointer to the PSI5 configuration structure containing clock and timestamp settings.
 *
 * \retval TRUE  Initialization was successful.
 *         FALSE The configuration is invalid.
 * 
 * A coding example can be found in \ref IfxLld_Psi5_Psi5_Usage
 */
IFX_EXTERN boolean IfxPsi5_Psi5_initModule(IfxPsi5_Psi5 *psi5, const IfxPsi5_Psi5_Config *config);

/**
 * \brief Initializes the PSI5 module configuration structure with default values.
 *
 * \param[inout]    config      Pointer to the PSI5 module configuration structure to be initialized.
 * \param[in]       psi5        Base address of the PSI5 register space.
 *
 * \retval None
 *
 * A coding example can be found in \ref IfxLld_Psi5_Psi5_Usage
 */
IFX_EXTERN void IfxPsi5_Psi5_initModuleConfig(IfxPsi5_Psi5_Config *config, Ifx_PSI5 *psi5);

/**
 * \brief Resets the PSI5 kernel to its initial state
 *
 * \param[inout]    psi5        Pointer to the base of PSI5 registers
 *
 * \retval None
 */
IFX_EXTERN void IfxPsi5_Psi5_resetModule(Ifx_PSI5 *psi5);

/** \} */

/** \addtogroup IfxLld_Psi5_Psi5_Channel
 * \{ */

/******************************************************************************/
/*-------------------------Inline Function Prototypes-------------------------*/
/******************************************************************************/

/**
 * \brief Starts the specified PSI5 channel with the provided options.
 *
 * \param[in]       channel     Pointer to the PSI5 channel handle structure. 
 * \param[in]       options     Pointer to the startup options structure. 
 *
 * \retval TRUE If the channel startup was successful.
 *         FALSE If the channel startup failed.
 */
IFX_INLINE boolean IfxPsi5_Psi5_startupChannel(IfxPsi5_Psi5_Channel *channel, IfxPsi5_Psi5_StartupOptions *options);

/******************************************************************************/
/*-------------------------Global Function Prototypes-------------------------*/
/******************************************************************************/

/**
 * \brief Initializes a PSI5 channel with the specified configuration.
 *
 * \param[inout]    channel     Pointer to the PSI5 channel handle structure.
 * \param[in]       config      Pointer to the PSI5 channel configuration structure.
 *
 * \retval TRUE If the channel was successfully initialized with a valid configuration.
 *         FALSE If the configuration is invalid or initialization failed.
 *
 * A coding example can be found in \ref IfxLld_Psi5_Psi5_Usage
 */
IFX_EXTERN boolean IfxPsi5_Psi5_initChannel(IfxPsi5_Psi5_Channel *channel, const IfxPsi5_Psi5_ChannelConfig *config);

/**
 * \brief Initializes the PSI5 channel configuration with default or specified settings.
 *
 * \param[inout]    config      Pointer to the PSI5 channel configuration structure to be initialized.
 * \param[in]       psi5        Pointer to the PSI5 module handle.
 *
 * \retval None
 *
 * A coding example can be found in \ref IfxLld_Psi5_Psi5_Usage
 */
IFX_EXTERN void IfxPsi5_Psi5_initChannelConfig(IfxPsi5_Psi5_ChannelConfig *config, IfxPsi5_Psi5 *psi5);

/**
 * \brief Reads the received PSI5 frame for the specified channel.
 *
 * \param[inout]    channel     Handle to the PSI5 channel structure. 
 * \param[inout]    frame       Pointer to the PSI5 frame buffer where the received frame data
 *                              will be stored.
 *
 * \retval TRUE The function successfully read a frame from the channel.
 *         FALSE No frame was available in the channel.
 *
 * A coding example can be found in \ref IfxLld_Psi5_Psi5_Usage
 */
IFX_EXTERN boolean IfxPsi5_Psi5_readChannelFrame(IfxPsi5_Psi5_Channel *channel, IfxPsi5_Psi5_Frame *frame);

/** \brief Get the received serial message for the channel
 * 
 * \param[in]       channel     pointer to the PSI5 channel
 * \param[in]       slot        Slot Id
 * \param[inout]    message     pointer to the PSI5 serial message buffer
 * 
 * \retval TRUE if successful. 
 *         FALSE if no serial message available
 */
IFX_EXTERN boolean IfxPsi5_Psi5_readChannelSerialMessage(IfxPsi5_Psi5_Channel *channel, IfxPsi5_Slot slot, IfxPsi5_Psi5_SerialMessage *message);

/**
 * \brief Transmit the data through the PSI5 channel.
 *
 * \param[inout]    channel     Pointer to the PSI5 channel handle structure.
 * \param[in]       data        The 64-bit data to be transmitted. Range: 0 to 0xFFFFFFFFFFFFFFFF.
 *
 * \retval TRUE If the data was successfully sent.
 *         FALSE If the transmission failed 
 */
IFX_EXTERN boolean IfxPsi5_Psi5_sendChannelData(IfxPsi5_Psi5_Channel *channel, uint64 data);

/** \addtogroup IfxLld_Psi5_Psi5_Clock
 * \{ */

/******************************************************************************/
/*-------------------------Global Function Prototypes-------------------------*/
/******************************************************************************/

/**
 * \brief Retrieves the configured fractional divider (fracDiv) clock frequency for the PSI5 module.
 *
 * \param[in]       psi5        Pointer to the base of PSI5 registers.
 * 
 * \retval uint32 The configured fracDiv clock frequency in Hz. Range 0 to 1MHz.
 */
IFX_EXTERN uint32 IfxPsi5_Psi5_getFracDivClock(Ifx_PSI5 *psi5);

/**
 * \brief Configures the specified clock with the given parameters.
 *
 * \param[inout]    psi5        Pointer to the base of PSI5 registers.
 * \param[in]       clock       Specifies the clock configuration, including frequency, mode, and type.
 *
 * \retval uint32 The actual configured clock frequency in Hz. Range 0 to 1MHz.
 */
IFX_EXTERN uint32 IfxPsi5_Psi5_initializeClock(Ifx_PSI5 *psi5, const IfxPsi5_Psi5_Clock *clock);

/** \} */

/******************************************************************************/
/*---------------------Inline Function Implementations------------------------*/
/******************************************************************************/

IFX_INLINE boolean IfxPsi5_Psi5_startupChannel(IfxPsi5_Psi5_Channel *channel, IfxPsi5_Psi5_StartupOptions *options)
{
    IFX_UNUSED_PARAMETER(channel);
    IFX_UNUSED_PARAMETER(options);
    return TRUE;
}


#endif /* IFXPSI5_PSI5_H */
