/**
 * \file IfxGtm_Tom.c
 * \brief GTM  basic functionality
 *
 * \version iLLD_1_0_1_9_0
 * \copyright Copyright (c) 2018 Infineon Technologies AG. All rights reserved.
 *
 *
 *                                 IMPORTANT NOTICE
 *
 *
 * Infineon Technologies AG (Infineon) is supplying this file for use
 * exclusively with Infineon's microcontroller products. This file can be freely
 * distributed within development tools that are supporting such microcontroller
 * products.
 *
 * THIS SOFTWARE IS PROVIDED "AS IS".  NO WARRANTIES, WHETHER EXPRESS, IMPLIED
 * OR STATUTORY, INCLUDING, BUT NOT LIMITED TO, IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE APPLY TO THIS SOFTWARE.
 * INFINEON SHALL NOT, IN ANY CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL,
 * OR CONSEQUENTIAL DAMAGES, FOR ANY REASON WHATSOEVER.
 *
 */

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include "IfxGtm_Tom.h"
#include "IfxGtm_bf.h"
#include "IfxGtm_Cmu.h"

/******************************************************************************/
/*-------------------------Function Implementations---------------------------*/
/******************************************************************************/

void IfxGtm_Tom_Ch_clearOneNotification(Ifx_GTM_TOM *tom, IfxGtm_Tom_Ch channel)
{
    Ifx_GTM_TOM_CH *tomCh = IfxGtm_Tom_Ch_getChannelPointer(tom, channel);
    tomCh->IRQ_NOTIFY.B.CCU1TC = 1;
}


void IfxGtm_Tom_Ch_clearZeroNotification(Ifx_GTM_TOM *tom, IfxGtm_Tom_Ch channel)
{
    Ifx_GTM_TOM_CH *tomCh = IfxGtm_Tom_Ch_getChannelPointer(tom, channel);
    tomCh->IRQ_NOTIFY.B.CCU0TC = 1;
}


float32 IfxGtm_Tom_Ch_getClockFrequency(Ifx_GTM *gtm, Ifx_GTM_TOM *tom, IfxGtm_Tom_Ch channel)
{
    IfxGtm_Tom_Ch_ClkSrc clock;
    IfxGtm_Cmu_Fxclk     clkIndex[5] = {
        IfxGtm_Cmu_Fxclk_0,      /*IfxGtm_Tom_Ch_ClkSrc_cmuFxclk0 */
        IfxGtm_Cmu_Fxclk_1,      /*IfxGtm_Tom_Ch_ClkSrc_cmuFxclk1 */
        IfxGtm_Cmu_Fxclk_2,      /*IfxGtm_Tom_Ch_ClkSrc_cmuFxclk2 */
        IfxGtm_Cmu_Fxclk_3,      /*IfxGtm_Tom_Ch_ClkSrc_cmuFxclk3 */
        IfxGtm_Cmu_Fxclk_4       /*IfxGtm_Tom_Ch_ClkSrc_cmuFxclk4 */
    };

    clock = IfxGtm_Tom_Ch_getClockSource(tom, channel);

    if (clock == IfxGtm_Tom_Ch_ClkSrc_noClock)
    {
        return 0.0;
    }
    else
    {
        return IfxGtm_Cmu_getFxClkFrequency(gtm, clkIndex[clock], TRUE);
    }
}


IfxGtm_Tom_Ch_ClkSrc IfxGtm_Tom_Ch_getClockSource(Ifx_GTM_TOM *tom, IfxGtm_Tom_Ch channel)
{
    IfxGtm_Tom_Ch_ClkSrc clock = IfxGtm_Tom_Ch_ClkSrc_noClock;

    Ifx_GTM_TOM_CH      *tomCh = IfxGtm_Tom_Ch_getChannelPointer(tom, channel);

    clock = (IfxGtm_Tom_Ch_ClkSrc)tomCh->CTRL.B.CLK_SRC_SR;

    return clock;
}


