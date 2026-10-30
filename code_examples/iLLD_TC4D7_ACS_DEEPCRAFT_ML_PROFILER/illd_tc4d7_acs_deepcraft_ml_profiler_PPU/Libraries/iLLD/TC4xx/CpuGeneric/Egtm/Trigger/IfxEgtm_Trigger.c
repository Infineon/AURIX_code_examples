/**
 * \file IfxEgtm_Trigger.c
 * \brief EGTM TRIGGER details
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
#include "IfxEgtm_Trigger.h"

/******************************************************************************/
/*-------------------------Function Implementations---------------------------*/
/******************************************************************************/

boolean IfxEgtm_Trigger_trigToAdc(IfxEgtm_Cluster egtmCluster, IfxEgtm_TrigSource egtmSource, IfxEgtm_TrigChannel Channel, IfxEgtm_Cfg_AdcTriggerSignal adcTrigSignal)
{
    boolean                   result   = FALSE;
    uint32                    idx      = 0U;
    /* Gets a pointer to the ADC trigger table entry for the specified signal */
    IfxEgtm_Cfg_TriggerEntry *tablesel = (IfxEgtm_Cfg_TriggerEntry *)(void *)IfxEgtm_Cfg_AdcTriggerTable[adcTrigSignal];

    /* Checks if the ADC trigger table entry is valid and if the cluster is compatible */
    if ((IfxEgtm_Cfg_AdcTriggerTable[adcTrigSignal] != NULL_PTR) &&
        (tablesel[1].B.cluster == (uint32)egtmCluster))                                                                        /* Check if ADC Trigger signal is compatible with cluster */
    {
    	/* Loop through all SEL values in the table */
        for (idx = 1u; idx <= IfxEgtm_Cfg_AdcTriggerTable[adcTrigSignal][0]; idx++)
        {
        	/* Checks for valid combination */
            if (IfxEgtm_Cfg_AdcTriggerTable[adcTrigSignal][idx] == IFXEGTM_CFG_GETTRIGENTRY(egtmCluster, egtmSource, Channel))
            {
            	/* If a match is found, set the result to TRUE and break out of the loop */
                result = TRUE;
                break;
            }
        }

        /* If a valid combination was found, configure the trigger signal */
        if (result == TRUE)
        {
        	/* Calculates the shift value based on the ADC trigger signal */
            uint32 shift   = ((uint32)adcTrigSignal & 0x3U) * 8u;
            /* Calculates the trigger selection value based on the index */
            uint32 trigsel = idx << shift;
            /* Calculates the mask value based on the shift */
            uint32 mask    = (uint32)0x1FU << shift;

            /* Configures the trigger signal using the calculated values */
            Ifx__ldmst(&(MODULE_EGTM.ADC.OUT[egtmCluster].U), mask, trigsel);
        }
    }

    /* Returns the result */
    return result;
}


boolean IfxEgtm_Trigger_trigToSent(IfxEgtm_Cluster egtmCluster, IfxEgtm_TrigSource egtmSource, IfxEgtm_TrigChannel Channel, IfxEgtm_Cfg_SentTriggerModules sentModule, IfxEgtm_Cfg_SentTriggerSignal sentTrigSignal)
{
    boolean                   result   = FALSE;
    uint32                    idx      = 0U;
    IfxEgtm_Cfg_TriggerEntry *tablesel = (IfxEgtm_Cfg_TriggerEntry *)(void *)IfxEgtm_Cfg_SentTriggerTable[sentTrigSignal];

    /* Checks if sent Trigger signal is compatible with cluster */
    if ((IfxEgtm_Cfg_SentTriggerTable[sentTrigSignal] != NULL_PTR) &&
        (tablesel[1].B.cluster == (uint32)egtmCluster))
    {
    	/* Loop through all SEL values */
        for (idx = 1u; idx <= IfxEgtm_Cfg_SentTriggerTable[sentTrigSignal][0]; idx++)
        {
        	/* Checks for valid combination */
            if (IfxEgtm_Cfg_SentTriggerTable[sentTrigSignal][idx] == IFXEGTM_CFG_GETTRIGENTRY(egtmCluster, egtmSource, Channel))
            {
            	/* If a match is found, set the result to TRUE and break out of the loop */
                result = TRUE;
                break;
            }
        }

        /* If a valid combination was found, configure the trigger signal */
        if (result == TRUE)
        {
        	/* Calculates the shift value based on the SENT trigger signal */
            uint32 shift   = (uint32)sentTrigSignal * 5;
            /* Calculates the trigger selection value based on the index */
            uint32 trigsel = idx << shift;
            /* Calculates the mask value based on the shift */
            uint32 mask    = (uint32)0x1FU << shift;
            /* Configures the trigger signal using the calculated values */
            Ifx__ldmst(&(MODULE_EGTM.SENT[sentModule].OUTA.U), mask, trigsel);
        }
    }

    return result;
}


boolean IfxEgtm_Trigger_trigToPsi5(IfxEgtm_Cluster egtmCluster, IfxEgtm_TrigSource egtmSource, IfxEgtm_TrigChannel Channel, IfxEgtm_Cfg_Psi5TriggerSignal psi5TrigSignal)
{
    boolean result = FALSE;
    uint32  idx    = 0U;

    if (IfxEgtm_Cfg_Psi5TriggerTable[psi5TrigSignal] != NULL_PTR)
    {
    	/* Loop through all SEL values */
        for (idx = 1u; idx <= IfxEgtm_Cfg_Psi5TriggerTable[psi5TrigSignal][0]; idx++)
        {
        	/* Checks for valid combination */
            if (IfxEgtm_Cfg_Psi5TriggerTable[psi5TrigSignal][idx] == IFXEGTM_CFG_GETTRIGENTRY(egtmCluster, egtmSource, Channel))
            {
                result = TRUE;
                break;
            }
        }

        if (result == TRUE)
        {
            uint32 shift   = (uint32)psi5TrigSignal << 2u;
            uint32 trigsel = idx << shift;
            uint32 mask    = (uint32)0xFU << shift;

            Ifx__ldmst(&(MODULE_EGTM.PSI5.OUT.U), mask, trigsel);
        }
    }

    return result;
}


