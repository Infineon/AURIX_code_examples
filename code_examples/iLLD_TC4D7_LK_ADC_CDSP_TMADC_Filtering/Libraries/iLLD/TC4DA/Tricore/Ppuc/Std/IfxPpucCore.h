/**
 * \file IfxPpucCore.h
 * \brief PPUC  basic functionality
 * \ingroup IfxLld_Ppuc
 *
 * \version iLLD-TC4-v2.1.1
 * \copyright Copyright (c) 2024 Infineon Technologies AG. All rights reserved.
 *
 *
 *
 *                                 IMPORTANT NOTICE
 *
 * Use of this file is subject to the terms of use agreed between (i) you or
 * the company in which ordinary course of business you are acting and (ii)
 * Infineon Technologies AG or its licensees. If and as long as no such terms
 * of use are agreed, use of this file is subject to following:
 *
 * Boost Software License - Version 1.0 - August 17th, 2003
 *
 * Permission is hereby granted, free of charge, to any person or organization
 * obtaining a copy of the software and accompanying documentation covered by
 * this license (the "Software") to use, reproduce, display, distribute,
 * execute, and transmit the Software, and to prepare derivative works of the
 * Software, and to permit third-parties to whom the Software is furnished to
 * do so, all subject to the following:
 *
 * The copyright notices in the Software and this entire statement, including
 * the above license grant, this restriction and the following disclaimer, must
 * be included in all copies of the Software, in whole or in part, and all
 * derivative works of the Software, unless such copies or derivative works are
 * solely in the form of machine-executable object code generated by a source
 * language processor.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT
 * SHALL THE COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE
 * FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN CONTRACT, TORT OR OTHERWISE,
 * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 *
 *
 * Contains the implementation related to the EV Core
 *
 * \defgroup IfxLld_Ppuc_Std_Core Core Basic Functionality
 * \ingroup IfxLld_Ppuc_Std
 * \defgroup IfxLld_Ppuc_Std_Core_Core Core_Functions
 * \ingroup IfxLld_Ppuc_Std_Core
 * \defgroup IfxLld_Ppuc_Std_Core_Enums Core_Enums
 * \ingroup IfxLld_Ppuc_Std_Core
 * \defgroup IfxLld_Ppuc_Std_Core_structures Core_Structures
 * \ingroup IfxLld_Ppuc_Std_Core
 */

#ifndef IFXPPUCCORE_H
#define IFXPPUCCORE_H 1

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include "_Impl/IfxPpuc_cfg.h"
#include "Cpu/Std/IfxCpu_Intrinsics.h"
#include "IfxPpu_reg.h"
#include "Ap/Std/IfxApApu.h"

/******************************************************************************/
/*--------------------------------Enumerations--------------------------------*/
/******************************************************************************/

/** \addtogroup IfxLld_Ppuc_Std_Core_Enums
 * \{ */
/** \brief Desribes the core status
 */
typedef enum
{
    IfxPpucCore_Status_run   = 0,  /**< \brief The processor is in run state */
    IfxPpucCore_Status_sleep = 1,  /**< \brief The processor is in sleep state */
    IfxPpucCore_Status_halt  = 2   /**< \brief The processor is in halt state */
} IfxPpucCore_Status;

/** \} */

/******************************************************************************/
/*-----------------------------Data Structures--------------------------------*/
/******************************************************************************/

typedef struct
{
    uint8   vmId;        /**< \brief The virtual machine ID */
    boolean vmEn;        /**< \brief Virtual machine enable */
    uint8   prsId;       /**< \brief The protection set ID */
    boolean prsEn;       /**< \brief Protection set enable */
} IfxPpucCore_Ptag;

/** \addtogroup IfxLld_Ppuc_Std_Core_Core
 * \{ */

/******************************************************************************/
/*-------------------------Inline Function Prototypes-------------------------*/
/******************************************************************************/

/** \brief Remove the processor out of halt state to start/resume execution
 * \param ppuc PPUC module pointer
 * \return None
 */
IFX_INLINE void IfxPpucCore_startCore(Ifx_PPU *ppuc);

/** \brief Put the processor into halt state
 * \param ppuc PPUC module pointer
 * \return None
 */
IFX_INLINE void IfxPpucCore_haltCore(Ifx_PPU *ppuc);

/** \brief Returns the processor status
 * \param ppuc PPUC module pointer
 * \return The processor status
 */
IFX_INLINE IfxPpucCore_Status IfxPpucCore_getCoreStatus(Ifx_PPU *ppuc);

/** \brief Sets the interrupt vector base address
 * \param ppuc PPUC module pointer
 * \param intVectAddress Interrupt vector base address
 * \return None
 */
