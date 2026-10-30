/**
 * \file IfxSmuStdby.h
 * \brief SMU  basic functionality
 * \ingroup IfxLld_Smu
 *
 * \version iLLD_1_22_0
 * \copyright Copyright (c) 2026 Infineon Technologies AG. All rights reserved.
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
 * \defgroup IfxLld_Smu_Std_Stdby STDBY
 * \ingroup IfxLld_Smu_Std
 * \defgroup IfxLld_Smu_Std_Stdby_Enumerations Enumerations
 * \ingroup IfxLld_Smu_Std_Stdby
 * \defgroup IfxLld_Smu_Std_Stdby_StdByFunctions StdBy Functions
 * \ingroup IfxLld_Smu_Std_Stdby
 */

#ifndef IFXSMUSTDBY_H
#define IFXSMUSTDBY_H 1

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include "_Impl/IfxSmu_cfg.h"
#include "IfxSmu_reg.h"
#include "Scu/Std/IfxScuWdt.h"
#include "_Utilities/Ifx_Assert.h"
#include "IfxPms_reg.h"

/******************************************************************************/
/*--------------------------------Enumerations--------------------------------*/
/******************************************************************************/

/** \addtogroup IfxLld_Smu_Std_Stdby_Enumerations
 * \{ */
/** \brief This bit  (CMD_STDBY.B.ASCE) controls if a status flag set in an AGx register upon detection of the alarm event can be cleared by software or not. When ASCE is enabled, software shall write a 1 to bit position in AGx to clear the bit
 * (W1C). When a W1C action takes place the ASCE bit is automatically cleared to 0 by hardware and software shall set the ASCE bit again.
 * 0B SMU_stdby alarm status bits in AGi cannot be cleared.
 * 1B SMU_stdby alarm status bits in AGi can be cleared
 */
typedef enum
{
    IfxSmuStdby_AlarmStatusClear_disable = 0,  /**< \brief SMU_stdby alarm status bits in AGi cannot be cleared. */
    IfxSmuStdby_AlarmStatusClear_enable  = 1   /**< \brief SMU_stdby alarm status bits in AGi can be cleared */
} IfxSmuStdby_AlarmStatusClear;

/** \brief Status flag for alarm (AG2i_STDBY.B.SFz)
 * 0B Status flag  does not report a fault condition
 * 1B Status flag reports a fault condition
 */
typedef enum
{
    IfxSmuStdby_AlarmStatusFlag_noFaultExist = 0,  /**< \brief Status flag does not report a fault condition */
    IfxSmuStdby_AlarmStatusFlag_faultExist   = 1   /**< \brief Status flag reports a fault condition */
} IfxSmuStdby_AlarmStatusFlag;

/** \brief Fault signaling configuration flag (AG2iFSP_STDBY.B.FEz)
 */
typedef enum
{
    IfxSmuStdby_FaultSignalAlarmConfigFlagEvent_disable = 0,  /**< \brief FSP disabled for this alarm event */
    IfxSmuStdby_FaultSignalAlarmConfigFlagEvent_enable  = 1   /**< \brief FSP enabled for this alarm event. */
} IfxSmuStdby_FaultSignalAlarmConfigFlagEvent;

/** \brief Error Pin Fault State Status  (AG2i_STDBY.B.FSPERR)
 */
typedef enum
{
    IfxSmuStdby_FspErrorPinFaultState_noFault = 0,  /**< \brief Error pin was not set into fault state */
    IfxSmuStdby_FspErrorPinFaultState_fault   = 1   /**< \brief The Error pin was set into fault state */
} IfxSmuStdby_FspErrorPinFaultState;

/** \brief SMU_stdby Error pin function to be able set Pin to fault state. (CMD_STDBY.B.FSP0EN or CMD_STDBY.B.FSP1EN)
 */
