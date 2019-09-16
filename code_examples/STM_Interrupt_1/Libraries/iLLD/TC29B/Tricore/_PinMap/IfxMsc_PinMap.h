/**
 * \file IfxMsc_PinMap.h
 * \brief MSC I/O map
 * \ingroup IfxLld_Msc
 *
 * \version iLLD_1_0_1_9_0
 * \copyright Copyright (c) 2013 Infineon Technologies AG. All rights reserved.
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
 * \defgroup IfxLld_Msc_pinmap MSC Pin Mapping
 * \ingroup IfxLld_Msc
 */

#ifndef IFXMSC_PINMAP_H
#define IFXMSC_PINMAP_H

#include <IfxMsc_reg.h>
#include <_Impl/IfxMsc_cfg.h>
#include <Port/Std/IfxPort.h>

/** \addtogroup IfxLld_Msc_pinmap
 * \{ */

/** \brief INJ pin mapping structure */
typedef const struct
{
    Ifx_MSC*          module;   /**< \brief Base address */
    IfxPort_Pin       pin;      /**< \brief Port pin */
    Ifx_RxSel         select;   /**< \brief Input multiplexer value */
} IfxMsc_Inj_In;

/** \brief SDI pin mapping structure */
typedef const struct
{
    Ifx_MSC*          module;   /**< \brief Base address */
    IfxPort_Pin       pin;      /**< \brief Port pin */
    Ifx_RxSel         select;   /**< \brief Input multiplexer value */
} IfxMsc_Sdi_In;

/** \brief EN pin mapping structure */
typedef const struct
{
    Ifx_MSC*          module;   /**< \brief Base address */
    uint8             target;   /**< \brief Target ID */
    IfxPort_Pin       pin;      /**< \brief Port pin */
    IfxPort_OutputIdx select;   /**< \brief Port control code */
} IfxMsc_En_Out;

/** \brief FCLP pin mapping structure */
typedef const struct
{
    Ifx_MSC*          module;   /**< \brief Base address */
    IfxPort_Pin       pin;      /**< \brief Port pin */
    IfxPort_OutputIdx select;   /**< \brief Port control code */
} IfxMsc_Fclp_Out;

/** \brief FCLN pin mapping structure */
typedef const struct
{
    Ifx_MSC*          module;   /**< \brief Base address */
    IfxPort_Pin       pin;      /**< \brief Port pin */
    IfxPort_OutputIdx select;   /**< \brief Port control code */
} IfxMsc_Fcln_Out;

/** \brief SOP pin mapping structure */
typedef const struct
{
    Ifx_MSC*          module;   /**< \brief Base address */
    IfxPort_Pin       pin;      /**< \brief Port pin */
    IfxPort_OutputIdx select;   /**< \brief Port control code */
} IfxMsc_Sop_Out;

/** \brief SON pin mapping structure */
typedef const struct
{
    Ifx_MSC*          module;   /**< \brief Base address */
    IfxPort_Pin       pin;      /**< \brief Port pin */
    IfxPort_OutputIdx select;   /**< \brief Port control code */
} IfxMsc_Son_Out;