IFX_INLINE void IfxPpucCore_configureInterruptVectorBaseAddress(Ifx_PPU *ppuc, uint32 intVectAddress);

/** \brief Enable the PPUC module
 * \param ppuc PPUC module pointer
 * \return None
 */
IFX_INLINE void IfxPpucCore_enableModule(Ifx_PPU *ppuc);

/** \brief Disables the PPUC module
 * \param ppuc PPUC module pointer
 * \return None
 */
IFX_INLINE void IfxPpucCore_disableModule(Ifx_PPU *ppuc);

/** \brief Check if the module is enabled or not
 * \param ppuc PPUC module pointer
 * \return module enable status
 */
IFX_INLINE boolean IfxPpucCore_isModuleEnabled(Ifx_PPU *ppuc);

/** \brief Enable Interrupt handling for PPU as ISP
 * \param ppuc PPUC module pointer
 * \return None
 */
IFX_INLINE void IfxPpucCore_enableInterruptHandling(Ifx_PPU *ppuc);

/** \brief Disable Interrupt handling for PPU as ISP
 * \param ppuc PPUC module pointer
 * \return None
 */
IFX_INLINE void IfxPpucCore_disableInterruptHandling(Ifx_PPU *ppuc);

/** \brief Enable the CBU interface
 * \param ppuc PPUC module pointer
 * \return None
 */
IFX_INLINE void IfxPpucCore_enableCBUInterface(Ifx_PPU *ppuc);

/** \brief Disable the CBU interface
 * \param ppuc PPUC module pointer
 * \return None
 */
IFX_INLINE void IfxPpucCore_disableCBUInterface(Ifx_PPU *ppuc);

/** \brief Enable the STU interface
 * \param ppuc PPUC module pointer
 * \return None
 */
IFX_INLINE void IfxPpucCore_enableSTUInterface(Ifx_PPU *ppuc);

/** \brief Disable the STU interface
 * \param ppuc PPUC module pointer
 * \return None
 */
IFX_INLINE void IfxPpucCore_disableSTUInterface(Ifx_PPU *ppuc);

/** \brief Enable the LBU interface
 * \param ppuc PPUC module pointer
 * \return None
 */
IFX_INLINE void IfxPpucCore_enableLBUInterface(Ifx_PPU *ppuc);

/** \brief Disable the LBU interface
 * \param ppuc PPUC module pointer
 * \return None
 */
IFX_INLINE void IfxPpucCore_disableLBUInterface(Ifx_PPU *ppuc);

/** \brief Enable the CSMDMI interface
 * \param ppuc PPUC module pointer
 * \return None
 */
IFX_INLINE void IfxPpucCore_enableCSMDMIInterface(Ifx_PPU *ppuc);

/** \brief Disable the CSMDMI interface
 * \param ppuc PPUC module pointer
 * \return None
 */
IFX_INLINE void IfxPpucCore_disableCSMDMIInterface(Ifx_PPU *ppuc);

/** \brief Enable the STUDMI interface
 * \param ppuc PPUC module pointer
 * \return None
 */
IFX_INLINE void IfxPpucCore_enableSTUDMIInterface(Ifx_PPU *ppuc);

/** \brief Disable the STUDMI interface
 * \param ppuc PPUC module pointer
 * \return None
 */
IFX_INLINE void IfxPpucCore_disableSTUDMIInterface(Ifx_PPU *ppuc);

/** \brief Enable the VMDMI interface
 * \param ppuc PPUC module pointer
 * \return None
 */
IFX_INLINE void IfxPpucCore_enableVMDMIInterface(Ifx_PPU *ppuc);

/** \brief Disable the VMDMI interface
 * \param ppuc PPUC module pointer
 * \return None
 */
IFX_INLINE void IfxPpucCore_disableVMDMIInterface(Ifx_PPU *ppuc);

/** \brief API to define VM and PRS ID for PPU.CBU interface
 * \param ppuc PPUC module pointer
 * \param ptag ptag pointer
 * \return None
 */
IFX_INLINE void IfxPpucCore_setPtagCBU(Ifx_PPU *ppuc, IfxPpucCore_Ptag *ptag);

/** \brief API to define VM and PRS ID for PPU.LBU interface
 * \param ppuc PPUC module pointer
 * \param ptag ptag pointer
 * \return None
 */
IFX_INLINE void IfxPpucCore_setPtagLBU(Ifx_PPU *ppuc, IfxPpucCore_Ptag *ptag);

/** \brief API to define VM and PRS ID for PPU.STU interface
 * \param ppuc PPUC module pointer
 * \param ptag ptag pointer
 * \return None
 */
