/**
 * \file IfxScrAdcomp.h
 * \brief SCRADCOMP  basic functionality
 * \ingroup IfxLld_Scr
 *
 * \version iLLD-TC4-v2.6.0
 * \copyright Copyright (c) 2026 Infineon Technologies AG. All rights reserved.
 *
 *
 *                                 IMPORTANT NOTICE
 *
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
 * \defgroup IfxLld_Scr_Adcomp ADCOMP
 * \ingroup IfxLld_Scr
 * \defgroup IfxLld_Scr_Adcomp_Enumerations Enum
 * \ingroup IfxLld_Scr_Adcomp
 * \defgroup IfxLld_Scr_Adcomp_Module Module Functionality
 * \ingroup IfxLld_Scr_Adcomp
 */

#ifndef IFXSCRADCOMP_H
#define IFXSCRADCOMP_H 1

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include "Ifx_Cfg.h"
#include "_Impl/IfxScrAdcomp_cfg.h"
#if defined(DEVICE_TC4DX)
#include "_Reg/TC4Dx/IfxScr_bf.h"
#include "_Reg/TC4Dx/IfxScr_reg.h"
#elif defined(DEVICE_TC49XN)
#include "_Reg/TC49xN/IfxScr_bf.h"
#include "_Reg/TC49xN/IfxScr_reg.h"
#elif defined(DEVICE_TC48X)
#include "_Reg/TC48x/IfxScr_bf.h"
#include "_Reg/TC48x/IfxScr_reg.h"
#elif defined(DEVICE_TC48XAA)
#include "_Reg/TC48xAA/IfxScr_bf.h"
#include "_Reg/TC48xAA/IfxScr_reg.h"
#elif defined(DEVICE_TC46X)
#include "_Reg/TC46x/IfxScr_bf.h"
#include "_Reg/TC46x/IfxScr_reg.h"
#elif defined(DEVICE_TC44X)
#include "_Reg/TC44x/IfxScr_bf.h"
#include "_Reg/TC44x/IfxScr_reg.h"
#elif defined(DEVICE_TC4ZX)
#include "_Reg/TC4Zx/IfxScr_bf.h"
#include "_Reg/TC4Zx/IfxScr_reg.h"
#elif defined(DEVICE_TC4EX)
#include "_Reg/TC4Ex/IfxScr_bf.h"
#include "_Reg/TC4Ex/IfxScr_reg.h"
#elif defined(DEVICE_TC4PX)
#include "_Reg/TC4Px/IfxScr_bf.h"
#include "_Reg/TC4Px/IfxScr_reg.h"
#endif /* #if defined(DEVICE_TC4DX) */

/******************************************************************************/
/*-------------------------------Enumerations---------------------------------*/
/******************************************************************************/
/** \addtogroup IfxLld_Scr_Adcomp_Enumerations
 * \{ */
/** \brief Input channel number
 */
typedef enum
{
    IfxScrAdcomp_Channel_0  = 0,  /**< \brief ADC Input Channel 0 */
    IfxScrAdcomp_Channel_1  = 1,  /**< \brief ADC Input Channel 1 */
    IfxScrAdcomp_Channel_2  = 2,  /**< \brief ADC Input Channel 2 */
    IfxScrAdcomp_Channel_3  = 3,  /**< \brief ADC Input Channel 3 */
    IfxScrAdcomp_Channel_4  = 4,  /**< \brief ADC Input Channel 4 */
    IfxScrAdcomp_Channel_5  = 5,  /**< \brief ADC Input Channel 5 */
    IfxScrAdcomp_Channel_6  = 6,  /**< \brief ADC Input Channel 6 */
    IfxScrAdcomp_Channel_7  = 7,  /**< \brief ADC Input Channel 7 */
    IfxScrAdcomp_Channel_8  = 8,  /**< \brief ADC Input Channel 8 */
    IfxScrAdcomp_Channel_9  = 9,  /**< \brief ADC Input Channel 9 */
    IfxScrAdcomp_Channel_10 = 10, /**< \brief ADC Input Channel 8 */
    IfxScrAdcomp_Channel_11 = 11, /**< \brief ADC Input Channel 8 */
    IfxScrAdcomp_Channel_12 = 12, /**< \brief ADC Input Channel 8 */
    IfxScrAdcomp_Channel_13 = 13, /**< \brief ADC Input Channel 8 */
    IfxScrAdcomp_Channel_14 = 14, /**< \brief ADC Input Channel 8 */
    IfxScrAdcomp_Channel_15 = 15  /**< \brief ADC Input Channel 8 */
} IfxScrAdcomp_Channel;

/** \brief Enumeration for sample time
 */
typedef enum
{
    IfxScrAdcomp_SampleTIme_60_80ns = 0,  /**< \brief Sample time (60ns-80ns) */
    IfxScrAdcomp_SampleTIme_100ns   = 1,  /**< \brief Sample time 100ns */
    IfxScrAdcomp_SampleTIme_200ns   = 2,  /**< \brief Sample time 200ns */
    IfxScrAdcomp_SampleTIme_400ns   = 3   /**< \brief Sample time 400ns */
} IfxScrAdcomp_SampleTIme;

/** \} */

/******************************************************************************/
/*-------------------------Inline Function Prototypes-------------------------*/
/******************************************************************************/
/** \addtogroup IfxLld_Scr_Adcomp_Module
 * \{ */
