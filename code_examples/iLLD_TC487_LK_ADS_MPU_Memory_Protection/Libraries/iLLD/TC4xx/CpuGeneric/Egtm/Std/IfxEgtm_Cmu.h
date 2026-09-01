/**
 * \file IfxEgtm_Cmu.h
 * \brief EGTM  basic functionality
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
 * \defgroup IfxLld_Egtm_Std_Cmu Cmu Basic Functionality
 * \ingroup IfxLld_Egtm_Std
 * \defgroup IfxLld_Egtm_Std_Cmu_CMUEnumerations CMU Enumerations
 * \ingroup IfxLld_Egtm_Std_Cmu
 * \defgroup IfxLld_Egtm_Std_Cmu_CMU_Functions CMU Functions
 * \ingroup IfxLld_Egtm_Std_Cmu
 */

#ifndef IFXEGTM_CMU_H
#define IFXEGTM_CMU_H 1

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include "_Impl/IfxEgtm_cfg.h"
#include "IfxEgtm_bf.h"
#include "IfxEgtm.h"

/******************************************************************************/
/*--------------------------------Enumerations--------------------------------*/
/******************************************************************************/

/** \addtogroup IfxLld_Egtm_Std_Cmu_CMUEnumerations
 * \{ */
typedef enum
{
    IfxEgtm_Cmu_Clk_0 = 0,
    IfxEgtm_Cmu_Clk_1,
    IfxEgtm_Cmu_Clk_2,
    IfxEgtm_Cmu_Clk_3,
    IfxEgtm_Cmu_Clk_4,
    IfxEgtm_Cmu_Clk_5,
    IfxEgtm_Cmu_Clk_6,
    IfxEgtm_Cmu_Clk_7
} IfxEgtm_Cmu_Clk;

/** \brief External clock
 */
typedef enum
{
    IfxEgtm_Cmu_Eclk_0 = 0,
    IfxEgtm_Cmu_Eclk_1,
    IfxEgtm_Cmu_Eclk_2
} IfxEgtm_Cmu_Eclk;

/** \brief Fixed clock
 */
typedef enum
{
    IfxEgtm_Cmu_Fxclk_0 = 0,
    IfxEgtm_Cmu_Fxclk_1,
    IfxEgtm_Cmu_Fxclk_2,
    IfxEgtm_Cmu_Fxclk_3,
    IfxEgtm_Cmu_Fxclk_4
} IfxEgtm_Cmu_Fxclk;

/** \brief Tim Filter counter frequency select
 * Definition in Ifx_EGTM_CLS_TIM_CH_CTRL.B.FLT_CNT_FRQ
 */
typedef enum
{
    IfxEgtm_Cmu_Tim_Filter_Clk_0,  /**< \brief FLT_CNT counts with CMU_CLK0 */
    IfxEgtm_Cmu_Tim_Filter_Clk_1,  /**< \brief FLT_CNT counts with CMU_CLK1 */
    IfxEgtm_Cmu_Tim_Filter_Clk_6,  /**< \brief FLT_CNT counts with CMU_CLK6 */
    IfxEgtm_Cmu_Tim_Filter_Clk_7   /**< \brief FLT_CNT counts with CMU_CLK7 */
} IfxEgtm_Cmu_Tim_Filter_Clk;

/** \} */

/******************************************************************************/
/*------------------------------Type Definitions------------------------------*/
/******************************************************************************/

/** \brief CMU clock enable status of all configurable, external and fixed clocks.
 */
typedef Ifx_EGTM_CLS_CMU_CLK_EN IfxEgtm_Cmu_EnableStatusOfAllClocks;

/** \addtogroup IfxLld_Egtm_Std_Cmu_CMU_Functions
 * \{ */

/******************************************************************************/
/*-------------------------Inline Function Prototypes-------------------------*/
/******************************************************************************/

/** \brief Enable / Disable the configurable, fixed, and external clocks
 *
 * \param[inout] egtm    Pointer to EGTM module
 * \param[in]    clkMask Enable / Disable mask.
 *
 * \retval None
 */
IFX_INLINE void IfxEgtm_Cmu_enableClocks(Ifx_EGTM *egtm, uint32 clkMask);

/** \brief Returns the EGTM global clock frequency in Hz
 *
 * \param[in] egtm Pointer to EGTM module
 *
 * \retval EGTM global clock frequency in Hz
 */
