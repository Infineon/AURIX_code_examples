/**
 * \file IfxSent.h
 * \brief SENT  basic functionality
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
 * \defgroup IfxLld_Sent_Std_Enumerations Enumerations
 * \ingroup IfxLld_Sent_Std
 * \defgroup IfxLld_Sent_Std_Configuration Configuration Functions
 * \ingroup IfxLld_Sent_Std
 * \defgroup IfxLld_Sent_Std_Interrupts Interrupts
 * \ingroup IfxLld_Sent_Std
 * \defgroup IfxLld_Sent_Std_Operative Operative Functions
 * \ingroup IfxLld_Sent_Std
 * \defgroup IfxLld_Sent_Std_Baudrate Baudrate Configuration
 * \ingroup IfxLld_Sent_Std
 * \defgroup IfxLld_Sent_Std_IO IO Pin Configuration Functions
 * \ingroup IfxLld_Sent_Std
 */

#ifndef IFXSENT_H
#define IFXSENT_H 1

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include "_Impl/IfxSent_cfg.h"
#include "Src/Std/IfxSrc.h"
#include "Scu/Std/IfxScuCcu.h"
#include "_PinMap/IfxSent_PinMap.h"
#include "Cpu/Std/IfxCpu_Intrinsics.h"
#include "IfxSent_bf.h"
#include "IfxSent_reg.h"

/******************************************************************************/
/*-----------------------------------Macros-----------------------------------*/
/******************************************************************************/

#define IFXSENT_INTERRUPT_STATUS_ERROR_FLAGS (0x000037f4)

/******************************************************************************/
/*--------------------------------Enumerations--------------------------------*/
/******************************************************************************/

/** \addtogroup IfxLld_Sent_Std_Enumerations
 * \{ */
/** \brief SENT.CH[channelId].IOCR.ALTI , Specifies alternate input for channel
 */
typedef enum
{
    IfxSent_AlternateInput_0 = 0,      /**< \brief Specifies alternate input 0  */
    IfxSent_AlternateInput_1,          /**< \brief Specifies alternate input 1  */
    IfxSent_AlternateInput_2,          /**< \brief Specifies alternate input 2  */
    IfxSent_AlternateInput_3           /**< \brief Specifies alternate input 3  */
} IfxSent_AlternateInput;

/** \brief SENT.CH[channelId].RSR.CST, Specifies the current channel status
 */
typedef enum
{
    IfxSent_ChannelStatus_stop        = 0, /**< \brief Specifies the channel is stopped */
    IfxSent_ChannelStatus_initialize  = 1, /**< \brief Specifies the channel is initialized */
    IfxSent_ChannelStatus_running     = 2, /**< \brief Specifies the channel is running */
    IfxSent_ChannelStatus_synchronize = 3  /**< \brief Specifies the channel is synchronized */
} IfxSent_ChannelStatus;

/** \brief SENT.FDR.DM , Specifies clock divider mode
 */
typedef enum
{
    IfxSent_ClockDividerMode_off        = 0, /**< \brief Specifies clock divider mode off */
    IfxSent_ClockDividerMode_normal     = 1, /**< \brief Specifies clock normal divider mode */
    IfxSent_ClockDividerMode_fractional = 2  /**< \brief Specifies clock fractional divider mode */
} IfxSent_ClockDividerMode;

/** \brief SENT.CH[channelId].SDS.CON , Specifies received configuration bit value
 */
typedef enum
{
    IfxSent_ConfigBit_0 = 0,      /**< \brief Specifies received configuration bit value 0  */
    IfxSent_ConfigBit_1           /**< \brief Specifies received configuration bit value 1  */
} IfxSent_ConfigBit;

/** \brief SENT.CH[channelId].IOCR.DEPTH , Specifies number of port input samples
 */
typedef enum
{
    IfxSent_DigitalGlitchesLength_off = 0,  /**< \brief Specifies port input samples off */
    IfxSent_DigitalGlitchesLength_1   = 1,  /**< \brief Specifies 1 port input samples  */
    IfxSent_DigitalGlitchesLength_2,        /**< \brief Specifies 2 port input samples  */
    IfxSent_DigitalGlitchesLength_3,        /**< \brief Specifies 3 port input samples  */
    IfxSent_DigitalGlitchesLength_4,        /**< \brief Specifies 4 port input samples  */
    IfxSent_DigitalGlitchesLength_5,        /**< \brief Specifies 5 port input samples  */
    IfxSent_DigitalGlitchesLength_6,        /**< \brief Specifies 6 port input samples  */
    IfxSent_DigitalGlitchesLength_7,        /**< \brief Specifies 7 port input samples  */
    IfxSent_DigitalGlitchesLength_8,        /**< \brief Specifies 8 port input samples  */
    IfxSent_DigitalGlitchesLength_9,        /**< \brief Specifies 9 port input samples  */
    IfxSent_DigitalGlitchesLength_10,       /**< \brief Specifies 10 port input samples  */
    IfxSent_DigitalGlitchesLength_11,       /**< \brief Specifies 11 port input samples  */
    IfxSent_DigitalGlitchesLength_12,       /**< \brief Specifies 12 port input samples  */
    IfxSent_DigitalGlitchesLength_13,       /**< \brief Specifies 13 port input samples  */
    IfxSent_DigitalGlitchesLength_14,       /**< \brief Specifies 14 port input samples  */
    IfxSent_DigitalGlitchesLength_15        /**< \brief Specifies 15 port input samples  */
} IfxSent_DigitalGlitchesLength;

