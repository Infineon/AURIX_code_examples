/**
 * \file IfxQspi.h
 * \brief QSPI  basic functionality
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
 * \defgroup IfxLld_Qspi_Std_Enum Enumerations
 * \ingroup IfxLld_Qspi_Std
 * \defgroup IfxLld_Qspi_Std_Operative Operative Functions
 * \ingroup IfxLld_Qspi_Std
 * \defgroup IfxLld_Qspi_Std_Support Support Functions
 * \ingroup IfxLld_Qspi_Std
 * \defgroup IfxLld_Qspi_Std_Interrupt Interrupt Functions
 * \ingroup IfxLld_Qspi_Std
 * \defgroup IfxLld_Qspi_Std_IO IO Pin Configuration Functions
 * \ingroup IfxLld_Qspi_Std
 */

#ifndef IFXQSPI_H
#define IFXQSPI_H 1

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include "_Impl/IfxQspi_cfg.h"
#include "Cpu/Std/IfxCpu_Intrinsics.h"
#include "Scu/Std/IfxScuCcu.h"
#include "Src/Std/IfxSrc.h"
#include "_PinMap/IfxQspi_PinMap.h"

/******************************************************************************/
/*-----------------------------------Macros-----------------------------------*/
/******************************************************************************/

/** \brief Get Fifo size required for Long / Long continous mode interms 32-bit
 * LONG MODE FIFO size (data size in bytes) = (size for Bacon) + (Datasize converted to 32-bit)
 */
#define IFXQSPI_BACONSIZE(Datasize)           (((((Datasize) % 16) == 0) ? ((uint8)((Datasize) / 16)) : ((uint8)((Datasize) / 16) + 1)))

#define IFXQSPI_FIFO32BITSIZE(Datasize)       ((((Datasize) % 4) == 0) ? ((uint8)((Datasize) / 4)) : ((uint8)((Datasize) / 4) + 1))

#define IFXQSPI_GETLONGMODEFIFOSIZE(Datasize) (IFXQSPI_BACONSIZE(Datasize) + IFXQSPI_FIFO32BITSIZE(Datasize))

/** \brief Errors enable mask for ERRORENS
 */
#define IFXQSPI_ERRORENABLEMASK ((uint32)0x1FF)

/******************************************************************************/
/*--------------------------------Enumerations--------------------------------*/
/******************************************************************************/

/** \addtogroup IfxLld_Qspi_Std_Enum
 * \{ */
#if defined(DEVICE_TC33XED) || defined(DEVICE_TC33X) || defined(DEVICE_TC35X) || defined(DEVICE_TC39XB)
/** \brief CAPCON Register Edge Configuration (CAPCON.EDGECON)
 */
typedef enum
{
    IfxQspi_CaptureControlEdgeConfiguration_rrMode = 0,  /**< \brief RR mode (rising edge to rising edge) */
    IfxQspi_CaptureControlEdgeConfiguration_rfMode = 1,  /**< \brief RF mode (rising edge to falling edge) */
    IfxQspi_CaptureControlEdgeConfiguration_frMode = 2,  /**< \brief FR mode (falling edge to rising edge) */
    IfxQspi_CaptureControlEdgeConfiguration_ffMode = 3   /**< \brief FF mode (falling edge to falling edge) */
} IfxQspi_CaptureControlEdgeConfiguration;

/** \brief CAPCON Input Seletion line (CAPCON.INS)
 */
typedef enum
{
    IfxQspi_CaptureControlInputSelection_inputA = 0,  /**< \brief INA selected */
    IfxQspi_CaptureControlInputSelection_inputB = 1,  /**< \brief INB selected */
    IfxQspi_CaptureControlInputSelection_inputC = 2,  /**< \brief INC selected */
    IfxQspi_CaptureControlInputSelection_inputD = 3   /**< \brief IND selected */
} IfxQspi_CaptureControlInputSelection;
#endif

/** \brief QSPI channel Number (BACON.CS)
 */
typedef enum
{
    IfxQspi_ChannelId_0,     /**< \brief Channel #0  */
    IfxQspi_ChannelId_1,     /**< \brief Channel #1  */
    IfxQspi_ChannelId_2,     /**< \brief Channel #2  */
    IfxQspi_ChannelId_3,     /**< \brief Channel #3  */
    IfxQspi_ChannelId_4,     /**< \brief Channel #4  */
    IfxQspi_ChannelId_5,     /**< \brief Channel #5  */
    IfxQspi_ChannelId_6,     /**< \brief Channel #6  */
    IfxQspi_ChannelId_7,     /**< \brief Channel #7  */
    IfxQspi_ChannelId_8,     /**< \brief Channel #8  */
    IfxQspi_ChannelId_9,     /**< \brief Channel #9  */
    IfxQspi_ChannelId_10,    /**< \brief Channel #10  */
    IfxQspi_ChannelId_11,    /**< \brief Channel #11  */
    IfxQspi_ChannelId_12,    /**< \brief Channel #12  */
    IfxQspi_ChannelId_13,    /**< \brief Channel #13  */
    IfxQspi_ChannelId_14,    /**< \brief Channel #14  */
    IfxQspi_ChannelId_15     /**< \brief Channel #15  */
} IfxQspi_ChannelId;

/** \brief Data length unit of a frame (BACON.BYTE)
 */
typedef enum
{
    IfxQspi_DataLengthUnit_bit  = 0, /**< \brief Data Length in Bits */
    IfxQspi_DataLengthUnit_byte = 1  /**< \brief Data length in Bytes */
} IfxQspi_DataLengthUnit;

/** \brief Length of Delay for Idle, Leading and Trailing Delays
 * Length in TPER units. Length = Value + 1. Refer Figure "Calculation of the delays".
 * Definition in BACON.B.IDLE, BACON.B.LEAD and BACON.B.TRAIL
 */
typedef enum
{
    IfxQspi_DelayLength_1 = 0,  /**< \brief length of 1 TPER unit */
    IfxQspi_DelayLength_2 = 1,  /**< \brief length of 2 TPER units */
    IfxQspi_DelayLength_3 = 2,  /**< \brief length of 3 TPER units */
    IfxQspi_DelayLength_4 = 3,  /**< \brief length of 4 TPER units */
    IfxQspi_DelayLength_5 = 4,  /**< \brief length of 5 TPER units */
    IfxQspi_DelayLength_6 = 5,  /**< \brief length of 6 TPER units */
    IfxQspi_DelayLength_7 = 6,  /**< \brief length of 7 TPER units */
    IfxQspi_DelayLength_8 = 7   /**< \brief length of 8 TPER units */
} IfxQspi_DelayLength;

/** \brief Prescalar for Delay Parameters (Idle Delay, Leading Delay and Trailing Delay)
 * Length in TPER units. Prescalar = 4^(Value). Refer Figure "Calculation of the delays".
 * Definition in BACON.B.IPRE, BACON.B.LPRE and BACON.B.TPRE
 */
typedef enum
{
    IfxQspi_DelayPrescalar_1     = 0, /**< \brief prescalar of 1 */
    IfxQspi_DelayPrescalar_4     = 1, /**< \brief prescalar of 4 */
    IfxQspi_DelayPrescalar_16    = 2, /**< \brief prescalar of 16 */
    IfxQspi_DelayPrescalar_64    = 3, /**< \brief prescalar of 64 */
    IfxQspi_DelayPrescalar_256   = 4, /**< \brief prescalar of 256 */
    IfxQspi_DelayPrescalar_1024  = 5, /**< \brief prescalar of 1024 */
    IfxQspi_DelayPrescalar_4096  = 6, /**< \brief prescalar of 4096 */
    IfxQspi_DelayPrescalar_16384 = 7  /**< \brief prescalar of 16384 */
} IfxQspi_DelayPrescalar;

/** \brief QSPI Error Flags (STATUS.ERRORFLAGS)
 */
typedef enum
{
    IfxQspi_Error_none                      = 0,   /**< \brief No Error */
    IfxQspi_Error_parity                    = 1,   /**< \brief Parity Error */
    IfxQspi_Error_configuration             = 2,   /**< \brief Configuration Error */
    IfxQspi_Error_baudrate                  = 4,   /**< \brief BaudRate Error */
    IfxQspi_Error_txfifoOverflow            = 8,   /**< \brief TX FIFO Overflow Error */
    IfxQspi_Error_txfifoUnderflow           = 16,  /**< \brief TX FIFO Underflow Error */
    IfxQspi_Error_rxfifoOverflow            = 32,  /**< \brief RX FIFO Overflow Error */
    IfxQspi_Error_rxfifoUnderflow           = 64,  /**< \brief RX FIFO Underflow Error */
    IfxQspi_Error_expectTimeout             = 128, /**< \brief EXPECT Timeout Error */
    IfxQspi_Error_slsiMisplacedInactivation = 256  /**< \brief SLSI misplaced inactivation (slave mode) */
} IfxQspi_Error;

/** \brief Frame Expect phase time out value
 */
typedef enum
{
    IfxQspi_ExpectTimeout_64      = 0,   /**< \brief Expect phse time out 64 */
    IfxQspi_ExpectTimeout_128     = 1,   /**< \brief Expect phse time out 128 */
    IfxQspi_ExpectTimeout_256     = 2,   /**< \brief Expect phse time out 256 */
    IfxQspi_ExpectTimeout_512     = 3,   /**< \brief Expect phse time out 512 */
    IfxQspi_ExpectTimeout_1024    = 4,   /**< \brief Expect phse time out 1024 */
    IfxQspi_ExpectTimeout_2048    = 5,   /**< \brief Expect phse time out 2048 */
    IfxQspi_ExpectTimeout_4096    = 6,   /**< \brief Expect phse time out 4096 */
    IfxQspi_ExpectTimeout_8192    = 7,   /**< \brief Expect phse time out 8192 */
    IfxQspi_ExpectTimeout_16384   = 8,   /**< \brief Expect phse time out 16384 */
    IfxQspi_ExpectTimeout_32768   = 9,   /**< \brief Expect phse time out 32768 */
    IfxQspi_ExpectTimeout_65536   = 10,  /**< \brief Expect phse time out 65536 */
    IfxQspi_ExpectTimeout_131072  = 11,  /**< \brief Expect phse time out 131072 */
    IfxQspi_ExpectTimeout_262144  = 12,  /**< \brief Expect phse time out 262144 */
    IfxQspi_ExpectTimeout_524288  = 13,  /**< \brief Expect phse time out 524288 */
    IfxQspi_ExpectTimeout_1048576 = 14,  /**< \brief Expect phse time out 1048576 */
    IfxQspi_ExpectTimeout_2097152 = 15   /**< \brief Expect phse time out 2097152 */
} IfxQspi_ExpectTimeout;

/** \brief QSPI controller mode (GLOBALCON.MODE)
 */
typedef enum
{
    IfxQspi_Mode_master      = 0,  /**< \brief QSPI in "master" mode */
    IfxQspi_Mode_pwmOverQspi = 1,  /**< \brief QSPI in "PWM over QSPI" mode */
    IfxQspi_Mode_slave       = 2   /**< \brief QSPI in "slave" mode */
} IfxQspi_Mode;

/** \brief Request between pause and Run transition
 */
typedef enum
{
    IfxQspi_PauseRunTransition_pause = 0,  /**< \brief Request value for pause */
    IfxQspi_PauseRunTransition_run   = 1   /**< \brief Request value for Run */
} IfxQspi_PauseRunTransition;

/** \brief QSPI frame phase (STATUS.PHASE)
 */
typedef enum
{
    IfxQspi_Phase_wait        = 0, /**< \brief Frame wait phase */
    IfxQspi_Phase_idleA       = 1, /**< \brief Frame idleA phase */
    IfxQspi_Phase_idleB       = 2, /**< \brief frame idleB phase */
    IfxQspi_Phase_lead        = 3, /**< \brief Frame lead phase */
    IfxQspi_Phase_data        = 4, /**< \brief Frame data phase */
    IfxQspi_Phase_trail       = 5, /**< \brief Frame trail phase */
    IfxQspi_Phase_expect      = 6, /**< \brief Frame expect phase */
    IfxQspi_Phase_leadStrobe  = 7, /**< \brief Frame leadstrobe phase */
    IfxQspi_Phase_trailStrobe = 8  /**< \brief Frame trailstrobe phase */
} IfxQspi_Phase;

/** \brief Phase Transition Event (GLOBALCON1.B.PT1 and GLOBALCON1.B.PT2)
 */
