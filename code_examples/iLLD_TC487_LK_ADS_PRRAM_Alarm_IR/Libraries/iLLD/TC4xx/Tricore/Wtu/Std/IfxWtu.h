/**
 * \file IfxWtu.h
 * \brief WTU  basic functionality
 * \ingroup IfxLld_Wtu
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
 *
 * This file contains the APIs for Watchdog timer uint and other Protection related functions.
 *
 * \defgroup IfxLld_Wtu_Std_Wtu_Configuration Watchdog Configuration functions
 * \ingroup IfxLld_Wtu_Std
 * \defgroup IfxLld_Wtu_Std_Wdt_Operative Watchdog Operative functions
 * \ingroup IfxLld_Wtu_Std
 */

#ifndef IFXWTU_H
#define IFXWTU_H 1

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include "_Impl/IfxWtu_cfg.h"
#include "Cpu/Std/IfxCpu_Intrinsics.h"
#include "IfxWtu_reg.h"
#include "IfxWtu_bf.h"
#include "IfxWtu.asm.h"
#include "Ap/Std/IfxApProt.h"
#include "Ap/Std/IfxApApu.h"

/******************************************************************************/
/*-----------------------------------Macros-----------------------------------*/
/******************************************************************************/

/** \brief Reset password of watchdog timer module.
 */
#define IFXWTU_RESET_PASSWORD (0x7CU)

/******************************************************************************/
/*-----------------------------Data Structures--------------------------------*/
/******************************************************************************/

/** \brief Configuration structure for Watchdog Timer Uint.
 * IfxWtu_Config is a type describing configuration structure of Safety WTU registers defined in IfxWtu.h file.
 */
typedef struct
{
    uint16      password;                            /**< \brief password for access to WTUxCTRLA reg */
    uint16      reload;                              /**< \brief WTU reload value */
    IfxWtu_IFSR inputFrequency;                      /**< \brief input frequency of the WTU */
    boolean     disableWatchdog;                     /**< \brief Disable Request Control Bit */
    boolean     enableSmuRestriction;                /**< \brief Unlock Restriction Request Control Bit */
    boolean     enableAutomaticPasswordChange;       /**< \brief Password Auto-sequence Request Bit */
    boolean     enableTimerCheck;                    /**< \brief Counter Check Request Bit */
    boolean     enableTimerCheckTolerance;           /**< \brief Timer Check Tolerance Request */
    uint8       TimerCheckToleranceValue;            /**< \brief Timer Check Tolerance Value */
    boolean     clrInternalResetFlag;                /**< \brief Clear Internal Reset Flag */
    uint16      TCVI;                                /**< \brief watchdog virtual timer guess value. */
} IfxWtu_Config;

/** \addtogroup IfxLld_Wtu_Std_Wtu_Configuration
 * \{ */

/******************************************************************************/
/*-------------------------Global Function Prototypes-------------------------*/
/******************************************************************************/

/** \brief WTU API to initialize WDT configuration structure - Constructor
 *   This API initialize the Wtu configuration structure to default values, these default
 *   values are for software specific, not necessarily hardware reset values.
 *   User must use this API call before IfxWtu_Init API call
 * \param config Wtu configuration structure to be initialized
 * \return None
 */
IFX_EXTERN void IfxWtu_initConfig(IfxWtu_Config *config);

/** \brief WTU API to Initialize the CTRLA register based on the config structure pointer initialisation.
 * \param wtu_ctrla Pointer to the watchdog config0 register.
 * \param config Pointer to the WTU configuration structure containing initialization parameters.
 * \return None
 */
IFX_EXTERN void IfxWtu_initConfig0Register(Ifx_WTU_CTRLA *wtu_ctrla, IfxWtu_Config *config);

/** \brief WTU API to Initialize the CTRLB register based on the config structure pointer initialisation.
 * \param wtu_ctrlb Pointer to the watchdog config1 register.
 * \param config Pointer to the WTU configuration structure containing initialization parameters.
 * \return None
 */
IFX_EXTERN void IfxWtu_initConfig1Register(Ifx_WTU_CTRLB *wtu_ctrlb, IfxWtu_Config *config);

/** \brief WTU API to Initialize the CPU watchdog with the specified configuration.
 *
 *   This API initialize the Wtu software driver and corresponding CPU WDT hardware module.
 *   User can configure project specific Watchdog password, Watchdog timer period and other settings
 *   with this interface.
 *   API corresponds to one instance of the hardware module.
 *   User must use this API call for each instance of the WDT hardware module used.
 * \param wtu Reference to register map of CPU WTU hardware instance.
 * \param config Wtu configuration structure for initialisation.
 * \return None
 */
