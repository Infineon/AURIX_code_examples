/**
 * \file IfxSpu.h
 * \brief SPU  basic functionality
 * \ingroup IfxLld_Spu
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
 *
 * \defgroup IfxLld_Spu_Std_Enum Enumerations
 * \ingroup IfxLld_Spu_Std
 * \defgroup IfxLld_Spu_Std_DataStructures Data Structures
 * \ingroup IfxLld_Spu_Std
 */

#ifndef IFXSPU_H
#define IFXSPU_H 1

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include "_Impl/IfxSpu_cfg.h"
#include "IfxSpu_bf.h"
#include "Cpu/Std/IfxCpu_Intrinsics.h"
#include "_Utilities/Ifx_Assert.h"
#include "Scu/Std/IfxScuWdt.h"
#include "IfxSpu_reg.h"

/******************************************************************************/
/*--------------------------------Enumerations--------------------------------*/
/******************************************************************************/

/** \addtogroup IfxLld_Spu_Std_Enum
 * \{ */
/** \brief Bin Rejection mode.\n
 * Definition in IfxSPU_BINREJCTRL.RMODE
 */
typedef enum
{
    IfxSpu_BinRejection_Mode_off,     /**< \brief Pass all data */
    IfxSpu_BinRejection_Mode_reject,  /**< \brief Remove the selected bins from the output data */
    IfxSpu_BinRejection_Mode_zero     /**< \brief Set the selected bins to zero */
} IfxSpu_BinRejection_Mode;

/** \brief CA-CFAR algorithm selection\n
 * Definition in IfxSPU_CFARCFG.CAALGO
 */
typedef enum
{
    IfxSpu_CFAR_CA_Algorithm_cash,  /**< \brief CASH-CFAR */
    IfxSpu_CFAR_CA_Algorithm_ca,    /**< \brief CA-CFAR */
    IfxSpu_CFAR_CA_Algorithm_cago,  /**< \brief CAGO-CFAR */
    IfxSpu_CFAR_CA_Algorithm_caso   /**< \brief CASO-CFAR */
} IfxSpu_CFAR_CA_Algorithm;

/** \brief CFAR engine selection\n
 * Definition in IfxSPU_BEx_CFARCTRL.CFARSEL
 */
typedef enum
{
    IfxSpu_CFAR_Engine_ca,    /**< \brief Output the CA-CFAR engine result for inline CFAR mode */
    IfxSpu_CFAR_Engine_gos,   /**< \brief Output the GOS-CFAR Engine result for inline CFAR mode */
    IfxSpu_CFAR_Engine_both,  /**< \brief Both engines for inline CFAR mode */
    IfxSpu_CFAR_Engine_auto   /**< \brief Automatic selection for inline CFAR mode */
} IfxSpu_CFAR_Engine;

/** \brief GOS-CFAR algorithm selection\n
 * Definition in IfxSPU_CFARCFG.GOSALGO
 */
typedef enum
{
    IfxSpu_CFAR_GOS_Algorithm_gos,    /**< \brief GOS-CFAR */
    IfxSpu_CFAR_GOS_Algorithm_gosgo,  /**< \brief GOSGO-CFAR */
    IfxSpu_CFAR_GOS_Algorithm_gosso   /**< \brief GOSSO-CFAR */
} IfxSpu_CFAR_GOS_Algorithm;

/** \brief CFAR mode\n
 * Definition in IfxSPU_BEx_CFARCTRL.CFAREN
 */
typedef enum
{
    IfxSpu_CFAR_Mode_off,              /**< \brief Off */
    IfxSpu_CFAR_Mode_inline,           /**< \brief Inline CFAR */
    IfxSpu_CFAR_Mode_offline,          /**< \brief Offline CFAR */
    IfxSpu_CFAR_Mode_localMaxInline,   /**< \brief Inline Local Maximum */
    IfxSpu_CFAR_Mode_localMaxOffline,  /**< \brief Offline Local Maximum */
    IfxSpu_CFAR_Mode_nci,              /**< \brief CFAR on NCI output */
    IfxSpu_CFAR_Mode_localMaxNci       /**< \brief Threshold comparison based on NCI output */
} IfxSpu_CFAR_Mode;

/** \brief Spectrum extension for CFAR or threshold units\n
 * Definition in IfxSPU_BEx_CFARCTRL.EXTNSN
 */
typedef enum
{
    IfxSpu_CFAR_SpectrumExtension_off,      /**< \brief No spectrum extension */
    IfxSpu_CFAR_SpectrumExtension_range,    /**< \brief Range spectrum extension */
    IfxSpu_CFAR_SpectrumExtension_velocity  /**< \brief Velocity spectrum extension */
} IfxSpu_CFAR_SpectrumExtension;

/** \brief clock division ratio for the FFT engine\n
 * Definition in IfxSPU_CTRL.DIV
 */
typedef enum
{
    IfxSpu_ClockDivisionRatio_unity,  /**< \brief 1:1 clock ratio */
    IfxSpu_ClockDivisionRatio_div2,   /**< \brief 1:2 clock ratio */
    IfxSpu_ClockDivisionRatio_div4,   /**< \brief 1:4 clock ratio */
    IfxSpu_ClockDivisionRatio_div8    /**< \brief 1:8 clock ratio */
} IfxSpu_ClockDivisionRatio;

/** \brief Source of the data to be processed\n
 * Definition in IfxSPU_ID_CONF.SRC
 */
typedef enum
{
    IfxSpu_DataSource_rif0,     /**< \brief Data source RIF0 */
    IfxSpu_DataSource_rif1,     /**< \brief Data source RIF1 */
    IfxSpu_DataSource_rifBoth,  /**< \brief Data source RIF0 and RIF1 */
    IfxSpu_DataSource_emem      /**< \brief Data source Emem (radar memeory) */
} IfxSpu_DataSource;

/** \brief Radar memeory output data format \n
 * Definition in IfxSPU_BEx_UNLDR_CONF.FORMAT
 */
typedef enum
{
    IfxSpu_FftDataFormat_complex16Bit,  /**< \brief 16 bit complex data */
    IfxSpu_FftDataFormat_complex32Bit   /**< \brief 32 bit complex data */
} IfxSpu_FftDataFormat;

/** \brief Number of samples for the FFT\n
 * Definition in IfxSPU_BEx_LDR_CONF.SIZE
 */
typedef enum
{
    IfxSpu_FftSize_8 = 3,  /**< \brief FFT is eight data samples */
    IfxSpu_FftSize_16,     /**< \brief FFT is sixteen data samples */
    IfxSpu_FftSize_32,     /**< \brief FFT is thirty two data samples */
    IfxSpu_FftSize_64,     /**< \brief FFT is sixty four data samples */
    IfxSpu_FftSize_128,    /**< \brief FFT is one hundred and twenty eight data samples */
    IfxSpu_FftSize_256,    /**< \brief FFT is two hundred and fifty six data samples */
    IfxSpu_FftSize_512,    /**< \brief FFT is five hundred and twelve data samples */
    IfxSpu_FftSize_1024,   /**< \brief FFT is one thousand and twenty four data samples */
    IfxSpu_FftSize_2048    /**< \brief FFT is two thousand and forty eigth data samples */
} IfxSpu_FftSize;

/** \brief Power values per histogram bin
 */
typedef enum
{
    IfxSpu_Histogram_Bins_32   = 0,  /**< \brief HistogramBins 32 */
    IfxSpu_Histogram_Bins_64   = 1,  /**< \brief HistogramBins 64 */
    IfxSpu_Histogram_Bins_128  = 2,  /**< \brief HistogramBins 128 */
    IfxSpu_Histogram_Bins_256  = 3,  /**< \brief HistogramBins 256 */
    IfxSpu_Histogram_Bins_512  = 4,  /**< \brief HistogramBins 512 */
    IfxSpu_Histogram_Bins_1024 = 5,  /**< \brief HistogramBins 1024 */
    IfxSpu_Histogram_Bins_2048 = 6,  /**< \brief HistogramBins 2048 */
    IfxSpu_Histogram_Bins_4096 = 7   /**< \brief HistogramBins 4096 */
} IfxSpu_Histogram_Bins;

/** \brief Input data format (real or complex)\n
 * Definition in IfxSPU_ID_CONF.FORMAT
 */
typedef enum
{
    IfxSpu_InputDataFormat_real,    /**< \brief Input data is real number */
    IfxSpu_InputDataFormat_complex  /**< \brief Input data has real and imaginary components */
} IfxSpu_InputDataFormat;

/** \brief Input data type (signed or unsigned)\n
 * Definition in IfxSPU_ID_CONF.SIGNED
 */
typedef enum
{
    IfxSpu_InputDataType_unsigned,  /**< \brief Unsigned input data */
    IfxSpu_InputDataType_signed     /**< \brief Signed input data */
} IfxSpu_InputDataType;

/** \brief Check combine mode.\n
 * Definition in IfxSPU_LCLMAX.CMBN
 */
typedef enum
{
    IfxSpu_LocalMax_CombinedMode_or,  /**< \brief OR check results */
    IfxSpu_LocalMax_CombinedMode_and  /**< \brief AND check results */
} IfxSpu_LocalMax_CombinedMode;

/** \brief Local maximum mode.\n
 * Definition in IfxSPU_LCLMAX.LMODE
 */
typedef enum
{
    IfxSpu_LocalMax_Mode_off,    /**< \brief Off */
    IfxSpu_LocalMax_Mode_under,  /**< \brief Reject bin if not local maximum */
    IfxSpu_LocalMax_Mode_over    /**< \brief Reject bin if local maximum */
} IfxSpu_LocalMax_Mode;

/** \brief Local maximum mode.\n
 * Definition in IfxSPU_LCLMAX.TMODE
 */
typedef enum
{
    IfxSpu_LocalMax_ThresholdMode_off,    /**< \brief Off */
    IfxSpu_LocalMax_ThresholdMode_under,  /**< \brief Reject bin if under threshold */
    IfxSpu_LocalMax_ThresholdMode_over    /**< \brief Reject bin if over threshold */
} IfxSpu_LocalMax_ThresholdMode;

/** \brief width of the comparison window for the Local Maximum detection.\n
 * Definition in IfxSPU_LCLMAX.WIDTH
 */
typedef enum
{
    IfxSpu_LocalMax_WindowWidth_off,    /**< \brief No local maximum */
    IfxSpu_LocalMax_WindowWidth_three,  /**< \brief On, with window size of three */
    IfxSpu_LocalMax_WindowWidth_five    /**< \brief On, with window size of five */
} IfxSpu_LocalMax_WindowWidth;

