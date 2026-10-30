/**
 * \file IfxMtu.h
 * \brief MTU  basic functionality
 * \ingroup IfxLld_Mtu
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
 * \defgroup IfxLld_Mtu_Usage How to use the Mtu driver?
 * \ingroup IfxLld_Mtu
 *
 * The Memory Test Unit (MTU)  controls and monitors the test, initialization and data integrity checking functions of the various internal memories in the device
 *
 * The Mtu driver provides set of routines for various Mbist operations
 *
 * In the following sections it will be described, how to integrate the Mtu driver into the application framework.
 *
 * \section IfxLld_Mtu_SramInit Sram Initialisation
 * \subsection IfxLld_Mtu_Include Include Files
 *
 * Include following header file into your C code:
 * \code
 * #include <Mtu/IfxMtu.h>
 * // include below file only if interrupt mode is used.
 * #include "Src/Std/IfxSrc.h"
 * \endcode
 *
 * \subsection IfxLld_Mtu_Variables Variables
 *
 * \code
 * // used only if interrupt mode is used.
 * static IfxMtu_MbistSel mbistSel;
 * \endcode
 *
 * \subsection IfxLld_Mtu_Interrupt Interrupt Handler Installation
 *
 * See also \ref IfxLld_Cpu_Irq_Usage
 *
 * Define priorities for the Interrrupt handlers. This is normally done in the Ifx_IntPrioDef.h file:
 * \code
 * // priorities are normally defined in Ifx_IntPrioDef.h
 * #define IFX_INTPRIO_MTU  10
 *
 * \endcode
 *
 * Add the interrupt service routines to your C code. They have to call the Mtu interrupt handlers:
 * \code
 * IFX_INTERRUPT(mtuDoneISR, 0, IFX_INTPRIO_MTU)
 * {
 *     IfxMtu_isrDone();
 * }
 * \endcode
 *
 * Finally install the interrupt handlers in your initialisation function:
 * \code
 *         volatile Ifx_SRC_SRCR *src;
 *         src = &MODULE_SRC.MTUDONE ;
 *         IfxSrc_init(src, IfxCpu_Irq_getTos(IfxCpu_getCoreIndex()) , IFX_INTPRIO_MTU );
 *         IfxSrc_enable(src);
 *
 *     // install interrupt handlers
 *     IfxCpu_Irq_installInterruptHandler(&mtuDoneISR, IFX_INTPRIO_MTU);
 *     IfxCpu_enableInterrupts();
 * \endcode
 *
 * \subsection IfxLld_Mtu_ClearSram_SyncPolling Clear Sram (Synchronous polling mode)
 *
 * The Sram initialisation in synchronous polling mode (i.e wait till the complete operation is done) can be used as:
 *
 * \code
 *     clearSram(IfxMtu_MbistSel_cpu0Dspr);
 * \endcode
 *
 * \subsection IfxLld_Mtu_ClearSram_ASyncPolling Clear Sram (Asynchronous polling mode)
 *
 * The Sram initialisation can be triggered by calling IfxMtu_clearSramStart() function, then can be queried for completion in a task using IfxMtu_isMbistDone. Once it's completed, then IfxMtu_clearSramContinue() has to be
 * called.
 * Note: The Safety Endinit watchdog has to be cleared before and set after for the IfxMtu_clearSramStart() and IfxMtu_clearSramContinue() functions.
 *
 * Following code triggers Sram initilisation.
 * \code
 *
 *     uint16 password         = 0;
 *
 *     password = IfxScuWdt_getSafetyWatchdogPassword();
 *
 *     // Clear EndInit
 *     IfxScuWdt_clearSafetyEndinit(password);
 *
 *     IfxMtu_clearSramStart(IfxMtu_MbistSel_cpu0Dspr);
 *
 *     // Set EndInit Watchdog
 *     IfxScuWdt_setSafetyEndinit(password);
 * \endcode
 *
 * Sram initialisation status can be queried in a task and once done complete the operation using:
 * \code
 *     if (IfxMtu_isMbistDone(IfxMtu_MbistSel_cpu0Dspr))
 *     {
 *         // Sram Clear operation done
 *
 *         // Clear EndInit
 *         IfxScuWdt_clearSafetyEndinit(password);
 *
 *         IfxMtu_clearSramContinue(IfxMtu_MbistSel_cpu0Dspr);
 *
 *         // Set EndInit Watchdog
 *         IfxScuWdt_setSafetyEndinit(password);
 *     }
 *     else
 *     {
 *         // Sram operation is still in progress
 *     }
 * \endcode
 *
 * \subsection IfxLld_Mtu_ClearSram_ASyncInterrupt Clear Sram (Asynchronous interrupt mode)
 * Do the interrupt configuration and initialisation as specified in \ref IfxLld_Mtu_Interrupt
 * The Sram initialisation can be triggered by calling IfxMtu_clearSramStart() function. Once the operation is completed, Mtu Done isr is raised. Inside the Isr IfxMtu_clearSramContinue() has to be called.
 * Note: The Safety Endinit watchdog has to be cleared before and set after for the IfxMtu_clearSramStart() and IfxMtu_clearSramContinue() functions.
 *
 * Following code triggers Sram initialisation.
 * \code
 *
 *     uint16 password         = 0;
 *
 *     password = IfxScuWdt_getSafetyWatchdogPassword();
 *
 *     // Clear EndInit
 *     IfxScuWdt_clearSafetyEndinit(password);
 *
 *     mbistSel = IfxMtu_MbistSel_cpu0Dspr; // mbistSel is a static / global variable.
 *     IfxMtu_clearSramStart(mbistSel);
 *
 *     // Set EndInit Watchdog
 *     IfxScuWdt_setSafetyEndinit(password);
 * \endcode
 * In the Mtu done isr, the following code can be used.
 *
 * \code
 *     if (IfxMtu_isMbistDone(mbistSel))
 *     {
 *         // Sram Clear operation done
 *
 *         // Clear EndInit
 *         IfxScuWdt_clearSafetyEndinit(password);
 *
 *         IfxMtu_clearSramContinue(mbistSel);
 *
 *         // Set EndInit Watchdog
 *         IfxScuWdt_setSafetyEndinit(password);
 *     }
 *
 * \endcode
 *
 * \section IfxLld_Mtu_SramError Sram Error tracking
 * Example usage of Sram Error tracking
 * \code
 * IfxScuWdt_clearSafetyEndinit(password);
 *
 * IfxMtu_MbistSel mbistSel = IfxMtu_MbistSel_cpu1Dspr;
 * Ifx_MC *mc = (Ifx_MC *)(IFXMTU_MC_ADDRESS_BASE + 0x100 * mbistSel);
 *
 * IfxMtu_enableMbistShell(mbistSel);
 *
 * // for auto-init memories: wait for the end of the clear operation
 * while (IfxMtu_isAutoInitRunning(mbistSel))
 * {}
 * IfxMtu_enableErrorTracking(mbistSel, TRUE);
 * uint32 numEtrr = 5;
 * // print tracked error address
 * {
 *  Ifx_MC_ETRR trackedSramAddresses[IFXMTU_MAX_TRACKED_ADDRESSES];
 *  uint8  numTrackedAddresses = IfxMtu_getTrackedSramAddresses(mbistSel, trackedSramAddresses);
 *  for(uint32 i=0; i<numEtrr; ++i) {
 *                         printf("%d: Error Address:0x%04x, Error System Address:0x%04x \n",
 *                                    i,
 *                                    trackedSramAddresses[i].B.ADDR,
 *                                    IfxMtu_getSystemAddress(mbistSel, trackedSramAddresses[i]));
 *                       }
 *        }
 * }
 *
 * IfxMtu_disableMbistShell(mbistSel);
 * IfxScuWdt_setSafetyEndinit(password);
 * \endcode
 *
 * \section IfxLld_Mtu_MemoryTest Memory Tests
 * \subsection IfxLld_Mtu_MemoryTest_NDI Non Destructive Inversion Test
 *
 * Usage Example:
 * \code
 *     // Enable MTU clock
 *     {
 *         uint16 password = IfxScuWdt_getCpuWatchdogPassword();
 *         IfxScuWdt_clearCpuEndinit(password);
 *         IfxMtu_enableModule();
 *         IfxScuWdt_setCpuEndinit(password);
 *     }
 *
 *
 *     {
 *         uint16 password = IfxScuWdt_getSafetyWatchdogPassword();
 *         uint16 errAddr = 0;
 *         IfxScuWdt_clearSafetyEndinit(password);
 *
 *        // run Non distructive inversion test for cpu0 DSPR memory (Range selection disabled)
 *         IfxMtu_runNonDestructiveInversionTest(IfxMtu_MbistSel_cpu0Dspr, 0, 0xFF, 0, &errAddr);
 *       // Clear Error Flags which are set in case you want to run further tests
 *         IfxMtu_clearErrorTracking(IfxMtu_MbistSel_cpu0Dspr);
 *
 *         IfxScuWdt_setSafetyEndinit(password);
 *     }
 * \endcode
 *
 * \subsection IfxLld_Mtu_MemoryTest_CheckerBoard Checker Board Test
 * Usage Example:
 * \code
 *     // Enable MTU clock
 *     {
 *         uint16 password = IfxScuWdt_getCpuWatchdogPassword();
 *         IfxScuWdt_clearCpuEndinit(password);
 *         IfxMtu_enableModule();
 *         IfxScuWdt_setCpuEndinit(password);
 *     }
 *
 *
 *     {
 *         uint16 password = IfxScuWdt_getSafetyWatchdogPassword();
 *         uint16 errAddr = 0;
 *         IfxScuWdt_clearSafetyEndinit(password);
 *        // run checkerboard test for cpu0 DSPR memory (Range selection disabled)
 *         IfxMtu_runCheckerBoardTest(IfxMtu_MbistSel_cpu0Dspr, 0, 0xFFFF, 0, &errAddr, 0);
 *
 *         IfxScuWdt_setSafetyEndinit(password);
 *     }
 * \endcode
 *
 * \subsection IfxLld_Mtu_MemoryTest_MarchU MarchU Test
 * Usage Example:
 * \code
 *     // Enable MTU clock
 *     {
 *         uint16 password = IfxScuWdt_getCpuWatchdogPassword();
 *         IfxScuWdt_clearCpuEndinit(password);
 *         IfxMtu_enableModule();
 *         IfxScuWdt_setCpuEndinit(password);
 *     }
 *
 *
 *     {
 *         uint16 password = IfxScuWdt_getSafetyWatchdogPassword();
 *         uint16 errAddr = 0;
 *         IfxScuWdt_clearSafetyEndinit(password);
 *        // run March U test for cpu0 DSPR memory (Range selection disabled)
 *         IfxMtu_runMarchUTest(IfxMtu_MbistSel_cpu0Dspr, 0, 0xFFFF, 0, &errAddr);
 *
 *         IfxScuWdt_setSafetyEndinit(password);
 *     }
 * \endcode
 *
 * \defgroup IfxLld_Mtu_Std_Utility Utility Functions
 * \ingroup IfxLld_Mtu_Std
 * \defgroup IfxLld_Mtu_Std_Operative MBIST Operations
 * \ingroup IfxLld_Mtu_Std
 * \defgroup IfxLld_Mtu_Std_ErrorTracking MBIST Error Tracking
 * \ingroup IfxLld_Mtu_Std
 */

