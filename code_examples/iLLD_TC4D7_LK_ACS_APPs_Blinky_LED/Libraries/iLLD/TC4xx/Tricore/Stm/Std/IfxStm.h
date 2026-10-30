/**
 * \file IfxStm.h
 * \brief STM  basic functionality
 * \ingroup IfxLld_Stm
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
 * \defgroup IfxLld_Stm_Usage How to use the Stm driver?
 * \ingroup IfxLld_Stm
 *
 * The Stm Standard driver provides APIs to initialize, configure and control the Stm.
 *
 * In the following sections it will be described, how to integrate the driver into the application framework.
 *
 * \section IfxLld_Stm_Preparation Preparation
 * \subsection IfxLld_Stm_Include Include Files
 *
 * Include following header file into your C code:
 * \code
 * #include <Stm/Std/IfxStm.h>
 * \endcode
 *
 * \subsection IfxLld_Stm_Variables Variables
 *
 * Declare STM variables :
 * \code
 * Ifx_CPU *stmSfr;
 * IfxStm_CompareConfig stmConfig;
 * \endcode
 *
 * \subsection IfxLld_Stm_Interrupt Interrupt Handler Installation
 *
 * See also \ref IfxLld_Cpu_Irq_Usage
 *
 * Define priorities for the Interrrupt handlers. This is normally done in the Ifx_IntPrioDef.h file:
 * \code
 * // priorities are normally defined in Ifx_IntPrioDef.h
 * #define IFX_INTPRIO_STM0_SR0  10
 * \endcode
 *
 * Add the interrupt service routines to your C code. They have to call the Stm interrupt handlers:
 * please take care in choosing number of ticks, the below example code will raise an interrupt
 * evry time the specified number of ticks have been elapsed.
 * \code
 * IFX_INTERRUPT(stm0Sr0ISR, 0, IFX_INTPRIO_STM0_SR0)
 * {
 *     IfxStm_clearCompareFlag(stmSfr, stmConfig.comparator);
 *     IfxStm_increaseCompare(stmSfr, stmConfig.comparator, stmConfig.ticks);
 * }
 * \endcode
 *
 * Finally install the interrupt handlers in your initialisation function:
 * \code
 *     // install interrupt handlers
 *     IfxCpu_Irq_installInterruptHandler(&stm0Sr0ISR, IFX_INTPRIO_STM0_SR0);
 *     IfxCpu_enableInterrupts();
 * \endcode
 *
 * \subsection IfxLld_Stm_Init Module Initialisation
 *
 * The STM module can be configured to generate an interrupt at every compare match of the selected comaparator with the desired compare value, the interrupt can further be routed to other comparator.
 *
 * The module initialisation can be done as followed.
 *
 * \code
 *     stmSfr = &MODULE_STM0;
 *
 *     IfxStm_initCompareConfig(&stmConfig);
 *
 *     // configure to generate interrupt every 10 us
 *     sint32 ticks = IfxStm_getTicksFromMicroseconds(10);
 *
 *     stmConfig.ticks = ticks;
 *
 *     stmConfig.triggerPriority = IFX_INTPRIO_STM0_SR0;
 *     stmConfig.typeOfService = IfxSrc_Tos_cpu0;
 *
 *     IfxStm_initCompare(stmSfr, &stmConfig);
 *
 * \endcode
 *
 * Now the Stm shall generate interrupts regularly based on the configured time !
 *
 * \defgroup IfxLld_Stm_Std_Enumerations Enumerations
 * \ingroup IfxLld_Stm_Std
 * \defgroup IfxLld_Stm_Std_Structures Data Structures
 * \ingroup IfxLld_Stm_Std
 * \defgroup IfxLld_Stm_Std_Module Module Functions
 * \ingroup IfxLld_Stm_Std
 * \defgroup IfxLld_Stm_Std_Timer Timer Functions
 * \ingroup IfxLld_Stm_Std
 * \defgroup IfxLld_Stm_Std_Comparator Comparator Functions
 * \ingroup IfxLld_Stm_Std
 */

#ifndef IFXSTM_H
#define IFXSTM_H 1

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include "_Impl/IfxStm_cfg.h"
#include "Clock/Std/IfxClock.h"
#include "Src/Std/IfxSrc.h"
#include "IfxCpu_reg.h"
#include "Ap/Std/IfxApProt.h"
#include "Ap/Std/IfxApApu.h"
#include "Cpu/Std/IfxCpu.h"

/******************************************************************************/
/*-----------------------------------Macros-----------------------------------*/
/******************************************************************************/

#ifndef IFXSTM_DEFAULT_TIMER
#define IFXSTM_DEFAULT_TIMER       (&MODULE_CPU0)
#endif

#ifndef ON_AURIX_VP
#define ON_AURIX_VP       0
#endif

#define IFXSTM_RELTIMER_OFFSET     (0x0138U)

#define IFXSTM_CMP0_OFFSET         (0x0120U)

#define IFXSTM_CMP1_OFFSET         (0x0124U)

#define IFXSTM_CMCON_OFFSET        (0x0128U)

#define IFXSTM_ICR_OFFSET          (0x012CU)

#define IFXSTM_ISCR_OFFSET         (0x0130U)

#define IFXSTM_ISR_OFFSET          (0x0134U)

#define IFXSTM_OCS_OFFSET          (0x4U)

#define IFXSTM_ABS_OFFSET          (0x20U)

#define IFXSTM_VM0_RELTIMER_OFFSET (0x0118U)

