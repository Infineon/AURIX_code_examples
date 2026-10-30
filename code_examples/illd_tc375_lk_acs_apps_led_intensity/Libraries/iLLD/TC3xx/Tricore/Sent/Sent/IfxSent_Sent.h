/**
 * \file IfxSent_Sent.h
 * \brief SENT SENT details
 * \ingroup IfxLld_Sent
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
 * \defgroup IfxLld_Sent_Sent_Usage How to use the SENT Interface driver?
 * \ingroup IfxLld_Sent
 *
 * This SENT interface driver provides functions to communicate with external sensors.
 *
 * \section IfxLld_Sent_Sent_Preparation Preparation
 * \subsection IfxLld_Sent_Sent_Include Include Files
 *
 * Include following header file into your C code:
 * \code
 * #include <Sent/Sent/IfxSent_Sent.h>
 *
 * \endcode
 *
 * \subsection IfxLld_Sent_Sent_Variables Variables
 *
 * Declare SENT module and channel handles as global variables in your C code.
 * If multiple SENT channels should be serviced, it makes sense to declare the SENT channel handle as an array:
 * \code
 * #define TESTED_SENT_CHANNELS 3
 *
 * static IfxSent_Sent sent;
 * static IfxSent_Sent_Channel sentChannel[TESTED_SENT_CHANNELS];
 * \endcode
 *
 * \subsection IfxLld_Sent_Sent_Interrupt Interrupt Handler Installation
 *
 * See also \ref IfxLld_Cpu_Irq_Usage
 *
 * Define priorities for the Interrrupt handler. This is normally done in the Ifx_IntPrioDef.h file:
 * \code
 * #define IFX_INTPRIO_SENT_CHANNEL 1
 * \endcode
 *
 * Add the interrupt service routine to your C code. It has to call the SENT interrupt handler by passing the SENT channel handle:
 * \code
 * void SentInterruptHandler(IfxSent_Sent_Channel *channel);
 *
 * IFX_INTERRUPT(sentChannelISR, 0, IFX_INTPRIO_SENT_CHANNEL)
 * {
 *     int i;
 *
 *     for(i=0; i<TESTED_SENT_CHANNELS; ++i)
 *     {
 *         SentInterruptHandler(&sentChannel[i]);
 *     }
 * }
 * \endcode
 *
 * Note: the SentInterruptHandler function is not part of the interface driver, but has to be
 * implemented in the application. A template can be found below under \ref IfxLld_Sent_Sent_ISR
 *
 * Finally install the interrupt handlers in your initialisation function:
 * \code
 *     // install interrupt handler
 *     IfxCpu_Irq_installInterruptHandler(&sentChannelISR, IFX_INTPRIO_SENT_CHANNEL);
 *     IfxCpu_enableInterrupts();
 * \endcode
 *
 *
 * \subsection IfxLld_Sent_Sent_Init Module Initialisation
 *
 * The module initialisation can be done in the same function.
 * Here an example for SENT and SPC mode:
 *
 * \code
 *     // create module config
 *     IfxSent_Sent_Config sentConfig;
 *     IfxSent_Sent_initModuleConfig(&sentConfig, &MODULE_SENT);
 *
 *     // initialize module
 *     //IfxSent_Sent sent; // defined globally
 *     IfxSent_Sent_initModule(&sent, &sentConfig);
 * \endcode
 *
 * \subsection IfxLld_Sent_Sent_InitChannel Channel Initialisation
 * After the module has been initialized, one or more SENT channels can be configured.
 *
 * Here an example for three SENT channels in SENT and SPC mode:
 * \code
 *     // create channel config
 *     IfxSent_Sent_ChannelConfig sentChannelConfig;
 *     IfxSent_Sent_initChannelConfig(&sentChannelConfig, &sent);
 *
 *     // define tUnit of the external sensor
 *     sentChannelConfig.tUnit = 3.0E-6;
 *
 *     // ISR priorities and interrupt target
 *     sentChannelConfig.interrupt.priority = IFX_INTPRIO_SENT_CHANNEL;
 *     sentChannelConfig.interrupt.isrProvider = IfxCpu_Irq_getTos(IfxCpu_getCoreIndex());
 *
 *     int i;
 *     for(i=0; i<TESTED_SENT_CHANNELS; ++i)
 *     {
 *         // pin configuration
 *         const IfxSent_Sent_Pins sentPins[TESTED_SENT_CHANNELS] =
 *         {
 *             { // Channel 0
 *                 &IfxSent_SENT0C_P02_8_IN,    IfxPort_InputMode_noPullDevice,  // SENT input
 *                 &IfxSent_SPC0_P00_1_OUT,     IfxPort_OutputMode_openDrain,    // SENT output
 *                 IfxPort_PadDriver_cmosAutomotiveSpeed1
 *             },
 *
 *             { // Channel 1
 *                 &IfxSent_SENT1C_P02_7_IN,    IfxPort_InputMode_noPullDevice,  // SENT input
 *                 &IfxSent_SPC1_P02_7_OUT,     IfxPort_OutputMode_openDrain,    // SENT output
 *                 IfxPort_PadDriver_cmosAutomotiveSpeed1
 *             },
 *
 *             { // Channel 2
 *                 &IfxSent_SENT2C_P02_6_IN,    IfxPort_InputMode_noPullDevice,  // SENT input
 *                 &IfxSent_SPC2_P00_3_OUT,     IfxPort_OutputMode_openDrain,    // SENT output
 *                 IfxPort_PadDriver_cmosAutomotiveSpeed1
 *             },
 *         };
 *
 *         sentChannelConfig.pins = &sentPins[i];
 *
 *         // set channel
 *         sentChannelConfig.channelId = (IfxSent_ChannelId)i;
 *
 *         // initialize channel
 *         IfxSent_Sent_initChannel(&sentChannel[i], &sentChannelConfig);
 *     }
 * \endcode
 *
 * \subsection IfxLld_Sent_Sent_ISR Interrupt Service Handler
 * The ISR has to be implemented in the application. Following template can be used
 * to react on the events:
 *
 * \code
 * void SentInterruptHandler(IfxSent_Sent_Channel *channel)
 * {
 *     Ifx_SENT_CH_INTSTAT   interruptStatus = IfxSent_Sent_getAndClearInterruptStatus(channel);
 *
 *     if( interruptStatus.U )
 *     {
 *         // check for error conditions
 *         if (interruptStatus.U & IFXSENT_INTERRUPT_STATUS_ERROR_FLAGS)
 *         {
 *             // * Receive Buffer Overflow
 *             // * This bit is set after a frame has been received while the old one was
 *             // * not read from RDRx. I.e. the kernel wants to set any of the two
 *             // * interrupts RSI and RDI and finds any of these two interrupts already
 *             // * set. The old data is overwritten by the new data.
 *             // *
 *             if (interruptStatus.B.RBI)
 *             {
 *                 // insert your error handling code here
 *                 __debug();
 *             }
 *
 *             // * Transmit Buffer Underflow
 *             // * This bit is set after data has been completely transferred (PLEN
 *             // * exceeded) and no new data was written to SCRx.
 *             // *
 *             if (interruptStatus.B.TBI)
 *             {
 *                 // insert your error handling code here
 *                 __debug();
 *             }
 *
 *             // * Frequency Range Error
 *             // * This bit is set after a Synchronization / Calibration pulse was
 *             // * received that deviates more than +- 25% from the nominal value.
 *             // * The referring data is ignored.
 *             // *
 *             if (interruptStatus.B.FRI)
 *             {
 *                 // insert your error handling code here
 *                 __debug();
 *             }
 *
 *             // * Frequency Drift Error
 *             // * This bit is set after a subsequent Synchronization / Calibration
 *             // * pulse was received that deviates more than 1.5625% (1/64) from its
 *             // * predecessor.
 *             // *
 *             if (interruptStatus.B.FDI)
 *             {
 *                 // insert your error handling code here
 *                 __debug();
 *             }
 *
 *             // * Wrong Number of Nibbles
 *             // * This bit is set after a more nibbles have been received than expected
 *             // * or a Synchronization / Calibration Pulse is received too early thus
 *             // * too few nibbles have been received
 *             // *
 *             if (interruptStatus.B.NNI)
 *             {
 *                 // insert your error handling code here
 *                 __debug();
 *             }
 *
 *             // * Nibbles Value out of Range
 *             // * This bit is set after a too long or too short nibble pulse has been
 *             // * received. I.e. value < 0 or value > 15.
 *             // *
 *             if (interruptStatus.B.NVI)
 *             {
 *                 // insert your error handling code here
 *                 __debug();
 *             }
 *
 *             // * CRC Error
 *             // * This bit is set if the CRC check fails.
 *             // *
 *             if (interruptStatus.B.CRCI)
 *             {
 *                 // insert your error handling code here
 *                 __debug();
 *             }
 *
 *             // * Wrong Status and Communication Nibble Error
 *             // * In standard Serial Frame Mode (RCR.ESF is cleared), this bit is set
 *             // * if the Status and Communication nibble shows a start bit in a frame
 *             // * other than frame number n x 16.
 *             // * In Extended Serial Frame Mode this bit is without function.
 *             // *
 *             if (interruptStatus.B.WSI)
 *             {
 *                 // insert your error handling code here
 *                 __debug();
 *             }
 *
 *             // * Serial Data CRC Error
 *             // * This bit is set if the CRC of the serial message fails.
 *             // * In Extended Serial Message Format, this includes a check of the Serial
 *             // * Communication Nibble for correct 0 values of bit 3 in frames 7, 13 and 18.
 *             // *
 *             if (interruptStatus.B.SCRI)
 *             {
 *                 // insert your error handling code here
 *                 __debug();
 *             }
 *
 *             // * Watch Dog Error
 *             // * This bit is set if the Watch Dog Timer of the channel expires.
 *             // *
 *             if (interruptStatus.B.WDI)
 *             {
 *                 // insert your error handling code here
 *                 __debug();
 *             }
 *         }
 *
 *         // transaction events
 *
 *         // * Receive Data
 *         // * RDI is activated when a received frame is moved to a Receive Data
 *         // * Register RDR. Both RDI and RSI will be issued together in normal use
 *         // * cases where the frame size is not bigger than 8 nibbles and CRC is
 *         // * correct or not checked (if RCRx.CDIS is cleared).
 *         // *
 *         if (interruptStatus.B.RDI)
 *         {
 *             // * Ignore RDI bit, useful only when Frame Length is greater than
 *             // * 8 nibbles since it can indicate that end of frame
 *             // *
 *         }
 *
 *         // * Receive Success
 *         // * This bit is set at the successfully received end of a frame.
 *         // * Depending on bit RCRx.CDIS this indicates a successful check of the CRC.
 *         // *
 *         if (interruptStatus.B.RSI)
 *         {
 *             // here you could handle the incoming frame:
 *             IfxSent_Sent_Frame frame;
 *             IfxSent_Sent_readChannelSerialDataFrame(channel, &frame);
 *
 *             // do something with the incoming data
 *         }
 *
 *         // * Transfer Data
 *         // * This bit is set after the trigger condition was detected. Data to be
 *         // * transferred has been moved internally. Thus a new value can be written
 *         // * to SCRx. This can be used for back to back transfers.
 *         // *
 *         if (interruptStatus.B.TDI)
 *         {
 *         }
 *
 *         // * Serial Data Received
 *         // * This bit is set after all serial data bits have been received via the
 *         // * Status and Communication nibble. Depending on bit RCRx.SCDIS this
 *         // * indicates a successful check of the CRC.
 *         // *
 *         if (interruptStatus.B.SDI)
 *         {
 *             // here you could handle the incoming message:
 *
 *             // decode incoming message
 *             IfxSent_Sent_SerialMessageFrame message;
 *             IfxSent_Sent_readChannelSerialMessageFrame(channel, &message);
 *
 *             // do something with the incoming message
 *         }
 *     }
 * }
 * \endcode
 *
 * \subsection IfxLld_Sent_Sent_Frame Frame Decoding
 * Following code snippet shows, how incoming data of a TLE4998S device can be decoded:
 *
 * \code
 * static void parseSensorData(IfxSent_Sent_Frame *frame)
 * {
 *    uint32 data = frame->data;
 *    uint8 statusNibble = frame->statusNibble;
 *
 *    // select B range [mT]
 *    const uint8 rangeValTable[4] = { 200, 100, 50, 0 };
 *    uint8 rangeVal = rangeValTable[statusNibble & 3];
 *
 *    uint16 hallVal = (short)((((data & 0xFFFF) * rangeVal) / 0x7FFF) - rangeVal);
 *    uint16 temperature = ((short)((data >> 16) & 0x00FF) - 55);
 *
 *    // do something with the values here...
 * }
 * \endcode
 *
 * \defgroup IfxLld_Sent_Sent Interface Driver
 * \ingroup IfxLld_Sent
 * \defgroup IfxLld_Sent_Sent_Structures Data Structures
 * \ingroup IfxLld_Sent_Sent
 * \defgroup IfxLld_Sent_Sent_Module Module Functions
 * \ingroup IfxLld_Sent_Sent
 * \defgroup IfxLld_Sent_Sent_Channel Channel Functions
 * \ingroup IfxLld_Sent_Sent
 */

