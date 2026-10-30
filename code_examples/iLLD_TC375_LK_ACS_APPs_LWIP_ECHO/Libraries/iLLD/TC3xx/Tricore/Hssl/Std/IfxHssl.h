/**
 * \file IfxHssl.h
 * \brief HSSL  basic functionality
 * \ingroup IfxLld_Hssl
 *
 * \version iLLD_1_22_0
 * \copyright Copyright (c) 2026 Infineon Technologies AG. All rights reserved.
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
 * \defgroup IfxLld_Hssl_Std_Enumerations Enumerations
 * \ingroup IfxLld_Hssl_Std
 * \defgroup IfxLld_Hssl_Std_HsctFunctions Hsct Functions
 * \ingroup IfxLld_Hssl_Std
 * \defgroup IfxLld_Hssl_Std_Structures Data Structures
 * \ingroup IfxLld_Hssl_Std
 * \defgroup IfxLld_Hssl_Std_HsslFunctions Hssl Functions
 * \ingroup IfxLld_Hssl_Std
 */

#ifndef IFXHSSL_H
#define IFXHSSL_H 1

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include "_Impl/IfxHssl_cfg.h"
#include "Cpu/Std/IfxCpu_Intrinsics.h"
#include "Scu/Std/IfxScuWdt.h"
#include "IfxHssl_bf.h"
#include "IfxHsct_bf.h"
#include "Src/Std/IfxSrc.h"

/******************************************************************************/
/*--------------------------------Enumerations--------------------------------*/
/******************************************************************************/

/** \addtogroup IfxLld_Hssl_Std_Enumerations
 * \{ */
/** \brief channel selection
 */
typedef enum
{
    IfxHssl_ChannelId_0,     /**< \brief Channel 0  */
    IfxHssl_ChannelId_1,     /**< \brief Channel 1  */
    IfxHssl_ChannelId_2,     /**< \brief Channel 2  */
    IfxHssl_ChannelId_3      /**< \brief Channel 3  */
} IfxHssl_ChannelId;

/** \brief communication command selection
 * Definition in Ifx_HSSL.I.ICON.B.RWT
 */
typedef enum
{
    IfxHssl_Command_noAction     = 0, /**< \brief command no action */
    IfxHssl_Command_readFrame    = 1, /**< \brief command read frame */
    IfxHssl_Command_writeFrame   = 2, /**< \brief command write frame */
    IfxHssl_Command_triggerFrame = 3  /**< \brief command trigger frame */
} IfxHssl_Command;

/** \brief predefined control command payload values
 */
typedef enum
{
    IfxHssl_ControlCommand_ping                  = 0,   /**< \brief ping (send by master. Slave sends back a fixed 32-bit payload result.) */
    IfxHssl_ControlCommand_highSpeedClockStart   = 2,   /**< \brief slave interface clock multiplier start (in preparation for high speed mode) */
    IfxHssl_ControlCommand_highSpeedClockStop    = 4,   /**< \brief slave interface clock multiplier stop (after fallback from high speed mode) */
    IfxHssl_ControlCommand_lowSpeedTransmission  = 8,   /**< \brief select low speed mode for transfers from the Master to the Slave */
    IfxHssl_ControlCommand_highSpeedTransmission = 16,  /**< \brief select high speed mode for transfers from the Master to the Slave */
    IfxHssl_ControlCommand_lowSpeedReception     = 32,  /**< \brief select low speed mode for transfers from the Slave to the Master */
    IfxHssl_ControlCommand_mediumSpeedReception  = 64,  /**< \brief select medium speed mode for transfers from the Slave to the master */
    IfxHssl_ControlCommand_highSpeedReception    = 128, /**< \brief select high speed mode for transfers from the Slave to the master */
    IfxHssl_ControlCommand_enableReception       = 49,  /**< \brief enable Slave interface transmitter */
    IfxHssl_ControlCommand_disableReception      = 50,  /**< \brief disable Slave interface transmitter */
    IfxHssl_ControlCommand_turnOnClockTestMode   = 52,  /**< \brief turn on clock test mode */
    IfxHssl_ControlCommand_turnOffClockTestMode  = 56,  /**< \brief turn off clock test mode */
    IfxHssl_ControlCommand_turnOnPayloadLoopback = 255  /**< \brief turn on payload loopback */
} IfxHssl_ControlCommand;

/** \brief Defines the length of the data in bits of the write and read command.
 * Definition in Ifx_HSSL.I.ICON.B.DATLEN
 */
typedef enum
{
    IfxHssl_DataLength_8bit  = 0,  /**< \brief 8 bit */
    IfxHssl_DataLength_16bit = 1,  /**< \brief 16 bit */
    IfxHssl_DataLength_32bit = 2   /**< \brief 32 bit */
} IfxHssl_DataLength;

/** \brief HSCT interrupt source
 * Definition in Ifx_HSCT.IRQ
 */
typedef enum
{
    IfxHssl_Hsct_InterruptSource_headerError                    = IFX_HSCT_IRQ_HER_OFF,    /**< \brief Header error detected */
    IfxHssl_Hsct_InterruptSource_payloadError                   = IFX_HSCT_IRQ_PYER_OFF,   /**< \brief Payload error detected */
    IfxHssl_Hsct_InterruptSource_commandError                   = IFX_HSCT_IRQ_CER_OFF,    /**< \brief HSCT Command error */
    IfxHssl_Hsct_InterruptSource_interfaceControlFrameSend      = IFX_HSCT_IRQ_IFCFS_OFF,  /**< \brief Interface control frame send */
    IfxHssl_Hsct_InterruptSource_speedModeSwitchError           = IFX_HSCT_IRQ_SMER_OFF,   /**< \brief Speed mode switch error */
    IfxHssl_Hsct_InterruptSource_unsolicitedMessageSendFinished = IFX_HSCT_IRQ_USMSF_OFF,  /**< \brief Unsolicited message frame send finished */
    IfxHssl_Hsct_InterruptSource_pllLockLosterror               = IFX_HSCT_IRQ_PLER_OFF,   /**< \brief Pll lock lost error */
    IfxHssl_Hsct_InterruptSource_UnsolicitedMessageReceived     = IFX_HSCT_IRQ_USM_OFF,    /**< \brief Unsolicited message received */
    IfxHssl_Hsct_InterruptSource_pingAnswerReceived             = IFX_HSCT_IRQ_PAR_OFF,    /**< \brief PING Answer Received */
    IfxHssl_Hsct_InterruptSource_txTransferError                = IFX_HSCT_IRQ_TXTE_OFF,   /**< \brief TX transfer error occurred on a disabled
                                                                                            * TX channel */
    IfxHssl_Hsct_InterruptSource_synchronizationFifoOverflow    = IFX_HSCT_IRQ_SFO_OFF,    /**< \brief Synchronization FIFO overflow (in RX
                                                                                            * direction) */
    IfxHssl_Hsct_InterruptSource_synchronizationFifoUnderflow   = IFX_HSCT_IRQ_SFU_OFF     /**< \brief Synchronization FIFO underflow (in TX
                                                                                            * direction) */
} IfxHssl_Hsct_InterruptSource;

