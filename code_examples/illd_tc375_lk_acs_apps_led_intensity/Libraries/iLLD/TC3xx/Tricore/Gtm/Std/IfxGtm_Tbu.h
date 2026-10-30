/**
 * \file IfxGtm_Tbu.h
 * \brief GTM  basic functionality
 * \ingroup IfxLld_Gtm
 *
 * \version iLLD_1_22_0
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

/******************************************************************************/
/*--------------------------------Enumerations--------------------------------*/
/******************************************************************************/

/** \addtogroup IfxLld_Gtm_Std_Tbu_Enumerations
 * \{ */
/** \brief GTM TOM TBU Time stamps.
 * Definition in Ifx_GTM_TOM_TGC_ACT_TB.B.TBU_SEL , Ifx_GTM_ATOM_AGC_ACT_TB.B.TBU_SEL
 */
typedef enum
{
    IfxGtm_Tbu_Ts_0,
    IfxGtm_Tbu_Ts_1,
    IfxGtm_Tbu_Ts_2,
    IfxGtm_Tbu_Ts_3
} IfxGtm_Tbu_Ts;

/** \brief GTM TOM TBU Clock Source.
 * Definition in Ifx_GTM_TBU_CH0_CTRL.B.CH_CLK_SRC, Ifx_GTM_TBU_CH1_CTRL.B.CH_CLK_SRC, Ifx_GTM_TBU_CH2_CTRL.B.CH_CLK_SRC
 */
typedef enum
{
	IfxGtm_Tbu_ClkSrc_0 = 0,  /**< \brief CMU_CLK0 selected */
	IfxGtm_Tbu_ClkSrc_1 = 1,  /**< \brief CMU_CLK1 selected */
	IfxGtm_Tbu_ClkSrc_2,      /**< \brief CMU_CLK2 selected */
	IfxGtm_Tbu_ClkSrc_3,      /**< \brief CMU_CLK3 selected */
	IfxGtm_Tbu_ClkSrc_4,      /**< \brief CMU_CLK4 selected */
	IfxGtm_Tbu_ClkSrc_5,      /**< \brief CMU_CLK5 selected */
	IfxGtm_Tbu_ClkSrc_6,      /**< \brief CMU_CLK6 selected */
	IfxGtm_Tbu_ClkSrc_7       /**< \brief CMU_CLK7 selected */
} IfxGtm_Tbu_ClkSrc;

/** \} */

/** \addtogroup IfxLld_Gtm_Std_Tbu_Basic_Functions
 * \{ */

/******************************************************************************/
/*-------------------------Inline Function Prototypes-------------------------*/
/******************************************************************************/

/**
 * \brief Enables the specified TBU channel.
 *
 * \param[inout] gtm 	 Pointer to the GTM module instance.
 * \param[in]    channel TBU Time stamps channel to enable. Range: \ref IfxGtm_Tbu_Ts
 *
 * \retval None
 */
IFX_INLINE void IfxGtm_Tbu_enableChannel(Ifx_GTM *gtm, IfxGtm_Tbu_Ts channel);

/**
 * \brief Disables the specified TBU channel.
 *
 * \param[inout] gtm 	 Pointer to the GTM module instance.
 * \param[in] 	 channel TBU Time stamps channel to disable. Range: \ref IfxGtm_Tbu_Ts
 *
 * \retval None
 */
IFX_INLINE void IfxGtm_Tbu_disableChannel(Ifx_GTM *gtm, IfxGtm_Tbu_Ts channel);

/**
 * \brief Checks if a specific TBU channel is enabled.
 *
 * \param[in] gtm 	  Pointer to the GTM module instance.
 * \param[in] channel The TBU channel to check. Range: \ref IfxGtm_Tbu_Ts
 *
 * \retval TRUE If the specified TBU channel is enabled.
 *         FALSE If the specified TBU channel is disabled.
 */
IFX_INLINE boolean IfxGtm_Tbu_isChannelEnabled(Ifx_GTM *gtm, IfxGtm_Tbu_Ts channel);

/**
 * \brief Sets the TBU Channel Mode for the specified channel.
 *
 * \param[inout] gtm 	  	       Pointer to the GTM module instance.
 * \param[in]    channel 	       TBU Time stamps channel to configure. Range: \ref IfxGtm_Tbu_Ts
 * \param[in]    enableChannelMode Boolean value to enable (TRUE) or disable (FALSE) the channel mode.
 *
 * \retval None
 */
