/**
 * \file IfxCan.h
 * \brief CAN  basic functionality
 * \ingroup IfxLld_Can
 *
 * \version iLLD-TC4-v2.6.0
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
 * \defgroup IfxLld_Can_Std_Enum Enumerations
 * \ingroup IfxLld_Can_Std
 * \defgroup IfxLld_Can_Std_Data_Structures Data Structures
 * \ingroup IfxLld_Can_Std
 * \defgroup IfxLld_Can_Std_Node_Functions Node Functions
 * \ingroup IfxLld_Can_Std
 * \defgroup IfxLld_Can_Std_Tx_Element_Functions Tx Element Functions
 * \ingroup IfxLld_Can_Std
 * \defgroup IfxLld_Can_Std_Rx_Element_Functions Rx Element Functions
 * \ingroup IfxLld_Can_Std
 * \defgroup IfxLld_Can_Std_Filter_Functions Filter Functions
 * \ingroup IfxLld_Can_Std
 * \defgroup IfxLld_Can_Std_Interrupt_Functions Interrupt Functions
 * \ingroup IfxLld_Can_Std
 * \defgroup IfxLld_Can_Std_Module_Functions Module Functions
 * \ingroup IfxLld_Can_Std
 * \defgroup IfxLld_Can_Std_Tx_Event_FIFO_Element_Functions Tx Event FIFO Element Functions
 * \ingroup IfxLld_Can_Std
 */

#ifndef IFXCAN_H
#define IFXCAN_H 1

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include "_Impl/IfxCan_cfg.h"
#include "_PinMap/IfxCan_PinMap.h"
#include "Cpu/Std/IfxCpu_Intrinsics.h"
#include "_Utilities/Ifx_Assert.h"
#include "Src/Std/IfxSrc.h"
#include "Clock/Std/IfxClock.h"
#include "Ap/Std/IfxApProt.h"
#include "Ap/Std/IfxApApu.h"

/******************************************************************************/
/*--------------------------------Enumerations--------------------------------*/
/******************************************************************************/

/** \addtogroup IfxLld_Can_Std_Enum
 * \{ */
/** \brief CAN node Bus Off status
 */
typedef enum
{
    IfxCan_CanNodeBusOffErrorStatus_NoErr     = 0, /**< \brief CAN node not in Bus Off state */
    IfxCan_CanNodeBusOffErrorStatus_BusOffErr = 1  /**< \brief CAN node in Bus Off state */
} IfxCan_CanNodeBusOffErrorStatus;

/** \brief CAN node communication state
 */
typedef enum
{
    IfxCan_CanNodeCommunicationState_synchronize = 0,  /**< \brief CAN node is synchronizing on CAN communication */
    IfxCan_CanNodeCommunicationState_idle        = 1,  /**< \brief Node is neither receiving nor transmitting */
    IfxCan_CanNodeCommunicationState_receive     = 2,  /**< \brief Node is operating as receiver */
    IfxCan_CanNodeCommunicationState_transmit    = 3   /**< \brief Node is operating as transmitter */
} IfxCan_CanNodeCommunicationState;

/** \brief Status of warning limit for error counters in CAN node
 * Definition in Ifx_CAN_N_PSR.B.EW
 */
typedef enum
{
    IfxCan_CanNodeErrorWarningLimitStatus_notReached = 0,  /**< \brief Error counters are below the warning limit */
    IfxCan_CanNodeErrorWarningLimitStatus_reached    = 1   /**< \brief Error counter reached the warning limit */
} IfxCan_CanNodeErrorWarningLimitStatus;

/** \brief Clock selection option\n
 * Description in Ifx_CAN.MCR.CLKSELx, (x = 0,1,2)
 */
typedef enum
{
    IfxCan_ClockSelect_0,  /**< \brief clock selection 0 */
    IfxCan_ClockSelect_1,  /**< \brief clock selection 1 */
    IfxCan_ClockSelect_2,  /**< \brief clock selection 2 */
    IfxCan_ClockSelect_3   /**< \brief clock selection 3 */
} IfxCan_ClockSelect;

/** \brief Type of Clock Source selection\n
 * Description in Ifx_CAN.MCR.CLKSELx, (x = 0,1,2)
 */
typedef enum
{
    IfxCan_ClockSource_noClock      = 0,  /**< \brief No clock is switched on */
    IfxCan_ClockSource_asynchronous = 1,  /**< \brief The Asynchronous clock source is switched on */
    IfxCan_ClockSource_synchronous  = 2,  /**< \brief The Synchronous clock source is switched on */
    IfxCan_ClockSource_both         = 3   /**< \brief Both clock sources are switched on */
} IfxCan_ClockSource;

/** \brief Type of Cre interrupt\n
 * Definition in  Ifx_CAN.N[x].CRE.IR
 */
typedef enum
{
    IfxCan_CreInterrupt_RxBuffer0,                        /**< \brief CRE RX Buffer 0 Interrupt */
    IfxCan_CreInterrupt_RxBuffer1,                        /**< \brief CRE RX Buffer 1 Interrupt */
    IfxCan_CreInterrupt_TxBuffer0,                        /**< \brief CRE THBUF 0 Interrupt */
    IfxCan_CreInterrupt_TxBuffer1,                        /**< \brief CRE THBUF 1 Interrupt */
    IfxCan_CreInterrupt_IdmuStdFrameRateMeasurementLost,  /**< \brief CRE IDMU Standard Frame Rate Measurement Lost Interrupt */
    IfxCan_CreInterrupt_IdmuXtdFrameRateMeasurementLost,  /**< \brief CRE IDMU Extended Frame Rate Measurement Lost Interrupt */
    IfxCan_CreInterrupt_IncorrectReadSequenceError0,      /**< \brief CRE Incorrect Read Sequence Error Interrupt 0 */
    IfxCan_CreInterrupt_IncorrectReadSequenceError1,      /**< \brief CRE Incorrect Read Sequence Error Interrupt 1 */
    IfxCan_CreInterrupt_IncorrectWriteSequenceError0,     /**< \brief CRE Incorrect Write Sequence Error Interrupt 0 */
    IfxCan_CreInterrupt_IncorrectWriteSequenceError1,     /**< \brief CRE Incorrect Write Sequence Error Interrupt 0 */
    IfxCan_CreInterrupt_CrcError0,                        /**< \brief CRE CRC Error Interrupt 0 */
    IfxCan_CreInterrupt_CrcError1,                        /**< \brief CRE CRC Error Interrupt 1 */
    IfxCan_CreInterrupt_Rx0WatchdogTimeoutError,          /**< \brief CRE RHBUF0 Watchdog Timeout Error Interrupt */
    IfxCan_CreInterrupt_Rx1WatchdogTimeoutError,          /**< \brief CRE RHBUF1 Watchdog Timeout Error Interrupt */
    IfxCan_CreInterrupt_Tx0WatchdogTimeoutError,          /**< \brief CRE THBUF0 Watchdog Timeout Error Interrupt */
    IfxCan_CreInterrupt_Tx1WatchdogTimeoutError           /**< \brief CRE THBUF0 Watchdog Timeout Error Interrupt */
} IfxCan_CreInterrupt;

/** \brief RHBUF Index in CRE
 */
typedef enum
{
    IfxCan_CreRxHostBufferIndex_0 = 0,  /**< \brief RHBUF 0 */
    IfxCan_CreRxHostBufferIndex_1       /**< \brief RHBUF 1 */
} IfxCan_CreRxHostBufferIndex;

/** \brief Status of Time Stamp in CRE\n
 */
typedef enum
{
    IfxCan_CreTimeStampCaptured_invalid = 0,  /**< \brief Time Stamp is not available/invalid. */
    IfxCan_CreTimeStampCaptured_valid   = 1   /**< \brief Time Stamp is available/valid. */
} IfxCan_CreTimeStampCaptured;

/** \brief Type of Time Stamp in CRE\n
 */
typedef enum
{
    IfxCan_CreTimeStampType_16bit = 0,  /**< \brief Internal 16 bit Time Stamp is used. */
    IfxCan_CreTimeStampType_32bit = 1   /**< \brief 32 bit TSU Time Stamp is used. */
} IfxCan_CreTimeStampType;

/** \brief THBUF Index in CRE
 */
typedef enum
{
    IfxCan_CreTxHostBufferIndex_0 = 0,  /**< \brief THBUF 0 */
    IfxCan_CreTxHostBufferIndex_1       /**< \brief THBUF 1 */
} IfxCan_CreTxHostBufferIndex;

/** \brief Data Field Size\n
 * Definition in Ifx_CAN.N[x]TX.ESC.B.TBDS, Ifx_CAN.N[x].RX.ESC.B.RBDS, Ifx_CAN.N[x].RX.ESC.B.FyDS (x= 0,1,2,3; y = 0, 1)
 */
typedef enum
{
    IfxCan_DataFieldSize_8,   /**< \brief 8 byte data field */
    IfxCan_DataFieldSize_12,  /**< \brief 12 byte data field */
    IfxCan_DataFieldSize_16,  /**< \brief 16 byte data field */
    IfxCan_DataFieldSize_20,  /**< \brief 20 byte data field */
    IfxCan_DataFieldSize_24,  /**< \brief 24 byte data field */
    IfxCan_DataFieldSize_32,  /**< \brief 32 byte data field */
    IfxCan_DataFieldSize_48,  /**< \brief 48 byte data field */
    IfxCan_DataFieldSize_64   /**< \brief 64 byte data field */
} IfxCan_DataFieldSize;

/** \brief Data Length code of the Message\n
 * Definition in Ifx_CAN_R1.B.DLC or Ifx_CAN_TXEVENT_E1.B.DLC or Ifx_CAN_TXMSG_T1.B.DLC
 */
typedef enum
{
    IfxCan_DataLengthCode_0,   /**< \brief 0 data bytes */
    IfxCan_DataLengthCode_1,   /**< \brief 1 data bytes */
    IfxCan_DataLengthCode_2,   /**< \brief 2 data bytes */
    IfxCan_DataLengthCode_3,   /**< \brief 3 data bytes */
    IfxCan_DataLengthCode_4,   /**< \brief 4 data bytes */
    IfxCan_DataLengthCode_5,   /**< \brief 5 data bytes */
    IfxCan_DataLengthCode_6,   /**< \brief 6 data bytes */
    IfxCan_DataLengthCode_7,   /**< \brief 7 data bytes */
    IfxCan_DataLengthCode_8,   /**< \brief 8 data bytes */
    IfxCan_DataLengthCode_12,  /**< \brief 12 data bytes */
    IfxCan_DataLengthCode_16,  /**< \brief 16 data bytes */
    IfxCan_DataLengthCode_20,  /**< \brief 20 data bytes */
    IfxCan_DataLengthCode_24,  /**< \brief 24 data bytes */
    IfxCan_DataLengthCode_32,  /**< \brief 32 data bytes */
    IfxCan_DataLengthCode_48,  /**< \brief 48 data bytes */
    IfxCan_DataLengthCode_64   /**< \brief 64 data bytes */
} IfxCan_DataLengthCode;

/** \brief Destination IDs for Routing rules.
 * Reference for DID values is the Routing destinations ID map Table in DRE UM.
 */
typedef enum
{
    IfxCan_DestinationId_none       = 0,  /**< \brief No Destination */
    IfxCan_DestinationId_Can0_Node0 = 1,  /**< \brief Node 0 of MCMCAN0 */
    IfxCan_DestinationId_Can0_Node1,      /**< \brief Node 1 of MCMCAN0 */
    IfxCan_DestinationId_Can0_Node2,      /**< \brief Node 2 of MCMCAN0 */
    IfxCan_DestinationId_Can0_Node3,      /**< \brief Node 3 of MCMCAN0 */
    IfxCan_DestinationId_Can1_Node0,      /**< \brief Node 0 of MCMCAN1 */
    IfxCan_DestinationId_Can1_Node1,      /**< \brief Node 1 of MCMCAN1 */
    IfxCan_DestinationId_Can1_Node2,      /**< \brief Node 2 of MCMCAN1 */
    IfxCan_DestinationId_Can1_Node3,      /**< \brief Node 3 of MCMCAN1 */
#if IFXCAN_NUM_MODULES > 2	
    IfxCan_DestinationId_Can2_Node0,      /**< \brief Node 0 of MCMCAN2 */
    IfxCan_DestinationId_Can2_Node1,      /**< \brief Node 1 of MCMCAN2 */
    IfxCan_DestinationId_Can2_Node2,      /**< \brief Node 2 of MCMCAN2 */
    IfxCan_DestinationId_Can2_Node3,      /**< \brief Node 3 of MCMCAN2 */
#endif /* #if IFXCAN_NUM_MODULES > 2 */	
#if IFXCAN_NUM_MODULES > 3	
    IfxCan_DestinationId_Can3_Node0,      /**< \brief Node 0 of MCMCAN3 */
    IfxCan_DestinationId_Can3_Node1,      /**< \brief Node 1 of MCMCAN3 */
    IfxCan_DestinationId_Can3_Node2,      /**< \brief Node 2 of MCMCAN3 */
    IfxCan_DestinationId_Can3_Node3,      /**< \brief Node 3 of MCMCAN3 */
#endif /* #if IFXCAN_NUM_MODULES > 3 */	
#if IFXCAN_NUM_MODULES > 4		
    IfxCan_DestinationId_Can4_Node0,      /**< \brief Node 0 of MCMCAN4 */
    IfxCan_DestinationId_Can4_Node1,      /**< \brief Node 1 of MCMCAN4 */
    IfxCan_DestinationId_Can4_Node2,      /**< \brief Node 2 of MCMCAN4 */
    IfxCan_DestinationId_Can4_Node3,      /**< \brief Node 3 of MCMCAN4 */
#endif /* #if IFXCAN_NUM_MODULES > 4 */
    IfxCan_DestinationId_Ethernet1 = 24,  /**< \brief Ethernet Output Buffer 1 */
    IfxCan_DestinationId_Ethernet2,       /**< \brief Ethernet Output Buffer 2 */
    IfxCan_DestinationId_Ethernet3,       /**< \brief Ethernet Output Buffer 3 */
    IfxCan_DestinationId_Ethernet4,       /**< \brief Ethernet Output Buffer 4 */
    IfxCan_DestinationId_Ethernet5,       /**< \brief Ethernet Output Buffer 5 */
    IfxCan_DestinationId_Ethernet6,       /**< \brief Ethernet Output Buffer 6 */
    IfxCan_DestinationId_Memory1 = 32,    /**< \brief RAM location 1 */
    IfxCan_DestinationId_Memory2,         /**< \brief RAM location 2 */
    IfxCan_DestinationId_Memory3,         /**< \brief RAM location 3 */
    IfxCan_DestinationId_Memory4,         /**< \brief RAM location 4 */
    IfxCan_DestinationId_Memory5,         /**< \brief RAM location 5 */
    IfxCan_DestinationId_Memory6,         /**< \brief RAM location 6 */
    IfxCan_DestinationId_Memory7,         /**< \brief RAM location 7 */
    IfxCan_DestinationId_Memory8,         /**< \brief RAM location 8 */
    IfxCan_DestinationId_Memory9,         /**< \brief RAM location 9 */
    IfxCan_DestinationId_Memory10,        /**< \brief RAM location 10 */
    IfxCan_DestinationId_Memory11,        /**< \brief RAM location 11 */
    IfxCan_DestinationId_Memory12,        /**< \brief RAM location 12 */
    IfxCan_DestinationId_Memory13,        /**< \brief RAM location 13 */
    IfxCan_DestinationId_Memory14,        /**< \brief RAM location 14 */
    IfxCan_DestinationId_Memory15,        /**< \brief RAM location 15 */
    IfxCan_DestinationId_Memory16,        /**< \brief RAM location 16 */
    IfxCan_DestinationId_Memory17,        /**< \brief RAM location 17 */
    IfxCan_DestinationId_Memory18,        /**< \brief RAM location 18 */
    IfxCan_DestinationId_Memory19,        /**< \brief RAM location 19 */
    IfxCan_DestinationId_Memory20,        /**< \brief RAM location 20 */
    IfxCan_DestinationId_Memory21,        /**< \brief RAM location 21 */
    IfxCan_DestinationId_Memory22,        /**< \brief RAM location 22 */
    IfxCan_DestinationId_Memory23,        /**< \brief RAM location 23 */
    IfxCan_DestinationId_Memory24,        /**< \brief RAM location 24 */
    IfxCan_DestinationId_Memory25,        /**< \brief RAM location 25 */
    IfxCan_DestinationId_Memory26,        /**< \brief RAM location 26 */
    IfxCan_DestinationId_Memory27,        /**< \brief RAM location 27 */
    IfxCan_DestinationId_Memory28         /**< \brief RAM location 28 */
} IfxCan_DestinationId;

/** \brief Prescalar for External CAN Timer
 * Defined in N.TIMER.CCR.B.TPSC
 */
typedef enum
{
    IfxCan_ExtTimerPrescalar_1 = 0,  /**< \brief Prescalar for Clock is 1 */
    IfxCan_ExtTimerPrescalar_2,      /**< \brief Prescalar for Clock is 2 */
    IfxCan_ExtTimerPrescalar_3,      /**< \brief Prescalar for Clock is 3 */
    IfxCan_ExtTimerPrescalar_4,      /**< \brief Prescalar for Clock is 4 */
    IfxCan_ExtTimerPrescalar_5,      /**< \brief Prescalar for Clock is 5 */
    IfxCan_ExtTimerPrescalar_6,      /**< \brief Prescalar for Clock is 6 */
    IfxCan_ExtTimerPrescalar_7,      /**< \brief Prescalar for Clock is 7 */
    IfxCan_ExtTimerPrescalar_8,      /**< \brief Prescalar for Clock is 8 */
    IfxCan_ExtTimerPrescalar_9,      /**< \brief Prescalar for Clock is 9 */
    IfxCan_ExtTimerPrescalar_10,     /**< \brief Prescalar for Clock is 10 */
    IfxCan_ExtTimerPrescalar_11,     /**< \brief Prescalar for Clock is 11 */
    IfxCan_ExtTimerPrescalar_12,     /**< \brief Prescalar for Clock is 12 */
    IfxCan_ExtTimerPrescalar_13,     /**< \brief Prescalar for Clock is 13 */
    IfxCan_ExtTimerPrescalar_14,     /**< \brief Prescalar for Clock is 14 */
    IfxCan_ExtTimerPrescalar_15,     /**< \brief Prescalar for Clock is 15 */
    IfxCan_ExtTimerPrescalar_16      /**< \brief Prescalar for Clock is 16 */
} IfxCan_ExtTimerPrescalar;

/** \brief Filter Element Configuration
 * Definition in Ifx_CAN_STDMSG_S0.B.SFEC or Ifx_CAN_EXTMSG_F0.B.EFEC
 */
typedef enum
{
    IfxCan_FilterElementConfiguration_disable,                     /**< \brief Disable filter element */
    IfxCan_FilterElementConfiguration_storeInRxFifo0,              /**< \brief Store in Rx FIFO 0 if filter matches */
    IfxCan_FilterElementConfiguration_storeInRxFifo1,              /**< \brief Store in Rx FIFO 1 if filter matches */
    IfxCan_FilterElementConfiguration_rejectId,                    /**< \brief Reject ID if filter matches */
    IfxCan_FilterElementConfiguration_setPriority,                 /**< \brief Set priority if filter matches */
    IfxCan_FilterElementConfiguration_setPriorityAndStoreInFifo0,  /**< \brief Set priority and store in FIFO 0 if filter matches */
    IfxCan_FilterElementConfiguration_setPriorityAndStoreInFifo1,  /**< \brief Set priority and store in FIFO 1 if filter matches */
    IfxCan_FilterElementConfiguration_storeInRxBuffer              /**< \brief Store into Rx Buffer */
} IfxCan_FilterElementConfiguration;

/** \brief CAN frame format type
 * Definition in Ifx_CAN_TXEVENT.E1A.B.FDF or Ifx_CAN_TXEVENT.E1B.B.FDF
 */
typedef enum
{
    IfxCan_FrameFormatType_standard,  /**< \brief Standard format */
    IfxCan_FrameFormatType_fd         /**< \brief FD format */
} IfxCan_FrameFormatType;

/** \brief CAN Frame mode\n
 * Description in Ifx_CAN.N[x].CCCR.CME, (x= 0 to 3)
 */
typedef enum
{
    IfxCan_FrameMode_standard,      /**< \brief Standard CAN frame (transmit and receive) */
    IfxCan_FrameMode_fdLong,        /**< \brief CAN FD long frame in transmit and CAN FD long and fast frame in receive */
    IfxCan_FrameMode_fdLongAndFast  /**< \brief CAN FD long and fast frames (transmit and receive) */
} IfxCan_FrameMode;

/** \brief CAN frame type
 */
typedef enum
{
    IfxCan_FrameType_receive,             /**< \brief Data frame is received */
    IfxCan_FrameType_transmit,            /**< \brief Data frame is generated */
    IfxCan_FrameType_transmitAndReceive,  /**< \brief for both transmit and receive frames */
    IfxCan_FrameType_remoteRequest,       /**< \brief Remote request frame is generated */
    IfxCan_FrameType_remoteAnswer         /**< \brief Answer frame is generated on reception of the corresponding remote request */
} IfxCan_FrameType;

/** \brief Prescalar for Internal CAN Timer
 */
typedef enum
{
    IfxCan_IntTimerPrescalar_1 = 0,  /**< \brief Prescalar for Clock is 1 */
    IfxCan_IntTimerPrescalar_2,      /**< \brief Prescalar for Clock is 2 */
    IfxCan_IntTimerPrescalar_3,      /**< \brief Prescalar for Clock is 3 */
    IfxCan_IntTimerPrescalar_4,      /**< \brief Prescalar for Clock is 4 */
    IfxCan_IntTimerPrescalar_5,      /**< \brief Prescalar for Clock is 5 */
    IfxCan_IntTimerPrescalar_6,      /**< \brief Prescalar for Clock is 6 */
    IfxCan_IntTimerPrescalar_7,      /**< \brief Prescalar for Clock is 7 */
    IfxCan_IntTimerPrescalar_8,      /**< \brief Prescalar for Clock is 8 */
    IfxCan_IntTimerPrescalar_9,      /**< \brief Prescalar for Clock is 9 */
    IfxCan_IntTimerPrescalar_10,     /**< \brief Prescalar for Clock is 10 */
    IfxCan_IntTimerPrescalar_11,     /**< \brief Prescalar for Clock is 11 */
    IfxCan_IntTimerPrescalar_12,     /**< \brief Prescalar for Clock is 12 */
    IfxCan_IntTimerPrescalar_13,     /**< \brief Prescalar for Clock is 13 */
    IfxCan_IntTimerPrescalar_14,     /**< \brief Prescalar for Clock is 14 */
    IfxCan_IntTimerPrescalar_15,     /**< \brief Prescalar for Clock is 15 */
    IfxCan_IntTimerPrescalar_16      /**< \brief Prescalar for Clock is 16 */
} IfxCan_IntTimerPrescalar;

/** \brief CRE IDMU: Satus of Frame Inter Arrival Measurement\n
 */
typedef enum
{
    IfxCan_InterArrivalMeasureStatus_unavailable = 0,  /**< \brief IAM is not available/invalid. */
    IfxCan_InterArrivalMeasureStatus_available   = 1   /**< \brief IAM is available/valid. */
} IfxCan_InterArrivalMeasureStatus;

/** \brief Type of interrupt\n
 * Definition in Ifx_CAN.N[x].IE, Ifx_CAN.N[x].IR, Ifx_CAN.N[x].ILS, (x= 0 to 3) and Ifx_CAN.N[x].CRE.IR. Note index of CRE Interrupts should not be taken from here.
 */
typedef enum
{
    IfxCan_Interrupt_rxFifo0NewMessage,                   /**< \brief Rx FIFO 0 New Message Interrupt */
    IfxCan_Interrupt_rxFifo0WatermarkReached,             /**< \brief Rx FIFO 0 Watermark Reached Interrupt */
    IfxCan_Interrupt_rxFifo0Full,                         /**< \brief Rx FIFO 0 Full Interrupt */
    IfxCan_Interrupt_rxFifo0MessageLost,                  /**< \brief Rx FIFO 0 Message Lost Interrupt */
    IfxCan_Interrupt_rxFifo1NewMessage,                   /**< \brief Rx FIFO 1 New Message Interrupt */
    IfxCan_Interrupt_rxFifo1WatermarkReached,             /**< \brief Rx FIFO 1 Watermark Reached Interrupt */
    IfxCan_Interrupt_rxFifo1Full,                         /**< \brief Rx FIFO 1 Full Interrupt */
    IfxCan_Interrupt_rxFifo1MessageLost,                  /**< \brief Rx FIFO 1 Message Lost Interrupt */
    IfxCan_Interrupt_highPriorityMessage,                 /**< \brief High Priority Message Interrupt */
    IfxCan_Interrupt_transmissionCompleted,               /**< \brief Transmission Completed Interrupt */
    IfxCan_Interrupt_transmissionCancellationFinished,    /**< \brief Transmission Cancellation Finished Interrupt */
    IfxCan_Interrupt_txFifoEmpty,                         /**< \brief Tx FIFO Empty Interrupt */
    IfxCan_Interrupt_txEventFifoNewEntry,                 /**< \brief Tx Event FIFO New Entry Interrupt */
    IfxCan_Interrupt_txEventFifoWatermarkReached,         /**< \brief Tx Event FIFO Watermark Reached Interrupt */
    IfxCan_Interrupt_txEventFifoFull,                     /**< \brief Tx Event FIFO Full Interrupt */
    IfxCan_Interrupt_txEventFifoEventLost,                /**< \brief Tx Event FIFO Event Lost Interrupt */
    IfxCan_Interrupt_timestampWraparound,                 /**< \brief Timestamp Wraparound Interrupt */
    IfxCan_Interrupt_messageRAMAccessFailure,             /**< \brief Message RAM Access Failure Interrupt */
    IfxCan_Interrupt_timeoutOccurred,                     /**< \brief Timeout Occurred Interrupt */
    IfxCan_Interrupt_messageStoredToDedicatedRxBuffer,    /**< \brief Message stored to Dedicated Rx Buffer Interrupt */
    IfxCan_Interrupt_errorLoggingOverflow = 22,           /**< \brief Error Logging Overflow Interrupt */
    IfxCan_Interrupt_errorPassive,                        /**< \brief Error Passive Interrupt */
    IfxCan_Interrupt_warningStatus,                       /**< \brief Warning Status Interrupt */
    IfxCan_Interrupt_busOffStatus,                        /**< \brief Bus_Off Status Interrupt */
    IfxCan_Interrupt_watchdog,                            /**< \brief Watchdog Interrupt */
    IfxCan_Interrupt_protocolErrorArbitration,            /**< \brief Protocol Error in Arbitration phase Interrupt */
    IfxCan_Interrupt_protocolErrorData,                   /**< \brief Protocol Error in Data phase Interrupt */
    IfxCan_Interrupt_creRxBuffer0,                        /**< \brief (Not for Absolute Indexing, kept to configure G2INTR) CRE RX Buffer 0 Interrupt */
    IfxCan_Interrupt_creRxBuffer1,                        /**< \brief (Not for Absolute Indexing,, kept to configure G2INTR) CRE RX Buffer 1 Interrupt */
    IfxCan_Interrupt_creTxBuffer0,                        /**< \brief (Not for Absolute Indexing, kept to configure G2INTR) CRE TX Buffer 0 Interrupt */
    IfxCan_Interrupt_creTxBuffer1,                        /**< \brief (Not for Absolute Indexing, kept to configure G2INTR) CRE TX Buffer 1 Interrupt */
    IfxCan_Interrupt_creIdmuStdFrameRateMeasurementLost,  /**< \brief (Not for Absolute Indexing, kept to configure G2INTR) CRE IDMU Standard Frame Rate Measurement Lost Interrupt */
    IfxCan_Interrupt_creIdmuXtdFrameRateMeasurementLost,  /**< \brief (Not for Absolute Indexing, kept to configure G2INTR) CRE IDMU Extended Frame Rate Measurement Lost Interrupt */
    IfxCan_Interrupt_creError                             /**< \brief (Not for Absolute Indexing, kept to configure G2INTR) CRE Error Interrupt */
} IfxCan_Interrupt;

/** \brief Type of interrupt\n
 * Definition in Ifx_CAN.N.G[x]INTR (x= 0, 1, 2)
 */
typedef enum
{
    IfxCan_InterruptGroup_tefifo,   /**< \brief Transmit Event FIFO Incidents */
    IfxCan_InterruptGroup_hpe,      /**< \brief High Priority Events */
    IfxCan_InterruptGroup_wati,     /**< \brief Watermark interrupts are mapped here. */
    IfxCan_InterruptGroup_alrt,     /**< \brief Alerts */
    IfxCan_InterruptGroup_moer,     /**< \brief Module errors */
    IfxCan_InterruptGroup_safe,     /**< \brief Safety counter overflow */
    IfxCan_InterruptGroup_boff,     /**< \brief Bus Off */
    IfxCan_InterruptGroup_loi,      /**< \brief Last Error Interrupts */
    IfxCan_InterruptGroup_reint,    /**< \brief Message stored in dedicated receive buffer interrupt (IR.DRX) */
    IfxCan_InterruptGroup_rxf1f,    /**< \brief Receive FIFO1 full interrupt */
    IfxCan_InterruptGroup_rxf0f,    /**< \brief Receive FIFO0 full interrupt */
    IfxCan_InterruptGroup_rxf1n,    /**< \brief Receive FIFO1 new message Interrupt */
    IfxCan_InterruptGroup_rxf0n,    /**< \brief Receive FIFO0 new message Interrupt */
    IfxCan_InterruptGroup_reti,     /**< \brief Receive timeouts */
    IfxCan_InterruptGroup_traq,     /**< \brief Transmission Queue Events */
    IfxCan_InterruptGroup_traco,    /**< \brief Interrupts of the transmission control */
    IfxCan_InterruptGroup_rxHBuf0,  /**< \brief Interrupts of CRE Rx host buffer 0 */
    IfxCan_InterruptGroup_rxHBuf1,  /**< \brief Interrupts of CRE Rx host buffer 1 */
    IfxCan_InterruptGroup_txHBuf0,  /**< \brief Interrupts of CRE Tx host buffer 0 */
    IfxCan_InterruptGroup_txHBuf1,  /**< \brief Interrupts of CRE Tx host buffer 1 */
    IfxCan_InterruptGroup_idmu,     /**< \brief Interrupts of IDMU relevant interrupts */
    IfxCan_InterruptGroup_cre       /**< \brief Interrupts of CRE Error interrupts (CRE_IR.IRSI, CRE_IR.IWSI, CRE_IR.CRCI, RE_IR.RWDTI, CRE_IR.TWDTI) */
} IfxCan_InterruptGroup;

/** \brief Interrupt line number INT_Ox (x= 0 - 15) \n
 * Definition in Ifx_CAN_N_GRINT1 or Ifx_CAN_N_GRINT2
 */
typedef enum
{
    IfxCan_InterruptLine_0,   /**< \brief Interrupt Line 0 */
    IfxCan_InterruptLine_1,   /**< \brief Interrupt Line 1 */
    IfxCan_InterruptLine_2,   /**< \brief Interrupt Line 2 */
    IfxCan_InterruptLine_3,   /**< \brief Interrupt Line 3 */
    IfxCan_InterruptLine_4,   /**< \brief Interrupt Line 4 */
    IfxCan_InterruptLine_5,   /**< \brief Interrupt Line 5 */
    IfxCan_InterruptLine_6,   /**< \brief Interrupt Line 6 */
    IfxCan_InterruptLine_7,   /**< \brief Interrupt Line 7 */
    IfxCan_InterruptLine_8,   /**< \brief Interrupt Line 8 */
    IfxCan_InterruptLine_9,   /**< \brief Interrupt Line 9 */
    IfxCan_InterruptLine_10,  /**< \brief Interrupt Line 10 */
    IfxCan_InterruptLine_11,  /**< \brief Interrupt Line 11 */
    IfxCan_InterruptLine_12,  /**< \brief Interrupt Line 12 */
    IfxCan_InterruptLine_13,  /**< \brief Interrupt Line 13 */
    IfxCan_InterruptLine_14,  /**< \brief Interrupt Line 14 */
    IfxCan_InterruptLine_15   /**< \brief Interrupt Line 15 */
} IfxCan_InterruptLine;

/** \brief Type of last error to occur on the CAN node
 * Definition in Ifx_CAN_N_PSR.B.LEC or Ifx_CAN_N_PSR.B.DLEC
 */
typedef enum
{
    IfxCan_LastErrorCodeType_noError       = 0, /**< \brief No Error occured in the recent CAN message transmission or reception. */
    IfxCan_LastErrorCodeType_stuffError    = 1, /**< \brief More than 5 consecutive equal bits recieved in CAN message */
    IfxCan_LastErrorCodeType_formError     = 2, /**< \brief Fixed format part of recieved frame has wrong format */
    IfxCan_LastErrorCodeType_ackError      = 3, /**< \brief No ACK recieved from another node for transmitted CAN message */
    IfxCan_LastErrorCodeType_bit1Error     = 4, /**< \brief Transmitted recessive and read back dominant on the CAN bus. */
    IfxCan_LastErrorCodeType_bit0Error     = 5, /**< \brief Transmitted dominant and read back recessive on the CAN bus. */
    IfxCan_LastErrorCodeType_crcError      = 6, /**< \brief CRC Error */
    IfxCan_LastErrorCodeType_noCANBusEvent = 7  /**< \brief No CAN bus event occured */
} IfxCan_LastErrorCodeType;

/** \brief Message Id length (Standard / Extended)
 * Definition in Ifx_CAN_TXMSG_T0.B.XTD or Ifx_CAN_R0.B.XTD or Ifx_CAN_TXEVENT_E0.B.XTD
 */
typedef enum
{
    IfxCan_MessageIdLength_standard,  /**< \brief Standard Message ID */
    IfxCan_MessageIdLength_extended,  /**< \brief Extended Message ID */
    IfxCan_MessageIdLength_both       /**< \brief Both Standard and Extended message IDs */
} IfxCan_MessageIdLength;

/** \brief Indicate the action to be taken with the messages which do not match with any element of the filter.
 * Definition in Ifx_CAN_N_GFC.B.ANFS or Ifx_CAN_N_GFC.B.ANFE
 */
typedef enum
{
    IfxCan_NonMatchingFrame_acceptToRxFifo0 = 0,  /**< \brief Accept the non matching messages into Rx FIFO 0 */
    IfxCan_NonMatchingFrame_acceptToRxFifo1 = 1,  /**< \brief Accepts the non matching messages into Rx FIFO 1 */
    IfxCan_NonMatchingFrame_reject          = 2   /**< \brief Reject the non-matching messages */
} IfxCan_NonMatchingFrame;

/** \brief Tx event FIFO Read Status
 */
typedef enum
{
    IfxCan_ReadTxEventStatus_readSuccessful,      /**< \brief Tx event FIFO read successful */
    IfxCan_ReadTxEventStatus_elementNotAvailable  /**< \brief Tx event FIFO read failed, element not available */
} IfxCan_ReadTxEventStatus;

