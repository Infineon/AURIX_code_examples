/**
 * \file IfxIom.h
 * \brief IOM  basic functionality
 * \ingroup IfxLld_Iom
 *
 * \version iLLD_1_0_1_9_0
 * \copyright Copyright (c) 2018 Infineon Technologies AG. All rights reserved.
 *
 *
 *                                 IMPORTANT NOTICE
 *
 *
 * Infineon Technologies AG (Infineon) is supplying this file for use
 * exclusively with Infineon's microcontroller products. This file can be freely
 * distributed within development tools that are supporting such microcontroller
 * products.
 *
 * THIS SOFTWARE IS PROVIDED "AS IS".  NO WARRANTIES, WHETHER EXPRESS, IMPLIED
 * OR STATUTORY, INCLUDING, BUT NOT LIMITED TO, IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE APPLY TO THIS SOFTWARE.
 * INFINEON SHALL NOT, IN ANY CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL,
 * OR CONSEQUENTIAL DAMAGES, FOR ANY REASON WHATSOEVER.
 *
 * \defgroup IfxLld_Iom_Std_Enumeration Enumeration
 * \ingroup IfxLld_Iom_Std
 * \defgroup IfxLld_Iom_Std_Utility Utility Functions
 * \ingroup IfxLld_Iom_Std
 * \defgroup IfxLld_Iom_Std_Enumeration_Obsolete Enumeration Obsolete (NOt recommended for use)
 * \ingroup IfxLld_Iom_Std
 * \defgroup IfxLld_Iom_Std_Module_Obsolete Module Functions Obsolete (NOt recommended for use)
 * \ingroup IfxLld_Iom_Std
 */

#ifndef IFXIOM_H
#define IFXIOM_H 1

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include "_Impl/IfxIom_cfg.h"
#include "IfxIom_reg.h"
#include "Scu/Std/IfxScuWdt.h"
#include "Cpu/Std/IfxCpu_Intrinsics.h"

/******************************************************************************/
/*--------------------------------Enumerations--------------------------------*/
/******************************************************************************/

/** \addtogroup IfxLld_Iom_Std_Enumeration
 * \{ */
/** \brief Event source configuration
 * IOM_LAMCFGm.MOS
 */
typedef enum
{
    IfxIom_LamEventSource_mon       = 0, /**< \brief Monitor signal is sourced directly from FPCmch */
    IfxIom_LamEventSource_monXorRef = 1  /**< \brief Monitor signal is EXOR'd with FPCrch */
} IfxIom_LamEventSource;

/** \brief Event trigger configuration
 * IOM_LAMCFGm.EDS upper two bits
 */
typedef enum
{
    IfxIom_LamEventTrigger_none        = 0,  /**< \brief Neither edge used to gate event generation */
    IfxIom_LamEventTrigger_risingEdge  = 1,  /**< \brief Positive edge used to gate event generation */
    IfxIom_LamEventTrigger_fallingEdge = 2,  /**< \brief Negative edge used to gate event generation */
    IfxIom_LamEventTrigger_anyEdge     = 3   /**< \brief Either edge used to gate event generation */
} IfxIom_LamEventTrigger;

/** \brief Timer clear event configuration
 * IOM_LAMCFGm.EDS upper lower bits
 */
typedef enum
{
    IfxIom_LamEventWindowClearEvent_none        = 0,  /**< \brief Neither edge used to clear event windowcounter */
    IfxIom_LamEventWindowClearEvent_risingEdge  = 1,  /**< \brief Positive edge used to clear event windowcounter */
    IfxIom_LamEventWindowClearEvent_fallingEdge = 2,  /**< \brief Negative edge used to clear event windowcounter */
    IfxIom_LamEventWindowClearEvent_anyEdge     = 3   /**< \brief Either edge used to clear event windowcounter */
} IfxIom_LamEventWindowClearEvent;

/** \brief Timer control source configuration
 *  IOM_LAMCFGm.EWS
 */
typedef enum
{
    IfxIom_LamEventWindowControlSource_ref = 0,  /**< \brief Event window generation is determined from the reference signal */
    IfxIom_LamEventWindowControlSource_mon = 1   /**< \brief Event window generation is determined from the monitor signal */
} IfxIom_LamEventWindowControlSource;

/** \brief Timer run configuration
 * IOM_LAMCFGm.RMS
 */
typedef enum
{
    IfxIom_LamEventWindowRunControl_freeRunning = 0,  /**< \brief Event window generation is free-running. */
    IfxIom_LamEventWindowRunControl_gated       = 1   /**< \brief Event window generation is gated with the monitor or reference signal */
} IfxIom_LamEventWindowRunControl;

/** \brief FPC filer mode
 * IOM_FPCCTRk.MOD, with additional definition for noFilter
 */
typedef enum
{
    IfxIom_LamFilterMode_delayDebounceBothEdge                               = 0,  /**< \brief Delayed Debounce Filter Mode on both edges */
    IfxIom_LamFilterMode_immediateDebounceBothEdge                           = 1,  /**< \brief Immediate Debounce Filter Mode on both edges */
    IfxIom_LamFilterMode_immediateDebounceRisingEdge                         = 2,  /**< \brief Rising edge: Immediate Debounce Filter Mode, falling edge: no filtering */
    IfxIom_LamFilterMode_immediateDebounceFallingEdge                        = 3,  /**< \brief Rising edge: no filtering, falling edge: Immediate Debounce Filter Mode */
    IfxIom_LamFilterMode_delayDebounceRisingEdgeImmediateDebounceFallingEdge = 4,  /**< \brief Rising edge: Delayed Debounce Filter Mode, falling edge: Immediate Debounce Filter Mode */
    IfxIom_LamFilterMode_immediateDebounceRisingEdgeDelayDebounceFallingEdge = 5,  /**< \brief Immediate Debounce Filter Mode, falling edge: Delayed Debounce Filter Mode */
    IfxIom_LamFilterMode_prescalerOnRisingEdge                               = 6,  /**< \brief Prescaler Mode (triggered on rising edge) */
    IfxIom_LamFilterMode_prescalerOnFallingEdge                              = 7,  /**< \brief Prescaler Mode (triggered on falling edge) */
    IfxIom_LamFilterMode_noFilter                                            = 8   /**< \brief No filter (value used for software only ) */
} IfxIom_LamFilterMode;