uint32 IfxGtm_Tom_Ch_getCompareOne(Ifx_GTM_TOM *tom, IfxGtm_Tom_Ch channel)
{
    Ifx_GTM_TOM_CH *tomCh = IfxGtm_Tom_Ch_getChannelPointer(tom, channel);

    return tomCh->CM1.U;
}


volatile uint32 *IfxGtm_Tom_Ch_getCompareOnePointer(Ifx_GTM_TOM *tom, IfxGtm_Tom_Ch channel)
{
    Ifx_GTM_TOM_CH *tomCh = IfxGtm_Tom_Ch_getChannelPointer(tom, channel);

    return (volatile uint32 *)&tomCh->CM1.U;
}


uint32 IfxGtm_Tom_Ch_getCompareZero(Ifx_GTM_TOM *tom, IfxGtm_Tom_Ch channel)
{
    Ifx_GTM_TOM_CH *tomCh = IfxGtm_Tom_Ch_getChannelPointer(tom, channel);

    return tomCh->CM0.U;
}


volatile uint32 *IfxGtm_Tom_Ch_getCompareZeroPointer(Ifx_GTM_TOM *tom, IfxGtm_Tom_Ch channel)
{
    Ifx_GTM_TOM_CH *tomCh = IfxGtm_Tom_Ch_getChannelPointer(tom, channel);
    return (volatile uint32 *)&tomCh->CM0.U;
}


boolean IfxGtm_Tom_Ch_getOutputLevel(Ifx_GTM_TOM *tom, IfxGtm_Tom_Ch channel)
{
    boolean         result;
    Ifx_GTM_TOM_CH *tomCh = IfxGtm_Tom_Ch_getChannelPointer(tom, channel);

    result = tomCh->STAT.B.OL == 1;

    return result;
}


volatile Ifx_SRC_SRCR *IfxGtm_Tom_Ch_getSrcPointer(Ifx_GTM *gtm, IfxGtm_Tom tom, IfxGtm_Tom_Ch channel)
{
    return &MODULE_SRC.GTM.GTM[0].TOM[tom][channel / 2];
}


Ifx_GTM_TOM_TGC *IfxGtm_Tom_Ch_getTgcPointer(Ifx_GTM_TOM *tom, uint32 tgcIndex)
{
    Ifx_GTM_TOM_TGC *pointer;

    if (tgcIndex == 0)
    {
        pointer = (Ifx_GTM_TOM_TGC *)&tom->TGC0_GLB_CTRL;
    }
    else
    {
        pointer = (Ifx_GTM_TOM_TGC *)&tom->TGC1_GLB_CTRL;
    }

    return pointer;
}


volatile uint32 *IfxGtm_Tom_Ch_getTimerPointer(Ifx_GTM_TOM *tom, IfxGtm_Tom_Ch channel)
{
    Ifx_GTM_TOM_CH *tomCh = IfxGtm_Tom_Ch_getChannelPointer(tom, channel);
    return (volatile uint32 *)&tomCh->CN0.U;
}


boolean IfxGtm_Tom_Ch_isOneNotification(Ifx_GTM_TOM *tom, IfxGtm_Tom_Ch channel)
{
    boolean         result;
    Ifx_GTM_TOM_CH *tomCh = IfxGtm_Tom_Ch_getChannelPointer(tom, channel);
    result = tomCh->IRQ_NOTIFY.B.CCU1TC != 0;
    return result;
}


boolean IfxGtm_Tom_Ch_isZeroNotification(Ifx_GTM_TOM *tom, IfxGtm_Tom_Ch channel)
{
    boolean         result;
    Ifx_GTM_TOM_CH *tomCh = IfxGtm_Tom_Ch_getChannelPointer(tom, channel);
    result = tomCh->IRQ_NOTIFY.B.CCU0TC != 0;
    return result;
}


void IfxGtm_Tom_Ch_raiseInterruptOne(Ifx_GTM_TOM *tom, IfxGtm_Tom_Ch channel)
{
    Ifx_GTM_TOM_CH *tomCh = IfxGtm_Tom_Ch_getChannelPointer(tom, channel);
    tomCh->IRQ_FORCINT.B.TRG_CCU1TC0 = 1;
}


