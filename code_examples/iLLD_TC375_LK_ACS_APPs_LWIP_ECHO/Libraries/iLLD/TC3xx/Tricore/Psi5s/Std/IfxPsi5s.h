/**
 * \file IfxPsi5s.h
 * \brief PSI5S  basic functionality
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
 * \defgroup IfxLld_Psi5s_Std_Enumerations Enumerations
 * \ingroup IfxLld_Psi5s_Std
 * \defgroup IfxLld_Psi5s_Std_Channel Channel Operative Functions
 * \ingroup IfxLld_Psi5s_Std
 * \defgroup IfxLld_Psi5s_Std_IO IO Pin Configuration Functions
 * \ingroup IfxLld_Psi5s_Std
 * \defgroup IfxLld_Psi5s_Std_Interrupt Interrupt configuration functions
 * \ingroup IfxLld_Psi5s_Std
 * \defgroup IfxLld_Psi5s_Std_Module Module Functions
 * \ingroup IfxLld_Psi5s_Std
 */

#ifndef IFXPSI5S_H
#define IFXPSI5S_H 1

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include "_Impl/IfxPsi5s_cfg.h"
#include "_PinMap/IfxPsi5s_PinMap.h"
#include "Cpu/Std/IfxCpu_Intrinsics.h"
#include "IfxPsi5s_bf.h"
#include "IfxPsi5s_reg.h"
#include "Src/Std/IfxSrc.h"
#include "Scu/Std/IfxScuCcu.h"

/******************************************************************************/
/*--------------------------------Enumerations--------------------------------*/
/******************************************************************************/

/** \addtogroup IfxLld_Psi5s_Std_Enumerations
 * \{ */
/** \brief MODULE_PSI5S.IOCR.ALTI:Alternate input
 */
typedef enum
{
    IfxPsi5s_AlternateInput_0 = 0,      /**< \brief Alternate Input 0  */
    IfxPsi5s_AlternateInput_1,          /**< \brief Alternate Input 1  */
    IfxPsi5s_AlternateInput_2,          /**< \brief Alternate Input 2  */
    IfxPsi5s_AlternateInput_3           /**< \brief Alternate Input 3  */
} IfxPsi5s_AlternateInput;

/** \brief MODULE_PSI5S.BG.BR_VALUE:Baudrate prescalar select
 */
typedef enum
{
    IfxPsi5s_AscBaudratePrescalar_divideBy2 = 0,  /**< \brief Divide by 2 is selected for baudrate timer prescalar */
    IfxPsi5s_AscBaudratePrescalar_divideBy3 = 1   /**< \brief Divide by 3 is selected for baudrate timer prescalar */
} IfxPsi5s_AscBaudratePrescalar;

/** \brief MODULE_PSI5S.CON.M:ASC mode of operation
 */
typedef enum
{
    IfxPsi5s_AscMode_sync                     = 0,  /**< \brief Synchronous mode */
    IfxPsi5s_AscMode_async_8bitData           = 1,  /**< \brief Asynchronous mode with 8 bit data */
    IfxPsi5s_AscMode_async_7bitDataWithParity = 3,  /**< \brief Asynchronous mode with 7 bit data with parity */
    IfxPsi5s_AscMode_async_9bitData           = 4,  /**< \brief Asynchronous mode with 9 bit data */
    IfxPsi5s_AscMode_async_8bitDataWithWakeup = 5,  /**< \brief Asynchronous mode with 8 bit data with wakeup */
    IfxPsi5s_AscMode_async_8bitDataWithParity = 7   /**< \brief Asynchronous mode with 8 bit data with parity */
} IfxPsi5s_AscMode;

/** \brief MODULE_PSI5S.CON.STP: Number of stop bits
 */
typedef enum
{
    IfxPsi5s_AscStopBits_1 = 0,      /**< \brief 1 stop bit  */
    IfxPsi5s_AscStopBits_2           /**< \brief 2 stop bit  */
} IfxPsi5s_AscStopBits;

/** \brief PSI5S Channel Id defined in MODULE_PSI5S.RDS.B.CID.
 */
typedef enum
{
    IfxPsi5s_ChannelId_0 = 0,     /**< \brief Ifx_PSI5S Channel 0  */
    IfxPsi5s_ChannelId_1,         /**< \brief Ifx_PSI5S Channel 1  */
    IfxPsi5s_ChannelId_2,         /**< \brief Ifx_PSI5S Channel 2  */
    IfxPsi5s_ChannelId_3,         /**< \brief Ifx_PSI5S Channel 3  */
    IfxPsi5s_ChannelId_4,         /**< \brief Ifx_PSI5S Channel 4  */
    IfxPsi5s_ChannelId_5,         /**< \brief Ifx_PSI5S Channel 5  */
    IfxPsi5s_ChannelId_6,         /**< \brief Ifx_PSI5S Channel 6  */
    IfxPsi5s_ChannelId_7,         /**< \brief Ifx_PSI5S Channel 7  */
    IfxPsi5s_ChannelId_none = -1  /**< \brief None of the Ifx_PSI5S Channels */
} IfxPsi5s_ChannelId;

/** \brief Clock Selection
 */
typedef enum
{
    IfxPsi5s_ClockType_fracDiv    = 0,  /**< \brief Fractional Divide clock */
    IfxPsi5s_ClockType_timeStamp  = 1,  /**< \brief Timestamp clock */
    IfxPsi5s_ClockType_ascFracDiv = 2,  /**< \brief Asc Fractional divider clock */
    IfxPsi5s_ClockType_ascOutput  = 3   /**< \brief Asc output clock */
} IfxPsi5s_ClockType;

/** \brief MODULE_PSI5S.RCRAx.CRCy(x= 0,1,..7:y=0,1,..,5),MODULE_PSI5S.RCRBx.CRCy(x= 0,1,..7:y=0,1,..,5)CRC or parity
 */
