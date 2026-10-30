/**
 * \file IfxEgtm_Tbu.h
 * \brief EGTM  basic functionality
 * \ingroup IfxLld_Egtm
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
 * \defgroup IfxLld_Egtm_Std_Tbu Tbu Basic Functionality
 * \ingroup IfxLld_Egtm_Std
 * \defgroup IfxLld_Egtm_Std_Tbu_Enumerations TBU Enumerations
 * \ingroup IfxLld_Egtm_Std_Tbu
 * \defgroup IfxLld_Egtm_Std_Tbu_Basic_Functions TBU Basic Functions
 * \ingroup IfxLld_Egtm_Std_Tbu
 */

#ifndef IFXEGTM_TBU_H
#define IFXEGTM_TBU_H 1

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include "_Impl/IfxEgtm_cfg.h"
#include "IfxEgtm_Cmu.h"

/******************************************************************************/
/*--------------------------------Enumerations--------------------------------*/
/******************************************************************************/

/** \addtogroup IfxLld_Egtm_Std_Tbu_Enumerations
 * \{ */
/** \brief EGTM TOM TBU Time stamps
 */
typedef enum
{
    IfxEgtm_Tbu_Ts_0,
    IfxEgtm_Tbu_Ts_1,
    IfxEgtm_Tbu_Ts_2,
    IfxEgtm_Tbu_Ts_3
} IfxEgtm_Tbu_Ts;

/** \} */

/** \addtogroup IfxLld_Egtm_Std_Tbu_Basic_Functions
 * \{ */

/******************************************************************************/
/*-------------------------Inline Function Prototypes-------------------------*/
/******************************************************************************/

/** \brief Enables the channel
 *
 * \param[inout] egtm    Pointer to EGTM module
 * \param[in]    cluster Cluster index
 *                       Range: \ref: IfxEgtm_Cluster
 * \param[in]    channel TBU Time stamps
 *                       Range: \ref: IfxEgtm_Tbu_Ts
 *
 * \retval None
 */
IFX_INLINE void IfxEgtm_Tbu_enableChannel(Ifx_EGTM *egtm, IfxEgtm_Cluster cluster, IfxEgtm_Tbu_Ts channel);

/** \brief Disables the specified TBU channel.
 *
 * \param[inout] egtm    Pointer to EGTM module
 * \param[in]    cluster Cluster index
 *                       Range: \ref: IfxEgtm_Cluster
 * \param[in]    channel TBU Time stamps
 *                       Range: \ref: IfxEgtm_Tbu_Ts
 *
 * \retval None
 */
IFX_INLINE void IfxEgtm_Tbu_disableChannel(Ifx_EGTM *egtm, IfxEgtm_Cluster cluster, IfxEgtm_Tbu_Ts channel);

/** \brief Returns the clock frequency
 *
 * \param[in] egtm    Pointer to EGTM module
 * \param[in] cluster Cluster index
 *                    Range: \ref: IfxEgtm_Cluster
 * \param[in] channel TBU Time stamps
 *                    Range: \ref: IfxEgtm_Tbu_Ts
 *
 * \retval frequency
 */
IFX_INLINE float32 IfxEgtm_Tbu_getClockFrequency(Ifx_EGTM *egtm, IfxEgtm_Cluster cluster, IfxEgtm_Tbu_Ts channel);

/** \brief Function to check if a TBU channel is enabled.
 * Returns TRUE if the corresponding channel is enabled
 * Returns FALSE if the corresponding channel is disabled.
 *
 * \param[in] egtm    Pointer to EGTM SFR
 * \param[in] cluster Cluster index
 *                    Range: \ref: IfxEgtm_Cluster
 * \param[in] channel Channel of TBU
 *                    Range: \ref: IfxEgtm_Tbu_Ts
 *
 * \retval TRUE: channel is enabled
 */
IFX_INLINE boolean IfxEgtm_Tbu_isChannelEnabled(Ifx_EGTM *egtm, IfxEgtm_Cluster cluster, IfxEgtm_Tbu_Ts channel);

/**
 * \brief Configures the TBU time base value for the specified channel.
 *
 * \param[inout] gtm	 Pointer to the EGTM module instance.
 * \param[in]	 channel TBU Time stamps. Range: \ref IfxEgtm_Tbu_Ts
 * \param[in]	 base 	 Time base value to be set.
 *                		 Range: - For Channel0 : 0 to 0x7FFFFFF
 *                        	 	- For Channel 1,2 : 0 to 0xFFFFFF
 *
 * \retval None
 */