#ifndef IFXSENT_SENT_H
#define IFXSENT_SENT_H 1

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include "Scu/Std/IfxScuWdt.h"
#include "Sent/Std/IfxSent.h"
#include "Cpu/Irq/IfxCpu_Irq.h"

/******************************************************************************/
/*-----------------------------Data Structures--------------------------------*/
/******************************************************************************/

/** \addtogroup IfxLld_Sent_Sent_Structures
 * \{ */
/** \brief Specifies the Interrupt type enables structure
 */
typedef struct
{
    uint32 receiveDataInterrupt : 1;                     /**< \brief Specifies receive data interrupt enable. Range : 1 if an interrupt request can be generated, 0 if no interrupt request can be generated */
    uint32 receiveSuccessInterrupt : 1;                  /**< \brief Specifies receive success interrupt enable. Range : 1 if an interrupt request can be generated, 0 if no interrupt request can be generated */
    uint32 receiveBufferOverflowInterrupt : 1;           /**< \brief Specifies receive buffer overflow interrupt enable. Range : 1 if an interrupt request can be generated, 0 if no interrupt request can be generated */
    uint32 transferDataInterrupt : 1;                    /**< \brief Specifies transfer data interrupt enable. Range : 1 if an interrupt request can be generated, 0 if no interrupt request can be generated */
    uint32 transferBufferUnderflowInterrupt : 1;         /**< \brief Specifies transfer buffer underflow interrupt enable. Range : 1 if an interrupt request can be generated, 0 if no interrupt request can be generated */
    uint32 serialDataReceiveInterrupt : 1;               /**< \brief Specifies serial data interrupt enable. Range : 1 if an interrupt request can be generated, 0 if no interrupt request can be generated */
    uint32 watchdogErrorInterrupt : 1;                   /**< \brief Specifies watchdog error interrupt enable. Range : 1 if an interrupt request can be generated, 0 if no interrupt request can be generated */
    uint32 serialDataCrcErrorInterrupt : 1;              /**< \brief Specifies serial data CRC error interrupt enable. Range : 1 if an interrupt request can be generated, 0 if no interrupt request can be generated */
    uint32 wrongStatusNibbleErrorInterrupt : 1;          /**< \brief Specifies wrong status nibble error interrupt enable. Range : 1 if an interrupt request can be generated, 0 if no interrupt request can be generated */
    uint32 crcErrorInterrupt : 1;                        /**< \brief Specifies CRC error interrupt enable. Range : 1 if an interrupt request can be generated, 0 if no interrupt request can be generated */
    uint32 nibblesValueOutOfRangeErrorInterrupt : 1;     /**< \brief Specifies nibble value out of range error interrupt enable. Range : 1 if an interrupt request can be generated, 0 if no interrupt request can be generated */
    uint32 nibblesWrongErrorInterrupt : 1;               /**< \brief Specifies nibbles wrong error interrupt enable. Range : 1 if an interrupt request can be generated, 0 if no interrupt request can be generated */
    uint32 frequencyDriftErrorInterrupt : 1;             /**< \brief Specifies frequency drift error interrupt enable. Range : 1 if an interrupt request can be generated, 0 if no interrupt request can be generated */
    uint32 frequencyRangeErrorInterrupt : 1;             /**< \brief Specifies frequency not in the range error interrupt enable. Range : 1 if an interrupt request can be generated, 0 if no interrupt request can be generated */
} IfxSent_Sent_Enable;

