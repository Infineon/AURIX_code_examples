/**
 * \file IfxCcu6_TimerWithTrigger.h
 * \brief CCU6 TIMERWITHTRIGGER details
 * \ingroup IfxLld_Ccu6
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
 * \defgroup IfxLld_Ccu6_TimerWithTrigger_Usage How to use the CCU6 TimerWithTrigger Interface driver?
 * \ingroup IfxLld_Ccu6_TimerWithTrigger
 * This driver implements the timer functionalities as defined by \ref library_srvsw_stdif_timer.
 * The user is free to use either the driver specific APIs below or to used the \ref library_srvsw_stdif_timer "standard interface APIs".
 *
 * \defgroup IfxLld_Ccu6_TimerWithTrigger TimerWithTrigger Interface driver
 * \ingroup IfxLld_Ccu6
 * \defgroup IfxLld_Ccu6_TimerWithTrigger_Data_Structures Data Structures
 * \ingroup IfxLld_Ccu6_TimerWithTrigger
 * \defgroup IfxLld_Ccu6_TimerWithTrigger_Timer_StdIf_Functions Timer StdIf Functions
 * \ingroup IfxLld_Ccu6_TimerWithTrigger
 * \defgroup IfxLld_Ccu6_TimerWithTrigger_Timer_Functions Timer Functions
 * \ingroup IfxLld_Ccu6_TimerWithTrigger
 */

#ifndef IFXCCU6_TIMERWITHTRIGGER_H
#define IFXCCU6_TIMERWITHTRIGGER_H 1

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include "_PinMap/IfxCcu6_PinMap.h"
#include "Ccu6/Std/IfxCcu6.h"
#include "StdIf/IfxStdIf_Timer.h"

/******************************************************************************/
/*-----------------------------Data Structures--------------------------------*/
/******************************************************************************/

/** \addtogroup IfxLld_Ccu6_TimerWithTrigger_Data_Structures
 * \{ */
/** \brief Structure for the timer base
 */
typedef struct
{
    Ifx_TimerValue          period;               /**< \brief Timer period in ticks (cached value) */
    boolean                 triggerEnabled;       /**< \brief If TRUE, the trigger functionality is Initialised */
    float32                 clockFreq;            /**< \brief Timer input clock frequency (cached value) */
    IfxStdIf_Timer_CountDir countDir;             /**< \brief Timer counting mode */
} IfxCcu6_TimerWithTrigger_Base;

/** \} */

/** \brief CCU6 Timer interface
 */
typedef struct
{
    IfxCcu6_TimerWithTrigger_Base base;       /**< \brief Timer base structure */
    Ifx_CCU6                     *ccu6;       /**< \brief CCU6 module used for the timer functionality */
} IfxCcu6_TimerWithTrigger;

/** \brief Configuration structure for T12 and T13 Timer
 */
typedef struct
{
    IfxStdIf_Timer_Config  base;                      /**< \brief Standard interface timer configuration */
    Ifx_CCU6              *ccu6;                      /**< \brief CCU6 module used for the timer functionality */
    IfxCcu6_Cout63_Out    *triggerOut;
    IfxCcu6_ServiceRequest serviceReqNrPeriod;        /**< \brief Service request used for the period */
    IfxCcu6_ServiceRequest serviceReqNrTrigger;       /**< \brief Service request used for the Trigger */
} IfxCcu6_TimerWithTrigger_Config;

/** \addtogroup IfxLld_Ccu6_TimerWithTrigger_Timer_StdIf_Functions
 * \{ */

/******************************************************************************/
/*-------------------------Global Function Prototypes-------------------------*/
/******************************************************************************/

/** \brief Returns the timer event
 * \param driver CCU6 Timer interface Handle
 * \return Timer event
 *
 * \see IfxStdIf_Timer_AckTimerIrq
 *
 */
IFX_EXTERN boolean IfxCcu6_TimerWithTrigger_acknowledgeTimerIrq(IfxCcu6_TimerWithTrigger *driver);

/** \brief Returns the trigger event
 * \param driver CCU6 Timer interface Handle
 * \return Timer event
 *
 * \see IfxStdIf_Timer_AckTriggerIrq
 *
 */
IFX_EXTERN boolean IfxCcu6_TimerWithTrigger_acknowledgeTriggerIrq(IfxCcu6_TimerWithTrigger *driver);

/** \brief Enable the transfer of the shadow registers
 * \param driver CCU6 Timer interface Handle
 * \return None
 *
 * \see IfxStdIf_Timer_ApplyUpdate
 *
 */
IFX_EXTERN void IfxCcu6_TimerWithTrigger_applyUpdate(IfxCcu6_TimerWithTrigger *driver);

/** \brief Disables the upadte\n
 * This function is has an empty body as the updated is disabled automatically after the shadow transfer
 * \param driver CCU6 Timer interface Handle
 * \return None
 *
 * \see IfxStdIf_Timer_DisableUpdate
 *
 */
IFX_EXTERN void IfxCcu6_TimerWithTrigger_disableUpdate(IfxCcu6_TimerWithTrigger *driver);

/** \brief Returns the frequency
 * \param driver CCU6 Timer interface Handle
 * \return Frequency
 *
 * \see IfxStdIf_Timer_GetFrequency
 *
 */
IFX_EXTERN float32 IfxCcu6_TimerWithTrigger_getFrequency(IfxCcu6_TimerWithTrigger *driver);

/** \brief Returns the Input frequncy
 * \param driver CCU6 Timer interface Handle
 * \return Frequency
 *
 * \see IfxStdIf_Timer_GetInputFrequency
 *
 */