/** \brief Precision of the output data written to the Radar Memory from Non-coherent intergration\n
 * Definition in IfxSPU_BEx_NCICTRL.FORMAT
 */
typedef enum
{
    IfxSpu_NCI_OutputFormat_off,        /**< \brief Output channel is off */
    IfxSpu_NCI_OutputFormat_real16Bit,  /**< \brief 16 bit data output (real) */
    IfxSpu_NCI_OutputFormat_real32Bit   /**< \brief 32 bit data output (real) */
} IfxSpu_NCI_OutputFormat;

/** \brief Scaling factor applied to the results from Non-coherent intergration\n
 * Definition in IfxSPU_BEx_NCICTRL.SCALE
 */
typedef enum
{
    IfxSpu_NCI_ScalingFactor_off,   /**< \brief Output channel is off */
    IfxSpu_NCI_ScalingFactor_div2,  /**< \brief Divide result by 2 */
    IfxSpu_NCI_ScalingFactor_div4,  /**< \brief Divide result by 4 */
    IfxSpu_NCI_ScalingFactor_div8   /**< \brief Divide result by 8 */
} IfxSpu_NCI_ScalingFactor;

/** \brief Number of Antennae connected to each RIF instance\n
 * Definition in IfxSPU_ID_CONF.ANT
 */
typedef enum
{
    IfxSpu_Num_Antennae_1 = 1,  /**< \brief 1 antenna is connected */
    IfxSpu_Num_Antennae_2,      /**< \brief 2 antennae are connected  */
    IfxSpu_Num_Antennae_3,      /**< \brief 3 antennae are connected  */
    IfxSpu_Num_Antennae_4       /**< \brief 4 antennae are connected  */
} IfxSpu_Num_Antennae;

/** \brief Processing instance number to choose the register instance for base engine (BEx)
 */
typedef enum
{
    IfxSpu_PassId_0,  /**< \brief First processing instance */
    IfxSpu_PassId_1   /**< \brief Second processing instance */
} IfxSpu_PassId;

/** \brief Double pass configuration mode\n
 * Definition in IfxSPU_DPASS_CONF
 */
typedef enum
{
    IfxSpu_PassMode_single,    /**< \brief Double pass mode disable */
    IfxSpu_PassMode_double,    /**< \brief Double pass mode enabled without buffer memory switch */
    IfxSpu_PassMode_alternate  /**< \brief Double pass mode enabled with buffer memory switch */
} IfxSpu_PassMode;

/** \brief Phase shift\n
 * Definition in IfxSPU_BEx_LDR_CONF.PHSHFT
 */
typedef enum
{
    IfxSpu_PhaseShift_0,    /**< \brief No phase shift */
    IfxSpu_PhaseShift_90,   /**< \brief 90 degree phase shift  */
    IfxSpu_PhaseShift_180,  /**< \brief 180 degree phase shift  */
    IfxSpu_PhaseShift_270   /**< \brief 270 degree phase shift  */
} IfxSpu_PhaseShift;

/** \brief Operating mode of the Input DMA\n
 * Definition in IfxSPU_ID_RM_CONF.TRNSPS
 */
typedef enum
{
    IfxSpu_RM_AddressingMode_linear,    /**< \brief Linear mode */
    IfxSpu_RM_AddressingMode_transpose  /**< \brief Transpose mode */
} IfxSpu_RM_AddressingMode;

/** \brief Defines how to identify each FFT dataset with a particular antenna\n
 * Definition in IfxSPU_ID_RM_CONF.AM
 */
typedef enum
{
    IfxSpu_RM_AntennaMapping_default,          /**< \brief Antenna ID passed to processing chain is permanently 0d */
    IfxSpu_RM_AntennaMapping_indexMode,        /**< \brief Antenna ID is derived from the dataset index */
    IfxSpu_RM_AntennaMapping_innerLoopRepeat,  /**< \brief Antenna ID is derived from the inner loop repeat counter value */
    IfxSpu_RM_AntennaMapping_outerLoopRepeat,  /**< \brief Antenna ID is derived from the outer loop repeat counter value */
    IfxSpu_RM_AntennaMapping_binLoopRepeat     /**< \brief Antenna ID is derived from the bin loop repeat counter value */
} IfxSpu_RM_AntennaMapping;

/** \brief Radar memeory input data format \n
 * Definition in IfxSPU_ID_RM_CONF.FORMAT
 */
typedef enum
{
    IfxSpu_RM_InputDataFormat_complex16Bit     = 0, /**< \brief 16 bit precision complex data */
    IfxSpu_RM_InputDataFormat_complex32Bit     = 1, /**< \brief 32 bit precision complex data */
    IfxSpu_RM_InputDataFormat_power32Bit       = 2, /**< \brief 32 bit precision power data */
    IfxSpu_RM_InputDataFormat_real16Bit        = 4, /**< \brief 16 bit precision real data */
    IfxSpu_RM_InputDataFormat_real32Bit        = 5, /**< \brief 32 bit precision real data */
    IfxSpu_RM_InputDataFormat_realHalfFloat    = 6, /**< \brief half-precision floating-point real data */
    IfxSpu_RM_InputDataFormat_complexHalfFloat = 7  /**< \brief half-precision floating-point complex data */
} IfxSpu_RM_InputDataFormat;

/** \brief Processing mode of the Input DMA\n
 * Definition in IfxSPU_ID_RM_CONF.PM
 */
typedef enum
{
    IfxSpu_RM_ProcessingMode_default,     /**< \brief Default mode */
    IfxSpu_RM_ProcessingMode_integration  /**< \brief Integration mode */
} IfxSpu_RM_ProcessingMode;

/** \brief Calculations Using Complex Data to use the real component only or the complex component also\n
 * Definition in IfxSPU_BEx_SUMCTRL.REAL
 */
typedef enum
{
    IfxSpu_Summation_DataFormat_complex,  /**< \brief Calculations will use real and complex components */
    IfxSpu_Summation_DataFormat_real      /**< \brief Calculations will use the real component of the input data only. The
                                           * complex component will be discarded */
} IfxSpu_Summation_DataFormat;

/** \brief Operating mode of the Summation Unit in the power domain\n
 * Definition in IfxSPU_BEx_SUMCTRL.PWRMODE
 */
typedef enum
{
    IfxSpu_Summation_PowerMode_off,  /**< \brief Off */
    IfxSpu_Summation_PowerMode_sum   /**< \brief Sum */
} IfxSpu_Summation_PowerMode;

/** \brief OCDS Suspend Control (OCDS.SUS)
 */
typedef enum
{
    IfxSpu_SuspendMode_none = 0,  /**< \brief No suspend */
    IfxSpu_SuspendMode_hard = 1,  /**< \brief Hard Suspend */
    IfxSpu_SuspendMode_soft = 2   /**< \brief Soft Suspend */
} IfxSpu_SuspendMode;

/** \brief SPU trigger mode\n
 * Definition in IfxSPU_CTRL.MODE
 */
typedef enum
{
    IfxSpu_TriggerMode_off      = 0,  /**< \brief SPU is disabled */
    IfxSpu_TriggerMode_internal = 1,  /**< \brief Internal trigger */
    IfxSpu_TriggerMode_external = 2,  /**< \brief External trigger */
    IfxSpu_TriggerMode_spu0Done = 3,  /**< \brief Trigger on SPU0 done */
#if IFXSPU_NUM_MODULES > 1
    IfxSpu_TriggerMode_spu1Done = 4,  /**< \brief Trigger on SPU1 done */
#endif
    IfxSpu_TriggerMode_reload   = 5,  /**< \brief Reload configuration from memory with no processing */
    IfxSpu_TriggerMode_software = 6,  /**< \brief Software trigger */
    IfxSpu_TriggerMode_stop     = 7   /**< \brief SPU will stop at end of current operation */
} IfxSpu_TriggerMode;

/** \brief Format of the Window Function Data stored in the configuration memeory\n
 * Definition in IfxSPU_BEx_LDR_CONF.FORMAT
 */
typedef enum
{
    IfxSpu_WindowDataFormat_real16,     /**< \brief 16 bit real window data */
    IfxSpu_WindowDataFormat_real32,     /**< \brief 32 bit real window data */
    IfxSpu_WindowDataFormat_complex16,  /**< \brief 16 bit complex window data */
    IfxSpu_WindowDataFormat_complex32   /**< \brief 32 bit complex window data */
} IfxSpu_WindowDataFormat;

/** \} */

/** \brief Output Data Processor  scaling factor
 * Definition in IfxSPU_BEx_ODP_CONF.SCALE
 */
typedef enum
{
    IfxSpu_ODP_Format_complex32Bit,      /**< \brief Output is written with 32 bit precision complex */
    IfxSpu_ODP_Format_real32Bit,         /**< \brief Output is written with 32 bit precision real */
    IfxSpu_ODP_Format_complex16Bit,      /**< \brief Output is written with 16 bit precision complex */
    IfxSpu_ODP_Format_real16Bit,         /**< \brief Output is written with 16 bit precision real */
    IfxSpu_ODP_Format_complexHalfFloat,  /**< \brief Output is written with half-precision floating-point complex */
    IfxSpu_ODP_Format_realHalfFloat      /**< \brief Output is written with half-precision floating-point precision real */
} IfxSpu_ODP_Format;

/** \brief Operating mode of the Summation Unit on complex or magnitude data
 * Definition in IfxSPU_BEx_SUMCTRL.SUMMODE
 */
typedef enum
{
    IfxSpu_Summation_Mode_off,      /**< \brief Off */
    IfxSpu_Summation_Mode_sum,      /**< \brief Sum */
    IfxSpu_Summation_Mode_sumLinP,  /**< \brief Sum linear power */
    IfxSpu_Summation_Mode_sumAnt    /**< \brief Sum across antenna */
} IfxSpu_Summation_Mode;

/** \brief Definition in IfxSPU_BEx_PWRSUM.FORMAT
 */
typedef enum
{
    IfxSpu_Summation_Precision_32bit,  /**< \brief 32 bit precision */
    IfxSpu_Summation_Precision_16bit   /**< \brief 16-bit precision */
} IfxSpu_Summation_Precision;

/** \brief Definition in IfxSPU_BEx_PWRSUM.SCALE
 */
typedef enum
{
    IfxSpu_Summation_Scale_off,
    IfxSpu_Summation_Scale_div2,
    IfxSpu_Summation_Scale_div4,
    IfxSpu_Summation_Scale_div8
} IfxSpu_Summation_Scale;

/******************************************************************************/
/*-----------------------------Data Structures--------------------------------*/
/******************************************************************************/

/** \addtogroup IfxLld_Spu_Std_DataStructures
 * \{ */