/** \brief Rx Buffer number
 */
typedef enum
{
    IfxCan_RxBufferId_0,   /**< \brief Rx buffer 0 */
    IfxCan_RxBufferId_1,   /**< \brief Rx buffer 1 */
    IfxCan_RxBufferId_2,   /**< \brief Rx buffer 2 */
    IfxCan_RxBufferId_3,   /**< \brief Rx buffer 3 */
    IfxCan_RxBufferId_4,   /**< \brief Rx buffer 4 */
    IfxCan_RxBufferId_5,   /**< \brief Rx buffer 5 */
    IfxCan_RxBufferId_6,   /**< \brief Rx buffer 6 */
    IfxCan_RxBufferId_7,   /**< \brief Rx buffer 7 */
    IfxCan_RxBufferId_8,   /**< \brief Rx buffer 8 */
    IfxCan_RxBufferId_9,   /**< \brief Rx buffer 9 */
    IfxCan_RxBufferId_10,  /**< \brief Rx buffer 10 */
    IfxCan_RxBufferId_11,  /**< \brief Rx buffer 11 */
    IfxCan_RxBufferId_12,  /**< \brief Rx buffer 12 */
    IfxCan_RxBufferId_13,  /**< \brief Rx buffer 13 */
    IfxCan_RxBufferId_14,  /**< \brief Rx buffer 14 */
    IfxCan_RxBufferId_15,  /**< \brief Rx buffer 15 */
    IfxCan_RxBufferId_16,  /**< \brief Rx buffer 16 */
    IfxCan_RxBufferId_17,  /**< \brief Rx buffer 17 */
    IfxCan_RxBufferId_18,  /**< \brief Rx buffer 18 */
    IfxCan_RxBufferId_19,  /**< \brief Rx buffer 19 */
    IfxCan_RxBufferId_20,  /**< \brief Rx buffer 20 */
    IfxCan_RxBufferId_21,  /**< \brief Rx buffer 21 */
    IfxCan_RxBufferId_22,  /**< \brief Rx buffer 22 */
    IfxCan_RxBufferId_23,  /**< \brief Rx buffer 23 */
    IfxCan_RxBufferId_24,  /**< \brief Rx buffer 24 */
    IfxCan_RxBufferId_25,  /**< \brief Rx buffer 25 */
    IfxCan_RxBufferId_26,  /**< \brief Rx buffer 26 */
    IfxCan_RxBufferId_27,  /**< \brief Rx buffer 27 */
    IfxCan_RxBufferId_28,  /**< \brief Rx buffer 28 */
    IfxCan_RxBufferId_29,  /**< \brief Rx buffer 29 */
    IfxCan_RxBufferId_30,  /**< \brief Rx buffer 30 */
    IfxCan_RxBufferId_31,  /**< \brief Rx buffer 31 */
    IfxCan_RxBufferId_32,  /**< \brief Rx buffer 32 */
    IfxCan_RxBufferId_33,  /**< \brief Rx buffer 33 */
    IfxCan_RxBufferId_34,  /**< \brief Rx buffer 34 */
    IfxCan_RxBufferId_35,  /**< \brief Rx buffer 35 */
    IfxCan_RxBufferId_36,  /**< \brief Rx buffer 36 */
    IfxCan_RxBufferId_37,  /**< \brief Rx buffer 37 */
    IfxCan_RxBufferId_38,  /**< \brief Rx buffer 38 */
    IfxCan_RxBufferId_39,  /**< \brief Rx buffer 39 */
    IfxCan_RxBufferId_40,  /**< \brief Rx buffer 40 */
    IfxCan_RxBufferId_41,  /**< \brief Rx buffer 41 */
    IfxCan_RxBufferId_42,  /**< \brief Rx buffer 42 */
    IfxCan_RxBufferId_43,  /**< \brief Rx buffer 43 */
    IfxCan_RxBufferId_44,  /**< \brief Rx buffer 44 */
    IfxCan_RxBufferId_45,  /**< \brief Rx buffer 45 */
    IfxCan_RxBufferId_46,  /**< \brief Rx buffer 46 */
    IfxCan_RxBufferId_47,  /**< \brief Rx buffer 47 */
    IfxCan_RxBufferId_48,  /**< \brief Rx buffer 48 */
    IfxCan_RxBufferId_49,  /**< \brief Rx buffer 49 */
    IfxCan_RxBufferId_50,  /**< \brief Rx buffer 50 */
    IfxCan_RxBufferId_51,  /**< \brief Rx buffer 51 */
    IfxCan_RxBufferId_52,  /**< \brief Rx buffer 52 */
    IfxCan_RxBufferId_53,  /**< \brief Rx buffer 53 */
    IfxCan_RxBufferId_54,  /**< \brief Rx buffer 54 */
    IfxCan_RxBufferId_55,  /**< \brief Rx buffer 55 */
    IfxCan_RxBufferId_56,  /**< \brief Rx buffer 56 */
    IfxCan_RxBufferId_57,  /**< \brief Rx buffer 57 */
    IfxCan_RxBufferId_58,  /**< \brief Rx buffer 58 */
    IfxCan_RxBufferId_59,  /**< \brief Rx buffer 59 */
    IfxCan_RxBufferId_60,  /**< \brief Rx buffer 60 */
    IfxCan_RxBufferId_61,  /**< \brief Rx buffer 61 */
    IfxCan_RxBufferId_62,  /**< \brief Rx buffer 62 */
    IfxCan_RxBufferId_63   /**< \brief Rx buffer 63 */
} IfxCan_RxBufferId;

/** \brief Rx FIFO 0/1 operating mode\n
 * Description in Ifx_CAN.N[x].RXFyC.FyOM, (x= 0 to 3; y = 0, 1)
 */
typedef enum
{
    IfxCan_RxFifoMode_blocking,  /**< \brief Blocking mode */
    IfxCan_RxFifoMode_overwrite  /**< \brief Overwrite mode */
} IfxCan_RxFifoMode;

/** \brief Rx Buffers or FIFO 0 or combination Mode of reception
 */
typedef enum
{
    IfxCan_RxMode_dedicatedBuffers,  /**< \brief Rx dedicated buffers operation */
    IfxCan_RxMode_fifo0,             /**< \brief Rx FIFO 0 operation */
    IfxCan_RxMode_fifo1,             /**< \brief Rx FIFO 1 operation */
    IfxCan_RxMode_sharedFifo0,       /**< \brief Rx shared dedicated buffers and Rx FIFO 0 operation */
    IfxCan_RxMode_sharedFifo1,       /**< \brief Rx shared dedicated buffers and Rx FIFO 1 operation */
    IfxCan_RxMode_sharedAll          /**< \brief Rx shared dedicated buffers and Rx FIFO 0 and Rx FIFO 1 operation */
} IfxCan_RxMode;

/** \brief Enable/disable the sensitivity of the module to sleep signal\n
 * Definition in Ifx_CAN.CLC.B.EDIS
 */
typedef enum
{
    IfxCan_SleepMode_enable  = 0, /**< \brief enables sleep mode */
    IfxCan_SleepMode_disable = 1  /**< \brief disables sleep mode */
} IfxCan_SleepMode;

/** \brief CAN API status definition
 */
typedef enum
{
    IfxCan_Status_ok          = 0, /**< \brief CAN API status Okay for send message*/
    IfxCan_Status_notSentBusy = 1  /**< \brief CAN API status Not Sent Busy for send message */
} IfxCan_Status;

/** \brief Standard Filter Type
 * Description in CAN_STDMSG_S0.SFT
 */
typedef enum
{
    IfxCan_StdFilterType_range,    /**< \brief Range filter from SF1ID to SF2ID (SF2ID is greater than SF1ID) */
    IfxCan_StdFilterType_dualId,   /**< \brief Dual ID filter for SF1ID or SF2ID */
    IfxCan_StdFilterType_classic,  /**< \brief Classic filter: SF1ID = filter, SF2ID = mask */
    IfxCan_StdFilterType_none      /**< \brief Filter element disabled */
} IfxCan_StdFilterType;

/** \brief Group ID for Standard Frames
 */
typedef enum
{
    IfxCan_StdFrameGroupId_1 = 0,  /**< \brief Standard Frame Group 1 */
    IfxCan_StdFrameGroupId_2,      /**< \brief Standard Frame Group 2 */
    IfxCan_StdFrameGroupId_3,      /**< \brief Standard Frame Group 3 */
    IfxCan_StdFrameGroupId_4,      /**< \brief Standard Frame Group 4 */
    IfxCan_StdFrameGroupId_5,      /**< \brief Standard Frame Group 5 */
    IfxCan_StdFrameGroupId_6,      /**< \brief Standard Frame Group 6 */
    IfxCan_StdFrameGroupId_7,      /**< \brief Standard Frame Group 7 */
    IfxCan_StdFrameGroupId_8,      /**< \brief Standard Frame Group 8 */
    IfxCan_StdFrameGroupId_9,      /**< \brief Standard Frame Group 9 */
    IfxCan_StdFrameGroupId_10,     /**< \brief Standard Frame Group 10 */
    IfxCan_StdFrameGroupId_11,     /**< \brief Standard Frame Group 11 */
    IfxCan_StdFrameGroupId_12,     /**< \brief Standard Frame Group 12 */
    IfxCan_StdFrameGroupId_13,     /**< \brief Standard Frame Group 13 */
    IfxCan_StdFrameGroupId_14,     /**< \brief Standard Frame Group 14 */
    IfxCan_StdFrameGroupId_15,     /**< \brief Standard Frame Group 15 */
    IfxCan_StdFrameGroupId_16,     /**< \brief Standard Frame Group 16 */
    IfxCan_StdFrameGroupId_17,     /**< \brief Standard Frame Group 17 */
    IfxCan_StdFrameGroupId_18,     /**< \brief Standard Frame Group 18 */
    IfxCan_StdFrameGroupId_19,     /**< \brief Standard Frame Group 19 */
    IfxCan_StdFrameGroupId_20,     /**< \brief Standard Frame Group 20 */
    IfxCan_StdFrameGroupId_21,     /**< \brief Standard Frame Group 21 */
    IfxCan_StdFrameGroupId_22,     /**< \brief Standard Frame Group 22 */
    IfxCan_StdFrameGroupId_23,     /**< \brief Standard Frame Group 23 */
    IfxCan_StdFrameGroupId_24,     /**< \brief Standard Frame Group 24 */
    IfxCan_StdFrameGroupId_25,     /**< \brief Standard Frame Group 25 */
    IfxCan_StdFrameGroupId_26,     /**< \brief Standard Frame Group 26 */
    IfxCan_StdFrameGroupId_27,     /**< \brief Standard Frame Group 27 */
    IfxCan_StdFrameGroupId_28,     /**< \brief Standard Frame Group 28 */
    IfxCan_StdFrameGroupId_29,     /**< \brief Standard Frame Group 29 */
    IfxCan_StdFrameGroupId_30,     /**< \brief Standard Frame Group 30 */
    IfxCan_StdFrameGroupId_31,     /**< \brief Standard Frame Group 31 */
    IfxCan_StdFrameGroupId_32,     /**< \brief Standard Frame Group 32 */
    IfxCan_StdFrameGroupId_33,     /**< \brief Standard Frame Group 33 */
    IfxCan_StdFrameGroupId_34,     /**< \brief Standard Frame Group 34 */
    IfxCan_StdFrameGroupId_35,     /**< \brief Standard Frame Group 35 */
    IfxCan_StdFrameGroupId_36,     /**< \brief Standard Frame Group 36 */
    IfxCan_StdFrameGroupId_37,     /**< \brief Standard Frame Group 37 */
    IfxCan_StdFrameGroupId_38,     /**< \brief Standard Frame Group 38 */
    IfxCan_StdFrameGroupId_39,     /**< \brief Standard Frame Group 39 */
    IfxCan_StdFrameGroupId_40,     /**< \brief Standard Frame Group 40 */
    IfxCan_StdFrameGroupId_41,     /**< \brief Standard Frame Group 41 */
    IfxCan_StdFrameGroupId_42,     /**< \brief Standard Frame Group 42 */
    IfxCan_StdFrameGroupId_43,     /**< \brief Standard Frame Group 43 */
    IfxCan_StdFrameGroupId_44,     /**< \brief Standard Frame Group 44 */
    IfxCan_StdFrameGroupId_45,     /**< \brief Standard Frame Group 45 */
    IfxCan_StdFrameGroupId_46,     /**< \brief Standard Frame Group 46 */
    IfxCan_StdFrameGroupId_47,     /**< \brief Standard Frame Group 47 */
    IfxCan_StdFrameGroupId_48,     /**< \brief Standard Frame Group 48 */
    IfxCan_StdFrameGroupId_49,     /**< \brief Standard Frame Group 49 */
    IfxCan_StdFrameGroupId_50,     /**< \brief Standard Frame Group 50 */
    IfxCan_StdFrameGroupId_51,     /**< \brief Standard Frame Group 51 */
    IfxCan_StdFrameGroupId_52,     /**< \brief Standard Frame Group 52 */
    IfxCan_StdFrameGroupId_53,     /**< \brief Standard Frame Group 53 */
    IfxCan_StdFrameGroupId_54,     /**< \brief Standard Frame Group 54 */
    IfxCan_StdFrameGroupId_55,     /**< \brief Standard Frame Group 55 */
    IfxCan_StdFrameGroupId_56,     /**< \brief Standard Frame Group 56 */
    IfxCan_StdFrameGroupId_57,     /**< \brief Standard Frame Group 57 */
    IfxCan_StdFrameGroupId_58,     /**< \brief Standard Frame Group 58 */
    IfxCan_StdFrameGroupId_59,     /**< \brief Standard Frame Group 59 */
    IfxCan_StdFrameGroupId_60,     /**< \brief Standard Frame Group 60 */
    IfxCan_StdFrameGroupId_61,     /**< \brief Standard Frame Group 61 */
    IfxCan_StdFrameGroupId_62,     /**< \brief Standard Frame Group 62 */
    IfxCan_StdFrameGroupId_63,     /**< \brief Standard Frame Group 63 */
    IfxCan_StdFrameGroupId_64,     /**< \brief Standard Frame Group 64 */
    IfxCan_StdFrameGroupId_65,     /**< \brief Standard Frame Group 65 */
    IfxCan_StdFrameGroupId_66,     /**< \brief Standard Frame Group 66 */
    IfxCan_StdFrameGroupId_67,     /**< \brief Standard Frame Group 67 */
    IfxCan_StdFrameGroupId_68,     /**< \brief Standard Frame Group 68 */
    IfxCan_StdFrameGroupId_69,     /**< \brief Standard Frame Group 69 */
    IfxCan_StdFrameGroupId_70,     /**< \brief Standard Frame Group 70 */
    IfxCan_StdFrameGroupId_71,     /**< \brief Standard Frame Group 71 */
    IfxCan_StdFrameGroupId_72,     /**< \brief Standard Frame Group 72 */
    IfxCan_StdFrameGroupId_73,     /**< \brief Standard Frame Group 73 */
    IfxCan_StdFrameGroupId_74,     /**< \brief Standard Frame Group 74 */
    IfxCan_StdFrameGroupId_75,     /**< \brief Standard Frame Group 75 */
    IfxCan_StdFrameGroupId_76,     /**< \brief Standard Frame Group 76 */
    IfxCan_StdFrameGroupId_77,     /**< \brief Standard Frame Group 77 */
    IfxCan_StdFrameGroupId_78,     /**< \brief Standard Frame Group 78 */
    IfxCan_StdFrameGroupId_79,     /**< \brief Standard Frame Group 79 */
    IfxCan_StdFrameGroupId_80,     /**< \brief Standard Frame Group 80 */
    IfxCan_StdFrameGroupId_81,     /**< \brief Standard Frame Group 81 */
    IfxCan_StdFrameGroupId_82,     /**< \brief Standard Frame Group 82 */
    IfxCan_StdFrameGroupId_83,     /**< \brief Standard Frame Group 83 */
    IfxCan_StdFrameGroupId_84,     /**< \brief Standard Frame Group 84 */
    IfxCan_StdFrameGroupId_85,     /**< \brief Standard Frame Group 85 */
    IfxCan_StdFrameGroupId_86,     /**< \brief Standard Frame Group 86 */
    IfxCan_StdFrameGroupId_87,     /**< \brief Standard Frame Group 87 */
    IfxCan_StdFrameGroupId_88,     /**< \brief Standard Frame Group 88 */
    IfxCan_StdFrameGroupId_89,     /**< \brief Standard Frame Group 89 */
    IfxCan_StdFrameGroupId_90,     /**< \brief Standard Frame Group 90 */
    IfxCan_StdFrameGroupId_91,     /**< \brief Standard Frame Group 91 */
    IfxCan_StdFrameGroupId_92,     /**< \brief Standard Frame Group 92 */
    IfxCan_StdFrameGroupId_93,     /**< \brief Standard Frame Group 93 */
    IfxCan_StdFrameGroupId_94,     /**< \brief Standard Frame Group 94 */
    IfxCan_StdFrameGroupId_95,     /**< \brief Standard Frame Group 95 */
    IfxCan_StdFrameGroupId_96,     /**< \brief Standard Frame Group 96 */
    IfxCan_StdFrameGroupId_97,     /**< \brief Standard Frame Group 97 */
    IfxCan_StdFrameGroupId_98,     /**< \brief Standard Frame Group 98 */
    IfxCan_StdFrameGroupId_99,     /**< \brief Standard Frame Group 99 */
    IfxCan_StdFrameGroupId_100,    /**< \brief Standard Frame Group 100 */
    IfxCan_StdFrameGroupId_101,    /**< \brief Standard Frame Group 101 */
    IfxCan_StdFrameGroupId_102,    /**< \brief Standard Frame Group 102 */
    IfxCan_StdFrameGroupId_103,    /**< \brief Standard Frame Group 103 */
    IfxCan_StdFrameGroupId_104,    /**< \brief Standard Frame Group 104 */
    IfxCan_StdFrameGroupId_105,    /**< \brief Standard Frame Group 105 */
    IfxCan_StdFrameGroupId_106,    /**< \brief Standard Frame Group 106 */
    IfxCan_StdFrameGroupId_107,    /**< \brief Standard Frame Group 107 */
    IfxCan_StdFrameGroupId_108,    /**< \brief Standard Frame Group 108 */
    IfxCan_StdFrameGroupId_109,    /**< \brief Standard Frame Group 109 */
    IfxCan_StdFrameGroupId_110,    /**< \brief Standard Frame Group 110 */
    IfxCan_StdFrameGroupId_111,    /**< \brief Standard Frame Group 111 */
    IfxCan_StdFrameGroupId_112,    /**< \brief Standard Frame Group 112 */
    IfxCan_StdFrameGroupId_113,    /**< \brief Standard Frame Group 113 */
    IfxCan_StdFrameGroupId_114,    /**< \brief Standard Frame Group 114 */
    IfxCan_StdFrameGroupId_115,    /**< \brief Standard Frame Group 115 */
    IfxCan_StdFrameGroupId_116,    /**< \brief Standard Frame Group 116 */
    IfxCan_StdFrameGroupId_117,    /**< \brief Standard Frame Group 117 */
    IfxCan_StdFrameGroupId_118,    /**< \brief Standard Frame Group 118 */
    IfxCan_StdFrameGroupId_119,    /**< \brief Standard Frame Group 119 */
    IfxCan_StdFrameGroupId_120,    /**< \brief Standard Frame Group 120 */
    IfxCan_StdFrameGroupId_121,    /**< \brief Standard Frame Group 121 */
    IfxCan_StdFrameGroupId_122,    /**< \brief Standard Frame Group 122 */
    IfxCan_StdFrameGroupId_123,    /**< \brief Standard Frame Group 123 */
    IfxCan_StdFrameGroupId_124,    /**< \brief Standard Frame Group 124 */
    IfxCan_StdFrameGroupId_125,    /**< \brief Standard Frame Group 125 */
    IfxCan_StdFrameGroupId_126,    /**< \brief Standard Frame Group 126 */
    IfxCan_StdFrameGroupId_127,    /**< \brief Standard Frame Group 127 */
    IfxCan_StdFrameGroupId_128     /**< \brief Standard Frame Group 128 */
} IfxCan_StdFrameGroupId;

/** \brief Size of Standard Frame Rate Measurements
 */
typedef enum
{
    IfxCan_StdFrameRateSize_0 = 0,  /**< \brief 0 Standard Frame Rate Measurements */
    IfxCan_StdFrameRateSize_1,      /**< \brief 1 Standard Frame Rate Measurements */
    IfxCan_StdFrameRateSize_2,      /**< \brief 2 Standard Frame Rate Measurements */
    IfxCan_StdFrameRateSize_3,      /**< \brief 3 Standard Frame Rate Measurements */
    IfxCan_StdFrameRateSize_4,      /**< \brief 4 Standard Frame Rate Measurements */
    IfxCan_StdFrameRateSize_5,      /**< \brief 5 Standard Frame Rate Measurements */
    IfxCan_StdFrameRateSize_6,      /**< \brief 6 Standard Frame Rate Measurements */
    IfxCan_StdFrameRateSize_7,      /**< \brief 7 Standard Frame Rate Measurements */
    IfxCan_StdFrameRateSize_8,      /**< \brief 8 Standard Frame Rate Measurements */
    IfxCan_StdFrameRateSize_9,      /**< \brief 9 Standard Frame Rate Measurements */
    IfxCan_StdFrameRateSize_10,     /**< \brief 10 Standard Frame Rate Measurements */
    IfxCan_StdFrameRateSize_11,     /**< \brief 11 Standard Frame Rate Measurements */
    IfxCan_StdFrameRateSize_12,     /**< \brief 12 Standard Frame Rate Measurements */
    IfxCan_StdFrameRateSize_13,     /**< \brief 13 Standard Frame Rate Measurements */
    IfxCan_StdFrameRateSize_14,     /**< \brief 14 Standard Frame Rate Measurements */
    IfxCan_StdFrameRateSize_15,     /**< \brief 15 Standard Frame Rate Measurements */
    IfxCan_StdFrameRateSize_16,     /**< \brief 16 Standard Frame Rate Measurements */
    IfxCan_StdFrameRateSize_17,     /**< \brief 17 Standard Frame Rate Measurements */
    IfxCan_StdFrameRateSize_18,     /**< \brief 18 Standard Frame Rate Measurements */
    IfxCan_StdFrameRateSize_19,     /**< \brief 19 Standard Frame Rate Measurements */
    IfxCan_StdFrameRateSize_20,     /**< \brief 20 Standard Frame Rate Measurements */
    IfxCan_StdFrameRateSize_21,     /**< \brief 21 Standard Frame Rate Measurements */
    IfxCan_StdFrameRateSize_22,     /**< \brief 22 Standard Frame Rate Measurements */
    IfxCan_StdFrameRateSize_23,     /**< \brief 23 Standard Frame Rate Measurements */
    IfxCan_StdFrameRateSize_24,     /**< \brief 24 Standard Frame Rate Measurements */
    IfxCan_StdFrameRateSize_25,     /**< \brief 25 Standard Frame Rate Measurements */
    IfxCan_StdFrameRateSize_26,     /**< \brief 26 Standard Frame Rate Measurements */
    IfxCan_StdFrameRateSize_27,     /**< \brief 27 Standard Frame Rate Measurements */
    IfxCan_StdFrameRateSize_28,     /**< \brief 28 Standard Frame Rate Measurements */
    IfxCan_StdFrameRateSize_29,     /**< \brief 29 Standard Frame Rate Measurements */
    IfxCan_StdFrameRateSize_30,     /**< \brief 30 Standard Frame Rate Measurements */
    IfxCan_StdFrameRateSize_31,     /**< \brief 31 Standard Frame Rate Measurements */
    IfxCan_StdFrameRateSize_32,     /**< \brief 32 Standard Frame Rate Measurements */
    IfxCan_StdFrameRateSize_33,     /**< \brief 33 Standard Frame Rate Measurements */
    IfxCan_StdFrameRateSize_34,     /**< \brief 34 Standard Frame Rate Measurements */
    IfxCan_StdFrameRateSize_35,     /**< \brief 35 Standard Frame Rate Measurements */
    IfxCan_StdFrameRateSize_36,     /**< \brief 36 Standard Frame Rate Measurements */
    IfxCan_StdFrameRateSize_37,     /**< \brief 37 Standard Frame Rate Measurements */
    IfxCan_StdFrameRateSize_38,     /**< \brief 38 Standard Frame Rate Measurements */
    IfxCan_StdFrameRateSize_39,     /**< \brief 39 Standard Frame Rate Measurements */
    IfxCan_StdFrameRateSize_40,     /**< \brief 40 Standard Frame Rate Measurements */
    IfxCan_StdFrameRateSize_41,     /**< \brief 41 Standard Frame Rate Measurements */
    IfxCan_StdFrameRateSize_42,     /**< \brief 42 Standard Frame Rate Measurements */
    IfxCan_StdFrameRateSize_43,     /**< \brief 43 Standard Frame Rate Measurements */
    IfxCan_StdFrameRateSize_44,     /**< \brief 44 Standard Frame Rate Measurements */
    IfxCan_StdFrameRateSize_45,     /**< \brief 45 Standard Frame Rate Measurements */
    IfxCan_StdFrameRateSize_46,     /**< \brief 46 Standard Frame Rate Measurements */
    IfxCan_StdFrameRateSize_47,     /**< \brief 47 Standard Frame Rate Measurements */
    IfxCan_StdFrameRateSize_48,     /**< \brief 48 Standard Frame Rate Measurements */
    IfxCan_StdFrameRateSize_49,     /**< \brief 49 Standard Frame Rate Measurements */
    IfxCan_StdFrameRateSize_50,     /**< \brief 50 Standard Frame Rate Measurements */
    IfxCan_StdFrameRateSize_51,     /**< \brief 51 Standard Frame Rate Measurements */
    IfxCan_StdFrameRateSize_52,     /**< \brief 52 Standard Frame Rate Measurements */
    IfxCan_StdFrameRateSize_53,     /**< \brief 53 Standard Frame Rate Measurements */
    IfxCan_StdFrameRateSize_54,     /**< \brief 54 Standard Frame Rate Measurements */
    IfxCan_StdFrameRateSize_55,     /**< \brief 55 Standard Frame Rate Measurements */
    IfxCan_StdFrameRateSize_56,     /**< \brief 56 Standard Frame Rate Measurements */
    IfxCan_StdFrameRateSize_57,     /**< \brief 57 Standard Frame Rate Measurements */
    IfxCan_StdFrameRateSize_58,     /**< \brief 58 Standard Frame Rate Measurements */
    IfxCan_StdFrameRateSize_59,     /**< \brief 59 Standard Frame Rate Measurements */
    IfxCan_StdFrameRateSize_60,     /**< \brief 60 Standard Frame Rate Measurements */
    IfxCan_StdFrameRateSize_61,     /**< \brief 61 Standard Frame Rate Measurements */
    IfxCan_StdFrameRateSize_62,     /**< \brief 62 Standard Frame Rate Measurements */
    IfxCan_StdFrameRateSize_63,     /**< \brief 63 Standard Frame Rate Measurements */
    IfxCan_StdFrameRateSize_64,     /**< \brief 64 Standard Frame Rate Measurements */
    IfxCan_StdFrameRateSize_65,     /**< \brief 65 Standard Frame Rate Measurements */
    IfxCan_StdFrameRateSize_66,     /**< \brief 66 Standard Frame Rate Measurements */
    IfxCan_StdFrameRateSize_67,     /**< \brief 67 Standard Frame Rate Measurements */
    IfxCan_StdFrameRateSize_68,     /**< \brief 68 Standard Frame Rate Measurements */
    IfxCan_StdFrameRateSize_69,     /**< \brief 69 Standard Frame Rate Measurements */
    IfxCan_StdFrameRateSize_70,     /**< \brief 70 Standard Frame Rate Measurements */
    IfxCan_StdFrameRateSize_71,     /**< \brief 71 Standard Frame Rate Measurements */
    IfxCan_StdFrameRateSize_72,     /**< \brief 72 Standard Frame Rate Measurements */
    IfxCan_StdFrameRateSize_73,     /**< \brief 73 Standard Frame Rate Measurements */
    IfxCan_StdFrameRateSize_74,     /**< \brief 74 Standard Frame Rate Measurements */
    IfxCan_StdFrameRateSize_75,     /**< \brief 75 Standard Frame Rate Measurements */
    IfxCan_StdFrameRateSize_76,     /**< \brief 76 Standard Frame Rate Measurements */
    IfxCan_StdFrameRateSize_77,     /**< \brief 77 Standard Frame Rate Measurements */
    IfxCan_StdFrameRateSize_78,     /**< \brief 78 Standard Frame Rate Measurements */
    IfxCan_StdFrameRateSize_79,     /**< \brief 79 Standard Frame Rate Measurements */
    IfxCan_StdFrameRateSize_80,     /**< \brief 80 Standard Frame Rate Measurements */
    IfxCan_StdFrameRateSize_81,     /**< \brief 81 Standard Frame Rate Measurements */
    IfxCan_StdFrameRateSize_82,     /**< \brief 82 Standard Frame Rate Measurements */
    IfxCan_StdFrameRateSize_83,     /**< \brief 83 Standard Frame Rate Measurements */
    IfxCan_StdFrameRateSize_84,     /**< \brief 84 Standard Frame Rate Measurements */
    IfxCan_StdFrameRateSize_85,     /**< \brief 85 Standard Frame Rate Measurements */
    IfxCan_StdFrameRateSize_86,     /**< \brief 86 Standard Frame Rate Measurements */
    IfxCan_StdFrameRateSize_87,     /**< \brief 87 Standard Frame Rate Measurements */
    IfxCan_StdFrameRateSize_88,     /**< \brief 88 Standard Frame Rate Measurements */
    IfxCan_StdFrameRateSize_89,     /**< \brief 89 Standard Frame Rate Measurements */
    IfxCan_StdFrameRateSize_90,     /**< \brief 90 Standard Frame Rate Measurements */
    IfxCan_StdFrameRateSize_91,     /**< \brief 91 Standard Frame Rate Measurements */
    IfxCan_StdFrameRateSize_92,     /**< \brief 92 Standard Frame Rate Measurements */
    IfxCan_StdFrameRateSize_93,     /**< \brief 93 Standard Frame Rate Measurements */
    IfxCan_StdFrameRateSize_94,     /**< \brief 94 Standard Frame Rate Measurements */
    IfxCan_StdFrameRateSize_95,     /**< \brief 95 Standard Frame Rate Measurements */
    IfxCan_StdFrameRateSize_96,     /**< \brief 96 Standard Frame Rate Measurements */
    IfxCan_StdFrameRateSize_97,     /**< \brief 97 Standard Frame Rate Measurements */
    IfxCan_StdFrameRateSize_98,     /**< \brief 98 Standard Frame Rate Measurements */
    IfxCan_StdFrameRateSize_99,     /**< \brief 99 Standard Frame Rate Measurements */
    IfxCan_StdFrameRateSize_100,    /**< \brief 100 Standard Frame Rate Measurements */
    IfxCan_StdFrameRateSize_101,    /**< \brief 101 Standard Frame Rate Measurements */
    IfxCan_StdFrameRateSize_102,    /**< \brief 102 Standard Frame Rate Measurements */
    IfxCan_StdFrameRateSize_103,    /**< \brief 103 Standard Frame Rate Measurements */
    IfxCan_StdFrameRateSize_104,    /**< \brief 104 Standard Frame Rate Measurements */
    IfxCan_StdFrameRateSize_105,    /**< \brief 105 Standard Frame Rate Measurements */
    IfxCan_StdFrameRateSize_106,    /**< \brief 106 Standard Frame Rate Measurements */
    IfxCan_StdFrameRateSize_107,    /**< \brief 107 Standard Frame Rate Measurements */
    IfxCan_StdFrameRateSize_108,    /**< \brief 108 Standard Frame Rate Measurements */
    IfxCan_StdFrameRateSize_109,    /**< \brief 109 Standard Frame Rate Measurements */
    IfxCan_StdFrameRateSize_110,    /**< \brief 110 Standard Frame Rate Measurements */
    IfxCan_StdFrameRateSize_111,    /**< \brief 111 Standard Frame Rate Measurements */
    IfxCan_StdFrameRateSize_112,    /**< \brief 112 Standard Frame Rate Measurements */
    IfxCan_StdFrameRateSize_113,    /**< \brief 113 Standard Frame Rate Measurements */
    IfxCan_StdFrameRateSize_114,    /**< \brief 114 Standard Frame Rate Measurements */
    IfxCan_StdFrameRateSize_115,    /**< \brief 115 Standard Frame Rate Measurements */
    IfxCan_StdFrameRateSize_116,    /**< \brief 116 Standard Frame Rate Measurements */
    IfxCan_StdFrameRateSize_117,    /**< \brief 117 Standard Frame Rate Measurements */
    IfxCan_StdFrameRateSize_118,    /**< \brief 118 Standard Frame Rate Measurements */
    IfxCan_StdFrameRateSize_119,    /**< \brief 119 Standard Frame Rate Measurements */
    IfxCan_StdFrameRateSize_120,    /**< \brief 120 Standard Frame Rate Measurements */
    IfxCan_StdFrameRateSize_121,    /**< \brief 121 Standard Frame Rate Measurements */
    IfxCan_StdFrameRateSize_122,    /**< \brief 122 Standard Frame Rate Measurements */
    IfxCan_StdFrameRateSize_123,    /**< \brief 123 Standard Frame Rate Measurements */
    IfxCan_StdFrameRateSize_124,    /**< \brief 124 Standard Frame Rate Measurements */
    IfxCan_StdFrameRateSize_125,    /**< \brief 125 Standard Frame Rate Measurements */
    IfxCan_StdFrameRateSize_126,    /**< \brief 126 Standard Frame Rate Measurements */
    IfxCan_StdFrameRateSize_127,    /**< \brief 127 Standard Frame Rate Measurements */
    IfxCan_StdFrameRateSize_128     /**< \brief 128 Standard Frame Rate Measurements */
} IfxCan_StdFrameRateSize;

/** \brief Number of Routing Rules for Standard Frames
 */
