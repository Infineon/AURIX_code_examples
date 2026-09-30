/**
 * \file IfxAsclin.c
 * \brief ASCLIN  basic functionality
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

#include "IfxAsclin.h"

/******************************************************************************/
/*-------------------------Function Implementations---------------------------*/
/******************************************************************************/

void IfxAsclin_disableModule(Ifx_ASCLIN *asclin)
{
	/* disables the module */
    IfxAsclin_setDisableModuleRequest(asclin);
}


void IfxAsclin_enableAscErrorFlags(Ifx_ASCLIN *asclin, boolean parEnable, boolean rfoEnable)
{
	/* enables parity error */
    IfxAsclin_enableParityErrorFlag(asclin, parEnable);
    /* enables Rx fifo Overflow error */
    IfxAsclin_enableRxFifoOverflowFlag(asclin, rfoEnable);
}


void IfxAsclin_enableModule(Ifx_ASCLIN *asclin)
{
	/* enables the module */
    IfxAsclin_setEnableModuleRequest(asclin);
}


Ifx_ASCLIN *IfxAsclin_getAddress(IfxAsclin_Index asclin)
{
    Ifx_ASCLIN *module;

    if (asclin < IFXASCLIN_NUM_MODULES)
    {
        module = (Ifx_ASCLIN *)IfxAsclin_cfg_indexMap[asclin].module;
    }
    else
    {
        module = NULL_PTR;
    }

    return module;
}


uint32 IfxAsclin_getFaFrequency(Ifx_ASCLIN *asclin)
{
    uint32                frequency;
    /* gets the current clock source */
    IfxAsclin_ClockSource clockSource = (IfxAsclin_ClockSource)IfxAsclin_getClockSource(asclin);

    switch (clockSource)
    {
    /* gets the respective frequency */
    case IfxAsclin_ClockSource_noClock:
        frequency = 0;
        break;
    case IfxAsclin_ClockSource_ascFastClock:
        frequency = IfxClock_getAsclinFFrequency();
        break;
    case IfxAsclin_ClockSource_ascSlowClock:
        frequency = IfxClock_getAsclinSFrequency();
        break;
    default:
        frequency = 0;
        break;
    }

    return frequency;
}


IfxAsclin_Index IfxAsclin_getIndex(Ifx_ASCLIN *asclin)
{
    uint32          index;
    IfxAsclin_Index result;

    result = IfxAsclin_Index_none;

    for (index = 0; index < IFXASCLIN_NUM_MODULES; index++)
    {
        if (IfxAsclin_cfg_indexMap[index].module == asclin)
        {
            result = (IfxAsclin_Index)IfxAsclin_cfg_indexMap[index].index;
            break;
        }
    }

    return result;
}


float32 IfxAsclin_getOvsFrequency(Ifx_ASCLIN *asclin)
{
    return (IfxAsclin_getPdFrequency(asclin) * asclin->BRG.B.NUMERATOR) / asclin->BRG.B.DENOMINATOR;
}


float32 IfxAsclin_getPdFrequency(Ifx_ASCLIN *asclin)
{
    return (float32)IfxAsclin_getFaFrequency(asclin) / (asclin->BITCON.B.PRESCALER + 1);
}


float32 IfxAsclin_getShiftFrequency(Ifx_ASCLIN *asclin)
{
    return IfxAsclin_getOvsFrequency(asclin) / (asclin->BITCON.B.OVERSAMPLING + 1);
}


volatile Ifx_SRC_SRCR *IfxAsclin_getSrcPointerEr(Ifx_ASCLIN *asclin)
{
    return (volatile Ifx_SRC_SRCR *)(&MODULE_SRC.ASCLIN[IfxAsclin_getIndex(asclin)].ERR);
}


volatile Ifx_SRC_SRCR *IfxAsclin_getSrcPointerRx(Ifx_ASCLIN *asclin)
{
    return (volatile Ifx_SRC_SRCR *)(&MODULE_SRC.ASCLIN[IfxAsclin_getIndex(asclin)].RX);
}


volatile Ifx_SRC_SRCR *IfxAsclin_getSrcPointerTx(Ifx_ASCLIN *asclin)
{
    return (volatile Ifx_SRC_SRCR *)(&MODULE_SRC.ASCLIN[IfxAsclin_getIndex(asclin)].TX);
}