typedef enum
{
    IfxQspi_PhaseTransitionEvent_endOfWait                 = 0,  /**< \brief BUSY (end of WAIT phase) */
    IfxQspi_PhaseTransitionEvent_serialClockPolarityChange = 1,  /**< \brief SCLKPC (serial clock polarity change) */
    IfxQspi_PhaseTransitionEvent_startOfFrame              = 2,  /**< \brief SOF (Start Of Frame ) */
    IfxQspi_PhaseTransitionEvent_transmitBufferEmptied     = 3,  /**< \brief TBE (Transmit Buffer Emptied) */
    IfxQspi_PhaseTransitionEvent_receiveBufferFilled       = 4,  /**< \brief RBF (Receive Buffer Filled) */
    IfxQspi_PhaseTransitionEvent_endOfFrame                = 5,  /**< \brief EOF (End of Frame) */
    IfxQspi_PhaseTransitionEvent_dataNotAvailable          = 6,  /**< \brief DNA (Data not Available = Start of Expect) */
    IfxQspi_PhaseTransitionEvent_endOfExpect               = 7   /**< \brief CONT (End of EXPECT phase) */
} IfxQspi_PhaseTransitionEvent;

/** \brief Reset Request (GLOBALCON.RESETS)
 */
typedef enum
{
    IfxQspi_Reset_none                = 0,  /**< \brief No Reset */
    IfxQspi_Reset_stateMachineAndFifo = 1,  /**< \brief State Machine, TXFIFO and RXFIFO reset, registers not reseted */
    IfxQspi_Reset_registers           = 2,  /**< \brief Registers Reset */
    IfxQspi_Reset_kernel              = 3   /**< \brief Kernel / Module Reset */
} IfxQspi_Reset;

/** \brief Receive Fifo Interrupt Threshold (GLOBALCON1.B.RXFIFOINT)
 */
typedef enum
{
    IfxQspi_RxFifoInt_0,     /**< \brief RxFifo Interrupt Threshold  #0  */
    IfxQspi_RxFifoInt_1,     /**< \brief RxFifo Interrupt Threshold  #1  */
    IfxQspi_RxFifoInt_2,     /**< \brief RxFifo Interrupt Threshold  #2  */
    IfxQspi_RxFifoInt_3      /**< \brief RxFifo Interrupt Threshold  #3  */
} IfxQspi_RxFifoInt;

/** \brief Enable/disable the sensitivity of the module to sleep signal\n
 * Definition in Ifx_QSPI.CLC.B.EDIS
 */
typedef enum
{
    IfxQspi_SleepMode_enable  = 0, /**< \brief Sleep Mode enabled */
    IfxQspi_SleepMode_disable = 1  /**< \brief Sleep Mode disabled */
} IfxQspi_SleepMode;

/** \brief STROBE delay for SLSO in delayed mode (GLOBALCON.STROBE)
 */
typedef enum
{
    IfxQspi_StrobeDelay_1,     /**< \brief SLSO delay 1 cycle(s)  */
    IfxQspi_StrobeDelay_2,     /**< \brief SLSO delay 2 cycle(s)  */
    IfxQspi_StrobeDelay_3,     /**< \brief SLSO delay 3 cycle(s)  */
    IfxQspi_StrobeDelay_4,     /**< \brief SLSO delay 4 cycle(s)  */
    IfxQspi_StrobeDelay_5,     /**< \brief SLSO delay 5 cycle(s)  */
    IfxQspi_StrobeDelay_6,     /**< \brief SLSO delay 6 cycle(s)  */
    IfxQspi_StrobeDelay_7,     /**< \brief SLSO delay 7 cycle(s)  */
    IfxQspi_StrobeDelay_8,     /**< \brief SLSO delay 8 cycle(s)  */
    IfxQspi_StrobeDelay_9,     /**< \brief SLSO delay 9 cycle(s)  */
    IfxQspi_StrobeDelay_10,    /**< \brief SLSO delay 10 cycle(s)  */
    IfxQspi_StrobeDelay_11,    /**< \brief SLSO delay 11 cycle(s)  */
    IfxQspi_StrobeDelay_12,    /**< \brief SLSO delay 12 cycle(s)  */
    IfxQspi_StrobeDelay_13,    /**< \brief SLSO delay 13 cycle(s)  */
    IfxQspi_StrobeDelay_14,    /**< \brief SLSO delay 14 cycle(s)  */
    IfxQspi_StrobeDelay_15,    /**< \brief SLSO delay 15 cycle(s)  */
    IfxQspi_StrobeDelay_16,    /**< \brief SLSO delay 16 cycle(s)  */
    IfxQspi_StrobeDelay_17,    /**< \brief SLSO delay 17 cycle(s)  */
    IfxQspi_StrobeDelay_18,    /**< \brief SLSO delay 18 cycle(s)  */
    IfxQspi_StrobeDelay_19,    /**< \brief SLSO delay 19 cycle(s)  */
    IfxQspi_StrobeDelay_20,    /**< \brief SLSO delay 20 cycle(s)  */
    IfxQspi_StrobeDelay_21,    /**< \brief SLSO delay 21 cycle(s)  */
    IfxQspi_StrobeDelay_22,    /**< \brief SLSO delay 22 cycle(s)  */
    IfxQspi_StrobeDelay_23,    /**< \brief SLSO delay 23 cycle(s)  */
    IfxQspi_StrobeDelay_24,    /**< \brief SLSO delay 24 cycle(s)  */
    IfxQspi_StrobeDelay_25,    /**< \brief SLSO delay 25 cycle(s)  */
    IfxQspi_StrobeDelay_26,    /**< \brief SLSO delay 26 cycle(s)  */
    IfxQspi_StrobeDelay_27,    /**< \brief SLSO delay 27 cycle(s)  */
    IfxQspi_StrobeDelay_28,    /**< \brief SLSO delay 28 cycle(s)  */
    IfxQspi_StrobeDelay_29,    /**< \brief SLSO delay 29 cycle(s)  */
    IfxQspi_StrobeDelay_30,    /**< \brief SLSO delay 30 cycle(s)  */
    IfxQspi_StrobeDelay_31,    /**< \brief SLSO delay 31 cycle(s)  */
    IfxQspi_StrobeDelay_32     /**< \brief SLSO delay 32 cycle(s)  */
} IfxQspi_StrobeDelay;

/** \brief Transmit Fifo Interrupt Threshold (GLOBALCON1.B.TXFIFOINT)
 */
typedef enum
{
    IfxQspi_TxFifoInt_1,     /**< \brief TxFifo Interrupt Threshold  #1  */
    IfxQspi_TxFifoInt_2,     /**< \brief TxFifo Interrupt Threshold  #2  */
    IfxQspi_TxFifoInt_3,     /**< \brief TxFifo Interrupt Threshold  #3  */
    IfxQspi_TxFifoInt_4      /**< \brief TxFifo Interrupt Threshold  #4  */
} IfxQspi_TxFifoInt;

/** \} */

/** \brief Transmit FIFO mode (GLOBALCON1.B.TXFM)
 */
typedef enum
{
    IfxQspi_FifoMode_combinedMove = 0,  /**< \brief Combined Move Mode */
    IfxQspi_FifoMode_singleMove   = 1,  /**< \brief Single Move Mode */
    IfxQspi_FifoMode_batchMove    = 2   /**< \brief Batch Move Mode */
} IfxQspi_FifoMode;

/** \brief OCDS Suspend Control (OCDS.SUS)
 */
typedef enum
{
    IfxQspi_SuspendMode_none = 0,  /**< \brief No suspend */
    IfxQspi_SuspendMode_hard = 1,  /**< \brief Hard Suspend */
    IfxQspi_SuspendMode_soft = 2   /**< \brief Soft Suspend */
} IfxQspi_SuspendMode;

/** \brief SPI Interface Status */
typedef enum
{
    IfxQspi_Status_ok,
    IfxQspi_Status_busy,
    IfxQspi_Status_unknown
} IfxQspi_Status;

/** \brief Slave select output timing */
typedef enum
{
    IfxQspi_SlsoTiming_0 = 0,             /**< zero delay clock */
    IfxQspi_SlsoTiming_1,                 /**< 1 half-clock delay */
    IfxQspi_SlsoTiming_2,                 /**< 2 half-clock delay */
    IfxQspi_SlsoTiming_3,                 /**< 3 half-clock delay */
    IfxQspi_SlsoTiming_4,                 /**< 4 half-clock delay */
    IfxQspi_SlsoTiming_5,                 /**< 5 half-clock delay */
    IfxQspi_SlsoTiming_6,                 /**< 6 half-clock delay */
    IfxQspi_SlsoTiming_7                  /**< 7 half-clock delay */
} IfxQspi_SlsoTiming;

/** \brief Heading (BACON.B.MSB) */
typedef enum
{
    IfxQspi_DataHeading_lsbFirst = 0,     /**< LSB first */
    IfxQspi_DataHeading_msbFirst          /**< MSB first */
} IfxQspi_DataHeading;

/** \brief Clock phase (ECON.B.CPH) */
typedef enum
{
    IfxQspi_ShiftClock_shiftTransmitDataOnLeadingEdge = 0,    /**< Shift Tx data on leading edge */
    IfxQspi_ShiftClock_shiftTransmitDataOnTrailingEdge        /**< Shift Tx data on training edge */
} IfxQspi_ShiftClock;

/** \brief Clock polarity (ECON.B.CPOL) */
typedef enum
{
    IfxQspi_ClockPolarity_idleLow = 0,    /**< Idle clock line is low */
    IfxQspi_ClockPolarity_idleHigh        /**< Idle clock line is high */
} IfxQspi_ClockPolarity;

/** \brief Parity Mode\n (ECON.B.PAREN)*/
typedef enum
{
	IfxQspi_ParityMode_even = 0,  /**< \brief Even Parity */
	IfxQspi_ParityMode_odd  = 1   /**< \brief Odd Parity */
} IfxQspi_ParityMode;

/******************************************************************************/
/*-----------------------------Data Structures--------------------------------*/
/******************************************************************************/

/** \brief Structure holding the "pre" and "delay" values.
 * To be populated into BACON register after delay calculation.
 */
typedef struct
{
    uint8 pre;         /**< \brief specifies the prescalar value. Range: 0 to 7. */
    uint8 delay;       /**< \brief delay multiplier. Range: 0 to 7. */
} IfxQspi_DelayConst;

/** \brief Delay Parameters for Idle, Leading and Trailing Delays
 * To be populated into BACON register and handle after delay calculation by application.
 */
typedef struct
{
    IfxQspi_DelayPrescalar idlePrescalar;           /**< \brief prescalar value for Idle delay */
    IfxQspi_DelayLength    idleDelay;               /**< \brief length of Idle delay */
    IfxQspi_DelayPrescalar leadingPrescalar;        /**< \brief prescalar value for Leading delay */
    IfxQspi_DelayLength    leadingDelay;            /**< \brief length of Leading delay */
    IfxQspi_DelayPrescalar trailingPrescalar;       /**< \brief prescalar value for Trailing delay */
    IfxQspi_DelayLength    trailingDelay;           /**< \brief length of Trailing delay */
} IfxQspi_DelayParameters;

/** \addtogroup IfxLld_Qspi_Std_Operative
 * \{ */

/** \brief Typedef for slso timing
 */
typedef uint32 IfxQspi_SlsoTiming_HalfTsclk;

/** \brief Qspi channel data access flags
 */
typedef volatile struct
{
    boolean onTransfer;              /**< \brief Channel status: On transfer. Range: TRUE transfer as active, FALSE transfer as inactive. */
    boolean byteAccess;              /**< \brief Channel status: 8bit / 16 bit access */
} IfxQspi_Flags;

/** \brief Qspi excgange error checks
 */
typedef struct
{
    boolean baudrate;                /**< \brief TRUE = checked, FALSE = ignored */
    boolean phase;                   /**< \brief TRUE = checked, FALSE = ignored */
    boolean receive;                 /**< \brief TRUE = checked, FALSE = ignored */
    boolean transmit;                /**< \brief TRUE = checked, FALSE = ignored */
} IfxQspi_ErrorChecks;

/** \brief Qspi master/slave channel modes
 */
typedef struct
{
    IfxQspi_SlsoTiming_HalfTsclk  csInactiveDelay;         /**< \brief CS Inactive Delay in Tsclk/2 units */
    IfxQspi_SlsoTiming_HalfTsclk  csLeadDelay;             /**< \brief CS Lead Delay in Tsclk/2 units */
    IfxQspi_SlsoTiming_HalfTsclk  csTrailDelay;            /**< \brief CS Trail Delay in Tsclk/2 units */
    boolean enabled;                 /**< \brief 1 = channel enabled, 0 = channel disabled */
    boolean autoCS;                  /**< \brief 1 = chip select is controlled by the hardware module or, 0 = by software. */
    boolean loopback;                /**< \brief 0 = normal mode, 1 = loopback mode. In loopback mode, channel 0 is selected as default */
    boolean clockPolarity;           /**< \brief \ref IfxQspi_ClockPolarity*/
    boolean shiftClock;              /**< \brief \ref IfxQspi_ShiftClock */
    boolean dataHeading;             /**< \brief \ref IfxQspi_DataHeading */
    uint8   dataWidth;               /**< \brief range 2 .. 32 bits (note 2 = 2-bits, 3 = 3-bits ... */
    boolean csActiveLevel;           /**< \brief \ref Ifx_ActiveState */
    boolean parityCheck;             /**< \brief 0 = disabled, 1 = enabled */
    boolean parityMode;              /**< \brief \ref IfxQspi_ParityMode */
}IfxQspi_chMode;

