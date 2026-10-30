/**
 * \file IfxPsi5.h
 * \brief PSI5  basic functionality
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
 * \defgroup IfxLld_Psi5_Std_Enumerations Enumerations
 * \ingroup IfxLld_Psi5_Std
 * \defgroup IfxLld_Psi5_Std_Channel Channel Status Functions
 * \ingroup IfxLld_Psi5_Std
 * \defgroup IfxLld_Psi5_Std_IO IO Pin Configuration Functions
 * \ingroup IfxLld_Psi5_Std
 * \defgroup IfxLld_Psi5_Std_Interrupt Interrupt configuration function
 * \ingroup IfxLld_Psi5_Std
 * \defgroup IfxLld_Psi5_Std_Operative Operative functions
 * \ingroup IfxLld_Psi5_Std
 */

#ifndef IFXPSI5_H
#define IFXPSI5_H 1

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include "_Impl/IfxPsi5_cfg.h"
#include "_PinMap/IfxPsi5_PinMap.h"
#include "IfxPsi5_reg.h"
#include "Scu/Std/IfxScuWdt.h"
#include "Cpu/Std/IfxCpu_Intrinsics.h"
#include "Src/Std/IfxSrc.h"

/******************************************************************************/
/*--------------------------------Enumerations--------------------------------*/
/******************************************************************************/

/** \addtogroup IfxLld_Psi5_Std_Enumerations
 * \{ */
/** \brief MODULE_PSI5.IOCRx.ALTI(x = 0,1,2),Alternate input selection
 */
typedef enum
{
    IfxPsi5_AlternateInput_0 = 0,      /**< \brief Alternate Input  0  */
    IfxPsi5_AlternateInput_1,          /**< \brief Alternate Input  1  */
    IfxPsi5_AlternateInput_2,          /**< \brief Alternate Input  2  */
    IfxPsi5_AlternateInput_3           /**< \brief Alternate Input  3  */
} IfxPsi5_AlternateInput;

/** \brief MODULE_PSI5.RCRCx.BRS(x = 0,1,2),Baud rate selection
 */
typedef enum
{
    IfxPsi5_BaudRate_125 = 0,  /**< \brief Slow 125 kHz clock */
    IfxPsi5_BaudRate_189 = 1   /**< \brief Fast 189 kHz clock */
} IfxPsi5_BaudRate;

/** \brief MODULE_PSI5.RCRBx.CRCy(x = 0,1,2; y=0,1,2,3,4,5),CRC or parity selection
 */
typedef enum
{
    IfxPsi5_CRCorParity_parity = 0,  /**< \brief parity selection */
    IfxPsi5_CRCorParity_crc    = 1   /**< \brief CRC selection */
} IfxPsi5_CRCorParity;

/** \brief Clock type
 */
typedef enum
{
    IfxPsi5_ClockType_fracDiv       = 0,  /**< \brief Fractional Divide clock */
    IfxPsi5_ClockType_slowClock_125 = 1,  /**< \brief Slow 125 kHz clock */
    IfxPsi5_ClockType_fastClock_189 = 2,  /**< \brief Fast 189 kHz clock */
    IfxPsi5_ClockType_timeStamp     = 3   /**< \brief Timestamp clock */
} IfxPsi5_ClockType;

/** \brief MODULE_PSI5.IOCRx.DEPTH(x = 0,1,2),Digital input filter depth
 */
typedef enum
{
    IfxPsi5_DigitalInputFilterDepth_0 = 0,      /**< \brief Digital input filter depth is  0  */
    IfxPsi5_DigitalInputFilterDepth_1,          /**< \brief Digital input filter depth is  1  */
    IfxPsi5_DigitalInputFilterDepth_2,          /**< \brief Digital input filter depth is  2  */
    IfxPsi5_DigitalInputFilterDepth_3,          /**< \brief Digital input filter depth is  3  */
    IfxPsi5_DigitalInputFilterDepth_4,          /**< \brief Digital input filter depth is  4  */
    IfxPsi5_DigitalInputFilterDepth_5,          /**< \brief Digital input filter depth is  5  */
    IfxPsi5_DigitalInputFilterDepth_6,          /**< \brief Digital input filter depth is  6  */
    IfxPsi5_DigitalInputFilterDepth_7,          /**< \brief Digital input filter depth is  7  */
    IfxPsi5_DigitalInputFilterDepth_8,          /**< \brief Digital input filter depth is  8  */
    IfxPsi5_DigitalInputFilterDepth_9,          /**< \brief Digital input filter depth is  9  */
    IfxPsi5_DigitalInputFilterDepth_10,         /**< \brief Digital input filter depth is  10  */
    IfxPsi5_DigitalInputFilterDepth_11,         /**< \brief Digital input filter depth is  11  */
    IfxPsi5_DigitalInputFilterDepth_12,         /**< \brief Digital input filter depth is  12  */
    IfxPsi5_DigitalInputFilterDepth_13,         /**< \brief Digital input filter depth is  13  */
    IfxPsi5_DigitalInputFilterDepth_14,         /**< \brief Digital input filter depth is  14  */
    IfxPsi5_DigitalInputFilterDepth_15          /**< \brief Digital input filter depth is  15  */
} IfxPsi5_DigitalInputFilterDepth;

/** \brief MODULE_PSI5.FDR.DM,Divider mode
 */
typedef enum
{
    IfxPsi5_DividerMode_spb        = 0,  /**< \brief divider mode is off */
    IfxPsi5_DividerMode_normal     = 1,  /**< \brief divider mode is normal */
    IfxPsi5_DividerMode_fractional = 2,  /**< \brief divider mode is fractional */
    IfxPsi5_DividerMode_off        = 3   /**< \brief divider mode is off */
} IfxPsi5_DividerMode;

/** \brief MODULE_PSI5.RCRBx.FECy(x = 0,1,2; y=0,1,2,3,4,5),Frame expectation control
 */
typedef enum
{
    IfxPsi5_FrameExpectation_notExpected = 0,  /**< \brief No frame is expected */
    IfxPsi5_FrameExpectation_expected    = 1   /**< \brief Frame is expected */
} IfxPsi5_FrameExpectation;

/** \brief specifies interrupt node pointer defined in MODULE_PSI5.INP[x].U
 */
