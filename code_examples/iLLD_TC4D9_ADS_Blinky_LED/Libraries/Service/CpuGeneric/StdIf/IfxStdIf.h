/**
 * \file IfxStdIf.h
 * \brief Standard interface types
 * \ingroup IfxLld
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
 *
 * \defgroup library_srvsw_stdif Standard interface
 * \ingroup library_srvsw
 *
 *
 *
 * \par Terms
 *
 * Term                      |  Description
 * ------------------------- | -------
 * Standard Interface        | Interface defined in this document
 * Interface Driver          | Specific device driver as defined by the iLLD
 * Standard Interface Driver | Specific interface driver which implements the Standard Interface
 * API used at runtime       | API that are used after initialization
 * Module                    | Hardware functional block / IP
 *
 * \par Overview
 * The Standard Interface provides generic runtime API written in C for common use case application. It abstracts the underlaying Interface Driver,
 * i.e. the runtime API is completely device independent. It provides generic API for common use case application.
 *
 * Example of Standard Interface:
 * - Serial communication interface
 * - PWM interface
 * - Position sensor interface
 * - Timer interface
 * - EEPROM interface
 *
 * The target is to be able to exchange the microcontroller or external connected devices on which the application is based with a minimal impact
 *  on the application code, to reduce the application software development and maintenance effort.  This is archived by the Standard Interface,
 * for which, changing the hardware only requires the update of the device configuration settings and the device initialization code. The API used
 * at runtime, which represents the majority and the complexitity of the related code keep unchanged.
 *
 * Motivation: because the current software developed for the automotive applications mainly don't use C++, the Standard Interface provides a common
 *  definition for the device driver and an alternative layer for different hardware instead of using C++ interface wrapper class.
 *
 *
 * The below figure shows the layers used and an example of APIs used by the application.
 * \image html "StandardInterfaceLayers.png" "Standard interface layers"
 * \image html "StandardInterfaceDataPipeExample.png" "Standard interface example: Serial interface as data pipe"
 * \image html "StandardInterfaceTimerExample.png" "Standard interface example: Timer"
 *
 * The Standard Interface is implemented by Standard Interface wrapper by providing the function pointer to the custom functions. This gives
 * the possibility to the programmer to use it or not. When used, it increases the code portability but slightly decreases the performance in
 * term of run time execution and code size. When not used, the performance is not affected.
 *
 *
 * \par Definition
 * The standard interface requires the definition of at least two components: the standard interface component and the standard interface wrapper
 * component. The standard interface component defines for each standard interface a standard interface object and a set of standard APIs used at
 * runtime by the application. The standard interface wrapper component initializes the standard interface component by linking it to the interface
 * driver.
 *
 * \attention:  The application shall explicitly use the API provided by the standard interface component at runtime to access driver's parameters
 * (setter/ getter) or action (methods). Trying to access members of the standard interface component directly though the object may not guaranty
 * future code compatibility. The same applies to the interface driver (reminder).
 *
 *
 * \par Convention
 *
 * The Standard interface defines the following files:
 * Path/File                                       | Description
 * ----------------------------------------------- | -----------------
 * 1_SrvSw/StdIf/IfxStdIf.h                        | Global standard interface definitions
 * 1_SrvSw/StdIf/IfxStdIf_\<standard interface\>.h   | Specific standard interface definitions
 * TCxxx/\<Module\>/Ifx\<Module\>_\<interface\>.h/c      | Specific standard interface wrapper initialization API are reconized by the name Ifx<Module>_<interface>_StdIf<std interface>Init()
 * TCxxx/\<Module\>/Ifx\<Module\>_\<interface\>.h/c      | Specific standard interface wrapper function API are named according to the interface driver naming rules
 *
 */

#ifndef IFXSTDIF_H
#define IFXSTDIF_H 1

#include "Ifx_Types.h"

typedef void *IfxStdIf_InterfaceDriver; /**< \brief Pointer to the specific interface driver */

#endif /* IFXSTDIF_H_ */
