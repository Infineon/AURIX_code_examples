/**
 * \file IfxPcieLib_Device.c
 * \brief PCIE DEVICE details
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

#if defined(DEVICE_TC4DX) || defined(DEVICE_TC45X)
#include "IfxPcieLib_Device.h"

/******************************************************************************/
/*-------------------------Function Implementations---------------------------*/
/******************************************************************************/

IfxPcie_Status IfxPcieLib_Device_initAtu(IfxPcie *pcieSFR, IfxPcieLib_Device_Atu *atu, IfxPcieLib_Device_AtuCfg *atuCfg)
{
    IfxPcie_Status status      = IfxPcie_Status_success;
    uint8          inboundReg  = 0u;
    uint8          outboundReg = 0u;

    if (atuCfg != NULL_PTR)     /* check if there is a valid atu Configuration */
    {
        for (inboundReg = 0; inboundReg <= atuCfg->numInboundRegion; inboundReg++)
        {
            IfxPcieLib_Device_initAtuRegion(pcieSFR, &(atu->inboundRegion[inboundReg]), &(atuCfg->inboundRegion[inboundReg]));
        }

        for (outboundReg = 0; outboundReg <= atuCfg->numOutboundRegion; outboundReg++)
        {
            if (atuCfg->outboundRegion[outboundReg].regionIndex != (IfxPcie_AtuRegion)IFXPCIE_CFG_ECAM_ATU_INDEX)
            {
                IfxPcieLib_Device_initAtuRegion(pcieSFR, &(atu->outboundRegion[outboundReg]), &(atuCfg->outboundRegion[outboundReg]));
            }
            else
            {
                status = IfxPcie_Status_failure;
            }
        }
    }

    return status;
}


void IfxPcieLib_Device_initAtuRegion(IfxPcie *pcieSFR, IfxPcieLib_Device_AtuRegion *atuRegion, IfxPcieLib_Device_AtuRegionCfg *atuCfg)
{
    uint8 atuIndex = (uint8)(atuCfg->regionIndex);

    if (atuCfg->direction == IfxPcie_AtuDirection_outBound)
    {
        Ifx_PCIE_DSP_ATU_OUTBOUND *outBoundPtr = &(pcieSFR->DSP.ATU[atuIndex].OUTBOUND);

        outBoundPtr->REGION_CTRL_2.B.REGION_EN = 0u;    /* Disable Region First */

        if (atuCfg->barMapped == FALSE)
        {
            /* Configure the CPU (local) address as original address */
            outBoundPtr->LWR_BASE_ADDR.U   = atuCfg->localMemBase;
            outBoundPtr->UPPER_BASE_ADDR.U = 0U;      /* set to 0 for AURIX 32 Bit */

            /* Configure the Wire address as target address */
            outBoundPtr->LWR_TARGET_ADD.U    = (uint32)(atuCfg->wireMemBase);
            outBoundPtr->UPPER_TARGET_ADDR.U = (uint32)(atuCfg->wireMemBase >> 32u);

            /* Configure the Limit */
            outBoundPtr->LIMIT_ADDR.U = atuCfg->localMemBase + (atuCfg->memSize - 1u);
        }
        else
        {
            /* Do nothing for OUTBOUND currently */
        }

        IfxPcieLib_Device_setupOutboundTlp(outBoundPtr, atuRegion, &(atuCfg->outboundTlp));
        outBoundPtr->REGION_CTRL_2.B.REGION_EN = (uint32)atuCfg->enable;    /* Enable the Region */
    }
    else /* in-bound */
    {
        Ifx_PCIE_DSP_ATU_INBOUND              *inBoundPtr = &(pcieSFR->DSP.ATU[atuIndex].INBOUND);

        inBoundPtr->REGION_CTRL_2.B.REGION_EN = 0u; /* Disable Region First */

        Ifx_PCIE_DSP_ATU_INBOUND_REGION_CTRL_1 regionCtrl1;
        Ifx_PCIE_DSP_ATU_INBOUND_REGION_CTRL_2 regionCtrl2;
        regionCtrl1.U = inBoundPtr->REGION_CTRL_1.U;
        regionCtrl2.U = inBoundPtr->REGION_CTRL_2.U;

        if (atuCfg->barMapped == FALSE)
        {
            /* Configure the CPU (local) address as target address */
            inBoundPtr->LWR_TARGET_ADD.U = (uint32)(atuCfg->localMemBase);

            /* Configure the Wire address as original address */
            inBoundPtr->LWR_BASE_ADDR.U   = (uint32)(atuCfg->wireMemBase);
            inBoundPtr->UPPER_BASE_ADDR.U = (uint32)(atuCfg->wireMemBase >> 32);

            /* Configure the Limit */
            inBoundPtr->LIMIT_ADDR.U = (uint32)(atuCfg->wireMemBase) + (atuCfg->memSize - 1u);
        }
        else
        {
            if (IfxPcie_getDeviceMode(pcieSFR) != IfxPcie_DeviceMode_rc)
            {
                /* Configure the CPU (local) address as target address */
                inBoundPtr->LWR_TARGET_ADD.U = (uint32)(atuCfg->localMemBase);

                regionCtrl2.B.MATCH_MODE     = 1u; /* BAR match mode */
                regionCtrl2.B.BAR_NUM        = (uint32)atuCfg->barIndex;
                atuRegion->barIndex          = atuCfg->barIndex;
            }
        }

        regionCtrl1.B.TYPE                    = atuCfg->outboundTlp.tlpHeader.type; /* Set the TLP Type for match mode */

        inBoundPtr->REGION_CTRL_1.U           = regionCtrl1.U;
        inBoundPtr->REGION_CTRL_2.U           = regionCtrl2.U;
        inBoundPtr->REGION_CTRL_2.B.REGION_EN = (uint32)atuCfg->enable; /* Enable */

        atuRegion->direction                  = IfxPcie_AtuDirection_inBound;
        atuRegion->tlpType                    = atuCfg->inboundTlp.tlpHeader.type;
    }

    atuRegion->localMemBase = atuCfg->localMemBase;
    atuRegion->wireMemBase  = atuCfg->wireMemBase;
    atuRegion->barMapped    = atuCfg->barMapped;
    atuRegion->memSize      = atuCfg->memSize;
    atuRegion->regionIndex  = atuCfg->regionIndex;

    atuRegion->enabled      = TRUE;
    atuRegion->lockStatus   = IfxPcie_AtuLock_locked;
}