/** \} */

/** \addtogroup IfxLld_Sent_Sent_Structures
 * \{ */
/** \brief Specifies SENT handle structure
 */
typedef struct
{
    Ifx_SENT *sent;       /**< \brief Specifies pointer to SENT registers */
} IfxSent_Sent;

/** \brief Specifies interrupt flags union . In addition it allows to write and read to/from all flags as once via the ALL member.
 */
typedef union
{
    uint32              ALL;          /**< \brief Specifies to write and read to/from all flags as once via the ALL member. Range : 0 to 0x3FFF. */
    IfxSent_Sent_Enable enable;       /**< \brief Structure contains the interrupt flags */
} IfxSent_Sent_EnabledInterrupts;

/** \brief Specifies the input output control properties
 */
typedef struct
{
    boolean                       inputPulsePolarityHigh;         /**< \brief Specifies the polarity of input of each channel. Range: TRUE if input pulse polarity is active high , FALSE if input pulse polarity is active low. */
    boolean                       outputPulsePolarityHigh;        /**< \brief Specifies the polarity of input of each channel. Range: TRUE if output pulse polarity is active high , FALSE if output pulse polarity is active low. */
    boolean                       edgeCounterCleared;             /**< \brief Specifies the edge counter reset. Range: TRUE if edge counter is cleared. FALSE if edge counter is not cleared.*/
    boolean                       glitchFallingCleared;           /**< \brief Specifies the glitch falling edge clear. Range: TRUE if FEG is cleared, FALSE if FEG is not cleared. */
    boolean                       glitchRisingCleared;            /**< \brief Specifies the glitch rising edge clear. Range: TRUE if REG is cleared, FALSE if REG is not cleared. */
    boolean                       triggerMonitorCleared;          /**< \brief Specifies the trigger monitor reset. Range: TRUE if TRM is cleared, FALSE if TRM is not cleared. */
    IfxSent_DigitalGlitchesLength digitalGlitchFilterDepth;       /**< \brief Specifies the Digital Glitch Filter depth for input signal delay */
    IfxSent_ExternalTrigger       externalTrigger;                /**< \brief Specifies the external trigger line source */
} IfxSent_Sent_InputOutputControl;

