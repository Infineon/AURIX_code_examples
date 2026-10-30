/**
 * \file IfxGtm_Trig.h
 * \brief GTM TRIG details
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
 * \defgroup IfxLld_Gtm_Trig GTM Trigger Configuration
 * \ingroup IfxLld_Gtm
 * \defgroup IfxLld_Gtm_Trig_Enumerations Enumerations
 * \ingroup IfxLld_Gtm_Trig
 * \defgroup IfxLld_Gtm_Trig_Data_Structures Data Structures
 * \ingroup IfxLld_Gtm_Trig
 * \defgroup IfxLld_Gtm_Trig_Trigger_Functions Trigger Functions
 * \ingroup IfxLld_Gtm_Trig
 */

#ifndef IFXGTM_TRIG_H
#define IFXGTM_TRIG_H 1

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include "Cpu/Std/Ifx_Types.h"
#include "_Impl/IfxGtm_cfg.h"
#include "Gtm/Std/IfxGtm_Tim.h"

/******************************************************************************/
/*--------------------------------Enumerations--------------------------------*/
/******************************************************************************/

/** \addtogroup IfxLld_Gtm_Trig_Enumerations
 * \{ */
/** \brief Enum for ADC group
 */
typedef enum
{
    IfxGtm_Trig_AdcGroup_0,   /**< \brief For ADC group 0  */
    IfxGtm_Trig_AdcGroup_1,   /**< \brief For ADC group 1  */
    IfxGtm_Trig_AdcGroup_2,   /**< \brief For ADC group 2  */
    IfxGtm_Trig_AdcGroup_3,   /**< \brief For ADC group 3  */
    IfxGtm_Trig_AdcGroup_4,   /**< \brief For ADC group 4  */
    IfxGtm_Trig_AdcGroup_5,   /**< \brief For ADC group 5  */
    IfxGtm_Trig_AdcGroup_6,   /**< \brief For ADC group 6  */
    IfxGtm_Trig_AdcGroup_7,   /**< \brief For ADC group 7  */
    IfxGtm_Trig_AdcGroup_8,   /**< \brief For ADC group 8  */
    IfxGtm_Trig_AdcGroup_9,   /**< \brief For ADC group 9  */
    IfxGtm_Trig_AdcGroup_10,  /**< \brief For ADC group 10 */
    IfxGtm_Trig_AdcGroup_11   /**< \brief For ADC group 11 */
} IfxGtm_Trig_AdcGroup;

/** \brief Enum for ADC trigger
 */
typedef enum
{
    IfxGtm_Trig_AdcTrig_0,     /**< \brief For ADC Trig 0 */
    IfxGtm_Trig_AdcTrig_1,     /**< \brief For ADC Trig 1 */
    IfxGtm_Trig_AdcTrig_2,     /**< \brief For ADC Trig 2 */
    IfxGtm_Trig_AdcTrig_3,     /**< \brief For ADC Trig 3 */
    IfxGtm_Trig_AdcTrig_4,     /**< \brief For ADC Trig 4 */
    IfxGtm_Trig_AdcTrig_count  /**< \brief count of the enum definition */
} IfxGtm_Trig_AdcTrig;

/** \brief Enum for ADC trigger channel
 */
typedef enum
{
    IfxGtm_Trig_AdcTrigChannel_3,     /**< \brief For ADC Trig Channel 3  */
    IfxGtm_Trig_AdcTrigChannel_4,     /**< \brief For ADC Trig Channel 4  */
    IfxGtm_Trig_AdcTrigChannel_5,     /**< \brief For ADC Trig Channel 5  */
    IfxGtm_Trig_AdcTrigChannel_6,     /**< \brief For ADC Trig Channel 6  */
    IfxGtm_Trig_AdcTrigChannel_7,     /**< \brief For ADC Trig Channel 7  */
    IfxGtm_Trig_AdcTrigChannel_11,    /**< \brief For ADC Trig Channel 11 */
    IfxGtm_Trig_AdcTrigChannel_12,    /**< \brief For ADC Trig Channel 12 */
    IfxGtm_Trig_AdcTrigChannel_13,    /**< \brief For ADC Trig Channel 13 */
    IfxGtm_Trig_AdcTrigChannel_14,    /**< \brief For ADC Trig Channel 14 */
    IfxGtm_Trig_AdcTrigChannel_15,    /**< \brief For ADC Trig Channel 15 */
    IfxGtm_Trig_AdcTrigChannel_count  /**< \brief count of the enum definition */
} IfxGtm_Trig_AdcTrigChannel;

/** \brief Enum for ADC trigger source
 */
typedef enum
{
    IfxGtm_Trig_AdcTrigSource_atom0,   /**< \brief For ADC Trig Source Atom 0  */
    IfxGtm_Trig_AdcTrigSource_atom1,   /**< \brief For ADC Trig Source Atom 1  */
    IfxGtm_Trig_AdcTrigSource_atom2,   /**< \brief For ADC Trig Source Atom 2  */
    IfxGtm_Trig_AdcTrigSource_atom3,   /**< \brief For ADC Trig Source Atom 3  */
    IfxGtm_Trig_AdcTrigSource_atom4,   /**< \brief For ADC Trig Source Atom 4  */
    IfxGtm_Trig_AdcTrigSource_atom5,   /**< \brief For ADC Trig Source Atom 5  */
    IfxGtm_Trig_AdcTrigSource_atom6,   /**< \brief For ADC Trig Source Atom 6  */
    IfxGtm_Trig_AdcTrigSource_atom7,   /**< \brief For ADC Trig Source Atom 7  */
    IfxGtm_Trig_AdcTrigSource_atom8,   /**< \brief For ADC Trig Source Atom 8  */
    IfxGtm_Trig_AdcTrigSource_atom9,   /**< \brief For ADC Trig Source Atom 9  */
    IfxGtm_Trig_AdcTrigSource_atom10,  /**< \brief For ADC Trig Source Atom 10 */
    IfxGtm_Trig_AdcTrigSource_atom11,  /**< \brief For ADC Trig Source Atom 11 */
    IfxGtm_Trig_AdcTrigSource_tom0,    /**< \brief For ADC Trig Source Tom 0   */
    IfxGtm_Trig_AdcTrigSource_tom1,    /**< \brief For ADC Trig Source Tom 1   */
    IfxGtm_Trig_AdcTrigSource_tom2,    /**< \brief For ADC Trig Source Tom 2   */
    IfxGtm_Trig_AdcTrigSource_tom3,    /**< \brief For ADC Trig Source Tom 3   */
    IfxGtm_Trig_AdcTrigSource_tom4,    /**< \brief For ADC Trig Source Tom 4   */
    IfxGtm_Trig_AdcTrigSource_tom5,    /**< \brief For ADC Trig Source Tom 5   */
    IfxGtm_Trig_AdcTrigSource_count    /**< \brief count of the enum definition */
} IfxGtm_Trig_AdcTrigSource;

