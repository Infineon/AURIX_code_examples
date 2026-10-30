/**
 * \file IfxGtm_Cmu.h
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
typedef Ifx_GTM_CMU_CLK_EN IfxGtm_Cmu_EnableStatusOfAllClocks;

/** \addtogroup IfxLld_Gtm_Std_Cmu_CMU_Basic_Functions
 * \{ */

/******************************************************************************/
/*-------------------------Global Function Prototypes-------------------------*/
/******************************************************************************/

/**
 * \brief Enable or disable the configurable, fixed, and external clocks of the GTM module.
 *
 * \param[inout] gtm     Pointer to the GTM module instance to be configured.
 * \param[in]    clkMask Enable/disable mask. Range: 0x00000000 to 0x00FFFFFF
 *
 * \retval None
 */
IFX_EXTERN void IfxGtm_Cmu_enableClocks(Ifx_GTM *gtm, uint32 clkMask);

/**
 * \brief Returns the GTM configurable clock frequency in Hz
 *
 * \param[in] gtm           Pointer to the GTM module instance.
 * \param[in] clkIndex      Index of the configurable clock to query. Range: \ref IfxGtm_Cmu_Clk
 * \param[in] assumeEnabled Boolean flag to control frequency calculation behavior.
 *                          - TRUE: Calculate frequency assuming the clock is enabled
 *                          - FALSE: Use actual clock state for calculation
 *
 * \retval float32 GTM configurable clock frequency in Hz
 */
IFX_EXTERN float32 IfxGtm_Cmu_getClkFrequency(Ifx_GTM *gtm, IfxGtm_Cmu_Clk clkIndex, boolean assumeEnabled);

/**
 * \brief Gets the GTM external clock frequency in Hz
 *
 * \param[in] gtm           Pointer to the GTM module instance.
 * \param[in] clkIndex      Index of the external clock. Range: \ref IfxGtm_Cmu_Eclk
 * \param[in] assumeEnabled When TRUE, calculates the frequency as if the clock is enabled; when FALSE, uses the actual clock state
 *
 * \retval float32 GTM external clock frequency in Hz
 */
IFX_EXTERN float32 IfxGtm_Cmu_getEclkFrequency(Ifx_GTM *gtm, IfxGtm_Cmu_Eclk clkIndex, boolean assumeEnabled);

/**
 * \brief Returns the GTM fixed clock frequency in Hz
 *
 * \param[in] gtm 			Pointer to the GTM module instance.
 * \param[in] clkIndex 		Index of the fixed clock to query. Range: \ref IfxGtm_Cmu_Fxclk
 * \param[in] assumeEnabled When TRUE, the function assumes the clock is enabled
 *                          for frequency calculation. When FALSE, the actual
 *                          clock state is considered.
 *
 * \retval float32 GTM fixed clock frequency in Hz
 */
IFX_EXTERN float32 IfxGtm_Cmu_getFxClkFrequency(Ifx_GTM *gtm, IfxGtm_Cmu_Fxclk clkIndex, boolean assumeEnabled);

/**
 * \brief Returns the GTM global clock frequency in Hz
 *
 * \param[in] gtm Pointer to the GTM module instance.
 *
 * \retval float32 GTM global clock frequency in Hz
 */
IFX_EXTERN float32 IfxGtm_Cmu_getGclkFrequency(Ifx_GTM *gtm);

/**
 * \brief Returns the CMU module frequency in Hz.
 * This function retrieves the frequency of the CMU module. For the GTM system clock frequency, use IfxGtm_getSysClkFrequency() instead.
 *
 * \param[in] gtm Pointer to the GTM module instance.
 *
 * \retval float32 The CMU module frequency in Hz.
 */
IFX_EXTERN float32 IfxGtm_Cmu_getModuleFrequency(Ifx_GTM *gtm);

/**
 * \brief Checks if the specified configurable clock is enabled
 *
 * \param[in] gtm      Pointer to the GTM module instance.
 * \param[in] clkIndex Index of the configurable clock to check. Range: \ref IfxGtm_Cmu_Clk
 *
 * \retval TRUE If the clock is enabled.
 *         FALSE If the clock is disabled.
 */