#ifndef IFXMTU_H
#define IFXMTU_H 1

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include "_Impl/IfxMtu_cfg.h"
#include "IfxMtu_reg.h"
#include "IfxScu_reg.h"
#include "_Utilities/Ifx_Assert.h"
#include "Scu/Std/IfxScuWdt.h"
#include "Scu/Std/IfxScuCcu.h"
#include "IfxMtu_bf.h"

/******************************************************************************/
/*-----------------------------------Macros-----------------------------------*/
/******************************************************************************/

#define IFXMTU_WAIT_TIMEOUTCOUNT                 (((sint32)0x1000))

#define IFXMTU_LOOP_TIMEOUT_CHECK(tVar, tErr) \
    {                                         \
        if (((sint32)--tVar) <= 0)            \
        {                                     \
            tErr = (uint8)1;                  \
            break;                            \
        }                                     \
        else                                  \
        {                                     \
        }                                     \
    }

/** \brief Configuration patterns for the MBIST
 * Array of configurations which are used by MCx_CONFIG0 register
 */
#define IFXMTU_MBIST_CONFIG_NONDISTTEST_MCONTROL {(0x4008U)}

#define IFXMTU_MBIST_CONFIG_NONDISTTEST_CONFIG0       \
    {                                                 \
        (                                             \
            (5U << IFX_MTU_MC_CONFIG0_ACCSTYPE_OFF) | \
            (4U << IFX_MTU_MC_CONFIG0_NUMACCS_OFF)    \
        )                                             \
    }