/** \brief CAN device enum
 */
typedef enum
{
    IfxGtm_Trig_CanDevice_0,     /**< \brief CAN device 0  */
    IfxGtm_Trig_CanDevice_1,     /**< \brief CAN device 1  */
    IfxGtm_Trig_CanDevice_2,     /**< \brief CAN device 2  */
    IfxGtm_Trig_CanDevice_count  /**< \brief count of the enum definition */
} IfxGtm_Trig_CanDevice;

/** \brief Enum for CAN trigger
 */
typedef enum
{
    IfxGtm_Trig_CanTrig_0,     /**< \brief For CAN Trig 0  */
    IfxGtm_Trig_CanTrig_1,     /**< \brief For CAN Trig 1  */
    IfxGtm_Trig_CanTrig_2,     /**< \brief For CAN Trig 2  */
    IfxGtm_Trig_CanTrig_3,     /**< \brief For CAN Trig 3  */
    IfxGtm_Trig_CanTrig_count  /**< \brief count of the enum definition */
} IfxGtm_Trig_CanTrig;

/** \brief Enum for CAN trigger channel
 */
typedef enum
{
    IfxGtm_Trig_CanTrigChannel_0,     /**< \brief For CAN Trig Channel 0  */
    IfxGtm_Trig_CanTrigChannel_1,     /**< \brief For CAN Trig Channel 1  */
    IfxGtm_Trig_CanTrigChannel_2,     /**< \brief For CAN Trig Channel 2  */
    IfxGtm_Trig_CanTrigChannel_3,     /**< \brief For CAN Trig Channel 3  */
    IfxGtm_Trig_CanTrigChannel_4,     /**< \brief For CAN Trig Channel 4  */
    IfxGtm_Trig_CanTrigChannel_5,     /**< \brief For CAN Trig Channel 5  */
    IfxGtm_Trig_CanTrigChannel_6,     /**< \brief For CAN Trig Channel 6  */
    IfxGtm_Trig_CanTrigChannel_7,     /**< \brief For CAN Trig Channel 7  */
    IfxGtm_Trig_CanTrigChannel_11,    /**< \brief For CAN Trig Channel 11 */
    IfxGtm_Trig_CanTrigChannel_12,    /**< \brief For CAN Trig Channel 12 */
    IfxGtm_Trig_CanTrigChannel_13,    /**< \brief For CAN Trig Channel 13 */
    IfxGtm_Trig_CanTrigChannel_14,    /**< \brief For CAN Trig Channel 15 */
    IfxGtm_Trig_CanTrigChannel_count  /**< \brief count of the enum definition */
} IfxGtm_Trig_CanTrigChannel;

/** \brief Enum for CAN trigger source
 */
typedef enum
{
    IfxGtm_Trig_CanTrigSource_tom0,   /**< \brief For CAN Trig Source Tom 0  */
    IfxGtm_Trig_CanTrigSource_tom1,   /**< \brief For CAN Trig Source Tom 1  */
    IfxGtm_Trig_CanTrigSource_atom0,  /**< \brief For CAN Trig Source Atom 0 */
    IfxGtm_Trig_CanTrigSource_atom1,  /**< \brief For CAN Trig Source Atom 1 */
    IfxGtm_Trig_CanTrigSource_atom2,  /**< \brief For CAN Trig Source Atom 2 */
    IfxGtm_Trig_CanTrigSource_count   /**< \brief count of the enum definition */
} IfxGtm_Trig_CanTrigSource;

/** \brief Enum for EDSADC trigger
 */
#ifndef DEVICE_TC33X
typedef enum
{
    IfxGtm_Trig_EdsadcTrig_0,   /**< \brief For Edsadc Trig 0  */
    IfxGtm_Trig_EdsadcTrig_1,   /**< \brief For Edsadc Trig 1  */
    IfxGtm_Trig_EdsadcTrig_2,   /**< \brief For Edsadc Trig 2  */
    IfxGtm_Trig_EdsadcTrig_3    /**< \brief For Edsadc Trig 3  */
} IfxGtm_Trig_EdsadcTrig;

/** \brief Enum for EDSADC trigger source.
 * Definition in Ifx_GTM_DSADC_OUTSEL0.B.SELx (x = 0 to 7) and Ifx_GTM_DSADC_OUTSEL1.B.SELx (x = 0 to 13)
 */