IFX_EXTERN boolean IfxGtm_Cmu_isClkClockEnabled(Ifx_GTM *gtm, IfxGtm_Cmu_Clk clkIndex);

/**
 * \brief Checks if a specific external clock is enabled.
 *
 * \param[in] gtm      Pointer to the GTM module instance.
 * \param[in] clkIndex Index of the external clock to check. Range: \ref IfxGtm_Cmu_Eclk
 *
 * \retval TRUE If the specified external clock is enabled.
 *         FALSE If the specified external clock is disabled.
 */
IFX_EXTERN boolean IfxGtm_Cmu_isEclkClockEnabled(Ifx_GTM *gtm, IfxGtm_Cmu_Eclk clkIndex);

/**
 * \brief Checks if the fixed clock is enabled for the GTM module.
 *
 * \param gtm [in] Pointer to the GTM module instance.
 *
 * \retval TRUE If the fixed clock is enabled.
 *         FALSE If the fixed clock is disabled.
 */
IFX_EXTERN boolean IfxGtm_Cmu_isFxClockEnabled(Ifx_GTM *gtm);

/**
 * \brief Select the clock input for CLK6 and CLK7.
 * 
 * \note The frequency can only be modified when the corresponding clock is disabled using IfxGtm_Cmu_enableClocks()
 *
 * \param[inout] gtm    Pointer to the GTM module instance.
 * \param[in] clkIndex  Index of the configurable clock to be configured. Range: \ref IfxGtm_Cmu_Clk
 * \param[in] useGlobal Boolean flag to select the input source:
 *                      - TRUE: Use the global clock as input.
 *                      - FALSE: Use the SUB_INC as input.
 *
 * \retval None
 */
IFX_EXTERN void IfxGtm_Cmu_selectClkInput(Ifx_GTM *gtm, IfxGtm_Cmu_Clk clkIndex, boolean useGlobal);

/**
 * \brief Configures the specified GTM configurable clock with the desired frequency in Hz.
 *
 * \param[inout] gtm       Pointer to the GTM module instance.
 * \param[in]    clkIndex  Index of the configurable clock to set. Range: \ref IfxGtm_Cmu_Clk
 * \param[in]    frequency Frequency in Hz for the selected configurable clock.
 *                         Range: Must be a positive value (frequency > 0).
 *
 * \retval None
 */
IFX_EXTERN void IfxGtm_Cmu_setClkFrequency(Ifx_GTM *gtm, IfxGtm_Cmu_Clk clkIndex, float32 frequency);

/** \brief Configures the GTM external clock frequency in Hz.
 *
 * \param[inout] gtm       Pointer to the GTM module instance.
 * \param[in]    clkIndex  Index of the external clock to set. Range: \ref IfxGtm_Cmu_Clk
 * \param[in]    frequency Frequency in Hz. Range: Must be a positive value (frequency > 0).
 *
 * \retval None
 */
IFX_EXTERN void IfxGtm_Cmu_setEclkFrequency(Ifx_GTM *gtm, IfxGtm_Cmu_Eclk clkIndex, float32 frequency);

/**
 * \brief Configures the GTM global clock frequency in Hz.
 *
 * \param[inout] gtm       Pointer to the GTM module instance.
 * \param[in]    frequency Frequency in Hz to be set for the global clock. Range: Must be a positive value (frequency > 0).
 *
 * \retval None
 */
IFX_EXTERN void IfxGtm_Cmu_setGclkFrequency(Ifx_GTM *gtm, float32 frequency);

/******************************************************************************/
/*-------------------------Inline Function Prototypes-------------------------*/
/******************************************************************************/

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

/** \} */

/******************************************************************************/
/*---------------------Inline Function Implementations------------------------*/
/******************************************************************************/

