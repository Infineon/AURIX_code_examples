/**
 * \file IfxGtm_cfg.h
 * \brief GTM on-chip implementation data
 * \ingroup IfxLld_Gtm
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
 * \defgroup IfxLld_Gtm GTM
 * \ingroup IfxLld
 * \defgroup IfxLld_Gtm_Impl Implementation
 * \ingroup IfxLld_Gtm
 * \defgroup IfxLld_Gtm_Std Standard Driver
 * \ingroup IfxLld_Gtm
 * \defgroup IfxLld_Gtm_Atom Atom Interface Drivers
 * \ingroup IfxLld_Gtm
 * \defgroup IfxLld_Gtm_Tom TOM Interface Drivers
 * \ingroup IfxLld_Gtm
 * \defgroup IfxLld_Gtm_Tim Tim Interface Drivers
 * \ingroup IfxLld_Gtm
 * \defgroup IfxLld_Gtm_Impl_Enumerations Enumerations
 * \ingroup IfxLld_Gtm_Impl
 * \defgroup IfxLld_Gtm_Impl_Data_Structures Data Structures
 * \ingroup IfxLld_Gtm_Impl
 * \defgroup IfxLld_Gtm_Impl_Default Union
 * \ingroup IfxLld_Gtm_Impl
 */

#ifndef IFXGTM_CFG_H
#define IFXGTM_CFG_H 1

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include "Ifx_Cfg.h"

#if defined DEVICE_TC49XN
#include "TC49xN/IfxGtm_cfg_TC49xN.h"
#elif defined DEVICE_TC46X
#include "TC46x/IfxGtm_cfg_TC46x.h"
#elif defined DEVICE_TC4EX
#include "TC4Ex/IfxGtm_cfg_TC4Ex.h"
#endif

#endif /* IFXGTM_CFG_H */