/** \brief SENT.CH[channelId].RCR.ESF , Specifies the serial frame structure
 */
typedef enum
{
    IfxSent_ExtendedSerialFrameMode_standard = 0,  /**< \brief Specifies the standard serial frame structure */
    IfxSent_ExtendedSerialFrameMode_extended = 1   /**< \brief Specifies the extended serial frame structure */
} IfxSent_ExtendedSerialFrameMode;

/** \brief SENT.CH[channelId].IOCR.ETS , Specifies the external trigger line
 */
typedef enum
{
    IfxSent_ExternalTrigger_0 = 0,      /**< \brief Specifies the external trigger line 0  */
    IfxSent_ExternalTrigger_1,          /**< \brief Specifies the external trigger line 1  */
    IfxSent_ExternalTrigger_2,          /**< \brief Specifies the external trigger line 2  */
    IfxSent_ExternalTrigger_3,          /**< \brief Specifies the external trigger line 3  */
    IfxSent_ExternalTrigger_4,          /**< \brief Specifies the external trigger line 4  */
    IfxSent_ExternalTrigger_5,          /**< \brief Specifies the external trigger line 5  */
    IfxSent_ExternalTrigger_6,          /**< \brief Specifies the external trigger line 6  */
    IfxSent_ExternalTrigger_7,          /**< \brief Specifies the external trigger line 7  */
    IfxSent_ExternalTrigger_8,          /**< \brief Specifies the external trigger line 8  */
    IfxSent_ExternalTrigger_9,          /**< \brief Specifies the external trigger line 9  */
    IfxSent_ExternalTrigger_10,         /**< \brief Specifies the external trigger line 10  */
    IfxSent_ExternalTrigger_11,         /**< \brief Specifies the external trigger line 11  */
    IfxSent_ExternalTrigger_12,         /**< \brief Specifies the external trigger line 12  */
    IfxSent_ExternalTrigger_13,         /**< \brief Specifies the external trigger line 13  */
    IfxSent_ExternalTrigger_14,         /**< \brief Specifies the external trigger line 14  */
    IfxSent_ExternalTrigger_15          /**< \brief Specifies the external trigger line 15  */
} IfxSent_ExternalTrigger;

/** \brief SENT.CH[channelId].RCR.CFC, Specifies received frame check mode
 */
typedef enum
{
    IfxSent_FrameCheckMode_pastSyncPulse   = 0, /**< \brief Specifies frame check mode against past sync pulse */
    IfxSent_FrameCheckMode_futureSuncPulse = 1  /**< \brief Specifies frame check mode against future sync pulse */
} IfxSent_FrameCheckMode;

/** \brief SENT.CH[channelId].INP.X(X= RSI,RDI,RBI,TDI,TBI,ERRI,SDI,WDI),Specifies interrupt requested node for respective interrupt
 */
typedef enum
{
    IfxSent_InterruptNodePointer_trigo0 = 0,      /**< \brief Specifies interrupt requested node TRIGO 0  */
    IfxSent_InterruptNodePointer_trigo1,          /**< \brief Specifies interrupt requested node TRIGO 1  */
    IfxSent_InterruptNodePointer_trigo2,          /**< \brief Specifies interrupt requested node TRIGO 2  */
    IfxSent_InterruptNodePointer_trigo3,          /**< \brief Specifies interrupt requested node TRIGO 3  */
    IfxSent_InterruptNodePointer_trigo4,          /**< \brief Specifies interrupt requested node TRIGO 4  */
    IfxSent_InterruptNodePointer_trigo5,          /**< \brief Specifies interrupt requested node TRIGO 5  */
    IfxSent_InterruptNodePointer_trigo6,          /**< \brief Specifies interrupt requested node TRIGO 6  */
    IfxSent_InterruptNodePointer_trigo7,          /**< \brief Specifies interrupt requested node TRIGO 7  */
    IfxSent_InterruptNodePointer_trigo8,          /**< \brief Specifies interrupt requested node TRIGO 8  */
    IfxSent_InterruptNodePointer_trigo9           /**< \brief Specifies interrupt requested node TRIGO 9  */
} IfxSent_InterruptNodePointer;

/** \brief SENT.CH[channelId].VIEW.RDNPy( y=0,1,..7 ).Specifies receive data target nibble pointer
 */
typedef enum
{
    IfxSent_Nibble_0 = 0,      /**< \brief Specifies receive data target nibble pointer to nibble 0  */
    IfxSent_Nibble_1,          /**< \brief Specifies receive data target nibble pointer to nibble 1  */
    IfxSent_Nibble_2,          /**< \brief Specifies receive data target nibble pointer to nibble 2  */
    IfxSent_Nibble_3,          /**< \brief Specifies receive data target nibble pointer to nibble 3  */
    IfxSent_Nibble_4,          /**< \brief Specifies receive data target nibble pointer to nibble 4  */
    IfxSent_Nibble_5,          /**< \brief Specifies receive data target nibble pointer to nibble 5  */
    IfxSent_Nibble_6,          /**< \brief Specifies receive data target nibble pointer to nibble 6  */
    IfxSent_Nibble_7           /**< \brief Specifies receive data target nibble pointer to nibble 7  */
} IfxSent_Nibble;

