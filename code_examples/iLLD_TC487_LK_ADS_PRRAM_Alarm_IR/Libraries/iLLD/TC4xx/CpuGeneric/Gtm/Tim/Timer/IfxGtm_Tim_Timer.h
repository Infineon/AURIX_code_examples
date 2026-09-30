/**
 * \file IfxGtm_Tim_Timer.h
 * \brief GTM TIMER details
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
 * \defgroup IfxLld_Gtm_Tim_Timer TIM Timer Interface
 * \ingroup IfxLld_Gtm_Tim
 */

#ifndef IFXGTM_TIM_TIMER_H
#define IFXGTM_TIM_TIMER_H 1

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include "_Impl/IfxGtm_cfg.h"
#include "Gtm/Std/IfxGtm_Tim.h"
#include "Gtm/Std/IfxGtm_Cmu.h"

/******************************************************************************/
/*-----------------------------Data Structures--------------------------------*/
/******************************************************************************/

/** \brief Tim handle data structure
 */
typedef struct
{
    Ifx_GTM         *gtm;            /**< \brief Pointer to GTM module */
    Ifx_GTM_CLS_TIM *tim;            /**< \brief Pointer to TIM module */
    IfxGtm_Cluster   clsIndex;       /**< \brief Specifies the CLS module no */
    IfxGtm_Tim_Ch    channel;        /**< \brief Tim channel no */
} IfxGtm_Tim_Timer;

/** \brief Tim configuration data structure
 */
typedef struct
{
    IfxGtm_Cluster               clsIndex;                         /**< \brief Specifies the CLS instance number */
    IfxGtm_Tim_Ch                channel;                          /**< \brief Tim channel no */
    IfxGtm_Tim_ChannelControl    channelControl;                   /**< \brief Control configuration */
    uint32                       raisingEdgeFilterTime;            /**< \brief Filter Raising Edge parameter. Range: 0 to 0xFFFFFF */
    uint32                       fallingEdgeFilterTime;            /**< \brief Filter Falling Edge parameter. Range: 0 to 0xFFFFFF */
    uint32                       shadowCounter;                    /**< \brief Shadow counter value. Range: 0 to 0xFFFFFF */
    boolean                      irqEnable;                        /**< \brief enable interrupt notification */
    IfxGtm_IrqMode               irqMode;                          /**< \brief interrupt mode (level/pulse/pulse notify/single pulse) */
    IfxGtm_Tim_IrqType           irqType;                          /**< \brief interrupt type (new value/ ecnt overflow/ gpr overflow/ cnt overflow / TO detect / glitch detect) */
    IfxGtm_Tim_InputSourceSelect inputSourceSelect;                /**< \brief input source selection (mode , Value) */
    boolean                      enableAuxInputSourceSelect;       /**< \brief enable auxiliary input source selection */
} IfxGtm_Tim_Timer_Config;

/******************************************************************************/
/*-------------------------Global Function Prototypes-------------------------*/
/******************************************************************************/

/** \brief Initializes the TIM channel object.
 *
 * \param[inout] driver TOM Timer interface Handle.
 * \param[in]    config Configuration structure for TIM.
 * \retval None
 */
IFX_EXTERN void IfxGtm_Tim_Timer_initChannel(IfxGtm_Tim_Timer *driver, IfxGtm_Tim_Timer_Config *config);

/** \brief Initializes the config struct with default TIM channel configuration.
 *
 * \param[inout] config pointer to the TIM Channel configuration (it will be initialized by this function).
 * \param[in]    gtm    Pointer to GTM module.
 *
 * \retval None
 */
IFX_EXTERN void IfxGtm_Tim_Timer_initChannelConfig(IfxGtm_Tim_Timer_Config *config, Ifx_GTM *gtm);
#endif /* IFXGTM_TIM_TIMER_H */
