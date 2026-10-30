/**
 * \file IfxIom_Driver.h
 * \brief IOM DRIVER details
 * \ingroup IfxLld_Iom
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
 * The IOM driver enable easy usage of the IOM module, by abstracting the internal module structure.
 *  For it's configuration it requires the LAM channel to be used together with the reference and monitor signal. The muxes and filters
 *  are configured accordingly. The driver handles the event combiner "accumulated event timer" resources base on the single or multi-event
 *  configuration making use of the next free timer if required.
 *
 *  Double resource usage (LAM channel, accumulated event timers) is checked and reported at driver initialization .
 *
 *  The driver care for the timing and clock conversion, all timing configuration are to be given in second.
 *
 *  Example of use:
 *  - Initialization of the Iom
 *  - Initialization of LAM channel 0 with:
 *      - IOM monitor input: External pin P20.13, delay debounce filter both edge 0.5us, signal inverted,
 *      - IOM reference: GTM TOUT14, no filter, not inverted
 *      - Event window controlled by ref signal, with a free running timer and cleared on any edge of the reference signal, threshold set to 1us
 *      - Event source is XOR of monitor and reference signal, event is triggered on falling edge of the XOR
 *      - An alarm signal is generated if the monitor signal is not within the threshold, after two events.
 *
 *
 *  \code
 *  void InitLam(IfxIom_Driver *driver, IfxIom_Driver *lam){
 *        IfxIom_Driver_Config configDriver;
 *         IfxIom_Driver_LamConfig configLam;
 *
 *         IfxIom_Driver_initConfig(&configDriver, &MODULE_IOM);
 *         IfxIom_Driver_init(driver, &configDriver);
 *
 *         IfxIom_Driver_initLamConfig(&configLam, driver);
 *
 *         configLam.channel = IfxIom_LamId_0;
 *
 *         configLam.mon.input = IfxIom_MonInput_p20_13;
 *         configLam.mon.filter.mode = IfxIom_LamFilterMode_delayDebounceBothEdge;
 *         configLam.mon.filter.clearTimerOnGlitch = FALSE;
 *         configLam.mon.filter.fallingEdgeFilterTime = 0.5e-6;
 *         configLam.mon.filter.risingEdgeFilterTime = configLam.ref.filter.fallingEdgeFilterTime;
 *         configLam.mon.inverted = TRUE;
 *
 *         configLam.ref.input= IfxIom_RefInput_gtmTout14;
 *         configLam.ref.filter.mode = IfxIom_LamFilterMode_noFilter;
 *         configLam.ref.inverted = FALSE;
 *
 *         configLam.eventWindow.controlSource = IfxIom_LamEventWindowControlSource_ref;
 *         configLam.eventWindow.run = IfxIom_LamEventWindowRunControl_freeRunning;
 *         configLam.eventWindow.clearEvent = IfxIom_LamEventWindowClearEvent_anyEdge;
 *      configLam.eventWindow.threshold = 1e-6;
 *         configLam.event.source = IfxIom_LamEventSource_monXorRef;
 *         configLam.event.trigger = IfxIom_LamEventTrigger_fallingEdge;
 *
 *         configLam.systemEventTriggerThreshold = 2;
 *
 *         IfxIom_Driver_initLam(lam, &configLam);
 *
 *  }
 *  \endcode
 *
 * \defgroup IfxLld_Iom_Driver IOM Driver
 * \ingroup IfxLld_Iom
 * \defgroup IfxLld_Iom_Driver_func Driver Functions
 * \ingroup IfxLld_Iom_Driver
 * \defgroup IfxLld_Iom_Driver_struct Structures
 * \ingroup IfxLld_Iom_Driver
 */

#ifndef IFXIOM_DRIVER_H
#define IFXIOM_DRIVER_H 1

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include "Iom/Std/IfxIom.h"

/******************************************************************************/
/*-----------------------------Data Structures--------------------------------*/
/******************************************************************************/

/** \addtogroup IfxLld_Iom_Driver_struct
 * \{ */
/** \brief IOM LAM filter configuration
 */
