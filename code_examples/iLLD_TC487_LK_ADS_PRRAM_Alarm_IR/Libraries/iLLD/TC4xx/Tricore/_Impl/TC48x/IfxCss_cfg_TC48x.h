/**
 * \file IfxCss_cfg_TC48x.h
 * \brief CSS on-chip implementation data
 * \ingroup IfxLld_Css
 *
 * \version iLLD-TC4-v2.6.0
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
 * \defgroup IfxLld_Css CSS
 * \ingroup IfxLld
 * \defgroup IfxLld_Css_Impl Implementation
 * \ingroup IfxLld_Css
 * \defgroup IfxLld_Css_Std Standard Driver
 * \ingroup IfxLld_Css
 */

#ifndef IFXCSS_CFG_TC48X_H
#define IFXCSS_CFG_TC48X_H 1

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include "Ifx_Types.h"

/******************************************************************************/
/*-----------------------------------Macros-----------------------------------*/
/******************************************************************************/

/** \brief Number of Channels
 */
#define IFXCSS_NUM_CHANNELS                      (21)

/** \brief Number of CSS modules
 */
#define IFXCSS_NUM_MODULES                       (1)

/** \brief Channel 0 Input FIFO Size in Bytes
 */
#define IFXCSS_CHANNEL0_INPUTFIFOSIZE_BYTES      ((uint16)(204))

/** \brief Channel 1-2 Input FIFO Size in Bytes
 */
#define IFXCSS_CHANNEL1TO2_INPUTFIFOSIZE_BYTES   ((uint16)(1548))

/** \brief Channel 3-20 Input FIFO Size in Bytes
 */
#define IFXCSS_CHANNEL3TO20_INPUTFIFOSIZE_BYTES  ((uint16)(268))

/** \brief Channel 0 Output FIFO Size in Bytes
 */
#define IFXCSS_CHANNEL0_OUTPUTFIFOSIZE_BYTES     ((uint16)(256))

/** \brief Channel 1-2 Output FIFO Size in Bytes
 */
#define IFXCSS_CHANNEL1TO2_OUTPUTFIFOSIZE_BYTES  ((uint16)(1536))

/** \brief Channel 3-20 Output FIFO Size in Bytes
 */
#define IFXCSS_CHANNEL3TO20_OUTPUTFIFOSIZE_BYTES ((uint16)(192))

/** \brief Counter for timeout
 */
#ifndef IFXCSS_TIMEOUT_COUNT
#define IFXCSS_TIMEOUT_COUNT                     ((uint32)0xFFFFFFFEu)
#endif

/** \brief Reset CSS channel in channel init function if this macro is True
 */
#ifndef IFXCSS_RESET_CHANNEL_IN_INIT
#define IFXCSS_RESET_CHANNEL_IN_INIT             (TRUE)
#endif

#endif /* IFXCSS_CFG_TC48X_H */