#define IFXSTM_VM0_CMP0_OFFSET     (0x0100U)

#define IFXSTM_VM0_CMP1_OFFSET     (0x0104U)

#define IFXSTM_VM0_CMCON_OFFSET    (0x0108U)

#define IFXSTM_VM0_ICR_OFFSET      (0x010CU)

#define IFXSTM_VM0_ISCR_OFFSET     (0x0110U)

#define IFXSTM_VM0_ISR_OFFSET      (0x0114U)

#define IFXSTM_BASE_OFFSET         (0x20U)

/******************************************************************************/
/*--------------------------------Enumerations--------------------------------*/
/******************************************************************************/

/** \addtogroup IfxLld_Stm_Std_Enumerations
 * \{ */
/** \brief Comparator Id defined in MODULE_CPUx.ISCR.B.CMP0IRR(x = 0, 1, 2), MODULE_CPUx.ICR.B.CMP0IRR(x = 0, 1, 2)
 */
typedef enum
{
    IfxStm_Comparator_0 = 0,      /**< \brief Comparator Id 0  */
    IfxStm_Comparator_1           /**< \brief Comparator Id 1  */
} IfxStm_Comparator;

/** \brief Compare with relative or Absolute Timer
 */
typedef enum
{
    IfxStm_ComparatorComparison_absolute = 0,  /**< \brief Compare with Absolute timer */
    IfxStm_ComparatorComparison_relative = 1   /**< \brief Compare with relative timer */
} IfxStm_ComparatorComparison;

/** \brief Comparator Interrupt request source defined in MODULE_SRC.STM.STMCPU[index].SRx (x =0, 1)
 */
typedef enum
{
    IfxStm_ComparatorInterrupt_ir0 = 0,  /**< \brief Select STMIR0 */
    IfxStm_ComparatorInterrupt_ir1 = 1   /**< \brief Select STMIR1 */
} IfxStm_ComparatorInterrupt;

/** \brief Comparator start bit position defined in MODULE_CPUx.CMCON.B.MSTART0(x = 0,1,2)
 */
typedef enum
{
    IfxStm_ComparatorOffset_0 = 0,      /**< \brief Comparator start bit position 0 with 64 bit timer  */
    IfxStm_ComparatorOffset_1,          /**< \brief Comparator start bit position 1 with 64 bit timer  */
    IfxStm_ComparatorOffset_2,          /**< \brief Comparator start bit position 2 with 64 bit timer  */
    IfxStm_ComparatorOffset_3,          /**< \brief Comparator start bit position 3 with 64 bit timer  */
    IfxStm_ComparatorOffset_4,          /**< \brief Comparator start bit position 4 with 64 bit timer  */
    IfxStm_ComparatorOffset_5,          /**< \brief Comparator start bit position 5 with 64 bit timer  */
    IfxStm_ComparatorOffset_6,          /**< \brief Comparator start bit position 6 with 64 bit timer  */
    IfxStm_ComparatorOffset_7,          /**< \brief Comparator start bit position 7 with 64 bit timer  */
    IfxStm_ComparatorOffset_8,          /**< \brief Comparator start bit position 8 with 64 bit timer  */
    IfxStm_ComparatorOffset_9,          /**< \brief Comparator start bit position 9 with 64 bit timer  */
    IfxStm_ComparatorOffset_10,         /**< \brief Comparator start bit position 10 with 64 bit timer  */
    IfxStm_ComparatorOffset_11,         /**< \brief Comparator start bit position 11 with 64 bit timer  */
    IfxStm_ComparatorOffset_12,         /**< \brief Comparator start bit position 12 with 64 bit timer  */
    IfxStm_ComparatorOffset_13,         /**< \brief Comparator start bit position 13 with 64 bit timer  */
    IfxStm_ComparatorOffset_14,         /**< \brief Comparator start bit position 14 with 64 bit timer  */
    IfxStm_ComparatorOffset_15,         /**< \brief Comparator start bit position 15 with 64 bit timer  */
    IfxStm_ComparatorOffset_16,         /**< \brief Comparator start bit position 16 with 64 bit timer  */
    IfxStm_ComparatorOffset_17,         /**< \brief Comparator start bit position 17 with 64 bit timer  */
    IfxStm_ComparatorOffset_18,         /**< \brief Comparator start bit position 18 with 64 bit timer  */
    IfxStm_ComparatorOffset_19,         /**< \brief Comparator start bit position 19 with 64 bit timer  */
    IfxStm_ComparatorOffset_20,         /**< \brief Comparator start bit position 20 with 64 bit timer  */
    IfxStm_ComparatorOffset_21,         /**< \brief Comparator start bit position 21 with 64 bit timer  */
    IfxStm_ComparatorOffset_22,         /**< \brief Comparator start bit position 22 with 64 bit timer  */
    IfxStm_ComparatorOffset_23,         /**< \brief Comparator start bit position 23 with 64 bit timer  */
    IfxStm_ComparatorOffset_24,         /**< \brief Comparator start bit position 24 with 64 bit timer  */
    IfxStm_ComparatorOffset_25,         /**< \brief Comparator start bit position 25 with 64 bit timer  */
    IfxStm_ComparatorOffset_26,         /**< \brief Comparator start bit position 26 with 64 bit timer  */
    IfxStm_ComparatorOffset_27,         /**< \brief Comparator start bit position 27 with 64 bit timer  */
    IfxStm_ComparatorOffset_28,         /**< \brief Comparator start bit position 28 with 64 bit timer  */
    IfxStm_ComparatorOffset_29,         /**< \brief Comparator start bit position 29 with 64 bit timer  */
    IfxStm_ComparatorOffset_30,         /**< \brief Comparator start bit position 30 with 64 bit timer  */
    IfxStm_ComparatorOffset_31          /**< \brief Comparator start bit position 31 with 64 bit timer  */
} IfxStm_ComparatorOffset;

