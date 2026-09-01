/**
 * \file IfxGeth_cfg.c
 * \brief GETH on-chip implementation data
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
 *
 */

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include "Ifx_Cfg.h"
#if defined (__TASKING__)
#pragma warning 508		/* To suppress empty file warning */
#endif
#if defined (__ghs__)
#pragma diag_suppress 96		/* To suppress empty file warning */
#endif

#if !defined(DEVICE_TC49XN) && !defined(DEVICE_TC46X) && !defined(DEVICE_TC45X) && !defined(DEVICE_TC4EX) && !defined(DEVICE_TC4PX)

#include "IfxGeth_cfg.h"

/******************************************************************************/
/*-----------------------Exported Variables/Constants-------------------------*/
/******************************************************************************/

IFX_CONST IfxModule_IndexMap        IfxGeth_cfg_indexMap[IFXGETH_NUM_MODULES] = {
    {&MODULE_GETH0, (uint32)IfxGeth_Index_0},
};

IFX_CONST IfxGeth_TxTrafficClassMap IfxGeth_cfg_trafficClassMap[IFXGETH_NUM_PORTS][IFXGETH_NUM_TX_TRAFFIC_CLASSES] = {
    {
        {&GETH0_PORT0_MTL_TCQ0_TXQ0_OPERATION_MODE, IfxGeth_TxTrafficClass_0, IfxGeth_TxTrafficClassType_0},
        {&GETH0_PORT0_MTL_TCQ1_TXQ1_OPERATION_MODE, IfxGeth_TxTrafficClass_1, IfxGeth_TxTrafficClassType_0},
        {&GETH0_PORT0_MTL_TCQ2_TXQ2_OPERATION_MODE, IfxGeth_TxTrafficClass_2, IfxGeth_TxTrafficClassType_0},
#if defined(DEVICE_TC4DX) || defined(DEVICE_TC4ZX)
        {&GETH0_PORT0_MTL_TCQ3_TXQ3_OPERATION_MODE, IfxGeth_TxTrafficClass_3, IfxGeth_TxTrafficClassType_0},
        {&GETH0_PORT0_MTL_TCQ4_TXQ4_OPERATION_MODE, IfxGeth_TxTrafficClass_4, IfxGeth_TxTrafficClassType_0},
#elif defined(DEVICE_TC48XAA) || defined(DEVICE_TC48X) || defined(DEVICE_TC44X)
        {&GETH0_PORT0_MTL_TCQ3_TXQ3_OPERATION_MODE, IfxGeth_TxTrafficClass_3, IfxGeth_TxTrafficClassType_1},
        {&GETH0_PORT0_MTL_TCQ4_TXQ4_OPERATION_MODE, IfxGeth_TxTrafficClass_4, IfxGeth_TxTrafficClassType_1},
#endif /* #if defined(DEVICE_TC4DX) || defined(DEVICE_TC4ZX) */
        {&GETH0_PORT0_MTL_TCQ5_TXQ5_OPERATION_MODE, IfxGeth_TxTrafficClass_5, IfxGeth_TxTrafficClassType_1},
        {&GETH0_PORT0_MTL_TCQ6_TXQ6_OPERATION_MODE, IfxGeth_TxTrafficClass_6, IfxGeth_TxTrafficClassType_1},
        {&GETH0_PORT0_MTL_TCQ7_TXQ7_OPERATION_MODE, IfxGeth_TxTrafficClass_7, IfxGeth_TxTrafficClassType_1}
    },
    {
        {&GETH0_PORT1_MTL_TCQ0_TXQ0_OPERATION_MODE, IfxGeth_TxTrafficClass_0, IfxGeth_TxTrafficClassType_0},
        {&GETH0_PORT1_MTL_TCQ1_TXQ1_OPERATION_MODE, IfxGeth_TxTrafficClass_1, IfxGeth_TxTrafficClassType_0},
        {&GETH0_PORT1_MTL_TCQ2_TXQ2_OPERATION_MODE, IfxGeth_TxTrafficClass_2, IfxGeth_TxTrafficClassType_0},
#if defined(DEVICE_TC4DX) || defined(DEVICE_TC4ZX)
        {&GETH0_PORT1_MTL_TCQ3_TXQ3_OPERATION_MODE, IfxGeth_TxTrafficClass_3, IfxGeth_TxTrafficClassType_0},
        {&GETH0_PORT1_MTL_TCQ4_TXQ4_OPERATION_MODE, IfxGeth_TxTrafficClass_4, IfxGeth_TxTrafficClassType_0},
#elif defined(DEVICE_TC48XAA) || defined(DEVICE_TC48X) || defined(DEVICE_TC44X)
        {&GETH0_PORT1_MTL_TCQ3_TXQ3_OPERATION_MODE, IfxGeth_TxTrafficClass_3, IfxGeth_TxTrafficClassType_1},
        {&GETH0_PORT1_MTL_TCQ4_TXQ4_OPERATION_MODE, IfxGeth_TxTrafficClass_4, IfxGeth_TxTrafficClassType_1},
#endif /* #if defined(DEVICE_TC4DX) || defined(DEVICE_TC4ZX) */
        {&GETH0_PORT1_MTL_TCQ5_TXQ5_OPERATION_MODE, IfxGeth_TxTrafficClass_5, IfxGeth_TxTrafficClassType_1},
        {&GETH0_PORT1_MTL_TCQ6_TXQ6_OPERATION_MODE, IfxGeth_TxTrafficClass_6, IfxGeth_TxTrafficClassType_1},
        {&GETH0_PORT1_MTL_TCQ7_TXQ7_OPERATION_MODE, IfxGeth_TxTrafficClass_7, IfxGeth_TxTrafficClassType_1}
    }
};

#endif /* #if !defined(DEVICE_TC49XN) && !defined(DEVICE_TC46X) && !defined(DEVICE_TC45X) && !defined(DEVICE_TC4EX) */

#if defined (_TASKING_) || defined (_ghs_)
#pragma restore
#endif
