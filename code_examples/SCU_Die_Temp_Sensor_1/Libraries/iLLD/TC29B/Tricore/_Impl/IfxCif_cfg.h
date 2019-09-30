/**
 * \file IfxCif_cfg.h
 * \brief CIF on-chip implementation data
 * \ingroup IfxLld_Cif
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
 * \defgroup IfxLld_Cif CIF
 * \ingroup IfxLld
 * \defgroup IfxLld_Cif_Impl Implementation
 * \ingroup IfxLld_Cif
 * \defgroup IfxLld_Cif_Std Standard Driver
 * \ingroup IfxLld_Cif
 */

#ifndef IFXCIF_CFG_H
#define IFXCIF_CFG_H 1

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include "Cpu/Std/Ifx_Types.h"

/******************************************************************************/
/*-----------------------------------Macros-----------------------------------*/
/******************************************************************************/

#ifndef IFXCIF_DEBUG
#define IFXCIF_DEBUG       __debug()
#endif

/** \brief Number of extra phats
 */
#define IFXCIF_EXTRA_PATHS (5)

#ifndef IFXCIF_MAX_I2CNAK
#define IFXCIF_MAX_I2CNAK  (16)
#endif

#define IFXCIF_NUM_MODULES (1)

#endif /* IFXCIF_CFG_H */