IFX_EXTERN IfxMsc_En_Out IfxMsc0_EN0_P10_2_OUT;  /**< \brief MSC0_EN0: MSC0 output */
IFX_EXTERN IfxMsc_En_Out IfxMsc0_EN0_P10_3_OUT;  /**< \brief MSC0_EN0: MSC0 output */
IFX_EXTERN IfxMsc_En_Out IfxMsc0_EN0_P10_4_OUT;  /**< \brief MSC0_EN0: MSC0 output */
IFX_EXTERN IfxMsc_En_Out IfxMsc0_EN0_P11_11_OUT;  /**< \brief MSC0_EN0: MSC0 output */
IFX_EXTERN IfxMsc_En_Out IfxMsc0_EN0_P14_10_OUT;  /**< \brief MSC0_EN0: MSC0 output */
IFX_EXTERN IfxMsc_En_Out IfxMsc0_EN0_P15_5_OUT;  /**< \brief MSC0_EN0: MSC0 output */
IFX_EXTERN IfxMsc_En_Out IfxMsc0_EN1_P10_1_OUT;  /**< \brief MSC0_EN1: MSC0 output */
IFX_EXTERN IfxMsc_En_Out IfxMsc0_EN1_P11_2_OUT;  /**< \brief MSC0_EN1: MSC0 output */
IFX_EXTERN IfxMsc_En_Out IfxMsc0_EN1_P13_0_OUT;  /**< \brief MSC0_EN1: MSC0 output */
IFX_EXTERN IfxMsc_En_Out IfxMsc0_EN1_P14_9_OUT;  /**< \brief MSC0_EN1: MSC0 output */
IFX_EXTERN IfxMsc_En_Out IfxMsc0_EN1_P15_3_OUT;  /**< \brief MSC0_EN1: MSC0 output */
IFX_EXTERN IfxMsc_En_Out IfxMsc0_END2_P10_2_OUT;  /**< \brief MSC0_END2: MSC0 output */
IFX_EXTERN IfxMsc_En_Out IfxMsc0_END2_P10_3_OUT;  /**< \brief MSC0_END2: MSC0 output */
IFX_EXTERN IfxMsc_En_Out IfxMsc0_END2_P10_4_OUT;  /**< \brief MSC0_END2: MSC0 output */
IFX_EXTERN IfxMsc_En_Out IfxMsc0_END2_P11_11_OUT;  /**< \brief MSC0_END2: MSC0 output */
IFX_EXTERN IfxMsc_En_Out IfxMsc0_END2_P14_10_OUT;  /**< \brief MSC0_END2: MSC0 output */
IFX_EXTERN IfxMsc_En_Out IfxMsc0_END2_P15_5_OUT;  /**< \brief MSC0_END2: MSC0 output */
IFX_EXTERN IfxMsc_En_Out IfxMsc0_END3_P10_1_OUT;  /**< \brief MSC0_END3: MSC0 output */
IFX_EXTERN IfxMsc_En_Out IfxMsc0_END3_P11_2_OUT;  /**< \brief MSC0_END3: MSC0 output */
IFX_EXTERN IfxMsc_En_Out IfxMsc0_END3_P13_0_OUT;  /**< \brief MSC0_END3: MSC0 output */
IFX_EXTERN IfxMsc_En_Out IfxMsc0_END3_P14_9_OUT;  /**< \brief MSC0_END3: MSC0 output */
IFX_EXTERN IfxMsc_En_Out IfxMsc0_END3_P15_3_OUT;  /**< \brief MSC0_END3: MSC0 output */
IFX_EXTERN IfxMsc_En_Out IfxMsc1_EN0_P23_4_OUT;  /**< \brief MSC1_EN0: MSC1 output */
IFX_EXTERN IfxMsc_En_Out IfxMsc1_EN0_P32_4_OUT;  /**< \brief MSC1_EN0: MSC1 output */
IFX_EXTERN IfxMsc_En_Out IfxMsc1_EN1_P23_5_OUT;  /**< \brief MSC1_EN1: MSC1 output */
IFX_EXTERN IfxMsc_En_Out IfxMsc1_END2_P23_4_OUT;  /**< \brief MSC1_END2: MSC1 output */
IFX_EXTERN IfxMsc_En_Out IfxMsc1_END2_P32_4_OUT;  /**< \brief MSC1_END2: MSC1 output */
IFX_EXTERN IfxMsc_En_Out IfxMsc1_END3_P23_5_OUT;  /**< \brief MSC1_END3: MSC1 output */
IFX_EXTERN IfxMsc_En_Out IfxMsc2_EN0_P13_4_OUT;  /**< \brief MSC2_EN0: MSC2 output */
IFX_EXTERN IfxMsc_En_Out IfxMsc2_EN0_P14_14_OUT;  /**< \brief MSC2_EN0: MSC2 output */
IFX_EXTERN IfxMsc_En_Out IfxMsc2_EN1_P14_13_OUT;  /**< \brief MSC2_EN1: MSC2 output */
IFX_EXTERN IfxMsc_En_Out IfxMsc2_EN2_P14_11_OUT;  /**< \brief MSC2_EN2: MSC2 output */
IFX_EXTERN IfxMsc_En_Out IfxMsc2_END0_P14_11_OUT;  /**< \brief MSC2_END0: MSC2 output */
IFX_EXTERN IfxMsc_En_Out IfxMsc2_END2_P13_4_OUT;  /**< \brief MSC2_END2: MSC2 output */
IFX_EXTERN IfxMsc_En_Out IfxMsc2_END2_P14_14_OUT;  /**< \brief MSC2_END2: MSC2 output */
IFX_EXTERN IfxMsc_En_Out IfxMsc2_END3_P14_13_OUT;  /**< \brief MSC2_END3: MSC2 output */
IFX_EXTERN IfxMsc_Fcln_Out IfxMsc0_FCLND_P13_0_OUT;  /**< \brief MSC0_FCLND: MSC0 output (LVDS) */
IFX_EXTERN IfxMsc_Fcln_Out IfxMsc0_FCLN_P13_0_OUT;  /**< \brief MSC0_FCLN: MSC0 output (LVDS) */
IFX_EXTERN IfxMsc_Fcln_Out IfxMsc1_FCLND_P22_0_OUT;  /**< \brief MSC1_FCLND: MSC1 output (LVDS) */
IFX_EXTERN IfxMsc_Fcln_Out IfxMsc1_FCLN_P22_0_OUT;  /**< \brief MSC1_FCLN: MSC1 output (LVDS) */
IFX_EXTERN IfxMsc_Fcln_Out IfxMsc2_FCLND_P13_4_OUT;  /**< \brief MSC2_FCLND: MSC2 output (LVDS) */
IFX_EXTERN IfxMsc_Fcln_Out IfxMsc2_FCLN_P13_4_OUT;  /**< \brief MSC2_FCLN: MSC2 output (LVDS) */
IFX_EXTERN IfxMsc_Fclp_Out IfxMsc0_FCLP_P11_6_OUT;  /**< \brief MSC0_FCLP: MSC0 output */
IFX_EXTERN IfxMsc_Fclp_Out IfxMsc0_FCLP_P13_1_OUT;  /**< \brief MSC0_FCLP: MSC0 output (LVDS) */
IFX_EXTERN IfxMsc_Fclp_Out IfxMsc0_FCLP_P13_2_OUT;  /**< \brief MSC0_FCLP: MSC0 output */
IFX_EXTERN IfxMsc_Fclp_Out IfxMsc1_FCLP_P22_1_OUT;  /**< \brief MSC1_FCLP: MSC1 output (LVDS) */
IFX_EXTERN IfxMsc_Fclp_Out IfxMsc2_FCLP_P13_5_OUT;  /**< \brief MSC2_FCLP: MSC2 output (LVDS) */
IFX_EXTERN IfxMsc_Inj_In IfxMsc0_INJ0_P00_0_IN;  /**< \brief MSC0_INJ0: MSC0 input */
IFX_EXTERN IfxMsc_Inj_In IfxMsc0_INJ1_P10_5_IN;  /**< \brief MSC0_INJ1: MSC0 input */
IFX_EXTERN IfxMsc_Inj_In IfxMsc1_INJ0_P23_3_IN;  /**< \brief MSC1_INJ0: MSC1 input */
IFX_EXTERN IfxMsc_Inj_In IfxMsc1_INJ1_P33_13_IN;  /**< \brief MSC1_INJ1: MSC1 input */
IFX_EXTERN IfxMsc_Inj_In IfxMsc2_INJ0_P13_13_IN;  /**< \brief MSC2_INJ0: MSC2 input */
IFX_EXTERN IfxMsc_Inj_In IfxMsc2_INJ1_P14_15_IN;  /**< \brief MSC2_INJ1: MSC2 output */
IFX_EXTERN IfxMsc_Sdi_In IfxMsc0_SDI0_P11_10_IN;  /**< \brief MSC0_SDI0: MSC0 input */
IFX_EXTERN IfxMsc_Sdi_In IfxMsc0_SDI1_P10_2_IN;  /**< \brief MSC0_SDI1: MSC0 input */
IFX_EXTERN IfxMsc_Sdi_In IfxMsc0_SDI2_P14_3_IN;  /**< \brief MSC0_SDI2: MSC0 input */
IFX_EXTERN IfxMsc_Sdi_In IfxMsc0_SDI3_P11_3_IN;  /**< \brief MSC0_SDI3: MSC0 input */
IFX_EXTERN IfxMsc_Sdi_In IfxMsc1_SDI0_P23_1_IN;  /**< \brief MSC1_SDI0: MSC1 input */
IFX_EXTERN IfxMsc_Sdi_In IfxMsc1_SDI1_P02_3_IN;  /**< \brief MSC1_SDI1: MSC1 input */
IFX_EXTERN IfxMsc_Sdi_In IfxMsc1_SDI2_P32_4_IN;  /**< \brief MSC1_SDI2: MSC1 input */
IFX_EXTERN IfxMsc_Sdi_In IfxMsc2_SDI0_P14_12_IN;  /**< \brief MSC2_SDI0: MSC2 input */
IFX_EXTERN IfxMsc_Son_Out IfxMsc0_SOND_P13_2_OUT;  /**< \brief MSC0_SOND: MSC0 output (LVDS) */
IFX_EXTERN IfxMsc_Son_Out IfxMsc0_SON_P13_2_OUT;  /**< \brief MSC0_SON: MSC0 output (LVDS) */
IFX_EXTERN IfxMsc_Son_Out IfxMsc1_SOND_P22_2_OUT;  /**< \brief MSC1_SOND: MSC1 output (LVDS) */
IFX_EXTERN IfxMsc_Son_Out IfxMsc1_SON_P22_2_OUT;  /**< \brief MSC1_SON: MSC1 output (LVDS) */
IFX_EXTERN IfxMsc_Son_Out IfxMsc2_SOND_P13_6_OUT;  /**< \brief MSC2_SOND: MSC2 output (LVDS) */
IFX_EXTERN IfxMsc_Son_Out IfxMsc2_SON_P13_6_OUT;  /**< \brief MSC2_SON: MSC2 output (LVDS) */
IFX_EXTERN IfxMsc_Sop_Out IfxMsc0_SOP_P11_9_OUT;  /**< \brief MSC0_SOP: MSC0 output */
IFX_EXTERN IfxMsc_Sop_Out IfxMsc0_SOP_P13_3_OUT;  /**< \brief MSC0_SOP: MSC0 output (LVDS) */
IFX_EXTERN IfxMsc_Sop_Out IfxMsc1_SOP_P22_3_OUT;  /**< \brief MSC1_SOP: MSC1 output (LVDS) */
IFX_EXTERN IfxMsc_Sop_Out IfxMsc2_SOP_P13_7_OUT;  /**< \brief MSC2_SOP: MSC2 output (LVDS) */
IFX_EXTERN IfxMsc_Sop_Out IfxMsc2_SOP_P14_11_OUT;  /**< \brief MSC2_SOP: MSC2 output */