/** \brief Size of compare value to compare with timer defined in MODULE_CPUx.CMCON.B.MSIZE0(x = 0,1,2)
 */
typedef enum
{
    IfxStm_ComparatorSize_1Bit   = 0,   /**< \brief Size of compare value to compare with timer: 1 bit */
    IfxStm_ComparatorSize_2Bits  = 1,   /**< \brief Size of compare value to compare with timer: 2 bits */
    IfxStm_ComparatorSize_3Bits  = 2,   /**< \brief Size of compare value to compare with timer: 3 bits */
    IfxStm_ComparatorSize_4Bits  = 3,   /**< \brief Size of compare value to compare with timer: 4 bits */
    IfxStm_ComparatorSize_5Bits  = 4,   /**< \brief Size of compare value to compare with timer: 5 bits */
    IfxStm_ComparatorSize_6Bits  = 5,   /**< \brief Size of compare value to compare with timer: 6 bits */
    IfxStm_ComparatorSize_7Bits  = 6,   /**< \brief Size of compare value to compare with timer: 7 bits */
    IfxStm_ComparatorSize_8Bits  = 7,   /**< \brief Size of compare value to compare with timer: 8 bits */
    IfxStm_ComparatorSize_9Bits  = 8,   /**< \brief Size of compare value to compare with timer: 9 bits */
    IfxStm_ComparatorSize_10Bits = 9,   /**< \brief Size of compare value to compare with timer: 10 bits */
    IfxStm_ComparatorSize_11Bits = 10,  /**< \brief Size of compare value to compare with timer: 11 bits */
    IfxStm_ComparatorSize_12Bits = 11,  /**< \brief Size of compare value to compare with timer: 12 bits */
    IfxStm_ComparatorSize_13Bits = 12,  /**< \brief Size of compare value to compare with timer: 13 bits */
    IfxStm_ComparatorSize_14Bits = 13,  /**< \brief Size of compare value to compare with timer: 14 bits */
    IfxStm_ComparatorSize_15Bits = 14,  /**< \brief Size of compare value to compare with timer: 15 bits */
    IfxStm_ComparatorSize_16Bits = 15,  /**< \brief Size of compare value to compare with timer: 16 bits */
    IfxStm_ComparatorSize_17Bits = 16,  /**< \brief Size of compare value to compare with timer: 17 bits */
    IfxStm_ComparatorSize_18Bits = 17,  /**< \brief Size of compare value to compare with timer: 18 bits */
    IfxStm_ComparatorSize_19Bits = 18,  /**< \brief Size of compare value to compare with timer: 19 bits */
    IfxStm_ComparatorSize_20Bits = 19,  /**< \brief Size of compare value to compare with timer: 20 bits */
    IfxStm_ComparatorSize_21Bits = 20,  /**< \brief Size of compare value to compare with timer: 21 bits */
    IfxStm_ComparatorSize_22Bits = 21,  /**< \brief Size of compare value to compare with timer: 22 bits */
    IfxStm_ComparatorSize_23Bits = 22,  /**< \brief Size of compare value to compare with timer: 23 bits */
    IfxStm_ComparatorSize_24Bits = 23,  /**< \brief Size of compare value to compare with timer: 24 bits */
    IfxStm_ComparatorSize_25Bits = 24,  /**< \brief Size of compare value to compare with timer: 25 bits */
    IfxStm_ComparatorSize_26Bits = 25,  /**< \brief Size of compare value to compare with timer: 26 bits */
    IfxStm_ComparatorSize_27Bits = 26,  /**< \brief Size of compare value to compare with timer: 27 bits */
    IfxStm_ComparatorSize_28Bits = 27,  /**< \brief Size of compare value to compare with timer: 28 bits */
    IfxStm_ComparatorSize_29Bits = 28,  /**< \brief Size of compare value to compare with timer: 29 bits */
    IfxStm_ComparatorSize_30Bits = 29,  /**< \brief Size of compare value to compare with timer: 30 bits */
    IfxStm_ComparatorSize_31Bits = 30,  /**< \brief Size of compare value to compare with timer: 31 bits */
    IfxStm_ComparatorSize_32Bits = 31   /**< \brief Size of compare value to compare with timer: 32 bits */
} IfxStm_ComparatorSize;

/** \brief Enable/disable the sensitivity of the module to sleep signal\n
 * Definition in Ifx_STM.CLC.B.EDIS
 */
typedef enum
{
    IfxStm_SleepMode_enable  = 0, /**< \brief enables sleep mode */
    IfxStm_SleepMode_disable = 1  /**< \brief disables sleep mode */
} IfxStm_SleepMode;

/** \brief OCDS Suspend Control
 * Definition in Ifx_CPU_STM.OCS.B.SUS
 */
typedef enum
{
    IfxStm_SuspendMode_none = 0,  /**< \brief No suspend */
    IfxStm_SuspendMode_hard = 1,  /**< \brief Hard Suspend */
    IfxStm_SuspendMode_soft = 2   /**< \brief Soft Suspend */
} IfxStm_SuspendMode;