typedef enum
{
    IfxSmuStdby_FspErrorPinState_inactive = 0,  /**< \brief SMU_stdby Error Pin fault indication function on pin inactive. */
    IfxSmuStdby_FspErrorPinState_active   = 1   /**< \brief SMU_stdby Error Pin fault indication function on pin inactive. */
} IfxSmuStdby_FspErrorPinState;

/** \brief SMU_stdby Module Enable(CMD_STDBY.B.SMUEN)
 */
typedef enum
{
    IfxSmuStdby_SmuStdbyModuleState_disable = 0,  /**< \brief SMU_stdby disabled. */
    IfxSmuStdby_SmuStdbyModuleState_enable  = 1   /**< \brief SMU_stdby enabled. */
} IfxSmuStdby_SmuStdbyModuleState;

/** \} */

/** \addtogroup IfxLld_Smu_Std_Stdby_StdByFunctions
 * \{ */

/******************************************************************************/
/*-------------------------Inline Function Prototypes-------------------------*/
/******************************************************************************/

/**
 * \brief Clears the TSTEN, TSTRUN, TSTDONE, TSTOK, SMUERR, and PMSERR flags.
 * This function resets the status flags related to the SMU standby monitoring and BIST operations.
 *
 * \retval None
 * 
 */
IFX_INLINE void IfxSmuStdby_clearSmuStdbyMonBistFlags(void);

/**
 * \brief Enables or disables the alarm status clear functionality in the SMU Standby command register.
 * This controls if a status flag set in an AGx register upon detection of the alarm event can be cleared by software or not.
 * When ASCE is enabled, software shall write a 1 to bit position in AGx to clear the bit (W1C). When a W1C action takes
 * place the ASCE bit is automatically cleared to 0 by hardware and software shall set the ASCE bit again.
 *
 * \retval None
 * 
 */
IFX_INLINE void IfxSmuStdby_enableAlarmStatusClear(void);

/**
 * \brief Enables or disables the SMU Standby module.
 * 
 * \param[in] SMU standby enable/disable Module. Range: \ref IfxSmuStdby_SmuStdbyModuleState.
 * 
 * \retval None
 * 
 */
IFX_INLINE void IfxSmuStdby_enableSmuStdby(IfxSmuStdby_SmuStdbyModuleState enable);

/**
 * \brief Enables the SMU standby mode Built-in Self Test (BIST).
 *
 * \retval None
 *
 */
IFX_INLINE void IfxSmuStdby_enableSmuStdbyMonBist(void);

/**
 * \brief Retrieves the status of a specific SMU standby alarm group.
 *
 * \param[in] alarmGroup The identifier of the SMU standby alarm group to query. Range: 20 or 21.
 *
 * \retval uint32 The current status of the specified SMU standby alarm group. Range: 0 to 0x4000 FFF0.
 *
 */
IFX_INLINE uint32 IfxSmuStdby_getSmuStdbyAlarmGroupStatus(uint8 alarmGroup);

/**
 * \brief Retrieves the status of a specific SMU standby alarm.
 *
 * \param[in] alarmGroup The SMU standby alarm group to query. Range: 20 or 21.
 * \param[in] alarmNum   The specific alarm number within the group. Range: 0 to 31.
 *
 * \retval uint32 The current status of the specified SMU standby alarm. Range: 0 to 0x4000 FFF0.
 *
 */
IFX_INLINE uint32 IfxSmuStdby_getSmuStdbyAlarmStatus(uint8 alarmGroup, uint8 alarmNum);

/**
 * \brief Retrieves the current status of the SMU standby module, indicating whether it is enabled or disabled.
 * 
 * \retval The current state of the SMU standby module. Range: \ref IfxSmuStdby_SmuStdbyModuleState.
 *
 */
IFX_INLINE IfxSmuStdby_SmuStdbyModuleState IfxSmuStdby_getSmuStdbyModuleStatus(void);

/**
 * \brief Retrieves the BIST PMS error flag status for the SMU standby monitoring.
 *
 * \retval TRUE If PMS error flag is set (error occurred).
 *         FALSE If PMS error flag is not set (no error).
 *
 */