/** \brief Enable/disable the sensitivity of the module to sleep signal\n
 * Definition in  Ifx_HSCT.CLC.B.EDIS
 */
typedef enum
{
    IfxHssl_Hsct_SleepMode_enable  = 0, /**< \brief enables sleep mode */
    IfxHssl_Hsct_SleepMode_disable = 1  /**< \brief disables sleep mode */
} IfxHssl_Hsct_SleepMode;

/** \brief Enable/disable the sensitivity of the module to sleep signal\n
 * Definition in Ifx_HSSL.CLC.B.EDIS
 */
typedef enum
{
    IfxHssl_Hssl_SleepMode_enable  = 0, /**< \brief enables sleep mode */
    IfxHssl_Hssl_SleepMode_disable = 1  /**< \brief disables sleep mode */
} IfxHssl_Hssl_SleepMode;

/** \brief interface mode (master IF /slave IF)
 * Definition in Ifx_HSCT.INIT.B.IFM
 */
typedef enum
{
    IfxHssl_InterfaceMode_master = 0,  /**< \brief master IF mode */
    IfxHssl_InterfaceMode_slave  = 1   /**< \brief slave IF mode */
} IfxHssl_InterfaceMode;

/** \brief master mode receive speed
 * Definition in Ifx_HSCT.IFCTRL.B.MRXSPEED
 */
typedef enum
{
    IfxHssl_MasterModeRxSpeed_lowSpeed    = 0,  /**< \brief low speed */
    IfxHssl_MasterModeRxSpeed_mediumSpeed = 1,  /**< \brief medium speed */
    IfxHssl_MasterModeRxSpeed_highSpeed   = 2   /**< \brief high speed */
} IfxHssl_MasterModeRxSpeed;

/** \brief master mode transmit speed
 * Definition in Ifx_HSCT.IFCTRL.B.MTXSPEED
 */
typedef enum
{
    IfxHssl_MasterModeTxSpeed_lowSpeed  = 0, /**< \brief low speed */
    IfxHssl_MasterModeTxSpeed_highSpeed = 2  /**< \brief high speed */
} IfxHssl_MasterModeTxSpeed;

/** \brief PLL reference clock
 * Definition in Ifx_HSCT.CONFIGPHY.B.OSCCLKEN
 */
typedef enum
{
    IfxHssl_PllReferenceClock_hsctSystemClockInput = 0,  /**< \brief hsct system clock input (HSCT SysClk_i) */
    IfxHssl_PllReferenceClock_oscillatorInput      = 1   /**< \brief oscillator input */
} IfxHssl_PllReferenceClock;

/** \brief SysClk / Reference Clock Frequency rate
 * Definition in Ifx_HSCT.INIT.B.SRCF
 */
typedef enum
{
    IfxHssl_RefClockFrequency_10Mhz = 0,  /**< \brief SysClk/ RefClk is 10 MHz */
    IfxHssl_RefClockFrequency_20Mhz = 1,  /**< \brief SysClk/ RefClk is 20 MHz */
    IfxHssl_RefClockFrequency_40Mhz = 2   /**< \brief SysClk/ RefClk is 40 MHz */
} IfxHssl_RefClockFrequency;

/** \brief streaming mode ( single / continuous )
 * Definition in Ifx_HSSL.CFG.B.SMT/SMR
 */
typedef enum
{
    IfxHssl_StreamingMode_continuous = 0,  /**< \brief streaming mode continuous (with two memory blocks) */
    IfxHssl_StreamingMode_single     = 1   /**< \brief streaming mode single (with one memory block) */
} IfxHssl_StreamingMode;

/** \brief OCDS Suspend Control (OCDS.SUS)
 * Definition in Ifx_HSSL_OCS.B.SUS
 */
typedef enum
{
    IfxHssl_SuspendMode_none = 0,  /**< \brief No suspend */
    IfxHssl_SuspendMode_hard = 1,  /**< \brief Hard Suspend */
    IfxHssl_SuspendMode_soft = 2   /**< \brief Soft Suspend */
} IfxHssl_SuspendMode;

/** \brief SysClk divider
 * Definition in Ifx_HSCT.INIT.B.SSCF
 */
typedef enum
{
    IfxHssl_SysClockDivider_1 = 0,  /**< \brief SysClk Divider 1/1 */
    IfxHssl_SysClockDivider_2 = 1,  /**< \brief SysClk Divider 1/2 */
    IfxHssl_SysClockDivider_4 = 2   /**< \brief SysClk Divider 1/4 */
} IfxHssl_SysClockDivider;

/** \} */

/** \brief HSSL channel error interrupt source, which triggers the ERR interrupt
 * Definition in Ifx_HSSL.MFLAGS
 */
typedef enum
{
    IfxHssl_Hssl_ERRInterruptSource_notAcknowledgeError = IFX_HSSL_MFLAGS_NACK_OFF,      /**< \brief NACK error (triggers ERR interrupt) */
    IfxHssl_Hssl_ERRInterruptSource_transactionTagError = IFX_HSSL_MFLAGS_TTE_OFF,       /**< \brief Transaction Tag Error (triggers ERR interrupt) */
    IfxHssl_Hssl_ERRInterruptSource_timeoutError        = IFX_HSSL_MFLAGS_TIMEOUT_OFF,   /**< \brief Timeout error (triggers ERR interrupt) */
    IfxHssl_Hssl_ERRInterruptSource_unexpectedError     = IFX_HSSL_MFLAGS_UNEXPECTED_OFF /**< \brief Unexpected error (triggers ERR interrupt) */
} IfxHssl_Hssl_ERRInterruptSource;

/** \brief HSSL global error interrupt source, which triggers the EXI interrupt
 * Definition in Ifx_HSSL.MFLAGS
 */