/** \} */

/******************************************************************************/
/*-----------------------------Data Structures--------------------------------*/
/******************************************************************************/

/** \addtogroup IfxLld_Stm_Std_Structures
 * \{ */
/** \brief Comparator Configuration Structure
 */
typedef struct
{
    IfxStm_Comparator           comparator;                /**< \brief Comparator Id defined in STMx.ISCR.B.CMP0IRR(x = 0, 1, 2). */
    IfxStm_ComparatorInterrupt  comparatorInterrupt;       /**< \brief Comparator Interrupt request source defined in SRx (x =0, 1). */
    IfxStm_ComparatorOffset     compareOffset;             /**< \brief Comparator start bit position  defined in STMx.CMCON.B.MSTART0(x = 0,1,2). */
    IfxStm_ComparatorSize       compareSize;               /**< \brief Size of compare value to compare with timer defined in STMx.CMCON.B.MSIZE0(x = 0,1,2). */
    IfxStm_ComparatorComparison comparison;                /**< \brief Compare with Relative or Absolute timer */
    uint32                      ticks;                     /**< \brief count for next comparison from current timer count. Range: 0 to 0xFFFFFFFF. */
    Ifx_Priority                triggerPriority;           /**< \brief Interrupt priority. Range = 0 .. 255. 0 = interrupt is disabled. */
    IfxSrc_Tos                  typeOfService;             /**< \brief Type of service. */
    IfxSrc_VmId                 vmId;                      /**< \brief Virtual Machine number */
} IfxStm_CompareConfig;

/** \} */

/** \addtogroup IfxLld_Stm_Std_Module
 * \{ */

/******************************************************************************/
/*-------------------------Inline Function Prototypes-------------------------*/
/******************************************************************************/

/** \brief Returns system timer value.
 *
 * \param[in] cpu Pointer to System timer module registers.
 *
 * \retval uint64 System timer value. Range: 0 to 0xFFFFFFFFFFFFFFFF.
 */
IFX_INLINE uint64 IfxStm_get(Ifx_CPU *cpu);

/** \brief Returns the system timer frequency.
 *
 * \retval uint64 The system timer frequency in Hz. Range: 0 to 0xFFFFFFFFFFFFFFFF.
 */
IFX_INLINE uint64 IfxStm_getFrequency(void);

/** \brief Returns the module's suspend state.
 *
 * \param[in] cpu Pointer to STM module registers.
 *
 * \retval TRUE If module is suspended.
 *         FALSE If module is not suspended.
 */
IFX_INLINE boolean IfxStm_isModuleSuspended(Ifx_CPU *cpu);

/** \brief Configure the Module to Hard/Soft suspend mode.
 * Note: The api works only when the OCDS is enabled and in Supervisor Mode. When OCDS is disabled the OCS suspend control is ineffective.
 *
 * \param[inout] cpu  Pointer to STM module registers.
 * \param[in]    mode Module suspend mode. Range: \ref IfxStm_SuspendMode.
 *
 * \retval None
 */
IFX_INLINE void IfxStm_setSuspendMode(Ifx_CPU *cpu, IfxStm_SuspendMode mode);

/******************************************************************************/
/*-------------------------Global Function Prototypes-------------------------*/
/******************************************************************************/

/** \brief Disables the Stm module.
 *
 * \param[inout] cpu Pointer to STM registers.
 *
 * \retval None
 */
IFX_EXTERN void IfxStm_disableModule(Ifx_CPU *cpu);

/** \brief enable suspend by debugger.
 * Note: The API will write into the OCS register only if OCDS is enabled.
 *
 * \param[inout] cpu Pointer to System timer module registers.
 *
 * \retval None
 */
IFX_EXTERN void IfxStm_enableOcdsSuspend(Ifx_CPU *cpu);

/** \brief Returns the module index of the selected STM module.
 *
 * \param[in] stm Pointer to STM module registers.
 *
 * \retval Ifx_CPU* Pointer to the STM module register address.
 */
IFX_EXTERN Ifx_CPU *IfxStm_getAddress(IfxStm_Index stm);

/** \brief API to get the resource index of the STM specified.
 *
 * \param[in] cpu Pointer to System timer module registers.
 *
 * \retval IfxStm_Index System timer module index. Range: \ref IfxStm_Index.
 */
IFX_EXTERN IfxStm_Index IfxStm_getIndex(Ifx_CPU *cpu);

/** \} */

/** \addtogroup IfxLld_Stm_Std_Timer
 * \{ */

/******************************************************************************/
/*-------------------------Inline Function Prototypes-------------------------*/
/******************************************************************************/

/** \brief Returns the timer value shifted right by offset.
 *
 * \param[in] cpu    Pointer to System timer module registers.
 * \param[in] offset Offset value. Range: 0 to 63.
 *
 * \retval uint64 the lower system timer value shifted by offset. Range: 0 to 0xFFFFFFFFFFFFFFFF.
 */
IFX_INLINE uint64 IfxStm_getOffsetTimer(Ifx_CPU *cpu, uint8 offset);

/** \brief Wait for requested time.
 * The macro waits in while loop for the specified time in system timer ticks.
 *
 * \param[in] cpu   Pointer to System timer module registers.
 * \param[in] ticks Ticks Wait time in system timer ticks. Range: 0 to 0xFFFFFFFFFFFFFFFF.
 *
 * \retval None
 */