uint32 IfxAsclin_read16(Ifx_ASCLIN *asclin, uint16 *data, uint32 count)
{
    volatile Ifx_ASCLIN_RXDATA *rxData = (volatile Ifx_ASCLIN_RXDATA *)&asclin->RXDATA[0].U;

    while (count > 0)
    {
        *data++ = (uint16)rxData->U;
        count--;
    }

    return count;
}


uint32 IfxAsclin_read32(Ifx_ASCLIN *asclin, uint32 *data, uint32 count)
{
    volatile Ifx_ASCLIN_RXDATA *rxData = (volatile Ifx_ASCLIN_RXDATA *)&asclin->RXDATA[0].U;

    while (count > 0)
    {
        *data++ = rxData->U;
        count--;
    }

    return count;
}


uint32 IfxAsclin_read8(Ifx_ASCLIN *asclin, uint8 *data, uint32 count)
{
    volatile Ifx_ASCLIN_RXDATA *rxData = (volatile Ifx_ASCLIN_RXDATA *)&asclin->RXDATA[0].U;

    while (count > 0)
    {
        *data++ = (uint8)rxData->U;
        count--;
    }

    return count;
}


void IfxAsclin_resetModule(Ifx_ASCLIN *asclin)
{
#if (IFX_PROT_ENABLED == 1U)
    IfxApProt_setState((Ifx_PROT_PROT *)&(asclin->PROTE), IfxApProt_State_config);
#endif
    asclin->RST.CTRLA.B.KRST = 1;           /* only if both Kernel reset bits are set a reset is executed */
    asclin->RST.CTRLB.B.KRST = 1;

    /* wait until reset is executed */
    while (0 == asclin->RST.STAT.B.KRST)
    {}

    /* clear Kernel reset status bit */
    asclin->RST.CTRLB.B.STATCLR = 1;

    /* wait until KRST is cleared, only after this reset sequence is completed */
    while (asclin->RST.STAT.B.KRST == 1)
    {}

#if (IFX_PROT_ENABLED == 1U)
    IfxApProt_setState((Ifx_PROT_PROT *)&(asclin->PROTE), IfxApProt_State_run);
#endif
}


void IfxAsclin_setBaudrateBitFields(Ifx_ASCLIN *asclin, uint16 prescaler, uint16 numerator, uint16 denominator, IfxAsclin_OversamplingFactor oversampling)
{
    IfxAsclin_ClockSource clockSource = (IfxAsclin_ClockSource)IfxAsclin_getClockSource(asclin); /* gets the current clock source */
    IfxAsclin_setClockSource(asclin, IfxAsclin_ClockSource_noClock);                             /* turns off the clock for settings */
    IfxAsclin_setPrescaler(asclin, prescaler);                                                   /* sets the prescaler*/
    IfxAsclin_setNumerator(asclin, numerator);                                                   /* sets the numerator*/
    IfxAsclin_setDenominator(asclin, denominator);                                               /* sets the denominator*/
    IfxAsclin_setOversampling(asclin, oversampling);                                             /* sets the oversampling*/
    IfxAsclin_setClockSource(asclin, clockSource);                                               /* sets the clock source back on*/
}


