/**
 * \file IfxAdc.c
 * \brief ADC  basic functionality
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

#include "IfxAdc.h"

/******************************************************************************/
/*-------------------------Function Implementations---------------------------*/
/******************************************************************************/

void IfxAdc_suspendTmadcModule(IfxAdc_TmadcModule moduleId, IfxAdc_TmadcSuspendMode mode)
{
    Ifx_ADC_OCSTM ocsTmadc;
    ocsTmadc.U         = MODULE_ADC.OCSTM.U;
    ocsTmadc.B.SUSM    = mode;
    ocsTmadc.B.SUS     = (1u << moduleId);
    ocsTmadc.B.SUS_P   = 1u;
    MODULE_ADC.OCSTM.U = ocsTmadc.U;

    while (MODULE_ADC.OCSTM.B.SUSSTA == 0u)
    {
        /* Wait until module is not suspended */
    }
}


volatile Ifx_SRC_SRCR *IfxAdc_getTmadcSrcPointer(IfxAdc_TmadcModule moduleId, IfxAdc_TmadcServReq node)
{
    volatile Ifx_SRC_SRCR *srcPtr = NULL_PTR;

    switch (node)
    {
    case IfxAdc_TmadcServReq_0:
        srcPtr = (volatile Ifx_SRC_SRCR *)(&MODULE_SRC.TMADC[moduleId].SR[0]);
        break;
    case IfxAdc_TmadcServReq_1:
        srcPtr = (volatile Ifx_SRC_SRCR *)(&MODULE_SRC.TMADC[moduleId].SR[1]);
        break;
    case IfxAdc_TmadcServReq_2:
        srcPtr = (volatile Ifx_SRC_SRCR *)(&MODULE_SRC.TMADC[moduleId].SR[2]);
        break;
    case IfxAdc_TmadcServReq_3:
        srcPtr = (volatile Ifx_SRC_SRCR *)(&MODULE_SRC.TMADC[moduleId].SR[3]);
        break;
    case IfxAdc_TmadcServReq_4:
        srcPtr = (volatile Ifx_SRC_SRCR *)(&MODULE_SRC.TMADC[moduleId].SR[4]);
        break;
    case IfxAdc_TmadcServReq_5:
        srcPtr = (volatile Ifx_SRC_SRCR *)(&MODULE_SRC.TMADC[moduleId].SR[5]);
        break;
    default:
        /* Invalid Module id*/
        break;
    }

    return srcPtr;
}


#if IFXADC_IS_DSADC_AVAILABLE
volatile Ifx_SRC_SRCR *IfxAdc_getDsadcSrcPointer(IfxAdc_DsadcChannel channelId, uint8 node)
{
    volatile Ifx_SRC_SRCR *srcPtr = NULL_PTR;

    switch (node)
    {
    case 0:
        srcPtr = (volatile Ifx_SRC_SRCR *)(&MODULE_SRC.DSADC[channelId].SR[0]);
        break;
    case 1:
        srcPtr = (volatile Ifx_SRC_SRCR *)(&MODULE_SRC.DSADC[channelId].SR[1]);
        break;
    case 2:
        srcPtr = (volatile Ifx_SRC_SRCR *)(&MODULE_SRC.DSADC[channelId].SR[2]);
        break;
    case 3:
        srcPtr = (volatile Ifx_SRC_SRCR *)(&MODULE_SRC.DSADC[channelId].SR[3]);
        break;
    default:
        /* Invalid Channel id*/
        break;
    }

    return srcPtr;
}


#if IFXADC_IS_EXMOD_AVAILABLE
volatile Ifx_SRC_SRCR *IfxAdc_getExmodSrcPointer(IfxAdc_Exmod channelId, uint8 node)
{
    volatile Ifx_SRC_SRCR *srcPtr = NULL_PTR;

    switch (node)
    {
    case 0:
        srcPtr = (volatile Ifx_SRC_SRCR *)(&MODULE_SRC.EXMOD[channelId].SR[0]);
        break;
    case 1:
        srcPtr = (volatile Ifx_SRC_SRCR *)(&MODULE_SRC.EXMOD[channelId].SR[1]);
        break;
    case 2:
        srcPtr = (volatile Ifx_SRC_SRCR *)(&MODULE_SRC.EXMOD[channelId].SR[2]);
        break;
    case 3:
        srcPtr = (volatile Ifx_SRC_SRCR *)(&MODULE_SRC.EXMOD[channelId].SR[3]);
        break;
    default:
        /* Invalid Channel id*/
        break;
    }

    return srcPtr;
}
#endif /* #if IFXADC_IS_EXMOD_AVAILABLE */
#endif /* #if IFXADC_IS_DSADC_AVAILABLE */