IFX_INLINE void IfxPpucCore_setPtagSTU(Ifx_PPU *ppuc, IfxPpucCore_Ptag *ptag);

/******************************************************************************/
/*-------------------------Global Function Prototypes-------------------------*/
/******************************************************************************/

/** \brief Configures the interrupt vector base address, enables the PPU to ICU interface and removes the processor from halt state
 * \param ppuc PPUC module pointer
 * \param intVectAddress interrupt vector base address
 * \return None
 */
IFX_EXTERN void IfxPpucCore_configureCoreAndRun(Ifx_PPU *ppuc, uint32 intVectAddress);

/** \brief Configures access to all masters to the PPU in the device
 * \param apConfig config pointer to configuration structure.
 * \return None
 */
IFX_EXTERN void IfxPpucCore_configureAccessToPpuc(IfxApApu_ApuConfig *apConfig);

/** \} */

/******************************************************************************/
/*-------------------------Inline Function Prototypes-------------------------*/
/******************************************************************************/

/** \brief API to trigger a SW reset and clear the status. Returns TRUE if successful, FALSE if not successful.
 * \param ppuc PPU module pointer
 * \return Return true
 */
IFX_INLINE boolean IfxPpucCore_triggerSwReset(Ifx_PPU *ppuc);

/** \brief API to request wake up from sleep
 * \param ppuc PPUC Module pointer
 * \return None
 */
IFX_INLINE void IfxPpucCore_requestWakeUp(Ifx_PPU *ppuc);

/******************************************************************************/
/*-------------------------Global Function Prototypes-------------------------*/
/******************************************************************************/

/** \brief Configures access to all masters to the PPU CSM in the device
 * \param apConfig config pointer to configuration structure.
 * \return None
 */
IFX_EXTERN void IfxPpucCore_configureAccessToPpucCsm(IfxApApu_ApuConfig *apConfig);

/******************************************************************************/
/*---------------------Inline Function Implementations------------------------*/
/******************************************************************************/

IFX_INLINE void IfxPpucCore_startCore(Ifx_PPU *ppuc)
{
    ppuc->CTRL.B.REQR = 1U;

    /* Wait till the status is changed to RUN */
    while (ppuc->STAT.B.RUN != 0U)
    {}
}


IFX_INLINE void IfxPpucCore_haltCore(Ifx_PPU *ppuc)
{
    ppuc->CTRL.B.REQH = 1U;

    /* Wait till the processor is put to halt */
    while (ppuc->STAT.B.RUN != 2U)
    {}
}


IFX_INLINE IfxPpucCore_Status IfxPpucCore_getCoreStatus(Ifx_PPU *ppuc)
{
    return (IfxPpucCore_Status)(ppuc->STAT.B.RUN);
}


IFX_INLINE void IfxPpucCore_configureInterruptVectorBaseAddress(Ifx_PPU *ppuc, uint32 intVectAddress)
{
    ppuc->VECBASE.U = intVectAddress;
}


IFX_INLINE void IfxPpucCore_enableModule(Ifx_PPU *ppuc)
{
    /* TODO ADD the PROT mechanism once details available */
    ppuc->CLC.B.DISR = 0U;
}


IFX_INLINE void IfxPpucCore_disableModule(Ifx_PPU *ppuc)
{
    /* TODO ADD the PROT mechanism once details available */
    ppuc->CLC.B.DISR = 1U;
}


IFX_INLINE boolean IfxPpucCore_isModuleEnabled(Ifx_PPU *ppuc)
{
    return (boolean)(ppuc->CLC.B.DISS == 0U);
}


IFX_INLINE void IfxPpucCore_enableInterruptHandling(Ifx_PPU *ppuc)
{
    ppuc->CTRL.B.ENIRQ = 1U;
}


IFX_INLINE void IfxPpucCore_disableInterruptHandling(Ifx_PPU *ppuc)
{
    ppuc->CTRL.B.ENIRQ = 0U;
}


IFX_INLINE void IfxPpucCore_enableCBUInterface(Ifx_PPU *ppuc)
{
    /* TODO ADD the PROT mechanism once details available */
    ppuc->CTRL.B.CBU = 1U;
}


IFX_INLINE void IfxPpucCore_disableCBUInterface(Ifx_PPU *ppuc)
{
    /* TODO ADD the PROT mechanism once details available */
    ppuc->CTRL.B.CBU = 0U;
}


IFX_INLINE void IfxPpucCore_enableSTUInterface(Ifx_PPU *ppuc)
{
    /* TODO ADD the PROT mechanism once details available */
    ppuc->CTRL.B.STU = 1U;
}


