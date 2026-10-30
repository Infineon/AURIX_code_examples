/**
 * \file IfxPcieLib_Cap.c
 * \brief PCIE CAP details
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
#include "IfxPcieLib_Cap.h"

/******************************************************************************/
/*-------------------------Function Implementations---------------------------*/
/******************************************************************************/

void IfxPcieLib_Cap_probeCapabilities(IfxPcieLib_Cap *cap, IfxPcieDevice_CfgHdr *configHdr)
{
    uint8   capOffset = configHdr->type0.capPtr;
    uint32 *capPtr;
    uint8   capId     = 0u;

    cap->msi.capPtr  = NULL_PTR;        /* Initialize all to NULL first */
    cap->msix.capPtr = NULL_PTR;
    cap->pcie.capPtr = NULL_PTR;
    cap->pmc.capPtr  = NULL_PTR;

    /* Let's start probing for PCI compatible capabilities first */
    while (capOffset != 0u)
    {
        capPtr = (uint32 *)((uint8 *)configHdr + capOffset);
        capId  = (uint8)*capPtr;

        switch (capId)
        {
        case IFXPCIECAP_PCI_CAP_ID_MSI:
            cap->msi.capPtr = (IfxPcieCap_MsiCap *)capPtr;
            break;
        case IFXPCIECAP_PCI_CAP_ID_MSIX:
            cap->msix.capPtr      = (IfxPcieCap_MsixCap *)capPtr;
            cap->msix.tableAddr   = NULL_PTR;
            cap->msix.usedEntries = 0u;
            break;
        case IFXPCIECAP_PCI_CAP_ID_PCIE:
            cap->pcie.capPtr = (IfxPcieCap_PcieCap *)capPtr;
            break;
        case IFXPCIECAP_PCI_CAP_ID_PM:
            cap->pmc.capPtr = (IfxPcieCap_PmCap *)capPtr;
            break;
        default:
            break;
        }

        capOffset = (uint8)(*capPtr >> 8u);
    }

    /* Now, let us start probing for the extended capabilities */

    uint32 extendedCapOffset = 0x100u;
    uint8  vsecIndex         = 0u;

    while (extendedCapOffset != 0u)
    {
        IfxPcieCap_ExtendedCapHeader *extendedCapPtr = (IfxPcieCap_ExtendedCapHeader *)((uint32)configHdr + extendedCapOffset);

        switch (extendedCapPtr->B.capId)
        {
        case IFXPCIECAP_EXTENDED_CAP_ID_AER:
            cap->extendedCap.aer.capPtr = (IfxPcieCap_AerCap *)extendedCapPtr;
            break;
        case IFXPCIECAP_EXTENDED_CAP_ID_PTM:
            cap->extendedCap.ptm.capPtr = (IfxPcieCap_PtmCap *)extendedCapPtr;
            break;
        case IFXPCIECAP_EXTENDED_CAP_ID_LTR:
            cap->extendedCap.ltr.capPtr = (IfxPcieCap_LtrCap *)extendedCapPtr;
            break;
        case IFXPCIECAP_EXTENDED_CAP_ID_SN:
            cap->extendedCap.sn.capPtr = (IfxPcieCap_SnCap *)extendedCapPtr;
            break;
        case IFXPCIECAP_EXTENDED_CAP_ID_VSEC:

            if (vsecIndex < IFXPCIE_CFG_MAX_NUM_VSEC_CAP)                       /* User support for max Vendor Specific Capabilities */
            {
                cap->extendedCap.vsec[vsecIndex].capPtr     = (void *)extendedCapPtr;
                cap->extendedCap.vsec[vsecIndex].extHeader  = (IfxPcieCap_ExtendedCapHeader *)extendedCapPtr;
                cap->extendedCap.vsec[vsecIndex].vsecHeader = (IfxPcieCap_VendorSpecHeader *)((uint32)extendedCapPtr + 4u);
            }

            vsecIndex++;
            break;
        default:
            break;
        }

        extendedCapOffset = extendedCapPtr->B.capOffset;
    }
}


