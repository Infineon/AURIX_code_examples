/**
 * \file IfxGtm_Tbu.h
 * \brief GTM  basic functionality
 * \ingroup IfxLld_Gtm
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
 * \defgroup IfxLld_Gtm_Std_Tbu Tbu Basic Functionality
 * \ingroup IfxLld_Gtm_Std
 * \defgroup IfxLld_Gtm_Std_Tbu_Enumerations TBU Enumerations
 * \ingroup IfxLld_Gtm_Std_Tbu
 * \defgroup IfxLld_Gtm_Std_Tbu_Basic_Functions TBU Basic Functions
 * \ingroup IfxLld_Gtm_Std_Tbu
 */

#ifndef IFXGTM_TBU_H
#define IFXGTM_TBU_H 1

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include "_Impl/IfxGtm_cfg.h"
#include "IfxGtm_Cmu.h"

/******************************************************************************/
/*--------------------------------Enumerations--------------------------------*/
/******************************************************************************/

/** \addtogroup IfxLld_Gtm_Std_Tbu_Enumerations
 * \{ */
/** \brief GTM TOM TBU Time stamps
 */
typedef enum
{
    IfxGtm_Tbu_Ts_0,
    IfxGtm_Tbu_Ts_1,
    IfxGtm_Tbu_Ts_2,
    IfxGtm_Tbu_Ts_3
} IfxGtm_Tbu_Ts;

/** \} */

/** \addtogroup IfxLld_Gtm_Std_Tbu_Basic_Functions
 * \{ */

/******************************************************************************/
/*-------------------------Inline Function Prototypes-------------------------*/
/******************************************************************************/

/** \brief Enables the channel.
 *
 * \param[in] gtm     Pointer to GTM module.
 * \param[in] cluster Cluster index. Range: \ref IfxGtm_Cluster.
 * \param[in] channel TBU Time stamps. Range: \ref IfxGtm_Tbu_Ts.
 *
 * \retval None
 */
IFX_INLINE void IfxGtm_Tbu_enableChannel(Ifx_GTM *gtm, IfxGtm_Cluster cluster, IfxGtm_Tbu_Ts channel);

/** \brief Disables the channel.
 *
 * \param[in] gtm     Pointer to GTM module.
 * \param[in] cluster Cluster index. Range: \ref IfxGtm_Cluster.
 * \param[in] channel TBU Time stamps. Range: \ref IfxGtm_Tbu_Ts.
 *
 * \retval None
 */
IFX_INLINE void IfxGtm_Tbu_disableChannel(Ifx_GTM *gtm, IfxGtm_Cluster cluster, IfxGtm_Tbu_Ts channel);

/** \brief Returns the clock frequency.
 *
 * \param[in] gtm     Pointer to GTM module.
 * \param[in] cluster Cluster index. Range: \ref IfxGtm_Cluster.
 * \param[in] channel TBU Time stamps. Range: \ref IfxGtm_Tbu_Ts.
 *
 * \retval float32 frequency.
 */
IFX_INLINE float32 IfxGtm_Tbu_getClockFrequency(Ifx_GTM *gtm, IfxGtm_Cluster cluster, IfxGtm_Tbu_Ts channel);

/** \brief Function to check if a TBU channel is enabled.

 * \param[in] gtm     Pointer to GTM SFR
 * \param[in] cluster Cluster index. Range: \ref IfxGtm_Cluster.
 * \param[in] channel Channel of TBU. Range: \ref IfxGtm_Tbu_Ts.
 *
 * \retval TRUE if the corresponding channel is enabled.
 *         FALSE if the corresponding channel is disabled.
 */
IFX_INLINE boolean IfxGtm_Tbu_isChannelEnabled(Ifx_GTM *gtm, IfxGtm_Cluster cluster, IfxGtm_Tbu_Ts channel);

/**
 * \brief Configures the TBU time base value for the specified channel.
 *
 * \param[inout] gtm	 Pointer to the GTM module instance.
 * \param[in]	 channel TBU Time stamps. Range: \ref IfxGtm_Tbu_Ts
 * \param[in]	 base 	 Time base value to be set.
 *                		 Range: - For Channel0 : 0 to 0x7FFFFFF
 *                        	 	- For Channel 1,2,3 : 0 to 0xFFFFFF
 *
 * \retval None
 */
IFX_INLINE void IfxGtm_Tbu_setChannelBase(Ifx_GTM *gtm, IfxGtm_Cluster cluster, IfxGtm_Tbu_Ts channel, uint32 base);


