/**
 * \file IfxSrc.c
 * \brief SRC basic functionality
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

#include "IfxSrc.h"

/******************************************************************************/
/*-------------------------Function Implementations---------------------------*/
/******************************************************************************/

void IfxSrc_setOtgbSrnIndex(volatile Ifx_INT *intr, IfxSrc_OtgbSrnIndex srnIndex, IfxSrc_OtgbSrnIndexVal *srnIndexVal)
{
    Ifx_INT_OIXS0 intrSel0;
    Ifx_INT_OIXS1 intrSel1;

    intrSel0.U = intr->OIXS0.U;
    intrSel1.U = intr->OIXS1.U;

    switch (srnIndex)
    {
    case IfxSrc_OtgbSrnIndex_srnIndex0: intrSel0.B.IRQ0 = srnIndexVal->srnIndexVal0;
        break;
    case IfxSrc_OtgbSrnIndex_srnIndex1: intrSel0.B.IRQ1 = srnIndexVal->srnIndexVal1;
        break;
    case IfxSrc_OtgbSrnIndex_srnIndex2: intrSel1.B.IRQ2 = srnIndexVal->srnIndexVal2;
        break;
    case IfxSrc_OtgbSrnIndex_srnIndex3: intrSel1.B.IRQ3 = srnIndexVal->srnIndexVal3;
        break;
    }

    intr->OIXS0.U = intrSel0.U;
    intr->OIXS1.U = intrSel1.U;
}


void IfxSrc_initOtgb(volatile Ifx_INT *intr, IfxSrc_OtgbConfig *OtgbConfig)
{
	/* Configures the trigger for the Otgb source */
    IfxSrc_configOtgbTriggerSet(intr, OtgbConfig->trigger);
    /* Used to select the OTGB Bus for the selected triggerSet */
    IfxSrc_configOtgbBusSelect(intr, OtgbConfig->busSelect);

    if (OtgbConfig->trigger == IfxSrc_TrigSet_is)
    {
    	/* Used to select only one SRN index and corresponding SRN index Value */
        IfxSrc_setOtgbSrnIndex(intr, (IfxSrc_OtgbSrnIndex)0U, &OtgbConfig->srnIndexVal);
        IfxSrc_setOtgbSrnIndex(intr, (IfxSrc_OtgbSrnIndex)1U, &OtgbConfig->srnIndexVal);
        IfxSrc_setOtgbSrnIndex(intr, (IfxSrc_OtgbSrnIndex)2U, &OtgbConfig->srnIndexVal);
        IfxSrc_setOtgbSrnIndex(intr, (IfxSrc_OtgbSrnIndex)3U, &OtgbConfig->srnIndexVal);
    }
    else if (OtgbConfig->trigger == IfxSrc_TrigSet_sp)
    {
    	/* Configures interrupt triggers for OTGB service provider based on the provided configuration */
        IfxSrc_configOtgbServiceProviderTrigger(intr, &OtgbConfig->spConfig);
    }
    else
    {
        /* Configured to SPA trigger Set */
    }
}


void IfxSrc_initOtgbConfig(IfxSrc_OtgbConfig *OtgbConfig)
{
	/* Initializes the OTGB configuration structure with default values */
    OtgbConfig->trigger                  = IfxSrc_TrigSet_is;
    OtgbConfig->busSelect                = IfxSrc_OtgbBusSel_otgb0;
    OtgbConfig->srnIndexVal.srnIndexVal0 = 0;
    OtgbConfig->srnIndexVal.srnIndexVal1 = 0;
    OtgbConfig->srnIndexVal.srnIndexVal2 = 0;
    OtgbConfig->srnIndexVal.srnIndexVal3 = 0;
    OtgbConfig->spConfig.tos0            = IfxSrc_Tos_cpu0;
    OtgbConfig->spConfig.tos1            = IfxSrc_Tos_cpu0;
    OtgbConfig->spConfig.bus0Enable      = FALSE;
    OtgbConfig->spConfig.bus1Enable      = FALSE;
}


void IfxSrc_configOtgbServiceProviderTrigger(volatile Ifx_INT *intr, IfxSrc_spConfig *spConfig)
{
    Ifx_INT_OIT irqTrace;
    irqTrace.U = intr->OIT.U;

    if (spConfig->bus0Enable == TRUE)
    {
        irqTrace.B.TOS0 = spConfig->tos0;
        irqTrace.B.OE0  = 1;
    }

    if (spConfig->bus1Enable == TRUE)
    {
        irqTrace.B.TOS1 = spConfig->tos1;
        irqTrace.B.OE1  = 1;
    }

    intr->OIT.U = irqTrace.U;
}


