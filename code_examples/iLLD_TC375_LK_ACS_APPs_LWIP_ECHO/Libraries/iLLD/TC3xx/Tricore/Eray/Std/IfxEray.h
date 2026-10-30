/**
 * \file IfxEray.h
 * \brief ERAY  basic functionality
 * \ingroup IfxLld_Eray
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
 * \defgroup IfxLld_Eray_Std_Enumerations Enumerations
 * \ingroup IfxLld_Eray_Std
 * \defgroup IfxLld_Eray_Std_Interrupt Interrupt Functions
 * \ingroup IfxLld_Eray_Std
 * \defgroup IfxLld_Eray_Std_IO IO Pin Configuration Functions
 * \ingroup IfxLld_Eray_Std
 * \defgroup IfxLld_Eray_Std_Module Module Functions
 * \ingroup IfxLld_Eray_Std
 * \defgroup IfxLld_Eray_Std_Status Status Functions
 * \ingroup IfxLld_Eray_Std
 * \defgroup IfxLld_Eray_Std_Configuration Configuration Functions
 * \ingroup IfxLld_Eray_Std
 * \defgroup IfxLld_Eray_Std_Structures Data Structures
 * \ingroup IfxLld_Eray_Std
 * \defgroup IfxLld_Eray_Std_Operative Operative Functions
 * \ingroup IfxLld_Eray_Std
 */

#ifndef IFXERAY_H
#define IFXERAY_H 1

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include "_Impl/IfxEray_cfg.h"
#include "_PinMap/IfxEray_PinMap.h"
#include "Src/Std/IfxSrc.h"
#include "IfxEray_reg.h"

/******************************************************************************/
/*--------------------------------Enumerations--------------------------------*/
/******************************************************************************/

/** \addtogroup IfxLld_Eray_Std_Enumerations
 * \{ */
/** \brief Baudrate on the flexray bus, defined in MODULE_ERAY0.PRTC1.B.BRP.
 */
typedef enum
{
    IfxEray_Baudrate_10  = 0, /**< \brief baudrate is 10MBits/Sec */
    IfxEray_Baudrate_5   = 1, /**< \brief baudrate is 5MBits/Sec */
    IfxEray_Baudrate_2_5 = 2  /**< \brief baudrate is 2.5MBits/Sec */
} IfxEray_Baudrate;

/** \brief wheather transmit buffer or receive buffer, defined in MODULE_ERAY0.WRHS1.B.CFG.
 */
typedef enum
{
    IfxEray_BufferDirection_receive  = 0, /**< \brief buffer is configured as receive buffer */
    IfxEray_BufferDirection_transmit = 1  /**< \brief buffer is configured as transmit buffer */
} IfxEray_BufferDirection;

/** \brief Selection of channel Id, defined in MODULE_ERAY0.SUCC1.B.WUCS
 */
typedef enum
{
    IfxEray_Channel_a = 0,  /**< \brief channel A */
    IfxEray_Channel_b = 1   /**< \brief channel B */
} IfxEray_Channel;

/** \brief Selection of error flag to clear defined in MODULE_ERAY.EIR.U
 */
typedef enum
{
    IfxEray_ClearErrorFlag_pemc = 1,         /**< \brief POC error mode change bit. */
    IfxEray_ClearErrorFlag_cna  = 2,         /**< \brief command not accepted event bit. */
    IfxEray_ClearErrorFlag_sfbm = 4,         /**< \brief sync frame below minimum bit. */
    IfxEray_ClearErrorFlag_sfo  = 8,         /**< \brief sync frame overflow event bit */
    IfxEray_ClearErrorFlag_ccf  = 16,        /**< \brief clock correction failure event. */
    IfxEray_ClearErrorFlag_ccl  = 32,        /**< \brief CHI command locked event. */
    IfxEray_ClearErrorFlag_eerr = 64,        /**< \brief ECC error event bit. */
    IfxEray_ClearErrorFlag_rfo  = 128,       /**< \brief RxFIFO overrun event bit. */
    IfxEray_ClearErrorFlag_efa  = 256,       /**< \brief empty FIFO access event bit. */
    IfxEray_ClearErrorFlag_iiba = 512,       /**< \brief illegal input buffer access event. */
    IfxEray_ClearErrorFlag_ioba = 1024,      /**< \brief illegal output buffer access event. */
    IfxEray_ClearErrorFlag_mhf  = 2048,      /**< \brief message handler constraint flag. */
    IfxEray_ClearErrorFlag_eda  = 65536,     /**< \brief error event on channel A. */
    IfxEray_ClearErrorFlag_ltva = 131072,    /**< \brief latest transmit violation flag on channel A . */
    IfxEray_ClearErrorFlag_taba = 262144,    /**< \brief transmission across channel A boundary flag. */
    IfxEray_ClearErrorFlag_edb  = 16777216,  /**< \brief error event on channel B. */
    IfxEray_ClearErrorFlag_ltvb = 33554432,  /**< \brief latest transmit violation flag on channel B . */
    IfxEray_ClearErrorFlag_tabb = 67108864   /**< \brief transmission across channel B boundary flag. */
} IfxEray_ClearErrorFlag;

/** \brief Selection of status flag to clear defined in MODULE_ERAY.SIR.U
 */
typedef enum
{
    IfxEray_ClearStatusFlag_wst  = 1,         /**< \brief wakeup status bit. */
    IfxEray_ClearStatusFlag_cas  = 2,         /**< \brief collision avoidance bit. */
    IfxEray_ClearStatusFlag_cycs = 4,         /**< \brief cycle start service bit. */
    IfxEray_ClearStatusFlag_txi  = 8,         /**< \brief transmit service request bit. */
    IfxEray_ClearStatusFlag_rxi  = 16,        /**< \brief receive service request bit. */
    IfxEray_ClearStatusFlag_rfne = 32,        /**< \brief receive fifo not empty bit. */
    IfxEray_ClearStatusFlag_rfcl = 64,        /**< \brief RxFIFO critical level reached bit. */
    IfxEray_ClearStatusFlag_nmvc = 128,       /**< \brief network management vector bit. */
    IfxEray_ClearStatusFlag_ti0  = 256,       /**< \brief timer0 service request bit. */
    IfxEray_ClearStatusFlag_ti1  = 512,       /**< \brief timer1 service request bit. */
    IfxEray_ClearStatusFlag_tibc = 1024,      /**< \brief transfer input buffer completion request bit. */
    IfxEray_ClearStatusFlag_tobc = 2048,      /**< \brief transfer output buffer completion request bit. */
    IfxEray_ClearStatusFlag_swe  = 4096,      /**< \brief stop watch event bit. */
    IfxEray_ClearStatusFlag_sucs = 8192,      /**< \brief startup success event bit. */
    IfxEray_ClearStatusFlag_mbsi = 16384,     /**< \brief message buffer service status bit. */
    IfxEray_ClearStatusFlag_sds  = 32768,     /**< \brief dynamic segment start bit. */
    IfxEray_ClearStatusFlag_wupa = 65536,     /**< \brief wakeup pattern channel A bit. */
    IfxEray_ClearStatusFlag_mtsa = 131072,    /**< \brief MTS receive channel A bit. */
    IfxEray_ClearStatusFlag_wupb = 16777216,  /**< \brief wakeup pattern channel B bit. */
    IfxEray_ClearStatusFlag_mtsb = 33554432   /**< \brief MTS receive channel B bit. */
} IfxEray_ClearStatusFlag;

/** \brief Clock divider in RUN mode, defined in MODULE_ERAY0.B.RMC.
 */
typedef enum
{
    IfxEray_ClockDivider_none = 0,  /**< \brief no clock signal */
    IfxEray_ClockDivider_1    = 1,  /**< \brief run mode clock divider 1  */
    IfxEray_ClockDivider_2,         /**< \brief run mode clock divider 2  */
    IfxEray_ClockDivider_3,         /**< \brief run mode clock divider 3  */
    IfxEray_ClockDivider_4,         /**< \brief run mode clock divider 4  */
    IfxEray_ClockDivider_5,         /**< \brief run mode clock divider 5  */
    IfxEray_ClockDivider_6,         /**< \brief run mode clock divider 6  */
    IfxEray_ClockDivider_7          /**< \brief run mode clock divider 7  */
} IfxEray_ClockDivider;

/** \brief External offset correction control defined in MODULE_ERAY0.GTU11.B.EOCC.
 */
typedef enum
{
    IfxEray_ExternalOffset_noCorrection         = 1,  /**< \brief No external correction control. */
    IfxEray_ExternalOffset_correctionSubtracted = 2,  /**< \brief External offset correction subtracted from calculated correction. */
    IfxEray_ExternalOffset_correctionAdded      = 3   /**< \brief External offset correction added to calculated correction. */
} IfxEray_ExternalOffset;

/** \brief External clock offset correction value defined in MODULE_ERAY0.GTU11.B.EOC.
 */
typedef enum
{
    IfxEray_ExternalOffsetCorrection_0 = 0,      /**< \brief external clock offset correction value 0  */
    IfxEray_ExternalOffsetCorrection_1,          /**< \brief external clock offset correction value 1  */
    IfxEray_ExternalOffsetCorrection_2,          /**< \brief external clock offset correction value 2  */
    IfxEray_ExternalOffsetCorrection_3,          /**< \brief external clock offset correction value 3  */
    IfxEray_ExternalOffsetCorrection_4,          /**< \brief external clock offset correction value 4  */
    IfxEray_ExternalOffsetCorrection_5,          /**< \brief external clock offset correction value 5  */
    IfxEray_ExternalOffsetCorrection_6,          /**< \brief external clock offset correction value 6  */
    IfxEray_ExternalOffsetCorrection_7           /**< \brief external clock offset correction value 7  */
} IfxEray_ExternalOffsetCorrection;

/** \brief External rate correction control MODULE_ERAY0.GTU11.B.ERCC.
 */
typedef enum
{
    IfxEray_ExternalRate_noCorrection         = 1,  /**< \brief No external correction control. */
    IfxEray_ExternalRate_correctionSubtracted = 2,  /**< \brief External rate correction subtracted from calculated correction. */
    IfxEray_ExternalRate_correctionAdded      = 3   /**< \brief External rate correction added to calculated correction. */
} IfxEray_ExternalRate;

/** \brief External clock rate correction value defined in MODULE_ERAY0.GTU11.B.ERC.
 */
typedef enum
{
    IfxEray_ExternalRateCorrection_0 = 0,      /**< \brief external clock rate correction value 0  */
    IfxEray_ExternalRateCorrection_1,          /**< \brief external clock rate correction value 1  */
    IfxEray_ExternalRateCorrection_2,          /**< \brief external clock rate correction value 2  */
    IfxEray_ExternalRateCorrection_3,          /**< \brief external clock rate correction value 3  */
    IfxEray_ExternalRateCorrection_4,          /**< \brief external clock rate correction value 4  */
    IfxEray_ExternalRateCorrection_5,          /**< \brief external clock rate correction value 5  */
    IfxEray_ExternalRateCorrection_6,          /**< \brief external clock rate correction value 6  */
    IfxEray_ExternalRateCorrection_7           /**< \brief external clock rate correction value 7  */
} IfxEray_ExternalRateCorrection;

/** \brief Duration of dynamic slot idle phase, defined in MODULE_ERAY0.B.DSI.
 */
typedef enum
{
    IfxEray_IdleDynamicSlots_0 = 0,      /**< \brief duration of dynamic slot idle phase is 0  */
    IfxEray_IdleDynamicSlots_1,          /**< \brief duration of dynamic slot idle phase is 1  */
    IfxEray_IdleDynamicSlots_2           /**< \brief duration of dynamic slot idle phase is 2  */
} IfxEray_IdleDynamicSlots;

/** \brief Interrupt lines
 */
typedef enum
{
    IfxEray_InterruptLine_0 = 0,  /**< \brief line 0 */
    IfxEray_InterruptLine_1 = 1   /**< \brief line 1 */
} IfxEray_InterruptLine;

/** \brief Wakeup or Startup listen timeout in presence of noise, defined in MODULE_ERAY0.SUCC2.B.LTN.
 */
typedef enum
{
    IfxEray_ListenTimeOutNoise_2 = 1,      /**< \brief listen Time-out noise 2  */
    IfxEray_ListenTimeOutNoise_3,          /**< \brief listen Time-out noise 3  */
    IfxEray_ListenTimeOutNoise_4,          /**< \brief listen Time-out noise 4  */
    IfxEray_ListenTimeOutNoise_5,          /**< \brief listen Time-out noise 5  */
    IfxEray_ListenTimeOutNoise_6,          /**< \brief listen Time-out noise 6  */
    IfxEray_ListenTimeOutNoise_7,          /**< \brief listen Time-out noise 7  */
    IfxEray_ListenTimeOutNoise_8,          /**< \brief listen Time-out noise 8  */
    IfxEray_ListenTimeOutNoise_9,          /**< \brief listen Time-out noise 9  */
    IfxEray_ListenTimeOutNoise_10,         /**< \brief listen Time-out noise 10  */
    IfxEray_ListenTimeOutNoise_11,         /**< \brief listen Time-out noise 11  */
    IfxEray_ListenTimeOutNoise_12,         /**< \brief listen Time-out noise 12  */
    IfxEray_ListenTimeOutNoise_13,         /**< \brief listen Time-out noise 13  */
    IfxEray_ListenTimeOutNoise_14,         /**< \brief listen Time-out noise 14  */
    IfxEray_ListenTimeOutNoise_15,         /**< \brief listen Time-out noise 15  */
    IfxEray_ListenTimeOutNoise_16          /**< \brief listen Time-out noise 16  */
} IfxEray_ListenTimeOutNoise;

/** \brief Maximum number of sync frames in a cluster defined in MODULE_ERAY0.GTU02.B.SNM.
 */