#define IFXMTU_MBIST_CONFIG_NONDISTTEST_CONFIG1       \
    {                                                 \
        (                                             \
            (8U << IFX_MTU_MC_CONFIG1_ACCSPAT_OFF) |  \
            (0U << IFX_MTU_MC_CONFIG1_SELFASTB_OFF) | \
            (5U << IFX_MTU_MC_CONFIG1_AG_MOD_OFF)     \
        )                                             \
    }

/** \brief Mask for the ERROR flags
 */
#define IFXMTU_ERROR_FLAGS_MASK                                               \
    (((unsigned int)IFX_MTU_MC_ECCD_EOV_MSK << IFX_MTU_MC_ECCD_EOV_OFF) |     \
     ((unsigned int)IFX_MTU_MC_ECCD_CERR_MSK << IFX_MTU_MC_ECCD_CERR_OFF) |   \
     ((unsigned int)IFX_MTU_MC_ECCD_UCERR_MSK << IFX_MTU_MC_ECCD_UCERR_OFF) | \
     ((unsigned int)IFX_MTU_MC_ECCD_MERR_MSK << IFX_MTU_MC_ECCD_MERR_OFF))

/******************************************************************************/
/*-----------------------------Data Structures--------------------------------*/
/******************************************************************************/

/** \addtogroup IfxLld_Mtu_Std_Operative
 * \{ */
typedef struct
{
    Ifx_MTU_MC_CONFIG0 config0;
    Ifx_MTU_MC_CONFIG1 config1;
} IfxMtu_MbistConfigPattern;

typedef struct
{
    IfxMtu_MbistSel sshSel;                            /**< \brief Member (config0) */
    uint8           lowAddress;                        /**< \brief Lower address (scrambled) of memory Range to be tested. Range: 0. */
    uint8           highAddress;                       /**< \brief Higher address (scrambled) of memory Range to be tested. Range: 1 to 0x7F. */
    uint8           uncorrectableErrorThreshold;       /**< \brief Threshold number for uncorrectable errors. Range: 0 to 5. */
    uint8           preClearEnable;                    /**< \brief Enable SRAM clearing before the test. Range: 0 to 1. */
} IfxMtu_MbistSshConfig;

/** \} */

/** \addtogroup IfxLld_Mtu_Std_Operative
 * \{ */
typedef struct
{
    Ifx_MTU_MC_MCONTROL                  mcontrol;                     /**< \brief Value of MCONTROL register except START bit */
    uint8                                numOfSshConfigurations;       /**< \brief Number of SSH Configurations in the memory test. Range: 0 to 0xFF. */
    uint8                                numOfConfigPatterns;          /**< \brief Number of configuration patterns. Range: 0 to 0xFF. */
    IFX_CONST IfxMtu_MbistSshConfig     *sshConfigurations;            /**< \brief Pointer to number of SSH configuration structures */
    IFX_CONST IfxMtu_MbistConfigPattern *configPatterns;               /**< \brief Pointer to number of configuration patterns */
} IfxMtu_MbistConfig;

/** \} */

/** \addtogroup IfxLld_Mtu_Std_Utility
 * \{ */

/******************************************************************************/
/*-------------------------Inline Function Prototypes-------------------------*/
/******************************************************************************/