/** \brief Configuration structure for Windowing
 */
typedef struct
{
    boolean                 enabled;                                   /**< \brief Enable / Disable window function. Range: TRUE Enable window function, FALSE Disable window function */
    IfxSpu_WindowDataFormat dataFormat;                                /**< \brief Format of the Window Function Data stored in the configuration memeory */
    uint16                  baseAddress;                               /**< \brief Window coefficient base address. Range: 0 to 0xFFFF */
    uint16                  antennaOffsets[IFXSPU_MAX_ANTENNAE];       /**< \brief Offset Addresses for each antenna. Range: 0 to 0xFFFF */
} IfxSpu_WindowingConfig;

/** \} */

/** \addtogroup IfxLld_Spu_Std_DataStructures
 * \{ */
/** \brief Configuration structure for CA-CFAR algorithm
 */
typedef struct
{
    IfxSpu_CFAR_CA_Algorithm algorithm;                   /**< \brief CA-CFAR algorithm selection */
    uint8                    guardCells;                  /**< \brief Number of guard cells in CA-CFAR leading and lagging the cell under test. Range: 0 to 0x3F */
    uint8                    windowCellsExponent;         /**< \brief Number of active cells in leading/lagging windows to be averaged in CA-CFAR. Range: 0 to 0x7 */
    uint8                    cashSubWindowExponent;       /**< \brief Number of sub window cells CASH-CFAR. Range: 0 to 0x7 */
    uint16                   beta;                        /**< \brief Additive constant scaling the CA-CFAR theshold. Range: 0 to 0xFFFF */
} IfxSpu_CfarCAConfig;

/** \brief Configuration structure for CFAR module control
 */
typedef struct
{
    IfxSpu_CFAR_Mode              mode;                        /**< \brief CFAR mode */
    uint32                        baseAddress;                 /**< \brief Base address to be used when writing data to Radar Memory. Range: 0 to 0x7FFFF */
    IfxSpu_CFAR_SpectrumExtension spectrumExtension;           /**< \brief Spectrum extension for CFAR or threshold units */
    uint8                         spectrumExtensionSize;       /**< \brief Window size to be used for spectrum extension. Range: 0 to 0x3F */
    boolean                       caCfarEnabled;               /**< \brief CFAR CA Engine Enable. Range: TRUE CA Engine On, FALSE CA Engine Off */
    boolean                       gosCfarEnabled;              /**< \brief CFAR GOS Engine Enable. Range: TRUE GOS Engine On, FALSE GOS Engine Off */
} IfxSpu_CfarConfig;

/** \brief Configuration structure for GOS-CFAR algorithm
 */
typedef struct
{
    IfxSpu_CFAR_GOS_Algorithm algorithm;           /**< \brief GOS-CFAR algorithm selection */
    uint8                     guardCells;          /**< \brief Number of guard cells in GOS-CFAR leading and lagging the cell under test. Range: 0 to 0x3F */
    uint8                     indexLead;           /**< \brief Index of sorted statistic in leading window in GOS-CFAR. Range: 0 to 0x1F */
    uint8                     indexLag;            /**< \brief Index of sorted statistic in lagging window in GOS-CFAR. Range: 0 to 0x1F */
    uint8                     windowCells;         /**< \brief Number of active cells in leading/lagging windows to be averaged in GOS-CFAR. Range: 0 to 0x3F */
    uint16                    beta;                /**< \brief Additive constant scaling the CA-CFAR theshold. Range: 0 to 0xFFFF */
    uint16                    addressOffset;       /**< \brief Channel 5 Address Offset in bytes. Range: 0 to 0xFFFF */
} IfxSpu_CfarGOSConfig;

/** \brief Configuration structure for Streaming FFT
 */
typedef struct
{
    boolean              enabled;           /**< \brief Enable / Disable FFT processing. Range: TRUE Enable FFT processing, FALSE Disable FFT processing */
    boolean              inversed;          /**< \brief Enable / Disable inverse FFT. Range: TRUE Enable inverse FFT, FALSE Disable inverse FFT */
    IfxSpu_FftSize       size;              /**< \brief Number of FFT points. Range: 0 to 0x8 */
    IfxSpu_FftDataFormat dataFormat;        /**< \brief Format of the data to be written to the buffer memory */
    boolean              forceToReal;       /**< \brief Force the output to Real enable / disable choice. Range: TRUE Enable Force the output to Real, FALSE Disable Force the output to Real */
    uint8                exponent;          /**< \brief Alignment correction to be applied when reformatting to 16 bit. Range: 0 to 0x1F */
} IfxSpu_FftConfig;

/** \brief Configuration structure for FFT output
 */
typedef struct
{
    boolean           enabled;           /**< \brief Major Operating Mode for the ODP, ON / OFF */
    uint32            baseAddress;       /**< \brief The base address to be used when writing data to Radar Memory. Range: 0 to 0x7FFFF */
    IfxSpu_ODP_Format format;            /**< \brief Output Data Processor  scaling factor */
    uint16            exponent;          /**< \brief The number of LSBs to be removed when writing 16 bit precision data to the Radar Memory. Range: 0 to 0x1F */
    boolean           inPlace;           /**< \brief In Place Fft enable / disable choice. Range: TRUE Enable In Place Fft, FALSE Disable In Place Fft */
} IfxSpu_FftOutputConfig;

/** \brief Configuration structure for Histogram
 */
typedef struct
{
    boolean               enabled;                    /**< \brief Enable / Disable choice for Histogram. Range: TRUE Histogram is generated, FALSE No histogram is generated */
    IfxSpu_Histogram_Bins numClasses;                 /**< \brief Number of power values per histogram bin */
    uint32                baseAddress;                /**< \brief Base address to be used Histogram. Range: 0 to 0xFFFF */
    uint16                startDelay;                 /**< \brief Delay from Start of Measurement Cycle before the accumulation of histogram is started. Range: 0 to 0xFFFF */
    uint16                endDelay;                   /**< \brief Delay from Start of Measurement Cycle before the accumulation of histogram is ended. Range: 0 to 0xFFFF */
    boolean               antennaFilterEnabled;       /**< \brief Enable / Disable choice for Antenna Filter. Range: TRUE Antenna filtering is enabled, FALSE ON, Antenna filtering is disabled */
    uint8                 antennaFilterMask;          /**< \brief Antenna Filter mask. Range: 0 to 0x7 */
} IfxSpu_HistogramConfig;

/** \brief Configuration structure for Math1 unit
 */
typedef struct
{
    uint8                  loaderExponent;            /**< \brief Alignment correction to be applied when reformatting to 32 bit. Range: 0 to 0x3F */
    uint8                  numDropLastSamples;        /**< \brief Number of last samples of the input data to be ignored. Range: 0 to 0xFF */
    uint8                  numDropFirstSamples;       /**< \brief Number of first samples of the input data to be ignored. Range: 0 to 0xFF */
    uint16                 numPadFrontSamples;        /**< \brief Number of  samples to be padded at front. Range: 0 to 0x1FFF */
    IfxSpu_WindowingConfig window;                    /**< \brief Windowing configuration */
    IfxSpu_PhaseShift      phaseShift;                /**< \brief Fast phase shift */
} IfxSpu_Math1Config;

/** \brief Configuration structure for Non-Coherent Integration control
 */
typedef struct
{
    boolean                  enabled;             /**< \brief Enable / Disable choice for Non-Coherent Integration */
    uint32                   baseAddress;         /**< \brief Base address to be used when writing data to Radar Memory. Range: 0 to 0x7FFFF */
    IfxSpu_NCI_OutputFormat  outputFormat;        /**< \brief Precision of the output data written to the Radar Memory from Non-coherent intergration */
    IfxSpu_NCI_ScalingFactor scalingFactor;       /**< \brief Scaling factor applied to the results from Non-coherent intergration */
} IfxSpu_NciConfig;

/** \brief Configuration structure for Power Information Channel
 */
typedef struct
{
    boolean enabled;           /**< \brief Enable / Disable choice for Power Information Channel */
    uint32  baseAddress;       /**< \brief Base address to be used when writing data to Radar Memory. Range: 0 to 0x7FFFF */
} IfxSpu_PowerOutputConfig;

/** \brief Configuration structure for RIF input data
 */
typedef struct
{
    IfxSpu_InputDataFormat dataFormat;                           /**< \brief Input data format (real or complex) */
    IfxSpu_InputDataType   dataType;                             /**< \brief Input data type (signed or unsigned) */
    uint16                 numRamps;                             /**< \brief ramps per messurement cycle. Range: 0 to 0x7FF */
    IfxSpu_Num_Antennae    numAntennae;                          /**< \brief Number of Antennae connected to each RIF instance */
    uint16                 sampleCount;                          /**< \brief Number of samples per ramp. Range: 0 to 0x7FF */
    boolean                preAcquisitionCounterEnabled;         /**< \brief Enable / Disable Preacquisition counter */
    uint16                 preAcquisitionCounterLimit;           /**< \brief Preacquisition counter limit. Range: 0 to 0x7FF */ 
    boolean                bypassModeEnabled;                    /**< \brief Enable / Disable Bypass mode */
    uint32                 bypassAddress;                        /**< \brief Bypass address. Range: 0 to 0xFFFF */
    boolean                bypassReloadEnabled;                  /**< \brief Enable / Disable Bypass reload */
    boolean                triggerOnLimit;                       /**< \brief If set to TRUE, then the SPU will start acquiring data when the counter reaches the value in the LIMIT field(configured by data member preAcquisitionCounterLimit of this struct).
                                                                  *
                                                                  * NOTE : This is considered as an internal trigger event and the CTRL.MODE bitfield should be set for internal trigger. */
    boolean preAcquisitionCounterReset;                          /**< \brief Preacquisition counter reset. Range: TRUE Enable counter reset, FALSE Disable counter reset */
    boolean preAcquisitionCounterTrigger;                        /**< \brief Preacquisition counter trigger. Range: TRUE SPU will start acquiring data FALSE SPU will stop acquiring data */
    boolean preAcquisitionCounterError;                          /**< \brief Preacquisition counter error on limit. Range: TRUE Error interrupt will be triggered, FALSE Error interrupt will not be triggered */
    boolean preAcquisitionCounterAttention;                      /**< \brief Preacquisition counter attention on limit. Range: TRUE Attention request interrupt will be triggered, FALSE Attention request interrupt will not be triggered */
} IfxSpu_RifConfig;

/** \brief Configuration structure for Radar Memory input data
 */