IFX_INLINE float32 IfxEgtm_Cmu_getGclkFrequency(Ifx_EGTM *egtm);

/** \brief returns the CMU module frequency in Hz. This is only for CMU module frequency.
 * For EGTM SYS frequency: IfxEgtm_getSysClkFrequency() is to be used.
 *
 * \param[in] egtm Pointer to EGTM module
 *
 * \retval EGTM module frequency in Hz
 */
IFX_INLINE float32 IfxEgtm_Cmu_getModuleFrequency(Ifx_EGTM *egtm);

/** \brief Returns the configurable clock enable status
 *
 * \param[in] egtm     Pointer to EGTM module
 * \param[in] clkIndex Index of the configurable clock 0=CMU_CLK0, 1=CMU_CLK1, ...
 *                     Range: \ref: IfxEgtm_Cmu_Clk
 *
 * \retval TRUE The clock is enabled, FALSE The clock is disabled
 */
IFX_INLINE boolean IfxEgtm_Cmu_isClkClockEnabled(Ifx_EGTM *egtm, IfxEgtm_Cmu_Clk clkIndex);

/** \brief Returns the external clock enable status
 *
 * \param[in] egtm     Pointer to EGTM module
 * \param[in] clkIndex Index of the external clock 0=CMU_ECLK0, 1=CMU_ECLK1, ...
 *                     Range: \ref: IfxEgtm_Cmu_Clk
 *
 * \retval TRUE The clock is enabled, FALSE The clock is disabled
 */
IFX_INLINE boolean IfxEgtm_Cmu_isEclkClockEnabled(Ifx_EGTM *egtm, IfxEgtm_Cmu_Eclk clkIndex);

/** \brief Returns the fixed clock enable status
 *
 * \param[in] egtm Pointer to EGTM module
 *
 * \retval TRUE The clock is enabled, FALSE The clock is disabled
 */
IFX_INLINE boolean IfxEgtm_Cmu_isFxClockEnabled(Ifx_EGTM *egtm);

/** \brief Select the clock input for CLK6 and CLK7
 * note The frequency can only be modified when the corresponding clock is disabled using IfxEgtm_Cmu_enableClocks()
 *
 * \param[inout] egtm      Pointer to EGTM module
 * \param[in]    clkIndex  Index of the configurable clock 0=CMU_CLK0, 1=CMU_CLK1, ...
 *                         Range: \ref: IfxEgtm_Cmu_Clk
 * \param[in]    useGlobal If TRUE, uses the global clock as an input, else use the SUB_INC input
 *
 * \retval None
 */
IFX_INLINE void IfxEgtm_Cmu_selectClkInput(Ifx_EGTM *egtm, IfxEgtm_Cmu_Clk clkIndex, boolean useGlobal);

/** \brief Sets the count value for the clock divider of a configurable clock divider block
 * Tcmu_clk[clkIndex] = (count + 1) * Tcmu_gclk_en
 * Note: Ensure CLSi_CMU_CLK_EN.EN_CLKx and CLSi_CMU_CLK_EN.EN_ECLKz (z=1) are disabled before calling this API. API doesn't perform any check.
 *
 * \param[inout] egtm     Pointer to GTM module
 * \param[in]    clkIndex Index of the configurable clock 0=CMU_CLK0, 1=CMU_CLK1, ...
 *                        Range: \ref: IfxEgtm_Cmu_Clk
 * \param[in]    count    Count value for the clock divider
 *                        Range: 0 to 0x00FFFFFF
 *
 * \retval None
 */
IFX_INLINE void IfxEgtm_Cmu_setClkCount(Ifx_EGTM *egtm, IfxEgtm_Cmu_Clk clkIndex, uint32 count);

/** \brief Sets the numerator and denominator for External clock
 * Tcmu_eclk[clkIndex] = (numerator / denominator) * Tcls0_clk
 * Note: Ensure CLSi_CMU_CLK_EN.EN_ECLKz is disabled before calling this API. API doesn't perform any check.
 *
 * \param[inout] egtm        Pointer to GTM module
 * \param[in]    clkIndex    Index of the external clock 0=CMU_ECLK0, 1=CMU_ECLK1, ...
 *                           Range: \ref: IfxEgtm_Cmu_Clk
 * \param[in]    numerator   Numerator for external clock divider. Defines numerator of the fractional divider
 *                           Range: 0 to 0x00FFFFFF
 * \param[in]    denominator Denominator for external clock divider. Defines denominator of the fractional divider
 *                           Range: 0 to 0x00FFFFFF
 *
 * \retval None
 */