typedef enum
{
    IfxEray_MaxSynchFrames_2 = 2,      /**< \brief Maximum number of sync frames in a cluster are 2  */
    IfxEray_MaxSynchFrames_3,          /**< \brief Maximum number of sync frames in a cluster are 3  */
    IfxEray_MaxSynchFrames_4,          /**< \brief Maximum number of sync frames in a cluster are 4  */
    IfxEray_MaxSynchFrames_5,          /**< \brief Maximum number of sync frames in a cluster are 5  */
    IfxEray_MaxSynchFrames_6,          /**< \brief Maximum number of sync frames in a cluster are 6  */
    IfxEray_MaxSynchFrames_7,          /**< \brief Maximum number of sync frames in a cluster are 7  */
    IfxEray_MaxSynchFrames_8,          /**< \brief Maximum number of sync frames in a cluster are 8  */
    IfxEray_MaxSynchFrames_9,          /**< \brief Maximum number of sync frames in a cluster are 9  */
    IfxEray_MaxSynchFrames_10,         /**< \brief Maximum number of sync frames in a cluster are 10  */
    IfxEray_MaxSynchFrames_11,         /**< \brief Maximum number of sync frames in a cluster are 11  */
    IfxEray_MaxSynchFrames_12,         /**< \brief Maximum number of sync frames in a cluster are 12  */
    IfxEray_MaxSynchFrames_13,         /**< \brief Maximum number of sync frames in a cluster are 13  */
    IfxEray_MaxSynchFrames_14,         /**< \brief Maximum number of sync frames in a cluster are 14  */
    IfxEray_MaxSynchFrames_15          /**< \brief Maximum number of sync frames in a cluster are 15  */
} IfxEray_MaxSynchFrames;

/** \brief Commmand to control the Communication, defined in MODULE_ERAY0.SUCC1.B.CMD.
 */
typedef enum
{
    IfxEray_PocCommand_notAccepted  = 0,   /**< \brief command not accepted. */
    IfxEray_PocCommand_config       = 1,   /**< \brief command to controller to enter CONFIG */
    IfxEray_PocCommand_ready        = 2,   /**< \brief command to controller to enter READY. */
    IfxEray_PocCommand_wakeup       = 3,   /**< \brief command to controller to enter WAKEUP */
    IfxEray_PocCommand_run          = 4,   /**< \brief command to controller to enter RUN */
    IfxEray_PocCommand_allSlots     = 5,   /**< \brief command to controller to enter ALL_SLOTS */
    IfxEray_PocCommand_halt         = 6,   /**< \brief command to controller to enter HALT */
    IfxEray_PocCommand_freeze       = 7,   /**< \brief command to controller to enter FREEZE */
    IfxEray_PocCommand_sendMts      = 8,   /**< \brief command to controller to enter SEND_MTS */
    IfxEray_PocCommand_coldStart    = 9,   /**< \brief command to controller to enter COLD_START */
    IfxEray_PocCommand_reset        = 10,  /**< \brief command to controller to enter RESET */
    IfxEray_PocCommand_monitor      = 11,  /**< \brief command to controller to enter MONITOR */
    IfxEray_PocCommand_clearRam     = 12,  /**< \brief command to controller to enter CLEAR_RAM */
    IfxEray_PocCommand_asynchronous = 14,  /**< \brief command to controller to enter asynchronous transmit mode */
    IfxEray_PocCommand_loopBack     = 15   /**< \brief command to controller to enter Loop back mode */
} IfxEray_PocCommand;

/** \brief State of Communication Controller Protocol operation control, defined in MODULE_ERAY0.CCSV.B.POCS.
 */
typedef enum
{
    IfxEray_PocState_defaultConfig               = 0,   /**< \brief controller entered default config state */
    IfxEray_PocState_ready                       = 1,   /**< \brief controller entered ready state */
    IfxEray_PocState_normalActive                = 2,   /**< \brief controller entered normal-active state */
    IfxEray_PocState_normalPassive               = 3,   /**< \brief controller entered normal-passive state */
    IfxEray_PocState_halt                        = 4,   /**< \brief controller entered halt state */
    IfxEray_PocState_monitor                     = 5,   /**< \brief controller entered monitor state */
    IfxEray_PocState_loopBack                    = 13,  /**< \brief controller entered loop back mode. */
    IfxEray_PocState_asynchronous                = 14,  /**< \brief controller entered asynchronous transfer mode. */
    IfxEray_PocState_config                      = 15,  /**< \brief controller entered config state */
    IfxEray_PocState_wakeupStandby               = 16,  /**< \brief controller entered wakeup standby state */
    IfxEray_PocState_wakeupListen                = 17,  /**< \brief controller entered wakeup-listen state */
    IfxEray_PocState_wakeupSend                  = 18,  /**< \brief controller entered wakeup-send state */
    IfxEray_PocState_wakeupDetect                = 19,  /**< \brief controller entered wakeup-detection state */
    IfxEray_PocState_startup                     = 32,  /**< \brief controller entered startup state */
    IfxEray_PocState_coldStartListen             = 33,  /**< \brief controller entered clod-start listen state */
    IfxEray_PocState_collisionResolution         = 34,  /**< \brief controller entered collission-resolution state. */
    IfxEray_PocState_consistencyCheck            = 35,  /**< \brief controller entered consistency-check. */
    IfxEray_PocState_gap                         = 36,  /**< \brief controller entered gap state. */
    IfxEray_PocState_join                        = 37,  /**< \brief controller entered join state. */
    IfxEray_PocState_integrationCheck            = 38,  /**< \brief controller entered integration-check. */
    IfxEray_PocState_integrationListen           = 39,  /**< \brief controller entered integration-listen state. */
    IfxEray_PocState_integrationConsistencyCheck = 40,  /**< \brief controller entered integration consistency check state */
    IfxEray_PocState_initializeSchedule          = 41,  /**< \brief controller entered initialise schedule state */
    IfxEray_PocState_startupAborted              = 42,  /**< \brief controller entered startup-abort state */
    IfxEray_PocState_startupSucceed              = 43   /**< \brief controller entered startup succeed state. */
} IfxEray_PocState;

/** \brief Receiving channel, defined in MODULE_ERAY0.FRF.B.CH.
 */
typedef enum
{
    IfxEray_ReceiveChannel_both = 0,  /**< \brief both channels for reception */
    IfxEray_ReceiveChannel_b    = 1,  /**< \brief channel A for reception */
    IfxEray_ReceiveChannel_a    = 2,  /**< \brief channel B for reception */
    IfxEray_ReceiveChannel_none = 3   /**< \brief none channels for reception */
} IfxEray_ReceiveChannel;

/** \brief Enable/disable the sensitivity of the module to sleep signal\n
 * Definition in Ifx_ERAY.CLC.B.EDIS
 */
typedef enum
{
    IfxEray_SleepMode_enable  = 0, /**< \brief enables sleep mode */
    IfxEray_SleepMode_disable = 1  /**< \brief disables sleep mode */
} IfxEray_SleepMode;

/** \brief Sample count value for strobing, defined in MODULE_ERAY0.PRTC1.B.SPP.
 */
typedef enum
{
    IfxEray_StrobePosition_5 = 0,  /**< \brief Sample count 5 for strobing */
    IfxEray_StrobePosition_4 = 1,  /**< \brief Sample count 4 for strobing */
    IfxEray_StrobePosition_6 = 2   /**< \brief Sample count 6 for strobing */
} IfxEray_StrobePosition;

/** \brief OCDS Suspend Control, defined in MODULE_ERAY0.OCS.B.SUS
 */
typedef enum
{
    IfxEray_SuspendMode_none = 0,  /**< \brief No suspend */
    IfxEray_SuspendMode_hard = 1,  /**< \brief Hard Suspend */
    IfxEray_SuspendMode_soft = 2   /**< \brief Soft Suspend */
} IfxEray_SuspendMode;

/** \brief Transmission mode of Header, defined in MODULE_ERAY0.WRHS1.B.TXM.
 */
typedef enum
{
    IfxEray_TransmissionMode_continuous = 0,  /**< \brief continuos transmission mode */
    IfxEray_TransmissionMode_singleShot = 1   /**< \brief single transmission mode */
} IfxEray_TransmissionMode;

/** \brief Initial transmission mode, defined in MODULE_ERAY0.SUCC1.B.TSM.
 */
typedef enum
{
    IfxEray_TransmissionSlotMode_all    = 0, /**< \brief transmission in all slots. */
    IfxEray_TransmissionSlotMode_single = 1  /**< \brief transmission in key slot. */
} IfxEray_TransmissionSlotMode;

/** \brief Wakeup pattern carry channel, defined in MODULE_ERAY0.SUCC1.B.WUCS.
 */
typedef enum
{
    IfxEray_WakeupChannel_a = 0,  /**< \brief send wakeup channel pattern on channel A */
    IfxEray_WakeupChannel_b = 1   /**< \brief send wakeup channel pattern on channel B */
} IfxEray_WakeupChannel;

/** \} */

/******************************************************************************/
/*-----------------------------Data Structures--------------------------------*/
/******************************************************************************/

/** \addtogroup IfxLld_Eray_Std_Structures
 * \{ */
/** \brief Header section in  a frame.
 */
typedef struct
{
    uint16                   frameId;                         /**< \brief slot ID of the selected Message Buffer. Range: 0x0 to 0x7FF. */
    uint8                    cycleCode;                       /**< \brief the cycle set used for cycle counter filtering. Range: 0x0 to 0x7F. */
    boolean                  channelAFiltered;                /**< \brief channel A serves as a control for transmit and filter for receive buffers. */
    boolean                  channelBFiltered;                /**< \brief channel B serves as a control for transmit and filter for receive buffers. */
    IfxEray_BufferDirection  bufferDirection;                 /**< \brief selects buffer as a transmit buffer or as a receive buffer. */
    boolean                  transmitPayloadIndicatior;       /**< \brief whether payload indicator is set or not. */
    IfxEray_TransmissionMode transmissionMode;                /**< \brief transmission mode of Header. */
    boolean                  bufferServiceEnabled;            /**< \brief whether buffer service request is enabled or not. */
    uint8                    payloadLength;                   /**< \brief length of data section. Range: 0x0 to 0x7F. */
    uint16                   dataPointer;                     /**< \brief pointer to the data section of message buffer in RAM. Range: 0x0 to 0x7FF.*/
    boolean                  startupFrameIndicator;           /**< \brief whether startup frame is indicated or not. */
    boolean                  syncFrameIndicator;              /**< \brief whether sync frame is indicated or not. */
} IfxEray_Header;

/** \brief Received header in a frame.
 */
typedef struct
{
    uint16 frameId : 11;                     /**< \brief received frame id. Range: 0x0 to 0x7FF. */
    uint8  payloadLength : 7;                /**< \brief received payload length. Range: 0x0 to 0x7F. */
    uint16 headerCrc : 11;                   /**< \brief received header crc. Range: 0x0 to 0x7FF. */
    uint8  nullFrameIndicator : 1;           /**< \brief null frame indicator. Range: TRUE atleast one data frame received, FALSE no data frame received. */
    uint8  syncFrame : 1;                    /**< \brief sync frame indicator. Range: TRUE receive frame is a synch frame. FALSE received frame is not a synch frame. */
    uint8  startupFrame : 1;                 /**< \brief startup frame indicator. Range:TRUE receive frame is a startup frame, FALSE received frame is not a startup frame. */
    uint8  cycleNumber : 7;                  /**< \brief cycle number in which frame is received.Range: 0x0 to 3F. */
    uint8  payloadPreambleIndicator : 1;     /**< \brief payload preamble indicator. Range: TRUE received payload segment has network management and message id or not, FALSE it hasn't. */
} IfxEray_ReceivedHeader;

/** \brief Transmit control structure.
 */
typedef struct
{
    boolean headerTransfered;        /**< \brief whether header is transfered from input buffers to Message RAM or not. Range: TRUE header transfer is requested, FALSE header transfer is not requested. */
    boolean dataTransfered;          /**< \brief whether data is transfered from input buffers to Message RAM or not. Range: TRUE data transfer is requested, FALSE data transfer is not requested. */
    boolean transferRequested;       /**< \brief transmit buffer released for transmission or not. Range: TRUE if set transmission request flag, FALSE if reset transmission request flag. */
    uint8   bufferIndex;             /**< \brief buffer index in the Message RAM. Range: 0x0 to 0x7F. */
} IfxEray_SlotConfig;

/** \} */

/** \addtogroup IfxLld_Eray_Std_Interrupt
 * \{ */

/******************************************************************************/
/*-------------------------Inline Function Prototypes-------------------------*/
/******************************************************************************/

/**
 * \brief Clears the specified error flag in the ERAY module.
 *
 * \param[inout] eray      Pointer to the ERAY module registers.
 * \param[in]    errorFlag The error flag to be cleared. Range: \ref IfxEray_ClearErrorFlag.
 *
 * \retval None
 *
 */
IFX_INLINE void IfxEray_clearErrorFlag(Ifx_ERAY *eray, IfxEray_ClearErrorFlag errorFlag);

/**
 * \brief Clears a specified status flag in the ERAY module.
 *
 * \param[inout] eray       Pointer to the ERAY module registers.
 * \param[in]    statusFlag The status flag to be cleared. Range: \ref IfxEray_ClearStatusFlag.
 *
 * \retval None
 *
 */
IFX_INLINE void IfxEray_clearStatusFlag(Ifx_ERAY *eray, IfxEray_ClearStatusFlag statusFlag);

/**
 * \brief Retrieves the error interrupt flags for the ERAY module.
 *
 * \param[in] eray Pointer to the ERAY module registers.
 *
 * \retval Ifx_ERAY_EIR The error interrupt flags.
 *
 */
IFX_INLINE Ifx_ERAY_EIR IfxEray_getErrorInterrupts(Ifx_ERAY *eray);

/**
 * \brief Gets the IBUSY service request control register pointer.
 *
 * \param[in] eray Pointer to the ERAY module registers.
 *
 * \retval Ifx_SRC_SRCR* Pointer to the IBUSY service request control register.
 *
 */