typedef enum
{
    IfxPsi5s_CrcOrParity_parity = 0,  /**< \brief parity selection */
    IfxPsi5s_CrcOrParity_crc    = 1   /**< \brief CRC selection */
} IfxPsi5s_CrcOrParity;

/** \brief MODULE_PSI5S.FDR.DM;MODULE_PSI5S.FDRT.B.DM:Divider mode
 */
typedef enum
{
    IfxPsi5s_DividerMode_spb        = 0,  /**< \brief divider mode is off */
    IfxPsi5s_DividerMode_normal     = 1,  /**< \brief divider mode is normal */
    IfxPsi5s_DividerMode_fractional = 2,  /**< \brief divider mode is fractional */
    IfxPsi5s_DividerMode_off        = 3   /**< \brief divider mode is off */
} IfxPsi5s_DividerMode;

/** \brief MODULE_PSI5S.SCRx.EPS(x=0,1,...,7):Enhanced protocol types
 */
typedef enum
{
    IfxPsi5s_EnhancedProtocol_toothGapMethod              = 0,  /**< \brief toothGapMethod Enhanced protocol type */
    IfxPsi5s_EnhancedProtocol_pulseWidth_frameFormat_1to3 = 1,  /**< \brief pulseWidth_frameFormat_1to3 Enhanced protocol type */
    IfxPsi5s_EnhancedProtocol_pulseWidth_frameFormat_4    = 3   /**< \brief pulseWidth_frameFormat_4 Enhanced protocol type */
} IfxPsi5s_EnhancedProtocol;

/** \brief MODULE_PSI5S.RCRAx.FIDS(x=0,1,....,7):.Frame ID updation
 */
typedef enum
{
    IfxPsi5s_FrameId_frameHeader   = 0, /**< \brief Frame ID is updated from packet frame header (Sync mode) */
    IfxPsi5s_FrameId_rollingNumber = 1  /**< \brief Frame ID is a rolling number 0 .. 5 copied from FCNT */
} IfxPsi5s_FrameId;

/** \brief MODULE_PSI5S.GCR.IDT:Idle time bit count
 */
typedef enum
{
    IfxPsi5s_IdleTime_1 = 0,      /**< \brief 1 bit Idle time  */
    IfxPsi5s_IdleTime_2,          /**< \brief 2 bit Idle time  */
    IfxPsi5s_IdleTime_3,          /**< \brief 3 bit Idle time  */
    IfxPsi5s_IdleTime_4,          /**< \brief 4 bit Idle time  */
    IfxPsi5s_IdleTime_5,          /**< \brief 5 bit Idle time  */
    IfxPsi5s_IdleTime_6,          /**< \brief 6 bit Idle time  */
    IfxPsi5s_IdleTime_7,          /**< \brief 7 bit Idle time  */
    IfxPsi5s_IdleTime_8,          /**< \brief 8 bit Idle time  */
    IfxPsi5s_IdleTime_9,          /**< \brief 9 bit Idle time  */
    IfxPsi5s_IdleTime_10,         /**< \brief 10 bit Idle time  */
    IfxPsi5s_IdleTime_11,         /**< \brief 11 bit Idle time  */
    IfxPsi5s_IdleTime_12,         /**< \brief 12 bit Idle time  */
    IfxPsi5s_IdleTime_13,         /**< \brief 13 bit Idle time  */
    IfxPsi5s_IdleTime_14,         /**< \brief 14 bit Idle time  */
    IfxPsi5s_IdleTime_15,         /**< \brief 15 bit Idle time  */
    IfxPsi5s_IdleTime_16          /**< \brief 16 bit Idle time  */
} IfxPsi5s_IdleTime;

/** \brief Enable/Disable interrupt request .defined in MODULE_PSI5S.INTEN[x]
 */
typedef enum
{
    IfxPsi5s_InterruptRequest_disabled = 0,  /**< \brief no interrupt request can be generated for this source */
    IfxPsi5s_InterruptRequest_enabled  = 1   /**< \brief An Interrupt request can be generated for source */
} IfxPsi5s_InterruptRequest;

/** \brief Enable/Disable the interrupt and  select interrupt source pointer defined in MODULE_PSI5S.INTEN[x].U
 * and MODULE_PSI5S.INP[x].U
 */
typedef enum
{
    IfxPsi5s_InterruptSource_rsi  = 0,
    IfxPsi5s_InterruptSource_rdi  = 1,  /**< \brief Enable Interrupt Request RDI */
    IfxPsi5s_InterruptSource_rbi  = 2,  /**< \brief Enable Interrupt Request RBI */
    IfxPsi5s_InterruptSource_tei  = 3,  /**< \brief Enable Interrupt Request TEI */
    IfxPsi5s_InterruptSource_chci = 4,  /**< \brief Enable Interrupt Request CHCI */
    IfxPsi5s_InterruptSource_crci = 5,  /**< \brief Enable Interrupt Request CRCI */
    IfxPsi5s_InterruptSource_tpi  = 6,  /**< \brief Enable Interrupt Request TPI */
    IfxPsi5s_InterruptSource_tpoi = 7,  /**< \brief Enable Interrupt Request TPOI */
    IfxPsi5s_InterruptSource_hdi  = 8   /**< \brief Enable Interrupt Request HDI */
} IfxPsi5s_InterruptSource;

/** \brief Enable/Disable Loop back Mode
 */
typedef enum
{
    IfxPsi5s_LoopBackMode_disable = 0,  /**< \brief loop-back mode disabled */
    IfxPsi5s_LoopBackMode_enable  = 1   /**< \brief loop-back mode enabled */
} IfxPsi5s_LoopBackMode;

/** \brief Messaging bits presence
 */
typedef enum
{
    IfxPsi5s_MessagingBits_absent  = 0, /**< \brief No messaging bits */
    IfxPsi5s_MessagingBits_present = 1  /**< \brief 2 messaging bits */
} IfxPsi5s_MessagingBits;

