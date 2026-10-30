/**
 * \file IfxIom_Iom.h
 * \brief IOM IOM details
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
 *
 * \defgroup IfxLld_Iom_obsoleteInterface  Obselete Interface for backward compatibility, (Not recommended for use)
 * \ingroup IfxLld_Iom
 *
 * \defgroup IfxLld_Iom_Iom_Usage How to use the IOM Iom Interface driver?
 * \ingroup IfxLld_Iom_obsoleteInterface
 *
 * IOM Module takes the monitor and reference signals from applicable system peripherals(GTM,CCU6,QSPI,PSI5,ASCLIN) and also from external hardware(Sensors) and compare them with respect to one another and generate the alarm events which are routed to SMU.
 *
 * In the following sections it will be described, how to integrate the driver into the application framework.
 *
 * \section IfxLld_Iom_Iom_Preparation Preparation
 * \subsection IfxLld_Iom_Iom_Include Include Files
 *
 * Include following header file into your C code:
 *
 * \code
 *
 * #include <Iom/Iom/IfxIom_Iom.h>
 *
 * \endcode
 *
 * \subsection IfxLld_Iom_Iom_Variables Variables
 *
 * Declare the IOM handle and the configuration buffers as global variables in your C code:
 * \code
 *
 * static IfxIom_Iom_EcmConfig ecmConfig;
 * static IfxIom_Iom_FpcConfig fpcConfig;
 * static IfxIom_Iom_LamConfig lamConfig;
 * static IfxIom_Iom iom;
 *
 * \endcode
 * \subsection IfxLld_Iom_Iom_Init Module Initialisation
 *
 * The module initialisation can be done in the same function. Here an example:
 * \code
 * //Initialize the module handle
 * IfxIom_Iom_initModuleConfig(&iom, &MODULE_IOM);
 *
 * //Enable the module control
 * IfxIom_Iom_initModule(&iom);
 *
 * //Initialize the default Filter & Prescaler Cell channel configuration buffer
 * IfxIom_Iom_initFpcChannelConfig(&fpcConfig);
 * //Filter & Prescaler Cell channel supplied configuration
 * fpcConfig.channelId           = IfxIom_FpcChannelId_2;
 * fpcConfig.filterMode          = IfxIom_FilterMode_delayedDebounce;
 * fpcConfig.comparatorThreshold = 15;
 * fpcConfig.monitorSignal       = IfxIom_MonitorSignal_portLogic;
 * fpcConfig.referenceSignal     = IfxIom_ReferenceSignal_0;
 * fpcConfig.timerReset          = TRUE;
 * //Initialize the Filter & Prescaler Cell channel with supplied configuration
 * IfxIom_Iom_initFpcChannel(&iom, &fpcConfig);
 *
 * //Initialize the default Logic Analyser Module configuration buffer
 * IfxIom_Iom_initAnalyserConfig(&lamConfig);
 * //Logic Analyser Module Block supplied configuration
 * lamConfig.monitorSignalInverted     = FALSE;
 * lamConfig.referenceSignalInverted   = FALSE;
 * lamConfig.lamMonitorSource    = IfxIom_LamMonitorSource_directFpcMonitor;
 * lamConfig.lamMode                   = IfxIom_LamRunMode_freeRunning;
 * lamConfig.eventSource         = IfxIom_EventSource_monitor;
 * lamConfig.eventActiveEdgeSelection = IfxIom_EventActiveEdgeSelection_negativeGateEitherClear;
 * lamConfig.eventWindowInverted       = TRUE;
 * lamConfig.lamMonitorInputChannel    = IfxIom_LamMonitorInputChannel_2;
 * lamConfig.lamReferenceInputChannel   = IfxIom_LamReferenceInputChannel_2;
 * lamConfig.lamId                     = IfxIom_LamId_2;
 * lamConfig.eventWindowThreshold = 15;
 * //Initialize the Logic Analyser Module with supplied configuration
 * IfxIom_Iom_initAnalyser(&iom, &lamConfig);
 *
 * //Initialize the default Event Combiner Module configuration buffer
 * IfxIom_Iom_initCombinerConfig(&ecmConfig);
 * //Initialize the Logic Analyser Module with supplied configuration
 * IfxIom_Iom_initCombiner(&iom, &ecmConfig);
 * \endcode
 *
 * The IOM is ready for use now!
 *
 * Once the Iom driver is initialized, GTM or CCU6 or QSPI or PSI5 or ASCLIN  should be configured to get the two signals with some delay by which event occur.
 *
 * The tested two signals are at below pins.
 *
 * To generate GTM signals see IfxLld_Gtm_Tom_PwmHl_Usage
 *
 * Two GTM signals at below PWM out pins are used as monitor or reference to IOM
 *
 * First pin is for Monitor and second pin is for reference. The above initialized IOM generates the event to SMU if pulse or duty cycle too short.
 *
 * \defgroup IfxLld_Iom_Iom_obsoleteInterface Obselete Interface for backward compatibility, (Not recommended for use)
 * \ingroup IfxLld_Iom
 * \defgroup IfxLld_Iom_Iom_obsoleteInterface_Structures Data Structures
 * \ingroup IfxLld_Iom_Iom_obsoleteInterface
 * \defgroup IfxLld_Iom_Iom_obsoleteInterface_Module Module Functions
 * \ingroup IfxLld_Iom_Iom_obsoleteInterface
 * \defgroup IfxLld_Iom_Iom_obsoleteInterface_Operative Operative Functions
 * \ingroup IfxLld_Iom_Iom_obsoleteInterface
 */