IFX_INLINE volatile Ifx_SRC_SRCR *IfxEray_getInputBufferBusySrcPtr(Ifx_ERAY *eray);

/**
 * \brief Retrieves a pointer to the INT0 service request source register.
 *
 * \param[in] eray Pointer to the ERAY module registers.
 *
 * \retval Ifx_SRC_SRCR* Pointer to the INT0 service request source register.
 *
 */
IFX_INLINE volatile Ifx_SRC_SRCR *IfxEray_getInterruptLine0SrcPtr(Ifx_ERAY *eray);

/**
 * \brief Retrieves a pointer to the INT1 service request source register.
 *
 * \param[in] eray Pointer to the ERAY module registers.
 *
 * \retval Ifx_SRC_SRCR* Pointer to the INT1 service request source register.
 *
 */
IFX_INLINE volatile Ifx_SRC_SRCR *IfxEray_getInterruptLine1SrcPtr(Ifx_ERAY *eray);

/**
 * \brief Retrieves the interrupt status of a specified message buffer in the ERAY module.
 *
 * \param[in] eray          Pointer to the ERAY module registers.
 * \param[in] messageBuffer The message buffer to check the interrupt status for. Range: 0x0 to 0x7F.
 *
 * \retval TRUE An interrupt is pending for the specified message buffer.
 *         FALSE No interrupt is pending for the specified message buffer.
 *
 */
IFX_INLINE boolean IfxEray_getMessageBufferInterruptStatus(Ifx_ERAY *eray, uint8 messageBuffer);

/**
 * \brief Gets the MBSC0 service request from the ERAY module.
 *
 * \param[in] eray Pointer to the ERAY module registers.
 *
 * \retval Ifx_SRC_SRCR* Pointer to the MBSC0 service request register (SRCR).
 *
 */
IFX_INLINE volatile Ifx_SRC_SRCR *IfxEray_getMessageBufferStatus0SrcPtr(Ifx_ERAY *eray);

/**
 * \brief Gets the MBSC1 service request status register pointer.
 *
 * \param[in] eray Pointer to the ERAY module registers.
 *
 * \retval Ifx_SRC_SRCR* Pointer to the MBSC1 service request status register.
 *
 */
IFX_INLINE volatile Ifx_SRC_SRCR *IfxEray_getMessageBufferStatus1SrcPtr(Ifx_ERAY *eray);

/**
 * \brief Gets the NDAT0 service request source pointer.
 *
 * \param[in] eray Pointer to the ERAY module registers.
 *
 * \retval Ifx_SRC_SRCR* Pointer to the NDAT0 service request source register.
 *
 */
IFX_INLINE volatile Ifx_SRC_SRCR *IfxEray_getNewDataInterrupt0SrcPtr(Ifx_ERAY *eray);

/**
 * \brief Gets the NDAT1 service request source pointer.
 *
 * \param[in] eray Pointer to the ERAY module registers.
 *
 * \retval Ifx_SRC_SRCR* Pointer to the NDAT1 service request source register.
 *
 */
IFX_INLINE volatile Ifx_SRC_SRCR *IfxEray_getNewDataInterrupt1SrcPtr(Ifx_ERAY *eray);

/**
 * \brief Checks and returns the status of the new data interrupt for a specified message buffer.
 *
 * \param[in] eray Pointer to the ERAY module registers.
 * \param[in] ndat Message buffer number to check the interrupt status for. Range: 0x0 to 0x7F.
 *
 * \retval TRUE New data interrupt is pending for the specified message buffer.
 *         FALSE No new data interrupt is pending for the specified message buffer.
 *
 */
IFX_INLINE boolean IfxEray_getNewDataInterruptStatus(Ifx_ERAY *eray, uint8 ndat);

/**
 * \brief Gets the address of the OBUSY (Output Buffer Busy) service request register.
 *
 * \param[in] eray Pointer to the ERAY module registers.
 *
 * \retval Ifx_SRC_SRCR* Pointer to the OBUSY service request register.
 *
 */
IFX_INLINE volatile Ifx_SRC_SRCR *IfxEray_getOutputBufferBusySrcPtr(Ifx_ERAY *eray);

/**
 * \brief Retrieves the status interrupt flags for the ERAY module.
 *
 * \param[in] eray Pointer to the ERAY module registers.
 *
 * \retval Ifx_ERAY_SIR A bitwise combination of flags indicating the current interrupt status.
 *
 */
IFX_INLINE Ifx_ERAY_SIR IfxEray_getStatusInterrupts(Ifx_ERAY *eray);

/**
 * \brief Gets the TINT0 service request.
 *
 * \param[in] eray Pointer to the ERAY module registers.
 *
 * \retval Ifx_SRC_SRCR* Pointer to the TINT0 service request register.
 *
 */
IFX_INLINE volatile Ifx_SRC_SRCR *IfxEray_getTimerInterrupt0SrcPtr(Ifx_ERAY *eray);

/**
 * \brief Gets the TINT1 service request register pointer.
 *
 * \param[in] eray Pointer to the ERAY module registers.
 *
 * \retval Ifx_SRC_SRCR* Pointer to the TINT1 service request register.
 *
 */
IFX_INLINE volatile Ifx_SRC_SRCR *IfxEray_getTimerInterrupt1SrcPtr(Ifx_ERAY *eray);

/******************************************************************************/
/*-------------------------Global Function Prototypes-------------------------*/
/******************************************************************************/

/**
 * \brief Clears all the error flags for the ERAY module.
 *
 * \param[inout] eray Pointer to the ERAY module registers.
 *
 * \retval None
 * 
 */
IFX_EXTERN void IfxEray_clearAllFlags(Ifx_ERAY *eray);

/**
 * \brief Enables all the Interrupt lines for the ERAY module.
 *
 * \param[inout] eray Pointer to the ERAY module registers.
 *
 * \retval None
 * 
 */
IFX_EXTERN void IfxEray_enableInterruptLines(Ifx_ERAY *eray);

/**
 * \brief Configures the interrupt destination for a specified message buffer.
 *
 * \param[inout] eray                     Pointer to the ERAY module registers.
 * \param[in]    messageBuffer            The message buffer interrupt to configure. Range: 0x0 to 0x7F.
 * \param[in]    messageBufferDestination The destination interrupt output to select. Range: 0x0 or 0x1.
 *
 * \retval None
 *
 */
IFX_EXTERN void IfxEray_setMessageBufferInterruptDestination(Ifx_ERAY *eray, uint8 messageBuffer, uint8 messageBufferDestination);

/**
 * \brief Selects between NDAT0 and NDAT1 interrupt destinations for the ERAY module.
 *
 * \param[inout] eray            Pointer to the ERAY module registers.
 * \param[in]    ndat            The NDAT interrupt to configure (NDAT0 or NDAT1). Range: 0x0 to 0x7F.
 * \param[in]    ndatDestination The destination for the NDAT interrupt output. Range: 0x0 to 0x1.
 *
 * \retval None
 * 
 */
IFX_EXTERN void IfxEray_setNewDataInterruptDestination(Ifx_ERAY *eray, uint8 ndat, uint8 ndatDestination);

/** \} */

/** \addtogroup IfxLld_Eray_Std_IO
 * \{ */

/******************************************************************************/
/*-------------------------Inline Function Prototypes-------------------------*/
/******************************************************************************/

/**
 * \brief Initializes a RX pin with a specified input mode.
 *
 * \param[in] rx     Pointer to the RX pin which should be configured.
 * \param[in] rxMode The input mode to be configured for the RX pin. Range: \ref IfxPort_InputMode.
 *
 * \retval None
 *
 */
IFX_INLINE void IfxEray_initRxPin(const IfxEray_Rxd_In *rx, IfxPort_InputMode rxMode);

/**
 * \brief Initializes a TX Enable output pin with the specified mode and pad driver settings.
 *
 * \param[in] txEn      Pointer to the TX Enable Pin which should be configured.
 * \param[in] txEnMode  The output mode to be configured for the TX Enable pin. Range: \ref IfxPort_OutputMode.
 * \param[in] padDriver The pad driver mode to be configured for the TX Enable pin. Range: \ref IfxPort_PadDriver.
 *
 * \retval None
 *
 */
IFX_INLINE void IfxEray_initTxEnPin(const IfxEray_Txen_Out *txEn, IfxPort_OutputMode txEnMode, IfxPort_PadDriver padDriver);

/**
 * \brief Initializes a TX output pin with specified mode and driver settings.
 *
 * \param[in] tx        Pointer to the TX Pin which should be configured.
 * \param[in] txMode    The pin output mode which should be configured. Range: \ref IfxPort_OutputMode.
 * \param[in] padDriver The pad driver mode which should be configured. Range: \ref IfxPort_PadDriver.
 *
 * \retval None
 *
 */
IFX_INLINE void IfxEray_initTxPin(const IfxEray_Txd_Out *tx, IfxPort_OutputMode txMode, IfxPort_PadDriver padDriver);

/** \} */

/** \addtogroup IfxLld_Eray_Std_Module
 * \{ */

/******************************************************************************/
/*-------------------------Inline Function Prototypes-------------------------*/
/******************************************************************************/

/**
 * \brief Disables the ERAY module.
 *
 * \param[inout] eray Pointer to the ERAY module registers.
 *
 * \retval None
 *
 */
IFX_INLINE void IfxEray_disableModule(Ifx_ERAY *eray);

/**
 * \brief Enables the ERAY module.
 *
 * \param[inout] eray Pointer to the ERAY module registers.
 *
 * \retval None
 * 
 */
IFX_INLINE void IfxEray_enableModule(Ifx_ERAY *eray);

/**
 * \brief Returns the module's suspend state.
 *
 * \param[in] eray Pointer to the ERAY module registers.
 *
 * \retval TRUE Module is suspended.
 *         FALSE Module is not suspended.
 *
 */
IFX_INLINE boolean IfxEray_isModuleSuspended(Ifx_ERAY *eray);

/**
 * \brief Sets the sensitivity of the module to sleep signal, enabling or disabling it.
 *
 * \param[inout] eray Pointer to the ERAY module registers.
 * \param[in]    mode Mode selection for sensitivity. Range: \ref IfxEray_SleepMode.
 *
 * \retval None
 *
 */
IFX_INLINE void IfxEray_setSleepMode(Ifx_ERAY *eray, IfxEray_SleepMode mode);

/******************************************************************************/
/*-------------------------Global Function Prototypes-------------------------*/
/******************************************************************************/

/**
 * \brief Retrieves the register address of the ERAY module for the specified index.
 *
 * \param[in] eray Resource index of the ERAY module. Range: \ref IfxEray_Index.
 *
 * \retval Ifx_ERAY* Pointer to the ERAY module's register address.
 * 
 */
IFX_EXTERN Ifx_ERAY *IfxEray_getAddress(IfxEray_Index eray);

/**
 * \brief Retrieves the resource index of the specified ERAY module.
 *
 * \param[in] eray Pointer to the ERAY module registers.
 *
 * \retval IfxEray_Index The resource index of the ERAY module. Range: \ref IfxEray_Index.
 *
 */
IFX_EXTERN IfxEray_Index IfxEray_getIndex(Ifx_ERAY *eray);

/**
 * \brief Resets the ERAY module to its initial state.
 *
 * \param[inout] eray Pointer to the ERAY module registers.
 *
 * \retval None
 *
 */
IFX_EXTERN void IfxEray_resetModule(Ifx_ERAY *eray);

/** \} */

/** \addtogroup IfxLld_Eray_Std_Status
 * \{ */

/******************************************************************************/
/*-------------------------Inline Function Prototypes-------------------------*/
/******************************************************************************/

/**
 * \brief Retrieves the current FIFO status of the ERAY module.
 *
 * \param[in] eray Pointer to the ERAY module registers.
 *
 * \retval Ifx_ERAY_FSR The FIFO status.
 *
 */
IFX_INLINE Ifx_ERAY_FSR IfxEray_getFifoStatus(Ifx_ERAY *eray);

/**
 * \brief Gets the Input Buffer Host Busy status.
 *
 * \param[in] eray Pointer to the ERAY module registers.
 *
 * \retval TRUE Host is busy.
 *         FALSE Host is not busy.
 *
 */
IFX_INLINE boolean IfxEray_getInputBufferBusyHostStatus(Ifx_ERAY *eray);

/**
 * \brief Checks if the Input Buffer Shadow is currently busy.
 *
 * \param[in] eray Pointer to the ERAY module registers.
 *
 * \retval uint8 TRUE If the Input Buffer Shadow is busy.
 *               FALSE If the Input Buffer Shadow is idle.
 *
 */
IFX_INLINE uint8 IfxEray_getInputBufferBusyShadowStatus(Ifx_ERAY *eray);

/**
 * \brief Retrieves the current output buffer index from the ERAY module.
 *
 * \param[in] eray Pointer to the ERAY module registers.
 *
 * \retval uint8 The current output buffer index. Range: 0x0 to 0x7F.
 * 
 */
IFX_INLINE uint8 IfxEray_getOutputBuffer(Ifx_ERAY *eray);

/**
 * \brief Gets the Output Buffer Shadow status.
 *
 * \param[in] eray Pointer to the ERAY module registers.
 *
 * \retval TRUE If the output buffer shadow is busy.
 *         FALSE If the output buffer shadow is not busy.
 *
 */
IFX_INLINE boolean IfxEray_getOutputBufferBusyShadowStatus(Ifx_ERAY *eray);

/**
 * \brief Gets the current POC state of the ERAY module.
 *
 * \param[in] eray Pointer to the ERAY module registers.
 *
 * \retval IfxEray_PocState The current POC state. Range: \ref IfxEray_PocState.
 *
 */
IFX_INLINE IfxEray_PocState IfxEray_getPocState(Ifx_ERAY *eray);

