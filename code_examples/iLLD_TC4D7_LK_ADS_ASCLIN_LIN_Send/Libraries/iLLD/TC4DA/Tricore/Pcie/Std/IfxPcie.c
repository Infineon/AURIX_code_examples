/**
 * \file IfxPcie.c
 * \brief PCIE  basic functionality
 *
 * \version iLLD-TC4-v2.2.0
 * \copyright Copyright (c) 2022 Infineon Technologies AG. All rights reserved.
 *
 *
 *
 *                                 IMPORTANT NOTICE
 *
 * Use of this file is subject to the terms of use agreed between (i) you or
 * the company in which ordinary course of business you are acting and (ii)
 * Infineon Technologies AG or its licensees. If and as long as no such terms
 * of use are agreed, use of this file is subject to following:
 *
 * Boost Software License - Version 1.0 - August 17th, 2003
 *
 * Permission is hereby granted, free of charge, to any person or organization
 * obtaining a copy of the software and accompanying documentation covered by
 * this license (the "Software") to use, reproduce, display, distribute,
 * execute, and transmit the Software, and to prepare derivative works of the
 * Software, and to permit third-parties to whom the Software is furnished to
 * do so, all subject to the following:
 *
 * The copyright notices in the Software and this entire statement, including
 * the above license grant, this restriction and the following disclaimer, must
 * be included in all copies of the Software, in whole or in part, and all
 * derivative works of the Software, unless such copies or derivative works are
 * solely in the form of machine-executable object code generated by a source
 * language processor.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT
 * SHALL THE COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE
 * FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN CONTRACT, TORT OR OTHERWISE,
 * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 *
 *
 */

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include "IfxPcie.h"
#include "IfxPcie_usp_bf.h"

/******************************************************************************/
/*-------------------------Function Implementations---------------------------*/
/******************************************************************************/

void IfxPcie_CfgRdb(Ifx_PCIE_DSP *PcieRcReg, uint32 CfgstartAddr, uint32 offset, uint8 *val)
{
    *val = *((uint8 *)(CfgstartAddr + offset));
}


void IfxPcie_CfgRdl(uint32 CfgstartAddr, uint32 offset, uint32 *val)
{
    *val = *((uint32 *)(CfgstartAddr + (offset)));
}


void IfxPcie_CfgRdw(Ifx_PCIE_DSP *PcieRcReg, uint32 CfgstartAddr, uint32 offset, uint16 *val)
{
    *val = *((uint16 *)(CfgstartAddr + offset));
}


void IfxPcie_CfgWrb(Ifx_PCIE_DSP *PcieRcReg, uint32 CfgstartAddr, uint32 offset, uint8 val)
{
    *((uint8 *)(CfgstartAddr + offset)) = val;
}


void IfxPcie_CfgWrw(Ifx_PCIE_DSP *PcieRcReg, uint32 CfgstartAddr, uint32 offset, uint16 val)
{
    *((uint16 *)(CfgstartAddr + offset)) = val;
    //val = IfxPcie_getCapabilityPtr(CfgstartAddr, offset);
}


void IfxPcie_CfgWrl(uint32 CfgstartAddr, uint32 offset, uint32 val)
{
    *((uint32 *)(CfgstartAddr + (offset))) = val;
}


void IfxPcie_MemRdl(Ifx_PCIE_DSP *PcieRcReg, uint32 MemstartAddr, uint32 offset, uint32 *val)
{
    *val = *((uint32 *)(MemstartAddr + offset));
}


void IfxPcie_MemWrl(Ifx_PCIE_DSP *PcieRcReg, uint32 MemstartAddr, uint32 offset, uint32 val)
{
    *((uint32 *)(MemstartAddr + offset)) = val;
}


void IfxPcie_CpuMemRdl(uint32 MemstartAddr, uint32 offset, uint32 *val)
{
    *val = *((uint32 *)(MemstartAddr + offset));
}


void IfxPcie_CpuMemWrl(uint32 MemstartAddr, uint32 offset, uint32 val)
{
    *((uint32 *)(MemstartAddr + offset)) = val;
}