typedef struct
{
    boolean              clearTimerOnGlitch;          /**< \brief Reset timer behavior for filter and prescaler channel on glitch. Range: TRUE if the timer is cleared on glitch, FALSE if it is decremented on glitch. */
    float32              fallingEdgeFilterTime;       /**< \brief Falling edge filter time in second for immediate debounce filter mode. In delayed filter time this corresponds to the minimal filter time. */
    IfxIom_LamFilterMode mode;                        /**< \brief Filter mode */
    uint32               prescalerFactor;             /**< \brief Prescaler factor, must be > 0, only valid for prescaler mode. Range: 0 to 0xFFFF. */
    float32              risingEdgeFilterTime;        /**< \brief Rising edge filter time in second for immediate debounce filter mode. In delayed filter time this corresponds to the minimal filter time. */
} IfxIom_Driver_LamFilterConfig;

/** \} */

/** \addtogroup IfxLld_Iom_Driver_struct
 * \{ */
/** \brief IOM driver
 */
typedef struct
{
    Ifx_IOM *module;                         /**< \brief Pointer to IOM module SFR set */
    uint8    accumulatedEventUsedMask;       /**< \brief Indicates the used / unused accumulated counter ECM. bit0=CTS0, bit1=CTS2, ... 0=unused, 1=used. Range:0 to 15. */
    uint16   lamUsedMask;                    /**< \brief Indicates the used / unused LAM. bit0=LAM0, bit1=LAM2, ... 0=unused, 1=used */
} IfxIom_Driver;

/** \brief IOM LAM event configuration
 */
typedef struct
{
    IfxIom_LamEventSource  source;        /**< \brief Event source */
    IfxIom_LamEventTrigger trigger;       /**< \brief Event trigger */
} IfxIom_Driver_LamEventConfig;

/** \brief IOM LAM event window configuration
 */
typedef struct
{
    IfxIom_LamEventWindowClearEvent    clearEvent;          /**< \brief Timer clear event */
    IfxIom_LamEventWindowControlSource controlSource;       /**< \brief Timer control source */
    boolean                            inverted;            /**< \brief Invert event window signal. Range: TRUE if the signal is inverted, FALSE if the signal is not inverted. */
    IfxIom_LamEventWindowRunControl    run;                 /**< \brief Timer run control */
    float32                            threshold;           /**< \brief Event window threshold in second. If 0, no event are generated */
} IfxIom_Driver_LamEventWindowConfig;

/** \brief IOM LAM monitor input configuration
 */
typedef struct
{
    IfxIom_Driver_LamFilterConfig filter;         /**< \brief Filter configuration */
    IfxIom_MonInput               input;          /**< \brief Monitor input */
    boolean                       inverted;       /**< \brief Invert monitor signal. Range: TRUE if the signal is inverted, FALSE if the signal is not inverted. */
} IfxIom_Driver_LamMonConfig;

/** \brief IOM LAM reference input configuration
 */
typedef struct
{
    IfxIom_Driver_LamFilterConfig filter;         /**< \brief Filter configuration */
    IfxIom_RefInput               input;          /**< \brief Reference input */
    boolean                       inverted;       /**< \brief Invert reference signal. Range: TRUE if the signal is inverted, FALSE if the signal is not inverted. */
} IfxIom_Driver_LamRefConfig;

/** \} */

/** \addtogroup IfxLld_Iom_Driver_struct
 * \{ */
/** \brief IOM Driver Configuration
 */
typedef struct
{
    Ifx_IOM *module;       /**< \brief IOM module SFRs */
} IfxIom_Driver_Config;

/** \brief IOM LAM object
 */
typedef struct
{
    IfxIom_Driver        *iomDriver;                         /**< \brief Main IOM Driver */
    IfxIom_LamId          channel;                           /**< \brief LAM Channel */
    uint8                 monIndex;                          /**< \brief Monitor input index. Range: 0 to 15.*/
    uint8                 refIndex;                          /**< \brief Reference input index. Range: 0 to 15. */
    IfxIom_RefInputSignal refInput;                          /**< \brief Reference input */
    IfxIom_MonInputSignal monInput;                          /**< \brief Monitor input */
    sint8                 accumulatedCounterIndex;           /**< \brief Accumulated counter used. Negative value means no counter used */
    uint8                 systemEventTriggerThreshold;       /**< \brief Specifies the number of LAM event that triggers the System Event. Value 0 disables the trigger event. Value one enables the trigger event. Value from 2 to 15 will use the counter to filter events, max 4 counters exists for the IOM. Range: 0 to 15. */
} IfxIom_Driver_Lam;