IFX_INLINE IfxGtm_Cmu_EnableStatusOfAllClocks IfxGtm_Cmu_suspendAllClocks(Ifx_GTM *gtm)
{
    IfxGtm_Cmu_EnableStatusOfAllClocks currentStatus = gtm->CMU.CLK_EN;

    gtm->CMU.CLK_EN.U = ((uint32)IfxGtm_FeatureControl_disable << IFX_GTM_CMU_CLK_EN_EN_CLK0_OFF)
					  | ((uint32)IfxGtm_FeatureControl_disable << IFX_GTM_CMU_CLK_EN_EN_CLK1_OFF)
					  | ((uint32)IfxGtm_FeatureControl_disable << IFX_GTM_CMU_CLK_EN_EN_CLK2_OFF)
					  | ((uint32)IfxGtm_FeatureControl_disable << IFX_GTM_CMU_CLK_EN_EN_CLK3_OFF)
					  | ((uint32)IfxGtm_FeatureControl_disable << IFX_GTM_CMU_CLK_EN_EN_CLK4_OFF)
					  | ((uint32)IfxGtm_FeatureControl_disable << IFX_GTM_CMU_CLK_EN_EN_CLK5_OFF)
					  | ((uint32)IfxGtm_FeatureControl_disable << IFX_GTM_CMU_CLK_EN_EN_CLK6_OFF)
					  | ((uint32)IfxGtm_FeatureControl_disable << IFX_GTM_CMU_CLK_EN_EN_CLK7_OFF)
					  | ((uint32)IfxGtm_FeatureControl_disable << IFX_GTM_CMU_CLK_EN_EN_ECLK0_OFF)
					  | ((uint32)IfxGtm_FeatureControl_disable << IFX_GTM_CMU_CLK_EN_EN_ECLK1_OFF)
					  | ((uint32)IfxGtm_FeatureControl_disable << IFX_GTM_CMU_CLK_EN_EN_ECLK2_OFF)
					  | ((uint32)IfxGtm_FeatureControl_disable << IFX_GTM_CMU_CLK_EN_EN_FXCLK_OFF);

    return currentStatus;
}


IFX_INLINE void IfxGtm_Cmu_resumeSuspendedClocks(Ifx_GTM *gtm, IfxGtm_Cmu_EnableStatusOfAllClocks currentStatus)
{
	gtm->CMU.CLK_EN.U = currentStatus.U &
						(((uint32)IfxGtm_FeatureControl_enable << IFX_GTM_CMU_CLK_EN_EN_CLK0_OFF)
						 | ((uint32)IfxGtm_FeatureControl_enable << IFX_GTM_CMU_CLK_EN_EN_CLK1_OFF)
						 | ((uint32)IfxGtm_FeatureControl_enable << IFX_GTM_CMU_CLK_EN_EN_CLK2_OFF)
						 | ((uint32)IfxGtm_FeatureControl_enable << IFX_GTM_CMU_CLK_EN_EN_CLK3_OFF)
						 | ((uint32)IfxGtm_FeatureControl_enable << IFX_GTM_CMU_CLK_EN_EN_CLK4_OFF)
						 | ((uint32)IfxGtm_FeatureControl_enable << IFX_GTM_CMU_CLK_EN_EN_CLK5_OFF)
						 | ((uint32)IfxGtm_FeatureControl_enable << IFX_GTM_CMU_CLK_EN_EN_CLK6_OFF)
						 | ((uint32)IfxGtm_FeatureControl_enable << IFX_GTM_CMU_CLK_EN_EN_CLK7_OFF)
						 | ((uint32)IfxGtm_FeatureControl_enable << IFX_GTM_CMU_CLK_EN_EN_ECLK0_OFF)
						 | ((uint32)IfxGtm_FeatureControl_enable << IFX_GTM_CMU_CLK_EN_EN_ECLK1_OFF)
						 | ((uint32)IfxGtm_FeatureControl_enable << IFX_GTM_CMU_CLK_EN_EN_ECLK2_OFF)
						 | ((uint32)IfxGtm_FeatureControl_enable << IFX_GTM_CMU_CLK_EN_EN_FXCLK_OFF));
}

#endif /* IFXGTM_CMU_H */