typedef enum
{
    IfxHssl_Hssl_EXIInterruptSource_memoryAccessViolation  = IFX_HSSL_MFLAGS_MAV_OFF,   /**< \brief Memory Access Violation error (triggers EXI interrupt) */
    IfxHssl_Hssl_EXIInterruptSource_busAccessError         = IFX_HSSL_MFLAGS_SRIE_OFF,  /**< \brief SRI/SPB Bus Access Error (triggers EXI interrupt) */
    IfxHssl_Hssl_EXIInterruptSource_channelNumberCodeError = IFX_HSSL_MFLAGS_PIE1_OFF,  /**< \brief PHY Inconsistency Error 1 (Channel Number
                                                                                         * Code Error,  triggers EXI interrupt) */
    IfxHssl_Hssl_EXIInterruptSource_dataLengthError        = IFX_HSSL_MFLAGS_PIE2_OFF,  /**< \brief PHY Inconsistency Error 2 (Data Length Error, triggers EXI interrupt) */
    IfxHssl_Hssl_EXIInterruptSource_crcError               = IFX_HSSL_MFLAGS_CRCE_OFF   /**< \brief CRC error (triggers EXI interrupt) */
} IfxHssl_Hssl_EXIInterruptSource;

/******************************************************************************/
/*-----------------------------Data Structures--------------------------------*/
/******************************************************************************/

/** \addtogroup IfxLld_Hssl_Std_Structures
 * \{ */
/** \brief HSCT module handle
 */
typedef struct
{
    Ifx_HSCT *hsct;           /**< \brief pointer to HSCT registers */
    boolean   loopBack;       /**< \brief loop back selection. Range: Enable(TRUE) or Disable(FALSE) */
} IfxHssl_Hsct;

/** \brief Configuration structure of the HSCT module
 */
typedef struct
{
    Ifx_HSCT             *hsct;                /**< \brief pointer to HSCT registers */
    IfxHssl_InterfaceMode interfaceMode;       /**< \brief interface mode (master IF /slave IF) */
    boolean               highSpeedMode;       /**< \brief high speed mode selection. Range: TRUE if enable high speed mode;FALSE if disable high speed mode(FALSE) */
    boolean               loopBack;            /**< \brief loop back selection. Range: Enable(TRUE) or Disable(FALSE) */
} IfxHssl_Hsct_Config;

/** \} */

/** \addtogroup IfxLld_Hssl_Std_HsctFunctions
 * \{ */

/******************************************************************************/
/*-------------------------Inline Function Prototypes-------------------------*/
/******************************************************************************/

/**
 * \brief Clears the specified HSCT interrupt flag
 *
 * \param[inout] hsct   Pointer to the HSCT object.
 * \param[in]    source The interrupt source to clear. Range: \ref IfxHssl_Hsct_InterruptSource
 *
 * \retval None
 */
IFX_INLINE void IfxHssl_clearHsctInterruptFlag(Ifx_HSCT *hsct, IfxHssl_Hsct_InterruptSource source);

/**
 * \brief Disables the specified HSCT interrupt flag..
 *
 * \param[inout] hsct   Pointer to the HSCT object.
 * \param[in]    source The HSCT interrupt source to disable. Range: \ref IfxHssl_Hsct_InterruptSource
 *
 * \retval None
 */
IFX_INLINE void IfxHssl_disableHsctInterruptFlag(Ifx_HSCT *hsct, IfxHssl_Hsct_InterruptSource source);

/**
 * \brief Enables the HSCT interrupt with the specified priority and type of service.
 *
 * \param[inout] hsct          Pointer to the HSCT object.
 * \param[in]    typeOfService Specifies the type of service for the interrupt. This can be either CPU or DMA, depending on the application's requirements. Range: \ref IfxSrc_Tos
 * \param[in]    priority      The priority level for the interrupt. The priority determines the precedence of the interrupt in the system. Range: 0 to 0xFF.
 *
 * \retval None
 */
IFX_INLINE void IfxHssl_enableHsctInterrupt(Ifx_HSCT *hsct, IfxSrc_Tos typeOfService, uint16 priority);

/**
 * \brief Enables a specific HSCT interrupt source, allowing the generation of interrupts when the corresponding condition is met.
 *
 * \param[inout] hsct   Pointer to the HSCT object.
 * \param[in]    source The interrupt source to enable. Range: \ref IfxHssl_Hsct_InterruptSource
 *
 * \retval None
 */
IFX_INLINE void IfxHssl_enableHsctInterruptFlag(Ifx_HSCT *hsct, IfxHssl_Hsct_InterruptSource source);

/**
 * \brief Enables HSCT LVDS loopback
 *
 * \param[inout] hsct   Pointer to the HSCT object.
 *
 * \retval None
 */
IFX_INLINE void IfxHssl_enableHsctLvdsLoopback(Ifx_HSCT *hsct);

/**
 * \brief Retrieves the status of a specific HSCT interrupt flag.
 *
 * \param[in] hsct   Pointer to the HSCT object.
 * \param[in] source The interrupt source to query. Range: \ref IfxHssl_Hsct_InterruptSource
 *
 * \retval TRUE The interrupt flag for the specified source is set.
 *         FALSE The interrupt flag for the specified source is not set.
 */
IFX_INLINE boolean IfxHssl_getHsctInterruptFlagStatus(Ifx_HSCT *hsct, IfxHssl_Hsct_InterruptSource source);

/**
 * \brief Sets the sensitivity of the module to the sleep signal.
 * 
 * \param[inout] hsct Pointer to the HSCT object.
 * \param[in]    mode Mode selection for sleep signal sensitivity. Range: \ref IfxHssl_Hsct_SleepMode
 * 
 * \retval None
 */
IFX_INLINE void IfxHssl_setHsctSleepMode(Ifx_HSCT *hsct, IfxHssl_Hsct_SleepMode mode);

/**
 * \brief Retrieves the last received unsolicited status message from the HSCT module.
 *
 * \param[in] hsct   Pointer to the HSCT object.
 *
 * \retval uint32 The unsolicited status message received by the HSCT module. Range: 0 to 0xFFFFFFFF
 */
IFX_INLINE uint32 IfxHssl_getHsctUnsolicitedStatusMessage(Ifx_HSCT *hsct);

/**
 * \brief Sends an unsolicited status message.
 *
 * \param[inout] hsct    Pointer to the HSCT object.
 * \param[in]    message Unsolicited status message to be transmitted. Range: 0 to 0xFFFFFFFF
 *
 * \retval None
 */
IFX_INLINE void IfxHssl_sendHsctUnsolicitedStatusMessage(Ifx_HSCT *hsct, uint32 message);

