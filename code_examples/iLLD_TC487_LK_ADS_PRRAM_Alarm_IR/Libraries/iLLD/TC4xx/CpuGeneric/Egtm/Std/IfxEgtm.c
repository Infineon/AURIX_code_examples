/**
 * \file IfxEgtm.c
 * \brief EGTM  basic functionality
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

#include "Ifx_Cfg.h"
#if defined (__TASKING__)
#pragma warning 508 /* To suppress empty file warning */
#endif
#if defined (__ghs__)
#pragma diag_suppress 96 /* To suppress empty file warning */
#endif

#if !defined(DEVICE_TC45X)
#include "IfxEgtm.h"

/******************************************************************************/
/*-------------------------Function Implementations---------------------------*/
/******************************************************************************/

boolean IfxEgtm_ConnectToMsc(IfxEgtm_Cluster egtmCluster, IfxEgtm_TrigSource egtmSource, IfxEgtm_TrigChannel Channel, IfxEgtm_MscOut *mscOut)
{
    boolean result     = FALSE;
    uint32  idx        = 0U;
    uint32  indexAltIn = 0U;

    /* 1. Checks whether MSC Set is present in table */
    if (IfxEgtm_Cfg_MscSetTable[mscOut->mscSet] != NULL_PTR)
    {
        /* Get number of values in table from first index and loop through all entries */
        for (idx = 1u; idx <= IfxEgtm_Cfg_MscSetTable[mscOut->mscSet][0]; idx++)
        {
            if (IfxEgtm_Cfg_MscSetTable[mscOut->mscSet][idx] == IFXEGTM_CFG_GETTRIGENTRY(egtmCluster, egtmSource, Channel)) /* Check for valid combination */
            {
                result = TRUE;
                break;
            }
        }

        uint8 mscLevel2MuxIndex;
        mscLevel2MuxIndex = (uint8)mscOut->mscSelect;

        /* 2. Checks whether MSC module is present */
        if ((result == TRUE) && (IfxEgtm_Cfg_MscAltInputTable[mscLevel2MuxIndex] != NULL_PTR))
        {
            for (indexAltIn = 0u; indexAltIn < IFXEGTM_CFG_NUMMSCALTINPUT; indexAltIn++) /* loop through all AltInput SEL values */
            {
                /* 3. Check whether ALT input selection exists for MSC Set */
                if (*(IfxEgtm_Cfg_MscAltInputTable[mscLevel2MuxIndex] + (((uint32)mscOut->mscAltIn << 2u) + indexAltIn)) == (uint32)mscOut->mscSet)
                {
                    result = TRUE;
                    break;
                }
                else
                {
                    result = FALSE;
                }
            }
        }

        /* 4. Performs Multiplexer connection */
        if (result == TRUE)
        {
            uint32 shift, mask, sel;

            /* Connection 1: Connect GTM output channel to one of the MSC set */
            shift = ((uint32)mscOut->mscSetSignal & 0x3U) << 0x3u;
            sel   = idx << shift;
            mask  = (uint32)IFX_EGTM_MSCSET_CON0_SEL0_MSK << shift;

            switch ((uint8)mscOut->mscSetSignal >> 2)
            {
            case 0:
                Ifx__ldmst(&(MODULE_EGTM.MSCSET[mscOut->mscSet].CON0.U), mask, sel);
                break;
            case 1:
                Ifx__ldmst(&(MODULE_EGTM.MSCSET[mscOut->mscSet].CON1.U), mask, sel);
                break;
            case 2:
                Ifx__ldmst(&(MODULE_EGTM.MSCSET[mscOut->mscSet].CON2.U), mask, sel);
                break;
            case 3:
                Ifx__ldmst(&(MODULE_EGTM.MSCSET[mscOut->mscSet].CON3.U), mask, sel);
                break;
            default:
                /* do nothing */
                break;
            }

            /* Connection 2:
             * TC49x: Connect MSC Set to one of the MSC module and module's INLCON/INLECON/INHCON/INHECON
             * TC4Dx: Connect MSC Set to one of the MSC select and select's INLCON/INLECON/INHCON/INHECON
             */
            shift = ((uint32)mscOut->mscSetSignal << 1u);
            sel   = indexAltIn << shift;
            mask  = (uint32)IFX_EGTM_MSC_INLCON_SEL0_MSK << shift;

            switch ((uint8)mscOut->mscAltIn)
            {
            case 0:
                Ifx__ldmst(&(MODULE_EGTM.MSC[mscLevel2MuxIndex].INLCON.U), mask, sel);
                break;
            case 1:
                Ifx__ldmst(&(MODULE_EGTM.MSC[mscLevel2MuxIndex].INLECON.U), mask, sel);
                break;
            case 2:
                Ifx__ldmst(&(MODULE_EGTM.MSC[mscLevel2MuxIndex].INHCON.U), mask, sel);
                break;
            case 3:
                Ifx__ldmst(&(MODULE_EGTM.MSC[mscLevel2MuxIndex].INHECON.U), mask, sel);
                break;
            default:
                /* do nothing */
                break;
            }

            /* Connection 3: Connect MSC Select to one of the MSC module */
            shift = ((uint32)mscOut->mscModule << 0x3u);
            sel   = (mscOut->mscSelect + 0x4u) << shift;
            mask  = (uint32)IFX_EGTM_MSCSELIN_INLCON_MMSC0_MSK << shift;

            switch ((uint8)mscOut->mscAltIn)
            {
            case 0:
                Ifx__ldmst(&(MODULE_EGTM.MSCSELIN.INLCON.U), mask, sel);
                break;
            case 1:
                Ifx__ldmst(&(MODULE_EGTM.MSCSELIN.INLECON.U), mask, sel);
                break;
            case 2:
                Ifx__ldmst(&(MODULE_EGTM.MSCSELIN.INHCON.U), mask, sel);
                break;
            case 3:
                Ifx__ldmst(&(MODULE_EGTM.MSCSELIN.INHECON.U), mask, sel);
                break;
            default:
                /* do nothing */
                break;
            }
        }
    }

    return result;
}