uint64 IfxPcie_getBarMemSize(volatile uint32 *barReg, boolean doubleWord)
{
    uint64 barMemSize        = 0u;
    uint64 barDoubleWordBase = 0u;
    uint32 barWordBase       = 0u;

    *barReg = 0xFFFFFFFFu;                                                      /* Write all 1's */

    IFXPCIE_CONFIGWRITE_DELAY(IFXPCIE_CFG_CONFIGWRITE_DELAYCOUNT);

    if (doubleWord)
    {
        barDoubleWordBase = (*barReg);
        barReg++;

        *barReg = 0xFFFFFFFFu;

        IFXPCIE_CONFIGWRITE_DELAY(IFXPCIE_CFG_CONFIGWRITE_DELAYCOUNT);

        barDoubleWordBase |= (uint64)(*barReg) << 32u;
        barDoubleWordBase  = barDoubleWordBase & (~(uint64)(0xFu));
        barMemSize         = ~barDoubleWordBase + 1u;
    }
    else
    {
        barWordBase = *barReg;
        barWordBase = barWordBase & (~(uint32)(0xFu));
        barMemSize  = (uint64)((~barWordBase) + 1u);
    }

    barMemSize = (barMemSize == 1u) ? 0 : barMemSize;

    return barMemSize;
}


boolean IfxPcie_getPmeEventStatus(IfxPcie *pcieSFR, IfxPcie_PmeEvent pmeEvent)
{
    boolean eventOccurred = FALSE;

    if ((pmeEvent > IfxPcie_PmeEvent_none)
        && (pmeEvent < IfxPcie_PmeEvent_count))
    {
        if (pmeEvent == IfxPcie_PmeEvent_wakeUp)
        {
            eventOccurred = (pcieSFR->DSP.PM.STAT1.B.WAKINT == 1u) ? TRUE : FALSE;
        }
        else
        {
            switch (pmeEvent)
            {
            case IfxPcie_PmeEvent_pmEvent:
                eventOccurred = (pcieSFR->DSP.PM.CTRL.B.PMEINT == 1u) ? TRUE : FALSE;
                break;
            case IfxPcie_PmeEvent_message:
                eventOccurred = (pcieSFR->DSP.PM.CTRL.B.PMEMSG == 1u) ? TRUE : FALSE;
                break;
            case IfxPcie_PmeEvent_turnOffAck:
                eventOccurred = (pcieSFR->DSP.PM.CTRL.B.TRNACK == 1u) ? TRUE : FALSE;
                break;
            case IfxPcie_PmeEvent_turnOff:
                eventOccurred = (pcieSFR->DSP.PM.CTRL.B.TURNOFF == 1u) ? TRUE : FALSE;
                break;
            default:
                break;
            }
        }
    }

    return eventOccurred;
}


boolean IfxPcie_getPendingPmeInterrupts(IfxPcie *pcieSFR, IfxPcie_PmeInterrupt *pmeInterrupt)
{
    boolean               eventOccurred = FALSE;
    Ifx_PCIE_DSP_PM_STAT1 pmStatus1Reg;
    Ifx_PCIE_DSP_PM_CTRL  pmCtrl;
    pmStatus1Reg.U = pcieSFR->DSP.PM.STAT1.U;
    pmCtrl.U       = pcieSFR->DSP.PM.CTRL.U;

    if (((pmStatus1Reg.U) | (pmCtrl.U)) != 0x0u)
    {
        eventOccurred                      = TRUE;

        pmeInterrupt->B.wakeUp             = (pmStatus1Reg.B.WAKINT == 1u) ? TRUE : FALSE;
        pmeInterrupt->B.pmeEvent           = (pmCtrl.B.PMEINT == 1u) ? TRUE : FALSE;
        pmeInterrupt->B.pmeMessage         = (pmCtrl.B.PMEMSG == 1u) ? TRUE : FALSE;
        pmeInterrupt->B.turnOffAcknowledge = (pmCtrl.B.TRNACK == 1u) ? TRUE : FALSE;
        pmeInterrupt->B.turnOff            = (pmCtrl.B.TURNOFF == 1u) ? TRUE : FALSE;
    }

    return eventOccurred;
}


void IfxPcie_enablePmeInterrupts(IfxPcie *pcieSFR, uint32 enableMask)
{
    pcieSFR->DSP.PM.INTEN.U |= enableMask;
}


void IfxPcie_disablePmeInterrupts(IfxPcie *pcieSFR, uint32 disableMask)
{
    pcieSFR->DSP.PM.INTEN.U &= ~disableMask;
}


void IfxPcie_clearPmeInterrupts(IfxPcie *pcieSFR, uint32 clearMask)
{
    pcieSFR->DSP.PM.INTCLR.U |= clearMask;
}


