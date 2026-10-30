/**
 * \file IfxGtm_Cmu.h
 * \brief GTM  basic functionality
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
 * \defgroup IfxLld_Gtm_Std_Cmu Cmu Basic Functionality
 * \ingroup IfxLld_Gtm_Std
 * \defgroup IfxLld_Gtm_Std_Cmu_CMUEnumerations CMU Enumerations
 * \ingroup IfxLld_Gtm_Std_Cmu
 * \defgroup IfxLld_Gtm_Std_Cmu_CMU_Basic_Functions CMU Basic Functions
 * \ingroup IfxLld_Gtm_Std_Cmu
 */

#ifndef IFXGTM_CMU_H
#define IFXGTM_CMU_H 1

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include "_Impl/IfxGtm_cfg.h"
#include "IfxGtm_bf.h"
#include "IfxGtm.h"

/******************************************************************************/
/*--------------------------------Enumerations--------------------------------*/
/******************************************************************************/

/** \addtogroup IfxLld_Gtm_Std_Cmu_CMUEnumerations
 * \{ */
/** \brief CMU clock
 */
typedef enum
{
    IfxGtm_Cmu_Clk_0 = 0,  /**< \brief CMU Clock0 */
    IfxGtm_Cmu_Clk_1,      /**< \brief CMU Clock1 */
    IfxGtm_Cmu_Clk_2,      /**< \brief CMU Clock2 */
    IfxGtm_Cmu_Clk_3,      /**< \brief CMU Clock3 */
    IfxGtm_Cmu_Clk_4,      /**< \brief CMU Clock4 */
    IfxGtm_Cmu_Clk_5,      /**< \brief CMU Clock5 */
    IfxGtm_Cmu_Clk_6,      /**< \brief CMU Clock6 */
    IfxGtm_Cmu_Clk_7       /**< \brief CMU Clock7 */
} IfxGtm_Cmu_Clk;

/** \brief External clock
 */
typedef enum
{
    IfxGtm_Cmu_Eclk_0 = 0,  /**< \brief External Clock Eclk0 */
    IfxGtm_Cmu_Eclk_1,      /**< \brief External Clock Eclk1 */
    IfxGtm_Cmu_Eclk_2       /**< \brief External Clock Eclk2 */
} IfxGtm_Cmu_Eclk;

/** \brief Fixed clock
 */
typedef enum
{
    IfxGtm_Cmu_Fxclk_0 = 0,  /**< \brief Fixed Clock Fxclk0 */
    IfxGtm_Cmu_Fxclk_1,      /**< \brief Fixed Clock Fxclk1 */
    IfxGtm_Cmu_Fxclk_2,      /**< \brief Fixed Clock Fxclk2 */
    IfxGtm_Cmu_Fxclk_3,      /**< \brief Fixed Clock Fxclk3 */
    IfxGtm_Cmu_Fxclk_4       /**< \brief Fixed Clock Fxclk4 */
} IfxGtm_Cmu_Fxclk;

/** \brief Tim Filter counter frequency select.
 * Definition in Ifx_GTM_TIM_CH_CTRL.B.FLT_CNT_FRQ
 */
typedef enum
{
    IfxGtm_Cmu_Tim_Filter_Clk_0,  /**< \brief FLT_CNT counts with CMU_CLK0 */
    IfxGtm_Cmu_Tim_Filter_Clk_1,  /**< \brief FLT_CNT counts with CMU_CLK1 */
    IfxGtm_Cmu_Tim_Filter_Clk_6,  /**< \brief FLT_CNT counts with CMU_CLK6 */
    IfxGtm_Cmu_Tim_Filter_Clk_7   /**< \brief FLT_CNT counts with CMU_CLK7 */
} IfxGtm_Cmu_Tim_Filter_Clk;

/** \} */

/******************************************************************************/
/*------------------------------Type Definitions------------------------------*/
/******************************************************************************/

/** \brief CMU clock enable status of all configurable, external and fixed clocks.
 */
typedef Ifx_GTM_CLS_CMU_CLK_EN IfxGtm_Cmu_EnableStatusOfAllClocks;

/** \addtogroup IfxLld_Gtm_Std_Cmu_CMU_Basic_Functions
 * \{ */

/******************************************************************************/
/*-------------------------Global Function Prototypes-------------------------*/
/******************************************************************************/

