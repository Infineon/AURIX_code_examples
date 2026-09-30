/**
 * \file IfxScrTimer01.h
 * \brief Timer0 and Timer1 basic functionality
 * \ingroup IfxLld_ScrTimer01
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
 * \defgroup IfxLld_ScrTimer01_Std_Enumerations Enumerations
 * \ingroup IfxLld_ScrTimer01_Std
 * \defgroup IfxLld_ScrTimer01_Std_DataStructures Data structures
 * \ingroup IfxLld_ScrTimer01_Std
 * \defgroup IfxLld_ScrTimer01_Std_Timer0Functionality Timer0 Functionality
 * \ingroup IfxLld_ScrTimer01_Std
 * \defgroup IfxLld_ScrTimer01_Std_Timer1Functionality Timer1 Functionality
 * \ingroup IfxLld_ScrTimer01_Std
 * \defgroup IfxLld_ScrTimer01_Std_init Timer01 Initialization Functionality
 * \ingroup IfxLld_ScrTimer01_Std
 *
 */

#ifndef IFXSCRTIMER01_H
#define IFXSCRTIMER01_H 1

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include "Ifx_Cfg.h"
#include "_Impl/IfxScrTimer01_cfg.h"
#if defined(DEVICE_TC4DX)
#include "_Reg/TC4Dx/IfxScr_bf.h"
#include "_Reg/TC4Dx/IfxScr_reg.h"
#elif defined(DEVICE_TC49XN)
#include "_Reg/TC49xN/IfxScr_bf.h"
#include "_Reg/TC49xN/IfxScr_reg.h"
#elif defined(DEVICE_TC48X)
#include "_Reg/TC48x/IfxScr_bf.h"
#include "_Reg/TC48x/IfxScr_reg.h"
#elif defined(DEVICE_TC48XAA)
#include "_Reg/TC48xAA/IfxScr_bf.h"
#include "_Reg/TC48xAA/IfxScr_reg.h"
#elif defined(DEVICE_TC46X)
#include "_Reg/TC46x/IfxScr_bf.h"
#include "_Reg/TC46x/IfxScr_reg.h"
#elif defined(DEVICE_TC44X)
#include "_Reg/TC44x/IfxScr_bf.h"
#include "_Reg/TC44x/IfxScr_reg.h"
#elif defined(DEVICE_TC4ZX)
#include "_Reg/TC4Zx/IfxScr_bf.h"
#include "_Reg/TC4Zx/IfxScr_reg.h"
#elif defined(DEVICE_TC4EX)
#include "_Reg/TC4Ex/IfxScr_bf.h"
#include "_Reg/TC4Ex/IfxScr_reg.h"
#elif defined(DEVICE_TC4PX)
#include "_Reg/TC4Px/IfxScr_bf.h"
#include "_Reg/TC4Px/IfxScr_reg.h"
#endif /* #if defined(DEVICE_TC4DX) */

/******************************************************************************/
/*-------------------------------Enumerations---------------------------------*/
/******************************************************************************/
/** \addtogroup IfxLld_ScrTimer01_Std_Enumerations
 * \{ */
/** \brief Enumeration for Timer0 and Timer 1 operating modes
 */
typedef enum
{
    IfxScrTimer01_Mode_0 = 0,   /**< \brief Mode 0: 13-bit timer/counter */
    IfxScrTimer01_Mode_1 = 1,   /**< \brief Mode 1: 16-bit timer/counter */
    IfxScrTimer01_Mode_2 = 2,   /**< \brief Mode 2: 8-bit timer/counter with auto-reload */
    IfxScrTimer01_Mode_3 = 3    /**< \brief Mode 3: Two 8-bit timers/counters */
} IfxScrTimer01_Mode;

/** \brief Enumeration for trigger control
 */
typedef enum
{
    IfxScrTimer01_TriggerControl_level = 0,   /**< \brief Low level triggered */
    IfxScrTimer01_TriggerControl_edge  = 1    /**< \brief Falling edge triggered */
} IfxScrTimer01_TriggerControl;

/******************************************************************************/
/*-----------------------------Data Structures--------------------------------*/
/******************************************************************************/

/** \addtogroup IfxLld_ScrTimer01_Std_DataStructures
 * \{ */