typedef struct
{
    IfxSpu_RM_InputDataFormat dataFormat;            /**< \brief Radar memeory input data format */
    uint32                    baseAddress;           /**< \brief Radar memeory base address. Range: 0 to 0x7FFFF */
    uint32                    innerLoopOffset;       /**< \brief Inner loop offset address. Range: 0 to 0xFFFFFF */
    uint32                    outerLoopOffset;       /**< \brief Outer loop offset address. Range: 0 to 0xFFFFFF */
    uint32                    binLoopOffset;         /**< \brief Bin loop offset address. Range: 0 to 0xFFFFFF */
    uint16                    innerLoopRepeat;       /**< \brief Inner loop repeat value. Range: 0 to 0x1FFF */
    uint16                    outerLoopRepeat;       /**< \brief Outer loop repeat value. Range: 0 to 0x1FFF */
    uint16                    binLoopRepeat;         /**< \brief Bin loop repeat value. Range: 0 to 0x1FFF */
    IfxSpu_RM_AddressingMode  addressingMode;        /**< \brief Operating mode of the Input DMA */
    IfxSpu_RM_ProcessingMode  processingMode;        /**< \brief Processing mode of the Input DMA */
    uint8                     numBlocks;             /**< \brief Number of data blocks that will fit into the buffer memory. Range: 0 to 0x7 */
    IfxSpu_RM_AntennaMapping  antennaMapping;        /**< \brief Mapping of FFT datasets to antenna */
} IfxSpu_RmConfig;

/** \brief Configuration structure for Sideband Statistics
 */
typedef struct
{
    boolean enabled;           /**< \brief Enable / Disable choice for Sideband Statistics */
    uint32  baseAddress;       /**< \brief Base address to be used when writing data to Radar Memory. Range: 0 to 0x7FFFF */
} IfxSpu_SidebandStatisticsConfig;

/** \brief Configuration structure for Summation unit control
 */
typedef struct
{
    uint32                      baseAddress;         /**< \brief Base address to be used when writing data to Radar Memory. Rnage: 0 to 0x7FFFF */
    IfxSpu_Summation_Mode       mode;                /**< \brief Operating mode of the Summation Unit on complex or magnitude data */
    IfxSpu_Summation_DataFormat dataFormat;          /**< \brief Calculations Using Complex Data to use the real component only or the complex component also */
    uint8                       antennaeToUse;       /**< \brief Selection of which antennae to use. Range: 0 to 0xFF */
    IfxSpu_Summation_Scale      shift;               /**< \brief Normalize CSUM result by dividing the result */
    IfxSpu_Summation_Precision  precision;           /**< \brief Output precision format */
} IfxSpu_SummationConfig;

/** \} */

/** \addtogroup IfxLld_Spu_Std_DataStructures
 * \{ */
/** \brief Configuration structure for Bin Rejection unit
 */
typedef struct
{
    IfxSpu_BinRejection_Mode mode;                   /**< \brief Bin rejection mode */
    boolean                  thresholdEnabled;       /**< \brief Enable / Disable choice for Zero with Threshold. Range: TRUE ZETH Zero with Threshold, FALSE OFF Unit Disabled
     */
    uint32                   thresholdValue;         /**< \brief Magnitude value to be used for comparison. Range: 0 to 0xFFFFFF */
    uint16                   numAllowedBins;         /**< \brief Number of passed bins (i.e. non-rejected), starting from the first. Range: 0 to 0x7F */
    boolean                  leftJustify;            /**< \brief Define whether the threshold value will be left justified to 24-bit. Range: TRUE LEFT Left Justify Pad with 8 LSBs to create a 32 bit comparison value,\n
                                                                 FALSE RIGHT Right Justify Pad with 8 MSBs to create a 32 bit comparison value*/
    IfxSpu_CFAR_Engine       inlineCfarSelect;       /**< \brief Inline CFAR engine selection */
} IfxSpu_BinRejectionConfig;

/** \brief Configuration structure for FFT input
 */
typedef struct
{
    IfxSpu_DataSource dataSource;       /**< \brief Source of the data to be processed */
    IfxSpu_RifConfig  rif;              /**< \brief Configuration structure for RIF input data */
    IfxSpu_RmConfig   rm;               /**< \brief Configuration structure for Radar Memory input data */
} IfxSpu_FftInputConfig;

/** \brief Configuration structure for interrupts
 */
typedef struct
{
    boolean powerDataWrite;             /**< \brief Enable/Disable the attention request, End of power data write from Output DMA engine */
    boolean complexDataWrite;           /**< \brief Enable/Disable the attention request, End of complex data write from Output DMA engine */
    boolean inputDmaUnit;               /**< \brief Enable/Disable the attention request, input DMA unit */
    boolean linkedListEnd;              /**< \brief Enable/Disable the attention request, End of linked list */
    boolean pactrTrigger;               /**< \brief Enable/Disable the attention request, partial acquisition counter trigger */
    boolean anyStatus;                  /**< \brief Enable/Disable the attention request, Any status event */
    boolean inputDmaReadError;          /**< \brief Enable/Disable the Error flag, Input DMA unit read error */
    boolean inputDmaWriteError;         /**< \brief Enable/Disable the Error flag, Input DMA unit write error */
    boolean outputDmaEngineError;       /**< \brief Enable/Disable the Error flag, Output DMA Engine error */
    boolean fifoOverrun;                /**< \brief Enable/Disable the Error flag, FIFO overrun */
    boolean pactrError;                 /**< \brief Enable/Disable the Error flag, Partial acquisition counter error */
    boolean math2UnitOverrun;           /**< \brief Enable/Disable the Error flag, MATH2 uint overrun */
} IfxSpu_InterruptConfig;

/** \brief Configuration structure for Local Maximum unit
 */
typedef struct
{
    IfxSpu_LocalMax_WindowWidth   windowWidth;          /**< \brief Local Max window width */
    IfxSpu_LocalMax_Mode          localMaxMode;         /**< \brief Local Max mode */
    IfxSpu_LocalMax_ThresholdMode thresholdMode;        /**< \brief Threshold mode */
    IfxSpu_LocalMax_CombinedMode  combinedMode;         /**< \brief Combine operation between result of localMaxMode and thresholdMode */
    uint32                        thresholdValue;       /**< \brief Threshold Value to be Used for Bin Magnitude Comparison. Range: 0 to 0xFFFFFF */
    boolean                       leftJustify;          /**< \brief Selects if comparison to be made against the 24 MSBs or 24 LSBs. Range: TRUE LEFT Left Justify Pad with 8 LSBs to create a 32 bit comparison,/n
                                                                    FALSE  RIGHT Right Justify Pad with 8 MSBs to create a 32 bit comparison value */
} IfxSpu_LocalMaxConfig;

/** \brief Configuration structure for Magnitude approximation
 */
typedef struct
{
    uint16 alpha;       /**< \brief Alpha. Range: 0 to 0xFFFF */
    uint16 beta;        /**< \brief Beta. Range: 0 to 0xFFFF */
} IfxSpu_MagnitudeConfig;

/** \brief Configuration Structure for Pass mode registers
 */
typedef struct
{
    IfxSpu_FftConfig                fft;              /**< \brief Configuration structure for Streaming FFT */
    IfxSpu_Math1Config              math1;            /**< \brief Configuration structure for Math1 unit */
    IfxSpu_HistogramConfig          histogram;        /**< \brief Configuration structure for Histogram */
    IfxSpu_NciConfig                nci;              /**< \brief Configuration structure for Non-Coherent Integration control */
    IfxSpu_SummationConfig          csum;             /**< \brief Configuration structure for Summation unit control */
    IfxSpu_CfarConfig               cfar;             /**< \brief Configuration structure for CFAR module control */
    IfxSpu_CfarCAConfig             cfarCA;           /**< \brief Configuration structure for CFAR CA */
    IfxSpu_CfarGOSConfig            cfarGOS;          /**< \brief Configuration structure for CFAR GOS */
    IfxSpu_PowerOutputConfig        power;            /**< \brief Configuration structure for Power Information Channel */
    IfxSpu_FftOutputConfig          fftOut;           /**< \brief Configuration structure for FFT output */
    IfxSpu_SidebandStatisticsConfig statistics;       /**< \brief Configuration structure for Sideband Statistics */
} IfxSpu_PassConfig;

/** \} */

/** \addtogroup IfxLld_Spu_Std_DataStructures
 * \{ */
/** \brief SFRs which are related to linked-list configuration
 */
typedef struct
{
    Ifx_SPU_ID         ID;                 /**< \brief Input DMA Configuration Registers */
    Ifx_SPU_PACTR      PACTR;              /**< \brief Pre-Acquisition Counter */
    Ifx_SPU_DPASS_CONF DPASS_CONF;         /**< \brief Double Pass Configuration */
    Ifx_SPU_BE         BE[2];              /**< \brief SPU BE object */
    Ifx_SPU_BIN_REJ    BIN_REJ[64];        /**< \brief Bin Rejection Mask */
    Ifx_SPU_MAGAPPROX  MAGAPPROX;          /**< \brief Magnitude Approximation Constants */
    Ifx_SPU_NCI        NCI;                /**< \brief NCI Antennae Scaling Factors Registers */
    Ifx_SPU_CFAR       CFAR;               /**< \brief CFAR Configuration */
    Ifx_SPU_SCALARADD  SCALARADD;          /**< \brief Scalar Addition Operand */
    Ifx_SPU_SCALARMULT SCALARMULT;         /**< \brief Scalar Multiplication Operand */
    Ifx_SPU_BINREJCTRL BINREJCTRL;         /**< \brief Bin Rejection Unit Control */
    Ifx_SPU_LCLMAX     LCLMAX;             /**< \brief Local Maximum Control */
    Ifx_SPU_ACFG2      ACFG2;              /**< \brief Spare Configuration Register */
    uint32             reserved;           /**< \brief reserved */
    Ifx_SPU_REGCRC     REGCRC;             /**< \brief Register CRC */
    Ifx_SPU_CTRL       CTRL;               /**< \brief SPU Control */
    uint32             reserved1[4];
} IfxSpu_ConfigSlot;

/** \brief Configuration structure of the SPU module initialisation
 */
typedef struct
{
    IfxSpu_ClockDivisionRatio clockDivisionRatio;       /**< \brief clock division ratio for the FFT engine */
    IfxSpu_InterruptConfig    interrupt;                /**< \brief Configuration structure for enabling/disabling interrupt event */
} IfxSpu_ModuleConfig;

/** \brief Configuration structure for SPU
 */