/**
 * \brief Retrieves the channel that received the wakeup pattern.
 *
 * \param[in] eray Pointer to the ERAY module registers.
 *
 * \retval IfxEray_WakeupChannel The channel that received the wakeup pattern. Range: \ref IfxEray_WakeupChannel.
 *
 */
IFX_INLINE IfxEray_WakeupChannel IfxEray_getWakeupPatternReceivedChannel(Ifx_ERAY *eray);

/**
 * \brief Waits until the controller enters the specified POC state.
 * 
 * \param[in] eray     Pointer to the ERAY module registers.
 * \param[in] pocState The target POC state to wait for. Range: \ref IfxEray_PocState.
 * 
 * \retval None
 * 
 */
IFX_INLINE void IfxEray_waitForPocState(Ifx_ERAY *eray, IfxEray_PocState pocState);

/******************************************************************************/
/*-------------------------Global Function Prototypes-------------------------*/
/******************************************************************************/

/**
 * \brief Changes the Communication Controller state.
 *
 * \param[inout] eray       Pointer to the ERAY module registers.
 * \param[in]    pocCommand POC command to trigger the state change. Range: \ref IfxEray_PocCommand.
 *
 * \retval TRUE Command was successfully accepted.
 *         FALSE Command was not accepted.
 *
 */
IFX_EXTERN boolean IfxEray_changePocState(Ifx_ERAY *eray, IfxEray_PocCommand pocCommand);

/**
 * \brief Configures the POC state to the Ready state.
 *
 * \param[inout] eray Pointer to the ERAY module registers.
 *
 * \retval None
 *
 */
IFX_EXTERN void IfxEray_setPocReady(Ifx_ERAY *eray);

/** \} */

/** \addtogroup IfxLld_Eray_Std_Configuration
 * \{ */

/******************************************************************************/
/*-------------------------Inline Function Prototypes-------------------------*/
/******************************************************************************/

/**
 * \brief Requests to receive the header section from the message buffer.
 *
 * \param[inout] eray           Pointer to the ERAY module registers.
 * \param[in]    headerReceived Boolean flag indicating whether the header was received.
 *                              - TRUE: Header was received.
 *                              - FALSE: Header was not received.
 *
 * \retval None
 *
 */
IFX_INLINE void IfxEray_receiveHeader(Ifx_ERAY *eray, boolean headerReceived);

/**
 * \brief Configures the ERAY module to send the header in the frame.
 *
 * \param[inout] eray             Pointer to the ERAY module registers.
 * \param[in]    headerTransfered Boolean flag indicating whether the header transfer should be initiated.
 *                                - TRUE: Header transfer is requested.
 *                                - FALSE: Header transfer is not requested.
 *
 * \retval None
 *
 */
IFX_INLINE void IfxEray_sendHeader(Ifx_ERAY *eray, boolean headerTransfered);

/**
 * \brief Sets the number of cycle pairs for the Active state in the ERAY module.
 *
 * \param[inout] eray                        Pointer to the ERAY module registers.
 * \param[in]    numberOfCyclePairsForActive The number of cycle pairs for the Active state. Range: 0x0 to 0x15.
 *
 * \retval None
 *
 */
IFX_INLINE void IfxEray_setActiveCyclePairs(Ifx_ERAY *eray, uint8 numberOfCyclePairsForActive);

/**
 * \brief Sets auto delays between input, output buffers, and message RAM.
 *
 * \param[inout] eray Pointer to the ERAY module registers.
 *
 * \retval None
 *
 */
IFX_INLINE void IfxEray_setAutoDelayBuffers(Ifx_ERAY *eray);

/**
 * \brief Sets the baudrate on the Flexray bus.
 *
 * \param[inout] eray     Pointer to the ERAY module registers.
 * \param[in]    baudrate Baudrate value to be set. Range: \ref IfxEray_Baudrate.
 *
 * \retval None
 *
 */
IFX_INLINE void IfxEray_setBaudrate(Ifx_ERAY *eray, IfxEray_Baudrate baudrate);

/**
 * \brief Sets secured buffers in message RAM.
 *
 * \param[inout] eray        Pointer to the ERAY module registers.
 * \param[in]    secureValue Secure value to be set. Range: 0x0 to 0x3.
 *
 * \retval None
 *
 */
IFX_INLINE void IfxEray_setBufferReconfigSecure(Ifx_ERAY *eray, uint8 secureValue);

/**
 * \brief Configures the initial offsets for channel A in the ERAY module.
 * 
 * \param[inout] eray                           Pointer to the ERAY module registers.
 * \param[in]    channelAMicrotickInitialOffset Initial offset for channel A in microticks. Range: 0x0 to 0xF0.
 * \param[in]    channelAMacrotickInitialOffset Initial offset for channel A in macroticks. Range: 0x0 to 0xF0.
 * 
 * \retval None
 * 
 */
IFX_INLINE void IfxEray_setChannelAInitialOffsets(Ifx_ERAY *eray, uint8 channelAMicrotickInitialOffset, uint8 channelAMacrotickInitialOffset);

/**
 * \brief Configures the initial offset settings for channel B in the ERAY module.
 * 
 * \param[inout] eray                           Pointer to the ERAY module registers.
 * \param[in]    channelBMicrotickInitialOffset Initial offset for channel B in microticks. Range: 0x2 to 0x48.
 * \param[in]    channelBMacrotickInitialOffset Initial offset for channel B in macroticks. Range: 0x2 to 0x48.
 *
 * \retval None
 * 
 */
IFX_INLINE void IfxEray_setChannelBInitialOffsets(Ifx_ERAY *eray, uint8 channelBMicrotickInitialOffset, uint8 channelBMacrotickInitialOffset);

/**
 * \brief Configures the reception delay for both channel A and channel B.
 *
 * \param[inout] eray                   Pointer to the ERAY module registers.
 * \param[in]    channelAReceptionDelay Reception delay value for channel A. Range: 0x0 to 0xC8.
 * \param[in]    channelBReceptionDelay Reception delay value for channel B. Range: 0x0 to 0xC8.
 *
 * \retval None
 *
 */
IFX_INLINE void IfxEray_setChannelsReceiveDelay(Ifx_ERAY *eray, uint8 channelAReceptionDelay, uint8 channelBReceptionDelay);

/** \brief Sets clock correction cycles for Passive and Halt.
 *
 * \param[inout] eray                         pointer to ERAY module registers.
 * \param[in]    clockCorrectionCyclesPassive maximum number of cycles missing clock correction leading for passive state. Range: 0x1 to 0xF.
 * \param[in]    clockCorrectionCyclesHalt    maximum number of cycles missing clock correction leading for halt state. Range: 0x1 to 0xF.
 *
 * \retval None
 *
 */
IFX_INLINE void IfxEray_setClockCorrectionCycles(Ifx_ERAY *eray, uint8 clockCorrectionCyclesPassive, uint8 clockCorrectionCyclesHalt);

/**
 * \brief Configures whether the ERAY module enters a halt state upon detecting a clock synchronization error.
 *
 * \param[inout] eray               Pointer to the ERAY module registers.
 * \param[in]    clockSyncErrorHalt Boolean flag indicating whether to enter halt state in case of a clock synchronization error.
 *                                  - TRUE: communication controller will enter halt state.
 *                                  - FALSE: communication controller will enter/remain in normal passive state.
 *
 * \retval None
 *
 */
IFX_INLINE void IfxEray_setClockSynchErrorHalt(Ifx_ERAY *eray, boolean clockSyncErrorHalt);

/**
 * \brief Sets cluster drift values for clock synchronization in the ERAY module.
 *
 * \param[inout] eray           Pointer to the ERAY module registers.
 * \param[in]    clusterDrift   Cluster drift damping value used in clock synchronization. Range: 0x0 to 0x14.
 * \param[in]    maxDriftOffset Maximum drift offset between two nodes. Range: 0x2 to 0x783.
 *
 * \retval None
 *
 */
IFX_INLINE void IfxEray_setClusterDriftValues(Ifx_ERAY *eray, uint8 clusterDrift, uint16 maxDriftOffset);

/**
 * \brief Configures the acceptable deviation for cluster startup frames during the integration process.
 *
 * \param[inout] eray                     Pointer to the ERAY module registers.
 * \param[in]    acceptedStartupDeviation The deviation value for startup frames during integration. Range: 0x0 to 0x753.
 *
 * \retval None
 *
 */
IFX_INLINE void IfxEray_setClusterStartupDeviation(Ifx_ERAY *eray, uint16 acceptedStartupDeviation);

/**
 * \brief Sets the duration for collision avoidance symbol window.
 *
 * \param[inout] eray                       Pointer to the ERAY module registers.
 * \param[in]    collisionAvoidanceDuration The accepted duration of the CAS symbol window. Range: 0x43 to 0x63.
 *
 * \retval None
 *
 */
IFX_INLINE void IfxEray_setCollisionAvoidanceDuration(Ifx_ERAY *eray, uint8 collisionAvoidanceDuration);

/**
 * \brief Sets the duration of the communication cycle in Macroticks.
 * 
 * \param[inout] eray       Pointer to the ERAY module registers.
 * \param[in]    macroticks Duration of the communication cycle in Macroticks. Range: 0xA to 0x3E80.
 *
 * \retval None
 * 
 */
IFX_INLINE void IfxEray_setCycleDurationMacroticks(Ifx_ERAY *eray, uint16 macroticks);

/**
 * \brief Configures the duration of the communication cycle in microticks.
 *
 * \param[inout] eray       Pointer to the ERAY module registers.
 * \param[in]    microticks Specifies the duration of the communication cycle in microticks. Range: 0x280 to 0x9C400.
 *
 * \retval None
 *
 */
IFX_INLINE void IfxEray_setCycleDurationMicroticks(Ifx_ERAY *eray, uint32 microticks);

/**
 * \brief Configures the decoding correction value for the ERAY module.
 *
 * \param[inout] eray               Pointer to the ERAY module registers.
 * \param[in]    decodingCorrection Decoding correction value. Range: 0xE to 0x8F.
 *
 * \retval None
 *
 */
IFX_INLINE void IfxEray_setDecodingCorrectionValue(Ifx_ERAY *eray, uint8 decodingCorrection);

/**
 * \brief Configures dynamic slots settings for the ERAY module.
 *
 * \param[inout] eray              Pointer to the ERAY module registers.
 * \param[in]    dynamicSlotLength Duration of dynamic slot in macroticks. Range: 0x2 to 0x3F.
 * \param[in]    dynamicSlotCount  Number of dynamic slots in a communication cycle. Range: 0x0 to 0x1F32.
 * \param[in]    idleDynamicSlots  Duration of dynamic slot idle phase. Range: \ref IfxEray_IdleDynamicSlots.
 *
 * \retval None
 *
 */
IFX_INLINE void IfxEray_setDynamicSlots(Ifx_ERAY *eray, uint8 dynamicSlotLength, uint16 dynamicSlotCount, IfxEray_IdleDynamicSlots idleDynamicSlots);

/**
 * \brief Sets external correction controls for the ERAY module, allowing configuration of offset and rate corrections.
 *
 * \param[inout] eray           Pointer to the ERAY module registers.
 * \param[in]    externalOffset External offset correction control. Range: \ref IfxEray_ExternalOffset.
 * \param[in]    externalRate   External rate correction control. Range: \ref IfxEray_ExternalRate.
 *
 * \retval None
 *
 */
IFX_INLINE void IfxEray_setExternalCorrectionControl(Ifx_ERAY *eray, IfxEray_ExternalOffset externalOffset, IfxEray_ExternalRate externalRate);

/**
 * \brief Sets external correction values for the ERAY module.
 *
 * \param[inout] eray                     Pointer to the ERAY module registers.
 * \param[in]    externalOffsetCorrection External clock offset correction value. Range: \ref IfxEray_ExternalOffsetCorrection.
 * \param[in]    externalRateCorrection   External clock rate correction value. Range: \ref IfxEray_ExternalRateCorrection.
 *
 * \retval None
 *
 */
IFX_INLINE void IfxEray_setExternalCorrectionValues(Ifx_ERAY *eray, IfxEray_ExternalOffsetCorrection externalOffsetCorrection, IfxEray_ExternalRateCorrection externalRateCorrection);

/**
 * \brief Sets the starting index of the FIFO buffer in the ERAY module.
 *
 * \param[inout] eray                 Pointer to the ERAY module registers.
 * \param[in]    fifoBufferStartIndex The starting index value for the FIFO buffer. Range: 0x0 to 0xFF.
 *
 * \retval None
 * 
 */
IFX_INLINE void IfxEray_setFifoBufferStartIndex(Ifx_ERAY *eray, uint8 fifoBufferStartIndex);

/**
 * \brief Configures the FIFO filter settings for the ERAY module.
 *
 * \param[inout] eray Pointer to the ERAY module registers.
 * \param[in]    rejectedFrameId        Frame ID to be rejected by the FIFO. Range: 0x0 to 0x7FF.
 * \param[in]    filteredCycleNumber    Number of cycles to filter. Range: 0x0 to 0x7F.
 * \param[in]    fifoNullFramesRejected Rejection of null frames. TRUE reject all null Frames, FALSE null Frames are stored in the FIFO.
 * \param[in]    frameIdFilter          Frame ID to be filtered by the FIFO. Range: 0x0 to 0x3FF.
 *
 * \retval None
 *
 */
IFX_INLINE void IfxEray_setFifoFilterConfigurations(Ifx_ERAY *eray, uint16 rejectedFrameId, uint8 filteredCycleNumber, boolean fifoNullFramesRejected, uint16 frameIdFilter);

/**
 * \brief Configures FIFO message buffer settings for the ERAY module.
 *
 * \param[inout] eray               Pointer to the ERAY module registers.
 * \param[in]    receiveChannel     The receive channel to configure. Range: \ref IfxEray_ReceiveChannel.
 * \param[in]    staticFifoDisabled Boolean flag indicating whether the static FIFO is disabled. TRUE if reject messages for static segment, FALSE if FIFO also used in static segment.
 * \param[in] fifoDepth             The depth of the FIFO buffer. Range: 0x0 to 0xFF.
 *
 * \retval None
 *
 */