/** \brief Specifies the interrupt control properties
 */
typedef struct
{
    uint16     priority;          /**< \brief Specifies the interrupt priority. Always 1 since all interrupts are handled at a time. Range: 0 to 0xFF. */
    IfxSrc_Tos isrProvider;       /**< \brief Specifies the interrupt service provider. CPU or DMA. */
} IfxSent_Sent_Interrupt;

/** \brief Specifies the interrupt control properties structure
 */
typedef struct
{
    IfxSent_InterruptNodePointer receiveSuccessInterruptNode;                /**< \brief Specifies the interrupt node for rsi request */
    IfxSent_InterruptNodePointer receiveDataInterruptNode;                   /**< \brief Specifies the interrupt node for rdi request */
    IfxSent_InterruptNodePointer receiveBufferOverflowInterruptNode;         /**< \brief Specifies the interrupt node for rbi request */
    IfxSent_InterruptNodePointer transferDataInterruptNode;                  /**< \brief Specifies the interrupt node for tdi request */
    IfxSent_InterruptNodePointer transferBufferUnderflowInterruptNode;       /**< \brief Specifies the interrupt node for tbi request */
    IfxSent_InterruptNodePointer errorInterruptNode;                         /**< \brief Specifies the interrupt node for erri request */
    IfxSent_InterruptNodePointer serialDataReceiveInterruptNode;             /**< \brief Specifies the interrupt node for sdi request */
    IfxSent_InterruptNodePointer watchdogErrorInterruptNode;                 /**< \brief Specifies the interrupt node for wdi request */
} IfxSent_Sent_InterruptNodeControl;

