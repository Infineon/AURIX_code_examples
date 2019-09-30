/**
 * \file IfxFft.h
 * \brief FFT  basic functionality
 * \ingroup IfxLld_Fft
 *
 * \version iLLD_1_0_1_9_0
 * \copyright Copyright (c) 2017 Infineon Technologies AG. All rights reserved.
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
 * \defgroup IfxLld_Fft_Std_Enumerations Enumerations
 * \ingroup IfxLld_Fft_Std
 * \defgroup IfxLld_Fft_Std_UtilityFunctions Utility Functions
 * \ingroup IfxLld_Fft_Std
 */

#ifndef IFXFFT_H
#define IFXFFT_H 1

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include "_Impl/IfxFft_cfg.h"
#include "Cpu/Std/IfxCpu_Intrinsics.h"
#include "Src/Std/IfxSrc.h"
#include "IfxFft_reg.h"
#include "IfxLmu_reg.h"
#include "Scu/Std/IfxScuWdt.h"

/******************************************************************************/
/*--------------------------------Enumerations--------------------------------*/
/******************************************************************************/

/** \addtogroup IfxLld_Fft_Std_Enumerations
 * \{ */
/** \brief Input format
 * Definition in Ifx_FFT.CSR.B.IN.FMT
 */
typedef enum
{
    IfxFft_Input_complexSInt32 = 0,  /**< \brief 1 complex 32-bit data per 64-bit word */
    IfxFft_Input_realSInt32    = 1,  /**< \brief 2 real 32-bit data per 64-bit word */
    IfxFft_Input_complexSInt16 = 2,  /**< \brief 2 complex 16-bit data per 64-bit word */
    IfxFft_Input_realSInt16    = 3   /**< \brief 4 real 16-bit data per 64-bit word */
} IfxFft_Input;

/** \brief Length of transform. Log base 2 of the required transform size.
 * Length must be between 3 (transform of 8) and 11 (transform of 2048).
 * Definition in Ifx_FFT.CSR.B.LENGTH
 */
typedef enum
{
    IfxFft_Length_8    = 3,  /**< \brief transform of 8 */
    IfxFft_Length_16   = 4,  /**< \brief transform of 16 */
    IfxFft_Length_32   = 5,  /**< \brief transform of 32 */
    IfxFft_Length_64   = 6,  /**< \brief transform of 64 */
    IfxFft_Length_128  = 7,  /**< \brief transform of 128 */
    IfxFft_Length_256  = 8,  /**< \brief transform of 256 */
    IfxFft_Length_512  = 9,  /**< \brief transform of 512 */
    IfxFft_Length_1024 = 10  /**< \brief transform of 1024 */
} IfxFft_Length;

/** \brief Operation (FFT / IFFT)
 * Definition in Ifx_FFT.CSR.B.IFFT
 */
typedef enum
{
    IfxFft_Operation_fft  = 0, /**< \brief perform FFT */
    IfxFft_Operation_ifft = 1  /**< \brief perform IFFT */
} IfxFft_Operation;

/** \brief Output format
 * Definition in Ifx_FFT.CSR.B.OUT.FMT
 */
typedef enum
{
    IfxFft_Output_complexSInt32 = 0,  /**< \brief 1 complex 32-bit data per 64-bit word */
    IfxFft_Output_complexSInt16 = 1   /**< \brief 2 complex 16-bit data per 64-bit word */
} IfxFft_Output;

/** \brief OCDS Suspend Control (OCDS.SUS)
 */
typedef enum
{
    IfxFft_SuspendMode_none = 0,  /**< \brief No suspend */
    IfxFft_SuspendMode_hard = 1,  /**< \brief Hard Suspend */
    IfxFft_SuspendMode_soft = 2   /**< \brief Soft Suspend */
} IfxFft_SuspendMode;

/** \} */

/** \addtogroup IfxLld_Fft_Std_UtilityFunctions
 * \{ */

/******************************************************************************/
/*-------------------------Inline Function Prototypes-------------------------*/
/******************************************************************************/

/** \brief Disables the FFT module and also the LMU interface
 * \param fft pointer to FFT registers
 * \param lmu pointer to LMU registers
 * \return None
 */
IFX_INLINE void IfxFft_disableModule(Ifx_FFT *fft, Ifx_LMU *lmu);

/** \brief Enables the FFT module and also the LMU interface
 * \param fft pointer to FFT registers
 * \param lmu pointer to LMU registers
 * \return None
 */
IFX_INLINE void IfxFft_enableModule(Ifx_FFT *fft, Ifx_LMU *lmu);

/** \brief Returns the input format
 * \param fft pointer to FFT registers
 * \return Input format
 */
IFX_INLINE IfxFft_Input IfxFft_getInputFormat(Ifx_FFT *fft);

/** \brief Returns the length of the transform (length code, 3 to 10)
 * \param fft pointer to FFT registers
 * \return Length of the transform (length code)
 */
IFX_INLINE IfxFft_Length IfxFft_getLength(Ifx_FFT *fft);

/** \brief Converts the given input length into the transform length code, to write into Ifx_FFT.CSR.B.LENGTH
 * \param length Input length of the transform
 * \return Length of the transform (code, 3 to 10)
 */
IFX_INLINE IfxFft_Length IfxFft_getLengthCode(uint16 length);

/** \brief Retruns the actual length of the transform from the length code
 * \param length Length of transform
 * \return Actual length of the transform
 */
IFX_INLINE uint16 IfxFft_getLengthFromCode(IfxFft_Length length);

/** \brief Returns the output format
 * \param fft pointer to FFT registers
 * \return Output format
 */
IFX_INLINE IfxFft_Output IfxFft_getOutputFormat(Ifx_FFT *fft);