IFX_INLINE void IfxEray_setFifoMessageBufferConfigurations(Ifx_ERAY *eray, IfxEray_ReceiveChannel receiveChannel, boolean staticFifoDisabled, uint8 fifoDepth);

/**
 * \brief Configures the first dynamic buffer for the ERAY module.
 *
 * \param[inout] eray               Pointer to the ERAY module registers.
 * \param[in]    firstDynamicBuffer First dynamic buffer value to be set. Range: 0x0 to 0xFF.
 *
 * \retval None
 *
 */
IFX_INLINE void IfxEray_setFirstDynamicBuffer(Ifx_ERAY *eray, uint8 firstDynamicBuffer);

/** \brief Sets startup or wakeup listen timeouts.
 *
 * \param[inout] eray                     Pointer to ERAY module registers.
 * \param[in]    listenTimeOut            Wakeup or startup listen timeout in microticks. Range: 0x504 to 0x139706.
 * \param[in]    listenTimeOutNoise upper Limit for startup or wakeup listen timeout in presence of noise. Range: \ref IfxEray_ListenTimeOutNoise.
 *
 * \retval None
 */
IFX_INLINE void IfxEray_setListenTimeOuts(Ifx_ERAY *eray, uint32 listenTimeOut, IfxEray_ListenTimeOutNoise listenTimeOutNoise);

/**
 * \brief Sets the maximum number of cold start attempts allowed for the active state.
 *
 * \param[inout] eray                 Pointer to the ERAY module registers.
 * \param[in]    maxColdStartAttempts Maximum number of cold start attempts allowed. Range: 0x2 to 0x1F.
 *
 * \retval None
 * 
 */
IFX_INLINE void IfxEray_setMaxColdStartAttempts(Ifx_ERAY *eray, uint8 maxColdStartAttempts);

/**
 * \brief Configures the maximum correction values for the ERAY module.
 *
 * \param[inout] eray                Pointer to the ERAY module registers.
 * \param[in]    maxOffsetCorrection Maximum offset correction value. Range: 0x5 to 0x3BA2.
 * \param[in]    maxRateCorrection   Maximum rate correction value. Range: 0x1 to 0x783.
 *
 * \retval None
 *
 */
IFX_INLINE void IfxEray_setMaxCorrectionValues(Ifx_ERAY *eray, uint16 maxOffsetCorrection, uint16 maxRateCorrection);

/**
 * \brief Sets the maximum number of synchronization frames in a cluster.
 *
 * \param[inout] eray          Pointer to the ERAY module registers.
 * \param[in]    maxSyncFrames Maximum number of synchronization frames in a cluster. Range: \ref IfxEray_MaxSynchFrames.
 *
 * \retval None
 *
 */
IFX_INLINE void IfxEray_setMaxSynchFrames(Ifx_ERAY *eray, IfxEray_MaxSynchFrames maxSyncFrames);

/**
 * \brief Configures the ERAY module with the specified number of message buffers.
 *
 * \param[inout] eray                   Pointer to the ERAY module registers.
 * \param[in]    numberOfMessageBuffers The number of message buffers to be used. Range: 0x1 to 0xFF.
 *
 * \retval None
 * 
 */
IFX_INLINE void IfxEray_setMessageBufferCount(Ifx_ERAY *eray, uint8 numberOfMessageBuffers);

/**
 * \brief Configures the message handler settings for the ERAY module, including static frame payload and transmission timing.
 *
 * \param[inout] eray                    Pointer to the ERAY module registers.
 * \param[in]    staticFramepayload      Payload length of static frames in double bytes. Range: 0x0 to 0x7F.
 * \param[in]    latestTransmissionStart Number of dynamic slots before transmission of the inhibit frame in the dynamic segment. Range: 0x0 to 0x1F2D.
 *
 * \retval None
 *
 */
IFX_INLINE void IfxEray_setMessageHandlerConfigurations(Ifx_ERAY *eray, uint8 staticFramepayload, uint16 latestTransmissionStart);

/**
 * \brief Sets the starting point of the Network Idle Time Phase for the ERAY module.
 *
 * \param[inout] eray                 Pointer to the ERAY module registers.
 * \param[in]    networkStartIdleTime The starting point of the Network Idle Time Phase. Range: 0x7 to 0x3E7D.
 *
 * \retval None
 * 
 */
IFX_INLINE void IfxEray_setNetworkStartIdleTime(Ifx_ERAY *eray, uint16 networkStartIdleTime);

/**
 * \brief Configures the length of the network management vector for the ERAY module.
 *
 * \param[inout] eray                Pointer to the ERAY module registers.
 * \param[in]    networkVectorLength The desired length of the network management vector. Range: 0x0 to 0xC.
 *
 * \retval None
 *
 */
IFX_INLINE void IfxEray_setNetworkVectorLength(Ifx_ERAY *eray, uint32 networkVectorLength);

/**
 * \brief Configures the connection status of channels A and B to a node.
 *
 * \param[inout] eray                  Pointer to the ERAY module registers.
 * \param[in]    channelAConnectedNode Boolean indicating whether channel A is connected to the node. TRUE if node connected to channel A, FALSE if not connected to channel A.
 * \param[in]    channelBConnectedNode Boolean indicating whether channel B is connected to the node. TRUE if node connected to channel B, FALSE if not connected to channel B.
 *
 * \retval None
 *
 */
IFX_INLINE void IfxEray_setNodeChannels(Ifx_ERAY *eray, boolean channelAConnectedNode, boolean channelBConnectedNode);

/**
 * \brief Sets the offset correction starting point for the ERAY module.
 *
 * \param[inout] eray             Pointer to the ERAY module registers.
 * \param[in]    correctionOffset Offset correction value to be applied. Range: 0x8 to 0x3E7E.
 *
 * \retval None
 *
 */
IFX_INLINE void IfxEray_setOffsetCorrection(Ifx_ERAY *eray, uint16 correctionOffset);

/**
 * \brief Configures the ERAY module to request frame reception based on the given flag.
 *
 * \param[inout] eray             Pointer to the ERAY module registers.
 * \param[in]    receiveRequested Boolean flag indicating whether frame reception is requested. TRUE if transfer to OBF shadow requested, FALSE no request.
 *
 * \retval None
 *
 */
IFX_INLINE void IfxEray_setReceiveRequest(Ifx_ERAY *eray, boolean receiveRequested);

/** \brief Sets receive wakeup times.
 *
 * \param[inout] eray                      Pointer to ERAY module registers.
 * \param[in]    receiveWakeupTestDuration Duration of receive wakeup pattern. Range: 0x4C to 0x12D.
 * \param[in]    receiveWakeupIdleTime     Duration of receive wakeup idle time. Range: 0xE to 0x3B.
 * \param[in]    receiveWakeupLowTime      Duration of receive wakeup low time. Range: 0xA to 0x37.
 *
 * \retval None
 *
 */
IFX_INLINE void IfxEray_setReceiveWakeupTimes(Ifx_ERAY *eray, uint16 receiveWakeupTestDuration, uint8 receiveWakeupIdleTime, uint8 receiveWakeupLowTime);

/**
 * \brief Configures the ERAY module to use a specific buffer for receiving frames.
 *
 * \param[inout] eray        Pointer to the ERAY module registers.
 * \param[in]    bufferIndex The buffer number to be used for receiving frames.Range: 0x0 to 0x7F.
 *
 * \retval None
 *
 */
IFX_INLINE void IfxEray_setRxBufferNumber(Ifx_ERAY *eray, uint8 bufferIndex);

/**
 * \brief Configures the static and dynamic action points for the ERAY module slots.
 *
 * \param[inout] eray               Pointer to the ERAY module registers.
 * \param[in]    staticActionPoint  Static slots and symbol window action point. Range: 0x1 to 0x3F.
 * \param[in]    dynamicActionPoint Dynamic slots action point. Range: 0x1 to 0x1F.
 *
 * \retval None
 *
 */
IFX_INLINE void IfxEray_setSlotActionPoints(Ifx_ERAY *eray, uint8 staticActionPoint, uint8 dynamicActionPoint);

/**
 * \brief Configures the static slot settings for the ERAY module.
 * 
 * \param[inout] eray             Pointer to the ERAY module registers.
 * \param[in]    staticSlotLength Duration of each static slot in macroticks. Range: 0x4 to 0x0293.
 * \param[in]    staticSlotsCount Number of static slots in a communication cycle. Range: 0x2 to 0x3FF.
 * 
 * \retval None
 * 
 */
IFX_INLINE void IfxEray_setStaticSlots(Ifx_ERAY *eray, uint16 staticSlotLength, uint16 staticSlotsCount);

/**
 * \brief Sets the sample point for strobing in the ERAY module.
 *
 * \param[inout] eray           Pointer to the ERAY module registers.
 * \param[in]    strobePosition The sample count value for strobing. Range: \ref IfxEray_StrobePosition.
 *
 * \retval None
 *
 */
IFX_INLINE void IfxEray_setStrobePosition(Ifx_ERAY *eray, IfxEray_StrobePosition strobePosition);

/**
 * \brief Configures the symbol transmission channels for the ERAY module.
 *
 * \param[inout] eray                      Pointer to the ERAY module registers.
 * \param[in]    channelASymbolTransmitted Boolean flag indicating whether Channel A transmits symbols. TRUE if channel A selected for MTS transmission, FALSE if channel A disabled for MTS transmission.
 * \param[in]    channelBSymbolTransmitted Boolean flag indicating whether Channel B transmits symbols. TRUE if channel B selected for MTS transmission, FALSE if channel B disabled for MTS transmission.
 *
 * \retval None
 *
 */
IFX_INLINE void IfxEray_setSymbolChannels(Ifx_ERAY *eray, boolean channelASymbolTransmitted, boolean channelBSymbolTransmitted);

/**
 * \brief Sets the transmission slot mode for the ERAY module.
 *
 * \param[inout] eray                 Pointer to the ERAY module registers.
 * \param[in]    transmissionSlotMode The transmission slot mode to be set. Range: \ref IfxEray_TransmissionSlotMode.
 *
 * \retval None
 *
 */
IFX_INLINE void IfxEray_setTransmissionSlotMode(Ifx_ERAY *eray, IfxEray_TransmissionSlotMode transmissionSlotMode);

/**
 * \brief Sets the transmission start time duration for the ERAY module.
 *
 * \param[inout] eray                  Pointer to the ERAY module registers.
 * \param[in]    transmissionStartTime The transmission start time duration. Range: 0x3 to 0xF.
 *
 * \retval None
 * 
 */
IFX_INLINE void IfxEray_setTransmissionStartTime(Ifx_ERAY *eray, uint8 transmissionStartTime);

/**
 * \brief Sets a request to transmit a frame through the ERAY module.
 *
 * \param[inout] eray              Pointer to the ERAY module registers.
 * \param[in]    transferRequested Boolean flag indicating whether a transfer is requested. TRUE if set transmission request flag, FALSE if reset transmission request flag.
 *
 * \retval None
 *
 */
IFX_INLINE void IfxEray_setTransmitRequest(Ifx_ERAY *eray, boolean transferRequested);

/** \brief Sets transmit wakeup times.
 *
 * \param[inout] eray                      Pointer to the ERAY module registers.
 * \param[in]    transmitWakeupRepetitions Transmission wakeup repetitions. Range: 0x2 to 0x3F.
 * \param[in]    transmitWakeupIdleTime    Duration of transmit wakeup idle time. Range: 0x2D to 0xB4.
 * \param[in]    transmitWakeupLowTime     Duration of transmit wakeup low time. Range: 0xF to 0x3C.
 *
 * \retval None
 *
 */
IFX_INLINE void IfxEray_setTransmitWakeupTimes(Ifx_ERAY *eray, uint8 transmitWakeupRepetitions, uint8 transmitWakeupIdleTime, uint8 transmitWakeupLowTime);

/**
 * \brief Configures the transmission status of startup and synchronization frames for the ERAY module.
 * 
 * \param[inout] eray                    Pointer to the ERAY module registers.
 * \param[in]    startupFrameTransmitted Flag indicating whether the startup frame has been transmitted.
 *                                       - TRUE: Startup frame has been transmitted.
 *                                       - FALSE: Startup frame has not been transmitted.
 * \param[in]    synchFrameTransmitted   Flag indicating whether the synchronization frame has been transmitted.
 *                                       - TRUE: Synchronization frame has been transmitted.
 *                                       - FALSE Synchronization frame has not been transmitted.
 * 
 * \retval None
 * 
 */
IFX_INLINE void IfxEray_setTransmittedFrames(Ifx_ERAY *eray, boolean startupFrameTransmitted, boolean synchFrameTransmitted);

/**
 * \brief Configures the transmit buffer number for the ERAY module.
 * 
 * \param[inout] eray        Pointer to the ERAY module registers.
 * \param[in]    bufferIndex The buffer number to be used for transmission. Range: 0x0 to 0x7F.
 *
 * \retval None
 * 
 */
IFX_INLINE void IfxEray_setTxBufferNumber(Ifx_ERAY *eray, uint8 bufferIndex);

/**
 * \brief Swaps the shadow and Host output registers if requested.
 *
 * \param[inout] eray          Pointer to the ERAY module registers.
 * \param[in]    swapRequested Boolean flag indicating whether the swap operation should be performed. TRUE if swap OBF shadow and OBF host, FALSE no action.
 *
 * \retval None
 * 
 */
IFX_INLINE void IfxEray_setViewData(Ifx_ERAY *eray, boolean swapRequested);

/**
 * \brief Configures the specified wakeup pattern channel for the ERAY module.
 *
 * \param[inout] eray                 Pointer to the ERAY module registers.
 * \param[in]    wakeupPatternChannel The cluster wakeup pattern channel to configure. Range: \ref IfxEray_WakeupChannel.
 *
 * \retval None
 *
 */