/** \brief MODULE_PSI5S.NFC.NFx:Expected Psi5s frames
 */
typedef enum
{
    IfxPsi5s_NumberExpectedFrames_1 = 1,      /**< \brief 1 psi5s frame expected  */
    IfxPsi5s_NumberExpectedFrames_2,          /**< \brief 2 psi5s frame expected  */
    IfxPsi5s_NumberExpectedFrames_3,          /**< \brief 3 psi5s frame expected  */
    IfxPsi5s_NumberExpectedFrames_4,          /**< \brief 4 psi5s frame expected  */
    IfxPsi5s_NumberExpectedFrames_5,          /**< \brief 5 psi5s frame expected  */
    IfxPsi5s_NumberExpectedFrames_6           /**< \brief 6 psi5s frame expected  */
} IfxPsi5s_NumberExpectedFrames;

/** \brief Enable/disable the sensitivity of the module to sleep signal\n
 * Definition in Ifx_PSI5S.CLC.B.EDIS
 */
typedef enum
{
    IfxPsi5s_SleepMode_enable  = 0, /**< \brief enables sleep mode */
    IfxPsi5s_SleepMode_disable = 1  /**< \brief disables sleep mode */
} IfxPsi5s_SleepMode;

/** \brief OCDS Suspend Control (OCDS.SUS)
 */
typedef enum
{
    IfxPsi5s_SuspendMode_none = 0,  /**< \brief No suspend */
    IfxPsi5s_SuspendMode_hard = 1,  /**< \brief Hard Suspend */
    IfxPsi5s_SuspendMode_soft = 2   /**< \brief Soft Suspend */
} IfxPsi5s_SuspendMode;

/** \brief MODULE_PSI5S.TSCNTA.B.TBS;MODULE_PSI5S.TSCNTB.B.TBS:Time base
 */
typedef enum
{
    IfxPsi5s_TimeBase_internal = 0,  /**< \brief Internal time stamp clock */
    IfxPsi5s_TimeBase_external = 1   /**< \brief External GTM inputs */
} IfxPsi5s_TimeBase;

/** \brief Start/stop Current time stamp count
 */
typedef enum
{
    IfxPsi5s_TimeStampCount_stopped = 0,  /**< \brief CTS stopped */
    IfxPsi5s_TimeStampCount_started = 1   /**< \brief CTS Started */
} IfxPsi5s_TimeStampCount;

/** \brief MODULE_PSI5S.TSCNTx(x= A,B):Timestamp register
 */
typedef enum
{
    IfxPsi5s_TimestampRegister_a = 0,  /**< \brief Timestamp register A */
    IfxPsi5s_TimestampRegister_b = 1   /**< \brief Timestamp register B */
} IfxPsi5s_TimestampRegister;

/** \brief MODULE_PSI5S.RCRAx.TSTS:Timestamp trigger
 */
typedef enum
{
    IfxPsi5s_TimestampTrigger_syncPulse = 0,  /**< \brief Timestamp trigger on sync pulse */
    IfxPsi5s_TimestampTrigger_frame     = 1   /**< \brief Timestamp trigger on any frame */
} IfxPsi5s_TimestampTrigger;

/** \brief MODULE_PSI5S.TSCNTA.B.ETB;MODULE_PSI5S.TSCNTB.B.ETB:Trigger Id
 */
typedef enum
{
    IfxPsi5s_Trigger_0 = 0,      /**< \brief Trigger 0  */
    IfxPsi5s_Trigger_1,          /**< \brief Trigger 1  */
    IfxPsi5s_Trigger_2,          /**< \brief Trigger 2  */
    IfxPsi5s_Trigger_3,          /**< \brief Trigger 3  */
    IfxPsi5s_Trigger_4,          /**< \brief Trigger 4  */
    IfxPsi5s_Trigger_5,          /**< \brief Trigger 5  */
    IfxPsi5s_Trigger_6,          /**< \brief Trigger 6  */
    IfxPsi5s_Trigger_7           /**< \brief Trigger 7  */
} IfxPsi5s_Trigger;

/** \brief specifies service request line defined in MODULE_PSI5S.INP[x].U
 */
typedef enum
{
    IfxPsi5s_TriggerOutput_0 = 0,      /**< \brief Triggered output line is TRIGO_0  */
    IfxPsi5s_TriggerOutput_1,          /**< \brief Triggered output line is TRIGO_1  */
    IfxPsi5s_TriggerOutput_2,          /**< \brief Triggered output line is TRIGO_2  */
    IfxPsi5s_TriggerOutput_3,          /**< \brief Triggered output line is TRIGO_3  */
    IfxPsi5s_TriggerOutput_4,          /**< \brief Triggered output line is TRIGO_4  */
    IfxPsi5s_TriggerOutput_5,          /**< \brief Triggered output line is TRIGO_5  */
    IfxPsi5s_TriggerOutput_6,          /**< \brief Triggered output line is TRIGO_6  */
    IfxPsi5s_TriggerOutput_7           /**< \brief Triggered output line is TRIGO_7  */
} IfxPsi5s_TriggerOutput;

/** \brief Trigger type external / periodic
 */
typedef enum
{
    IfxPsi5s_TriggerType_periodic = 0,  /**< \brief Periodic trigger */
    IfxPsi5s_TriggerType_external = 1   /**< \brief External trigger */
} IfxPsi5s_TriggerType;

/** \brief MODULE_PSI5S.RCRAx.UFCY(x=0,1,...7;y=0,1...5):UART frame count
 */
typedef enum
{
    IfxPsi5s_UartFrameCount_3 = 0,      /**< \brief 3 UART frames  */
    IfxPsi5s_UartFrameCount_4,          /**< \brief 4 UART frames  */
    IfxPsi5s_UartFrameCount_5,          /**< \brief 5 UART frames  */
    IfxPsi5s_UartFrameCount_6           /**< \brief 6 UART frames  */
} IfxPsi5s_UartFrameCount;

