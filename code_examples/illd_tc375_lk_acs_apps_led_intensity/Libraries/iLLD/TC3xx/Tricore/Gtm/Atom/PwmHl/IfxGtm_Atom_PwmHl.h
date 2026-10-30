/**
 * \file IfxGtm_Atom_PwmHl.h
 * \brief GTM PWMHL details
 * \ingroup IfxLld_Gtm
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
 * \defgroup IfxLld_Gtm_Atom_PwmHl_Usage How to use the GTM ATOM PWM HL Driver
 * \ingroup IfxLld_Gtm_Atom_PwmHl
 *
 *   This driver implements the PWM functionalities as defined by \ref library_srvsw_stdif_pwmhl.
 *   The user is free to use either the driver specific APIs below or to used the \ref library_srvsw_stdif_pwmhl "standard interface APIs".
 *
 * \section Specific Specific implementation
 *   Implementation is similar to \ref IfxLld_Gtm_Tom_PwmHl
 *
 *
 *   For a detailed configuration of the microcontroller, see \ref IfxGtm_Atom_PwmHl_init().
 *
 * \section Example Usage example
 *   Initialisation is done by, e.g:
 * \code
 *   IfxGtm_Atom_PwmHl_Config driverConfig;
 *   IfxGtm_Atom_PwmHl        driverData;
 *   IfxStdIf_PwmHl          pwmhl;
 *   IfxGtm_Atom_PwmHl_initConfig(&driverConfig, &MODULE_GTM);
 *   IfxGtm_Atom_PwmHl_init(&driverData, &driverConfig);
 *   IfxGtm_Atom_PwmHl_stdIfPwmHlInit(pwmhl, &driverData);
 * \endcode
 *
 *   During run-time, \ref library_srvsw_stdif_pwmhl "the interface functions" shall be used, e.g.:
 * \code
 *   IfxStdIf_Timer* timer = IfxStdIf_PwmHl_getTimer(pwmhl);
 *   Ifx_TimerValue onTime[3]; // assume configured for three HL channels
 *
 *   onTime[0] = 10;
 *   onTime[1] = 20;
 *   onTime[2] = 30;
 *
 *   IfxStdIf_Timer_disableUpdate(timer);
 *   IfxStdIf_Timer_setPeriod(timer, period);
 *   IfxStdIf_PwmHl_setOnTime(pwmhl, onTime);
 *   IfxStdIf_Timer_applyUpdate(timer);
 * \endcode
 *
 * \defgroup IfxLld_Gtm_Atom_PwmHl ATOM PWM HL Interface Driver
 * \ingroup IfxLld_Gtm_Atom
 * \defgroup IfxLld_Gtm_Atom_PwmHl_Data_Structures Data Structures
 * \ingroup IfxLld_Gtm_Atom_PwmHl
 * \defgroup IfxLld_Gtm_Atom_PwmHl_Functions PwmHl Functions
 * \ingroup IfxLld_Gtm_Atom_PwmHl
 * \defgroup IfxLld_Gtm_Atom_PwmHl_PwmHl_StdIf_Functions PwmHl StdIf Functions
 * \ingroup IfxLld_Gtm_Atom_PwmHl
 */

#ifndef IFXGTM_ATOM_PWMHL_H
#define IFXGTM_ATOM_PWMHL_H 1

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include "StdIf/IfxStdIf_PwmHl.h"
#include "Gtm/Atom/Timer/IfxGtm_Atom_Timer.h"

/******************************************************************************/
/*-----------------------------------Macros-----------------------------------*/
/******************************************************************************/

/** \brief Maximal number of channels handled by the driver. One channel has a top and bottom pwm output
 */
#define IFXGTM_ATOM_PWMHL_MAX_NUM_CHANNELS (8)

/******************************************************************************/
/*------------------------------Type Definitions------------------------------*/
/******************************************************************************/

typedef struct IfxGtm_Atom_PwmHl_s IfxGtm_Atom_PwmHl;

typedef void                     (*IfxGtm_Atom_PwmHl_Update)(IfxGtm_Atom_PwmHl *driver, Ifx_TimerValue *tOn);

typedef void                     (*IfxGtm_Atom_PwmHl_UpdateShift)(IfxGtm_Atom_PwmHl *driver, Ifx_TimerValue *tOn, Ifx_TimerValue *shift);

typedef void                     (*IfxGtm_Atom_PwmHl_UpdatePulse)(IfxGtm_Atom_PwmHl *driver, float32 *tOn, float32 *offset);