typedef enum
{
    IfxGtm_Trig_EdsadcTrigSource_tom0_6,    /**< \brief For Edsadc Trig Source Tom0_6   */
    IfxGtm_Trig_EdsadcTrigSource_tom0_7,    /**< \brief For Edsadc Trig Source Tom0_7   */
    IfxGtm_Trig_EdsadcTrigSource_tom0_13,   /**< \brief For Edsadc Trig Source Tom0_13  */
    IfxGtm_Trig_EdsadcTrigSource_tom0_14,   /**< \brief For Edsadc Trig Source Tom0_14  */
    IfxGtm_Trig_EdsadcTrigSource_atom0_4,   /**< \brief For Edsadc Trig Source Atom0_4  */
    IfxGtm_Trig_EdsadcTrigSource_atom0_5,   /**< \brief For Edsadc Trig Source Atom0_5  */
    IfxGtm_Trig_EdsadcTrigSource_atom0_6,   /**< \brief For Edsadc Trig Source Atom0_6  */
    IfxGtm_Trig_EdsadcTrigSource_atom0_7,   /**< \brief For Edsadc Trig Source Atom0_7  */
    IfxGtm_Trig_EdsadcTrigSource_atom1_4,   /**< \brief For Edsadc Trig Source Atom1_4  */
    IfxGtm_Trig_EdsadcTrigSource_atom1_5,   /**< \brief For Edsadc Trig Source Atom1_5  */
    IfxGtm_Trig_EdsadcTrigSource_atom1_6,   /**< \brief For Edsadc Trig Source Atom1_6  */
    IfxGtm_Trig_EdsadcTrigSource_atom1_7,   /**< \brief For Edsadc Trig Source Atom1_7  */
    IfxGtm_Trig_EdsadcTrigSource_atom4_6,   /**< \brief For Edsadc Trig Source Atom4_6  */
    IfxGtm_Trig_EdsadcTrigSource_atom4_7,   /**< \brief For Edsadc Trig Source Atom4_7  */
    IfxGtm_Trig_EdsadcTrigSource_atom6_6,   /**< \brief For Edsadc Trig Source Atom6_6  */
    IfxGtm_Trig_EdsadcTrigSource_reserved0, /**< \brief Reserved 0                      */
    IfxGtm_Trig_EdsadcTrigSource_tom2_6,    /**< \brief For Edsadc Trig Source Tom2_6   */
    IfxGtm_Trig_EdsadcTrigSource_tom2_7,    /**< \brief For Edsadc Trig Source Tom2_7   */
    IfxGtm_Trig_EdsadcTrigSource_tom2_13,   /**< \brief For Edsadc Trig Source Tom2_13  */
    IfxGtm_Trig_EdsadcTrigSource_tom2_14,   /**< \brief For Edsadc Trig Source Tom2_14  */
    IfxGtm_Trig_EdsadcTrigSource_atom2_4,   /**< \brief For Edsadc Trig Source Atom2_4  */
    IfxGtm_Trig_EdsadcTrigSource_atom2_5,   /**< \brief For Edsadc Trig Source Atom2_5  */
    IfxGtm_Trig_EdsadcTrigSource_atom2_6,   /**< \brief For Edsadc Trig Source Atom2_6  */
    IfxGtm_Trig_EdsadcTrigSource_atom2_7,   /**< \brief For Edsadc Trig Source Atom2_7  */
    IfxGtm_Trig_EdsadcTrigSource_atom3_4,   /**< \brief For Edsadc Trig Source Atom3_4  */
    IfxGtm_Trig_EdsadcTrigSource_atom3_5,   /**< \brief For Edsadc Trig Source Atom3_5  */
    IfxGtm_Trig_EdsadcTrigSource_atom3_6,   /**< \brief For Edsadc Trig Source Atom3_6  */
    IfxGtm_Trig_EdsadcTrigSource_atom3_7,   /**< \brief For Edsadc Trig Source Atom3_7  */
    IfxGtm_Trig_EdsadcTrigSource_atom5_6,   /**< \brief For Edsadc Trig Source Atom5_6  */
    IfxGtm_Trig_EdsadcTrigSource_atom5_7,   /**< \brief For Edsadc Trig Source Atom5_7  */
    IfxGtm_Trig_EdsadcTrigSource_atom6_7,   /**< \brief For Edsadc Trig Source Atom6_7  */
    IfxGtm_Trig_EdsadcTrigSource_reserved1, /**< \brief Reserved 1                      */
    IfxGtm_Trig_EdsadcTrigSource_tom1_7,    /**< \brief For Edsadc Trig Source Tom1_7   */
    IfxGtm_Trig_EdsadcTrigSource_tom1_14,   /**< \brief For Edsadc Trig Source Tom1_14  */
    IfxGtm_Trig_EdsadcTrigSource_tom3_7,    /**< \brief For Edsadc Trig Source Tom3_7   */
    IfxGtm_Trig_EdsadcTrigSource_tom3_14,   /**< \brief For Edsadc Trig Source Tom3_14  */
    IfxGtm_Trig_EdsadcTrigSource_tom4_7,    /**< \brief For Edsadc Trig Source Tom4_7   */
    IfxGtm_Trig_EdsadcTrigSource_tom4_14,   /**< \brief For Edsadc Trig Source Tom4_14  */
    IfxGtm_Trig_EdsadcTrigSource_tom5_7,    /**< \brief For Edsadc Trig Source Tom5_7   */
    IfxGtm_Trig_EdsadcTrigSource_tom5_14,   /**< \brief For Edsadc Trig Source Tom5_14  */
    IfxGtm_Trig_EdsadcTrigSource_atom7_6,   /**< \brief For Edsadc Trig Source Atom7_6  */
    IfxGtm_Trig_EdsadcTrigSource_atom7_7,   /**< \brief For Edsadc Trig Source Atom7_7  */
    IfxGtm_Trig_EdsadcTrigSource_atom8_6,   /**< \brief For Edsadc Trig Source Atom8_6  */
    IfxGtm_Trig_EdsadcTrigSource_atom8_7,   /**< \brief For Edsadc Trig Source Atom8_7  */
    IfxGtm_Trig_EdsadcTrigSource_atom9_6,   /**< \brief For Edsadc Trig Source Atom9_6  */
    IfxGtm_Trig_EdsadcTrigSource_atom9_7,   /**< \brief For Edsadc Trig Source Atom9_7  */
    IfxGtm_Trig_EdsadcTrigSource_atom11_6,  /**< \brief For Edsadc Trig Source Atom11_6 */
    IfxGtm_Trig_EdsadcTrigSource_reserved2, /**< \brief Reserved 2                      */
    IfxGtm_Trig_EdsadcTrigSource_tom1_6,    /**< \brief For Edsadc Trig Source Tom1_6   */
    IfxGtm_Trig_EdsadcTrigSource_atom10_6,  /**< \brief For Edsadc Trig Source Atom10_6 */
    IfxGtm_Trig_EdsadcTrigSource_atom10_7,  /**< \brief For Edsadc Trig Source Atom10_7 */
    IfxGtm_Trig_EdsadcTrigSource_atom11_7   /**< \brief For Edsadc Trig Source Atom11_7 */
} IfxGtm_Trig_EdsadcTrigSource;