typedef enum
{
    IfxPsi5_InterruptNodePointer_rsi  = 0,  /**< \brief Interrupt Node Pointer for Interrupt RSI */
    IfxPsi5_InterruptNodePointer_rdi  = 1,  /**< \brief Interrupt Node Pointer for Interrupt RDI */
    IfxPsi5_InterruptNodePointer_rbi  = 2,  /**< \brief Interrupt Node Pointer for Interrupt RBI */
    IfxPsi5_InterruptNodePointer_tdi  = 3,  /**< \brief Interrupt Node Pointer for Interrupt TDI */
    IfxPsi5_InterruptNodePointer_tbi  = 4,  /**< \brief Interrupt Node Pointer for Interrupt TBI */
    IfxPsi5_InterruptNodePointer_erri = 5,  /**< \brief Interrupt Node Pointer for Interrupt ERRI */
    IfxPsi5_InterruptNodePointer_sdi  = 6,  /**< \brief Interrupt Node Pointer for Interrupt SDI */
    IfxPsi5_InterruptNodePointer_fwi  = 7   /**< \brief Interrupt Node Pointer for Interrupt FWI */
} IfxPsi5_InterruptNodePointer;

/** \brief Enable/Disable Interrupt Request.defined in MODULE_PSI5.INTENA[x]
 */
typedef enum
{
    IfxPsi5_InterruptRequest_disabled = 0,  /**< \brief No Interrupt Request can be generated for respective source */
    IfxPsi5_InterruptRequest_enabled  = 1   /**< \brief An Interrupt Request can be generated for source */
} IfxPsi5_InterruptRequest;

/** \brief enable the interrupt source of any interrupt of PSI5 Channel.specify in MODULE_PSI5.INTENA[x].U and MODULE_PSI5.INTENB[x].U
 */
typedef enum
{
    IfxPsi5_InterruptSource_rsi   = 0,   /**< \brief Enable Interrupt Request RSI */
    IfxPsi5_InterruptSource_rdi   = 1,   /**< \brief Enable Interrupt Request RDI */
    IfxPsi5_InterruptSource_rbi   = 2,   /**< \brief Enable Interrupt Request RBI */
    IfxPsi5_InterruptSource_tei   = 3,   /**< \brief Enable Interrupt Request TEI */
    IfxPsi5_InterruptSource_nbi   = 4,   /**< \brief Enable Interrupt Request NBI */
    IfxPsi5_InterruptSource_mei   = 5,   /**< \brief Enable Interrupt Request MEI */
    IfxPsi5_InterruptSource_crci  = 6,   /**< \brief Enable Interrupt Request CRCI */
    IfxPsi5_InterruptSource_fwi   = 7,   /**< \brief Enable Interrupt Request FWI */
    IfxPsi5_InterruptSource_rui   = 8,   /**< \brief Enable Interrupt Request RUI */
    IfxPsi5_InterruptSource_rmi   = 9,   /**< \brief Enable Interrupt Request RMI */
    IfxPsi5_InterruptSource_tpi   = 10,  /**< \brief Enable Interrupt Request TPI */
    IfxPsi5_InterruptSource_tpoi  = 11,  /**< \brief Enable Interrupt Request TPOI */
    IfxPsi5_InterruptSource_tsi   = 12,  /**< \brief Enable Interrupt Request TSI */
    IfxPsi5_InterruptSource_tsoi  = 13,  /**< \brief Enable Interrupt Request TSOI */
    IfxPsi5_InterruptSource_toi   = 14,  /**< \brief Enable Interrupt Request TOI */
    IfxPsi5_InterruptSource_tooi  = 15,  /**< \brief Enable Interrupt Request TOOI */
    IfxPsi5_InterruptSource_nfi   = 16,  /**< \brief Enable Interrupt Request NFI */
    IfxPsi5_InterruptSource_wsi0  = 17,  /**< \brief Enable Interrupt Request WSi0 */
    IfxPsi5_InterruptSource_wsi1  = 18,  /**< \brief Enable Interrupt Request WSI1 */
    IfxPsi5_InterruptSource_wsi2  = 19,  /**< \brief Enable Interrupt Request WSI2 */
    IfxPsi5_InterruptSource_wsi3  = 20,  /**< \brief Enable Interrupt Request WSI3 */
    IfxPsi5_InterruptSource_wsi4  = 21,  /**< \brief Enable Interrupt Request WSI4 */
    IfxPsi5_InterruptSource_wsi5  = 22,  /**< \brief Enable Interrupt Request WSI */
    IfxPsi5_InterruptSource_sdi0  = 23,  /**< \brief Enable Interrupt Request SDI0 */
    IfxPsi5_InterruptSource_sdi1  = 24,  /**< \brief Enable Interrupt Request SDI1 */
    IfxPsi5_InterruptSource_sdi2  = 25,  /**< \brief Enable Interrupt Request SDI2 */
    IfxPsi5_InterruptSource_sdi3  = 26,  /**< \brief Enable Interrupt Request SDI3 */
    IfxPsi5_InterruptSource_sdi4  = 27,  /**< \brief Enable Interrupt Request SDI4 */
    IfxPsi5_InterruptSource_sdi5  = 28,  /**< \brief Enable Interrupt Request SDI5 */
    IfxPsi5_InterruptSource_soi0  = 29,  /**< \brief Enable Interrupt Request SOI0 */
    IfxPsi5_InterruptSource_soi1  = 30,  /**< \brief Enable Interrupt Request SOI1 */
    IfxPsi5_InterruptSource_soi2  = 31,  /**< \brief Enable Interrupt Request SOI2 */
    IfxPsi5_InterruptSource_soi3  = 32,  /**< \brief Enable Interrupt Request SOI3 */
    IfxPsi5_InterruptSource_soi4  = 33,  /**< \brief Enable Interrupt Request SOI4 */
    IfxPsi5_InterruptSource_soi5  = 34,  /**< \brief Enable Interrupt Request SOI4 */
    IfxPsi5_InterruptSource_scri0 = 35,  /**< \brief Enable Interrupt Request SCRI0 */
    IfxPsi5_InterruptSource_scri1 = 36,  /**< \brief Enable Interrupt Request SCRI1 */
    IfxPsi5_InterruptSource_scri2 = 37,  /**< \brief Enable Interrupt Request SCRI2 */
    IfxPsi5_InterruptSource_scri3 = 38,  /**< \brief Enable Interrupt Request SCRI3 */
    IfxPsi5_InterruptSource_scri4 = 39,  /**< \brief Enable Interrupt Request SCRI4 */
    IfxPsi5_InterruptSource_scri5 = 40   /**< \brief Enable Interrupt Request SCRI5 */
} IfxPsi5_InterruptSource;