/**
 * \brief Set the HSCT RX link speed.
 *
 * \param[inout] hsct    Pointer to the HSCT object.
 * \param[in]    rxSpeed Speed for Rx link. Range: \ref IfxHssl_MasterModeRxSpeed
 *
 * \retval None
 */
IFX_INLINE void IfxHssl_setHsctRxLinkSpeed(Ifx_HSCT *hsct, IfxHssl_MasterModeRxSpeed rxSpeed);

/**
 * \brief Set the HSCT TX link speed.
 *
 * \param[inout] hsct    Pointer to the HSCT object.
 * \param[in]    txSpeed Speed for Tx link. Range: \ref IfxHssl_MasterModeTxSpeed
 *
 * \retval None
 */
IFX_INLINE void IfxHssl_setHsctTxLinkSpeed(Ifx_HSCT *hsct, IfxHssl_MasterModeTxSpeed txSpeed);

/**
 * \brief Enable the HSCT transmit path in the master interface.
 *
 * \param[inout] hsct   Pointer to the HSCT object.
 *
 * \retval None
 */
IFX_INLINE void IfxHssl_enableHsctTransmitPath(Ifx_HSCT *hsct);

/**
 * \brief Enable HSCT receive path in the master interface.
 * 
 * \param[inout] hsct   Pointer to the HSCT object.
 * 
 * \retval None
 */
IFX_INLINE void IfxHssl_enableHsctReceivePath(Ifx_HSCT *hsct);

/**
 * \brief Disables the transmit path of the HSCT module in master interface.
 *
 * \param[inout] hsct   Pointer to the HSCT object.
 * 
 * \retval None
 */
IFX_INLINE void IfxHssl_disableHsctTransmitPath(Ifx_HSCT *hsct);

/**
 * \brief Disables the HSCT receive path in the master interface.
 *
 * \param[inout] hsct   Pointer to the HSCT object.
 *
 * \retval None
 */
IFX_INLINE void IfxHssl_disableHsctReceivePath(Ifx_HSCT *hsct);

/******************************************************************************/
/*-------------------------Global Function Prototypes-------------------------*/
/******************************************************************************/

/**
 * \brief Disables the HSCT module.
 *
 * \param[inout] hsct   Pointer to the HSCT object.
 *
 * \retval None
 */
IFX_EXTERN void IfxHssl_disableHsctModule(Ifx_HSCT *hsct);

/**
 * \brief Enables the HSCT module.
 *
 * \param[inout] hsct   Pointer to the HSCT object.
 *
 * \retval None
 */
IFX_EXTERN void IfxHssl_enableHsctModule(Ifx_HSCT *hsct);

/**
 * \brief Retrieves the base address of the HSCT module for a given HSCT index.
 *
 * \param[in] hsct   Resource index of the HSCT.
 *
 * \retval Ifx_HSCT* Base address of the HSCT module registers.
 */
IFX_EXTERN Ifx_HSCT *IfxHssl_getHsctAddress(IfxHssl_hsctIndex hsct);

/**
 * \brief Retrieves the resource index associated with the specified HSCT instance.
 *
 * \param[in] hsct   Pointer to the HSCT object.
 *
 * \retval IfxHssl_hsctIndex The unique resource index of the HSCT instance. Range: \ref IfxHssl_hsctIndex
 */
IFX_EXTERN IfxHssl_hsctIndex IfxHssl_getHsctIndex(Ifx_HSCT *hsct);

/**
 * \brief Returns the SRC pointer for HSCT.
 *
 * \param[in] hsct   Pointer to the HSCT object.
 *
 * \retval Ifx_SRC_SRCR* Pointer to the SRC registers for the HSCT module.
 */
IFX_EXTERN volatile Ifx_SRC_SRCR *IfxHssl_getHsctSrcPointer(Ifx_HSCT *hsct);

/**
 * \brief Resets the HSCT kernel to its initial state.
 *
 * \param[inout] hsct   Pointer to the HSCT object.
 *
 * \retval None
 */
IFX_EXTERN void IfxHssl_resetHsctKernel(Ifx_HSCT *hsct);

/** \} */

/** \addtogroup IfxLld_Hssl_Std_HsslFunctions
 * \{ */

/******************************************************************************/
/*-------------------------Inline Function Prototypes-------------------------*/
/******************************************************************************/

/**
 * \brief Clears the HSSl channel error interrupt flag
 *
 * \param[inout] hssl      Pointer to the HSSL object.
 * \param[in]    source    HSSL channel error interrupt source to clear. Range: \ref IfxHssl_Hssl_ERRInterruptSource
 * \param[in]    channelId HSSL channel number to clear the error interrupt flag for. Range: \ref IfxHssl_ChannelId
 *
 * \retval None
 */
IFX_INLINE void IfxHssl_clearHsslChannelErrorInterruptFlag(Ifx_HSSL *hssl, IfxHssl_Hssl_ERRInterruptSource source, IfxHssl_ChannelId channelId);

/**
 * \brief Clears the specified HSSL global error interrupt flag.
 *
 * \param[inout] hssl   Pointer to the HSSL object.
 * \param[in]    source The HSSL global error interrupt source to clear. Range: \ref IfxHssl_Hssl_EXIInterruptSource
 *
 * \retval None
 */
IFX_INLINE void IfxHssl_clearHsslGlobalErrorInterruptFlag(Ifx_HSSL *hssl, IfxHssl_Hssl_EXIInterruptSource source);

/**
 * \brief Clears the Initialise Mode Flag status
 *
 * \param[inout] hssl   Pointer to the HSSL object.
 *
 * \retval None
 */
IFX_INLINE void IfxHssl_clearInitialiseModeFlag(Ifx_HSSL *hssl);

/**
 * \brief Disables the HSSL channel error interrupt flag, which triggers the ERR interrupt.
 *
 * \param[inout] hssl      Pointer to the HSSL object.
 * \param[in]    source    HSSL channel error interrupt source to disable. Range: \ref IfxHssl_Hssl_ERRInterruptSource
 * \param[in]    channelId HSSL channel number to disable the error interrupt for. Range: \ref IfxHssl_ChannelId
 *
 * \retval None
 */
IFX_INLINE void IfxHssl_disableHsslChannelErrorInterruptFlag(Ifx_HSSL *hssl, IfxHssl_Hssl_ERRInterruptSource source, IfxHssl_ChannelId channelId);

/**
 * \brief Disables the HSSL channel error interrupt flag, which triggers the EXI interrupt.
 *
 * \param[inout] hssl   Pointer to the HSSL object.
 * \param[in]    source HSSL global error interrupt source to disable. Range: \ref IfxHssl_Hssl_EXIInterruptSource
 *
 * \retval None
 */