/** \brief Returns the status of FFT DONE request
 * \param fft pointer to FFT registers
 * \return Status of FFT DONE request
 */
IFX_INLINE volatile Ifx_SRC_SRCR *IfxFft_getSrcPointerDone(Ifx_FFT *fft);

/** \brief Returns the status of FFT RFS request
 * \param fft pointer to FFT registers
 * \return Status of FFT RFS request
 */
IFX_INLINE volatile Ifx_SRC_SRCR *IfxFft_getSrcPointerRfs(Ifx_FFT *fft);

/** \brief Returns the actual length of the transform
 * \param fft pointer to FFT registers
 * \return Actual length of the transform ()
 */
IFX_INLINE uint16 IfxFft_getTransformLength(Ifx_FFT *fft);

/** \brief Returns the status of whether the FFT Engine is Idle or has at least one transform in operation.
 * \param fft pointer to FFT registers
 * \return (true / false)
 */
IFX_INLINE boolean IfxFft_isEngineBusy(Ifx_FFT *fft);

/** \brief Returns the status of whether the module is enabled or not
 * \param fft pointer to FFT registers
 * \return (true / false)
 */
IFX_INLINE boolean IfxFft_isModuleEnabled(Ifx_FFT *fft);

/** \brief Returns the module's suspend state.
 * TRUE :if module is suspended.
 * FALSE:if module is not yet suspended.
 * \param fft Pointer to FFT module registers
 * \return Suspend status (TRUE / FALSE)
 */
IFX_INLINE boolean IfxFft_isModuleSuspended(Ifx_FFT *fft);

/** \brief Returns the status of whether the module can accept a START operation or not
 * \param fft Pointer to FFT registers
 * \return (true / false)
 */
IFX_INLINE boolean IfxFft_isReadyForStart(Ifx_FFT *fft);

/** \brief Configure the Module to Hard/Soft suspend mode.
 * Note: The api works only when the OCDS is enabled and in Supervisor Mode. When OCDS is disabled the OCS suspend control is ineffective.
 * \param fft Pointer to FFT module registers
 * \param mode Module suspend mode
 * \return None
 */
IFX_INLINE void IfxFft_setSuspendMode(Ifx_FFT *fft, IfxFft_SuspendMode mode);

/** \} */

/******************************************************************************/
/*---------------------Inline Function Implementations------------------------*/
/******************************************************************************/

IFX_INLINE void IfxFft_disableModule(Ifx_FFT *fft, Ifx_LMU *lmu)
{
    uint16 password = IfxScuWdt_getCpuWatchdogPassword();
    IfxScuWdt_clearCpuEndinit(password);
    // FFT clock disable
    fft->CLC.B.DISR = 1;
    IfxScuWdt_setCpuEndinit(password);
}


IFX_INLINE void IfxFft_enableModule(Ifx_FFT *fft, Ifx_LMU *lmu)
{
    uint16 password = IfxScuWdt_getCpuWatchdogPassword();
    IfxScuWdt_clearCpuEndinit(password);
    // FFT clock enable
    fft->CLC.U = 0x0;
    IfxScuWdt_setCpuEndinit(password);
}


IFX_INLINE IfxFft_Input IfxFft_getInputFormat(Ifx_FFT *fft)
{
    return (IfxFft_Input)fft->CSR.B.IN_FMT;
}


IFX_INLINE IfxFft_Length IfxFft_getLength(Ifx_FFT *fft)
{
    return (IfxFft_Length)fft->CSR.B.LENGTH;
}


IFX_INLINE IfxFft_Length IfxFft_getLengthCode(uint16 length)
{
    return (IfxFft_Length)(31 - __clz((uint32)length));
}


IFX_INLINE uint16 IfxFft_getLengthFromCode(IfxFft_Length length)
{
    return 1 << (uint32)length;
}


IFX_INLINE IfxFft_Output IfxFft_getOutputFormat(Ifx_FFT *fft)
{
    return (IfxFft_Output)fft->CSR.B.OUT_FMT;
}


IFX_INLINE volatile Ifx_SRC_SRCR *IfxFft_getSrcPointerDone(Ifx_FFT *fft)
{
    // only a single FFT available, therefore no check for the fft pointer required
    return &MODULE_SRC.FFT.FFT[0].DONE;
}


IFX_INLINE volatile Ifx_SRC_SRCR *IfxFft_getSrcPointerRfs(Ifx_FFT *fft)
{
    // only a single FFT available, therefore no check for the fft pointer required
    return &MODULE_SRC.FFT.FFT[0].RFS;
}


IFX_INLINE uint16 IfxFft_getTransformLength(Ifx_FFT *fft)
{
    return 1U << fft->CSR.B.LENGTH;
}


IFX_INLINE boolean IfxFft_isEngineBusy(Ifx_FFT *fft)
{
    return fft->CSR.B.BUSY != 0;
}


IFX_INLINE boolean IfxFft_isModuleEnabled(Ifx_FFT *fft)
{
    return fft->CLC.B.DISS == 0;
}


IFX_INLINE boolean IfxFft_isModuleSuspended(Ifx_FFT *fft)
{
    Ifx_FFT_OCS ocs;

    // read the status
    ocs.U = fft->OCS.U;

    // return the status
    return ocs.B.SUSSTA;
}


IFX_INLINE boolean IfxFft_isReadyForStart(Ifx_FFT *fft)
{
    return fft->CSR.B.RFS != 0;
}


IFX_INLINE void IfxFft_setSuspendMode(Ifx_FFT *fft, IfxFft_SuspendMode mode)
{
    Ifx_FFT_OCS ocs;

    // remove protection and configure the suspend mode.
    ocs.B.SUS_P = 1;
    ocs.B.SUS   = mode;
    fft->OCS.U  = ocs.U;
}


#endif /* IFXFFT_H */