typedef enum
{
    IfxCan_StdRoutingRuleSize_0 = 0,  /**< \brief 0 Standard Frame Routing Rules */
    IfxCan_StdRoutingRuleSize_1,      /**< \brief 1 Standard Frame Routing Rules */
    IfxCan_StdRoutingRuleSize_2,      /**< \brief 2 Standard Frame Routing Rules */
    IfxCan_StdRoutingRuleSize_3,      /**< \brief 3 Standard Frame Routing Rules */
    IfxCan_StdRoutingRuleSize_4,      /**< \brief 4 Standard Frame Routing Rules */
    IfxCan_StdRoutingRuleSize_5,      /**< \brief 5 Standard Frame Routing Rules */
    IfxCan_StdRoutingRuleSize_6,      /**< \brief 6 Standard Frame Routing Rules */
    IfxCan_StdRoutingRuleSize_7,      /**< \brief 7 Standard Frame Routing Rules */
    IfxCan_StdRoutingRuleSize_8,      /**< \brief 8 Standard Frame Routing Rules */
    IfxCan_StdRoutingRuleSize_9,      /**< \brief 9 Standard Frame Routing Rules */
    IfxCan_StdRoutingRuleSize_10,     /**< \brief 10 Standard Frame Routing Rules */
    IfxCan_StdRoutingRuleSize_11,     /**< \brief 11 Standard Frame Routing Rules */
    IfxCan_StdRoutingRuleSize_12,     /**< \brief 12 Standard Frame Routing Rules */
    IfxCan_StdRoutingRuleSize_13,     /**< \brief 13 Standard Frame Routing Rules */
    IfxCan_StdRoutingRuleSize_14,     /**< \brief 14 Standard Frame Routing Rules */
    IfxCan_StdRoutingRuleSize_15,     /**< \brief 15 Standard Frame Routing Rules */
    IfxCan_StdRoutingRuleSize_16,     /**< \brief 16 Standard Frame Routing Rules */
    IfxCan_StdRoutingRuleSize_17,     /**< \brief 17 Standard Frame Routing Rules */
    IfxCan_StdRoutingRuleSize_18,     /**< \brief 18 Standard Frame Routing Rules */
    IfxCan_StdRoutingRuleSize_19,     /**< \brief 19 Standard Frame Routing Rules */
    IfxCan_StdRoutingRuleSize_20,     /**< \brief 20 Standard Frame Routing Rules */
    IfxCan_StdRoutingRuleSize_21,     /**< \brief 21 Standard Frame Routing Rules */
    IfxCan_StdRoutingRuleSize_22,     /**< \brief 22 Standard Frame Routing Rules */
    IfxCan_StdRoutingRuleSize_23,     /**< \brief 23 Standard Frame Routing Rules */
    IfxCan_StdRoutingRuleSize_24,     /**< \brief 24 Standard Frame Routing Rules */
    IfxCan_StdRoutingRuleSize_25,     /**< \brief 25 Standard Frame Routing Rules */
    IfxCan_StdRoutingRuleSize_26,     /**< \brief 26 Standard Frame Routing Rules */
    IfxCan_StdRoutingRuleSize_27,     /**< \brief 27 Standard Frame Routing Rules */
    IfxCan_StdRoutingRuleSize_28,     /**< \brief 28 Standard Frame Routing Rules */
    IfxCan_StdRoutingRuleSize_29,     /**< \brief 29 Standard Frame Routing Rules */
    IfxCan_StdRoutingRuleSize_30,     /**< \brief 30 Standard Frame Routing Rules */
    IfxCan_StdRoutingRuleSize_31,     /**< \brief 31 Standard Frame Routing Rules */
    IfxCan_StdRoutingRuleSize_32,     /**< \brief 32 Standard Frame Routing Rules */
    IfxCan_StdRoutingRuleSize_33,     /**< \brief 33 Standard Frame Routing Rules */
    IfxCan_StdRoutingRuleSize_34,     /**< \brief 34 Standard Frame Routing Rules */
    IfxCan_StdRoutingRuleSize_35,     /**< \brief 35 Standard Frame Routing Rules */
    IfxCan_StdRoutingRuleSize_36,     /**< \brief 36 Standard Frame Routing Rules */
    IfxCan_StdRoutingRuleSize_37,     /**< \brief 37 Standard Frame Routing Rules */
    IfxCan_StdRoutingRuleSize_38,     /**< \brief 38 Standard Frame Routing Rules */
    IfxCan_StdRoutingRuleSize_39,     /**< \brief 39 Standard Frame Routing Rules */
    IfxCan_StdRoutingRuleSize_40,     /**< \brief 40 Standard Frame Routing Rules */
    IfxCan_StdRoutingRuleSize_41,     /**< \brief 41 Standard Frame Routing Rules */
    IfxCan_StdRoutingRuleSize_42,     /**< \brief 42 Standard Frame Routing Rules */
    IfxCan_StdRoutingRuleSize_43,     /**< \brief 43 Standard Frame Routing Rules */
    IfxCan_StdRoutingRuleSize_44,     /**< \brief 44 Standard Frame Routing Rules */
    IfxCan_StdRoutingRuleSize_45,     /**< \brief 45 Standard Frame Routing Rules */
    IfxCan_StdRoutingRuleSize_46,     /**< \brief 46 Standard Frame Routing Rules */
    IfxCan_StdRoutingRuleSize_47,     /**< \brief 47 Standard Frame Routing Rules */
    IfxCan_StdRoutingRuleSize_48,     /**< \brief 48 Standard Frame Routing Rules */
    IfxCan_StdRoutingRuleSize_49,     /**< \brief 49 Standard Frame Routing Rules */
    IfxCan_StdRoutingRuleSize_50,     /**< \brief 50 Standard Frame Routing Rules */
    IfxCan_StdRoutingRuleSize_51,     /**< \brief 51 Standard Frame Routing Rules */
    IfxCan_StdRoutingRuleSize_52,     /**< \brief 52 Standard Frame Routing Rules */
    IfxCan_StdRoutingRuleSize_53,     /**< \brief 53 Standard Frame Routing Rules */
    IfxCan_StdRoutingRuleSize_54,     /**< \brief 54 Standard Frame Routing Rules */
    IfxCan_StdRoutingRuleSize_55,     /**< \brief 55 Standard Frame Routing Rules */
    IfxCan_StdRoutingRuleSize_56,     /**< \brief 56 Standard Frame Routing Rules */
    IfxCan_StdRoutingRuleSize_57,     /**< \brief 57 Standard Frame Routing Rules */
    IfxCan_StdRoutingRuleSize_58,     /**< \brief 58 Standard Frame Routing Rules */
    IfxCan_StdRoutingRuleSize_59,     /**< \brief 59 Standard Frame Routing Rules */
    IfxCan_StdRoutingRuleSize_60,     /**< \brief 60 Standard Frame Routing Rules */
    IfxCan_StdRoutingRuleSize_61,     /**< \brief 61 Standard Frame Routing Rules */
    IfxCan_StdRoutingRuleSize_62,     /**< \brief 62 Standard Frame Routing Rules */
    IfxCan_StdRoutingRuleSize_63,     /**< \brief 63 Standard Frame Routing Rules */
    IfxCan_StdRoutingRuleSize_64,     /**< \brief 64 Standard Frame Routing Rules */
    IfxCan_StdRoutingRuleSize_65,     /**< \brief 65 Standard Frame Routing Rules */
    IfxCan_StdRoutingRuleSize_66,     /**< \brief 66 Standard Frame Routing Rules */
    IfxCan_StdRoutingRuleSize_67,     /**< \brief 67 Standard Frame Routing Rules */
    IfxCan_StdRoutingRuleSize_68,     /**< \brief 68 Standard Frame Routing Rules */
    IfxCan_StdRoutingRuleSize_69,     /**< \brief 69 Standard Frame Routing Rules */
    IfxCan_StdRoutingRuleSize_70,     /**< \brief 70 Standard Frame Routing Rules */
    IfxCan_StdRoutingRuleSize_71,     /**< \brief 71 Standard Frame Routing Rules */
    IfxCan_StdRoutingRuleSize_72,     /**< \brief 72 Standard Frame Routing Rules */
    IfxCan_StdRoutingRuleSize_73,     /**< \brief 73 Standard Frame Routing Rules */
    IfxCan_StdRoutingRuleSize_74,     /**< \brief 74 Standard Frame Routing Rules */
    IfxCan_StdRoutingRuleSize_75,     /**< \brief 75 Standard Frame Routing Rules */
    IfxCan_StdRoutingRuleSize_76,     /**< \brief 76 Standard Frame Routing Rules */
    IfxCan_StdRoutingRuleSize_77,     /**< \brief 77 Standard Frame Routing Rules */
    IfxCan_StdRoutingRuleSize_78,     /**< \brief 78 Standard Frame Routing Rules */
    IfxCan_StdRoutingRuleSize_79,     /**< \brief 79 Standard Frame Routing Rules */
    IfxCan_StdRoutingRuleSize_80,     /**< \brief 80 Standard Frame Routing Rules */
    IfxCan_StdRoutingRuleSize_81,     /**< \brief 81 Standard Frame Routing Rules */
    IfxCan_StdRoutingRuleSize_82,     /**< \brief 82 Standard Frame Routing Rules */
    IfxCan_StdRoutingRuleSize_83,     /**< \brief 83 Standard Frame Routing Rules */
    IfxCan_StdRoutingRuleSize_84,     /**< \brief 84 Standard Frame Routing Rules */
    IfxCan_StdRoutingRuleSize_85,     /**< \brief 85 Standard Frame Routing Rules */
    IfxCan_StdRoutingRuleSize_86,     /**< \brief 86 Standard Frame Routing Rules */
    IfxCan_StdRoutingRuleSize_87,     /**< \brief 87 Standard Frame Routing Rules */
    IfxCan_StdRoutingRuleSize_88,     /**< \brief 88 Standard Frame Routing Rules */
    IfxCan_StdRoutingRuleSize_89,     /**< \brief 89 Standard Frame Routing Rules */
    IfxCan_StdRoutingRuleSize_90,     /**< \brief 90 Standard Frame Routing Rules */
    IfxCan_StdRoutingRuleSize_91,     /**< \brief 91 Standard Frame Routing Rules */
    IfxCan_StdRoutingRuleSize_92,     /**< \brief 92 Standard Frame Routing Rules */
    IfxCan_StdRoutingRuleSize_93,     /**< \brief 93 Standard Frame Routing Rules */
    IfxCan_StdRoutingRuleSize_94,     /**< \brief 94 Standard Frame Routing Rules */
    IfxCan_StdRoutingRuleSize_95,     /**< \brief 95 Standard Frame Routing Rules */
    IfxCan_StdRoutingRuleSize_96,     /**< \brief 96 Standard Frame Routing Rules */
    IfxCan_StdRoutingRuleSize_97,     /**< \brief 97 Standard Frame Routing Rules */
    IfxCan_StdRoutingRuleSize_98,     /**< \brief 98 Standard Frame Routing Rules */
    IfxCan_StdRoutingRuleSize_99,     /**< \brief 99 Standard Frame Routing Rules */
    IfxCan_StdRoutingRuleSize_100,    /**< \brief 100 Standard Frame Routing Rules */
    IfxCan_StdRoutingRuleSize_101,    /**< \brief 101 Standard Frame Routing Rules */
    IfxCan_StdRoutingRuleSize_102,    /**< \brief 102 Standard Frame Routing Rules */
    IfxCan_StdRoutingRuleSize_103,    /**< \brief 103 Standard Frame Routing Rules */
    IfxCan_StdRoutingRuleSize_104,    /**< \brief 104 Standard Frame Routing Rules */
    IfxCan_StdRoutingRuleSize_105,    /**< \brief 105 Standard Frame Routing Rules */
    IfxCan_StdRoutingRuleSize_106,    /**< \brief 106 Standard Frame Routing Rules */
    IfxCan_StdRoutingRuleSize_107,    /**< \brief 107 Standard Frame Routing Rules */
    IfxCan_StdRoutingRuleSize_108,    /**< \brief 108 Standard Frame Routing Rules */
    IfxCan_StdRoutingRuleSize_109,    /**< \brief 109 Standard Frame Routing Rules */
    IfxCan_StdRoutingRuleSize_110,    /**< \brief 110 Standard Frame Routing Rules */
    IfxCan_StdRoutingRuleSize_111,    /**< \brief 111 Standard Frame Routing Rules */
    IfxCan_StdRoutingRuleSize_112,    /**< \brief 112 Standard Frame Routing Rules */
    IfxCan_StdRoutingRuleSize_113,    /**< \brief 113 Standard Frame Routing Rules */
    IfxCan_StdRoutingRuleSize_114,    /**< \brief 114 Standard Frame Routing Rules */
    IfxCan_StdRoutingRuleSize_115,    /**< \brief 115 Standard Frame Routing Rules */
    IfxCan_StdRoutingRuleSize_116,    /**< \brief 116 Standard Frame Routing Rules */
    IfxCan_StdRoutingRuleSize_117,    /**< \brief 117 Standard Frame Routing Rules */
    IfxCan_StdRoutingRuleSize_118,    /**< \brief 118 Standard Frame Routing Rules */
    IfxCan_StdRoutingRuleSize_119,    /**< \brief 119 Standard Frame Routing Rules */
    IfxCan_StdRoutingRuleSize_120,    /**< \brief 120 Standard Frame Routing Rules */
    IfxCan_StdRoutingRuleSize_121,    /**< \brief 121 Standard Frame Routing Rules */
    IfxCan_StdRoutingRuleSize_122,    /**< \brief 122 Standard Frame Routing Rules */
    IfxCan_StdRoutingRuleSize_123,    /**< \brief 123 Standard Frame Routing Rules */
    IfxCan_StdRoutingRuleSize_124,    /**< \brief 124 Standard Frame Routing Rules */
    IfxCan_StdRoutingRuleSize_125,    /**< \brief 125 Standard Frame Routing Rules */
    IfxCan_StdRoutingRuleSize_126,    /**< \brief 126 Standard Frame Routing Rules */
    IfxCan_StdRoutingRuleSize_127,    /**< \brief 127 Standard Frame Routing Rules */
    IfxCan_StdRoutingRuleSize_128     /**< \brief 128 Standard Frame Routing Rules */
} IfxCan_StdRoutingRuleSize;

/** \brief OCDS Suspend Control (OCDS.SUS)
 * Definition in Ifx_CAN_OCS.B.SUS
 */
typedef enum
{
    IfxCan_SuspendMode_none = 0,  /**< \brief No suspend */
    IfxCan_SuspendMode_hard = 1,  /**< \brief Hard Suspend */
    IfxCan_SuspendMode_soft = 2   /**< \brief Soft Suspend */
} IfxCan_SuspendMode;

/** \brief Source for Can Time Stamp\n
 * Refer to N.TSCC.B.TSS
 */
typedef enum
{
    IfxCan_TSCC_TSS_none     = 0,  /**< \brief No Time Stamps used */
    IfxCan_TSCC_TSS_internal = 1,  /**< \brief Internal 16 bit Counter used */
    IfxCan_TSCC_TSS_external = 2   /**< \brief 16 bit external counter as selected by N_TIMER_CCR.B.TRIGSRC */
} IfxCan_TSCC_TSS;

/** \brief State of Time Stamp Capture
 * Definition in Ifx_CAN_TXEVENT.E1B.B.TSC
 */
typedef enum
{
    IfxCan_TimeStampState_notCaptured = 0,  /**< \brief No Time Stamp Captured. */
    IfxCan_TimeStampState_captured    = 1   /**< \brief Timestamp captured and stored in TSU Timestamp register referenced by TXTSP or RXTSP. */
} IfxCan_TimeStampState;

/** \brief Type of Can Time Stamps used\n
 */
typedef enum
{
    IfxCan_TimeStamper_none        = 0,  /**< \brief No Time Stamps used. */
    IfxCan_TimeStamper_canInternal = 1,  /**< \brief Internal 16 bit Counter used. */
    IfxCan_TimeStamper_external    = 2,  /**< \brief 16 bit counter with external trigger source */
    IfxCan_TimeStamper_tsuInternal = 3,  /**< \brief TSU is used, Counter (32 bit) is internal. Available for all Nodes. */
    IfxCan_TimeStamper_tsuExternal = 4   /**< \brief TSU is used, Counter (32 bit) is external, comes from Node 0's counter. Available for all Nodes, except Node 0. */
} IfxCan_TimeStamper;

/** \brief Tigger Source for Can Timer\n
 * Defined in N.TIMER.CCR.B.TRIGSRC
 */
typedef enum
{
    IfxCan_TimerTrigger_clock = 0,  /**< \brief Trigger source is fSYNi */
    IfxCan_TimerTrigger_stm   = 1,  /**< \brief Trigger source is STM */
    IfxCan_TimerTrigger_gtm   = 2,  /**< \brief Trigger source is GTM */
    IfxCan_TimerTrigger_egtm  = 3   /**< \brief Trigger source is eGTM */
} IfxCan_TimerTrigger;

/** \brief TSU Internal Node's Counter or connect to TSU External Node 0 Counter\n
 */
typedef enum
{
    IfxCan_TsuCounter_internal = 0,  /**< \brief Internal TSU Counter is used, available for all nodes. */
    IfxCan_TsuCounter_external = 1   /**< \brief External TSU Counter is used, connects to Node 0's counter, available for Node 1, 2 and 3. Not valid for Node 0. */
} IfxCan_TsuCounter;

/** \brief Index of TSU Time Stamp Register
 */
typedef enum
{
    IfxCan_TsuTimeStampIndex_0 = 0,  /**< \brief Time Stamp Register 0 */
    IfxCan_TsuTimeStampIndex_1,      /**< \brief Time Stamp Register 1 */
    IfxCan_TsuTimeStampIndex_2,      /**< \brief Time Stamp Register 2 */
    IfxCan_TsuTimeStampIndex_3,      /**< \brief Time Stamp Register 3 */
    IfxCan_TsuTimeStampIndex_4,      /**< \brief Time Stamp Register 4 */
    IfxCan_TsuTimeStampIndex_5,      /**< \brief Time Stamp Register 5 */
    IfxCan_TsuTimeStampIndex_6,      /**< \brief Time Stamp Register 6 */
    IfxCan_TsuTimeStampIndex_7,      /**< \brief Time Stamp Register 7 */
    IfxCan_TsuTimeStampIndex_8,      /**< \brief Time Stamp Register 8 */
    IfxCan_TsuTimeStampIndex_9,      /**< \brief Time Stamp Register 9 */
    IfxCan_TsuTimeStampIndex_10,     /**< \brief Time Stamp Register 10 */
    IfxCan_TsuTimeStampIndex_11,     /**< \brief Time Stamp Register 11 */
    IfxCan_TsuTimeStampIndex_12,     /**< \brief Time Stamp Register 12 */
    IfxCan_TsuTimeStampIndex_13,     /**< \brief Time Stamp Register 13 */
    IfxCan_TsuTimeStampIndex_14,     /**< \brief Time Stamp Register 14 */
    IfxCan_TsuTimeStampIndex_15      /**< \brief Time Stamp Register 15 */
} IfxCan_TsuTimeStampIndex;

/** \brief Position of the Time Stamp\n
 * Refer TSU.TSCFG.B.SCP
 */
typedef enum
{
    IfxCan_TsuTimeStampPosition_endOfFrame   = 0, /**< \brief Time Stamp taken at end of the frame */
    IfxCan_TsuTimeStampPosition_startOfFrame = 1  /**< \brief Time Stamp taken at start of the frame */
} IfxCan_TsuTimeStampPosition;

/** \brief Tx Buffer number
 */
typedef enum
{
    IfxCan_TxBufferId_0,   /**< \brief Tx buffer 0 */
    IfxCan_TxBufferId_1,   /**< \brief Tx buffer 1 */
    IfxCan_TxBufferId_2,   /**< \brief Tx buffer 2 */
    IfxCan_TxBufferId_3,   /**< \brief Tx buffer 3 */
    IfxCan_TxBufferId_4,   /**< \brief Tx buffer 4 */
    IfxCan_TxBufferId_5,   /**< \brief Tx buffer 5 */
    IfxCan_TxBufferId_6,   /**< \brief Tx buffer 6 */
    IfxCan_TxBufferId_7,   /**< \brief Tx buffer 7 */
    IfxCan_TxBufferId_8,   /**< \brief Tx buffer 8 */
    IfxCan_TxBufferId_9,   /**< \brief Tx buffer 9 */
    IfxCan_TxBufferId_10,  /**< \brief Tx buffer 10 */
    IfxCan_TxBufferId_11,  /**< \brief Tx buffer 11 */
    IfxCan_TxBufferId_12,  /**< \brief Tx buffer 12 */
    IfxCan_TxBufferId_13,  /**< \brief Tx buffer 13 */
    IfxCan_TxBufferId_14,  /**< \brief Tx buffer 14 */
    IfxCan_TxBufferId_15,  /**< \brief Tx buffer 15 */
    IfxCan_TxBufferId_16,  /**< \brief Tx buffer 16 */
    IfxCan_TxBufferId_17,  /**< \brief Tx buffer 17 */
    IfxCan_TxBufferId_18,  /**< \brief Tx buffer 18 */
    IfxCan_TxBufferId_19,  /**< \brief Tx buffer 19 */
    IfxCan_TxBufferId_20,  /**< \brief Tx buffer 20 */
    IfxCan_TxBufferId_21,  /**< \brief Tx buffer 21 */
    IfxCan_TxBufferId_22,  /**< \brief Tx buffer 22 */
    IfxCan_TxBufferId_23,  /**< \brief Tx buffer 23 */
    IfxCan_TxBufferId_24,  /**< \brief Tx buffer 24 */
    IfxCan_TxBufferId_25,  /**< \brief Tx buffer 25 */
    IfxCan_TxBufferId_26,  /**< \brief Tx buffer 26 */
    IfxCan_TxBufferId_27,  /**< \brief Tx buffer 27 */
    IfxCan_TxBufferId_28,  /**< \brief Tx buffer 28 */
    IfxCan_TxBufferId_29,  /**< \brief Tx buffer 29 */
    IfxCan_TxBufferId_30,  /**< \brief Tx buffer 30 */
    IfxCan_TxBufferId_31   /**< \brief Tx buffer 31 */
} IfxCan_TxBufferId;

/** \brief Tx FIFO/Queue Mode
 */
typedef enum
{
    IfxCan_TxMode_fifo,              /**< \brief Tx FIFO operation */
    IfxCan_TxMode_queue,             /**< \brief Tx Queue operation */
    IfxCan_TxMode_dedicatedBuffers,  /**< \brief Tx dedicated buffers operation */
    IfxCan_TxMode_sharedFifo,        /**< \brief Tx shared dedicated buffers and Tx FIFO operation */
    IfxCan_TxMode_sharedQueue        /**< \brief Tx shared dedicated buffers and Tx Queue operation */
} IfxCan_TxMode;

/** \brief Extended Filter Type
 * Description in CAN_EXTMSG_F1.EFT
 */
typedef enum
{
    IfxCan_XtdFilterType_range,              /**< \brief Range filter from EFID1 to EFID2 (EFID2 is greater than EFID1) */
    IfxCan_XtdFilterType_dualId,             /**< \brief Dual ID filter for EFID1 or EFID2 */
    IfxCan_XtdFilterType_classic,            /**< \brief Classic filter: EFID1 = filter, EFID2 = mask */
    IfxCan_XtdFilterType_range_without_mask  /**< \brief Range filter from EFID1 to EFID2 (EFID2 is greater than EFID1), XIDAM mask not applied */
} IfxCan_XtdFilterType;

/** \brief Group ID for Extended Frames
 */
typedef enum
{
    IfxCan_XtdFrameGroupId_1 = 0,  /**< \brief Extended Frame Group 1 */
    IfxCan_XtdFrameGroupId_2,      /**< \brief Extended Frame Group 2 */
    IfxCan_XtdFrameGroupId_3,      /**< \brief Extended Frame Group 3 */
    IfxCan_XtdFrameGroupId_4,      /**< \brief Extended Frame Group 4 */
    IfxCan_XtdFrameGroupId_5,      /**< \brief Extended Frame Group 5 */
    IfxCan_XtdFrameGroupId_6,      /**< \brief Extended Frame Group 6 */
    IfxCan_XtdFrameGroupId_7,      /**< \brief Extended Frame Group 7 */
    IfxCan_XtdFrameGroupId_8,      /**< \brief Extended Frame Group 8 */
    IfxCan_XtdFrameGroupId_9,      /**< \brief Extended Frame Group 9 */
    IfxCan_XtdFrameGroupId_10,     /**< \brief Extended Frame Group 10 */
    IfxCan_XtdFrameGroupId_11,     /**< \brief Extended Frame Group 11 */
    IfxCan_XtdFrameGroupId_12,     /**< \brief Extended Frame Group 12 */
    IfxCan_XtdFrameGroupId_13,     /**< \brief Extended Frame Group 13 */
    IfxCan_XtdFrameGroupId_14,     /**< \brief Extended Frame Group 14 */
    IfxCan_XtdFrameGroupId_15,     /**< \brief Extended Frame Group 15 */
    IfxCan_XtdFrameGroupId_16,     /**< \brief Extended Frame Group 16 */
    IfxCan_XtdFrameGroupId_17,     /**< \brief Extended Frame Group 17 */
    IfxCan_XtdFrameGroupId_18,     /**< \brief Extended Frame Group 18 */
    IfxCan_XtdFrameGroupId_19,     /**< \brief Extended Frame Group 19 */
    IfxCan_XtdFrameGroupId_20,     /**< \brief Extended Frame Group 20 */
    IfxCan_XtdFrameGroupId_21,     /**< \brief Extended Frame Group 21 */
    IfxCan_XtdFrameGroupId_22,     /**< \brief Extended Frame Group 22 */
    IfxCan_XtdFrameGroupId_23,     /**< \brief Extended Frame Group 23 */
    IfxCan_XtdFrameGroupId_24,     /**< \brief Extended Frame Group 24 */
    IfxCan_XtdFrameGroupId_25,     /**< \brief Extended Frame Group 25 */
    IfxCan_XtdFrameGroupId_26,     /**< \brief Extended Frame Group 26 */
    IfxCan_XtdFrameGroupId_27,     /**< \brief Extended Frame Group 27 */
    IfxCan_XtdFrameGroupId_28,     /**< \brief Extended Frame Group 28 */
    IfxCan_XtdFrameGroupId_29,     /**< \brief Extended Frame Group 29 */
    IfxCan_XtdFrameGroupId_30,     /**< \brief Extended Frame Group 30 */
    IfxCan_XtdFrameGroupId_31,     /**< \brief Extended Frame Group 31 */
    IfxCan_XtdFrameGroupId_32,     /**< \brief Extended Frame Group 32 */
    IfxCan_XtdFrameGroupId_33,     /**< \brief Extended Frame Group 33 */
    IfxCan_XtdFrameGroupId_34,     /**< \brief Extended Frame Group 34 */
    IfxCan_XtdFrameGroupId_35,     /**< \brief Extended Frame Group 35 */
    IfxCan_XtdFrameGroupId_36,     /**< \brief Extended Frame Group 36 */
    IfxCan_XtdFrameGroupId_37,     /**< \brief Extended Frame Group 37 */
    IfxCan_XtdFrameGroupId_38,     /**< \brief Extended Frame Group 38 */
    IfxCan_XtdFrameGroupId_39,     /**< \brief Extended Frame Group 39 */
    IfxCan_XtdFrameGroupId_40,     /**< \brief Extended Frame Group 40 */
    IfxCan_XtdFrameGroupId_41,     /**< \brief Extended Frame Group 41 */
    IfxCan_XtdFrameGroupId_42,     /**< \brief Extended Frame Group 42 */
    IfxCan_XtdFrameGroupId_43,     /**< \brief Extended Frame Group 43 */
    IfxCan_XtdFrameGroupId_44,     /**< \brief Extended Frame Group 44 */
    IfxCan_XtdFrameGroupId_45,     /**< \brief Extended Frame Group 45 */
    IfxCan_XtdFrameGroupId_46,     /**< \brief Extended Frame Group 46 */
    IfxCan_XtdFrameGroupId_47,     /**< \brief Extended Frame Group 47 */
    IfxCan_XtdFrameGroupId_48,     /**< \brief Extended Frame Group 48 */
    IfxCan_XtdFrameGroupId_49,     /**< \brief Extended Frame Group 49 */
    IfxCan_XtdFrameGroupId_50,     /**< \brief Extended Frame Group 50 */
    IfxCan_XtdFrameGroupId_51,     /**< \brief Extended Frame Group 51 */
    IfxCan_XtdFrameGroupId_52,     /**< \brief Extended Frame Group 52 */
    IfxCan_XtdFrameGroupId_53,     /**< \brief Extended Frame Group 53 */
    IfxCan_XtdFrameGroupId_54,     /**< \brief Extended Frame Group 54 */
    IfxCan_XtdFrameGroupId_55,     /**< \brief Extended Frame Group 55 */
    IfxCan_XtdFrameGroupId_56,     /**< \brief Extended Frame Group 56 */
    IfxCan_XtdFrameGroupId_57,     /**< \brief Extended Frame Group 57 */
    IfxCan_XtdFrameGroupId_58,     /**< \brief Extended Frame Group 58 */
    IfxCan_XtdFrameGroupId_59,     /**< \brief Extended Frame Group 59 */
    IfxCan_XtdFrameGroupId_60,     /**< \brief Extended Frame Group 60 */
    IfxCan_XtdFrameGroupId_61,     /**< \brief Extended Frame Group 61 */
    IfxCan_XtdFrameGroupId_62,     /**< \brief Extended Frame Group 62 */
    IfxCan_XtdFrameGroupId_63,     /**< \brief Extended Frame Group 63 */
    IfxCan_XtdFrameGroupId_64      /**< \brief Extended Frame Group 64 */
} IfxCan_XtdFrameGroupId;

/** \brief Size of Extended Frame Rate Measurements
 */
typedef enum
{
    IfxCan_XtdFrameRateSize_0 = 0,  /**< \brief 0 Extended Frame Rate Measurements */
    IfxCan_XtdFrameRateSize_1,      /**< \brief 1 Extended Frame Rate Measurements */
    IfxCan_XtdFrameRateSize_2,      /**< \brief 2 Extended Frame Rate Measurements */
    IfxCan_XtdFrameRateSize_3,      /**< \brief 3 Extended Frame Rate Measurements */
    IfxCan_XtdFrameRateSize_4,      /**< \brief 4 Extended Frame Rate Measurements */
    IfxCan_XtdFrameRateSize_5,      /**< \brief 5 Extended Frame Rate Measurements */
    IfxCan_XtdFrameRateSize_6,      /**< \brief 6 Extended Frame Rate Measurements */
    IfxCan_XtdFrameRateSize_7,      /**< \brief 7 Extended Frame Rate Measurements */
    IfxCan_XtdFrameRateSize_8,      /**< \brief 8 Extended Frame Rate Measurements */
    IfxCan_XtdFrameRateSize_9,      /**< \brief 9 Extended Frame Rate Measurements */
    IfxCan_XtdFrameRateSize_10,     /**< \brief 10 Extended Frame Rate Measurements */
    IfxCan_XtdFrameRateSize_11,     /**< \brief 11 Extended Frame Rate Measurements */
    IfxCan_XtdFrameRateSize_12,     /**< \brief 12 Extended Frame Rate Measurements */
    IfxCan_XtdFrameRateSize_13,     /**< \brief 13 Extended Frame Rate Measurements */
    IfxCan_XtdFrameRateSize_14,     /**< \brief 14 Extended Frame Rate Measurements */
    IfxCan_XtdFrameRateSize_15,     /**< \brief 15 Extended Frame Rate Measurements */
    IfxCan_XtdFrameRateSize_16,     /**< \brief 16 Extended Frame Rate Measurements */
    IfxCan_XtdFrameRateSize_17,     /**< \brief 17 Extended Frame Rate Measurements */
    IfxCan_XtdFrameRateSize_18,     /**< \brief 18 Extended Frame Rate Measurements */
    IfxCan_XtdFrameRateSize_19,     /**< \brief 19 Extended Frame Rate Measurements */
    IfxCan_XtdFrameRateSize_20,     /**< \brief 20 Extended Frame Rate Measurements */
    IfxCan_XtdFrameRateSize_21,     /**< \brief 21 Extended Frame Rate Measurements */
    IfxCan_XtdFrameRateSize_22,     /**< \brief 22 Extended Frame Rate Measurements */
    IfxCan_XtdFrameRateSize_23,     /**< \brief 23 Extended Frame Rate Measurements */
    IfxCan_XtdFrameRateSize_24,     /**< \brief 24 Extended Frame Rate Measurements */
    IfxCan_XtdFrameRateSize_25,     /**< \brief 25 Extended Frame Rate Measurements */
    IfxCan_XtdFrameRateSize_26,     /**< \brief 26 Extended Frame Rate Measurements */
    IfxCan_XtdFrameRateSize_27,     /**< \brief 27 Extended Frame Rate Measurements */
    IfxCan_XtdFrameRateSize_28,     /**< \brief 28 Extended Frame Rate Measurements */
    IfxCan_XtdFrameRateSize_29,     /**< \brief 29 Extended Frame Rate Measurements */
    IfxCan_XtdFrameRateSize_30,     /**< \brief 30 Extended Frame Rate Measurements */
    IfxCan_XtdFrameRateSize_31,     /**< \brief 31 Extended Frame Rate Measurements */
    IfxCan_XtdFrameRateSize_32,     /**< \brief 32 Extended Frame Rate Measurements */
    IfxCan_XtdFrameRateSize_33,     /**< \brief 33 Extended Frame Rate Measurements */
    IfxCan_XtdFrameRateSize_34,     /**< \brief 34 Extended Frame Rate Measurements */
    IfxCan_XtdFrameRateSize_35,     /**< \brief 35 Extended Frame Rate Measurements */
    IfxCan_XtdFrameRateSize_36,     /**< \brief 36 Extended Frame Rate Measurements */
    IfxCan_XtdFrameRateSize_37,     /**< \brief 37 Extended Frame Rate Measurements */
    IfxCan_XtdFrameRateSize_38,     /**< \brief 38 Extended Frame Rate Measurements */
    IfxCan_XtdFrameRateSize_39,     /**< \brief 39 Extended Frame Rate Measurements */
    IfxCan_XtdFrameRateSize_40,     /**< \brief 40 Extended Frame Rate Measurements */
    IfxCan_XtdFrameRateSize_41,     /**< \brief 41 Extended Frame Rate Measurements */
    IfxCan_XtdFrameRateSize_42,     /**< \brief 42 Extended Frame Rate Measurements */
    IfxCan_XtdFrameRateSize_43,     /**< \brief 43 Extended Frame Rate Measurements */
    IfxCan_XtdFrameRateSize_44,     /**< \brief 44 Extended Frame Rate Measurements */
    IfxCan_XtdFrameRateSize_45,     /**< \brief 45 Extended Frame Rate Measurements */
    IfxCan_XtdFrameRateSize_46,     /**< \brief 46 Extended Frame Rate Measurements */
    IfxCan_XtdFrameRateSize_47,     /**< \brief 47 Extended Frame Rate Measurements */
    IfxCan_XtdFrameRateSize_48,     /**< \brief 48 Extended Frame Rate Measurements */
    IfxCan_XtdFrameRateSize_49,     /**< \brief 49 Extended Frame Rate Measurements */
    IfxCan_XtdFrameRateSize_50,     /**< \brief 50 Extended Frame Rate Measurements */
    IfxCan_XtdFrameRateSize_51,     /**< \brief 51 Extended Frame Rate Measurements */
    IfxCan_XtdFrameRateSize_52,     /**< \brief 52 Extended Frame Rate Measurements */
    IfxCan_XtdFrameRateSize_53,     /**< \brief 53 Extended Frame Rate Measurements */
    IfxCan_XtdFrameRateSize_54,     /**< \brief 54 Extended Frame Rate Measurements */
    IfxCan_XtdFrameRateSize_55,     /**< \brief 55 Extended Frame Rate Measurements */
    IfxCan_XtdFrameRateSize_56,     /**< \brief 56 Extended Frame Rate Measurements */
    IfxCan_XtdFrameRateSize_57,     /**< \brief 57 Extended Frame Rate Measurements */
    IfxCan_XtdFrameRateSize_58,     /**< \brief 58 Extended Frame Rate Measurements */
    IfxCan_XtdFrameRateSize_59,     /**< \brief 59 Extended Frame Rate Measurements */
    IfxCan_XtdFrameRateSize_60,     /**< \brief 60 Extended Frame Rate Measurements */
    IfxCan_XtdFrameRateSize_61,     /**< \brief 61 Extended Frame Rate Measurements */
    IfxCan_XtdFrameRateSize_62,     /**< \brief 62 Extended Frame Rate Measurements */
    IfxCan_XtdFrameRateSize_63,     /**< \brief 63 Extended Frame Rate Measurements */
    IfxCan_XtdFrameRateSize_64      /**< \brief 64 Extended Frame Rate Measurements */
} IfxCan_XtdFrameRateSize;