void IfxSrc_configureAccessToSrcs(IfxApApu_ApuConfig *apConfig)
{
#if defined(DEVICE_TC48XAA) || defined(DEVICE_TC48X)
	IfxSrc_Tos tos[IFXSRC_NUM_ICU] = {IfxSrc_Tos_cpu0,IfxSrc_Tos_cpu1,IfxSrc_Tos_cpu2,IfxSrc_Tos_cpu3,IfxSrc_Tos_csrm,IfxSrc_Tos_dma0};
#elif defined(DEVICE_TC46X)
	IfxSrc_Tos tos[IFXSRC_NUM_ICU] = {IfxSrc_Tos_cpu0,IfxSrc_Tos_cpu1,IfxSrc_Tos_cpu2,IfxSrc_Tos_cpu3,IfxSrc_Tos_csrm,IfxSrc_Tos_dma0,IfxSrc_Tos_gtm,IfxSrc_Tos_ppu};
#elif defined(DEVICE_TC45X)
    IfxSrc_Tos tos[IFXSRC_NUM_ICU] = {IfxSrc_Tos_cpu0,IfxSrc_Tos_cpu1,IfxSrc_Tos_csrm,IfxSrc_Tos_dma0,IfxSrc_Tos_ppu,IfxSrc_Tos_rdma };
#elif defined(DEVICE_TC44X)
    IfxSrc_Tos tos[IFXSRC_NUM_ICU] = {IfxSrc_Tos_cpu0,IfxSrc_Tos_cpu1,IfxSrc_Tos_cpu2,IfxSrc_Tos_csrm,IfxSrc_Tos_dma0};
#elif defined(DEVICE_TC4ZX)
    IfxSrc_Tos tos[IFXSRC_NUM_ICU] = {IfxSrc_Tos_cpu0,IfxSrc_Tos_cpu1,IfxSrc_Tos_cpu2,IfxSrc_Tos_cpu3,IfxSrc_Tos_cpu4,IfxSrc_Tos_cpu5,IfxSrc_Tos_csrm,IfxSrc_Tos_dma0,IfxSrc_Tos_dma1};
#elif defined(DEVICE_TC4EX)
    IfxSrc_Tos tos[IFXSRC_NUM_ICU] = {IfxSrc_Tos_cpu0,IfxSrc_Tos_cpu1,IfxSrc_Tos_cpu2,IfxSrc_Tos_csrm,IfxSrc_Tos_dma0,IfxSrc_Tos_gtm,IfxSrc_Tos_ppu};
#elif defined(DEVICE_TC4PX)
    IfxSrc_Tos tos[IFXSRC_NUM_ICU] = {IfxSrc_Tos_cpu0,IfxSrc_Tos_cpu1,IfxSrc_Tos_csrm,IfxSrc_Tos_dma0,IfxSrc_Tos_ppu};
#else
	uint8 tos;
#endif /* #if defined(DEVICE_TC48XAA) || defined(DEVICE_TC48X) */

#if defined(DEVICE_TC49XN)
    /* Allow Service Request register access register access for CPUx targeted SRNs (TOS=x) */
    for (tos = 0; tos < IFXSRC_NUM_CORES; tos++)
    {
        IfxApApu_init((Ifx_ACCEN_ACCEN *)&MODULE_INT.TOS[tos].ACCENSCTRL, apConfig);
        IfxApApu_init((Ifx_ACCEN_ACCEN *)&MODULE_INT.TOS[tos].ACCENSCFG, apConfig);
    }

    for (tos = 6U; tos <= IFXSRC_NUM_ICU; tos++)
	{
		IfxApApu_init((Ifx_ACCEN_ACCEN *)&MODULE_INT.TOS[tos].ACCENSCTRL, apConfig);
		IfxApApu_init((Ifx_ACCEN_ACCEN *)&MODULE_INT.TOS[tos].ACCENSCFG, apConfig);
	}
#elif defined(DEVICE_TC4DX)
    
    /* Allow Service Request register access register access for CPUx targeted SRNs (TOS=x) */
    for (tos = 0; tos < IFXSRC_NUM_ICU; tos++)
    {
        if (tos != IfxSrc_Tos_gtm)
        {
            IfxApApu_init((Ifx_ACCEN_ACCEN *)&MODULE_INT.TOS[tos].ACCENSCTRL, apConfig);
            IfxApApu_init((Ifx_ACCEN_ACCEN *)&MODULE_INT.TOS[tos].ACCENSCFG, apConfig);
        }
    }
#else
    uint8 i;
    /* Allow Service Request register access register access for CPUx targeted SRNs (TOS=x) */
	for (i = 0; i < IFXSRC_NUM_ICU; i++)
	{
		IfxApApu_init((Ifx_ACCEN_ACCEN *)&MODULE_INT.TOS[tos[i]].ACCENSCTRL, apConfig);
		IfxApApu_init((Ifx_ACCEN_ACCEN *)&MODULE_INT.TOS[tos[i]].ACCENSCFG, apConfig);
	}
#endif /* #if defined(DEVICE_TC49XN) */
}