void IfxGtm_Tom_Ch_raiseInterruptZero(Ifx_GTM_TOM *tom, IfxGtm_Tom_Ch channel)
{
    Ifx_GTM_TOM_CH *tomCh = IfxGtm_Tom_Ch_getChannelPointer(tom, channel);
    tomCh->IRQ_FORCINT.B.TRG_CCU0TC0 = 1;
}


void IfxGtm_Tom_Ch_setClockSource(Ifx_GTM_TOM *tom, IfxGtm_Tom_Ch channel, IfxGtm_Tom_Ch_ClkSrc clock)
{
    Ifx_GTM_TOM_CH *tomCh = IfxGtm_Tom_Ch_getChannelPointer(tom, channel);

    tomCh->CTRL.B.CLK_SRC_SR = clock;
}


void IfxGtm_Tom_Ch_setCompare(Ifx_GTM_TOM *tom, IfxGtm_Tom_Ch channel, uint32 compareZero, uint32 compareOne)
{
    Ifx_GTM_TOM_CH *tomCh = IfxGtm_Tom_Ch_getChannelPointer(tom, channel);

    tomCh->CM0.U = compareZero; // TK: replaced .B access to optimize runtime
    tomCh->CM1.U = compareOne;
}


void IfxGtm_Tom_Ch_setCompareOne(Ifx_GTM_TOM *tom, IfxGtm_Tom_Ch channel, uint32 compareOne)
{
    Ifx_GTM_TOM_CH *tomCh = IfxGtm_Tom_Ch_getChannelPointer(tom, channel);

    tomCh->CM1.U = compareOne; // TK: replaced .B access to optimize runtime
}


void IfxGtm_Tom_Ch_setCompareOneShadow(Ifx_GTM_TOM *tom, IfxGtm_Tom_Ch channel, uint32 shadowOne)
{
    Ifx_GTM_TOM_CH *tomCh = IfxGtm_Tom_Ch_getChannelPointer(tom, channel);

    tomCh->SR1.U = shadowOne; // TK: replaced .B access to optimize runtime
}


void IfxGtm_Tom_Ch_setCompareShadow(Ifx_GTM_TOM *tom, IfxGtm_Tom_Ch channel, uint32 shadowZero, uint32 shadowOne)
{
    Ifx_GTM_TOM_CH *tomCh = IfxGtm_Tom_Ch_getChannelPointer(tom, channel);

    tomCh->SR0.U = shadowZero; // TK: replaced .B access to optimize runtime
    tomCh->SR1.U = shadowOne;
}


void IfxGtm_Tom_Ch_setCompareZero(Ifx_GTM_TOM *tom, IfxGtm_Tom_Ch channel, uint32 compareZero)
{
    Ifx_GTM_TOM_CH *tomCh = IfxGtm_Tom_Ch_getChannelPointer(tom, channel);

    tomCh->CM0.U = compareZero; // TK: replaced .B access to optimize runtime
}


void IfxGtm_Tom_Ch_setCompareZeroShadow(Ifx_GTM_TOM *tom, IfxGtm_Tom_Ch channel, uint32 shadowZero)
{
    Ifx_GTM_TOM_CH *tomCh = IfxGtm_Tom_Ch_getChannelPointer(tom, channel);

    tomCh->SR0.U = shadowZero; // TK: replaced .B access to optimize runtime
}


void IfxGtm_Tom_Ch_setCounterValue(Ifx_GTM_TOM *tom, IfxGtm_Tom_Ch channel, uint32 value)
{
    Ifx_GTM_TOM_CH *tomCh = IfxGtm_Tom_Ch_getChannelPointer(tom, channel);

    tomCh->CN0.U = value; // TK: replaced .B access to optimize runtime
}


