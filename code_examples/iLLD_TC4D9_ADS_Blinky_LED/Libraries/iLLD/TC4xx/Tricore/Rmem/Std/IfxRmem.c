/**
 * \file IfxRmem.c
 * \brief RMEM  basic functionality
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
#include "IfxRmem.h"

/** \addtogroup IfxLld_Rmem_Std_Config
 * \{ */

/******************************************************************************/
/*-----------------------Private Function Prototypes--------------------------*/
/******************************************************************************/

/** \brief configure the radar memory access
 * \param accen pointer to the APU registers
 * \param config config pointer to the default APU configuration structure.
 * \param protReg pointer to the PROT registers
 * \param accenIndex The accen index which needs to be configured
 * \return None
 */
IFX_STATIC void IfxRmem_configMemoryAccess(Ifx_RMEM_ACCENCFG *accen, IfxRmem_ApuMemoryConfig *config, volatile Ifx_RMEM_PROTRGN *protReg, uint8 accenIndex);

/** \} */

/******************************************************************************/
/*-------------------------Function Implementations---------------------------*/
/******************************************************************************/

void IfxRmem_initApConfig(IfxRmem_ApConfig *config)
{
    uint8                         index;
    const IfxRmem_ApuMemoryConfig defaultConfig = {
        .apuConfig    = {
            .wraTagId = 0U,
            .wrbTagId = 0U,
            .rdaTagId = 0U,
            .rdbTagId = 0U,
            .vmWrId   = 0U,
            .vmRdId   = 0U,
            .prsWrId  = 0U,
            .prsRdId  = 0U
        },
        .rgnlaVal = 0U,
        .rgnuaVal = 0xffffffffU,
    };

    IfxApProt_initConfig(&config->protseConfig);
    IfxApProt_initConfig(&config->protrgnConfig);

    /* Initialize the APU Memory regions */
    for (index = 0U; index < IFXRMEM_NUM_PARTITION; index++)
    {
        *(&config->apuMemoryConfig[index]) = defaultConfig;
    }
}


void IfxRmem_initAp(Ifx_RMEM *rmemSFR, IfxRmem_ApConfig *config)
{
    uint8                      index;
    volatile Ifx_RMEM_PROTRGN *protgen;
    protgen = &rmemSFR->PROTRGN;

    /* Initialize the PROT */
    (void)IfxApProt_init((volatile Ifx_PROT_PROT *)(volatile void *)&rmemSFR->PROTSE, &config->protseConfig);
    (void)IfxApProt_init((volatile Ifx_PROT_PROT *)(volatile void *)&rmemSFR->PROTRGN, &config->protrgnConfig);

    /* Initialize the APU */
    for (index = 0U; index < IFXRMEM_NUM_PARTITION; index++)
    {
        /* Change the state to CONFIG, Configure APU and set PROT state back to RUN */
        (void)IfxApProt_setState((volatile Ifx_PROT_PROT *)(volatile void *)&rmemSFR->PROTRGN, IfxApProt_State_config);
        IfxRmem_configMemoryAccess((Ifx_RMEM_ACCENCFG *)&rmemSFR->ACCENCFG, &config->apuMemoryConfig[index], protgen, index);
        /* Change the state to RUN */
        (void)IfxApProt_setState((volatile Ifx_PROT_PROT *)(volatile void *)&rmemSFR->PROTRGN, IfxApProt_State_run);
    }
}


IFX_STATIC void IfxRmem_configMemoryAccess(Ifx_RMEM_ACCENCFG *accen, IfxRmem_ApuMemoryConfig *config, volatile Ifx_RMEM_PROTRGN *protReg, uint8 accenIndex)
{
    IfxApProt_setProtectionRegionSelect((volatile Ifx_PROT_PROT *)(volatile void *)protReg, accenIndex);
    IfxApApu_init((volatile Ifx_ACCEN_ACCEN *)(volatile void *)accen, &config->apuConfig);
    IfxApApu_configRegionLowerAddress((volatile Ifx_ACCEN_ACCEN_RGNLA *)(volatile void *)&accen->RGNLA, config->rgnlaVal);
    IfxApApu_configRegionUpperAddress((volatile Ifx_ACCEN_ACCEN_RGNUA *)(volatile void *)&accen->RGNUA, config->rgnuaVal);
}


void IfxRmem_safetyErrorInject(Ifx_RMEM *rmemSFR, IfxRmem_Error errorType)
{
#if defined(IFX_PROT_ENABLED)
#if (IFX_PROT_ENABLED == 1U)
    IfxApProt_setState((Ifx_PROT_PROT *)&rmemSFR->PROTSE, IfxApProt_State_config);
#endif
#endif

    if (errorType == IfxRmem_Error_dataPathECC)
    {
        rmemSFR->SCTRL.B.GED = IFXRMEM_DATAPATH_ERROR_EN;
    }
    else if (errorType == IfxRmem_Error_mbxComparator)
    {
        rmemSFR->SCTRL.B.MCMPTST = IFXRMEM_COMPARATORTEST_ERROR_EN;
    }
    else
    {
        rmemSFR->SCTRL.B.VCMPTST = IFXRMEM_COMPARATORTEST_ERROR_EN;
    }

#if defined(IFX_PROT_ENABLED)
#if (IFX_PROT_ENABLED == 1U)
    IfxApProt_setState((Ifx_PROT_PROT *)&rmemSFR->PROTSE, IfxApProt_State_run);
#endif
#endif
}


void IfxRmem_configureAccessToRmems(IfxApApu_ApuConfig *apConfig)
{
    uint8 index;

    for (index = 0; index < IFXRMEM_NUM_MODULES; index++)
    {
        Ifx_RMEM *rmem = (Ifx_RMEM *)(((uint32)&MODULE_RMEM0) + index * ((uint32)&MODULE_RMEM1 - (uint32)&MODULE_RMEM0));
        IfxApApu_init((Ifx_ACCEN_ACCEN *)&rmem->ACCENCFG, apConfig);
    }
}

#endif /* #if defined(DEVICE_TC45X) */

#if defined (_TASKING_) || defined (_ghs_)
#pragma restore
#endif