/** \brief Enable/disable the sensitivity of the module to sleep signal\n
 * Definition in Ifx_SENT.CLC.B.EDIS
 */
typedef enum
{
    IfxSent_SleepMode_enable  = 0, /**< \brief enables sleep mode */
    IfxSent_SleepMode_disable = 1  /**< \brief disables sleep mode */
} IfxSent_SleepMode;

/** \brief Specifies the SENT SPC operational mode
 */
typedef enum
{
    IfxSent_SpcMode_sync          = 0, /**< \brief Specifies synchronous SPC mode */
    IfxSent_SpcMode_range         = 1, /**< \brief Specifies range selection SPC mode */
    IfxSent_SpcMode_bidirectional = 2  /**< \brief Specifies bidirectional transmit SPC mode */
} IfxSent_SpcMode;

/** \brief Ifx_SENT.OCS.B.SUS, Specifies OCDS Suspend Control
 */
typedef enum
{
    IfxSent_SuspendMode_none = 0,  /**< \brief No suspend */
    IfxSent_SuspendMode_hard = 1,  /**< \brief Hard Suspend */
    IfxSent_SuspendMode_soft = 2   /**< \brief Soft Suspend */
} IfxSent_SuspendMode;

/** \brief SENT.CH[channelId].SCR.BASE, Specifies selection of pulse based on time
 */
typedef enum
{
    IfxSent_TimeBase_measuredFrequency = 0,  /**< \brief Specifies selection of pulse based on measured frequency */
    IfxSent_TimeBase_nominalFrequency  = 1   /**< \brief Specifies selection of pulse based on nomianl frequency */
} IfxSent_TimeBase;

/** \brief SENT.CH[channelId].SCR.TRIG, Specifies trigger source for pulse generation
 */
typedef enum
{
    IfxSent_TriggerSource_off             = 0, /**< \brief Specifies no pulse generation */
    IfxSent_TriggerSource_immediate       = 1, /**< \brief Specifies immediate pulse generation */
    IfxSent_TriggerSource_fallingEdge     = 2, /**< \brief Specifies pulse generation at fallingEdge */
    IfxSent_TriggerSource_externalTrigger = 3  /**< \brief Specifies pulse generation after each external trigger */
} IfxSent_TriggerSource;

/** \} */

/** \brief SENT.CH[channelId].INTCLR, Specifies Sent Interrupt Source
 */
typedef enum
{
    IfxSent_InterruptSource_rsi  = 0,   /**< \brief Enable Interrupt Request RSI */
    IfxSent_InterruptSource_rdi  = 1,   /**< \brief Enable Interrupt Request RDI */
    IfxSent_InterruptSource_rbi  = 2,   /**< \brief Enable Interrupt Request RBI */
    IfxSent_InterruptSource_tdi  = 3,   /**< \brief Enable Interrupt Request TDI */
    IfxSent_InterruptSource_tbi  = 4,   /**< \brief Enable Interrupt Request TBI */
    IfxSent_InterruptSource_fri  = 5,   /**< \brief Enable Interrupt Request FRI */
    IfxSent_InterruptSource_fdi  = 6,   /**< \brief Enable Interrupt Request FDI */
    IfxSent_InterruptSource_nni  = 7,   /**< \brief Enable Interrupt Request NNI */
    IfxSent_InterruptSource_nvi  = 8,   /**< \brief Enable Interrupt Request NVI */
    IfxSent_InterruptSource_crci = 9,   /**< \brief Enable Interrupt Request crci */
    IfxSent_InterruptSource_wsi  = 10,  /**< \brief Enable Interrupt Request wsi */
    IfxSent_InterruptSource_sdi  = 11,  /**< \brief Enable Interrupt Request sdi */
    IfxSent_InterruptSource_scri = 12,  /**< \brief Enable Interrupt Request scri */
    IfxSent_InterruptSource_wdi  = 13   /**< \brief Enable Interrupt Request wdi */
} IfxSent_InterruptSource;

/** \addtogroup IfxLld_Sent_Std_Configuration
 * \{ */

/******************************************************************************/
/*-------------------------Inline Function Prototypes-------------------------*/
/******************************************************************************/

/**
 * \brief Sets the alternate input for the specified SENT channel.
 *
 * \param[inout] sent           Pointer to the base address of the SENT register space.
 * \param[in]    channelId      SENT channel number. Range: \ref IfxSent_ChannelId.
 * \param[in]    alternateInput Alternate input pin selection for the channel. Range: \ref IfxSent_AlternateInput.
 *
 * \retval None
 *
 */
IFX_INLINE void IfxSent_setAltiInput(Ifx_SENT *sent, IfxSent_ChannelId channelId, IfxSent_AlternateInput alternateInput);