IFX_INLINE void IfxStm_waitTicks(Ifx_CPU *cpu, uint64 ticks);

/** \} */

/** \addtogroup IfxLld_Stm_Std_Comparator
 * \{ */

/******************************************************************************/
/*-------------------------Inline Function Prototypes-------------------------*/
/******************************************************************************/

/** \brief Returns the updated compare register value.
 *
 * \param[in] cpu        Pointer to System timer module registers.
 * \param[in] comparator Comparator selection comparator.
 *
 * \retval uint32 The compare value.  Range: 0 to 0xFFFFFFFF.
 */
IFX_INLINE uint32 IfxStm_getCompare(Ifx_CPU *cpu, IfxStm_Comparator comparator);

/** \brief Returns the number of ticks for the selected micro seconds based on the STM frequency.
 *
 * \param[in] microSeconds Number of micro seconds that need to be converted to ticks. Range: 0 to 0xFFFFFFFF.
 *
 * \retval uint64 Ticks. Range: 0 to 0xFFFFFFFFFFFFFFFF.
 */
IFX_INLINE uint64 IfxStm_getTicksFromMicroseconds(uint32 microSeconds);

/** \brief Returns the number of ticks for the selected milli seconds based on the STM frequency.
 *
 * \param[in] milliSeconds Number of micro seconds that need to be converted to ticks. Range: 0 to 0xFFFFFFFF.
 *
 * \retval uint64 Ticks. Range: 0 to 0xFFFFFFFFFFFFFFFF.
 */
IFX_INLINE uint64 IfxStm_getTicksFromMilliseconds(uint32 milliSeconds);

/** \brief Update the compare register value increased with given ticks.
 *
 * \param[inout] cpu        Pointer to System timer module registers.
 * \param[in]    comparator Comparator selection comparator. Range: \ref IfxStm_Comparator.
 * \param[in]    ticks      Count for next comparison from current timer count. Range: 0 to 0xFFFFFFFF.
 *
 * \retval None
 */
IFX_INLINE void IfxStm_increaseCompare(Ifx_CPU *cpu, IfxStm_Comparator comparator, uint32 ticks);

/** \brief Update the compare register value.
 *
 * \param[inout] cpu        Pointer to System timer module registers.
 * \param[in]    comparator Comparator selection comparator. Range: \ref IfxStm_Comparator.
 * \param[in]    ticks      Count for next comparison. Range: 0 to 0xFFFFFFFF.
 *
 * \retval None
 */
IFX_INLINE void IfxStm_updateCompare(Ifx_CPU *cpu, IfxStm_Comparator comparator, uint32 ticks);

/** \brief Returns the number of micro seconds for the selected ticks based on the STM frequency.
 * Note: The user to ensure that overflow doesnt occur.
 *
 * \param[in] ticks Number of ticks that need to be converted to microseconds. Range: 0 to 0xFFFFFFFFFFFFFFFF.
 *
 * \retval uint64 Microseconds. Range: 0 to 0xFFFFFFFFFFFFFFFF.
 */
IFX_INLINE uint64 IfxStm_getMicrosecondsFromTicks(uint64 ticks);

/** \brief Returns the number of milliseconds for the selected ticks based on the STM frequency.
 * Note: The user to ensure that overflow doesn't occur.
 *
 * \param[in] ticks Number of ticks that need to be converted to milliseconds. Range: 0 to 0xFFFFFFFFFFFFFFFF.
 *
 * \retval uint64 Milliseconds. Range: 0 to 0xFFFFFFFFFFFFFFFF.
 */
IFX_INLINE uint64 IfxStm_getMillisecondsFromTicks(uint64 ticks);

/** \brief Returns the number of nano seconds for the selected ticks based on the STM frequency.
 * Note: The user to ensure that overflow doesnt occur.
 *
 * \param[in] ticks Number of ticks that need to be converted to nanoseconds. Range: 0 to 0xFFFFFFFFFFFFFFFF.
 *
 * \retval uint64 Nanoseconds. Range: 0 to 0xFFFFFFFFFFFFFFFF.
 */
IFX_INLINE uint64 IfxStm_getNanosecondsFromTicks(uint64 ticks);

/******************************************************************************/
/*-------------------------Global Function Prototypes-------------------------*/
/******************************************************************************/

/** \brief Clear the compare interrupt flag.
 *
 * \param[inout] cpu        Pointer to System timer module registers.
 * \param[in]    comparator Comparator selection comparator. Range: \ref IfxStm_Comparator.
 *
 * \retval None
 */
IFX_EXTERN void IfxStm_clearCompareFlag(Ifx_CPU *cpu, IfxStm_Comparator comparator);

/** \brief Disables the compare interrupt.
 *
 * \param[inout] cpu        Pointer to System timer module registers.
 * \param[in]    comparator Comparator selection comparator. Range: \ref IfxStm_Comparator.
 *
 * \retval None
 */
IFX_EXTERN void IfxStm_disableComparatorInterrupt(Ifx_CPU *cpu, IfxStm_Comparator comparator);

/** \brief Enables the compare interrupt.
 *
 * \param[inout] cpu        Pointer to System timer module registers.
 * \param[in]    comparator Comparator selection comparator. Range: \ref IfxStm_Comparator.
 *
 * \retval None
 */
IFX_EXTERN void IfxStm_enableComparatorInterrupt(Ifx_CPU *cpu, IfxStm_Comparator comparator);

