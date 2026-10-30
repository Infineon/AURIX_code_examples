/**
 * \file IfxRdma_cfg.h
 * \brief RDMA on-chip implementation data
 * \ingroup IfxLld_Rdma
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
 * \defgroup IfxLld_Rdma RDMA
 * \ingroup IfxLld
 * \defgroup IfxLld_Rdma_Impl Implementation
 * \ingroup IfxLld_Rdma
 * \defgroup IfxLld_Rdma_Std Standard Driver
 * \ingroup IfxLld_Rdma
 */

#ifndef IFXRDMA_CFG_H
#define IFXRDMA_CFG_H 1

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include "Ifx_Cfg.h"

#if defined DEVICE_TC45X
#include "TC45x/IfxRdma_cfg_TC45x.h"
#endif

#endif /* IFXRDMA_CFG_H */