IFX_INLINE void IfxEray_setWakeupPatternChannel(Ifx_ERAY *eray, IfxEray_WakeupChannel wakeupPatternChannel);

/** \} */

/** \addtogroup IfxLld_Eray_Std_Operative
 * \{ */

/******************************************************************************/
/*-------------------------Inline Function Prototypes-------------------------*/
/******************************************************************************/

/**
 * \brief Requests to receive data from the message buffer.
 *
 * \param[inout] eray         Pointer to the ERAY module registers.
 * \param[in]    dataReceived Boolean flag indicating whether data should be received. TRUE data section selected for transfer from message RAM to output buffer, FALSE data Section is not read.
 *
 * \retval None
 *
 */
IFX_INLINE void IfxEray_receiveData(Ifx_ERAY *eray, boolean dataReceived);

/**
 * \brief Sets the data transfer bit in the ERAY module to indicate whether data has been transferred.
 *
 * \param[inout] eray           Pointer to the ERAY module registers.
 * \param[in]    dataTransfered Boolean flag indicating whether data has been transferred. TRUE data section selected for transfer from input buffer to the message RAM, FALSE data section is not updated.
 *
 * \retval None
 *
 */
IFX_INLINE void IfxEray_sendData(Ifx_ERAY *eray, boolean dataTransfered);

/******************************************************************************/
/*-------------------------Global Function Prototypes-------------------------*/
/******************************************************************************/

/**
 * \brief Calculate and returns the CRC for frame.
 *
 * \param[in] payloadLength         Payload length configured for frame. Range: 0x0 to 0x7F.
 * \param[in] frameId               Slot id. Range: 0x0 to 0xFFFF.
 * \param[in] startupFrameIndicator Whether startup frame is indicated or not.
 * \param[in] syncFrameIndicator    Whether sync frame is indicated or not.
 *
 * \retval uint16 calculated CRC value. Range: 0x0 to 0xFFFF.
 *
 */
IFX_EXTERN uint16 IfxEray_calcHeaderCrc(uint8 payloadLength, uint16 frameId, boolean startupFrameIndicator, boolean syncFrameIndicator);

/**
 * \brief Reads the received data from the output registers of the ERAY module into a buffer.
 *
 * \param[in]    eray          Pointer to the ERAY module registers.
 * \param[inout] data          Pointer to the buffer where the received data will be stored.
 * \param[in]    payloadLength The length of the payload data received in the current frame, specified in bytes. Range: 0x0 to 0x7F.
 *
 * \retval None
 *
 */
IFX_EXTERN void IfxEray_readData(Ifx_ERAY *eray, uint32 *data, uint8 payloadLength);

/**
 * \brief Reads header and payload data from the ERAY module's output buffers.
 *
 * \param[in]    eray             Pointer to the ERAY module registers.
 * \param[inout] header           Pointer to the structure that will hold the received header information.
 * \param[inout] data             Pointer to the buffer that will store the received payload data.
 * \param[in]    maxPayloadLength Maximum length of the payload data to be received. Range: 0x0 to 0x7F.
 *
 * \retval None
 *
 */
IFX_EXTERN void IfxEray_readFrame(Ifx_ERAY *eray, IfxEray_ReceivedHeader *header, uint32 *data, Ifx_SizeT maxPayloadLength);

/**
 * \brief Configures and writes header and data to the input buffers and sets the slot configuration for the ERAY module.
 *
 * \param[inout] eray       Pointer to the ERAY module registers.
 * \param[in]    header     Pointer to the header section of the message buffer containing frame ID, cycle code, channel filtering, buffer direction, and other control flags.
 * \param[in]    data       Pointer to the data section of the message buffer to be written to the input buffers.
 * \param[in]    slotConfig Pointer to the slot allocation configuration structure specifying transfer status, buffer index, and transmission requests.
 *
 * \retval None
 * 
 */
IFX_EXTERN void IfxEray_setSlot(Ifx_ERAY *eray, const IfxEray_Header *header, const uint32 *data, const IfxEray_SlotConfig *slotConfig);

/**
 * \brief Writes data section of a frame to input data registers.
 *
 * \param[inout] eray          Pointer to the ERAY module registers.
 * \param[in]    data          Pointer to the data segment in a frame to be written.
 * \param[in]    payloadLength Payload length configured for the slot buffer. Range: 0x0 to 0x7F.
 *
 * \retval None
 *
 */
IFX_EXTERN void IfxEray_writeData(Ifx_ERAY *eray, const uint32 *data, uint8 payloadLength);

/** \} */

/******************************************************************************/
/*-------------------------Inline Function Prototypes-------------------------*/
/******************************************************************************/

/**
 * \brief Gets the FIFO buffer index for the ERAY module.
 *
 * \param[in] eray Pointer to the ERAY module registers.
 *
 * \retval uint8 The current FIFO buffer index Range: 0x0 to 0xFF.
 *
 */
IFX_INLINE uint8 IfxEray_getFifoIndex(Ifx_ERAY *eray);

/**
 * \brief Configures the ERAY module's suspend mode to hard, soft, or none.
 *
 * \param[inout] eray Pointer to the ERAY module registers.
 * \param[in]    mode Suspend mode to be configured. Range: \ref IfxEray_SuspendMode.
 *
 * \note The function only works when the OCDS is enabled and the system is in Supervisor Mode.
 *       When OCDS is disabled, the OCS suspend control is ineffective.
 *
 * \retval None
 *
 */
IFX_INLINE void IfxEray_setSuspendMode(Ifx_ERAY *eray, IfxEray_SuspendMode mode);

/**
 * \brief Initializes the RX pin configuration with the specified input mode and pad driver settings.
 *
 * \param[in] rx        The RX pin to be configured.
 * \param[in] rxMode    The input mode to be set for the RX pin. Range: \ref IfxPort_InputMode.
 * \param[in] padDriver The pad driver configuration to be applied. Range: \ref IfxPort_PadDriver.
 *
 * \retval None
 *
 */
IFX_INLINE void IfxEray_initRxPinWithPadLevel(const IfxEray_Rxd_In *rx, IfxPort_InputMode rxMode, IfxPort_PadDriver padDriver);

/**
 * \brief Selects the receiver channel input for the specified ERAY node.
 *
 * \param[inout] eray   Pointer to the ERAY module registers.
 * \param[in]    nodeId ERAY node identifier. Range: \ref IfxEray_NodeId.
 * \param[in]    select Receive channel selection. Range: \ref Ifx_RxSel.
 *
 * \retval None
 *
 */
IFX_INLINE void IfxEray_selectRecieveInput(Ifx_ERAY *eray, IfxEray_NodeId nodeId, Ifx_RxSel select);

/**
 * \brief Sets the POC command to control the ERAY module's state.
 *
 * \param[inout] eray Pointer to the ERAY module registers.
 * \param[in]    cmd  POC command to be executed. Range: \ref IfxEray_PocCommand.
 *
 * \retval None
 *
 */
IFX_INLINE void IfxEray_setPocCommand(Ifx_ERAY *eray, IfxEray_PocCommand cmd);

/**
 * \brief Checks if the ERAY module's RAMs are cleared.
 *
 * \param[in] eray Pointer to the ERAY module registers.
 *
 * \retval TRUE If the ERAY module's RAMs are cleared.
 *         FALSE If the ERAY module's RAMs are not cleared.
 *
 */
IFX_INLINE boolean IfxEray_isRamsCleared(Ifx_ERAY *eray);

/**
 * \brief Checks whether the POC (Point of Control) is currently busy.
 *
 * \param[in] eray Pointer to the ERAY module registers.
 *
 * \retval TRUE POC is busy.
 *         FALSE POC is not busy.
 *
 */
IFX_INLINE boolean IfxEray_isPocBusy(Ifx_ERAY *eray);

/**
 * \brief Enables the specified interrupt line for the ERAY module.
 *
 * \param[inout] eray    Pointer to the ERAY module registers.
 * \param[in]    intLine The interrupt line to be enabled. Range: \ref IfxEray_InterruptLine.
 *
 * \retval None
 *
 */
IFX_INLINE void IfxEray_enableInterruptLine(Ifx_ERAY *eray, IfxEray_InterruptLine intLine);

/**
 * \brief Enables the transmit interrupt functionality.
 *
 * \param[inout] eray Pointer to the ERAY module registers.
 *
 * \retval None
 *
 */
IFX_INLINE void IfxEray_enableTransmitInterrupt(Ifx_ERAY *eray);

/**
 * \brief Enables all error interrupts for the specified ERAY module.
 *
 * \param[inout] eray Pointer to the ERAY module registers.
 *
 * \retval None
 *
 */
IFX_INLINE void IfxEray_enableAllErrorInterrupts(Ifx_ERAY *eray);

/**
 * \brief Unlocks the test mode key for the ERAY module.
 *
 * \param[inout] eray Pointer to the ERAY module registers.
 *
 * \retval None
 * 
 */
IFX_INLINE void IfxEray_unlockTestModeKey(Ifx_ERAY *eray);

/**
 * \brief Enables write access to the test mode registers of the ERAY module.
 *
 * \param[inout] eray Pointer to the ERAY module registers.
 *
 * \retval None
 * 
 */
IFX_INLINE void IfxEray_enableWriteTestRegister(Ifx_ERAY *eray);

/**
 * \brief Enables the external loopback functionality for the ERAY module.
 *
 * \param[inout] eray  Pointer to the ERAY module registers.
 *
 * \retval None
 * 
 */
IFX_INLINE void IfxEray_enableExternalLoopback(Ifx_ERAY *eray);

/**
 * \brief Unlocks the test mode configuration for the ERAY module.
 *
 * \param[inout] eray Pointer to the ERAY module registers.
 *
 * \retval None
 * 
 */
IFX_INLINE void IfxEray_unlockConfigurationKey(Ifx_ERAY *eray);

/**
 * \brief Configures the SUC1 register of the ERAY module with the specified configuration value.
 *
 * \param[inout] eray        Pointer to the ERAY module registers.
 * \param[in]    configValue The 32-bit configuration value to be written to the SUC1 register.Range: 0x0 to 0xFFFFB8F.
 *
 * \retval None
 *
 */
IFX_INLINE void IfxEray_configureSuc1Register(Ifx_ERAY *eray, uint32 configValue);

/**
 * \brief Configures the macro tick value for the ERAY module by setting the MTCCV register.
 *
 * \param[inout] eray      Pointer to the ERAY module registers.
 * \param[in]    tickValue The value to be set for the macro tick. Range: 0x0 to 0x3F3FFF.
 *
 * \retval None
 *
 */
IFX_INLINE void IfxEray_setMacroTickValue(Ifx_ERAY *eray, uint32 tickValue);

/**
 * \brief Returns the current cycle counter value of the ERAY module.
 *
 * \param[in] eray Pointer to the ERAY module registers.
 *
 * \retval uint8 The current cycle count value. Range: 0x0 to 0x3F.
 *
 */
IFX_INLINE uint8 IfxEray_getCycleCountValue(Ifx_ERAY *eray);

/******************************************************************************/
/*---------------------Inline Function Implementations------------------------*/
/******************************************************************************/

IFX_INLINE void IfxEray_clearErrorFlag(Ifx_ERAY *eray, IfxEray_ClearErrorFlag errorFlag)
{
    eray->EIR.U = errorFlag;
}


IFX_INLINE void IfxEray_clearStatusFlag(Ifx_ERAY *eray, IfxEray_ClearStatusFlag statusFlag)
{
    eray->SIR.U = statusFlag;
}


IFX_INLINE void IfxEray_disableModule(Ifx_ERAY *eray)
{
    uint16 passwd = IfxScuWdt_getCpuWatchdogPassword();
    IfxScuWdt_clearCpuEndinit(passwd);
    //disable the module
    eray->CLC.B.DISR = 1;
    IfxScuWdt_setCpuEndinit(passwd);
}


IFX_INLINE void IfxEray_enableModule(Ifx_ERAY *eray)
{
    uint16 passwd = IfxScuWdt_getCpuWatchdogPassword();
    IfxScuWdt_clearCpuEndinit(passwd);
    // Run Mode Clock divider to 1
    //enable the module
    eray->CLC.U = 0x00000100;

    // ensure that write access finished before leaving this function
    if (eray->CLC.U)
    {}

    IfxScuWdt_setCpuEndinit(passwd);
}


IFX_INLINE Ifx_ERAY_EIR IfxEray_getErrorInterrupts(Ifx_ERAY *eray)
{
    Ifx_ERAY_EIR interruptFlags;
    interruptFlags.U = eray->EIR.U;
    return interruptFlags;
}


IFX_INLINE uint8 IfxEray_getFifoIndex(Ifx_ERAY *eray)
{
    return eray->MRC.B.FFB;
}


IFX_INLINE Ifx_ERAY_FSR IfxEray_getFifoStatus(Ifx_ERAY *eray)
{
    Ifx_ERAY_FSR fifoStatus;
    fifoStatus.U = eray->FSR.U;
    return fifoStatus;
}


IFX_INLINE boolean IfxEray_getInputBufferBusyHostStatus(Ifx_ERAY *eray)
{
    return (eray->IBCR.B.IBSYH == 1) ? TRUE : FALSE;
}


IFX_INLINE uint8 IfxEray_getInputBufferBusyShadowStatus(Ifx_ERAY *eray)
{
    return (eray->IBCR.B.IBSYS == 1) ? TRUE : FALSE;
}


IFX_INLINE volatile Ifx_SRC_SRCR *IfxEray_getInputBufferBusySrcPtr(Ifx_ERAY *eray)
{
#if IFXERAY_NUM_MODULES > 1
    if (eray == &MODULE_ERAY0)
    {
        return &MODULE_SRC.ERAY.ERAY[0].IBUSY;
    }
    else
    {
        return &MODULE_SRC.ERAY.ERAY[1].IBUSY;
    }
#else
    IFX_UNUSED_PARAMETER(eray);
    return &MODULE_SRC.ERAY.ERAY[0].IBUSY;
#endif
}


