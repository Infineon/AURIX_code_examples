/**
 * \file IfxRif.c
 * \brief RIF  basic functionality
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

#if defined(DEVICE_TC45X)
#include "IfxRif.h"

/******************************************************************************/
/*-------------------------Function Implementations---------------------------*/
/******************************************************************************/

IfxRif_Index IfxRif_getIndex(Ifx_RIF *rif)
{
    uint32       index;
    IfxRif_Index result;

    result = IfxRif_Index_none;

    for (index = 0; index < IFXRIF_NUM_MODULES; index++)
    {
        if (IfxRif_cfg_indexMap[index].module == rif)
        {
            result = (IfxRif_Index)IfxRif_cfg_indexMap[index].index;
            break;
        }
    }

    return result;
}


Ifx_RIF *IfxRif_getAddress(IfxRif_Index rif)
{
    Ifx_RIF *module;

    if ((uint8)rif < (uint8)IFXRIF_NUM_MODULES)
    {
        module = (Ifx_RIF *)IfxRif_cfg_indexMap[rif].module;
    }
    else
    {
        module = NULL_PTR;
    }

    return module;
}


volatile Ifx_SRC_SRCR *IfxRif_getSrcPointer(Ifx_RIF *rif, IfxRif_Interrupt interrupt)
{
    volatile Ifx_SRC_SRCR       *srcPtr                          = NULL_PTR;

    volatile Ifx_SRC_SRCR *const srcTable[IFXRIF_NUM_MODULES][5] = {
        {&MODULE_SRC.RIF[0].ERR, &MODULE_SRC.RIF[0].INT[0], &MODULE_SRC.RIF[0].INT[1], &MODULE_SRC.RIF[0].CSI2SR, &MODULE_SRC.RIF[0].CSI2APSR},
        {&MODULE_SRC.RIF[1].ERR, &MODULE_SRC.RIF[1].INT[0], &MODULE_SRC.RIF[1].INT[1], &MODULE_SRC.RIF[1].CSI2SR, &MODULE_SRC.RIF[1].CSI2APSR},
        {&MODULE_SRC.RIF[2].ERR, &MODULE_SRC.RIF[2].INT[0], &MODULE_SRC.RIF[2].INT[1], &MODULE_SRC.RIF[2].CSI2SR, &MODULE_SRC.RIF[2].CSI2APSR},
    };

    IfxRif_Index                 index = IfxRif_getIndex(rif);

    if (index != IfxRif_Index_none)
    {
        srcPtr = srcTable[index][interrupt];
    }

    return srcPtr;
}


void IfxRif_configureAccessToRifs(IfxApApu_ApuConfig *apConfig)
{
    IfxApApu_init((Ifx_ACCEN_ACCEN *)&MODULE_RIF0.ACCEN, apConfig);
}

#endif /* #if defined(DEVICE_TC45X) */

#if defined (_TASKING_) || defined (_ghs_)
#pragma restore
#endif