/** \brief MODULE_PSI5.RCRBx.MSGy(x = 0,1,2; y=0,1,2,3,4,5),Messaging bits presence
 */
typedef enum
{
    IfxPsi5_MessagingBits_absent  = 0, /**< \brief No messaging bits */
    IfxPsi5_MessagingBits_present = 1  /**< \brief 2 messaging bits */
} IfxPsi5_MessagingBits;

/** \brief MODULE_PSI5.RCRCx.TSR(x = 0,1,2),Timestamp select for receive data registers
 */
typedef enum
{
    IfxPsi5_ReceiveDataRegisterTimestamp_pulse = 0,  /**< \brief Pulse based timestamp SPTSC to be stored in RDRHC */
    IfxPsi5_ReceiveDataRegisterTimestamp_frame = 1   /**< \brief Start of frame based timestamp SPTSC to be stored in RDRHC */
} IfxPsi5_ReceiveDataRegisterTimestamp;

/** \brief Enable/disable the sensitivity of the module to sleep signal\n
 * Definition in Ifx_PSI5.CLC.B.EDIS
 */
typedef enum
{
    IfxPsi5_SleepMode_enable  = 0, /**< \brief enables sleep mode */
    IfxPsi5_SleepMode_disable = 1  /**< \brief disables sleep mode */
} IfxPsi5_SleepMode;

/** \brief MODULE_PSI5.RDRHx.SC(x = 0-2),Slot Id
 */
typedef enum
{
    IfxPsi5_Slot_0 = 0,      /**< \brief slot 0  */
    IfxPsi5_Slot_1,          /**< \brief slot 1  */
    IfxPsi5_Slot_2,          /**< \brief slot 2  */
    IfxPsi5_Slot_3,          /**< \brief slot 3  */
    IfxPsi5_Slot_4,          /**< \brief slot 4  */
    IfxPsi5_Slot_5           /**< \brief slot 5  */
} IfxPsi5_Slot;

/** \brief OCDS Suspend Control (OCDS.SUS)
 */
typedef enum
{
    IfxPsi5_SuspendMode_none = 0,  /**< \brief No suspend */
    IfxPsi5_SuspendMode_hard = 1,  /**< \brief Hard Suspend */
    IfxPsi5_SuspendMode_soft = 2   /**< \brief Soft Suspend */
} IfxPsi5_SuspendMode;

/** \brief MODULE_PSI5.PGCx.TBS(x = 0,1,2),Time base
 */
typedef enum
{
    IfxPsi5_TimeBase_internal = 0,  /**< \brief Internal time stamp clock */
    IfxPsi5_TimeBase_external = 1   /**< \brief External GTM inputs */
} IfxPsi5_TimeBase;

/** \brief MODULE_PSI5.RCRCx.TSP(x = 0,1,2),MODULE_PSI5.RCRCx.TSF(x = 0,1,2)Timestamp register type
 */
typedef enum
{
    IfxPsi5_TimestampRegister_a = 0,  /**< \brief Timestamp register A */
    IfxPsi5_TimestampRegister_b = 1,  /**< \brief Timestamp register B */
    IfxPsi5_TimestampRegister_c = 2   /**< \brief Timestamp register C */
} IfxPsi5_TimestampRegister;

/** \brief MODULE_PSI5.PGCx.ETS(x = 0,1,2),Trigger Id
 */
typedef enum
{
    IfxPsi5_Trigger_0 = 0,      /**< \brief trigger  0  */
    IfxPsi5_Trigger_1,          /**< \brief trigger  1  */
    IfxPsi5_Trigger_2,          /**< \brief trigger  2  */
    IfxPsi5_Trigger_3,          /**< \brief trigger  3  */
    IfxPsi5_Trigger_4,          /**< \brief trigger  4  */
    IfxPsi5_Trigger_5           /**< \brief trigger  5  */
} IfxPsi5_Trigger;

/** \brief Output line selected by node Pointer defined in MODULE_PSI5.INP[x].U
 */
typedef enum
{
    IfxPsi5_TriggerOutput_0 = 0,      /**< \brief Triggered output line is TRIGO_0  */
    IfxPsi5_TriggerOutput_1,          /**< \brief Triggered output line is TRIGO_1  */
    IfxPsi5_TriggerOutput_2,          /**< \brief Triggered output line is TRIGO_2  */
    IfxPsi5_TriggerOutput_3,          /**< \brief Triggered output line is TRIGO_3  */
    IfxPsi5_TriggerOutput_4,          /**< \brief Triggered output line is TRIGO_4  */
    IfxPsi5_TriggerOutput_5,          /**< \brief Triggered output line is TRIGO_5  */
    IfxPsi5_TriggerOutput_6,          /**< \brief Triggered output line is TRIGO_6  */
    IfxPsi5_TriggerOutput_7           /**< \brief Triggered output line is TRIGO_7  */
} IfxPsi5_TriggerOutput;

/** \brief Trigger type
 */
typedef enum
{
    IfxPsi5_TriggerType_periodic = 0,  /**< \brief Periodic trigger */
    IfxPsi5_TriggerType_external = 1,  /**< \brief External trigger */
    IfxPsi5_TriggerType_bypass   = 2   /**< \brief Bypassed trigger */
} IfxPsi5_TriggerType;

/** \brief MODULE_PSI5.RCRBx.VBSy(x = 0,1,2; y=0,1,2,3,4,5),Verbose mode
 */
typedef enum
{
    IfxPsi5_Verbose_off = 0,  /**< \brief Verbose mode is turned off */
    IfxPsi5_Verbose_on  = 1   /**< \brief Verbose mode is turned on */
} IfxPsi5_Verbose;

/** \} */

/** \brief Options for choosing different Fractional Divider Registers
 */