IFX_INLINE volatile Ifx_SRC_SRCR *IfxEray_getInterruptLine0SrcPtr(Ifx_ERAY *eray)
{
#if IFXERAY_NUM_MODULES > 1
    if (eray == &MODULE_ERAY0)
    {
        return &MODULE_SRC.ERAY.ERAY[0].INT0;
    }
    else
    {
        return &MODULE_SRC.ERAY.ERAY[1].INT0;
    }
#else
    IFX_UNUSED_PARAMETER(eray);
    return &MODULE_SRC.ERAY.ERAY[0].INT0;
#endif
}


IFX_INLINE volatile Ifx_SRC_SRCR *IfxEray_getInterruptLine1SrcPtr(Ifx_ERAY *eray)
{
#if IFXERAY_NUM_MODULES > 1
    if (eray == &MODULE_ERAY0)
    {
        return &MODULE_SRC.ERAY.ERAY[0].INT1;
    }
    else
    {
        return &MODULE_SRC.ERAY.ERAY[1].INT1;
    }
#else
    IFX_UNUSED_PARAMETER(eray);
    return &MODULE_SRC.ERAY.ERAY[0].INT1;
#endif
}


IFX_INLINE boolean IfxEray_getMessageBufferInterruptStatus(Ifx_ERAY *eray, uint8 messageBuffer)
{
    uint8           ix                     = messageBuffer / 32;
    uint32          mask                   = 1 << (messageBuffer % 32);
    Ifx_ERAY_MBSC1 *mbscSFR                = (Ifx_ERAY_MBSC1 *)((uint32)&eray->MBSC1 + 4 * ix);
    boolean         messageBufferInterrupt = (mbscSFR->U & mask) ? TRUE : FALSE;

    return messageBufferInterrupt;
}


IFX_INLINE volatile Ifx_SRC_SRCR *IfxEray_getMessageBufferStatus0SrcPtr(Ifx_ERAY *eray)
{
#if IFXERAY_NUM_MODULES > 1
    if (eray == &MODULE_ERAY0)
    {
        return &MODULE_SRC.ERAY.ERAY[0].MBSC0;
    }
    else
    {
        return &MODULE_SRC.ERAY.ERAY[1].MBSC0;
    }
#else
    IFX_UNUSED_PARAMETER(eray);
    return &MODULE_SRC.ERAY.ERAY[0].MBSC0;
#endif
}


IFX_INLINE volatile Ifx_SRC_SRCR *IfxEray_getMessageBufferStatus1SrcPtr(Ifx_ERAY *eray)
{
#if IFXERAY_NUM_MODULES > 1
    if (eray == &MODULE_ERAY0)
    {
        return &MODULE_SRC.ERAY.ERAY[0].MBSC1;
    }
    else
    {
        return &MODULE_SRC.ERAY.ERAY[1].MBSC1;
    }
#else
    IFX_UNUSED_PARAMETER(eray);
    return &MODULE_SRC.ERAY.ERAY[0].MBSC1;
#endif
}


IFX_INLINE volatile Ifx_SRC_SRCR *IfxEray_getNewDataInterrupt0SrcPtr(Ifx_ERAY *eray)
{
#if IFXERAY_NUM_MODULES > 1
    if (eray == &MODULE_ERAY0)
    {
        return &MODULE_SRC.ERAY.ERAY[0].NDAT0;
    }
    else
    {
        return &MODULE_SRC.ERAY.ERAY[1].NDAT0;
    }
#else
    IFX_UNUSED_PARAMETER(eray);
    return &MODULE_SRC.ERAY.ERAY[0].NDAT0;
#endif
}


IFX_INLINE volatile Ifx_SRC_SRCR *IfxEray_getNewDataInterrupt1SrcPtr(Ifx_ERAY *eray)
{
#if IFXERAY_NUM_MODULES > 1
    if (eray == &MODULE_ERAY0)
    {
        return &MODULE_SRC.ERAY.ERAY[0].NDAT1;
    }
    else
    {
        return &MODULE_SRC.ERAY.ERAY[1].NDAT1;
    }
#else
    IFX_UNUSED_PARAMETER(eray);
    return &MODULE_SRC.ERAY.ERAY[0].NDAT1;
#endif
}


IFX_INLINE boolean IfxEray_getNewDataInterruptStatus(Ifx_ERAY *eray, uint8 ndat)
{
    uint8           ix            = ndat / 32;
    uint32          mask          = 1 << (ndat % 32);
    Ifx_ERAY_NDAT1 *ndatSFR       = (Ifx_ERAY_NDAT1 *)((uint32)&eray->NDAT1 + 4 * ix);
    boolean         ndatInterrupt = (ndatSFR->U & mask) ? TRUE : FALSE;

    return ndatInterrupt;
}


IFX_INLINE uint8 IfxEray_getOutputBuffer(Ifx_ERAY *eray)
{
    return eray->OBCR.B.OBRH;
}


IFX_INLINE boolean IfxEray_getOutputBufferBusyShadowStatus(Ifx_ERAY *eray)
{
    return (eray->OBCR.B.OBSYS == 1) ? TRUE : FALSE;
}


IFX_INLINE volatile Ifx_SRC_SRCR *IfxEray_getOutputBufferBusySrcPtr(Ifx_ERAY *eray)
{
#if IFXERAY_NUM_MODULES > 1
    if (eray == &MODULE_ERAY0)
    {
        return &MODULE_SRC.ERAY.ERAY[0].OBUSY;
    }
    else
    {
        return &MODULE_SRC.ERAY.ERAY[1].OBUSY;
    }
#else
    IFX_UNUSED_PARAMETER(eray);
    return &MODULE_SRC.ERAY.ERAY[0].OBUSY;
#endif
}


IFX_INLINE IfxEray_PocState IfxEray_getPocState(Ifx_ERAY *eray)
{
    return (IfxEray_PocState)eray->CCSV.B.POCS;
}


IFX_INLINE Ifx_ERAY_SIR IfxEray_getStatusInterrupts(Ifx_ERAY *eray)
{
    Ifx_ERAY_SIR interruptFlags;
    interruptFlags.U = eray->SIR.U;
    return interruptFlags;
}


IFX_INLINE volatile Ifx_SRC_SRCR *IfxEray_getTimerInterrupt0SrcPtr(Ifx_ERAY *eray)
{
#if IFXERAY_NUM_MODULES > 1
    if (eray == &MODULE_ERAY0)
    {
        return &MODULE_SRC.ERAY.ERAY[0].TINT0;
    }
    else
    {
        return &MODULE_SRC.ERAY.ERAY[1].TINT0;
    }
#else
    IFX_UNUSED_PARAMETER(eray);
    return &MODULE_SRC.ERAY.ERAY[0].TINT0;
#endif
}


IFX_INLINE volatile Ifx_SRC_SRCR *IfxEray_getTimerInterrupt1SrcPtr(Ifx_ERAY *eray)
{
#if IFXERAY_NUM_MODULES > 1
    if (eray == &MODULE_ERAY0)
    {
        return &MODULE_SRC.ERAY.ERAY[0].TINT1;
    }
    else
    {
        return &MODULE_SRC.ERAY.ERAY[1].TINT1;
    }
#else
    IFX_UNUSED_PARAMETER(eray);
    return &MODULE_SRC.ERAY.ERAY[0].TINT1;
#endif
}


IFX_INLINE IfxEray_WakeupChannel IfxEray_getWakeupPatternReceivedChannel(Ifx_ERAY *eray)
{
    IfxEray_WakeupChannel wakeupChannel = IfxEray_WakeupChannel_a;

    if (eray->SIR.B.WUPA == 1)
    {
        wakeupChannel = IfxEray_WakeupChannel_a;
    }
    else if (eray->SIR.B.WUPB == 1)
    {
        wakeupChannel = IfxEray_WakeupChannel_b;
    }

    return wakeupChannel;
}


IFX_INLINE void IfxEray_initRxPin(const IfxEray_Rxd_In *rx, IfxPort_InputMode rxMode)
{
    IfxPort_setPinModeInput(rx->pin.port, rx->pin.pinIndex, rxMode);

    if (rx->nodeId == IfxEray_NodeId_a)
    {
        rx->module->CUST1.B.RISA = rx->select;
    }
    else
    {
        rx->module->CUST1.B.RISB = rx->select;
    }
}


IFX_INLINE void IfxEray_initTxEnPin(const IfxEray_Txen_Out *txEn, IfxPort_OutputMode txEnMode, IfxPort_PadDriver padDriver)
{
    IfxPort_setPinModeOutput(txEn->pin.port, txEn->pin.pinIndex, txEnMode, txEn->select);
    IfxPort_setPinPadDriver(txEn->pin.port, txEn->pin.pinIndex, padDriver);
}


IFX_INLINE void IfxEray_initTxPin(const IfxEray_Txd_Out *tx, IfxPort_OutputMode txMode, IfxPort_PadDriver padDriver)
{
    IfxPort_setPinModeOutput(tx->pin.port, tx->pin.pinIndex, txMode, tx->select);
    IfxPort_setPinPadDriver(tx->pin.port, tx->pin.pinIndex, padDriver);
}


IFX_INLINE boolean IfxEray_isModuleSuspended(Ifx_ERAY *eray)
{
    Ifx_ERAY_OCS ocs;

    // read the status
    ocs.U = eray->OCS.U;

    // return the status
    return ocs.B.SUSSTA;
}


IFX_INLINE void IfxEray_receiveData(Ifx_ERAY *eray, boolean dataReceived)
{
    eray->OBCM.B.RDSS = dataReceived;
}


IFX_INLINE void IfxEray_receiveHeader(Ifx_ERAY *eray, boolean headerReceived)
{
    eray->OBCM.B.RHSS = headerReceived;
}


IFX_INLINE void IfxEray_sendData(Ifx_ERAY *eray, boolean dataTransfered)
{
    eray->IBCM.B.LDSH = dataTransfered;
}


IFX_INLINE void IfxEray_sendHeader(Ifx_ERAY *eray, boolean headerTransfered)
{
    eray->IBCM.B.LHSH = headerTransfered;
}


IFX_INLINE void IfxEray_setActiveCyclePairs(Ifx_ERAY *eray, uint8 numberOfCyclePairsForActive)
{
    eray->SUCC1.B.PTA = numberOfCyclePairsForActive;
}


IFX_INLINE void IfxEray_setAutoDelayBuffers(Ifx_ERAY *eray)
{
    eray->CUST1.B.IEN = 1;
    eray->CUST1.B.OEN = 1;
    eray->CUST3.U     = 0xFFFFFFFF;
}


IFX_INLINE void IfxEray_setBaudrate(Ifx_ERAY *eray, IfxEray_Baudrate baudrate)
{
    eray->PRTC1.B.BRP = baudrate;
}


IFX_INLINE void IfxEray_setBufferReconfigSecure(Ifx_ERAY *eray, uint8 secureValue)
{
    eray->MRC.B.SEC = secureValue;
}


IFX_INLINE void IfxEray_setChannelAInitialOffsets(Ifx_ERAY *eray, uint8 channelAMicrotickInitialOffset, uint8 channelAMacrotickInitialOffset)
{
    eray->GTUC03.B.UIOA = channelAMicrotickInitialOffset;
    eray->GTUC03.B.MIOA = channelAMacrotickInitialOffset;
}


IFX_INLINE void IfxEray_setChannelBInitialOffsets(Ifx_ERAY *eray, uint8 channelBMicrotickInitialOffset, uint8 channelBMacrotickInitialOffset)
{
    eray->GTUC03.B.UIOB = channelBMicrotickInitialOffset;
    eray->GTUC03.B.MIOB = channelBMacrotickInitialOffset;
}


IFX_INLINE void IfxEray_setChannelsReceiveDelay(Ifx_ERAY *eray, uint8 channelAReceptionDelay, uint8 channelBReceptionDelay)
{
    eray->GTUC05.B.DCA = channelAReceptionDelay;
    eray->GTUC05.B.DCB = channelBReceptionDelay;
}


IFX_INLINE void IfxEray_setClockCorrectionCycles(Ifx_ERAY *eray, uint8 clockCorrectionCyclesPassive, uint8 clockCorrectionCyclesHalt)
{
    Ifx_ERAY_SUCC3 succ3;
    succ3.U       = 0;
    succ3.B.WCP   = clockCorrectionCyclesPassive;
    succ3.B.WCF   = clockCorrectionCyclesHalt;
    eray->SUCC3.U = succ3.U;
}


IFX_INLINE void IfxEray_setClockSynchErrorHalt(Ifx_ERAY *eray, boolean clockSyncErrorHalt)
{
    eray->SUCC1.B.HCSE = clockSyncErrorHalt;
}


IFX_INLINE void IfxEray_setClusterDriftValues(Ifx_ERAY *eray, uint8 clusterDrift, uint16 maxDriftOffset)
{
    eray->GTUC05.B.CDD = clusterDrift;
    eray->GTUC06.B.MOD = maxDriftOffset;
}


IFX_INLINE void IfxEray_setClusterStartupDeviation(Ifx_ERAY *eray, uint16 acceptedStartupDeviation)
{
    eray->GTUC06.B.ASR = acceptedStartupDeviation;
}


IFX_INLINE void IfxEray_setCollisionAvoidanceDuration(Ifx_ERAY *eray, uint8 collisionAvoidanceDuration)
{
    eray->PRTC1.B.CASM = collisionAvoidanceDuration;
}


IFX_INLINE void IfxEray_setCycleDurationMacroticks(Ifx_ERAY *eray, uint16 macroticks)
{
    eray->GTUC02.B.MPC = macroticks;
}


IFX_INLINE void IfxEray_setCycleDurationMicroticks(Ifx_ERAY *eray, uint32 microticks)
{
    eray->GTUC01.U = microticks;
}