/******************************************************************************/
/*-----------------------------Data Structures--------------------------------*/
/******************************************************************************/

/** \addtogroup IfxLld_Gtm_Atom_PwmHl_Data_Structures
 * \{ */
/** \brief Multi-channels PWM object definition (channels only)
 */
typedef struct
{
    Ifx_TimerValue  deadtime;               /**< \brief Dead time between the top and bottom channel in ticks. Range: 0 to 0x00FFFFFF */
    Ifx_TimerValue  minPulse;               /**< \brief minimum pulse that is output, shorter pulse time will be output as 0% duty cycle. Range: 0 to 0x00FFFFFF */
    Ifx_TimerValue  maxPulse;               /**< \brief internal parameter. Range: 0 to 0x00FFFFFF */
    Ifx_Pwm_Mode    mode;                   /**< \brief actual PWM mode */
    sint8           setMode;                /**< \brief A non zero flag indicates that the PWM mode is being modified */
    Ifx_ActiveState ccxActiveState;         /**< \brief Top PWM active state */
    Ifx_ActiveState coutxActiveState;       /**< \brief Bottom PWM active state */
    boolean         inverted;               /**< \brief Flag indicating the center aligned inverted mode (TRUE). Range: TRUE: Inverted, FALSE : Not inverted */
    uint8           channelCount;           /**< \brief Number of PWM channels, one channel is made of a top and bottom channel. Range 1 to 8 */
} IfxGtm_Atom_PwmHl_Base;

/** \} */

/** \addtogroup IfxLld_Gtm_Atom_PwmHl_Data_Structures
 * \{ */
/** \brief GTM ATOM: PWM HL configuration
 */
typedef struct
{
    IfxStdIf_PwmHl_Config           base;           /**< \brief PWM HL standard interface configuration */
    IfxGtm_Atom_Timer              *timer;          /**< \brief Pointer to the linked timer object */
    IfxGtm_Atom                     atom;           /**< \brief ATOM unit used */
    IFX_CONST IfxGtm_Atom_ToutMapP *ccx;            /**< \brief Pointer to an array of size pwmHl.channels.channelCount containing the channels used. Channels must be adjacent channels */
    IFX_CONST IfxGtm_Atom_ToutMapP *coutx;          /**< \brief Pointer to an array of size pwmHl.channels.channelCount containing the channels used. Channels must be adjacent channels */
    boolean                         initPins;       /**< \brief TRUE: Initialize pins in driver
                                                     * FALSE: Don't initialize pins in driver. User handles separately. */
} IfxGtm_Atom_PwmHl_Config;

/** \brief Structure for PWM configuration
 */
typedef struct
{
    Ifx_Pwm_Mode                  mode;                 /**< \brief Pwm Mode */
    boolean                       inverted;             /**< \brief Inverted configuration for the selected mode. Range: TRUE: Inverted, FALSE : Not inverted */
    IfxGtm_Atom_PwmHl_Update      update;               /**< \brief update call back function for the selected mode */
    IfxGtm_Atom_PwmHl_UpdateShift updateAndShift;       /**< \brief update shift call back function for the selected mode */
    IfxGtm_Atom_PwmHl_UpdatePulse updatePulse;          /**< \brief update pulse call back function for the selected mode */
} IfxGtm_Atom_PwmHl_Mode;

/** \brief GTM ATOM PWM driver
 */
struct IfxGtm_Atom_PwmHl_s
{
    IfxGtm_Atom_PwmHl_Base        base;                                            /**< \brief Multi-channels PWM object definition (channels only) */
    IfxGtm_Atom_Timer            *timer;                                           /**< \brief Pointer to the linked timer object */
    IfxGtm_Atom_PwmHl_Update      update;                                          /**< \brief Update function for actual selected mode */
    IfxGtm_Atom_PwmHl_UpdateShift updateAndShift;                                  /**< \brief Update shift function for actual selected mode */
    IfxGtm_Atom_PwmHl_UpdatePulse updatePulse;                                     /**< \brief Update pulse function for actual selected mode */
    Ifx_GTM_ATOM                 *atom;                                            /**< \brief ATOM unit used */
    Ifx_GTM_ATOM_AGC             *agc;                                             /**< \brief AGC unit used */
    IfxGtm_Atom_Ch                ccx[IFXGTM_ATOM_PWMHL_MAX_NUM_CHANNELS];         /**< \brief ATOM channels used for the CCCX outputs */
    IfxGtm_Atom_Ch                coutx[IFXGTM_ATOM_PWMHL_MAX_NUM_CHANNELS];       /**< \brief ATOM channels used for the OUTX outputs */
    IfxGtm_Atom_Ch               *ccxTemp;                                         /**< \brief cached value */
    IfxGtm_Atom_Ch               *coutxTemp;                                       /**< \brief cached value */
};