IFX_INLINE void IfxEgtm_Cmu_setEclkDivider(Ifx_EGTM *egtm, IfxEgtm_Cmu_Eclk clkIndex, uint32 numerator, uint32 denominator);

/** \brief Sets the numerator and denominator for Global clock
 * Tcmu_gclk_en = (numerator / denominator) * Tcls0_clk
 * Note: Ensure CLSi_CMU_CLK_EN.EN_CLKx and CLSi_CMU_CLK_EN.EN_FXCLK are disabled before calling this API. API doesn't perform any check.
 *
 * \param[inout] egtm        Pointer to GTM module
 * \param[in]    numerator   Numerator for global clock resolution generator. Defines numerator of the fractional divider.
 *                           Range: 0 to 0x00FFFFFF
 * \param[in]    denominator Denominator for global clock resolution generator. Defines denominator of the fractional divider.
 *                           Range: 0 to 0x00FFFFFF
 *
 * \retval None
 */
IFX_INLINE void IfxEgtm_Cmu_setGclkDivider(Ifx_EGTM *egtm, uint32 numerator, uint32 denominator);

/** \brief Temporarily suspend all CMU clocks and return current clock-enable status.
 *
 * The returned status shall be passed later to IfxEgtm_Cmu_resumeSuspendedClocks() to restore
 * the previously enabled clocks.
 *
 * \param[inout] egtm Pointer to EGTM module.
 *
 * \retval IfxEgtm_Cmu_EnableStatusOfAllClocks Current CMU clock-enable register state.
 */
IFX_INLINE IfxEgtm_Cmu_EnableStatusOfAllClocks IfxEgtm_Cmu_suspendAllClocks(Ifx_EGTM *egtm);

/** \brief Restore all previously suspended CMU clocks.
 *
 * The argument shall be the status captured by IfxEgtm_Cmu_suspendAllClocks().
 *
 * \param[inout] egtm          Pointer to EGTM module.
 * \param[in]    currentStatus Previously captured CMU clock-enable register state.
 *
 * \retval None
 */
IFX_INLINE void IfxEgtm_Cmu_resumeSuspendedClocks(Ifx_EGTM *egtm, IfxEgtm_Cmu_EnableStatusOfAllClocks currentStatus);

/******************************************************************************/
/*-------------------------Global Function Prototypes-------------------------*/
/******************************************************************************/

/** \brief Returns the EGTM configurable clock frequency in Hz
 *
 * \param[in] egtm          Pointer to EGTM module
 * \param[in] clkIndex      Index of the configurable clock 0=CMU_CLK0, 1=CMU_CLK1, ...
 *                          Range: \ref: IfxEgtm_Cmu_Clk
 * \param[in] assumeEnabled When TRUE, attempt to calculate the frequency as if the clock is enabled.
 *
 * \retval EGTM configurable clock frequency in Hz
 */
IFX_EXTERN float32 IfxEgtm_Cmu_getClkFrequency(Ifx_EGTM *egtm, IfxEgtm_Cmu_Clk clkIndex, boolean assumeEnabled);

/** \brief Returns the EGTM external clock frequency in Hz
 *
 * \param[in] egtm          Pointer to EGTM module
 * \param[in] clkIndex      Index of the external clock 0=CMU_ECLK0, 1=CMU_ECLK1, ...
 *                          Range: \ref: IfxEgtm_Cmu_Clk
 * \param[in] assumeEnabled When TRUE, attempt to calculate the frequency as if the clock is enabled.
 *
 * \retval EGTM external clock frequency in Hz
 */
IFX_EXTERN float32 IfxEgtm_Cmu_getEclkFrequency(Ifx_EGTM *egtm, IfxEgtm_Cmu_Eclk clkIndex, boolean assumeEnabled);

/** \brief Returns the EGTM fixed clock frequency in Hz
 *
 * \param[in] egtm          Pointer to EGTM module
 * \param[in] clkIndex      Index of the fixed clock 0=CMU_FXCLK0, 1=CMU_FXCLK1, ...
 *                          Range: \ref: IfxEgtm_Cmu_Clk
 * \param[in] assumeEnabled When TRUE, attempt to calculate the frequency as if the clock is enabled.
 *
 * \retval EGTM fixed clock frequency in Hz
 */