/**
 * \brief Configures the time stamp pre-divider value for the SENT module.
 *
 * \param[inout] sent                Pointer to the base address of the SENT register space.
 * \param[in]    timeStampPreDivider Time stamp pre-divider value to be set. Range: 0 to 0xFFFFF.
 *
 * \retval None
 *
 */
IFX_INLINE void IfxSent_setTimeStampPredivider(Ifx_SENT *sent, uint32 timeStampPreDivider);

/** \} */

/** \addtogroup IfxLld_Sent_Std_Interrupts
 * \{ */

/******************************************************************************/
/*-------------------------Inline Function Prototypes-------------------------*/
/******************************************************************************/

/**
 * \brief Copies the current interrupt flags into the Ifx_SENT_CH_INTSTAT structure and clears the flags in hardware.
 * This function is designed to be used within an Interrupt Service Routine (ISR) to retrieve the events that triggered the interrupt.
 *
 * \param[inout] sent       Pointer to the base address of the SENT register space.
 * \param[in]    channelId  SENT channel number. Range: \ref IfxSent_ChannelId.
 *
 * \retval Ifx_SENT_CH_INTSTAT  Interrupt flags that have been cleared.
 * 
 */
IFX_INLINE Ifx_SENT_CH_INTSTAT IfxSent_getAndClearInterruptStatus(Ifx_SENT *sent, IfxSent_ChannelId channelId);

/**
 * \brief Retrieves the current interrupt status of a specified SENT channel.
 *
 * \param[in] sent      Pointer to the base address of the SENT register space.
 * \param[in] channelId SENT channel number. Range: \ref IfxSent_ChannelId.
 *
 * \retval Ifx_SENT_CH_INTSTAT The current interrupt status of the specified channel.
 *
 */
IFX_INLINE Ifx_SENT_CH_INTSTAT IfxSent_getChannelInterruptStatus(Ifx_SENT *sent, IfxSent_ChannelId channelId);

/**
 * \brief Retrieves the interrupt source register for the specified SENT channel.
 *
 * \param[in] channelId The SENT channel identifier. Range: \ref IfxSent_ChannelId.
 *
 * \retval  Ifx_SRC_SRCR* A pointer to the interrupt source register for the specified channel.
 *
 */
IFX_INLINE volatile Ifx_SRC_SRCR *IfxSent_getChannelSrc(IfxSent_ChannelId channelId);

/** \} */

/** \addtogroup IfxLld_Sent_Std_Operative
 * \{ */

/******************************************************************************/
/*-------------------------Inline Function Prototypes-------------------------*/
/******************************************************************************/

/**
 * \brief Disables the specified SENT channel, stopping further transmission on it.
 *
 * \param[inout] sent      Pointer to the base address of the SENT register space.
 * \param[in]    channelId The ID of the SENT channel to disable. Range: \ref IfxSent_ChannelId.
 *
 * \retval None
 * 
 */
IFX_INLINE void IfxSent_disableChannel(Ifx_SENT *sent, IfxSent_ChannelId channelId);

/**
 * \brief Disables the operation of the SENT module.
 *
 * \param[inout] Pointer to the base address of the SENT register space.
 *
 * \retval None
 * 
 */
IFX_INLINE void IfxSent_disableModule(Ifx_SENT *sent);

/**
 * \brief Enables the specified SENT channel for operation.
 *
 * \param[inout] sent      Pointer to the base address of the SENT register space.
 * \param[in]    channelId The ID of the SENT channel to be enabled. Range: \ref IfxSent_ChannelId.
 *
 * \retval None
 * 
 */
IFX_INLINE void IfxSent_enableChannel(Ifx_SENT *sent, IfxSent_ChannelId channelId);

/**
 * \brief Enables the SENT module.
 *
 * \param[inout] sent Pointer to the base address of the SENT register space.
 *
 * \retval None
 * 
 */
IFX_INLINE void IfxSent_enableModule(Ifx_SENT *sent);

/**
 * \brief Checks if the SENT module is in a suspended state.
 *
 * \param[in] sent Pointer to the base address of the SENT register space.
 *
 * \retval  TRUE If Module is suspended.
 *          FALSE If Module is not suspended.
 *
 */
IFX_INLINE boolean IfxSent_isModuleSuspended(Ifx_SENT *sent);

/**
 * \brief Sets the sensitivity of the module to sleep signal.
 *
 * \param[inout] sent Pointer to the base address of the SENT register space.
 * \param[in]    mode Mode selection for sleep signal sensitivity. Range: \ref IfxSent_SleepMode.
 *
 * \retval None
 *
 */
IFX_INLINE void IfxSent_setSleepMode(Ifx_SENT *sent, IfxSent_SleepMode mode);

/**
 * \brief Configures the SENT module's suspend mode to either Hard, Soft, or None.
 *
 * \param[inout] sent Pointer to the base address of the SENT register space.
 * \param[in]    mode Module suspend mode to be configured. Range: \ref IfxSent_SuspendMode.
 *
 * \note The API works only when the OCDS is enabled and in Supervisor Mode. When OCDS is disabled, the OCS suspend control is ineffective.
 *
 * \retval None
 *
 */
