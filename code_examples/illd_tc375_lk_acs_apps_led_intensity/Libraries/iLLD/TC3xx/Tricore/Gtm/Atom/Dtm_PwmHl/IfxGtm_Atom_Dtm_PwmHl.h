/**
 * \file IfxGtm_Atom_Dtm_PwmHl.h
 * \brief GTM DTM_PWMHL details
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
 * \defgroup IfxLld_Gtm_Atom_Dtm_PwmHl_Usage How to use the GTM ATOM DTM PWM HL Driver
 * \ingroup IfxLld_Gtm_Atom_Dtm_PwmHl
 *
 *   This driver implements the PWM functionalities as defined by \ref library_srvsw_stdif_pwmhl.
 *   The user is free to use either the driver specific APIs below or to used the \ref library_srvsw_stdif_pwmhl "standard interface APIs".
 *
 * \section Specific Specific implementation
 *   Implementation is similar to \ref IfxLld_Gtm_Tom_PwmHl
 *
 *
 *   For a detailed configuration of the microcontroller, see \ref IfxGtm_AtomDtm_PwmHl_init().
 *
 * \section Example Usage example
 *   Initialisation is done by, e.g:
 * \code
 *   IfxGtm_AtomDtm_PwmHl_Config driverConfig;
 *   IfxGtm_AtomDtm_PwmHl        driverData;
 *   IfxStdIf_PwmHl          pwmhl;
 *   IfxGtm_AtomDtm_PwmHl_initConfig(&driverConfig, &MODULE_GTM);
 *   IfxGtm_AtomDtm_PwmHl_init(&driverData, &driverConfig);
 *   IfxGtm_AtomDtm_PwmHl_stdIfPwmHlInit(pwmhl, &driverData);
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
 * \defgroup IfxLld_Gtm_Atom_Dtm_PwmHl ATOM DTM Interface Driver
 * \ingroup IfxLld_Gtm_Atom
 */

#ifndef IFXGTM_ATOM_DTM_PWMHL_H
#define IFXGTM_ATOM_DTM_PWMHL_H 1

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include "StdIf/IfxStdIf_PwmHl.h"
#include "Gtm/Atom/Timer/IfxGtm_Atom_Timer.h"
#include "Gtm/Std/IfxGtm_Dtm.h"

/******************************************************************************/
/*-----------------------------------Macros-----------------------------------*/
/******************************************************************************/

/** \brief Maximal number of channels handled by the driver. One channel has a top and bottom pwm output
 */
#define IFXGTM_ATOM_DTM_PWMHL_MAX_NUM_CHANNELS      (8)

#define IFXGTM_ATOM_DTM_PWMHL_MAX_DEADTIME_IN_TICKS (1023)

/******************************************************************************/
/*------------------------------Type Definitions------------------------------*/
/******************************************************************************/

typedef struct IfxGtm_Atom_Dtm_PwmHl_s IfxGtm_AtomDtm_PwmHl;

typedef void                         (*IfxGtm_Atom_Dtm_PwmHl_Update)(IfxGtm_AtomDtm_PwmHl *driver, Ifx_TimerValue *tOn);

typedef void                         (*IfxGtm_Atom_Dtm_PwmHl_UpdateShift)(IfxGtm_AtomDtm_PwmHl *driver, Ifx_TimerValue *tOn, Ifx_TimerValue *shift);

typedef void                         (*IfxGtm_Atom_Dtm_PwmHl_UpdatePulse)(IfxGtm_AtomDtm_PwmHl *driver, float32 *tOn, float32 *offset);

/******************************************************************************/
/*-----------------------------Data Structures--------------------------------*/
/******************************************************************************/

/** \brief Multi-channels PWM object definition (channels only)
 */
typedef struct
{
    Ifx_TimerValue  deadtime;               /**< \brief Dead time between the top and bottom channel in ticks. Range: 0 to 0x3FF */
    Ifx_TimerValue  minPulse;               /**< \brief minimum pulse that is output, shorter pulse time will be output as 0% duty cycle. Range: 0 to 0x00FFFFFF */
    Ifx_TimerValue  maxPulse;               /**< \brief internal parameter. Range: 0 to 0x00FFFFFF */
    Ifx_Pwm_Mode    mode;                   /**< \brief actual PWM mode */
    sint8           setMode;                /**< \brief A non zero flag indicates that the PWM mode is being modified */
    Ifx_ActiveState ccxActiveState;         /**< \brief Top PWM active state */
    Ifx_ActiveState coutxActiveState;       /**< \brief Bottom PWM active state */
    boolean         inverted;               /**< \brief Flag indicating the center aligned inverted mode (TRUE). Range: TRUE: Inverted, FALSE : Not inverted */
    uint8           channelCount;           /**< \brief Number of PWM channels, one channel is made of a top and bottom channel. Range 1 to 8 */
} IfxGtm_Atom_Dtm_PwmHl_Base;