IFX_EXTERN float32 IfxEgtm_Cmu_getFxClkFrequency(Ifx_EGTM *egtm, IfxEgtm_Cmu_Fxclk clkIndex, boolean assumeEnabled);

/** \brief Set the EGTM configurable clock frequency in Hz
 *
 * \param[inout] egtm      Pointer to EGTM module
 * \param[in]    clkIndex  Index of the configurable clock 0=CMU_CLK0, 1=CMU_CLK1, ...
 *                         Range: \ref: IfxEgtm_Cmu_Clk
 * \param[in]    frequency Frequency in Hz
 *
 * \retval None
 */
IFX_EXTERN void IfxEgtm_Cmu_setClkFrequency(Ifx_EGTM *egtm, IfxEgtm_Cmu_Clk clkIndex, float32 frequency);

/** \brief Set the EGTM external clock frequency in Hz
 *
 * \param[inout] egtm      Pointer to EGTM module
 * \param[in]    clkIndex  Index of the external clock 0=CMU_ECLK0, 1=CMU_ECLK1, ...
 *                         Range: \ref: IfxEgtm_Cmu_Clk
 * \param[in]    frequency Frequency in Hz
 *
 * \retval None
 */
IFX_EXTERN void IfxEgtm_Cmu_setEclkFrequency(Ifx_EGTM *egtm, IfxEgtm_Cmu_Eclk clkIndex, float32 frequency);

/** \brief Set the EGTM global clock frequency in Hz
 *
 * \param[inout] egtm      Pointer to EGTM module
 * \param[in]    frequency Frequency in Hz
 *
 * \retval None
 */
IFX_EXTERN void IfxEgtm_Cmu_setGclkFrequency(Ifx_EGTM *egtm, float32 frequency);

/** \} */

/******************************************************************************/
/*---------------------Inline Function Implementations------------------------*/
/******************************************************************************/

IFX_INLINE void IfxEgtm_Cmu_enableClocks(Ifx_EGTM *egtm, uint32 clkMask)
{
    egtm->CLS->CMU.CLK_EN.U = clkMask;
}


IFX_INLINE IfxEgtm_Cmu_EnableStatusOfAllClocks IfxEgtm_Cmu_suspendAllClocks(Ifx_EGTM *egtm)
{
    IfxEgtm_Cmu_EnableStatusOfAllClocks currentStatus;
    currentStatus.U = egtm->CLS->CMU.CLK_EN.U;

    egtm->CLS->CMU.CLK_EN.U = ((uint32)IfxEgtm_FeatureControl_disable << IFX_EGTM_CLS_CMU_CLK_EN_EN_CLK0_OFF)
                            | ((uint32)IfxEgtm_FeatureControl_disable << IFX_EGTM_CLS_CMU_CLK_EN_EN_CLK1_OFF)
                            | ((uint32)IfxEgtm_FeatureControl_disable << IFX_EGTM_CLS_CMU_CLK_EN_EN_CLK2_OFF)
                            | ((uint32)IfxEgtm_FeatureControl_disable << IFX_EGTM_CLS_CMU_CLK_EN_EN_CLK3_OFF)
                            | ((uint32)IfxEgtm_FeatureControl_disable << IFX_EGTM_CLS_CMU_CLK_EN_EN_CLK4_OFF)
                            | ((uint32)IfxEgtm_FeatureControl_disable << IFX_EGTM_CLS_CMU_CLK_EN_EN_CLK5_OFF)
                            | ((uint32)IfxEgtm_FeatureControl_disable << IFX_EGTM_CLS_CMU_CLK_EN_EN_CLK6_OFF)
                            | ((uint32)IfxEgtm_FeatureControl_disable << IFX_EGTM_CLS_CMU_CLK_EN_EN_CLK7_OFF)
                            | ((uint32)IfxEgtm_FeatureControl_disable << IFX_EGTM_CLS_CMU_CLK_EN_EN_ECLK0_OFF)
                            | ((uint32)IfxEgtm_FeatureControl_disable << IFX_EGTM_CLS_CMU_CLK_EN_EN_ECLK1_OFF)
                            | ((uint32)IfxEgtm_FeatureControl_disable << IFX_EGTM_CLS_CMU_CLK_EN_EN_ECLK2_OFF)
                            | ((uint32)IfxEgtm_FeatureControl_disable << IFX_EGTM_CLS_CMU_CLK_EN_EN_FXCLK_OFF);

    return currentStatus;
}


