/**
 * \file IfxPms_cfg_TC37x.h
 * \brief PMS on-chip implementation data
 * \ingroup IfxLld_Pms
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
 * \defgroup IfxLld_Pms PMS
 * \ingroup IfxLld
 * \defgroup IfxLld_Pms_Impl Implementation
 * \ingroup IfxLld_Pms
 * \defgroup IfxLld_Pms_Std Pm and Evr Drivers
 * \ingroup IfxLld_Pms
 */

#ifndef IFXPMS_CFG_TC397X_H
#define IFXPMS_CFG_TC397X_H 1

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include "Ifx_Cfg.h"

/******************************************************************************/
/*-----------------------------------Macros-----------------------------------*/
/******************************************************************************/

#define IFXPMS_STANDBY_CPU0_DLMU_RAR_AREA (0x90000000U)

#define IFXPMS_STANDBY_DLMU_RAR_SIZE      (16U /* in words (32 bit) */)

#define IFXPMS_STANDBY_CPU1_DLMU_RAR_AREA (0x90010000U)

#define IFXPMS_NUM_MODULES                (1)

/** \brief This macro is intended to be defined in Ifx_Cfg.h and is meant to cut off the clock supply to desired modules by writing to their respective CLC.B.DISR or CLC.B.EDIS
 * It is used in IfxPmsPm_startSleepSequenceinFlash().
 * This macro is empty by default.For example:
 *
 *
 * Example usage:
 * #define IFXPMS_DISABLE_MODULES_DURING_SLEEP          \
 * {                                                      \
 *     uint16 passwd = IfxScuWdt_getCpuWatchdogPassword();\
 *     IfxScuWdt_clearCpuEndinit(passwd);                 \
 *     MODULE_ASCLIN.CLC.B.DISR = 1;                      \
 *          MODULE_EVADC.CLC.B.DISR = 1;                        \
 *          MODULE_EDSADC.CLC.B.DISR = 1;                       \
 *     IfxScuWdt_setCpuEndinit(passwd);                   \
 * }
 */
#ifndef IFXPMS_DISABLE_MODULES_DURING_SLEEP
#define IFXPMS_DISABLE_MODULES_DURING_SLEEP
#endif

/** \brief This macro is intended to be defined in Ifx_Cfg.h and is meant to cut off the clock supply to desired modules by writing to their respective CLC.B.DISR or CLC.B.EDIS.
 * It is used in IfxPmsPm_startStandbySequenceInFlash().
 *
 * This macro is empty by default.For example:
 *
 *
 * Example usage:
 * #define IFXPMS_DISABLE_ALL_MODULES_STANDBY          \
 * {                                                      \
 *     uint16 passwd = IfxScuWdt_getCpuWatchdogPassword();\
 *     IfxScuWdt_clearCpuEndinit(passwd);                 \
 *     MODULE_ASCLIN.CLC.B.DISR = 1;                      \
 *          MODULE_EVADC.CLC.B.DISR = 1;                        \
 *          MODULE_EDSADC.CLC.B.DISR = 1;                       \
 *     IfxScuWdt_setCpuEndinit(passwd);                   \
 * }
 */
#ifndef IFXPMS_DISABLE_ALL_MODULES_STANDBY
#define IFXPMS_DISABLE_ALL_MODULES_STANDBY
#endif

/** \brief This macro is intended to be defined in Ifx_Cfg.h and is meant to restore the clock supply to desired modules by writing to their respective CLC.B.DISR.
 * This is used in IfxPmsPm_initiateWakeup()
 * This macro is empty by default.For example:
 *
 *
 * Example usage:
 * #define IFXPMS_WAKEUP_MODULES         \
 * {                                                      \
 *     uint16 passwd = IfxScuWdt_getCpuWatchdogPassword();\
 *     IfxScuWdt_clearCpuEndinit(passwd);                 \
 *     MODULE_ASCLIN.CLC.B.DISR = 0;                      \
 *          MODULE_EVADC.CLC.B.DISR = 0;                        \
 *          MODULE_EDSADC.CLC.B.DISR = 0;                       \
 *     IfxScuWdt_setCpuEndinit(passwd);                   \
 * }
 */
#ifndef IFXPMS_WAKEUP_MODULES
#define IFXPMS_WAKEUP_MODULES
#endif

/** \brief This macro is intended to be defined in Ifx_Cfg.h and is meant to contain any activity the application might need to do after wakeup.
 * This can be done here in this macro or after the control returns from IfxPmsPm_initiateWakeup()
 * This macro is empty by default.
 */
#ifndef IFXPMS_RESTART_EXECUTION
#define IFXPMS_RESTART_EXECUTION
#endif

/** \brief Number of cycles to wait after switching to backup clock is triggered before shutting down the oscillator.
 * This is given as a configurable macro because the value required has been seen to vary and so the application may define it in Ifx_Cfg.h.
 */
#ifndef IFXPMS_WAIT_CYCLES
#define IFXPMS_WAIT_CYCLES 100
#endif

#endif /* IFXPMS_CFG_TC397X_H */