/** \} */

/******************************************************************************/
/*---------------------Inline Function Implementations------------------------*/
/******************************************************************************/

IFX_INLINE void IfxGtm_Tbu_enableChannel(Ifx_GTM *gtm, IfxGtm_Cluster cluster, IfxGtm_Tbu_Ts channel)
{
    uint32 shift = (uint32)channel << 1u;

    Ifx__ldmst(&gtm->CLS[cluster].TBU.CHEN.U, (uint32)((uint32)3u << shift), ((uint32)IfxGtm_FeatureControl_enable << shift));
}


IFX_INLINE void IfxGtm_Tbu_disableChannel(Ifx_GTM *gtm, IfxGtm_Cluster cluster, IfxGtm_Tbu_Ts channel)
{
    uint32 shift = (uint32)channel << 1u;

    Ifx__ldmst(&gtm->CLS[cluster].TBU.CHEN.U, (uint32)((uint32)3u << shift), ((uint32)IfxGtm_FeatureControl_disable << shift));
}


IFX_INLINE float32 IfxGtm_Tbu_getClockFrequency(Ifx_GTM *gtm, IfxGtm_Cluster cluster, IfxGtm_Tbu_Ts channel)
{
    float32 result = 0.0F;

    if (channel == IfxGtm_Tbu_Ts_0)
    {
        result = IfxGtm_Cmu_getClkFrequency(gtm, (IfxGtm_Cmu_Clk)gtm->CLS[cluster].TBU.CH0_CTRL.B.CH_CLK_SRC, TRUE);
    }
    else if (channel == IfxGtm_Tbu_Ts_1)
    {
        result = IfxGtm_Cmu_getClkFrequency(gtm, (IfxGtm_Cmu_Clk)gtm->CLS[cluster].TBU.CH1_CTRL.B.CH_CLK_SRC, TRUE);
    }
    else if (channel == IfxGtm_Tbu_Ts_2)
    {
        result = IfxGtm_Cmu_getClkFrequency(gtm, (IfxGtm_Cmu_Clk)gtm->CLS[cluster].TBU.CH2_CTRL.B.CH_CLK_SRC, TRUE);
    }
    else
    {}

    return result;
}


IFX_INLINE boolean IfxGtm_Tbu_isChannelEnabled(Ifx_GTM *gtm, IfxGtm_Cluster cluster, IfxGtm_Tbu_Ts channel)
{
    uint32  shift         = (uint32)channel << 1u;
    uint32  enable_status = (gtm->CLS[cluster].TBU.CHEN.U & ((uint32)3u << shift)) >> shift;
    boolean enabled;

    enabled = (enable_status == (uint32)IfxGtm_FeatureControl_enabled) ? TRUE : FALSE;
    return enabled;
}


IFX_INLINE void IfxGtm_Tbu_setChannelBase(Ifx_GTM *gtm, IfxGtm_Cluster cluster, IfxGtm_Tbu_Ts channel, uint32 base)
{
	if(channel == IfxGtm_Tbu_Ts_0)
	{
		gtm->CLS[cluster].TBU.CH0_BASE.B.BASE = (base & IFX_GTM_CLS_TBU_CH0_BASE_BASE_MSK);  /**< \brief Masking the time base register value with lower 27bit  */
	}
	else if(channel == IfxGtm_Tbu_Ts_1)
	{
		gtm->CLS[cluster].TBU.CH1.BASE.B.BASE = (base & IFX_GTM_CLS_TBU_CH_BASE_BASE_MSK);  /**< \brief Masking the time base register value with lower 24bit  */
	}
	else if(channel == IfxGtm_Tbu_Ts_2)
	{
		gtm->CLS[cluster].TBU.CH2.BASE.B.BASE = (base & IFX_GTM_CLS_TBU_CH_BASE_BASE_MSK);  /**< \brief Masking the time base register value with lower 24bit  */
	}
	else if(channel == IfxGtm_Tbu_Ts_3)
	{
		gtm->CLS[cluster].TBU.CH3_BASE.B.BASE = (base & IFX_GTM_CLS_TBU_CH3_BASE_BASE_MSK);  /**< \brief Masking the time base register value with lower 24bit  */
	}
	else
	{
		IFX_ASSERT(IFX_VERBOSE_LEVEL_ERROR, FALSE);                         /**< \brief Wrong Selection of channel */
	}
}

#endif /* IFXGTM_TBU_H */