IFX_INLINE void IfxEgtm_Cmu_resumeSuspendedClocks(Ifx_EGTM *egtm, IfxEgtm_Cmu_EnableStatusOfAllClocks currentStatus)
{
    egtm->CLS->CMU.CLK_EN.U = currentStatus.U &
                              (((uint32)IfxEgtm_FeatureControl_enable << IFX_EGTM_CLS_CMU_CLK_EN_EN_CLK0_OFF)
                               | ((uint32)IfxEgtm_FeatureControl_enable << IFX_EGTM_CLS_CMU_CLK_EN_EN_CLK1_OFF)
                               | ((uint32)IfxEgtm_FeatureControl_enable << IFX_EGTM_CLS_CMU_CLK_EN_EN_CLK2_OFF)
                               | ((uint32)IfxEgtm_FeatureControl_enable << IFX_EGTM_CLS_CMU_CLK_EN_EN_CLK3_OFF)
                               | ((uint32)IfxEgtm_FeatureControl_enable << IFX_EGTM_CLS_CMU_CLK_EN_EN_CLK4_OFF)
                               | ((uint32)IfxEgtm_FeatureControl_enable << IFX_EGTM_CLS_CMU_CLK_EN_EN_CLK5_OFF)
                               | ((uint32)IfxEgtm_FeatureControl_enable << IFX_EGTM_CLS_CMU_CLK_EN_EN_CLK6_OFF)
                               | ((uint32)IfxEgtm_FeatureControl_enable << IFX_EGTM_CLS_CMU_CLK_EN_EN_CLK7_OFF)
                               | ((uint32)IfxEgtm_FeatureControl_enable << IFX_EGTM_CLS_CMU_CLK_EN_EN_ECLK0_OFF)
                               | ((uint32)IfxEgtm_FeatureControl_enable << IFX_EGTM_CLS_CMU_CLK_EN_EN_ECLK1_OFF)
                               | ((uint32)IfxEgtm_FeatureControl_enable << IFX_EGTM_CLS_CMU_CLK_EN_EN_ECLK2_OFF)
                               | ((uint32)IfxEgtm_FeatureControl_enable << IFX_EGTM_CLS_CMU_CLK_EN_EN_FXCLK_OFF));
}


IFX_INLINE float32 IfxEgtm_Cmu_getGclkFrequency(Ifx_EGTM *egtm)
{
    uint32  N          = (uint32)egtm->CLS->CMU.GCLK_DEN.B.GCLK_DEN;
    uint32  Z          = (uint32)egtm->CLS->CMU.GCLK_NUM.B.GCLK_NUM;
    float32 multiplier = (float32)((float32)N / (float32)Z);

    return IfxEgtm_Cmu_getModuleFrequency(egtm) * multiplier;
}


IFX_INLINE float32 IfxEgtm_Cmu_getModuleFrequency(Ifx_EGTM *egtm)
{
    return (float32)IfxEgtm_getClusterFrequency(egtm, IfxEgtm_Cluster_0); /* CMU module frequency is cluster 0 clock frequency */
}


IFX_INLINE boolean IfxEgtm_Cmu_isClkClockEnabled(Ifx_EGTM *egtm, IfxEgtm_Cmu_Clk clkIndex)
{
    boolean enabled;
    enabled = (((egtm->CLS->CMU.CLK_EN.U >> (2u * (uint8)clkIndex)) & IFX_EGTM_CLS_CMU_CLK_EN_EN_CLK0_MSK) == 0x3) ? TRUE : FALSE;
    return enabled;
}


IFX_INLINE boolean IfxEgtm_Cmu_isEclkClockEnabled(Ifx_EGTM *egtm, IfxEgtm_Cmu_Eclk clkIndex)
{
    boolean enabled;
    enabled = (((egtm->CLS->CMU.CLK_EN.U >> (2u * (uint8)clkIndex + 16u)) & IFX_EGTM_CLS_CMU_CLK_EN_EN_CLK0_MSK) == 0x3) ? TRUE : FALSE;
    return enabled;
}


IFX_INLINE boolean IfxEgtm_Cmu_isFxClockEnabled(Ifx_EGTM *egtm)
{
    boolean enabled;
    enabled = (egtm->CLS->CMU.CLK_EN.B.EN_FXCLK == (uint8)0x3u) ? TRUE : FALSE;
    return enabled;
}