/** \brief Qspi basic master/slave channel configuration
 */
typedef struct
{
    float32               baudrate;      /**< \brief Specifies the SPI baudrate */
    IfxQspi_chMode        mode;          /**< \brief channel mode */
    IfxQspi_ErrorChecks   errorChecks;   /**< \brief error checks */
	IfxQspi_ChannelId     channelId;     /**< \brief channel identification number for the qspi channel */
}IfxQspi_chConfig;

/** \brief Qspi transmit/receive job parameters
 */
typedef struct
{
    void     *data;                      /**< \ data pointer     */
    Ifx_SizeT remaining;                 /**< \ data left to transfer  */
} IfxQspi_Job;

/******************************************************************************/
/*-------------------------Inline Function Prototypes-------------------------*/
/******************************************************************************/

/**
 * \brief Clears all event flags for the QSPI module.
 *
 * \param[inout] qspi Pointer to the QSPI module registers.
 *
 * \retval None
 * 
 */
IFX_INLINE void IfxQspi_clearAllEventFlags(Ifx_QSPI *qspi);

/**
 * \brief Clears the move counter interrupt after the last flag has been set.
 *
 * \param[inout] qspi           Pointer to the QSPI module registers.
 * \param[in]    clearInterrupt Boolean flag indicating whether to clear the interrupt.
 *                              TRUE if Clears the interrupt flag, FALSE if Does not clear the interrupt flag.
 *
 * \retval None
 *
 */
IFX_INLINE void IfxQspi_clearMoveCounterInterruptAfterLastFlag(Ifx_QSPI *qspi, boolean clearInterrupt);

/**
 * \brief Clears the interrupt before last flag for the QSPI module.
 * 
 * \param[inout] qspi           Pointer to the QSPI module registers.
 * \param[in]    clearInterrupt Boolean flag indicating whether to clear the interrupt.
 *                              TRUE if Clears the interrupt flag, FALSE if Does not clear the interrupt flag.
 *
 * \retval None
 * 
 */
IFX_INLINE void IfxQspi_clearMoveCounterInterruptBeforeLastFlag(Ifx_QSPI *qspi, boolean clearInterrupt);

/**
 * \brief Clears the receive (RX) service request for the QSPI module.
 *
 * \param[inout] qspi Pointer to the QSPI module registers.
 *
 * \retval None
 *
 */
IFX_INLINE void IfxQspi_clearRxReq(Ifx_QSPI *qspi);

/**
 * \brief Clears the transmit (TX) service requests for the QSPI module.
 *
 * \param[inout] qspi Pointer to the QSPI module registers.
 *
 * \retval None
 * 
 */
IFX_INLINE void IfxQspi_clearTxReq(Ifx_QSPI *qspi);

/** \brief Clear PT1 service requests.
 *
 * \param[inout] qspi Pointer to QSPI module registers.
 *
 * \retval None
 */
IFX_INLINE void IfxQspi_clearPt1Req(Ifx_QSPI *qspi);

/** \brief Clear PT2 service requests.
 *
 * \param[inout] qspi Pointer to QSPI module registers.
 *
 * \retval None
 */
IFX_INLINE void IfxQspi_clearPt2Req(Ifx_QSPI *qspi);

/** \brief Clear User event flag clear service requests.
 *
 * \param[inout] qspi Pointer to QSPI module registers.
 *
 * \retval None
 */
IFX_INLINE void IfxQspi_clearUsrReq(Ifx_QSPI *qspi);
/**
 * \brief Configures the PT1 event (also serves as the USR event if USREN=1) for the QSPI module.
 *
 * \param[inout] qspi      Pointer to the QSPI module registers.
 * \param[in]    pt1Config Specifies the Phase Transition Event configuration. Range: \ref IfxQspi_PhaseTransitionEvent.
 *
 * \retval None
 *
 */
IFX_INLINE void IfxQspi_configPT1Event(Ifx_QSPI *qspi, IfxQspi_PhaseTransitionEvent pt1Config);

/**
 * \brief Configures the Phase Transition 2 (PT2) event for the QSPI module.
 *
 * \param[inout] qspi      Pointer to the QSPI module registers.
 * \param[in]    pt2Config The configuration for the Phase Transition 2 event. Range: \ref IfxQspi_PhaseTransitionEvent.
 *
 * \retval None
 *
 */
IFX_INLINE void IfxQspi_configPT2Event(Ifx_QSPI *qspi, IfxQspi_PhaseTransitionEvent pt2Config);

#if defined(DEVICE_TC33XED) || defined(DEVICE_TC33X) || defined(DEVICE_TC35X) || defined(DEVICE_TC39XB)

/** \brief Configure Capcon register (Edge Configuration, input selection and capture interrupt select bit).
 *
 * \param[inout] qspi              Pointer to the QSPI module registers.
 * \param[in]    inputSel          Input port Selection. Range: \ref IfxQspi_CaptureControlInputSelection.
 * \param[in]    edgeConfiguration Edge configuration / capture mode. Range: \ref IfxQspi_CaptureControlEdgeConfiguration.
 *
 * \retval None
 *
 */
IFX_INLINE void IfxQspi_configureCapcon(Ifx_QSPI *qspi, IfxQspi_CaptureControlInputSelection inputSel, IfxQspi_CaptureControlEdgeConfiguration edgeConfiguration);
#endif

/**
 * \brief Enables or disables the loopback mode for the QSPI module.
 * 
 * \param[inout] qspi   Pointer to the QSPI module registers.
 * \param[in]    enable Boolean flag to enable (TRUE) or disable (FALSE) the loopback mode.
 *
 * \retval None
 * 
 */
IFX_INLINE void IfxQspi_enableLoopbackMode(Ifx_QSPI *qspi, boolean enable);

/**
 * \brief Enables or disables the Phase Transition 1 (PT1) event for the QSPI module.
 *
 * \param[inout] qspi   Pointer to the QSPI module registers.
 * \param[in]    enable Boolean value indicating whether to enable (1) or disable (0)
 *                      the PT1 event.
 *
 * \retval None
 * 
 */
IFX_INLINE void IfxQspi_enablePT1Event(Ifx_QSPI *qspi, boolean enable);

/**
 * \brief Enables or disables the Phase Transition 2 (PT2) event for the QSPI module.
 * 
 * \param[inout] qspi   Pointer to the QSPI module registers.
 * \param[in]    enable Boolean flag to enable (1) or disable (0) the PT2 event.
 * 
 * \retval None
 * 
 */
IFX_INLINE void IfxQspi_enablePT2Event(Ifx_QSPI *qspi, boolean enable);

/**
 * \brief Enables or disables the user event triggered by PT1.
 *
 * \param[inout] qspi   Pointer to the QSPI module registers.
 * \param[in]    enable Boolean flag to enable (true) or disable (false) the user event.
 *
 * \retval None
 *
 */
IFX_INLINE void IfxQspi_enableUsrEvent(Ifx_QSPI *qspi, boolean enable);

/**
 * \brief Retrieves the current error flags for the QSPI module.
 *
 * \param[in] qspi Pointer to the QSPI module registers.
 *
 * \retval uint16 A 16-bit value representing the current error flags.
 *                Range:
 *                - 0x001 Parity Error,
 *                - 0x002 Unexpected Configuration Error,
 *                - 0x004 Baud Rate Error (slave mode),
 *                - 0x008 TXFIFO overflow (software error),
 *                - 0x010 TXFIFO underflow (slave mode),
 *                - 0x020 RXFIFO overflow,
 *                - 0x040 RXFIFO underflow (software error),
 *                - 0x080 EXPECT time out error,
 *                - 0x100 SLSI misplaced inactivation (slave mode).
 *
 */
IFX_INLINE uint16 IfxQspi_getErrorFlags(Ifx_QSPI *qspi);

/** \brief Returns the transmit request status.
*
* \param[in] qspi Pointer to QSPI module registers.
*
* \retval TRUE If a transmit request is pending.
*         FALSE If no transmit request is pending.
*/
IFX_INLINE boolean IfxQspi_getTxReqStatus(Ifx_QSPI *qspi);

/** \brief Returns the receive request status.
*
* \param[in] qspi Pointer to QSPI module registers.
*
* \retval TRUE If a receive request is pending.
*         FALSE If no receive request is pending.
*/
IFX_INLINE boolean IfxQspi_getRxReqStatus(Ifx_QSPI *qspi);

/** \brief Returns the phase transition 1 flag status.
*
* \param[in] qspi Pointer to QSPI module registers.
*
* \retval TRUE If a phase transition 1 event has occurred.
*         FALSE If no phase transition 1 event has occurred.
*/
IFX_INLINE boolean IfxQspi_getPt1Status(Ifx_QSPI *qspi);

/** \brief Returns the phase transition 2 flag status.
*
* \param[in] qspi Pointer to QSPI module registers.
*
* \retval TRUE If a phase transition 2 event has occurred.
*         FALSE If no phase transition 2 event has occurred.
*/
IFX_INLINE boolean IfxQspi_getPt2Status(Ifx_QSPI *qspi);

/** \brief Returns the user request flag status.
*
* \param[in] qspi Pointer to QSPI module registers.
*
* \retval TRUE If a user request event has occurred.
*         FALSE If no user request event has occurred.
*/
IFX_INLINE boolean IfxQspi_getUsrReqStatus(Ifx_QSPI *qspi);

/**
 * \brief Requests the QSPI module to enter a paused state.
 * no interrupts
 * no communication
 *
 * \param[inout] qspi Pointer to the QSPI module registers.
 * 
 * \retval None
 * 
 */
IFX_INLINE void IfxQspi_pause(Ifx_QSPI *qspi);

/**
 * \brief Reads the oldest data from the Receive FIFO (RXFIFO) of the QSPI module.
 *
 * \param[in] qspi Pointer to the QSPI module registers.
 *
 * \retval uint32 The data read from the RXFIFO. Range: 0 to 0xFFFF FFFF.
 *
 */
IFX_INLINE uint32 IfxQspi_readReceiveFifo(Ifx_QSPI *qspi);

/**
 * \brief Requests a reset of specific QSPI module components.
 *
 * \param[inout] qspi Pointer to the QSPI module registers.
 * \param[in]    reset Type of reset to perform. Range: \ref IfxQspi_Reset.
 *
 * \retval None
 *
 */
IFX_INLINE void IfxQspi_requestReset(Ifx_QSPI *qspi, IfxQspi_Reset reset);

/**
 * \brief Requests the QSPI module to transition into the Run state.
 *
 * \param[inout] qspi Pointer to the QSPI module registers.
 *
 * \retval None
 *
 */
IFX_INLINE void IfxQspi_run(Ifx_QSPI *qspi);

/**
 * \brief Enable or disable the interrupt after the last byte has been transferred.
 *
 * \param[inout] qspi             Pointer to the QSPI module registers.
 * \param[in]    interruptEnabled Boolean flag to enable (true) or disable (false) the interrupt after the last byte.
 *
* \retval None
*
 */
IFX_INLINE void IfxQspi_setMoveCounterInterruptAfterLastEnabled(Ifx_QSPI *qspi, boolean interruptEnabled);

/**
 * \brief Configures the QSPI module to generate an interrupt after the last flag is set.
 *
 * \param[inout] qspi         Pointer to the QSPI module registers.
 * \param[in]    setInterrupt Boolean flag to enable or disable the interrupt after the last flag.
 *                            true if Enable interrupt after last flag, false if Disable interrupt after last flag.
 *
 * \retval None
 *
 */
IFX_INLINE void IfxQspi_setMoveCounterInterruptAfterLastFlag(Ifx_QSPI *qspi, boolean setInterrupt);

/**
 * \brief Enables or disables the interrupt before the last byte is transferred.
 *
 * \param[inout] qspi             Pointer to the QSPI module registers.
 * \param[in]    interruptEnabled Boolean flag to enable (true) or disable (false) the interrupt before the last byte.
 *
 * \retval None
 *
 */
IFX_INLINE void IfxQspi_setMoveCounterInterruptBeforeLastEnabled(Ifx_QSPI *qspi, boolean interruptEnabled);

/**
 * \brief Configures whether an interrupt is generated before the last data element is transferred.
 *
 * \param[inout] qspi         Pointer to the QSPI module registers.
 * \param[in]    setInterrupt Boolean flag to enable or disable the interrupt before the last data element transfer.
 *                            true if Enable interrupt before last data element, false if Disable interrupt before last data element.
 *
 * \retval None
 *
 */
IFX_INLINE void IfxQspi_setMoveCounterInterruptBeforeLastFlag(Ifx_QSPI *qspi, boolean setInterrupt);

/**
 * \brief Sets the trailing delay for the move counter prescaler to achieve the specified baud rate.
 *
 * \param[inout] qspi     Handle to the QSPI module registers.
 * \param[in]    baudrate The desired baud rate for the QSPI interface. Must be greater than 0.
 *
 * \retval None
 *
 */