/** \brief GTM ATOM: PWM HL configuration
 */
typedef struct
{
    IfxStdIf_PwmHl_Config           base;                /**< \brief PWM HL standard interface configuration */
    IfxGtm_Atom_Timer              *timer;               /**< \brief Pointer to the linked timer object */
    IfxGtm_Atom                     atom;                /**< \brief ATOM unit used */
    IFX_CONST IfxGtm_Atom_ToutMapP *ccx;                 /**< \brief Pointer to an array of size pwmHl.channels.channelCount containing the channels used. Channels must be adjacent channels */
    IFX_CONST IfxGtm_Atom_ToutMapP *coutx;               /**< \brief Pointer to an array of size pwmHl.channels.channelCount containing the channels used. Channels must be adjacent channels */
    IfxGtm_Dtm_ClockSource          deadTimeClock;       /**< \brief Clock used for the dead time generation */
    boolean                         initPins;            /**< \brief TRUE: Initialize pins in driver, FALSE: Don't initialize pins in driver. User handles separately. */
} IfxGtm_Atom_Dtm_PwmHl_Config;

/** \brief Structure for PWM configuration
 */
typedef struct
{
    Ifx_Pwm_Mode                      mode;                 /**< \brief PWM mode */
    boolean                           inverted;             /**< \brief Inverted configuration for the selected mode. Range: TRUE: Inverted, FALSE : Not inverted */
    IfxGtm_Atom_Dtm_PwmHl_Update      update;               /**< \brief update call back function for the selected mode */
    IfxGtm_Atom_Dtm_PwmHl_UpdateShift updateAndShift;       /**< \brief update shift call back function for the selected mode */
    IfxGtm_Atom_Dtm_PwmHl_UpdatePulse updatePulse;          /**< \brief update pulse call back function for the selected mode */
} IfxGtm_Atom_Dtm_PwmHl_Mode;

/** \brief GTM ATOM PWM driver
 */
struct IfxGtm_Atom_Dtm_PwmHl_s
{
    IfxGtm_Atom_Dtm_PwmHl_Base        base;                                                     /**< \brief Multi-channels PWM object definition (channels only) */
    IfxGtm_Atom_Timer                *timer;                                                    /**< \brief Pointer to the linked timer object */
    IfxGtm_Atom_Dtm_PwmHl_Update      update;                                                   /**< \brief update call back function for the selected mode */
    IfxGtm_Atom_Dtm_PwmHl_UpdateShift updateAndShift;                                           /**< \brief update shift call back function for the selected mode */
    IfxGtm_Atom_Dtm_PwmHl_UpdatePulse updatePulse;                                              /**< \brief update pulse call back function for the selected mode */
    Ifx_GTM_ATOM                     *atom;                                                     /**< \brief ATOM unit used */
    Ifx_GTM_ATOM_AGC                 *agc;                                                      /**< \brief AGC unit used */
    IfxGtm_Atom_Ch                    ccx[IFXGTM_ATOM_DTM_PWMHL_MAX_NUM_CHANNELS];              /**< \brief ATOM channels used for the CCCX outputs */
    IfxGtm_Atom_Ch                    coutx[IFXGTM_ATOM_DTM_PWMHL_MAX_NUM_CHANNELS];            /**< \brief ATOM channels used for the OUTX outputs */
    Ifx_GTM_CDTM_DTM                 *dtm[IFXGTM_ATOM_DTM_PWMHL_MAX_NUM_CHANNELS];              /**< \brief Dead time module (DTM) used. Matching the Atom */
    IfxGtm_Dtm_Ch                     dtmChannel[IFXGTM_ATOM_DTM_PWMHL_MAX_NUM_CHANNELS];       /**< \brief DTM channel used */
    float32                           dtmClockFreq;                                             /**< \brief Deadtime module input clock frequency (cached value) */
};

/******************************************************************************/
/*-------------------------Global Function Prototypes-------------------------*/
/******************************************************************************/