/** \brief Specifies the Logic Module Analyser Module Number
 */
typedef enum
{
    IfxIom_LamId_0 = 0,      /**< \brief Specifies the LAM Id0  */
    IfxIom_LamId_1,          /**< \brief Specifies the LAM Id1  */
    IfxIom_LamId_2,          /**< \brief Specifies the LAM Id2  */
    IfxIom_LamId_3,          /**< \brief Specifies the LAM Id3  */
    IfxIom_LamId_4,          /**< \brief Specifies the LAM Id4  */
    IfxIom_LamId_5,          /**< \brief Specifies the LAM Id5  */
    IfxIom_LamId_6,          /**< \brief Specifies the LAM Id6  */
    IfxIom_LamId_7,          /**< \brief Specifies the LAM Id7  */
    IfxIom_LamId_8,          /**< \brief Specifies the LAM Id8  */
    IfxIom_LamId_9,          /**< \brief Specifies the LAM Id9  */
    IfxIom_LamId_10,         /**< \brief Specifies the LAM Id10  */
    IfxIom_LamId_11,         /**< \brief Specifies the LAM Id11  */
    IfxIom_LamId_12,         /**< \brief Specifies the LAM Id12  */
    IfxIom_LamId_13,         /**< \brief Specifies the LAM Id13  */
    IfxIom_LamId_14,         /**< \brief Specifies the LAM Id14  */
    IfxIom_LamId_15          /**< \brief Specifies the LAM Id15  */
} IfxIom_LamId;

/** \brief Enable/disable the sensitivity of the module to sleep signal
 * Definition in Ifx_IOM.CLC.B.EDIS
 */
typedef enum
{
    IfxIom_SleepMode_enable  = 0, /**< \brief Enables sleep mode */
    IfxIom_SleepMode_disable = 1  /**< \brief Disables sleep mode */
} IfxIom_SleepMode;

/** \} */

/** \addtogroup IfxLld_Iom_Std_Enumeration_Obsolete
 * \{ */
/** \} */

/** \addtogroup IfxLld_Iom_Std_Utility
 * \{ */

/******************************************************************************/
/*-------------------------Inline Function Prototypes-------------------------*/
/******************************************************************************/

/** \brief Disables the IOM module .
 * \param iom Pointer to IOM module registers
 * \return None
 */
IFX_INLINE void IfxIom_disableModule(Ifx_IOM *iom);

/** \brief Enable the IOM module control.
 * \param iom Pointer to IOM module registers
 * \param clockDivider IOM clock divider. Set to 1 for max clock.
 * \return None
 */
IFX_INLINE void IfxIom_enableModule(Ifx_IOM *iom, uint8 clockDivider);

/** \brief Enable/disable the sensitivity of the module to sleep signal
 * \param iom Pointer to IOM registers
 * \param mode Mode selection (enable/disable)
 * \return None
 */
IFX_INLINE void IfxIom_setSleepMode(Ifx_IOM *iom, IfxIom_SleepMode mode);

/******************************************************************************/
/*-------------------------Global Function Prototypes-------------------------*/
/******************************************************************************/

/** \brief Return the frequency used for the filter and timers clock
 * FIXME to be updated once the clock documentation is clarified about clock value SPB / GTM? Check code where function is used if changed.
 * \param iom Pointer to IOM module registers
 */
IFX_EXTERN float32 IfxIom_getFrequency(Ifx_IOM *iom);

/** \brief Reset the IOM module
 * \param iom Pointer to IOM module registers
 * \return None
 */
IFX_EXTERN void IfxIom_resetModule(Ifx_IOM *iom);

/** \} */

/******************************************************************************/
/*---------------------Inline Function Implementations------------------------*/
/******************************************************************************/

IFX_INLINE void IfxIom_disableModule(Ifx_IOM *iom)
{
    uint16 psw = IfxScuWdt_getCpuWatchdogPassword();

    IfxScuWdt_clearCpuEndinit(psw);
    iom->CLC.B.DISR = 1;
    IfxScuWdt_setCpuEndinit(psw);
}


IFX_INLINE void IfxIom_enableModule(Ifx_IOM *iom, uint8 clockDivider)
{
    uint16 psw = IfxScuWdt_getCpuWatchdogPassword();

    IfxScuWdt_clearCpuEndinit(psw);
    iom->CLC.B.RMC  = clockDivider;
    iom->CLC.B.DISR = 0;
    IfxScuWdt_setCpuEndinit(psw);
}


IFX_INLINE void IfxIom_setSleepMode(Ifx_IOM *iom, IfxIom_SleepMode mode)
{
    uint16 passwd = IfxScuWdt_getCpuWatchdogPassword();
    IfxScuWdt_clearCpuEndinit(passwd);
    iom->CLC.B.EDIS = mode;
    IfxScuWdt_setCpuEndinit(passwd);
}


#endif /* IFXIOM_H */