IFX_INLINE void IfxEgtm_Tbu_setChannelBase(Ifx_EGTM *gtm, IfxEgtm_Cluster cluster, IfxEgtm_Tbu_Ts channel, uint32 base);

/** \} */

/******************************************************************************/
/*---------------------Inline Function Implementations------------------------*/
/******************************************************************************/

IFX_INLINE void IfxEgtm_Tbu_enableChannel(Ifx_EGTM *egtm, IfxEgtm_Cluster cluster, IfxEgtm_Tbu_Ts channel)
{
    uint32 shift = (uint32)channel << 1u;

    Ifx__ldmst(&egtm->CLS[cluster].TBU.CHEN.U, (uint32)((uint32)3u << shift), ((uint32)IfxEgtm_FeatureControl_enable << shift));
}


IFX_INLINE void IfxEgtm_Tbu_disableChannel(Ifx_EGTM *egtm, IfxEgtm_Cluster cluster, IfxEgtm_Tbu_Ts channel)
{
    uint32 shift = (uint32)channel << 1u;

    Ifx__ldmst(&egtm->CLS[cluster].TBU.CHEN.U, (uint32)((uint32)3u << shift), ((uint32)IfxEgtm_FeatureControl_disable << shift));
}


IFX_INLINE float32 IfxEgtm_Tbu_getClockFrequency(Ifx_EGTM *egtm, IfxEgtm_Cluster cluster, IfxEgtm_Tbu_Ts channel)
{
    float32 result = 0.0F;

    if (channel == IfxEgtm_Tbu_Ts_0)
    {
        result = IfxEgtm_Cmu_getClkFrequency(egtm, (IfxEgtm_Cmu_Clk)egtm->CLS[cluster].TBU.CH0_CTRL.B.CH_CLK_SRC, TRUE);
    }
    else if (channel == IfxEgtm_Tbu_Ts_1)
    {
        result = IfxEgtm_Cmu_getClkFrequency(egtm, (IfxEgtm_Cmu_Clk)egtm->CLS[cluster].TBU.CH1_CTRL.B.CH_CLK_SRC, TRUE);
    }
    else if (channel == IfxEgtm_Tbu_Ts_2)
    {
        result = IfxEgtm_Cmu_getClkFrequency(egtm, (IfxEgtm_Cmu_Clk)egtm->CLS[cluster].TBU.CH2_CTRL.B.CH_CLK_SRC, TRUE);
    }
    else
    {}

    return result;
}


IFX_INLINE boolean IfxEgtm_Tbu_isChannelEnabled(Ifx_EGTM *egtm, IfxEgtm_Cluster cluster, IfxEgtm_Tbu_Ts channel)
{
    uint32  shift         = (uint32)channel << 1u;
    uint32  enable_status = (egtm->CLS[cluster].TBU.CHEN.U & ((uint32)3u << shift)) >> shift;
    boolean enabled;

    enabled = (enable_status == (uint32)IfxEgtm_FeatureControl_enabled) ? TRUE : FALSE;
    return enabled;
}


IFX_INLINE void IfxEgtm_Tbu_setChannelBase(Ifx_EGTM *egtm, IfxEgtm_Cluster cluster, IfxEgtm_Tbu_Ts channel, uint32 base)
{
    if(channel == IfxEgtm_Tbu_Ts_0)
    {
        egtm->CLS[cluster].TBU.CH0_BASE.B.BASE = (base & IFX_EGTM_CLS_TBU_CH0_BASE_BASE_MSK);  /**< \brief Masking the time base register value with lower 27bit  */
    }
    else if(channel == IfxEgtm_Tbu_Ts_1)
    {
        egtm->CLS[cluster].TBU.CH1.BASE.B.BASE = (base & IFX_EGTM_CLS_TBU_CH_BASE_BASE_MSK);  /**< \brief Masking the time base register value with lower 24bit  */
    }
    else if(channel == IfxEgtm_Tbu_Ts_2)
    {
        egtm->CLS[cluster].TBU.CH2.BASE.B.BASE = (base & IFX_EGTM_CLS_TBU_CH_BASE_BASE_MSK);  /**< \brief Masking the time base register value with lower 24bit  */
    }
    else
    {
        IFX_ASSERT(IFX_VERBOSE_LEVEL_ERROR, FALSE);                         /**< \brief Wrong Selection of channel */
    }
}


#endif /* IFXEGTM_TBU_H */