/** \brief Enum for MSC trigger channel
 */
typedef enum
{
    IfxGtm_Trig_MscTrigChannel_0,	  /**< \brief For Msc Trig Channel 0	   */
    IfxGtm_Trig_MscTrigChannel_1,	  /**< \brief For Msc Trig Channel 1	   */
    IfxGtm_Trig_MscTrigChannel_2,	  /**< \brief For Msc Trig Channel 2	   */
    IfxGtm_Trig_MscTrigChannel_3,	  /**< \brief For Msc Trig Channel 3	   */
    IfxGtm_Trig_MscTrigChannel_4,	  /**< \brief For Msc Trig Channel 4  	   */
    IfxGtm_Trig_MscTrigChannel_5,	  /**< \brief For Msc Trig Channel 5	   */
    IfxGtm_Trig_MscTrigChannel_6,	  /**< \brief For Msc Trig Channel 6 	   */
    IfxGtm_Trig_MscTrigChannel_7,	  /**< \brief For Msc Trig Channel 7	   */
    IfxGtm_Trig_MscTrigChannel_8,	  /**< \brief For Msc Trig Channel 8	   */
    IfxGtm_Trig_MscTrigChannel_9,	  /**< \brief For Msc Trig Channel 9 	   */
    IfxGtm_Trig_MscTrigChannel_10,	  /**< \brief For Msc Trig Channel 10 	   */
    IfxGtm_Trig_MscTrigChannel_11,	  /**< \brief For Msc Trig Channel 11      */
    IfxGtm_Trig_MscTrigChannel_12,	  /**< \brief For Msc Trig Channel 12      */
    IfxGtm_Trig_MscTrigChannel_13,	  /**< \brief For Msc Trig Channel 13      */
    IfxGtm_Trig_MscTrigChannel_14,	  /**< \brief For Msc Trig Channel 14      */
    IfxGtm_Trig_MscTrigChannel_15,	  /**< \brief For Msc Trig Channel 15      */
    IfxGtm_Trig_MscTrigChannel_count  /**< \brief count of the enum definition */
} IfxGtm_Trig_MscTrigChannel;

/** \brief Enum for MSC trigger Input Type
 */
typedef enum
{
    IfxGtm_Trig_MscTrigInput_low,		    /**< \brief For Msc Trig Input type Low          */
    IfxGtm_Trig_MscTrigInput_lowExtended, 	/**< \brief For Msc Trig Input type Low extended */
    IfxGtm_Trig_MscTrigInput_high		    /**< \brief For Msc Trig Input type High         */
} IfxGtm_Trig_MscTrigInput;

/** \brief Enum for MSC trigger output select.
 * Definition in Ifx_GTM_MSC_MSCQ[i]_INLCON.B.SELx, Ifx_GTM_MSC_MSCQ[i]_INHCON.B.SELx and Ifx_GTM_MSC_MSCQ[i]_INLEXTCON.B.SELx (i = 0 to 3 , x = 0 to 15)
 */
typedef enum
{
    IfxGtm_Trig_MscTrigOutput_0,  /**< \brief For MSC Trig Output 0 */
    IfxGtm_Trig_MscTrigOutput_1,  /**< \brief For MSC Trig Output 1 */
    IfxGtm_Trig_MscTrigOutput_2,  /**< \brief For MSC Trig Output 2 */
    IfxGtm_Trig_MscTrigOutput_3   /**< \brief For MSC Trig Output 3 */
} IfxGtm_Trig_MscTrigOutput;

/** \brief Enum for MSC Sets
 */
typedef enum
{
    IfxGtm_Trig_MscTrigSet_1,     /**< \brief For MSC set 1  */
    IfxGtm_Trig_MscTrigSet_2,     /**< \brief For MSC set 2  */
    IfxGtm_Trig_MscTrigSet_3,     /**< \brief For MSC set 3  */
    IfxGtm_Trig_MscTrigSet_4,     /**< \brief For MSC set 4  */
    IfxGtm_Trig_MscTrigSet_5,     /**< \brief For MSC set 5  */
    IfxGtm_Trig_MscTrigSet_6,     /**< \brief For MSC set 6  */
    IfxGtm_Trig_MscTrigSet_7,     /**< \brief For MSC set 7  */
    IfxGtm_Trig_MscTrigSet_8,     /**< \brief For MSC set 8  */
    IfxGtm_Trig_MscTrigSet_9,     /**< \brief For MSC set 9  */
    IfxGtm_Trig_MscTrigSet_count  /**< \brief count of the enum definition */
} IfxGtm_Trig_MscTrigSet;

/** \brief Enum for MSC Signal
 */