/** \brief MODULE_PSI5S.RCRAx.WDMS:Watchdog timer mode
 */
typedef enum
{
    IfxPsi5s_WatchdogTimerMode_frame     = 0, /**< \brief Watch Dog Timer is restarted on reception of each recoverable frame (async mode) */
    IfxPsi5s_WatchdogTimerMode_syncPulse = 1  /**< \brief Watch Dog Timer is restarted on Sync Pulse and stopped at reception of the last frame configured in NFC.NFx.(sync mode) */
} IfxPsi5s_WatchdogTimerMode;

/** \} */

/** \brief List of Global interrupt sources or registers INTxG
 */
typedef enum
{
    IfxPsi5s_GlobalInterruptSource_tir   = 0,  /**< \brief Enable Interrupt Request TIR */
    IfxPsi5s_GlobalInterruptSource_rir   = 1,  /**< \brief Enable Interrupt Request RIR */
    IfxPsi5s_GlobalInterruptSource_eir   = 2,  /**< \brief Enable Interrupt Request EIR */
    IfxPsi5s_GlobalInterruptSource_tbir  = 3,  /**< \brief Enable Interrupt Request TBIR */
    IfxPsi5s_GlobalInterruptSource_xcrci = 4,  /**< \brief Enable Interrupt Request XCRCI */
    IfxPsi5s_GlobalInterruptSource_foi   = 5   /**< \brief Enable Interrupt Request FOI */
} IfxPsi5s_GlobalInterruptSource;

/** \addtogroup IfxLld_Psi5s_Std_Channel
 * \{ */

/******************************************************************************/
/*-------------------------Inline Function Prototypes-------------------------*/
/******************************************************************************/

/**
 * \brief Fills data into the transmit buffer for direct transmission in ASC mode.
 *
 * \param[inout] psi5s    Pointer to the PSI5S register space structure.
 * \param[in]    data     Pointer to the data to be filled into the transmit buffer.
 *
 * \retval None
 */
IFX_INLINE void IfxPsi5s_fillAscTransmitBuffer(Ifx_PSI5S *psi5s, uint32 *data);

/**
 * \brief Retrieves the received buffer value in ASC mode for the PSI5S module.
 *
 * \param[in]    psi5s    Pointer to the PSI5S register space structure.
 * 
 * \retval uint32 The received buffer value in ASC mode. Range 0 to 0x1FF
 */
IFX_INLINE uint32 IfxPsi5s_getReceiveBuffer(Ifx_PSI5S *psi5s);

/******************************************************************************/
/*-------------------------Global Function Prototypes-------------------------*/
/******************************************************************************/

/**
 * \brief Disables the ASC receiver module of the PSI5S interface.
 *
 * \param[inout] psi5s    Pointer to the PSI5S module registers structure.
 *
 * \retval None
 */
IFX_EXTERN void IfxPsi5s_disableAscReceiver(Ifx_PSI5S *psi5s);

/**
 * \brief Enables the ASC receiver module.
 *
 * \param[inout] psi5s    Pointer to the PSI5S peripheral's register space.
 *
 * \retval None
 */
IFX_EXTERN void IfxPsi5s_enableAscReceiver(Ifx_PSI5S *psi5s);

/**
 * \brief Enables or disables specified channel trigger counters based on the provided mask.
 *
 * \param[inout] psi5s     Pointer to the PSI5S register space.
 * \param[in]    channels  Bitmask specifying the channel trigger counters to enable or disable. Range: \ref IfxPsi5s_ChannelId
 * \param[in]    mask      Bitmask indicating which channel trigger counters should be modified. Range: \ref IfxPsi5s_ChannelId
 *
 * \retval None
 */
IFX_EXTERN void IfxPsi5s_enableDisableChannelTriggerCounters(Ifx_PSI5S *psi5s, uint32 channels, uint32 mask);

/**
 * \brief Enable/disable any combination of channels selected by mask parameter
 *
 * \param[inout] psi5s     Pointer to the PSI5S register space.
 * \param[in]    channels  Specifies which channels should be enabled or disabled. Use bitwise OR to combine
 *                         multiple channels. Range: \ref IfxPsi5s_ChannelId
 * \param[in]    mask      Specifies which channels should be modified. Use bitwise OR to combine multiple
 *                         channels. Range: \ref IfxPsi5s_ChannelId
 *
 * \retval None
 */
IFX_EXTERN void IfxPsi5s_enableDisableChannels(Ifx_PSI5S *psi5s, uint32 channels, uint32 mask);

/** 
 * \brief Function to get the baudrate frequency in HZ
 * 
 * \param[in]    psi5s              Pointer to PSI5s Register space
 * \param[in]    synchMode          Synchnous mode. Range 0: Asynchronous mode, 1: Synchronous mode
 * \param[in]    divMode            Specifies fractional/normal divider mode. Range 0: Fractional divider mode, 1: Normal divider mode
 * \param[in]    baudrateSelection  Select sbaudrate prescaler. \ref IfxPsi5s_AscBaudratePrescalar
 * 
 * \retval baudrate in HZ
 */
IFX_EXTERN float32 IfxPsi5s_getBaudrate(Ifx_PSI5S *psi5s, boolean synchMode, boolean divMode, IfxPsi5s_AscBaudratePrescalar baudrateSelection);

/**
 * \brief Starts ASC transactions on the PSI5S peripheral
 *
 * \param[inout] psi5s    Pointer to the PSI5S register space structure
 *
 * \retval None
 */
IFX_EXTERN void IfxPsi5s_startAscTransactions(Ifx_PSI5S *psi5s);