/** \brief Number of Routing Rules for Extended Frames
 */
typedef enum
{
    IfxCan_XtdRoutingRuleSize_0 = 0,  /**< \brief 0 Extended Frame Routing Rules */
    IfxCan_XtdRoutingRuleSize_1,      /**< \brief 1 Extended Frame Routing Rules */
    IfxCan_XtdRoutingRuleSize_2,      /**< \brief 2 Extended Frame Routing Rules */
    IfxCan_XtdRoutingRuleSize_3,      /**< \brief 3 Extended Frame Routing Rules */
    IfxCan_XtdRoutingRuleSize_4,      /**< \brief 4 Extended Frame Routing Rules */
    IfxCan_XtdRoutingRuleSize_5,      /**< \brief 5 Extended Frame Routing Rules */
    IfxCan_XtdRoutingRuleSize_6,      /**< \brief 6 Extended Frame Routing Rules */
    IfxCan_XtdRoutingRuleSize_7,      /**< \brief 7 Extended Frame Routing Rules */
    IfxCan_XtdRoutingRuleSize_8,      /**< \brief 8 Extended Frame Routing Rules */
    IfxCan_XtdRoutingRuleSize_9,      /**< \brief 9 Extended Frame Routing Rules */
    IfxCan_XtdRoutingRuleSize_10,     /**< \brief 10 Extended Frame Routing Rules */
    IfxCan_XtdRoutingRuleSize_11,     /**< \brief 11 Extended Frame Routing Rules */
    IfxCan_XtdRoutingRuleSize_12,     /**< \brief 12 Extended Frame Routing Rules */
    IfxCan_XtdRoutingRuleSize_13,     /**< \brief 13 Extended Frame Routing Rules */
    IfxCan_XtdRoutingRuleSize_14,     /**< \brief 14 Extended Frame Routing Rules */
    IfxCan_XtdRoutingRuleSize_15,     /**< \brief 15 Extended Frame Routing Rules */
    IfxCan_XtdRoutingRuleSize_16,     /**< \brief 16 Extended Frame Routing Rules */
    IfxCan_XtdRoutingRuleSize_17,     /**< \brief 17 Extended Frame Routing Rules */
    IfxCan_XtdRoutingRuleSize_18,     /**< \brief 18 Extended Frame Routing Rules */
    IfxCan_XtdRoutingRuleSize_19,     /**< \brief 19 Extended Frame Routing Rules */
    IfxCan_XtdRoutingRuleSize_20,     /**< \brief 20 Extended Frame Routing Rules */
    IfxCan_XtdRoutingRuleSize_21,     /**< \brief 21 Extended Frame Routing Rules */
    IfxCan_XtdRoutingRuleSize_22,     /**< \brief 22 Extended Frame Routing Rules */
    IfxCan_XtdRoutingRuleSize_23,     /**< \brief 23 Extended Frame Routing Rules */
    IfxCan_XtdRoutingRuleSize_24,     /**< \brief 24 Extended Frame Routing Rules */
    IfxCan_XtdRoutingRuleSize_25,     /**< \brief 25 Extended Frame Routing Rules */
    IfxCan_XtdRoutingRuleSize_26,     /**< \brief 26 Extended Frame Routing Rules */
    IfxCan_XtdRoutingRuleSize_27,     /**< \brief 27 Extended Frame Routing Rules */
    IfxCan_XtdRoutingRuleSize_28,     /**< \brief 28 Extended Frame Routing Rules */
    IfxCan_XtdRoutingRuleSize_29,     /**< \brief 29 Extended Frame Routing Rules */
    IfxCan_XtdRoutingRuleSize_30,     /**< \brief 30 Extended Frame Routing Rules */
    IfxCan_XtdRoutingRuleSize_31,     /**< \brief 31 Extended Frame Routing Rules */
    IfxCan_XtdRoutingRuleSize_32,     /**< \brief 32 Extended Frame Routing Rules */
    IfxCan_XtdRoutingRuleSize_33,     /**< \brief 33 Extended Frame Routing Rules */
    IfxCan_XtdRoutingRuleSize_34,     /**< \brief 34 Extended Frame Routing Rules */
    IfxCan_XtdRoutingRuleSize_35,     /**< \brief 35 Extended Frame Routing Rules */
    IfxCan_XtdRoutingRuleSize_36,     /**< \brief 36 Extended Frame Routing Rules */
    IfxCan_XtdRoutingRuleSize_37,     /**< \brief 37 Extended Frame Routing Rules */
    IfxCan_XtdRoutingRuleSize_38,     /**< \brief 38 Extended Frame Routing Rules */
    IfxCan_XtdRoutingRuleSize_39,     /**< \brief 39 Extended Frame Routing Rules */
    IfxCan_XtdRoutingRuleSize_40,     /**< \brief 40 Extended Frame Routing Rules */
    IfxCan_XtdRoutingRuleSize_41,     /**< \brief 41 Extended Frame Routing Rules */
    IfxCan_XtdRoutingRuleSize_42,     /**< \brief 42 Extended Frame Routing Rules */
    IfxCan_XtdRoutingRuleSize_43,     /**< \brief 43 Extended Frame Routing Rules */
    IfxCan_XtdRoutingRuleSize_44,     /**< \brief 44 Extended Frame Routing Rules */
    IfxCan_XtdRoutingRuleSize_45,     /**< \brief 45 Extended Frame Routing Rules */
    IfxCan_XtdRoutingRuleSize_46,     /**< \brief 46 Extended Frame Routing Rules */
    IfxCan_XtdRoutingRuleSize_47,     /**< \brief 47 Extended Frame Routing Rules */
    IfxCan_XtdRoutingRuleSize_48,     /**< \brief 48 Extended Frame Routing Rules */
    IfxCan_XtdRoutingRuleSize_49,     /**< \brief 49 Extended Frame Routing Rules */
    IfxCan_XtdRoutingRuleSize_50,     /**< \brief 50 Extended Frame Routing Rules */
    IfxCan_XtdRoutingRuleSize_51,     /**< \brief 51 Extended Frame Routing Rules */
    IfxCan_XtdRoutingRuleSize_52,     /**< \brief 52 Extended Frame Routing Rules */
    IfxCan_XtdRoutingRuleSize_53,     /**< \brief 53 Extended Frame Routing Rules */
    IfxCan_XtdRoutingRuleSize_54,     /**< \brief 54 Extended Frame Routing Rules */
    IfxCan_XtdRoutingRuleSize_55,     /**< \brief 55 Extended Frame Routing Rules */
    IfxCan_XtdRoutingRuleSize_56,     /**< \brief 56 Extended Frame Routing Rules */
    IfxCan_XtdRoutingRuleSize_57,     /**< \brief 57 Extended Frame Routing Rules */
    IfxCan_XtdRoutingRuleSize_58,     /**< \brief 58 Extended Frame Routing Rules */
    IfxCan_XtdRoutingRuleSize_59,     /**< \brief 59 Extended Frame Routing Rules */
    IfxCan_XtdRoutingRuleSize_60,     /**< \brief 60 Extended Frame Routing Rules */
    IfxCan_XtdRoutingRuleSize_61,     /**< \brief 61 Extended Frame Routing Rules */
    IfxCan_XtdRoutingRuleSize_62,     /**< \brief 62 Extended Frame Routing Rules */
    IfxCan_XtdRoutingRuleSize_63,     /**< \brief 63 Extended Frame Routing Rules */
    IfxCan_XtdRoutingRuleSize_64      /**< \brief 64 Extended Frame Routing Rules */
} IfxCan_XtdRoutingRuleSize;

/** \} */

/** \brief Type of Std PDU\n
 * Refer PR.B.TYP in SRTk
 */
typedef enum
{
    IfxCan_StdPduType_type1 = 1,  /**< \brief 11- bit Standard CAN ID with No Metadata */
    IfxCan_StdPduType_type2 = 2,  /**< \brief 11- bit Standard CAN ID with Metadata */
    IfxCan_StdPduType_type3 = 3   /**< \brief 11- bit Standard CAN ID with Optional Metadata */
} IfxCan_StdPduType;

/** \brief Type of Xtd PDU\n
 * Refer PR.B.TYP in XRTk
 */
typedef enum
{
    IfxCan_XtdPduType_type4 = 4,  /**< \brief 29- bit Extended CAN ID with No Metadata */
    IfxCan_XtdPduType_type5 = 5   /**< \brief 29- bit Extended CAN ID with No Metadata and No Source ID */
} IfxCan_XtdPduType;

/******************************************************************************/
/*-----------------------------Data Structures--------------------------------*/
/******************************************************************************/

/** \addtogroup IfxLld_Can_Std_Data_Structures
 * \{ */
/** \brief Configuration for Interrupt groups
 */
typedef struct
{
    IfxCan_InterruptLine interruptLine;       /**< \brief Intterupt line to which this interruipt has to be connetced to */
    Ifx_Priority         priority;            /**< \brief Priority of the interrupt. Range: 0 to 0xFF */
    IfxSrc_Tos           typeOfService;       /**< \brief Type of Service */
    IfxSrc_VmId          vmId;                /**< \brief Virtual Machine Number */
} IfxCan_GroupInterruptConfig;

/** \} */

/** \addtogroup IfxLld_Can_Std_Data_Structures
 * \{ */
/** \brief Structure for Cre Interrupt configuration
 */
typedef struct
{
    boolean                     rxBuffer0InterruptEnable;                             /**< \brief Interrupt Enable for Interrupts related to Rx Buffer 0 */
    boolean                     rxBuffer1InterruptEnable;                             /**< \brief Interrupt Enable for Interrupts related to Rx Buffer 1 */
    boolean                     txBuffer0InterruptEnable;                             /**< \brief Interrupt Enable for Interrupts related to Tx Buffer 0 */
    boolean                     txBuffer1InterruptEnable;                             /**< \brief Interrupt Enable for Interrupts related to Tx Buffer 1 */
    boolean                     IdmuStdFrameRateMeasurementLostInterruptEnable;       /**< \brief Interrupt Enable for Idmu Standard Frame Rate Measurement Lost Interrupt */
    boolean                     IdmuXtdFrameRateMeasurementLostInterruptEnable;       /**< \brief Interrupt Enable for Idmu Extended Frame Rate Measurement Lost Interrupt */
    boolean                     creErrorInterruptEnable;                              /**< \brief Interrupt Enable for Cre Error Interrupts */
    IfxCan_GroupInterruptConfig rxHBuf0;                                              /**< \brief Configuration for Rx Host Buffer 0 interrupts */
    IfxCan_GroupInterruptConfig rxHBuf1;                                              /**< \brief Configuration for Rx Host Buffer 1 interrupts */
    IfxCan_GroupInterruptConfig txHBuf0;                                              /**< \brief Configuration for Tx Host Buffer interrupts 0 */
    IfxCan_GroupInterruptConfig txHBuf1;                                              /**< \brief Configuration for Tx Host Buffer interrupts 1 */
    IfxCan_GroupInterruptConfig idmu;                                                 /**< \brief Configuration for Idmu interrupts */
    IfxCan_GroupInterruptConfig creError;                                             /**< \brief Configuration for Cre Error Interrupts */
} IfxCan_CreInterruptConfig;

/** \} */

/** \addtogroup IfxLld_Can_Std_Data_Structures
 * \{ */
/** \brief PROT and APU configuration
 */
typedef struct
{
    IfxApProt_ProtConfig proteConfig;          /**< \brief PROTE configurations */
    IfxApProt_ProtConfig protseConfig;         /**< \brief PROTSE Configuration */
    IfxApApu_ApuConfig   apuCanConfig;         /**< \brief APU Configurations for CAN */
    IfxApApu_ApuConfig   apuNode0Config;       /**< \brief APU Configurations for Node 0 */
    IfxApApu_ApuConfig   apuNode1Config;       /**< \brief APU Configurations for Node 1 */
    IfxApApu_ApuConfig   apuNode2Config;       /**< \brief APU Configurations for Node 2 */
    IfxApApu_ApuConfig   apuNode3Config;       /**< \brief APU Configurations for Node 3 */
} IfxCan_ApConfig;

/** \brief Structure for CRE configuration
 * To do for PD3: RT and BUF
 */
typedef struct
{
    uint16                    creStartAddress;                        /**< \brief CRE RAM Start Address for CRE_CONFIGADR.SA. Must be 32 bit word aligned. The value is right shifted by 2 and assigned to CRE_CONFIGADR.SA. Range: 0 to 0x3FFF0 */
    uint16                    stdRoutingTableStartAddress;            /**< \brief CRE Standard Routing Table Start Address. Must be 32 bit word aligned. The value is right shifted by 2 and assigned to STD_RT_PARAM.B.SA. Range: 0 to 0x3FFF */
    uint16                    xtdRoutingTableStartAddress;            /**< \brief CRE Extended Routing Table Start Address. Must be 32 bit word aligned. The value is right shifted by 2 and assigned to XTD_RT_PARAM.B.SA. Range: 0 to 0x3FFF */
    uint16                    stdFrameRateTableStartAddress;          /**< \brief CRE Standard Frame Rate Table Start Address. Must be 32 bit word aligned. The value is right shifted by 2 and assigned to STD_FRT_PARAM.B.SA. Range: 0 to 0x3FFF */
    uint16                    xtdFrameRateTableStartAddress;          /**< \brief CRE Extended Frame Rate Table Start Address. Must be 32 bit word aligned. The value is right shifted by 2 and assigned to XTD_FRT_PARAM.B.SA. Range: 0 to 0x3FFF */
    uint16                    stdTimeStampDatabaseStartAddress;       /**< \brief CRE Standard Time Stamp Database Start Address. Must be 32 bit word aligned. The value is right shifted by 2 and assigned to STD_TSD_PARAM.B.SA. Range: 0 to 0x3FFF */
    uint16                    xtdTimeStampDatabaseStartAddress;       /**< \brief CRE Extended Time Stamp Database Start Address. Must be 32 bit word aligned. The value is right shifted by 2 and assigned to XTD_TSD_PARAM.B.SA. Range: 0 to 0x3FFF */
    IfxCan_StdRoutingRuleSize stdRoutingRuleSize;                     /**< \brief Size of Routing Table for Standard Frames. 0 means Routing Table is disabled. Upto 128 Routing entries for Standard Frames. */
    IfxCan_XtdRoutingRuleSize xtdRoutingRuleSize;                     /**< \brief Size of Routing Table for Extended Frames. 0 means Routing Table is disabled. Upto 64 Routing entries for Extended Frames. */
    IfxCan_StdFrameRateSize   stdFrameRateTableSize;                  /**< \brief Size of Frame Rate Table for Standard Frames. 0 means Frame Rate Table is disabled. Upto 128 for 128 Standard Can Group IDs. */
    IfxCan_XtdFrameRateSize   xtdFrameRateTableSize;                  /**< \brief Size of Frame Rate Table for Extended Frames. 0 means Frame Rate Table is disabled. Upto 64 for 64 Extended Can Group IDs. */
    boolean                   enableCre;                              /**< \brief Bit to enable or disable CRE */
    boolean                   enableCreRouting;                       /**< \brief Bit to enable or disable Rounting in CRE. */
    boolean                   enableIdmu;                             /**< \brief Bit to enable or disable Intrusion Detection Measurement Features in CRE. */
    boolean                   rxBuf0LastReadMode;                     /**< \brief Last Read Mode for Rx Buffer 0 */
    boolean                   rxBuf1LastReadMode;                     /**< \brief Last Read Mode for Rx Buffer 1 */
    boolean                   txBuf0LastWriteMode;                    /**< \brief Last Write Mode for Tx Buffer 0 */
    boolean                   txBuf1LastWriteMode;                    /**< \brief Last Write Mode for Tx Buffer 1 */
    uint8                     rxBuf0FixedDataLength;                  /**< \brief Fixed Data Length for messages received in Rx Buffer 0. Last Read mode must be set. Range: 0 to 16 */
    uint8                     rxBuf1FixedDataLength;                  /**< \brief Fixed Data Length for messages received in Rx Buffer 1. Last Write mode must be set. Range: 0 to 16  */
    uint8                     txBuf0FixedDataLength;                  /**< \brief Fixed Data Length of messages written to Tx Buffer 0. Last Write mode must be set. Range: 0 to 16  */
    uint8                     txBuf1FixedDataLength;                  /**< \brief Fixed Data Length of messages written to Tx Buffer 1. Last Write mode must be set. Range: 0 to 16  */
    boolean                   rxBuf0DreTriggerEnable;                 /**< \brief Dre Trigger Enable for Rx Buffer 0 */
    boolean                   rxBuf1DreTriggerEnable;                 /**< \brief Dre Trigger Enable for Rx Buffer 1 */
    IfxCan_CreInterruptConfig interrupt;                              /**< \brief Structure for Interrupt configuration */
    boolean                   enableDestinationRouting;               /**< \brief Bit to enable or disable Destination node routing of the CAN frame to the Tx FIFO */
    boolean                   rxBuf0CrcEnable;                        /**< \brief Crc Enable for Rx Buffer 0 */
    boolean                   rxBuf1CrcEnable;                        /**< \brief Crc Enable for Rx Buffer 1 */
    boolean                   txBuf0CrcEnable;                        /**< \brief Crc Enable for Tx Buffer 0 */
    boolean                   txBuf1CrcEnable;                        /**< \brief Crc Enable for Tx Buffer 1 */
    boolean                   txBuf0CrcGate;                          /**< \brief Crc Gate for Tx Buffer 0. False: the CAN frame with CRC error is not discarded by the CRE, TRUE: the CAN frame with CRC error is discarded */
    boolean                   txBuf1CrcGate;                          /**< \brief Crc Gate for Tx Buffer 1. False: the CAN frame with CRC error is not discarded by the CRE, TRUE: the CAN frame with CRC error is discarded */
} IfxCan_CreConfig;

/** \brief Structure to read contents and status bits related to CRE Rx Buffers
 */
typedef struct
{
    Ifx_CAN_RHBUF rxHostBuffer;              /**< \brief CRE RX RHBUF OBject */
    boolean       isMessageAvailable;        /**< \brief Status Flag for New Message Available (RX_HBUFy_STAT.B.RyHREQ, y=0-1) */
    boolean       isRoutingValid;            /**< \brief Status Flag for Valid Routing Header (RX_HBUFy_STAT.B.VRH, y=0/1) */
    boolean       isTimeStampCaptured;       /**< \brief Status Flag for Valid Time Stamp (THEAD_INTRD.B.TSC) */
} IfxCan_CreRxBuffer;

/** \brief Structure for configuration parameters of CRE THBUF
 */
typedef struct
{
    IfxCan_CreTxHostBufferIndex txBufIndex;                  /**< \brief THBUF Index in CRE */
    uint32                      messageId;                   /**< \brief ID, CAN Message Identifier. Range: 0x000 to 0x7FF (Standard); 0 to 0x1FFFFFFF (Extended) */
    boolean                     remoteTransmitRequest;       /**< \brief RTR, Remote Transmit Request */
    boolean                     messageIdLength;             /**< \brief XTD, Message Id length (Standard / Extended) */
    boolean                     errorStateIndicator;         /**< \brief ESI, Error State Indicator */
    IfxCan_DataLengthCode       dataLengthCode;              /**< \brief DLC, Data Length Code */
    boolean                     bitRateSwitching;
    boolean                     frameFormat;                 /**< \brief CAN frame mode */
    boolean                     txEventFifoControl;          /**< \brief EFC, Tx Event FIFO Control (enable / disable) */
    uint16                      crc;                         /**< \brief CRC to be verified by CRE. CRC computed by application over the safety critical CAN payload of the CAN frame. This CRC is verified by the CRE before writing the CAN frame to the TxQueue. Range 0 to 0xFFFF */
} IfxCan_CreTxMsgConfig;

/** \brief Structure for Filter configuration
 */
typedef struct
{
    uint8                             number;                     /**< \brief Filter Number. Range: 0 to 32 */
    IfxCan_FilterElementConfiguration elementConfiguration;       /**< \brief *FEC, Filter Element Configuration of (standard / extended ID) filter element */
    IfxCan_StdFilterType              stdType;                    /**< \brief *SFT, Filter Type of standard ID filter element */
    IfxCan_XtdFilterType              xtdType;                    /**< \brief *EFT, Filter Type of extended ID filter element */
    uint32                            id1;                        /**< \brief *FID1 First ID of (standard / extended ID) filter element. Range: 0 to 0x1FFFFFFF */
    uint32                            id2;                        /**< \brief *FID2 Second ID of (standard / extended ID) filter element. Range: 0 to 0x1FFFFFFF */
    IfxCan_RxBufferId                 rxBufferOffset;             /**< \brief Rx Buffer number to set the offset to the Rx Buffer Start Address */
    boolean                           txTimeStampEnabled;         /**< \brief Time Stamp is enabled */
} IfxCan_Filter;

/** \brief Structure for CAN Message configuration (transmit/receive)
 */
typedef struct
{
    uint8                  bufferNumber;                  /**< \brief (Tx / Rx) Buffer Element number. Range: 0 to 31 */
    uint32                 messageId;                     /**< \brief ID, Identifier. Range: 0x000 to 0x7FF (Standard); 0 to 0x1FFFFFFF (Extended) */
    boolean                remoteTransmitRequest;         /**< \brief RTR, Remote Transmit Request (enable / disable) */
    IfxCan_MessageIdLength messageIdLength;               /**< \brief XTD, Message Id length (Standard / Extended) */
    boolean                errorStateIndicator;           /**< \brief ESI, Error State Indicator (enable / disable) */
    IfxCan_DataLengthCode  dataLengthCode;                /**< \brief DLC, Data Length Code */
    IfxCan_FrameMode       frameMode;                     /**< \brief CAN frame mode */
    boolean                txEventFifoControl;            /**< \brief EFC, Tx Event FIFO Control (enable / disable) */
    boolean                storeInTxFifoQueue;            /**< \brief Write message in Tx FIFO/QUEUE */
    boolean                readFromRxFifo0;               /**< \brief Read message from Rx FIFO 0 */
    boolean                readFromRxFifo1;               /**< \brief Read message from Rx FIFO 1 */
    IfxCan_TimeStamper     timeStampType;                 /**< \brief Time Stamp Type: to be filled based on "timeStampConfig.timeStamper" value in initNode config */
    uint32                 rxTimeStamp;                   /**< \brief Time Stamp value captured, refer to timeStampType value to determine time stamp mechanism used. Range: 0 to 0xFFFF */
    boolean                txTimeStampEnabled;            /**< \brief Time Stamp is enabled TRUE: Tx Event Time Stamp Capture enabled. FALSE: Tx Event Time Stamp Capture disabled. */
    boolean                bypassSwTransmitRequest;       /**< \brief Bypass SW Transmission request TRUE: TXBAR.ARz is not set. FALSE: TXBAR.ARz is set */
} IfxCan_Message;

/** \brief Structure for Message RAM configuration
 */
typedef struct
{
    uint32 baseAddress;                          /**< \brief Message RAM base address of the CAN. Range: 0xF0200000 to 0xF0223FFF */
    uint16 standardFilterListStartAddress;       /**< \brief Start address of Standard Message ID filter list (32-bit word address). Range: 0 to 0xFFFC */
    uint16 extendedFilterListStartAddress;       /**< \brief Start address of Extended Message ID filter list (32-bit word address). Range: 0 to 0xFFFC */
    uint16 rxFifo0StartAddress;                  /**< \brief Start address of Rx FIFO 0 in Message RAM (32-bit word address). Range: 0x0000 to 0x3FFF */
    uint16 rxFifo1StartAddress;                  /**< \brief Start address of Rx FIFO 1 in Message RAM (32-bit word address). Range: 0x0000 to 0x3FFF */
    uint16 rxBuffersStartAddress;                /**< \brief Start address of Rx Buffers section in the Message RAM (32-bit word address). Range: 0x0000 to 0x3FFF */
    uint16 txEventFifoStartAddress;              /**< \brief Start address of Tx Event FIFO in Message RAM (32-bit word address). Range: 0x0000 to 0x3FFF */
    uint16 txBuffersStartAddress;                /**< \brief Start address of Tx Buffers section in the Message RAM (32-bit word address). Range: 0x0000 to 0x3FFF */
} IfxCan_MessageRAM;

/** \brief structure for Standard Multicast Routing configuration
 */
typedef struct
{
    uint8                index;                /**< \brief Routing Rule Index (0-127) */
    IfxCan_DestinationId destinationId0;       /**< \brief 1st Destination ID */
    IfxCan_DestinationId destinationId1;       /**< \brief 2nd Destination ID */
    IfxCan_DestinationId destinationId2;       /**< \brief 3rd Destination ID */
    IfxCan_DestinationId destinationId3;       /**< \brief 4th Destination ID */
} IfxCan_StdMulticastRouting;

/** \brief structure for Standard Unicast Routing configuration
 */
typedef struct
{
    uint8                index;                          /**< \brief Routing Rule Index (0-127) */
    IfxCan_DestinationId destinationId;                  /**< \brief Destination ID */
    boolean              enableFormatModification;       /**< \brief CAN Frame Format Modifier enable bit. TRUE: Enabled, FALSE: Disabled */
    boolean              frameType;                      /**< \brief Type of Can Frame. 0: Classical CAN frame format, 1: CAN FD frame format */
    boolean              lengthModifier;                 /**< \brief Enable Data Length Code (DLC) Modification. 0: Destination CAN frame length is same as the received CAN frame, 1: Destination CAN Frame length is as defined by ISO 11898-1 */
    uint16               canIdModifier;                  /**< \brief 11 bit CAN Frame ID modifier value. The New Destination CAN Frame ID = (canIdModifier XOR RX_CANID). Range: 0 to 0x7FF */
} IfxCan_StdUnicastRouting;

/** \brief Configuration for Time Stamping Unit (TSU)
 */
typedef struct
{
    IfxCan_TsuCounter           tsuCounterType;       /**< \brief Internal Counter or external Node 0 Counter. */
    IfxCan_TsuTimeStampPosition position;             /**< \brief Time Stamp Position, at start or end of frame. */
    uint8                       prescalar;            /**< \brief Prescalar for Internal Counter. Range: 0 to 15 */
} IfxCan_TsuConfig;

/** \brief structure for Extended Multicast Routing configuration
 */
typedef struct
{
    uint8                index;                /**< \brief Routing Rule Index (0-63) */
    IfxCan_DestinationId destinationId0;       /**< \brief 1st Destination ID */
    IfxCan_DestinationId destinationId1;       /**< \brief 2nd Destination ID */
    IfxCan_DestinationId destinationId2;       /**< \brief 3rd Destination ID */
    IfxCan_DestinationId destinationId3;       /**< \brief 4th Destination ID */
} IfxCan_XtdMulticastRouting;

/** \brief structure for Extended Unicast Routing configuration
 */
typedef struct
{
    uint8                index;               /**< \brief Routing Rule Index (0-63) */
    IfxCan_DestinationId destinationId;       /**< \brief Destination ID */
} IfxCan_XtdUnicastRouting;

/** \} */

/** \brief Enable CRE Node Error Interrupts.
 * Refer to Ifx_CAN_N_ERRCTRL
 */
typedef struct
{
    boolean rxWatchdogTimeout0 : 1;              /**< \brief Enable Recieve watchdog timeout 0 error interrupt . Set:Enabled, Reset:Disabled */
    boolean rxWatchdogTimeout1 : 1;              /**< \brief Enable Recieve watchdog timeout 1 error interrupt . Set:Enabled, Reset:Disabled */
    boolean txWatchdogTimeout0 : 1;              /**< \brief Enable Transmit watchdog timeout 0 error interrupt. Set:Enabled, Reset:Disabled */
    boolean txWatchdogTimeout1 : 1;              /**< \brief Enable Transmit watchdog timeout 1 error interrupt. Set:Enabled, Reset:Disabled */
    boolean crcError : 1;                        /**< \brief Enable CRE CRC error interrupt. Set:Enabled, Reset:Disabled */
    boolean incorrectReadSequenceError : 1;      /**< \brief Enable CRE Incorrect Read Sequence Error Interrupt. Set:Enabled, Reset:Disabled */
    boolean incorrectWriteSequenceError : 1;     /**< \brief Enable CRE Incorrect Write Sequence Error Interrupt. Set:Enabled, Reset:Disabled */
} IfxCan_CreErrorInterruptEnable;

/** \brief Enable CRE Node Watchdog Groups.
 * Refer to Ifx_CAN_N_ERRCTRL
 */
typedef struct
{
    boolean group1 : 1;     /**< \brief Enable bit for monitoring event group 1. Refer to Ifx_CAN_N_ERRCTRL.WDG1 in UM for more details. Set:Enabled, Reset:Disabled */
    boolean group2 : 1;     /**< \brief Enable bit for monitoring event group 2. Refer to Ifx_CAN_N_ERRCTRL.WDG2 in UM for more details. Set:Enabled, Reset:Disabled */
    boolean group3 : 1;     /**< \brief Enable bit for monitoring event group 3. Refer to Ifx_CAN_N_ERRCTRL.WDG3 in UM for more details. Set:Enabled, Reset:Disabled */
} IfxCan_CreWatchdogGroups;

/** \brief structure for Standard PDU Routing configuration
 */
typedef struct
{
    uint8                index;               /**< \brief Routing Rule Index (0-127) */
    IfxCan_DestinationId destinationId;       /**< \brief Destination ID */
    IfxCan_StdPduType    pduType;             /**< \brief Type of PDU */
    uint16               metadata;            /**< \brief 16 bit SW configured Metadata used in the PDU ID generation */
} IfxCan_StdPduRouting;

/** \brief structure for Extended PDU Routing configuration
 */
typedef struct
{
    uint8                index;               /**< \brief Routing Rule Index (0-127) */
    IfxCan_DestinationId destinationId;       /**< \brief Destination ID */
    IfxCan_XtdPduType    pduType;             /**< \brief Type of PDU */
} IfxCan_XtdPduRouting;

/** \addtogroup IfxLld_Can_Std_Enum
 * \{ */

/******************************************************************************/
/*-------------------------Inline Function Prototypes-------------------------*/
/******************************************************************************/

/** \brief Enables/Disables the Standard Filter Sync.
 *
 * \param[inout] standardFilterElement Standard Filter Element.
 * \param[in]    enable                1: enables the SSYNC, 0: disables the SSYNC.
 *
 * \retval None
 */
IFX_INLINE void IfxCan_Node_setStandardFilterSync(Ifx_CAN_STDMSG *standardFilterElement, boolean enable);

/** \brief Reset the CRE RX host buffer Watchdog.
 *
 * \param[inout] node              Specifies the pointer to the CAN Node registers.
 * \param[in]    rxHostBufferIndex Rx host Buffer index. Range: \ref IfxCan_CreRxHostBufferIndex.
 *
 * \retval None
 */
IFX_INLINE void IfxCan_Node_resetRxBufferWatchdogEventGroup(Ifx_CAN_N *node, IfxCan_CreRxHostBufferIndex rxHostBufferIndex);

/** \} */

/** \addtogroup IfxLld_Can_Std_Data_Structures
 * \{ */

/******************************************************************************/
/*-------------------------Global Function Prototypes-------------------------*/
/******************************************************************************/

/** \brief Sets CAN frame mode request for transmission.
 * This function is deprecated. Use new function IfxCan_Node_setFrameModeReq.
 *
 * \param[in]    node            Specifies the pointer to the CAN Node registers.
 * \param[inout] txBufferElement Tx Buffer Element.
 * \param[in]    frameMode       CAN frame mode. Range: \ref IfxCan_FrameMode.
 *
 * \retval None
 */
IFX_EXTERN void IfxCan_Node_setFrameModeRequest(Ifx_CAN_N *node, Ifx_CAN_TXMSG *txBufferElement, IfxCan_FrameMode frameMode);

/** \} */

/** \addtogroup IfxLld_Can_Std_Node_Functions
 * \{ */

/******************************************************************************/
/*-------------------------Inline Function Prototypes-------------------------*/
/******************************************************************************/

/** \brief Disables the configuration change\n.
 * The CPU has no write access to the protected configuration registers.
 *
 * \param[inout] node Specifies the pointer to the CAN Node registers.
 *
 * \retval None
 */
IFX_INLINE void IfxCan_Node_disableConfigurationChange(Ifx_CAN_N *node);

/** \brief Enables the configuration change\n.
 * The CPU has write access to the protected configuration registers (while CCCR.INIT = 1).
 *
 * \param[inout] node Specifies the pointer to the CAN Node registers.
 *
 * \retval None
 */
IFX_INLINE void IfxCan_Node_enableConfigurationChange(Ifx_CAN_N *node);

/** \brief Enables the internal Virtual CAN bus loopback mode.
 *
 * \param[inout] node Specifies the pointer to the CAN Node registers.
 *
 * \retval None
 */
IFX_INLINE void IfxCan_Node_enableLoopbackMode(Ifx_CAN_N *node);

/** \brief Enables the external Virtual CAN bus loopback out mode.
 *
 * \param[inout] node Specifies the pointer to the CAN Node registers.
 *
 * \retval None
 */
IFX_INLINE void IfxCan_Node_enableLoopbackOutMode(Ifx_CAN_N *node);

/** \brief Returns the status of whether the CAN Node is synchronised or not.
 *
 * \param[in] node Specifies the pointer to the CAN Node registers.
 *
 * \retval Status TRUE: synchronized, FALSE : Sync in progress.
 */
IFX_INLINE boolean IfxCan_Node_isNodeSynchronized(Ifx_CAN_N *node);

/** \brief Initializes the node\n.
 * 0= Normal Operation\n.
 * 1= Initialization is started.
 *
 * \param[inout] node   Specifies the pointer to the CAN Node registers.
 * \param[in]    enable Enable / Disable choice.
 *
 * \retval None
 */
IFX_INLINE void IfxCan_Node_setInitialisation(Ifx_CAN_N *node, boolean enable);

/** \brief Sets Transceiver Delay Compensation offset.
 *
 * \param[inout] node  Specifies the pointer to the CAN Node registers.
 * \param[in]    delay Delay offset value. Range: 0 to 127.
 *
 * \retval None
 */
IFX_INLINE void IfxCan_Node_setTransceiverDelayCompensationOffset(Ifx_CAN_N *node, uint8 delay);