typedef enum
{
    IfxPsi5_FractionalDividerRegister_normal      = 0,  /**< \brief The Fractional Divider Register controls the input clock f_fracdiv. */
    IfxPsi5_FractionalDividerRegister_lowbitrate  = 1,  /**< \brief The Fractional Divider Register for lower Bit Rate contains the pre-divider that defines the time resolution of the
                                                         * f_125.It divides f_fracdiv by a factor and provides f_125 to all channels. */
    IfxPsi5_FractionalDividerRegister_highbitrate = 2,  /**< \brief The Fractional Divider Register for Higher Bit Rate contains the pre-divider that defines the time resolution of f_189.
                                                         * It divides f_fracdiv by a factor and provides f_189 to all channels. */
    IfxPsi5_FractionalDividerRegister_timestamp   = 3   /**< \brief The PSI5 Module Time Stamp Predivider Register contains the pre-divider that defines the time resolution of the
                                                         * Time Stamp Registers TSRA/B/C and the Sync Pulse Time Base Counter SBC. It divides fPSI5 by a factor. It contains as well the bits for reset control of the time stamp counters. */
} IfxPsi5_FractionalDividerRegister;

typedef enum
{
    IfxPsi5_InterruptServiceRequest_0 = 0,  /**< \brief Interrupt Service Request 0 */
    IfxPsi5_InterruptServiceRequest_1 = 1,  /**< \brief Interrupt Service Request 1 */
    IfxPsi5_InterruptServiceRequest_2 = 2,  /**< \brief Interrupt Service Request 2 */
    IfxPsi5_InterruptServiceRequest_3 = 3,  /**< \brief Interrupt Service Request 3 */
    IfxPsi5_InterruptServiceRequest_4 = 4,  /**< \brief Interrupt Service Request 4 */
    IfxPsi5_InterruptServiceRequest_5 = 5,  /**< \brief Interrupt Service Request 5 */
    IfxPsi5_InterruptServiceRequest_6 = 6,  /**< \brief Interrupt Service Request 6 */
    IfxPsi5_InterruptServiceRequest_7 = 7   /**< \brief Interrupt Service Request 7 */
} IfxPsi5_InterruptServiceRequest;

/** \brief Optiond for different Interrupt Status Registers(ISRA,ISRB)
 */
typedef enum
{
    IfxPsi5_InterruptStatusRegister_a = 0, /**< \brief Interrupt Status Register A */
    IfxPsi5_InterruptStatusRegister_b = 1  /**< \brief Interrupt Status Register B */
} IfxPsi5_InterruptStatusRegister;

/** \brief Optiond for different Receive Control Registers(RCRA,RCRB,RCRC)
 */
typedef enum
{
    IfxPsi5_ReceiverControlRegister_a = 0,  /**< \brief Receiver Control Register A configures the payload length of the up to 6 frames in the up to 6 slots. */
    IfxPsi5_ReceiverControlRegister_b = 1,  /**< \brief Receiver Control Register B configures up to 6 frame types in the up to 6 slots */
    IfxPsi5_ReceiverControlRegister_c = 2   /**< \brief Receiver Control Register C configures bit rate and time stamp sources */
} IfxPsi5_ReceiverControlRegister;

/** \addtogroup IfxLld_Psi5_Std_Channel
 * \{ */

/******************************************************************************/
/*-------------------------Inline Function Prototypes-------------------------*/
/******************************************************************************/

/**
 * \brief Access function to get the CRCI status register contents for a specific channel.
 *
 * \param[in]    psi5        Pointer to the PSI5 register space.
 * \param[in]    channel     Channel ID for which to retrieve the CRCI status.
 *
 * \retval uint32 The contents of the CRCI status register for the specified channel. Range 0 to 0xFFFFFFFF.
 */
IFX_INLINE uint32 IfxPsi5_getStatusCrci(Ifx_PSI5 *psi5, IfxPsi5_ChannelId channel);

/**
 * \brief Retrieves the MEI status register contents for the specified channel.
 *
 * \param[in]    psi5        Pointer to the PSI5 register space.
 * \param[in]    channel     Channel ID to retrieve the MEI status for.
 *
 * \retval uint32 The contents of the MEI status register for the specified channel. Range 0 to 0xFFFFFFFF.
 */
IFX_INLINE uint32 IfxPsi5_getStatusMei(Ifx_PSI5 *psi5, IfxPsi5_ChannelId channel);

/**
 * \brief Access function to get the NBI status register contents for a specified channel.
 *
 * \param[in]    psi5        Pointer to the PSI5 register space.
 * \param[in]    channel     Channel ID to access the NBI status for.
 * 
 * \retval uint32 NBI status register contents for the specified channel. Range 0 to 0xFFFFFFFF.
 */
IFX_INLINE uint32 IfxPsi5_getStatusNbi(Ifx_PSI5 *psi5, IfxPsi5_ChannelId channel);

/**
 * \brief Retrieves the NFI status register contents for a specified channel.
 *
 * \param[in]    psi5        Pointer to the PSI5 register space.
 * \param[in]    channel     Channel ID to retrieve the NFI status
 *
 * \retval uint32 The contents of the NFI status register for the specified channel. Range 0 to 0xFFFFFFFF.
 */
IFX_INLINE uint32 IfxPsi5_getStatusNfi(Ifx_PSI5 *psi5, IfxPsi5_ChannelId channel);

/**
 * \brief Retrieves the RDI status register contents for a specified channel.
 *
 * \param[in]    psi5        Pointer to the PSI5 register space.
 * \param[in]    channel     Channel ID for which to retrieve the RDI status.
 *
 * \retval uint32 The contents of the RDI status register for the specified channel. Range 0 to 0xFFFFFFFF.
 */
IFX_INLINE uint32 IfxPsi5_getStatusRdi(Ifx_PSI5 *psi5, IfxPsi5_ChannelId channel);

/**
 * \brief Access function to get the RMI status register contents for a specific channel.
 *
 * \param[in]    psi5        Pointer to the PSI5 register space. This parameter must not be NULL.
 * \param[in]    channel     The channel ID for which the RMI status is to be retrieved. 
 *
 * \retval uint32 The contents of the RMI status register for the specified channel. Range 0 to 0xFFFFFFFF.
 */
IFX_INLINE uint32 IfxPsi5_getStatusRmi(Ifx_PSI5 *psi5, IfxPsi5_ChannelId channel);

/**
 * \brief Retrieves the RSI status register contents for the specified channel.
 *
 * \param[in]    psi5        Pointer to the PSI5 register space.
 * \param[in]    channel     Channel ID to query the RSI status for.
 *
 * \retval uint32 The contents of the RSI status register for the specified channel. Range 0 to 0xFFFFFFFF.
 */
IFX_INLINE uint32 IfxPsi5_getStatusRsi(Ifx_PSI5 *psi5, IfxPsi5_ChannelId channel);