IFX_EXTERN void IfxWtu_initCpuWatchdog(Ifx_WTU_WDTCPU *wtu, IfxWtu_Config *config);

/** \brief Initializes the security watchdog with the specified configuration.
 *
 *   This API initialize the Wtu software driver and corresponding security WDT hardware module.
 *   User can configure project specific Watchdog password, Watchdog timer period and other settings
 *   with this interface.
 *   API corresponds to one instance of the hardware module.
 *   User must use this API call for each instance of the WDT hardware module used.
 * \param wtu Pointer to the WTU instance to be initialized.
 * \param config WTU Config Structure for initialisation.
 * \return None
 */
IFX_EXTERN void IfxWtu_initSecurityWatchdog(Ifx_WTU_WDTSEC *wtu, IfxWtu_Config *config);

/** \brief Initializes the system watchdog with the specified configuration.
 *
 *   This API initialize the Wdt software driver and corresponding system WDT hardware module.
 *   User can configure project specific Watchdog password, Watchdog timer period and other settings
 *   with this interface.
 *   API corresponds to one instance of the hardware module.
 *   User must use this API call for each instance of the WDT hardware module used.
 * \param wtu Pointer to the WTU instance to be initialized.
 * \param config WTU Config Structure for initialisation.
 * \return None
 */
IFX_EXTERN void IfxWtu_initSystemWatchdog(Ifx_WTU_WDTSYS *wtu, IfxWtu_Config *config);

/** \} */

/** \addtogroup IfxLld_Wtu_Std_Wdt_Operative
 * \{ */

/******************************************************************************/
/*-------------------------Inline Function Prototypes-------------------------*/
/******************************************************************************/

/** \brief WTU Inline API to fetch current password of CPU Watchdog module.
 *
 * This API will fetch current Watchdog password for CPU WDT Hardware module. password is needed to be passed
 * with most of the WDT APIs. Normally this API can be used to store the password locally in the caller function
 * or store the password globally in a global variable at the application memory.
 * This API is only meant to be used with startup routines where function call is not possible.
 * \param watchdog Pointer to the watchdog configuration structure for various CPU Watchdog module.
 * \return password Existing (Application specific) password for CPU Watchdog module.
 */
IFX_INLINE uint16 IfxWtu_getCpuWatchdogPasswordInline(Ifx_WTU_WDTCPU *watchdog);

/** \brief Retrieves the current security watchdog password.
 *
 * This API will fetch current Watchdog password for Security WDT Hardware module. password is needed to be passed
 * with most of the WDT APIs. Normally this API can be used to store the password locally in the caller function
 * or store the password globally in a global variable at the application memory.
 * This API is only meant to be used with startup routines where function call is not possible.
 * \return password Existing (Application specific) password for the Security Watchdog module.
 */
IFX_INLINE uint16 IfxWtu_getSecurityWatchdogPasswordInline(void);

/** \brief Retrieves the current system watchdog password.
 *
 * This API will fetch current Watchdog password for System WDT Hardware module. password is needed to be passed
 * with most of the WDT APIs. Normally this API can be used to store the password locally in the caller function
 * or store the password globally in a global variable at the application memory.
 * This API is only meant to be used with startup routines where function call is not possible.
 * \return password Existing (Application specific) password for the System Watchdog module.
 */
IFX_INLINE uint16 IfxWtu_getSystemWatchdogPasswordInline(void);

/******************************************************************************/
/*-------------------------Global Function Prototypes-------------------------*/
/******************************************************************************/

/** \brief WTU API to Retrieve the current status of the CPU watchdog.
 * \return status
 */
IFX_EXTERN uint8 IfxWtu_getCpuWatchdogStatus(void);

/** \brief WTU API to Get the current status of the Security Watchdog Unit.
 * \return status
 */
IFX_EXTERN uint8 IfxWtu_getSecurityWatchdogStatus(void);

/** \brief WTU API to Retrieve the current status of the system watchdog.
 * \return status
 */
IFX_EXTERN uint8 IfxWtu_getSystemWatchdogStatus(void);

/** \brief WTU API to fetch the current CPU watchdog password.
 *
 * This API will fetch current Watchdog password for CPU WDT Hardware module. password is needed to be passed
 * with most of the WDT APIs. Normally this API can be used to store the password locally in the caller function
 * or store the password globally in a global variable at the application memory.
 * \return password Existing (Application specific) password for CPU Watchdog module.
 */
IFX_EXTERN uint16 IfxWtu_getCpuWatchdogPassword(void);

