/**
 * \file IfxEgtm_Tim_Timer.h
 * \brief EGTM TIMER details
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
 * \defgroup IfxLld_Egtm_Tim_Timer Tim Timer Interface
 * \ingroup IfxLld_Egtm_Tim
 * \defgroup IfxLld_Egtm_Tim_Timer_Structures TIM Timer Structures
 * \ingroup IfxLld_Egtm_Tim_Timer
 * \defgroup IfxLld_Egtm_Tim_Timer_Functions TIM Timer Functions
 * \ingroup IfxLld_Egtm_Tim_Timer
 */

#ifndef IFXEGTM_TIM_TIMER_H
#define IFXEGTM_TIM_TIMER_H 1

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include "Egtm/Std/IfxEgtm_Tim.h"
#include "Egtm/Std/IfxEgtm_Cmu.h"
#include "_Impl/IfxEgtm_cfg.h"

/******************************************************************************/
/*-----------------------------Data Structures--------------------------------*/
/******************************************************************************/

/** \addtogroup IfxLld_Egtm_Tim_Timer_Structures
 * \{ */
/** \brief Tim handle data structure
 */
typedef struct
{
    Ifx_EGTM         *egtm;           /**< \brief Pointer to EGTM module */
    Ifx_EGTM_CLS_TIM *tim;            /**< \brief Pointer to TIM module */
    IfxEgtm_Cluster   clsIndex;       /**< \brief Specifies the CLS module no */
    IfxEgtm_Tim_Ch    channel;        /**< \brief Tim channel no */
} IfxEgtm_Tim_Timer;

/** \brief Tim configuration data structure
 */
typedef struct
{
    IfxEgtm_Cluster               clsIndex;                         /**< \brief Specifies the CLS instance number */
    IfxEgtm_Tim_Ch                channel;                          /**< \brief Tim channel no */
    IfxEgtm_Tim_ChannelControl    channelControl;                   /**< \brief Control configuration */
    uint32                        raisingEdgeFilterTime;            /**< \brief Filter Raising Edge parameter. Range: 0 to 0xFFFFFF */
    uint32                        fallingEdgeFilterTime;            /**< \brief Filter Falling Edge parameter. Range: 0 to 0xFFFFFF */
    uint32                        shadowCounter;                    /**< \brief Shadow counter value. Range: 0 to 0xFFFFFF */
    boolean                       irqEnable;                        /**< \brief enable interrupt notification */
    IfxEgtm_IrqMode               irqMode;                          /**< \brief interrupt mode (level/pulse/pulse notify/single pulse) */
    IfxEgtm_Tim_IrqType           irqType;                          /**< \brief interrupt type (new value/ ecnt overflow/ gpr overflow/ cnt overflow / TO detect / glitch detect) */
    IfxEgtm_Tim_InputSourceSelect inputSourceSelect;                /**< \brief input source selection (mode , Value) */
    boolean                       enableAuxInputSourceSelect;       /**< \brief enable Auxiliary input source selection */
} IfxEgtm_Tim_Timer_Config;

/** \} */

/** \addtogroup IfxLld_Egtm_Tim_Timer_Functions
 * \{ */

/******************************************************************************/
/*-------------------------Global Function Prototypes-------------------------*/
/******************************************************************************/

/** \brief initializes the TIM channel object
 *
 * \param[inout] driver TOM Timer interface Handle
 * \param[in]    config Configuration structure for TIM
 *
 * \retval None
 */
IFX_EXTERN void IfxEgtm_Tim_Timer_initChannel(IfxEgtm_Tim_Timer *driver, IfxEgtm_Tim_Timer_Config *config);

/** \brief initialize the config struct with default TIM channel configuration
 *
 * \param[inout] config Pointer to the TIM Channel configuration (it will be initialized by this function)
 * \param[in]    egtm   Pointer to EGTM module
 *
 * \retval None
 */
IFX_EXTERN void IfxEgtm_Tim_Timer_initChannelConfig(IfxEgtm_Tim_Timer_Config *config, Ifx_EGTM *egtm);

/** \} */

#endif /* IFXEGTM_TIM_TIMER_H */