/* \brief Timer01 Config Structure
 *
 *
 * FIXME:Initial Value and Reload Value are not included in the config structure as it is not valid for all modes and might be an overhead.
 * Instead Standard layer API's are provided for loading initial value and reload value.
 *
 * */

typedef struct
{
    IfxScrTimer01_Mode timerMode;        /* Mode select for Timer0. Options: IfxScrTimer01_Mode_0,IfxScrTimer01_Mode_1,IfxScrTimer01_Mode_2,IfxScrTimer01_Mode_3. Set in T01_TMOD.T0M */
    uint8              timerClockSource; /* Clock source for Timer0. Options: IfxScrTimer01_ClockSource_pclk, IfxScrTimer01_ClockSource_t0 */
    uint8              timerRunControl;  /* Run Control for Timer0. Options: IfxScrTimer01_RunControl_swOnly,IfxScrTimer01_RunControl_hw  */
}IfxScrTimer01_TimerConfig;

/** \} */

/******************************************************************************/
/*-------------------------Inline Function Prototypes-------------------------*/
/******************************************************************************/

/** \addtogroup IfxLld_ScrTimer01_Std_Timer0Functionality
 *  \{ */

/** \brief Loads initial value into Timer 0
 * NOTE: Check the mode while passing the value.
 *
 * For Mode 0 and Mode 2, the lower 8 bits of the parameter 'initialValue' will be taken.
 *
 * For Mode 1, 16-bit initialValue shall be taken.
 *
 * For Mode 3, The two 8 bit values for TH0 and TL0 needs to be concatenated as TH0:TL0 and passed.
 * For example, if TH0 is to be loaded with 0x12 and TL0 is to be loaded with 0x34, 0x1234 is to be passed as second argument(initialValue)
 *
 * \param mode Mode of operation of Timer 0
 * \param initialValue Initial Value to be loaded into Timer 0
 * \return None
 */
IFX_INLINE void IfxScrTimer01_loadTimer0InitialValue(IfxScrTimer01_Mode mode, uint16 initialValue);

/** \brief Loads Reload value to Timer 0 in mode 2.
 * NOTE: This API is only applicable for Mode 2: AutoReload Mode
 * \param reloadValue Value to be loaded
 * \return None
 */
IFX_INLINE void IfxScrTimer01_loadTimer0ReloadValue(uint8 reloadValue);

/** \brief Start/resume Timer0 counting
 * \return None
 */
IFX_INLINE void IfxScrTimer01_runTimer0(void);

/** \brief Halt Timer0 counting
 * \return None
 */
IFX_INLINE void IfxScrTimer01_haltTimer0(void);

/** \brief Queries status of Timer 0 overflow event
 * \return Returns status of Timer 0 overflow event
 */
IFX_INLINE boolean IfxScrTimer01_hasTimer0OverflowOccured(void);

/** \brief Set mode for Timer0.
 * \param mode Mode in which Timer0 is desired to be operated.
 *             Options are:
 *               IfxScrTimer01_Mode_0
 *               IfxScrTimer01_Mode_1
 *               IfxScrTimer01_Mode_2
 *               IfxScrTimer01_Mode_3
 * \return None
 */
IFX_INLINE void IfxScrTimer01_setTimer0Mode(IfxScrTimer01_Mode mode);

/** \brief Set external interrupt level/edge trigger control
 * \return None
 */
IFX_INLINE void IfxScrTimer01_setTriggerControlTimer0(IfxScrTimer01_TriggerControl trigger);

/**  \} */

/** \addtogroup IfxLld_ScrTimer10_Std_Timer1Functionality
 *  \{ */

/** \brief Loads initial value into Timer 1
 * NOTE: Check the mode while passing the value.
 *
 * For Mode 0 and Mode 2, the lower 8 bits of the parameter 'initialValue' will be taken.
 *
 * For Mode 1, 16-bit initialValue shall be taken.
 *
 * For Mode 3, The two 8 bit values for TH0 and TL0 needs to be concatenated as TH0:TL0 and passed.
 * For example, if TH0 is to be loaded with 0x12 and TL0 is to be loaded with 0x34, 0x1234 is to be passed as second argument(initialValue)
 *
 * \param mode Mode of operation of Timer 1
 * \param initialValue Initial Value to be loaded into Timer 1
 * \return None
 */
IFX_INLINE void IfxScrTimer01_loadTimer1InitialValue(IfxScrTimer01_Mode mode, uint16 initialValue);