/** \brief Get the LEC error status of the CAN node.
 *
 * \param[in] node Specifies the pointer to CAN node registers.
 *
 * \retval IfxCan_LastErrorCodeType LEC error status in CAN node PSR register. Range: \ref IfxCan_LastErrorCodeType.
 */
IFX_INLINE IfxCan_LastErrorCodeType IfxCan_Node_getLastErroCodeStatus(Ifx_CAN_N *node);

/** \brief Error Passive status of the CAN node.
 * TRUE: CAN node in error passive.
 * FALSE: CAN node not in error passive.
 *
 * \param[in] node Specifies the pointer to CAN node registers.
 *
 * \retval Error Passive error status of CAN node (TRUE/FALSE).
 */
IFX_INLINE boolean IfxCan_Node_isErrorPassive(Ifx_CAN_N *node);

/** \brief Get the warning status of the CAN node.
 *
 * \param[in] node Specifies the pointer to CAN node registers.
 *
 * \retval IfxCan_CanNodeErrorWarningLimitStatus Warning status in CAN node. Range: \ref IfxCan_CanNodeErrorWarningLimitStatus.
 */
IFX_INLINE IfxCan_CanNodeErrorWarningLimitStatus IfxCan_Node_getWarningStatus(Ifx_CAN_N *node);

/** \brief Get the Bus Off status of the CAN node.
 *
 * \param[in] node Specifies the pointer to CAN node registers.
 *
 * \retval IfxCan_CanNodeBusOffErrorStatus Bus Off Error status in CAN node. Range: \ref IfxCan_CanNodeBusOffErrorStatus.
 */
IFX_INLINE IfxCan_CanNodeBusOffErrorStatus IfxCan_Node_getBusOffStatus(Ifx_CAN_N *node);

/** \brief Get the Activity status of the CAN node.
 *
 * \param[in] node Specifies the pointer to CAN node registers.
 *
 * \retval IfxCan_CanNodeCommunicationState Activity status of CAN node. Range: \ref IfxCan_CanNodeCommunicationState.
 */
IFX_INLINE IfxCan_CanNodeCommunicationState IfxCan_Node_getActivityStatus(Ifx_CAN_N *node);

/** \brief Get the Error status in data phase of the CAN node in the recent CANFD operation with bit rate switch.
 *
 * \param[in] node Specifies the pointer to CAN node registers.
 *
 * \retval IfxCan_LastErrorCodeType Error status of the recent CAN FD with BRS flag set. Range: \ref IfxCan_LastErrorCodeType.
 */
IFX_INLINE IfxCan_LastErrorCodeType IfxCan_Node_getDataPhaseLastErrorCode(Ifx_CAN_N *node);

/** \brief Protocol Exception Event status.
 * TRUE: Protocol Exception event occured.
 * FALSE: Protocol Exception event not occured.
 *
 * \param[in] node Specifies the pointer to CAN node registers.
 *
 * \retval Get the Protocol Exception event status (TRUE/FALSE).
 */
IFX_INLINE boolean IfxCan_Node_isProtocolExceptionEventOccured(Ifx_CAN_N *node);

/** \brief Returns the error status of the recent recieved CAN FD message.
 * TRUE : Error status indicator is enabled.
 * FALSE: Erro status indicator not enabled.
 *
 * \param[in] node Specifies the pointer to CAN node registers.
 *
 * \retval Error indicator for recent received CAN FD message (TRUE/FALSE).
 */
IFX_INLINE boolean IfxCan_Node_isErrorStatusIndicatorEnabled(Ifx_CAN_N *node);

/** \brief Return the DLC code corresponding to the data length in bytes.
 *
 * \param[in] dataLength Data length in bytes. Range: 0 to 64
 *
 * \retval IfxCan_DataLengthCode Data length code. Range: \ref IfxCan_DataLengthCode.
 */
IFX_INLINE IfxCan_DataLengthCode IfxCan_Node_getCodeFromDataLengthInBytes(uint32 dataLength);

/** \brief Returns the number of consecutively free Tx FIFO elements.
 *
 * \param[in] node Specifies the pointer to CAN node registers.
 *
 * \retval uint8 Number of consecutively free Tx FIFO elements - Range: 0 to 32.
 */
IFX_INLINE uint8 IfxCan_Node_getTxFifoFillLevel(Ifx_CAN_N *node);

/** \brief Sets the Extended Filter ID and mask.
 *
 * \param[inout] node              Specifies the pointer to CAN node registers.
 * \param[in]    extendedIdAndMask Extended Filter ID and mask. Range: 0 to 0x1FFFFFFF
 *
 * \retval None
 */
IFX_INLINE void IfxCan_Node_setExtendedIdAndMask(Ifx_CAN_N *node, uint32 extendedIdAndMask);

/** \brief Returns the 32-bit value of Node Interrupt Signaling register.
 *
 * \param[in] node Specifies the pointer to CAN node registers.
 *
 * \retval uint32 32-bit unsigned value of Node interrupt signaling register. Range: 0 to 0x0000FFFF
 */
IFX_INLINE uint32 IfxCan_Node_getInterruptSignallingStatus(Ifx_CAN_N *node);

/** \brief Returns the 32-bit value of Node Interrupt Signaling register.
 *
 * \param[in] node Specifies the pointer to CAN node registers.
 *
 * \retval uint8 Returns index m of TSU.TS[m] registers used to capture the timestamp. Range: 0 to 15.
 */
IFX_INLINE uint8 IfxCan_Node_getTsuTimeStampPointer(Ifx_CAN_N *node);

/** \brief Returns Actual Timebase for timestamp generation.
 *
 * \param[in] node Specifies the pointer to CAN node registers.
 *
 * \retval uint32 Returns Actual Timebase which will be used for timestamp generation. Range: 0 to 0xFFFFFFFF.
 */
IFX_INLINE uint32 IfxCan_Node_getTsuActualTimebase(Ifx_CAN_N *node);

/** \brief Sets Actual Timebase for Timestamp generation.
 *
 * \param[inout] node           Specifies the pointer to CAN node registers.
 * \param[in]    actualTimebase Timebase value for timestamp generation. Range: 0 to 0xFFFFFFFF.
 *
 * \retval None
 */
IFX_INLINE void IfxCan_Node_setTsuActualTimebase(Ifx_CAN_N *node, uint32 actualTimebase);

/******************************************************************************/
/*-------------------------Global Function Prototypes-------------------------*/
/******************************************************************************/

/** \brief Converts data length code (DLC) into number of words.
 *
 * \param[in] dataLengthCode DLC, Data Length Code. Range: \ref IfxCan_DataLengthCode.
 *
 * \retval uint32 Number of data words. Range: 0 to 64
 */
IFX_EXTERN uint32 IfxCan_Node_getDataLength(IfxCan_DataLengthCode dataLengthCode);

/** \brief Converts data length code (DLC) into number of data words.
 * This function is deprecated. Use new function IfxCan_Node_getDataLength.
 *
 * \param[in] node           Specifies the pointer to the CAN Node registers.
 * \param[in] dataLengthCode DLC, Data Length Code. Range: \ref IfxCan_DataLengthCode.
 *
 * \retval uint32 Number of data words. Range: 0 to 64
 */
IFX_EXTERN uint32 IfxCan_Node_getDataLengthFromCode(Ifx_CAN_N *node, IfxCan_DataLengthCode dataLengthCode);

/** \brief Returns CAN frame mode of operation for a received frame.
 *
 * \param[in] rxBufferElement Rx Buffer Element.
 *
 * \retval IfxCan_FrameMode CAN frame mode. Range: \ref IfxCan_FrameMode.
 */
IFX_EXTERN IfxCan_FrameMode IfxCan_Node_getFrameMode(Ifx_CAN_RXMSG *rxBufferElement);

/** \brief Select and initialise the CAN node receive pin.
 *
 * \param[inout] node      Specifies the pointer to the CAN Node registers.
 * \param[inout] rxd       Rx pin.
 * \param[in]    mode      Input mode. Range: \ref IfxPort_InputMode.
 * \param[in]    padDriver Pad Driver Configuration. Range: \ref IfxPort_PadDriver.
 *
 * \retval TRUE: Returns TRUE if the operation was successful\n.
 *         FALSE: Returns FALSE if the operation was fail.
 */
IFX_EXTERN boolean IfxCan_Node_initRxPin(Ifx_CAN_N *node, IfxCan_Rxd_In *rxd, IfxPort_InputMode mode, IfxPort_PadDriver padDriver);

/** \brief Select and initialise the CAN node transmit pin.
 *
 * \param[inout] txd       Tx pin.
 * \param[in]    mode      Output mode. Range: \ref IfxPort_OutputMode.
 * \param[in]    padDriver Pad driver Configuration. Range: \ref IfxPort_PadDriver.
 *
 * \retval TRUE: Returns TRUE if the operation was successful\n.
 *         FALSE: Returns FALSE if the operation was errorneous.
 */
IFX_EXTERN boolean IfxCan_Node_initTxPin(IfxCan_Txd_Out *txd, IfxPort_OutputMode mode, IfxPort_PadDriver padDriver);

/** \brief Calculates and Sets the CAN baudrate for standard frames and arbitration phase of CAND FD frames.
 *
 * \param[inout] node          Specifies the pointer to the CAN Node registers.
 * \param[in]    moduleFreq    Specifies the CAN module frequency. Range:10MHz to 50MHz
 * \param[in]    baudrate      Specifies the baud rate. Unit: baud. Range upto 1000000
 * \param[in]    samplePoint   Specifies the sample point. Range = 0 to 10000 resp. [0%, 100%] of the total bit time.
 * \param[in]    syncJumpWidth Specifies the re-synchronization jump width. Range: 0 to 127
 *
 * \retval None
 */
IFX_EXTERN void IfxCan_Node_setBitTiming(Ifx_CAN_N *node, uint32 moduleFreq, uint32 baudrate, uint16 samplePoint, uint16 syncJumpWidth);

/** \brief Sets the values of CAN baudrate for standard frames.
 *
 * \param[inout] node          Pointer to the CAN node registers.
 * \param[in]    syncJumpWidth Synchronization Jump Width. Range: 0 to 127
 * \param[in]    timeSegment2  Time segment after the sample point.  Range: 1 to 127 
 * \param[in]    timeSegment1  Time segment before the sample point. Range: 1 to 255
 * \param[in]    prescaler     Baud Rate Prescaler. Range: 0 to 511
 *
 * \retval None
 */
IFX_EXTERN void IfxCan_Node_setBitTimingValues(Ifx_CAN_N *node, uint16 syncJumpWidth, uint8 timeSegment2, uint8 timeSegment1, uint16 prescaler);

/** \brief Calculates and Sets the CAN fast baudrate for CAN FD frames data phase.
 *
 * \param[inout] node          Specifies the pointer to the CAN Node registers.
 * \param[in]    moduleFreq    Specifies the CAN module frequency. Range:10MHz to 50MHz
 * \param[in]    baudrate      Specifies the baud rate. Unit: baud. Range upto 8000000
 * \param[in]    samplePoint   Specifies the sample point. Range = 0 to 10000. resp. [0%, 100%] of the total bit time.
 * \param[in]    syncJumpWidth Specifies the re-synchronization jump width. Range: 0 to 15
 *
 * \retval None
 */
IFX_EXTERN void IfxCan_Node_setFastBitTiming(Ifx_CAN_N *node, uint32 moduleFreq, uint32 baudrate, uint16 samplePoint, uint16 syncJumpWidth);

/** \brief Sets the values of CAN fast baudrate for CAN FD frames data phase.
 *
 * \param[inout] node          Pointer to the CAN node registers.
 * \param[in]    syncJumpWidth Synchronization Jump Width. Range: 0 to 15
 * \param[in]    timeSegment2  Time segment after the sample point. Range: 0 to 15
 * \param[in]    timeSegment1  Time segment before the sample point. Range: 0 to 31
 * \param[in]    prescaler     Baud Rate Prescaler value. Range: 0 to 31
 *
 * \retval None
 */
IFX_EXTERN void IfxCan_Node_setFastBitTimingValues(Ifx_CAN_N *node, uint16 syncJumpWidth, uint8 timeSegment2, uint8 timeSegment1, uint16 prescaler);

/** \brief Enables the CAN frame mode for transmission.
 *
 * \param[inout] node      Specifies the pointer to the CAN Node registers.
 * \param[in]    frameMode CAN frame mode. Range: \ref IfxCan_FrameMode.
 *
 * \retval None
 */
IFX_EXTERN void IfxCan_Node_setFrameMode(Ifx_CAN_N *node, IfxCan_FrameMode frameMode);

/** \brief Sets CAN frame mode request for transmission.
 *
 * \param[inout] txBufferElement Tx Buffer Element.
 * \param[in]    frameMode       CAN frame mode. Range: \ref IfxCan_FrameMode.
 *
 * \retval None
 */
IFX_EXTERN void IfxCan_Node_setFrameModeReq(Ifx_CAN_TXMSG *txBufferElement, IfxCan_FrameMode frameMode);

/** \brief Converts data length code (DLC) into number of bytes.
 *
 * \param[in] dataLengthCode Data length code. Range: \ref IfxCan_DataLengthCode.
 *
 * \retval uint32 Data length in bytes. Range: 0 to 64.
 */
IFX_EXTERN uint32 IfxCan_Node_getDataLengthInBytes(IfxCan_DataLengthCode dataLengthCode);

/** \brief This API provides the nominal baudrate of CAN Classical, and FD frames.
 * Note: Configure baud rate before calling this API.
 *
 * \param[in] node Specifies the pointer to the CAN-XL Node registers.
 *
 * \retval uint32 Baud rate. Range: 0 to 0xFFFFFFFF
 */
IFX_EXTERN uint32 IfxCan_Node_getNominalBaudRate(Ifx_CAN_N *node);

/** \brief This API provides the data phase baud rate of CAN FD frames.
 * Note: API will return correct values only if FD baud rate is already configured.
 *
 * \param[in] node Specifies the pointer to the CAN-XL Node registers.
 *
 * \retval uint32 Baud rate.Range: 0 to 0xFFFFFFFF
 */
IFX_EXTERN uint32 IfxCan_Node_getFdBaudRate(Ifx_CAN_N *node);

/** \} */

/** \addtogroup IfxLld_Can_Std_Tx_Element_Functions
 * \{ */

/******************************************************************************/
/*-------------------------Inline Function Prototypes-------------------------*/
/******************************************************************************/

/** \brief Bit Rate Switch status of the last recieved CAN FD message.
 * TRUE: Bit rate switch is enabled.
 * FALSE: Bit rate switch is disabled.
 *
 * \param[in] node Specifies the pointer to CAN node registers.
 *
 * \retval Bit Rate Switch flag status (TRUE/FALSE).
 */
IFX_INLINE boolean IfxCan_Node_isBitRateSwitchFlagEnabled(Ifx_CAN_N *node);

/** \brief Returns Tx FIFO/Queue Put Index.
 *
 * \param[in] node Specifies the pointer to the CAN Node registers.
 *
 * \retval IfxCan_TxBufferId Tx Buffer Element Number. Range: \ref IfxCan_TxBufferId.
 */
IFX_INLINE IfxCan_TxBufferId IfxCan_Node_getTxFifoQueuePutIndex(Ifx_CAN_N *node);

/** \brief Returns the status of whether cancellation is finished on the selected Tx buffer.
 *
 * \param[in] node       Specifies the pointer to the CAN Node registers.
 * \param[in] txBufferId Tx Buffer number. Range: \ref IfxCan_TxBufferId.
 *
 * \retval Status.
 */
IFX_INLINE boolean IfxCan_Node_isTxBufferCancellationFinished(Ifx_CAN_N *node, IfxCan_TxBufferId txBufferId);

/** \brief Returns the status of pending request of the selected Tx buffer.
 *
 * \param[in] node       Specifies the pointer to the CAN Node registers.
 * \param[in] txBufferId Tx Buffer number. Range: \ref IfxCan_TxBufferId.
 *
 * \retval Status.
 */
IFX_INLINE boolean IfxCan_Node_isTxBufferRequestPending(Ifx_CAN_N *node, IfxCan_TxBufferId txBufferId);

/** \brief Returns the status of whether transmission occured on the selected Tx buffer.
 *
 * \param[in] node       Specifies the pointer to the CAN Node registers.
 * \param[in] txBufferId Tx Buffer number. Range: \ref IfxCan_TxBufferId.
 *
 * \retval Status.
 */
IFX_INLINE boolean IfxCan_Node_isTxBufferTransmissionOccured(Ifx_CAN_N *node, IfxCan_TxBufferId txBufferId);

/** \brief Returns the status of Tx Fifo/Queue is full or not.
 *
 * \param[in] node Specifies the pointer to the CAN Node registers.
 *
 * \retval Status.
 */
IFX_INLINE boolean IfxCan_Node_isTxFifoQueueFull(Ifx_CAN_N *node);

/** \brief pauses the CAN Node for two CAN bit times before starting the next transmission.
 *
 * \param[inout] node   Specifies the pointer to the CAN Node registers.
 * \param[in]    enable Enable / Disable choice.
 *
 * \retval None
 */
IFX_INLINE void IfxCan_Node_pauseTransmission(Ifx_CAN_N *node, boolean enable);

/** \brief Sets the Data Length Code (DLC) for transmit frame.
 *
 * \param[inout] txBufferElement Tx Buffer Element.
 * \param[in]    dataLengthCode  DLC, data length code. Range: \ref IfxCan_DataLengthCode.
 *
 * \retval None
 */
IFX_INLINE void IfxCan_Node_setDataLength(Ifx_CAN_TXMSG *txBufferElement, IfxCan_DataLengthCode dataLengthCode);

/** \brief Sets the Data Length Code (DLC) for transmit frame.
 * This function is deprecated. Use new function IfxCan_Node_setDataLength.
 *
 * \param[in]    node            Specifies the pointer to the CAN Node registers.
 * \param[inout] txBufferElement Tx Buffer Element.
 * \param[in]    dataLengthCode  DLC, data length code. Range: \ref IfxCan_DataLengthCode.
 *
 * \retval None
 */
IFX_INLINE void IfxCan_Node_setDataLengthCode(Ifx_CAN_N *node, Ifx_CAN_TXMSG *txBufferElement, IfxCan_DataLengthCode dataLengthCode);

/** \brief Sets the number of dedicated Tx Buffers.
 *
 * \param[inout] node   Specifies the pointer to the CAN Node registers.
 * \param[in]    number Number of Tx Buffers. Range: 0 to 32
 *
 * \retval None
 */
IFX_INLINE void IfxCan_Node_setDedicatedTxBuffersNumber(Ifx_CAN_N *node, uint8 number);

/** \brief Sets the Error State Indicator (ESI) for transmit frame.
 *
 * \param[inout] txBufferElement Tx Buffer Element.
 * \param[in]    enable          Choice (True/ False).
 *
 * \retval None
 */
IFX_INLINE void IfxCan_Node_setErrStateIndicator(Ifx_CAN_TXMSG *txBufferElement, boolean enable);

/** \brief Sets the Error State Indicator (ESI) for transmit frame.
 * This function is decprecated. Use new function IfxCan_Node_setErrStateIndicator.
 *
 * \param[in]    node            Specifies the pointer to the CAN Node registers.
 * \param[inout] txBufferElement Tx Buffer Element.
 * \param[in]    enable          Choice (True/ False).
 *
 * \retval None
 */
IFX_INLINE void IfxCan_Node_setErrorStateIndicator(Ifx_CAN_N *node, Ifx_CAN_TXMSG *txBufferElement, boolean enable);

/** \brief Sets the Message Marker (MM) for transmit frame.
 *
 * \param[inout] txBufferElement Tx Buffer Element.
 * \param[in]    bufferId        MM, Message Marker , Buffer Id. Range: \ref IfxCan_TxBufferId.
 *
 * \retval None
 */
IFX_INLINE void IfxCan_Node_setMessageMarker(Ifx_CAN_TXMSG *txBufferElement, IfxCan_TxBufferId bufferId);

/** \brief Sets the identifier (ID) for transmit frame.
 *
 * \param[inout] txBufferElement Tx Buffer Element.
 * \param[in]    messageId       Identifier. Range: 0x000 to 0x7FF (Standard); 0 to 0x1FFFFFFF (Extended)
 * \param[in]    messageIdLength Message Id length (Standard / Extended). Range: \ref IfxCan_MessageIdLength.
 *
 * \retval None
 */
IFX_INLINE void IfxCan_Node_setMsgId(Ifx_CAN_TXMSG *txBufferElement, uint32 messageId, IfxCan_MessageIdLength messageIdLength);

/** \brief Sets the identifier (ID) for transmit frame.
 * This function is deprecated. Use the new function IfxCan_Node_setMsgId.
 *
 * \param[in]    node            Specifies the pointer to the CAN Node registers.
 * \param[inout] txBufferElement Tx Buffer Element.
 * \param[in]    messageId       Identifier. Range: 0x000 to 0x7FF (Standard); 0 to 0x1FFFFFFF (Extended)
 * \param[in]    messageIdLength Message Id length (Standard / Extended). Range: \ref IfxCan_MessageIdLength.
 *
 * \retval None
 */
IFX_INLINE void IfxCan_Node_setMesssageId(Ifx_CAN_N *node, Ifx_CAN_TXMSG *txBufferElement, uint32 messageId, IfxCan_MessageIdLength messageIdLength);

/** \brief Sets the remote Transmit Request (RTR) for transmit frame.
 *
 * \param[inout] txBufferElement Tx Buffer Element.
 * \param[in]    enable          Choice (True/ False).
 *
 * \retval None
 */
IFX_INLINE void IfxCan_Node_setRemoteTransmitReq(Ifx_CAN_TXMSG *txBufferElement, boolean enable);

/** \brief Sets the remote Transmit Request (RTR) for transmit frame.
 * This function is deprecated. Use new function IfxCan_Node_setRemoteTransmitReq.
 *
 * \param[in]    node            Specifies the pointer to the CAN Node registers.
 * \param[inout] txBufferElement Tx Buffer Element.
 * \param[in]    enable          Choice (True/ False).
 *
 * \retval None
 */
IFX_INLINE void IfxCan_Node_setRemoteTransmitRequest(Ifx_CAN_N *node, Ifx_CAN_TXMSG *txBufferElement, boolean enable);

/** \brief Sets Transmit FIFO/Queue Mode.
 *
 * \param[inout] node Specifies the pointer to the CAN Node registers.
 * \param[in]    mode Tx FIFO/Queue Mode. Range: \ref IfxCan_TxMode.
 *
 * \retval None
 */
IFX_INLINE void IfxCan_Node_setTransmitFifoQueueMode(Ifx_CAN_N *node, IfxCan_TxMode mode);

/** \brief Sets Transmit FIFO/Queue Size.
 *
 * \param[inout] node   Specifies the pointer to the CAN Node registers.
 * \param[in]    number Number of Tx Buffers used for Tx FIFO/Queue. Range: 0 to 32
 *
 * \retval None
 */
IFX_INLINE void IfxCan_Node_setTransmitFifoQueueSize(Ifx_CAN_N *node, uint8 number);

/** \brief Sets the Add Request for the selected Tx buffer.
 *
 * \param[inout] node       Specifies the pointer to the CAN Node registers.
 * \param[in]    txBufferId Tx Buffer number. Range: \ref IfxCan_TxBufferId.
 *
 * \retval None
 */
IFX_INLINE void IfxCan_Node_setTxBufferAddRequest(Ifx_CAN_N *node, IfxCan_TxBufferId txBufferId);

/** \brief Sets the Cancellation Request for the selected Tx buffer.
 *
 * \param[inout] node       Specifies the pointer to the CAN Node registers.
 * \param[in]    txBufferId Tx Buffer number. Range: \ref IfxCan_TxBufferId.
 *
 * \retval None
 */
IFX_INLINE void IfxCan_Node_setTxBufferCancellationRequest(Ifx_CAN_N *node, IfxCan_TxBufferId txBufferId);

/** \brief Sets Tx Buffer Data Field Size.
 *
 * \param[inout] node Specifies the pointer to the CAN Node registers.
 * \param[in]    size Tx Buffer Data Field Size. Range: \ref IfxCan_DataFieldSize.
 *
 * \retval None
 */
IFX_INLINE void IfxCan_Node_setTxBufferDataFieldSize(Ifx_CAN_N *node, IfxCan_DataFieldSize size);

/** \brief Sets the start address of Tx Buffers section in the Message RAM.
 *
 * \param[inout] node    Specifies the pointer to the CAN Node registers.
 * \param[in]    address Start address of Tx Buffers in the message RAM (must be 32-bit word aligned). Range: 0x0000 to 0x3FFF
 *
 * \retval None
 */
IFX_INLINE void IfxCan_Node_setTxBuffersStartAddress(Ifx_CAN_N *node, uint16 address);

/** \brief Sets the Tx Event Fifo Control (EFC) for transmit frame.
 * This function is deprecated. Use new function IfxCan_Node_setTxEventFifoCtrl.
 *
 * \param[in]    node            Specifies the pointer to the CAN Node registers.
 * \param[inout] txBufferElement Tx Buffer Element.
 * \param[in]    enable          Choice (True/ False).
 *
 * \retval None
 */
IFX_INLINE void IfxCan_Node_setTxEventFifoControl(Ifx_CAN_N *node, Ifx_CAN_TXMSG *txBufferElement, boolean enable);

/** \brief Sets Tx Event FIFO Acknowledge Index for given node.
 *
 * \param[inout] node               Specifies the pointer to the CAN Node registers.
 * \param[in]   TxEventBufferNumber Tx event buffer element number. Range: \ref IfxCan_TxBufferId.
 *
 * \retval None
 */
IFX_INLINE void IfxCan_Node_setTxEventFifoAcknowledgeIndex(Ifx_CAN_N *node, IfxCan_TxBufferId TxEventBufferNumber);

/******************************************************************************/
/*-------------------------Global Function Prototypes-------------------------*/
/******************************************************************************/

/** \brief Returns Tx Buffer Data Field Size in bytes.
 *
 * \param[in] node Specifies the pointer to the CAN Node registers.
 *
 * \retval uint8 Data field size. Range: 0 to 64
 */
IFX_EXTERN uint8 IfxCan_Node_getTxBufferDataFieldSize(Ifx_CAN_N *node);

/** \brief Returns the address of selected Tx buffer element.
 *
 * \param[in] node                  Pointer to the CAN node registers.
 * \param[in] ramBaseAddress        Message RAM base address of the CAN module. Range: 0xF0200000 to 0xF0223FFF
 * \param[in] txBuffersStartAddress Start address of the Tx Buffers section in the Message RAM. Range: 0x0000 to 0x3FFF
 * \param[in] txBufferNumber        Tx buffer element number. Range: \ref IfxCan_TxBufferId.
 *
 * \retval Ifx_CAN_TXMSG* Tx Buffer Element Address.
 */
IFX_EXTERN Ifx_CAN_TXMSG *IfxCan_Node_getTxBufferElementAddress(Ifx_CAN_N *node, uint32 ramBaseAddress, uint16 txBuffersStartAddress, IfxCan_TxBufferId txBufferNumber);

/** \brief Writes Data into Tx buffer element Node_writeTxBufData.
 *
 * \param[inout] txBufferElement Tx Buffer Element.
 * \param[in]    dataLengthCode  DLC, Data Length Code. Range: \ref IfxCan_DataLengthCode.
 * \param[in]    data            Pointer to data (in words).
 *
 * \retval None
 */
IFX_EXTERN void IfxCan_Node_writeTxBufData(Ifx_CAN_TXMSG *txBufferElement, IfxCan_DataLengthCode dataLengthCode, uint32 *data);

/** \brief Writes Data into Tx buffer element.
 * This function is deprecated. Use new function IfxCan_Node_writeTxBufData.
 *
 * \param[in]    node            Specifies the pointer to the CAN Node registers.
 * \param[inout] txBufferElement Tx Buffer Element.
 * \param[in]    dataLengthCode  DLC, Data Length Code. Range: \ref IfxCan_DataLengthCode.
 * \param[in]    data            Pointer to data (in words).
 *
 * \retval None
 */
IFX_EXTERN void IfxCan_Node_writeData(Ifx_CAN_N *node, Ifx_CAN_TXMSG *txBufferElement, IfxCan_DataLengthCode dataLengthCode, uint32 *data);

/** \} */

/** \addtogroup IfxLld_Can_Std_Rx_Element_Functions
 * \{ */

/******************************************************************************/
/*-------------------------Inline Function Prototypes-------------------------*/
/******************************************************************************/

/** \brief Returns the Data Length Code from the received frame.
 *
 * \param[in] rxBufferElement Rx Buffer Element.
 *
 * \retval uint32 Data Length Code. Range 0 to 15
 */
IFX_INLINE uint32 IfxCan_Node_getDataLengthCode(Ifx_CAN_RXMSG *rxBufferElement);

/** \brief Returns the identifier (ID) from the received frame.
 *
 * \param[in] rxBufferElement Rx Buffer Element.
 *
 * \retval uint32 Identifier. Range: 0x000 to 0x7FF (Standard); 0 to 0x1FFFFFFF (Extended)
 */
IFX_INLINE uint32 IfxCan_Node_getMesssageId(Ifx_CAN_RXMSG *rxBufferElement);

/** \brief Returns Rx FIFO 0 Fill Level.
 *
 * \param[in] node Specifies the pointer to the CAN Node registers.
 *
 * \retval uint8 Fill level. Range 0 to 64
 */
IFX_INLINE uint8 IfxCan_Node_getRxFifo0FillLevel(Ifx_CAN_N *node);

/** \brief Returns Rx FIFO 0 get index.
 *
 * \param[in] node Specifies the pointer to the CAN Node registers.
 *
 * \retval IfxCan_RxBufferId Rx Buffer Element Number. Range: \ref IfxCan_RxBufferId.
 */
IFX_INLINE IfxCan_RxBufferId IfxCan_Node_getRxFifo0GetIndex(Ifx_CAN_N *node);

/** \brief Returns Rx FIFO 1 Fill Level.
 *
 * \param[in] node Specifies the pointer to the CAN Node registers.
 *
 * \retval uint8 Fill level. Range 0 to 64
 */
IFX_INLINE uint8 IfxCan_Node_getRxFifo1FillLevel(Ifx_CAN_N *node);

/** \brief Returns Rx FIFO 1 get index.
 *
 * \param[in] node Specifies the pointer to the CAN Node registers.
 *
 * \retval IfxCan_RxBufferId Rx Buffer Element Number. Range: \ref IfxCan_RxBufferId.
 */
IFX_INLINE IfxCan_RxBufferId IfxCan_Node_getRxFifo1GetIndex(Ifx_CAN_N *node);

/** \brief Sets Rx Buffer Data Field Size.
 *
 * \param[inout] node Specifies the pointer to the CAN Node registers.
 * \param[in]    size Rx Buffer Data Field Size. Range: \ref IfxCan_DataFieldSize.
 *
 * \retval None
 */
IFX_INLINE void IfxCan_Node_setRxBufferDataFieldSize(Ifx_CAN_N *node, IfxCan_DataFieldSize size);

/** \brief Sets the start address of Rx Buffers section in the Message RAM.
 *
 * \param[inout] node    Specifies the pointer to the CAN Node registers.
 * \param[in]    address Start address of Rx Buffers in the Message RAM (must be 32-bit word aligned). Range: 0x0000 to 0x3FFF
 *
 * \retval None
 */
IFX_INLINE void IfxCan_Node_setRxBuffersStartAddress(Ifx_CAN_N *node, uint16 address);

/** \brief Sets Rx FIFO 0 Acknowledge Index.
 *
 * \param[inout] node           Specifies the pointer to the CAN Node registers.
 * \param[in]    RxBufferNumber Rx buffer element number. Range: \ref IfxCan_RxBufferId.
 *
 * \retval None
 */
IFX_INLINE void IfxCan_Node_setRxFifo0AcknowledgeIndex(Ifx_CAN_N *node, IfxCan_RxBufferId RxBufferNumber);

/** \brief Sets Rx Buffer Fifo 0 Data Field Size.
 *
 * \param[inout] node Specifies the pointer to the CAN Node registers.
 * \param[in]    size Rx FIFO 0 Data Field Size. Range: \ref IfxCan_DataFieldSize.
 *
 * \retval None
 */
IFX_INLINE void IfxCan_Node_setRxFifo0DataFieldSize(Ifx_CAN_N *node, IfxCan_DataFieldSize size);

/** \brief Sets Rx Buffer Fifo 0 operating mode.
 *
 * \param[inout] node Specifies the pointer to the CAN Node registers.
 * \param[in]    mode Rx FIFO 0 operating Mode. Range: \ref IfxCan_RxFifoMode.
 *
 * \retval None
 */
IFX_INLINE void IfxCan_Node_setRxFifo0OperatingMode(Ifx_CAN_N *node, IfxCan_RxFifoMode mode);

/** \brief Sets Rx FIFO 0 Size.
 *
 * \param[inout] node Specifies the pointer to the CAN Node registers.
 * \param[in]    size Rx FIFO 0 Size. Range: 0 to 64
 *
 * \retval None
 */
IFX_INLINE void IfxCan_Node_setRxFifo0Size(Ifx_CAN_N *node, uint8 size);

/** \brief Sets the start address of Rx FIFO 0 section in the Message RAM.
 *
 * \param[inout] node    Specifies the pointer to the CAN Node registers.
 * \param[in]    address Start address of Rx FIFO 0 in the Message RAM (must be 32-bit word aligned). Range: 0x0000 to 0x3FFF
 *
 * \retval None
 */
IFX_INLINE void IfxCan_Node_setRxFifo0StartAddress(Ifx_CAN_N *node, uint16 address);

/** \brief Sets Rx FIFO 0 Watermark Level.
 *
 * \param[inout] node  Specifies the pointer to the CAN Node registers.
 * \param[in]    level Rx FIFO 0 Watermark Level. Range: 1 to 64 (For ranges 0, 65 to 127, Watermark interrupt disabled).
 *
 * \retval None
 */
IFX_INLINE void IfxCan_Node_setRxFifo0WatermarkLevel(Ifx_CAN_N *node, uint8 level);

/** \brief Sets Rx FIFO 1 Acknowledge Index.
 *
 * \param[inout] node           Specifies the pointer to the CAN Node registers.
 * \param[in]    RxBufferNumber Rx buffer element number. Range: \ref IfxCan_RxBufferId.
 *
 * \retval None
 */
IFX_INLINE void IfxCan_Node_setRxFifo1AcknowledgeIndex(Ifx_CAN_N *node, IfxCan_RxBufferId RxBufferNumber);

/** \brief Sets Rx Buffer Fifo 1 Data Field Size.
 *
 * \param[inout] node Specifies the pointer to the CAN Node registers.
 * \param[in]    size Rx FIFO 1 Data Field Size. Range: \ref IfxCan_DataFieldSize.
 *
 * \retval None
 */
IFX_INLINE void IfxCan_Node_setRxFifo1DataFieldSize(Ifx_CAN_N *node, IfxCan_DataFieldSize size);

/** \brief Sets Rx Buffer Fifo 1 operating mode.
 *
 * \param[inout] node Specifies the pointer to the CAN Node registers.
 * \param[in]    mode Rx FIFO 1 operating Mode. Range: \ref IfxCan_RxFifoMode.
 *
 * \retval None
 */