IFX_INLINE void IfxSent_setSuspendMode(Ifx_SENT *sent, IfxSent_SuspendMode mode);

/******************************************************************************/
/*-------------------------Global Function Prototypes-------------------------*/
/******************************************************************************/

/**
 * \brief Resets the SENT module to its initial state.
 *
 * \param[inout] sent Pointer to the base address of the SENT register space.
 *
 * \retval None
 * 
 */
IFX_EXTERN void IfxSent_resetModule(Ifx_SENT *sent);

/** \} */

/** \addtogroup IfxLld_Sent_Std_Baudrate
 * \{ */

/******************************************************************************/
/*-------------------------Inline Function Prototypes-------------------------*/
/******************************************************************************/

/**
 * \brief Sets the channel fractional baudrate divider for the specified SENT channel.
 * 
 * \param[inout] sent      Pointer to the base address of the SENT register space.
 * \param[in]    channelId SENT channel number. Range: \ref IfxSent_ChannelId.
 * \param[in]    divider   Channel baudrate fractional divider value. Range: 2200 to 49100.
 *
 * \retval None
 *
 */
IFX_INLINE void IfxSent_setChannelFractionalDivider(Ifx_SENT *sent, IfxSent_ChannelId channelId, uint16 divider);

/**
 * \brief Configures the baudrate pre-divider for the specified SENT channel.
 *
 * \param[inout] sent       Pointer to the base address of the SENT register space.
 * \param[in]    channelId  SENT channel number. Range: \ref IfxSent_ChannelId.
 * \param[in]    preDivider Baudrate pre-divider value to be set. Range: 0 to 0x0FFF.
 *
 * \retval None
 * 
 */
IFX_INLINE void IfxSent_setChannelPreDivider(Ifx_SENT *sent, IfxSent_ChannelId channelId, uint16 preDivider);

/******************************************************************************/
/*-------------------------Global Function Prototypes-------------------------*/
/******************************************************************************/

/**
 * \brief Retrieves the module clock frequency for the specified SENT module.
 *
 * \param[in] sent Pointer to the base address of the SENT register space.
 *
 * \retval float32 The current module frequency in Hertz.
 *
 */
IFX_EXTERN float32 IfxSent_getModuleClock(Ifx_SENT *sent);

/**
 * \brief Initializes the desired unit time (f_tick) for the external SENT device connected to the given channel
 *
 * \param[inout] sent      Pointer to the base address of the SENT register space.
 * \param[in]    channelId SENT channel number.  Range: \ref IfxSent_ChannelId.
 * \param[in]    tUnit     Desired unit time (f_tick), e.g. 3E-6 for 3 uS.
 *
 * \retval None
 *
 */
IFX_EXTERN void IfxSent_initializeChannelUnitTime(Ifx_SENT *sent, IfxSent_ChannelId channelId, float32 tUnit);

/**
 * \brief Initializes the SENT module clock with the specified divider mode and step value.
 *
 * \param[inout] sent        Pointer to the base address of the SENT register space.
 * \param[in]    dividerMode Divider mode for clock output. Range: \ref IfxSent_ClockDividerMode.
 * \param[in]    stepValue   Clock frequency for for module fractional divider. Range: 0 to 1023.
 *
 * \retval None
 *
 */
IFX_EXTERN void IfxSent_initializeModuleClock(Ifx_SENT *sent, IfxSent_ClockDividerMode dividerMode, uint16 stepValue);

/** \} */

/** \addtogroup IfxLld_Sent_Std_IO
 * \{ */

/******************************************************************************/
/*-------------------------Inline Function Prototypes-------------------------*/
/******************************************************************************/

/**
 * \brief Initializes a SENT input pin with the specified input mode and pad driver.
 *
 * \param[in] sentIn    Pointer to the SENT Pin which should be configured.
 * \param[in] inputMode The pin input mode which should be configured. Range: \ref IfxPort_InputMode.
 * \param[in] padDriver The pad driver mode which should be configured. Range: \ref IfxPort_PadDriver.
 *
 * \retval None
 *
 */
IFX_INLINE void IfxSent_initSentPin(const IfxSent_Sent_In *sentIn, IfxPort_InputMode inputMode, IfxPort_PadDriver padDriver);

/**
 * \brief Initializes the SENT SPC output pin with the specified output mode and pad driver.
 *
 * \param[in] spcOut     Pointer to the SPC Pin which should be configured.
 * \param[in] spcOutMode Port Output Mode. Range: \ref IfxPort_OutputMode.
 * \param[in] padDriver  The pad driver mode which should be configured. Range: \ref IfxPort_PadDriver.
 *
 * \retval None
 *
 */
IFX_INLINE void IfxSent_initSpcPin(const IfxSent_Spc_Out *spcOut, IfxPort_OutputMode spcOutMode, IfxPort_PadDriver padDriver);

/** \} */

/******************************************************************************/
/*-------------------------Inline Function Prototypes-------------------------*/
/******************************************************************************/