/** \brief Loads Reload value to Timer 1 in mode 2.
 * NOTE: This API is only applicable for Mode 2: AutoReload Mode
 * \param reloadValue Value to be loaded
 * \return None
 */
IFX_INLINE void IfxScrTimer01_loadTimer1ReloadValue(uint8 reloadValue);

/** \brief Start/resume Timer1 counting
 * \return None
 */
IFX_INLINE void IfxScrTimer01_runTimer1(void);

/** \brief Halt Timer1 counting
 * \return None
 */
IFX_INLINE void IfxScrTimer01_haltTimer1(void);

/** \brief Queries status of Timer 1 overflow event
 * \return Returns status of Timer 1 overflow event
 */
IFX_INLINE boolean IfxScrTimer01_hasTimer1OverflowOccured(void);

/** \brief Set mode for Timer1.
 * \param mode Mode in which Timer1 is desired to be operated.
 *             Options are:
 *               IfxScrTimer01_Mode_0
 *               IfxScrTimer01_Mode_1
 *               IfxScrTimer01_Mode_2
 *               IfxScrTimer01_Mode_3
 * \return None
 */
IFX_INLINE void IfxScrTimer01_setTimer1Mode(IfxScrTimer01_Mode mode);

/** \brief Set external interrupt level/edge trigger control Timer1
 * \return None
 */
IFX_INLINE void IfxScrTimer01_setTriggerControlTimer1(IfxScrTimer01_TriggerControl trigger);

/** \} */

/** \addtogroup IfxLld_ScrTimer01_Std_init
 * \{ */

/** \brief Configures Timer 0 for operation
 * \param timerConfig Timer01 configuration
 * \return None
 */
IFX_INLINE void IfxScrTimer01_configureTimer0(IfxScrTimer01_TimerConfig *timerConfig);

/** \brief Configures Timer 1 for operation
 * \param timerConfig Timer01 configuration
 * \return None
 */
IFX_INLINE void IfxScrTimer01_configureTimer1(IfxScrTimer01_TimerConfig *timerConfig);

/** \brief Halts both Timer 0 and Timer 1
 * \return None
 */
IFX_INLINE void IfxScrTimer01_haltAllTimers(void);

/** \} */

/******************************************************************************/
/*---------------------Inline Function Implementations------------------------*/
/******************************************************************************/

IFX_INLINE void IfxScrTimer01_loadTimer0InitialValue(IfxScrTimer01_Mode mode, uint16 initialValue)
{
    if ((mode == IfxScrTimer01_Mode_0) || (mode == IfxScrTimer01_Mode_2))
    {
        SCR_T01_TL0.U = (uint8)initialValue;
    }
    else if ((mode == IfxScrTimer01_Mode_1) || (mode == IfxScrTimer01_Mode_3))
    {
        SCR_T01_TH0.U = (uint8)(initialValue >> 8u);
        SCR_T01_TL0.U = (uint8)initialValue;
    }
}


IFX_INLINE void IfxScrTimer01_loadTimer0ReloadValue(uint8 reloadValue)
{
    SCR_T01_TH0.U = (uint8)reloadValue;
}


IFX_INLINE void IfxScrTimer01_runTimer0()
{
    SCR_T01_TCON.U = (SCR_T01_TCON.U | (1u << IFX_SCR_T01_TCON_TR0_OFF));
}


IFX_INLINE void IfxScrTimer01_haltTimer0()
{
    SCR_T01_TCON.U = (SCR_T01_TCON.U & ~(1u << IFX_SCR_T01_TCON_TR0_OFF));
}


IFX_INLINE boolean IfxScrTimer01_hasTimer0OverflowOccured()
{
    return (boolean)((SCR_T01_TCON.U & (1u << IFX_SCR_T01_TCON_TF0_OFF)) >> IFX_SCR_T01_TCON_TF0_OFF);
}


IFX_INLINE void IfxScrTimer01_setTimer0Mode(IfxScrTimer01_Mode mode)
{
    SCR_T01_TMOD.U = ((SCR_T01_TMOD.U & ~IFX_SCR_T01_TMOD_T0M_MSK) | mode);
}


IFX_INLINE void IfxScrTimer01_setTriggerControlTimer0(IfxScrTimer01_TriggerControl trigger)
{
    SCR_T01_TCON.U = ((SCR_T01_TCON.U & ~(IFX_SCR_T01_TCON_IT0_MSK)) | (trigger << IFX_SCR_T01_TCON_IT0_OFF));
}