/** \brief IOM LAM configuration
 */
typedef struct
{
    IfxIom_Driver                     *iomDriver;                         /**< \brief Pointer to the IOM driver */
    IfxIom_LamId                       channel;                           /**< \brief LAM channel to be used */
    IfxIom_Driver_LamEventConfig       event;                             /**< \brief LAM event configuration */
    IfxIom_Driver_LamEventWindowConfig eventWindow;                       /**< \brief LAM eventWindow configuration */
    IfxIom_Driver_LamMonConfig         mon;                               /**< \brief LAM Monitor input configuration */
    IfxIom_Driver_LamRefConfig         ref;                               /**< \brief LAM reference input configuration */
    uint8                              systemEventTriggerThreshold;       /**< \brief Specifies the number of LAM event that triggers the System Event. Value 0 disables the trigger event. Value one enables the trigger event. Value from 2 to 15 will use the counter to filter events, max 4 counters exists for the IOM. Range: 0 to 15. */
} IfxIom_Driver_LamConfig;

/** \} */

/** \addtogroup IfxLld_Iom_Driver_func
 * \{ */

/******************************************************************************/
/*-------------------------Global Function Prototypes-------------------------*/
/******************************************************************************/

/**
 * \brief Clears all LAM monitor and reference glitch flags for the specified IOM driver.
 * 
 * \param[inout] driver Pointer to the IOM driver object.
 *
 * \retval None
 * 
 */
IFX_EXTERN void IfxIom_Driver_clearAllGlitch(IfxIom_Driver *driver);

/**
 * \brief Clears the event history and related markers for the IOM driver.
 * 
 * \param[inout] driver Pointer to the IOM driver object.
 *
 * \retval None
 * 
 */
IFX_EXTERN void IfxIom_Driver_clearHistory(IfxIom_Driver *driver);

/**
 * \brief Clears the LAM monitor signal glitch flag, indicating that the glitch condition has been resolved.
 *
 * \param[inout] driver Pointer to the IOM LAM driver object.
 *
 * \retval None
 *
 */
IFX_EXTERN void IfxIom_Driver_clearLamMonGlitch(IfxIom_Driver_Lam *driver);

/**
 * \brief Clears the LAM reference signal glitch flag for the specified driver.
 *
 * \param[inout] driver Pointer to the IOM LAM driver object.
 *
 * \retval None
 *
 */
IFX_EXTERN void IfxIom_Driver_clearLamRefGlitch(IfxIom_Driver_Lam *driver);

/**
 * \brief Disables all event generation for the specified IOM driver and returns the currently configured events.
 *
 * \param[inout] driver Pointer to the IOM driver object.
 *
 * \retval uint32 A bitmask representing the configured events that were disabled. Range: 0 to 0xFFFFF.
 * 
 */
IFX_EXTERN uint32 IfxIom_Driver_disableEvents(IfxIom_Driver *driver);

/**
 * \brief Disables the generation of LAM events for the specified driver.
 *
 * \param[inout] driver Pointer to the IOM LAM driver object.
 *
 * \retval None
 *
 */
IFX_EXTERN void IfxIom_Driver_disableLamEvent(IfxIom_Driver_Lam *driver);

/**
 * \brief Enables the event generation for the LAM (Local Alarm) channel.
 *
 * \param[inout] driver Pointer to the IOM LAM driver object.
 *
 * \retval None
 *
 */
IFX_EXTERN void IfxIom_Driver_enableLamEvent(IfxIom_Driver_Lam *driver);