void IfxPcieLib_Device_freeAtuRegion(IfxPcie *pcieSFR, IfxPcieLib_Device_AtuRegion *atuRegion)
{
    uint8 atuIndex = (uint8)(atuRegion->regionIndex);

    // TODO: This needs improvement to support CTRL1, CTRL2 flags
    if (atuRegion->direction == IfxPcie_AtuDirection_outBound)
    {
        Ifx_PCIE_DSP_ATU_OUTBOUND *outBoundPtr = &(pcieSFR->DSP.ATU[atuIndex].OUTBOUND);

        outBoundPtr->REGION_CTRL_2.U = 0u;  /* Disable Region */

        if (atuRegion->barMapped == FALSE)
        {
            /* Configure the CPU (local) address as original address */
            outBoundPtr->LWR_BASE_ADDR.U   = 0U;
            outBoundPtr->UPPER_BASE_ADDR.U = 0U;      /* set to 0 for AURIX 32 Bit */

            /* Configure the Wire address as target address */
            outBoundPtr->LWR_TARGET_ADD.U    = 0U;
            outBoundPtr->UPPER_TARGET_ADDR.U = 0U;

            /* Configure the Limit */
            outBoundPtr->LIMIT_ADDR.U = 0U;
        }
        else
        {
            /* Do nothing for OUTBOUND currently */
        }
    }
    else /* in-bound */
    {
        Ifx_PCIE_DSP_ATU_INBOUND *inBoundPtr = &(pcieSFR->DSP.ATU[atuIndex].INBOUND);

        inBoundPtr->REGION_CTRL_2.U = 0u;   /* Disable Region First */

        if (atuRegion->barMapped == FALSE)
        {
            /* Configure the CPU (local) address as target address */
            inBoundPtr->LWR_TARGET_ADD.U = 0U;

            /* Configure the Wire address as original address */
            inBoundPtr->LWR_BASE_ADDR.U   = 0U;
            inBoundPtr->UPPER_BASE_ADDR.U = 0U;

            /* Configure the Limit */
            inBoundPtr->LIMIT_ADDR.U = 0U;
        }
    }

    atuRegion->localMemBase = 0U;
    atuRegion->wireMemBase  = 0U;
    atuRegion->barMapped    = FALSE;
    atuRegion->barIndex     = IfxPcie_BarNum_0;
    atuRegion->memSize      = 0U;

    atuRegion->enabled      = FALSE;
    atuRegion->lockStatus   = IfxPcie_AtuLock_unlocked;
}


