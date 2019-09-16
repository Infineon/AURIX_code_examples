/**
 * \file IfxCif_PinMap.h
 * \brief CIF I/O map
 * \ingroup IfxLld_Cif
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
 * \defgroup IfxLld_Cif_pinmap CIF Pin Mapping
 * \ingroup IfxLld_Cif
 */

#ifndef IFXCIF_PINMAP_H
#define IFXCIF_PINMAP_H

#include <IfxCif_reg.h>
#include <_Impl/IfxCif_cfg.h>
#include <Port/Std/IfxPort.h>

/** \addtogroup IfxLld_Cif_pinmap
 * \{ */

/** \brief CLK pin mapping structure */
typedef const struct
{
    Ifx_CIF*          module;   /**< \brief Base address */
    IfxPort_Pin       pin;      /**< \brief Port pin */
} IfxCif_Clk_In;

/** \brief D pin mapping structure */
typedef const struct
{
    Ifx_CIF*          module;   /**< \brief Base address */
    IfxPort_Pin       pin;      /**< \brief Port pin */
} IfxCif_D_In;

/** \brief HSNC pin mapping structure */
typedef const struct
{
    Ifx_CIF*          module;   /**< \brief Base address */
    IfxPort_Pin       pin;      /**< \brief Port pin */
} IfxCif_Hsnc_In;

/** \brief VSNC pin mapping structure */
typedef const struct
{
    Ifx_CIF*          module;   /**< \brief Base address */
    IfxPort_Pin       pin;      /**< \brief Port pin */
} IfxCif_Vsnc_In;

IFX_EXTERN IfxCif_Clk_In IfxCif_CLK_P00_7_IN;  /**< \brief CIF_CLK: CIF input */
IFX_EXTERN IfxCif_D_In IfxCif_D0_P02_0_IN;  /**< \brief CIF_D0: CIF input */
IFX_EXTERN IfxCif_D_In IfxCif_D10_P00_1_IN;  /**< \brief CIF_D10: CIF input */
IFX_EXTERN IfxCif_D_In IfxCif_D11_P00_2_IN;  /**< \brief CIF_D11: CIF input */
IFX_EXTERN IfxCif_D_In IfxCif_D12_P00_3_IN;  /**< \brief CIF_D12: CIF input */
IFX_EXTERN IfxCif_D_In IfxCif_D13_P00_4_IN;  /**< \brief CIF_D13: CIF input */
IFX_EXTERN IfxCif_D_In IfxCif_D14_P00_5_IN;  /**< \brief CIF_D14: CIF input */
IFX_EXTERN IfxCif_D_In IfxCif_D15_P00_6_IN;  /**< \brief CIF_D15: CIF input */
IFX_EXTERN IfxCif_D_In IfxCif_D1_P02_1_IN;  /**< \brief CIF_D1: CIF input */
IFX_EXTERN IfxCif_D_In IfxCif_D2_P02_2_IN;  /**< \brief CIF_D2: CIF input */
IFX_EXTERN IfxCif_D_In IfxCif_D3_P02_3_IN;  /**< \brief CIF_D3: CIF input */
IFX_EXTERN IfxCif_D_In IfxCif_D4_P02_4_IN;  /**< \brief CIF_D4: CIF input */
IFX_EXTERN IfxCif_D_In IfxCif_D5_P02_5_IN;  /**< \brief CIF_D5: CIF input */
IFX_EXTERN IfxCif_D_In IfxCif_D6_P02_6_IN;  /**< \brief CIF_D6: CIF input */
IFX_EXTERN IfxCif_D_In IfxCif_D7_P02_7_IN;  /**< \brief CIF_D7: CIF input */
IFX_EXTERN IfxCif_D_In IfxCif_D8_P02_8_IN;  /**< \brief CIF_D8: CIF input */
IFX_EXTERN IfxCif_D_In IfxCif_D9_P00_0_IN;  /**< \brief CIF_D9: CIF input */
IFX_EXTERN IfxCif_Hsnc_In IfxCif_HSNC_P00_9_IN;  /**< \brief CIF_HSNC: CIF input */
IFX_EXTERN IfxCif_Vsnc_In IfxCif_VSNC_P00_8_IN;  /**< \brief CIF_VSNC: CIF input */

/** \} */

#endif /* IFXCIF_PINMAP_H */