#ifndef IFXIOM_IOM_H
#define IFXIOM_IOM_H 1

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include "Iom/Std/IfxIom.h"

/******************************************************************************/
/*-----------------------------Data Structures--------------------------------*/
/******************************************************************************/

/** \addtogroup IfxLld_Iom_Iom_obsoleteInterface_Structures
 * \{ */
/** \brief Event Combiner Module Global Event Selection Bit Field
 */
typedef struct
{
    uint32 eventCombinerSelection0 : 1;            /**< \brief Determines the inclusion of the channel0 event in the generation of the global event. Range : 1 if include channel event/event counter output, 0 if don�t include channel event/event counter output */
    uint32 eventCombinerSelection1 : 1;            /**< \brief Determines the inclusion of the channel1 event in the generation of the global event. Range : 1 if include channel event/event counter output, 0 if don�t include channel event/event counter output */
    uint32 eventCombinerSelection2 : 1;            /**< \brief Determines the inclusion of the channel2 event in the generation of the global event. Range : 1 if include channel event/event counter output, 0 if don�t include channel event/event counter output */
    uint32 eventCombinerSelection3 : 1;            /**< \brief Determines the inclusion of the channel3 event in the generation of the global event. Range : 1 if include channel event/event counter output, 0 if don�t include channel event/event counter output */
    uint32 eventCombinerSelection4 : 1;            /**< \brief Determines the inclusion of the channel4 event in the generation of the global event. Range : 1 if include channel event/event counter output, 0 if don�t include channel event/event counter output */
    uint32 eventCombinerSelection5 : 1;            /**< \brief Determines the inclusion of the channel5 event in the generation of the global event. Range : 1 if include channel event/event counter output, 0 if don�t include channel event/event counter output */
    uint32 eventCombinerSelection6 : 1;            /**< \brief Determines the inclusion of the channel6 event in the generation of the global event. Range : 1 if include channel event/event counter output, 0 if don�t include channel event/event counter output */
    uint32 eventCombinerSelection7 : 1;            /**< \brief Determines the inclusion of the channel7 event in the generation of the global event. Range : 1 if include channel event/event counter output, 0 if don�t include channel event/event counter output */
    uint32 eventCombinerSelection8 : 1;            /**< \brief Determines the inclusion of the channel8 event in the generation of the global event. Range : 1 if include channel event/event counter output, 0 if don�t include channel event/event counter output */
    uint32 eventCombinerSelection9 : 1;            /**< \brief Determines the inclusion of the channel9 event in the generation of the global event. Range : 1 if include channel event/event counter output, 0 if don�t include channel event/event counter output */
    uint32 eventCombinerSelection10 : 1;           /**< \brief Determines the inclusion of the channel10 event in the generation of the global event. Range : 1 if include channel event/event counter output, 0 if don�t include channel event/event counter output */
    uint32 eventCombinerSelection11 : 1;           /**< \brief Determines the inclusion of the channel11 event in the generation of the global event. Range : 1 if include channel event/event counter output, 0 if don�t include channel event/event counter output */
    uint32 eventCombinerSelection12 : 1;           /**< \brief Determines the inclusion of the channel12 event in the generation of the global event. Range : 1 if include channel event/event counter output, 0 if don�t include channel event/event counter output */
    uint32 eventCombinerSelection13 : 1;           /**< \brief Determines the inclusion of the channel13 event in the generation of the global event. Range : 1 if include channel event/event counter output, 0 if don�t include channel event/event counter output */
    uint32 eventCombinerSelection14 : 1;           /**< \brief Determines the inclusion of the channel14 event in the generation of the global event. Range : 1 if include channel event/event counter output, 0 if don�t include channel event/event counter output */
    uint32 eventCombinerSelection15 : 1;           /**< \brief Determines the inclusion of the channel15 event in the generation of the global event. Range : 1 if include channel event/event counter output, 0 if don�t include channel event/event counter output */
    uint32 countedEventCombinerSelection0 : 1;     /**< \brief Determines the inclusion of the respective channel event counter output (1 of 4) in the generation of the global event (AND function). Range : 1 if include channel event/event counter output, 0 if don�t include channel event/event counter output */
    uint32 countedEventCombinerSelection1 : 1;     /**< \brief Determines the inclusion of the respective channel event counter output (1 of 4) in the generation of the global event (AND function). Range : 1 if include channel event/event counter output, 0 if don�t include channel event/event counter output */
    uint32 countedEventCombinerSelection2 : 1;     /**< \brief Determines the inclusion of the respective channel event counter output (1 of 4) in the generation of the global event (AND function). Range : 1 if include channel event/event counter output, 0 if don�t include channel event/event counter output */
    uint32 countedEventCombinerSelection3 : 1;     /**< \brief Determines the inclusion of the respective channel event counter output (1 of 4) in the generation of the global event (AND function). Range : 1 if include channel event/event counter output, 0 if don�t include channel event/event counter output */
    uint32 reserved : 12;                          /**< \brief reserved */
} IfxIom_Iom_EcmGlobalEventSelectionBits;