/** \brief Enable / Disable the configurable, fixed, and external clocks.
 *
 * \param[inout] gtm     Pointer to GTM module.
 * \param[in]    clkMask Enable / Disable mask. Range: 0 to 0xFFFFFF.
 *
 * \retval None
 */
IFX_INLINE void IfxGtm_Cmu_enableClocks(Ifx_GTM *gtm, uint32 clkMask);

/** \brief Returns the GTM global clock frequency in Hz.
 *
 * \param[in] gtm Pointer to GTM module.
 *
 * \retval float32 GTM global clock frequency in Hz.
 */
IFX_INLINE float32 IfxGtm_Cmu_getGclkFrequency(Ifx_GTM *gtm);

/** \brief returns the CMU module frequency in Hz. This is only for CMU module frequency.
 * For GTM SYS frequency: IfxGtm_getSysClkFrequency() is to be used.
 *
 * \param[in] gtm Pointer to GTM module.
 *
 * \retval float32 GTM module frequency in Hz
 */
IFX_INLINE float32 IfxGtm_Cmu_getModuleFrequency(Ifx_GTM *gtm);

/** \brief Returns the configurable clock enable status.
 *
 * \param[in] gtm      Pointer to GTM module.
 * \param[in] clkIndex Index of the configurable clock 0=CMU_CLK0, 1=CMU_CLK1, .... Range: \ref IfxGtm_Cmu_Clk.
 *
 * \retval TRUE The clock is enabled, FALSE The clock is disabled.
 */
IFX_INLINE boolean IfxGtm_Cmu_isClkClockEnabled(Ifx_GTM *gtm, IfxGtm_Cmu_Clk clkIndex);

/** \brief Returns the external clock enable status.
 *
 * \param[in] gtm      Pointer to GTM module.
 * \param[in] clkIndex Index of the external clock 0=CMU_ECLK0, 1=CMU_ECLK1, .... Range: \ref IfxGtm_Cmu_Eclk.
 *
 * \retval TRUE The clock is enabled, FALSE The clock is disabled.
 */
IFX_INLINE boolean IfxGtm_Cmu_isEclkClockEnabled(Ifx_GTM *gtm, IfxGtm_Cmu_Eclk clkIndex);

/** \brief Returns the fixed clock enable status.
 *
 * \param[in] gtm Pointer to GTM module.
 *
 * \retval TRUE The clock is enabled, FALSE The clock is disabled.
 */
IFX_INLINE boolean IfxGtm_Cmu_isFxClockEnabled(Ifx_GTM *gtm);

/** \brief Select the clock input for CLK6 and CLK7.
 * note The frequency can only be modified when the corresponding clock is disabled using IfxGtm_Cmu_enableClocks().
 *
 * \param[inout] gtm       Pointer to GTM module.
 * \param[in]    clkIndex  Index of the configurable clock 0=CMU_CLK0, 1=CMU_CLK1, .... Range: \ref IfxGtm_Cmu_Eclk.
 * \param[in]    useGlobal If TRUE, uses the global clock as an input, else use the SUB_INC input.
 *
 * \retval None
 */
IFX_INLINE void IfxGtm_Cmu_selectClkInput(Ifx_GTM *gtm, IfxGtm_Cmu_Clk clkIndex, boolean useGlobal);

/** \brief Temporarily suspend all CMU clocks and return current clock-enable status.
 *
 * The returned status shall be passed later to IfxGtm_Cmu_resumeSuspendedClocks() to restore
 * the previously enabled clocks.
 *
 * \param[inout] gtm Pointer to GTM module.
 *
 * \retval IfxGtm_Cmu_EnableStatusOfAllClocks Current CMU clock-enable register state.
 */
IFX_INLINE IfxGtm_Cmu_EnableStatusOfAllClocks IfxGtm_Cmu_suspendAllClocks(Ifx_GTM *gtm);

/** \brief Restore all previously suspended CMU clocks.
 *
 * The argument shall be the status captured by IfxGtm_Cmu_suspendAllClocks().
 *
 * \param[inout] gtm           Pointer to GTM module.
 * \param[in]    currentStatus Previously captured CMU clock-enable register state.
 *
 * \retval None
 */
IFX_INLINE void IfxGtm_Cmu_resumeSuspendedClocks(Ifx_GTM *gtm, IfxGtm_Cmu_EnableStatusOfAllClocks currentStatus);

/******************************************************************************/
/*-------------------------Global Function Prototypes-------------------------*/
/******************************************************************************/