/**
 * \brief Retrieves the total frame length including the pause pulse for a specified SENT channel.
 *
 * \param[in] sent      Pointer to the base address of the SENT register space.
 * \param[in] channelId SENT channel number. Range: \ref IfxSent_ChannelId.
 *
 * \retval uint16 Returns the Frame length with pause pulse. Range: 0 to 65535.
 *
 */
IFX_INLINE uint16 IfxSent_getFrameLengthWithPausePulse(Ifx_SENT *sent, IfxSent_ChannelId channelId);

/**
 * \brief Set the watch dog timer limit value for a specified sent channel.
 *
 * \param[inout] sent               Pointer to the base address of the SENT register space.
 * \param[in]    channelId          SENT channel number. Range: \ref IfxSent_ChannelId.
 * \param[in]    watchDogTimerLimit Specifies the watch dog timer limit value. Range: 0 to 65535.
 *
 * \retval None
 *
 */
IFX_INLINE void IfxSent_setWatchDogTimerLimit(Ifx_SENT *sent, IfxSent_ChannelId channelId, uint16 watchDogTimerLimit);

/**
 * \brief Checks if the specified SENT module is enabled.
 *
 * \param[in] sent Pointer to the base address of the SENT register space.
 *
 * \retval TRUE If the module is enabled.
 *         FALSE If the module is disabled.
 *
 */
IFX_INLINE boolean IfxSent_isModuleEnabled(Ifx_SENT *sent);

/**
 * \brief Retrieves the interrupt status for a specific SENT channel and interrupt source.
 *
 * \param[in] sent      Pointer to the base address of the SENT register space.
 * \param[in] channelId SENT channel number. Range: \ref IfxSent_ChannelId.
 * \param[in] source    SENT interrupt source. Range: \ref IfxSent_InterruptSource.
 *
 * \retval TRUE If the specified interrupt is active.
 *         FALSE If the specified interrupt is inactive.
 *
 */
IFX_INLINE boolean IfxSent_getInterruptStatus(Ifx_SENT *sent, IfxSent_ChannelId channelId, IfxSent_InterruptSource source);

/**
 * \brief Clear the Interrupt Status for a SENT channel.
 *
 * \param[inout] sent      Pointer to the base address of the SENT register space.
 * \param[in]    channelId SENT channel number. Range: \ref IfxSent_ChannelId.
 * \param[in]    source    SENT interrupt source. Range: \ref IfxSent_InterruptSource.
 *
 * \retval None
 *
 */
IFX_INLINE void IfxSent_clearInterruptStatus(Ifx_SENT *sent, IfxSent_ChannelId channelId, IfxSent_InterruptSource source);

/**
 * \brief Reads the received data from the specified SENT channel.
 *
 * \param[in] sent      Pointer to the base address of the SENT register space.
 * \param[in] channelId SENT channel number.  Range: \ref IfxSent_ChannelId.
 *
 * \retval uint32 The Data content of a recieved Data Frame. Range: 0 to 0xFFFFFFFF.
 *
 */
IFX_INLINE uint32 IfxSent_readReceivedData(Ifx_SENT *sent, IfxSent_ChannelId channelId);

/**
 * \brief Reads and returns value in RSR (Received Status Register).
 *
 * \param[in] sent      Pointer to the base address of the SENT register space.
 * \param[in] channelId SENT channel number. Range: \ref IfxSent_ChannelId.
 *
 * \retval uint32 Returns 32 bit Receive status register(RSR). Range: 0 to 0xFFFF0F3F.
 *
 */
IFX_INLINE uint32 IfxSent_readReceivedStatus(Ifx_SENT *sent, IfxSent_ChannelId channelId);

/**
 * \brief Read and returns 4 bit CRC value in Receive Status Register.
 *
 * \param[in] sent      Pointer to the base address of the SENT register space.
 * \param[in] channelId SENT channel number. Range: \ref IfxSent_ChannelId.
 *
 * \retval uint8 4 bit CRC. Range: 0 to 15.
 *
 */
IFX_INLINE uint8 IfxSent_readReceivedCrc(Ifx_SENT *sent, IfxSent_ChannelId channelId);

/**
 * \brief Read and returns 2 bit CST value in Receive Status Register.
 *
 * \param[in] sent      Pointer to the base address of the SENT register space.
 * \param[in] channelId SENT channel number. Range: \ref IfxSent_ChannelId.
 *
 * \retval uint8 2 bit Channel status(CST). Range: 0 to 3.
 *
 */
IFX_INLINE uint8 IfxSent_readReceivedChannelStatus(Ifx_SENT *sent, IfxSent_ChannelId channelId);

/**
 * \brief Read and returns 4 bit SCN value in Receive Status Register.
 *
 * \param[in] sent      Pointer to the base address of the SENT register space.
 * \param[in] channelId SENT channel number. Range: \ref IfxSent_ChannelId.
 *
 * \retval uint8 4 bit Status and communication nibble(SCN). Range: 0 to 15.
 *
 */
IFX_INLINE uint8 IfxSent_readReceivedStatusAndCommunicationNibble(Ifx_SENT *sent, IfxSent_ChannelId channelId);