IFX_INLINE void IfxPpucCore_disableSTUInterface(Ifx_PPU *ppuc)
{
    /* TODO ADD the PROT mechanism once details available */
    ppuc->CTRL.B.STU = 0U;
}


IFX_INLINE void IfxPpucCore_enableLBUInterface(Ifx_PPU *ppuc)
{
    /* TODO ADD the PROT mechanism once details available */
    ppuc->CTRL.B.LBU = 1U;
}


IFX_INLINE void IfxPpucCore_disableLBUInterface(Ifx_PPU *ppuc)
{
    /* TODO ADD the PROT mechanism once details available */
    ppuc->CTRL.B.LBU = 0U;
}


IFX_INLINE void IfxPpucCore_enableCSMDMIInterface(Ifx_PPU *ppuc)
{
    /* TODO ADD the PROT mechanism once details available */
    ppuc->CTRL.B.CSMDMI = 1U;
}


IFX_INLINE void IfxPpucCore_disableCSMDMIInterface(Ifx_PPU *ppuc)
{
    /* TODO ADD the PROT mechanism once details available */
    ppuc->CTRL.B.CSMDMI = 0U;
}


IFX_INLINE void IfxPpucCore_enableSTUDMIInterface(Ifx_PPU *ppuc)
{
    /* TODO ADD the PROT mechanism once details available */
    ppuc->CTRL.B.STUDMI = 1U;
}


IFX_INLINE void IfxPpucCore_disableSTUDMIInterface(Ifx_PPU *ppuc)
{
    /* TODO ADD the PROT mechanism once details available */
    ppuc->CTRL.B.STUDMI = 0U;
}


IFX_INLINE boolean IfxPpucCore_triggerSwReset(Ifx_PPU *ppuc)
{
    boolean status = 0U;

    ppuc->RST.CTRLA.U = 0x1U;
    ppuc->RST.CTRLB.U = 0x1U;

    /* Wait until the reset status is updated */
    while (ppuc->RST.STAT.B.KRST != 2U)
    {}

    /* Clear the RST STATUS */
    ppuc->RST.CTRLB.B.STATCLR = 1U;

    if (ppuc->RST.STAT.B.KRST == 2U)
    {
        status = 1U;
    }

    return status;
}


IFX_INLINE void IfxPpucCore_requestWakeUp(Ifx_PPU *ppuc)
{
    ppuc->CTRL.B.REQWU = 1U;

    /* Wait till the processor starts execution */
    while (ppuc->STAT.B.RUN != 0U)
    {}
}


IFX_INLINE void IfxPpucCore_enableVMDMIInterface(Ifx_PPU *ppuc)
{
    /* TODO ADD the PROT mechanism once details available */
    ppuc->CTRL.B.VMDMI = 1U;
}


IFX_INLINE void IfxPpucCore_disableVMDMIInterface(Ifx_PPU *ppuc)
{
    /* TODO ADD the PROT mechanism once details available */
    ppuc->CTRL.B.VMDMI = 0U;
}


IFX_INLINE void IfxPpucCore_setPtagCBU(Ifx_PPU *ppuc, IfxPpucCore_Ptag *ptag)
{
    Ifx_PPU_PTAG_CBU cbu;

    cbu.U            = ppuc->PTAG.CBU.U;
    cbu.B.VM         = ptag->vmId;
    cbu.B.VMEN       = ptag->vmEn;
    cbu.B.PRSEN      = ptag->prsEn;
    cbu.B.PRS        = ptag->prsId;

    ppuc->PTAG.CBU.U = cbu.U;
}


IFX_INLINE void IfxPpucCore_setPtagLBU(Ifx_PPU *ppuc, IfxPpucCore_Ptag *ptag)
{
    Ifx_PPU_PTAG_LBU lbu;

    lbu.U            = ppuc->PTAG.LBU.U;
    lbu.B.VM         = ptag->vmId;
    lbu.B.VMEN       = ptag->vmEn;
    lbu.B.PRSEN      = ptag->prsEn;
    lbu.B.PRS        = ptag->prsId;

    ppuc->PTAG.LBU.U = lbu.U;
}


IFX_INLINE void IfxPpucCore_setPtagSTU(Ifx_PPU *ppuc, IfxPpucCore_Ptag *ptag)
{
    Ifx_PPU_PTAG_STU stu;
    stu.U            = ppuc->PTAG.STU.U;
    stu.B.VM         = ptag->vmId;
    stu.B.VMEN       = ptag->vmEn;
    stu.B.PRSEN      = ptag->prsEn;
    stu.B.PRS        = ptag->prsId;

    ppuc->PTAG.STU.U = stu.U;
}


#endif /* IFXPPUCCORE_H */