/** \brief Table dimensions */
#define IFXMSC_PINMAP_NUM_MODULES 3
#define IFXMSC_PINMAP_NUM_TARGETS 4
#define IFXMSC_PINMAP_EN_OUT_NUM_ITEMS 6
#define IFXMSC_PINMAP_FCLN_OUT_NUM_ITEMS 2
#define IFXMSC_PINMAP_FCLP_OUT_NUM_ITEMS 3
#define IFXMSC_PINMAP_INJ_IN_NUM_ITEMS 2
#define IFXMSC_PINMAP_SDI_IN_NUM_ITEMS 4
#define IFXMSC_PINMAP_SON_OUT_NUM_ITEMS 2
#define IFXMSC_PINMAP_SOP_OUT_NUM_ITEMS 2


/** \brief IfxMsc_En_Out table */
IFX_EXTERN const IfxMsc_En_Out *IfxMsc_En_Out_pinTable[IFXMSC_PINMAP_NUM_MODULES][IFXMSC_PINMAP_NUM_TARGETS][IFXMSC_PINMAP_EN_OUT_NUM_ITEMS];

/** \brief IfxMsc_Fcln_Out table */
IFX_EXTERN const IfxMsc_Fcln_Out *IfxMsc_Fcln_Out_pinTable[IFXMSC_PINMAP_NUM_MODULES][IFXMSC_PINMAP_FCLN_OUT_NUM_ITEMS];