typedef struct
{
    IfxSpu_FftInputConfig     input;                                 /**< \brief Configuration structure for FFT input */
    IfxSpu_CfarCAConfig       cfarCA;                                /**< \brief Configuration structure for CA-CFAR algorithm */
    IfxSpu_CfarGOSConfig      cfarGOS;                               /**< \brief Configuration structure for GOS-CFAR algorithm */
    IfxSpu_LocalMaxConfig     localMax;                              /**< \brief Configuration structure for Local Maximum unit */
    IfxSpu_BinRejectionConfig binrej;                                /**< \brief Configuration structure for Bin Rejection unit */
    uint16                    nciWeights[IFXSPU_MAX_ANTENNAE];       /**< \brief Antennae scaling factors. Range: 0 to 0xFFFF */
    IfxSpu_MagnitudeConfig    magnitude;                             /**< \brief Configuration structure for Magnitude approximation */
    IfxSpu_PassConfig         pass[2];                               /**< \brief Configuration Structure for Pass mode registers */
} IfxSpu_SlotConfig;

/** \brief Structure for statistical output
 */
typedef struct
{
    uint32 minPwr;          /**< \brief Minimum power. Range: 0 to 0xFFFFFFFF */
    uint32 maxPwr;          /**< \brief Maximum power. Range: 0 to 0xFFFFFFFF */
    uint32 meanPwr;         /**< \brief Mean power. Range: 0 to 0xFFFFFFFF */
    uint32 variance;        /**< \brief Variance. Range: 0 to 0xFFFFFFFF */
    uint16 minIdx;          /**< \brief Minimum Index. Range: 0 to 0xFFFFFFFF */
    uint16 maxIdx;          /**< \brief Maximum Index. Range: 0 to 0xFFFFFFFF */
    uint32 filler[3];       /**< \brief Filler to align into EMEM bus width. Range: 0 to 0xFFFFFFFF */
} IfxSpu_StatisticalOutput;

/** \} */

typedef struct
{
    IfxSpu_TriggerMode        mode;                   /**< \brief Trigger mode for the slot. (Not the nextSlot) */
    IfxSpu_ClockDivisionRatio clkDiv;                 /**< \brief Clock Divider */
    boolean                   trigger;                /**< \brief If set to TRUE, SPU will be triggered to commence data processing */
    boolean                   attentionRequest;       /**< \brief If set to TRUE, then a service request interrupt will be generated when the execution of the configuration is completed, even if this is not the last configuration in a linked list. */
    boolean                   crossTrigger;           /**< \brief If set to TRUE,an event will be triggered at the end of execution of the current configuration. */
} IfxSpu_CtrlConfig;

/** \brief Configuration structure for Log2 power summation unit contro
 */
typedef struct
{
    boolean enabled;           /**< \brief Enable / Disable choice for the power summation */
    uint32  baseAddress;       /**< \brief Base address to be used when writing data to Radar Memory. Range: 0 to 0x7FFFF */
} IfxSpu_Log2PowerSummationConfig;

/******************************************************************************/
/*-------------------------Inline Function Prototypes-------------------------*/
/******************************************************************************/

/**
 * \brief Returns the FFT size code corresponding to the specified length.
 *
 * \param[in] length  The FFT length to be converted to a size code.
 *                    Range: Must be a valid power of two.
 *
 * \retval IfxSpu_FftSize, The size code corresponding to the specified length.
 */
IFX_INLINE IfxSpu_FftSize IfxSpu_getSizeCode(uint32 length);

/**
 * \brief Checks if the SPU is currently busy.
 *
 * \param[in] spu  Pointer to the SPU register base.
 *
 * \retval TRUE  If the SPU is busy.
 *         FALSE If the SPU is not busy.
 */
IFX_INLINE boolean IfxSpu_isBusy(Ifx_SPU *spu);

/**
 * \brief Checks if the given CFAR mode is active.
 *
 * \param[in] mode  The CFAR mode to check.
 *                  Range: \ref IfxSpu_CFAR_Mode
 *
 * \retval TRUE  The mode is a valid CFAR mode.
 *         FALSE The mode is not a valid CFAR mode.
 */
IFX_INLINE boolean IfxSpu_isCfarMode(IfxSpu_CFAR_Mode mode);

/**
 * \brief Checks if the CFAR mode is a Local Max mode.
 *
 * \param[in] mode  The CFAR mode to check.
 *                  Range: \ref IfxSpu_CFAR_Mode
 *
 * \retval TRUE  The mode is a Local Max mode.
 *         FALSE The mode is not a Local Max mode.
 */
IFX_INLINE boolean IfxSpu_isLocalMaxMode(IfxSpu_CFAR_Mode mode);

/**
 * \brief Checks if the SPU module is currently suspended.
 *
 * \param[in] spu  Pointer to the SPU register base.
 *
 * \retval TRUE  Module is suspended.
 *         FALSE Module is not suspended.
 */
IFX_INLINE boolean IfxSpu_isModuleSuspended(Ifx_SPU *spu);

/**
 * \brief Rejects the specified bin number in the SPU configuration.
 *
 * \param[inout] slot       Pointer to a configuration slot.
 * \param[in]    binNumber  The bin number to be rejected.
 *
 * \retval None
 */
IFX_INLINE void IfxSpu_rejectBin(IfxSpu_ConfigSlot *slot, uint16 binNumber);

/**
 * \brief Configure the SPU module to operate in the specified suspend mode.
 *
 * \note: The api works only when the OCDS is enabled and in Supervisor Mode. When OCDS is disabled the OCS suspend control is ineffective.
 *
 * \param[inout] spu   Pointer to the SPU module registers.
 * \param[in]    mode  Suspend mode to be configured.
 *                     Range: \ref IfxSpu_SuspendMode
 *
 * \retval None
 */
IFX_INLINE void IfxSpu_setSuspendMode(Ifx_SPU *spu, IfxSpu_SuspendMode mode);

/**
 * \brief Configures the scalar addition operation for the SPU.
 *
 * \param[inout] slot     Pointer to a configuration slot.
 * \param[in]    operand  Additive scaling factor to be used for the scalar addition operation.
 *                        Range: 0 to 0xFFFF FFFF.
 *
 * \retval None
 */
IFX_INLINE void IfxSpu_setupScalarAddition(IfxSpu_ConfigSlot *slot, uint32 operand);

/**
 * \brief Configures the scalar multiplication operation for the SPU.
 *
 * \param[inout] slot     Pointer to a configuration slot.
 * \param[in]    operand  Multiplicative scaling factor to be applied to the FFT output data.
 *                        Range: 0 to 0xFFFF FFFF.
 *
 * \retval None
 */
IFX_INLINE void IfxSpu_setupScalarMultiplication(IfxSpu_ConfigSlot *slot, uint32 operand);

/**
 * \brief Returns the base pointer of the configuration RAM.
 *
 * \param[in] spu  Pointer to the SPU module registers.
 *
 * \retval None
 */
IFX_INLINE void *IfxSpu_getConfigRamPtr(Ifx_SPU *spu);

/**
 * \brief Checks if the specified SPU configuration slot is receiving input from the RIF module.
 *
 * \param[in] slot  Pointer to a configuration slot.
 *
 * \retval TRUE  If the slot is configured to receive input from the RIF module.
 *         FALSE If the slot is not configured to receive input from the RIF module.
 */
IFX_INLINE boolean IfxSpu_isRifInput(IfxSpu_ConfigSlot *slot);

/**
 * \brief Checks if the SPU configuration slot has a complex input format.
 *
 * \param[in] slot  Pointer to a configuration slot.
 *
 * \retval TRUE  The slot has a complex input format.
 *         FALSE The slot does not have a complex input format.
 */
IFX_INLINE boolean IfxSpu_isComplexInput(IfxSpu_ConfigSlot *slot);

/**
 * \brief Aligns the given dataset size to the next multiple of the EMEM bus size.
 *
 * \param[in] datasetSize  The size of the dataset in bytes that needs to be aligned.
 *                         Range: 0 to 0xFFFF FFFF.
 *
 * \retval uint32 The aligned size in bytes, which is the next multiple of the EMEM bus size greater than or equal to the input datasetSize.
 *         Range: 0 to 0xFFFF FFFF.
 */
IFX_INLINE uint32 IfxSpu_alignToBusSize(uint32 datasetSize);

/**
 * \brief Gets the input sample size in bytes for the specified radar memory input data format.
 *
 * \param[in] format  The input data format specification.
 *                    Range: \ref IfxSpu_RM_InputDataFormat.
 *
 * \retval uint32 The size of the input sample in bytes.
 *         Range: 0 to 7.
 */
IFX_INLINE uint32 IfxSpu_getInputSampleSize(IfxSpu_RM_InputDataFormat format);

/**
 * \brief Retrieves the ODP sample size in bytes based on the specified format.
 *
 * \param[in] format  The format of the ODP sample.
 *                     Range: \ref IfxSpu_ODP_Format.
 *
 * \retval uint32 The size of the FFT sample in bytes.
 *         Range: 0 to 7.
 */
IFX_INLINE uint32 IfxSpu_getFftSampleSize(IfxSpu_ODP_Format format);

/**
 * \brief Calculates the size of the FFT dataset in bytes based on the number of bins and the specified ODP format.
 *
 * \param[in] nBins  The number of bins in the FFT dataset.
 *                   Range: 0 to 0xFFFF FFFF.
 * \param[in] format The ODP format specifying the data type and scaling factor.
 *                   Range: \ref IfxSpu_ODP_Format.
 *
 * \retval uint32 The size of the FFT dataset in bytes.
 *         Range: 0 to 0xFFFF FFFF.
 */
IFX_INLINE uint32 IfxSpu_getFftDatasetSize(uint32 nBins, IfxSpu_ODP_Format format);

/**
 * \brief Calculates the size of the NCI dataset in bytes based on the number of bins and output format.
 *
 * \param[in] nBins  The number of bins.
 *                   Range: 0 to 0xFFFF FFFF.
 * \param[in] format The output format, determining the precision of the data.
 *                   Range: \ref IfxSpu_NCI_OutputFormat.
 *
 * \retval uint32 The size of the NCI dataset in bytes.
 *         Range: 0 to 0xFFFF FFFF.
 */
IFX_INLINE uint32 IfxSpu_getNciDatasetSize(uint32 nBins, IfxSpu_NCI_OutputFormat format);

/**
 * \brief Calculates the size of the summation dataset in bytes based on the number of bins, data format, and precision.
 *
 * \param[in] nBins      Number of bins.
 *                       Range: 0 to 0xFFFF FFFF.
 * \param[in] format     Data format specifying whether to use real or complex components.
 *                       Range: \ref IfxSpu_Summation_DataFormat.
 * \param[in] precision  Precision of the summation data.
 *                       Range: \ref IfxSpu_Summation_Precision.
 *
 * \retval uint32 The size of the summation dataset in bytes.
 *         Range: 0 to 0xFFFF FFFF.
 */