IFX_INLINE void IfxScrTimer01_loadTimer1InitialValue(IfxScrTimer01_Mode mode, uint16 initialValue)
{
    if ((mode == IfxScrTimer01_Mode_0) || (mode == IfxScrTimer01_Mode_2))
    {
        SCR_T01_TL1.U = (uint8)initialValue;
    }
    else if (mode == IfxScrTimer01_Mode_1)
    {
        SCR_T01_TH1.U = (uint8)(initialValue >> 8);
        SCR_T01_TL1.U = (uint8)initialValue;
    }
}


IFX_INLINE void IfxScrTimer01_loadTimer1ReloadValue(uint8 reloadValue)
{
    SCR_T01_TH1.U = (uint8)reloadValue;
}


IFX_INLINE void IfxScrTimer01_runTimer1(void)
{
    SCR_T01_TCON.U = (SCR_T01_TCON.U | (1u << IFX_SCR_T01_TCON_TR1_OFF));
}


IFX_INLINE void IfxScrTimer01_haltTimer1(void)
{
    SCR_T01_TCON.U = (SCR_T01_TCON.U & ~(1u << IFX_SCR_T01_TCON_TR1_OFF));
}


IFX_INLINE boolean IfxScrTimer01_hasTimer1OverflowOccured(void)
{
    return (boolean)((SCR_T01_TCON.U & (1u << IFX_SCR_T01_TCON_TF1_OFF)) >> IFX_SCR_T01_TCON_TF1_OFF);
}


IFX_INLINE void IfxScrTimer01_setTimer1Mode(IfxScrTimer01_Mode mode)
{
    SCR_T01_TMOD.U = ((SCR_T01_TMOD.U & ~(IFX_SCR_T01_TMOD_T1M_MSK << IFX_SCR_T01_TMOD_T1M_OFF)) | mode << IFX_SCR_T01_TMOD_T1M_OFF);
}


IFX_INLINE void IfxScrTimer01_setTriggerControlTimer1(IfxScrTimer01_TriggerControl trigger)
{
    SCR_T01_TCON.U = ((SCR_T01_TCON.U & ~(IFX_SCR_T01_TCON_IT1_MSK << IFX_SCR_T01_TCON_IT1_OFF)) | (trigger << IFX_SCR_T01_TCON_IT1_OFF));
}


IFX_INLINE void IfxScrTimer01_configureTimer0(IfxScrTimer01_TimerConfig *timerConfig)
{
    SCR_T01_TMOD.U = (SCR_T01_TMOD.U & 0xF0U) | ((timerConfig->timerRunControl) << IFX_SCR_T01_TMOD_GATE0_OFF) | ((timerConfig->timerClockSource) << IFX_SCR_T01_TMOD_T0S_OFF) | (timerConfig->timerMode);
    /* Set TRx in case Run control is HW*/
    SCR_T01_TCON.U = (SCR_T01_TCON.U & 0xEFU) | ((timerConfig->timerRunControl) << IFX_SCR_T01_TCON_TR0_OFF);
}


IFX_INLINE void IfxScrTimer01_configureTimer1(IfxScrTimer01_TimerConfig *timerConfig)
{
    SCR_T01_TMOD.U = (SCR_T01_TMOD.U & 0x0FU) | (((timerConfig->timerRunControl) << IFX_SCR_T01_TMOD_GATE1_OFF) | ((timerConfig->timerClockSource) << IFX_SCR_T01_TMOD_T1S_OFF) | ((timerConfig->timerMode) << IFX_SCR_T01_TMOD_T1M_OFF));
    /* Set TRx in case Run control is HW*/
    SCR_T01_TCON.U = (SCR_T01_TCON.U & 0xBFU) | ((timerConfig->timerRunControl) << IFX_SCR_T01_TCON_TR1_OFF);
}


IFX_INLINE void IfxScrTimer01_haltAllTimers(void)
{
    SCR_T01_TCON.U = (SCR_T01_TCON.U & ~((1u << IFX_SCR_T01_TCON_TR1_OFF) | (1u << IFX_SCR_T01_TCON_TR0_OFF)));
}


#endif /* IFXSCRTIMER01_H */