boolean IfxAsclin_setBitTiming(Ifx_ASCLIN *asclin, float32 baudrate, IfxAsclin_OversamplingFactor oversampling, IfxAsclin_SamplePointPosition samplepoint, IfxAsclin_SamplesPerBit medianFilter)
{
    IfxAsclin_ClockSource source = (IfxAsclin_ClockSource)IfxAsclin_getClockSource(asclin);
    float32               fOvs;
    uint32                d      = 0, n, dBest = 1, nBest = 1;
    float32               f;

    /* get the prescaler value */
    uint32                prescaler      = asclin->BITCON.B.PRESCALER + 1;
    /* get the PD frequency */
    float32               fpd            = IfxAsclin_getPdFrequency(asclin);
    /* min. value of (l_oversampling + 1) is 4 */
    uint32                l_oversampling = (IfxAsclin_OversamplingFactor)__maxu((oversampling + 1), 4);
    samplepoint = (IfxAsclin_SamplePointPosition)__maxu(samplepoint, 1);
    /* calculate the required  fOvs */
    fOvs        = baudrate * l_oversampling;
    float32               relError   = fOvs;
    float32               limit;                                         /* save the error limit */
    boolean               terminated = FALSE;
    float32               newRelError;
    uint32                adder_facL, adder_facH, adder_facL_min, count;

    /* increment the limit with the increase in baud rate */
    if (baudrate <= 6000)
    {
        limit = 0.01f * fOvs;
    }
    else if (baudrate < 100000)
    {
        limit = 0.001f * fOvs;
    }
    else if (baudrate < 1000000)
    {
        limit = 0.0001f * fOvs;
    }
    else if (baudrate < 8330000)
    {
        limit = 0.00001f * fOvs;
    }
    else
    {
        limit = 0.000001f * fOvs;
    }

    /* calculate the possible denominator "d" */
    d = (uint32)(fpd / fOvs);
    /* initialize "numerator" n with 1 */
    n = 1;

    if (d == 0)
    {
        while (d < 1)
        {
            /* decrement l_oversampling until "d" becomes >= 1; (l_oversampling + 1) should not be less than 4 */
            if (l_oversampling >= 5)
            {
                l_oversampling--;
                fOvs = baudrate * l_oversampling;
                d    = (uint32)(fpd / fOvs);
            }
            else
            {
                /* fall back to default values as desired baud rate cannot be achieved with the prescaler > 0 */
                prescaler      = 1;
                l_oversampling = (uint32)(IfxAsclin_OversamplingFactor_16 + 1);
                fpd            = (float32)IfxAsclin_getFaFrequency(asclin) / prescaler;
                fOvs           = baudrate * l_oversampling;
                d              = (uint32)(fpd / fOvs);
            }
        }
    }

    /* if d is possibly greater than 4095 or 0xFFF (12-bit resolution) */
    if (d >> 12)
    {
        /* check if the current baud rate fits in for the 12-bit  "d", for max. l_oversampling value. */
        if (((uint32)(fpd / (baudrate * 16))) >> 12)
        {
            /* increase the value of the prescaler to generate the required baudrate */
            while (d >> 12)
            {
                prescaler++;

                if (prescaler >> 12)
                {
                    prescaler = 0xFFF;
                    break;
                }

                fpd = (float32)IfxAsclin_getFaFrequency(asclin) / prescaler;
                d   = (uint32)(fpd / fOvs);
            }
        }
        else
        {
            /* increase the value of the oversampling to generate the required baudrate */
            while (d >> 12)
            {
                l_oversampling++;

                if (l_oversampling > 16)
                {
                    l_oversampling = (uint32)(IfxAsclin_OversamplingFactor_16 + 1);
                    break;
                }

                fOvs = baudrate * l_oversampling;
                d    = (uint32)(fpd / fOvs);
            }
        }
    }

    dBest          = d;
    nBest          = n;
    adder_facL_min = 0;
    f              = (fpd * n) / d;
    relError       = __absf(fOvs - f);

    if (relError <= limit)
    {
        terminated = TRUE;
    }

    for (n = 2; ((!terminated) && (n <= 0xFFF)); n++)
    {
        if (n == 2)
        {
            adder_facL = 1;
            adder_facH = 1;
        }
        else
        {
            adder_facL = (adder_facL_min * n) / nBest;
            adder_facH = adder_facL + 1;
        }

        for (count = adder_facL; ((count <= adder_facH) && (nBest <= dBest)); count++)
        {
            f           = (fpd * n) / (n * d + count); //why n in denominator?
            newRelError = __absf(fOvs - f);

            if (relError > newRelError)
            {
                relError = newRelError;
                nBest    = n;
                dBest    = (n * d + count);

                if (dBest > 4095)
                {
                    dBest = 4095;
                }

                adder_facL_min = count;
            }

            if (relError <= limit)
            {
                terminated = TRUE;
                break;
            }
        }
    }

    IfxAsclin_setClockSource(asclin, IfxAsclin_ClockSource_noClock);
    asclin->BRG.B.DENOMINATOR = dBest;
    asclin->BRG.B.NUMERATOR   = nBest;

    /* set the clock divider value */
    asclin->BITCON.B.PRESCALER = prescaler - 1;

    /* set the SHIFT frequency */
    asclin->BITCON.B.OVERSAMPLING = l_oversampling - 1;

    /* set the sampling point */
    asclin->BITCON.B.SAMPLEPOINT = samplepoint;

    /* set the median filter */
    asclin->BITCON.B.SM = medianFilter ? 1 : 0;

    IfxAsclin_setClockSource(asclin, source);

    return TRUE;
}


