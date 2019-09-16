/**
 * \file IfxGtm_Tbu.h
 * \brief GTM  basic functionality
 * \ingroup IfxLld_Gtm
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
/** \brief GTM TOM TBU Time stamps
 */
typedef enum
{
    IfxGtm_Tbu_Ts_0,
    IfxGtm_Tbu_Ts_1,
    IfxGtm_Tbu_Ts_2
} IfxGtm_Tbu_Ts;

/** \} */

/** \addtogroup IfxLld_Gtm_Std_Tbu_Basic_Functions
 * \{ */

/******************************************************************************/
/*-------------------------Inline Function Prototypes-------------------------*/
/******************************************************************************/

/** \brief Enables the channel
 * \param gtm Pointer to GTM module
 * \param channel TBU Time stamps
 * \return None
 */
IFX_INLINE void IfxGtm_Tbu_enableChannel(Ifx_GTM *gtm, IfxGtm_Tbu_Ts channel);

/** \brief Function to check if a TBU channel is enabled.
 * Returns TRUE if the corresponding channel is enabled
 * Returns FALSE if the corresponding channel is disabled.
 * \param gtm Pointer to GTM SFR
 * \param channel Channel of TBU
 * \return TRUE: channel is enabled
 */
IFX_INLINE boolean IfxGtm_Tbu_isChannelEnabled(Ifx_GTM *gtm, IfxGtm_Tbu_Ts channel);

/******************************************************************************/
/*-------------------------Global Function Prototypes-------------------------*/
/******************************************************************************/

/** \brief Returns the clock frequency
 * \param gtm Pointer to GTM module
 * \param channel TBU Time stamps
 * \return frequency
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


IFX_INLINE boolean IfxGtm_Tbu_isChannelEnabled(Ifx_GTM *gtm, IfxGtm_Tbu_Ts channel)
{
    uint32 shift         = channel * 2;
    uint32 enable_status = (gtm->TBU.CHEN.U & ((uint32)3 << shift)) >> shift;

    return enable_status == (uint32)IfxGtm_FeatureControl_enabled;
}


#endif /* IFXGTM_TBU_H */