/** \brief Returns the GTM configurable clock frequency in Hz.
 *
 * \param[in] gtm           Pointer to GTM module.
 * \param[in] clkIndex      Index of the configurable clock 0=CMU_CLK0, 1=CMU_CLK1, ... Range: \ref IfxGtm_Cmu_Eclk.
 * \param[in] assumeEnabled When TRUE, attempt to calculate the frequency as if the clock is enabled.
 *
 * \retval float32 GTM configurable clock frequency in Hz.
 */
IFX_EXTERN float32 IfxGtm_Cmu_getClkFrequency(Ifx_GTM *gtm, IfxGtm_Cmu_Clk clkIndex, boolean assumeEnabled);

/** \brief Returns the GTM external clock frequency in Hz.
 *
 * \param[in] gtm           Pointer to GTM module.
 * \param[in] clkIndex      Index of the external clock 0=CMU_ECLK0, 1=CMU_ECLK1, ... Range: \ref IfxGtm_Cmu_Eclk.
 * \param[in] assumeEnabled When TRUE, attempt to calculate the frequency as if the clock is enabled.
 * .
 * \retval float32 GTM external clock frequency in Hz.
 */
IFX_EXTERN float32 IfxGtm_Cmu_getEclkFrequency(Ifx_GTM *gtm, IfxGtm_Cmu_Eclk clkIndex, boolean assumeEnabled);

/** \brief Returns the GTM fixed clock frequency in Hz.
 *
 * \param[in] gtm           Pointer to GTM module.
 * \param[in] clkIndex      Index of the fixed clock 0=CMU_FXCLK0, 1=CMU_FXCLK1, ... Range: \ref IfxGtm_Cmu_Eclk.
 * \param[in] assumeEnabled When TRUE, attempt to calculate the frequency as if the clock is enabled.
 *
 * \retval float32 GTM fixed clock frequency in Hz
 */
IFX_EXTERN float32 IfxGtm_Cmu_getFxClkFrequency(Ifx_GTM *gtm, IfxGtm_Cmu_Fxclk clkIndex, boolean assumeEnabled);

/** \brief Set the GTM configurable clock frequency in Hz.
 *
 * \param[inout] gtm       Pointer to GTM module.
 * \param[in]    clkIndex  Index of the configurable clock 0=CMU_CLK0, 1=CMU_CLK1, ... Range: \ref IfxGtm_Cmu_Eclk.
 * \param[in]    frequency Frequency in Hz.
 *
 * \retval None
 */
IFX_EXTERN void IfxGtm_Cmu_setClkFrequency(Ifx_GTM *gtm, IfxGtm_Cmu_Clk clkIndex, float32 frequency);

/** \brief Set the GTM external clock frequency in Hz.
 *
 * \param[inout] gtm       Pointer to GTM module.
 * \param[in]    clkIndex  Index of the external clock 0=CMU_ECLK0, 1=CMU_ECLK1, ... Range: \ref IfxGtm_Cmu_Eclk.
 * \param[in]    frequency Frequency in Hz.
 *
 * \retval None
 */
IFX_EXTERN void IfxGtm_Cmu_setEclkFrequency(Ifx_GTM *gtm, IfxGtm_Cmu_Eclk clkIndex, float32 frequency);

/** \brief Set the GTM global clock frequency in Hz.
 *
 * \param[inout] gtm       Pointer to GTM module.
 * \param[in]    frequency Frequency in Hz.
 *
 * \retval None
 */
IFX_EXTERN void IfxGtm_Cmu_setGclkFrequency(Ifx_GTM *gtm, float32 frequency);

/** \} */

/******************************************************************************/
/*-------------------------Inline Function Prototypes-------------------------*/
/******************************************************************************/

/** \brief Sets the count value for the clock divider of a configurable clock divider block.
 * Tcmu_clk[clkIndex] = (count + 1) * Tcmu_gclk_en
 * Note: Ensure CLSi_CMU_CLK_EN.EN_CLKx and CLSi_CMU_CLK_EN.EN_ECLKz (z=1) are disabled before calling this API. API doesn't perform any check.
 *
 * \param[inout] gtm      Pointer to GTM module.
 * \param[in]    clkIndex Index of the configurable clock 0=CMU_CLK0, 1=CMU_CLK1, ... Range: \ref IfxGtm_Cmu_Eclk.
 * \param[in]    count    Count value for the clock divider. Range: 0 to 0xFFFFFF.
 *
 * \retval None
 */