/** \brief Specifies the received nibbles control properties
 */
typedef struct
{
    IfxSent_Nibble nibblePointer0;       /**< \brief Specifies the received nibble0 control */
    IfxSent_Nibble nibblePointer1;       /**< \brief Specifies the received nibble1 control */
    IfxSent_Nibble nibblePointer2;       /**< \brief Specifies the received nibble2 control */
    IfxSent_Nibble nibblePointer3;       /**< \brief Specifies the received nibble3 control */
    IfxSent_Nibble nibblePointer4;       /**< \brief Specifies the received nibble4 control */
    IfxSent_Nibble nibblePointer5;       /**< \brief Specifies the received nibble5 control */
    IfxSent_Nibble nibblePointer6;       /**< \brief Specifies the received nibble6 control */
    IfxSent_Nibble nibblePointer7;       /**< \brief Specifies the received nibble7 control */
} IfxSent_Sent_NibbleControl;

/** \brief Specifies the pins configuration for SENT channel
 */
typedef struct
{
    IFX_CONST IfxSent_Sent_In *in;              /**< \brief Specifies input pin configuration */
    IfxPort_InputMode          inMode;          /**< \brief Specifies input pin mode */
    IFX_CONST IfxSent_Spc_Out *out;             /**< \brief Specifies output pin configuration */
    IfxPort_OutputMode         outMode;         /**< \brief Specifies output pin mode */
    IfxPort_PadDriver          pinDriver;       /**< \brief Pad driver mode definition */
} IfxSent_Sent_Pins;

/** \brief Specifies the receive control properties
 */