/**
 * \brief Stops all ongoing ASC transactions and resets the ASC state machine.
 *
 * \param[inout] psi5s    Pointer to the PSI5S module registers.
 *
 * \retval None
 */
IFX_EXTERN void IfxPsi5s_stopAscTransactions(Ifx_PSI5S *psi5s);

/** \} */

/** \addtogroup IfxLld_Psi5s_Std_IO
 * \{ */

/******************************************************************************/
/*-------------------------Inline Function Prototypes-------------------------*/
/******************************************************************************/

/**
 * \brief Initializes a CLK output pin with specified output mode and pad driver settings.
 *
 * \param[in]    clk         Pointer to the CLK pin configuration structure to be initialized.
 * \param[in]    outputMode  The output mode to be configured. \ref IfxPort_OutputMode
 * \param[in]    padDriver   The pad driver mode to be configured. \ref IfxPort_PadDriver
 *
 * \retval None
 */
IFX_INLINE void IfxPsi5s_initClkPin(const IfxPsi5s_Clk_Out *clk, IfxPort_OutputMode outputMode, IfxPort_PadDriver padDriver);

/**
 * \brief Initializes a RX input pin with specified input mode and pad driver settings.
 *
 * \param[in]    rx          Pointer to the RX pin configuration 
 * \param[in]    inputMode   The input mode to be configured for the RX pin. \ref IfxPort_InputMode
 * \param[in]    padDriver   The pad driver mode to be configured for the RX pin. \ref IfxPort_PadDriver
 *
 * \retval None
 */
IFX_INLINE void IfxPsi5s_initRxPin(const IfxPsi5s_Rx_In *rx, IfxPort_InputMode inputMode, IfxPort_PadDriver padDriver);

/**
 * \brief Initializes a TX output pin with specified output mode and pad driver settings.
 *
 * \param[in]    tx          Pointer to the TX pin configuration structure to be initialized.
 * \param[in]    outputMode  The output mode to be configured for the TX pin. \ref IfxPort_OutputMode
 * \param[in]    padDriver   The pad driver mode to be configured for the TX pin. \ref IfxPort_PadDriver
 *
 * \retval None
 */
IFX_INLINE void IfxPsi5s_initTxPin(const IfxPsi5s_Tx_Out *tx, IfxPort_OutputMode outputMode, IfxPort_PadDriver padDriver);

/**
 * \brief Selects the alternate input for the Rx signal.
 *
 * \param[inout] psi5s       Pointer to the PSI5S registers structure.
 * \param[in]    alti        Alternate input selection for the Rx signal. \ref IfxPsi5s_AlternateInput
 *
 * \retval None
 */
IFX_INLINE void IfxPsi5s_setRxInput(Ifx_PSI5S *psi5s, IfxPsi5s_AlternateInput alti);

/** \} */

/** \addtogroup IfxLld_Psi5s_Std_Interrupt
 * \{ */

/******************************************************************************/
/*-------------------------Inline Function Prototypes-------------------------*/
/******************************************************************************/

/**
 * \brief Enables or disables the specified global interrupt source for the PSI5S module.
 *
 * \param[inout] psi5s             Pointer to the Ifx_PSI5S module space.
 * \param[in]    interruptSource   Specifies the global interrupt source to be enabled or disabled. \ref IfxPsi5s_GlobalInterruptSource
 * \param[in]    enabled           Boolean value indicating whether to enable (true) or disable (false) the interrupt source. \ref IfxPsi5s_InterruptRequest
 *
 * \retval None
 */
IFX_INLINE void IfxPsi5s_enableGlobalInterrupt(Ifx_PSI5S *psi5s, IfxPsi5s_GlobalInterruptSource interruptSource, IfxPsi5s_InterruptRequest enabled);

/**
 * \brief Enables or disables a specific interrupt source for the given PSI5S channel.
 *
 * \param[inout] psi5s             Pointer to the PSI5S register space.
 * \param[in]    channel           Specifies the channel number to configure. \ref IfxPsi5s_ChannelId
 * \param[in]    interruptSource   Specifies the interrupt source to enable or disable.\ref IfxPsi5s_InterruptSource
 * \param[in]    enabled           Enable or disable the interrupt request. This is an enumeration of type. \ref IfxPsi5s_InterruptRequest.
 *
 * \retval None
 */
IFX_INLINE void IfxPsi5s_enableInterrupt(Ifx_PSI5S *psi5s, IfxPsi5s_ChannelId channel, IfxPsi5s_InterruptSource interruptSource, IfxPsi5s_InterruptRequest enabled);

/**
 * \brief Get the receive interrupt status of the PSI5S module.
 *
 * \param[in]    psi5s             Pointer to the PSI5S register space.
 *
 * \retval TRUE If a receive interrupt is pending.
 *         FALSE If no receive interrupt is pending.
 */
IFX_INLINE boolean IfxPsi5s_getReceiveInterruptStatus(Ifx_PSI5S *psi5s);

/**
 * \brief Gets the transmit interrupt status of the PSI5S module.
 *
 * \param[in]    psi5s             Pointer to the PSI5S module instance.
 * 
 * \retval TRUE If a transmit interrupt is pending.
 *         FALSE If no transmit interrupt is pending.
 */
IFX_INLINE boolean IfxPsi5s_getTransmitInterruptStatus(Ifx_PSI5S *psi5s);

/**
 * \brief Configures the global interrupt node pointers for the PSI5-S module's ASC, XCRCI, and FOI
 * 
 * \param[inout] psi5s             Pointer to the PSI5S register space.
 * \param[in]    nodePointer       Specifies the global interrupt source node pointer to be configured. \ref IfxPsi5s_GlobalInterruptSource
 * \param[in]    triggerOutputLine Selects the trigger output line for the global interrupt. \ref IfxPsi5s_TriggerOutput
 *
 * \retval None
 */