IFX_EXTERN float32 IfxCcu6_TimerWithTrigger_getInputFrequency(IfxCcu6_TimerWithTrigger *driver);

/** \brief Returns the period of the timer
 * \param driver CCU6 Timer interface Handle
 * \return Period
 *
 * \see IfxStdIf_Timer_GetPeriod
 *
 */
IFX_EXTERN Ifx_TimerValue IfxCcu6_TimerWithTrigger_getPeriod(IfxCcu6_TimerWithTrigger *driver);

/** \brief Returns the resolution
 * \param driver CCU6 Timer interface Handle
 * \return Resolution
 *
 * \see IfxStdIf_Timer_GetResolution
 *
 */
IFX_EXTERN float32 IfxCcu6_TimerWithTrigger_getResolution(IfxCcu6_TimerWithTrigger *driver);

/** \brief Runs the timer
 * \param driver CCU6 Timer interface Handle
 * \return None
 *
 * \see IfxStdIf_Timer_Run
 *
 */
IFX_EXTERN void IfxCcu6_TimerWithTrigger_run(IfxCcu6_TimerWithTrigger *driver);

/** \brief Sets the frequency
 * \param driver CCU6 Timer interface Handle
 * \param frequency Frequency
 * \return TRUE on success else FALSE
 *
 * \see IfxStdIf_Timer_SetFrequency
 *
 */
IFX_EXTERN boolean IfxCcu6_TimerWithTrigger_setFrequency(IfxCcu6_TimerWithTrigger *driver, float32 frequency);

/** \brief Sets the period for the timer
 * \param driver CCU6 Timer interface Handle
 * \param period Period value
 * \return TRUE on success else FALSE
 *
 * \see IfxStdIf_Timer_SetPeriod
 *
 */
IFX_EXTERN boolean IfxCcu6_TimerWithTrigger_setPeriod(IfxCcu6_TimerWithTrigger *driver, Ifx_TimerValue period);

/** \brief Sets the single shot mode of the timer
 * \param driver CCU6 Timer interface Handle
 * \param enabled If TRUE, sets the single shot mode
 * \return None
 *
 * \see IfxStdIf_Timer_SetSingleMode
 *
 */
IFX_EXTERN void IfxCcu6_TimerWithTrigger_setSingleMode(IfxCcu6_TimerWithTrigger *driver, boolean enabled);

/** \brief Sets the trigger
 * \param driver CCU6 Timer interface Handle
 * \param triggerPoint Trigger point value
 * \return None
 *
 * \see IfxStdIf_Timer_SetTrigger
 *
 */
IFX_EXTERN void IfxCcu6_TimerWithTrigger_setTrigger(IfxCcu6_TimerWithTrigger *driver, Ifx_TimerValue triggerPoint);

/** \brief Initializes the standard interface timer
 * \param stdif Standard interface object, will be initialized by the function
 * \param driver CCU6 Timer interface Handle
 * \return TRUE on success else FALSE
 */
IFX_EXTERN boolean IfxCcu6_TimerWithTrigger_stdIfTimerInit(IfxStdIf_Timer *stdif, IfxCcu6_TimerWithTrigger *driver);

/** \brief Stops the timer
 * \param driver CCU6 Timer interface Handle
 * \return None
 *
 * \see IfxStdIf_Timer_Stop
 *
 */
IFX_EXTERN void IfxCcu6_TimerWithTrigger_stop(IfxCcu6_TimerWithTrigger *driver);

/** \brief Updates the input frequency
 * \param driver CCU6 Timer interface Handle
 * \return None
 *
 * \see IfxStdIf_Timer_UpdateInputFrequency
 *
 */
IFX_EXTERN void IfxCcu6_TimerWithTrigger_updateInputFrequency(IfxCcu6_TimerWithTrigger *driver);

/** \} */

/** \addtogroup IfxLld_Ccu6_TimerWithTrigger_Timer_Functions
 * \{ */

/******************************************************************************/
/*-------------------------Global Function Prototypes-------------------------*/
/******************************************************************************/

/** \brief Returns the pointer to timer channel
 * \param driver CCU6 Timer interface Handle
 * \return Pointer
 *
 * \see IfxStdIf_Timer_DisableUpdate
 *
 */
IFX_EXTERN volatile uint32 *IfxCcu6_TimerWithTrigger_getPointer(IfxCcu6_TimerWithTrigger *driver);

/** \brief Initialises the timer object\n
 * T12 is configured as timer, T13 is optionally configured as trigger\n
 * T12CLK, T12PRE and T12PR are chosen to achieve maximum PWM resolution\n
 * Note: To achieve maximum PWM resolution, the requested T12 frequency should be the\n
 * lowest PWM frequency.\n
 * \param driver CCU6 Timer interface Handle
 * \param config Configuration structure for Timer
 * \return TRUE on success else FALSE
 */
IFX_EXTERN boolean IfxCcu6_TimerWithTrigger_init(IfxCcu6_TimerWithTrigger *driver, IfxCcu6_TimerWithTrigger_Config *config);

/** \brief Initializes the configuration structure to default
 * \param config Configuration structure for Timer
 * \param ccu6 Pointer to CCU6 module
 * \return None
 */
IFX_EXTERN void IfxCcu6_TimerWithTrigger_initConfig(IfxCcu6_TimerWithTrigger_Config *config, Ifx_CCU6 *ccu6);

/** \} */

#endif /* IFXCCU6_TIMERWITHTRIGGER_H */