typedef enum
{
    IfxGtm_Trig_MscTrigSignal_0,     /**< \brief For MSC Trig Signal 0  */
    IfxGtm_Trig_MscTrigSignal_1,     /**< \brief For MSC Trig Signal 1  */
    IfxGtm_Trig_MscTrigSignal_2,     /**< \brief For MSC Trig Signal 2  */
    IfxGtm_Trig_MscTrigSignal_3,     /**< \brief For MSC Trig Signal 3  */
    IfxGtm_Trig_MscTrigSignal_4,     /**< \brief For MSC Trig Signal 4  */
    IfxGtm_Trig_MscTrigSignal_5,     /**< \brief For MSC Trig Signal 5  */
    IfxGtm_Trig_MscTrigSignal_6,     /**< \brief For MSC Trig Signal 6  */
    IfxGtm_Trig_MscTrigSignal_7,     /**< \brief For MSC Trig Signal 7  */
    IfxGtm_Trig_MscTrigSignal_8,     /**< \brief For MSC Trig Signal 8  */
    IfxGtm_Trig_MscTrigSignal_9,     /**< \brief For MSC Trig Signal 9  */
    IfxGtm_Trig_MscTrigSignal_10,    /**< \brief For MSC Trig Signal 10  */
    IfxGtm_Trig_MscTrigSignal_11,    /**< \brief For MSC Trig Signal 11  */
    IfxGtm_Trig_MscTrigSignal_12,    /**< \brief For MSC Trig Signal 12  */
    IfxGtm_Trig_MscTrigSignal_13,    /**< \brief For MSC Trig Signal 13  */
    IfxGtm_Trig_MscTrigSignal_14,    /**< \brief For MSC Trig Signal 14  */
    IfxGtm_Trig_MscTrigSignal_15     /**< \brief For MSC Trig Signal 15  */
} IfxGtm_Trig_MscTrigSignal;

/** \brief Enum for MSC trigger source
 */
typedef enum
{
    IfxGtm_Trig_MscTrigSource_tom0,    /**< \brief For MSC Trig Source Tom 0    */
    IfxGtm_Trig_MscTrigSource_tom1,    /**< \brief For MSC Trig Source Tom 1    */
    IfxGtm_Trig_MscTrigSource_tom2,    /**< \brief For MSC Trig Source Tom 2    */
    IfxGtm_Trig_MscTrigSource_tom3,    /**< \brief For MSC Trig Source Tom 3    */
    IfxGtm_Trig_MscTrigSource_tom4,    /**< \brief For MSC Trig Source Tom 4    */
    IfxGtm_Trig_MscTrigSource_tom5,    /**< \brief For MSC Trig Source Tom 5    */
    IfxGtm_Trig_MscTrigSource_atom0,   /**< \brief For MSC Trig Source Atom 0   */
    IfxGtm_Trig_MscTrigSource_atom1,   /**< \brief For MSC Trig Source Atom 1   */
    IfxGtm_Trig_MscTrigSource_atom2,   /**< \brief For MSC Trig Source Atom 2   */
    IfxGtm_Trig_MscTrigSource_atom3,   /**< \brief For MSC Trig Source Atom 3   */
    IfxGtm_Trig_MscTrigSource_atom4,   /**< \brief For MSC Trig Source Atom 4   */
    IfxGtm_Trig_MscTrigSource_atom5,   /**< \brief For MSC Trig Source Atom 5   */
    IfxGtm_Trig_MscTrigSource_atom6,   /**< \brief For MSC Trig Source Atom 6   */
    IfxGtm_Trig_MscTrigSource_atom7,   /**< \brief For MSC Trig Source Atom 7   */
    IfxGtm_Trig_MscTrigSource_atom8,   /**< \brief For MSC Trig Source Atom 8   */
    IfxGtm_Trig_MscTrigSource_atom9,   /**< \brief For MSC Trig Source Atom 9   */
    IfxGtm_Trig_MscTrigSource_atom10,  /**< \brief For MSC Trig Source Atom 10  */
    IfxGtm_Trig_MscTrigSource_atom11,  /**< \brief For MSC Trig Source Atom 11  */
    IfxGtm_Trig_MscTrigSource_count    /**< \brief count of the enum definition */
} IfxGtm_Trig_MscTrigSource;

/** \brief Enum for PSI5 trigger source.
 * Definition in Ifx_GTM_PSI5OUTSEL.B.SELx (x = 0 to 5)
 */
typedef enum
{
    IfxGtm_Trig_Psi5TrigSource_no_Trigger, /**< \brief No Trigger                   */
    IfxGtm_Trig_Psi5TrigSource_tom2_6,     /**< \brief For Psi5 Trig Source Tom2_6  */
    IfxGtm_Trig_Psi5TrigSource_tom2_7,     /**< \brief For Psi5 Trig Source Tom2_7  */
    IfxGtm_Trig_Psi5TrigSource_tom2_13,    /**< \brief For Psi5 Trig Source Tom2_13 */
    IfxGtm_Trig_Psi5TrigSource_tom2_14,    /**< \brief For Psi5 Trig Source Tom2_14 */
    IfxGtm_Trig_Psi5TrigSource_atom2_4,    /**< \brief For Psi5 Trig Source Atom2_4 */
    IfxGtm_Trig_Psi5TrigSource_atom2_5,    /**< \brief For Psi5 Trig Source Atom2_5 */
    IfxGtm_Trig_Psi5TrigSource_atom2_6,    /**< \brief For Psi5 Trig Source Atom2_6 */
    IfxGtm_Trig_Psi5TrigSource_atom2_7,    /**< \brief For Psi5 Trig Source Atom2_7 */
    IfxGtm_Trig_Psi5TrigSource_tom0_6,     /**< \brief For Psi5 Trig Source Tom0_6  */
    IfxGtm_Trig_Psi5TrigSource_tom0_7,     /**< \brief For Psi5 Trig Source Tom0_7  */
    IfxGtm_Trig_Psi5TrigSource_tom0_13,    /**< \brief For Psi5 Trig Source Tom0_13 */
    IfxGtm_Trig_Psi5TrigSource_tom0_14     /**< \brief For Psi5 Trig Source Tom0_14 */
} IfxGtm_Trig_Psi5TrigSource;