/**
 * \brief Retrieves the TEI status register contents for the specified channel.
 *
 * \param[in]    psi5        Pointer to the PSI5 register space.
 * \param[in]    channel     Channel ID to access the TEI status for.
 *
 * \retval uint32 The contents of the TEI status register for the specified channel. Range 0 to 0xFFFFFFFF.
 */
IFX_INLINE uint32 IfxPsi5_getStatusTei(Ifx_PSI5 *psi5, IfxPsi5_ChannelId channel);

/**
 * \brief Configures the sensitivity of the PSI5 module to the sleep signal.
 *
 * \param[inout] psi5        Pointer to the PSI5 registers.
 * \param[in]    mode        Mode selection for enabling or disabling sleep mode. Range \ref IfxPsi5_ChannelId
 *
 * \retval None
 */
IFX_INLINE void IfxPsi5_setSleepMode(Ifx_PSI5 *psi5, IfxPsi5_SleepMode mode);

/******************************************************************************/
/*-------------------------Global Function Prototypes-------------------------*/
/******************************************************************************/

/**
 * \brief Resets the PSI5 module to its initial state
 *
 * \param[inout] psi5        Pointer to the PSI5 registers structure
 *
 * \retval None
 */
IFX_EXTERN void IfxPsi5_resetModule(Ifx_PSI5 *psi5);

/** \} */

/** \addtogroup IfxLld_Psi5_Std_IO
 * \{ */

/******************************************************************************/
/*-------------------------Inline Function Prototypes-------------------------*/
/******************************************************************************/

/**
 * \brief Initializes and configures a PSI5 receiver input pin with specified input mode and pad driver settings.
 *
 * \param[in]    rx          Pointer to the RX pin configuration structure to be initialized.
 * \param[in]    inputMode   Input mode to be configured for the RX pin. Possible values: Range \ref IfxPort_InputMode
 * \param[in]    padDriver   Pad driver configuration for the RX pin. Possible values: Range \ref IfxPort_PadDriver
 *
 * \retval None
 */
IFX_INLINE void IfxPsi5_initRxPin(const IfxPsi5_Rx_In *rx, IfxPort_InputMode inputMode, IfxPort_PadDriver padDriver);

/**
 * \brief Initializes and configures a TX output pin with specified mode and driver settings.
 *
 * \param[in]    tx          Pointer to the TX pin configuration structure to be initialized.
 * \param[in]    outputMode  The output mode to be configured for the TX pin. Range: \ref IfxPort_OutputMode
 * \param[in]    padDriver   The pad driver mode to be configured for the TX pin. Range: \ref IfxPort_PadDriver
 *
 * \retval None
 */
IFX_INLINE void IfxPsi5_initTxPin(const IfxPsi5_Tx_Out *tx, IfxPort_OutputMode outputMode, IfxPort_PadDriver padDriver);

/**
 * \brief Sets the alternate RX input for the PSI5 channel
 *
 * \param[inout] psi5Ch            Pointer to the PSI5 channel register space
 * \param[in]    alternateInput    Alternate RX input selection. Range: \ref IfxPsi5_AlternateInput
 *
 * \retval None
 */
IFX_INLINE void IfxPsi5_setRxInput(Ifx_PSI5_CH *psi5Ch, IfxPsi5_AlternateInput alternateInput);

/** \} */

/** \addtogroup IfxLld_Psi5_Std_Interrupt
 * \{ */

/******************************************************************************/
/*-------------------------Inline Function Prototypes-------------------------*/
/******************************************************************************/

/**
 * \brief Configures the specified interrupt node pointer for the selected channel and trigger output line.
 *
 * \param[inout] psi5              Pointer to the Ifx_PSI5 module instance
 * \param[in]    channel           Channel ID to configure. Range: \ref IfxPsi5_ChannelId
 * \param[in]    nodePointer       Pointer to the interrupt node structure. Range: \ref IfxPsi5_InterruptNodePointer
 * \param[in]    triggerOutputLine Trigger output line selection. Range: \ref IfxPsi5_TriggerOutput
 *
 * \retval None
 */
IFX_INLINE void IfxPsi5_setInterruptNodePointer(Ifx_PSI5 *psi5, IfxPsi5_ChannelId channel, IfxPsi5_InterruptNodePointer nodePointer, IfxPsi5_TriggerOutput triggerOutputLine);

/******************************************************************************/
/*-------------------------Global Function Prototypes-------------------------*/
/******************************************************************************/

/**
 * \brief Enables or disables the specified interrupt source for the given channel of the PSI5 module.
 *
 * \param[inout] psi5              Pointer to the PSI5 module instance.
 * \param[in]    channel           Specifies the channel ID to configure the interrupt for. Range: \ref IfxPsi5_ChannelId
 * \param[in]    interruptSource   Specifies the interrupt source to enable or disable. Ranage: \ref IfxPsi5_InterruptSource
 * \param[in]    enabled           Specifies whether to enable or disable the interrupt source. Range: \ref IfxPsi5_InterruptRequest
 */
IFX_EXTERN void IfxPsi5_enableInterrupt(Ifx_PSI5 *psi5, IfxPsi5_ChannelId channel, IfxPsi5_InterruptSource interruptSource, IfxPsi5_InterruptRequest enabled);

/** \} */

/** \addtogroup IfxLld_Psi5_Std_Operative
 * \{ */

/******************************************************************************/
/*-------------------------Inline Function Prototypes-------------------------*/
/******************************************************************************/

/**
 * \brief Checks if the PSI5 module is currently suspended.
 *
 * \param[in]    psi5        Pointer to the PSI5 module registers.
 * 
 * \retval TRUE If the module is suspended.
 *         FALSE If the module is not suspended.
 */
IFX_INLINE boolean IfxPsi5_isModuleSuspended(Ifx_PSI5 *psi5);

/**
 * \brief Sets the suspend mode for the PSI5 module.
 *
 * \note The API works only when the OCDS is enabled and in Supervisor Mode. When OCDS is disabled, the OCS suspend control is ineffective.
 * 
 * \param[inout] psi5        Pointer to the PSI5 module registers.
 * \param[in]    mode        Suspend mode to be configured. Range: \ref IfxPsi5_SuspendMode
 *
 *
 * \retval None
 */
IFX_INLINE void IfxPsi5_setSuspendMode(Ifx_PSI5 *psi5, IfxPsi5_SuspendMode mode);

