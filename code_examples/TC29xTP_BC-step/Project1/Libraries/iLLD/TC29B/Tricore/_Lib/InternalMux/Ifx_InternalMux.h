/**
 * \file Ifx_InternalMux.h
 * \brief Mux configuration functions
 *
 * \version iLLD_1_0_1_9_0
 * \copyright Copyright (c) 2015 Infineon Technologies AG. All rights reserved.
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
 * \defgroup IfxLld_lib_internalmux_internalmux FIFO
 * This module implements the Internal Mux functionality.
 * \ingroup IfxLld_lib_internalmux
 */

#ifndef IFX_INTERNALMUX_H
#define IFX_INTERNALMUX_H 1

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include "Cpu/Std/Ifx_Types.h"

/******************************************************************************/
/*-----------------------------Data Structures--------------------------------*/
/******************************************************************************/
/** \addtogroup IfxLld_lib_internalmux_internalmux
 * \{ */
/** Individual Mux configuration structure
 *
 */
typedef struct
{
    volatile void *regAddr;     /**< \brief pointer to the register for Mux/Demux configuration */
    uint32         mask;        /**< \brief Bit field position for the Mux/Demux selection */
    uint32         value;       /**< \brief Mux/Demux configuration value */
} Ifx_InternalMux_MuxConfig;

/** Global/Combined Mux configuration object
 *
 */
typedef struct
{
    uint32                     size;            /**< size of the internal mux configuration array*/
    Ifx_InternalMux_MuxConfig *muxConfig;       /**< pointer to the internal mux config array*/
}Ifx_InternalMux_Config;

/******************************************************************************/
/*-------------------------Global Function Prototypes-------------------------*/
/******************************************************************************/
/** \brief Initialises the internal mux configuration
 *
 * \param cfg Pointer on the Global Mux Configuration object
 *
 * \return None
 */
IFX_EXTERN void Ifx_InternalMux_init(const Ifx_InternalMux_Config *cfg);

/**\}*/

#endif /* IFX_INTERNALMUX_H */