/**
 * \brief Disables the MBIST Shell of the given SRAM.
 *
 * \param[in] mbistSel The memory selection to disable the MBIST Shell for. Range: \ref IfxMtu_MbistSel.
 *
 * \retval None
 *
 * Usage Example
 * \code
 *
 *     IfxMtu_disableMbistShell(IfxMtu_MbistSel_cpu0Dtag);
 *
 *     // Note: Wait for Auto-initilisation to be completed for auto-init memories like cpu-Dtag, cpu-Ptag,  Cpu-Dcache, Cpu-Pcache
 *     while (IfxMtu_isAutoInitRunning(IfxMtu_MbistSel_cpu0Dtag))
 *     {}
 * \endcode
 *
 */
IFX_INLINE void IfxMtu_disableMbistShell(IfxMtu_MbistSel mbistSel);

/**
 * \brief Enables the MBIST Shell of the given SRAM.
 *
 * \param[in] mbistSel The memory selection for which the MBIST Shell should be enabled. Range: \ref IfxMtu_MbistSel.
 *
 * \retval None
 *
 * Usage Example
 * \code
 *     // Enable MTU clock
 *     {
 *         uint16 password = IfxScuWdt_getCpuWatchdogPassword();
 *         IfxScuWdt_clearCpuEndinit(password);
 *         IfxMtu_enableModule();
 *         IfxScuWdt_setCpuEndinit(password);
 *     }
 *
 *     {
 *       IfxMtu_enableMbistShell(IfxMtu_MbistSel_cpu0Dtag);
 *
 *       // Note: Wait for Auto-initilisation to be completed for auto-init memories like cpu-Dtag, cpu-Ptag,  Cpu-Dcache, Cpu-Pcache,
 *       while (IfxMtu_isAutoInitRunning(IfxMtu_MbistSel_cpu0Dtag))
 *       {}
 *     }
 * \endcode
 *
 */
IFX_INLINE void IfxMtu_enableMbistShell(IfxMtu_MbistSel mbistSel);

/**
 * \brief Enables the MTU module and its operations.
 *
 * \retval None
 *
 */
IFX_INLINE void IfxMtu_enableModule(void);

/**
 * \brief Returns register offset (x) and register bit offset (y) (MEMDONE[x].B.y).
 *
 * \param[in] mbistSel Memory Selection. Range: \ref IfxMtu_MbistSel.
 *
 * \retval uint32 A 32-bit unsigned integer representing the combined register offset (x) and bit offset (y) for MEMDONE[x].B.y. Range: 0 to 0xFFFF FFFF.
 *
 */
IFX_INLINE uint32 IfxMtu_getMemDoneRegisterIndex(IfxMtu_MbistSel mbistSel);

/**
 * \brief Returns TRUE if Auto-Initialisation is running for the given SRAM.
 * Should be polled after MBIST enableMbistShell to ensure that an auto-init operation is finished before starting a new operation.
 *
 * \param[in] mbistSel Memory Selection. Range: \ref IfxMtu_MbistSel.
 *
 * \retval TRUE If Auto-Initialisation is running for the selected memory block.
 *         FALSE If Auto-Initialisation is not running for the selected memory block.
 *
 */
IFX_INLINE boolean IfxMtu_isAutoInitRunning(IfxMtu_MbistSel mbistSel);

/**
 * \brief Checks if the MTU module is enabled  or not.
 *
 * \retval TRUE If the module is enabled.
 *         FALSE If the module is disabled.
 *
 */
IFX_INLINE boolean IfxMtu_isModuleEnabled(void);

/** \} */

/** \addtogroup IfxLld_Mtu_Std_Operative
 * \{ */

/******************************************************************************/
/*-------------------------Inline Function Prototypes-------------------------*/
/******************************************************************************/

/**
 * \brief Disables alarm-reporting flags for the specified memory block.
 *
 * \param[in] mbistSel Memory Selection. Range: \ref IfxMtu_MbistSel.
 *
 * \retval None
 *
 */
IFX_INLINE void IfxMtu_disableErrorReporting(IfxMtu_MbistSel mbistSel);

/**
 * \brief Enables alarm-reporting flags for the specified memory block.
 *
 * \param[in] mbistSel Memory Selection. Range: \ref IfxMtu_MbistSel.
 *
 * \retval None
 * 
 */
IFX_INLINE void IfxMtu_enableErrorReporting(IfxMtu_MbistSel mbistSel);

/**
 * \brief Checks if the MBIST clear SRAM operation is completed.
 *
 * \param[in] mbistSel Memory Selection. Range: \ref IfxMtu_MbistSel.
 *
 * \retval TRUE Operation is completed.
 *         FALSE Operation is still in progress.
 *
 */
IFX_INLINE boolean IfxMtu_isMbistDone(IfxMtu_MbistSel mbistSel);

/******************************************************************************/
/*-------------------------Global Function Prototypes-------------------------*/
/******************************************************************************/

/**
 * \brief Clears the MBIST SRAM in synchronous mode.
 * This function clears the MBIST SRAM and manages the endinit bit to prevent watchdog timeouts.
 * The endinit state is automatically restored to its original value at the end of the function.
 *
 * \param[in] mbistSel Memory Selection. Range: \ref IfxMtu_MbistSel.
 *
 * \retval None
 * 
 * A coding example can be found in \ref IfxLld_Mtu_Usage
 *
 */
IFX_EXTERN void IfxMtu_clearSram(IfxMtu_MbistSel mbistSel);

/**
 * \brief Continues the MBIST Clear SRAM operation after it has been completed.
 * Note: The function must be called with the safety endinit bit cleared.
 *
 * \param[in] mbistSel Memory Selection. Range: \ref IfxMtu_MbistSel.
 *
 * \retval None
 *
 * A coding example can be found in \ref IfxLld_Mtu_Usage
 * 
 */