IFX_INLINE void IfxPsi5s_setGlobalInterruptNodePointer(Ifx_PSI5S *psi5s, IfxPsi5s_GlobalInterruptSource nodePointer, IfxPsi5s_Trigger triggerOutputLine);

/**
 * \brief Sets the interrupt node pointer for a specified channel in the PSI5S module.
 *
 * \param[inout] psi5s             Pointer to the PSI5S module register space.
 * \param[in]    channel           Specifies the channel number to configure. \ref IfxPsi5s_ChannelId
 * \param[in]    nodePointer       Specifies the interrupt node pointer source. \ref IfxPsi5s_InterruptSource
 * \param[in]    triggerOutputLine Selects the service request line. \ref IfxPsi5s_TriggerOutput
 *
 * \retval None
 */
IFX_INLINE void IfxPsi5s_setInterruptNodePointer(Ifx_PSI5S *psi5s, IfxPsi5s_ChannelId channel, IfxPsi5s_InterruptSource nodePointer, IfxPsi5s_Trigger triggerOutputLine);

/** \} */

/** \addtogroup IfxLld_Psi5s_Std_Module
 * \{ */

/******************************************************************************/
/*-------------------------Inline Function Prototypes-------------------------*/
/******************************************************************************/

/**
 * \brief Clears the timestamp counter A of the PSI5S module.
 *
 * \param[inout] psi5s                 Pointer to the PSI5S module instance.
 * \param[in]    clearTimeStampCounter Boolean flag to clear the timestamp counter A by writing 1.
 *
 * \retval None
 */
IFX_INLINE void IfxPsi5s_clearTimeStampCounterA(Ifx_PSI5S *psi5s, boolean clearTimeStampCounter);

/**
 * \brief Clears the Time Stamp Counter B of the PSI5S module.
 *
 * \param[inout] psi5s                 Pointer to the PSI5S module instance.
 * \param[in]    clearTimeStampCounter Boolean flag to clear the timestamp counter B by writing 1.
 *
 * \retval None
 */
IFX_INLINE void IfxPsi5s_clearTimeStampCounterB(Ifx_PSI5S *psi5s, boolean clearTimeStampCounter);

/**
 * \brief Checks if the PSI5S module is in a suspended state.
 *
 * \param[in]    psi5s                 Pointer to the PSI5S module registers.
 *
 * \retval TRUE  The module is currently suspended.
 *         FALSE The module is not suspended and is operational.
 */
IFX_INLINE boolean IfxPsi5s_isModuleSuspended(Ifx_PSI5S *psi5s);

/**
 * \brief Enables or disables the loopback mode for the PSI5S module.
 * 
 * \param[inout] psi5s                 Pointer to the PSI5S register space.
 * \param[in]    enabled               Enable/disable loop back mode. \ref IfxPsi5s_LoopBackMode
 * 
 * \retval None
 */
IFX_INLINE void IfxPsi5s_setLoopBackMode(Ifx_PSI5S *psi5s, IfxPsi5s_LoopBackMode enabled);

/**
 * \brief Enables or disables the sleep mode of the PSI5S module.
 *
 * \param[inout] psi5s                 Pointer to the PSI5S register structure.
 * \param[in]    mode                  Sleep mode configuration. \ref IfxPsi5s_SleepMode
 *
 * \retval None
 */
IFX_INLINE void IfxPsi5s_setSleepMode(Ifx_PSI5S *psi5s, IfxPsi5s_SleepMode mode);

/**
 * \brief Configure the Module to Hard/Soft suspend mode.
 * 
 * \note The function will not work as expected if OCDS is enabled and in Supervisor Mode. When OCDS is disabled the OCS suspend control is ineffective.
 *
 * \param[inout] psi5s                 Pointer to the PSI5S module registers.
 * \param[in]    mode                  Suspend mode to be configured. \ref IfxPsi5s_SuspendMode
 *
 * \retval None
 */
IFX_INLINE void IfxPsi5s_setSuspendMode(Ifx_PSI5S *psi5s, IfxPsi5s_SuspendMode mode);

/**
 * \brief Starts or stops the timestamp counter A.
 *
 * \param[inout] psi5s                 Pointer to the PSI5S module space.
 * \param[in]    startTimeStamp        Start/stop the current timestamp count. \ref IfxPsi5s_TimeStampCount
 *
 * \retval None
 */
IFX_INLINE void IfxPsi5s_setTimeStampCounterA(Ifx_PSI5S *psi5s, IfxPsi5s_TimeStampCount startTimeStamp);

/**
 * \brief Starts or stops the Time Stamp Counter B.
 *
 * \param[inout] psi5s                 Pointer to the PSI5S module space.
 * \param[in]    startTimeStamp        The state of the time stamp counter. \ref IfxPsi5s_TimeStampCount
 *
 * \retval None
 */
IFX_INLINE void IfxPsi5s_setTimeStampCounterB(Ifx_PSI5S *psi5s, IfxPsi5s_TimeStampCount startTimeStamp);

/******************************************************************************/
/*-------------------------Global Function Prototypes-------------------------*/
/******************************************************************************/

/**
 * \brief Disables the PSI5S kernel
 *
 * \param[inout] psi5s                 Pointer to the base of PSI5S register space
 *
 * \retval None
 */
IFX_EXTERN void IfxPsi5s_disableModule(Ifx_PSI5S *psi5s);

/**
 * \brief Get the received psi5s frame status for the specified channel.
 *
 * \param[in]    psi5s                 Pointer to the PSI5S module instance.
 * \param[in]    channelId             Channel ID of the PSI5S channel. \ref IfxPsi5s_ChannelId
 *
 * \retval TRUE   A frame is available for reading.
 *         FALSE  No frame is available for reading.
 */
IFX_EXTERN boolean IfxPsi5s_getReadFrameStatus(Ifx_PSI5S *psi5s, IfxPsi5s_ChannelId channelId);