/******************************************************************************/
/*-------------------------Global Function Prototypes-------------------------*/
/******************************************************************************/

/**
 * \brief Disables the PSI5 kernel
 *
 * \param[inout] psi5        Pointer to the base of PSI5 registers
 *
 * \retval None
 */
IFX_EXTERN void IfxPsi5_disableModule(Ifx_PSI5 *psi5);

/** \} */

/******************************************************************************/
/*-------------------------Inline Function Prototypes-------------------------*/
/******************************************************************************/

/**
 * \brief Retrieves the lower part of the receive data register for the specified PSI5 channel.
 *
 * \param[in]    psi5        Pointer to the PSI5 SFR base register.
 * \param[in]    channel     Channel ID of the PSI5 channel whose receive data register is to be accessed.
 *
 * \retval uint32 The lower 32 bits of the received data for the specified channel. Range: 0 to 0xFFFFFFFF.
 */
IFX_INLINE uint32 IfxPsi5_getReceiveDataRegisterLow(Ifx_PSI5 *psi5, IfxPsi5_ChannelId channel);

/**
 * \brief Clears all interrupt flags for the specified channel and interrupt status register.
 *
 * \param[inout] psi5        Pointer to the Ifx_PSI5 SFR base register. 
 * \param[in]    channel     Channel ID of the PSI5 channel whose interrupt flags are to be cleared. Range: \ref IfxPsi5_ChannelId
 * \param[in]    intStatusReg The register to be selected depending on the interrupt source to be probed. Range: \ref IfxPsi5_InterruptStatusRegister
 * \param[in]    value       A bitmask representing the interrupt sources to be cleared. Range: 0 to 0xFFFFFF
 *                  
 * \retval None
 */
IFX_INLINE void IfxPsi5_clearAllInterrupt(Ifx_PSI5 *psi5, IfxPsi5_ChannelId channel, IfxPsi5_InterruptStatusRegister intStatusReg, uint32 value);

/**
 * \brief Retrieves the interrupt status for a specified PSI5 channel and interrupt status register.
 *
 * \param[in]    psi5        Pointer to the PSI5 SFR base register
 * \param[in]    channel     Channel ID of the PSI5 channel to probe (depending on the interrupt source being probed). Range: \ref IfxPsi5_ChannelId
 * \param[in]    intStatusReg The interrupt status register to probe. Range: \ref IfxPsi5_InterruptStatusRegister
 *
 * \retval uint32 The register value representing the status of the interrupt sources. Range: 0 to 0xFFFFFF
 */
IFX_INLINE uint32 IfxPsi5_getInterruptStatus(Ifx_PSI5 *psi5, IfxPsi5_ChannelId channel, IfxPsi5_InterruptStatusRegister intStatusReg);

/**
 * \brief Reads the oldest data content of up to 32 received data frames for a specific PSI5 channel.
 *
 * \param[in]    psi5        Pointer to the PSI5 SFR base register structure.
 * \param[in]    channel     Channel ID of the PSI5 channel to read data from. Range: \ref IfxPsi5_ChannelId
 * 
 * \retval uint32 The oldest data content of up to 32 received data frames. Range: 0 to 0xFFFFFFFF.
 */
IFX_INLINE uint32 IfxPsi5_readReceiveFifoData(Ifx_PSI5 *psi5, IfxPsi5_ChannelId channel);

/**
 * \brief Gets the FIFO write pointer for the specified PSI5 channel.
 *
 * \param[in]    psi5        Pointer to the PSI5 SFR base register.
 * \param[in]    channel     Channel ID of the PSI5 channel. Range: \ref IfxPsi5_ChannelId
 * 
 * \retval uint16 The current FIFO write pointer value. Range: 0 to 0x3F.
 */
IFX_INLINE uint16 IfxPsi5_getWriteFifoPointer(Ifx_PSI5 *psi5, IfxPsi5_ChannelId channel);

/**
 * \brief Gets the current FIFO read pointer for the specified PSI5 channel.
 *
 * \param[in]    psi5        Pointer to the PSI5 SFR base register structure.
 * \param[in]    channel     The channel ID for which the FIFO read pointer is to be retrieved. Range: \ref IfxPsi5_ChannelId
 *
 * \retval uint16 The current read pointer value for the specified channel. Range: 0 to 0x3F.
 */
IFX_INLINE uint16 IfxPsi5_getReadFifoPointer(Ifx_PSI5 *psi5, IfxPsi5_ChannelId channel);

/**
 * \brief Clears the interrupt flag for a specified source within a given PSI5 channel.
 *
 * \param[inout] psi5        Pointer to the PSI5 SFR base register. 
 * \param[in]    channel     Channel ID of the PSI5 channel whose interrupt flag is to be cleared. Range: \ref IfxPsi5_ChannelId
 * \param[in]    interruptSource Interrupt source to be cleared. Range: \ref IfxPsi5_InterruptSource
 *
 * \retval None 
 */
IFX_INLINE void IfxPsi5_clearInterrupt(Ifx_PSI5 *psi5, IfxPsi5_ChannelId channel, IfxPsi5_InterruptSource interruptSource);

/**
 * \brief Retrieves the pointer to the SRC register for the specified PSI5 interrupt source.
 *
 * \param[in]    psi5        Pointer to the PSI5 SFR base register. 
 * \param[in]    intRequest  The interrupt service request to identify the specific interrupt source. Range: \ref IfxPsi5_InterruptServiceRequest
 *                        
 * \retval Ifx_SRC_SRCR*  The address of the SRC register corresponding to the specified interrupt service request.
 */
IFX_INLINE volatile Ifx_SRC_SRCR *IfxPsi5_getSrcPointer(Ifx_PSI5 *psi5, IfxPsi5_InterruptServiceRequest intRequest);

/**
 * \brief Enables all channels and error flags for the PSI5 peripheral.
 *
 * \param[inout] psi5        Pointer to the Ifx_PSI5 SFR base register.
 *
 * \retval None 
 */
IFX_INLINE void IfxPsi5_enableAllChannels(Ifx_PSI5 *psi5);

/**
 * \brief Sets the receive FIFO warning level for the specified PSI5 channel.
 *
 * \param[inout] psi5        Pointer to the PSI5 SFR's base address.
 * \param[in]    channel     Channel ID of the PSI5 channel to configure. Range: \ref IfxPsi5_ChannelId
 * \param[in]    value       Warning level value to be set for the receive FIFO. Range: 0 to 0x1F.
 *
 * \retval None
 */