IFX_INLINE void IfxQspi_setMoveCounterPrescalerTrailingDelay(Ifx_QSPI *qspi, const float baudrate);

/**
 * \brief Configures the RX FIFO interrupt threshold for the QSPI module to generate service requests when the specified threshold is reached.
 *
 * \param[inout] qspi      Pointer to the QSPI module registers.
 * \param[in]    rxFifoInt RxFIFO Interrupt threshold to set. Range: \ref IfxQspi_RxFifoInt.
 *
 * \retval None
 * 
 */
IFX_INLINE void IfxQspi_setReceiveFifoInterrruptThreshold(Ifx_QSPI *qspi, IfxQspi_RxFifoInt rxFifoInt);

/**
 * \brief Enables or disables the injection of Trail2 from the MCCON configuration register.
 *
 * \param[inout] qspi          Pointer to the QSPI module registers.
 * \param[in]    trail2Enabled Boolean flag to enable or disable Trail2 injection.
 *                             TRUE if Enable Trail2 injection from MCCON register, FALSE if Disable Trail2 injection and use bacon configuration.
 *
 * \retval None
 *
 */
IFX_INLINE void IfxQspi_trail2InjectionEnabled(Ifx_QSPI *qspi, boolean trail2Enabled);

/**
 * \brief Writes a 32-bit data value into the QSPI transmit FIFO.
 *
 * \param[inout] qspi Pointer to the QSPI module registers.
 * \param[in]    data The 32-bit data value to be written into the TxFIFO. Range: 0 to 0xFFFF FFFF.
 *
 * \retval None
 *
 */
IFX_INLINE void IfxQspi_writeTransmitFifo(Ifx_QSPI *qspi, uint32 data);

/**
 * \brief Checks if the QSPI module is in a suspended state.
 *
 * \param[in] qspi Pointer to the QSPI module registers.
 *
 * \retval TRUE If Module is suspended.
 *         FALSE If Module is not suspended.
 *
 */
IFX_INLINE boolean IfxQspi_isModuleSuspended(Ifx_QSPI *qspi);

/**
 * \brief Configures the QSPI module's suspend mode to either hard, soft, or none.
 * Note: The api works only when the OCDS is enabled and in Supervisor Mode. When OCDS is disabled the OCS suspend control is ineffective.
 *
 * \param[inout] qspi Pointer to the QSPI module registers.
 * \param[in]    mode The suspend mode to be set. Range: \ref IfxQspi_SuspendMode.
 *
 * \retval None
 *
 */
IFX_INLINE void IfxQspi_setSuspendMode(Ifx_QSPI *qspi, IfxQspi_SuspendMode mode);

/******************************************************************************/
/*-------------------------Global Function Prototypes-------------------------*/
/******************************************************************************/

/**
 * \brief Reads 16-bit data from the Rx FIFO of the QSPI module.
 *
 * \param[in]    qspi  Pointer to the QSPI module registers.
 * \param[inout] data  Array to store the received 16-bit data items. Range: 0 to 0xFFFF.
 * \param[in]    count Number of 16-bit data items to read from the FIFO.
 *
 * \retval None
 * 
 */
IFX_EXTERN void IfxQspi_read16(Ifx_QSPI *qspi, uint16 *data, Ifx_SizeT count);

/**
 * \brief Reads 32-bit data from the Rx FIFO
 *
 * \param[in]    qspi  Pointer to the QSPI module registers.
 * \param[inout] data  Array to store the received 32-bit data. Range: 0 to 0xFFFF FFFF.
 * \param[in]    count Number of 32-bit words to read from the FIFO.
 *
 * \retval None
 *
 */
IFX_EXTERN void IfxQspi_read32(Ifx_QSPI *qspi, uint32 *data, Ifx_SizeT count);

/**
 * \brief Reads 8-bit data from the QSPI receive FIFO into the provided data buffer.
 *
 * \param[in]    qspi  Pointer to the QSPI module registers.
 * \param[inout] data  Pointer to the array where the received data will be stored.
 *                     The array must be large enough to hold "count" bytes. Range: 0 to 0xFF.
 * \param[in]    count Number of 8-bit data items to read from the FIFO.
 *                     This value should be at least 1 and not exceed the FIFO size.
 *
 * \retval None
 *
 */
IFX_EXTERN void IfxQspi_read8(Ifx_QSPI *qspi, uint8 *data, Ifx_SizeT count);

/**
 * \brief Resets the QSPI module to its initial state.
 *
 * \param[inout] qspi Pointer to the QSPI registers.
 *
 * \retval None
 * 
 */
IFX_EXTERN void IfxQspi_resetModule(Ifx_QSPI *qspi);

/**
 * \brief Writes 16-bit data into the Tx FIFO
 *
 * \param[in] qspi      Pointer to QSPI module registers.
 * \param[in] channelId Channel number to which eCON belongs. Range: \ref IfxQspi_ChannelId.
 * \param[in] data      Array of 16-bit data to be sent. Must not be NULL. Range: 0 to 0xFFFF.
 * \param[in] count     Number of 16-bit data items to be sent. Must be a non-negative value.
 * 
 * \retval None
 * 
 */
IFX_EXTERN void IfxQspi_write16(Ifx_QSPI *qspi, IfxQspi_ChannelId channelId, uint16 *data, Ifx_SizeT count);

/**
 * \brief Writes 32-bit data into the Tx FIFO for a specified QSPI channel.
 *
 * \param[in] qspi      Pointer to the QSPI module registers.
 * \param[in] channelId Channel number to which the write operation belongs. Range: \ref IfxQspi_ChannelId.
 * \param[in] data      Pointer to the array of 32-bit data to be sent. Range: 0 to 0xFFFF FFFF.
 * \param[in] count     Number of 32-bit items to be sent. Must be greater than or equal to 0.
 *
 * \retval None
 * 
 */
IFX_EXTERN void IfxQspi_write32(Ifx_QSPI *qspi, IfxQspi_ChannelId channelId, uint32 *data, Ifx_SizeT count);

/**
 * \brief Writes 8-bit data into the Tx FIFO.
 *
 * \param[in] qspi      Pointer to the QSPI module registers.
 * \param[in] channelId The channel number to which the data should be written. Range: \ref IfxQspi_ChannelId.
 * \param[in] data      Pointer to the array of uint8 data to be sent. Range: 0 to 0xFF.
 * \param[in] count     Number of uint8 items to be written to the FIFO.
 *
 * \retval None
 * 
 */
IFX_EXTERN void IfxQspi_write8(Ifx_QSPI *qspi, IfxQspi_ChannelId channelId, uint8 *data, Ifx_SizeT count);

/** \} */

/** \addtogroup IfxLld_Qspi_Std_Support
 * \{ */

/******************************************************************************/
/*-------------------------Inline Function Prototypes-------------------------*/
/******************************************************************************/

/**
 * \brief Retrieves the current operational mode of the QSPI module.
 *
 * \param[in] qspi Pointer to the QSPI module registers.
 *
 * \retval The current mode of the QSPI module. Range: \ref IfxQspi_Mode.
 * 
 */
IFX_INLINE IfxQspi_Mode IfxQspi_getMode(Ifx_QSPI *qspi);

/**
 * \brief Retrieves the current frequency of the QSPI module.
 *
 * \param[in] qspi Pointer to the QSPI module registers.
 *
 * \retval float The module frequency in Hz.
 * 
 */
IFX_INLINE float IfxQspi_getModuleFrequency(Ifx_QSPI *qspi);

/**
 * \brief Gets the actual transmission phase of the QSPI module.
 *
 * \param[in] qspi Pointer to the QSPI module registers.
 *
 * \retval IfxQspi_Phase The current transmission phase. Range: \ref IfxQspi_Phase.
 * 
 */
IFX_INLINE IfxQspi_Phase IfxQspi_getPhase(Ifx_QSPI *qspi);

/**
 * \brief Retrieves the current filling level of the Receive FIFO (RXFIFO).
 *
 * \param[in] qspi Pointer to the QSPI module registers.
 *
 * \retval uint8 The current fill level of the RXFIFO. Range: 0 to 4.
 *
 */
IFX_INLINE uint8 IfxQspi_getReceiveFifoLevel(Ifx_QSPI *qspi);

/**
 * \brief Gets the Time Quanta (TQ) frequency for the QSPI module.
 *
 * \param[in] qspi Pointer to the QSPI module registers.
 *
 * \retval float The Time Quanta frequency in Hz.
 *
 */
IFX_INLINE float IfxQspi_getTimeQuantaFrequency(Ifx_QSPI *qspi);

/**
 * \brief Gets the current filling level of the Transmit FIFO (TXFIFO).
 *
 * \param[in] qspi Pointer to the QSPI module registers.
 * 
 * \retval uint8 The current filling level of the TXFIFO. Range: 0 to 4.
 * 
 */
IFX_INLINE uint8 IfxQspi_getTransmitFifoLevel(Ifx_QSPI *qspi);

/**
 * \brief Checks if the QSPI module is enabled or disabled.
 *
 * \param[in] qspi Pointer to the QSPI module registers.
 *
 * \retval TRUE If the module is enabled.
 *         FALSE If the module is disabled.
 *
 */
IFX_INLINE boolean IfxQspi_isModuleEnabled(Ifx_QSPI *qspi);

/**
 * \brief Sets the disable module request for the QSPI module.
 *
 * \param[inout] qspi Pointer to the QSPI module registers.
 *
 * \retval None
 * 
 */
IFX_INLINE void IfxQspi_setDisableModuleRequest(Ifx_QSPI *qspi);

/**
 * \brief Enables the module request for the specified QSPI instance.
 *
 * \param[inout] qspi Pointer to the QSPI module registers.
 *
 * \retval None
 *
 */
IFX_INLINE void IfxQspi_setEnableModuleRequest(Ifx_QSPI *qspi);

/**
 * \brief Sets the sensitivity of the QSPI module to the sleep signal.
 * 
 * \param[inout] qspi Pointer to the QSPI module registers.
 * \param[in]    mode Sleep mode selection. Range: \ref IfxQspi_SleepMode.
 * 
 * \retval None
 * 
 */
IFX_INLINE void IfxQspi_setSleepMode(Ifx_QSPI *qspi, IfxQspi_SleepMode mode);

/**
 * \brief Configures the threshold level for the Transmit FIFO that triggers an interrupt when the FIFO reaches this level.
 *
 * \param[inout] qspi      Pointer to the QSPI module registers.
 * \param[in]    txFifoInt TxFifo Interrupt threshold to set. This parameter specifies the threshold level for the Transmit FIFO.
 *                         The threshold determines when an interrupt is generated based on the FIFO fill level. Range: \ref IfxQspi_TxFifoInt.
 *
 * \retval None
 * 
 */
IFX_INLINE void IfxQspi_setTransmitFifoInterrruptThreshold(Ifx_QSPI *qspi, IfxQspi_TxFifoInt txFifoInt);

/**
 * \brief Writes a configuration value into the BACON register of the QSPI module.
 *
 * \param[inout] qspi     Pointer to the QSPI module registers.
 * \param[in]    baconVal The 32-bit value to be written into the BACON register. Range: 0 to 0xFFFF FFFF.
 *
 * \retval None
 *
 */
IFX_INLINE void IfxQspi_writeBasicConfiguration(Ifx_QSPI *qspi, uint32 baconVal);

/**
 * \brief Writes the basic configuration into the BACON register with the .LAST flag set to 0.
 *
 * \param[inout] qspi     Pointer to the QSPI module registers.
 * \param[in]    baconVal Value to be written into the BACON register. Range: 0 to 0xFFFF FFFF.
 *
 * \retval None
 *
 */
IFX_INLINE void IfxQspi_writeBasicConfigurationBeginStream(Ifx_QSPI *qspi, uint32 baconVal);

/**
 * \brief Writes the provided baconVal into the BACON register with the .LAST flag set to 1.
 *
 * \param[inout] qspi     Pointer to the QSPI module registers.
 * \param[in]    baconVal The value to be written into the BACON register. Range: 0 to 0xFFFF FFFF.
 *
 * \retval None
 *
 */
IFX_INLINE void IfxQspi_writeBasicConfigurationEndStream(Ifx_QSPI *qspi, uint32 baconVal);

/**
 * \brief Writes the extended configuration value to the specified QSPI channel's ECON register.
 *
 * \param[inout] qspi      Pointer to the QSPI module registers.
 * \param[in]    channelId QSPI channel number to configure. Range: \ref IfxQspi_ChannelId.
 * \param[in]    econVal   Extended configuration value to write. Range: 0 to 0xC000 7FFF.
 *
 * \retval None
 *
 */
IFX_INLINE void IfxQspi_writeExtendedConfiguration(Ifx_QSPI *qspi, IfxQspi_ChannelId channelId, uint32 econVal);

/**
 * \brief Writes data and configuration into the MIXEDENTRY register of the QSPI module.
 *
 * \param[inout] qspi        Pointer to the QSPI module registers.
 * \param[in]    mixEntryVal Data and configuration combined in a single mixed entry value. Range: 0 to 0xFFFF FFFF.
 *
 * \retval None
 *
 */