IFX_INLINE uint32 IfxSpu_getSummationDatasetSize(uint32 nBins, IfxSpu_Summation_DataFormat format, IfxSpu_Summation_Precision precision);

/**
 * \brief Calculates the size of the thresholding dataset in bytes.
 *
 * \param[in] Nf  Number of bins used in the thresholding operation.
 *
 * \retval uint16 The size of the thresholding dataset in bytes.
 *         Range: 0 to 16.
 */
IFX_INLINE uint16 IfxSpu_getThresholdingOutputSize(uint16 Nf);

/**
 * \brief Resets the Pre-Acquisition Counter (PACTR) to its initial state.
 *
 * \param[inout] slot  Pointer to a configuration slot.
 *
 * \retval None
 */
IFX_INLINE void IfxSpu_resetPactr(IfxSpu_ConfigSlot *slot);

/**
 * \brief Calculates and writes the CRC for the given SPU configuration slot.
 *
 * \param[inout] slot  Pointer to a configuration slot.
 *
 * \retval None
 */
IFX_INLINE void IfxSpu_calculateAndWriteRegisterCrc(IfxSpu_ConfigSlot *slot);

/**
 * \brief Clears and resets the Math1 configuration structure to its default values.
 *
 * \param[in] config  Pointer to the Math1 configuration structure to be cleared.
 *
 * \retval None
 */
IFX_INLINE void IfxSpu_clearMath1Config(IfxSpu_Math1Config *config);

/**
 * \brief Clears the FFT input configuration.
 *
 * \param[in] config  Pointer to the FFT input configuration structure.
 *
 * \retval None
 */
IFX_INLINE void IfxSpu_clearInputConfig(IfxSpu_FftInputConfig *config);

/******************************************************************************/
/*-------------------------Global Function Prototypes-------------------------*/
/******************************************************************************/

/**
 * \brief Checks the configuration slot for validity and consistency.
 *
 * \param[in] slot    Pointer to a configuration slot.
 * \param[in] caller  The name of the function or module that called this function,
 *                    used for debugging or logging purposes.
 * \param[in] line    The line number in the caller's source file where this function
 *                    was called, used for debugging or logging purposes.
 *
 * \retval None
 */
IFX_EXTERN void IfxSpu_checkConfigSlot(IfxSpu_ConfigSlot *slot, const char *caller, uint32 line);

/**
 * \brief Disables the SPU module, shutting down its operation and preparing it for a low-power state.
 *
 * \param[inout] spu Pointer to the SPU module registers.
 *
 * \retval None
 */
IFX_EXTERN void IfxSpu_disableModule(Ifx_SPU *spu);

/**
 * \brief Returns the memory address of the selected SPU module's registers.
 *
 * \param[in] spu  SPU module index to retrieve the address for.
 *
 * \retval Ifx_SPU* Base address of the selected SPU module's registers.
 */
IFX_EXTERN Ifx_SPU *IfxSpu_getAddress(IfxSpu_Index spu);

/**
 * \brief Retrieves a configuration slot for the specified SPU module.
 *
 * \param[in] spu     Pointer to the SPU module registers.
 * \param[in] slotNr  If 0 will return pointer to ID_CONF register of the spu, Else pointer to slotNr in the Configuration RAM. Maximum value of slotNr is \ref IFXSPU_CONFIG_SLOT_MAX.
 *                    Range: 1 to \ref IFXSPU_CONFIG_SLOT_MAX.
 *
 * \retval IfxSpu_ConfigSlot* Pointer to the requested configuration slot.
 */
IFX_EXTERN IfxSpu_ConfigSlot *IfxSpu_getConfigSlot(Ifx_SPU *spu, uint32 slotNr);

/**
 * \brief Retrieves the data source associated with a given configuration slot.
 *
 * \param[in] slot  Pointer to a configuration slot.
 *
 * \return IfxSpu_DataSource The data source associated with the configuration slot.
 *         Range: \ref IfxSpu_DataSource.
 */
IFX_EXTERN IfxSpu_DataSource IfxSpu_getDataSource(IfxSpu_ConfigSlot *slot);

/**
 * \brief Returns the module index of the selected SPU module.
 *
 * \param[in] spu Pointer to the SPU module registers.
 *
 * \retval IfxSpu_Index The module index of the selected SPU module.
 *         Range: \ref IfxSpu_Index.
 */
IFX_EXTERN IfxSpu_Index IfxSpu_getIndex(Ifx_SPU *spu);

/**
 * \brief Retrieves the number of connected antennae based on the input source configuration.
 *
 * \param[in] slot  Pointer to a configuration slot.
 *
 * \retval uint16 Number of connected antennae when input is from RIF.
 *                Zero when input is from EMEM.
 */
IFX_EXTERN uint16 IfxSpu_getNumConnectedAntennae(IfxSpu_ConfigSlot *slot);

/**
 * \brief Retrieves the number of input samples per vector for the specified SPU configuration slot.
 *
 * \param[in] slot  Pointer to a configuration slot.
 *
 * \retval uint16 The number of input samples per vector, represented as an unsigned 16-bit integer.
 *         Range: 0 to 0x1FFFF.
 */
IFX_EXTERN uint16 IfxSpu_getNumInputSamples(IfxSpu_ConfigSlot *slot);

/**
 * \brief Gets the number of input ramps when the input is sourced from RIF (not from EMEM).
 *
 * \param[in] slot  Pointer to a configuration slot. (see \ref IfxSpu_getConfigSlot())
 *
 * \retval uint16 Number of ramps when input is from RIF; zero if input is from EMEM.
 */
IFX_EXTERN uint16 IfxSpu_getNumRamps(IfxSpu_ConfigSlot *slot);

/**
 * \brief Initialises the SPU module with the specified configuration.
 *
 * \param[inout] spu    Pointer to the SPU module registers.
 * \param[in]    config Configuration structure containing settings for clock division and interrupt handling.
 *
 * \retval None
 */
IFX_EXTERN void IfxSpu_initModule(Ifx_SPU *spu, const IfxSpu_ModuleConfig *config);

/**
 * \brief Initializes the specified SPU module configuration structure with default values.
 *
 * \param[inout] config The configuration structure to be initialized.
 *
 * \retval None
 */
IFX_EXTERN void IfxSpu_initModuleConfig(IfxSpu_ModuleConfig *config);

/**
 * \brief Loads configuration data into the specified SPU's configuration RAM.
 *
 * \param[in] spu      Pointer to the SPU module registers.
 * \param[in] dataPtr  Pointer to the location of source data to load.
 * \param[in] offset32 Offset in the configuration RAM where the data will be loaded (in 32-bit words).
 *                     Range: 0 to 0xFFFF FFFF.
 * \param[in] count32  Number of 32-bit words to transfer from the source data to the configuration RAM.
 *                     Range: 0 to 0xFFFF FFFF.
 *
 * \retval None
 */
IFX_EXTERN void IfxSpu_loadConfigRAM(Ifx_SPU *spu, const void *dataPtr, uint32 offset32, uint32 count32);

/**
 * \brief Reloads the configuration for the specified SPU slot.
 *
 * \param[inout] spu     Pointer to the SPU module registers.
 * \param[in]    slotNr  Configuration slot number to reload.
 *                       Range: 1 to \ref IFXSPU_CONFIG_SLOT_MAX.
 *
 * \retval None
 */
IFX_EXTERN void IfxSpu_reloadConfig(Ifx_SPU *spu, uint32 slotNr);

/**
 * \brief Resets the Non-Coherent Integration (NCI) Antennae scaling factors to their default values.
 *
 * \param[inout] slot Pointer to a configuration slot. (see \ref IfxSpu_getConfigSlot())
 *
 * \retval None
 */
IFX_EXTERN void IfxSpu_resetNciWeights(IfxSpu_ConfigSlot *slot);

/**
 * \brief Configures the pass mode for the specified DMA engine configuration slot.
 *
 * \param[inout] slot     Pointer to a configuration slot. (see \ref IfxSpu_getConfigSlot())
 * \param[in]    passMode The pass mode to be configured.
 *                        Range: \ref IfxSpu_PassMode.
 *
 * \retval None
 */
IFX_EXTERN void IfxSpu_setPassMode(IfxSpu_ConfigSlot *slot, IfxSpu_PassMode passMode);

/**
 * \brief Configures the Bin Rejection unit with the specified settings.
 *
 * \param[inout] slot   Pointer to a configuration slot. (see \ref IfxSpu_getConfigSlot())
 * \param[in]    config Configuration structure for Bin Rejection unit.
 *
 * \retval None
 */
IFX_EXTERN void IfxSpu_setupBinRejection(IfxSpu_ConfigSlot *slot, const IfxSpu_BinRejectionConfig *config);

/**
 * \brief Configures the CFAR module for the SPU.
 *
 * \param[inout] slot   Pointer to a configuration slot. (see \ref IfxSpu_getConfigSlot())
 * \param[in]    passId Processing instance number to select the register instance for the base engine (BEx).
 * \param[in]    config Pointer to a configuration structure for CFAR module control.
 *
 * \retval None
 */
IFX_EXTERN void IfxSpu_setupCfar(IfxSpu_ConfigSlot *slot, IfxSpu_PassId passId, const IfxSpu_CfarConfig *config);

/**
 * \brief Configures the CFAR CA (Constant False Alarm Rate - Cell Averaging) algorithm for the specified slot.
 * 
 * \param[inout] slot    Pointer to a configuration slot. (see \ref IfxSpu_getConfigSlot())
 * \param[in]    config  Pointer to the configuration structure CA-CFAR algorithm.
 * 
 * \retval None
 */
IFX_EXTERN void IfxSpu_setupCfarCA(IfxSpu_ConfigSlot *slot, const IfxSpu_CfarCAConfig *config);

/**
 * \brief Configures the CFAR GOS algorithm for a given configuration slot.
 *
 * \param[inout] slot   Pointer to a configuration slot. (see \ref IfxSpu_getConfigSlot())
 * \param[in]    config Pointer to the configuration structure containing GOS-CFAR algorithm parameters.
 *
 * \retval None
 */
IFX_EXTERN void IfxSpu_setupCfarGOS(IfxSpu_ConfigSlot *slot, const IfxSpu_CfarGOSConfig *config);