IFX_INLINE void IfxGtm_Cmu_setClkCount(Ifx_GTM *gtm, IfxGtm_Cmu_Clk clkIndex, uint32 count);

/** \brief Sets the numerator and denominator for External clock.
 * Tcmu_eclk[clkIndex] = (numerator / denominator) * Tcls0_clk
 * Note: Ensure CLSi_CMU_CLK_EN.EN_ECLKz is disabled before calling this API. API doesn't perform any check.
 *
 * \param[inout] gtm         Pointer to GTM module.
 * \param[in]    clkIndex    Index of the external clock 0=CMU_ECLK0, 1=CMU_ECLK1, ... Range: \ref IfxGtm_Cmu_Eclk.
 * \param[in]    numerator   Numerator for external clock divider. Defines numerator of the fractional divider. Range: 0 to 0xFFFFFF.
 * \param[in]    denominator Denominator for external clock divider. Defines denominator of the fractional divider. Range: 0 to 0xFFFFFF.
 *
 * \retval None
 */
IFX_INLINE void IfxGtm_Cmu_setEclkDivider(Ifx_GTM *gtm, IfxGtm_Cmu_Eclk clkIndex, uint32 numerator, uint32 denominator);

/** \brief Sets the numerator and denominator for Global clock.
 * Tcmu_gclk_en = (numerator / denominator) * Tcls0_clk
 * Note: Ensure CLSi_CMU_CLK_EN.EN_CLKx and CLSi_CMU_CLK_EN.EN_FXCLK are disabled before calling this API. API doesn't perform any check.
 *
 * \param[inout] gtm         Pointer to GTM module.
 * \param[in]    numerator   Numerator for global clock resolution generator. Defines numerator of the fractional divider. Range: 0 to 0xFFFFFF.
 * \param[in]    denominator Denominator for global clock resolution generator. Defines denominator of the fractional divider. Range: 0 to 0xFFFFFF.
 *
 * \retval None
 */
IFX_INLINE void IfxGtm_Cmu_setGclkDivider(Ifx_GTM *gtm, uint32 numerator, uint32 denominator);

/******************************************************************************/
/*---------------------Inline Function Implementations------------------------*/
/******************************************************************************/

IFX_INLINE void IfxGtm_Cmu_enableClocks(Ifx_GTM *gtm, uint32 clkMask)
{
    gtm->CLS->CMU.CLK_EN.U = clkMask;
}


IFX_INLINE IfxGtm_Cmu_EnableStatusOfAllClocks IfxGtm_Cmu_suspendAllClocks(Ifx_GTM *gtm)
{
    IfxGtm_Cmu_EnableStatusOfAllClocks currentStatus;
    currentStatus.U = gtm->CLS->CMU.CLK_EN.U;

    gtm->CLS->CMU.CLK_EN.U = ((uint32)IfxGtm_FeatureControl_disable << IFX_GTM_CLS_CMU_CLK_EN_EN_CLK0_OFF)
                           | ((uint32)IfxGtm_FeatureControl_disable << IFX_GTM_CLS_CMU_CLK_EN_EN_CLK1_OFF)
                           | ((uint32)IfxGtm_FeatureControl_disable << IFX_GTM_CLS_CMU_CLK_EN_EN_CLK2_OFF)
                           | ((uint32)IfxGtm_FeatureControl_disable << IFX_GTM_CLS_CMU_CLK_EN_EN_CLK3_OFF)
                           | ((uint32)IfxGtm_FeatureControl_disable << IFX_GTM_CLS_CMU_CLK_EN_EN_CLK4_OFF)
                           | ((uint32)IfxGtm_FeatureControl_disable << IFX_GTM_CLS_CMU_CLK_EN_EN_CLK5_OFF)
                           | ((uint32)IfxGtm_FeatureControl_disable << IFX_GTM_CLS_CMU_CLK_EN_EN_CLK6_OFF)
                           | ((uint32)IfxGtm_FeatureControl_disable << IFX_GTM_CLS_CMU_CLK_EN_EN_CLK7_OFF)
                           | ((uint32)IfxGtm_FeatureControl_disable << IFX_GTM_CLS_CMU_CLK_EN_EN_ECLK0_OFF)
                           | ((uint32)IfxGtm_FeatureControl_disable << IFX_GTM_CLS_CMU_CLK_EN_EN_ECLK1_OFF)
                           | ((uint32)IfxGtm_FeatureControl_disable << IFX_GTM_CLS_CMU_CLK_EN_EN_ECLK2_OFF)
                           | ((uint32)IfxGtm_FeatureControl_disable << IFX_GTM_CLS_CMU_CLK_EN_EN_FXCLK_OFF);

    return currentStatus;
}


