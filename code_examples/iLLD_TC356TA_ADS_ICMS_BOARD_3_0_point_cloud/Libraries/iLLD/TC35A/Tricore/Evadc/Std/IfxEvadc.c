/**
 * \file IfxEvadc.c
 * \brief EVADC  basic functionality
 *
 * \version iLLD_1_0_1_16_1
 * \copyright Copyright (c) 2023 Infineon Technologies AG. All rights reserved.
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

#include "IfxEvadc.h"

/******************************************************************************/
/*-------------------------Function Implementations---------------------------*/
/******************************************************************************/

void IfxEvadc_addToQueue(Ifx_EVADC_G *group, IfxEvadc_ChannelId channel, IfxEvadc_RequestSource sourceType, uint32 options)
{
    switch (sourceType)
    {
    case IfxEvadc_RequestSource_queue0:
        group->Q[0].QINR.U = (channel | options);
        break;
    case IfxEvadc_RequestSource_queue1:
        group->Q[1].QINR.U = (channel | options);
        break;
    case IfxEvadc_RequestSource_queue2:
        group->Q[2].QINR.U = (channel | options);

        break;
    }
}


void IfxEvadc_configExternalMultiplexerMode(Ifx_EVADC *evadc, Ifx_EVADC_G *evadcG, IfxEvadc_ExternalMultiplexerMode mode, uint8 channels, IfxEvadc_EmuxSelectValue startChannel, IfxEvadc_EmuxCodingScheme code, IfxEvadc_EmuxSampleTimeControl sampleTimeControl, IfxEvadc_ChannelSelectionStyle channelSelectionStyle)
{
    Ifx_EVADC_G_EMUXCTR emuxctr;
    Ifx_EVADC_G_EMUXCS  emuxcs;

    emuxctr.B.EMXWC    = 1;
    emuxctr.B.EMUXMODE = mode;
    emuxctr.B.EMXCSS   = channelSelectionStyle;
    emuxctr.B.EMUXSET  = startChannel;
    emuxctr.B.EMXCOD   = code;
    emuxctr.B.EMXST    = sampleTimeControl;
    emuxcs.B.EMUXCH    = channels;
    IfxEvadc_enableAccess(evadc, IfxEvadc_Protection_externalMultiplexer);
    evadcG->EMUXCTR.U  = emuxctr.U;
    emuxctr.B.EMXWC    = 0;
    evadcG->EMUXCTR.U  = emuxctr.U;
    evadcG->EMUXCS.U   = emuxcs.U;
    IfxEvadc_disableAccess(evadc, IfxEvadc_Protection_externalMultiplexer);
}


void IfxEvadc_disableAccess(Ifx_EVADC *evadc, IfxEvadc_Protection protectionSet)
{
    uint16 passwd = IfxScuWdt_getSafetyWatchdogPassword();
    IfxScuWdt_clearSafetyEndinit(passwd);

    if (protectionSet < IFXEVADC_MAXIMUM_BITFIELDS_IN_ACCPROT0_REGISTER)
    {
        evadc->ACCPROT0.U |= (0x00000001 << protectionSet);
    }
    else if (protectionSet < IFXEVADC_MAXIMUM_BITFIELDS_IN_ACCPROT1_REGISTER)
    {
        evadc->ACCPROT1.U |= (0x00000001 << (protectionSet & 0x1F));
    }
    else
    {
        evadc->ACCPROT2.U |= (0x00000001 << (protectionSet & 0x3F));
    }

    IfxScuWdt_setSafetyEndinit(passwd);
}


void IfxEvadc_disableQueueSlotExternalTrigger(Ifx_EVADC_G *evadcG, IfxEvadc_RequestSource sourceType)
{
    switch (sourceType)
    {
    case IfxEvadc_RequestSource_queue0:
        evadcG->Q[0].QMR.B.ENTR = 0; /* disable external trigger */
        break;
    case IfxEvadc_RequestSource_queue1:
        evadcG->Q[1].QMR.B.ENTR = 0; /* disable external trigger */
        break;
    case IfxEvadc_RequestSource_queue2:
        evadcG->Q[2].QMR.B.ENTR = 0; /* disable external trigger */
        break;
    }
}