IfxPcie_Status IfxPcieLib_Cap_configureMsiCap(IfxPcieLib_Cap_Msi *msiCap, IfxPcieLib_Cap_MsiCfg *msiCfgPtr)
{
    IfxPcie_Status                  status  = IfxPcie_Status_failure;
    uint8                           msiType = 0u;
    IfxPcieCap_MsiCap              *capPtr  = msiCfgPtr->capPtr;
    volatile IfxPcieCap_MsiMsgCtrl *msgCtrl;
    IfxPcieCap_MsiMsgCtrl           msgCtrlReg;

    if (capPtr != NULL_PTR)
    {
        msiCap->capPtr = msiCfgPtr->capPtr;
        msgCtrl        = &(capPtr->msgControl);
        msgCtrlReg.U   = msgCtrl->U;                                        /* Read Message Control Register */

        if (msgCtrlReg.B.multiMsgCapable >= msiCfgPtr->numInterrupts)       /* Check if device supports all interrupts needed */
        {
            msiType = (uint8)((msgCtrlReg.B.cap64Bit) | ((msgCtrlReg.B.vectorMaskCapable) << 1u));

            switch (msiType)
            {
            case 0u:                                                        /* No per vector mask, 32 bit address */
                capPtr->msiAddress = (uint32)(msiCfgPtr->address);
                capPtr->cap02h     = (uint32)(msiCfgPtr->dataPattern);
                break;
            case 1u:                                                        /* No Per Vector Mask, 64 Bit address */
                capPtr->msiAddress = (uint32)(msiCfgPtr->address);
                capPtr->cap02h     = (uint32)(msiCfgPtr->address >> 32u);
                capPtr->cap03h     = (uint32)(msiCfgPtr->dataPattern);
                break;
            case 2u:                                                        /* Per Vector Mask, 32 Bit address */
                capPtr->msiAddress = (uint32)(msiCfgPtr->address);
                capPtr->cap02h     = (uint32)(msiCfgPtr->dataPattern);
                capPtr->cap03h     = msiCfgPtr->initialMask;
                break;
            case 3u:                                                        /* Per Vector Mask, 64 Bit address */
                capPtr->msiAddress = (uint32)(msiCfgPtr->address);
                capPtr->cap02h     = (uint32)(msiCfgPtr->address >> 32u);
                capPtr->cap03h     = (uint32)(msiCfgPtr->dataPattern);
                capPtr->cap04h     = msiCfgPtr->initialMask;
                break;
            default:
                /* Not possible, do nothing */
                break;
            }

            msgCtrlReg.B.multiMsgEnable = msiCfgPtr->numInterrupts;
            msgCtrl->U                  = msgCtrlReg.U;                     /* Write Message Control Register */
            /* NOTE: MSI is not enabled here, enable separately */

            status = IfxPcie_Status_success;
        }
    }

    return status;
}


IfxPcie_Status IfxPcieLib_Cap_configureMsixCap(IfxPcieLib_Cap_Msix *msixCap, IfxPcieLib_Cap_MsixCfg *msixCfgPtr)
{
    IfxPcie_Status                   status    = IfxPcie_Status_failure;
    IfxPcieCap_MsixCap              *capPtr    = msixCfgPtr->capPtr;
    IfxPcieCap_MsixTableEntry       *tableAddr = msixCfgPtr->tableAddr;
    IfxPcieCap_MsixMsgCtrl           msgCtrlReg;
    volatile IfxPcieCap_MsixMsgCtrl *msgCtrl;
    uint16                           freeTableEntries, index;

    if ((capPtr != NULL_PTR)
        && (tableAddr != NULL_PTR))
    {
        msixCap->capPtr    = capPtr;
        msixCap->tableAddr = tableAddr;

        msgCtrl            = &(capPtr->msgControl);
        msgCtrlReg.U       = msgCtrl->U;                                    /* Read Message Control Register */
        freeTableEntries   = msgCtrlReg.B.tableSize - msixCap->usedEntries + 1u;

        if ((freeTableEntries > 0u)
            && (msixCfgPtr->numInterrupts <= freeTableEntries))
        {
            tableAddr = tableAddr + (msixCap->usedEntries);             /* Get next Table Address */

            for (index = 0u; index < msixCfgPtr->numInterrupts; index++)
            {
                tableAddr->lowerAddress = (uint32)(msixCfgPtr->address);
                tableAddr->upperAddress = (uint32)(msixCfgPtr->address >> 32u);
                tableAddr->data         = msixCfgPtr->dataPattern + index;  /* Data is unique for each interrupt */
                tableAddr->vectorCtrl   = 0x0u;                             /* do not mask */
                msixCap->usedEntries++;                                     /* Used one entry */
                tableAddr++;
            }

            status = IfxPcie_Status_success;
            /* NOTE: MSIX is not enabled here, enable separately */
        }
    }

    return status;
}


IfxPcie_Status IfxPcieLib_Cap_configureAerCap(IfxPcieLib_Cap_Aer *aerCap, IfxPcieLib_Cap_AerCfg *aerCfgPtr)
{
    IfxPcie_Status     status = IfxPcie_Status_failure;
    IfxPcieCap_AerCap *capPtr = aerCfgPtr->capPtr;

    if (capPtr != NULL_PTR)
    {
        aerCap->capPtr = capPtr;

        status        |= IfxPcieCap_setAerCapability(capPtr, IfxPcieCap_AerCapabilities_ecrcCheck, aerCfgPtr->ecrcCheckEnable);
        status        |= IfxPcieCap_setAerCapability(capPtr, IfxPcieCap_AerCapabilities_ecrcGen, aerCfgPtr->ecrcGenEnable);
        status        |= IfxPcieCap_setAerCapability(capPtr, IfxPcieCap_AerCapabilities_mulHdrRec, aerCfgPtr->multipleHdrRecEnable);
    }
    else
    {
        aerCap->capPtr = NULL_PTR;
    }

    return status;
}

#endif /* defined(DEVICE_TC4DX) || defined(DEVICE_TC45X) */

#if defined (_TASKING_) || defined (_ghs_)
#pragma restore
#endif