boolean IfxEgtm_Trigger_trigToPsi5s(IfxEgtm_Cluster egtmCluster, IfxEgtm_TrigSource egtmSource, IfxEgtm_TrigChannel Channel, IfxEgtm_Cfg_Psi5sTriggerModules psi5sModule, IfxEgtm_Cfg_Psi5sTriggerSignal psi5sTrigSignal)
{
    boolean result = FALSE;
    uint32  idx    = 0U;

    if (IfxEgtm_Cfg_Psi5sTriggerTable[psi5sTrigSignal] != NULL_PTR)
    {
        for (idx = 1u; idx <= IfxEgtm_Cfg_Psi5sTriggerTable[psi5sTrigSignal][0]; idx++)                                            /* loop through all SEL values */
        {
            if (IfxEgtm_Cfg_Psi5sTriggerTable[psi5sTrigSignal][idx] == IFXEGTM_CFG_GETTRIGENTRY(egtmCluster, egtmSource, Channel)) /* check for valid combination */
            {
                result = TRUE;
                break;
            }
        }

        if (result == TRUE)
        {
            uint32 shift   = (uint32)psi5sTrigSignal << 2u;
            uint32 trigsel = idx << shift;
            uint32 mask    = (uint32)0xFU << shift;

            Ifx__ldmst(&(MODULE_EGTM.PSI5S[psi5sModule].OUT.U), mask, trigsel);
        }
    }

    return result;
}


boolean IfxEgtm_Trigger_trigToCan(IfxEgtm_Cluster egtmCluster, IfxEgtm_TrigSource egtmSource, IfxEgtm_TrigChannel Channel, IfxEgtm_Cfg_CanTriggerSignal canTrigSignal)
{
    boolean result = FALSE;
    uint32  idx    = 0U;

    if (IfxEgtm_Cfg_CanTriggerTable[canTrigSignal] != NULL_PTR)
    {
        for (idx = 1u; idx <= IfxEgtm_Cfg_CanTriggerTable[canTrigSignal][0]; idx++)                                            /* loop through all SEL values */
        {
            if (IfxEgtm_Cfg_CanTriggerTable[canTrigSignal][idx] == IFXEGTM_CFG_GETTRIGENTRY(egtmCluster, egtmSource, Channel)) /* check for valid combination */
            {
                result = TRUE;
                break;
            }
        }

        if (result == TRUE)
        {
            uint32 cannodeSel = ((uint32)canTrigSignal >> 2U);
            uint32 outselReg  = (uint32)canTrigSignal & 0x3U;

            MODULE_EGTM.CAN[cannodeSel].OUT[outselReg].B.SEL = (uint8)idx;
        }
    }

    return result;
}


boolean IfxEgtm_Trigger_trigToQspi(IfxEgtm_Cluster egtmCluster, IfxEgtm_TrigSource egtmSource, IfxEgtm_TrigChannel Channel, IfxEgtm_Cfg_QspiTriggerSignal qspiTrigSignal)
{
    boolean result = FALSE;
    uint16  idx    = 0U;

    if (IfxEgtm_Cfg_QspiTriggerTable[qspiTrigSignal] != NULL_PTR)
    {
        for (idx = 1u; idx <= IfxEgtm_Cfg_QspiTriggerTable[qspiTrigSignal][0]; idx++)                                            /* loop through all SEL values */
        {
            if (IfxEgtm_Cfg_QspiTriggerTable[qspiTrigSignal][idx] == IFXEGTM_CFG_GETTRIGENTRY(egtmCluster, egtmSource, Channel)) /* check for valid combination */
            {
                result = TRUE;
                break;
            }
        }

        if (result == TRUE)
        {
            MODULE_EGTM.QSPI[qspiTrigSignal].OUT.B.SEL = (uint8)idx;
        }
    }

    return result;
}


boolean IfxEgtm_Trigger_trigToAsclin(IfxEgtm_Cluster egtmCluster, IfxEgtm_TrigSource egtmSource, IfxEgtm_TrigChannel Channel, IfxEgtm_Cfg_AsclinTriggerSignal asclinTrigSignal)
{
    boolean result = FALSE;
    uint16  idx    = 0U;

    if (IfxEgtm_Cfg_AsclinTriggerTable[asclinTrigSignal] != NULL_PTR)
    {
        for (idx = 1u; idx <= IfxEgtm_Cfg_AsclinTriggerTable[asclinTrigSignal][0]; idx++)                                            /* loop through all SEL values */
        {
            if (IfxEgtm_Cfg_AsclinTriggerTable[asclinTrigSignal][idx] == IFXEGTM_CFG_GETTRIGENTRY(egtmCluster, egtmSource, Channel)) /* check for valid combination */
            {
                result = TRUE;
                break;
            }
        }

        if (result == TRUE)
        {
            MODULE_EGTM.ASCLIN[asclinTrigSignal].OUT.B.SEL = (uint8)idx;
        }
    }

    return result;
}

#endif /* !defined(DEVICE_TC45X) */

#if defined (_TASKING_) || defined (_ghs_)
#pragma restore
#endif