boolean IfxPcie_getErrorEventStatus(IfxPcie *pcieSFR, IfxPcie_ErrorEvent errorEvent)
{
    boolean eventOccurred = FALSE;

    if ((errorEvent > IfxPcie_ErrorEvent_none)
        && (errorEvent < IfxPcie_ErrorEvent_count))
    {
        Ifx_PCIE_DSP_ERR_STAT errorStat;
        errorStat.U = pcieSFR->DSP.ERR.STAT.U;

        switch (errorEvent)
        {
        case IfxPcie_ErrorEvent_corr:
            eventOccurred = (errorStat.B.CORR == 1u) ? TRUE : FALSE;
            break;
        case IfxPcie_ErrorEvent_nonFatal:
            eventOccurred = (errorStat.B.NFAT == 1u) ? TRUE : FALSE;
            break;
        case IfxPcie_ErrorEvent_fatal:
            eventOccurred = (errorStat.B.FAT == 1u) ? TRUE : FALSE;
            break;
        default:
            break;
        }
    }

    return eventOccurred;
}


boolean IfxPcie_getPendingErrorInterrupts(IfxPcie *pcieSFR, IfxPcie_ErrorInterrupt *errorInterrupt)
{
    boolean               eventOccurred = FALSE;
    Ifx_PCIE_DSP_ERR_STAT errorStat;
    errorStat.U                = pcieSFR->DSP.ERR.STAT.U;

    eventOccurred              = TRUE;
    errorInterrupt->B.corr     = (errorStat.B.CORR == 1u) ? TRUE : FALSE;
    errorInterrupt->B.nonFatal = (errorStat.B.NFAT == 1u) ? TRUE : FALSE;
    errorInterrupt->B.fatal    = (errorStat.B.FAT == 1u) ? TRUE : FALSE;

    return eventOccurred;
}


void IfxPcie_enableErrorInterrupts(IfxPcie *pcieSFR, uint32 enableMask)
{
    pcieSFR->DSP.ERR.INTEN.U |= enableMask;
}


void IfxPcie_disableErrorInterrupts(IfxPcie *pcieSFR, uint32 disableMask)
{
    pcieSFR->DSP.ERR.INTEN.U &= ~disableMask;
}


void IfxPcie_clearErrorInterrupts(IfxPcie *pcieSFR, uint32 clearMask)
{
    pcieSFR->DSP.ERR.INTCLR.U |= clearMask;
}


void IfxPcie_sendPmeTurnOffMessage(IfxPcie *pcieSFR)
{
    pcieSFR->DSP.PM.CTRL.B.TURNOFF = 1u;
}


void IfxPcie_waitForHsphy(Ifx_HSPHY *hsphySFR, IfxHsphy_PhyIndex phyIndex)
{
    /* STEP 1: HSPHY Initializations, if needed */
#if IFXPCIE_CFG_ENABLE_PHY == 1
    uint32 calibDone = 0;

    while (IfxHsphy_isPhyReady(hsphySFR, phyIndex) != TRUE)
    {}

    IfxHsphy_setExtLdDone(hsphySFR, phyIndex);

    /* Wait until PHY finish init */
    while (calibDone == 0)
    {
        hsphySFR->PHYREG[(uint32)phyIndex].CTRL.U = 0x000A4050u;   //Read Access to RAWCMN_DIG_AON_CMNCAL_STATUS

        while (1 == hsphySFR->PHYREG[(uint32)phyIndex].CTRL.B.ACT) //wait until finish reading
        {}

        calibDone  = hsphySFR->PHYREG[(uint32)phyIndex].DATA.U;
        calibDone &= 0x00000002; //second bit indicates whether calibration is completed
    }

#endif
}


void IfxPcie_enableLtrInterrupt(IfxPcie *pcieSFR)
{
    pcieSFR->DSP.LTR.CTRL.B.RLTREN = 1u;
}


void IfxPcie_disableLtrInterrupt(IfxPcie *pcieSFR)
{
    pcieSFR->DSP.LTR.CTRL.B.RLTREN = 0u;
}


boolean IfxPcie_isLtrEventPending(IfxPcie *pcieSFR)
{
    boolean ltrPending = FALSE;

    if (pcieSFR->DSP.LTR.CTRL.B.RLTR == 1u)
    {
        ltrPending = TRUE;
    }

    return ltrPending;
}


void IfxPcie_clearLtrEvent(IfxPcie *pcieSFR)
{
    pcieSFR->DSP.LTR.CTRL.B.RLTRCLR = 1u;
}