void IfxAsclin_setBitTimingValues(Ifx_ASCLIN *asclin, IfxAsclin_BitTimingConfig *config)
{
    IfxAsclin_ClockSource source = (IfxAsclin_ClockSource)IfxAsclin_getClockSource(asclin);

    IfxAsclin_setClockSource(asclin, IfxAsclin_ClockSource_noClock);
    asclin->BRG.B.DENOMINATOR = config->denominator;
    asclin->BRG.B.NUMERATOR   = config->numerator;

    /* set the SHIFT frequency */
    asclin->BITCON.B.OVERSAMPLING = (config->oversampling - 1);

    /* set the sampling point */
    asclin->BITCON.B.SAMPLEPOINT = config->samplepoint;

    /* set the median filter */
    asclin->BITCON.B.SM = (config->sm) ? 1 : 0;

    IfxAsclin_setClockSource(asclin, source);
}


void IfxAsclin_setClockSource(Ifx_ASCLIN *asclin, IfxAsclin_ClockSource clockSource)
{
	/* selects the given clock source */
    asclin->CSR.B.CLKSEL = clockSource;

    /* waits TW or polls for CSR.CON to change */
    if (clockSource == IfxAsclin_ClockSource_noClock)
    {
        while (IfxAsclin_getClockStatus(asclin) != 0U)
        {}
    }
    else
    {
        while (IfxAsclin_getClockStatus(asclin) != 1U)
        {}
    }
}


uint32 IfxAsclin_write16(Ifx_ASCLIN *asclin, uint16 *data, uint32 count)
{
    volatile Ifx_ASCLIN_TXDATA *txData = (volatile Ifx_ASCLIN_TXDATA *)&asclin->TXDATA[0].U;

    while ((count > 0))
    {
        txData->U = *data++;
        count--;
    }

    return count;
}


uint32 IfxAsclin_write32(Ifx_ASCLIN *asclin, uint32 *data, uint32 count)
{
    volatile Ifx_ASCLIN_TXDATA *txData = (volatile Ifx_ASCLIN_TXDATA *)&asclin->TXDATA[0].U;

    while ((count > 0))
    {
        txData->U = *data++;
        count--;
    }

    return count;
}


uint32 IfxAsclin_write8(Ifx_ASCLIN *asclin, uint8 *data, uint32 count)
{
    volatile Ifx_ASCLIN_TXDATA *txData = (volatile Ifx_ASCLIN_TXDATA *)&asclin->TXDATA[0].U;

    while ((count > 0))
    {
        txData->U = *data++;
        count--;
    }

    return count;
}


void IfxAsclin_initAp(Ifx_ASCLIN *asclin, IfxAsclin_ApConfig *config)
{
    IfxApProt_init((Ifx_PROT_PROT *)&asclin->PROTE, &config->proteConfig);
    IfxApProt_init((Ifx_PROT_PROT *)&asclin->PROTSE, &config->protseConfig);

    /* change the state to CONFIG, Configure APU and set PROT state back to RUN */
    /* initialize the APU */
    IfxApProt_setState((Ifx_PROT_PROT *)&asclin->PROTSE, IfxApProt_State_config);
    IfxApApu_init((Ifx_ACCEN_ACCEN *)&asclin->ACCEN, &config->apuConfig);
    IfxApProt_setState((Ifx_PROT_PROT *)&asclin->PROTSE, IfxApProt_State_run);
}


void IfxAsclin_initApConfig(IfxAsclin_ApConfig *config)
{
    IfxApProt_initConfig(&config->proteConfig);
    IfxApProt_initConfig(&config->protseConfig);
    IfxApApu_initConfig(&config->apuConfig);
}


void IfxAsclin_configureAccessToAsclins(IfxApApu_ApuConfig *apConfig)
{
    uint8 index;

    for (index = 0; index < IFXASCLIN_NUM_MODULES; index++)
    {
        Ifx_ASCLIN *asclin = (Ifx_ASCLIN *)(((uint32)&MODULE_ASCLIN0) + index * ((uint32)&MODULE_ASCLIN1 - (uint32)&MODULE_ASCLIN0));

        IfxApApu_init((Ifx_ACCEN_ACCEN *)&asclin->ACCEN, apConfig);
    }
}
