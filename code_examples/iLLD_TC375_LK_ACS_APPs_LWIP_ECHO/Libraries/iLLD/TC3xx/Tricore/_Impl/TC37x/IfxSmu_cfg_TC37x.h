/**
 * \file IfxSmu_cfg_TC37x.h
 * \brief Smu on-chip implementation data
 * \ingroup IfxLld_Smu
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
 * \defgroup IfxLld_Smu SMU
 * \ingroup IfxLld
 * \defgroup IfxLld_Smu_Impl Implementation
 * \ingroup IfxLld_Smu
 * \defgroup IfxLld_Smu_Std Standard Driver
 * \ingroup IfxLld_Smu
 * \defgroup IfxLld_Smu_Impl_Enum_AlarmGroup Alarm Group Enumeration
 * \ingroup IfxLld_Smu_Impl
 * \defgroup IfxLld_Smu_Impl_Enum_ListAlarms List of Alarms Enumeration
 * \ingroup IfxLld_Smu_Impl
 */

#ifndef IFXSMU_CFG_TC37X_H
#define IFXSMU_CFG_TC37X_H 1

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include "Cpu/Std/Ifx_Types.h"

/******************************************************************************/
/*-----------------------------------Macros-----------------------------------*/
/******************************************************************************/

/** \brief Number of SMU Alarm Groups
 */
#define  IFXSMU_NUM_ALARM_GROUPS (12)

/******************************************************************************/
/*-------------------------------Enumerations---------------------------------*/
/******************************************************************************/

/** \brief SMU Alarms
 */