IFX_EXTERN void IfxMtu_clearSramContinue(IfxMtu_MbistSel mbistSel);

/**
 * \brief This Function triggers the Clear the MBIST SRAM operation (Asynchronous operation). It doesn't wait till the end of operation.
 * The application has to poll the Mbist status (IfxMtu_isMbistDone()) in a task and once the operation is done, the IfxMtu_clearSramContinue() function should be called to complete the operation.
 * Alternately the application can enable the "memory test done" interrupt. And in the ISR, the IfxMtu_clearSramContinue()  has to be called.
 * If Synchronous usage is need, use IfxMtu_clearSram() function.
 * Note: The function should be called with safety endinit bit cleared.
 *
 * \param[in] mbistSel Memory Selection. Range: \ref IfxMtu_MbistSel.
 *
 * \retval None
 *
 * A coding example can be found in \ref IfxLld_Mtu_Usage
 *
 */
IFX_EXTERN void IfxMtu_clearSramStart(IfxMtu_MbistSel mbistSel);

/**
 * \brief Checks if the last MBIST test passed for all configured SSH cells.
 *  This function shall check for all the configured SSH cells if the tests were passed
 *
 * \param[in] mbistConfig Pointer to the configuration structure for the RAM test.
 *
 * \retval TRUE All MBIST tests passed successfully.
 *         FALSE At least one MBIST test failed.
 *
 */
IFX_EXTERN boolean IfxMtu_isTestPass(const IfxMtu_MbistConfig *mbistConfig);

/**
 * \brief Reads data from the specified SRAM address in the MTU module based on the memory selection.
 *
 * \param[in] mbistSel    Memory Selection. Range: \ref IfxMtu_MbistSel.
 * \param[in] sramAddress SRAM address to be read. Range: 0 to 65535.
 *
 * \retval None
 *
 * A coding example can be found in \ref IfxLld_Mtu_Usage
 *
 */
IFX_EXTERN void IfxMtu_readSramAddress(IfxMtu_MbistSel mbistSel, uint16 sramAddress);

/**
 * \brief Run CheckerBoard test. This test consists of writing the physical checkerboard pattern into the memory, then reading it back for verification.
 * Note: The function clears & sets safety endinit bit while running the test to prevent watchdog TO and automatically restores the endinit state (same state at the time of entering the function) at the end.
 * Note: Though 8-bit function arguments are used for "range", only 7-bits are valid, and the user must check documentation before passing the correct values.
 *
 * \param[in]    mbistSel              Memory block selection. Specifies which memory block to test. Range: \ref IfxMtu_MbistSel.
 * \param[in]    rangeSel              Enable/disable range Selection (0 - disable, 1- enable). Range: 0 to 255.
 * \param[in]    rangeAddrUp           when range mode is enabled, it specifies the upper logical block address limit in 64 word increments. Range: 0 to 255.
 * \param[in]    rangeAddrLow          when range mode is enabled, it specifies the lower logical block address limit. Range: 0 to 255.
 * \param[inout] errorAddr             If the test fails, it contains the error address (bit0 - bit12) and memory block index (Bit13 - Bit15). Range: 0 to 65535.
 * \param[in]    numberRedundancyLines Number of redundancy lines. Range: 0 to 65535.
 *
 * \retval TRUE Test failed.
 *         FALSE Test passed successfully.
 *
 */
IFX_EXTERN uint8 IfxMtu_runCheckerBoardTest(IfxMtu_MbistSel mbistSel, uint8 rangeSel, uint8 rangeAddrUp, uint8 rangeAddrLow, uint16 *errorAddr, uint32 numberRedundancyLines);

/**
 * \brief Run March U test.  This test MARCHES 0 and 1 values through the memory array in an up and down direction. More precisely, 0 and 1 values are propagated through the memory in each direction;
 * i.e. a single bit cell toggles into each direction with the neighboring cells having a given value and, in another run, the inverse given value.
 * Note: The function clears & sets safety endinit bit while running the test to prevent watchdog TO and automatically restores the endinit state (same state at the time of entering the function) at the end.
 * Note: Though 8-bit function arguments are used for "range", only 7-bits are valid, and the user must check documentation before passing the correct values.
 *
 * \param[in]    mbistSel     Memory block selection. Specifies which memory block to test. Range: \ref IfxMtu_MbistSel.
 * \param[in]    rangeSel     Enable/disable range Selection (0 - disable, 1- enable). Range: 0 to 255.
 * \param[in]    rangeAddrUp  when range mode is enabled, it specifies the upper logical block address limit in 64 word increments. Range: 0 to 255.
 * \param[in]    rangeAddrLow when range mode is enabled, it specifies the lower logical block address limit. Range: 0 to 255.
 * \param[inout] errorAddr    If the test fails, it contains the error address (bit0 - bit12) and memory block index (Bit13 - Bit15). Range: 0 to 65535.
 *
 * \retval TRUE Test failed.
 *         FALSE Test passed successfully.
 *
 */
IFX_EXTERN uint8 IfxMtu_runMarchUTest(IfxMtu_MbistSel mbistSel, uint8 rangeSel, uint8 rangeAddrUp, uint8 rangeAddrLow, uint16 *errorAddr);