/** \brief Enum for PSI5S trigger source.
 * Definition in Ifx_GTM_PSI5SOUTSEL.B.SELx (x = 0 to 7)
 */
typedef enum
{
    IfxGtm_Trig_Psi5sTrigSource_no_Trigger, /**< \brief No Trigger                    */
    IfxGtm_Trig_Psi5sTrigSource_tomX_6,     /**< \brief For Psi5s Trig Source TomX_6  */
    IfxGtm_Trig_Psi5sTrigSource_tomX_7,     /**< \brief For Psi5s Trig Source TomX_7  */
    IfxGtm_Trig_Psi5sTrigSource_tomX_13,    /**< \brief For Psi5s Trig Source TomX_13 */
    IfxGtm_Trig_Psi5sTrigSource_tomX_14,    /**< \brief For Psi5s Trig Source TomX_14 */
    IfxGtm_Trig_Psi5sTrigSource_atomX_4,    /**< \brief For Psi5s Trig Source AtomX_4 */
    IfxGtm_Trig_Psi5sTrigSource_atomX_5,    /**< \brief For Psi5s Trig Source AtomX_5 */
    IfxGtm_Trig_Psi5sTrigSource_atomX_6,    /**< \brief For Psi5s Trig Source AtomX_6 */
    IfxGtm_Trig_Psi5sTrigSource_atomX_7     /**< \brief For Psi5s Trig Source AtomX_7 */
} IfxGtm_Trig_Psi5sTrigSource;
#endif /*#ifndef DEVICE_TC33X*/

/** \brief Enum for SENT group
 */
typedef enum
{
    IfxGtm_Trig_SentGroup_0,    /**< \brief For SENT group 0  */
    IfxGtm_Trig_SentGroup_1,    /**< \brief For SENT group 1  */
    IfxGtm_Trig_SentGroup_2,    /**< \brief For SENT group 2  */
    IfxGtm_Trig_SentGroup_3,    /**< \brief For SENT group 3  */
    IfxGtm_Trig_SentGroup_4,    /**< \brief For SENT group 4  */
    IfxGtm_Trig_SentGroup_5,    /**< \brief For SENT group 5  */
    IfxGtm_Trig_SentGroup_6,    /**< \brief For SENT group 6  */
    IfxGtm_Trig_SentGroup_7,    /**< \brief For SENT group 7  */
    IfxGtm_Trig_SentGroup_8,    /**< \brief For SENT group 8  */
    IfxGtm_Trig_SentGroup_9,    /**< \brief For SENT group 9  */
    IfxGtm_Trig_SentGroup_10,   /**< \brief For SENT group 10 */
    IfxGtm_Trig_SentGroup_11,   /**< \brief For SENT group 11 */
    IfxGtm_Trig_SentGroup_12,   /**< \brief For SENT group 12 */
    IfxGtm_Trig_SentGroup_13,   /**< \brief For SENT group 13 */
    IfxGtm_Trig_SentGroup_14,   /**< \brief For SENT group 14 */
    IfxGtm_Trig_SentGroup_15    /**< \brief For SENT group 15 */
} IfxGtm_Trig_SentGroup;

/** \brief Enum for SENT trigger
 */
typedef enum
{
    IfxGtm_Trig_SentTrig_0,     /**< \brief SENT trigger 0 */
    IfxGtm_Trig_SentTrig_1,     /**< \brief SENT trigger 1 */
    IfxGtm_Trig_SentTrig_2,     /**< \brief SENT trigger 2 */
    IfxGtm_Trig_SentTrig_3      /**< \brief SENT trigger 3 */
} IfxGtm_Trig_SentTrig;

/** \brief Enum for SENT trigger channel
 */
typedef enum
{
    IfxGtm_Trig_SentTrigChannel_3,     /**< \brief For SENT Trig Channel 3	    */
    IfxGtm_Trig_SentTrigChannel_4,     /**< \brief For SENT Trig Channel 4	    */
    IfxGtm_Trig_SentTrigChannel_5,     /**< \brief For SENT Trig Channel 5	    */
    IfxGtm_Trig_SentTrigChannel_6,     /**< \brief For SENT Trig Channel 6	    */
    IfxGtm_Trig_SentTrigChannel_7,     /**< \brief For SENT Trig Channel 7	    */
    IfxGtm_Trig_SentTrigChannel_11,    /**< \brief For SENT Trig Channel 11	    */
    IfxGtm_Trig_SentTrigChannel_12,    /**< \brief For SENT Trig Channel 12	    */
    IfxGtm_Trig_SentTrigChannel_13,    /**< \brief For SENT Trig Channel 13	    */
    IfxGtm_Trig_SentTrigChannel_14,    /**< \brief For SENT Trig Channel 14	    */
    IfxGtm_Trig_SentTrigChannel_15,    /**< \brief For SENT Trig Channel 15	    */
    IfxGtm_Trig_SentTrigChannel_count  /**< \brief count of the enum definition */
} IfxGtm_Trig_SentTrigChannel;

/** \brief Enum for SENT trigger source
 */