IFX_INLINE void IfxGtm_Tbu_setChannelMode(Ifx_GTM *gtm, IfxGtm_Tbu_Ts channel, boolean enableChannelMode);

/**
 * \brief Sets the clock source for the specified TBU channel.
 *
 * \param[inout] gtm 	     Pointer to the GTM module instance.
 * \param[in]    channel     TBU Time stamps. Range: \ref IfxGtm_Tbu_Ts
 * \param[in]    clocksource Clock source for channel[x] time base counter. Range: \ref IfxGtm_Tbu_ClkSrc
 *
 * \retval None
 */
IFX_INLINE void IfxGtm_Tbu_setChannelClockSource(Ifx_GTM *gtm, IfxGtm_Tbu_Ts channel, IfxGtm_Tbu_ClkSrc clocksource);

/**
 * \brief Sets the TBU_CH0_BASE Register Resolution for Channel 0
 *
 * \param[inout] gtm 	    Pointer to the GTM module instance.
 * \param[in]    resolution TBU_CH0_BASE register resolution setting. Range 0 or 1.
 *
 * \retval None
 */
IFX_INLINE void IfxGtm_Tbu_setCh0BaseRegisterResolution(Ifx_GTM *gtm, boolean resolution);

#if IFXGTM_NUM_TBU_CHANNELS > 3
/**
 * \brief Sets the TBU Channel Selector for the modulo counter of Channel 3.
 *
 * \param[inout] gtm      Pointer to the GTM module instance.
 * \param[in]    selector Channel selector for the modulo counter (TRUE/FALSE).
 *
 * \retval None
 */
IFX_INLINE void IfxGtm_Tbu_setCh3ChannelSelector(Ifx_GTM *gtm, boolean selector);
#endif

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
IFX_INLINE void IfxGtm_Tbu_setChannelBase(Ifx_GTM *gtm, IfxGtm_Tbu_Ts channel, uint32 base);

#if IFXGTM_NUM_TBU_CHANNELS > 3
/**
 * \brief Sets the TBU Modulo value for channel 3
 *
 * \param[inout] gtm      Pointer to the GTM module instance.
 * \param[in]    baseMark The BASE_MARK value to be set [Range: 0 to 0xFFFFFF]
 *
 * \retval None
 */
IFX_INLINE void IfxGtm_Tbu_setChannel3BaseMark(Ifx_GTM *gtm, uint32 baseMark);
#endif

/******************************************************************************/
/*-------------------------Global Function Prototypes-------------------------*/
/******************************************************************************/

/**
 * \brief Retrieves the clock frequency for the specified TBU channel.
 *
 * \param[in] gtm     Pointer to the GTM module instance.
 * \param[in] channel TBU Time stamps. Range: \ref IfxGtm_Tbu_Ts
 *
 * \retval float32 Clock frequency in Hz.
 */
IFX_EXTERN float32 IfxGtm_Tbu_getClockFrequency(Ifx_GTM *gtm, IfxGtm_Tbu_Ts channel);

/** \} */

/******************************************************************************/
/*---------------------Inline Function Implementations------------------------*/
/******************************************************************************/

IFX_INLINE void IfxGtm_Tbu_enableChannel(Ifx_GTM *gtm, IfxGtm_Tbu_Ts channel)
{
    uint32 shift = channel * 2;

    __ldmst_c(&gtm->TBU.CHEN.U, (3U << shift), (IfxGtm_FeatureControl_enable << shift));
}

IFX_INLINE void IfxGtm_Tbu_disableChannel(Ifx_GTM *gtm, IfxGtm_Tbu_Ts channel)
{
	uint32 shift = channel * 2;
	__ldmst_c(&gtm->TBU.CHEN.U, (3U << shift), (IfxGtm_FeatureControl_disable << shift));
}

IFX_INLINE boolean IfxGtm_Tbu_isChannelEnabled(Ifx_GTM *gtm, IfxGtm_Tbu_Ts channel)
{
    uint32 shift         = channel * 2;
    uint32 enable_status = (gtm->TBU.CHEN.U & ((uint32)3 << shift)) >> shift;

    return enable_status == (uint32)IfxGtm_FeatureControl_enabled;
}