/** \brief get the interrupt source pointer for the comparator.
 *
 * \param[in] Index      STM index.
 * \param[in] comparator Comparator selection comparator. Range: \ref IfxStm_Comparator.
 *
 * \retval Ifx_SRC_SRCR* Pointer to the interrupt source.
 */
IFX_EXTERN volatile Ifx_SRC_SRCR *IfxStm_getSrcPointer(IfxStm_Index index, IfxStm_ComparatorInterrupt comparator);

/** \brief Initialise stm compare register.
 *
 * \param[inout] cpu    Pointer to System timer module registers.
 * \param[in]    config Pointer to configuration structure.
 *
 * \retval TRUE If the comparator was successfully initialized.
 *         FALSE If the comparator was not successfully initialized.
 */
IFX_EXTERN boolean IfxStm_initCompare(Ifx_CPU *cpu, const IfxStm_CompareConfig *config);

/** \brief Initialise compare configuration with default values.
 *
 * \param[inout] config Pointer to configuration structure.
 *
 * \retval None
 */
IFX_EXTERN void IfxStm_initCompareConfig(IfxStm_CompareConfig *config);

/** \brief Indicates if the compare interrupt flag is set.
 *
 * \param[in] cpu        Pointer to System timer module registers.
 * \param[in] comparator Comparator selection comparator. Range: \ref IfxStm_Comparator.
 *
 * \retval TRUE If the interrupt flag is set.
 *         FALSE If the interrupt flag is not set.
 */
IFX_EXTERN boolean IfxStm_isCompareFlagSet(Ifx_CPU *cpu, IfxStm_Comparator comparator);

/** \brief Set the compare behavior.
 *
 * \param[inout] cpu        Pointer to System timer module registers.
 * \param[in]    comparator Comparator selection comparator. Range: \ref IfxStm_Comparator.
 * \param[in]    offset     Comparator start bit position. Range: \ref IfxStm_ComparatorOffset.
 * \param[in]    size       Size of compare value to compare with timer. Range: \ref IfxStm_ComparatorSize.
 * \param[in]    interrupt  Comparator Interrupt request source defined. Range: \ref IfxStm_ComparatorInterrupt.
 *
 * \retval None
 */
IFX_EXTERN void IfxStm_setCompareControl(Ifx_CPU *cpu, IfxStm_Comparator comparator, IfxStm_ComparatorOffset offset, IfxStm_ComparatorSize size, IfxStm_ComparatorInterrupt interrupt);

/** \brief Configure access to all masters to all the STMs in the device.
 *
 * \param[in] apConfig Config pointer to configuration structure.
 *
 * \retval None
 */
IFX_EXTERN void IfxStm_configureAccessToStms(IfxApApu_ApuConfig *apConfig);

/** \} */

/******************************************************************************/
/*-------------------------Inline Function Prototypes-------------------------*/
/******************************************************************************/

/** \brief Returns the STM counter value.
 *
 * \retval sint64 Returns the STM counter value.
 */
IFX_INLINE sint64 IfxStm_now(void);

/** \brief Get the deadline value.
 *
 * \param[in] timeout Timeout value.
 *
 * \retval sint64 Return the deadline.
 */
IFX_INLINE sint64 IfxStm_getDeadLine(sint64 timeout);

/** \brief Checked if deadline has occured.
 *
 * \param[in] deadLine Deadline value.
 *
 * \retval TRUE If the deadline has occurred.
 *         FALSE If If the deadline has not occurred.
 */
IFX_INLINE boolean IfxStm_isDeadLine(sint64 deadLine);

/** \brief Waits for a specific time.
 *
 * \param[in] timeout Timeout value.
 *
 * \retval None
 */
IFX_INLINE void IfxStm_wait(sint64 timeout);

/** \brief Returns system Relative timer value.
 *
 * \param[in] cpu Pointer to System timer module registers.
 *
 * \retval uint64 System timer value. Range: 0 to 0xFFFFFFFFFFFFFFFF.
 */
IFX_INLINE uint64 IfxStm_getRelTimer(Ifx_CPU *cpu);

/** \brief Enables the STM module.
 *
 * \param[inout] cpu Pointer to the stm instance.
 *
 * \retval None
 */
IFX_INLINE void IfxStm_enableModule(Ifx_CPU *cpu);

/** \brief STM module enable status.
 *
 * \param[in] cpu Pointer to the stm instance.
 *
 * \retval TRUE If the STM module is enabled.
 *         FALSE If the STM module is disabled.
 * cpu->STM.CLC.B.DISS = 0, then module is enabled and if cpu->STM.CLC.B.DISS =1, then stm module is disabled.
 */
IFX_INLINE boolean IfxStm_getModuleStatus(Ifx_CPU *cpu);

/******************************************************************************/
/*---------------------Inline Function Implementations------------------------*/
/******************************************************************************/

IFX_INLINE uint64 IfxStm_get(Ifx_CPU *cpu)
{
    uint64 result;

    result = (uint64)cpu->STM.ABS.U;

    return result;
}