typedef enum
{
    IfxSmu_Alarm_CPU0_Lockstep_ComparatorError                            = 0,   /**< \brief ALM0[0] : Safety Mechanism: Lockstep CPU Alarm: Lockstep Comparator Error*/
    IfxSmu_Alarm_CPU0_Buslevel_MpuViolation                               = 1,   /**< \brief ALM0[1] : Safety Mechanism: Bus-level Memory Protection Unit Alarm: Bus-level MPU violation.*/
    IfxSmu_Alarm_CPU0_PFI0_PFLASH0_ReadPathError                          = 2,   /**< \brief ALM0[2] : Safety Mechanism: PFLASH Read Path Monitor Alarm: PFLASH0 Read Path Error*/
    IfxSmu_Alarm_CPU0_PCACHETAG_UncorrectableErrorDetection     		  = 4,   /**< \brief ALM0[4] : Safety Mechanism: SRAM Monitor  Alarm: PCACHE TAG Uncorrectable  error detection*/
    IfxSmu_Alarm_CPU0_PCACHETAG_MiscellaneousErrorDetection               = 5,   /**< \brief ALM0[5] : Safety Mechanism: SRAM Monitor Alarm: PCACHE TAG Miscellaneous error detection*/
    IfxSmu_Alarm_CPU0_PSPRPCACHE_SingleBitErrorCorrection                 = 6,   /**< \brief ALM0[6] : Safety Mechanism: SRAM Monitor Alarm: PSPR/PCACHE Single bit error correction*/
    IfxSmu_Alarm_CPU0_PSPRPCACHE_UncorrectableErrorDetection     		  = 7,   /**< \brief ALM0[7] : Safety Mechanism: SRAM Monitor  Alarm: PSPR/PCACHE Uncorrectable  error detection*/
    IfxSmu_Alarm_CPU0_PSPRPCACHE_MiscellaneousErrorDetection              = 8,   /**< \brief ALM0[8] : Safety Mechanism: SRAM Monitor Alarm: PSPR/PCACHE Miscellaneous error detection*/
    IfxSmu_Alarm_CPU0_DSPRDCACHEDLMU_SingleBitErrorCorrection             = 9,   /**< \brief ALM0[9] : Safety Mechanism: SRAM Monitor Alarm: DSPR/DCACHE/DLMU Single bit error correction*/
    IfxSmu_Alarm_CPU0_DSPRDCACHEDLMU_UncorrectableErrorDetection 		  = 10,  /**< \brief ALM0[10] : Safety Mechanism(s): SRAM Monitor  Alarm: DSPR/DCACHE/DLMU Uncorrectable  error detection*/
    IfxSmu_Alarm_CPU0_DSPRDCACHEDLMU_MiscelleniousErrorDetection          = 11,  /**< \brief ALM0[11] : Safety Mechanism(s): SRAM Monitor Alarm: DSPR/DCACHE/DLMU Miscellenious error detection*/
    IfxSmu_Alarm_CPU0_DCACHETAG_SingleBitErrorCorrection                  = 12,  /**< \brief ALM0[12] : Safety Mechanism: SRAM Monitor Alarm: DCACHE TAG Single bit error correction*/
    IfxSmu_Alarm_CPU0_DCACHETAG_UncorrectableErrorDetection      		  = 13,  /**< \brief ALM0[13] : Safety Mechanism: SRAM Monitor  Alarm: DCACHE TAG Uncorrectable  error detection*/
    IfxSmu_Alarm_CPU0_DCACHETAG_MiscellaneousErrorDetection               = 14,  /**< \brief ALM0[14] : Safety Mechanism: SRAM Monitor Alarm: DCACHE TAG Miscellaneous error detection*/
    IfxSmu_Alarm_CPU0_CPU_InstructionFetchSriInterfaceEdcError            = 22,  /**< \brief ALM0[22] : Safety Mechanism: SRI End-to-End EDC Alarm: CPU Instruction Fetch SRI Interface EDC Error*/
    IfxSmu_Alarm_CPU0_CPU_DataSriInterfaceLoadStoreEdcError               = 23,  /**< \brief ALM0[23] : Safety Mechanism: SRI End-to-End EDC Alarm: CPU Data SRI Interface (Load/Store) EDC Error*/
    IfxSmu_Alarm_CPU0_CPU_ExceptionInterruptTrap                          = 24,  /**< \brief ALM0[24] : Safety Mechanism: Exception Monitor  Alarm: CPU exception (interrupt/trap)*/
    IfxSmu_Alarm_CPU1_Lockstep_ComparatorError                            = 32,  /**< \brief ALM1[0] : Safety Mechanism: Lockstep CPU Alarm: Lockstep Comparator Error*/
    IfxSmu_Alarm_CPU1_Buslevel_MpuViolation                               = 33,  /**< \brief ALM1[1] : Safety Mechanism: Bus-level Memory Protection Unit Alarm: Bus-level MPU violation.*/
    IfxSmu_Alarm_CPU1_PFI1_PFLASH1_ReadPathError                          = 34,  /**< \brief ALM1[2] : Safety Mechanism: PFLASH Read Path Monitor Alarm: PFLASH1 Read Path Error*/
    IfxSmu_Alarm_CPU1_PCACHETAG_UncorrectableErrorDetection      		  = 36,  /**< \brief ALM1[4] : Safety Mechanism: SRAM Monitor  Alarm: PCACHE TAG Uncorrectable  error detection*/
    IfxSmu_Alarm_CPU1_PCACHETAG_MiscellaneousErrorDetection               = 37,  /**< \brief ALM1[5] : Safety Mechanism: SRAM Monitor Alarm: PCACHE TAG Miscellaneous error detection*/
    IfxSmu_Alarm_CPU1_PSPRPCACHE_SingleBitErrorCorrection                 = 38,  /**< \brief ALM1[6] : Safety Mechanism: SRAM Monitor Alarm: PSPR/PCACHE Single bit error correction*/
    IfxSmu_Alarm_CPU1_PSPRPCACHE_UncorrectableErrorDetection              = 39,  /**< \brief ALM1[7] : Safety Mechanism: SRAM Monitor  Alarm: PSPR/PCACHE Uncorrectable  error detection*/
    IfxSmu_Alarm_CPU1_PSPRPCACHE_MiscellaneousErrorDetection              = 40,  /**< \brief ALM1[8] : Safety Mechanism: SRAM Monitor Alarm: PSPR/PCACHE Miscellaneous error detection*/
    IfxSmu_Alarm_CPU1_DSPRDCACHEDLMU_SingleBitErrorCorrection             = 41,  /**< \brief ALM1[9] : Safety Mechanism: SRAM Monitor Alarm: DSPR/DCACHE/DLMU Single bit error correction*/
    IfxSmu_Alarm_CPU1_DSPRDCACHEDLMU_UncorrectableErrorDetection 		  = 42,  /**< \brief ALM1[10] : Safety Mechanism(s): SRAM Monitor  Alarm: DSPR/DCACHE/DLMU Uncorrectable  error detection*/
    IfxSmu_Alarm_CPU1_DSPRDCACHEDLMU_MiscellaneousErrorDetection          = 43,  /**< \brief ALM1[11] : Safety Mechanism(s): SRAM Monitor Alarm: DSPR/DCACHE/DLMU Miscellaneous error detection*/
    IfxSmu_Alarm_CPU1_DCACHETAG_SingleBitErrorCorrection                  = 44,  /**< \brief ALM1[12] : Safety Mechanism: SRAM Monitor Alarm: DCACHE TAG Single bit error correction*/
    IfxSmu_Alarm_CPU1_DCACHETAG_UncorrectableErrorDetection               = 45,  /**< \brief ALM1[13] : Safety Mechanism: SRAM Monitor  Alarm: DCACHE TAG Uncorrectable  error detection*/
    IfxSmu_Alarm_CPU1_DCACHETAG_MiscellaneousErrorDetection               = 46,  /**< \brief ALM1[14] : Safety Mechanism: SRAM Monitor Alarm: DCACHE TAG Miscellaneous error detection*/
    IfxSmu_Alarm_CPU1_CPU_InstructionFetchSriInterfaceEdcError            = 54,  /**< \brief ALM1[22] : Safety Mechanism: SRI End-to-End EDC Alarm: CPU Instruction Fetch SRI Interface EDC Error*/
    IfxSmu_Alarm_CPU1_CPU_DataSriInterfaceLoadStoreEdcError               = 55,  /**< \brief ALM1[23] : Safety Mechanism: SRI End-to-End EDC Alarm: CPU Data SRI Interface (Load/Store) EDC Error*/
    IfxSmu_Alarm_CPU1_CPU_ExceptionInterruptTrap                          = 56,  /**< \brief ALM1[24] : Safety Mechanism: Exception Monitor  Alarm: CPU exception (interrupt/trap)*/
    IfxSmu_Alarm_CPU2_Lockstep_ComparatorError                            = 64,  /**< \brief ALM2[0] : Safety Mechanism: Lockstep CPU Alarm: Lockstep Comparator Error*/
    IfxSmu_Alarm_CPU2_Buslevel_MpuViolation                               = 65,  /**< \brief ALM2[1] : Safety Mechanism: Bus-level Memory Protection Unit Alarm: Bus-level MPU violation.*/
    IfxSmu_Alarm_CPU2_PFI2_PFLASH2_ReadPathError                          = 66,  /**< \brief ALM2[2] : Safety Mechanism: PFLASH Read Path Monitor Alarm: PFLASH2 Read Path Error*/
    IfxSmu_Alarm_CPU2_PCACHETAG_UncorrectableErrorDetection               = 68,  /**< \brief ALM2[4] : Safety Mechanism: SRAM Monitor  Alarm: PCACHE TAG Uncorrectable  error detection*/
    IfxSmu_Alarm_CPU2_PCACHETAG_MiscellaneousErrorDetection               = 69,  /**< \brief ALM2[5] : Safety Mechanism: SRAM Monitor Alarm: PCACHE TAG Miscellaneous error detection*/
    IfxSmu_Alarm_CPU2_PSPRPCACHE_SingleBitErrorCorrection                 = 70,  /**< \brief ALM2[6] : Safety Mechanism: SRAM Monitor Alarm: PSPR/PCACHE Single bit error correction*/
    IfxSmu_Alarm_CPU2_PSPRPCACHE_UncorrectableErrorDetection     		  = 71,  /**< \brief ALM2[7] : Safety Mechanism: SRAM Monitor  Alarm: PSPR/PCACHE Uncorrectable  error detection*/
    IfxSmu_Alarm_CPU2_PSPRPCACHE_MiscellaneousErrorDetection              = 72,  /**< \brief ALM2[8] : Safety Mechanism: SRAM Monitor Alarm: PSPR/PCACHE Miscellaneous error detection*/
    IfxSmu_Alarm_CPU2_DSPRDCACHEDLMU_SingleBitErrorCorrection             = 73,  /**< \brief ALM2[9] : Safety Mechanism: SRAM Monitor Alarm: DSPR/DCACHE/DLMU Single bit error correction*/
    IfxSmu_Alarm_CPU2_DSPRDCACHEDLMU_UncorrectableErrorDetection 		  = 74,  /**< \brief ALM2[10] : Safety Mechanism(s): SRAM Monitor  Alarm: DSPR/DCACHE/DLMU Uncorrectable  error detection*/
    IfxSmu_Alarm_CPU2_DSPRDCACHEDLMU_MiscellaneousErrorDetection          = 75,  /**< \brief ALM2[11] : Safety Mechanism(s): SRAM Monitor Alarm: DSPR/DCACHE/DLMU Miscellaneous error detection*/
    IfxSmu_Alarm_CPU2_DCACHETAG_SingleBitErrorCorrection                  = 76,  /**< \brief ALM2[12] : Safety Mechanism: SRAM Monitor Alarm: DCACHE TAG Single bit error correction*/
    IfxSmu_Alarm_CPU2_DCACHETAG_UncorrectableErrorDetection      		  = 77,  /**< \brief ALM2[13] : Safety Mechanism: SRAM Monitor  Alarm: DCACHE TAG Uncorrectable  error detection*/
    IfxSmu_Alarm_CPU2_DCACHETAG_MiscellaneousErrorDetection               = 78,  /**< \brief ALM2[14] : Safety Mechanism: SRAM Monitor Alarm: DCACHE TAG Miscellaneous error detection*/
    IfxSmu_Alarm_CPU2_CPU_InstructionFetchSriInterfaceEdcError            = 86,  /**< \brief ALM2[22] : Safety Mechanism: SRI End-to-End EDC Alarm: CPU Instruction Fetch SRI Interface EDC Error*/
    IfxSmu_Alarm_CPU2_CPU_DataSriInterfaceLoadStoreEdcError               = 87,  /**< \brief ALM2[23] : Safety Mechanism: SRI End-to-End EDC Alarm: CPU Data SRI Interface (Load/Store) EDC Error*/
    IfxSmu_Alarm_CPU2_CPU_ExceptionInterruptTrap                    	  = 88,  /**< \brief ALM2[24] : Safety Mechanism: Exception Monitor  Alarm: CPU exception (interrupt/trap)*/
    IfxSmu_Alarm_MTU_Safety_FfUncorrectableErrorDetected                  = 192, /**< \brief ALM6[0] : Safety Mechanism: Safety FlipFlop Alarm: Safety FF uncorrectable error detected*/
    IfxSmu_Alarm_IOM_Safety_FfUncorrectableErrorDetected                  = 193, /**< \brief ALM6[1] : Safety Mechanism: Safety FlipFlop Alarm: Safety FF uncorrectable error detected*/
    IfxSmu_Alarm_IR_Safety_FfUncorrectableErrorDetected                   = 194, /**< \brief ALM6[2] : Safety Mechanism: Safety FlipFlop Alarm: Safety FF uncorrectable error detected*/
    IfxSmu_Alarm_EMEM_Safety_FfUncorrectableErrorDetected                 = 195, /**< \brief ALM6[3] : Safety Mechanism: Safety FlipFlop Alarm: Safety FF uncorrectable error detected*/
    IfxSmu_Alarm_SCU_Safety_FfUncorrectableErrorDetected                  = 196, /**< \brief ALM6[4] : Safety Mechanism: Safety FlipFlop Alarm: Safety FF uncorrectable error detected*/
    IfxSmu_Alarm_PMS_Safety_FfUncorrectableErrorDetected                  = 197, /**< \brief ALM6[5] : Safety Mechanism: Safety FlipFlop Alarm: Safety FF uncorrectable error detected*/
    IfxSmu_Alarm_DMA_Safety_FfUncorrectableErrorDetected                  = 198, /**< \brief ALM6[6] : Safety Mechanism: Safety FlipFlop Alarm: Safety FF uncorrectable error detected*/
    IfxSmu_Alarm_SMU_core_Safety_FfUncorrectableErrorDetected             = 199, /**< \brief ALM6[7] : Safety Mechanism: Safety FlipFlop Alarm: Safety FF uncorrectable error detected*/
    IfxSmu_Alarm_SYS_PLL_PER_PLL_Safety_FfUncorrectableErrorDetected      = 200, /**< \brief ALM6[8] : Safety Mechanism: Safety FlipFlop Alarm: Safety FF uncorrectable error detected*/
    IfxSmu_Alarm_GTM_GTM_SingleBitErrorCorrection                         = 202, /**< \brief ALM6[10] : Safety Mechanism: SRAM Monitor Alarm: GTM Single bit error correction*/
    IfxSmu_Alarm_GTM_GTM_UncorrectableErrorDetection             		  = 203, /**< \brief ALM6[11] : Safety Mechanism: SRAM Monitor  Alarm: GTM Uncorrectable  error detection*/
    IfxSmu_Alarm_GTM_GTM_MiscellaneousErrorDetection                      = 204, /**< \brief ALM6[12] : Safety Mechanism: SRAM Monitor Alarm: GTM Miscellaneous error detection*/
    IfxSmu_Alarm_ERAY_ERAY_SingleBitErrorCorrection                       = 205, /**< \brief ALM6[13] : Safety Mechanism: SRAM Monitor Alarm: ERAY Single bit error correction*/
    IfxSmu_Alarm_ERAY_ERAY_UncorrectableErrorDetection           		  = 206, /**< \brief ALM6[14] : Safety Mechanism: SRAM Monitor  Alarm: ERAY Uncorrectable  error detection*/
    IfxSmu_Alarm_ERAY_ERAY_MiscellaneousErrorDetection                    = 207, /**< \brief ALM6[15] : Safety Mechanism: SRAM Monitor Alarm: ERAY Miscellaneous error detection*/
    IfxSmu_Alarm_CAN_CAN_SingleBitErrorCorrection                         = 208, /**< \brief ALM6[16] : Safety Mechanism: SRAM Monitor Alarm: CAN Single bit error correction*/
    IfxSmu_Alarm_CAN_CAN_UncorrectableErrorDetection             		  = 209, /**< \brief ALM6[17] : Safety Mechanism: SRAM Monitor  Alarm: CAN Uncorrectable  error detection*/
    IfxSmu_Alarm_CAN_CAN_MiscellaneousErrorDetection                      = 210, /**< \brief ALM6[18] : Safety Mechanism: SRAM Monitor Alarm: CAN Miscellaneous error detection*/
    IfxSmu_Alarm_Misc_MISC_SingleBitErrorCorrection                       = 211, /**< \brief ALM6[19] : Safety Mechanism: SRAM Monitor Alarm: MISC Single bit error correction*/
    IfxSmu_Alarm_Misc_MISC_UncorrectableErrorDetection           		  = 212, /**< \brief ALM6[20] : Safety Mechanism: SRAM Monitor  Alarm: MISC Uncorrectable  error detection*/
    IfxSmu_Alarm_Misc_MISC_MiscellaneousErrorDetection                    = 213, /**< \brief ALM6[21] : Safety Mechanism: SRAM Monitor Alarm: MISC Miscellaneous error detection*/
    IfxSmu_Alarm_CERBERUS_Safety_FfUncorrectableErrorDetected             = 215, /**< \brief ALM6[23] : Safety Mechanism: Safety FlipFlop Alarm: Safety FF uncorrectable error detected*/
    IfxSmu_Alarm_CCU_Safety_FfCorrectableErrorDetected                    = 216, /**< \brief ALM6[24] : Safety Mechanism: Safety FlipFlop Alarm: Safety FF correctable error detected*/
    IfxSmu_Alarm_CCU_Safety_FfUncorrectableErrorDetected                  = 217, /**< \brief ALM6[25] : Safety Mechanism: Safety FlipFlop Alarm: Safety FF uncorrectable error detected*/
    IfxSmu_Alarm_LMU_FSI_RAM_LMUDMU_SingleBitErrorCorrection              = 224, /**< \brief ALM7[0] : Safety Mechanism: SRAM Monitor Alarm: LMU/DMU Single bit error correction*/
    IfxSmu_Alarm_LMU_FSI_RAM_LMUDMU_UncorrectableErrorDetection  		  = 225, /**< \brief ALM7[1] : Safety Mechanism: SRAM Monitor  Alarm: LMU/DMU Uncorrectable  error detection*/
    IfxSmu_Alarm_LMU_FSI_RAM_LMUDMU_MiscellaneousErrorDetection           = 226, /**< \brief ALM7[2] : Safety Mechanism: SRAM Monitor Alarm: LMU/DMU Miscellaneous error detection*/
    IfxSmu_Alarm_LMU_Lockstep_ComparatorError                             = 236, /**< \brief ALM7[12] : Safety Mechanism: LMU Lockstep Alarm: Lockstep Comparator Error*/
    IfxSmu_Alarm_LMU_Lockstep_ControlError                                = 237, /**< \brief ALM7[13] : Safety Mechanism: LMU Lockstep Alarm: Lockstep Control Error*/
    IfxSmu_Alarm_LMU_ECC_Error                                            = 238, /**< \brief ALM7[14] : Safety Mechanism: SRAM ECC Monitor Alarm: ECC Error*/
    IfxSmu_Alarm_LMU_Buslevel_MpuError                                    = 239, /**< \brief ALM7[15] : Safety Mechanism: Bus-level MPU Alarm: Bus-level MPU error*/
    IfxSmu_Alarm_LMU_EDC_ReadPhaseError                                   = 240, /**< \brief ALM7[16] : Safety Mechanism: LMU Error Detection Code (EDC) Alarm: EDC Read Phase Error*/
    IfxSmu_Alarm_XBAR0_SRI_BusErrorEvent                                  = 241, /**< \brief ALM7[17] : Safety Mechanism: Built-in SRI Error Detection Alarm: SRI Bus Error Event*/
    IfxSmu_Alarm_XBAR1_SRI_BusErrorEvent                                  = 242, /**< \brief ALM7[18] : Safety Mechanism: Built-in SRI Error Detection Alarm: SRI Bus Error Event*/
    IfxSmu_Alarm_XBAR2_SRI_BusErrorEvent                                  = 243, /**< \brief ALM7[19] : Safety Mechanism: Built-in SRI Error Detection Alarm: SRI Bus Error Event*/
    IfxSmu_Alarm_SPB_BusErrorEvent                               		  = 244, /**< \brief ALM7[20] : Safety Mechanism: Built-in SPB Error Detection  Alarm: SPB Bus Error Event*/
    IfxSmu_Alarm_BBB_BusErrorEvent                               		  = 245, /**< \brief ALM7[21] : Safety Mechanism: Built-in BBB Error Detection  Alarm: BBB Bus Error Event*/
    IfxSmu_Alarm_FSI_PFlash_SingleBitError                                = 246, /**< \brief ALM7[22] : Safety Mechanism: PFlash ECC Alarm: PFlash Single Bit Error*/
    IfxSmu_Alarm_FSI_PFlash_DoubleBitError                                = 247, /**< \brief ALM7[23] : Safety Mechanism: PFlash ECC Alarm: PFlash Double Bit Error*/
    IfxSmu_Alarm_FSI_Single_BitCorrectionTrackingBufferFull               = 248, /**< \brief ALM7[24] : Safety Mechanism: PFlash ECC Alarm: Single Bit Correction Tracking Buffer Full*/
    IfxSmu_Alarm_FSI_Double_BitCorrectionTrackingBufferFull               = 249, /**< \brief ALM7[25] : Safety Mechanism: PFlash ECC Alarm: Double Bit Correction Tracking Buffer Full*/
    IfxSmu_Alarm_FSI_Multiple_BitErrorDetectionTrackingBufferFull         = 250, /**< \brief ALM7[26] : Safety Mechanism: PFlash ECC  Alarm: Multiple Bit Error Detection Tracking Buffer Full*/
    IfxSmu_Alarm_FSI_Zero_BitErrorTrackingBufferFull                      = 251, /**< \brief ALM7[27] : Safety Mechanism: PFlash ECC Alarm: Zero Bit Error Tracking Buffer Full*/
    IfxSmu_Alarm_FSI_PFlash_EccError                                      = 252, /**< \brief ALM7[28] : Safety Mechanism: PFlash ECC Monitor Alarm: PFlash ECC Error*/
    IfxSmu_Alarm_FSI_PFlash_EdcError                                      = 253, /**< \brief ALM7[29] : Safety Mechanism: PFlash EDC Monitor Alarm: PFlash EDC Error*/
    IfxSmu_Alarm_FSI_CPUFLASHCON_ConfigurationError                       = 254, /**< \brief ALM7[30] : Safety Mechanism: PFlash Configuration Monitor Alarm: CPU FLASHCON Configuration Error*/
    IfxSmu_Alarm_FSI_Flash_StoredConfigurationError                       = 255, /**< \brief ALM7[31] : Safety Mechanism: PFlash Configuration Monitor Alarm: Flash Stored Configuration Error*/
    IfxSmu_Alarm_SCU_OS_CClockFrequencyOutOfRange                         = 256, /**< \brief ALM8[0] : Safety Mechanism: Clock Monitor Alarm: OSC clock frequency out of range */
    IfxSmu_Alarm_CCU_Backup_ClockOutOfRangeAlarm                          = 257, /**< \brief ALM8[1] : Safety Mechanism: Clock Monitor Alarm: Back-up clock out-of-range alarm */
    IfxSmu_Alarm_CCU_Backup_ClockAliveAlarm                               = 258, /**< \brief ALM8[2] : Safety Mechanism: Clock Alive Monitor Alarm: Back-up clock alive alarm */
    IfxSmu_Alarm_SCU_System_PllDcoLossOfLockEvent                         = 259, /**< \brief ALM8[3] : Safety Mechanism: PLL loss of lock detection Alarm: System PLL DCO loss of lock event*/
    IfxSmu_Alarm_SCU_Peripheral_PllDcoLossOfLockEvent                     = 260, /**< \brief ALM8[4] : Safety Mechanism: PLL loss of lock detection Alarm: Peripheral PLL DCO loss of lock event*/
    IfxSmu_Alarm_SCU_LBIST_Alarm                                          = 261, /**< \brief ALM8[5] : Safety Mechanism: LBIST Safe Reset State Alarm: LBIST Alarm*/
    IfxSmu_Alarm_SCU_External_RequestUnitAlarm0                           = 262, /**< \brief ALM8[6] : Safety Mechanism: External Alarm Alarm: External Request Unit Alarm 0*/
    IfxSmu_Alarm_SCU_External_RequestUnitAlarm1                           = 263, /**< \brief ALM8[7] : Safety Mechanism: External Alarm Alarm: External Request Unit Alarm 1*/
    IfxSmu_Alarm_SCU_External_RequestUnitAlarm2                           = 264, /**< \brief ALM8[8] : Safety Mechanism: External Alarm Alarm: External Request Unit Alarm 2*/
    IfxSmu_Alarm_SCU_External_RequestUnitAlarm3                           = 265, /**< \brief ALM8[9] : Safety Mechanism: External Alarm Alarm: External Request Unit Alarm 3*/
    IfxSmu_Alarm_SCU_CPU0_WatchdogTimeOut                                 = 266, /**< \brief ALM8[10] : Safety Mechanism: Watchdog Alarm: CPU0 Watchdog time-out*/
    IfxSmu_Alarm_SCU_CPU1_WatchdogTimeOut                                 = 267, /**< \brief ALM8[11] : Safety Mechanism: Watchdog Alarm: CPU1 Watchdog time-out*/
    IfxSmu_Alarm_SCU_CPU2_WatchdogTimeOut                                 = 268, /**< \brief ALM8[12] : Safety Mechanism: Watchdog Alarm: CPU2 Watchdog time-out*/
    IfxSmu_Alarm_SCU_Safety_WatchdogTimeOut                               = 272, /**< \brief ALM8[16] : Safety Mechanism: Watchdog Alarm: Safety Watchdog time-out*/
    IfxSmu_Alarm_SCU_Watchdog_TimeOut                                	  = 273, /**< \brief ALM8[17] : Safety Mechanism: All Watchdogs  Alarm: watchdog time-out*/
    IfxSmu_Alarm_SCU_Lockstep_DualRailError                               = 274, /**< \brief ALM8[18] : Safety Mechanism: Lockstep Dual Rail Monitor  Alarm: dual rail error*/
    IfxSmu_Alarm_SCU_External_EmergencyStopSignalEvent                    = 275, /**< \brief ALM8[19] : Safety Mechanism: Emergency Stop Alarm: External Emergency Stop Signal Event*/
    IfxSmu_Alarm_SCU_Pad_HeatingAlarm                                     = 276, /**< \brief ALM8[20] : Safety Mechanism: Pad Monitor Alarm: Pad heating alarm*/
    IfxSmu_Alarm_SCU_LBIST_TestModeAlarm                                  = 277, /**< \brief ALM8[21] : Safety Mechanism: LBIST Test Mode Alarm: LBIST Test Mode Alarm*/
    IfxSmu_Alarm_IR_EDC_ConfigurationDataPathError                        = 278, /**< \brief ALM8[22] : Safety Mechanism: Interrupt Monitor  Alarm: EDC Configuration Data Path Error */
    IfxSmu_Alarm_DMA_DMASRI_EccError                                      = 279, /**< \brief ALM8[23] : Safety Mechanism: DMA SRI ECC  Alarm: DMA SRI ECC Error*/
    IfxSmu_Alarm_IOM_Pin_MismatchIndication                               = 281, /**< \brief ALM8[25] : Safety Mechanism: External Alarm Alarm: Pin Mismatch Indication*/
    IfxSmu_Alarm_SCU_External_RequestUnitAlarm4                           = 282, /**< \brief ALM8[26] : Safety Mechanism: External Alarm Alarm: External Request Unit Alarm 4*/
    IfxSmu_Alarm_SCU_External_RequestUnitAlarm5                           = 283, /**< \brief ALM8[27] : Safety Mechanism: External Alarm Alarm: External Request Unit Alarm 5*/
    IfxSmu_Alarm_SCU_External_RequestUnitAlarm6                           = 284, /**< \brief ALM8[28] : Safety Mechanism: External Alarm Alarm: External Request Unit Alarm 6*/
    IfxSmu_Alarm_SCU_External_RequestUnitAlarm7                           = 285, /**< \brief ALM8[29] : Safety Mechanism: External Alarm Alarm: External Request Unit Alarm 7*/
    IfxSmu_Alarm_DTS_core_Under_TemperatureAlarm                          = 286, /**< \brief ALM8[30] : Safety Mechanism: Core Domain Die Temperature Sensor Alarm: Under Temperature Alarm*/
    IfxSmu_Alarm_DTS_core_Over_TemperatureAlarm                           = 287, /**< \brief ALM8[31] : Safety Mechanism: Core Domain Die Temperature Sensor Alarm: Over Temperature Alarm*/
    IfxSmu_Alarm_DTS_Temperature_Overflow                                 = 288, /**< \brief ALM9[0] : Safety Mechanism: Die Temperature Sensor Alarm: Temperature overflow*/
    IfxSmu_Alarm_DTS_Temperature_Underflow                                = 289, /**< \brief ALM9[1] : Safety Mechanism: Die Temperature Sensor Alarm: Temperature underflow*/
    IfxSmu_Alarm_EVR_Overvoltage_Alarm                                    = 291, /**< \brief ALM9[3] : Safety Mechanism: Voltage Monitor Alarm: Over-voltage Alarm*/
    IfxSmu_Alarm_EVR_Undervoltage_Alarm                                   = 293, /**< \brief ALM9[5] : Safety Mechanism: Voltage Monitor Alarm: Under-voltage Alarm*/
    IfxSmu_Alarm_EVR_Short_ToLowHightAlarm                                = 303, /**< \brief ALM9[15] : Safety Mechanism: Voltage Monitor Alarm: Short to low/hight Alarm*/
    IfxSmu_Alarm_HSM_Overvoltage_Alarm                                    = 304, /**< \brief ALM9[16] : Safety Mechanism: Voltage Monitor Alarm: Over-voltage Alarm*/
    IfxSmu_Alarm_HSM_Undervoltage_Alarm                                   = 305, /**< \brief ALM9[17] : Safety Mechanism: Voltage Monitor Alarm: Under-voltage Alarm*/
    IfxSmu_Alarm_EMEM_Unexpected_WriteToEmemAlarm                         = 308, /**< \brief ALM9[20] : Safety Mechanism: EMEM Monitor Alarm: Unexpected Write to EMEM Alarm*/
    IfxSmu_Alarm_EMEM_SEP_ControlLogicAlarm                               = 309, /**< \brief ALM9[21] : Safety Mechanism: SEP Control Logic Monitor  Alarm: SEP Control Logic Alarm*/
    IfxSmu_Alarm_EMEM_Lockstep_ControlLogicInputAlarm                     = 310, /**< \brief ALM9[22] : Safety Mechanism: Lockstep Control Logic Input Monitor Alarm: Lockstep Control Logic Input Alarm*/
    IfxSmu_Alarm_Software_Alarm0                                          = 320, /**< \brief ALM10[0] : Safety Mechanism: Software Monitor Alarm: Software Alarm 0*/
    IfxSmu_Alarm_Software_Alarm1                                          = 321, /**< \brief ALM10[1] : Safety Mechanism: Software Monitor Alarm: Software Alarm 1*/
    IfxSmu_Alarm_Software_Alarm2                                          = 322, /**< \brief ALM10[2] : Safety Mechanism: Software Monitor Alarm: Software Alarm 2*/
    IfxSmu_Alarm_Software_Alarm3                                          = 323, /**< \brief ALM10[3] : Safety Mechanism: Software Monitor Alarm: Software Alarm 3*/
    IfxSmu_Alarm_Software_Alarm4                                          = 324, /**< \brief ALM10[4] : Safety Mechanism: Software Monitor Alarm: Software Alarm 4*/
    IfxSmu_Alarm_Software_Alarm5                                          = 325, /**< \brief ALM10[5] : Safety Mechanism: Software Monitor Alarm: Software Alarm 5*/
    IfxSmu_Alarm_Software_Alarm6                                          = 326, /**< \brief ALM10[6] : Safety Mechanism: Software Monitor Alarm: Software Alarm 6*/
    IfxSmu_Alarm_Software_Alarm7                                          = 327, /**< \brief ALM10[7] : Safety Mechanism: Software Monitor Alarm: Software Alarm 7*/
    IfxSmu_Alarm_Software_Alarm8                                          = 328, /**< \brief ALM10[8] : Safety Mechanism: Software Monitor Alarm: Software Alarm 8*/
    IfxSmu_Alarm_Software_Alarm9                                          = 329, /**< \brief ALM10[9] : Safety Mechanism: Software Monitor Alarm: Software Alarm 9*/
    IfxSmu_Alarm_Software_Alarm10                                         = 330, /**< \brief ALM10[10] : Safety Mechanism: Software Monitor Alarm: Software Alarm 10*/
    IfxSmu_Alarm_Software_Alarm11                                         = 331, /**< \brief ALM10[11] : Safety Mechanism: Software Monitor Alarm: Software Alarm 11*/
    IfxSmu_Alarm_Software_Alarm12                                         = 332, /**< \brief ALM10[12] : Safety Mechanism: Software Monitor Alarm: Software Alarm 12*/
    IfxSmu_Alarm_Software_Alarm13                                         = 333, /**< \brief ALM10[13] : Safety Mechanism: Software Monitor Alarm: Software Alarm 13*/
    IfxSmu_Alarm_Software_Alarm14                                         = 334, /**< \brief ALM10[14] : Safety Mechanism: Software Monitor Alarm: Software Alarm 14*/
    IfxSmu_Alarm_Software_Alarm15                                         = 335, /**< \brief ALM10[15] : Safety Mechanism: Software Monitor Alarm: Software Alarm 15*/
    IfxSmu_Alarm_SMU_Timer0_TimeOut                                       = 336, /**< \brief ALM10[16] : Safety Mechanism: Recovery Timer 0  Alarm: Timer time-out */
    IfxSmu_Alarm_SMU_Timer1_TimeOut                                       = 337, /**< \brief ALM10[17] : Safety Mechanism: Recovery Timer 1  Alarm: Timer time-out */
    IfxSmu_Alarm_SMU_Error_PinFaultStateActivation                        = 338, /**< \brief ALM10[18] : Safety Mechanism: ErrorPin Alarm: Error Pin fault state activation*/
    IfxSmu_Alarm_SMU_Safety_FfCorrectableErrorDetected                    = 340, /**< \brief ALM10[20] : Safety Mechanism: Safety FlipFlop Alarm: Safety FF correctable error detected*/
    IfxSmu_Alarm_SMU_Safety_FfUncorrectableErrorDetected                  = 341, /**< \brief ALM10[21] : Safety Mechanism: Safety FlipFlop Alarm: Safety FF uncorrectable error detected*/
    IfxSmu_Alarm_SMU_Access_EnableErrorDetected                           = 342, /**< \brief ALM10[22] : Safety Mechanism: Access Enable Protection Alarm: Access Enable error detected*/
    IfxSmu_Alarm_LMU_EDC_AddressPhaseError                                = 352, /**< \brief ALM11[0] : Safety Mechanism: SRI Error Detection Code (EDC) Alarm: EDC Address Phase Error*/
    IfxSmu_Alarm_LMU_EDC_WritePhaseError                                  = 353, /**< \brief ALM11[1] : Safety Mechanism: SRI Error Detection Code (EDC) Alarm: EDC Write Phase Error*/
    IfxSmu_Alarm_XBAR_EDC_AddressPhaseError                               = 354, /**< \brief ALM11[2] : Safety Mechanism: SRI Error Detection Code (EDC) Alarm: EDC Address Phase Error*/
    IfxSmu_Alarm_XBAR_EDC_WritePhaseError                                 = 355, /**< \brief ALM11[3] : Safety Mechanism: SRI Error Detection Code (EDC) Alarm: EDC Write Phase Error*/
    IfxSmu_Alarm_DMU_EDC_AddressPhaseError                                = 356, /**< \brief ALM11[4] : Safety Mechanism: SRI Error Detection Code (EDC) Alarm: EDC Address Phase Error*/
    IfxSmu_Alarm_DMU_EDC_WritePhaseError                                  = 357, /**< \brief ALM11[5] : Safety Mechanism: SRI Error Detection Code (EDC) Alarm: EDC Write Phase Error*/
    IfxSmu_Alarm_SFI_BBB_EDC_AddressPhaseError                            = 358, /**< \brief ALM11[6] : Safety Mechanism: SRI Error Detection Code (EDC) Alarm: EDC Address Phase Error*/
    IfxSmu_Alarm_SFI_BBB_EDC_WritePhaseError                              = 359, /**< \brief ALM11[7] : Safety Mechanism: SRI Error Detection Code (EDC) Alarm: EDC Write Phase Error*/
    IfxSmu_Alarm_SRI_EDC_ReadPhaseError                                   = 360, /**< \brief ALM11[8] : Safety Mechanism: SRI Error Detection Code (EDC)  Alarm: EDC Read Phase Error */
    IfxSmu_Alarm_SFI_SPB_EDC_ReadPhaseError                               = 361, /**< \brief ALM11[9] : Safety Mechanism: SRI Error Detection Code (EDC) Alarm: EDC Read Phase Error*/
    IfxSmu_Alarm_HSSL_HSSL0EDC_ReadPhaseError                             = 362, /**< \brief ALM11[10] : Safety Mechanism: SRI Error Detection Code (EDC) Alarm: HSSL0 EDC Read Phase Error*/
    IfxSmu_Alarm_CONVERTER_Phase_SyncronizerError                         = 364, /**< \brief ALM11[12] : Safety Mechanism: Converter Alarm: Phase Syncronizer Error*/
    IfxSmu_Alarm_XBAR_SOTA_SwapError                                      = 365, /**< \brief ALM11[13] : Safety Mechanism: SRI SOTA Monitor Alarm: SOTA Swap Error*/
	IfxSmu_Alarm_EVR_VDD_OverVoltageAlarm                                 = 4,   /**< \brief ALM20[4] : Safety Mechanism: Voltage Monitor Alarm: VDD Over-voltage Alarm*/
	IfxSmu_Alarm_EVR_VDDPD_OverVoltageAlarm                               = 5,   /**< \brief ALM20[5] : Safety Mechanism: Voltage Monitor Alarm: VDDPD Over-voltage Alarm*/
	IfxSmu_Alarm_EVR_VDDP3_OverVoltageAlarm                               = 6,   /**< \brief ALM20[6] : Safety Mechanism: Voltage Monitor Alarm: VDDP3 Over-voltage Alarm*/
	IfxSmu_Alarm_EVR_VDDM_OverVoltageAlarm                                = 7,   /**< \brief ALM20[7] : Safety Mechanism: Voltage Monitor Alarm: VDDM Over-voltage Alarm*/
	IfxSmu_Alarm_EVR_VEXT_OverVoltageAlarm                                = 8,   /**< \brief ALM20[8] : Safety Mechanism: Voltage Monitor Alarm: VEXT Over-voltage Alarm*/
	IfxSmu_Alarm_EVR_VEVRSB_OverVoltageAlarm                              = 9,   /**< \brief ALM20[9] : Safety Mechanism: Voltage Monitor Alarm: VEVRSB Over-voltage Alarm*/
	IfxSmu_Alarm_EVR_VDD_UnderVoltageAlarm                                = 10,   /**< \brief ALM20[10] : Safety Mechanism: Voltage Monitor Alarm: VDD Under-voltage Alarm*/
	IfxSmu_Alarm_EVR_VDDPD_UnderVoltageAlarm                              = 11,   /**< \brief ALM20[11] : Safety Mechanism: Voltage Monitor Alarm: VDDPD Under-voltage Alarm*/
	IfxSmu_Alarm_EVR_VDDP3_UnderVoltageAlarm                              = 12,   /**< \brief ALM20[12] : Safety Mechanism: Voltage Monitor Alarm: VDDP3 Under-voltage Alarm*/
	IfxSmu_Alarm_EVR_VDDM_UnderVoltageAlarm                               = 13,   /**< \brief ALM20[13] : Safety Mechanism: Voltage Monitor Alarm: VDDM Under-voltage Alarm*/
	IfxSmu_Alarm_EVR_VEXT_UnderVoltageAlarm                               = 14,   /**< \brief ALM20[14] : Safety Mechanism: Voltage Monitor Alarm: VEXT Under-voltage Alarm*/
	IfxSmu_Alarm_EVR_VEVRSB_UnderVoltageAlarm                             = 15,   /**< \brief ALM20[15] : Safety Mechanism: Voltage Monitor Alarm: VEVRSB Under-voltage Alarm*/
	IfxSmu_Alarm_HSM_VDD_UnderVoltageAlarm                                = 0,   /**< \brief ALM21[0] : Safety Mechanism: Voltage Monitor Alarm: VDD Under-voltage Alarm*/
	IfxSmu_Alarm_HSM_VDDP3_UnderVoltageAlarm                              = 1,   /**< \brief ALM21[1] : Safety Mechanism: Voltage Monitor Alarm: VDDP3 Under-voltage Alarm*/
	IfxSmu_Alarm_HSM_VEXT_UnderVoltageAlarm                               = 2,   /**< \brief ALM21[2] : Safety Mechanism: Voltage Monitor Alarm: VEXT Under-voltage Alarm*/
	IfxSmu_Alarm_HSM_VDD_OverVoltageAlarm                                 = 3,   /**< \brief ALM21[3] : Safety Mechanism: Voltage Monitor Alarm: VDD Over-voltage Alarm*/
	IfxSmu_Alarm_HSM_VDDP3_OverVoltageAlarm                               = 4,   /**< \brief ALM21[4] : Safety Mechanism: Voltage Monitor Alarm: VDDP3 Over-voltage Alarm*/
	IfxSmu_Alarm_HSM_VEXT_OverVoltageAlarm                                = 5,   /**< \brief ALM21[5] : Safety Mechanism: Voltage Monitor Alarm: VEXT Over-voltage Alarm*/
	IfxSmu_Alarm_SMUSTDBY_Safety_FfUncorrectableErrorDetected             = 7,   /**< \brief ALM21[7] : Safety Flip-flop Alarm: Safety flip-flop uncorrectable error detected*/
	IfxSmu_Alarm_PMS_Temperature_Underflow                                = 8,   /**< \brief ALM21[8] : Safety Mechanism: Die Temperature Sensor Alarm: Temperature underflow*/
	IfxSmu_Alarm_PMS_Temperature_Overflow                                 = 9,   /**< \brief ALM21[9] : Safety Mechanism: Die Temperature Sensor Alarm: Temperature overflow*/
	IfxSmu_Alarm_PMS_Access_ProtectionViolation                           = 10,   /**< \brief ALM21[10] : Safety Mechanism: Register Access Protection Alarm: Access Protection violation*/
	IfxSmu_Alarm_EVR_EVRC_ShortToLowAlarm                                 = 11,   /**< \brief ALM21[11] : Safety Mechanism: Voltage Monitor Alarm: EVRC Short to Low Alarm*/
	IfxSmu_Alarm_EVR_EVRC_ShortToHighAlarm                                = 12,   /**< \brief ALM21[12] : Safety Mechanism: Voltage Monitor Alarm: EVRC Short to High Alarm*/
	IfxSmu_Alarm_EVR_EV33_ShortToLowAlarm                                 = 13,   /**< \brief ALM21[13] : Safety Mechanism: Voltage Monitor Alarm: EV33 Short to Low Alarm*/
	IfxSmu_Alarm_EVR_EV33_ShortToHighAlarm                                = 14,   /**< \brief ALM21[14] : Safety Mechanism: Voltage Monitor Alarm: EV33 Short to High Alarm*/
	IfxSmu_Alarm_CCU_PLLx_fSPB_AliveAlarm                                 = 15,   /**< \brief ALM21[15] : Safety Mechanism: Clock Alive Monitor Alarm: PLLx/fSPB Alive Alarm (provided on fBACK clock with x = 0..2)*/
	IfxSmu_Alarm_SMU_core_AliveAlarm                                      = 16,   /**< \brief ALM21[16] : Safety Mechanism: SMU_core Alive Monitor Alarm: SMU_core Alive Alarm*/
} IfxSmu_Alarm;

/******************************************************************************/
/*-----------------------------Data Structures--------------------------------*/
/******************************************************************************/

#endif /* IFXSMU_CFG_TC37X_H */
