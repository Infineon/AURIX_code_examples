/**
 * \file IfxGtm.h
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
/** \brief Enum for GTM interrupt modes
 */
typedef enum
{
    IfxGtm_IrqMode_level       = 0,
    IfxGtm_IrqMode_pulse       = 1,
    IfxGtm_IrqMode_pulseNotify = 2,
    IfxGtm_IrqMode_singlePulse = 3
} IfxGtm_IrqMode;

/** \brief OCDS Suspend Control (OCDS.SUS)
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

/** \brief Returs the status of module enabled or disabled
 * \param gtm Pointer to GTM module
 * \return status: TRUE/FALSE
 */
IFX_INLINE boolean IfxGtm_isEnabled(Ifx_GTM *gtm);

/** \brief Returns the module's suspend state.
 * TRUE :if module is suspended.
 * FALSE:if module is not yet suspended.
 * \param gtm Pointer to GTM module registers
 * \return Suspend status (TRUE / FALSE)
 */
IFX_INLINE boolean IfxGtm_isModuleSuspended(Ifx_GTM *gtm);

/** \brief Configure the Module to Hard/Soft suspend mode.
 * Note: The api works only when the OCDS is enabled and in Supervisor Mode. When OCDS is disabled the OCS suspend control is ineffective.
 * \param gtm Pointer to GTM module registers
 * \param mode Module suspend mode
 * \return None
 */
IFX_INLINE void IfxGtm_setSuspendMode(Ifx_GTM *gtm, IfxGtm_SuspendMode mode);

/******************************************************************************/
/*-------------------------Global Function Prototypes-------------------------*/
/******************************************************************************/

/** \brief Disables the module
 * \param gtm Pointer to GTM module
 * \return None
 */
IFX_EXTERN void IfxGtm_disable(Ifx_GTM *gtm);

/** \brief Enables the module
 * \param gtm Pointer to GTM module
 * \return None
 */
IFX_EXTERN void IfxGtm_enable(Ifx_GTM *gtm);

/** \} */

/******************************************************************************/
/*-------------------------Global Function Prototypes-------------------------*/
/******************************************************************************/

/** \brief returns the GTM SYSCLK frequency.
 * Refer to the Clock distribution for details on GTM SYS CLK.
 * \return sysFreq
 */
IFX_EXTERN float32 IfxGtm_getSysClkFrequency(void);

/******************************************************************************/
/*---------------------Inline Function Implementations------------------------*/
/******************************************************************************/

IFX_INLINE boolean IfxGtm_isEnabled(Ifx_GTM *gtm)
{
    return gtm->CLC.B.DISS == 0;
}


IFX_INLINE boolean IfxGtm_isModuleSuspended(Ifx_GTM *gtm)
{
    Ifx_GTM_OCS ocs;

    // read the status
    ocs.U = gtm->OCS.U;

    // return the status
    return ocs.B.SUSSTA;
}


IFX_INLINE void IfxGtm_setSuspendMode(Ifx_GTM *gtm, IfxGtm_SuspendMode mode)
{
    Ifx_GTM_OCS ocs;

    // remove protection and configure the suspend mode.
    ocs.B.SUS_P = 1;
    ocs.B.SUS   = mode;

    gtm->OCS.U  = ocs.U;
}


#endif /* IFXGTM_H */