IFX_INLINE void IfxHssl_disableHsslGlobalErrorInterruptFlag(Ifx_HSSL *hssl, IfxHssl_Hssl_EXIInterruptSource source);

/**
 * \brief Enables all error flags for the HSSL module.
 *
 * \param[inout] hssl   Pointer to the HSSL object.
 * 
 * \retval None
 */
IFX_INLINE void IfxHssl_enableAllErrorFlags(Ifx_HSSL *hssl);

/**
 * \brief Enables the HSSL COK interrupt for the specified channel.
 *
 * \param[inout] hssl       Pointer to the HSSL object.
 * \param[in] channelId     The ID of the HSSL channel to enable the COK interrupt for. Range: \ref IfxHssl_ChannelId
 * \param[in] typeOfService Specifies the type of service for the interrupt (Cpu or DMA). Range: \ref IfxSrc_Tos
 * \param[in] priority      The priority level for the interrupt. Range: 0 to 0xFF
 *
 * \retval None
 */
IFX_INLINE void IfxHssl_enableHsslCOKInterrupt(Ifx_HSSL *hssl, IfxHssl_ChannelId channelId, IfxSrc_Tos typeOfService, uint16 priority);

/**
 * \brief Enables the HSSL channel error interrupt flag, which triggers the ERR interrupt for the specified channel and error source.
 *
 * \param[inout] hssl      Pointer to the HSSL object.
 * \param[in]    source    Specifies the HSSL channel error interrupt source to enable. Range: \ref IfxHssl_Hssl_ERRInterruptSource
 * \param[in]    channelId The HSSL channel number to enable the error interrupt for. Range: \ref IfxHssl_ChannelId
 *
 * \retval None
 */
IFX_INLINE void IfxHssl_enableHsslChannelErrorInterruptFlag(Ifx_HSSL *hssl, IfxHssl_Hssl_ERRInterruptSource source, IfxHssl_ChannelId channelId);

/**
 * \brief Enables the HSSL ERR interrupt for the specified channel.
 *
 * \param[inout] hssl       Pointer to the HSSL object.
 * \param[in] channelId     The ID of the HSSL channel to enable the ERR interrupt for. Range: \ref IfxHssl_ChannelId
 * \param[in] typeOfService The type of service for the interrupt (Cpu or DMA). Range: \ref IfxSrc_Tos
 * \param[in] priority      The priority level for the interrupt. Range: 0 to 0xFF
 *
 * \retval None
 */
IFX_INLINE void IfxHssl_enableHsslERRInterrupt(Ifx_HSSL *hssl, IfxHssl_ChannelId channelId, IfxSrc_Tos typeOfService, uint16 priority);

/**
 * \brief Enables the HSSL EXI interrupt for the specified channel.
 *
 * \param[inout] hssl       Pointer to the HSSL object.
 * \param[in] typeOfService Specifies the type of service for the interrupt. Range: \ref IfxSrc_Tos
 * \param[in] priority      The priority level for the interrupt. Range: 0 to 0xFF
 *
 * \retval None
 */
IFX_INLINE void IfxHssl_enableHsslEXIInterrupt(Ifx_HSSL *hssl, IfxSrc_Tos typeOfService, uint16 priority);

/**
 * \brief Enables the HSSL global error interrupt flag for the specified source, triggering the EXI interrupt.
 *
 * \param[inout] hssl   Pointer to the HSSL object.
 * \param[in]    source HSSL global error interrupt source to enable. Range: \ref IfxHssl_Hssl_EXIInterruptSource
 *
 * \retval None
 */
IFX_INLINE void IfxHssl_enableHsslGlobalErrorInterruptFlag(Ifx_HSSL *hssl, IfxHssl_Hssl_EXIInterruptSource source);

/**
 * \brief Enables the HSSL RDI interrupt for the specified channel.
 *
 * \param[inout] hssl          Pointer to the HSSL object.
 * \param[in]    channelId     HSSL channel identifier. Range: \ref IfxHssl_ChannelId
 * \param[in]    typeOfService Type of Service (Cpu or DMA) for the interrupt. Range: \ref IfxSrc_Tos
 * \param[in]    priority      Priority level for the interrupt. Range: 0 to 0xFF
 *
 * \retval None
 */
IFX_INLINE void IfxHssl_enableHsslRDIInterrupt(Ifx_HSSL *hssl, IfxHssl_ChannelId channelId, IfxSrc_Tos typeOfService, uint16 priority);

/**
 * \brief Enables the HSSL TRG interrupt for the specified channel.
 *
 * \param[inout] hssl          Pointer to the HSSL object.
 * \param[in]    channelId     The HSSL channel identifier. Range: \ref IfxHssl_ChannelId
 * \param[in]    typeOfService Specifies the type of service for the interrupt. Range: \ref IfxSrc_Tos
 * \param[in]    priority      The priority level for the interrupt. Range: 0 to 0xFF
 *
 * \retval None
 */
IFX_INLINE void IfxHssl_enableHsslTRGInterrupt(Ifx_HSSL *hssl, IfxHssl_ChannelId channelId, IfxSrc_Tos typeOfService, uint16 priority);

/**
 * \brief Returns the status of all MFLAGS status.
 * 
 * \param[in] hssl   Pointer to the HSSL object.
 *
 * \retval uint32 Status of all MFLAGS. Range: 0 to 0xF3FCFFFF
 */
IFX_INLINE uint32 IfxHssl_getAllMflagsStatus(Ifx_HSSL *hssl);

/**
 * \brief Retrieves the current count value from the HSSL module.
 *
 * \param[in] hssl   Pointer to the HSSL object.
 *
 * \retval uint16 The current count value. Range: 0 to 0xFFFF
 */
IFX_INLINE uint16 IfxHssl_getCurrentCount(Ifx_HSSL *hssl);

/**
 * \brief Gets the status of the HSSL channel error interrupt flag.
 *
 * \param[in] hssl      Pointer to the HSSL object.
 * \param[in] source    The HSSL channel error interrupt source. Range: \ref IfxHssl_Hssl_ERRInterruptSource
 * \param[in] channelId The HSSL channel number. Range: \ref IfxHssl_ChannelId
 *
 * \retval TRUE The error interrupt flag is set.
 *         FALSE The error interrupt flag is not set.
 */
IFX_INLINE boolean IfxHssl_getHsslChannelErrorInterruptFlagStatus(Ifx_HSSL *hssl, IfxHssl_Hssl_ERRInterruptSource source, IfxHssl_ChannelId channelId);