void IfxGtm_Tom_Ch_setGatedCounter(Ifx_GTM_TOM *tom, IfxGtm_Tom_Ch channel, boolean enabled)
{
    if (channel <= IfxGtm_Tom_Ch_7)
    {
        Ifx_GTM_TOM_CH *tomCh = IfxGtm_Tom_Ch_getChannelPointer(tom, channel);

        tomCh->CTRL.B.GCM = enabled ? 1 : 0;
    }
}


void IfxGtm_Tom_Ch_setNotification(Ifx_GTM_TOM *tom, IfxGtm_Tom_Ch channel, IfxGtm_IrqMode mode, boolean interruptOnCompareZero, boolean interruptOnCompareOne)
{
    Ifx_GTM_TOM_CH       *tomCh = IfxGtm_Tom_Ch_getChannelPointer(tom, channel);

    Ifx_GTM_TOM_CH_IRQ_EN en;
    en.U = tomCh->IRQ_EN.U;

    /* Disable all interrupts of the interrupt set to change mode */
    tomCh->IRQ_EN.U            = IFX_ZEROS;
    tomCh->IRQ_MODE.B.IRQ_MODE = mode;
    tomCh->IRQ_EN.U            = en.U; /* Set the values back */

    en.B.CCU0TC_IRQ_EN         = interruptOnCompareZero ? 1 : 0;
    en.B.CCU1TC_IRQ_EN         = interruptOnCompareOne ? 1 : 0;
    tomCh->IRQ_EN.U            = en.U;
}


void IfxGtm_Tom_Ch_setOneShotMode(Ifx_GTM_TOM *tom, IfxGtm_Tom_Ch channel, boolean enabled)
{
    Ifx_GTM_TOM_CH *tomCh = IfxGtm_Tom_Ch_getChannelPointer(tom, channel);

    tomCh->CTRL.B.OSM = enabled ? 1 : 0;
}


void IfxGtm_Tom_Ch_setPcm(Ifx_GTM_TOM *tom, IfxGtm_Tom_Ch channel, boolean enabled)
{
    if (channel == IfxGtm_Tom_Ch_15)
    {
        tom->CH15.CTRL.B.BITREV = enabled ? 1 : 0;  /* FIXME check when datasheet updated, currently not specified */
    }
}


void IfxGtm_Tom_Ch_setResetSource(Ifx_GTM_TOM *tom, IfxGtm_Tom_Ch channel, IfxGtm_Tom_Ch_ResetEvent event)
{
    Ifx_GTM_TOM_CH *tomCh = IfxGtm_Tom_Ch_getChannelPointer(tom, channel);

    tomCh->CTRL.B.RST_CCU0 = event;
}


void IfxGtm_Tom_Ch_setSignalLevel(Ifx_GTM_TOM *tom, IfxGtm_Tom_Ch channel, Ifx_ActiveState activeState)
{
    Ifx_GTM_TOM_CH *tomCh = IfxGtm_Tom_Ch_getChannelPointer(tom, channel);

    tomCh->CTRL.B.SL = activeState == Ifx_ActiveState_high ? 1 : 0;
}


void IfxGtm_Tom_Ch_setSpe(Ifx_GTM_TOM *tom, IfxGtm_Tom_Ch channel, boolean enabled)
{
    if (channel <= IfxGtm_Tom_Ch_7)
    {
        Ifx_GTM_TOM_CH *tomCh = IfxGtm_Tom_Ch_getChannelPointer(tom, channel);

        tomCh->CTRL.B.SPEM = enabled ? 1 : 0;
    }
}


void IfxGtm_Tom_Ch_setTriggerOutput(Ifx_GTM_TOM *tom, IfxGtm_Tom_Ch channel, IfxGtm_Tom_Ch_OutputTrigger trigger)
{
    Ifx_GTM_TOM_CH *tomCh = IfxGtm_Tom_Ch_getChannelPointer(tom, channel);

    tomCh->CTRL.B.TRIGOUT = trigger;
}