void IfxEgtm_initApConfig(IfxEgtm_ApConfig *config)
{
    uint8 i = 0U;
    IfxApProt_initConfig(&(config->protseConfig));

    IfxApProt_initConfig(&(config->ctrlApConfig.proteConfig));
    IfxApApu_initConfig(&(config->ctrlApConfig.apuConfig));

    IfxApApu_initConfig(&(config->wrapApConfig.apuConfig));

    for (i = 0u; i < IFXEGTM_NUM_CCM_OBJECTS; i++)
    {
        IfxApApu_initConfig(&(config->clApConfig[i].apuConfig));
    }
}


void IfxEgtm_initAp(Ifx_EGTM *egtm, IfxEgtm_ApConfig *config)
{
    uint8 i = 0U;
    /* Initialize the PROTs */
    IfxEgtm_initProtSe(egtm, &(config->protseConfig));

    IfxEgtm_initCtrlProt(egtm, &(config->ctrlApConfig.proteConfig));

    /* Change the state to CONFIG, Configure APU and set PROT state back to RUN */
    /* Initializes the APU */
    (void)IfxApProt_setState((volatile Ifx_PROT_PROT *)(volatile void *)&(egtm->PROTSE), IfxApProt_State_config);
    IfxEgtm_initCtrlApu(egtm, &(config->ctrlApConfig.apuConfig));
    (void)IfxApProt_setState((volatile Ifx_PROT_PROT *)(volatile void *)&(egtm->PROTSE), IfxApProt_State_run);

    (void)IfxApProt_setState((volatile Ifx_PROT_PROT *)(volatile void *)&(egtm->PROTSE), IfxApProt_State_config);
    IfxEgtm_initWrapApu(egtm, &(config->wrapApConfig.apuConfig));
    (void)IfxApProt_setState((volatile Ifx_PROT_PROT *)(volatile void *)&(egtm->PROTSE), IfxApProt_State_run);

    (void)IfxApProt_setState((volatile Ifx_PROT_PROT *)(volatile void *)&(egtm->PROTSE), IfxApProt_State_config);

    for (i = 0u; i < IFXEGTM_NUM_CCM_OBJECTS; i++)
    {
        IfxEgtm_initClApu(egtm, (IfxEgtm_Cluster)i, &(config->clApConfig[i].apuConfig));
    }

    (void)IfxApProt_setState((volatile Ifx_PROT_PROT *)(volatile void *)&(egtm->PROTSE), IfxApProt_State_run);
}


void IfxEgtm_configureAccessToEgtms(IfxApApu_ApuConfig *apConfig)
{
    uint8 cluster;
    IfxApApu_init((volatile Ifx_ACCEN_ACCEN *)(volatile void *)&MODULE_EGTM.CTRL.ACCEN, apConfig);

    for (cluster = 0u; cluster < IFXEGTM_NUM_CCM_OBJECTS; cluster++)
    {
        IfxApApu_init((volatile Ifx_ACCEN_ACCEN *)(volatile void *)&MODULE_EGTM.CL[cluster].ACCEN, apConfig);
    }

    IfxApApu_init((volatile Ifx_ACCEN_ACCEN *)(volatile void *)&MODULE_EGTM.WRAP.ACCEN, apConfig);
#if defined(DEVICE_TC49XN) || defined(DEVICE_TC44X) || defined(DEVICE_TC46X) || defined(DEVICE_TC48XAA) || defined(DEVICE_TC48X) || defined(DEVICE_TC4DX) || defined(DEVICE_TC4ZX) || defined(DEVICE_TC4EX) || defined(DEVICE_TC4PX)
    IfxApApu_init((volatile Ifx_ACCEN_ACCEN *)(volatile void *)&MODULE_EGTM.CTRLGTM.ACCEN, apConfig);

    IfxApApu_init((volatile Ifx_ACCEN_ACCEN *)(volatile void *)&MODULE_EGTM.SAFEGTM.ACCEN, apConfig);
#endif /* #if defined(DEVICE_TC49XN) || defined(DEVICE_TC44X) || defined(DEVICE_TC46X) || defined(DEVICE_TC48XAA) || defined(DEVICE_TC48X) || defined(DEVICE_TC4DX) || defined(DEVICE_TC4ZX) || defined(DEVICE_TC4EX) || defined(DEVICE_TC4PX) */
}


#endif /* !defined(DEVICE_TC45X) */

#if defined (_TASKING_) || defined (_ghs_)
#pragma restore
#endif