typedef struct
{
    boolean                         crcModeDisabled;                     /**< \brief Specifies the CRC mode disabled mode. Range: TRUE if CRC is disabled, FALSE if CRC is enabled. */
    boolean                         crcMethodDisabled;                   /**< \brief Specifies the CRC with zero nibbles disabled or enabled. Range: TRUE if augmentation is switched off for both 4-bit message CRC and the 4-
                                                                                     bit CRC of the serial messages, FALSE if augmentation is selected for both 4-bit message CRC and the 4-bit CRC of the serial messages. */
    boolean                         alternateCrcSelected;                /**< \brief Specifies the CRC is calculated for both fast and serial messages. Range: TRUE if 4 bit in parallel CRC calculation as used e.g. in hall
                                                                                     sensor TLE4998C, FALSE if Serial CRC calculation as specified in J2716 JAN2010. */
    boolean                         serialDataProcessingEnabled;         /**< \brief Specifies the serial data processing mode. Range: TRUE if automatic Serial Data Processing is enabled, FALSE if automatic Serial Data Processing is disabled. */
    boolean                         serialDataDisabledCrcDisabled;       /**< \brief Specifies the CRC disable for serial data disabled mode. Range: TRUE if CRC is disabled CRC nibble can be read from SDSx, FALSE if CRC is enabled. */
    boolean                         statusNibbleEnabled;                 /**< \brief Specifies the status nibble to include in CRC. Range: TRUE if status Nibble included in CRC, FALSE if status Nibble not included in CRC. */
    boolean                         driftErrorsDisabled;                 /**< \brief Specifies the drift errors enabled or disabled. Range: TRUE if drift Errors disabled, FALSE if drift Errors enabled. */
    boolean                         endPulseIgnored;                     /**< \brief Specifies the pause pulse during synchronization. Range: TRUE if end Pulse ignored, FALSE if end Pulse not ignored. */
    boolean                         suspendTriggered;                    /**< \brief Specifies the suspend trigger disables the channel or not. Range: TRUE if an OCDS suspend trigger disables the SENT channel, FALSE if an OCDS suspend trigger is ignored by this SENT channel. */
    uint8                           frameLength;                         /**< \brief Specifies frame length in nibbles. Range: 0 to 0xFF. */
    IfxSent_FrameCheckMode          frameCheckMode;                      /**< \brief Specifies the frame check mode for valid frame */
    IfxSent_ExtendedSerialFrameMode extendedSerialFrameMode;             /**< \brief Specifies the extended serial frame mode */
    boolean                         frequencyDriftCheckEnabled;          /**< \brief Specifies the frequency drift check based on frame length is enable or disable */
} IfxSent_Sent_ReceiveControl;

/** \brief Specifies the SPC channel properties structure
 */
typedef struct
{
    uint8                 pulseLength;            /**< \brief Specifies the pulse length in ticktimes. Range: 0 to 0x3F. */
    uint8                 pulseDelayLength;       /**< \brief Specifies the pulse delay length. Range: 0 to 0x3F. */
    IfxSent_TriggerSource triggerSource;          /**< \brief Specifies the trigger source and mode */
    IfxSent_TimeBase      timeBase;               /**< \brief Specifies the pulse time base */
    IfxSent_SpcMode       spcMode;                /**< \brief Specifies the SENT SPC operational mode */
} IfxSent_Sent_TransmitControl;

/** \} */

/** \addtogroup IfxLld_Sent_Sent_Structures
 * \{ */
/** \brief Specifies the SENT Channel handle structure
 */
typedef struct
{
    IfxSent_Sent     *driver;          /**< \brief Specifies the pointer to SENT module handler */
    Ifx_SENT_CH      *channel;         /**< \brief Specifies the pointer SENT channel registers */
    IfxSent_ChannelId channelId;       /**< \brief Specifies the SENT channel number */
} IfxSent_Sent_Channel;

/** \brief Specifies the SENT Channel configuration structure
 */