void IfxEvadc_enableAccess(Ifx_EVADC *evadc, IfxEvadc_Protection protectionSet)
{
    uint16 passwd = IfxScuWdt_getSafetyWatchdogPassword();
    IfxScuWdt_clearSafetyEndinit(passwd);

    if (protectionSet < IFXEVADC_MAXIMUM_BITFIELDS_IN_ACCPROT0_REGISTER)
    {
        evadc->ACCPROT0.U &= ~(0x00000001 << protectionSet);
    }
    else if (protectionSet < IFXEVADC_MAXIMUM_BITFIELDS_IN_ACCPROT1_REGISTER)
    {
        evadc->ACCPROT1.U &= ~(0x00000001 << (protectionSet & 0x1F));
    }
    else
    {
        evadc->ACCPROT2.U &= ~(0x00000001 << (protectionSet & 0x3F));
    }

    IfxScuWdt_setSafetyEndinit(passwd);
}


void IfxEvadc_enableQueueSlotExternalTrigger(Ifx_EVADC_G *evadcG, IfxEvadc_RequestSource sourceType)
{
    switch (sourceType)
    {
    case IfxEvadc_RequestSource_queue0:
        evadcG->Q[0].QMR.B.ENTR = 1; /* enable external trigger */
        break;
    case IfxEvadc_RequestSource_queue1:
        evadcG->Q[1].QMR.B.ENTR = 1; /* enable external trigger */
        break;
    case IfxEvadc_RequestSource_queue2:
        evadcG->Q[2].QMR.B.ENTR = 1; /* enable external trigger */

        break;
    }
}


float32 IfxEvadc_getAdcDigitalFrequency(Ifx_EVADC *evadc)
{
    IFX_UNUSED_PARAMETER(evadc);
#ifdef IFX_CFG_AURIX_SCUCCU_USED
    return IfxScuCcu_getSpbFrequency();
#else
    return IfxScuCcu_getAdcFrequency();
#endif
}


float32 IfxEvadc_getAdcModuleFrequency(Ifx_EVADC *evadc)
{
    IFX_UNUSED_PARAMETER(evadc);
#ifdef IFX_CFG_AURIX_SCUCCU_USED
    return IfxScuCcu_getSpbFrequency();
#else
    return IfxScuCcu_getAdcFrequency();
#endif
}


IfxEvadc_GatingMode IfxEvadc_getQueueSlotGatingMode(Ifx_EVADC_G *evadcG, IfxEvadc_RequestSource sourceType)
{
    uint8 gatingMode = 0;

    switch (sourceType)
    {
    case IfxEvadc_RequestSource_queue0:
        gatingMode = evadcG->Q[0].QMR.B.ENGT;
        break;
    case IfxEvadc_RequestSource_queue1:
        gatingMode = evadcG->Q[1].QMR.B.ENGT;
        break;
    case IfxEvadc_RequestSource_queue2:
        gatingMode = evadcG->Q[2].QMR.B.ENGT;

        break;
    }

    return (IfxEvadc_GatingMode)gatingMode;
}


IfxEvadc_GatingSource IfxEvadc_getQueueSlotGatingSource(Ifx_EVADC_G *evadcG, IfxEvadc_RequestSource sourceType)
{
    uint32 gateSource = 0;

    switch (sourceType)
    {
    case IfxEvadc_RequestSource_queue0:
        gateSource = evadcG->Q[0].QCTRL.B.GTSEL;
        break;
    case IfxEvadc_RequestSource_queue1:
        gateSource = evadcG->Q[1].QCTRL.B.GTSEL;
        break;
    case IfxEvadc_RequestSource_queue2:
        gateSource = evadcG->Q[2].QCTRL.B.GTSEL;
        break;
    }

    return (IfxEvadc_GatingSource)gateSource;
}