uint32 IfxGtm_Tom_Tgc_buildFeature(uint16 enableMask, uint16 disableMask, uint8 bitfieldOffset)
{
    uint8  i;
    uint32 reg  = 0;
    uint32 mask = enableMask | (disableMask << 16);

    for (i = 0; i < IFXGTM_TOM_NUM_TGC_CHANNELS; i++)
    {
        /* Bitfield length is 2 bits */
        uint8 shift = (i * 2) + bitfieldOffset;

        if (mask & 0x1)
        {
            reg |= IfxGtm_FeatureControl_enable << shift;
        }

        if (mask & 0x10000)
        {
            reg |= IfxGtm_FeatureControl_disable << shift;
        }

        mask = mask >> 1;
    }

    return reg;
}


uint32 IfxGtm_Tom_Tgc_buildFeatureForChannel(IfxGtm_Tom_Ch channel, boolean enabled, uint8 bitfieldOffset)
{
    uint32 reg = 0;

    /* Bitfield length is 2 bits */
    uint8  shift = ((channel % 8) * 2) + bitfieldOffset;

    if (enabled == 1)
    {
        reg = IfxGtm_FeatureControl_enable << shift;
    }
    else
    {
        reg = IfxGtm_FeatureControl_disable << shift;
    }

    return reg;
}


void IfxGtm_Tom_Tgc_enableChannel(Ifx_GTM_TOM_TGC *tgc, IfxGtm_Tom_Ch channel, boolean enabled, boolean immediate)
{
    uint32 value;

    value = IfxGtm_Tom_Tgc_buildFeatureForChannel(channel, enabled, IFX_GTM_TOM_TGC0_ENDIS_CTRL_ENDIS_CTRL0_OFF);

    if (immediate)
    {
        tgc->ENDIS_CTRL.U = value;
        tgc->ENDIS_STAT.U = value;
    }
    else
    {
        tgc->ENDIS_CTRL.U = value;
    }
}


void IfxGtm_Tom_Tgc_enableChannelOutput(Ifx_GTM_TOM_TGC *tgc, IfxGtm_Tom_Ch channel, boolean enabled, boolean immediate)
{
    uint32 value;

    value = IfxGtm_Tom_Tgc_buildFeatureForChannel(channel, enabled, IFX_GTM_TOM_TGC0_OUTEN_CTRL_OUTEN_CTRL0_OFF);

    if (immediate)
    {
        tgc->OUTEN_CTRL.U = value;
        tgc->OUTEN_STAT.U = value;
    }
    else
    {
        tgc->OUTEN_CTRL.U = value;
    }
}


void IfxGtm_Tom_Tgc_enableChannelUpdate(Ifx_GTM_TOM_TGC *tgc, IfxGtm_Tom_Ch channel, boolean enabled)
{
    tgc->GLB_CTRL.U = IfxGtm_Tom_Tgc_buildFeatureForChannel(channel, enabled, IFX_GTM_TOM_TGC0_GLB_CTRL_UPEN_CTRL0_OFF);
}


void IfxGtm_Tom_Tgc_enableChannels(Ifx_GTM_TOM_TGC *tgc, uint16 enableMask, uint16 disableMask, boolean immediate)
{
    uint32 value;

    /* FIXME: Alann... is it possible to optimize, not always re-calculating the value using buildFeature function ? */
    value = IfxGtm_Tom_Tgc_buildFeature(enableMask, disableMask, IFX_GTM_TOM_TGC0_ENDIS_CTRL_ENDIS_CTRL0_OFF);

    if (immediate)
    {
        tgc->ENDIS_CTRL.U = value;
        tgc->ENDIS_STAT.U = value;
    }
    else
    {
        tgc->ENDIS_CTRL.U = value;
    }
}


void IfxGtm_Tom_Tgc_enableChannelsOutput(Ifx_GTM_TOM_TGC *tgc, uint16 enableMask, uint16 disableMask, boolean immediate)
{
    uint32 value;

    value = IfxGtm_Tom_Tgc_buildFeature(enableMask, disableMask, IFX_GTM_TOM_TGC0_OUTEN_CTRL_OUTEN_CTRL0_OFF);

    if (immediate)
    {
        tgc->OUTEN_CTRL.U = value;
        tgc->OUTEN_STAT.U = value;
    }
    else
    {
        tgc->OUTEN_CTRL.U = value;
    }
}