/**
 * \brief Read and returns 32 bit Received Time Stamp Value.
 *
 * \param[in] sent      Pointer to the base address of the SENT register space.
 * \param[in] channelId SENT channel number. Range: \ref IfxSent_ChannelId.
 *
 * \retval uint32 32 bit Time Stamp. Range: 0 to 0xFFFFFFFF.
 *
 */
IFX_INLINE uint32 IfxSent_readReceivedTimeStamp(Ifx_SENT *sent, IfxSent_ChannelId channelId);

/**
 * \brief Read and returns 6 bit PLEN value in SCR Register.
 *
 * \param[in] sent      Pointer to the base address of the SENT register space.
 * \param[in] channelId SENT channel. Range: \ref IfxSent_ChannelId.
 *
 * \retval uint8 6 bit Pulse length(PLEN). Range: 0 to 63.
 *
 */
IFX_INLINE uint8 IfxSent_readSpcPulseLength(Ifx_SENT *sent, IfxSent_ChannelId channelId);

/**
 * \brief Read and returns 6 bit Delay length value in SCR Register.
 *
 * \param[in] sent      Pointer to the base address of the SENT register space.
 * \param[in] channelId SENT channel number. Range: \ref IfxSent_ChannelId.
 *
 * \retval uint8 6 bit Delay length(DEL). Range: 0 to 63.
 *
 */
IFX_INLINE uint8 IfxSent_readSpcDelayLength(Ifx_SENT *sent, IfxSent_ChannelId channelId);

/******************************************************************************/
/*-------------------------Global Function Prototypes-------------------------*/
/******************************************************************************/

/**
 * \brief Read and returns the current unit time (f_tick) of the given channel.
 *
 * \param[in] sent      Pointer to the base address of the SENT register space.
 * \param[in] channelId SENT channel number. Range: \ref IfxSent_ChannelId.
 *
 * \retval float32 The current unit time in seconds.
 *
 */
IFX_EXTERN float32 IfxSent_getChannelUnitTime(Ifx_SENT *sent, IfxSent_ChannelId channelId);

/******************************************************************************/
/*---------------------Inline Function Implementations------------------------*/
/******************************************************************************/

IFX_INLINE void IfxSent_disableChannel(Ifx_SENT *sent, IfxSent_ChannelId channelId)
{
    sent->CH[channelId].RCR.B.CEN = 0;
}


IFX_INLINE void IfxSent_disableModule(Ifx_SENT *sent)
{
    uint16 passwd = IfxScuWdt_getCpuWatchdogPassword();
    IfxScuWdt_clearCpuEndinit(passwd);
    sent->CLC.B.DISR = 1;
    IfxScuWdt_setCpuEndinit(passwd);
}


IFX_INLINE void IfxSent_enableChannel(Ifx_SENT *sent, IfxSent_ChannelId channelId)
{
    sent->CH[channelId].RCR.B.CEN = 1;
}


IFX_INLINE void IfxSent_enableModule(Ifx_SENT *sent)
{
    uint16 passwd = IfxScuWdt_getCpuWatchdogPassword();
    IfxScuWdt_clearCpuEndinit(passwd);
    sent->CLC.B.DISR = 0;
    IfxScuWdt_setCpuEndinit(passwd);

    if (sent->CLC.U)
    {}
}


IFX_INLINE Ifx_SENT_CH_INTSTAT IfxSent_getAndClearInterruptStatus(Ifx_SENT *sent, IfxSent_ChannelId channelId)
{
    Ifx_SENT_CH_INTSTAT interruptFlags;
    interruptFlags.U             = sent->CH[channelId].INTSTAT.U;
    sent->CH[channelId].INTCLR.U = interruptFlags.U;
    return interruptFlags;
}


IFX_INLINE Ifx_SENT_CH_INTSTAT IfxSent_getChannelInterruptStatus(Ifx_SENT *sent, IfxSent_ChannelId channelId)
{
    Ifx_SENT_CH_INTSTAT interruptFlags;
    interruptFlags.U = sent->CH[channelId].INTSTAT.U;
    return interruptFlags;
}


IFX_INLINE volatile Ifx_SRC_SRCR *IfxSent_getChannelSrc(IfxSent_ChannelId channelId)
{
    Ifx_SENT_CH_INP tempINP;
    tempINP.U = MODULE_SENT.CH[channelId].INP.U;
    return &MODULE_SRC.SENT.SENT[tempINP.B.RSI].SR;
}


IFX_INLINE uint16 IfxSent_getFrameLengthWithPausePulse(Ifx_SENT *sent, IfxSent_ChannelId channelId)
{
    uint16 frameLength;
    frameLength = sent->CH[channelId].RSR.B.FRLEN;
    return frameLength;
}


IFX_INLINE void IfxSent_initSentPin(const IfxSent_Sent_In *sentIn, IfxPort_InputMode inputMode, IfxPort_PadDriver padDriver)
{
    if (sentIn->pin.port != NULL_PTR)
    {
        IfxPort_setPinModeInput(sentIn->pin.port, sentIn->pin.pinIndex, inputMode);
        IfxPort_setPinPadDriver(sentIn->pin.port, sentIn->pin.pinIndex, padDriver);
        IfxSent_setAltiInput(sentIn->module, sentIn->channelId, (IfxSent_AlternateInput)sentIn->select);
    }
}