/** \} */

/** \addtogroup IfxLld_Iom_Iom_obsoleteInterface_Structures
 * \{ */
typedef struct
{
    IfxIom_EventCounterChannel   input;           /**< \brief Specifies which channel output event to be routed to the Counter */
    IfxIom_EventCounterThreshold threshold;       /**< \brief Specifies the Counter threshold value */
} IfxIom_Iom_EcmConfigCounter;

/** \brief Event Combiner Module Global Event Selection
 */
typedef union
{
    IfxIom_Iom_EcmGlobalEventSelectionBits B;
    uint32                                 U;
} IfxIom_Iom_EcmGlobalEventSelection;

/** \} */

/** \addtogroup IfxLld_Iom_Iom_obsoleteInterface_Structures
 * \{ */
/** \brief Specifies handle to IOM module.
 */
typedef struct
{
    Ifx_IOM *iom;       /**< \brief Specifies the pointer to IOM registers. */
} IfxIom_Iom;

/** \brief Specifies the ECM block configuration structure
 */
typedef struct
{
    IfxIom_Iom_EcmConfigCounter        eventCounter[4];
    IfxIom_Iom_EcmGlobalEventSelection globalEventSelection;       /**< \brief Specifies which channel event & which counted event to be included in global event generation. bit [15:0] specifies the channel event selection and bit [19:16] specifies accumulated event */
} IfxIom_Iom_EcmConfig;

/** \brief Specifies Filter and Prescaler Cell configuration.
 */