typedef struct
{
    IfxSent_Sent                     *driver;                    /**< \brief Specifies the pointer to SENT module handler */
    uint16                            watchDogTimerLimit;        /**< \brief Speciifes the enabled interrupts for each Channel. Range: 0 to 0xFFFF. */
    IfxSent_ChannelId                 channelId;                 /**< \brief Specifies the SENT channel number */
    IfxSent_Sent_InputOutputControl   inputOutputControl;        /**< \brief Specifies the input output controllable properties */
    IfxSent_Sent_ReceiveControl       receiveControl;            /**< \brief Specifies the receive control properties */
    IfxSent_Sent_TransmitControl      transmitControl;           /**< \brief Specifies the transmit control properties */
    IfxSent_Sent_InterruptNodeControl interuptNodeControl;       /**< \brief Specifies the interrupt control properties structure */
    IFX_CONST IfxSent_Sent_Pins      *pins;                      /**< \brief Specifies the pins configuration for SENT channel */
    float32                           tUnit;                     /**< \brief desired unit time (f_tick), e.g. 3E-6 for 3 uS */
    IfxSent_Sent_NibbleControl        nibbleControl;             /**< \brief Specifies the received nibbles control properties */
    IfxSent_Sent_Interrupt            interrupt;                 /**< \brief Specifies the interrupt control properties structure.*/
    boolean                           spcModeOn;                 /**< \brief Specifies the SENT SPC mode enable/disable. Range: TRUE if SPC mode is enabled, FALSE if if SPC mode is disabled. */
    IfxSent_Sent_EnabledInterrupts    enabledInterrupts;
} IfxSent_Sent_ChannelConfig;

/** \brief Specifies the SENT module configuration structure
 */
typedef struct
{
    Ifx_SENT *module;                    /**< \brief Specifies pointer to SENT registers */
    boolean   sleepModeEnabled;          /**< \brief Specifies SENT enable/disable. Range: TRUE if sleep mode enable, FALSE if sleep mode disable. */
    uint32    timeStampPreDivider;       /**< \brief Specifies the pre-divider to get clock in time stamp.Range: 0 to 0xFFFFF. */
} IfxSent_Sent_Config;

/** \brief Specifies the frame configuration structure for a channel
 */
typedef struct
{
    uint32 data;               /**< \brief Contains the data from last received frame. Range: 0 to 0xFFFFFFFF. */
    uint32 timeStamp;          /**< \brief Contains the timestamp of last received frame. Range: 0 to 0xFFFFFFFF. */
    uint8  statusNibble;       /**< \brief Contains the status and communication Nibble of last received frame 0 to 0xF. */
} IfxSent_Sent_Frame;

/** \brief Specifies received message frame
 */
typedef struct
{
    uint8             crc;              /**< \brief Contains the received CRC value 0 to 0x3F. */
    uint8             messageId;        /**< \brief Contains the received message ID value.Range: 0 to 0xFF. */
    uint16            serialData;       /**< \brief Contains the received serial data value. Range: 0 to 0xFFFF. */
    IfxSent_ConfigBit configBit;        /**< \brief Contains the received configuration bit value */
} IfxSent_Sent_SerialMessageFrame;

/** \} */

/** \addtogroup IfxLld_Sent_Sent_Module
 * \{ */

/******************************************************************************/
/*-------------------------Global Function Prototypes-------------------------*/
/******************************************************************************/

/**
 * \brief Resets the SENT module to its initial state.
 *
 * \param[inout] driver Pointer to the SENT module handler.
 *
 * \retval None
 * 
 */
IFX_EXTERN void IfxSent_Sent_deInitModule(IfxSent_Sent *driver);

/** \brief Initialise the SENT with the supplied configuration.
 *
 * \param[inout] driver Pointer to the SENT module handler.
 * \param[in]    config Pointer to the SENT module configuration.
 *
 * \retval TRUE If initialization successful.
 *         FALSE If initialization unsuccessful.
 *
 * Usage example: see \ref IfxLld_Sent_Sent_Usage
 *
 */
IFX_EXTERN boolean IfxSent_Sent_initModule(IfxSent_Sent *driver, const IfxSent_Sent_Config *config);

/**
 * \brief Initializes the SENT module configuration structure with default values.
 *
 * \param[inout] config Pointer to the SENT module configuration.
 *
 * \param[in]    sent   Pointer to the base address of the SENT register space.
 *
 * \retval None
 *
 * Usage example: see \ref IfxLld_Sent_Sent_Usage
 *
 */
IFX_EXTERN void IfxSent_Sent_initModuleConfig(IfxSent_Sent_Config *config, Ifx_SENT *sent);

/** \} */

/** \addtogroup IfxLld_Sent_Sent_Channel
 * \{ */

/******************************************************************************/
/*-------------------------Inline Function Prototypes-------------------------*/
/******************************************************************************/