/** \brief Enable the ADC comparator.
 *   Note: 100Mhz clock source should be enabled before calling this function
 * \return None
 */
IFX_INLINE void IfxScrAdcomp_enableModule(void);

/** \brief Disable the ADC comparator.
 * \return None
 */
IFX_INLINE void IfxScrAdcomp_disableModule(void);

/** \brief Checks if the ADCOMP is enabled.
 */
IFX_INLINE boolean IfxScrAdcomp_isEnabled(void);

/** \brief Checks if the ADC is ready for a new conversion to be triggered
 *  \return TRUE --> ADC conversion is completed
 *          FALSE --> ADC conversion is ongoing
 */
IFX_INLINE boolean IfxScrAdcomp_isReadyForNewConversion(void);

/** \brief Selects the input channel for ADC
 * \param channel The input channel to be selected
 * \return None
 */
IFX_INLINE void IfxScrAdcomp_selectChannel(IfxScrAdcomp_Channel channel);

/** \brief Selects the sample time for ADC
 * \param time Sample time
 * \return None
 */
IFX_INLINE void IfxScrAdcomp_selectSampleTime(IfxScrAdcomp_SampleTIme time);

/** \brief Triggers a ADC conversion
 * \return None
 */
IFX_INLINE void IfxScrAdcomp_startConversion(void);

/** \brief Returns the converted result
 * \return The converted value
 */
IFX_INLINE uint16 IfxScrAdcomp_getResult(void);

/** \} */

/******************************************************************************/
/*---------------------Inline Function Implementations------------------------*/
/******************************************************************************/

IFX_INLINE void IfxScrAdcomp_enableModule(void)
{
    SCR_SYSCON0.U    = SCR_SYSCON0.U & (uint8)(0xFE);
    SCR_ADCOMP_CON.U = (SCR_ADCOMP_CON.U | (1u << IFX_SCR_ADCOMP_CON_EN_REQ_OFF));

    /* Wait for module to start */
    while (!(SCR_ADCOMP_RESHSTAT.B.EN_STAT))
    {}
}


IFX_INLINE void IfxScrAdcomp_disableModule(void)
{
    SCR_SYSCON0.U    = SCR_SYSCON0.U & (uint8)(0xFE);
    SCR_ADCOMP_CON.U = (SCR_ADCOMP_CON.U & ~IFX_SCR_ADCOMP_CON_EN_REQ_MSK);
}


IFX_INLINE boolean IfxScrAdcomp_isEnabled(void)
{
    SCR_SYSCON0.U = SCR_SYSCON0.U & (uint8)(0xFE);
    return (boolean)((SCR_ADCOMP_RESHSTAT.U & (1u << IFX_SCR_ADCOMP_RESHSTAT_EN_STAT_OFF)) >> IFX_SCR_ADCOMP_RESHSTAT_EN_STAT_OFF);
}


IFX_INLINE boolean IfxScrAdcomp_isReadyForNewConversion(void)
{
    SCR_SYSCON0.U = SCR_SYSCON0.U & (uint8)(0xFE);
    unsigned char status = 0;

    /*Check if both ADCEN and EOCSAMPLE is set*/
    if (SCR_ADCOMP_RESHSTAT.U & (1u << IFX_SCR_ADCOMP_RESHSTAT_EN_STAT_OFF))
    {
        status = ((SCR_ADCOMP_RESHSTAT.U & (1u << IFX_SCR_ADCOMP_RESHSTAT_EOC_OFF)) >> IFX_SCR_ADCOMP_RESHSTAT_EOC_OFF);
    }

    return status;
}

IFX_INLINE void IfxScrAdcomp_selectChannel(IfxScrAdcomp_Channel channel)
{
    SCR_SYSCON0.U    = SCR_SYSCON0.U & (uint8)(0xFE);
    SCR_ADCOMP_CON.U = ((SCR_ADCOMP_CON.U & ~(IFX_SCR_ADCOMP_CON_CHSEL_MSK << IFX_SCR_ADCOMP_CON_CHSEL_OFF)) | channel << IFX_SCR_ADCOMP_CON_CHSEL_OFF);
}


IFX_INLINE void IfxScrAdcomp_selectSampleTime(IfxScrAdcomp_SampleTIme time)
{
    SCR_SYSCON0.U    = SCR_SYSCON0.U & (uint8)(0xFE);
    SCR_ADCOMP_CON.U = ((SCR_ADCOMP_CON.U & ~(IFX_SCR_ADCOMP_CON_STSEL_MSK << IFX_SCR_ADCOMP_CON_STSEL_OFF)) | time << IFX_SCR_ADCOMP_CON_STSEL_OFF);
}


IFX_INLINE void IfxScrAdcomp_startConversion(void)
{
    SCR_SYSCON0.U     = SCR_SYSCON0.U & (uint8)(0xFE);
    SCR_ADCOMP_CON.U |= (1u << IFX_SCR_ADCOMP_CON_SOC_OFF);
}

IFX_INLINE uint16 IfxScrAdcomp_getResult(void)
{
    uint16 result;
    SCR_SYSCON0.U = SCR_SYSCON0.U & (uint8)(0xFE);
    result        = SCR_ADCOMP_RESL.U | ((SCR_ADCOMP_RESHSTAT.U & IFX_SCR_ADCOMP_RESHSTAT_RES10_8_MSK) << 8u);
    return result;
}


#endif /* IFXSCRADCOMP_H */