IFX_INLINE void IfxQspi_writeMixedDataTransmitFifo(Ifx_QSPI *qspi, uint32 mixEntryVal);

/******************************************************************************/
/*-------------------------Global Function Prototypes-------------------------*/
/******************************************************************************/

/**
 * \brief Calculates the actual baudrate for the specified QSPI channel.
 *
 * \param[in] qspi Pointer to the QSPI module registers.
 * \param[in] channelId Identifier of the QSPI channel. Range: \ref IfxQspi_ChannelId.
 *
 * \retval float The actual baudrate in float.
 *
 */
IFX_EXTERN float IfxQspi_calcRealBaudrate(Ifx_QSPI *qspi, IfxQspi_ChannelId channelId);

/**
 * \brief Function to calculate BACON register values
 *
 * \param[in] qspi Pointer to QSPI module registers.
 * \param[in] channelId QSPI Channel Number. Range: \ref IfxQspi_ChannelId.
 * \param[in] chMode Pointer to the channel mode configuration structure defining the operating mode of the QSPI channel.
 * \param[in] baudrate Desired baudrate for the QSPI communication.
 *
 * \retval uint32 Calculated BACON value. Range: 0 to 0xFFFF FFFF.
 *
 */
IFX_EXTERN uint32 IfxQspi_calculateBasicConfigurationValue(Ifx_QSPI *qspi, const IfxQspi_ChannelId channelId, const IfxQspi_chMode *chMode, const float baudrate);

/**
 * \brief Calculates the extended configuration value for the QSPI channel's ECON register.
 *
 * \param[in] qspi     Pointer to the QSPI module registers.
 * \param[in] cs       QSPI channel Number : 8->0,9->1,....... Range: 0 to 0xFF.
 * \param[in] chConfig Pointer to the SPI channel configuration structure containing baudrate, mode, error checks, and channel ID.
 *
 * \retval uint32 The calculated ECON[CS] value for the specified channel. Range: 0 to 0xC000 7FFF.
 *
 */
IFX_EXTERN uint32 IfxQspi_calculateExtendedConfigurationValue(Ifx_QSPI *qspi, const uint8 cs, const IfxQspi_chConfig *chConfig);

/**
 * \brief Calculates the prescaler value for the QSPI module based on the specified baudrate.
 *
 * \param[in] qspi Pointer to the QSPI module registers.
 * \param[in] baudrate Maximum baudrate in Hz.
 *
 * \retval uint32 Prescaler value. Range: 0 to 7.
 * 
 */
IFX_EXTERN uint32 IfxQspi_calculatePrescaler(Ifx_QSPI *qspi, float baudrate);

/**
 * \brief Calculates the time quantum length for the QSPI module based on the maximum baudrate.
 *
 * \param[in] qspi Pointer to the QSPI module registers.
 * \param[in] maxBaudrate The maximum baudrate value in Hz (float) that the QSPI module is configured to operate at.
 *
 * \retval uint32 The calculated time quantum length in clock cycles. Range: 0 to 0xFFFF FFFF.
 * 
 */
IFX_EXTERN uint32 IfxQspi_calculateTimeQuantumLength(Ifx_QSPI *qspi, float maxBaudrate);

/**
 * \brief Retrieves the base address of the QSPI module registers.
 *
 * \param[in] qspi The index of the QSPI module. Range: \ref IfxQspi_Index.
 *
 * \retval Ifx_QSPI* Pointer to the base address of the QSPI module registers.
 * 
 */
IFX_EXTERN Ifx_QSPI *IfxQspi_getAddress(IfxQspi_Index qspi);

/**
 * \brief Retrieves the current index of the QSPI module.
 *
 * \param[in] qspi Pointer to the QSPI module registers.
 *
 * \retval IfxQspi_Index The current index value of the QSPI module. Range: \ref IfxQspi_Index.
 *
 */
IFX_EXTERN IfxQspi_Index IfxQspi_getIndex(Ifx_QSPI *qspi);

/** \brief Re-calculated BACON from the oldBACON.
 *
 * \param[in] oldBACON  Old BACON value.Range: 0 to 0xFFFF FFFF.
 * \param[in] numOfData numOfData in LONG or CONTINUOUS mode.
 * \param[in] shortData Specifies SHORT mode (TRUE) or other modes (FALSE).
 * \param[in] lastData  Specifies last data in LONG or CONTINUOUS.
 *
 * \retval uint32 Re-calculated BACON value. Range: 0 to 0xFFFF FFFF.
 *
 */
IFX_EXTERN uint32 IfxQspi_recalcBasicConfiguration(uint32 oldBACON, Ifx_SizeT numOfData, boolean shortData, boolean lastData);

/**
 * \brief Configures the Slave Select Output control for a specified QSPI channel.
 * 
 * \param[inout] qspi         Pointer to the QSPI module registers.
 * \param[in]    channelId    QSPI channel identifier. Range: \ref IfxQspi_ChannelId.
 * \param[in]    outputEnable Boolean flag to enable the chip select output during transactions.
 * \param[in]    activeLevel  Boolean flag to set the active level of the Slave Select signal.
 *                            - TRUE: Active-high (Slave Select is asserted high).
 *                            - FALSE: Active-low (Slave Select is asserted low).
 *
 * \retval None
 * 
 */
IFX_EXTERN void IfxQspi_setSlaveSelectOutputControl(Ifx_QSPI *qspi, IfxQspi_ChannelId channelId, boolean outputEnable, boolean activeLevel);

/**
 * \brief Calculates the delay constants (pre and delay) from the user-specified CS delays.
 *
 * \param[in]    qspi       Pointer to the QSPI module registers.
 * \param[in]    channelId  QSPI channel identifier. Range: \ref IfxQspi_ChannelId.
 * \param[in]    chMode     Pointer to the channel mode configuration structure, containing
 *                          settings like CS delays, enable status, and other channel-specific configurations.
 * \param[inout] delayConst Pointer to the structure where the calculated delay constants
 *                          (pre and delay values) will be stored.
 *
 * \retval None
 *
 */
IFX_EXTERN void IfxQspi_calculateDelayConstants(const Ifx_QSPI *qspi, const IfxQspi_ChannelId channelId, const IfxQspi_chMode *chMode, IfxQspi_DelayConst *delayConst);

/** \} */

/** \addtogroup IfxLld_Qspi_Std_Interrupt
 * \{ */

/******************************************************************************/
/*-------------------------Inline Function Prototypes-------------------------*/
/******************************************************************************/
#if defined(DEVICE_TC33XED) || defined(DEVICE_TC33X) || defined(DEVICE_TC35X) || defined(DEVICE_TC39XB)

/** \brief Api to enable/disable CAPCON interrupt.
 *
 * \param[inout] qspi   Pointer to the QSPI module registers.
 * \param[in]    enable Enable Interrupt.
 *
 * \retval None
 *
 */
IFX_INLINE void IfxQspi_enableCapconInterrupt(Ifx_QSPI *qspi, boolean enable);
#endif

/**
 * \brief Retrieves the error source register for the QSPI module.
 *
 * \param[in] qspi Pointer to the QSPI module registers.
 *
 * \retval  Ifx_SRC_SRCR* Pointer to the error source register containing error flags.
 * 
 */
IFX_INLINE volatile Ifx_SRC_SRCR *IfxQspi_getErrorSrc(Ifx_QSPI *qspi);

/**
 * \brief Retrieves the service request configuration register for the receive FIFO of the QSPI module.
 *
 * \param[in] qspi Pointer to the QSPI module registers.
 * 
 * \retval Ifx_SRC_SRCR* pointer to the SRCR register of the receive FIFO.
 *
 */
IFX_INLINE volatile Ifx_SRC_SRCR *IfxQspi_getReceiveSrc(Ifx_QSPI *qspi);

/**
 * \brief Retrieves the transmission service request configuration for the TXFIFO.
 *
 * \param[in] qspi Pointer to the QSPI module registers.
 *
 * \retval  Ifx_SRC_SRCR* Pointer to the transmission service request configuration register.
 * 
 */
IFX_INLINE volatile Ifx_SRC_SRCR *IfxQspi_getTransmitSrc(Ifx_QSPI *qspi);

/** \brief Gets the Phase Transition service request
 *
 * \param[in] qspi Pointer to QSPI module registers
 *
 * \retval Phase Transition service request value
 */
IFX_INLINE volatile Ifx_SRC_SRCR *IfxQspi_getPhaseTransitionSrc(Ifx_QSPI *qspi);

/** \} */

/** \addtogroup IfxLld_Qspi_Std_IO
 * \{ */

/******************************************************************************/
/*-------------------------Inline Function Prototypes-------------------------*/
/******************************************************************************/

/**
 * \brief Initializes a MRST input pin for QSPI communication.
 *
 * \param[in] mrstIn     Pointer to the MRST input pin configuration structure.
 * \param[in] mrstInMode Input mode to be configured for the MRST pin (e.g., pull-up, pull-down, etc.). Range: \ref IfxPort_InputMode.
 *
 * \retval None
 * 
 */
IFX_INLINE void IfxQspi_initMrstInPin(const IfxQspi_Mrst_In *mrstIn, IfxPort_InputMode mrstInMode);

/**
 * \brief Initializes a MRST output pin configuration.
 *
 * \param[in] mrstOut     Pointer to the MRST output pin configuration structure to be initialized.
 * \param[in] mrstOutMode The output mode to be configured for the MRST pin (e.g., push-pull, open-drain). Range: \ref IfxPort_OutputMode.
 * \param[in] padDriver   The pad driver mode to be configured for the MRST pin (e.g., normal, high-speed). Range: \ref IfxPort_PadDriver.
 *
 * \retval None
 * 
 */
IFX_INLINE void IfxQspi_initMrstOutPin(const IfxQspi_Mrst_Out *mrstOut, IfxPort_OutputMode mrstOutMode, IfxPort_PadDriver padDriver);

/**
 * \brief Initializes a MTSR input pin with a specified input mode.
 *
 * \param[in] mtsrIn     The MTSR input pin to be configured. This is a pointer to a constant
 *                       IfxQspi_Mtsr_In struct that contains the pin configuration details.
 * \param[in] mtsrInMode The input mode to be set for the MTSR pin. Range: \ref IfxPort_InputMode.
 *
 * \retval None 
 *
 */
IFX_INLINE void IfxQspi_initMtsrInPin(const IfxQspi_Mtsr_In *mtsrIn, IfxPort_InputMode mtsrInMode);

/**
 * \brief Initializes a MTSR output pin with the specified output mode and pad driver settings.
 *
 * \param[in] mtsrOut     Pointer to the MTSR pin configuration to be initialized.
 * \param[in] mtsrOutMode The output mode to be configured for the MTSR pin. This is typically an enumeration
 *                        of predefined output modes (e.g., push-pull, open-drain, etc.). Range: \ref IfxPort_OutputMode.
 * \param[in] padDriver   The pad driver mode to be configured for the MTSR pin. This is typically an enumeration
 *                        of predefined pad driver settings (e.g., normal, high-speed, etc.). Range: \ref IfxPort_PadDriver.
 *
 * \retval None
 *
 */
IFX_INLINE void IfxQspi_initMtsrOutPin(const IfxQspi_Mtsr_Out *mtsrOut, IfxPort_OutputMode mtsrOutMode, IfxPort_PadDriver padDriver);

/**
 * \brief Initializes a SCLK input pin with the specified input mode.
 *
 * \param[in] sclkIn     The SCLK input pin to be configured. Must be a valid pointer to an IfxQspi_Sclk_In structure.
 * \param[in] sclkInMode The input mode to be set for the SCLK pin. Must be of type IfxPort_InputMode. Range: \ref IfxPort_InputMode.
 *
 * \retval None
 *
 */
IFX_INLINE void IfxQspi_initSclkInPin(const IfxQspi_Sclk_In *sclkIn, IfxPort_InputMode sclkInMode);

/**
 * \brief Initializes a SCLK output pin with the specified configuration.
 *
 * \param[in] sclkOut     Pointer to the SCLK pin configuration structure to be initialized.
 * \param[in] sclkOutMode The output mode to be configured for the SCLK pin (e.g., push-pull, open-drain). Range: \ref IfxPort_OutputMode.
 * \param[in] padDriver   The pad driver mode to be configured for the SCLK pin (e.g., normal, high-speed). Range: \ref IfxPort_PadDriver.
 *
 * \retval None
 * 
 */
IFX_INLINE void IfxQspi_initSclkOutPin(const IfxQspi_Sclk_Out *sclkOut, IfxPort_OutputMode sclkOutMode, IfxPort_PadDriver padDriver);

/**
 * \brief Initializes a SLSI input pin configuration.
 *
 * \param[in] slsi     Pointer to the SLSI pin configuration structure to be initialized.
 * \param[in] slsiMode The input mode to be configured for the SLSI pin. Range: \ref IfxPort_InputMode.
 *
 * \retval None
 * 
 */
