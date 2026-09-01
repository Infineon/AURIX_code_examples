/**
 * \file IfxDma.c
 * \brief DMA  basic functionality
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
 */

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include "IfxDma.h"

/******************************************************************************/
/*-------------------------Function Implementations---------------------------*/
/******************************************************************************/

IfxDma_Index IfxDma_getIndex(Ifx_DMA *dma)
{
    uint32       index;
    IfxDma_Index result;

    result = IfxDma_Index_none;

    for (index = 0; index < IFXDMA_NUM_MODULES; index++)
    {
        if (IfxDma_cfg_indexMap[index].module == dma)
        {
            result = (IfxDma_Index)IfxDma_cfg_indexMap[index].index;
            break;
        }
    }

    return result;
}


void IfxDma_configureAccessToDmas(IfxApApu_ApuConfig *apConfig)
{
    for (uint8 i = 0; i < IFXDMA_NUM_RP; i++)
    {
        /* Loop through all the Resource Partitions */
        IfxApApu_init((Ifx_ACCEN_ACCEN *)&MODULE_DMA0.RP[i].ACCEN, apConfig);
    }
    #if (IFXDMA_NUM_MODULES == 2)
    for (uint8 i = 0; i < IFXDMA_NUM_RP - 8U; i++)
    {
        /* Loop through all the Resource Partitions */
        IfxApApu_init((Ifx_ACCEN_ACCEN *)&MODULE_DMA1.RP[i].ACCEN, apConfig);
    }
    #endif	/* #if (IFXDMA_NUM_MODULES == 2) */
}