/** \brief IfxMsc_Fclp_Out table */
IFX_EXTERN const IfxMsc_Fclp_Out *IfxMsc_Fclp_Out_pinTable[IFXMSC_PINMAP_NUM_MODULES][IFXMSC_PINMAP_FCLP_OUT_NUM_ITEMS];

/** \brief IfxMsc_Inj_In table */
IFX_EXTERN const IfxMsc_Inj_In *IfxMsc_Inj_In_pinTable[IFXMSC_PINMAP_NUM_MODULES][IFXMSC_PINMAP_INJ_IN_NUM_ITEMS];

/** \brief IfxMsc_Sdi_In table */
IFX_EXTERN const IfxMsc_Sdi_In *IfxMsc_Sdi_In_pinTable[IFXMSC_PINMAP_NUM_MODULES][IFXMSC_PINMAP_SDI_IN_NUM_ITEMS];

/** \brief IfxMsc_Son_Out table */
IFX_EXTERN const IfxMsc_Son_Out *IfxMsc_Son_Out_pinTable[IFXMSC_PINMAP_NUM_MODULES][IFXMSC_PINMAP_SON_OUT_NUM_ITEMS];

/** \brief IfxMsc_Sop_Out table */
IFX_EXTERN const IfxMsc_Sop_Out *IfxMsc_Sop_Out_pinTable[IFXMSC_PINMAP_NUM_MODULES][IFXMSC_PINMAP_SOP_OUT_NUM_ITEMS];

/** \} */

#endif /* IFXMSC_PINMAP_H */