typedef struct
{
    uint16                 comparatorThreshold;       /**< \brief Specifies the threshold value that is compared with timer. Range: 0 to 0xFFFF. */
    boolean                timerReset;                /**< \brief Specifies the timer reset bit. Range: TRUE if the timer is cleared on glitch, FALSE if it is decremented on glitch. */
    IfxIom_MonitorSignal   monitorSignal;             /**< \brief Specifies the monitor signal input for Filter & Prescaler cell */
    IfxIom_ReferenceSignal referenceSignal;           /**< \brief Specifies the reference signal input for Filter & Prescaler cell */
    IfxIom_FilterMode      filterMode;                /**< \brief Specifies the Filter & Prescaler Cell mode */
    IfxIom_FpcChannelId    channelId;                 /**< \brief Specifies the number of Filter & Prescaler Cell channel */
    IfxIom_EdgeClearType   edgeType;                  /**< \brief Specifies the edge type which need to be cleared. */
    boolean                exorInputEnable[8];        /**< \brief Specifies the EXOR GTM input signal enable array (8 GTM inputs can be selected by enabling them). Range: TRUE enable EXOR GTM input signal array, FALSE disable EXOR GTM input signal array. */
} IfxIom_Iom_FpcConfig;

/** \brief Specifies Logic Analyser Module configuration.
 */
typedef struct
{
    IfxIom_LamId                    lamId;                          /**< \brief Specifies Id of Logic Analyser Module */
    uint32                          eventWindowThreshold;           /**< \brief This bit field determines the threshold value for the event window counter from which an event is generated. Range: 0 to 0xFFFFFF. */
    boolean                         monitorSignalInverted;          /**< \brief Specifies whether the monitor signal from the FPC channel to LAM is inverted or not. Range: TRUE if the monitor signal is inverted, FALSE if the monitor signal is not inverted. */
    boolean                         referenceSignalInverted;        /**< \brief Specifies whether the reference signal from the FPC channel to LAM is inverted or not. Range: TRUE if the reference signal is inverted, FALSE if the reference signal is not inverted. */
    IfxIom_EventSource              eventSource;                    /**< \brief Specifies whether the event window generation is from the monitor or reference signal. */
    IfxIom_LamMonitorInputChannel   lamMonitorInputChannel;         /**< \brief Specifies which FPC/mux block monitor output signal is to be used for LAM block */
    IfxIom_LamReferenceInputChannel lamReferenceInputChannel;       /**< \brief Specifies which FPC/mux block reference output signal is to be used for LAM block */
    IfxIom_LamMonitorSource         lamMonitorSource;               /**< \brief Specifies whether the monitor signal from the FPC monitor channel is sourced directly or compared with the reference signal from the FPC reference channel for the event compare. */
    IfxIom_LamRunMode               lamMode;                        /**< \brief Specifies whether the event window generation is free-running or gated with the monitor or reference. */
    boolean                         eventWindowInverted;            /**< \brief Specifies whether the event window polarity is inverted or not. Range: TRUE if the event window signal is inverted, FALSE if the event window signal is not inverted. */
    IfxIom_EventActiveEdgeSelection eventActiveEdgeSelection;       /**< \brief Specifies which active edges of the monitor and reference signals are used for the event window generation. */
} IfxIom_Iom_LamConfig;

/** \} */

/** \addtogroup IfxLld_Iom_Iom_obsoleteInterface_Module
 * \{ */

/******************************************************************************/
/*-------------------------Global Function Prototypes-------------------------*/
/******************************************************************************/

/**
 * \brief De-initializes the IOM module, resetting it to its default state.
 *
 * \param[inout] iom Pointer to the IOM module handle.
 *
 * \retval None
 *
 */
IFX_EXTERN void IfxIom_Iom_deInitModule(IfxIom_Iom *iom);

/**
 * \brief Initializes the Logic Analyser Module (LAM) for internal event generation.
 * 
 * \param[inout] iom       Pointer to the IOM module handle.
 * \param[in]    lamConfig Pointer to the LAM configuration structure.
 *
 * \retval TRUE If the initialization is successful.
 *         FALSE If the initialization fails.
 *
 * Usage example: see \ref IfxLld_Iom_Iom_Usage
 * 
 */
IFX_EXTERN boolean IfxIom_Iom_initAnalyser(IfxIom_Iom *iom, const IfxIom_Iom_LamConfig *lamConfig);

/**
 * \brief Initializes the default Logic Analyser Module buffer configuration.
 *
 * \param[inout] lamConfig Pointer to the LAM configuration structure to be initialized.
 *
 * \retval None
 *
 * Usage example: see \ref IfxLld_Iom_Iom_Usage
 *
 */