/**
 * \brief Retrieves the status of the HSSL global error interrupt flag for a specified source.
 *
 * \param[in] hssl   Pointer to the HSSL object.
 * \param[in] source The HSSL global error interrupt source. Range: \ref IfxHssl_Hssl_EXIInterruptSource
 *
 * \retval TRUE The global error interrupt flag is set for the specified source.
 *         FALSE The global error interrupt flag is not set for the specified source.
 *
 */
IFX_INLINE boolean IfxHssl_getHsslGloabalErrorInterruptFlagStatus(Ifx_HSSL *hssl, IfxHssl_Hssl_EXIInterruptSource source);

/**
 * \brief Checks and returns the current status of the Initialise Mode Flag.
 *
 * \param[in] hssl   Pointer to the HSSL object.
 *
 * \retval TRUE If Initialise Mode.
 *         FALSE If Run mode.
 */
IFX_INLINE boolean IfxHssl_getInitialiseModeFlagStatus(Ifx_HSSL *hssl);

/**
 * \brief Returns the current reload count value from the HSSL module.
 *
 * \param[in] hssl   Pointer to the HSSL object.
 *
 * \retval uint16 The current reload count value. Range: 0 to 0xFFFF
 */
IFX_INLINE uint16 IfxHssl_getReloadCount(Ifx_HSSL *hssl);

/**
 * \brief Checks if the HSSL module is in a suspended state.
 *
 * \param[in] hssl   Pointer to the HSSL object.
 *
 * \retval TRUE If Module is suspended.
 *         FALSE If Module is not yet suspended.
 */
IFX_INLINE boolean IfxHssl_isModuleSuspended(Ifx_HSSL *hssl);

/**
 * \brief Configures the module's sensitivity to the sleep signal by enabling or disabling it.
 *
 * \param[inout] hssl Pointer to the HSSL object.
 * \param[in]    mode Mode selection for sleep signal sensitivity. Range: \ref IfxHssl_Hssl_SleepMode
 *
 * \retval None
 */
IFX_INLINE void IfxHssl_setHsslSleepMode(Ifx_HSSL *hssl, IfxHssl_Hssl_SleepMode mode);

/**
 * \brief Sets the Initialise Mode Flag for the HSSL module.
 *
 * \param[inout] hssl   Pointer to the HSSL object.
 *
 * \retval None
 */
IFX_INLINE void IfxHssl_setInitialiseModeFlag(Ifx_HSSL *hssl);

/**
 * \brief Sets the reload count for the HSSL module.
 *
 * \param[inout] hssl        Pointer to the HSSL object.
 * \param[in]    reloadValue The reload value to be set. Range: 0 to 0xFFFF
 *
 * \retval None
 */
IFX_INLINE void IfxHssl_setReloadCount(Ifx_HSSL *hssl, uint16 reloadValue);

/**
 * \brief Configure the Module to Hard/Soft suspend mode.
 *
 * \param[inout] hssl Pointer to the HSSL object.
 * \param[in]    mode Module suspend mode. Range: \ref IfxHssl_SuspendMode
 *
 * \retval None
 *
 * \note The function will only take effect if OCDS is enabled and the system is in
 * Supervisor Mode. If OCDS is disabled, the OCS suspend control is ineffective.
 */
IFX_INLINE void IfxHssl_setSuspendMode(Ifx_HSSL *hssl, IfxHssl_SuspendMode mode);

/**
 * \brief Sets the timeout reload value for a specified HSSL channel.
 *
 * \param[inout] hssl         Pointer to the HSSL object.
 * \param[in]    channelId    HSSL channel number. Range: \ref IfxHssl_ChannelId
 * \param[in]    timeoutValue Timeout value to be set. Range: 0 to 255
 *
 * \retval None
 */
IFX_INLINE void IfxHssl_setTimeoutReloadValue(Ifx_HSSL *hssl, IfxHssl_ChannelId channelId, uint8 timeoutValue);

/******************************************************************************/
/*-------------------------Global Function Prototypes-------------------------*/
/******************************************************************************/

/**
 * \brief Disables the HSSL module.
 *
 * \param[inout] hssl   Pointer to the HSSL object.
 *
 * \retval None
 */
IFX_EXTERN void IfxHssl_disableHsslModule(Ifx_HSSL *hssl);

/**
 * \brief Enables the HSSL module.
 *
 * \param[inout] hssl   Pointer to the HSSL object.
 *
 * \retval None
 */
IFX_EXTERN void IfxHssl_enableHsslModule(Ifx_HSSL *hssl);

/**
 * \brief Retrieves the base address of an HSSL module based on the provided index.
 *
 * \param[in] hssl The index of the HSSL module to retrieve the address for. Range: \ref IfxHssl_hsslIndex
 *
 * \retval Ifx_HSSL* Pointer to the base address of the HSSL module.
 */
IFX_EXTERN Ifx_HSSL *IfxHssl_getHsslAddress(IfxHssl_hsslIndex hssl);

/**
 * \brief Returns the SRC pointer for HSSL COK of specified channel
 *
 * \param[in] hssl      Pointer to the HSSL object.
 * \param[in] channelId HSSL channel number. Range: \ref IfxHssl_ChannelId
 *
 * \retval Ifx_SRC_SRCR* SRC pointer for HSSL COK interrupt of specific channel.
 */
IFX_EXTERN volatile Ifx_SRC_SRCR *IfxHssl_getHsslCOKSrcPointer(Ifx_HSSL *hssl, IfxHssl_ChannelId channelId);

/**
 * \brief Returns the SRC pointer for HSSL ERR of the specified channel
 *
 * \param[in] hssl      Pointer to the HSSL object.
 * \param[in] channelId HSSL channel number. Range: \ref IfxHssl_ChannelId
 *
 * \retval Ifx_SRC_SRCR* Pointer to the SRC register for the HSSL ERR interrupt of the specified channel.
 */
IFX_EXTERN volatile Ifx_SRC_SRCR *IfxHssl_getHsslERRSrcPointer(Ifx_HSSL *hssl, IfxHssl_ChannelId channelId);

/**
 * \brief Returns SRC pointer for HSSL EXI interrupt.
 *
 * \param[in] hssl   Pointer to the HSSL object.
 *
 * \retval Ifx_SRC_SRCR* A pointer to the SRC register for the HSSL EXI interrupt.
 */
IFX_EXTERN volatile Ifx_SRC_SRCR *IfxHssl_getHsslEXISrcPointer(Ifx_HSSL *hssl);