/**
 * \brief This function runs the Non-Destructive Inversion test algorithm.
 * Non-Destructive Inversion test can be considered as a simple linear test that is able to find all Stuck-At faults (the cell remains stuck at a value for any operation) without destroying any user data. The test accesses every Word in the address range defined by the RANGE register, four times.
 * Test Steps:
 * 1. Read data Word including check bits
 * 2. write back all bits inverted
 * 3. Read data Word including check bits
 * 4. Write back all bits inverted
 * At the end of this procedure the user data remains unchanged and and every bit has been set to 0 and 1. Any single Stuck-At error will be visible as a correctable error.
 * Note: The function clears & sets safety endinit bit while running the test to prevent watchdog TO and automatically restores the endinit state (same state at the time of entering the function) at the end.
 * The Error flags need to be cleared to enable further tracking after the test
 * Note: Though 8-bit function arguments are used for "range", only 7-bits are valid, and the user must check documentation before passing the correct values.
 * 
 * \param[in]    mbistSel     The memory block selection. Range: \ref IfxMtu_MbistSel.
 * \param[in]    rangeSel     Enable/disable range Selection (0 - disable, 1- enable). Range: 0 to 255.
 * \param[in]    rangeAddrUp  when range mode is enabled, it specifies the upper logical block address limit in 64 word increments. Range: 0 to 255.
 * \param[in]    rangeAddrLow when range mode is enabled, it specifies the lower logical block address limit. Range: 0 to 255.
 * \param[inout] errorAddr    If the test fails, it contains the error address (bit0 - bit12) and memory block index (Bit13 - Bit15). Range: 0 to 65535.
 * 
 * \retval TRUE Test failed with errors detected.
 *         FALSE Test passed without errors.
 */
IFX_EXTERN uint8 IfxMtu_runNonDestructiveInversionTest(IfxMtu_MbistSel mbistSel, uint8 rangeSel, uint8 rangeAddrUp, uint8 rangeAddrLow, uint16 *errorAddr);

/**
 * \brief Writes the SRAM address for the selected MBIST memory region.
 *
 * \param[in] mbistSel    Memory selection for the MBIST operation. Range: \ref IfxMtu_MbistSel.
 * \param[in] sramAddress SRAM address to be written. The address must be within the range of a 16-bit unsigned integer. Range: 0 to 65535.
 *
 * \retval None
 * 
 */
IFX_EXTERN void IfxMtu_writeSramAddress(IfxMtu_MbistSel mbistSel, uint16 sramAddress);

/**
 * \brief Run the MBIST on all configured Gang configurations
 *    Requirements:
 *    1) This function shall run the tests on all SRAMs, which configured by the SSH structure array
 *    1.1) Address range (already scrambled address info) is made available through configuration
 *    1.2) Part of the test pattern is passed through MCONTROL
 *    2) For each cell, the test shall execute all the configuration patterns as passed through pattern array
 *    2.1) Test for each configuration pattern shall end either for the completion or for the failure
 *    2.2) Test shall only end if the test is finished (with or without pass) or timeout
 *    2.3) Failed test shall not be evaluated (this function only runs the tests)
 *    3) Function shall return TRUE if the test execution for one of the configuration patterns is not finished
 *    4) Function shall return FALSE if the test execution is finished
 *    Assumptions of usage:
 *    1) This function is not interrupted.
 *    2) DSPRAM of the CPU on which this function is running is being tested
 *    2) For destructive tests, the tested ram shall be re initialized by user
 *
 * \param[in] mbistConfig Pointer to the configuration structure for the RAM test.
 *
 * \retval TRUE Test execution is still running (at least one configuration pattern has not finished).
 *         FALSE Test execution has completed for all configuration patterns.
 *
 */
IFX_EXTERN boolean IfxMtu_runMbistAll(const IfxMtu_MbistConfig *const mbistConfig[]);

/**
 * \brief Run the MBIST on configured Gang configuration.
 *    Requirements:
 *    1) This function shall run the tests on all SRAMs, which configured by the SSH structure array
 *    1.1) Address range (already scrambled address info) is made available through configuration
 *    1.2) Part of the test pattern is passed through MCONTROL
 *    2) For each cell, the test shall execute all the configuration patterns as passed through pattern array
 *    2.1) Test for each configuration pattern shall end either for the completion or for the failure
 *    2.2) Test shall only end if the test is finished (with or without pass) or timeout
 *    2.3) Failed test shall not be evaluated (this function only runs the tests)
 *    3) Function shall return TRUE if the test execution for one of the configuration patterns is not finished
 *    4) Function shall return FALSE if the test execution is finished
 *    Assumptions of usage:
 *    1) This function is not interrupted.
 *    2) DSPRAM of the CPU on which this function is running is being tested
 *    2) For destructive tests, the tested ram shall be re initialized by user
 *
 * \param[in] mbistConfig Pointer to the configuration structure for the RAM test.
 * 
 * \retval TRUE Test is successfully finished.
 *         FALSE Test is not successfully finished.
 *
 */
IFX_EXTERN boolean IfxMtu_runMbist(const IfxMtu_MbistConfig *mbistConfig);

/** \} */

/** \addtogroup IfxLld_Mtu_Std_ErrorTracking
 * \{ */

/******************************************************************************/
/*-------------------------Inline Function Prototypes-------------------------*/
/******************************************************************************/

/**
 * \brief Checks if error tracking is enabled for the specified memory selection.
 *
 * \param[in] mbistSel The memory block selection for which to check error tracking status. Range: \ref IfxMtu_MbistSel.
 *
 * \retval TRUE Error tracking is enabled for the specified memory selection.
 *         FALSE Error tracking is disabled for the specified memory selection.
 *
 */
IFX_INLINE boolean IfxMtu_isErrorTrackingEnabled(IfxMtu_MbistSel mbistSel);