/** \} */

/** \addtogroup IfxLld_Gtm_Atom_PwmHl_Functions
 * \{ */

/******************************************************************************/
/*-------------------------Global Function Prototypes-------------------------*/
/******************************************************************************/

/**
 * \brief Initializes the GTM ATOM PWMHL driver with the provided configuration.
 *
 * This function sets up the GTM ATOM PWM driver according to the specified configuration.
 * It ensures proper initialization of the timer and PWM channels.
 *
 * \param[inout] driver Pointer to GTM ATOM PWM driver instance to be initialized.
 * \param[in]    config Configuration structure containing PWMHL settings,
 *                      including the base configuration, timer object, ATOM unit, and channel mapping.
 *
 * \retval TRUE If the initialization was successful.
 *         FALSE If the initialization failed.
 *
 * \note To ensure proper initialization and avoid unexpected behavior, the timer must be started
 * before calling this function. Failure to do so may result in channel counters not being reset,
 * leading to potential overflow and random output signals.
 */
IFX_EXTERN boolean IfxGtm_Atom_PwmHl_init(IfxGtm_Atom_PwmHl *driver, const IfxGtm_Atom_PwmHl_Config *config);

/**
 * \brief Initializes the PWMHL configuration structure to default values.
 *
 * \param[inout] config Pointer to the configuration structure that will be initialized.
 *
 * \retval None
 */
IFX_EXTERN void IfxGtm_Atom_PwmHl_initConfig(IfxGtm_Atom_PwmHl_Config *config);

/** \} */

/** \addtogroup IfxLld_Gtm_Atom_PwmHl_PwmHl_StdIf_Functions
 * \{ */

/******************************************************************************/
/*-------------------------Global Function Prototypes-------------------------*/
/******************************************************************************/

/**
 * \brief Returns the dead time of the GTM ATOM PWM driver.
 *
 * This function retrieves the currently configured dead time value from the GTM ATOM PWM driver.
 *
 * \param[in] driver Pointer to GTM ATOM PWM driver handle.
 *
 * \retval float32 Dead time value in seconds.
 */
IFX_EXTERN float32 IfxGtm_Atom_PwmHl_getDeadtime(IfxGtm_Atom_PwmHl *driver);

/**
 * \brief Retrieves the minimum pulse width supported by the PWM driver.
 *
 * This function returns the minimum pulse width in seconds that can be generated
 * by the PWM driver. The value is used to ensure that the PWM output does not
 * exceed the hardware's minimum pulse width capability.
 *
 * \param[in] driver Pointer to GTM ATOM PWM driver handle.
 *
 * \retval float32 Minimum pulse width in seconds.
 */
IFX_EXTERN float32 IfxGtm_Atom_PwmHl_getMinPulse(IfxGtm_Atom_PwmHl *driver);

/**
 * \brief Retrieves the current PWM mode configuration.
 *
 * This function returns the operational mode of the PWM driver, which can be used
 * to determine the current mode of the PWM module.
 *
 * \param[in] driver Pointer to GTM ATOM PWM driver handle.
 *
 * \retval Ifx_Pwm_Mode The current PWM mode. Range: \ref  Ifx_Pwm_Mode
 */
IFX_EXTERN Ifx_Pwm_Mode IfxGtm_Atom_PwmHl_getMode(IfxGtm_Atom_PwmHl *driver);

/**
 * \brief Sets the dead time for the PWM signal to prevent simultaneous switching.
 *
 * \param[inout] driver   Pointer to GTM ATOM PWM driver handle.
 * \param[in]    deadtime Dead time value to be set (unit: seconds).
 *
 * \retval TRUE If the dead time was successfully set.
 * 		   FALSE If the dead time setting failed.
 */
IFX_EXTERN boolean IfxGtm_Atom_PwmHl_setDeadtime(IfxGtm_Atom_PwmHl *driver, float32 deadtime);