IFX_INLINE void IfxSent_initSpcPin(const IfxSent_Spc_Out *spcOut, IfxPort_OutputMode spcOutMode, IfxPort_PadDriver padDriver)
{
    if (spcOut->pin.port != NULL_PTR)
    {
        IfxPort_setPinModeOutput(spcOut->pin.port, spcOut->pin.pinIndex, spcOutMode, spcOut->select);
        IfxPort_setPinPadDriver(spcOut->pin.port, spcOut->pin.pinIndex, padDriver);
    }
}


IFX_INLINE boolean IfxSent_isModuleSuspended(Ifx_SENT *sent)
{
    Ifx_SENT_OCS ocs;

    /* Read the status */
    ocs.U = sent->OCS.U;

    /* Return the status */
    return ocs.B.SUSSTA;
}


IFX_INLINE void IfxSent_setAltiInput(Ifx_SENT *sent, IfxSent_ChannelId channelId, IfxSent_AlternateInput alternateInput)
{
    sent->CH[channelId].IOCR.B.ALTI = alternateInput;
}


IFX_INLINE void IfxSent_setChannelFractionalDivider(Ifx_SENT *sent, IfxSent_ChannelId channelId, uint16 divider)
{
    sent->CH[channelId].CFDR.B.DIV = divider;
}


IFX_INLINE void IfxSent_setChannelPreDivider(Ifx_SENT *sent, IfxSent_ChannelId channelId, uint16 preDivider)
{
    sent->CH[channelId].CPDR.B.PDIV = preDivider;
}


IFX_INLINE void IfxSent_setSleepMode(Ifx_SENT *sent, IfxSent_SleepMode mode)
{
    uint16 passwd = IfxScuWdt_getCpuWatchdogPassword();
    IfxScuWdt_clearCpuEndinit(passwd);
    sent->CLC.B.EDIS = mode;
    IfxScuWdt_setCpuEndinit(passwd);
}


IFX_INLINE void IfxSent_setSuspendMode(Ifx_SENT *sent, IfxSent_SuspendMode mode)
{
    Ifx_SENT_OCS ocs;

    /* Remove protection and configure the suspend mode. */
    ocs.B.SUS_P = 1;
    ocs.B.SUS   = mode;
    sent->OCS.U = ocs.U;
}


IFX_INLINE void IfxSent_setTimeStampPredivider(Ifx_SENT *sent, uint32 timeStampPreDivider)
{
    sent->TPD.B.TDIV = timeStampPreDivider;
}


IFX_INLINE void IfxSent_setWatchDogTimerLimit(Ifx_SENT *sent, IfxSent_ChannelId channelId, uint16 watchDogTimerLimit)
{
    sent->CH[channelId].WDT.B.WDL = watchDogTimerLimit;
}


IFX_INLINE boolean IfxSent_isModuleEnabled(Ifx_SENT *sent)
{
    return sent->CLC.B.DISS == 0;
}


IFX_INLINE boolean IfxSent_getInterruptStatus(Ifx_SENT *sent, IfxSent_ChannelId channelId, IfxSent_InterruptSource source)
{
    return (sent->CH[channelId].INTSTAT.U >> source) == 1;
}


IFX_INLINE void IfxSent_clearInterruptStatus(Ifx_SENT *sent, IfxSent_ChannelId channelId, IfxSent_InterruptSource source)
{
    sent->CH[channelId].INTCLR.U = (1 << source);
}


IFX_INLINE uint32 IfxSent_readReceivedData(Ifx_SENT *sent, IfxSent_ChannelId channelId)
{
    return sent->RDR[channelId].U;
}


IFX_INLINE uint32 IfxSent_readReceivedStatus(Ifx_SENT *sent, IfxSent_ChannelId channelId)
{
    return sent->CH[channelId].RSR.U;
}


IFX_INLINE uint8 IfxSent_readReceivedCrc(Ifx_SENT *sent, IfxSent_ChannelId channelId)
{
    return sent->CH[channelId].RSR.B.CRC;
}


IFX_INLINE uint8 IfxSent_readReceivedChannelStatus(Ifx_SENT *sent, IfxSent_ChannelId channelId)
{
    return sent->CH[channelId].RSR.B.CST;
}


IFX_INLINE uint8 IfxSent_readReceivedStatusAndCommunicationNibble(Ifx_SENT *sent, IfxSent_ChannelId channelId)
{
    return sent->CH[channelId].RSR.B.SCN;
}


IFX_INLINE uint32 IfxSent_readReceivedTimeStamp(Ifx_SENT *sent, IfxSent_ChannelId channelId)
{
    return sent->RTS[channelId].U;
}


IFX_INLINE uint8 IfxSent_readSpcPulseLength(Ifx_SENT *sent, IfxSent_ChannelId channelId)
{
    return sent->CH[channelId].SCR.B.PLEN;
}


IFX_INLINE uint8 IfxSent_readSpcDelayLength(Ifx_SENT *sent, IfxSent_ChannelId channelId)
{
    return sent->CH[channelId].SCR.B.DEL;
}


#endif /* IFXSENT_H */