/**
 * \brief Initializes the GTM ATOM DTM PWM HL driver with the provided configuration.
 * 
 * This function sets up the GTM ATOM PWM driver according to the specified configuration.
 * It initializes the driver object and prepares it for operation.
 *
 * \note To ensure proper initialization and channels counter are reset by the timer and do not overflow, leading to random signal on the output, the timer must be started before calling this function.
 *
 * \param[inout] driver Pointer to GTM ATOM PWM driver object to be initialized.
 * \param[in]    config Configuration structure containing PWMHL settings.
 *
 * \retval TRUE If initialization was successful.
 *         FALSE If initialization failed.
 */
IFX_EXTERN boolean IfxGtm_Atom_Dtm_PwmHl_init(IfxGtm_AtomDtm_PwmHl *driver, const IfxGtm_Atom_Dtm_PwmHl_Config *config);

/**
 * \brief Initializes the GTM ATOM DTM PWM HL configuration structure to default values.
 *
 * This function sets up the provided configuration structure with default settings
 * for the GTM ATOM DTM PWM HL module. The structure includes parameters for the
 * PWM HL standard interface, linked timer objects, ATOM unit selection,
 * channel mappings, dead time clock sources, and pin initialization flags.
 *
 * \param[inout] config The configuration structure to be initialized.
 *                      This structure includes fields for PWM HL standard interface,
 *                  	timer links, ATOM unit, channel mappings, dead time clock,
 *                  	and pin initialization control.
 *
 * \retval None
 */
IFX_EXTERN void IfxGtm_Atom_Dtm_PwmHl_initConfig(IfxGtm_Atom_Dtm_PwmHl_Config *config);

/**
 * \brief Retrieves the current dead time value from the GTM ATOM PWM driver.
 *
 * This function returns the dead time value configured for the PWM driver.
 *
 * \param[in] driver Pointer to the GTM ATOM PWM driver handle.
 *                	 This handle provides access to the driver's configuration
 *                	 and operational parameters.
 *
 * \retval float32 The dead time value in seconds.
 */
IFX_EXTERN float32 IfxGtm_Atom_Dtm_PwmHl_getDeadtime(IfxGtm_AtomDtm_PwmHl *driver);

/**
 * \brief Gets the dead time tick value for the GTM ATOM PWM driver.
 *
 * This function retrieves the currently configured dead time tick value for the specified GTM ATOM PWM driver instance.
 *
 * \param[in] driver Pointer to the GTM ATOM PWM driver handle.
 *
 * \retval Ifx_TickTime The current dead time tick value configured for the PWM output.
 */
IFX_EXTERN Ifx_TickTime IfxGtm_Atom_Dtm_PwmHl_getDeadtimeTick(IfxGtm_AtomDtm_PwmHl *driver);

/**
 * \brief Returns the minimum pulse width.
 *
 * This function retrieves the minimum pulse width value from the GTM ATOM PWM driver.
 *
 * \param[in] driver Pointer to the GTM ATOM PWM driver handle.
 *
 * \retval float32 Minimum pulse width in seconds.
 */
IFX_EXTERN float32 IfxGtm_Atom_Dtm_PwmHl_getMinPulse(IfxGtm_AtomDtm_PwmHl *driver);

/**
 * \brief Retrieves the current PWM mode configuration.
 *
 * This function returns the current mode of operation for the GTM ATOM PWM driver.
 *
 * \param[in] driver Pointer to the GTM ATOM PWM driver handle.
 *
 * \retval Ifx_Pwm_Mode The current PWM mode. Range: \ref Ifx_Pwm_Mode
 */
IFX_EXTERN Ifx_Pwm_Mode IfxGtm_Atom_Dtm_PwmHl_getMode(IfxGtm_AtomDtm_PwmHl *driver);

/**
 * \brief Configures the dead time for the GTM ATOM PWM driver to prevent shoot-through in high-side and low-side switches.
 *
 * \param[inout] driver Pointer to the GTM ATOM PWM driver handle.
 * \param[in]    deadtime Dead time value to be set (unit: seconds).
 * 
 * \retval TRUE If the dead time was successfully set.
 *         FALSE If the dead time setting failed.
 */
IFX_EXTERN boolean IfxGtm_Atom_Dtm_PwmHl_setDeadtime(IfxGtm_AtomDtm_PwmHl *driver, float32 deadtime);

/**
 * \brief Sets the minimum pulse width for the PWM signal.
 *
 * This function configures the minimum pulse width for the PWM signal generated by the GTM ATOM driver.
 *
 * \param[inout] driver Pointer to the GTM ATOM PWM driver handle.
 * \param[in]    minPulse Minimum pulse width to be set (in seconds). Must be less than the maximum pulse width.
 *
 * \retval TRUE If the minimum pulse width was successfully set.
 *         FALSE If the operation failed.
 */
