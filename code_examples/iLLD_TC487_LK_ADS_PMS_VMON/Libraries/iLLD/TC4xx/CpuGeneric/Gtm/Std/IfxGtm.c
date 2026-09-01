/**
 * \file IfxGtm.c
 * \brief GTM  basic functionality
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
#pragma warning 508		/* To suppress empty file warning */
#endif
#if defined (__ghs__)
#pragma diag_suppress 96		/* To suppress empty file warning */
#endif

#if defined(DEVICE_TC49XN) || defined(DEVICE_TC46X) || defined(DEVICE_TC4EX)
#include "IfxGtm.h"

/******************************************************************************/
/*-------------------------Function Implementations---------------------------*/
/******************************************************************************/

boolean IfxGtm_ConnectToMsc(IfxGtm_Cluster gtmCluster, IfxGtm_TrigSource gtmSource, IfxGtm_TrigChannel Channel, IfxGtm_MscOut *mscOut)
{
    boolean result     = FALSE;
    uint32  idx        = 0U;
    uint32  indexAltIn = 0U;

    /* 1. Check whether MSC Set is present in table */
    if (IfxGtm_Cfg_MscSetTable[mscOut->mscSet] != NULL_PTR)
    {
        /* Get number of values in table from first index and loop through all entries */
        for (idx = 1u; idx <= IfxGtm_Cfg_MscSetTable[mscOut->mscSet][0]; idx++)                                         /* loop through all SEL values */
        {
            if (IfxGtm_Cfg_MscSetTable[mscOut->mscSet][idx] == IFXGTM_CFG_GETTRIGENTRY(gtmCluster, gtmSource, Channel)) /* check for valid combination */
            {
                result = TRUE;
                break;
            }
        }

        uint8 mscLevel2MuxIndex;
        mscLevel2MuxIndex = (uint8)mscOut->mscModule;

        /* 2. Check whether MSC module is present */
        if ((result == TRUE) && (IfxGtm_Cfg_MscAltInputTable[mscLevel2MuxIndex] != NULL_PTR))
        {
            for (indexAltIn = 0u; indexAltIn < IFXGTM_CFG_NUMMSCALTINPUT; indexAltIn++)   /* loop through all AltInput SEL values */
            {
                /* 3. Check whether ALT input selection exists for MSC Set */
                if (*(IfxGtm_Cfg_MscAltInputTable[mscLevel2MuxIndex] + (((uint32)mscOut->mscAltIn << 2u) + indexAltIn)) == (uint32)mscOut->mscSet)
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

        /* 4. Perform Multiplexer connection */
        if (result == TRUE)
        {
            uint32 shift, mask, sel;

            /* Connection 1: Connect GTM output channel to one of the MSC set */
            shift = ((uint32)mscOut->mscSetSignal & 0x3U) << 0x3u;
            sel   = idx << shift;
            mask  = (uint32)IFX_GTM_MSCSET_CON0_SEL0_MSK << shift;

            switch ((uint8)mscOut->mscSetSignal >> 2)
            {
            case 0:
                Ifx__ldmst(&(MODULE_GTM.MSCSET[mscOut->mscSet].CON0.U), mask, sel);
                break;
            case 1:
                Ifx__ldmst(&(MODULE_GTM.MSCSET[mscOut->mscSet].CON1.U), mask, sel);
                break;
            case 2:
                Ifx__ldmst(&(MODULE_GTM.MSCSET[mscOut->mscSet].CON2.U), mask, sel);
                break;
            case 3:
                Ifx__ldmst(&(MODULE_GTM.MSCSET[mscOut->mscSet].CON3.U), mask, sel);
                break;
            default:
                /* do nothing */
                break;
            }

            /* Connection 2:
             * Connect MSC Set to one of the MSC module and module's INLCON/INLECON/INHCON/INHECON
             */
            shift = ((uint32)mscOut->mscSetSignal << 1u);
            sel   = indexAltIn << shift;
            mask  = (uint32)IFX_GTM_MSC_INLCON_SEL0_MSK << shift;

            switch ((uint8)mscOut->mscAltIn)
            {
            case 0:
                Ifx__ldmst(&(MODULE_GTM.MSC[mscLevel2MuxIndex].INLCON.U), mask, sel);
                break;
            case 1:
                Ifx__ldmst(&(MODULE_GTM.MSC[mscLevel2MuxIndex].INLECON.U), mask, sel);
                break;
            case 2:
                Ifx__ldmst(&(MODULE_GTM.MSC[mscLevel2MuxIndex].INHCON.U), mask, sel);
                break;
            case 3:
                Ifx__ldmst(&(MODULE_GTM.MSC[mscLevel2MuxIndex].INHECON.U), mask, sel);
                break;
            default:
                /* do nothing */
                break;
            }
        }
    }

    return result;
}


void IfxGtm_initApConfig(IfxGtm_ApConfig *config)
{
    uint8 i = 0U;
    IfxApProt_initConfig(&(config->protseConfig));

    IfxApProt_initConfig(&(config->ctrlApConfig.proteConfig));
    IfxApApu_initConfig(&(config->ctrlApConfig.apuConfig));

    IfxApApu_initConfig(&(config->wrapApConfig.apuConfig));

    for (i = 0u; i < IFXGTM_NUM_CCM_OBJECTS; i++)
    {
        IfxApApu_initConfig(&(config->clApConfig[i].apuConfig));
    }
}


void IfxGtm_initAp(Ifx_GTM *gtm, IfxGtm_ApConfig *config)
{
    uint8 i = 0U;
    /* Initialize the PROTs */
    IfxGtm_initProtSe(gtm, &(config->protseConfig));

    IfxGtm_initCtrlProt(gtm, &(config->ctrlApConfig.proteConfig));

    /* Change the state to CONFIG, Configure APU and set PROT state back to RUN */
    /* Initialize the APU */
    (void)IfxApProt_setState((volatile Ifx_PROT_PROT *)(volatile void *)&(gtm->PROTSE), IfxApProt_State_config);
    IfxGtm_initCtrlApu(gtm, &(config->ctrlApConfig.apuConfig));
    (void)IfxApProt_setState((volatile Ifx_PROT_PROT *)(volatile void *)&(gtm->PROTSE), IfxApProt_State_run);

    (void)IfxApProt_setState((volatile Ifx_PROT_PROT *)(volatile void *)&(gtm->PROTSE), IfxApProt_State_config);
    IfxGtm_initWrapApu(gtm, &(config->wrapApConfig.apuConfig));
    (void)IfxApProt_setState((volatile Ifx_PROT_PROT *)(volatile void *)&(gtm->PROTSE), IfxApProt_State_run);

    (void)IfxApProt_setState((volatile Ifx_PROT_PROT *)(volatile void *)&(gtm->PROTSE), IfxApProt_State_config);

    for (i = 0u; i < IFXGTM_NUM_CCM_OBJECTS; i++)
    {
        IfxGtm_initClApu(gtm, (IfxGtm_Cluster)i, &(config->clApConfig[i].apuConfig));
    }

    (void)IfxApProt_setState((volatile Ifx_PROT_PROT *)(volatile void *)&(gtm->PROTSE), IfxApProt_State_run);
}


void IfxGtm_configureAccessToGtms(IfxApApu_ApuConfig *apConfig)
{
    uint8 cluster;
    IfxApApu_init((volatile Ifx_ACCEN_ACCEN *)(volatile void *)&MODULE_GTM.CTRL.ACCEN, apConfig);

    for (cluster = 0u; cluster < IFXGTM_NUM_CCM_OBJECTS; cluster++)
    {
        IfxApApu_init((volatile Ifx_ACCEN_ACCEN *)(volatile void *)&MODULE_GTM.CL[cluster].ACCEN, apConfig);
    }

    IfxApApu_init((volatile Ifx_ACCEN_ACCEN *)(volatile void *)&MODULE_GTM.WRAP.ACCEN, apConfig);
#if defined(DEVICE_TC49XN) || defined(DEVICE_TC4EX)
    IfxApApu_init((volatile Ifx_ACCEN_ACCEN *)(volatile void *)&MODULE_GTM.CTRLGTM.ACCEN, apConfig);

    IfxApApu_init((volatile Ifx_ACCEN_ACCEN *)(volatile void *)&MODULE_GTM.SAFEGTM.ACCEN, apConfig);
#endif /* #if defined(DEVICE_TC49XN) || defined(DEVICE_TC4EX) */
}

#endif /* #if defined(DEVICE_TC49XN) || defined(DEVICE_TC46X) || defined(DEVICE_TC4EX) */

#if defined (_TASKING_) || defined (_ghs_)
#pragma restore
#endif