IFX_INLINE boolean IfxSmuStdby_getSmuStdbyMonBistPmsErrorFlag(void);

/**
 * \brief This function retrieves the status of the Smu Stdby BIST SMUERR flag.
 * 
 * \retval  TRUE If the Smu Stdby BIST SMUERR flag is set, indicating an error condition.
 *          FALSE If the Smu Stdby BIST SMUERR flag is not set, indicating no error condition.
 *
 */
IFX_INLINE boolean IfxSmuStdby_getSmuStdbyMonBistSmuErrorFlag(void);

/**
 * \brief This function returns the status of the Smu Stdby BIST test done flag.
 *
 * \retval TRUE The BIST test has completed.
 *         FALSE The BIST test has not completed.
 * 
 */
IFX_INLINE boolean IfxSmuStdby_getSmuStdbyMonBistTestDoneFlag(void);

/**
 * \brief Returns the status of the Smu Stdby BIST TSTOK flag.
 *
 * \retval TRUE The BIST test has completed successfully.
 *         FALSE The BIST test has not completed successfully or an error occurred.
 * 
 */
IFX_INLINE boolean IfxSmuStdby_getSmuStdbyMonBistTestOkFlag(void);

/**
 * \brief This function returns the status of the Smu Stdby BIST test run flag.
 *
 * \retval TRUE The BIST test run flag is set.
 *         FALSE The BIST test run flag is not set.
 *
 */
IFX_INLINE boolean IfxSmuStdby_getSmuStdbyMonBistTestRunFlag(void);

/**
 * \brief Sets the FSP0 Error pin fault indication function to active or inactive.
 *
 * \param[in] active The state to which the FSP0 Error pin fault indication function is to be set.
 *                   Range: \ref IfxSmuStdby_FspErrorPinState.
 *
 * \retval None
 *
 */
IFX_INLINE void IfxSmuStdby_setFsp0ErrorPinActive(IfxSmuStdby_FspErrorPinState active);

/**
 * \brief Sets the FSP1 Error pin fault indication to either active or inactive.
 *
 * \param[in] active The state to which the FSP1 Error pin fault indication is to be set.
 *                   Range: \ref IfxSmuStdby_FspErrorPinState.
 *
 * \retval None
 *
 */
IFX_INLINE void IfxSmuStdby_setFsp1ErrorPinActive(IfxSmuStdby_FspErrorPinState active);

/******************************************************************************/
/*-------------------------Global Function Prototypes-------------------------*/
/******************************************************************************/

/**
 * \brief Sets the event flags for the fault signal configuration of a specific alarm group.
 *
 * \param[in] alarmGroup The identifier of the alarm group to configure. Range: 20 or 21.
 * \param[in] flags      The event flags to set for the specified alarm group. Range: 0 to 0xFFFF FFFF.
 *
 * \retval None
 *
 */
IFX_EXTERN void IfxSmuStdby_setFaultSignalAGConfigEventFlags(uint8 alarmGroup, uint32 flags);

/**
 * \brief Configures the Fault Signal Alarm configuration event flag for a specified alarm group and number.
 *
 * \param[in] alarmGroup The alarm group to configure. Range: 20 or 21.
 * \param[in] alarmNum   The alarm number within the group. Range: 0 to 31.
 * \param[in] enable     The flag to enable or disable the Fault Signal Alarm configuration event.
 *                       Range: \ref IfxSmuStdby_FaultSignalAlarmConfigFlagEvent.
 *
 * \retval None
 *
 */
IFX_EXTERN void IfxSmuStdby_setFaultSignalAlarmConfigEventFlag(uint8 alarmGroup, uint8 alarmNum, IfxSmuStdby_FaultSignalAlarmConfigFlagEvent enable);