typedef enum
{
    IfxGtm_Trig_SentTrigSource_atom0,   /**< \brief For SENT Trig Source Atom 0  */
    IfxGtm_Trig_SentTrigSource_atom1,   /**< \brief For SENT Trig Source Atom 1  */
    IfxGtm_Trig_SentTrigSource_atom2,   /**< \brief For SENT Trig Source Atom 2  */
    IfxGtm_Trig_SentTrigSource_atom3,   /**< \brief For SENT Trig Source Atom 3  */
    IfxGtm_Trig_SentTrigSource_atom4,   /**< \brief For SENT Trig Source Atom 4  */
    IfxGtm_Trig_SentTrigSource_atom5,   /**< \brief For SENT Trig Source Atom 5  */
    IfxGtm_Trig_SentTrigSource_atom6,   /**< \brief For SENT Trig Source Atom 6  */
    IfxGtm_Trig_SentTrigSource_atom7,   /**< \brief For SENT Trig Source Atom 7  */
    IfxGtm_Trig_SentTrigSource_atom8,   /**< \brief For SENT Trig Source Atom 8  */
    IfxGtm_Trig_SentTrigSource_atom9,   /**< \brief For SENT Trig Source Atom 9  */
    IfxGtm_Trig_SentTrigSource_atom10,  /**< \brief For SENT Trig Source Atom 10 */
    IfxGtm_Trig_SentTrigSource_atom11,  /**< \brief For SENT Trig Source Atom 11 */
    IfxGtm_Trig_SentTrigSource_tom0,    /**< \brief For SENT Trig Source Tom 0   */
    IfxGtm_Trig_SentTrigSource_tom1,    /**< \brief For SENT Trig Source Tom 1   */
    IfxGtm_Trig_SentTrigSource_tom2,    /**< \brief For SENT Trig Source Tom 2   */
    IfxGtm_Trig_SentTrigSource_tom3,    /**< \brief For SENT Trig Source Tom 3   */
    IfxGtm_Trig_SentTrigSource_tom4,    /**< \brief For SENT Trig Source Tom 4   */
    IfxGtm_Trig_SentTrigSource_tom5,    /**< \brief For SENT Trig Source Tom 5   */
    IfxGtm_Trig_SentTrigSource_count    /**< \brief count of the enum definition */
} IfxGtm_Trig_SentTrigSource;

/** \} */

/******************************************************************************/
/*-----------------------------Data Structures--------------------------------*/
/******************************************************************************/

/** \brief MSC Trigger Configuration
 */
#ifndef DEVICE_TC33X
typedef struct
{
    IfxGtm_Trig_MscTrigSignal  signal;        /**< \brief MSC Signal */
    IfxGtm_Trig_MscTrigSet     mscSet;        /**< \brief MSC Set */
    IfxGtm_Trig_MscTrigSource  source;        /**< \brief Trigger Source */
    IfxGtm_Trig_MscTrigChannel channel;       /**< \brief MSC Channel */
} IfxGtm_Trig_MscOut;
#endif /*#ifndef DEVICE_TC33X*/
/** \addtogroup IfxLld_Gtm_Trig_Trigger_Functions
 * \{ */

/******************************************************************************/
/*-------------------------Global Function Prototypes-------------------------*/
/******************************************************************************/

#ifndef DEVICE_TC33X
/**
 * \brief Configures the GTM module to trigger a TIM channel from an EDSADC channel.
 *
 * \param[inout] gtm           Pointer to the GTM module instance.
 * \param[in]    edsadcChannel EDSADC channel to use as the trigger source. Range: 2 to 13.
 * \param[in]    tim           TIM object within the GTM to trigger. Range: \ref IfxGtm_Tim
 * \param[in]    timChannel    TIM channel to trigger. Range: \ref IfxGtm_Tim_Ch
 *
 * \retval TRUE If the configuration was successful.
 *         FALSE If the configuration failed.
 */
IFX_EXTERN boolean IfxGtm_Trig_fromEdsadc(Ifx_GTM *gtm, uint32 edsadcChannel, IfxGtm_Tim tim, IfxGtm_Tim_Ch timChannel);

/**
 * \brief Configures the GTM MSC trigger source, input type, output select, and signal.
 *
 * \param[inout] gtm    Pointer to the GTM module instance.
 * \param[in]    msc    MSC ID to configure. Range: 0 to 3.
 * \param[in]    input  MSC trigger input type. Range: \ref IfxGtm_Trig_MscTrigInput
 * \param[in]    output MSC trigger output select. Range: \ref IfxGtm_Trig_MscTrigOutput
 * \param[in]    signal MSC trigger signal. Range: \ref IfxGtm_Trig_MscTrigSignal
 *
 * \retval TRUE Configuration was successful.
 *         FALSE Configuration failed.
 */
IFX_EXTERN boolean IfxGtm_Trig_fromMsc(Ifx_GTM *gtm, uint32 msc, IfxGtm_Trig_MscTrigInput input, IfxGtm_Trig_MscTrigOutput output, IfxGtm_Trig_MscTrigSignal signal);
#endif

/**
 * \brief Configures the GTM module to trigger a CAN module.
 *
 * This function sets up the GTM module to generate a trigger for a CAN device based on the specified parameters.
 *
 * \param[inout] gtm       Pointer to the GTM module instance.
 * \param[in]    canTrig   CAN trigger configuration. Range: \ref IfxGtm_Trig_CanTrig
 * \param[in]    canDevice CAN device identifier. Range: \ref IfxGtm_Trig_CanDevice
 * \param[in]    source    CAN Trigger source. Range: \ref IfxGtm_Trig_CanTrigSource
 * \param[in]    channel   CAN Trigger channel. Range: \ref IfxGtm_Trig_CanTrigChannel
 *
 * \retval TRUE The configuration was successful.
 *         FALSE The configuration failed.
 */
IFX_EXTERN boolean IfxGtm_Trig_toCan(Ifx_GTM *gtm, IfxGtm_Trig_CanTrig canTrig, IfxGtm_Trig_CanDevice canDevice, IfxGtm_Trig_CanTrigSource source, IfxGtm_Trig_CanTrigChannel channel);