#if IFXADC_IS_CDSP_AVAILABLE
void IfxAdc_suspendCdspCore(IfxAdc_CdspCore coreId, IfxAdc_CdspSuspendMode mode)
{
    Ifx_ADC_CDSP_OCSCDSPA ocsCdspA;
#if IFXADC_NUM_CDSP_CORES > 9U
    Ifx_ADC_CDSP_OCSCDSPB ocsCdspB;
#endif

#if IFXADC_NUM_CDSP_CORES > 9U

    if (coreId < IfxAdc_CdspCore_9)
#endif
    {
        ocsCdspA.U                 = MODULE_ADC.CDSP.OCSCDSPA.U;
        ocsCdspA.B.SUSM            = mode;
        ocsCdspA.B.SUS             = (1u << coreId);
        ocsCdspA.B.SUS_P           = 1u;
        MODULE_ADC.CDSP.OCSCDSPA.U = ocsCdspA.U;

        while (((MODULE_ADC.CDSP.OCSCDSPA.B.SUSSTA >> coreId) & 0x01) != 1u)
        {
            /* Wait until module is not suspended */
        }
    }

#if IFXADC_NUM_CDSP_CORES > 9U
    else
    {
        coreId                     = (IfxAdc_CdspCore)(coreId - IfxAdc_CdspCore_9);
        ocsCdspB.U                 = MODULE_ADC.CDSP.OCSCDSPB.U;
        ocsCdspB.B.SUSM            = mode;
        ocsCdspB.B.SUS             = (1u << coreId);
        ocsCdspB.B.SUS_P           = 1u;
        MODULE_ADC.CDSP.OCSCDSPA.U = ocsCdspB.U;

        while (((MODULE_ADC.CDSP.OCSCDSPB.B.SUSSTA >> coreId) & 0x01) != 1u)
        {
            /* Wait until module is not suspended */
        }
    }
#endif
}


volatile Ifx_SRC_SRCR *IfxAdc_getCdspSrcPointer(IfxAdc_CdspCore coreId, uint8 node)
{
    volatile Ifx_SRC_SRCR *srcPtr = NULL_PTR;

    switch (node)
    {
    case 0:
        srcPtr = (volatile Ifx_SRC_SRCR *)(&MODULE_SRC.CDSP[coreId].SR[0]);
        break;
    case 1:
        srcPtr = (volatile Ifx_SRC_SRCR *)(&MODULE_SRC.CDSP[coreId].SR[1]);
        break;
    case 2:
        srcPtr = (volatile Ifx_SRC_SRCR *)(&MODULE_SRC.CDSP[coreId].SR[2]);
        break;
    default:
        /* Invalid Node*/
        break;
    }

    return srcPtr;
}
#endif /* #if IFXADC_IS_CDSP_AVAILABLE */


void IfxAdc_configureAccessToAdc(IfxApApu_ApuConfig *apConfig)
{
    uint8 index = 0u;

    for (index = 0u; index < IFXADC_NUM_APU; index++)
    {
        IfxApApu_init((Ifx_ACCEN_ACCEN *)&MODULE_ADC.ACCEN[index], apConfig);
    }
}


void IfxAdc_configureAccessToAdcModule(Ifx_ADC *adc, IfxApApu_ApuConfig *apuConfig, IfxAdc_Apu apuId)
{
    IfxApApu_init((Ifx_ACCEN_ACCEN *)&adc->ACCEN[apuId], apuConfig);
}


#if IFXADC_IS_GTM_AVAILABLE
void IfxAdc_routeBoundaryFlagOutputToGtm(Ifx_ADC *adc, IfxAdc_BoundaryFlagOutput output, IfxAdc_Select_BoundaryFlag moduleBoundaryFlag, uint8 gtmCluster)
{
	volatile Ifx_ADC_GTBFSEL *regPtr_GTBFSEL= &adc->GTBFSEL[gtmCluster];

	switch (output)
	{
	case IfxAdc_BoundaryFlagOutput_0:
		regPtr_GTBFSEL->B.OUT0SEL = (uint32)moduleBoundaryFlag;
	break;
	case IfxAdc_BoundaryFlagOutput_1:
		regPtr_GTBFSEL->B.OUT1SEL = (uint32)moduleBoundaryFlag;
	break;
	case IfxAdc_BoundaryFlagOutput_2:
		regPtr_GTBFSEL->B.OUT2SEL = (uint32)moduleBoundaryFlag;
	break;
	case IfxAdc_BoundaryFlagOutput_3:
		regPtr_GTBFSEL->B.OUT3SEL = (uint32)moduleBoundaryFlag;
	break;
	default:
	/* Wrong value! do nothing*/
	break;
	}
}
#endif /* #if IFXADC_IS_GTM_AVAILABLE */


#if IFXADC_IS_EGTM_AVAILABLE
void IfxAdc_routeBoundaryFlagOutputToEgtm(Ifx_ADC *adc, IfxAdc_BoundaryFlagOutput output, IfxAdc_Select_BoundaryFlag moduleBoundaryFlag, uint8 egtmCluster)
{
	volatile Ifx_ADC_ETBFSEL *regPtr_ETBFSEL= &adc->ETBFSEL[egtmCluster];

	switch (output)
	{
	case IfxAdc_BoundaryFlagOutput_0:
		regPtr_ETBFSEL->B.OUT0SEL = (uint32)moduleBoundaryFlag;
	break;
	case IfxAdc_BoundaryFlagOutput_1:
		regPtr_ETBFSEL->B.OUT1SEL = (uint32)moduleBoundaryFlag;
	break;
	case IfxAdc_BoundaryFlagOutput_2:
		regPtr_ETBFSEL->B.OUT2SEL = (uint32)moduleBoundaryFlag;
	break;
	case IfxAdc_BoundaryFlagOutput_3:
		regPtr_ETBFSEL->B.OUT3SEL = (uint32)moduleBoundaryFlag;
	break;
	default:
	/* Wrong value! do nothing*/
	break;
	}
}
#endif /* #if IFXADC_IS_EGTM_AVAILABLE */