IFX_INLINE void IfxQspi_initSlsi(const IfxQspi_Slsi_In *slsi, IfxPort_InputMode slsiMode);

/**
 * \brief Initializes a SLSO (Slow Speed Output) pin configuration for QSPI operations.
 *
 * \param[in] slso      A pointer to the SLSO pin configuration structure to be initialized.
 * \param[in] slsoMode  The output mode to be configured for the SLSO pin. This is typically an enumeration defining the pin's output behavior. Range: \ref IfxPort_OutputMode.
 * \param[in] padDriver The pad driver mode to be configured for the SLSO pin. This is typically an enumeration specifying the pin's driving strength or slew rate. Range: \ref IfxPort_PadDriver.
 * \param[in] outIndex  The index of the pad driver configuration. Range: \ref IfxPort_OutputIdx.
 *
 * \retval None 
 *
 */
IFX_INLINE void IfxQspi_initSlso(const IfxQspi_Slso_Out *slso, IfxPort_OutputMode slsoMode, IfxPort_PadDriver padDriver, IfxPort_OutputIdx outIndex);

/** \} */

/******************************************************************************/
/*-------------------------Inline Function Prototypes-------------------------*/
/******************************************************************************/

/**
 * \brief Retrieves the current operating mode of the Receive FIFO for the specified QSPI module.
 *
 * \param[in] qspi Pointer to the QSPI module registers.
 *
 * \retval The current Receive FIFO mode.
 *
 */
IFX_INLINE IfxQspi_FifoMode IfxQspi_getRxFifoMode(Ifx_QSPI *qspi);

/**
 * \brief Retrieves the current mode of the Transfer FIFO for the specified QSPI module.
 *
 * \param[in] qspi Pointer to the QSPI module registers.
 *
 * \retval The current mode of the Transfer FIFO. Range: \ref IfxQspi_FifoMode.
 *
 */
IFX_INLINE IfxQspi_FifoMode IfxQspi_getTxFifoMode(Ifx_QSPI *qspi);

/**
 * \brief Permutates bytes to or from Big Endian format for the specified QSPI channel.
 *
 * \param[inout] qspi      Pointer to QSPI module registers.
 * \param[in]    channelId QSPI channel number to configure. Range: \ref IfxQspi_ChannelId.
 * \param[in]    bigEndian Specifies the byte order. A value of 0 configures for Little Endian,
 *                         while any non-zero value configures for Big Endian. Range: 0 to 3.
 *
 * \retval None
 *
 */
IFX_INLINE void IfxQspi_permutateBigEndian(Ifx_QSPI *qspi, IfxQspi_ChannelId channelId, uint8 bigEndian);

/**
 * \brief Sets the value of bit segment1 (A) for the specified QSPI channel.
 *
 * \param[inout] qspi     Pointer to QSPI module registers.
 * \param[in] channelId   QSPI channel number (BACON.CS). Range: \ref IfxQspi_ChannelId.
 * \param[in] bitSegment1 Length expressed in time quantums of ECONz.Q. Range: 0 to 3.
 *
 * \retval None
 *
 */
IFX_INLINE void IfxQspi_setBitsegment1(Ifx_QSPI *qspi, IfxQspi_ChannelId channelId, uint8 bitSegment1);

/**
 * \brief Sets the value of bit segment2 (B) for the specified QSPI channel.
 * 
 * \param[inout] qspi        Pointer to the QSPI module registers.
 * \param[in]    channelId   QSPI channel number. Range: \ref IfxQspi_ChannelId.
 * \param[in]    bitSegment2 Length of bit segment2 in time quanta. Range: 0 to 3.
 *
 * \retval None
 * 
 */
IFX_INLINE void IfxQspi_setBitsegment2(Ifx_QSPI *qspi, IfxQspi_ChannelId channelId, uint8 bitSegment2);

/**
 * \brief Sets the value of bit segment3 (C) for the specified QSPI channel.
 * 
 * \param[inout] qspi        Pointer to QSPI module registers.
 * \param[in]    channelId   Channel number to which the ECON value belongs. Range: \ref IfxQspi_ChannelId.
 * \param[in]    bitSegment3 Length expressed in time quantums of ECONz.Q. Range: 0 to 3.
 * 
 * \retval None
 * 
 */
IFX_INLINE void IfxQspi_setBitsegment3(Ifx_QSPI *qspi, IfxQspi_ChannelId channelId, uint8 bitSegment3);

/**
 * \brief Configures the receive FIFO mode for the specified QSPI module.
 *
 * \param[inout] qspi Pointer to the QSPI module registers.
 * \param[in]    mode The desired FIFO mode for the receive operation. Range: \ref IfxQspi_FifoMode.
 *
 * \retval None
 * 
 */
IFX_INLINE void IfxQspi_setRxFifoMode(Ifx_QSPI *qspi, IfxQspi_FifoMode mode);

/**
 * \brief Sets the Time Quantum value for a specified QSPI channel.
 *
 * \param[inout] qspi        Pointer to the QSPI module registers.
 * \param[in]    channelId   Channel number to which econ val belongs. Range: \ref IfxQspi_ChannelId.
 * \param[in]    timeQuantum Specifies the Time Quantum value. Range: 0 to 63.
 *
 * \retval None
 * 
 */
IFX_INLINE void IfxQspi_setTimeQuantum(Ifx_QSPI *qspi, IfxQspi_ChannelId channelId, uint32 timeQuantum);

/**
 * \brief Configures the transmit FIFO mode for the QSPI module.
 *
 * \param[inout] qspi Pointer to the QSPI module registers.
 * \param[in]    mode Selects the transmit FIFO mode to be configured.  Range: \ref IfxQspi_FifoMode.
 *
 * \retval None
 *
 */
IFX_INLINE void IfxQspi_setTxFifoMode(Ifx_QSPI *qspi, IfxQspi_FifoMode mode);

/**
 * \brief Provides functionality for both setting of MRSTIN pin direction as input and configuring pad driver
 *
 * \param[in] mrstIn     Pointer to the MRSTIN pin configuration to be initialized.
 * \param[in] mrstInMode The input mode to be configured for the MRSTIN pin. Range: \ref IfxPort_InputMode.
 * \param[in] padDriver  The pad driver strength to be configured. Range: \ref IfxPort_PadDriver.
 *
 * \retval None
 * 
 */
IFX_INLINE void IfxQspi_initMrstInPinWithPadLevel(const IfxQspi_Mrst_In *mrstIn, IfxPort_InputMode mrstInMode, IfxPort_PadDriver padDriver);

/**
 * \brief Initializes the MTSRIN pin as an input and configures the pad driver for QSPI communication.
 *
 * \param[in] mtsrIn     Pointer to the MTSRIN pin configuration structure.
 * \param[in] mtsrInMode The input mode to be set for the MTSRIN pin. Range: \ref IfxPort_InputMode.
 * \param[in] padDriver  The pad driver configuration. Range: \ref IfxPort_PadDriver.
 *
 * \retval None
 *
 */
IFX_INLINE void IfxQspi_initMtsrInPinWithPadLevel(const IfxQspi_Mtsr_In *mtsrIn, IfxPort_InputMode mtsrInMode, IfxPort_PadDriver padDriver);

/**
 * \brief Initializes the SCLKIN pin as an input with the specified pad driver configuration.
 *
 * \param[in] sclkIn     Pointer to the SCLKIN pin to be configured.
 * \param[in] sclkInMode The input mode to be set for the SCLKIN pin. Range: \ref IfxPort_InputMode.
 * \param[in] padDriver  The pad driver configuration to be applied. Range: \ref IfxPort_PadDriver.
 *
 * \retval None
 *
 */
IFX_INLINE void IfxQspi_initSclkInPinWithPadLevel(const IfxQspi_Sclk_In *sclkIn, IfxPort_InputMode sclkInMode, IfxPort_PadDriver padDriver);

/**
 * \brief Initializes the SLSI pin as an input with the specified mode and pad driver configuration.
 *
 * \param[in] slsi      The SLSI pin to be configured. This is a pointer to a constant IfxQspi_Slsi_In struct.
 * \param[in] slsiMode  The input mode to be configured for the SLSI pin. Range: \ref IfxPort_InputMode.
 * \param[in] padDriver The pad driver configuration to be applied.  Range: \ref IfxPort_PadDriver.
 *
 * \retval None
 *
 */
IFX_INLINE void IfxQspi_initSlsiWithPadLevel(const IfxQspi_Slsi_In *slsi, IfxPort_InputMode slsiMode, IfxPort_PadDriver padDriver);


/**
 * \brief Writes delay parameters into the BACON register for QSPI module configuration.
 * 
 * \param[inout] qspi   Pointer to QSPI module registers.
 * \param[in]    config Structure containing delay parameters:
 *                      - Idle, leading, and trailing delay configurations
 *                      - Each delay type includes a prescalar and length value
 *
 * \retval None
 * 
 */
IFX_INLINE void IfxQspi_setBaconDelayParameters(Ifx_QSPI *qspi, IfxQspi_DelayParameters *config);

/** \brief Provides functionality for both setting of MRST_OUT pin direction as Output and configuring LVDS pad driver
 * \param[in] mrstOut pointer to MRST output pin configuration
 * \param[in] mrstOutMode MRST mode
 * \param[in] padDriver PAD driver
 * \param[inout] mrstOutLvdsCfg Pointer to MRST LVDS configuration
 * \retval None
 */
IFX_INLINE void IfxQspi_initMrstOutLvdsPin(const IfxQspi_Mrst_Out *mrstOut, IfxPort_OutputMode mrstOutMode, IfxPort_PadDriver padDriver, IfxPort_LvdsConfig *mrstOutLvdsCfg);

/** \brief Provides functionality for both setting of MTSR_OUT pin direction as Output and configuring LVDS pad driver
 * \param[in] mtsrOut pointer to MTSR output pin configuration
 * \param[in] mtsrOutMode MTSR mode
 * \param[in] padDriver PAD driver
 * \param[inout] mtsrOutLvdsCfg Pointer to MTSR LVDS configuration
 * \retval None
 */
IFX_INLINE void IfxQspi_initMtsrOutLvdsPin(const IfxQspi_Mtsr_Out *mtsrOut, IfxPort_OutputMode mtsrOutMode, IfxPort_PadDriver padDriver, IfxPort_LvdsConfig *mtsrOutLvdsCfg);

/** \brief Provides functionality for both setting of SCLK_OUT pin direction as Output and configuring LVDS pad driver
 * \param[in] sclkOut pointer to SCLK output pin configuration
 * \param[in] sclkOutMode SCLK Mode
 * \param[in] padDriver Pad driver
 * \param[inout] sclkOutLvdsCfg Pointer to SCLK output LVDS configuration
 * \retval None
 */
IFX_INLINE void IfxQspi_initSclkOutLvdsPin(const IfxQspi_Sclk_Out *sclkOut, IfxPort_OutputMode sclkOutMode, IfxPort_PadDriver padDriver, IfxPort_LvdsConfig *sclkOutLvdsCfg);

/** \brief Provides functionality for both setting of MRST_IN pin direction as Output and configuring LVDS pad driver
 * \param[in] mrstIn pointer to MRST input pin configuration
 * \param[in] mrstInMode MRST pin input mode selection
 * \param[in] padDriver MRTS input pin pad driver selection
 * \param[inout] mrstInLvdsCfg Pointer to MRST input LVDS configuration
 * \retval None
 */
IFX_INLINE void IfxQspi_initMrstInLvdsPinWithPadLevel(const IfxQspi_Mrst_In *mrstIn, IfxPort_InputMode mrstInMode, IfxPort_PadDriver padDriver, IfxPort_LvdsConfig *mrstInLvdsCfg);


/** \brief Provides functionality for both setting of MTSR_OUT pin direction as Output and configuring LVDS pad driver
 * \param[in] mtsrIn pointer to MTSR input pin configuration
 * \param[in] mtsrInMode MTSR pin input mode selection
 * \param[in] padDriver MTSR input pin pad driver selection
 * \param[inout] mtsrInLvdsCfg Pointer to MTSR input LVDS configuration
 * \retval None
 */
IFX_INLINE void IfxQspi_initMtsrInLvdsPinWithPadLevel(const IfxQspi_Mtsr_In *mtsrIn, IfxPort_InputMode mtsrInMode, IfxPort_PadDriver padDriver, IfxPort_LvdsConfig *mtsrInLvdsCfg);

/** \brief Provides functionality for both setting of MTSR_OUT pin direction as Output and configuring LVDS pad driver
 * \param[in] sclkIn pointer to SCLK input pin configuration
 * \param[in] sclkInMode SCLK pin input mode selection
 * \param[in] padDriver SCLK input pin pad driver selection
 * \param[inout] sclkInLvdsCfg Pointer to SCLK input LVDS configuration
 * \retval None
 */
IFX_INLINE void IfxQspi_initSclkInLvdsPinWithPadLevel(const IfxQspi_Sclk_In *sclkIn, IfxPort_InputMode sclkInMode, IfxPort_PadDriver padDriver, IfxPort_LvdsConfig *sclkInLvdsCfg);