/**
 * \brief Configures the GTM module to trigger an ADC conversion.
 *
 * This function sets up the GTM module to generate a trigger signal for an ADC
 * conversion based on the specified ADC group, trigger, source, and channel.
 *
 * \param[inout] gtm      Pointer to the GTM module instance.
 * \param[in]    adcGroup ADC group to be used for triggering. Range: \ref IfxGtm_Trig_AdcGroup
 * \param[in]    adcTrig  ADC trigger to be configured. Range: \ref IfxGtm_Trig_AdcTrig
 * \param[in]    source   ADC trigger source to be used. Range: \ref IfxGtm_Trig_AdcTrigSource
 * \param[in]    channel  ADC trigger channel to be used. Range: \ref IfxGtm_Trig_AdcTrigChannel
 *
 * \retval TRUE If the configuration was successful.
 *         FALSE If the configuration failed.
 */
IFX_EXTERN boolean IfxGtm_Trig_toEVadc(Ifx_GTM *gtm, IfxGtm_Trig_AdcGroup adcGroup, IfxGtm_Trig_AdcTrig adcTrig, IfxGtm_Trig_AdcTrigSource source, IfxGtm_Trig_AdcTrigChannel channel);

/**
 * \brief Clears the EVADC trigger configuration for a specified ADC group and trigger.
 *
 * This function clears the configuration for the specified ADC group and trigger within the GTM module.
 *
 * \param[inout] gtm      Pointer to the GTM module instance.
 * \param[in]    adcGroup ADC group to be cleared. Range: \ref IfxGtm_Trig_AdcGroup
 * \param[in]    adcTrig  ADC trigger to be cleared. Range: \ref IfxGtm_Trig_AdcTrig
 *
 * \retval None
 */
IFX_EXTERN void IfxGtm_Trig_toEVadcClear(Ifx_GTM *gtm, IfxGtm_Trig_AdcGroup adcGroup, IfxGtm_Trig_AdcTrig adcTrig);

#ifndef DEVICE_TC33X
/**
 * \brief Configures the EDSADC trigger source for the specified channel.
 *
 * This function sets up the trigger source for the EDSADC channel specified by edsadcChannel.
 * It associates the trigger with a specific source and trigger type.
 *
 * \param[inout] gtm           Pointer to the GTM module instance.
 * \param[in]    edsadcChannel The EDSADC channel number to configure.
 * \param[in] 	 edsadcTrig    The trigger type for the EDSADC channel. Range: \ref IfxGtm_Trig_EdsadcTrig
 * \param[in] 	 sel 		   The trigger source selection. Range: \ref IfxGtm_Trig_EdsadcTrigSource
 *
 * \retval None
 */
IFX_EXTERN void IfxGtm_Trig_toEdsadc(Ifx_GTM *gtm, uint32 edsadcChannel, IfxGtm_Trig_EdsadcTrig edsadcTrig, IfxGtm_Trig_EdsadcTrigSource sel);

/**
 * \brief Configures the MSC trigger.
 *
 * \param[inout] gtm     Pointer to the GTM module instance.
 * \param[in]    signal  MSC trigger signal. Range: \ref IfxGtm_Trig_MscTrigSignal
 * \param[in]    mscSet  MSC set. Range: \ref IfxGtm_Trig_MscTrigSet
 * \param[in]    source  MSC trigger source. Range: \ref IfxGtm_Trig_MscTrigSource
 * \param[in]    channel MSC trigger channel. Range: \ref IfxGtm_Trig_MscTrigChannel
 *
 * \retval TRUE If the Configuration was successful.
 *         FALSE If the Configuration failed.
 */
IFX_EXTERN boolean IfxGtm_Trig_toMsc(Ifx_GTM *gtm, IfxGtm_Trig_MscTrigSignal signal, IfxGtm_Trig_MscTrigSet mscSet, IfxGtm_Trig_MscTrigSource source, IfxGtm_Trig_MscTrigChannel channel);

/**
 * \brief Configures the PSI5 trigger source for the specified channel in the GTM module.
 *
 * \param[inout] gtm         Pointer to the GTM module instance.
 * \param[in]    psi5Channel The PSI5 channel to configure. 
 * \param[in]    sel 		 The trigger source selection for the PSI5 channel. Range: \ref IfxGtm_Trig_Psi5TrigSource
 *
 * \retval None
 */
IFX_EXTERN void IfxGtm_Trig_toPsi5(Ifx_GTM *gtm, uint32 psi5Channel, IfxGtm_Trig_Psi5TrigSource sel);

/**
 * \brief Configures the PSI5S trigger source for the specified channel in the GTM module.
 *
 * \param[inout] gtm          Pointer to the GTM module instance.
 * \param[in]    psi5sChannel PSI5S channel number to configure.
 * \param[in]    sel          Trigger source selection for the PSI5S channel. Range: \ref IfxGtm_Trig_Psi5sTrigSource
 *
 * \retval None
 */
IFX_EXTERN void IfxGtm_Trig_toPsi5s(Ifx_GTM *gtm, uint32 psi5sChannel, IfxGtm_Trig_Psi5sTrigSource sel);
#endif /*#ifndef DEVICE_TC33X*/

/**
 * \brief Configures the SENT trigger in the GTM module.
 *
 * \param[inout] gtm       Pointer to the GTM module instance.
 * \param[in] 	 sentGroup SENT group to be configured. Range: \ref IfxGtm_Trig_SentGroup
 * \param[in] 	 sentTrig  SENT trigger to be configured. Range: \ref IfxGtm_Trig_SentTrig
 * \param[in]	 source    SENT trigger source to be used. Range: \ref IfxGtm_Trig_SentTrigSource
 * \param[in]	 channel   SENT trigger channel to be used. Range: \ref IfxGtm_Trig_SentTrigChannel
 *
 * \retval TRUE If the configuration was successful.
 *         FALSE If the configuration failed.
 */
IFX_EXTERN boolean IfxGtm_Trig_toSent(Ifx_GTM *gtm, IfxGtm_Trig_SentGroup sentGroup, IfxGtm_Trig_SentTrig sentTrig, IfxGtm_Trig_SentTrigSource source, IfxGtm_Trig_SentTrigChannel channel);

/** \} */

#endif /* IFXGTM_TRIG_H */