/**
 * \brief Indicates whether a frame was successfully received on the specified channel.
 *
 * \param[in]    psi5s                 Pointer to PSI5S module registers
 * \param[in]    channelId             Channel Number. \ref IfxPsi5s_ChannelId
 *
 * \retval TRUE Frame was successfully received
 *         FALSE Frame was not successfully received
 */
IFX_EXTERN boolean IfxPsi5s_getSuccessfullyReceivedFrameStatus(Ifx_PSI5S *psi5s, IfxPsi5s_ChannelId channelId);

/**
 * \brief Resets the PSI5S module to its initial state
 *
 * \param[inout] psi5s                 Pointer to the PSI5S registers structure.
 *
 * \retval None
 */
IFX_EXTERN void IfxPsi5s_resetModule(Ifx_PSI5S *psi5s);

/** \} */

/******************************************************************************/
/*-------------------------Inline Function Prototypes-------------------------*/
/******************************************************************************/

/**
 * \brief Retrieves the interrupt status for a specific channel and interrupt source in PSI5S.
 *
 * \param[in]    psi5s                 Pointer to the PSI5S SFR's base address.
 * \param[in]    channel               Channel ID of the channel whose interrupt status is to be retrieved. \ref IfxPsi5s_ChannelId
 * \param[in]    interruptSource       Interrupt source to check. \ref IfxPsi5s_InterruptSource
 *
 * \retval TRUE The interrupt is active for the specified channel and source.
 *         FALSE The interrupt is not active for the specified channel and source.
 */
IFX_INLINE boolean IfxPsi5s_getInterruptStatus(Ifx_PSI5S *psi5s, IfxPsi5s_ChannelId channel, IfxPsi5s_InterruptSource interruptSource);

/**
 * \brief Clears the interrupt status for a specified source within a given PSI5-S channel.
 *
 * \param[inout] psi5s                 Pointer to the base address of the PSI5-S module's SFR.
 * \param[in]    channel               Channel ID of the PSI5-S channel whose interrupt status needs to be cleared. \ref IfxPsi5s_ChannelId
 * \param[in]    interruptSource       The specific interrupt source to be cleared. \ref IfxPsi5s_InterruptSource
 * 
 * \retval None
 */
IFX_INLINE void IfxPsi5s_clearInterruptStatus(Ifx_PSI5S *psi5s, IfxPsi5s_ChannelId channel, IfxPsi5s_InterruptSource interruptSource);

/**
 * \brief Checks the status of a specified global interrupt source for the PSI5-S module.
 *
 * \param[in]    psi5s                 Pointer to the base address of the PSI5-S module's SFR registers.
 * \param[in]    interruptSource       The global interrupt source to check. \ref IfxPsi5s_GlobalInterruptSource
 *
 * \retval TRUE The specified global interrupt source is active.
 *         FALSE The specified global interrupt source is not active.
 */
IFX_INLINE boolean IfxPsi5s_getGlobalInterruptStatus(Ifx_PSI5S *psi5s, IfxPsi5s_GlobalInterruptSource interruptSource);

/**
 * \brief Clears the status of any interrupt of the ASC
 * 
 * \param[inout] psi5s                 Pointer to the base address of the PSI5-S SFR.
 * \param[in]    interruptSource       The global interrupt source to be cleared. \ref IfxPsi5s_GlobalInterruptSource
 *
 * \retval None
 */
IFX_INLINE void IfxPsi5s_clearGlobalInterruptStatus(Ifx_PSI5S *psi5s, IfxPsi5s_GlobalInterruptSource interruptSource);

/******************************************************************************/
/*-------------------------Global Function Prototypes-------------------------*/
/******************************************************************************/

/**
 * \brief Get the address of the SRC register for a specific channel.
 *
 * \param[in]    psi5s                 Pointer to the base address of the PSI5S SFR .
 * \param[in]    channel               Channel ID of the channel for which to get the SRC register address. \ref IfxPsi5s_ChannelId
 * 
 * \retval Ifx_SRC_SRCR* Pointer to the SRC register address.
 */
IFX_EXTERN volatile Ifx_SRC_SRCR *IfxPsi5s_getSrcAddress(Ifx_PSI5S *psi5s, IfxPsi5s_ChannelId channel);

/******************************************************************************/
/*---------------------Inline Function Implementations------------------------*/
/******************************************************************************/

IFX_INLINE void IfxPsi5s_clearTimeStampCounterA(Ifx_PSI5S *psi5s, boolean clearTimeStampCounter)
{
    psi5s->TSCNTA.B.CLRA = clearTimeStampCounter;
}


IFX_INLINE void IfxPsi5s_clearTimeStampCounterB(Ifx_PSI5S *psi5s, boolean clearTimeStampCounter)
{
    psi5s->TSCNTA.B.CLRB = clearTimeStampCounter;
}


IFX_INLINE void IfxPsi5s_enableGlobalInterrupt(Ifx_PSI5S *psi5s, IfxPsi5s_GlobalInterruptSource interruptSource, IfxPsi5s_InterruptRequest enabled)
{
    psi5s->INTENG.U |= (enabled << interruptSource);
}


IFX_INLINE void IfxPsi5s_enableInterrupt(Ifx_PSI5S *psi5s, IfxPsi5s_ChannelId channel, IfxPsi5s_InterruptSource interruptSource, IfxPsi5s_InterruptRequest enabled)
{
    psi5s->INTEN[channel].U |= (enabled << interruptSource);
}


IFX_INLINE void IfxPsi5s_fillAscTransmitBuffer(Ifx_PSI5S *psi5s, uint32 *data)
{
    psi5s->TBUF.U = *data;
}


IFX_INLINE uint32 IfxPsi5s_getReceiveBuffer(Ifx_PSI5S *psi5s)
{
    return psi5s->RBUF.U;
}


