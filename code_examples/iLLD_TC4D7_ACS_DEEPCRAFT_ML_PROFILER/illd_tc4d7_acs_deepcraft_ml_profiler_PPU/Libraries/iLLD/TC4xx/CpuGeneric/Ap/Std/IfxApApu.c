/**
 * \file IfxApApu.c
 * \brief AP basic functionality
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

#include "IfxApApu.h"

/******************************************************************************/
/*-------------------------Function Implementations---------------------------*/
/******************************************************************************/

void IfxApApu_init(volatile Ifx_ACCEN_ACCEN *accen, IfxApApu_ApuConfig *config)
{
    IfxApApu_configWriteRegA(&accen->WRA, config->wraTagId);
    IfxApApu_configWriteRegB(&accen->WRB, config->wrbTagId);
    IfxApApu_configReadRegA(&accen->RDA, config->rdaTagId);
    IfxApApu_configReadRegB(&accen->RDB, config->rdbTagId);
    IfxApApu_setVmReg(&accen->VM, ((config->vmRdId) | ((config->vmWrId) << (IFX_ACCEN_ACCEN_VM_WR00_OFF))));
    IfxApApu_setPrsReg(&accen->PRS, ((config->prsRdId) | ((config->prsWrId) << (IFX_ACCEN_ACCEN_PRS_WR00_OFF))));
}


void IfxApApu_initConfig(IfxApApu_ApuConfig *config)
{
    const IfxApApu_ApuConfig defaultConfig = {
        .wraTagId = 0xFFFFFFFFU,
        .wrbTagId = 0xFFFFFFFFU,
        .rdaTagId = 0xFFFFFFFFU,
        .rdbTagId = 0xFFFFFFFFU,
        .vmWrId   = 0xFFU,
        .vmRdId   = 0xFFU,
        .prsWrId  = 0xFFU,
        .prsRdId  = 0xFFU
    };

    *config = defaultConfig;
}


void IfxApApu_configMemoryAccess(volatile Ifx_ACCEN_ACCEN *accen, IfxApApu_ApuMemoryConfig *config, Ifx_PROT_PROT *protReg, unsigned char accenIndex)
{
    IfxApProt_setProtectionRegionSelect(protReg, accenIndex);
    IfxApApu_init(accen, config->apuConfig);
    IfxApApu_configRegionLowerAddress(&accen->RGNLA, config->rgnlaVal);
    IfxApApu_configRegionUpperAddress(&accen->RGNUA, config->rgnuaVal);
}


#ifdef IFXAP_NUM_LMU
void IfxApApu_configureAccessToLmus(IfxApApu_ApuMemoryConfig *memConfig)
{
    uint8 region;

    for (region = 0; region < sizeof(IfxAp_lmuRegions) / sizeof(IfxAp_memoryRegion); region++)
    {
        memConfig->rgnlaVal = (uint32)IfxAp_lmuRegions[region].memStartAddress & 0xDFFFFFC0U;
        memConfig->rgnuaVal = (uint32)IfxAp_lmuRegions[region].memEndAddress & 0xDFFFFFC0U;

        IfxApApu_configMemoryAccess((Ifx_ACCEN_ACCEN *)&((Ifx_LMU *)IfxAp_lmuRegions[region].moduleAddress)->ACCENCFG,
            memConfig,
            (Ifx_PROT_PROT *)&((Ifx_LMU *)IfxAp_lmuRegions[region].moduleAddress)->PROTRGN,
            0);
    }
}
#endif /* #ifdef IFXAP_NUM_LMU */


void IfxApApu_configureAccessToDlmus(IfxApApu_ApuMemoryConfig *memConfig)
{
    uint8 region;

    for (region = 0; region < sizeof(IfxAp_dlmuRegions) / sizeof(IfxAp_memoryRegion); region++)
    {
        memConfig->rgnlaVal = (uint32)IfxAp_dlmuRegions[region].memStartAddress & 0xDFFFFFC0U;
        memConfig->rgnuaVal = (uint32)IfxAp_dlmuRegions[region].memEndAddress & 0xDFFFFFC0U;

        IfxApApu_configMemoryAccess((Ifx_ACCEN_ACCEN *)&((Ifx_CPU *)IfxAp_dlmuRegions[region].moduleAddress)->ACCENDLMUCFG,
            memConfig,
            (Ifx_PROT_PROT *)&((Ifx_CPU *)IfxAp_dlmuRegions[region].moduleAddress)->PROTDLMUSE,
            0);
    }
}


void IfxApApu_configureAccessToDsprs(IfxApApu_ApuMemoryConfig *memConfig)
{
    uint8 region;

    for (region = 0; region < sizeof(IfxAp_dsprRegions) / sizeof(IfxAp_memoryRegion); region++)
    {
        memConfig->rgnlaVal = (uint32)IfxAp_dsprRegions[region].memStartAddress & 0xFFFFFFC0U;
        memConfig->rgnuaVal = (uint32)IfxAp_dsprRegions[region].memEndAddress & 0xFFFFFFC0U;

        IfxApApu_configMemoryAccess((Ifx_ACCEN_ACCEN *)&((Ifx_CPU *)IfxAp_dsprRegions[region].moduleAddress)->ACCENSPRCFG,
            memConfig,
            (Ifx_PROT_PROT *)&((Ifx_CPU *)IfxAp_dsprRegions[region].moduleAddress)->PROTSPRSE,
            0);
    }
}


void IfxApApu_configureAccessToPsprs(IfxApApu_ApuMemoryConfig *memConfig)
{
    uint8 region;

    for (region = 0; region < sizeof(IfxAp_psprRegions) / sizeof(IfxAp_memoryRegion); region++)
    {
        memConfig->rgnlaVal = (uint32)IfxAp_psprRegions[region].memStartAddress & 0xFFFFFFC0U;
        memConfig->rgnuaVal = (uint32)IfxAp_psprRegions[region].memEndAddress & 0xFFFFFFC0U;

        IfxApApu_configMemoryAccess((Ifx_ACCEN_ACCEN *)&((Ifx_CPU *)IfxAp_psprRegions[region].moduleAddress)->ACCENSPRCFG,
            memConfig,
            (Ifx_PROT_PROT *)&((Ifx_CPU *)IfxAp_psprRegions[region].moduleAddress)->PROTSPRSE,
            1);
    }
}


#ifdef IFXAP_NUM_RMEM
void IfxApApu_configureAccessToRmems(IfxApApu_ApuMemoryConfig *memConfig)
{
    uint8 region;

    for (region = 0; region < sizeof(IfxAp_rmemRegions) / sizeof(IfxAp_memoryRegion); region++)
    {
        memConfig->rgnlaVal = (uint32)IfxAp_rmemRegions[region].memStartAddress & 0xDFFFFFC0U;
        memConfig->rgnuaVal = (uint32)IfxAp_rmemRegions[region].memEndAddress & 0xDFFFFFC0U;

        IfxApApu_configMemoryAccess((Ifx_ACCEN_ACCEN *)&((Ifx_RMEM *)IfxAp_rmemRegions[region].moduleAddress)->ACCENCFG,
            memConfig,
            (Ifx_PROT_PROT *)&((Ifx_RMEM *)IfxAp_rmemRegions[region].moduleAddress)->PROTRGN,
            0);
    }
}
#endif /* #ifdef IFXAP_NUM_RMEM */