IFX_INLINE void IfxPsi5_setReceiveFifoWarningLevel(Ifx_PSI5 *psi5, IfxPsi5_ChannelId channel, uint32 value);

/**
 * \brief Configures the receiver control register for a specified channel.
 *
 * \param[inout] psi5        Pointer to PSI5 SFR's base address.
 * \param[in]    channel     Channel ID of the PSI5 channel to configure. Range: \ref IfxPsi5_ChannelId
 * \param[in]    rcr         Receiver control register to configure. Range: \ref IfxPsi5_ReceiverControlRegister
 * \param[in]    value       Value to be written into the selected RCRy register. RCRA Range: 0 to 0xFFFFFFFF, RCRB Range: 0 to 0xFFFFFF, RCRC Range: 0 to 0x3F.
 *
 * \retval None
 */
IFX_INLINE void IfxPsi5_setReceiverControl(Ifx_PSI5 *psi5, IfxPsi5_ChannelId channel, IfxPsi5_ReceiverControlRegister rcr, uint32 value);

/**
 * \brief Configures the fractional divider for the specified PSI5 fractional divider register.
 *
 * \param[inout] psi5        Pointer to PSI5 SFR base register
 * \param[in]    fcd         Select the appropriate divider register. Range: \ref IfxPsi5_FractionalDividerRegister
 * \param[in]    value       Contains the divider value for the selected register. FDR Range: 0 to 0xC3FF, FDRL Range: 0 to 0xC3FF, FDRH Range: 0 to 0xC3FF, FDRT Range: 0 to 0x7E00C3FF.
 *
 * \retval None
 */
IFX_INLINE void IfxPsi5_setFractionalDivider(Ifx_PSI5 *psi5, IfxPsi5_FractionalDividerRegister fcd, uint32 value);

/******************************************************************************/
/*-------------------------Global Function Prototypes-------------------------*/
/******************************************************************************/

/**
 * \brief Enables the PSI5 module.
 *
 * \param[inout] psi5        Pointer to the Ifx_PSI5 structure.
 * 
 * \retval None
 */
IFX_EXTERN void IfxPsi5_enableModule(Ifx_PSI5 *psi5);

/**
 * \brief Enables a specific PSI5 channel for operation.
 *
 * \param[inout] psi5        Pointer to the PSI5 SFR base register.
 * \param[in]    channelId   The ID of the channel to be enabled. Range: \ref IfxPsi5_ChannelId
 *
 * \retval None
 */
IFX_EXTERN void IfxPsi5_enableChannel(Ifx_PSI5 *psi5, IfxPsi5_ChannelId channelId);

/******************************************************************************/
/*---------------------Inline Function Implementations------------------------*/
/******************************************************************************/

IFX_INLINE uint32 IfxPsi5_getStatusCrci(Ifx_PSI5 *psi5, IfxPsi5_ChannelId channel)
{
    return psi5->CRCIOV[channel].U;
}


IFX_INLINE uint32 IfxPsi5_getStatusMei(Ifx_PSI5 *psi5, IfxPsi5_ChannelId channel)
{
    return psi5->MEIOV[channel].U;
}


IFX_INLINE uint32 IfxPsi5_getStatusNbi(Ifx_PSI5 *psi5, IfxPsi5_ChannelId channel)
{
    return psi5->NBIOV[channel].U;
}


IFX_INLINE uint32 IfxPsi5_getStatusNfi(Ifx_PSI5 *psi5, IfxPsi5_ChannelId channel)
{
    return psi5->NFIOV[channel].U;
}


IFX_INLINE uint32 IfxPsi5_getStatusRdi(Ifx_PSI5 *psi5, IfxPsi5_ChannelId channel)
{
    return psi5->RDIOV[channel].U;
}


IFX_INLINE uint32 IfxPsi5_getStatusRmi(Ifx_PSI5 *psi5, IfxPsi5_ChannelId channel)
{
    return psi5->RMIOV[channel].U;
}


IFX_INLINE uint32 IfxPsi5_getStatusRsi(Ifx_PSI5 *psi5, IfxPsi5_ChannelId channel)
{
    return psi5->RSIOV[channel].U;
}


IFX_INLINE uint32 IfxPsi5_getStatusTei(Ifx_PSI5 *psi5, IfxPsi5_ChannelId channel)
{
    return psi5->TEIOV[channel].U;
}


IFX_INLINE void IfxPsi5_initRxPin(const IfxPsi5_Rx_In *rx, IfxPort_InputMode inputMode, IfxPort_PadDriver padDriver)
{
    if (rx->pin.port != NULL_PTR)
    {
        IfxPort_setPinModeInput(rx->pin.port, rx->pin.pinIndex, inputMode);
        IfxPort_setPinPadDriver(rx->pin.port, rx->pin.pinIndex, padDriver);
        Ifx_PSI5    *psi5   = rx->module;
        Ifx_PSI5_CH *psi5Ch = &psi5->CH[rx->channelId];
        IfxPsi5_setRxInput(psi5Ch, (IfxPsi5_AlternateInput)rx->select);
    }
}


IFX_INLINE void IfxPsi5_initTxPin(const IfxPsi5_Tx_Out *tx, IfxPort_OutputMode outputMode, IfxPort_PadDriver padDriver)
{
    if (tx->pin.port != NULL_PTR)
    {
        IfxPort_setPinModeOutput(tx->pin.port, tx->pin.pinIndex, outputMode, tx->select);
        IfxPort_setPinPadDriver(tx->pin.port, tx->pin.pinIndex, padDriver);
    }
}


IFX_INLINE void IfxPsi5_setInterruptNodePointer(Ifx_PSI5 *psi5, IfxPsi5_ChannelId channel, IfxPsi5_InterruptNodePointer nodePointer, IfxPsi5_TriggerOutput triggerOutputLine)
{
    uint16 passwd = IfxScuWdt_getCpuWatchdogPassword();
    IfxScuWdt_clearCpuEndinit(passwd);
    psi5->INP[channel].U = psi5->INP[channel].U | (triggerOutputLine << (nodePointer * 4));
    IfxScuWdt_setCpuEndinit(passwd);
}