IFX_EXTERN void IfxIom_Iom_initAnalyserConfig(IfxIom_Iom_LamConfig *lamConfig);

/**
 * \brief Initializes the Event Combiner Module (ECM) for global event handling.
 *
 * \param[inout] iom       Pointer to the IOM module handle.
 * \param[in]    ecmConfig Pointer to the IfxIom_Iom_EcmConfig structure.
 *
 * \retval TRUE If the initialization is successful.
 *         FALSE If the initialization fails.
 *
 * Usage example: see \ref IfxLld_Iom_Iom_Usage
 * 
 */
IFX_EXTERN boolean IfxIom_Iom_initCombiner(IfxIom_Iom *iom, const IfxIom_Iom_EcmConfig *ecmConfig);

/**
 * \brief Initializes the default Event Combiner Module configuration.
 *
 * \param[inout] ecmConfig Pointer to the IfxIom_Iom_EcmConfig structure that will be initialized.
 *
 * \retval None
 *
 * Usage example: see \ref IfxLld_Iom_Iom_Usage
 *
 */
IFX_EXTERN void IfxIom_Iom_initCombinerConfig(IfxIom_Iom_EcmConfig *ecmConfig);

/**
 * \brief Initializes the Filter & Prescaler Cell (FPC) for signal filtering and processing.
 * 
 * \param[inout] iom       Pointer to the IOM module handle.
 * \param[in]    fpcConfig Pointer to the IfxIom_Iom_FpcConfig structure that defines the Filter and Prescaler Cell configuration.
 * 
 * \retval TRUE Initialization was successful.
 *         FALSE Initialization failed (invalid configuration or parameters).
 * 
 * Usage example: see \ref IfxLld_Iom_Iom_Usage
 *
 */
IFX_EXTERN boolean IfxIom_Iom_initFpcChannel(IfxIom_Iom *iom, const IfxIom_Iom_FpcConfig *fpcConfig);

/**
 * \brief Initializes the default configuration for the Filter & Prescaler Cell (FPC) channel.
 *
 * \param[inout] fpcConfig Pointer to the IfxIom_Iom_FpcConfig structure that defines the Filter and Prescaler Cell configuration.
 *
 * \retval None
 *
 * Usage example: see \ref IfxLld_Iom_Iom_Usage
 *
 */
IFX_EXTERN void IfxIom_Iom_initFpcChannelConfig(IfxIom_Iom_FpcConfig *fpcConfig);

/**
 * \brief Initializes the IOM module with the supplied configuration.
 *
 * \param[inout] iom Pointer to the IOM module handle.
 *
 * \retval TRUE If the module was successfully initialized.
 *         FALSE If the initialization failed.
 *
 * Usage example: see \ref IfxLld_Iom_Iom_Usage
 *
 */
IFX_EXTERN boolean IfxIom_Iom_initModule(IfxIom_Iom *iom);

/**
 * \brief Initializes the Module default configuration buffer.
 *
 * \param[inout] iom    Pointer to the IOM module handle.
 * \param[in]    module Handle to the IOM module to be initialized.
 *
 * \retval None
 * 
 * Usage example: see \ref IfxLld_Iom_Iom_Usage
 *
 */
IFX_EXTERN void IfxIom_Iom_initModuleConfig(IfxIom_Iom *iom, Ifx_IOM *module);

/** \} */

/** \addtogroup IfxLld_Iom_Iom_obsoleteInterface_Operative
 * \{ */

/******************************************************************************/
/*-------------------------Global Function Prototypes-------------------------*/
/******************************************************************************/

/**
 * \brief Clears the detected falling and rising edges for the specified FPC configuration.
 *
 * \param[in]    fpcConfig Pointer to the IfxIom_Iom_FpcConfig structure that defines the Filter and Prescaler Cell configuration.
 * \param[inout] iom       Pointer to the IOM module handle.
 *
 * \retval None
 *
 * Usage example: see \ref IfxLld_Iom_Iom_Usage
 *
 */
IFX_EXTERN void IfxIom_Iom_clearFpcEdges(IfxIom_Iom_FpcConfig *fpcConfig, IfxIom_Iom *iom);

/** \} */

#endif /* IFXIOM_IOM_H */