void IfxGtm_Tom_Tgc_enableChannelsTrigger(Ifx_GTM_TOM_TGC *tgc, uint16 enableMask, uint16 disableMask)
{
    tgc->INT_TRIG.U = IfxGtm_Tom_Tgc_buildFeature(enableMask, disableMask, IFX_GTM_TOM_TGC0_INT_TRIG_INT_TRIG0_OFF);
}


void IfxGtm_Tom_Tgc_enableChannelsUpdate(Ifx_GTM_TOM_TGC *tgc, uint16 enableMask, uint16 disableMask)
{
    tgc->GLB_CTRL.U = IfxGtm_Tom_Tgc_buildFeature(enableMask, disableMask, IFX_GTM_TOM_TGC0_GLB_CTRL_UPEN_CTRL0_OFF);
}


void IfxGtm_Tom_Tgc_enableTimeTrigger(Ifx_GTM_TOM_TGC *tgc, boolean enabled)
{
    tgc->ACT_TB.B.TB_TRIG = enabled ? 1 : 0;
}


void IfxGtm_Tom_Tgc_resetChannels(Ifx_GTM_TOM_TGC *tgc, uint32 resetMask)
{
    uint8  i;
    uint32 reg = 0;

    for (i = 0; i < IFXGTM_TOM_NUM_TGC_CHANNELS; i++)
    {
        if (resetMask & 0x1)
        {
            reg |= 1 << i;
        }

        resetMask = resetMask >> 1;
    }

    tgc->GLB_CTRL.U = reg << IFX_GTM_TOM_TGC0_GLB_CTRL_RST_CH0_OFF;
}


void IfxGtm_Tom_Tgc_setChannelForceUpdate(Ifx_GTM_TOM_TGC *tgc, IfxGtm_Tom_Ch channel, boolean enabled, boolean resetEnabled)
{
    uint32 regEnable, regReset;

    regEnable        = IfxGtm_Tom_Tgc_buildFeatureForChannel(channel, enabled, IFX_GTM_TOM_TGC0_FUPD_CTRL_FUPD_CTRL0_OFF);
    regReset         = IfxGtm_Tom_Tgc_buildFeatureForChannel(channel, resetEnabled, IFX_GTM_TOM_TGC0_FUPD_CTRL_RSTCN0_CH0_OFF);

    tgc->FUPD_CTRL.U = regEnable | (regReset << 16);
}


void IfxGtm_Tom_Tgc_setChannelsForceUpdate(Ifx_GTM_TOM_TGC *tgc, uint16 enableMask, uint16 disableMask, uint16 resetEnableMask, uint16 resetDisableMask)
{
    uint32 regEnable, regReset;

    regEnable        = IfxGtm_Tom_Tgc_buildFeature(enableMask, disableMask, IFX_GTM_TOM_TGC0_FUPD_CTRL_FUPD_CTRL0_OFF);
    regReset         = IfxGtm_Tom_Tgc_buildFeature(resetEnableMask, resetDisableMask, IFX_GTM_TOM_TGC0_FUPD_CTRL_RSTCN0_CH0_OFF);

    tgc->FUPD_CTRL.U = regEnable | regReset;
}


void IfxGtm_Tom_Tgc_setTimeTrigger(Ifx_GTM_TOM_TGC *tgc, IfxGtm_Tbu_Ts base, uint32 value)
{
    Ifx_GTM_TOM_TGC0_ACT_TB act_tb;

    act_tb.U         = tgc->ACT_TB.U;
    act_tb.B.TBU_SEL = base;
    act_tb.B.ACT_TB  = value;
    tgc->ACT_TB.U    = act_tb.U;
}


void IfxGtm_Tom_Tgc_trigger(Ifx_GTM_TOM_TGC *tgc)
{
    tgc->GLB_CTRL.U = 1 << IFX_GTM_TOM_TGC0_GLB_CTRL_HOST_TRIG_OFF;
}
