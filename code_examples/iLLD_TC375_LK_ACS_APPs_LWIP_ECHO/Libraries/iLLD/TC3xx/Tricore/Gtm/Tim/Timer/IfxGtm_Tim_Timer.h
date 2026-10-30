/**
 * \file IfxGtm_Tim_Timer.h
 * \brief GTM TIMER details
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
 * \defgroup IfxLld_Gtm_Tim_Timer TIM Timer Interface
 * \ingroup IfxLld_Gtm_Tim
 */

#ifndef IFXGTM_TIM_TIMER_H
#define IFXGTM_TIM_TIMER_H 1

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include "Gtm/Std/IfxGtm_Tim.h"
#include "Gtm/Std/IfxGtm_Cmu.h"
#include "_Impl/IfxGtm_cfg.h"

/******************************************************************************/
/*-----------------------------Data Structures--------------------------------*/
/******************************************************************************/

/** \brief Tim handle data structure
 */
typedef struct
{
    Ifx_GTM      *gtm;            /**< \brief Pointer to GTM module */
    Ifx_GTM_TIM  *tim;            /**< \brief Pointer to TIM module */
    IfxGtm_Tim    timIndex;       /**< \brief Specifies the  TIM module no */
    IfxGtm_Tim_Ch channel;        /**< \brief Tim channel no */
} IfxGtm_Tim_Timer;

/** \brief Tim configuration data structure
 */
typedef struct
{
    IfxGtm_Tim                   timIndex;                         /**< \brief Specifies the TIM instance number */
    IfxGtm_Tim_Ch                channel;                          /**< \brief Tim channel no */
    IfxGtm_Tim_ChannelControl    channelControl;                   /**< \brief Control configuration */
    uint32                       raisingEdgeFilterTime;            /**< \brief Filter Raising Edge parameter. Range: 0 to 0xFFFFFF */
    uint32                       fallingEdgeFilterTime;            /**< \brief Filter Falling Edge parameter. Range: 0 to 0xFFFFFF */
    uint32                       shadowCounter;                    /**< \brief Shadow counter value. Range: 0 to 0xFFFFFF */
    boolean                      irqEnable;                        /**< \brief enable interrupt notification */
    IfxGtm_IrqMode               irqMode;                          /**< \brief interrupt mode (level/pulse/pulse notify/single pulse) */
    IfxGtm_Tim_IrqType           irqType;                          /**< \brief interrupt type (new value/ ecnt overflow/ gpr overflow/ cnt overflow / TO detect / glitch detect) */
    IfxGtm_Tim_InputSourceSelect inputSourceSelect;                /**< \brief input source selection (mode , Value) */
    boolean                      enableAuxInputSourceSelect;       /**< \brief enable aurilliary input source selection */
} IfxGtm_Tim_Timer_Config;

/******************************************************************************/
/*-------------------------Global Function Prototypes-------------------------*/
/******************************************************************************/

/**
 * \brief Initializes the specified TIM channel object with the provided configuration.
 *
 * This function configures the TIM channel according to the settings provided in the
 * configuration structure. It initializes the channel for operation based on the
 * specified parameters such as channel control, filter times, shadow counter, and
 * interrupt settings.
 *
 * \param[inout] driver Pointer to the TIM Timer interface handle. 
 * \param[in]    config Pointer to the configuration structure for the TIM channel. This
 *                 		structure includes settings such as channel control, filter times,
 *                 		shadow counter, interrupt enablement, and input source selection.
 *
 * \retval None
 */
IFX_EXTERN void IfxGtm_Tim_Timer_initChannel(IfxGtm_Tim_Timer *driver, IfxGtm_Tim_Timer_Config *config);

/**
 * \brief Initializes the TIM channel configuration structure with default values.
 *
 * This function sets up the provided TIM channel configuration structure with default
 * settings for a specified GTM module. The configuration includes channel-specific
 * parameters such as edge filtering times, shadow counter, interrupt settings, and
 * input source selections.
 *
 * \param[inout] config Pointer to the TIM channel configuration structure to be initialized.
 * \param[in]    gtm    Pointer to the GTM module instance to be used for configuration.
 *
 * \retval None
 */
IFX_EXTERN void IfxGtm_Tim_Timer_initChannelConfig(IfxGtm_Tim_Timer_Config *config, Ifx_GTM *gtm);
#endif /* IFXGTM_TIM_TIMER_H */