IFX_INLINE void IfxGtm_Cmu_resumeSuspendedClocks(Ifx_GTM *gtm, IfxGtm_Cmu_EnableStatusOfAllClocks currentStatus)
{
    gtm->CLS->CMU.CLK_EN.U = currentStatus.U &
                             (((uint32)IfxGtm_FeatureControl_enable << IFX_GTM_CLS_CMU_CLK_EN_EN_CLK0_OFF)
                              | ((uint32)IfxGtm_FeatureControl_enable << IFX_GTM_CLS_CMU_CLK_EN_EN_CLK1_OFF)
                              | ((uint32)IfxGtm_FeatureControl_enable << IFX_GTM_CLS_CMU_CLK_EN_EN_CLK2_OFF)
                              | ((uint32)IfxGtm_FeatureControl_enable << IFX_GTM_CLS_CMU_CLK_EN_EN_CLK3_OFF)
                              | ((uint32)IfxGtm_FeatureControl_enable << IFX_GTM_CLS_CMU_CLK_EN_EN_CLK4_OFF)
                              | ((uint32)IfxGtm_FeatureControl_enable << IFX_GTM_CLS_CMU_CLK_EN_EN_CLK5_OFF)
                              | ((uint32)IfxGtm_FeatureControl_enable << IFX_GTM_CLS_CMU_CLK_EN_EN_CLK6_OFF)
                              | ((uint32)IfxGtm_FeatureControl_enable << IFX_GTM_CLS_CMU_CLK_EN_EN_CLK7_OFF)
                              | ((uint32)IfxGtm_FeatureControl_enable << IFX_GTM_CLS_CMU_CLK_EN_EN_ECLK0_OFF)
                              | ((uint32)IfxGtm_FeatureControl_enable << IFX_GTM_CLS_CMU_CLK_EN_EN_ECLK1_OFF)
                              | ((uint32)IfxGtm_FeatureControl_enable << IFX_GTM_CLS_CMU_CLK_EN_EN_ECLK2_OFF)
                              | ((uint32)IfxGtm_FeatureControl_enable << IFX_GTM_CLS_CMU_CLK_EN_EN_FXCLK_OFF));
}


IFX_INLINE float32 IfxGtm_Cmu_getGclkFrequency(Ifx_GTM *gtm)
{
    uint32  N          = (uint32)gtm->CLS->CMU.GCLK_DEN.B.GCLK_DEN;
    uint32  Z          = (uint32)gtm->CLS->CMU.GCLK_NUM.B.GCLK_NUM;
    float32 multiplier = (float32)((float32)N / (float32)Z);

    return IfxGtm_Cmu_getModuleFrequency(gtm) * multiplier;
}


IFX_INLINE float32 IfxGtm_Cmu_getModuleFrequency(Ifx_GTM *gtm)
{
    return (float32)IfxGtm_getClusterFrequency(gtm, IfxGtm_Cluster_0); /* CMU module frequency is cluster 0 clock frequency */
}


IFX_INLINE boolean IfxGtm_Cmu_isClkClockEnabled(Ifx_GTM *gtm, IfxGtm_Cmu_Clk clkIndex)
{
    boolean enabled;
    enabled = (((gtm->CLS->CMU.CLK_EN.U >> (2u * (uint8)clkIndex)) & IFX_GTM_CLS_CMU_CLK_EN_EN_CLK0_MSK) == 0x3) ? TRUE : FALSE;
    return enabled;
}


IFX_INLINE boolean IfxGtm_Cmu_isEclkClockEnabled(Ifx_GTM *gtm, IfxGtm_Cmu_Eclk clkIndex)
{
    boolean enabled;
    enabled = (((gtm->CLS->CMU.CLK_EN.U >> (2u * (uint8)clkIndex + 16u)) & IFX_GTM_CLS_CMU_CLK_EN_EN_CLK0_MSK) == 0x3) ? TRUE : FALSE;
    return enabled;
}