/******************************************************************************/
/*---------------------Inline Function Implementations------------------------*/
/******************************************************************************/

IFX_INLINE void IfxQspi_clearAllEventFlags(Ifx_QSPI *qspi)
{
    qspi->FLAGSCLEAR.U = 0xFFFFU;
}


IFX_INLINE void IfxQspi_clearMoveCounterInterruptAfterLastFlag(Ifx_QSPI *qspi, boolean clearInterrupt)
{
    qspi->MCCON.B.IALC = clearInterrupt;
}


IFX_INLINE void IfxQspi_clearMoveCounterInterruptBeforeLastFlag(Ifx_QSPI *qspi, boolean clearInterrupt)
{
    qspi->MCCON.B.IBLC = clearInterrupt;
}


IFX_INLINE void IfxQspi_clearRxReq(Ifx_QSPI *qspi)
{
    qspi->FLAGSCLEAR.B.RXC = 1U;
}


IFX_INLINE void IfxQspi_clearTxReq(Ifx_QSPI *qspi)
{
    qspi->FLAGSCLEAR.B.TXC = 1U;
}


IFX_INLINE void IfxQspi_clearPt1Req(Ifx_QSPI *qspi)
{
    qspi->FLAGSCLEAR.B.PT1C = 1U;
}


IFX_INLINE void IfxQspi_clearPt2Req(Ifx_QSPI *qspi)
{
    qspi->FLAGSCLEAR.B.PT2C = 1U;
}


IFX_INLINE void IfxQspi_clearUsrReq(Ifx_QSPI *qspi)
{
    qspi->FLAGSCLEAR.B.USRC = 1U;
}


IFX_INLINE void IfxQspi_configPT1Event(Ifx_QSPI *qspi, IfxQspi_PhaseTransitionEvent pt1Config)
{
    qspi->GLOBALCON1.B.PT1 = pt1Config;
}


IFX_INLINE void IfxQspi_configPT2Event(Ifx_QSPI *qspi, IfxQspi_PhaseTransitionEvent pt2Config)
{
    qspi->GLOBALCON1.B.PT2 = pt2Config;
}

#if defined(DEVICE_TC33XED) || defined(DEVICE_TC33X) || defined(DEVICE_TC35X) || defined(DEVICE_TC39XB)
IFX_INLINE void IfxQspi_configureCapcon(Ifx_QSPI *qspi, IfxQspi_CaptureControlInputSelection inputSel, IfxQspi_CaptureControlEdgeConfiguration edgeConfiguration)
{
    qspi->CAPCON.B.INS     = inputSel;
    qspi->CAPCON.B.EDGECON = edgeConfiguration;
    qspi->CAPCON.B.CAPSEL  = 1;     /* Capture-irq on HC-irq */
    qspi->CAPCON.B.CAPC    = 0;
}


IFX_INLINE void IfxQspi_enableCapconInterrupt(Ifx_QSPI *qspi, boolean enable)
{
    qspi->CAPCON.B.EN = enable;
}
#endif

IFX_INLINE void IfxQspi_enableLoopbackMode(Ifx_QSPI *qspi, boolean enable)
{
    IFX_UNUSED_PARAMETER(enable);

    qspi->GLOBALCON.B.LB = 1;
}


IFX_INLINE void IfxQspi_enablePT1Event(Ifx_QSPI *qspi, boolean enable)
{
    qspi->GLOBALCON1.B.PT1EN = enable;
}


IFX_INLINE void IfxQspi_enablePT2Event(Ifx_QSPI *qspi, boolean enable)
{
    qspi->GLOBALCON1.B.PT2EN = enable;
}


IFX_INLINE void IfxQspi_enableUsrEvent(Ifx_QSPI *qspi, boolean enable)
{
    qspi->GLOBALCON1.B.USREN = enable;
}


IFX_INLINE uint16 IfxQspi_getErrorFlags(Ifx_QSPI *qspi)
{
    return qspi->STATUS.B.ERRORFLAGS;
}


IFX_INLINE boolean IfxQspi_getTxReqStatus(Ifx_QSPI *qspi)
{
    return (qspi->STATUS.B.TXF != 0U) ? TRUE : FALSE;
}


IFX_INLINE boolean IfxQspi_getRxReqStatus(Ifx_QSPI *qspi)
{
    return (qspi->STATUS.B.RXF != 0U) ? TRUE : FALSE;
}


IFX_INLINE boolean IfxQspi_getPt1Status(Ifx_QSPI *qspi)
{
    return (qspi->STATUS.B.PT1F != 0U) ? TRUE : FALSE;
}


IFX_INLINE boolean IfxQspi_getPt2Status(Ifx_QSPI *qspi)
{
    return (qspi->STATUS.B.PT2F != 0U) ? TRUE : FALSE;
}


IFX_INLINE boolean IfxQspi_getUsrReqStatus(Ifx_QSPI *qspi)
{
    return (qspi->STATUS.B.USRF != 0U) ? TRUE : FALSE;
}


IFX_INLINE volatile Ifx_SRC_SRCR *IfxQspi_getErrorSrc(Ifx_QSPI *qspi)
{
    uint32 index = IfxQspi_getIndex(qspi);
    return &MODULE_SRC.QSPI.QSPI[index].ERR;
}


IFX_INLINE IfxQspi_Mode IfxQspi_getMode(Ifx_QSPI *qspi)
{
    return (IfxQspi_Mode)qspi->GLOBALCON.B.MS;
}


IFX_INLINE float IfxQspi_getModuleFrequency(Ifx_QSPI *qspi)
{
    IFX_UNUSED_PARAMETER(qspi->CLC.U != 0);

    return IfxScuCcu_getQspiFrequency();
}


IFX_INLINE IfxQspi_Phase IfxQspi_getPhase(Ifx_QSPI *qspi)
{
    return (IfxQspi_Phase)qspi->STATUS.B.PHASE;
}


IFX_INLINE uint8 IfxQspi_getReceiveFifoLevel(Ifx_QSPI *qspi)
{
    return qspi->STATUS.B.RXFIFOLEVEL;
}


IFX_INLINE volatile Ifx_SRC_SRCR *IfxQspi_getReceiveSrc(Ifx_QSPI *qspi)
{
    uint32 index = IfxQspi_getIndex(qspi);
    return &MODULE_SRC.QSPI.QSPI[index].RX;
}


IFX_INLINE IfxQspi_FifoMode IfxQspi_getRxFifoMode(Ifx_QSPI *qspi)
{
    return (IfxQspi_FifoMode)qspi->GLOBALCON1.B.RXFM;
}


IFX_INLINE float IfxQspi_getTimeQuantaFrequency(Ifx_QSPI *qspi)
{
    return IfxQspi_getModuleFrequency(qspi) / (qspi->GLOBALCON.B.TQ + 1);
}


IFX_INLINE uint8 IfxQspi_getTransmitFifoLevel(Ifx_QSPI *qspi)
{
    return qspi->STATUS.B.TXFIFOLEVEL;
}


IFX_INLINE volatile Ifx_SRC_SRCR *IfxQspi_getTransmitSrc(Ifx_QSPI *qspi)
{
    uint32 index = IfxQspi_getIndex(qspi);
    return &MODULE_SRC.QSPI.QSPI[index].TX;
}


IFX_INLINE IfxQspi_FifoMode IfxQspi_getTxFifoMode(Ifx_QSPI *qspi)
{
    return (IfxQspi_FifoMode)qspi->GLOBALCON1.B.TXFM;
}

IFX_INLINE volatile Ifx_SRC_SRCR *IfxQspi_getPhaseTransitionSrc(Ifx_QSPI *qspi)
{
	uint32 index = IfxQspi_getIndex(qspi);
	return &MODULE_SRC.QSPI.QSPI[index].PT;
}


IFX_INLINE void IfxQspi_initMrstInPin(const IfxQspi_Mrst_In *mrstIn, IfxPort_InputMode mrstInMode)
{
    IfxPort_setPinModeInput(mrstIn->pin.port, mrstIn->pin.pinIndex, mrstInMode);
    mrstIn->module->PISEL.B.MRIS = mrstIn->select;
}


IFX_INLINE void IfxQspi_initMrstOutPin(const IfxQspi_Mrst_Out *mrstOut, IfxPort_OutputMode mrstOutMode, IfxPort_PadDriver padDriver)
{
    IfxPort_setPinModeOutput(mrstOut->pin.port, mrstOut->pin.pinIndex, mrstOutMode, mrstOut->select);
    IfxPort_setPinPadDriver(mrstOut->pin.port, mrstOut->pin.pinIndex, padDriver);
}


IFX_INLINE void IfxQspi_initMtsrInPin(const IfxQspi_Mtsr_In *mtsrIn, IfxPort_InputMode mtsrInMode)
{
    IfxPort_setPinModeInput(mtsrIn->pin.port, mtsrIn->pin.pinIndex, mtsrInMode);
    mtsrIn->module->PISEL.B.SRIS = mtsrIn->select;
}


IFX_INLINE void IfxQspi_initMtsrOutPin(const IfxQspi_Mtsr_Out *mtsrOut, IfxPort_OutputMode mtsrOutMode, IfxPort_PadDriver padDriver)
{
    IfxPort_setPinModeOutput(mtsrOut->pin.port, mtsrOut->pin.pinIndex, mtsrOutMode, mtsrOut->select);
    IfxPort_setPinPadDriver(mtsrOut->pin.port, mtsrOut->pin.pinIndex, padDriver);
}


IFX_INLINE void IfxQspi_initSclkInPin(const IfxQspi_Sclk_In *sclkIn, IfxPort_InputMode sclkInMode)
{
    IfxPort_setPinModeInput(sclkIn->pin.port, sclkIn->pin.pinIndex, sclkInMode);
    sclkIn->module->PISEL.B.SCIS = sclkIn->select;
}


IFX_INLINE void IfxQspi_initSclkOutPin(const IfxQspi_Sclk_Out *sclkOut, IfxPort_OutputMode sclkOutMode, IfxPort_PadDriver padDriver)
{
    IfxPort_setPinModeOutput(sclkOut->pin.port, sclkOut->pin.pinIndex, sclkOutMode, sclkOut->select);
    IfxPort_setPinPadDriver(sclkOut->pin.port, sclkOut->pin.pinIndex, padDriver);
}


IFX_INLINE void IfxQspi_initSlsi(const IfxQspi_Slsi_In *slsi, IfxPort_InputMode slsiMode)
{
    IfxPort_setPinModeInput(slsi->pin.port, slsi->pin.pinIndex, slsiMode);
    /* PISEL */
    slsi->module->PISEL.B.SLSIS = slsi->select + 1;
}


IFX_INLINE void IfxQspi_initSlso(const IfxQspi_Slso_Out *slso, IfxPort_OutputMode slsoMode, IfxPort_PadDriver padDriver, IfxPort_OutputIdx outIndex)
{
    IfxPort_setPinModeOutput(slso->pin.port, slso->pin.pinIndex, slsoMode, outIndex);
    IfxPort_setPinPadDriver(slso->pin.port, slso->pin.pinIndex, padDriver);
}


IFX_INLINE boolean IfxQspi_isModuleEnabled(Ifx_QSPI *qspi)
{
    return (qspi->CLC.B.DISS == 0) ? TRUE : FALSE;
}


IFX_INLINE void IfxQspi_pause(Ifx_QSPI *qspi)
{
    qspi->GLOBALCON.B.EN = 0;

    while (IfxQspi_getPhase(qspi) != IfxQspi_Phase_wait)
    {}
}


IFX_INLINE void IfxQspi_permutateBigEndian(Ifx_QSPI *qspi, IfxQspi_ChannelId channelId, uint8 bigEndian)
{
    int cs = channelId % 8;
    qspi->ECON[cs].B.BE = bigEndian;
}


IFX_INLINE uint32 IfxQspi_readReceiveFifo(Ifx_QSPI *qspi)
{
    return qspi->RXEXIT.U;
}


IFX_INLINE void IfxQspi_requestReset(Ifx_QSPI *qspi, IfxQspi_Reset reset)
{
    qspi->GLOBALCON.B.RESETS = reset;
}


IFX_INLINE void IfxQspi_run(Ifx_QSPI *qspi)
{
    qspi->GLOBALCON.B.EN = 1;
}


IFX_INLINE void IfxQspi_setBitsegment1(Ifx_QSPI *qspi, IfxQspi_ChannelId channelId, uint8 bitSegment1)
{
    int cs = channelId % 8;
    qspi->ECON[cs].B.A = bitSegment1;
}


IFX_INLINE void IfxQspi_setBitsegment2(Ifx_QSPI *qspi, IfxQspi_ChannelId channelId, uint8 bitSegment2)
{
    int cs = channelId % 8;
    qspi->ECON[cs].B.B = bitSegment2;
}