IfxEvadc_RequestSlotPriority IfxEvadc_getQueueSlotPriority(Ifx_EVADC_G *evadcG, IfxEvadc_RequestSource sourceType)
{
    uint8 slotPriority = 0;

    switch (sourceType)
    {
    case IfxEvadc_RequestSource_queue0:
        slotPriority = evadcG->ARBPR.B.PRIO0;
        break;
    case IfxEvadc_RequestSource_queue1:
        slotPriority = evadcG->ARBPR.B.PRIO1;
        break;
    case IfxEvadc_RequestSource_queue2:
        slotPriority = evadcG->ARBPR.B.PRIO2;
        break;
    }

    return (IfxEvadc_RequestSlotPriority)slotPriority;
}


IfxEvadc_RequestSlotStartMode IfxEvadc_getQueueSlotStartMode(Ifx_EVADC_G *evadcG, IfxEvadc_RequestSource sourceType)
{
    uint8 slotStartMode = 0;

    switch (sourceType)
    {
    case IfxEvadc_RequestSource_queue0:
        slotStartMode = evadcG->ARBPR.B.CSM0;
        break;
    case IfxEvadc_RequestSource_queue1:
        slotStartMode = evadcG->ARBPR.B.CSM1;
        break;
    case IfxEvadc_RequestSource_queue2:
        slotStartMode = evadcG->ARBPR.B.CSM2;
        break;
    }

    return (IfxEvadc_RequestSlotStartMode)slotStartMode;
}


IfxEvadc_TriggerSource IfxEvadc_getQueueSlotTriggerInput(Ifx_EVADC_G *evadcG, IfxEvadc_RequestSource sourceType)
{
    uint32 triggerSource = 0;

    switch (sourceType)
    {
    case IfxEvadc_RequestSource_queue0:
        triggerSource = evadcG->Q[0].QCTRL.B.XTSEL;
        break;
    case IfxEvadc_RequestSource_queue1:
        triggerSource = evadcG->Q[1].QCTRL.B.XTSEL;
        break;
    case IfxEvadc_RequestSource_queue2:
        triggerSource = evadcG->Q[2].QCTRL.B.XTSEL;

        break;
    }

    return (IfxEvadc_TriggerSource)triggerSource;
}


IfxEvadc_TriggerMode IfxEvadc_getQueueSlotTriggerMode(Ifx_EVADC_G *evadcG, IfxEvadc_RequestSource sourceType)
{
    uint8 triggerMode = 0;

    switch (sourceType)
    {
    case IfxEvadc_RequestSource_queue0:
        triggerMode = evadcG->Q[0].QCTRL.B.XTMODE;
        break;
    case IfxEvadc_RequestSource_queue1:
        triggerMode = evadcG->Q[1].QCTRL.B.XTMODE;
        break;
    case IfxEvadc_RequestSource_queue2:
        triggerMode = evadcG->Q[2].QCTRL.B.XTMODE;

        break;
    }

    return (IfxEvadc_TriggerMode)triggerMode;
}


IfxEvadc_Status IfxEvadc_getQueueStatus(Ifx_EVADC_G *group, IfxEvadc_RequestSource sourceType)
{
    IfxEvadc_Status status = IfxEvadc_Status_noError;

    switch (sourceType)
    {
    case IfxEvadc_RequestSource_queue0:

        /* just fill level is checked */
        if (0x7 == group->Q[0].QSR.B.FILL)
        {
            status = IfxEvadc_Status_queueFull;
        }
        else
        {
            status = IfxEvadc_Status_noError;
        }

        break;

    case IfxEvadc_RequestSource_queue1:

        if (0x7 == group->Q[1].QSR.B.FILL)
        {
            status = IfxEvadc_Status_queueFull;
        }
        else
        {
            status = IfxEvadc_Status_noError;
        }

        break;

    case IfxEvadc_RequestSource_queue2:

        if (0x7 == group->Q[2].QSR.B.FILL)
        {
            status = IfxEvadc_Status_queueFull;
        }
        else
        {
            status = IfxEvadc_Status_noError;
        }

        break;
    }

    return status;
}


