/**
 * \file IfxMailBox.h
 *
 * \version iLLD-TC4-v2.6.0
 * \copyright Copyright (c) 2026 Infineon Technologies AG. All rights reserved.
 *
 *
 *                                 IMPORTANT NOTICE
 *
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
 */

#ifndef IFX_MAILBOX_H
#define IFX_MAILBOX_H

#include "Ifx_Cfg.h"
#include "IfxCpu_cfg.h"

#define COMMAND_OFFSET   (0)
#define STATUS_OFFSET    (COMMAND_OFFSET + 4)
#define KERNEL_ID_OFFSET (STATUS_OFFSET + 4)
#define ARG_COUNT_OFFSET (KERNEL_ID_OFFSET + 4)
#define FIRST_ARG_OFFSET (ARG_COUNT_OFFSET + 4)

#if defined(DEVICE_TC4DX) || defined(DEVICE_TC49XN) || defined(DEVICE_TC4ZX)

/** \brief TC0 Mailbox
 */
#define TRICORE_0_REQUEST_MAILBOX  (0xB0680200)

/** \brief TC1 Mailbox
 */
#if (IFXCPU_NUM_SAFE_MODULES >= 2U)
#define TRICORE_1_REQUEST_MAILBOX  (0xB0680400)
#endif

/** \brief TC2 Mailbox
 */
#if (IFXCPU_NUM_SAFE_MODULES >= 3U)
#define TRICORE_2_REQUEST_MAILBOX  (0xB0680600)
#endif

/** \brief TC3 Mailbox
 */
#if (IFXCPU_NUM_SAFE_MODULES >= 4U)
#define TRICORE_3_REQUEST_MAILBOX  (0xB0680800)
#endif

/** \brief TC4 Mailbox
 */
#if (IFXCPU_NUM_SAFE_MODULES >= 5U)
#define TRICORE_4_REQUEST_MAILBOX  (0xB0680A00)
#endif

/** \brief TC5 Mailbox
 */
#if (IFXCPU_NUM_SAFE_MODULES >= 6U)
#define TRICORE_5_REQUEST_MAILBOX  (0xB0680C00)
#endif

/** \brief TC6 Mailbox
 */
#define TRICORE_6_HANDSHAKE_MAILBOX  (0xB0681000)

/** \brief PPU Mailbox
 */
#define PPU_STATUS_MAILBOX         (0xB0680E00)

#elif defined(DEVICE_TC45X) || defined(DEVICE_TC48X) || defined(DEVICE_TC48XAA) || defined(DEVICE_TC44X) || defined(DEVICE_TC42X) ||\
	  defined(DEVICE_TC4SX) || defined(DEVICE_TC4PX) || defined(DEVICE_TC4EX)
/** \brief TC0 Mailbox
 */
#define TRICORE_0_REQUEST_MAILBOX  (0xB000F200)

/** \brief TC1 Mailbox
 */
#if (IFXCPU_NUM_SAFE_MODULES >= 2U)
#define TRICORE_1_REQUEST_MAILBOX  (0xB000F400)
#endif

/** \brief TC2 Mailbox
 */
#if (IFXCPU_NUM_SAFE_MODULES >= 3U)
#define TRICORE_2_REQUEST_MAILBOX  (0xB000F600)
#endif

/** \brief TC3 Mailbox
 */
#if (IFXCPU_NUM_SAFE_MODULES >= 4U)
#define TRICORE_3_REQUEST_MAILBOX  (0xB000F800)
#endif

/** \brief TC6 Mailbox
 */
#define TRICORE_6_HANDSHAKE_MAILBOX  (0xB000FC00)

/** \brief PPU Mailbox
 */
#define PPU_STATUS_MAILBOX         (0xB001C000)

#elif defined(DEVICE_TC46X)

/** \brief TC0 Mailbox
 */
#define TRICORE_0_REQUEST_MAILBOX  (0xB047F200)

/** \brief TC1 Mailbox
 */
#define TRICORE_1_REQUEST_MAILBOX  (0xB047F400)

/** \brief TC2 Mailbox
 */
#define TRICORE_2_REQUEST_MAILBOX  (0xB047F600)

/** \brief TC3 Mailbox
 */
#define TRICORE_3_REQUEST_MAILBOX  (0xB047F800)


/** \brief TC5 Mailbox
 */
#define TRICORE_6_HANDSHAKE_MAILBOX  (0xB047FA00)

/** \brief PPU Mailbox
 */
#define PPU_STATUS_MAILBOX         (0xB001C000)

#else
#error "Device not defined in Ifx_Cfg.h file."
#endif

/** \brief MAX Args
 */
#define MAX_ARGS (10)

/** \brief Num of Cores
 */
#define MAX_NUM_CORES IFXCPU_NUM_SAFE_MODULES

/** \brief OPEN CL Mode
 */
#define OPEN_CL_MODE 1

/** \brief if defined, the interrupt from Server to Client is configured as the notifier, if not, the field NewMessageAvail in fifo struct is the notifier
 */
//#define S2C_INTERRUPT_NOTIFICATION 1

/** \brief PPUC Status
 */
typedef enum
{
	IfxMailBox_PpucStatus_busy =0U,
	IfxMailBox_PpucStatus_ready,
	IfxMailBox_PpucStatus_free
}IfxMailBox_PpucStatus;

/** \brief Status of the operation/service
 */
typedef enum
{
	IfxMailbox_Status_requestDone=0U,
	IfxMailbox_Status_requestInProgress,
	IfxMailbox_Status_successful,
	IfxMailbox_Status_notsuccessful,
	IfxMailbox_Status_tryLater
}IfxMailbox_Status;

/** \brief New command or not
 */
typedef enum
{
	IfxMailbox_Command_none=0U,
	IfxMailbox_Command_new
}IfxMailbox_Command;

/** \brief Mailbox structure
 */
typedef struct
{
	unsigned int command;
	unsigned int status;
	unsigned int id;
	unsigned int num_args;
	int *args[MAX_ARGS];
}IfxMailbox;

#endif /* COMMON_MBX_H_ */ 