IFX_INLINE void IfxCan_Node_setRxFifo1OperatingMode(Ifx_CAN_N *node, IfxCan_RxFifoMode mode);

/** \brief Sets Rx FIFO 1 Size.
 *
 * \param[inout] node Specifies the pointer to the CAN Node registers.
 * \param[in]    size Rx FIFO 1 Size. Range 0 to 64
 *
 * \retval None
 */
IFX_INLINE void IfxCan_Node_setRxFifo1Size(Ifx_CAN_N *node, uint8 size);

/** \brief Sets the start address of Rx FIFO 1 section in the Message RAM.
 *
 * \param[inout] node    Specifies the pointer to the CAN Node registers.
 * \param[in]    address Start address of Rx FIFO 1 in the Message RAM (must be 32-bit word aligned). Range: 0x0000 to 0x3FFF
 *
 * \retval None
 */
IFX_INLINE void IfxCan_Node_setRxFifo1StartAddress(Ifx_CAN_N *node, uint16 address);

/** \brief Sets Rx FIFO 1 Watermark Level.
 *
 * \param[inout] node Specifies the pointer to the CAN Node registers.
 * \param[in]    level Rx FIFO 1 Watermark Level. Range: 1 to 64 (For ranges 0, 65 to 127, Watermark interrupt disabled).
 *
 * \retval None
 */
IFX_INLINE void IfxCan_Node_setRxFifo1WatermarkLevel(Ifx_CAN_N *node, uint8 level);

/******************************************************************************/
/*-------------------------Global Function Prototypes-------------------------*/
/******************************************************************************/

/** \brief Clears the New Data flag of the selected Rx buffer.
 *
 * \param[inout] node       Specifies the pointer to the CAN Node registers.
 * \param[in]    rxBufferId Rx Buffer number. Range: \ref IfxCan_RxBufferId.
 *
 * \retval None
 */
IFX_EXTERN void IfxCan_Node_clearRxBufferNewDataFlag(Ifx_CAN_N *node, IfxCan_RxBufferId rxBufferId);

/** \brief Returns Rx Buffer Data Field Size in bytes.
 *
 * \param[in] node Specifies the pointer to the CAN Node registers.
 *
 * \retval uint8 Data field size. Range: 8 to 64
 */
IFX_EXTERN uint8 IfxCan_Node_getRxBufferDataFieldSize(Ifx_CAN_N *node);

/** \brief Returns the address of selected Rx buffer element.
 *
 * \param[in] node                  Specifies the pointer to the CAN Node registers.
 * \param[in] ramBaseAddress        Message RAM base address of CAN Module. Range: 0xF0200000 to 0xF0223FFF
 * \param[in] rxBuffersStartAddress Start address of Rx Buffers section in the Message RAM. Range: 0x0000 to 0x3FFF
 * \param[in] rxBufferNumber        Rx buffer element number. Range: \ref IfxCan_RxBufferId
 *
 * \retval Ifx_CAN_RXMSG* Rx Buffer Element Address.
 */
IFX_EXTERN Ifx_CAN_RXMSG *IfxCan_Node_getRxBufferElementAddress(Ifx_CAN_N *node, uint32 ramBaseAddress, uint16 rxBuffersStartAddress, IfxCan_RxBufferId rxBufferNumber);

/** \brief Returns Rx FIFO 0 Data Field Size in bytes.
 *
 * \param[in] node Specifies the pointer to the CAN Node registers.
 *
 * \retval uint8 Data field size. Range: 8 to 64
 */
IFX_EXTERN uint8 IfxCan_Node_getRxFifo0DataFieldSize(Ifx_CAN_N *node);

/** \brief Returns the address of selected Rx FIFO 0 element.
 *
 * \param[in] node                Specifies the pointer to the CAN Node registers.
 * \param[in] ramBaseAddress      Message RAM base address of the CAN Module. Range: 0xF0200000 to 0xF0223FFF
 * \param[in] rxFifo0StartAddress Start address of Rx FIFO 0 section in the Message RAM. Range: 0x0000 to 0x3FFF
 * \param[in] rxBufferNumber      Rx buffer element number. Range: \ref IfxCan_RxBufferId
 *
 * \retval Ifx_CAN_RXMSG* Rx FIFO 0 Element Address.
 */
IFX_EXTERN Ifx_CAN_RXMSG *IfxCan_Node_getRxFifo0ElementAddress(Ifx_CAN_N *node, uint32 ramBaseAddress, uint16 rxFifo0StartAddress, IfxCan_RxBufferId rxBufferNumber);

/** \brief Returns Rx FIFO 1 Data Field Size in bytes.
 *
 * \param[in] node Specifies the pointer to the CAN Node registers.
 *
 * \retval uint8 The size of the data field in the receive FIFO 1. Range 8 to 64
 */
IFX_EXTERN uint8 IfxCan_Node_getRxFifo1DataFieldSize(Ifx_CAN_N *node);

/** \brief Returns the address of selected Rx FIFO 1 element.
 *
 * \param[in] node                Specifies the pointer to the CAN Node registers.
 * \param[in] ramBaseAddress      Message RAM base address of the CAN Module. Range: 0xF0200000 to 0xF0223FFF
 * \param[in] rxFifo1StartAddress Start address of Rx FIFO 1 section in the Message RAM. Range: 0x0000 to 0x3FFF
 * \param[in] rxBufferNumber      Rx buffer element number. Range: \ref IfxCan_RxBufferId
 *
 * \retval Ifx_CAN_RXMSG* Rx FIFO 1 Element Address.
 */
IFX_EXTERN Ifx_CAN_RXMSG *IfxCan_Node_getRxFifo1ElementAddress(Ifx_CAN_N *node, uint32 ramBaseAddress, uint16 rxFifo1StartAddress, IfxCan_RxBufferId rxBufferNumber);

/** \brief Returns the status of whether the selcted Rx buffer has been updated from new data.
 *
 * \param[in] node       Specifies the pointer to the CAN Node registers.
 * \param[in] rxBufferId Rx Buffer number. Range: \ref IfxCan_RxBufferId.
 *
 * \retval TRUE If new data is available in the specified Rx buffer.
 *         FALSE If no new data is available in the specified Rx buffer.
 */
IFX_EXTERN boolean IfxCan_Node_isRxBufferNewDataUpdated(Ifx_CAN_N *node, IfxCan_RxBufferId rxBufferId);

/** \brief Reads data from Rx buffer element.
 *
 * \param[in]    rxBufferElement Rx Buffer Element.
 * \param[in]    dataLengthCode  DLC, Data Length Code. Range: \ref IfxCan_DataLengthCode.
 * \param[inout] data            Pointer to data (in words).
 *
 * \retval None
 */
IFX_EXTERN void IfxCan_Node_readData(Ifx_CAN_RXMSG *rxBufferElement, IfxCan_DataLengthCode dataLengthCode, uint32 *data);

/** \} */

/** \addtogroup IfxLld_Can_Std_Filter_Functions
 * \{ */

/******************************************************************************/
/*-------------------------Inline Function Prototypes-------------------------*/
/******************************************************************************/

/** \brief Disables the selected interrupt.
 *
 * \param[inout] node Specifies the pointer to the CAN Node registers.
 *
 * \retval None
 */
IFX_INLINE void IfxCan_Node_acceptRemoteFramesWithStandardId(Ifx_CAN_N *node);

/** \brief Disables the selected interrupt.
 *
 * \param[inout] node Specifies the pointer to the CAN Node registers.
 *
 * \retval None
 */
IFX_INLINE void IfxCan_Node_acceptRemoteFrameswithExtendedId(Ifx_CAN_N *node);

/** \brief Configure the filter for non matching frames with extended id.
 *
 * \param[inout] node   Specifies the pointer to the CAN Node registers.
 * \param[in]    filter Action to be performed on non matching messages. Range: \ref IfxCan_NonMatchingFrame.
 *
 * \retval None
 */
IFX_INLINE void IfxCan_Node_configureExtendedFilterForNonMatchingFrames(Ifx_CAN_N *node, IfxCan_NonMatchingFrame filter);

/** \brief Configure the filter for non matching frames with standard id.
 *
 * \param[inout] node   Specifies the pointer to the CAN Node registers.
 * \param[in]    filter Action to be performed on non matching messages. Range: \ref IfxCan_NonMatchingFrame.
 *
 * \retval None
 */
IFX_INLINE void IfxCan_Node_configureStandardFilterForNonMatchingFrames(Ifx_CAN_N *node, IfxCan_NonMatchingFrame filter);

/** \brief Reject the remote frames with extended id.
 *
 * \param[inout] node Specifies the pointer to the CAN Node registers.
 *
 * \retval None
 */
IFX_INLINE void IfxCan_Node_rejectRemoteFramesWithExtendedId(Ifx_CAN_N *node);

/** \brief Reject the remote frames with standard id.
 *
 * \param[inout] node Specifies the pointer to the CAN Node registers.
 *
 * \retval None
 */
IFX_INLINE void IfxCan_Node_rejectRemoteFramesWithStandardId(Ifx_CAN_N *node);

/** \brief Sets the Extended Filter Element Configuration.
 *
 * \param[inout] extendedFilterElement      Extended Filter Element.
 * \param[in]    filterElementConfiguration Filter Element Configuration. Range: \ref IfxCan_FilterElementConfiguration.
 *
 * \retval None
 */
IFX_INLINE void IfxCan_Node_setExtendedFilterConfiguration(Ifx_CAN_EXTMSG *extendedFilterElement, IfxCan_FilterElementConfiguration filterElementConfiguration);

/** \brief Sets the Extended Filter ID 1 for Extended Filter Element.
 *
 * \param[inout] extendedFilterElement Extended Filter Element.
 * \param[in]    id                    Filter ID 1. Range: 0x00000000 to 0x1FFFFFFF
 *
 * \retval None
 */
IFX_INLINE void IfxCan_Node_setExtendedFilterId1(Ifx_CAN_EXTMSG *extendedFilterElement, uint32 id);

/** \brief Sets the Extended Filter ID 2 for Extended Filter Element.
 *
 * \param[inout] extendedFilterElement Extended Filter Element.
 * \param[in]    id                    Filter ID 2. Range: 0x00000000 to 0x1FFFFFFF
 *
 * \retval None
 */
IFX_INLINE void IfxCan_Node_setExtendedFilterId2(Ifx_CAN_EXTMSG *extendedFilterElement, uint32 id);

/** \brief Sets the Extended Message ID filter list size.
 *
 * \param[inout] node Specifies the pointer to the CAN Node registers.
 * \param[in]    size Number of Extended Message ID filter elements. Range: 0 to 64
 *
 * \retval None
 */
IFX_INLINE void IfxCan_Node_setExtendedFilterListSize(Ifx_CAN_N *node, uint8 size);

/** \brief Sets the start address of Extended Message ID filter list.
 *
 * \param[inout] node    Specifies the pointer to the CAN Node registers.
 * \param[in]    address Start address of Extended Message ID filter list in the Message RAM (must be 32-bit word aligned). Range: 0x0000 to 0x3FFF
 *
 * \retval None
 */
IFX_INLINE void IfxCan_Node_setExtendedFilterListStartAddress(Ifx_CAN_N *node, uint16 address);

/** \brief Sets the Offset to the Rx Buffer Start Address RXBC.RBSA for storage of a matching message for Extended filter element.
 *
 * \param[inout] extendedFilterElement Extended Filter Element.
 * \param[in]    rxBufferNumber        Offset to the Rx Buffer Start Address RXBC.RBSA for storage of a matching message (Rx buffer number). Range: \ref IfxCan_RxBufferId.
 *
 * \retval None
 */
IFX_INLINE void IfxCan_Node_setExtendedFilterRxBufferOffset(Ifx_CAN_EXTMSG *extendedFilterElement, IfxCan_RxBufferId rxBufferNumber);

/** \brief Sets the Extended Filter Type for Extended Filter Element.
 *
 * \param[inout] extendedFilterElement Extended Filter Element.
 * \param[in]    filterType            Filter Type. Range: \ref IfxCan_XtdFilterType.
 *
 * \retval None
 */
IFX_INLINE void IfxCan_Node_setExtendedFilterType(Ifx_CAN_EXTMSG *extendedFilterElement, IfxCan_XtdFilterType filterType);

/** \brief Sets the Standard Filter Element Configuration.
 *
 * \param[inout] standardFilterElement      Standard Filter Element.
 * \param[in]    filterElementConfiguration Filter Element Configuration. Range: \ref IfxCan_FilterElementConfiguration.
 *
 * \retval None
 */
IFX_INLINE void IfxCan_Node_setStandardFilterConfiguration(Ifx_CAN_STDMSG *standardFilterElement, IfxCan_FilterElementConfiguration filterElementConfiguration);

/** \brief Sets the Standard Filter ID 1 for Standard Filter Element.
 *
 * \param[inout] standardFilterElement Standard Filter Element.
 * \param[in]    id                    Filter ID 1. Range: 0 to 0x7FF
 *
 * \retval None
 */
IFX_INLINE void IfxCan_Node_setStandardFilterId1(Ifx_CAN_STDMSG *standardFilterElement, uint32 id);

/** \brief Sets the Standard Filter ID 2 for Standard Filter Element.
 *
 * \param[inout] standardFilterElement Standard Filter Element.
 * \param[in]    id                    Filter ID 2. Range: 0 to 0x7FF
 *
 * \retval None
 */
IFX_INLINE void IfxCan_Node_setStandardFilterId2(Ifx_CAN_STDMSG *standardFilterElement, uint32 id);

/** \brief Sets the Standard  Message ID filter list size.
 *
 * \param[inout] node Specifies the pointer to the CAN Node registers.
 * \param[in]    size Number of Standard Message ID filter elements. Range: 0 to 128 
 *
 * \retval None
 */
IFX_INLINE void IfxCan_Node_setStandardFilterListSize(Ifx_CAN_N *node, uint8 size);

/** \brief Sets the start address of Standard Message ID filter list.
 *
 * \param[inout] node    Specifies the pointer to the CAN Node registers.
 * \param[in]    address Start address of Standard Message ID filter in the Message RAM (must be 32-bit word aligned). Range: 0x0000 to 0x3FFF
 *
 * \retval None
 */
IFX_INLINE void IfxCan_Node_setStandardFilterListStartAddress(Ifx_CAN_N *node, uint16 address);

/** \brief Sets the Offset to the Rx Buffer Start Address RXBC.RBSA for storage of a matching message for standard filter element.
 *
 * \param[inout] standardFilterElement Standard Filter Element.
 * \param[in]    rxBufferNumber        Offset to the Rx Buffer Start Address RXBC.RBSA for storage of a matching message (Rx buffer number). Range: \ref IfxCan_RxBufferId.
 *
 * \retval None
 */
IFX_INLINE void IfxCan_Node_setStandardFilterRxBufferOffset(Ifx_CAN_STDMSG *standardFilterElement, IfxCan_RxBufferId rxBufferNumber);

/** \brief Sets the Standard Filter Type for Standard Filter Element.
 *
 * \param[inout] standardFilterElement Standard Filter Element.
 * \param[in]    filterType            Filter Type. Range: \ref IfxCan_StdFilterType.
 *
 * \retval None
 */
IFX_INLINE void IfxCan_Node_setStandardFilterType(Ifx_CAN_STDMSG *standardFilterElement, IfxCan_StdFilterType filterType);

/******************************************************************************/
/*-------------------------Global Function Prototypes-------------------------*/
/******************************************************************************/

/** \brief Returns the address of selected extended filter element.
 *
 * \param[in] ramBaseAddress                 The base address of the Message RAM for the CAN module. Range: 0xF0200000 to 0xF0223FFF
 * \param[in] extendedFilterListStartAddress The start address of the Extended Message ID filter list (32-bit word address). Range: 0x0000 to 0x3FFF
 * \param[in] filterNumber                   Extended filter element number. Range: 0 to 63
 *
 * \retval Ifx_CAN_EXTMSG* Extended Filter Element Address.
 */
IFX_EXTERN Ifx_CAN_EXTMSG *IfxCan_Node_getExtendedFilterElementAddress(uint32 ramBaseAddress, uint16 extendedFilterListStartAddress, uint8 filterNumber);

/** \brief Returns the address of selected standard filter element.
 *
 * \param[in] ramBaseAddress                 The base address of the message RAM of the CAN module. Range: 0xF0200000 to 0xF0223FFF
 * \param[in] standardFilterListStartAddress The start address of the standard message ID filter list. Range: 0x0000 to 0x3FFF
 * \param[in] filterNumber                   Standard filter element number. Range: 0 to 127
 *
 * \retval Ifx_CAN_STDMSG* Standard Filter Element Address.
 */
IFX_EXTERN Ifx_CAN_STDMSG *IfxCan_Node_getStandardFilterElementAddress(uint32 ramBaseAddress, uint16 standardFilterListStartAddress, uint8 filterNumber);

/** \} */

/** \addtogroup IfxLld_Can_Std_Interrupt_Functions
 * \{ */

/******************************************************************************/
/*-------------------------Inline Function Prototypes-------------------------*/
/******************************************************************************/

/** \brief Clears the selected interrupt Flag.
 *
 * \param[inout] node      Specifies the pointer to the CAN Node registers.
 * \param[in]    interrupt Type of Interrupt. Range: \ref IfxCan_Interrupt.
 *
 * \retval None
 */
IFX_INLINE void IfxCan_Node_clearInterruptFlag(Ifx_CAN_N *node, IfxCan_Interrupt interrupt);

/** \brief Disables the selected interrupt.
 *
 * \param[inout] node      Specifies the pointer to the CAN Node registers.
 * \param[in]    interrupt Type of Interrupt. Range: \ref IfxCan_Interrupt.
 *
 * \retval None
 */
IFX_INLINE void IfxCan_Node_disableInterrupt(Ifx_CAN_N *node, IfxCan_Interrupt interrupt);

/** \brief Disables the Cancellation Finished Interrupt of the selected Tx buffer.
 *
 * \param[inout] node       Specifies the pointer to the CAN Node registers.
 * \param[in]    txBufferId Tx Buffer number. Range: \ref IfxCan_TxBufferId.
 *
 * \retval None
 */
IFX_INLINE void IfxCan_Node_disableTxBufferCancellationFinishedInterrupt(Ifx_CAN_N *node, IfxCan_TxBufferId txBufferId);

/** \brief Disables the Transmission Interrupt of the selected Tx buffer.
 *
 * \param[inout] node       Specifies the pointer to the CAN Node registers.
 * \param[in]    txBufferId Tx Buffer number. Range: \ref IfxCan_TxBufferId.
 *
 * \retval None
 */
IFX_INLINE void IfxCan_Node_disableTxBufferTransmissionInterrupt(Ifx_CAN_N *node, IfxCan_TxBufferId txBufferId);

/** \brief Enables the selected interrupt.
 *
 * \param[inout] node      Specifies the pointer to the CAN Node registers.
 * \param[in]    interrupt Type of Interrupt. Range: \ref IfxCan_Interrupt.
 *
 * \retval None
 */
IFX_INLINE void IfxCan_Node_enableInterrupt(Ifx_CAN_N *node, IfxCan_Interrupt interrupt);

/** \brief Enables the Cancellation Finished Interrupt of the selected Tx buffer.
 *
 * \param[inout] node       Specifies the pointer to the CAN Node registers.
 * \param[in]    txBufferId Tx Buffer number. Range: \ref IfxCan_TxBufferId.
 *
 * \retval None
 */
IFX_INLINE void IfxCan_Node_enableTxBufferCancellationFinishedInterrupt(Ifx_CAN_N *node, IfxCan_TxBufferId txBufferId);

/** \brief Enables the Transmission Interrupt of the selected Tx buffer.
 *
 * \param[inout] node       Specifies the pointer to the CAN Node registers.
 * \param[in]    txBufferId Tx Buffer number. Range: \ref IfxCan_TxBufferId.
 *
 * \retval None
 */
IFX_INLINE void IfxCan_Node_enableTxBufferTransmissionInterrupt(Ifx_CAN_N *node, IfxCan_TxBufferId txBufferId);

/** \brief Returns the status of selected interrupt flag.
 *
 * \param[in] node      Specifies the pointer to the CAN Node registers.
 * \param[in] interrupt Type of Interrupt. Range: \ref IfxCan_Interrupt.
 *
 * \retval TRUE If the specified interrupt flag is set.
 *         FALSE If the specified interrupt flag is not set.
 */
IFX_INLINE boolean IfxCan_Node_getInterruptFlagStatus(Ifx_CAN_N *node, IfxCan_Interrupt interrupt);

/******************************************************************************/
/*-------------------------Global Function Prototypes-------------------------*/
/******************************************************************************/

/** \brief Sets the slected interrupt to the selcted interrupt line.
 *
 * \param[inout] node           Specifies the pointer to the CAN Node registers.
 * \param[in]    interruptGroup Type of Interrupt group. Range: \ref IfxCan_InterruptGroup.
 * \param[in]    interruptLine  Interrupt line number. Range: \ref IfxCan_InterruptLine.
 *
 * \retval None
 */
IFX_EXTERN void IfxCan_Node_setGroupInterruptLine(Ifx_CAN_N *node, IfxCan_InterruptGroup interruptGroup, IfxCan_InterruptLine interruptLine);

/** \brief Sets the slected interrupt to the selcted interrupt line.
 *
 * \param[inout] node          Specifies the pointer to the CAN Node registers.
 * \param[in]    interrupt     Type of Interrupt. Range: \ref IfxCan_Interrupt.
 * \param[in]    interruptLine Interrupt line number. Range: \ref IfxCan_InterruptLine.
 *
 * \retval None
 */
IFX_EXTERN void IfxCan_Node_setInterruptLine(Ifx_CAN_N *node, IfxCan_Interrupt interrupt, IfxCan_InterruptLine interruptLine);

/** \} */

/** \addtogroup IfxLld_Can_Std_Module_Functions
 * \{ */

/******************************************************************************/
/*-------------------------Inline Function Prototypes-------------------------*/
/******************************************************************************/

/** \brief Returns the base adress of the selected Node of CAN module.
 *
 * \param[in] can    Specifies the pointer to the CAN registers.
 * \param[in] nodeId Node number of the module. Range: \ref IfxCan_NodeId.
 *
 * \retval Ifx_CAN* Specifies the pointer to the CAN Node registers.
 */
IFX_INLINE Ifx_CAN_N *IfxCan_getNodePointer(Ifx_CAN *can, IfxCan_NodeId nodeId);

/** \brief Returns the status of module enabled or disabled.
 *
 * \param[in] can Specifies the pointer to the CAN registers.
 *
 * \retval TRUE If the CAN module is enabled.
 *         FALSE If the CAN module is disabled.
 */
IFX_INLINE boolean IfxCan_isModuleEnabled(Ifx_CAN *can);

/** \brief Returns the module's suspend state.
 * TRUE :if module is suspended.
 * FALSE:if module is not yet suspended.
 *
 * \param[in] can Pointer to CAN module registers.
 *
 * \retval TRUE If the CAN module is currently suspended.
 *         FALSE If the CAN module is not yet suspended.
 */
IFX_INLINE boolean IfxCan_isModuleSuspended(Ifx_CAN *can);

/** \brief Sets the sensitivity of the module to sleep signal.
 *
 * \param[inout] can  Pointer to CAN registers.
 * \param[in]    mode Mode selection (enable/disable). Range: \ref IfxCan_SleepMode.
 *
 * \retval None
 */
IFX_INLINE void IfxCan_setSleepMode(Ifx_CAN *can, IfxCan_SleepMode mode);

/** \brief Set the Module to Hard/Soft suspend mode.
 * Note: The api works only when the OCDS is enabled and in Supervisor Mode. When OCDS is disabled the OCS suspend control is ineffective.
 *
 * \param[inout] can  Pointer to CAN module registers.
 * \param[in]    mode Module suspend mode. Range: \ref IfxCan_SuspendMode.
 *
 * \retval None
 */
IFX_INLINE void IfxCan_setSuspendMode(Ifx_CAN *can, IfxCan_SuspendMode mode);

/******************************************************************************/
/*-------------------------Global Function Prototypes-------------------------*/
/******************************************************************************/

/** \brief Disables the module (sets the disable request).
 *
 * \param[inout] can Specifies the pointer to the CAN registers.
 *
 * \retval None
 */
IFX_EXTERN void IfxCan_disableModule(Ifx_CAN *can);

/** \brief Enables the module (clears the disable request).
 *
 * \param[inout] can Specifies the pointer to the CAN registers.
 *
 * \retval None
 */
IFX_EXTERN void IfxCan_enableModule(Ifx_CAN *can);

/**
 * \param[in] can Module index of the CAN.
 *
 * \param[in] can Specifies the pointer to the CAN registers. Range: \ref IfxCan_Index.
 *
 * \retval Ifx_CAN* CAN module register address.
 */
IFX_EXTERN Ifx_CAN *IfxCan_getAddress(IfxCan_Index can);

/** \brief API to get the resource index of the CAN specified.
 *
 * \param[in] can Specifies the pointer to the CAN registers.
 *
 * \retval IfxCan_Index Can resource index. Range: \ref IfxCan_Index.
 */
IFX_EXTERN IfxCan_Index IfxCan_getIndex(Ifx_CAN *can);

/** \brief Returns the operating frequency of the CAN module.
 *
 * \retval uint32 Module Frequency. Range: 10MHz to 50MHz
 */
IFX_EXTERN uint32 IfxCan_getModuleFrequency(void);

/** \brief Resets CAN kernel.
 *
 * \param[inout] can Pointer to CAN registers.
 *
 * \retval None
 */
IFX_EXTERN void IfxCan_resetModule(Ifx_CAN *can);

/** \brief sets the clocksource selection.
 *
 * \param[inout] can         Specifies the pointer to the CAN registers.
 * \param[in]    clockSelect Clock selection option. Range: \ref IfxCan_ClockSelect.
 * \param[in]    clockSource Type of Clock Source selection. Range: \ref IfxCan_ClockSource.
 *
 * \retval None
 */
IFX_EXTERN void IfxCan_setClockSource(Ifx_CAN *can, IfxCan_ClockSelect clockSelect, IfxCan_ClockSource clockSource);

/** \brief Returns the adress of the selected routing element.
 *
 * \param[in] ramBaseAddress                   Address of CAN RAM. Range: 0 to 0xFFFFFFFF
 * \param[in] standardRoutingTableStartAddress Offset of Std Routing Table from Base Ram Address. Range: 0 to 0xFFFF
 * \param[in] index                            Index of the Routing element. Range: 0 to 0xFF
 *
 * \retval Ifx_CAN_SRT* Specifies the pointer to the corresponding routing index.
 */
IFX_EXTERN Ifx_CAN_SRT *IfxCan_Node_getStandardRoutingElementAddress(uint32 ramBaseAddress, uint16 standardRoutingTableStartAddress, uint8 index);

/** \brief Returns the adress of the selected routing element.
 *
 * \param[in] ramBaseAddress                   Address of CAN RAM. Range: 0 to 0xFFFFFFFF
 * \param[in] extendedRoutingTableStartAddress Offset of Xtd Routing Table from Base Ram Address. Range: 0 to 0xFFFF
 * \param[in] index                            Index of the Routing element. Range: 0 to 0xFF
 *
 * \retval Ifx_CAN_XRT* Specifies the pointer to the corresponding routing index.
 */
IFX_EXTERN Ifx_CAN_XRT *IfxCan_Node_getExtendedRoutingElementAddress(uint32 ramBaseAddress, uint16 extendedRoutingTableStartAddress, uint8 index);

/** \brief Initializes the RAM block.
 *
 * \param[inout] can Specifies the pointer to the CAN registers.
 *
 * \retval None
 */
IFX_EXTERN void IfxCan_ramInit(Ifx_CAN *can);

/** \} */

/** \addtogroup IfxLld_Can_Std_Tx_Event_FIFO_Element_Functions
 * \{ */

/******************************************************************************/
/*-------------------------Inline Function Prototypes-------------------------*/
/******************************************************************************/

/** \brief Sets the Tx Event Fifo Control (EFC) for transmit frame.
 *
 * \param[inout] txBufferElement Tx Buffer Element.
 * \param[in]    enable          Choice (True/ False).
 *
 * \retval None
 */
IFX_INLINE void IfxCan_Node_setTxEventFifoCtrl(Ifx_CAN_TXMSG *txBufferElement, boolean enable);

/** \brief Returns the Bit Rate Switch (BRS) from the Tx Event Fifo element.
 *
 * \param[in] txEventFifoElement Tx Event FIFO Element.
 *
 * \retval TRUE If BRS is active
 *         FALSE If BRS is not active
 */
IFX_INLINE boolean IfxCan_Node_getBRSFromTxEventFifo(Ifx_CAN_TXEVENT *txEventFifoElement);

/** \brief Returns the Data Length Code from the Tx Event Fifo Element.
 *
 * \param[in] txEventFifoElement Tx Event Fifo Element.
 *
 * \retval uint32 Data Length Code. Range: 0 to 15
 */
IFX_INLINE uint32 IfxCan_Node_getDLCFromTxEventFifo(Ifx_CAN_TXEVENT *txEventFifoElement);

/** \brief Returns the Error State Indicator (ESI) from the Tx Event Fifo element.
 *
 * \param[in] txEventFifoElement Tx Event FIFO Element.
 *
 * \retval Error State Indicator. TRUE If transmitting node is error passive
 *                                FALSE If transmitting node is error active
 */
IFX_INLINE boolean IfxCan_Node_getESIFromTxEventFifo(Ifx_CAN_TXEVENT *txEventFifoElement);

/** \brief Returns the FD Format (FDF) from the Tx Event Fifo element.
 *
 * \param[in] txEventFifoElement Tx Event FIFO Element.
 *
 * \retval TRUE If CAN FD frame format (new DLC-coding and CRC)
 *         FALSE If Standard frame format
 */
IFX_INLINE boolean IfxCan_Node_getFDFFromTxEventFifo(Ifx_CAN_TXEVENT *txEventFifoElement);

/** \brief Returns the Message Marker (MM) from the Tx Event Fifo element E1A.
 *
 * \param[in] txEventFifoElement Tx Event FIFO Element.
 *
 * \retval uint8 Message Marker value. Range 0 to 31
 */
IFX_INLINE uint8 IfxCan_Node_getMMFromTxEventFifo(Ifx_CAN_TXEVENT *txEventFifoElement);

/** \brief Returns the identifier (ID) from the Tx Event Fifo element.
 *
 * \param[in] txEventFifoElement Tx Event FIFO Element.
 *
 * \retval uint32 Identifier. Range: 0x000 to 0x7FF (Standard); 0 to 0x1FFFFFFF (Extended)
 */
IFX_INLINE uint32 IfxCan_Node_getMesssageIdFromTxEventFifo(Ifx_CAN_TXEVENT *txEventFifoElement);

/** \brief Returns the Remote Transmission Request Status (RTR) from the Tx Event Fifo element.
 *
 * \param[in] txEventFifoElement Tx Event FIFO Element.
 *
 * \retval Remote Transmission Request Status. TRUE  If Remote frame transmitted.
 *                                             FALSE If Data frame transmitted.
 */
IFX_INLINE boolean IfxCan_Node_getRTRFromTxEventFifo(Ifx_CAN_TXEVENT *txEventFifoElement);

/** \brief Returns the Tx Time Stamp (TXTS) from the Tx Event Fifo element.
 *
 * \param[in] txEventFifoElement Tx Event FIFO Element.
 *
 * \retval uint16 16 bit Tx Time Stamp. Range: 0 to 0xFFFF
 */
IFX_INLINE uint16 IfxCan_Node_getTXTSFromTxEventFifo(Ifx_CAN_TXEVENT *txEventFifoElement);

/** \brief Returns the Tx Event Fifo Acknowledge Index.
 *
 * \param[in] node Specifies the pointer to the CAN Node registers.
 *
 * \retval uint8 Returns Tx Event Fifo Acknowledge Index. Range: 0 to 31
 */
IFX_INLINE uint8 IfxCan_Node_getTxEventFifoAcknowledgeIndex(Ifx_CAN_N *node);

/** \brief Returns the Tx Event Fifo Fill Level.
 *
 * \param[in] node Specifies the pointer to the CAN Node registers.
 *
 * \retval uint8 Returns Tx Event Fifo Fill Level. Range: 0 to 32
 */
IFX_INLINE uint8 IfxCan_Node_getTxEventFifoFillLevel(Ifx_CAN_N *node);

/** \brief Returns the Tx Event Fifo Get Index.
 *
 * \param[in] node Specifies the pointer to the CAN Node registers.
 *
 * \retval uint8 Returns Tx Event Fifo Get Index. Range: 0 to 31
 */
IFX_INLINE uint8 IfxCan_Node_getTxEventFifoGetIndex(Ifx_CAN_N *node);

/** \brief Returns the Tx Event Fifo Put Index.
 *
 * \param[in] node Specifies the pointer to the CAN Node registers.
 *
 * \retval uint8 Returns Tx Event Fifo Put Index. Range: 0 to 31
 */
IFX_INLINE uint8 IfxCan_Node_getTxEventFifoPutIndex(Ifx_CAN_N *node);

/** \brief Returns Tx Event Fifo Size.
 *
 * \param[in] node Specifies the pointer to the CAN Node registers.
 *
 * \retval uint8 Tx Event Fifo Size. Range: 0 to 32
 */
IFX_INLINE uint8 IfxCan_Node_getTxEventFifoSize(Ifx_CAN_N *node);

/** \brief Returns Tx Event Fifo Start Address.
 *
 * \param[in] node Specifies the pointer to the CAN Node registers.
 *
 * \retval uint16 Tx Event Fifo Start Address. Range: 0x0000 to 0x3FFF
 */
IFX_INLINE uint16 IfxCan_Node_getTxEventFifoStartAddress(Ifx_CAN_N *node);

/** \brief Returns Tx Event Fifo Watermark Level.
 *
 * \param[in] node Specifies the pointer to the CAN Node registers.
 *
 * \retval uint8 Tx Event Fifo Watermark Level. Range: 1 to 32
 */
IFX_INLINE uint8 IfxCan_Node_getTxEventFifoWatermarkLevel(Ifx_CAN_N *node);

/** \brief Returns the status of Tx Event Fifo Element lost.
 *
 * \param[in] node Specifies the pointer to the CAN Node registers.
 *
 * \retval Returns status of Tx Event Fifo Element Lost\n.
 *         True : Element lost\n
 *         False : Element not lost
 */
IFX_INLINE boolean IfxCan_Node_isTxEventFifoElementLost(Ifx_CAN_N *node);

/** \brief Returns the status of Tx Event Fifo Full.
 *
 * \param[in] node Specifies the pointer to the CAN Node registers.
 *
 * \retval Returns status of Tx Event Fifo Full\n.
 *         True : Fifo full\n
 *         False : Fifo not full
 */
IFX_INLINE boolean IfxCan_Node_isTxEventFifoFull(Ifx_CAN_N *node);

/** \brief Sets Tx Event Fifo Size.
 *
 * \param[inout] node Specifies the pointer to the CAN Node registers.
 * \param[in]    size Tx Event Fifo Size. Range: 1 to 32
 *
 * \retval None
 */