Ifx_EVADC_G_RES IfxEvadc_getResultBasedOnRequestSource(Ifx_EVADC *evadc, Ifx_EVADC_G *group, IfxEvadc_ChannelId channel, IfxEvadc_RequestSource sourceType)
{
    sint32          sourceResultRegister = -1;
    Ifx_EVADC_G_RES tmpResult;

    switch (sourceType)
    {
    case IfxEvadc_RequestSource_queue0:
        sourceResultRegister = group->Q[0].QCTRL.B.SRCRESREG;
        break;

    case IfxEvadc_RequestSource_queue1:
        sourceResultRegister = group->Q[1].QCTRL.B.SRCRESREG;
        break;

    case IfxEvadc_RequestSource_queue2:
        sourceResultRegister = group->Q[2].QCTRL.B.SRCRESREG;
        break;
    }

    if (sourceResultRegister > 0)
    {
        tmpResult.U = group->RES[sourceResultRegister].U;

        return tmpResult;
    }
    else
    {
        if ((group->CHCTR[channel].B.RESTGT == 1))
        {
            tmpResult.B.VF     = evadc->GLOB.RES.B.VF;
            tmpResult.B.CRS    = evadc->GLOB.RES.B.CRS;
            tmpResult.B.EMUX   = evadc->GLOB.RES.B.EMUX;
            tmpResult.B.CHNR   = evadc->GLOB.RES.B.CHNR;
            tmpResult.B.DRC    = evadc->GLOB.RES.B.GNR;
            tmpResult.B.RESULT = evadc->GLOB.RES.B.RESULT;

            return tmpResult;
        }
        else
        {
            tmpResult.U = group->RES[group->CHCTR[channel].B.RESREG].U;

            return tmpResult;
        }
    }
}


uint32 IfxEvadc_initializeFAdcI(Ifx_EVADC *evadc, uint32 fAdcI, Ifx_EVADC_G *group)
{
    uint32 divA;
    uint32 result;
#ifdef IFX_CFG_AURIX_SCUCCU_USED
    uint32 fadc = IfxScuCcu_getSpbFrequency();
#else
    uint32 fadc = IfxScuCcu_getAdcFrequency();
#endif
    /*    DivA = min(max(0, Fadc / FAdcI - 1), 0x3F); */
    divA   = (fadc << 2) / fAdcI;

    divA   = (divA + 2) >> 2; /* Round to nearest integer */
    divA   = __minu(divA - 1, 0x1Fu);
    result = fadc / (divA + 1);

    if (result > IFXEVADC_ANALOG_FREQUENCY_MAX)
    {
        divA   = __minu(divA + 1, 0x1Fu);

        result = fadc / (divA + 1);
    }
    else
    {
        /* do nothing */
    }

    if (!((result >= IFXEVADC_ANALOG_FREQUENCY_MIN) && (result <= IFXEVADC_ANALOG_FREQUENCY_MAX)))
    {
        result = 0;             /* Min / Max FAdcI frequency */
    }
    else
    {
        IfxEvadc_initialiseAdcConverterClock(evadc, group, (IfxEvadc_ClockDividerFactor)divA);
    }

    return result;
}


boolean IfxEvadc_isRequestQueueSlotEnabled(Ifx_EVADC_G *evadcG, IfxEvadc_RequestSource sourceType)
{
    boolean enabled = 0;

    switch (sourceType)
    {
    case IfxEvadc_RequestSource_queue0:
        enabled = evadcG->ARBPR.B.ASEN0;
        break;
    case IfxEvadc_RequestSource_queue1:
        enabled = evadcG->ARBPR.B.ASEN1;
        break;
    case IfxEvadc_RequestSource_queue2:
        enabled = evadcG->ARBPR.B.ASEN2;
        break;
    }

    return enabled;
}


void IfxEvadc_resetModule(Ifx_EVADC *evadc)
{
    uint16 passwd = IfxScuWdt_getCpuWatchdogPassword();
    IfxScuWdt_clearCpuEndinit(passwd);

    IfxEvadc_enableAccess(evadc, IfxEvadc_Protection_globalConfig);
    evadc->KRST1.B.RST = 1;      /* Only if both Kernel reset bits are set a reset is executed */
    evadc->KRST0.B.RST = 1;
    IfxScuWdt_setCpuEndinit(passwd);

    while (evadc->KRST0.B.RSTSTAT == 0)
    {
        /* Wait until reset is executed */
    }

    IfxScuWdt_clearCpuEndinit(passwd);
    evadc->KRSTCLR.B.CLR = 1;    /* Clear Kernel reset status bit */
    IfxEvadc_disableAccess(evadc, IfxEvadc_Protection_globalConfig);
    IfxScuWdt_setCpuEndinit(passwd);
}