IFX_INLINE boolean IfxGtm_Cmu_isFxClockEnabled(Ifx_GTM *gtm)
{
    boolean enabled;
    enabled = (gtm->CLS->CMU.CLK_EN.B.EN_FXCLK == (uint8)0x3u) ? TRUE : FALSE;
    return enabled;
}


IFX_INLINE void IfxGtm_Cmu_selectClkInput(Ifx_GTM *gtm, IfxGtm_Cmu_Clk clkIndex, boolean useGlobal)
{
    switch (clkIndex)
    {
    case IfxGtm_Cmu_Clk_6:
        gtm->CLS->CMU.CLK_6_CTRL.B.CLK_SEL = (useGlobal == TRUE) ? (uint8)0u : (uint8)1u;
        break;
    case IfxGtm_Cmu_Clk_7:
        gtm->CLS->CMU.CLK_7_CTRL.B.CLK_SEL = (useGlobal == TRUE) ? (uint8)0u : (uint8)1u;
        break;
    default:
        /* do nothing */
        break;
    }
}


IFX_INLINE void IfxGtm_Cmu_setClkCount(Ifx_GTM *gtm, IfxGtm_Cmu_Clk clkIndex, uint32 count)
{
    switch (clkIndex)
    {
    case IfxGtm_Cmu_Clk_0:
        gtm->CLS->CMU.CLK0.CTRL.B.CLK_CNT = count;
        break;
    case IfxGtm_Cmu_Clk_1:
        gtm->CLS->CMU.CLK1.CTRL.B.CLK_CNT = count;
        break;
    case IfxGtm_Cmu_Clk_2:
        gtm->CLS->CMU.CLK2.CTRL.B.CLK_CNT = count;
        break;
    case IfxGtm_Cmu_Clk_3:
        gtm->CLS->CMU.CLK3.CTRL.B.CLK_CNT = count;
        break;
    case IfxGtm_Cmu_Clk_4:
        gtm->CLS->CMU.CLK4.CTRL.B.CLK_CNT = count;
        break;
    case IfxGtm_Cmu_Clk_5:
        gtm->CLS->CMU.CLK5.CTRL.B.CLK_CNT = count;
        break;
    case IfxGtm_Cmu_Clk_6:
        gtm->CLS->CMU.CLK_6_CTRL.B.CLK_CNT = count;
        break;
    case IfxGtm_Cmu_Clk_7:
        gtm->CLS->CMU.CLK_7_CTRL.B.CLK_CNT = count;
        break;
    default:
        /* do nothing */
        break;
    }
}


IFX_INLINE void IfxGtm_Cmu_setEclkDivider(Ifx_GTM *gtm, IfxGtm_Cmu_Eclk clkIndex, uint32 numerator, uint32 denominator)
{
    /* From UM: The CMU hardware alters the content of CLSi_CMU_ECLKz_NUM and CLSi_CMU_ECLKz_DEN automatically to 1H,
     * if CLSi_CMU_ECLKz_NUM is specified less than CLSi_CMU_ECLKz_DEN or one of the values is specified with
     * a value zero. Thus, a secure way for altering the values is writing twice to the register
     * CLSi_CMU_ECLKz_NUM followed by a single write to register CLSi_CMU_ECLKz_DEN
     */
    gtm->CLS->CMU.ECLK[clkIndex].NUM.U = numerator;
    gtm->CLS->CMU.ECLK[clkIndex].NUM.U = numerator;
    gtm->CLS->CMU.ECLK[clkIndex].DEN.U = denominator;
}


IFX_INLINE void IfxGtm_Cmu_setGclkDivider(Ifx_GTM *gtm, uint32 numerator, uint32 denominator)
{
    /* From UM: The CMU hardware alters the content of CLSi_CMU_GCLK_NUM and CLSi_CMU_GCLK_DEN automatically to 1H,
     * if CLSi_CMU_GCLK_NUM.GCLK_NUM is specified less than CLSi_CMU_GCLK_DEN.GCLK_DEN or one of the
     * values is specified with a value zero. Thus, a secure way for altering the values is writing twice to the register
     * CLSi_CMU_GCLK_NUM followed by a single write to register CLSi_CMU_GCLK_DEN
     */
    gtm->CLS->CMU.GCLK_NUM.U = numerator;
    gtm->CLS->CMU.GCLK_NUM.U = numerator;
    gtm->CLS->CMU.GCLK_DEN.U = denominator;
}


#endif /* IFXGTM_CMU_H */