/** \brief Copies the current interrupt flags into the Ifx_SENT_CH_INTSTAT structure, and clears the flags in hardware.
 * This function should be used in an ISR to retrieve the events which triggered the interrupt.

 * \param[inout] channel Pointer to the SENT channel handle structure.
 *
 * \retval Ifx_SENT_CH_INTSTAT The interrupt flags that were cleared.
 *
 * Usage example: see \ref IfxLld_Sent_Sent_Usage
 *
 */
IFX_INLINE Ifx_SENT_CH_INTSTAT IfxSent_Sent_getAndClearInterruptStatus(IfxSent_Sent_Channel *channel);

/******************************************************************************/
/*-------------------------Global Function Prototypes-------------------------*/
/******************************************************************************/

/**
 * \brief Initializes the SENT channel with the specified configuration.
 *
 * \param[inout] channel Pointer to the SENT channel handle structure.
 * \param[in]    config  Pointer to the SENT channel configuration.
 *
 * \retval TRUE If the configuration is valid and initialization is successful.
 *         FALSE If the configuration is invalid or initialization fails.
 *
 * Usage example: see \ref IfxLld_Sent_Sent_Usage
 *
 */
IFX_EXTERN boolean IfxSent_Sent_initChannel(IfxSent_Sent_Channel *channel, const IfxSent_Sent_ChannelConfig *config);

/**
 * \brief Initializes the SENT channel configuration structure with default values.
 *
 * \param[inout] config Pointer to the SENT channel configuration.
 * \param[in]    driver Pointer to the SENT module handler.
 *
 * \retval None
 *
 * Usage example: see \ref IfxLld_Sent_Sent_Usage
 *
 */
IFX_EXTERN void IfxSent_Sent_initChannelConfig(IfxSent_Sent_ChannelConfig *config, IfxSent_Sent *driver);

/**
 * \brief Reads the nibbles received in the Data register from a specified SENT channel and stores the data in the provided frame structure.
 *
 * \param[in]    channel Pointer to the SENT channel handle structure.
 * \param[inout] frame   Pointer to the frame structure where the received data, timestamp, and status nibble will be stored.
 *
 * \retval TRUE If data was successfully received and stored in the frame structure.
 *         FALSE If no data was received.
 * 
 * Usage example: see \ref IfxLld_Sent_Sent_Usage
 *
 */
IFX_EXTERN boolean IfxSent_Sent_readChannelSerialDataFrame(IfxSent_Sent_Channel *channel, IfxSent_Sent_Frame *frame);

/**
 * \brief Reads the serial data received and collected over several SENT frames from a specified channel.
 *
 * \param[in] channel    Pointer to the SENT channel handle structure.
 * \param[inout] message Pointer to the structure where the received serial message frame data will be stored. This structure includes fields for CRC, message ID, serial data, and configuration bit.
 *
 * \retval TRUE If a serial message was successfully received and stored in the message structure.
 *         FALSE If no serial message was received.
 *
 * Usage example: see \ref IfxLld_Sent_Sent_Usage
 *
 */
IFX_EXTERN boolean IfxSent_Sent_readChannelSerialMessageFrame(IfxSent_Sent_Channel *channel, IfxSent_Sent_SerialMessageFrame *message);

/** \} */

/******************************************************************************/
/*-------------------------Global Function Prototypes-------------------------*/
/******************************************************************************/

/**
 * \brief Generates SPC signal for the sensor and configures pulse timing parameters.
 *
 * \param[inout] channel     Pointer to the SENT channel handle structure.
 * \param[in]    pulseLength Configures the length of the SPC pulse. Range: 0 to 63.
 * \param[in]    delay       Configures the start delay of the SPC pulse. Range: 0 to 63.
 *
 * \retval None
 *
 */
IFX_EXTERN void IfxSent_Sent_spcPulseUpdate(IfxSent_Sent_Channel *channel, uint8 pulseLength, uint8 delay);

/**
 * \brief Triggers the SPC signal for the specified SENT channel.
 *
 * \param[inout] channel Pointer to the SENT channel handle structure.
 *
 * \retval None
 *
 */
IFX_EXTERN void IfxSent_Sent_spcPulseTrigger(IfxSent_Sent_Channel *channel);

/******************************************************************************/
/*---------------------Inline Function Implementations------------------------*/
/******************************************************************************/

IFX_INLINE Ifx_SENT_CH_INTSTAT IfxSent_Sent_getAndClearInterruptStatus(IfxSent_Sent_Channel *channel)
{
    return IfxSent_getAndClearInterruptStatus(channel->driver->sent, channel->channelId);
}


#endif /* IFXSENT_SENT_H */