/**
 * \brief Configures the specified slot in the SPU with the provided control configuration and links it to the next slot if specified.
 *
 * \param[in] spu        Pointer to the SPU module registers.
 * \param[in] slotNr     Configuration slot number to reload.
 *                       Range: 1 to \ref IFXSPU_CONFIG_SLOT_MAX.
 * \param[in] nextSlotNr Next slot number to link to. If set to zero, the current slot will be the last in the sequence.
 *                       Range: 1 to \ref IFXSPU_CONFIG_SLOT_MAX.
 * \param[in] ctrlConfig Pointer to the control configuration structure containing parameters for the slot configuration.
 *
 * \retval None
 */
IFX_EXTERN void IfxSpu_setupConfigSequence(Ifx_SPU *spu, uint32 slotNr, uint32 nextSlotNr, IfxSpu_CtrlConfig *ctrlConfig);

/**
 * \brief Setup the FFT streaming processor, initializing input and output parameters for the FFT engine.
 *
 * \param[inout] slot   Pointer to a configuration slot. (see \ref IfxSpu_getConfigSlot())
 * \param[in]    passId Processing instance number to choose the register instance for the base engine (BEx).
 *                      Range: \ref IfxSpu_PassId.
 * \param[in]    config Pointer to a configuration structure for the FFT engine.
 *
 * \retval None
 */
IFX_EXTERN void IfxSpu_setupFft(IfxSpu_ConfigSlot *slot, IfxSpu_PassId passId, const IfxSpu_FftConfig *config);

/**
 * \brief Setup the FFT output by initializing parameters for the Output Data Processor (ODP).
 *
 * \param[inout] slot    Pointer to a configuration slot. (see \ref IfxSpu_getConfigSlot())
 * \param[in]    passId  Processing instance number to select the register instance for the base engine (BEx).
 *                       Range: \ref IfxSpu_PassId.
 * \param[in]    config  Pointer to a configuration structure containing FFT output settings.
 *
 * \retval None
 */
IFX_EXTERN void IfxSpu_setupFftOutput(IfxSpu_ConfigSlot *slot, IfxSpu_PassId passId, const IfxSpu_FftOutputConfig *config);

/**
 * \brief Configures the histogram setup for the SPU.
 *
 * \param[inout] slot  Pointer to a configuration slot. (see \ref IfxSpu_getConfigSlot())
 * \param[in] passId   Processing instance number to select the register instance for the base engine (BEx).
 *                     Range: \ref IfxSpu_PassId.
 * \param[in] config   Pointer to the histogram configuration structure.
 *
 * \retval None
 */
IFX_EXTERN void IfxSpu_setupHistogram(IfxSpu_ConfigSlot *slot, IfxSpu_PassId passId, const IfxSpu_HistogramConfig *config);

/**
* \brief Configures the input parameters for the FFT processing and initializes the input DMA engine.
*
* \param[inout] slot    Pointer to a configuration slot. (see \ref IfxSpu_getConfigSlot())
* \param[in]    config  Pointer to the configuration structure containing FFT input settings.
*
* \retval None
*/
IFX_EXTERN void IfxSpu_setupInput(IfxSpu_ConfigSlot *slot, const IfxSpu_FftInputConfig *config);

/**
 * \brief Configures the Local Maximum unit with specified parameters.
 *
 * \param[inout] slot    Pointer to a configuration slot. (see \ref IfxSpu_getConfigSlot())
 * \param[in]    config  Pointer to a Local Max configuration structure.
 *
 * \retval None
 */
IFX_EXTERN void IfxSpu_setupLocalMax(IfxSpu_ConfigSlot *slot, const IfxSpu_LocalMaxConfig *config);

/**
 * \brief Configures the magnitude approximation settings for the SPU.
 *
 * \param[inout] slot   Pointer to a configuration slot. (see \ref IfxSpu_getConfigSlot())
 * \param[in]    config Pointer to the magnitude configuration structure.
 *
 * \retval None
 */
IFX_EXTERN void IfxSpu_setupMagnitude(IfxSpu_ConfigSlot *slot, IfxSpu_MagnitudeConfig *config);

/**
 * \brief Setup the Math1 unit, initializing parameters for the Math1 unit of the streaming processor.
 *
 * \param[inout] slot   Pointer to a configuration slot. (see \ref IfxSpu_getConfigSlot())
 * \param[in]    passId Processing instance number to select the register instance for the base engine (BEx).
 *                      Range: \ref IfxSpu_PassId.
 * \param[in]    config Pointer to a configuration structure for the Math1 unit.
 *
 * \retval None
 */
IFX_EXTERN void IfxSpu_setupMath1(IfxSpu_ConfigSlot *slot, IfxSpu_PassId passId, const IfxSpu_Math1Config *config);

/**
 * \brief Configures the Non-Coherent Integration (NCI) unit for the SPU.
 *
 * \param[inout] slot   Pointer to a configuration slot. (see \ref IfxSpu_getConfigSlot())
 * \param[in]    passId Processing instance number to select the register instance for the base engine (BEx).
 *                      Range: \ref IfxSpu_PassId.
 * \param[in]    config Pointer to the Non-Coherent intergration configuration structure.
 *
 * \retval None
 */
IFX_EXTERN void IfxSpu_setupNci(IfxSpu_ConfigSlot *slot, IfxSpu_PassId passId, const IfxSpu_NciConfig *config);

/**
 * \brief Configures the Non-Coherent Integration (NCI) Antennae scaling factors for the SPU.
 *
 * \param[inout] slot    Pointer to a configuration slot. (see \ref IfxSpu_getConfigSlot())
 * \param[in]    weights Array of scaling factors for the antennae.
 *                       Range: 0 to 7.
 *
 * \retval None
 */
IFX_EXTERN void IfxSpu_setupNciWeights(IfxSpu_ConfigSlot * slot, uint16 weights[IFXSPU_MAX_ANTENNAE]);

/**
 * \brief Setup the Power Information Channel.
 *
 * \param[inout] slot    Pointer to a configuration slot. (see \ref IfxSpu_getConfigSlot())
 * \param[in]    passId  Processing instance number to select the register instance for the base engine (BEx).
 *                       Range: \ref IfxSpu_PassId.
 * \param[in]    config  Pointer to Configuration structure for the Power Information Channel.
 *
 * \retval None
 */
IFX_EXTERN void IfxSpu_setupPowerChannel(IfxSpu_ConfigSlot *slot, IfxSpu_PassId passId, const IfxSpu_PowerOutputConfig *config);

/**
 * \brief Configures the Sideband statistics setup for the SPU.
 *
 * \param[inout] slot   Pointer to a configuration slot. (see \ref IfxSpu_getConfigSlot())
 * \param[in]    passId Processing instance number to select the register instance for the base engine (BEx).
 *                      Range: \ref IfxSpu_PassId.
 * \param[in]    config Pointer to the Sideband Statistics configuration structure.
 *
 * \retval None
 */
IFX_EXTERN void IfxSpu_setupSidebandStatistics(IfxSpu_ConfigSlot *slot, IfxSpu_PassId passId, const IfxSpu_SidebandStatisticsConfig *config);

/**
 * \brief Configures the Summation unit with the specified parameters.
 *
 * \param[inout] slot   Pointer to a configuration slot. (see \ref IfxSpu_getConfigSlot())
 * \param[in]    passId Processing instance number to select the register instance for the base engine (BEx).
 *                      Range: \ref IfxSpu_PassId.
 * \param[in]    config Pointer to a Configuration structure for Summation unit.
 *
 * \retval None
 */
IFX_EXTERN void IfxSpu_setupSummation(IfxSpu_ConfigSlot *slot, IfxSpu_PassId passId, const IfxSpu_SummationConfig *config);

/**
 * \brief Trigger the SPU operation by software.
 *
 * \param[inout] spu Pointer to the SPU module registers.
 *
 * \retval None
 */
IFX_EXTERN void IfxSpu_swTrigger(Ifx_SPU *spu);

/**
 * \brief Computes the CRC value for the SPU_REGCRC register based on the provided configuration slot.
 *
 * \param[in] slot Pointer to a configuration slot. (see \ref IfxSpu_getConfigSlot())
 *
 * \retval uint32 The computed 32-bit CRC value for the specified configuration slot.
 *
 * Example usage:
 * uint32 configSlotNr = 0; // 0 = SFR slot, 1 = slot in Configuration RAM.
 * uint32 regcrc = IfxSpu_calculateRegisterCrc(&MODULE_SPU0, configSlotNr);
 * slot->REGCRC.U = regcrc;
 */
IFX_EXTERN uint32 IfxSpu_calculateRegisterCrc(IfxSpu_ConfigSlot *slot);

/**
 * \brief Writes a set of configuration values to a specified slot in the SPU.
 *
 * \param[in] spu        Pointer to the SPU module registers.
 * \param[in] slotNr     Configuration slot number to reload.
 *                       Range: 1 to \ref IFXSPU_CONFIG_SLOT_MAX.
 * \param[in] slotValues Pointer to an array of uint32 values containing the configuration data to write.
 *                       Range: 0 to 0xFFFF FFFF.
 *
 * \retval None
 */
IFX_EXTERN void IfxSpu_writeConfigSlot(Ifx_SPU *spu, uint32 slotNr, const uint32 *slotValues);

/**
 * \brief Configures the Log2 power summation unit based on the provided configuration.
 *
 * \param[inout] slot   Pointer to a configuration slot. (see \ref IfxSpu_getConfigSlot())
 * \param[in]    passId Processing instance number to select the register instance for the base engine (BEx).
 *                      Range: \ref IfxSpu_PassId.
 * \param[in]    config Pointer to the configuration structure for Log2 power summation unit.
 *
 * \retval None
 */
IFX_EXTERN void IfxSpu_setupLog2PowerSummation(IfxSpu_ConfigSlot *slot, IfxSpu_PassId passId, const IfxSpu_Log2PowerSummationConfig *config);

/**
 * \brief Enables the module by allowing clock to the module.
 *
 * \param[inout] spu Pointer to the SPU module registers.
 *
 * \retval None
 */
IFX_EXTERN void IfxSpu_enableModule(Ifx_SPU *spu);

/**
 * \brief Resets the specified SPU module to its initial state.
 *
 * \param[inout] spu  Pointer to the SPU module registers.
 *
 * \retval None
 */
IFX_EXTERN void IfxSpu_resetModule(Ifx_SPU *spu);

/**
 * \brief Waits until the reload operation for the specified SPU module has completed.
 *
 * \param[in] spu Pointer to the SPU module registers.
 *
 * \retval None
 */
IFX_EXTERN void IfxSpu_waitReload(Ifx_SPU *spu);