/** \brief WTU API to fetch the security watchdog password.
 * This API will fetch current Watchdog password for Security WDT Hardware module. password is needed to be passed
 * with most of the WDT APIs. Normally this API can be used to store the password locally in the caller function
 * or store the password globally in a global variable at the application memory.
 * \return password Existing (Application specific) password for the Security Watchdog module.
 */
IFX_EXTERN uint16 IfxWtu_getSecurityWatchdogPassword(void);

/** \brief WTU API to fetch the system watchdog password.
 *
 * This API will fetch current Watchdog password for System WDT Hardware module. password is needed to be passed
 * with most of the WDT APIs. Normally this API can be used to store the password locally in the caller function
 * or store the password globally in a global variable at the application memory.
 * \return password Existing (Application specific) password for the System Watchdog module.
 */
IFX_EXTERN uint16 IfxWtu_getSystemWatchdogPassword(void);

/** \brief WTU API to change CPU Watchdog password.
 *
 *   This API will change password to new one for the corresponding to CPU WDT Hardware module.
 *   User need to have the old password stored locally in the caller function.
 * \param password Existing (Application specific) password for the Watchdog module.
 * \param newPassword The new password to be set for the CPU watchdog.
 * \return None
 */
IFX_EXTERN void IfxWtu_changeCpuWatchdogPassword(uint16 password, uint16 newPassword);

/** \brief WTU API to change CPU Watchdog timer reload value.
 *
 * This API will change Watchdog timer reload value to new one for CPU WDT Hardware module.
 * The Watchdog timers will be reloaded with this value after every serice of Watchdog.
 * User need to have the password stored locally in the caller function.
 * \param password Existing (Application specific) password for the Watchdog module.
 * \param reload Reload value for the timer.
 * \return None
 */
IFX_EXTERN void IfxWtu_changeCpuWatchdogReload(uint16 password, uint16 reload);

/** \brief WTU API to change Security Watchdog password.
 *
 * This API will change password to new one for the corresponding to Security WDT Hardware module.
 * User need to have the old password stored locally in the caller function.
 * \param password Existing (Application specific) password for the Watchdog module.
 * \param newPassword The new password to be set.
 * \return None
 */
IFX_EXTERN void IfxWtu_changeSecurityWatchdogPassword(uint16 password, uint16 newPassword);

/** \brief WTU API to change Security Watchdog timer reload value.
 *
 * This API will change Watchdog timer reload value to new one for Security WDT Hardware module.
 * The Watchdog timers will be reloaded with this value after every serice of Watchdog.
 * User need to have the password stored locally in the caller function.
 * \param password Existing (Application specific) password for the Watchdog module.
 * \param reload Reload value for the timer.
 * \return None
 */
IFX_EXTERN void IfxWtu_changeSecurityWatchdogReload(uint16 password, uint16 reload);

/** \brief WTU API to change System Watchdog password.
 *
 * This API will change password to new one for the corresponding to System WDT Hardware module.
 * User need to have the old password stored locally in the caller function.
 * \param password Existing (Application specific) password for the Watchdog module.
 * \param newPassword Application specific new password to be changed for the Watchdog module.
 * \return None
 */
IFX_EXTERN void IfxWtu_changeSystemWatchdogPassword(uint16 password, uint16 newPassword);

/** \brief WTU API to change System Watchdog timer reload value.
 *
 * This API will change Watchdog timer reload value to new one for System WDT Hardware module.
 * The Watchdog timers will be reloaded with this value after every serice of Watchdog.
 * User need to have the password stored locally in the caller function.
 * \param password Existing (Application specific) password for the Watchdog module.
 * \param reload Reload value for the timer.
 * \return None
 */
IFX_EXTERN void IfxWtu_changeSystemWatchdogReload(uint16 password, uint16 reload);

/** \brief WTU API to disable CPU Watchdog functionality.
 *
 * This API will disable Watchdog functionality of CPU WDT Hardware module. The Watchdog timers will stop counting
 * after this API call.
 * User need to have the password stored locally in the caller function.
 * \param password Existing (Application specific) password for the Watchdog module.
 * \return None
 */
IFX_EXTERN void IfxWtu_disableCpuWatchdog(uint16 password);

/** \brief WTU API to disable the Security Watchdog functionality.
 *
 * This API will disable Watchdog functionality of Security WDT Hardware module. The Watchdog timers will stop counting
 * after this API call.
 * User need to have the password stored locally in the caller function.
 * \param password Existing (Application specific) password for the Watchdog module.
 * \return None
 */
IFX_EXTERN void IfxWtu_disableSecurityWatchdog(uint16 password);

