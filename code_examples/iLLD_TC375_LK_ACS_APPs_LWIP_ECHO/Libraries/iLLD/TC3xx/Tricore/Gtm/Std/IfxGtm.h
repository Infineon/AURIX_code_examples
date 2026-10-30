/**
 * \file IfxGtm.h
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
 * \defgroup IfxLld_Gtm_Std_Basic_Functions Basic Functions
 * \ingroup IfxLld_Gtm_Std
 * \defgroup IfxLld_Gtm_Std_Enumerations Enumerations
 * \ingroup IfxLld_Gtm_Std
 */

#ifndef IFXGTM_H
#define IFXGTM_H 1

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include "_Impl/IfxGtm_cfg.h"

/******************************************************************************/
/*--------------------------------Enumerations--------------------------------*/
/******************************************************************************/

/** \addtogroup IfxLld_Gtm_Std_Enumerations
 * \{ */
/** \brief Enum for GTM interrupt modes.
 * Definition in Ifx_GTM_TOM_CH_IRQ_MODE.B.IRQ_MODE
 */
typedef enum
{
    IfxGtm_IrqMode_level       = 0,
    IfxGtm_IrqMode_pulse       = 1,
    IfxGtm_IrqMode_pulseNotify = 2,
    IfxGtm_IrqMode_singlePulse = 3
} IfxGtm_IrqMode;

/** \brief OCDS Suspend Control (OCDS.SUS)
 * Definition in Ifx_GTM_OCDS_OCS.B.SUS
 */
typedef enum
{
    IfxGtm_SuspendMode_none = 0,  /**< \brief No suspend */
    IfxGtm_SuspendMode_hard = 1,  /**< \brief Hard Suspend */
    IfxGtm_SuspendMode_soft = 2   /**< \brief Soft Suspend */
} IfxGtm_SuspendMode;

/** \} */

/** \addtogroup IfxLld_Gtm_Std_Basic_Functions
 * \{ */

/******************************************************************************/
/*-------------------------Inline Function Prototypes-------------------------*/
/******************************************************************************/

/**
 * \brief Returns the status of whether the GTM module is enabled or disabled.
 *
 * \param[in] gtm Pointer to the GTM module instance.
 *
 * \retval TRUE If the GTM module is enabled.
 * 		   FALSE If the GTM module is disabled.
 */
IFX_INLINE boolean IfxGtm_isEnabled(Ifx_GTM *gtm);

/**
 * \brief Checks if the GTM module is currently suspended.
 *
 * This function returns the current suspend state of the GTM module.
 *
 * \param[in] gtm Pointer to the GTM module instance.
 *
 * \retval TRUE Module is suspended.
 * 		   FALSE Module is not suspended.
 */
IFX_INLINE boolean IfxGtm_isModuleSuspended(Ifx_GTM *gtm);

/**
 * \brief Configures the GTM module to Hard/Soft suspend mode.
 * 
 * This function sets the suspend mode of the GTM module. The mode can be set to 
 * none, hard, or soft suspend. The function only works when the OCDS is enabled 
 * and the system is in Supervisor Mode. If OCDS is disabled, the suspend control 
 * will be ineffective.
 *
 * \param[inout] gtm  Pointer to the GTM module instance.
 * \param[in]    mode Suspend mode to be configured. 
 *					  Range: \ref IfxGtm_SuspendMode
 *
 * \retval None
 * 
 * \note The function will not work unless OCDS is enabled and the system is in 
 * Supervisor Mode. When OCDS is disabled, the OCS suspend control is ineffective.
 */
IFX_INLINE void IfxGtm_setSuspendMode(Ifx_GTM *gtm, IfxGtm_SuspendMode mode);

/******************************************************************************/
/*-------------------------Global Function Prototypes-------------------------*/
/******************************************************************************/

/**
 * \brief Disables the GTM module.
 *
 * \param[inout] gtm Pointer to the GTM module instance.
 *
 * \retval None
 */
IFX_EXTERN void IfxGtm_disable(Ifx_GTM *gtm);

/**
 * \brief Enables the GTM module
 *
 * \param[inout] gtm Pointer to the GTM module instance.
 * 
 * \retval None
 */
IFX_EXTERN void IfxGtm_enable(Ifx_GTM *gtm);

/** \} */

/******************************************************************************/
/*-------------------------Global Function Prototypes-------------------------*/
/******************************************************************************/

/**
 * \brief Retrieves the current frequency of the GTM system clock.
 *
 * This function returns the frequency of the GTM system clock (SYSCLK) in Hz.
 * The GTM system clock is a critical clock source for various timing operations
 * within the system.
 *
 * \retval float32 The current frequency of the GTM system clock in Hz.
 */
IFX_EXTERN float32 IfxGtm_getSysClkFrequency(void);

/**
 * \brief Returns the cluster frequency of the GTM cluster.
 * If the cluster is disabled, the function returns 0 as the frequency.
 *
 * \param[in] gtm Pointer to the GTM module instance.
 * \param[in] cluster Index of the cluster. Range: \ref IfxGtm_Cluster
 *
 * \retval float32 Cluster frequency in Hz, or 0 if the cluster is disabled.
 */
IFX_EXTERN float32 IfxGtm_getClusterFrequency(Ifx_GTM *gtm, IfxGtm_Cluster cluster);

/******************************************************************************/
/*---------------------Inline Function Implementations------------------------*/
/******************************************************************************/

IFX_INLINE boolean IfxGtm_isEnabled(Ifx_GTM *gtm)
{
    return gtm->CLC.B.DISS == 0;
}


IFX_INLINE boolean IfxGtm_isModuleSuspended(Ifx_GTM *gtm)
{
    Ifx_GTM_OCDS_OCS ocs;

    /* read the status */
    ocs.U = gtm->OCDS.OCS.U;

    /* return the status */
    return ocs.B.SUSSTA;
}


IFX_INLINE void IfxGtm_setSuspendMode(Ifx_GTM *gtm, IfxGtm_SuspendMode mode)
{
    Ifx_GTM_OCDS_OCS ocs;

    /* remove protection and configure the suspend mode. */
    ocs.B.SUS_P     = 1;
    ocs.B.SUS       = mode;

    gtm->OCDS.OCS.U = ocs.U;
}


#endif /* IFXGTM_H */