IFX_INLINE void IfxEray_setDecodingCorrectionValue(Ifx_ERAY *eray, uint8 decodingCorrection)
{
    eray->GTUC05.B.DEC = decodingCorrection;
}


IFX_INLINE void IfxEray_setDynamicSlots(Ifx_ERAY *eray, uint8 dynamicSlotLength, uint16 dynamicSlotCount, IfxEray_IdleDynamicSlots idleDynamicSlots)
{
    eray->GTUC08.B.MSL = dynamicSlotLength;
    eray->GTUC08.B.NMS = dynamicSlotCount;
    eray->GTUC09.B.DSI = idleDynamicSlots;
}


IFX_INLINE void IfxEray_setExternalCorrectionControl(Ifx_ERAY *eray, IfxEray_ExternalOffset externalOffset, IfxEray_ExternalRate externalRate)
{
    eray->GTUC11.B.EOCC = externalOffset;
    eray->GTUC11.B.ERCC = externalRate;
}


IFX_INLINE void IfxEray_setExternalCorrectionValues(Ifx_ERAY *eray, IfxEray_ExternalOffsetCorrection externalOffsetCorrection, IfxEray_ExternalRateCorrection externalRateCorrection)
{
    eray->GTUC11.B.EOC = externalOffsetCorrection;
    eray->GTUC11.B.ERC = externalRateCorrection;
}


IFX_INLINE void IfxEray_setFifoBufferStartIndex(Ifx_ERAY *eray, uint8 fifoBufferStartIndex)
{
    // Buffers from MRC.B.FFB to MRC.B.LCB are assigned FIFO
    eray->MRC.B.FFB = fifoBufferStartIndex;
}


IFX_INLINE void IfxEray_setFifoFilterConfigurations(Ifx_ERAY *eray, uint16 rejectedFrameId, uint8 filteredCycleNumber, boolean fifoNullFramesRejected, uint16 frameIdFilter)
{
    eray->FRF.B.FID   = rejectedFrameId;
    eray->FRF.B.CYF   = filteredCycleNumber;
    eray->FRF.B.RNF   = fifoNullFramesRejected;
    eray->FRFM.B.MFID = frameIdFilter;
}


IFX_INLINE void IfxEray_setFifoMessageBufferConfigurations(Ifx_ERAY *eray, IfxEray_ReceiveChannel receiveChannel, boolean staticFifoDisabled, uint8 fifoDepth)
{
    eray->FRF.B.CH  = receiveChannel;
    eray->FRF.B.RSS = staticFifoDisabled;
    eray->FCL.U     = fifoDepth;
}


IFX_INLINE void IfxEray_setFirstDynamicBuffer(Ifx_ERAY *eray, uint8 firstDynamicBuffer)
{
    // 0: No static bufers, 0x01...0x7F: 0 to (MRC.B.FDB - 1) are static buffers, 0x80...0xFF:No dynamic buffers
    eray->MRC.B.FDB = firstDynamicBuffer;
}


IFX_INLINE void IfxEray_setListenTimeOuts(Ifx_ERAY *eray, uint32 listenTimeOut, IfxEray_ListenTimeOutNoise listenTimeOutNoise)
{
    Ifx_ERAY_SUCC2 succ2;
    succ2.U       = 0;
    succ2.B.LT    = listenTimeOut;
    succ2.B.LTN   = listenTimeOutNoise;
    eray->SUCC2.U = succ2.U;
}


IFX_INLINE void IfxEray_setMaxColdStartAttempts(Ifx_ERAY *eray, uint8 maxColdStartAttempts)
{
    eray->SUCC1.B.CSA = maxColdStartAttempts;
}


IFX_INLINE void IfxEray_setMaxCorrectionValues(Ifx_ERAY *eray, uint16 maxOffsetCorrection, uint16 maxRateCorrection)
{
    eray->GTUC10.B.MOC = maxOffsetCorrection;
    eray->GTUC10.B.MRC = maxRateCorrection;
}


IFX_INLINE void IfxEray_setMaxSynchFrames(Ifx_ERAY *eray, IfxEray_MaxSynchFrames maxSyncFrames)
{
    eray->GTUC02.B.SNM = maxSyncFrames;
}


IFX_INLINE void IfxEray_setMessageBufferCount(Ifx_ERAY *eray, uint8 numberOfMessageBuffers)
{
    eray->MRC.B.LCB = numberOfMessageBuffers - 1;
}


IFX_INLINE void IfxEray_setMessageHandlerConfigurations(Ifx_ERAY *eray, uint8 staticFramepayload, uint16 latestTransmissionStart)
{
    Ifx_ERAY_MHDC mhdc;
    mhdc.U       = 0;
    mhdc.B.SFDL  = staticFramepayload;
    mhdc.B.SLT   = latestTransmissionStart;
    eray->MHDC.U = mhdc.U;
}


IFX_INLINE void IfxEray_setNetworkStartIdleTime(Ifx_ERAY *eray, uint16 networkStartIdleTime)
{
    eray->GTUC04.B.NIT = networkStartIdleTime;
}


IFX_INLINE void IfxEray_setNetworkVectorLength(Ifx_ERAY *eray, uint32 networkVectorLength)
{
    eray->NEMC.U = networkVectorLength;
}


IFX_INLINE void IfxEray_setNodeChannels(Ifx_ERAY *eray, boolean channelAConnectedNode, boolean channelBConnectedNode)
{
    eray->SUCC1.B.CCHA = channelAConnectedNode;
    eray->SUCC1.B.CCHB = channelBConnectedNode;
}


IFX_INLINE void IfxEray_setOffsetCorrection(Ifx_ERAY *eray, uint16 correctionOffset)
{
    eray->GTUC04.B.OCS = correctionOffset;
}


IFX_INLINE void IfxEray_setReceiveRequest(Ifx_ERAY *eray, boolean receiveRequested)
{
    eray->OBCR.B.REQ = receiveRequested;
}


IFX_INLINE void IfxEray_setReceiveWakeupTimes(Ifx_ERAY *eray, uint16 receiveWakeupTestDuration, uint8 receiveWakeupIdleTime, uint8 receiveWakeupLowTime)
{
    eray->PRTC1.B.RXW = receiveWakeupTestDuration;
    eray->PRTC2.B.RXI = receiveWakeupIdleTime;
    eray->PRTC2.B.RXL = receiveWakeupLowTime;
}


IFX_INLINE void IfxEray_setRxBufferNumber(Ifx_ERAY *eray, uint8 bufferIndex)
{
    eray->OBCR.B.OBRS = bufferIndex;
}


IFX_INLINE void IfxEray_setSleepMode(Ifx_ERAY *eray, IfxEray_SleepMode mode)
{
    uint16 passwd = IfxScuWdt_getCpuWatchdogPassword();
    IfxScuWdt_clearCpuEndinit(passwd);
    eray->CLC.B.EDIS = mode;
    IfxScuWdt_setCpuEndinit(passwd);
}


IFX_INLINE void IfxEray_setSlotActionPoints(Ifx_ERAY *eray, uint8 staticActionPoint, uint8 dynamicActionPoint)
{
    eray->GTUC09.B.MAPO = dynamicActionPoint;
    eray->GTUC09.B.APO  = staticActionPoint;
}


IFX_INLINE void IfxEray_setStaticSlots(Ifx_ERAY *eray, uint16 staticSlotLength, uint16 staticSlotsCount)
{
    eray->GTUC07.B.SSL = staticSlotLength;
    eray->GTUC07.B.NSS = staticSlotsCount;
}


IFX_INLINE void IfxEray_setStrobePosition(Ifx_ERAY *eray, IfxEray_StrobePosition strobePosition)
{
    eray->PRTC1.B.SPP = strobePosition;
}


IFX_INLINE void IfxEray_setSuspendMode(Ifx_ERAY *eray, IfxEray_SuspendMode mode)
{
    Ifx_ERAY_OCS ocs;

    // remove protection and configure the suspend mode.
    ocs.B.SUS_P = 1;
    ocs.B.SUS   = mode;
    eray->OCS.U = ocs.U;
}


IFX_INLINE void IfxEray_setSymbolChannels(Ifx_ERAY *eray, boolean channelASymbolTransmitted, boolean channelBSymbolTransmitted)
{
    eray->SUCC1.B.MTSA = channelASymbolTransmitted;
    eray->SUCC1.B.MTSB = channelBSymbolTransmitted;
}


IFX_INLINE void IfxEray_setTransmissionSlotMode(Ifx_ERAY *eray, IfxEray_TransmissionSlotMode transmissionSlotMode)
{
    eray->SUCC1.B.TSM = transmissionSlotMode;
}


IFX_INLINE void IfxEray_setTransmissionStartTime(Ifx_ERAY *eray, uint8 transmissionStartTime)
{
    eray->PRTC1.B.TSST = transmissionStartTime;
}


IFX_INLINE void IfxEray_setTransmitRequest(Ifx_ERAY *eray, boolean transferRequested)
{
    eray->IBCM.B.STXRH = transferRequested;
}


IFX_INLINE void IfxEray_setTransmitWakeupTimes(Ifx_ERAY *eray, uint8 transmitWakeupRepetitions, uint8 transmitWakeupIdleTime, uint8 transmitWakeupLowTime)
{
    eray->PRTC1.B.RWP = transmitWakeupRepetitions;
    eray->PRTC2.B.TXI = transmitWakeupIdleTime;
    eray->PRTC2.B.TXL = transmitWakeupLowTime;
}


IFX_INLINE void IfxEray_setTransmittedFrames(Ifx_ERAY *eray, boolean startupFrameTransmitted, boolean synchFrameTransmitted)
{
    eray->SUCC1.B.TXST = startupFrameTransmitted;
    eray->SUCC1.B.TXSY = synchFrameTransmitted;
}


IFX_INLINE void IfxEray_setTxBufferNumber(Ifx_ERAY *eray, uint8 bufferIndex)
{
    eray->IBCR.B.IBRH = bufferIndex;
}


IFX_INLINE void IfxEray_setViewData(Ifx_ERAY *eray, boolean swapRequested)
{
    eray->OBCR.B.VIEW = swapRequested;
}


IFX_INLINE void IfxEray_setWakeupPatternChannel(Ifx_ERAY *eray, IfxEray_WakeupChannel wakeupPatternChannel)
{
    eray->SUCC1.B.WUCS = wakeupPatternChannel;
}


IFX_INLINE void IfxEray_waitForPocState(Ifx_ERAY *eray, IfxEray_PocState pocState)
{
    while (eray->CCSV.B.POCS != (uint8)pocState)
    {}
}


IFX_INLINE void IfxEray_initRxPinWithPadLevel(const IfxEray_Rxd_In *rx, IfxPort_InputMode rxMode, IfxPort_PadDriver padDriver)
{
    IfxPort_setPinModeInput(rx->pin.port, rx->pin.pinIndex, rxMode);
    IfxPort_setPinPadDriver(rx->pin.port, rx->pin.pinIndex, padDriver);

    if (rx->nodeId == IfxEray_NodeId_a)
    {
        rx->module->CUST1.B.RISA = rx->select;
    }
    else
    {
        rx->module->CUST1.B.RISB = rx->select;
    }
}


IFX_INLINE void IfxEray_selectRecieveInput(Ifx_ERAY *eray, IfxEray_NodeId nodeId, Ifx_RxSel select)
{
    if (nodeId == IfxEray_NodeId_a)
    {
        eray->CUST1.B.RISA = select;
    }
    else
    {
        eray->CUST1.B.RISB = select;
    }
}


IFX_INLINE void IfxEray_setPocCommand(Ifx_ERAY *eray, IfxEray_PocCommand cmd)
{
    eray->SUCC1.B.CMD = cmd;
}


IFX_INLINE boolean IfxEray_isRamsCleared(Ifx_ERAY *eray)
{
    return eray->MHDS.B.CRAM != 0;
}


IFX_INLINE boolean IfxEray_isPocBusy(Ifx_ERAY *eray)
{
    return eray->SUCC1.B.PBSY != 0;
}


IFX_INLINE void IfxEray_enableInterruptLine(Ifx_ERAY *eray, IfxEray_InterruptLine intLine)
{
    if (intLine == IfxEray_InterruptLine_0)
    {
        eray->ILE.B.EINT0 = 0x1U;
    }
    else
    {
        eray->ILE.B.EINT1 = 0x1U;
    }
}


IFX_INLINE void IfxEray_enableTransmitInterrupt(Ifx_ERAY *eray)
{
    eray->SIES.B.TXIE = 0x1U;
}


IFX_INLINE void IfxEray_enableAllErrorInterrupts(Ifx_ERAY *eray)
{
    eray->EIES.U = 0x07070FFFU;
}


IFX_INLINE void IfxEray_unlockTestModeKey(Ifx_ERAY *eray)
{
    eray->LCK.B.TMK = 0x75U;
    eray->LCK.B.TMK = 0x8AU;
}


IFX_INLINE void IfxEray_enableWriteTestRegister(Ifx_ERAY *eray)
{
    eray->TEST1.B.WRTEN = 0x1U;
}


IFX_INLINE void IfxEray_enableExternalLoopback(Ifx_ERAY *eray)
{
    eray->TEST1.B.ELBE = 0x1U;
}


IFX_INLINE void IfxEray_unlockConfigurationKey(Ifx_ERAY *eray)
{
    eray->LCK.B.CLK = 0xCE;
    eray->LCK.B.CLK = 0x31;
}


IFX_INLINE void IfxEray_configureSuc1Register(Ifx_ERAY *eray, uint32 configValue)
{
    eray->SUCC1.U = configValue;
}


IFX_INLINE void IfxEray_setMacroTickValue(Ifx_ERAY *eray, uint32 tickValue)
{
    eray->MTCCV.U = tickValue;
}


IFX_INLINE uint8 IfxEray_getCycleCountValue(Ifx_ERAY *eray)
{
    return (uint8)eray->MTCCV.B.CCV;
}


#endif /* IFXERAY_H */