uint32 IfxPcie_getLtrMessagePayload(IfxPcie *pcieSFR)
{
    uint32 payload = pcieSFR->DSP.PORTLOGIC.PL_LTR_LATENCY_OFF.U;
    return payload;
}


void IfxPcie_triggerLtrMessage(IfxPcie *pcieSFR)
{
    pcieSFR->USP.LTR.CTRL.B.MSGREQ = 1u;
}


void IfxPcie_enableObffEventInterrupt(IfxPcie *pcieSFR, IfxPcie_ObffType obffType, IfxPcie_ObffEvent obffEvent)
{
    uint32 writeMask = 0x0u;

    if (obffEvent != IfxPcie_ObffEvent_none)
    {
        if (obffType == IfxPcie_ObffType_Msg)
        {
            writeMask = 1U << (IFX_PCIE_USP_OBFFMSG_IDLEEN_OFF + (uint32)(obffEvent * 3u));
            Ifx__ldmst(&(pcieSFR->USP.OBFFMSG), writeMask, writeMask);
        }
        else if (obffType == IfxPcie_ObffType_Wake)
        {
            writeMask = 1U << (IFX_PCIE_USP_OBFFWAKE_IDLEEN_OFF + (uint32)(obffEvent * 3u));
            Ifx__ldmst(&(pcieSFR->USP.OBFFWAKE), writeMask, writeMask);
        }
    }
}


void IfxPcie_disableObffEventInterrupt(IfxPcie *pcieSFR, IfxPcie_ObffType obffType, IfxPcie_ObffEvent obffEvent)
{
    uint32 writeMask = 0x0u;

    if (obffEvent != IfxPcie_ObffEvent_none)
    {
        if (obffType == IfxPcie_ObffType_Msg)
        {
            writeMask = 1U << (IFX_PCIE_USP_OBFFMSG_IDLEEN_OFF + (uint32)(obffEvent * 3u));
            Ifx__ldmst(&(pcieSFR->USP.OBFFMSG), writeMask, 0U);
        }
        else if (obffType == IfxPcie_ObffType_Wake)
        {
            writeMask = 1U << (IFX_PCIE_USP_OBFFWAKE_IDLEEN_OFF + (uint32)(obffEvent * 3u));
            Ifx__ldmst(&(pcieSFR->USP.OBFFWAKE), writeMask, 0U);
        }
    }
}


void IfxPcie_enableObffInterrupts(IfxPcie *pcieSFR, IfxPcie_ObffType obffType)
{
    uint32 writeMask = 0x0u;

    if (obffType == IfxPcie_ObffType_Msg)
    {
        writeMask = ((uint32)(1U << IFX_PCIE_USP_OBFFMSG_IDLEEN_OFF)) | ((uint32)(1U << IFX_PCIE_USP_OBFFMSG_OBFFEN_OFF)) | ((uint32)(1U << IFX_PCIE_USP_OBFFMSG_ACTEN_OFF));
        Ifx__ldmst(&(pcieSFR->USP.OBFFMSG), writeMask, writeMask);
    }
    else if (obffType == IfxPcie_ObffType_Wake)
    {
        writeMask = ((uint32)(1U << IFX_PCIE_USP_OBFFWAKE_IDLEEN_OFF)) | ((uint32)(1U << IFX_PCIE_USP_OBFFWAKE_OBFFEN_OFF)) | ((uint32)(1U << IFX_PCIE_USP_OBFFWAKE_ACTEN_OFF)) | ((uint32)(1U << IFX_PCIE_USP_OBFFWAKE_ERREN_OFF));
        Ifx__ldmst(&(pcieSFR->USP.OBFFWAKE), writeMask, writeMask);
    }
}


void IfxPcie_disableObffInterrupts(IfxPcie *pcieSFR, IfxPcie_ObffType obffType)
{
    uint32 writeMask = 0x0u;

    if (obffType == IfxPcie_ObffType_Msg)
    {
        writeMask = ((uint32)(1U << IFX_PCIE_USP_OBFFMSG_IDLEEN_OFF)) | ((uint32)(1U << IFX_PCIE_USP_OBFFMSG_OBFFEN_OFF)) | ((uint32)(1U << IFX_PCIE_USP_OBFFMSG_ACTEN_OFF));
        Ifx__ldmst(&(pcieSFR->USP.OBFFMSG), writeMask, 0U);
    }
    else if (obffType == IfxPcie_ObffType_Wake)
    {
        writeMask = ((uint32)(1U << IFX_PCIE_USP_OBFFWAKE_IDLEEN_OFF)) | ((uint32)(1U << IFX_PCIE_USP_OBFFWAKE_OBFFEN_OFF)) | ((uint32)(1U << IFX_PCIE_USP_OBFFWAKE_ACTEN_OFF)) | ((uint32)(1U << IFX_PCIE_USP_OBFFWAKE_ERREN_OFF));
        Ifx__ldmst(&(pcieSFR->USP.OBFFWAKE), writeMask, 0U);
    }
}