/**
 * \brief Retrieves the FFT output format based on the provided SPU configuration slot and pass number.
 *
 * \param[in] slot   Pointer to a configuration slot. (see \ref IfxSpu_getConfigSlot())
 * \param[in] passNr Pass number for which the FFT output format is to be retrieved.
 *                   Range: 0 to 1.
 *
 * \retval IfxSpu_ODP_Format The output data format of the FFT operation.
 *         Range: \ref IfxSpu_ODP_Format.
 */
IFX_EXTERN IfxSpu_ODP_Format IfxSpu_getFftOutputFormat(IfxSpu_ConfigSlot *slot, uint8 passNr);

/******************************************************************************/
/*-------------------Global Exported Variables/Constants----------------------*/
/******************************************************************************/

IFX_EXTERN IFX_CONST uint32 IfxSpu_crcTable[];

IFX_EXTERN IFX_CONST uint8  IfxSpu_reflect8[];

/******************************************************************************/
/*---------------------Inline Function Implementations------------------------*/
/******************************************************************************/

IFX_INLINE IfxSpu_FftSize IfxSpu_getSizeCode(uint32 length)
{
    return (IfxSpu_FftSize)(31 - __clz(length));
}


IFX_INLINE boolean IfxSpu_isBusy(Ifx_SPU *spu)
{
    Ifx_SPU_CTRL ctrl;
    ctrl.U = spu->CTRL.U;
    return ctrl.B.BUSY != 0;
}


IFX_INLINE boolean IfxSpu_isCfarMode(IfxSpu_CFAR_Mode mode)
{
    boolean result = FALSE;

    if ((mode == IfxSpu_CFAR_Mode_inline) || (mode == IfxSpu_CFAR_Mode_offline) || (mode == IfxSpu_CFAR_Mode_nci))
    {
        result = TRUE;
    }

    return result;
}


IFX_INLINE boolean IfxSpu_isLocalMaxMode(IfxSpu_CFAR_Mode mode)
{
    boolean result = FALSE;

    if ((mode == IfxSpu_CFAR_Mode_localMaxInline) || (mode == IfxSpu_CFAR_Mode_localMaxOffline) || (mode == IfxSpu_CFAR_Mode_localMaxInline))
    {
        result = TRUE;
    }

    return result;
}


IFX_INLINE boolean IfxSpu_isModuleSuspended(Ifx_SPU *spu)
{
    Ifx_SPU_OCS ocs;

    // read the status
    ocs.U = spu->OCS.U;

    // return the status
    return ocs.B.SUSSTA;
}


IFX_INLINE void IfxSpu_rejectBin(IfxSpu_ConfigSlot *slot, uint16 binNumber)
{
    uint32          index  = binNumber / 32;
    uint32          binPos = binNumber % 32;
    uint32          mask   = 1 << binPos;

    Ifx_SPU_BIN_REJ binRej;
    /* reject the selected bin */
    binRej.U               = slot->BIN_REJ[index].U;
    binRej.U              &= (~mask);
    slot->BIN_REJ[index].U = binRej.U;
}


IFX_INLINE void IfxSpu_setSuspendMode(Ifx_SPU *spu, IfxSpu_SuspendMode mode)
{
    Ifx_SPU_OCS ocs;

    // remove protection and configure the suspend mode.
    ocs.B.SUS_P = 1;
    ocs.B.SUS   = mode;
    spu->OCS.U  = ocs.U;
}


IFX_INLINE void IfxSpu_setupScalarAddition(IfxSpu_ConfigSlot *slot, uint32 operand)
{
    /* Set the additive scaling factor for FFT output data */
    Ifx_SPU_SCALARADD scalarAdd;
    scalarAdd.U         = slot->SCALARADD.U;
    scalarAdd.B.OPERAND = operand;
    slot->SCALARADD.U   = scalarAdd.U;
}


IFX_INLINE void IfxSpu_setupScalarMultiplication(IfxSpu_ConfigSlot *slot, uint32 operand)
{
    /* Set the multiplicative scaling factor to be applied to the FFT output data */
    Ifx_SPU_SCALARMULT scalarMult;
    scalarMult.U         = slot->SCALARMULT.U;
    scalarMult.B.OPERAND = operand;
    slot->SCALARMULT.U   = scalarMult.U;
}


IFX_INLINE void *IfxSpu_getConfigRamPtr(Ifx_SPU *spu)
{
    void *configRamPtr = NULL_PTR;

    if (spu == &MODULE_SPU0)
    {
        configRamPtr = (void *)IFXSPU_CONFIG_RAM0_BASE;
    }
#if IFXSPU_NUM_MODULES > 1
    else if (spu == &MODULE_SPU1)
    {
        configRamPtr = (void *)IFXSPU_CONFIG_RAM1_BASE;
    }
#endif
    return configRamPtr;
}


IFX_INLINE boolean IfxSpu_isRifInput(IfxSpu_ConfigSlot *slot)
{
    boolean result = FALSE;

    if (slot->ID.CONF.B.SRC != IfxSpu_DataSource_emem)
    {
        result = TRUE;
    }

    return result;
}


IFX_INLINE boolean IfxSpu_isComplexInput(IfxSpu_ConfigSlot *slot)
{
    boolean result = FALSE;

    if (FALSE == IfxSpu_isRifInput(slot))
    {
        switch (slot->ID.RM_CONF.B.FORMAT)
        {
        case IfxSpu_RM_InputDataFormat_complex16Bit: result     = TRUE; break;
        case IfxSpu_RM_InputDataFormat_complex32Bit: result     = TRUE; break;
        case IfxSpu_RM_InputDataFormat_complexHalfFloat: result = TRUE; break;
        }
    }
    else
    {
        result = (slot->ID.CONF.B.FORMAT == IfxSpu_InputDataFormat_complex);
    }

    return result;
}


IFX_INLINE uint32 IfxSpu_alignToBusSize(uint32 datasetSize)
{
    /* align to EMEM bus size */
    const uint32 bytesInBus       = 256 / 8;
    uint32       nBusTransactions = datasetSize / bytesInBus;
    nBusTransactions = nBusTransactions + (0 != (datasetSize % bytesInBus));
    datasetSize      = bytesInBus * nBusTransactions;

    return datasetSize;
}


IFX_INLINE uint32 IfxSpu_getInputSampleSize(IfxSpu_RM_InputDataFormat format)
{
    uint32 sampleSize;

    if (format == IfxSpu_RM_InputDataFormat_complex32Bit)
    {
        sampleSize = 8;
    }
    else if (format == IfxSpu_RM_InputDataFormat_real16Bit)
    {
        sampleSize = 2;
    }
    else if (format == IfxSpu_RM_InputDataFormat_realHalfFloat)
    {
        sampleSize = 2;
    }
    else
    {
        /* complex16Bit, complexHalfFloat */
        sampleSize = 4;
    }

    return sampleSize;
}


IFX_INLINE uint32 IfxSpu_getFftSampleSize(IfxSpu_ODP_Format format)
{
    uint32 sampleSize;

    if (format == IfxSpu_ODP_Format_complex32Bit)
    {
        sampleSize = 8;
    }
    else if (format == IfxSpu_ODP_Format_real16Bit)
    {
        sampleSize = 2;
    }
    else if (format == IfxSpu_ODP_Format_realHalfFloat)
    {
        sampleSize = 2;
    }
    else
    {
        /* complex16Bit, complexHalfFloat */
        sampleSize = 4;
    }

    return sampleSize;
}


IFX_INLINE uint32 IfxSpu_getFftDatasetSize(uint32 nBins, IfxSpu_ODP_Format format)
{
    uint32 datasetSize = (nBins * IfxSpu_getFftSampleSize(format));
    return IfxSpu_alignToBusSize(datasetSize);
}


IFX_INLINE uint32 IfxSpu_getNciDatasetSize(uint32 nBins, IfxSpu_NCI_OutputFormat format)
{
    uint32 binSize;

    if (format == IfxSpu_NCI_OutputFormat_real32Bit)
    {
        binSize = 4;
    }
    else if (format == IfxSpu_NCI_OutputFormat_real16Bit)
    {
        binSize = 2;
    }
    else
    {
        binSize = 0;
    }

    uint32 datasetSize = (nBins * binSize);
    return IfxSpu_alignToBusSize(datasetSize);
}


IFX_INLINE uint32 IfxSpu_getSummationDatasetSize(uint32 nBins, IfxSpu_Summation_DataFormat format, IfxSpu_Summation_Precision precision)
{
    uint32 binSize;

    if ((format == IfxSpu_Summation_DataFormat_complex) && (precision == IfxSpu_Summation_Precision_32bit))
    {
        binSize = 8;
    }
    else if ((format == IfxSpu_Summation_DataFormat_real) && (precision == IfxSpu_Summation_Precision_16bit))
    {
        binSize = 2;
    }
    else
    {
        binSize = 4;
    }

    uint32 datasetSize = (nBins * binSize);
    return IfxSpu_alignToBusSize(datasetSize);
}


IFX_INLINE uint16 IfxSpu_getThresholdingOutputSize(uint16 Nf)
{
    uint16 N8;

    if (Nf == 0)
    {
        N8 = 0;
    }
    else if (Nf <= 8)
    {
        N8 = 1;
    }
    else if (Nf <= 16)
    {
        N8 = 2;
    }
    else if (Nf <= 32)
    {
        N8 = 4;
    }
    else if (Nf <= 64)
    {
        N8 = 8;
    }
    else if (Nf <= 128)
    {
        N8 = 16;
    }
    else
    {
        N8 = ((Nf >> 8) + (0 != (Nf & 255))) << 5;
    }

    return N8;
}


IFX_INLINE void IfxSpu_resetPactr(IfxSpu_ConfigSlot *slot)
{
    Ifx_SPU_PACTR pactr;
    pactr.U       = slot->PACTR.U;
    pactr.B.RST   = 1;
    slot->PACTR.U = pactr.U;
}


IFX_INLINE void IfxSpu_calculateAndWriteRegisterCrc(IfxSpu_ConfigSlot *slot)
{
    slot->REGCRC.U = IfxSpu_calculateRegisterCrc(slot);
}


IFX_INLINE void IfxSpu_clearMath1Config(IfxSpu_Math1Config *config)
{
    uint32 byte_count = sizeof(IfxSpu_Math1Config);
    uint8 *addr       = (uint8 *)config;

    while (byte_count--)
    {
        *(addr++) = 0U;
    }
}


IFX_INLINE void IfxSpu_clearInputConfig(IfxSpu_FftInputConfig *config)
{
    uint32 byte_count = sizeof(IfxSpu_FftInputConfig);
    uint8 *addr       = (uint8 *)config;

    while (byte_count--)
    {
        *(addr++) = 0U;
    }
}


#endif /* IFXSPU_H */