/** \brief WTU API to disable System Watchdog functionality.
 *
 * This API will disable Watchdog functionality of System WDT Hardware module. The Watchdog timers will stop counting
 * after this API call.
 * User need to have the password stored locally in the caller function.
 * \param password Existing (Application specific) password for the Watchdog module.
 * \return None
 */
IFX_EXTERN void IfxWtu_disableSystemWatchdog(uint16 password);

/** \brief WTU API to enable CPU watchdog with the given password.
 *
 *   This API will enable Watchdog functionality of CPU WDT Hardware module. The Watchdog timers need to be serviced
 *   periodically after this API call.
 *   User need to have the password stored locally in the caller function.
 * \param password Existing (Application specific) password for the Watchdog module.
 * \return None
 */
IFX_EXTERN void IfxWtu_enableCpuWatchdog(uint16 password);

/** \brief WTU API to enable Security Watchdog functionality.
 *
 * This API will enable Watchdog functionality of Security WDT Hardware module. The Watchdog timers need to be serviced
 * periodically after this API call.
 * User need to have the password stored locally in the caller function.
 * \param password Existing (Application specific) password for the Watchdog module.
 * \return None
 */
IFX_EXTERN void IfxWtu_enableSecurityWatchdog(uint16 password);

/** \brief WTU API to enable the system watchdog with the given password.
 *
 * This API will enable Watchdog functionality of System WDT Hardware module. The Watchdog timers need to be serviced
 * periodically after this API call.
 * User need to have the password stored locally in the caller function.
 * \param password Existing (Application specific) password for the Watchdog module.
 * \return None
 */
IFX_EXTERN void IfxWtu_enableSystemWatchdog(uint16 password);

/** \brief WTU API to service Cpu Watchdog functionality.
 *
 * This API will service Watchdog functionality corresponding to Cpu WDT Hardware module.
 * User need to use this API call periodically. This API results in reloading of the Watchdog Timer.
 * User need to have the password stored locally in the caller function
 * \param password Existing (Application specific) password for the Watchdog module.
 * \return None
 */
IFX_EXTERN void IfxWtu_serviceCpuWatchdog(uint16 password);

/** \brief WTU API to service Security Watchdog functionality.
 *
 * This API will service Watchdog functionality corresponding to Security WDT Hardware module.
 * User need to use this API call periodically. This API results in reloading of the Watchdog Timer.
 * User need to have the password stored locally in the caller function.
 * \param password Existing (Application specific) password for the Watchdog module.
 * \return None
 */
IFX_EXTERN void IfxWtu_serviceSecurityWatchdog(uint16 password);

/** \brief WTU API to service System Watchdog functionality.
 *
 * This API will service Watchdog functionality corresponding to System WDT Hardware module.
 * User need to use this API call periodically. This API results in reloading of the Watchdog Timer.
 * User need to have the password stored locally in the caller function
 * \param password Existing (Application specific) password for the Watchdog module.
 * \return None
 */
IFX_EXTERN void IfxWtu_serviceSystemWatchdog(uint16 password);

/** \} */

/******************************************************************************/
/*---------------------Inline Function Implementations------------------------*/
/******************************************************************************/

IFX_INLINE uint16 IfxWtu_getCpuWatchdogPasswordInline(Ifx_WTU_WDTCPU *watchdog)
{
    uint16 password = 0;

    /* Read Password from CTRLA register
     * !!! NOTE: !!! when read bottom six bit of password are inverted so we have
     * to toggle them before returning password */
    password  = watchdog->CTRLA.B.PW;
    password ^= 0x007F;

    return password;
}


IFX_INLINE uint16 IfxWtu_getSecurityWatchdogPasswordInline(void)
{
    uint16          password = 0;
    Ifx_WTU_WDTSEC *watchdog = &MODULE_WTU.WDTSEC;

    /* Read Password from Safety WDT CTRLA register
     * !!! NOTE: !!! when read bottom six bit of password are inverted so we have
     * to toggle them before returning password */
    password  = watchdog->CTRLA.B.PW;
    password ^= 0x007F;

    return password;
}


IFX_INLINE uint16 IfxWtu_getSystemWatchdogPasswordInline(void)
{
    uint16          password = 0;
    Ifx_WTU_WDTSYS *watchdog = &MODULE_WTU.WDTSYS;

    /* Read Password from Safety WDT CTRLA register
     * !!! NOTE: !!! when read bottom six bit of password are inverted so we have
     * to toggle them before returning password */
    password  = watchdog->CTRLA.B.PW;
    password ^= 0x007F;

    return password;
}


#endif /* IFXWTU_H */