IFX_INLINE uint32 IfxStm_getCompare(Ifx_CPU *cpu, IfxStm_Comparator comparator)
{
#if (IFX_CFG_STM_MORPHING_ENABLE)
    Ifx_CPU_STM_CMP *cmp0 = (Ifx_CPU_STM_CMP *)((uint32)cpu + (uint32)(IFXSTM_CMP0_OFFSET));
    Ifx_CPU_STM_CMP *cmp1 = (Ifx_CPU_STM_CMP *)((uint32)cpu + (uint32)(IFXSTM_CMP1_OFFSET));
#else
#if (IFXSTM_IS_STMHV_AVAILABLE)
    uint32           vmId = (uint32)IfxCpu_getVirtualMachine();
    Ifx_CPU_STM_CMP *cmp0 = (Ifx_CPU_STM_CMP *)(&cpu->STMHV.VM[vmId].CMP[0]);
    Ifx_CPU_STM_CMP *cmp1 = (Ifx_CPU_STM_CMP *)(&cpu->STMHV.VM[vmId].CMP[1]);
#else
    Ifx_CPU_STM_CMP *cmp0 = (Ifx_CPU_STM_CMP *)(&cpu->STM.CMP[0]);
    Ifx_CPU_STM_CMP *cmp1 = (Ifx_CPU_STM_CMP *)(&cpu->STM.CMP[1]);
#endif /* #if (IFXSTM_IS_STMHV_AVAILABLE) */
#endif /* #if (IFX_CFG_STM_MORPHING_ENABLE) */
    if (comparator == IfxStm_Comparator_0)
    {
        return cmp0->B.CMPVAL;
    }
    else if (comparator == IfxStm_Comparator_1)
    {
        return cmp1->B.CMPVAL;
    }
    else
    {
        return 0U;
    }
}


IFX_INLINE uint64 IfxStm_getFrequency(void)
{
    uint64 result;

    result = (uint64)IfxClock_getStmFrequency();

    return result;
}


IFX_INLINE uint64 IfxStm_getOffsetTimer(Ifx_CPU *cpu, uint8 offset)
{
    uint64 now;

    now = IfxStm_get(cpu);

    return now >> offset;
}


IFX_INLINE uint64 IfxStm_getTicksFromMicroseconds(uint32 microSeconds)
{
    uint64 freq = IfxStm_getFrequency();
    return (freq / (1000000)) * microSeconds;
}


IFX_INLINE uint64 IfxStm_getTicksFromMilliseconds(uint32 milliSeconds)
{
    uint64 freq = IfxStm_getFrequency();
    return (freq / (1000)) * milliSeconds;
}


IFX_INLINE void IfxStm_increaseCompare(Ifx_CPU *cpu, IfxStm_Comparator comparator, uint32 ticks)
{
#if (IFX_CFG_STM_MORPHING_ENABLE)
    Ifx_CPU_STM_CMP *cmp0 = (Ifx_CPU_STM_CMP *)((uint32)cpu + (uint32)(IFXSTM_CMP0_OFFSET));
    Ifx_CPU_STM_CMP *cmp1 = (Ifx_CPU_STM_CMP *)((uint32)cpu + (uint32)(IFXSTM_CMP1_OFFSET));
#else
#if (IFXSTM_IS_STMHV_AVAILABLE)
    uint32           vmId = (uint32)IfxCpu_getVirtualMachine();
    Ifx_CPU_STM_CMP *cmp0 = (Ifx_CPU_STM_CMP *)(&cpu->STMHV.VM[vmId].CMP[0]);
    Ifx_CPU_STM_CMP *cmp1 = (Ifx_CPU_STM_CMP *)(&cpu->STMHV.VM[vmId].CMP[1]);
#else
    Ifx_CPU_STM_CMP *cmp0 = (Ifx_CPU_STM_CMP *)(&cpu->STM.CMP[0]);
    Ifx_CPU_STM_CMP *cmp1 = (Ifx_CPU_STM_CMP *)(&cpu->STM.CMP[1]);
#endif /* #if (IFXSTM_IS_STMHV_AVAILABLE) */
#endif /* #if (IFX_CFG_STM_MORPHING_ENABLE) */

    if (comparator == IfxStm_Comparator_0)
    {
        cmp0->B.CMPVAL = cmp0->B.CMPVAL + ticks;
    }
    else if (comparator == IfxStm_Comparator_1)
    {
        cmp1->B.CMPVAL = cmp1->B.CMPVAL + ticks;
    }
    else
    {
        /* Do nothing */
    }
}


IFX_INLINE boolean IfxStm_isModuleSuspended(Ifx_CPU *cpu)
{
    Ifx_CPU_STM_OCS  ocs;
    Ifx_CPU_STM_OCS *stmOcs = (Ifx_CPU_STM_OCS *)((uint32)cpu + (uint32)(IFXSTM_OCS_OFFSET));

    // read the status
    ocs.U = stmOcs->U;

    // return the status
    return ocs.B.SUSSTA;
}


IFX_INLINE void IfxStm_setSuspendMode(Ifx_CPU *cpu, IfxStm_SuspendMode mode)
{
    /* TODO  : Update with PROT */
    Ifx_CPU_STM_OCS  ocs;
    Ifx_CPU_STM_OCS *stmOcs = (Ifx_CPU_STM_OCS *)((uint32)cpu + (uint32)(IFXSTM_OCS_OFFSET));

    // remove protection and configure the suspend mode.
    ocs.B.SUS_P = 1;
    ocs.B.SUS   = mode;
    stmOcs->U   = ocs.U;
}