/**
 * \brief Retrieves the IOM event history for the specified driver object.
 * In returned mask value, bit0= LAM0, bit1=LAM1, ...
 *
 * \param[in]    driver Pointer to the IOM driver object.
 * \param[inout] a      Pointer to the Event mask of history level 0 (last event).
 * \param[inout] b      Pointer to the Event mask of history level 1.
 * \param[inout] c      Pointer to the Event mask of history level 2.
 * \param[inout] d      Pointer to the Event mask of history level 3 (oldest event).
 *
 * \retval None
 *
 */
IFX_EXTERN void IfxIom_Driver_getHistory(IfxIom_Driver *driver, uint16 *a, uint16 *b, uint16 *c, uint16 *d);

/**
 * \brief Initializes the IOM driver with the specified configuration.
 * Must be called before IfxIom_Driver_initLam()
 *
 * \param[inout] driver Pointer to the IOM driver object.
 * \param[in]    config Pointer to IOM driver configuration structure.
 *
 * \retval TRUE If initialization was successful.
 *         FALSE If initialization failed.
 *
 */
IFX_EXTERN boolean IfxIom_Driver_init(IfxIom_Driver *driver, IfxIom_Driver_Config *config);

/**
 * \brief Initializes the IOM driver configuration with default settings.
 *
 * \param[inout] config Pointer to IOM driver configuration structure to be initialized.
 * \param[in]    module Pointer to the IOM module SFRs.
 *
 * \retval None
 *
 */
IFX_EXTERN void IfxIom_Driver_initConfig(IfxIom_Driver_Config *config, Ifx_IOM *module);

/**
 * \brief Initialize the LAM channel.
 * 
 * \param[inout] driver Pointer to the IOM LAM driver object.
 * \param[in]    config Pointer to LAM configuration structure.
 * 
 * \retval TRUE If the initialization was successful.
 *         FALSE If the initialization failed.
 * 
 */
IFX_EXTERN boolean IfxIom_Driver_initLam(IfxIom_Driver_Lam *driver, IfxIom_Driver_LamConfig *config);

/**
 * \brief Initializes the LAM configuration with default values based on the provided driver.
 *
 * \param[inout] config Pointer to LAM configuration structure to be initialized.
 * \param[in]    driver Pointer to the IOM driver object.
 *
 * \retval None
 * 
 */
IFX_EXTERN void IfxIom_Driver_initLamConfig(IfxIom_Driver_LamConfig *config, IfxIom_Driver *driver);

/**
 * \brief Checks and returns the glitch detection status for rising and falling edges on the LAM monitor signal.
 *
 * \param[in]    driver            Pointer to the IOM LAM driver object.
 * \param[inout] risingEdgeGlitch  Set to TRUE if a rising edge glitch was detected on the monitor signal.
 * \param[inout] fallingEdgeGlitch Set to TRUE if a falling edge glitch was detected on the monitor signal.
 *
 * \retval None
 *
 */
IFX_EXTERN void IfxIom_Driver_isLamMonGlitch(IfxIom_Driver_Lam *driver, boolean *risingEdgeGlitch, boolean *fallingEdgeGlitch);

/**
 * \brief Checks and returns the status of rising and falling edge glitches on the reference signal for the LAM driver.
 *
 * \param[in]    driver            Pointer to the IOM LAM driver object.
 * \param[inout] risingEdgeGlitch  Set to TRUE if a rising edge glitch was detected on the reference signal.
 * \param[inout] fallingEdgeGlitch Set to TRUE if a falling edge glitch was detected on the reference signal.
 *
 * \retval None
 *
 */
IFX_EXTERN void IfxIom_Driver_isLamRefGlitch(IfxIom_Driver_Lam *driver, boolean *risingEdgeGlitch, boolean *fallingEdgeGlitch);

/** \brief Restore the IOM event mask.
 *
 * \param[inout] driver Pointer to the IOM driver object.
 * \param[in]    mask   Event configuration as returned by IfxIom_Driver_disableEvents(). Range: 0 to 0xFFFFF.
 *
 * \retval None
 *
 */
IFX_EXTERN void IfxIom_Driver_restoreEvents(IfxIom_Driver *driver, uint32 mask);

/** \} */

#endif /* IFXIOM_DRIVER_H */