/**
 * \brief Retrieves the resource index of the specified HSSL instance.
 *
 * \param[in] hssl   Pointer to the HSSL object.
 *
 * \retval IfxHssl_hsslIndex Resource index of the HSSL instance. Range: \ref IfxHssl_hsslIndex
 */
IFX_EXTERN IfxHssl_hsslIndex IfxHssl_getHsslIndex(Ifx_HSSL *hssl);

/**
 * \brief Returns the SRC pointer for HSSL RDI of a specified channel.
 *
 * \param[in] hssl      Pointer to the HSSL object.
 * \param[in] channelId HSSL channel number. Range: \ref IfxHssl_ChannelId
 *
 * \retval Ifx_SRC_SRCR* Pointer to the SRC register for HSSL RDI interrupt of specified channel.
 */
IFX_EXTERN volatile Ifx_SRC_SRCR *IfxHssl_getHsslRDISrcPointer(Ifx_HSSL *hssl, IfxHssl_ChannelId channelId);

/**
 * \brief Returns the SRC pointer for the HSSL TRG interrupt of a specified channel.
 *
 * \param[in] hssl      Pointer to the HSSL object.
 * \param[in] channelId HSSL channel number. Range: \ref IfxHssl_ChannelId
 *
 * \retval Ifx_SRC_SRCR* Pointer to the SRC register for HSSL TRG interrupt of specified channel.
 */
IFX_EXTERN volatile Ifx_SRC_SRCR *IfxHssl_getHsslTRGSrcPointer(Ifx_HSSL *hssl, IfxHssl_ChannelId channelId);

/**
 * \brief Resets the HSSL kernel.
 *
 * \param[inout] hssl   Pointer to the HSSL object.
 *
 * \retval None
 */
IFX_EXTERN void IfxHssl_resetHsslKernel(Ifx_HSSL *hssl);

/** \} */

/******************************************************************************/
/*---------------------Inline Function Implementations------------------------*/
/******************************************************************************/

IFX_INLINE void IfxHssl_clearHsctInterruptFlag(Ifx_HSCT *hsct, IfxHssl_Hsct_InterruptSource source)
{
    uint32 value = 1 << source;
    hsct->IRQCLR.U = value;
}


IFX_INLINE void IfxHssl_clearHsslChannelErrorInterruptFlag(Ifx_HSSL *hssl, IfxHssl_Hssl_ERRInterruptSource source, IfxHssl_ChannelId channelId)
{
    uint32 value = 1 << ((uint32)(channelId + source));
    hssl->MFLAGSCL.U = value;
}


IFX_INLINE void IfxHssl_clearHsslGlobalErrorInterruptFlag(Ifx_HSSL *hssl, IfxHssl_Hssl_EXIInterruptSource source)
{
    uint32 value = 1 << source;
    hssl->MFLAGSCL.U = value;
}


IFX_INLINE void IfxHssl_clearInitialiseModeFlag(Ifx_HSSL *hssl)
{
    hssl->MFLAGSCL.B.INIC = 0x1U;
}


IFX_INLINE void IfxHssl_disableHsctInterruptFlag(Ifx_HSCT *hsct, IfxHssl_Hsct_InterruptSource source)
{
    uint32 value = 1 << source;
    hsct->IRQEN.U &= ~value;
}


IFX_INLINE void IfxHssl_disableHsslChannelErrorInterruptFlag(Ifx_HSSL *hssl, IfxHssl_Hssl_ERRInterruptSource source, IfxHssl_ChannelId channelId)
{
    uint32 value = 1 << ((uint32)(channelId + source));
    hssl->MFLAGSEN.U &= ~value;
}


IFX_INLINE void IfxHssl_disableHsslGlobalErrorInterruptFlag(Ifx_HSSL *hssl, IfxHssl_Hssl_EXIInterruptSource source)
{
    uint32 value = 1 << source;
    hssl->MFLAGSEN.U &= ~value;
}


IFX_INLINE void IfxHssl_enableAllErrorFlags(Ifx_HSSL *hssl)
{
    hssl->MFLAGSEN.U = 0x23E0FFFFU;
}


IFX_INLINE void IfxHssl_enableHsctInterrupt(Ifx_HSCT *hsct, IfxSrc_Tos typeOfService, uint16 priority)
{
    volatile Ifx_SRC_SRCR *src;
    src = IfxHssl_getHsctSrcPointer(hsct);
    IfxSrc_init(src, typeOfService, priority);
    IfxSrc_enable(src);
}


IFX_INLINE void IfxHssl_enableHsctInterruptFlag(Ifx_HSCT *hsct, IfxHssl_Hsct_InterruptSource source)
{
    uint32 value = 1 << source;
    hsct->IRQEN.U |= value;
}


IFX_INLINE void IfxHssl_enableHsctLvdsLoopback(Ifx_HSCT *hsct)
{
    hsct->TESTCTRL.B.LLOPTXRX = 0x1U;
}


IFX_INLINE void IfxHssl_enableHsslCOKInterrupt(Ifx_HSSL *hssl, IfxHssl_ChannelId channelId, IfxSrc_Tos typeOfService, uint16 priority)
{
    volatile Ifx_SRC_SRCR *src;
    src = IfxHssl_getHsslCOKSrcPointer(hssl, channelId);
    IfxSrc_init(src, typeOfService, priority);
    IfxSrc_enable(src);
}


IFX_INLINE void IfxHssl_enableHsslChannelErrorInterruptFlag(Ifx_HSSL *hssl, IfxHssl_Hssl_ERRInterruptSource source, IfxHssl_ChannelId channelId)
{
    uint32 value = 1 << ((uint32)(channelId + source));
    hssl->MFLAGSEN.U |= value;
}


IFX_INLINE void IfxHssl_enableHsslERRInterrupt(Ifx_HSSL *hssl, IfxHssl_ChannelId channelId, IfxSrc_Tos typeOfService, uint16 priority)
{
    volatile Ifx_SRC_SRCR *src;
    src = IfxHssl_getHsslERRSrcPointer(hssl, channelId);
    IfxSrc_init(src, typeOfService, priority);
    IfxSrc_enable(src);
}


IFX_INLINE void IfxHssl_enableHsslEXIInterrupt(Ifx_HSSL *hssl, IfxSrc_Tos typeOfService, uint16 priority)
{
    volatile Ifx_SRC_SRCR *src;
    src = IfxHssl_getHsslEXISrcPointer(hssl);
    IfxSrc_init(src, typeOfService, priority);
    IfxSrc_enable(src);
}