IFX_INLINE void IfxStm_updateCompare(Ifx_CPU *cpu, IfxStm_Comparator comparator, uint32 ticks)
{
#if (IFX_CFG_STM_MORPHING_ENABLE)
    Ifx_CPU_STM_CMP *cmp0 = (Ifx_CPU_STM_CMP *)((uint32)cpu + (uint32)(IFXSTM_CMP0_OFFSET));
    Ifx_CPU_STM_CMP *cmp1 = (Ifx_CPU_STM_CMP *)((uint32)cpu + (uint32)(IFXSTM_CMP1_OFFSET));
#else
#if (IFXSTM_IS_STMHV_AVAILABLE)
    uint32           vmId = (uint32)IfxCpu_getVirtualMachine();
    Ifx_CPU_STM_CMP *cmp0 = (Ifx_CPU_STM_CMP *)(&cpu->STMHV.VM[vmId].CMP[0]);
    Ifx_CPU_STM_CMP *cmp1 = (Ifx_CPU_STM_CMP *)(&cpu->STMHV.VM[vmId].CMP[1]);
#else
    Ifx_CPU_STM_CMP *cmp0 = (Ifx_CPU_STM_CMP *)(&cpu->STM.CMP[0]);
    Ifx_CPU_STM_CMP *cmp1 = (Ifx_CPU_STM_CMP *)(&cpu->STM.CMP[1]);
#endif /* #if (IFXSTM_IS_STMHV_AVAILABLE) */
#endif /* #if (IFX_CFG_STM_MORPHING_ENABLE) */

    if (comparator == IfxStm_Comparator_0)
    {
        cmp0->B.CMPVAL = ticks;
    }
    else if (comparator == IfxStm_Comparator_1)
    {
        cmp1->B.CMPVAL = ticks;
    }
    else
    {
        /* Do Nothing */
    }
}


IFX_INLINE void IfxStm_waitTicks(Ifx_CPU *cpu, uint64 ticks)
{
    uint64 beginTime;

    beginTime = (uint64)IfxStm_get(cpu);

    /*below code will work because of unsigned 32 bit calculation even at timer wrapping condition
     * As an example if beginTime = 0xFFFFFFFE and current time = 2 (after overflow), unsigned calculation
     * 2 - 0xFFFFFFFE will be 4*/
    while ((IfxStm_get(cpu) - beginTime) < ticks)
    {}
}


IFX_INLINE sint64 IfxStm_now(void)
{
    sint64  stmNow;
    boolean interruptState;

    interruptState = IfxCpu_disableInterrupts();
    stmNow         = (Ifx_TickTime)IfxStm_get(IFXSTM_DEFAULT_TIMER) & TIME_INFINITE;
    IfxCpu_restoreInterrupts(interruptState);

    return stmNow;
}


IFX_INLINE sint64 IfxStm_getDeadLine(sint64 timeout)
{
    sint64 deadLine;

    if (timeout == TIME_INFINITE)
    {
        deadLine = TIME_INFINITE;
    }
    else
    {
        deadLine = IfxStm_now() + timeout;
    }

    return deadLine;
}


IFX_INLINE boolean IfxStm_isDeadLine(sint64 deadLine)
{
    boolean result;

    if (deadLine == TIME_INFINITE)
    {
        result = FALSE;
    }
    else
    {
        result = IfxStm_now() >= deadLine;
    }

    return result;
}


IFX_INLINE void IfxStm_wait(sint64 timeout)
{
    sint64 deadLine = IfxStm_getDeadLine(timeout);

    while (IfxStm_isDeadLine(deadLine) == FALSE)
    {}
}


IFX_INLINE uint64 IfxStm_getRelTimer(Ifx_CPU *cpu)
{
    uint64           result;
#if (IFX_CFG_STM_MORPHING_ENABLE)
    Ifx_CPU_STM_REL *rel  = (Ifx_CPU_STM_REL *)((uint32)cpu + (uint32)(IFXSTM_RELTIMER_OFFSET));
#else
#if (IFXSTM_IS_STMHV_AVAILABLE)
    uint32           vmId = (uint32)IfxCpu_getVirtualMachine();
    Ifx_CPU_STM_REL *rel  = (Ifx_CPU_STM_REL *)(&cpu->STMHV.VM[vmId].RELTIM);
#else
    Ifx_CPU_STM_REL *rel = (Ifx_CPU_STM_REL *)(&cpu->STM.RELTIM);
#endif /* #if (IFXSTM_IS_STMHV_AVAILABLE) */
#endif /* #if (IFX_CFG_STM_MORPHING_ENABLE) */
    result = (uint64)rel->U;

    return result;
}


IFX_INLINE uint64 IfxStm_getMicrosecondsFromTicks(uint64 ticks)
{
    uint64 freq = (uint64)IfxStm_getFrequency();
    return (uint64)((1000000 * ticks) / freq);
}


IFX_INLINE uint64 IfxStm_getMillisecondsFromTicks(uint64 ticks)
{
    uint64 freq = (uint64)IfxStm_getFrequency();
    return (uint64)((1000 * ticks) / freq);
}


IFX_INLINE uint64 IfxStm_getNanosecondsFromTicks(uint64 ticks)
{
    uint64 freq = (uint64)IfxStm_getFrequency();
    return (uint64)((1000000000 * ticks) / freq);
}


IFX_INLINE void IfxStm_enableModule(Ifx_CPU *cpu)
{
    if (cpu->STM.CLC.B.DISS == 1)
    {
        cpu->STM.CLC.B.DISR = 0;
    }
}


IFX_INLINE boolean IfxStm_getModuleStatus(Ifx_CPU *cpu)
{
    return (boolean)cpu->STM.CLC.B.DISS;
}


#endif /* IFXSTM_H */