/**
 * \brief Sets the status flag for a specific alarm in the SMU standby module.
 *
 * \param[in] alarmGroup The alarm group to configure. Range: 20 or 21.
 * \param[in] alarmNum   The alarm number within the alarm group. Range: 0 to 31.
 * \param[in] status     The status flag to set for the alarm. Range: \ref IfxSmuStdby_AlarmStatusFlag.
 *
 * \retval None
 *
 */
IFX_EXTERN void IfxSmuStdby_setSmuStdbyAlarmStatusFlag(uint8 alarmGroup, uint8 alarmNum, IfxSmuStdby_AlarmStatusFlag status);

/**
 * \brief Enables the SMU standby Built-in Self Test (BIST) to monitor and test the SMU functionality while in standby mode.
 *
 * \retval None
 *
 */
IFX_EXTERN void IfxSmuStdby_startSmuStdbyMonBist(void);

/** \} */

/******************************************************************************/
/*---------------------Inline Function Implementations------------------------*/
/******************************************************************************/

IFX_INLINE void IfxSmuStdby_clearSmuStdbyMonBistFlags(void)
{
    Ifx_PMS_MONBISTCTRL monBistCtrl;
    uint16              passwd = IfxScuWdt_getSafetyWatchdogPassword();

    /* Disable the write-protection for registers */
    IfxScuWdt_clearSafetyEndinit(passwd);

    monBistCtrl.U         = PMS_MONBISTCTRL.U;
    monBistCtrl.B.TSTCLR  = 1;
    monBistCtrl.B.BITPROT = 1;
    PMS_MONBISTCTRL.U     = monBistCtrl.U;

    /* Restore back the write-protection for registers */
    IfxScuWdt_setSafetyEndinit(passwd);
}


IFX_INLINE void IfxSmuStdby_enableAlarmStatusClear(void)
{
    Ifx_PMS_CMD_STDBY cmdStdby;
    uint16            passwd = IfxScuWdt_getSafetyWatchdogPassword();
    /* Disable the write-protection for registers */
    IfxScuWdt_clearSafetyEndinit(passwd);
    cmdStdby.U         = PMS_CMD_STDBY.U;
    cmdStdby.B.ASCE    = 1;
    cmdStdby.B.BITPROT = 1;
    PMS_CMD_STDBY.U    = cmdStdby.U;
    /* Restore back the write-protection for registers */
    IfxScuWdt_setSafetyEndinit(passwd);
}


IFX_INLINE void IfxSmuStdby_enableSmuStdby(IfxSmuStdby_SmuStdbyModuleState enable)
{
    Ifx_PMS_CMD_STDBY cmdStdby;
    uint16            passwd = IfxScuWdt_getSafetyWatchdogPassword();
    /* Disable the write-protection for registers */
    IfxScuWdt_clearSafetyEndinit(passwd);

    cmdStdby.U         = PMS_CMD_STDBY.U;
    cmdStdby.B.SMUEN   = enable;
    cmdStdby.B.BITPROT = 1;
    PMS_CMD_STDBY.U    = cmdStdby.U;

    /* Restore back the write-protection for registers */
    IfxScuWdt_setSafetyEndinit(passwd);
}


IFX_INLINE void IfxSmuStdby_enableSmuStdbyMonBist(void)
{
    Ifx_PMS_MONBISTCTRL monBistCtrl;
    uint16              passwd = IfxScuWdt_getSafetyWatchdogPassword();
    /* Disable the write-protection for registers */
    IfxScuWdt_clearSafetyEndinit(passwd);

    monBistCtrl.U         = PMS_MONBISTCTRL.U;
    monBistCtrl.B.TSTEN   = 1;
    monBistCtrl.B.BITPROT = 1;
    PMS_MONBISTCTRL.U     = monBistCtrl.U;

    /* Restore back the write-protection for registers */
    IfxScuWdt_setSafetyEndinit(passwd);
}