IFX_INLINE void IfxCan_Node_setTxEventFifoSize(Ifx_CAN_N *node, uint8 size);

/** \brief Sets Tx Event Fifo Start Address.
 *
 * \param[inout] node    Specifies the pointer to the CAN Node registers.
 * \param[in]    address Tx Event Fifo Start Address. Range: 0x0000 to 0x3FFF
 *
 * \retval None
 */
IFX_INLINE void IfxCan_Node_setTxEventFifoStartAddress(Ifx_CAN_N *node, uint16 address);

/** \brief Sets Tx Event Fifo Watermark Level.
 *
 * \param[inout] node  Specifies the pointer to the CAN Node registers.
 * \param[in]    level Tx Event Fifo Watermark Level. Range: 1 to 32
 *
 * \retval None
 */
IFX_INLINE void IfxCan_Node_setTxEventFifoWatermarkLevel(Ifx_CAN_N *node, uint8 level);

/******************************************************************************/
/*-------------------------Global Function Prototypes-------------------------*/
/******************************************************************************/

/** \brief Returns CAN frame mode of operation for a Tx Event Fifo Element.
 *
 * \param[in] txEventFifoElement Tx Event Fifo Element.
 *
 * \retval IfxCan_FrameMode CAN frame mode. Range: \ref IfxCan_FrameMode.
 */
IFX_EXTERN IfxCan_FrameMode IfxCan_Node_getFrameModeFromTxEventFifo(Ifx_CAN_TXEVENT *txEventFifoElement);

/** \brief Returns the address of selected Tx Event Fifo element.
 *
 * \param[in] ramBaseAddress          Message RAM base address of CAN module. Range: 0xF0200000 to 0xF0223FFF
 * \param[in] txEventFifoStartAddress Start address of Tx Event Fifo section in the Message RAM. Range: 0x0000 to 0x3FFF
 * \param[in] txEventFifoNumber       Tx Event Fifo element number. Range: 0 to 31
 *
 * \retval Ifx_CAN_TXEVENT* Tx Event Fifo Element Address.
 */
IFX_EXTERN Ifx_CAN_TXEVENT *IfxCan_Node_getTxEventFifoElementAddress(uint32 ramBaseAddress, uint16 txEventFifoStartAddress, uint8 txEventFifoNumber);

/** \} */

/******************************************************************************/
/*-------------------------Inline Function Prototypes-------------------------*/
/******************************************************************************/

/** \brief Sets the TSCE bit (Time Stamp Captuer Enable for TSU)for transmit frame.
 *
 * \param[inout] txBufferElement Tx Buffer Element.
 * \param[in]    enable          Choice (True/ False).
 *
 * \retval None
 */
IFX_INLINE void IfxCan_Node_setTxEventTimeStampCaptureEnable(Ifx_CAN_TXMSG *txBufferElement, boolean enable);

/** \brief CAN frame format of the last received message.
 * TRUE: CAN FD frame received.
 * FALSE: CAN FD frame not received.
 *
 * \param[in] node Specifies the pointer to CAN node registers.
 *
 * \retval CAN Frame format (TRUE/FALSE).
 */
IFX_INLINE boolean IfxCan_Node_isCanFDMsgReceived(Ifx_CAN_N *node);

/** \brief Enables/Disables the Extended Filter Sync.
 *
 * \param[inout] extendedFilterElement Extended Filter Element.
 * \param[in]    enable                1: enables the ESYNC, 0: disables the ESYNC.
 *
 * \retval None
 */
IFX_INLINE void IfxCan_Node_setExtendedFilterSync(Ifx_CAN_EXTMSG *extendedFilterElement, boolean enable);

/** \brief Enable Use TSU.
 *
 * \param[inout] node Specifies the pointer to CAN node registers.
 *
 * \retval None
 */
IFX_INLINE void IfxCan_Node_enableUseTsu(Ifx_CAN_N *node);

/** \brief Disable Use TSU.
 *
 * \param[inout] node Specifies the pointer to CAN node registers.
 *
 * \retval None
 */
IFX_INLINE void IfxCan_Node_disableUseTsu(Ifx_CAN_N *node);

/** \brief Enable the Time Stamping Unit (TSU).
 *
 * \param[inout] node Specifies the pointer to CAN node registers.
 *
 * \retval None
 */
IFX_INLINE void IfxCan_Node_enableTsu(Ifx_CAN_N *node);

/** \brief Disable the Time Stamping Unit (TSU).
 *
 * \param[inout] node Specifies the pointer to CAN node registers.
 *
 * \retval None
 */
IFX_INLINE void IfxCan_Node_disableTsu(Ifx_CAN_N *node);

/** \brief Set the prescalar for Internal TSU Counter.
 *
 * \param[inout] node      Specifies the pointer to CAN node registers.
 * \param[in]    prescalar Specifies the prescalar for Internal TSU Counter. Range: 0 to 0xF.
 *
 * \retval None
 */
IFX_INLINE void IfxCan_Node_setTsuInternalPrescalar(Ifx_CAN_N *node, uint8 prescalar);

/** \brief Set the position to capture the Time Stamp.
 *
 * \param[inout] node     Specifies the pointer to CAN node registers.
 * \param[in]    position Specifies the position to capture the Time Stamp. Range: \ref IfxCan_TsuTimeStampPosition.
 *
 * \retval None
 */
IFX_INLINE void IfxCan_Node_setTsuCapturePoint(Ifx_CAN_N *node, IfxCan_TsuTimeStampPosition position);

/** \brief Get the status of Captured Time Stamp.
 *
 * \param[in] rxHostBuffer Specifies the pointer to CRE RX FIFO Structure.
 *
 * \retval IfxCan_CreTimeStampCaptured 0: invalid Time Stamp, 1: valid Time Stamp. Range: \ref IfxCan_CreTimeStampCaptured.
 */
IFX_INLINE IfxCan_CreTimeStampCaptured IfxCan_Cre_getTimeStampCapturedStatus(Ifx_CAN_RHBUF *rxHostBuffer);

/** \brief Get the length of Captured Time Stamp.
 *
 * \param[in] rxHostBuffer Specifies the pointer to CRE RX FIFO Structure.
 *
 * \retval IfxCan_CreTimeStampType 0: 16 bit Time Stamp, 1: 32 bit Time Stamp. Range: \ref IfxCan_CreTimeStampType.
 */
IFX_INLINE IfxCan_CreTimeStampType IfxCan_Cre_getTimeStampLength(Ifx_CAN_RHBUF *rxHostBuffer);

/** \brief Get the Captured Time Stamp from Timing Header of Rx Fifo.
 *
 * \param[in] rxHostBuffer Specifies the pointer to CRE RX FIFO Structure.
 *
 * \retval uint32 Time Stamp. Range: 0 to 0xFFFFFFFF
 */
IFX_INLINE uint32 IfxCan_Cre_getTimeStamp(Ifx_CAN_RHBUF *rxHostBuffer);

/** \brief Get the status of Captured Inter Arrival Measure from Timing Header of Rx Fifo.
 *
 * \param[in] rxHostBuffer Specifies the pointer to CRE RX FIFO Structure.
 *
 * \retval IfxCan_InterArrivalMeasureStatus IAM Status. Range: \ref IfxCan_InterArrivalMeasureStatus.
 */
IFX_INLINE IfxCan_InterArrivalMeasureStatus IfxCan_Cre_getIamStatus(Ifx_CAN_RHBUF *rxHostBuffer);

/** \brief Get the IDMU Throughput value.
 *
 * \param[in] node Specifies the pointer to CAN node registers.
 *
 * \retval uint16 Throughput Value. Range: 0 to 0xFFFF
 */
IFX_INLINE uint16 IfxCan_Node_Cre_getThroughput(Ifx_CAN_N *node);

/** \brief Clears the IDMU Throughput value. Set PROTE to config before use.
 *
 * \param[inout] node Specifies the pointer to CAN node registers.
 *
 * \retval None
 */
IFX_INLINE void IfxCan_Node_Cre_clearThroughput(Ifx_CAN_N *node);

/** \brief Set the start address for IDMU Frame Rate Table for Standard Frames.
 *
 * \param[inout] node       Specifies the pointer to CAN node registers.
 * \param[in]    address    32 bit word aligned address. Range: 0 to 0x3FFF
 * \param[in]    ramAddress Address of CAN RAM (or equivalently start address of CAN Module to which the node belongs). Range: 0 to 0xFFFFFFFF
 *
 * \retval None
 */
IFX_INLINE void IfxCan_Node_Cre_setStdFrameRateAddress(Ifx_CAN_N *node, uint16 address, uint32 ramAddress);

/** \brief Set the start address for IDMU Frame Rate Table for Extended Frames.
 *
 * \param[inout] node       Specifies the pointer to CAN node registers.
 * \param[in]    address    32 bit word aligned address. Range: 0 to 0x3FFF
 * \param[in]    ramAddress Address of CAN RAM (or equivalently start address of CAN Module to which the node belongs). Range: 0 to 0xFFFFFFFF
 *
 * \retval None
 */
IFX_INLINE void IfxCan_Node_Cre_setXtdFrameRateAddress(Ifx_CAN_N *node, uint16 address, uint32 ramAddress);

/** \brief Return the absolute start address of IDMU Frame Rate Table for Standard Frames.
 *
 * \param[in] node       Specifies the pointer to CAN node registers.
 * \param[in] ramAddress Address of CAN RAM (or equivalently start address of CAN Module to which the node belongs). Range: 0 to 0xFFFFFFFF
 *
 * \retval uint32 Returns address. Range: 0 to 0xFFFFFFFF
 */
IFX_INLINE uint32 IfxCan_Node_Cre_getStdFrameRateAddress(Ifx_CAN_N *node, uint32 ramAddress);

/** \brief Return the absolute start address of IDMU Frame Rate Table for Extended Frames.
 *
 * \param[in] node       Specifies the pointer to CAN node registers.
 * \param[in] ramAddress Address of CAN RAM (or equivalently start address of CAN Module to which the node belongs). Range: 0 to 0xFFFFFFFF
 *
 * \retval uint32 Returns address. Range: 0 to 0xFFFFFFFF
 */
IFX_INLINE uint32 IfxCan_Node_Cre_getXtdFrameRateAddress(Ifx_CAN_N *node, uint32 ramAddress);

/** \brief Set the size of IDMU Standard Frame Rate Table.
 *
 * \param[inout] node       Specifies the pointer to CAN node registers.
 * \param[in]    size       Size of Standard Frame Rate Table. Range: \ref IfxCan_StdFrameRateSize.
 * \param[in]    ramAddress Address of CAN RAM (or equivalently start address of CAN Module to which the node belongs). Range: 0 to 0xFFFFFFFF
 *
 * \retval None
 */
IFX_INLINE void IfxCan_Node_Cre_setStdFrameRateSize(Ifx_CAN_N *node, IfxCan_StdFrameRateSize size, uint32 ramAddress);

/** \brief Set the size of IDMU Extended Frame Rate Table
 *
 * \param[inout] node       Specifies the pointer to CAN node registers.
 * \param[in]    size       Size of Extended Frame Rate Table. Range: \ref IfxCan_StdFrameRateSize.
 * \param[in]    ramAddress Address of CAN RAM (or equivalently start address of CAN Module to which the node belongs). Range: 0 to 0xFFFFFFFF
 *
 * \retval None
 */
IFX_INLINE void IfxCan_Node_Cre_setXtdFrameRateSize(Ifx_CAN_N *node, IfxCan_XtdFrameRateSize size, uint32 ramAddress);

/** \brief Lock the IDMU Standard Frame Rate Counters. Set PROTE to config before use.
 *
 * \param[inout] node Specifies the pointer to CAN node registers.
 *
 * \retval None
 */
IFX_INLINE void IfxCan_Node_Cre_enableStdFrameRateLock(Ifx_CAN_N *node);

/** \brief Lock the IDMU Extended Frame Rate Counters. Set PROTE to config before use.
 *
 * \param[inout] node Specifies the pointer to CAN node registers.
 *
 * \retval None
 */
IFX_INLINE void IfxCan_Node_Cre_enableXtdFrameRateLock(Ifx_CAN_N *node);

/** \brief Unlock the IDMU Standard Frame Rate Counters. Set PROTE to config before use.
 *
 * \param[inout] node Specifies the pointer to CAN node registers.
 *
 * \retval None
 */
IFX_INLINE void IfxCan_Node_Cre_disableStdFrameRateLock(Ifx_CAN_N *node);

/** \brief Unlock the IDMU Extended Frame Rate Counters. Set PROTE to config before use.
 *
 * \param[inout] node Specifies the pointer to CAN node registers.
 *
 * \retval None
 */
IFX_INLINE void IfxCan_Node_Cre_disableXtdFrameRateLock(Ifx_CAN_N *node);

/** \brief Returns the 32 bit specified TSU Time Stamp Register Value.
 *
 * \param[in] node  Specifies the pointer to CAN node registers.
 * \param[in] index Index of Time Stamp Register. Range: \ref IfxCan_TsuTimeStampIndex.
 *
 * \retval uint32 Time stamp value. Range: 0 to 0xFFFFFFFF
 */
IFX_INLINE uint32 IfxCan_Node_getTsuTimeStamp(Ifx_CAN_N *node, IfxCan_TsuTimeStampIndex index);

/** \brief New time stamp status for corresponding TSU.TS[index] register.
 *
 * \param[in] node  Specifies the pointer to CAN node registers.
 * \param[in] index Index of Time Stamp Register. Range: \ref IfxCan_TsuTimeStampIndex.
 *
 * \retval Returns 1 if new Time Stamp is available for the corresponding index, else 0.
 */
IFX_INLINE boolean IfxCan_Node_getTsuTimeStampNewStatus(Ifx_CAN_N *node, IfxCan_TsuTimeStampIndex index);

/** \brief Time stamp lost and overwritten status for corresponding TSU.TS[index] register.
 *
 * \param[in] node  Specifies the pointer to CAN node registers.
 * \param[in] index Index of Time Stamp Register. Range: \ref IfxCan_TsuTimeStampIndex.
 *
 * \retval Returns 1 if Time Stamp was overwritten before being read for the corresponding index, else 0.
 */
IFX_INLINE boolean IfxCan_Node_getTsuTimeStampLostStatus(Ifx_CAN_N *node, IfxCan_TsuTimeStampIndex index);

/** \brief Start/Stop the TxTrig0 Timer.
 *
 * \param[inout] node   Specifies the pointer to the CAN Node registers.
 * \param[in]    enable Choice (True: Start the timer, False: Stop the timer).
 *
 * \retval None
 */
IFX_INLINE void IfxCan_Node_setTimerStartTxTrig0(Ifx_CAN_N *node, boolean enable);

/** \brief Start/Stop the TxTrig1 Timer.
 *
 * \param[inout] node   Specifies the pointer to the CAN Node registers.
 * \param[in]    enable Choice (True: Start the timer, False: Stop the timer).
 *
 * \retval None
 */
IFX_INLINE void IfxCan_Node_setTimerStartTxTrig1(Ifx_CAN_N *node, boolean enable);

/** \brief Start/Stop the TxTrig2 Timer.
 *
 * \param[inout] node   Specifies the pointer to the CAN Node registers.
 * \param[in]    enable Choice (True: Start the timer, False: Stop the timer).
 *
 * \retval None
 */
IFX_INLINE void IfxCan_Node_setTimerStartTxTrig2(Ifx_CAN_N *node, boolean enable);

/** \brief Returns the Wide 16 bit Message Marker (MM0 and MM1) from the Tx Event Fifo element E1B.
 *
 * \param[in] txEventFifoElement Tx Event FIFO Element.
 *
 * \retval uint16 Message Marker. Range: 0 to 0xFFFF
 */
IFX_INLINE uint16 IfxCan_Node_getWideMMFromTxEventFifo(Ifx_CAN_TXEVENT *txEventFifoElement);

/** \brief Returns the Tx Time Stamp Pointer to TSU (TXTSP) from the Tx Event Fifo element if the Time Stamp Captured is Valid.
 *
 * \param[in] txEventFifoElement Tx Event FIFO Element.
 *
 * \retval 4 bit number of TSU Time Stamp Registers which holds the 32 bit time stamp. Range: 0 to 15
 */
IFX_INLINE uint8 IfxCan_Node_getValidTXTSPFromTxEventFifo(Ifx_CAN_TXEVENT *txEventFifoElement);

/** \brief Set the width of message marker.
 *
 * \param[inout] node   Specifies the pointer to CAN node registers.
 * \param[in]    enable TRUE: 16 bit message marker and 16 bit internal timestamping is disabled, FALSE: 8 bit message marker.
 *
 * \retval None
 */
IFX_INLINE void IfxCan_Node_setWideMessageMarker(Ifx_CAN_N *node, boolean enable);

/** \brief Set the TX host buffer DRE Software trigger.
 *
 * \param[inout] node Specifies the pointer to CAN node registers.
 *
 * \retval None
 */
IFX_INLINE void IfxCan_Node_setTxBufferDreSoftwareTrigger(Ifx_CAN_N *node);

/** \brief Reset the CRE TX host buffer Watchdog.
 *
 * \param[inout] node Specifies the pointer to CAN node registers. Range: \ref IfxCan_CreTxHostBufferIndex.
 *
 * \retval None
 */
IFX_INLINE void IfxCan_Node_resetTxBufferWatchdogEventGroup(Ifx_CAN_N *node, IfxCan_CreTxHostBufferIndex txHostBufferIndex);

/******************************************************************************/
/*-------------------------Global Function Prototypes-------------------------*/
/******************************************************************************/

/** \brief Returns the address of interrupt node source register.
 *
 * \param[in] can           Specifies the pointer to the CAN registers.
 * \param[in] interruptLine Interrupt line number. Range: \ref IfxCan_InterruptLine.
 *
 * \retval volatile Ifx_SRC_SRCR* Address of interrupt node source register.
 */
IFX_EXTERN volatile Ifx_SRC_SRCR *IfxCan_getSrcPointer(Ifx_CAN *can, IfxCan_InterruptLine interruptLine);

/** \brief Configure and initialise the 16 bit internal CAN Time Stamp Counter.
 * CCCR.UTSU must be disabled before use.
 *
 * \param[inout] node      Specifies the pointer to CAN node registers.
 * \param[in]    prescalar Prescalar for internal time stamp clock. Range: \ref IfxCan_IntTimerPrescalar.
 *
 * \retval None
 */
IFX_EXTERN void IfxCan_Node_setInternalTimeStamp(Ifx_CAN_N *node, IfxCan_IntTimerPrescalar prescalar);

/** \brief Configure the prescalar of 16 bit internal CAN Time Stamp.
 *
 * \param[inout] node      Specifies the pointer to CAN node registers.
 * \param[in]    prescalar Prescalar for internal time stamp clock. Range: \ref IfxCan_IntTimerPrescalar.
 *
 * \retval None
 */
IFX_EXTERN void IfxCan_Node_setTsccPrescalar(Ifx_CAN_N *node, IfxCan_IntTimerPrescalar prescalar);

/** \brief Initialise the 32 bit Time Stamping Unit.
 * CCCR.UTSU must be enabled before use.
 *
 * \param[inout] node      Specifies the pointer to CAN node registers.
 * \param[in]    tsuConfig Configuration for TSU.
 *
 * \retval None
 */
IFX_EXTERN void IfxCan_Node_tsuInit(Ifx_CAN_N *node, IfxCan_TsuConfig tsuConfig);

/** \brief Set the configured type of TSU Counter.
 *
 * \param[inout] node        Specifies the pointer to CAN node registers.
 * \param[in]    counterType TSU Counter Type. Range: \ref IfxCan_TsuCounter.
 *
 * \retval None
 */
IFX_EXTERN void IfxCan_Node_setTsuCounter(Ifx_CAN_N *node, IfxCan_TsuCounter counterType);

/** \brief Get the captured Inter Arrival Measure if available, else return 0. Minimum 2 frames belonging to a given Group ID must be received before IAM is available.
 *
 * \param[in] rxHostBuffer Specifies the pointer to CRE RX FIFO Structure.
 *
 * \retval uint32 28 bit Inter Arrival Measurement. Range: 0 to 0x0FFFFFFF.
 */
IFX_EXTERN uint32 IfxCan_Cre_getInterArrivalMeasure(Ifx_CAN_RHBUF *rxHostBuffer);

/** \brief Minimum 2 frames belonging to a given Group ID must be received before IAM is available. Wait until Inter Arrival Measurement. is available and return the measurement.
 *
 * \param[in] rxHostBuffer Specifies the pointer to CRE RX FIFO Structure.
 *
 * \retval uint32 28 bit Inter Arrival Measurement. Range: 0 to 0x0FFFFFFF.
 */
IFX_EXTERN uint32 IfxCan_Cre_waitAndGetValidIam(Ifx_CAN_RHBUF *rxHostBuffer);

/** \brief Returns the corresponding Frame Rate of a Standard Frame with the given Group ID.
 *
 * \param[in] node        Specifies the pointer to CAN node registers.
 * \param[in] id          Group Id of Standard Frame. Range: \ref IfxCan_StdFrameGroupId.
 * \param[in] ramAddress  Base address of RAM. Range: 0 to 0xFFFFFFFF
 * \param[in] clearEnable 1: clear the counter after read.
 *
 * \retval uint16 Frame rate. Range: 0 to 0xFFFF
 */
IFX_EXTERN uint16 IfxCan_Node_Cre_getStdGroupXFrameRate(Ifx_CAN_N *node, IfxCan_StdFrameGroupId id, uint32 ramAddress, boolean clearEnable);

/** \brief Returns the corresponding Frame Rate of an Extended Frame with the given Group ID.
 *
 * \param[in] node        Specifies the pointer to CAN node registers.
 * \param[in] id          Group Id of Extended Frame. Range: \ref IfxCan_StdFrameGroupId.
 * \param[in] ramAddress  Base address of RAM. Range: 0 to 0xFFFFFFFF
 * \param[in] clearEnable 1: clear the counter after read.
 *
 * \retval uint16 Frame rate. Range: 0 to 0xFFFF
 */
IFX_EXTERN uint16 IfxCan_Node_Cre_getXtdGroupXFrameRate(Ifx_CAN_N *node, IfxCan_XtdFrameGroupId id, uint32 ramAddress, boolean clearEnable);

/** \brief Configure 16 bit CAN Time Stamp to take count from external timers.
 * External Timers like STM, GTM, eGTM, etc have to be initialised first.
 * Call IfxCan_Node_forceStartExternalTimer after this API to start the external timer.
 *
 * \param[inout] node      Specifies the pointer to CAN node registers.
 * \param[in]    prescalar Prescalar for internal time stamp clock. Range: \ref IfxCan_ExtTimerPrescalar.
 * \param[in]    trigger   External trigger source for time stamp. Range: \ref IfxCan_TimerTrigger.
 *
 * \retval None
 */
IFX_EXTERN void IfxCan_Node_setExternalTimeStamp(Ifx_CAN_N *node, IfxCan_ExtTimerPrescalar prescalar, IfxCan_TimerTrigger trigger);

/** \brief Force Starts the external Timer.
 * External Timer(STM,GTM,TSU) have to be initialised first.
 * Can Node must be configured to select corresponding trigger source along with its configurations.
 * Then call this API to start the external timer.
 *
 * \param[inout] node Specifies the pointer to CAN node registers.
 *
 * \retval None
 */
IFX_EXTERN void IfxCan_Node_forceStartExternalTimer(Ifx_CAN_N *node);

/** \brief Starts the external Timer.
 * External Timer(STM,GTM,TSU) have to be initialized first.
 * Can Node must be configered to select corresponding trigger source along with its configurations.
 * Then call this API to start the external timer.
 * It will not start if Reset(TIMER.CCR.B.STRESET) is also 1.
 *
 * \param[inout] node  Specifies the pointer to CAN node registers
 * \param[in]    start TRUE: Starts the external timer if STRESET is False,
 *                     FALSE: Default value.
 *
 * \retval None
 */
IFX_EXTERN void IfxCan_Node_setStartExternalTimer(Ifx_CAN_N *node, boolean start);

/** \brief Resets the Timestamp for CAN FD messages.
 *
 * \param[inout] node  Specifies the pointer to CAN node registers.
 * \param[in]    reset TRUE: Resets the external timer.
 *                     FALSE: Default value. Must be 0 before starting the external timer.
 *
 * \retval None
 */
IFX_EXTERN void IfxCan_Node_setResetExternalTimer(Ifx_CAN_N *node, boolean reset);

/** \brief Initializes the 32 bit Time Stamping Unit, also with configuration change enable for standalone usage.
 * CCCR.UTSU must be enabled before use.
 *
 * \param[inout] node      Specifies the pointer to CAN node registers.
 * \param[in]    tsuConfig Configuration for TSU.
 *
 * \retval None
 */
IFX_EXTERN void IfxCan_Node_tsuInitWithConfigChangeEnable(Ifx_CAN_N *node, IfxCan_TsuConfig tsuConfig);

/** \brief Initialize the PROTs and APUs with default configuration.
 *
 * \param[inout] config Configuration pointer for the Access Protection.
 *
 * \retval None
 */
IFX_EXTERN void IfxCan_initApConfig(IfxCan_ApConfig *config);

/** \brief Initialize the PORTs and all 5 APU register set.
 *
 * \param[inout] can    CAN module pointer.
 * \param[in]    config Configuration pointer to the AP Config structure.
 *
 * \retval None
 */
IFX_EXTERN void IfxCan_initAp(Ifx_CAN *can, IfxCan_ApConfig *config);

/** \brief Clear all CRE Interrupt Flags.
 *
 * \param[inout] node Specifies the pointer to the CAN Node registers.
 *
 * \retval None
 */
IFX_EXTERN void IfxCan_Node_clearCreInterrupts(Ifx_CAN_N *node);

/** \brief Clear a particular CRE Interrupt Flag.
 *
 * \param[inout] node  Specifies the pointer to the CAN Node registers.
 * \param[in]    index Index of the CRE Interrupt Flag. Range: \ref IfxCan_CreInterrupt.
 *
 * \retval None
 */
IFX_EXTERN void IfxCan_Node_clearCreInterrupt(Ifx_CAN_N *node, IfxCan_CreInterrupt index);

/** \brief Sets the protected RAM Start Address, within the CAN RAM area for the given node. Set PROTE to config before use.
 *
 * \param[inout] node    Specifies the pointer to the CAN Node registers.
 * \param[in]    address 14 bit start address. Range: 0 to 0x3FFF.
 *
 * \retval None
 */
IFX_EXTERN void IfxCan_Node_setRamStartAddress(Ifx_CAN_N *node, uint16 address);

/** \brief Sets the protected RAM End Address, within the CAN RAM area for the given node. Set PROTE to config before use.
 *
 * \param[inout] node    Specifies the pointer to the CAN Node registers.
 * \param[in]    address 14 bit end address. Range: 0 to 0x3FFF.
 *
 * \retval None
 */
IFX_EXTERN void IfxCan_Node_setRamEndAddress(Ifx_CAN_N *node, uint16 address);

/** \brief Configures access to all masters to all the Can in the device.
 *
 * \param[in] apConfig pointer to configuration structure.
 *
 * \retval None
 */
IFX_EXTERN void IfxCan_configureAccessToCans(IfxApApu_ApuConfig *apConfig);

/** \brief Disable CRE Watchdog.
 *
 * \param[inout] can Specifies the pointer to the CAN module registers.
 *
 * \retval None
 */
IFX_EXTERN void IfxCan_disableModuleCreWatchdog(Ifx_CAN *can);

/** \brief Enable and configure prescalars of CRE Watchdog.
 *
 * \param[inout] can           Specifies the pointer to the CAN module registers.
 * \param[in]    fastPrescalar FastPrescalar 15 bit Fast Watchdog prescaler. Range: 0 to 0x7FFF.
 * \param[in]    slowPrescalar SlowPrescalar 16 bit Slow Watchdog prescaler. Range: 0 to 0xFFFF.
 *
 * \retval None
 */
IFX_EXTERN void IfxCan_enableModuleCreWatchdog(Ifx_CAN *can, uint16 fastPrescalar, uint16 slowPrescalar);

/** \brief Enable/Disable the Cre Watchdog groups of the selected node.
 *
 * \param[inout] can          Specifies the pointer to the CAN module registers.
 * \param[in]    nodeId       Specifies the Can Node. Range: \ref IfxCan_NodeId.
 * \param[in]    enableGroups Specifies the pointer to the watchdog group enable structure.
 *
 * \retval None
 */
IFX_EXTERN void IfxCan_enableCreNodeWatchdogGroups(Ifx_CAN *can, IfxCan_NodeId nodeId, IfxCan_CreWatchdogGroups *enableGroups);

/** \brief Enable/Disable the Cre Error Interrupts of the selected node.
 *
 * \param[inout] can              Specifies the pointer to the CAN module registers.
 * \param[in]    nodeId           Specifies the Can Node. Range: \ref IfxCan_NodeId.
 * \param[in]    enableInterrupts Specifies the pointer to the cre interrupt flag enable structure.
 *
 * \retval None
 */
IFX_EXTERN void IfxCan_enableCreNodeErrorInterrupts(Ifx_CAN *can, IfxCan_NodeId nodeId, IfxCan_CreErrorInterruptEnable *enableInterrupts);

/******************************************************************************/
/*---------------------Inline Function Implementations------------------------*/
/******************************************************************************/

IFX_INLINE void IfxCan_Node_disableConfigurationChange(Ifx_CAN_N *node)
{
    node->CCCR.B.CCE = 0;

    while (node->CCCR.B.CCE != 0)
    {}

    node->CCCR.B.INIT = 0;

    while (node->CCCR.B.INIT != 0)
    {}
}


IFX_INLINE void IfxCan_Node_enableConfigurationChange(Ifx_CAN_N *node)
{
    Ifx_CAN_N_CCCR cccr;

    /* If INIT already set, clear it before setting again. */
    /* The module needs some time if INIT was rewritten !*/
    if (node->CCCR.B.INIT == 1)
    {
        node->CCCR.B.CCE = 0;

        while (node->CCCR.B.CCE != 0)
        {}

        node->CCCR.B.INIT = 0;

        while (node->CCCR.B.INIT != 0)
        {}
    }

    node->CCCR.B.INIT = 1;

    while (node->CCCR.B.INIT != 1)
    {}

    {
        cccr.U       = node->CCCR.U;
        cccr.B.INIT  = 1;
        cccr.B.CCE   = 1;
        node->CCCR.U = cccr.U;
    }
}


IFX_INLINE void IfxCan_Node_enableLoopbackMode(Ifx_CAN_N *node)
{
    node->PORTCTRL.B.LBM = 1;
}

IFX_INLINE void IfxCan_Node_enableLoopbackOutMode(Ifx_CAN_N *node)
{
    node->PORTCTRL.B.LOUT = 1;
}

IFX_INLINE boolean IfxCan_Node_isNodeSynchronized(Ifx_CAN_N *node)
{
    return (boolean)((node->PSR.B.ACT != 0) ? 1 : 0);
}


IFX_INLINE void IfxCan_Node_setInitialisation(Ifx_CAN_N *node, boolean enable)
{
    node->CCCR.B.INIT = enable ? 1 : 0;
}


IFX_INLINE void IfxCan_Node_setTransceiverDelayCompensationOffset(Ifx_CAN_N *node, uint8 delay)
{
    /* enable Transceiver Delay Compensation */
    node->DBTP.B.TDC  = 1;
    /* set Transceiver Delay Compensation offset */
    node->TDCR.B.TDCO = delay;
}


IFX_INLINE IfxCan_LastErrorCodeType IfxCan_Node_getLastErroCodeStatus(Ifx_CAN_N *node)
{
    return (IfxCan_LastErrorCodeType)(node->PSR.B.LEC);
}


IFX_INLINE boolean IfxCan_Node_isErrorPassive(Ifx_CAN_N *node)
{
    return node->PSR.B.EP;
}


IFX_INLINE IfxCan_CanNodeErrorWarningLimitStatus IfxCan_Node_getWarningStatus(Ifx_CAN_N *node)
{
    return (IfxCan_CanNodeErrorWarningLimitStatus)(node->PSR.B.EW);
}


IFX_INLINE IfxCan_CanNodeBusOffErrorStatus IfxCan_Node_getBusOffStatus(Ifx_CAN_N *node)
{
    return (IfxCan_CanNodeBusOffErrorStatus)(node->PSR.B.BO);
}


IFX_INLINE IfxCan_CanNodeCommunicationState IfxCan_Node_getActivityStatus(Ifx_CAN_N *node)
{
    return (IfxCan_CanNodeCommunicationState)(node->PSR.B.ACT);
}


IFX_INLINE IfxCan_LastErrorCodeType IfxCan_Node_getDataPhaseLastErrorCode(Ifx_CAN_N *node)
{
    return (IfxCan_LastErrorCodeType)(node->PSR.B.DLEC);
}


IFX_INLINE boolean IfxCan_Node_isProtocolExceptionEventOccured(Ifx_CAN_N *node)
{
    return node->PSR.B.PXE;
}


IFX_INLINE boolean IfxCan_Node_isErrorStatusIndicatorEnabled(Ifx_CAN_N *node)
{
    return node->PSR.B.RESI;
}


IFX_INLINE boolean IfxCan_Node_isBitRateSwitchFlagEnabled(Ifx_CAN_N *node)
{
    return node->PSR.B.RBRS;
}


IFX_INLINE IfxCan_DataLengthCode IfxCan_Node_getCodeFromDataLengthInBytes(uint32 dataLength)
{
    uint32 code;

    if (dataLength <= 8)
    {
        code = dataLength;
    }
    else if (dataLength <= 24)
    {
        code = (dataLength >> 2) + 6;
    }
    else
    {
        code = (dataLength >> 4) + 11;
    }

    return (IfxCan_DataLengthCode)code;
}


IFX_INLINE IfxCan_TxBufferId IfxCan_Node_getTxFifoQueuePutIndex(Ifx_CAN_N *node)
{
    return (IfxCan_TxBufferId)node->TX.FQS.B.TFQPI;
}


IFX_INLINE boolean IfxCan_Node_isTxBufferCancellationFinished(Ifx_CAN_N *node, IfxCan_TxBufferId txBufferId)
{
    uint32  mask    = (1U << txBufferId);
    boolean tempVar = (boolean)((node->TX.BCF.U & mask) != 0 ? 1 : 0);
    return tempVar;
}


IFX_INLINE boolean IfxCan_Node_isTxBufferRequestPending(Ifx_CAN_N *node, IfxCan_TxBufferId txBufferId)
{
    uint32  mask    = (1U << txBufferId);
    boolean tempVar = (boolean)((node->TX.BRP.U & mask) != 0 ? 1 : 0);
    return tempVar;
}


IFX_INLINE boolean IfxCan_Node_isTxBufferTransmissionOccured(Ifx_CAN_N *node, IfxCan_TxBufferId txBufferId)
{
    uint32 mask = (1U << txBufferId);
    return (boolean)((node->TX.BTO.U & mask) != 0 ? 1 : 0);
}