/**
 * \brief Sets the minimum pulse width for the PWM signal.
 *
 * This function configures the minimum pulse width for the PWM signal generated by the GTM ATOM driver.
 * The minimum pulse width is used to ensure the PWM signal does not fall below a specified threshold.
 *
 * \param[inout] driver  Pointer to the GTM ATOM PWM driver instance. This parameter must point to a valid
 *                       IfxGtm_Atom_PwmHl object that has been initialized prior to this call.
 * \param[in] minPulse  The minimum pulse width to be set. The value is specified in the same time unit as
 *                      the PWM period (in seconds).
 *                      The minimum pulse width must be greater than zero and less than or equal to the
 *                      maximum pulse width.
 *
 * \retval TRUE If the minimum pulse width was successfully set.
 * 		   FALSE If the minimum pulse width could not be set.
 */
IFX_EXTERN boolean IfxGtm_Atom_PwmHl_setMinPulse(IfxGtm_Atom_PwmHl *driver, float32 minPulse);

/**
 * \brief Sets the PWM mode. The mode is only applied after calling setOnTime() and applyUpdate().
 *
 * \param[inout] driver Pointer to GTM ATOM PWM driver handle.
 * \param[in]    mode   Pwm mode to be set. 
 *	                    Range: \ref Ifx_Pwm_Mode
 *
 * \retval TRUE If successful configuration of the PWM mode.
 * 		   FALSE If the configuration fails.
 */
IFX_EXTERN boolean IfxGtm_Atom_PwmHl_setMode(IfxGtm_Atom_PwmHl *driver, Ifx_Pwm_Mode mode);

/** 
 * \brief Sets the ON time for the PWM signal.
 * 
 * \param[inout] driver Pointer to GTM ATOM PWM driver handle.
 * \param[in] tOn Pointer to the ON time value to set.
 *
 * \retval None
 */
IFX_EXTERN void IfxGtm_Atom_PwmHl_setOnTime(IfxGtm_Atom_PwmHl *driver, Ifx_TimerValue *tOn);

/**
 * \brief Configures the ON time and shift value for the PWM signal.
 * 
 * This function sets the ON time duration and the shift value (delay) for the PWM signal generated by the GTM ATOM PWM driver.
 * The ON time specifies how long the PWM signal remains active within each period, while the shift specifies the phase shift.
 *
 * \param[inout] driver Pointer to GTM ATOM PWM driver handle.
 * \param[in] tOn Pointer to the ON time value to set. 
 * \param[in] shift Pointer to the shift value to set in ticks.
 *
 * \retval None
 */
IFX_EXTERN void IfxGtm_Atom_PwmHl_setOnTimeAndShift(IfxGtm_Atom_PwmHl *driver, Ifx_TimerValue *tOn, Ifx_TimerValue *shift);

/** 
 * \brief Sets the ON time and offset, all switched are independent
 *
 * \param[inout] driver Pointer to GTM ATOM PWM driver handle.
 * \param[in]    tOn    Array of ON times for each phase. The array contains values for phase 0 top, phase 1 top, ..., phase 0 bottom, phase 1 bottom, etc.
 * \param[in]    offset Array of offset values in ticks for each phase. The array contains values for phase 0 top, phase 1 top, ..., phase 0 bottom, phase 1 bottom, etc.
 *
 * \retval None
 */
IFX_EXTERN void IfxGtm_Atom_PwmHl_setPulse(IfxGtm_Atom_PwmHl *driver, float32 *tOn, float32 *offset);

/**
 * \brief Set up channels based on their active and stuck states.
 *
 * \param[inout] driver   Pointer to GTM ATOM PWM driver handle.
 * \param[in]    activeCh Pointer to a boolean indicating whether the channel is active.
 * \param[in]    stuckSt  Pointer to a boolean indicating whether the channel is in a stuck state.
 *
 * \retval None
 */
IFX_EXTERN void IfxGtm_Atom_PwmHl_setupChannels(IfxGtm_Atom_PwmHl *driver, boolean *activeCh, boolean *stuckSt);

/**
 * \brief Initializes the standard interface PWM.
 *
 * This function initializes the standard interface PWM object using the provided driver.
 * The standard interface object will be configured and prepared for operation.
 *
 * \param[inout] stdif  Standard interface object that will be initialized by the function
 * \param[in]    driver Interface driver to be used by the standard interface. Must be initialized separately before calling this function.
 *
 * \retval TRUE If the initialization was successful.
 *  	   FALSE If the initialization failed.
 */
IFX_EXTERN boolean IfxGtm_Atom_PwmHl_stdIfPwmHlInit(IfxStdIf_PwmHl *stdif, IfxGtm_Atom_PwmHl *driver);

/** \} */

#endif /* IFXGTM_ATOM_PWMHL_H */