void IfxEvadc_setArbiterPriority(Ifx_EVADC_G *evadcG, boolean slotEnable, IfxEvadc_RequestSlotPriority prio, IfxEvadc_RequestSlotStartMode mode, IfxEvadc_RequestSource slot)
{
    if (slotEnable != FALSE)
    {
        evadcG->ARBPR.U |= slotEnable << (IFX_EVADC_G_ARBPR_ASEN0_OFF + slot); /* enable Slot */
        evadcG->ARBPR.U &= ~(IFX_EVADC_G_ARBPR_PRIO0_MSK << (slot * 4u));      /* clear Priority */
        evadcG->ARBPR.U |= (prio << (slot * 4u));                              /* Set Priority */

        if (mode != IfxEvadc_RequestSlotStartMode_waitForStart)
        {
            evadcG->ARBPR.U |= 0x1u << (IFX_EVADC_G_ARBPR_CSM0_OFF + (slot * 4u)); /* Set cancel inject mode */
        }
        else
        {
            evadcG->ARBPR.U &= ~(0x1u << (IFX_EVADC_G_ARBPR_CSM0_OFF + (slot * 4u)));  /* Set Wait for Start mode */
        }
    }
    else
    {
        evadcG->ARBPR.U &= ~(IFX_EVADC_G_ARBPR_ASEN0_MSK << (IFX_EVADC_G_ARBPR_ASEN0_OFF + slot));  /* disable Slot */
    }
}


void IfxEvadc_setQueueSlotGatingConfig(Ifx_EVADC_G *evadcG, IfxEvadc_GatingSource gatingSource, IfxEvadc_GatingMode gatingMode, IfxEvadc_RequestSource sourceType)
{
    Ifx_EVADC_G_Q_QCTRL qctrl;

    switch (sourceType)
    {
    case IfxEvadc_RequestSource_queue0:

        qctrl.U                 = evadcG->Q[0].QCTRL.U;
        qctrl.B.GTWC            = 1;
        qctrl.B.GTSEL           = gatingSource;
        evadcG->Q[0].QCTRL.U    = qctrl.U;
        evadcG->Q[0].QMR.B.ENGT = gatingMode;
        break;
    case IfxEvadc_RequestSource_queue1:

        qctrl.U                 = evadcG->Q[1].QCTRL.U;
        qctrl.B.GTWC            = 1;
        qctrl.B.GTSEL           = gatingSource;
        evadcG->Q[1].QCTRL.U    = qctrl.U;
        evadcG->Q[1].QMR.B.ENGT = gatingMode;

        break;
    case IfxEvadc_RequestSource_queue2:

        qctrl.U                 = evadcG->Q[2].QCTRL.U;
        qctrl.B.GTWC            = 1;
        qctrl.B.GTSEL           = gatingSource;
        evadcG->Q[2].QCTRL.U    = qctrl.U;
        evadcG->Q[2].QMR.B.ENGT = gatingMode;

        break;
    }
}


void IfxEvadc_setQueueSlotTriggerOperatingConfig(Ifx_EVADC_G *evadcG, IfxEvadc_TriggerMode triggerMode, IfxEvadc_TriggerSource triggerSource, IfxEvadc_RequestSource sourceType)
{
    Ifx_EVADC_G_Q_QCTRL qctrl;

    switch (sourceType)
    {
    case IfxEvadc_RequestSource_queue0:

        qctrl.U              = evadcG->Q[0].QCTRL.U;
        qctrl.B.XTWC         = 1;
        qctrl.B.XTMODE       = triggerMode;
        qctrl.B.XTSEL        = triggerSource;
        evadcG->Q[0].QCTRL.U = qctrl.U;
        break;
    case IfxEvadc_RequestSource_queue1:
        qctrl.U              = evadcG->Q[1].QCTRL.U;
        qctrl.B.XTWC         = 1;
        qctrl.B.XTMODE       = triggerMode;
        qctrl.B.XTSEL        = triggerSource;
        evadcG->Q[1].QCTRL.U = qctrl.U;
        break;
    case IfxEvadc_RequestSource_queue2:
        qctrl.U              = evadcG->Q[2].QCTRL.U;
        qctrl.B.XTWC         = 1;
        qctrl.B.XTMODE       = triggerMode;
        qctrl.B.XTSEL        = triggerSource;
        evadcG->Q[2].QCTRL.U = qctrl.U;

        break;
    }
}