IFX_INLINE boolean IfxPsi5s_getReceiveInterruptStatus(Ifx_PSI5S *psi5s)
{
    return (boolean)psi5s->INTSTATG.B.RIR;
}


IFX_INLINE boolean IfxPsi5s_getTransmitInterruptStatus(Ifx_PSI5S *psi5s)
{
    return (boolean)psi5s->INTSTATG.B.TIR;
}


IFX_INLINE void IfxPsi5s_initClkPin(const IfxPsi5s_Clk_Out *clk, IfxPort_OutputMode outputMode, IfxPort_PadDriver padDriver)
{
    if (clk->pin.port != NULL_PTR)
    {
        IfxPort_setPinModeOutput(clk->pin.port, clk->pin.pinIndex, outputMode, clk->select);
        IfxPort_setPinPadDriver(clk->pin.port, clk->pin.pinIndex, padDriver);
    }
}


IFX_INLINE void IfxPsi5s_initRxPin(const IfxPsi5s_Rx_In *rx, IfxPort_InputMode inputMode, IfxPort_PadDriver padDriver)
{
    if (rx->pin.port != NULL_PTR)
    {
        IfxPort_setPinModeInput(rx->pin.port, rx->pin.pinIndex, inputMode);
        IfxPort_setPinPadDriver(rx->pin.port, rx->pin.pinIndex, padDriver);
        IfxPsi5s_setRxInput(rx->module, (IfxPsi5s_AlternateInput)rx->select);
    }
}


IFX_INLINE void IfxPsi5s_initTxPin(const IfxPsi5s_Tx_Out *tx, IfxPort_OutputMode outputMode, IfxPort_PadDriver padDriver)
{
    if (tx->pin.port != NULL_PTR)
    {
        IfxPort_setPinModeOutput(tx->pin.port, tx->pin.pinIndex, outputMode, tx->select);
        IfxPort_setPinPadDriver(tx->pin.port, tx->pin.pinIndex, padDriver);
    }
}


IFX_INLINE boolean IfxPsi5s_isModuleSuspended(Ifx_PSI5S *psi5s)
{
    Ifx_PSI5S_OCS ocs;

    /* Read the status */
    ocs.U = psi5s->OCS.U;

    /* Return the status */
    return ocs.B.SUSSTA;
}


IFX_INLINE void IfxPsi5s_setGlobalInterruptNodePointer(Ifx_PSI5S *psi5s, IfxPsi5s_GlobalInterruptSource nodePointer, IfxPsi5s_Trigger triggerOutputLine)
{
    psi5s->INPG.U |= (triggerOutputLine << (nodePointer * 3));
}


IFX_INLINE void IfxPsi5s_setInterruptNodePointer(Ifx_PSI5S *psi5s, IfxPsi5s_ChannelId channel, IfxPsi5s_InterruptSource nodePointer, IfxPsi5s_Trigger triggerOutputLine)
{
    psi5s->INP[channel].U |= (triggerOutputLine << (nodePointer * 3));
}


IFX_INLINE void IfxPsi5s_setLoopBackMode(Ifx_PSI5S *psi5s, IfxPsi5s_LoopBackMode enabled)
{
    psi5s->CON.B.LB = enabled;
}


IFX_INLINE void IfxPsi5s_setRxInput(Ifx_PSI5S *psi5s, IfxPsi5s_AlternateInput alti)
{
    psi5s->IOCR.B.ALTI = alti;
}


IFX_INLINE void IfxPsi5s_setSleepMode(Ifx_PSI5S *psi5s, IfxPsi5s_SleepMode mode)
{
    uint16 passwd = IfxScuWdt_getCpuWatchdogPassword();
    IfxScuWdt_clearCpuEndinit(passwd);
    psi5s->CLC.B.EDIS = mode;
    IfxScuWdt_setCpuEndinit(passwd);
}


IFX_INLINE void IfxPsi5s_setSuspendMode(Ifx_PSI5S *psi5s, IfxPsi5s_SuspendMode mode)
{
    Ifx_PSI5S_OCS ocs;

    /* Remove protection and configure the suspend mode. */
    ocs.B.SUS_P  = 1;
    ocs.B.SUS    = mode;
    psi5s->OCS.U = ocs.U;
}


IFX_INLINE void IfxPsi5s_setTimeStampCounterA(Ifx_PSI5S *psi5s, IfxPsi5s_TimeStampCount startTimeStamp)
{
    psi5s->TSCNTA.B.TBEA = startTimeStamp;
}


IFX_INLINE void IfxPsi5s_setTimeStampCounterB(Ifx_PSI5S *psi5s, IfxPsi5s_TimeStampCount startTimeStamp)
{
    psi5s->TSCNTA.B.TBEB = startTimeStamp;
}


IFX_INLINE boolean IfxPsi5s_getInterruptStatus(Ifx_PSI5S *psi5s, IfxPsi5s_ChannelId channel, IfxPsi5s_InterruptSource interruptSource)
{
    return ((psi5s->INTSTAT[channel].U >> interruptSource) & 0x1) == 1;
}


IFX_INLINE void IfxPsi5s_clearInterruptStatus(Ifx_PSI5S *psi5s, IfxPsi5s_ChannelId channel, IfxPsi5s_InterruptSource interruptSource)
{
    psi5s->INTCLR[channel].U = (1 << interruptSource);
}


IFX_INLINE boolean IfxPsi5s_getGlobalInterruptStatus(Ifx_PSI5S *psi5s, IfxPsi5s_GlobalInterruptSource interruptSource)
{
    return ((psi5s->INTSTATG.U >> interruptSource) & 0x1) == 1;
}


IFX_INLINE void IfxPsi5s_clearGlobalInterruptStatus(Ifx_PSI5S *psi5s, IfxPsi5s_GlobalInterruptSource interruptSource)
{
    psi5s->INTCLRG.U = (1 << interruptSource);
}


#endif /* IFXPSI5S_H */
