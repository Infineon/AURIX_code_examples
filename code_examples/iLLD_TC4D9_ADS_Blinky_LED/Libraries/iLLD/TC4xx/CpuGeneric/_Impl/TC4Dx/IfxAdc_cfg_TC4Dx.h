/**
 * \file IfxAdc_cfg_TC4Dx.h
 * \brief ADC on-chip implementation data
 * \ingroup IfxLld_Adc
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
 * \defgroup IfxLld_Adc ADC
 * \ingroup IfxLld
 * \defgroup IfxLld_Adc_Impl Implementation
 * \ingroup IfxLld_Adc
 * \defgroup IfxLld_Adc_Std Standard
 * \ingroup IfxLld_Adc
 */

#ifndef IFXADC_CFG_TC4DX_H
#define IFXADC_CFG_TC4DX_H 1

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

/******************************************************************************/
/*-----------------------------------Macros-----------------------------------*/
/******************************************************************************/

/** \brief Number of TMADC Objects
 */
#define IFXADC_NUM_TMADC             (4)

#define IFXADC_NUM_SAR_CORES         (8)

/** \brief Number of CDSP Cores
 */
#define IFXADC_NUM_CDSP_CORES        (2)

/** \brief Number of TMADC Channels
 */
#define IFXADC_NUM_TMADC_CHANNELS    (16)

/** \brief ICCM and DCCM memory offset
 */
#define IFXADC_ICCM_DCCM_OFFSET      (0x2000u)

/** \brief Number of APU in ADC
 */
#define IFXADC_NUM_APU               (16)

/** \brief Maximum timeout in nanoseconds for calibration(3ms) + module power on(15us)
 */
#ifndef IFXADC_TMADC_MAX_TIMEOUT
#define IFXADC_TMADC_MAX_TIMEOUT     ((uint32)(3015000U))
#endif

/** \brief Maximum timeout in nanoseconds for module power on (15us)
 */
#ifndef IFXADC_TMADC_POWERON_TIMEOUT
#define IFXADC_TMADC_POWERON_TIMEOUT ((uint32)(15000U))
#endif

/** \brief Reinitialization of event source
 */
#define IFXADC_CDSP_IS_REINITIALIZATION_EVENT_SRC  (FALSE)

/** \brief Availability of CDSP
 */
#define IFXADC_IS_CDSP_AVAILABLE   (TRUE)

/** \brief Availability of DSADC
 */
#define IFXADC_IS_DSADC_AVAILABLE  (FALSE)

/** \brief Availability of ExMod
 */
#define IFXADC_IS_EXMOD_AVAILABLE  (FALSE)

/** \brief Availability of FCC
 */
#define IFXADC_IS_FCC_AVAILABLE    (FALSE)

/** \brief Availability of Emux Control interface 2 and 3
 */
#define IFXADC_TMADC_IS_EMUX_CI2_CI3_AVAILABLE     (FALSE)

/** \brief Route the ADC boundary flag signals to the output mux for GTM
 */
#define IFXADC_IS_GTM_AVAILABLE	   (FALSE)

/** \brief Route the ADC boundary flag signals to the output mux for EGTM
 */
#define IFXADC_IS_EGTM_AVAILABLE	(TRUE)

/******************************************************************************/
/*-------------------------------Enumerations---------------------------------*/
/******************************************************************************/

/** \brief Enumeration holding the DSP core
 */
typedef enum
{
    IfxAdc_CdspCore_none  = -1, /**< \brief Not Selected */
    IfxAdc_CdspCore_0     = 0,  /**< \brief CdspCore 0 */
    IfxAdc_CdspCore_1     = 1,  /**< \brief CdspCore 1 */
    IfxAdc_CdspCore_count = 2   /**< \brief Count */
} IfxAdc_CdspCore;

/** \brief Enumeration holding TMADC channel numbers
 */
typedef enum
{
    IfxAdc_TmadcChannel_none  = -1, /**< \brief Not Selected */
    IfxAdc_TmadcChannel_0     = 0,  /**< \brief TmadcChannel 0 */
    IfxAdc_TmadcChannel_1     = 1,  /**< \brief TmadcChannel 1 */
    IfxAdc_TmadcChannel_2     = 2,  /**< \brief TmadcChannel 2 */
    IfxAdc_TmadcChannel_3     = 3,  /**< \brief TmadcChannel 3 */
    IfxAdc_TmadcChannel_4     = 4,  /**< \brief TmadcChannel 4 */
    IfxAdc_TmadcChannel_5     = 5,  /**< \brief TmadcChannel 5 */
    IfxAdc_TmadcChannel_6     = 6,  /**< \brief TmadcChannel 6 */
    IfxAdc_TmadcChannel_7     = 7,  /**< \brief TmadcChannel 7 */
    IfxAdc_TmadcChannel_8     = 8,  /**< \brief TmadcChannel 8 */
    IfxAdc_TmadcChannel_9     = 9,  /**< \brief TmadcChannel 9 */
    IfxAdc_TmadcChannel_10    = 10, /**< \brief TmadcChannel 10 */
    IfxAdc_TmadcChannel_11    = 11, /**< \brief TmadcChannel 11 */
    IfxAdc_TmadcChannel_12    = 12, /**< \brief TmadcChannel 12 */
    IfxAdc_TmadcChannel_13    = 13, /**< \brief TmadcChannel 13 */
    IfxAdc_TmadcChannel_14    = 14, /**< \brief TmadcChannel 14 */
    IfxAdc_TmadcChannel_15    = 15, /**< \brief TmadcChannel 15 */
    IfxAdc_TmadcChannel_count = 16  /**< \brief Count */
} IfxAdc_TmadcChannel;

/** \brief Enumeration holding the module numbers of TMADC
 */
typedef enum
{
    IfxAdc_TmadcModule_none  = -1, /**< \brief Not Selected */
    IfxAdc_TmadcModule_0     = 0,  /**< \brief TmadcModule 0 */
    IfxAdc_TmadcModule_1     = 1,  /**< \brief TmadcModule 1 */
    IfxAdc_TmadcModule_2     = 2,  /**< \brief TmadcModule 2 */
    IfxAdc_TmadcModule_3     = 3,  /**< \brief TmadcModule 3 */
    IfxAdc_TmadcModule_count = 4   /**< \brief Count */
} IfxAdc_TmadcModule;

#endif /* IFXADC_CFG_TC4DX_H */