IFX_INLINE boolean IfxCan_Node_isTxFifoQueueFull(Ifx_CAN_N *node)
{
    return node->TX.FQS.B.TFQF;
}


IFX_INLINE void IfxCan_Node_pauseTransmission(Ifx_CAN_N *node, boolean enable)
{
    node->CCCR.B.TXP = enable ? 1 : 0;
}


IFX_INLINE void IfxCan_Node_setDataLength(Ifx_CAN_TXMSG *txBufferElement, IfxCan_DataLengthCode dataLengthCode)
{
    txBufferElement->T1.B.DLC = dataLengthCode;
}


IFX_INLINE void IfxCan_Node_setDataLengthCode(Ifx_CAN_N *node, Ifx_CAN_TXMSG *txBufferElement, IfxCan_DataLengthCode dataLengthCode)
{
    IFX_UNUSED_PARAMETER(node);
    txBufferElement->T1.B.DLC = dataLengthCode;
}


IFX_INLINE void IfxCan_Node_setDedicatedTxBuffersNumber(Ifx_CAN_N *node, uint8 number)
{
    node->TX.BC.B.NDTB = number;
}


IFX_INLINE void IfxCan_Node_setErrStateIndicator(Ifx_CAN_TXMSG *txBufferElement, boolean enable)
{
    txBufferElement->T0.B.ESI = enable ? 1 : 0;
}


IFX_INLINE void IfxCan_Node_setErrorStateIndicator(Ifx_CAN_N *node, Ifx_CAN_TXMSG *txBufferElement, boolean enable)
{
    IFX_UNUSED_PARAMETER(node);
    txBufferElement->T0.B.ESI = enable ? 1 : 0;
}


IFX_INLINE void IfxCan_Node_setMessageMarker(Ifx_CAN_TXMSG *txBufferElement, IfxCan_TxBufferId bufferId)
{
    txBufferElement->T1.B.MM0 = bufferId;
}


IFX_INLINE void IfxCan_Node_setMsgId(Ifx_CAN_TXMSG *txBufferElement, uint32 messageId, IfxCan_MessageIdLength messageIdLength)
{
    /* set identifier extention */
    txBufferElement->T0.B.XTD = (messageIdLength != IfxCan_MessageIdLength_extended) ? 0 : 1;
    /* set identifier */
    txBufferElement->T0.B.ID  = messageId << ((messageIdLength != IfxCan_MessageIdLength_standard) ? 0 : 18);
}


IFX_INLINE void IfxCan_Node_setMesssageId(Ifx_CAN_N *node, Ifx_CAN_TXMSG *txBufferElement, uint32 messageId, IfxCan_MessageIdLength messageIdLength)
{
    IFX_UNUSED_PARAMETER(node);
    /* set identifier extention */
    txBufferElement->T0.B.XTD = (messageIdLength != IfxCan_MessageIdLength_extended) ? 0 : 1;
    /* set identifier */
    txBufferElement->T0.B.ID  = messageId << ((messageIdLength != IfxCan_MessageIdLength_standard) ? 0 : 18);
}


IFX_INLINE void IfxCan_Node_setRemoteTransmitReq(Ifx_CAN_TXMSG *txBufferElement, boolean enable)
{
    txBufferElement->T0.B.RTR = enable ? 1 : 0;
}


IFX_INLINE void IfxCan_Node_setRemoteTransmitRequest(Ifx_CAN_N *node, Ifx_CAN_TXMSG *txBufferElement, boolean enable)
{
    IFX_UNUSED_PARAMETER(node);
    txBufferElement->T0.B.RTR = enable ? 1 : 0;
}


IFX_INLINE void IfxCan_Node_setTransmitFifoQueueMode(Ifx_CAN_N *node, IfxCan_TxMode mode)
{
    if ((mode == IfxCan_TxMode_fifo) || (mode == IfxCan_TxMode_queue))
    {
        node->TX.BC.B.TFQM = mode;
    }
    else
    {
        IFX_ASSERT(IFX_VERBOSE_LEVEL_ERROR, FALSE); /* wrong selection  */
    }
}


IFX_INLINE void IfxCan_Node_setTransmitFifoQueueSize(Ifx_CAN_N *node, uint8 number)
{
    node->TX.BC.B.TFQS = number;
}


IFX_INLINE void IfxCan_Node_setTxBufferAddRequest(Ifx_CAN_N *node, IfxCan_TxBufferId txBufferId)
{
    uint32 mask = (1U << txBufferId);
    node->TX.BAR.U = node->TX.BAR.U | (mask);
}


IFX_INLINE void IfxCan_Node_setTxBufferCancellationRequest(Ifx_CAN_N *node, IfxCan_TxBufferId txBufferId)
{
    uint32 mask = (1U << txBufferId);
    node->TX.BCR.U = node->TX.BCR.U | (mask);
}


IFX_INLINE void IfxCan_Node_setTxBufferDataFieldSize(Ifx_CAN_N *node, IfxCan_DataFieldSize size)
{
    node->TX.ESC.B.TBDS = size;
}


IFX_INLINE void IfxCan_Node_setTxBuffersStartAddress(Ifx_CAN_N *node, uint16 address)
{
    node->TX.BC.B.TBSA = address >> 2;
}


IFX_INLINE void IfxCan_Node_setTxEventFifoCtrl(Ifx_CAN_TXMSG *txBufferElement, boolean enable)
{
    txBufferElement->T1.B.EFC = enable ? 1 : 0;
}


IFX_INLINE void IfxCan_Node_setTxEventFifoControl(Ifx_CAN_N *node, Ifx_CAN_TXMSG *txBufferElement, boolean enable)
{
    IFX_UNUSED_PARAMETER(node);
    txBufferElement->T1.B.EFC = enable ? 1 : 0;
}


IFX_INLINE void IfxCan_Node_setTxEventTimeStampCaptureEnable(Ifx_CAN_TXMSG *txBufferElement, boolean enable)
{
    txBufferElement->T1.B.TSCE = enable ? 1 : 0;
}


IFX_INLINE uint32 IfxCan_Node_getDataLengthCode(Ifx_CAN_RXMSG *rxBufferElement)
{
    return (IfxCan_DataLengthCode)rxBufferElement->R1A.B.DLC;
}


IFX_INLINE uint32 IfxCan_Node_getMesssageId(Ifx_CAN_RXMSG *rxBufferElement)
{
    /* get identifier extention */
    IfxCan_MessageIdLength messageIdLength = (IfxCan_MessageIdLength)rxBufferElement->R0.B.XTD;

    /* get identifier */
    return rxBufferElement->R0.B.ID >> ((messageIdLength != IfxCan_MessageIdLength_standard) ? 0 : 18);
}


IFX_INLINE uint8 IfxCan_Node_getRxFifo0FillLevel(Ifx_CAN_N *node)
{
    return node->RX.F0S.B.F0FL;
}


IFX_INLINE IfxCan_RxBufferId IfxCan_Node_getRxFifo0GetIndex(Ifx_CAN_N *node)
{
    return (IfxCan_RxBufferId)node->RX.F0S.B.F0GI;
}


IFX_INLINE uint8 IfxCan_Node_getRxFifo1FillLevel(Ifx_CAN_N *node)
{
    return node->RX.F1S.B.F1FL;
}


IFX_INLINE IfxCan_RxBufferId IfxCan_Node_getRxFifo1GetIndex(Ifx_CAN_N *node)
{
    return (IfxCan_RxBufferId)node->RX.F1S.B.F1GI;
}


IFX_INLINE void IfxCan_Node_setRxBufferDataFieldSize(Ifx_CAN_N *node, IfxCan_DataFieldSize size)
{
    node->RX.ESC.B.RBDS = size;
}


IFX_INLINE void IfxCan_Node_setRxBuffersStartAddress(Ifx_CAN_N *node, uint16 address)
{
    node->RX.BC.B.RBSA = address >> 2;
}


IFX_INLINE void IfxCan_Node_setRxFifo0AcknowledgeIndex(Ifx_CAN_N *node, IfxCan_RxBufferId RxBufferNumber)
{
    node->RX.F0A.B.F0AI = RxBufferNumber;
}


IFX_INLINE void IfxCan_Node_setRxFifo0DataFieldSize(Ifx_CAN_N *node, IfxCan_DataFieldSize size)
{
    node->RX.ESC.B.F0DS = size;
}


IFX_INLINE void IfxCan_Node_setRxFifo0OperatingMode(Ifx_CAN_N *node, IfxCan_RxFifoMode mode)
{
    node->RX.F0C.B.F0OM = mode;
}


IFX_INLINE void IfxCan_Node_setRxFifo0Size(Ifx_CAN_N *node, uint8 size)
{
    node->RX.F0C.B.F0S = size;
}


IFX_INLINE void IfxCan_Node_setRxFifo0StartAddress(Ifx_CAN_N *node, uint16 address)
{
    node->RX.F0C.B.F0SA = address >> 2;
}


IFX_INLINE void IfxCan_Node_setRxFifo0WatermarkLevel(Ifx_CAN_N *node, uint8 level)
{
    node->RX.F0C.B.F0WM = level;
}


IFX_INLINE void IfxCan_Node_setRxFifo1AcknowledgeIndex(Ifx_CAN_N *node, IfxCan_RxBufferId RxBufferNumber)
{
    node->RX.F1A.B.F1AI = RxBufferNumber;
}


IFX_INLINE void IfxCan_Node_setRxFifo1DataFieldSize(Ifx_CAN_N *node, IfxCan_DataFieldSize size)
{
    node->RX.ESC.B.F1DS = size;
}


IFX_INLINE void IfxCan_Node_setRxFifo1OperatingMode(Ifx_CAN_N *node, IfxCan_RxFifoMode mode)
{
    node->RX.F1C.B.F1OM = mode;
}


IFX_INLINE void IfxCan_Node_setRxFifo1Size(Ifx_CAN_N *node, uint8 size)
{
    node->RX.F1C.B.F1S = size;
}


IFX_INLINE void IfxCan_Node_setRxFifo1StartAddress(Ifx_CAN_N *node, uint16 address)
{
    node->RX.F1C.B.F1SA = address >> 2;
}


IFX_INLINE void IfxCan_Node_setRxFifo1WatermarkLevel(Ifx_CAN_N *node, uint8 level)
{
    node->RX.F1C.B.F1WM = level;
}


IFX_INLINE void IfxCan_Node_acceptRemoteFramesWithStandardId(Ifx_CAN_N *node)
{
    node->GFC.B.RRFS = 0U;
}


IFX_INLINE void IfxCan_Node_acceptRemoteFrameswithExtendedId(Ifx_CAN_N *node)
{
    node->GFC.B.RRFE = 0U;
}


IFX_INLINE void IfxCan_Node_configureExtendedFilterForNonMatchingFrames(Ifx_CAN_N *node, IfxCan_NonMatchingFrame filter)
{
    node->GFC.B.ANFE = filter;
}


IFX_INLINE void IfxCan_Node_configureStandardFilterForNonMatchingFrames(Ifx_CAN_N *node, IfxCan_NonMatchingFrame filter)
{
    node->GFC.B.ANFS = filter;
}


IFX_INLINE void IfxCan_Node_rejectRemoteFramesWithExtendedId(Ifx_CAN_N *node)
{
    node->GFC.B.RRFE = 1U;
}


IFX_INLINE void IfxCan_Node_rejectRemoteFramesWithStandardId(Ifx_CAN_N *node)
{
    node->GFC.B.RRFS = 1U;
}


IFX_INLINE void IfxCan_Node_setExtendedFilterConfiguration(Ifx_CAN_EXTMSG *extendedFilterElement, IfxCan_FilterElementConfiguration filterElementConfiguration)
{
    extendedFilterElement->F0.B.EFEC = filterElementConfiguration;
}


IFX_INLINE void IfxCan_Node_setExtendedFilterId1(Ifx_CAN_EXTMSG *extendedFilterElement, uint32 id)
{
    extendedFilterElement->F0.B.EFID1 = id;
}


IFX_INLINE void IfxCan_Node_setExtendedFilterId2(Ifx_CAN_EXTMSG *extendedFilterElement, uint32 id)
{
    extendedFilterElement->F1.B.EFID2 = id;
}


IFX_INLINE void IfxCan_Node_setExtendedFilterListSize(Ifx_CAN_N *node, uint8 size)
{
    node->XIDFC.B.LSE = size;
}


IFX_INLINE void IfxCan_Node_setExtendedFilterListStartAddress(Ifx_CAN_N *node, uint16 address)
{
    node->XIDFC.B.FLESA = address >> 2;
}


IFX_INLINE void IfxCan_Node_setExtendedFilterRxBufferOffset(Ifx_CAN_EXTMSG *extendedFilterElement, IfxCan_RxBufferId rxBufferNumber)
{
    extendedFilterElement->F1.B.EFID2 = (uint8)rxBufferNumber;
}


IFX_INLINE void IfxCan_Node_setExtendedFilterType(Ifx_CAN_EXTMSG *extendedFilterElement, IfxCan_XtdFilterType filterType)
{
    extendedFilterElement->F1.B.EFT = filterType;
}


IFX_INLINE void IfxCan_Node_setStandardFilterConfiguration(Ifx_CAN_STDMSG *standardFilterElement, IfxCan_FilterElementConfiguration filterElementConfiguration)
{
    standardFilterElement->S0.B.SFEC = filterElementConfiguration;
}


IFX_INLINE void IfxCan_Node_setStandardFilterId1(Ifx_CAN_STDMSG *standardFilterElement, uint32 id)
{
    standardFilterElement->S0.B.SFID1 = id;
}


IFX_INLINE void IfxCan_Node_setStandardFilterId2(Ifx_CAN_STDMSG *standardFilterElement, uint32 id)
{
    standardFilterElement->S0.B.SFID2 = id;
}


IFX_INLINE void IfxCan_Node_setStandardFilterListSize(Ifx_CAN_N *node, uint8 size)
{
    node->SIDFC.B.LSS = size;
}


IFX_INLINE void IfxCan_Node_setStandardFilterListStartAddress(Ifx_CAN_N *node, uint16 address)
{
    node->SIDFC.B.FLSSA = address >> 2;
}


IFX_INLINE void IfxCan_Node_setStandardFilterRxBufferOffset(Ifx_CAN_STDMSG *standardFilterElement, IfxCan_RxBufferId rxBufferNumber)
{
    standardFilterElement->S0.B.SFID2 = (uint8)rxBufferNumber;
}


IFX_INLINE void IfxCan_Node_setStandardFilterType(Ifx_CAN_STDMSG *standardFilterElement, IfxCan_StdFilterType filterType)
{
    standardFilterElement->S0.B.SFT = filterType;
}


IFX_INLINE void IfxCan_Node_clearInterruptFlag(Ifx_CAN_N *node, IfxCan_Interrupt interrupt)
{
    uint32 value = (1U << interrupt);
    node->IR.U = value; /*Interrupt clear on write of 1 to corresponding bit*/
}


IFX_INLINE void IfxCan_Node_disableInterrupt(Ifx_CAN_N *node, IfxCan_Interrupt interrupt)
{
    uint32 mask = (1U << interrupt);
    node->IE.U = node->IE.U & ~(mask);
}


IFX_INLINE void IfxCan_Node_disableTxBufferCancellationFinishedInterrupt(Ifx_CAN_N *node, IfxCan_TxBufferId txBufferId)
{
    uint32 mask = (1U << txBufferId);
    node->TX.BCIE.U = node->TX.BCIE.U & ~(mask);
}


IFX_INLINE void IfxCan_Node_disableTxBufferTransmissionInterrupt(Ifx_CAN_N *node, IfxCan_TxBufferId txBufferId)
{
    uint32 mask = (1U << txBufferId);
    node->TX.BTIE.U = node->TX.BTIE.U & ~(mask);
}


IFX_INLINE void IfxCan_Node_enableInterrupt(Ifx_CAN_N *node, IfxCan_Interrupt interrupt)
{
    uint32 mask = (1U << interrupt);
    node->IE.U = node->IE.U | (mask);
}


IFX_INLINE void IfxCan_Node_enableTxBufferCancellationFinishedInterrupt(Ifx_CAN_N *node, IfxCan_TxBufferId txBufferId)
{
    uint32 mask = (1U << txBufferId);
    node->TX.BCIE.U = node->TX.BCIE.U | (mask);
}


IFX_INLINE void IfxCan_Node_enableTxBufferTransmissionInterrupt(Ifx_CAN_N *node, IfxCan_TxBufferId txBufferId)
{
    uint32 mask = (1U << txBufferId);
    node->TX.BTIE.U = node->TX.BTIE.U | (mask);
}


IFX_INLINE boolean IfxCan_Node_getInterruptFlagStatus(Ifx_CAN_N *node, IfxCan_Interrupt interrupt)
{
    uint32  mask   = (1U << interrupt);
    boolean status = (node->IR.U & mask) != 0;
    return status;
}


IFX_INLINE Ifx_CAN_N *IfxCan_getNodePointer(Ifx_CAN *can, IfxCan_NodeId nodeId)
{
    return &(can->N[nodeId]);
}


IFX_INLINE boolean IfxCan_isModuleEnabled(Ifx_CAN *can)
{
    return can->CLC.B.DISS == 0;
}


IFX_INLINE boolean IfxCan_isModuleSuspended(Ifx_CAN *can)
{
    Ifx_CAN_OCS ocs;

    // read the status
    ocs.U = can->OCS.U;

    // return the status
    return ocs.B.SUSSTA;
}


IFX_INLINE void IfxCan_setSleepMode(Ifx_CAN *can, IfxCan_SleepMode mode)
{
#if (IFX_PROT_ENABLED == 1U)
    IfxApProt_setState((Ifx_PROT_PROT *)&(can->PROTE), IfxApProt_State_config);
#endif
    can->CLC.B.EDIS = mode;
#if (IFX_PROT_ENABLED == 1U)
    IfxApProt_setState((Ifx_PROT_PROT *)&(can->PROTE), IfxApProt_State_run);
#endif
}


IFX_INLINE void IfxCan_setSuspendMode(Ifx_CAN *can, IfxCan_SuspendMode mode)
{
    Ifx_CAN_OCS ocs;

    // remove protection and configure the suspend mode.
    ocs.B.SUS_P = 1;
    ocs.B.SUS   = mode;
    can->OCS.U  = ocs.U;
}


IFX_INLINE boolean IfxCan_Node_getBRSFromTxEventFifo(Ifx_CAN_TXEVENT *txEventFifoElement)
{
    return txEventFifoElement->E1A.B.BRS;
}


IFX_INLINE uint32 IfxCan_Node_getDLCFromTxEventFifo(Ifx_CAN_TXEVENT *txEventFifoElement)
{
    return (IfxCan_DataLengthCode)txEventFifoElement->E1A.B.DLC;
}


IFX_INLINE boolean IfxCan_Node_getESIFromTxEventFifo(Ifx_CAN_TXEVENT *txEventFifoElement)
{
    return txEventFifoElement->E0.B.ESI;
}


IFX_INLINE boolean IfxCan_Node_getFDFFromTxEventFifo(Ifx_CAN_TXEVENT *txEventFifoElement)
{
    return txEventFifoElement->E1A.B.FDF;
}


IFX_INLINE uint8 IfxCan_Node_getMMFromTxEventFifo(Ifx_CAN_TXEVENT *txEventFifoElement)
{
    return (uint8)txEventFifoElement->E1A.B.MM;
}


IFX_INLINE uint32 IfxCan_Node_getMesssageIdFromTxEventFifo(Ifx_CAN_TXEVENT *txEventFifoElement)
{
    /* get identifier extention */
    IfxCan_MessageIdLength messageIdLength = (IfxCan_MessageIdLength)txEventFifoElement->E0.B.XTD;

    /* get identifier */
    return txEventFifoElement->E0.B.ID >> ((messageIdLength != IfxCan_MessageIdLength_standard) ? 0 : 18);
}


IFX_INLINE boolean IfxCan_Node_getRTRFromTxEventFifo(Ifx_CAN_TXEVENT *txEventFifoElement)
{
    return txEventFifoElement->E0.B.RTR;
}


IFX_INLINE uint16 IfxCan_Node_getTXTSFromTxEventFifo(Ifx_CAN_TXEVENT *txEventFifoElement)
{
    return (uint16)txEventFifoElement->E1A.B.TXTS;
}


IFX_INLINE uint8 IfxCan_Node_getTxEventFifoAcknowledgeIndex(Ifx_CAN_N *node)
{
    return (uint8)node->TX.EFA.B.EFAI;
}


IFX_INLINE uint8 IfxCan_Node_getTxEventFifoFillLevel(Ifx_CAN_N *node)
{
    return (uint8)node->TX.EFS.B.EFFL;
}


IFX_INLINE uint8 IfxCan_Node_getTxEventFifoGetIndex(Ifx_CAN_N *node)
{
    return (uint8)node->TX.EFS.B.EFGI;
}


IFX_INLINE uint8 IfxCan_Node_getTxEventFifoPutIndex(Ifx_CAN_N *node)
{
    return (uint8)node->TX.EFS.B.EFPI;
}


IFX_INLINE uint8 IfxCan_Node_getTxEventFifoSize(Ifx_CAN_N *node)
{
    return (uint8)node->TX.EFC.B.EFS;
}


IFX_INLINE uint16 IfxCan_Node_getTxEventFifoStartAddress(Ifx_CAN_N *node)
{
    return (uint16)node->TX.EFC.B.EFSA;
}


IFX_INLINE uint8 IfxCan_Node_getTxEventFifoWatermarkLevel(Ifx_CAN_N *node)
{
    return (uint8)node->TX.EFC.B.EFWM;
}


IFX_INLINE boolean IfxCan_Node_isTxEventFifoElementLost(Ifx_CAN_N *node)
{
    return node->TX.EFS.B.TEFL;
}


IFX_INLINE boolean IfxCan_Node_isTxEventFifoFull(Ifx_CAN_N *node)
{
    return node->TX.EFS.B.EFF;
}


IFX_INLINE void IfxCan_Node_setTxEventFifoSize(Ifx_CAN_N *node, uint8 size)
{
    node->TX.EFC.B.EFS = size;
}


IFX_INLINE void IfxCan_Node_setTxEventFifoStartAddress(Ifx_CAN_N *node, uint16 address)
{
    node->TX.EFC.B.EFSA = address >> 2;
}


IFX_INLINE void IfxCan_Node_setTxEventFifoWatermarkLevel(Ifx_CAN_N *node, uint8 level)
{
    node->TX.EFC.B.EFWM = level;
}


IFX_INLINE void IfxCan_Node_setTxEventFifoAcknowledgeIndex(Ifx_CAN_N *node, IfxCan_TxBufferId TxEventBufferNumber)
{
    node->TX.EFA.B.EFAI = TxEventBufferNumber;
}


IFX_INLINE boolean IfxCan_Node_isCanFDMsgReceived(Ifx_CAN_N *node)
{
    return node->PSR.B.RFDF;
}


IFX_INLINE void IfxCan_Node_setStandardFilterSync(Ifx_CAN_STDMSG *standardFilterElement, boolean enable)
{
    standardFilterElement->S0.B.SSYNC = enable;
}


IFX_INLINE void IfxCan_Node_setExtendedFilterSync(Ifx_CAN_EXTMSG *extendedFilterElement, boolean enable)
{
    extendedFilterElement->F1.B.ESYNC = enable;
}


IFX_INLINE void IfxCan_Node_enableUseTsu(Ifx_CAN_N *node)
{
    node->CCCR.B.UTSU = 1;
}


IFX_INLINE void IfxCan_Node_disableUseTsu(Ifx_CAN_N *node)
{
    node->CCCR.B.UTSU = 0;
}


IFX_INLINE void IfxCan_Node_enableTsu(Ifx_CAN_N *node)
{
    /* enable configuration change CCCR.CCE = 1, CCCR.INIT = 1 */
    IfxCan_Node_enableConfigurationChange(node);

    node->TSU.TSCFG.B.TSUE = 1;

    /* disable configuration change CCCR.CCE = 0, CCCR.INIT = 0 */
    IfxCan_Node_disableConfigurationChange(node);
}


IFX_INLINE void IfxCan_Node_disableTsu(Ifx_CAN_N *node)
{
    /* enable configuration change CCCR.CCE = 1, CCCR.INIT = 1 */
    IfxCan_Node_enableConfigurationChange(node);

    node->TSU.TSCFG.B.TSUE = 0;

    /* disable configuration change CCCR.CCE = 0, CCCR.INIT = 0 */
    IfxCan_Node_disableConfigurationChange(node);
}


IFX_INLINE void IfxCan_Node_setTsuInternalPrescalar(Ifx_CAN_N *node, uint8 prescalar)
{
    /* enable configuration change CCCR.CCE = 1, CCCR.INIT = 1 */
    IfxCan_Node_enableConfigurationChange(node);

    node->TSU.TSCFG.B.TBPRE = prescalar;

    /* disable configuration change CCCR.CCE = 0, CCCR.INIT = 0 */
    IfxCan_Node_disableConfigurationChange(node);
}


IFX_INLINE void IfxCan_Node_setTsuCapturePoint(Ifx_CAN_N *node, IfxCan_TsuTimeStampPosition position)
{
    /* enable configuration change CCCR.CCE = 1, CCCR.INIT = 1 */
    IfxCan_Node_enableConfigurationChange(node);

    node->TSU.TSCFG.B.SCP = position;

    /* disable configuration change CCCR.CCE = 0, CCCR.INIT = 0 */
    IfxCan_Node_disableConfigurationChange(node);
}


IFX_INLINE IfxCan_CreTimeStampCaptured IfxCan_Cre_getTimeStampCapturedStatus(Ifx_CAN_RHBUF *rxHostBuffer)
{
    return (IfxCan_CreTimeStampCaptured)rxHostBuffer->THEAD_INTRD.B.TSC;
}


IFX_INLINE IfxCan_CreTimeStampType IfxCan_Cre_getTimeStampLength(Ifx_CAN_RHBUF *rxHostBuffer)
{
    return (IfxCan_CreTimeStampType)rxHostBuffer->THEAD_INTRD.B.TSCLEN;
}


IFX_INLINE uint32 IfxCan_Cre_getTimeStamp(Ifx_CAN_RHBUF *rxHostBuffer)
{
    return rxHostBuffer->THEAD_RXTS.U;
}


IFX_INLINE IfxCan_InterArrivalMeasureStatus IfxCan_Cre_getIamStatus(Ifx_CAN_RHBUF *rxHostBuffer)
{
    return (IfxCan_InterArrivalMeasureStatus)rxHostBuffer->THEAD_INTRD.B.IAMSTAT;
}


IFX_INLINE uint16 IfxCan_Node_Cre_getThroughput(Ifx_CAN_N *node)
{
    return (uint16)node->IDMU.RXTPCFG.B.TP;
}


IFX_INLINE void IfxCan_Node_Cre_clearThroughput(Ifx_CAN_N *node)
{
    /*Set PROTE to config before use*/
    node->IDMU.RXTPCFG.B.TP = 0;
}


IFX_INLINE void IfxCan_Node_Cre_setStdFrameRateAddress(Ifx_CAN_N *node, uint16 address, uint32 ramAddress)
{
    uint32       creStartAddress = node->CRE.CONFIGADR.U;
    Ifx_CAN_CRE *creTableConfig  = (Ifx_CAN_CRE *)(ramAddress + creStartAddress);
    creTableConfig->STD_FRT_PARAM.B.SA = address >> 2;
}


IFX_INLINE void IfxCan_Node_Cre_setXtdFrameRateAddress(Ifx_CAN_N *node, uint16 address, uint32 ramAddress)
{
    uint32       creStartAddress = node->CRE.CONFIGADR.U;
    Ifx_CAN_CRE *creTableConfig  = (Ifx_CAN_CRE *)(ramAddress + creStartAddress);
    creTableConfig->STD_FRT_PARAM.B.SA = address >> 2;
}


IFX_INLINE uint32 IfxCan_Node_Cre_getStdFrameRateAddress(Ifx_CAN_N *node, uint32 ramAddress)
{
    uint32       creStartAddress = node->CRE.CONFIGADR.U;
    Ifx_CAN_CRE *creTableConfig  = (Ifx_CAN_CRE *)(ramAddress + creStartAddress);
    uint32       address         = ((creTableConfig->STD_FRT_PARAM.B.SA << 2) + ramAddress);
    return address;
}


IFX_INLINE uint32 IfxCan_Node_Cre_getXtdFrameRateAddress(Ifx_CAN_N *node, uint32 ramAddress)
{
    uint32       creStartAddress = node->CRE.CONFIGADR.U;
    Ifx_CAN_CRE *creTableConfig  = (Ifx_CAN_CRE *)(ramAddress + creStartAddress);
    uint32       address         = ((creTableConfig->XTD_FRT_PARAM.B.SA << 2) + ramAddress);
    return address;
}


IFX_INLINE void IfxCan_Node_Cre_setStdFrameRateSize(Ifx_CAN_N *node, IfxCan_StdFrameRateSize size, uint32 ramAddress)
{
    uint32       creStartAddress = node->CRE.CONFIGADR.U;
    Ifx_CAN_CRE *creTableConfig  = (Ifx_CAN_CRE *)(ramAddress + creStartAddress);
    creTableConfig->STD_FRT_PARAM.B.SIZE = size;
}


IFX_INLINE void IfxCan_Node_Cre_setXtdFrameRateSize(Ifx_CAN_N *node, IfxCan_XtdFrameRateSize size, uint32 ramAddress)
{
    uint32       creStartAddress = node->CRE.CONFIGADR.U;
    Ifx_CAN_CRE *creTableConfig  = (Ifx_CAN_CRE *)(ramAddress + creStartAddress);
    creTableConfig->XTD_FRT_PARAM.B.SIZE = size;
}


IFX_INLINE void IfxCan_Node_Cre_enableStdFrameRateLock(Ifx_CAN_N *node)
{
    /*Set PROTE to config before use*/
    node->IDMU.FRTCONFIG.B.STDLOCK = TRUE;
}


IFX_INLINE void IfxCan_Node_Cre_enableXtdFrameRateLock(Ifx_CAN_N *node)
{
    /*Set PROTE to config before use*/
    node->IDMU.FRTCONFIG.B.XTDLOCK = TRUE;
}


IFX_INLINE void IfxCan_Node_Cre_disableStdFrameRateLock(Ifx_CAN_N *node)
{
    /*Set PROTE to config before use*/
    node->IDMU.FRTCONFIG.B.STDLOCK = FALSE;
}


IFX_INLINE void IfxCan_Node_Cre_disableXtdFrameRateLock(Ifx_CAN_N *node)
{
    /*Set PROTE to config before use*/
    node->IDMU.FRTCONFIG.B.XTDLOCK = FALSE;
}


IFX_INLINE uint32 IfxCan_Node_getTsuTimeStamp(Ifx_CAN_N *node, IfxCan_TsuTimeStampIndex index)
{
    return node->TSU.TS[index].U;
}


IFX_INLINE boolean IfxCan_Node_getTsuTimeStampNewStatus(Ifx_CAN_N *node, IfxCan_TsuTimeStampIndex index)
{
    if (node->TSU.TSS1.U & (1 << index))
    {
        return TRUE; /*TSNz = 1*/
    }
    else
    {
        return FALSE; /*TSNz = 0*/
    }
}


IFX_INLINE boolean IfxCan_Node_getTsuTimeStampLostStatus(Ifx_CAN_N *node, IfxCan_TsuTimeStampIndex index)
{
    if (node->TSU.TSS1.U & (1 << (16 + index)))
    {
        return TRUE; /*TSLz = 1*/
    }
    else
    {
        return FALSE; /*TSLz = 0*/
    }
}


IFX_INLINE void IfxCan_Node_setTimerStartTxTrig0(Ifx_CAN_N *node, boolean enable)
{
    node->TIMER.TXTRIG0.B.STRT = enable;
}


IFX_INLINE void IfxCan_Node_setTimerStartTxTrig1(Ifx_CAN_N *node, boolean enable)
{
    node->TIMER.TXTRIG1.B.STRT = enable;
}


IFX_INLINE void IfxCan_Node_setTimerStartTxTrig2(Ifx_CAN_N *node, boolean enable)
{
    node->TIMER.TXTRIG2.B.STRT = enable;
}


IFX_INLINE uint16 IfxCan_Node_getWideMMFromTxEventFifo(Ifx_CAN_TXEVENT *txEventFifoElement)
{
    uint16 wideMessageMarker = (uint16)((txEventFifoElement->E1B.B.MM0) + ((txEventFifoElement->E1B.B.MM1) << 8));
    return wideMessageMarker;
}


IFX_INLINE uint8 IfxCan_Node_getValidTXTSPFromTxEventFifo(Ifx_CAN_TXEVENT *txEventFifoElement)
{
    if (txEventFifoElement->E1B.B.TSC)
    {
        return (uint8)txEventFifoElement->E1B.B.TXTSP;
    }
    else
    {
        return (uint8)0;
    }
}


IFX_INLINE void IfxCan_Node_setWideMessageMarker(Ifx_CAN_N *node, boolean enable)
{
    node->CCCR.B.WMM = enable;
}


IFX_INLINE void IfxCan_Node_setTxBufferDreSoftwareTrigger(Ifx_CAN_N *node)
{
    node->CRE.HBUF.TX[0].STAT.B.SWTRIG = 1; /* Note: Write to this bit is valid only for Tx Host buffer 0. SW write has no effect for Tx Host buffer 1 */
}


IFX_INLINE void IfxCan_Node_resetTxBufferWatchdogEventGroup(Ifx_CAN_N *node, IfxCan_CreTxHostBufferIndex txHostBufferIndex)
{
    node->CRE.HBUF.TX[txHostBufferIndex].STAT.B.WEG = 1;
}


IFX_INLINE void IfxCan_Node_resetRxBufferWatchdogEventGroup(Ifx_CAN_N *node, IfxCan_CreRxHostBufferIndex rxHostBufferIndex)
{
    node->CRE.HBUF.RX[rxHostBufferIndex].STAT.B.WEG = 1;
}


IFX_INLINE uint8 IfxCan_Node_getTxFifoFillLevel(Ifx_CAN_N *node)
{
    return node->TX.FQS.B.TFFL; /* returns number of consecutively free Tx FIFO elements */
}


IFX_INLINE void IfxCan_Node_setExtendedIdAndMask(Ifx_CAN_N *node, uint32 extendedIdAndMask)
{
    node->XIDAM.B.EIDM = extendedIdAndMask; /* sets extended ID and mask */
}


IFX_INLINE uint32 IfxCan_Node_getInterruptSignallingStatus(Ifx_CAN_N *node)
{
    return node->INTRSIG.U;
}


IFX_INLINE uint8 IfxCan_Node_getTsuTimeStampPointer(Ifx_CAN_N *node)
{
    return node->TSU.TSS2.B.TSP;
}


IFX_INLINE uint32 IfxCan_Node_getTsuActualTimebase(Ifx_CAN_N *node)
{
    return node->TSU.ATB.U;
}


IFX_INLINE void IfxCan_Node_setTsuActualTimebase(Ifx_CAN_N *node, uint32 actualTimebase)
{
    node->TSU.ATB.U = actualTimebase;
}


#endif /* IFXCAN_H */
