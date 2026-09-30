/**
 * \file Ifx_InternalMux.h
 * \brief Mux configuration functions
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
 * \defgroup IfxLld_lib_internalmux_internalmux FIFO
 * This module implements the Internal Mux functionality.
 * \ingroup IfxLld_lib_internalmux
 */

#ifndef IFX_INTERNALMUX_H
#define IFX_INTERNALMUX_H 1

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include "Ifx_Types.h"

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