/**
 * \brief Checks if error tracking has overflowed or multiple memory blocks have errors.
 *
 * \param[in] mbistSel The memory block selection to check. Range: \ref IfxMtu_MbistSel.
 *
 * \retval TRUE If error tracking overflow has occurred or multiple memory blocks are in error.
 *         FALSE If no overflow or single memory block error is detected.
 *
 */
IFX_INLINE boolean IfxMtu_isErrorTrackingOverflow(IfxMtu_MbistSel mbistSel);

/**
 * \brief Checks if any error flags are set for the specified memory selection.
 *
 * \param[in] mbistSel The memory selection to check for error flags. Range: \ref IfxMtu_MbistSel.
 *
 * \retval TRUE If any error flags are set for the specified memory selection.
 *         FALSE If no error flags are set for the specified memory selection.
 *
 */
IFX_INLINE boolean IfxMtu_checkErrorFlags(IfxMtu_MbistSel mbistSel);

/******************************************************************************/
/*-------------------------Global Function Prototypes-------------------------*/
/******************************************************************************/

/**
 * \brief Clears the error tracking registers (ETRR), valid, and overflow bits for the specified memory selection.
 *
 * \param[in] mbistSel The memory block selection for which to clear the error tracking registers. Range: \ref IfxMtu_MbistSel.
 *
 * \retval None
 *
 * A coding example can be found in \ref IfxLld_Mtu_Usage
 *
 */
IFX_EXTERN void IfxMtu_clearErrorTracking(IfxMtu_MbistSel mbistSel);

/**
 * \brief Enables or disables the tracking of SRAM errors based on the provided parameters.
 *
 * \param[in] mbistSel The memory block selection identifier. This parameter specifies which memory block's error tracking is to be enabled or disabled. Range: \ref IfxMtu_MbistSel.
 * \param[in] enable   A boolean flag to control the error tracking feature. Set to TRUE to enable error tracking, FALSE to disable it.
 *
 * \retval None
 * 
 * A coding example can be found in \ref IfxLld_Mtu_Usage
 *
 */
IFX_EXTERN void IfxMtu_enableErrorTracking(IfxMtu_MbistSel mbistSel, boolean enable);

/** \brief Returns the descrambled system address based on a tracked SRAM error which consists of ADDR and MBI (SRAM address and block)
 * Please note that not all memories of the system are supported by this function.
 * Additional memories will be considered on request.
 *
 * \param[in] mbistSel           Memory Selection. Range: \ref IfxMtu_MbistSel.
 * \param[in] trackedSramAddress Tracked SRAM address which consists of an ADDR and MBI field (SRAM address and block).
 *
 * \retval uint32 Descrambled system address if supported by this function, otherwise 0. Range: 0 t0 0xFFFF FFFF.
 * 
 * Example usage: see \ref IfxMtu_getTrackedSramAddresses
 *
 */
IFX_EXTERN uint32 IfxMtu_getSystemAddress(IfxMtu_MbistSel mbistSel, Ifx_MTU_MC_ETRR trackedSramAddress);

/**
 * \brief Returns the tracked SRAM error addresses and memory blocks which are stored in the MBIST ETRR registers.
 *
 * \param[in]    mbistSel             Memory Selection. Range: \ref IfxMtu_MbistSel.
 * \param[inout] trackedSramAddresses will contain the tracked error addresses in trackedSramAdresses[x].B.ADDR and affected blocks in sramAddresses[x].B.MBI.
 *
 * The array size shall be IFXMTU_MAX_TRACKED_ADDRESSES
 *
 * \retval uint8 number of tracked errors (0..IFXMTU_MAX_TRACKED_ADDRESSES). Range: 0 to 4.
 *
 * Example usage to print out tracked errors of a given memory:
 *
 * We assume that the MTU clock has already been enabled, and that the MBIST instance has been selected; e.g. for LMU:
 * \code
 *     uint16 password = IfxScuWdt_getCpuWatchdogPassword();
 *     IfxScuWdt_clearCpuEndinit(password);
 *
 *     IfxMtu_enableModule();
 *
 *     IfxMtu_MbistSel mbistSel = IfxMtu_MbistSel_lmu;
 *
 *     IfxMtu_enableMbistShell(mbistSel);
 *
 *     // for auto-init memories: wait for the end of the clear operation
 *     while (IfxMtu_isAutoInitRunning(mbistSel))
 *         {}
 * \endcode
 *
 * Now the tracking information can be retrieved with:
 *
 * \code
 *     {
 *         Ifx_MC_ETRR trackedSramAddresses[IFXMTU_MAX_TRACKED_ADDRESSES];
 *         uint8  numTrackedAddresses = IfxMtu_getTrackedSramAddresses(mbistSel, trackedSramAddresses);
 *
 *         clib_ver_printf("Tracked addresses: %d (Overflow: %d)\n",
 *                         numTrackedAddresses,
 *                         IfxMtu_isErrorTrackingOverflow(mbistSel) ? 1 : 0);
 *
 *         for(int i=0; i<numTrackedAddresses; ++i) {
 *             clib_ver_printf("%d: A:0x%04x MBI:%d -> SystemAddress: 0x%08x\n",
 *                             i,
 *                             trackedSramAddresses[i].B.ADDR,
 *                             trackedSramAddresses[i].B.MBI,
 *                             IfxMtu_getSystemAddress(mbistSel, trackedSramAddresses[i]));
 *         }
 *     }
 * \endcode
 *
 */
IFX_EXTERN uint8 IfxMtu_getTrackedSramAddresses(IfxMtu_MbistSel mbistSel, Ifx_MTU_MC_ETRR *trackedSramAddresses);