IFX_INLINE uint32 IfxSmuStdby_getSmuStdbyAlarmGroupStatus(uint8 alarmGroup)
{
    uint32 alarmGroupStatus = 0;

    if (alarmGroup == 20U)
    {
        alarmGroupStatus = PMS_AG_STDBY0.U & 0x0000FFFFU;
    }
    else if (alarmGroup == 21U)
    {
        alarmGroupStatus = PMS_AG_STDBY1.U;
    }
    else
    {
        IFX_ASSERT(IFX_VERBOSE_LEVEL_ERROR, FALSE);
    }

    return alarmGroupStatus;
}


IFX_INLINE uint32 IfxSmuStdby_getSmuStdbyAlarmStatus(uint8 alarmGroup, uint8 alarmNum)
{
    uint32 alarmStatus = 0;

    if (alarmGroup == 20U)
    {
        alarmStatus = (PMS_AG_STDBY0.U >> alarmNum) & 0x01U;
    }
    else if (alarmGroup == 21U)
    {
        alarmStatus = (PMS_AG_STDBY1.U >> alarmNum) & 0x01U;
    }
    else
    {
        IFX_ASSERT(IFX_VERBOSE_LEVEL_ERROR, FALSE);
    }

    return alarmStatus;
}


IFX_INLINE IfxSmuStdby_SmuStdbyModuleState IfxSmuStdby_getSmuStdbyModuleStatus(void)
{
    return (IfxSmuStdby_SmuStdbyModuleState)PMS_CMD_STDBY.B.SMUEN;
}


IFX_INLINE boolean IfxSmuStdby_getSmuStdbyMonBistPmsErrorFlag(void)
{
    return PMS_MONBISTSTAT.B.PMSERR;
}


IFX_INLINE boolean IfxSmuStdby_getSmuStdbyMonBistSmuErrorFlag(void)
{
    return PMS_MONBISTSTAT.B.SMUERR;
}


IFX_INLINE boolean IfxSmuStdby_getSmuStdbyMonBistTestDoneFlag(void)
{
    return PMS_MONBISTSTAT.B.TSTDONE;
}


IFX_INLINE boolean IfxSmuStdby_getSmuStdbyMonBistTestOkFlag(void)
{
    return PMS_MONBISTSTAT.B.TSTOK;
}


IFX_INLINE boolean IfxSmuStdby_getSmuStdbyMonBistTestRunFlag(void)
{
    return PMS_MONBISTSTAT.B.TSTRUN;
}


IFX_INLINE void IfxSmuStdby_setFsp0ErrorPinActive(IfxSmuStdby_FspErrorPinState active)
{
    Ifx_PMS_CMD_STDBY cmdStdby;
    uint16            passwd = IfxScuWdt_getSafetyWatchdogPassword();
    /* Disable the write-protection for registers */
    IfxScuWdt_clearSafetyEndinit(passwd);

    cmdStdby.U         = PMS_CMD_STDBY.U;
    cmdStdby.B.FSP0EN  = (boolean)active;
    cmdStdby.B.BITPROT = 1;
    PMS_CMD_STDBY.U    = cmdStdby.U;
    /* Restore back the write-protection for registers */
    IfxScuWdt_setSafetyEndinit(passwd);
}


IFX_INLINE void IfxSmuStdby_setFsp1ErrorPinActive(IfxSmuStdby_FspErrorPinState active)
{
    Ifx_PMS_CMD_STDBY cmdStdby;
    uint16            passwd = IfxScuWdt_getSafetyWatchdogPassword();
    /* Disable the write-protection for registers */
    IfxScuWdt_clearSafetyEndinit(passwd);

    cmdStdby.U         = PMS_CMD_STDBY.U;
    cmdStdby.B.FSP1EN  = (boolean)active;
    cmdStdby.B.BITPROT = 1;
    PMS_CMD_STDBY.U    = cmdStdby.U;
    /* Restore back the write-protection for registers */
    IfxScuWdt_setSafetyEndinit(passwd);
}


#endif /* IFXSMUSTDBY_H */