IFX_EXTERN boolean IfxGtm_Atom_Dtm_PwmHl_setMinPulse(IfxGtm_AtomDtm_PwmHl *driver, float32 minPulse);

/**
 * \brief Sets the PWM mode, which is applied only after calling setOnTime() and applyUpdate()
 *
 * \param[inout] driver Pointer to the GTM ATOM PWM driver handle.
 * \param[in]    mode   Pwm mode to be set (Ifx_Pwm_Mode)
 *				  	    Range: \ref Ifx_Pwm_Mode
 *
 * \retval TRUE If the mode set successfully.
 *         FALSE If the mode setting failed.
 *
 * \note The PWM mode change will only take effect after calling setOnTime() and applyUpdate()
 */
IFX_EXTERN boolean IfxGtm_Atom_Dtm_PwmHl_setMode(IfxGtm_AtomDtm_PwmHl *driver, Ifx_Pwm_Mode mode);

/**
 * \brief Configures the ON time for the PWM signal.
 *
 * This function sets the duration during which the PWM signal remains in the high state.
 *
 * \param[inout] driver Pointer to the GTM ATOM PWM driver handle.
 * \param[in]    tOn    Pointer to the timer value specifying the ON time.
 *
 * \retval None
 */
IFX_EXTERN void IfxGtm_Atom_Dtm_PwmHl_setOnTime(IfxGtm_AtomDtm_PwmHl *driver, Ifx_TimerValue *tOn);

/**
 * \brief Sets the ON time and Shift for the GTM ATOM PWM driver
 *
 * This function configures the ON time and Shift value for the PWM signal generated by the GTM ATOM driver.
 * The ON time determines the duration the PWM signal remains high, while the Shift value specifies the phase shift
 * in ticks for the PWM signal.
 *
 * \param[inout] driver Pointer to the GTM ATOM PWM driver handle.
 * \param[in]    tOn    Pointer to the timer value specifying the ON time.
 * \param[in]    shift  Pointer to the timer value specifying the shift value in ticks.
 *
 * \retval None
 */
IFX_EXTERN void IfxGtm_Atom_Dtm_PwmHl_setOnTimeAndShift(IfxGtm_AtomDtm_PwmHl *driver, Ifx_TimerValue *tOn, Ifx_TimerValue *shift);

/**
 * \brief Sets the ON time and offset, all switched are independent
 *
 * This function configures the pulse width modulation (PWM) driver by setting the ON time (tOn) and offset values for each phase.
 *
 * \param[inout] driver Pointer to the GTM ATOM PWM driver handle.
 * \param[in]    tOn    Array of ON times for each phase. The array contains values for phase 0 top, phase 1 top, ..., phase 0 bottom, phase 1 bottom, etc.
 * \param[in]    offset Array of offset values in ticks for each phase. The array contains values for phase 0 top, phase 1 top, ..., phase 0 bottom, phase 1 bottom, etc.
 *
 * \retval None
 */
IFX_EXTERN void IfxGtm_Atom_Dtm_PwmHl_setPulse(IfxGtm_AtomDtm_PwmHl *driver, float32 *tOn, float32 *offset);

/**
 * \brief Set up channels based on their active and stuck states.
 *
 * \param[in] driver   Pointer to the GTM ATOM PWM driver handle.
 * \param[in] activeCh Pointer to a boolean indicating whether the channel is active.
 * \param[in] stuckSt  Pointer to a boolean indicating whether the channel is in a stuck state.
 *
 * \retval None
 */
IFX_EXTERN void IfxGtm_Atom_Dtm_PwmHl_setupChannels(IfxGtm_AtomDtm_PwmHl *driver, boolean *activeCh, boolean *stuckSt);

/**
 * \brief Initializes the standard interface PWM.
 *
 * This function initializes the standard interface PWM object using the provided driver.
 * The function sets up the standard interface to work with the specified driver, which must be
 * initialized separately before calling this function.
 *
 * \param[inout] stdif  Standard interface object that will be initialized by the function.
 * \param[in]    driver Interface driver to be used by the standard interface. Must be initialized separately.
 *
 * \retval TRUE If the initialization was successful.
 *         FALSE If the initialization failed.
 */
IFX_EXTERN boolean IfxGtm_Atom_Dtm_PwmHl_stdIfPwmHlInit(IfxStdIf_PwmHl *stdif, IfxGtm_AtomDtm_PwmHl *driver);
#endif /* IFXGTM_ATOM_DTM_PWMHL_H */