IFX_INLINE void IfxHssl_enableHsslGlobalErrorInterruptFlag(Ifx_HSSL *hssl, IfxHssl_Hssl_EXIInterruptSource source)
{
    uint32 value = 1 << source;
    hssl->MFLAGSEN.U |= value;
}


IFX_INLINE void IfxHssl_enableHsslRDIInterrupt(Ifx_HSSL *hssl, IfxHssl_ChannelId channelId, IfxSrc_Tos typeOfService, uint16 priority)
{
    volatile Ifx_SRC_SRCR *src;
    src = IfxHssl_getHsslRDISrcPointer(hssl, channelId);
    IfxSrc_init(src, typeOfService, priority);
    IfxSrc_enable(src);
}


IFX_INLINE void IfxHssl_enableHsslTRGInterrupt(Ifx_HSSL *hssl, IfxHssl_ChannelId channelId, IfxSrc_Tos typeOfService, uint16 priority)
{
    volatile Ifx_SRC_SRCR *src;
    src = IfxHssl_getHsslTRGSrcPointer(hssl, channelId);
    IfxSrc_init(src, typeOfService, priority);
    IfxSrc_enable(src);
}


IFX_INLINE uint32 IfxHssl_getAllMflagsStatus(Ifx_HSSL *hssl)
{
    return hssl->MFLAGS.U;
}


IFX_INLINE uint16 IfxHssl_getCurrentCount(Ifx_HSSL *hssl)
{
    return hssl->IS.FC.B.CURCOUNT;
}


IFX_INLINE boolean IfxHssl_getHsctInterruptFlagStatus(Ifx_HSCT *hsct, IfxHssl_Hsct_InterruptSource source)
{
    return (hsct->IRQ.U >> source) & 0x1;
}


IFX_INLINE boolean IfxHssl_getHsslChannelErrorInterruptFlagStatus(Ifx_HSSL *hssl, IfxHssl_Hssl_ERRInterruptSource source, IfxHssl_ChannelId channelId)
{
    return (hssl->MFLAGS.U >> ((uint32)(channelId + source))) & 0x1;
}


IFX_INLINE boolean IfxHssl_getHsslGloabalErrorInterruptFlagStatus(Ifx_HSSL *hssl, IfxHssl_Hssl_EXIInterruptSource source)
{
    return (hssl->MFLAGS.U >> source) & 0x1;
}


IFX_INLINE boolean IfxHssl_getInitialiseModeFlagStatus(Ifx_HSSL *hssl)
{
    return hssl->MFLAGS.B.INI != 0;
}


IFX_INLINE uint16 IfxHssl_getReloadCount(Ifx_HSSL *hssl)
{
    return hssl->IS.FC.B.RELCOUNT;
}


IFX_INLINE boolean IfxHssl_isModuleSuspended(Ifx_HSSL *hssl)
{
    Ifx_HSSL_OCS ocs;

    /* Read the status */
    ocs.U = hssl->OCS.U;

    /* Return the status */
    return ocs.B.SUSSTA;
}


IFX_INLINE void IfxHssl_setHsctSleepMode(Ifx_HSCT *hsct, IfxHssl_Hsct_SleepMode mode)
{
    uint16 passwd = IfxScuWdt_getCpuWatchdogPassword();
    IfxScuWdt_clearCpuEndinit(passwd);
    hsct->CLC.B.EDIS = mode;
    IfxScuWdt_setCpuEndinit(passwd);
}


IFX_INLINE void IfxHssl_setHsslSleepMode(Ifx_HSSL *hssl, IfxHssl_Hssl_SleepMode mode)
{
    uint16 passwd = IfxScuWdt_getCpuWatchdogPassword();
    IfxScuWdt_clearCpuEndinit(passwd);
    hssl->CLC.B.EDIS = mode;
    IfxScuWdt_setCpuEndinit(passwd);
}


IFX_INLINE void IfxHssl_setInitialiseModeFlag(Ifx_HSSL *hssl)
{
    hssl->MFLAGSSET.B.INIS = 0x1U;
}


IFX_INLINE void IfxHssl_setReloadCount(Ifx_HSSL *hssl, uint16 reloadValue)
{
    hssl->IS.FC.B.RELCOUNT = reloadValue;
}


IFX_INLINE void IfxHssl_setSuspendMode(Ifx_HSSL *hssl, IfxHssl_SuspendMode mode)
{
    Ifx_HSSL_OCS ocs;

    /* Remove protection and configure the suspend mode. */
    ocs.B.SUS_P = 1;
    ocs.B.SUS   = mode;
    hssl->OCS.U = ocs.U;
}


IFX_INLINE void IfxHssl_setTimeoutReloadValue(Ifx_HSSL *hssl, IfxHssl_ChannelId channelId, uint8 timeoutValue)
{
    hssl->I[channelId].ICON.B.TOREL = timeoutValue;
}


IFX_INLINE uint32 IfxHssl_getHsctUnsolicitedStatusMessage(Ifx_HSCT *hsct)
{
    return hsct->USMR.U;
}


IFX_INLINE void IfxHssl_sendHsctUnsolicitedStatusMessage(Ifx_HSCT *hsct, uint32 message)
{
    hsct->USMS.U = message;
}


IFX_INLINE void IfxHssl_setHsctRxLinkSpeed(Ifx_HSCT *hsct, IfxHssl_MasterModeRxSpeed rxSpeed)
{
    hsct->IFCTRL.B.MRXSPEED = rxSpeed;
}


IFX_INLINE void IfxHssl_setHsctTxLinkSpeed(Ifx_HSCT *hsct, IfxHssl_MasterModeTxSpeed txSpeed)
{
    hsct->IFCTRL.B.MTXSPEED = txSpeed;
}


IFX_INLINE void IfxHssl_enableHsctTransmitPath(Ifx_HSCT *hsct)
{
    hsct->DISABLE.B.TX_DIS = 0x0U;
}


IFX_INLINE void IfxHssl_enableHsctReceivePath(Ifx_HSCT *hsct)
{
    hsct->DISABLE.B.RX_DIS = 0x0U;
}


IFX_INLINE void IfxHssl_disableHsctTransmitPath(Ifx_HSCT *hsct)
{
    hsct->DISABLE.B.TX_DIS = 0x1U;
}


IFX_INLINE void IfxHssl_disableHsctReceivePath(Ifx_HSCT *hsct)
{
    hsct->DISABLE.B.RX_DIS = 0x1U;
}


#endif /* IFXHSSL_H */