IFX_INLINE void IfxGtm_Tbu_setChannelMode(Ifx_GTM *gtm, IfxGtm_Tbu_Ts channel, boolean enableChannelMode)
{
	if(channel == IfxGtm_Tbu_Ts_1)
	{
		gtm->TBU.CH1_CTRL.B.CH_MODE = (enableChannelMode == TRUE)? 1 : 0;
	}
	else if(channel == IfxGtm_Tbu_Ts_2)
	{
		gtm->TBU.CH2_CTRL.B.CH_MODE = (enableChannelMode == TRUE) ? 1 : 0;
	}
#if IFXGTM_NUM_TBU_CHANNELS > 3
	else if(channel == IfxGtm_Tbu_Ts_3)
	{
		/**< \brief Does Nothing as Channel 3 CH_MODE bit-field is a read-only, hence can't be assigned. */
	}
#endif
	else
	{
		IFX_ASSERT(IFX_VERBOSE_LEVEL_ERROR, FALSE);     /**< \brief Wrong Selection of channel: Channel 0 does not support Channel Mode selection*/
	}
}

IFX_INLINE void IfxGtm_Tbu_setChannelClockSource(Ifx_GTM *gtm, IfxGtm_Tbu_Ts channel, IfxGtm_Tbu_ClkSrc clocksource)
{
	if(channel == IfxGtm_Tbu_Ts_0)
	{
		gtm->TBU.CH0_CTRL.B.CH_CLK_SRC = clocksource;
	}
	else if(channel == IfxGtm_Tbu_Ts_1)
	{
		gtm->TBU.CH1_CTRL.B.CH_CLK_SRC = clocksource;
	}
	else if(channel == IfxGtm_Tbu_Ts_2)
	{
		gtm->TBU.CH2_CTRL.B.CH_CLK_SRC = clocksource;
	}
	else
	{
		IFX_ASSERT(IFX_VERBOSE_LEVEL_ERROR, FALSE);     /**< \brief Wrong Selection of channel: Channel 3 does not support Clock Source selection*/
	}
}

IFX_INLINE void IfxGtm_Tbu_setCh0BaseRegisterResolution(Ifx_GTM *gtm, boolean resolution)
{
	gtm->TBU.CH0_CTRL.B.LOW_RES = (resolution == TRUE)? 1 : 0;
}

#if IFXGTM_NUM_TBU_CHANNELS > 3
IFX_INLINE void IfxGtm_Tbu_setCh3ChannelSelector(Ifx_GTM *gtm, boolean selector)
{
	gtm->TBU.CH3_CTRL.B.USE_CH2 = (selector == TRUE)? 1 : 0;   
}
#endif

IFX_INLINE void IfxGtm_Tbu_setChannelBase(Ifx_GTM *gtm, IfxGtm_Tbu_Ts channel, uint32 base) 
{
	if(channel == IfxGtm_Tbu_Ts_0)
	{
		gtm->TBU.CH0_BASE.B.BASE = (base & IFX_GTM_TBU_CH0_BASE_BASE_MSK);  /**< \brief Masking the time base register value with lower 27bit  */
	}
	else if(channel == IfxGtm_Tbu_Ts_1)
	{
		gtm->TBU.CH1_BASE.B.BASE = (base & IFX_GTM_TBU_CH1_BASE_BASE_MSK); /**< \brief Masking the time base register value with lower 24bit  */
	}
	else if(channel == IfxGtm_Tbu_Ts_2)
	{
		gtm->TBU.CH2_BASE.B.BASE = (base & IFX_GTM_TBU_CH2_BASE_BASE_MSK); /**< \brief Masking the time base register value with lower 24bit  */
	}
#if IFXGTM_NUM_TBU_CHANNELS > 3
	else if(channel == IfxGtm_Tbu_Ts_3)
	{
		gtm->TBU.CH3_BASE.B.BASE = (base & IFX_GTM_TBU_CH3_BASE_BASE_MSK); /**< \brief Masking the time base register value with lower 24bit  */
	}
#endif
	else
	{
		IFX_ASSERT(IFX_VERBOSE_LEVEL_ERROR, FALSE);                         /**< \brief Wrong Selection of channel */
	}
}

#if IFXGTM_NUM_TBU_CHANNELS > 3
IFX_INLINE void IfxGtm_Tbu_setChannel3BaseMark(Ifx_GTM *gtm, uint32 baseMark)
{
	gtm->TBU.CH3_BASE_MARK.B.BASE_MARK = (baseMark & IFX_GTM_TBU_CH3_BASE_MARK_BASE_MARK_MSK);  /**< \brief Masking the time base mark value with lower 24bit  */
}
#endif

#endif /* IFXGTM_TBU_H */