IFX_INLINE void IfxPsi5_setRxInput(Ifx_PSI5_CH *psi5Ch, IfxPsi5_AlternateInput alternateInput)
{
    uint16 passwd = IfxScuWdt_getCpuWatchdogPassword();
    IfxScuWdt_clearCpuEndinit(passwd);
    psi5Ch->IOCR.B.ALTI = alternateInput;
    IfxScuWdt_setCpuEndinit(passwd);
}


IFX_INLINE void IfxPsi5_setSleepMode(Ifx_PSI5 *psi5, IfxPsi5_SleepMode mode)
{
    uint16 passwd = IfxScuWdt_getCpuWatchdogPassword();
    IfxScuWdt_clearCpuEndinit(passwd);
    psi5->CLC.B.EDIS = mode;
    IfxScuWdt_setCpuEndinit(passwd);
}


IFX_INLINE boolean IfxPsi5_isModuleSuspended(Ifx_PSI5 *psi5)
{
    Ifx_PSI5_OCS ocs;

    // read the status
    ocs.U = psi5->OCS.U;

    // return the status
    return ocs.B.SUSSTA;
}


IFX_INLINE void IfxPsi5_setSuspendMode(Ifx_PSI5 *psi5, IfxPsi5_SuspendMode mode)
{
    Ifx_PSI5_OCS ocs;

    // remove protection and configure the suspend mode.
    ocs.B.SUS_P = 1;
    ocs.B.SUS   = mode;
    psi5->OCS.U = ocs.U;
}


IFX_INLINE uint32 IfxPsi5_getReceiveDataRegisterLow(Ifx_PSI5 *psi5, IfxPsi5_ChannelId channel)
{
    return psi5->CH[channel].RDRL.U;
}


IFX_INLINE void IfxPsi5_clearAllInterrupt(Ifx_PSI5 *psi5, IfxPsi5_ChannelId channel, IfxPsi5_InterruptStatusRegister intStatusReg, uint32 value)
{
    if (intStatusReg == IfxPsi5_InterruptStatusRegister_a)
    {
        psi5->INTCLRA[channel].U = value;
    }
    else
    {
        psi5->INTCLRB[channel].U = value;
    }
}


IFX_INLINE uint32 IfxPsi5_getInterruptStatus(Ifx_PSI5 *psi5, IfxPsi5_ChannelId channel, IfxPsi5_InterruptStatusRegister intStatusReg)
{
    if (intStatusReg == IfxPsi5_InterruptStatusRegister_a)
    {
        return psi5->INTSTATA[channel].U;
    }
    else
    {
        return psi5->INTSTATB[channel].U;
    }
}


IFX_INLINE uint32 IfxPsi5_readReceiveFifoData(Ifx_PSI5 *psi5, IfxPsi5_ChannelId channel)
{
    return psi5->RDF[channel].U;
}


IFX_INLINE uint16 IfxPsi5_getWriteFifoPointer(Ifx_PSI5 *psi5, IfxPsi5_ChannelId channel)
{
    return psi5->RFC[channel].B.WRP;
}


IFX_INLINE uint16 IfxPsi5_getReadFifoPointer(Ifx_PSI5 *psi5, IfxPsi5_ChannelId channel)
{
    return psi5->RFC[channel].B.REP;
}


IFX_INLINE void IfxPsi5_clearInterrupt(Ifx_PSI5 *psi5, IfxPsi5_ChannelId channel, IfxPsi5_InterruptSource interruptSource)
{
    if (interruptSource < IfxPsi5_InterruptSource_wsi0)
    {
        psi5->INTCLRA[channel].U = (1 << interruptSource);
    }
    else
    {
        psi5->INTCLRB[channel].U = (1 << interruptSource);
    }
}


IFX_INLINE volatile Ifx_SRC_SRCR *IfxPsi5_getSrcPointer(Ifx_PSI5 *psi5, IfxPsi5_InterruptServiceRequest intRequest)
{
    IFX_UNUSED_PARAMETER(psi5);
    return &MODULE_SRC.PSI5.PSI5[0].SR[intRequest];
}


IFX_INLINE void IfxPsi5_enableAllChannels(Ifx_PSI5 *psi5)
{
    uint16 passwd = IfxScuWdt_getCpuWatchdogPassword();
    IfxScuWdt_clearCpuEndinit(passwd);
    psi5->GCR.U = psi5->GCR.U | 0x000F001FU;
    IfxScuWdt_setCpuEndinit(passwd);
}


IFX_INLINE void IfxPsi5_setReceiveFifoWarningLevel(Ifx_PSI5 *psi5, IfxPsi5_ChannelId channel, uint32 value)
{
    psi5->RFC[channel].B.FWL = value;
}


IFX_INLINE void IfxPsi5_setReceiverControl(Ifx_PSI5 *psi5, IfxPsi5_ChannelId channel, IfxPsi5_ReceiverControlRegister rcr, uint32 value)
{
    uint16 passwd = IfxScuWdt_getCpuWatchdogPassword();
    IfxScuWdt_clearCpuEndinit(passwd);

    switch (rcr)
    {
    case IfxPsi5_ReceiverControlRegister_a:
        psi5->CH[channel].RCRA.U = value;
        break;
    case IfxPsi5_ReceiverControlRegister_b:
        psi5->CH[channel].RCRB.U = value;
        break;
    case IfxPsi5_ReceiverControlRegister_c:
        psi5->CH[channel].RCRC.U = value;
        break;
    default:
        break;
    }

    IfxScuWdt_setCpuEndinit(passwd);
}


IFX_INLINE void IfxPsi5_setFractionalDivider(Ifx_PSI5 *psi5, IfxPsi5_FractionalDividerRegister fcd, uint32 value)
{
    uint16 passwd = IfxScuWdt_getCpuWatchdogPassword();
    IfxScuWdt_clearCpuEndinit(passwd);

    switch (fcd)
    {
    case IfxPsi5_FractionalDividerRegister_normal:
        psi5->FDR.I = value;
        break;
    case IfxPsi5_FractionalDividerRegister_lowbitrate:
        psi5->FDRL.I = value;
        break;
    case IfxPsi5_FractionalDividerRegister_highbitrate:
        psi5->FDRH.I = value;
        break;
    case IfxPsi5_FractionalDividerRegister_timestamp:
        psi5->FDRT.I = value;
        break;
    default:
        break;
    }

    IfxScuWdt_setCpuEndinit(passwd);
}


#endif /* IFXPSI5_H */