IFX_INLINE void IfxQspi_setBitsegment3(Ifx_QSPI *qspi, IfxQspi_ChannelId channelId, uint8 bitSegment3)
{
    int cs = channelId % 8;
    qspi->ECON[cs].B.C = bitSegment3;
}


IFX_INLINE void IfxQspi_setDisableModuleRequest(Ifx_QSPI *qspi)
{
    qspi->CLC.B.DISR = 1;
}


IFX_INLINE void IfxQspi_setEnableModuleRequest(Ifx_QSPI *qspi)
{
    qspi->CLC.B.DISR = 0;
}


IFX_INLINE void IfxQspi_setMoveCounterInterruptAfterLastEnabled(Ifx_QSPI *qspi, boolean interruptEnabled)
{
    qspi->MCCON.B.IALEN = interruptEnabled;
}


IFX_INLINE void IfxQspi_setMoveCounterInterruptAfterLastFlag(Ifx_QSPI *qspi, boolean setInterrupt)
{
    qspi->MCCON.B.IALS = setInterrupt;
}


IFX_INLINE void IfxQspi_setMoveCounterInterruptBeforeLastEnabled(Ifx_QSPI *qspi, boolean interruptEnabled)
{
    qspi->MCCON.B.IBLEN = interruptEnabled;
}


IFX_INLINE void IfxQspi_setMoveCounterInterruptBeforeLastFlag(Ifx_QSPI *qspi, boolean setInterrupt)
{
    qspi->MCCON.B.IBLS = setInterrupt;
}


IFX_INLINE void IfxQspi_setMoveCounterPrescalerTrailingDelay(Ifx_QSPI *qspi, const float baudrate)
{
    qspi->MCCON.B.TPRE2 = IfxQspi_calculatePrescaler(qspi, baudrate);
}


IFX_INLINE void IfxQspi_setReceiveFifoInterrruptThreshold(Ifx_QSPI *qspi, IfxQspi_RxFifoInt rxFifoInt)
{
    qspi->GLOBALCON1.B.RXFIFOINT = rxFifoInt;
}


IFX_INLINE void IfxQspi_setRxFifoMode(Ifx_QSPI *qspi, IfxQspi_FifoMode mode)
{
    qspi->GLOBALCON1.B.RXFM = mode;
}


IFX_INLINE void IfxQspi_setSleepMode(Ifx_QSPI *qspi, IfxQspi_SleepMode mode)
{
    qspi->CLC.B.EDIS = mode;
}


IFX_INLINE void IfxQspi_setTimeQuantum(Ifx_QSPI *qspi, IfxQspi_ChannelId channelId, uint32 timeQuantum)
{
    int cs = channelId % 8;
    qspi->ECON[cs].B.Q = timeQuantum;
}


IFX_INLINE void IfxQspi_setTransmitFifoInterrruptThreshold(Ifx_QSPI *qspi, IfxQspi_TxFifoInt txFifoInt)
{
    qspi->GLOBALCON1.B.TXFIFOINT = txFifoInt;
}


IFX_INLINE void IfxQspi_setTxFifoMode(Ifx_QSPI *qspi, IfxQspi_FifoMode mode)
{
    qspi->GLOBALCON1.B.TXFM = mode;
}


IFX_INLINE void IfxQspi_trail2InjectionEnabled(Ifx_QSPI *qspi, boolean trail2Enabled)
{
    qspi->MCCON.B.T2EN = trail2Enabled;
}


IFX_INLINE void IfxQspi_writeBasicConfiguration(Ifx_QSPI *qspi, uint32 baconVal)
{
    qspi->BACONENTRY.U = baconVal;
}


IFX_INLINE void IfxQspi_writeBasicConfigurationBeginStream(Ifx_QSPI *qspi, uint32 baconVal)
{
    Ifx_QSPI_BACON bacon;
    bacon.U            = baconVal;
    bacon.B.LAST       = 0;

    qspi->BACONENTRY.U = bacon.U;
}


IFX_INLINE void IfxQspi_writeBasicConfigurationEndStream(Ifx_QSPI *qspi, uint32 baconVal)
{
    Ifx_QSPI_BACON bacon;
    bacon.U            = baconVal;
    bacon.B.LAST       = 1;

    qspi->BACONENTRY.U = bacon.U;
}


IFX_INLINE void IfxQspi_writeExtendedConfiguration(Ifx_QSPI *qspi, IfxQspi_ChannelId channelId, uint32 econVal)
{
    int cs = channelId % 8;
    qspi->ECON[cs].U = econVal;
}


IFX_INLINE void IfxQspi_writeMixedDataTransmitFifo(Ifx_QSPI *qspi, uint32 mixEntryVal)
{
    qspi->MIXENTRY.U = mixEntryVal;
}


IFX_INLINE void IfxQspi_writeTransmitFifo(Ifx_QSPI *qspi, uint32 data)
{
    qspi->DATAENTRY[0].U = data;
}


IFX_INLINE boolean IfxQspi_isModuleSuspended(Ifx_QSPI *qspi)
{
    Ifx_QSPI_OCS ocs;

    /* Read the status */
    ocs.U = qspi->OCS.U;

    /* Return the status */
    return ocs.B.SUSSTA;
}


IFX_INLINE void IfxQspi_setSuspendMode(Ifx_QSPI *qspi, IfxQspi_SuspendMode mode)
{
    Ifx_QSPI_OCS ocs;

    /* Remove protection and configure the suspend mode. */
    ocs.B.SUS_P = 1;
    ocs.B.SUS   = mode;
    qspi->OCS.U = ocs.U;
}


IFX_INLINE void IfxQspi_initMrstInPinWithPadLevel(const IfxQspi_Mrst_In *mrstIn, IfxPort_InputMode mrstInMode, IfxPort_PadDriver padDriver)
{
    IfxPort_setPinModeInput(mrstIn->pin.port, mrstIn->pin.pinIndex, mrstInMode);
    IfxPort_setPinPadDriver(mrstIn->pin.port, mrstIn->pin.pinIndex, padDriver);
    mrstIn->module->PISEL.B.MRIS = mrstIn->select;
}


IFX_INLINE void IfxQspi_initMtsrInPinWithPadLevel(const IfxQspi_Mtsr_In *mtsrIn, IfxPort_InputMode mtsrInMode, IfxPort_PadDriver padDriver)
{
    IfxPort_setPinModeInput(mtsrIn->pin.port, mtsrIn->pin.pinIndex, mtsrInMode);
    IfxPort_setPinPadDriver(mtsrIn->pin.port, mtsrIn->pin.pinIndex, padDriver);
    mtsrIn->module->PISEL.B.SRIS = mtsrIn->select;
}


IFX_INLINE void IfxQspi_initSclkInPinWithPadLevel(const IfxQspi_Sclk_In *sclkIn, IfxPort_InputMode sclkInMode, IfxPort_PadDriver padDriver)
{
    IfxPort_setPinModeInput(sclkIn->pin.port, sclkIn->pin.pinIndex, sclkInMode);
    IfxPort_setPinPadDriver(sclkIn->pin.port, sclkIn->pin.pinIndex, padDriver);
    sclkIn->module->PISEL.B.SCIS = sclkIn->select;
}


IFX_INLINE void IfxQspi_initSlsiWithPadLevel(const IfxQspi_Slsi_In *slsi, IfxPort_InputMode slsiMode, IfxPort_PadDriver padDriver)
{
    IfxPort_setPinModeInput(slsi->pin.port, slsi->pin.pinIndex, slsiMode);
    /* PISEL */
    IfxPort_setPinPadDriver(slsi->pin.port, slsi->pin.pinIndex, padDriver);
    slsi->module->PISEL.B.SLSIS = slsi->select + 1;
}


IFX_INLINE void IfxQspi_setBaconDelayParameters(Ifx_QSPI *qspi, IfxQspi_DelayParameters *config)
{
    Ifx_QSPI_BACON bacon;
    bacon.U            = qspi->BACON.U;
    bacon.B.IPRE       = config->idlePrescalar;
    bacon.B.IDLE       = config->idleDelay;
    bacon.B.LPRE       = config->leadingPrescalar;
    bacon.B.LEAD       = config->leadingDelay;
    bacon.B.TPRE       = config->trailingPrescalar;
    bacon.B.TRAIL      = config->trailingDelay;

    qspi->BACONENTRY.U = bacon.U;
}

IFX_INLINE void IfxQspi_initMrstOutLvdsPin(const IfxQspi_Mrst_Out *mrstOut, IfxPort_OutputMode mrstOutMode, IfxPort_PadDriver padDriver, IfxPort_LvdsConfig *mrstOutLvdsCfg)
{
    IfxPort_setPinModeOutput(mrstOut->pin.port, mrstOut->pin.pinIndex, mrstOutMode, mrstOut->select);
    IfxPort_setPinPadDriver(mrstOut->pin.port, mrstOut->pin.pinIndex, padDriver);
    IfxPort_setPinModeLVDS(mrstOut->pin.port, mrstOut->pin.pinIndex, (IfxPort_Mode)(mrstOut->select | mrstOutMode), mrstOutLvdsCfg);
}


IFX_INLINE void IfxQspi_initMtsrOutLvdsPin(const IfxQspi_Mtsr_Out *mtsrOut, IfxPort_OutputMode mtsrOutMode, IfxPort_PadDriver padDriver, IfxPort_LvdsConfig *mtsrOutLvdsCfg)
{
    IfxPort_setPinModeOutput(mtsrOut->pin.port, mtsrOut->pin.pinIndex, mtsrOutMode, mtsrOut->select);
    IfxPort_setPinPadDriver(mtsrOut->pin.port, mtsrOut->pin.pinIndex, padDriver);
    IfxPort_setPinModeLVDS(mtsrOut->pin.port, mtsrOut->pin.pinIndex, IfxPort_Mode_inputNoPullDevice, mtsrOutLvdsCfg);
}


IFX_INLINE void IfxQspi_initSclkOutLvdsPin(const IfxQspi_Sclk_Out *sclkOut, IfxPort_OutputMode sclkOutMode, IfxPort_PadDriver padDriver, IfxPort_LvdsConfig *sclkOutLvdsCfg)
{
    IfxPort_setPinModeOutput(sclkOut->pin.port, sclkOut->pin.pinIndex, sclkOutMode, sclkOut->select);
    IfxPort_setPinPadDriver(sclkOut->pin.port, sclkOut->pin.pinIndex, padDriver);
    IfxPort_setPinModeLVDS(sclkOut->pin.port, sclkOut->pin.pinIndex, (IfxPort_Mode)(sclkOut->select | sclkOutMode), sclkOutLvdsCfg);
}


IFX_INLINE void IfxQspi_initMrstInLvdsPinWithPadLevel(const IfxQspi_Mrst_In *mrstIn, IfxPort_InputMode mrstInMode, IfxPort_PadDriver padDriver, IfxPort_LvdsConfig *mrstInLvdsCfg)
{
    IfxPort_setPinModeInput(mrstIn->pin.port, mrstIn->pin.pinIndex, mrstInMode);
    IfxPort_setPinPadDriver(mrstIn->pin.port, mrstIn->pin.pinIndex, padDriver);
    IfxPort_setPinModeLVDS(mrstIn->pin.port, mrstIn->pin.pinIndex, (IfxPort_Mode)(mrstIn->select | mrstInMode), mrstInLvdsCfg);
    mrstIn->module->PISEL.B.MRIS = mrstIn->select;
}


IFX_INLINE void IfxQspi_initMtsrInLvdsPinWithPadLevel(const IfxQspi_Mtsr_In *mtsrIn, IfxPort_InputMode mtsrInMode, IfxPort_PadDriver padDriver, IfxPort_LvdsConfig *mtsrInLvdsCfg)
{
    IfxPort_setPinModeInput(mtsrIn->pin.port, mtsrIn->pin.pinIndex, mtsrInMode);
    IfxPort_setPinPadDriver(mtsrIn->pin.port, mtsrIn->pin.pinIndex, padDriver);
    IfxPort_setPinModeLVDS(mtsrIn->pin.port, mtsrIn->pin.pinIndex, IfxPort_Mode_inputNoPullDevice, mtsrInLvdsCfg);
    mtsrIn->module->PISEL.B.SRIS = mtsrIn->select;
}


IFX_INLINE void IfxQspi_initSclkInLvdsPinWithPadLevel(const IfxQspi_Sclk_In *sclkIn, IfxPort_InputMode sclkInMode, IfxPort_PadDriver padDriver, IfxPort_LvdsConfig *sclkInLvdsCfg)
{
    IfxPort_setPinModeInput(sclkIn->pin.port, sclkIn->pin.pinIndex, sclkInMode);
    IfxPort_setPinPadDriver(sclkIn->pin.port, sclkIn->pin.pinIndex, padDriver);
    IfxPort_setPinModeLVDS(sclkIn->pin.port, sclkIn->pin.pinIndex, IfxPort_Mode_inputNoPullDevice, sclkInLvdsCfg);
    sclkIn->module->PISEL.B.SCIS = sclkIn->select;
}

#endif /* IFXQSPI_H */