/** \} */

/******************************************************************************/
/*---------------------Inline Function Implementations------------------------*/
/******************************************************************************/

IFX_INLINE void IfxMtu_disableErrorReporting(IfxMtu_MbistSel mbistSel)
{
    Ifx_MTU_MC *mc = &MODULE_MTU.MC[mbistSel];
    mc->ALMSRCS.B.MISCE = 0;
    mc->ALMSRCS.B.OPENE = 0;
}


IFX_INLINE void IfxMtu_disableMbistShell(IfxMtu_MbistSel mbistSel)
{
    volatile uint32 *mtuMemtest = (volatile uint32 *)((uint32)&MTU_MEMTEST0 + 4 * (mbistSel >> 5));
    uint32           mask       = 1 << (mbistSel & 0x1f);
    *mtuMemtest &= ~mask;
    /* Set EndInit Watchdog (to prevent Watchdog TO)*/
    uint16           password = IfxScuWdt_getSafetyWatchdogPassword();
    IfxScuWdt_setSafetyEndinit(password);

    while (!IfxMtu_isMbistDone(mbistSel))
    {
        __nop();
    }

    /* Clear EndInit */
    IfxScuWdt_clearSafetyEndinit(password);
    /*Enable Error Reporting  */
    Ifx_MTU_MC *mc = &MODULE_MTU.MC[mbistSel];
    mc->ALMSRCS.B.MISCE = 1;
    mc->ALMSRCS.B.OPENE = 1;
}


IFX_INLINE void IfxMtu_enableErrorReporting(IfxMtu_MbistSel mbistSel)
{
    Ifx_MTU_MC *mc = &MODULE_MTU.MC[mbistSel];
    mc->ALMSRCS.B.MISCE = 1;
    mc->ALMSRCS.B.OPENE = 1;
}


IFX_INLINE void IfxMtu_enableMbistShell(IfxMtu_MbistSel mbistSel)
{
    Ifx_MTU_MC      *mc = &MODULE_MTU.MC[mbistSel];
    mc->ALMSRCS.B.MISCE = 0;
    mc->ALMSRCS.B.OPENE = 0;
    volatile uint32 *mtuMemtest = (volatile uint32 *)((uint32)&MTU_MEMTEST0 + 4 * (mbistSel >> 5));
    uint32           mask       = 1 << (mbistSel & 0x1f);
    *mtuMemtest |= mask;
}


IFX_INLINE void IfxMtu_enableModule(void)
{
    uint8 isEndInitEnabled = 0;

    if (IfxScuWdt_getCpuWatchdogEndInit() == 1U)
    {
        /* Clear EndInit */
        IfxScuWdt_clearCpuEndinit(IfxScuWdt_getCpuWatchdogPassword());
        isEndInitEnabled = 1;
    }

    /* MTU clock enable */
    MTU_CLC.U = 0x0U;

    if (isEndInitEnabled == 1U)
    {
        IfxScuWdt_setCpuEndinit(IfxScuWdt_getCpuWatchdogPassword());
    }
}


IFX_INLINE uint32 IfxMtu_getMemDoneRegisterIndex(IfxMtu_MbistSel mbistSel)
{
    uint32 index;

    if (mbistSel > 63)
    {
        index = mbistSel - 64;
        index = index << 8 | 2;
    }
    else if (mbistSel > 31)
    {
        index = mbistSel - 32;
        index = index << 8 | 1;
    }
    else
    {
        index = mbistSel << 8;
    }

    return index;
}


IFX_INLINE boolean IfxMtu_isAutoInitRunning(IfxMtu_MbistSel mbistSel)
{
    volatile uint32 *mtuMemstat = (volatile uint32 *)((uint32)&MTU_MEMSTAT0 + 4 * (mbistSel >> 5));
    uint32           mask       = 1 << (mbistSel & 0x1f);
    return (*mtuMemstat & mask) != 0;
}


IFX_INLINE boolean IfxMtu_isErrorTrackingEnabled(IfxMtu_MbistSel mbistSel)
{
    Ifx_MTU_MC *mc = &MODULE_MTU.MC[mbistSel];
    return mc->ECCS.B.TRE ? TRUE : FALSE;
}


IFX_INLINE boolean IfxMtu_isErrorTrackingOverflow(IfxMtu_MbistSel mbistSel)
{
    Ifx_MTU_MC *mc = &MODULE_MTU.MC[mbistSel];
    return mc->ECCD.B.EOV ? TRUE : FALSE;
}


IFX_INLINE boolean IfxMtu_isMbistDone(IfxMtu_MbistSel mbistSel)
{
    volatile uint32 index;
    volatile uint32 bitIndex;
    uint32          memDone;

    index    = IfxMtu_getMemDoneRegisterIndex(mbistSel);
    bitIndex = index >> 8;
    index    = index & 0xF;
    memDone  = *((volatile uint32 *)(&MTU_MEMDONE0 + index));
    return ((memDone) >> bitIndex) & 0x1;
}


IFX_INLINE boolean IfxMtu_isModuleEnabled(void)
{
    return MTU_CLC.B.DISS == 0;
}


IFX_INLINE boolean IfxMtu_checkErrorFlags(IfxMtu_MbistSel mbistSel)
{
    Ifx_MTU_MC *mc = &MODULE_MTU.MC[mbistSel];
    return (boolean)((mc->ECCD.U & IFXMTU_ERROR_FLAGS_MASK) > 0);
}


#endif /* IFXMTU_H */