IfxPcie_ObffEvent IfxPcie_getPendingObffEvent(IfxPcie *pcieSFR, IfxPcie_ObffType obffType)
{
    IfxPcie_ObffEvent event = IfxPcie_ObffEvent_none;

    if (obffType == IfxPcie_ObffType_Msg)
    {
        Ifx_PCIE_USP_OBFFMSG msgReg;
        msgReg.U = pcieSFR->USP.OBFFMSG.U;

        if (msgReg.B.IDLE == 1u)
        {
            event = IfxPcie_ObffEvent_idle;
        }
        else if (msgReg.B.OBFF == 1u)
        {
            event = IfxPcie_ObffEvent_obff;
        }
        else if (msgReg.B.ACT == 1u)
        {
            event = IfxPcie_ObffEvent_cpuActive;
        }
    }
    else if (obffType == IfxPcie_ObffType_Wake)
    {
        Ifx_PCIE_USP_OBFFWAKE wakeReg;
        wakeReg.U = pcieSFR->USP.OBFFWAKE.U;

        if (wakeReg.B.IDLE == 1u)
        {
            event = IfxPcie_ObffEvent_idle;
        }
        else if (wakeReg.B.OBFF == 1u)
        {
            event = IfxPcie_ObffEvent_obff;
        }
        else if (wakeReg.B.ACT == 1u)
        {
            event = IfxPcie_ObffEvent_cpuActive;
        }
        else if (wakeReg.B.WAKERR == 1u)
        {
            event = IfxPcie_ObffEvent_wakeError;
        }
    }

    return event;
}


void IfxPcie_clearPendingObffEvent(IfxPcie *pcieSFR, IfxPcie_ObffType obffType, IfxPcie_ObffEvent obffEvent)
{
    uint32 writeMask = 0x0u;

    if (obffEvent != IfxPcie_ObffEvent_none)
    {
        if (obffType == IfxPcie_ObffType_Msg)
        {
            writeMask = 1U << (IFX_PCIE_USP_OBFFMSG_IDLECLR_OFF + (uint32)(obffEvent * 3u));
            Ifx__ldmst(&(pcieSFR->USP.OBFFMSG), writeMask, 0U);
        }
        else if (obffType == IfxPcie_ObffType_Wake)
        {
            writeMask = 1U << (IFX_PCIE_USP_OBFFWAKE_IDLECLR_OFF + (uint32)(obffEvent * 3u));
            Ifx__ldmst(&(pcieSFR->USP.OBFFWAKE), writeMask, 0U);
        }
    }
}


void IfxPcie_triggerObff(IfxPcie *pcieSFR, IfxPcie_ObffType obffType, IfxPcie_ObffEvent obffEvent)
{
    uint32 writeMask = 0x0u;

    if ((obffEvent != IfxPcie_ObffEvent_none) && (obffEvent != IfxPcie_ObffEvent_wakeError))
    {
        if (obffType == IfxPcie_ObffType_Msg)
        {
            writeMask = 1U << (IFX_PCIE_USP_OBFFMSG_IDLEREQ_OFF + (uint32)(obffEvent));
            Ifx__ldmst(&(pcieSFR->USP.OBFFMSG), writeMask, writeMask);
        }
        else if (obffType == IfxPcie_ObffType_Wake)
        {
            writeMask = 1U << (IFX_PCIE_USP_OBFFWAKE_IDLEREQ_OFF + (uint32)(obffEvent));
            Ifx__ldmst(&(pcieSFR->USP.OBFFWAKE), writeMask, writeMask);
        }
    }
}


void IfxPcie_configureAccessToPcies(IfxApApu_ApuConfig *apConfig)
{
    IfxApApu_init((Ifx_ACCEN_ACCEN *)&MODULE_PCIE0_DSP.ACCEN, apConfig);
    IfxApApu_init((Ifx_ACCEN_ACCEN *)&MODULE_PCIE1_DSP.ACCEN, apConfig);
}
