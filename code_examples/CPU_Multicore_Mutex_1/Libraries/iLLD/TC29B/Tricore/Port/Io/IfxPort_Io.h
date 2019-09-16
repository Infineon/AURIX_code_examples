/**
 * \file IfxPort_Io.h
 * \brief PORT IO details
 * \ingroup IfxLld_Port
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
 * \defgroup IfxLld_Port_Io_Usage How to use the PORT I/O driver?
 * \ingroup IfxLld_Port
 *
 * The PORT I/O driver provides several functions to easily configure and read pins.
 * The configuration includes input/output, mode, pad driver strength and state. For referencing the pins and their ports a  IfxPort_PinMap is available as well.
 *
 * In the following sections it will be described, how to integrate the driver into the application framework.
 *
 * \section IfxLld_Port_Io_Preparation Preparation
 * \subsection IfxLld_Port_Io_Include Include Files
 *
 * Include following header file into your C code:
 * \code
 * #include <Port/Io/IfxPort_Io.h>
 * \endcode
 *
 * \subsection IfxLld_Port_Io_Variables Conifguration Table
 *
 * Specify the used pins, their modes and (for outputs) the pad driver strength:
 * <br> Note: For inputs the pad driver strength is only a dummy.
 * \code
 *     const IfxPort_Io_ConfigPin configPin[] = {
 *         {&IfxPort_P00_0,  IfxPort_Mode_inputPullDown, IfxPort_PadDriver_cmosAutomotiveSpeed1},              // P00.0
 *         {&IfxPort_P33_0, IfxPort_Mode_outputPushPullGeneral, IfxPort_PadDriver_cmosAutomotiveSpeed1},  // P33.0
 *       };
 * \endcode
 *
 * Note: the IfxPort_* pins are defined in  IfxPort_PinMap
 *
 * \subsection IfxLld_Port_Io_Init Port Initialisation
 *
 * Assemble the final configuration structure:
 *
 * \code
 * const IfxPort_Io_Config conf = {
 *         sizeof(configPin)/sizeof(IfxPort_Io_ConfigPin),
 *         (IfxPort_Io_ConfigPin *)configPin
 * };
 * \endcode
 *
 * Call the initialisation function:
 *
 * \code
 * IfxPort_Io_initModule(&conf);
 * \endcode
 *
 * Now the pins are configured as specified.
 *
 * \section IfxLld_Port_Io_MiscFunctions Misc. Functions of the Standard Layer
 *
 * \subsection IfxLld_Port_Io_Mode Pin Mode Configuration
 *
 * Generally, you can use one function for both inputs and outputs to set the desired mode.
 *
 * \code
 * // configure P33.0 as general output
 * IfxPort_setPinMode(&MODULE_P33, 0,  IfxPort_Mode_outputPushPullGeneral);
 * \endcode
 *
 * For inputs use the IfxPort_setPinModeInput function:
 *
 * \code
 * // configure P33.0 as input with pullUp
 * IfxPort_setPinModeInput(&MODULE_P33, 0, IfxPort_InputMode_pullUp);
 * \endcode
 *
 * For outputs use the IfxPort_setModeOutput function:
 *
 * \code
 * // configure P33.0 as output in general pushPull mode
 * IfxPort_setPinModeOutput(&MODULE_P33, 0, IfxPort_OutputMode_pushPull, IfxPort_OutputIdx_general);
 * \endcode
 *
 * If the pin is an output, the pad driver should be configured as well:
 *
 * \code
 * IfxPort_setPinPadDriver(&MODULE_P33, 0, IfxPort_PadDriver_cmosAutomotiveSpeed1);
 * \endcode
 *
 * \subsection IfxLld_Port_Io_Input Reading Input State
 * Read the state of a single pin:
 * \code
 * uint8 state = IfxPort_getPinState(&MODULE_P33, 0); // read P33.0
 * \endcode
 *
 * \subsection IfxLld_Port_Io_Output Setting Output State
 *
 * Generally, you can use one function to set an output pin high or low or to toggle it.
 *
 * \code
 * IfxPort_setPinState(&MODULE_P33, 0, IfxPort_State_toggled); // toggle P33.0
 * \endcode
 *
 * An output pin can be set high as following:
 * \code
 * IfxPort_setPinHigh(&MODULE_P33, 0); // P33.0 = 1
 * \endcode
 *
 * An output pin can be set low as following:
 * \code
 * IfxPort_setPinLow(&MODULE_P33, 0); // P33.0 = 0
 * \endcode
 *
 * \subsection IfxLld_Port_Io_Emergency Configure Emergency Function
 *
 * Enable emergency stop for P33.0:
 * \code
 * IfxPort_enableEmergencyStop(&MODULE_P33, 0);
 * \endcode
 *
 * The driver also provides a function to disable this feature.
 *
 * \defgroup IfxLld_Port_Io Interface Driver
 * \ingroup IfxLld_Port
 * \defgroup IfxLld_Port_Io_DataStructures Data Structures
 * \ingroup IfxLld_Port_Io
 * \defgroup IfxLld_Port_Io_ModuleFunctions Module Functions
 * \ingroup IfxLld_Port_Io
 */

#ifndef IFXPORT_IO_H
#define IFXPORT_IO_H 1

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include "Port/Std/IfxPort.h"

/******************************************************************************/
/*-----------------------------Data Structures--------------------------------*/
/******************************************************************************/

/** \addtogroup IfxLld_Port_Io_DataStructures
 * \{ */
typedef struct
{
    IFX_CONST IfxPort_Pin *pin;
    IfxPort_Mode           mode;
    IfxPort_PadDriver      padDriver;
} IfxPort_Io_ConfigPin;

/** \} */

/** \addtogroup IfxLld_Port_Io_DataStructures
 * \{ */
typedef struct
{
    uint32                size;
    IfxPort_Io_ConfigPin *pinTable;
} IfxPort_Io_Config;

/** \} */

/** \addtogroup IfxLld_Port_Io_ModuleFunctions
 * \{ */

/******************************************************************************/
/*-------------------------Global Function Prototypes-------------------------*/
/******************************************************************************/

/**
 * \return None
 */
IFX_EXTERN void IfxPort_Io_initModule(const IfxPort_Io_Config *config);

/** \} */

#endif /* IFXPORT_IO_H */
