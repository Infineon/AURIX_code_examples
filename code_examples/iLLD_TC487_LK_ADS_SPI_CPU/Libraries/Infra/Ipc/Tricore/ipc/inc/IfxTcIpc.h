/**
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

#ifndef TRICOREIPC_H
#define TRICOREIPC_H 1

#include "IfxMailbox.h"
#include "IfxCpu_cfg.h"

#ifndef IFXTCIPC_MAX_NUM_SERVICES
#define IFXTCIPC_MAX_NUM_SERVICES 1u
#endif
/** \brief Interrupt priority for TC0
 */
#define IFX_INTPRIO_IPC_TC0 1

/** \brief Interrupt priority for TC1
 */
#if (IFXCPU_NUM_SAFE_MODULES >= 2U) 
#define IFX_INTPRIO_IPC_TC1 1
#endif

/** \brief Interrupt priority for TC2
 */
#if (IFXCPU_NUM_SAFE_MODULES >= 3U)  
#define IFX_INTPRIO_IPC_TC2 1
#endif

/** \brief Interrupt priority for TC3
 */
#if (IFXCPU_NUM_SAFE_MODULES >= 4U)  
#define IFX_INTPRIO_IPC_TC3 1
#endif

/** \brief Interrupt priority for TC4
 */
#if (IFXCPU_NUM_SAFE_MODULES >= 5U)  
#define IFX_INTPRIO_IPC_TC4 1
#endif

/** \brief Interrupt priority for TC5
 */
#if (IFXCPU_NUM_SAFE_MODULES >= 6U)   
#define IFX_INTPRIO_IPC_TC5 1
#endif

/** \brief Interrupt priority for PPU ICI
 */
#define IFX_INTPRIO_C2S 23

/** \brief Remote Procedure call API which is used to access the PPUC Service
 * This will first try to lock the PPU for the specific TCx.
 * If the Lock is acquired it will then fill the mailbox and trigger the PPUs service
 * \param kernel_id The specific PPU Kernel service to be requested
 * \param arg_cnt The number of arguments
 * \param *args[] Pointer to the arguments
 * \return Returns the status as 0 for Success or others if not successful
 */
IfxMailbox_Status IfxTcIpc_Rpc(unsigned int id, unsigned int arg_cnt, int *args[]);

/** \brief API to initialize the S2C interrupt for TC0
 */
void IfxTcIpc_initS2CInterruptTc0(void);

/** \brief API to initialize the S2C interrupt for TC1
 */
#if (IFXCPU_NUM_SAFE_MODULES >= 2U) 
void IfxTcIpc_initS2CInterruptTc1(void);
#endif

/** \brief API to initialize the S2C interrupt for TC2
 */
 #if (IFXCPU_NUM_SAFE_MODULES >= 3U) 
void IfxTcIpc_initS2CInterruptTc2(void);
#endif

/** \brief API to initialize the S2C interrupt for TC3
 */
#if (IFXCPU_NUM_SAFE_MODULES >= 4U)  
void IfxTcIpc_initS2CInterruptTc3(void);
#endif

/** \brief API to initialize the S2C interrupt for TC4
 */
#if (IFXCPU_NUM_SAFE_MODULES >= 5U)   
void IfxTcIpc_initS2CInterruptTc4(void);
#endif

/** \brief API to initialize the S2C interrupt for TC5
 */
#if (IFXCPU_NUM_SAFE_MODULES >= 6U)    
void IfxTcIpc_initS2CInterruptTc5(void);
#endif

#endif /* TRICOREIPC_H_ */