void IfxPcieLib_Device_setupOutboundTlp(Ifx_PCIE_DSP_ATU_OUTBOUND *outBoundPtr, IfxPcieLib_Device_AtuRegion *atuRegion, IfxPcieLib_Device_OutboundTlpCfg *outboundTlp)
{
    Ifx_PCIE_DSP_ATU_OUTBOUND_REGION_CTRL_1 regionCtrl1;
    Ifx_PCIE_DSP_ATU_OUTBOUND_REGION_CTRL_2 regionCtrl2;
    regionCtrl1.U            = outBoundPtr->REGION_CTRL_1.U;
    regionCtrl2.U            = outBoundPtr->REGION_CTRL_2.U;

    regionCtrl2.B.DMA_BYPASS = outboundTlp->dmaBypass == TRUE ? 1u : 0u;
    regionCtrl1.B.TYPE       = outboundTlp->tlpHeader.type;

    switch (outboundTlp->tlpHeader.type)
    {
    case IfxPcie_TlpType_memRequest:                                                /* Memory Type */
    case IfxPcie_TlpType_memLockRequest:
        regionCtrl1.B.TC = outboundTlp->tlpHeader.trafficClass;

        if (outboundTlp->tlpHeader.tag != 0u)
        {
            regionCtrl2.B.TAG_SUBSTITUTE_EN = 1u;
            regionCtrl2.B.TAG               = outboundTlp->tlpHeader.tag;
        }

        if (outboundTlp->payloadInhibit == TRUE)
        {
            regionCtrl2.B.INHIBIT_PAYLOAD = 1u;
        }

        if (outboundTlp->tlpHeader.orderingAttr == IfxPcie_TlpOrdering_relaxed)
        {
            regionCtrl1.B.ATTR = (uint32)2u;
        }

        break;
    case IfxPcie_TlpType_msg:                                                             /* Messages Type */
        regionCtrl1.B.TYPE                 = (uint32)(outboundTlp->tlpHeader.type + outboundTlp->tlpHeader.messageRoute);
        regionCtrl1.B.TC                   = (uint32)outboundTlp->tlpHeader.trafficClass; /* Set Traffic Class */
        regionCtrl2.B.MSG_CODE             = (uint32)outboundTlp->tlpHeader.messageCode;  /* Set Message code */
        regionCtrl2.B.HEADER_SUBSTITUTE_EN = 1u;                                          /* Enable Header Substitution */

        outBoundPtr->UPPER_TARGET_ADDR.U   = outboundTlp->tlpHeader.dword3.U;             /* Write Bytes 8-11 */
        outBoundPtr->LWR_TARGET_ADD.U      = outboundTlp->tlpHeader.dword4;               /* Write Bytes 12-15 */

        if (outboundTlp->tlpHeader.tag != 0u)
        {
            regionCtrl2.B.TAG_SUBSTITUTE_EN = 1u;
            regionCtrl2.B.TAG               = outboundTlp->tlpHeader.tag;
        }

        if (outboundTlp->payloadInhibit == TRUE)
        {
            regionCtrl2.B.INHIBIT_PAYLOAD = 1u;
        }

        if (outboundTlp->tlpHeader.orderingAttr == IfxPcie_TlpOrdering_relaxed)
        {
            regionCtrl1.B.ATTR = (uint32)2u;
        }

        break;
    default:
        break;                                                                      /* For all other types, nothing special */
    }

    outBoundPtr->REGION_CTRL_1.U = regionCtrl1.U;
    outBoundPtr->REGION_CTRL_2.U = regionCtrl2.U;

    atuRegion->direction         = IfxPcie_AtuDirection_outBound;
    atuRegion->tlpType           = outboundTlp->tlpHeader.type;
}

#endif /* defined(DEVICE_TC4DX) || defined(DEVICE_TC45X) */

#if defined (_TASKING_) || defined (_ghs_)
#pragma restore
#endif