void IfxEvadc_startupCalibration(Ifx_EVADC *evadc)
{
    boolean calibrationRunning;
    uint8   adcCalGroupNum = 0;
    /* Start calibration */
    IfxEvadc_enableAccess(evadc, IfxEvadc_Protection_globalConfig);
    /* Set SUCAL bit */
    IfxEvadc_initiateStartupCalibration(evadc);
    IfxEvadc_disableAccess(evadc, IfxEvadc_Protection_globalConfig);

    /* Wait for hardware self-test and calibration to complete */
    /* Wait until Calibration is done */
    do
    {
        calibrationRunning = FALSE;

        for (adcCalGroupNum = 0; adcCalGroupNum < IFXEVADC_NUM_ADC_GROUPS; adcCalGroupNum++)
        {
            if (IfxEvadc_getAdcCalibrationActiveState(evadc, adcCalGroupNum) != 0)     /* Check ADC Calibration Flag CAL */
            {
                calibrationRunning = TRUE;
            }
            else
            {
                /* do nothing */
            }
        }
    } while (calibrationRunning == TRUE); /* wait until calibration of all calibrated kernels are done */
}


boolean IfxEvadc_syncConvWorkAround(Ifx_EVADC *evadc)
{
    volatile uint32 timeOut = 0;

    boolean         status  = 1; /* 0 = Operation failed.Used for detecting OCDS Debug Active State Activation failure & Trigger Line TL1 Activation failure. */

/* get status of OCDS and trigger line TL1 by reading corresponding OCDS */
    if (MODULE_CBS.OSTATE.B.OEN == 0)
    {
        MODULE_CBS.OEC.B.PAT = 0xA1;
        MODULE_CBS.OEC.B.PAT = 0x5E;
        MODULE_CBS.OEC.B.PAT = 0xA1;
        MODULE_CBS.OEC.B.PAT = 0x5E;
    }

    timeOut = 20;

    while (MODULE_CBS.OSTATE.B.OEN == 0 && (timeOut--) == 0)
    {
        status = 0;
    }

    evadc->OCS.U = 1 << IFX_EVADC_OCS_SUS_P_OFF |
                   3 << IFX_EVADC_OCS_SUS_OFF;

    timeOut = 20;

    while (MODULE_CBS.TLS.B.TL1 == 0 && (timeOut--) == 0)
    {
        MODULE_CBS.TLC.B.TLSP1 = 0x3;         /* trigger line TL1 forced to active */
    }

    timeOut = 20;

    while (MODULE_CBS.TLS.B.TL1 == 0 && (timeOut--) == 0)
    {
        status = 0;
    }

    timeOut = 200;

    while (evadc->OCS.B.SUSSTA == 1 && (timeOut--) == 0)
    {}

    /* For EVADC deactivate Soft Suspend Mode 1 */
    evadc->OCS.U = 1 << IFX_EVADC_OCS_SUS_P_OFF |
                   0 << IFX_EVADC_OCS_SUS_OFF;

    /* Recover status (the status before entering this routine) */

    if (MODULE_CBS.TLS.B.TL1 == 0)            /* trigger line TL1 was not active */
    {
        MODULE_CBS.TLC.B.TLSP1 = 0x2;         /* trigger line TL1 forced inactive*/
        MODULE_CBS.TLC.B.TLSP1 = 0x0;         /* trigger line TL1 unchanged (release forced inactive)*/
    }

    if (MODULE_CBS.OSTATE.B.OEN == 1)         /* OCDS is enabled*/
    {           /*disable OCDS*/
        MODULE_CBS.OEC.B.DS = 1;
    }

    return status;
}