IFX_INLINE void IfxEgtm_Cmu_selectClkInput(Ifx_EGTM *egtm, IfxEgtm_Cmu_Clk clkIndex, boolean useGlobal)
{
    switch (clkIndex)
    {
    case IfxEgtm_Cmu_Clk_6:
        egtm->CLS->CMU.CLK_6_CTRL.B.CLK_SEL = (useGlobal == TRUE) ? (uint8)0u : (uint8)1u;
        break;
    case IfxEgtm_Cmu_Clk_7:
        egtm->CLS->CMU.CLK_7_CTRL.B.CLK_SEL = (useGlobal == TRUE) ? (uint8)0u : (uint8)1u;
        break;
    default:
        /* do nothing */
        break;
    }
}


IFX_INLINE void IfxEgtm_Cmu_setClkCount(Ifx_EGTM *egtm, IfxEgtm_Cmu_Clk clkIndex, uint32 count)
{
    switch (clkIndex)
    {
    case IfxEgtm_Cmu_Clk_0:
        egtm->CLS->CMU.CLK0.CTRL.B.CLK_CNT = count;
        break;
    case IfxEgtm_Cmu_Clk_1:
        egtm->CLS->CMU.CLK1.CTRL.B.CLK_CNT = count;
        break;
    case IfxEgtm_Cmu_Clk_2:
        egtm->CLS->CMU.CLK2.CTRL.B.CLK_CNT = count;
        break;
    case IfxEgtm_Cmu_Clk_3:
        egtm->CLS->CMU.CLK3.CTRL.B.CLK_CNT = count;
        break;
    case IfxEgtm_Cmu_Clk_4:
        egtm->CLS->CMU.CLK4.CTRL.B.CLK_CNT = count;
        break;
    case IfxEgtm_Cmu_Clk_5:
        egtm->CLS->CMU.CLK5.CTRL.B.CLK_CNT = count;
        break;
    case IfxEgtm_Cmu_Clk_6:
        egtm->CLS->CMU.CLK_6_CTRL.B.CLK_CNT = count;
        break;
    case IfxEgtm_Cmu_Clk_7:
        egtm->CLS->CMU.CLK_7_CTRL.B.CLK_CNT = count;
        break;
    default:
        /* do nothing */
        break;
    }
}


IFX_INLINE void IfxEgtm_Cmu_setEclkDivider(Ifx_EGTM *egtm, IfxEgtm_Cmu_Eclk clkIndex, uint32 numerator, uint32 denominator)
{
    /* From UM: The CMU hardware alters the content of CLSi_CMU_ECLKz_NUM and CLSi_CMU_ECLKz_DEN automatically to 1H,
     * if CLSi_CMU_ECLKz_NUM is specified less than CLSi_CMU_ECLKz_DEN or one of the values is specified with
     * a value zero. Thus, a secure way for altering the values is writing twice to the register
     * CLSi_CMU_ECLKz_NUM followed by a single write to register CLSi_CMU_ECLKz_DEN
     */
    egtm->CLS->CMU.ECLK[clkIndex].NUM.U = numerator;
    egtm->CLS->CMU.ECLK[clkIndex].NUM.U = numerator;
    egtm->CLS->CMU.ECLK[clkIndex].DEN.U = denominator;
}


IFX_INLINE void IfxEgtm_Cmu_setGclkDivider(Ifx_EGTM *egtm, uint32 numerator, uint32 denominator)
{
    /* From UM: The CMU hardware alters the content of CLSi_CMU_GCLK_NUM and CLSi_CMU_GCLK_DEN automatically to 1H,
     * if CLSi_CMU_GCLK_NUM.GCLK_NUM is specified less than CLSi_CMU_GCLK_DEN.GCLK_DEN or one of the
     * values is specified with a value zero. Thus, a secure way for altering the values is writing twice to the register
     * CLSi_CMU_GCLK_NUM followed by a single write to register CLSi_CMU_GCLK_DEN
     */
    egtm->CLS->CMU.GCLK_NUM.U = numerator;
    egtm->CLS->CMU.GCLK_NUM.U = numerator;
    egtm->CLS->CMU.GCLK_DEN.U = denominator;
}


#endif /* IFXEGTM_CMU_H */
