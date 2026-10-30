/**
 * \file IfxCif.h
 * \brief CIF  basic functionality
 * \ingroup IfxLld_Cif
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
 * \defgroup IfxLld_Cif_Std_stdEnumerations Standard Enumerations
 * \ingroup IfxLld_Cif_Std
 * \defgroup IfxLld_Cif_Std_ispEnum ISP Enumerations
 * \ingroup IfxLld_Cif_Std
 * \defgroup IfxLld_Cif_Std_stdFunctions Standard Functions
 * \ingroup IfxLld_Cif_Std
 * \defgroup IfxLld_Cif_Std_ispFunctions ISP Functions
 * \ingroup IfxLld_Cif_Std
 * \defgroup IfxLld_Cif_Std_ldsFunctions Linear Downscaler Functions
 * \ingroup IfxLld_Cif_Std
 * \defgroup IfxLld_Cif_Std_ldsEnumerations Linear Downscaler Enumerations
 * \ingroup IfxLld_Cif_Std
 * \defgroup IfxLld_Cif_Std_miFunctions Memory Interface Functions
 * \ingroup IfxLld_Cif_Std
 * \defgroup IfxLld_Cif_Std_miEnumerations Memory Interface Enumerations
 * \ingroup IfxLld_Cif_Std
 * \defgroup IfxLld_Cif_Std_jpeFunctions JPEG Encoder Functions
 * \ingroup IfxLld_Cif_Std
 * \defgroup IfxLld_Cif_Std_jpeEnumerations JPEG Encoder Enumerations
 * \ingroup IfxLld_Cif_Std
 * \defgroup IfxLld_Cif_Std_swFunctions Security Watchdog Functions
 * \ingroup IfxLld_Cif_Std
 * \defgroup IfxLld_Cif_Std_swEnumerations Security Watchdog Enumerations
 * \ingroup IfxLld_Cif_Std
 * \defgroup IfxLld_Cif_Std_ispisFunctions ISP Image Stabilization Functions
 * \ingroup IfxLld_Cif_Std
 * \defgroup IfxLld_Cif_Std_ispisEnumerations ISP Image Stabilization Enumerations
 * \ingroup IfxLld_Cif_Std
 * \defgroup IfxLld_Cif_Std_epFunctions Extra Path Functions
 * \ingroup IfxLld_Cif_Std
 * \defgroup IfxLld_Cif_Std_epEnumerations Extra Path Enumerations
 * \ingroup IfxLld_Cif_Std
 * \defgroup IfxLld_Cif_Std_dpFunctions Debug Path Functions
 * \ingroup IfxLld_Cif_Std
 * \defgroup IfxLld_Cif_Std_dpEnumerations Debug Path Enumerations
 * \ingroup IfxLld_Cif_Std
 */

#ifndef IFXCIF_H
#define IFXCIF_H 1

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include "_Impl/IfxCif_cfg.h"
#include "Scu/Std/IfxScuWdt.h"
#include "IfxCif_bf.h"
#include "IfxCif_reg.h"
#include "Cpu/Std/IfxCpu_Intrinsics.h"

/******************************************************************************/
/*--------------------------------Enumerations--------------------------------*/
/******************************************************************************/

/** \addtogroup IfxLld_Cif_Std_stdEnumerations
 * \{ */
/** \brief Enumerator for data path of main path
 * Definition in MODULE_CIF.DPCL.B.CIF_MP_MUX
 */
typedef enum
{
    IfxCif_DataPathSelectorForMainPath_Disabled                          = 0,  /**< \brief Main path is disabled */
    IfxCif_DataPathSelectorForMainPath_DataToMemoryInterfaceUncompressed = 1,  /**< \brief Main path is routed to the Memory Interface */
    IfxCif_DataPathSelectorForMainPath_DataToJpegEncoder                 = 2   /**< \brief Main path is routed to the JPEG encoder */
} IfxCif_DataPathSelectorForMainPath;

/** \brief Enumerator for the state of an error
 * Definition in MODULE_CIF.MIEP.STA_ERR.B.EP_5_FIFO_FULL, MODULE_CIF.MIEP.STA_ERR.B.EP_4_FIFO_FULL, MODULE_CIF.MIEP.STA_ERR.B.EP_3_FIFO_FULL, MODULE_CIF.MIEP.STA_ERR.B.EP_2_FIFO_FULL,
 * MODULE_CIF.MIEP.STA_ERR.B.EP_1_FIFO_FULL, MODULE_CIF.MIEP.STA_ERR.B.EP_5_IC_SIZE_ERR, MODULE_CIF.MIEP.STA_ERR.B.EP_4_IC_SIZE_ERR, MODULE_CIF.MIEP.STA_ERR.B.EP_3_IC_SIZE_ERR,
 * MODULE_CIF.MIEP.STA_ERR.B.EP_2_IC_SIZE_ERR, and MODULE_CIF.MIEP.STA_ERR.B.EP_1_IC_SIZE_ERR.
 * MODULE_CIF.MI.STATUS.B.BUS_WRITE_ERROR, MODULE_CIF.MI.STATUS.B.MP_CR_FIFO_FULL, MODULE_CIF.MI.STATUS.B.MP_CB_FIFO_FULL, MODULE_CIF.MI.STATUS.B.MP_Y_FIFO_FULL
 */
typedef enum
{
    IfxCif_ErrorState_NoError = 0,  /**< \brief No error occurred */
    IfxCif_ErrorState_Error   = 1   /**< \brief Error occurred */
} IfxCif_ErrorState;

/** \brief Enumerator for the extra paths
 * Definition in Ifx_CIF.Ep[5] and Ifx_CIF_MIEP. CH_1S[5];
 */
typedef enum
{
    IfxCif_ExtraPath_1 = 0,
    IfxCif_ExtraPath_2 = 1,
    IfxCif_ExtraPath_3 = 2,
    IfxCif_ExtraPath_4 = 3,
    IfxCif_ExtraPath_5 = 4
} IfxCif_ExtraPath;

/** \brief Enumerator for tiers
 * Definition in MODULE_CIF.ISPIS.H_OFFS.U
 */
typedef enum
{
    IfxCif_ImageTiers_Horizontal = 0,  /**< \brief Horizontal tier */
    IfxCif_ImageTiers_Vertical   = 1   /**< \brief Vertical tier */
} IfxCif_ImageTiers;

/** \brief Enumerator for input interfaces supported by the CIF interface
 * Definition in MODULE_CIF.DPCL.B.IF_SELECT
 */
typedef enum
{
    IfxCif_InputInterface_ParallelInterface = 0  /**< \brief Parallel interface (currently the only supported input interface) */
} IfxCif_InputInterface;

/** \brief Enumerator for the state of an interrupt
 * Definition in MODULE_CIF.JPE.ERROR_MIS.B.VLC_TABLE_ERR, MODULE_CIF.JPE.ERROR_MIS.B.R2B_IMG_SIZE_ERR, MODULE_CIF.JPE.ERROR_MIS.B.DCT_ERR, MODULE_CIF.JPE.ERROR_MIS.B.VLC_SYMBOL_ERR,
 * MODULE_CIF.JPE.STATUS_MIS.B.GEN_HEADER_DONE, MODULE_CIF.JPE.STATUS_MIS.B.ENCODE_DONE, MODULE_CIF.MI.MIS.B.BUS_ERROR, MODULE_CIF.MI.MIS.B.WRAP_MP_CR, MODULE_CIF.MI.MIS.B.WRAP_MP_CB,
 * MODULE_CIF.MI.MIS.B.WRAP_MP_Y, MODULE_CIF.MI.MIS.B.FILL_MP_Y, MODULE_CIF.MI.MIS.B.MBLK_LINE, MODULE_CIF.MI.MIS.B.MP_FRAME_END, MODULE_CIF.WD.MIS.B.MIS_WD_VES_TO, MODULE_CIF.WD.MIS.B.MIS_WD_VSE_TO,
 * MODULE_CIF.WD.MIS.B.MIS_WD_HES_TO, MODULE_CIF.WD.MIS.B.MIS_WD_HSE_TO, MODULE_CIF.JPE.ERROR_RIS.B.VLC_TABLE_ERR, MODULE_CIF.JPE.ERROR_RIS.B.R2B_IMG_SIZE_ERR, MODULE_CIF.JPE.ERROR_RIS.B.DCT_ERR,
 * MODULE_CIF.JPE.ERROR_RIS.B.VLC_SYMBOL_ERR, MODULE_CIF.JPE.STATUS_RIS.B.GEN_HEADER_DONE, MODULE_CIF.JPE.STATUS_RIS.B.ENCODE_DONE, MODULE_CIF.MI.RIS.B.BUS_ERROR, MODULE_CIF.MI.RIS.B.WRAP_MP_CR,
 * MODULE_CIF.MI.RIS.B.WRAP_MP_CB, MODULE_CIF.MI.RIS.B.WRAP_MP_Y, MODULE_CIF.MI.RIS.B.FILL_MP_Y, MODULE_CIF.MI.RIS.B.MBLK_LINE, MODULE_CIF.MI.RIS.B.MP_FRAME_END. MODULE_CIF.WD.RIS.B.RIS_WD_VES_TO,
 * MODULE_CIF.WD.RIS.B.RIS_WD_VSE_TO, MODULE_CIF.WD.RIS.B.RIS_WD_HES_TO, MODULE_CIF.WD.RIS.B.RIS_WD_HSE_TO.
 */
typedef enum
{
    IfxCif_InterruptTriggeredState_NotTriggered = 0,  /**< \brief Interrupt was not triggered */
    IfxCif_InterruptTriggeredState_Triggered    = 1   /**< \brief Interrupt was triggered */
} IfxCif_InterruptTriggeredState;

/** \brief Enumerator for port input selections
 */
typedef enum
{
    IfxCif_PortInputSelection_PinMapping0 = 0,  /**< \brief pin mapping 0 */
    IfxCif_PortInputSelection_PinMapping1 = 1   /**< \brief pin mapping 1 */
} IfxCif_PortInputSelection;

/** \brief Enumerator for states
 */
typedef enum
{
    IfxCif_State_Disabled = 0,  /**< \brief Disabled state */
    IfxCif_State_Enabled  = 1   /**< \brief Enabled state */
} IfxCif_State;

/** \brief Enumerator for submodules of the CIF interface
 */
typedef enum
{
    IfxCif_Submodules_AllModules            = 0,  /**< \brief All submodules */
    IfxCif_Submodules_Debug                 = 1,  /**< \brief Debug submodule */
    IfxCif_Submodules_ExtraPaths            = 2,  /**< \brief Extra Paths submodule */
    IfxCif_Submodules_LinearDownscaler      = 3,  /**< \brief Linear Downscaler submodule */
    IfxCif_Submodules_SecurityWatchdog      = 4,  /**< \brief Security Watchdog submodule */
    IfxCif_Submodules_MemoryInterface       = 5,  /**< \brief Memory Interface submodule */
    IfxCif_Submodules_JpegEncoder           = 6,  /**< \brief JPEG Encoder submodule */
    IfxCif_Submodules_ImageSignalProcessing = 7,  /**< \brief Image Signal Processing submodule */
    IfxCif_Submodules_YCSplitter            = 8   /**< \brief Y/C-Splitter submodule */
} IfxCif_Submodules;

/** \brief Enumerator for channel mode of Y/C splitter
 * Definition in MODULE_CIF.DPCL.B.CIF_CHAN_MODE
 */
typedef enum
{
    IfxCif_YCSplitterChannelMode_Disabled           = 0, /**< \brief Y/C splitter is disabled */
    IfxCif_YCSplitterChannelMode_MainPathAndRawMode = 1  /**< \brief Y/C splitter is enabled for main path and RAW mode */
} IfxCif_YCSplitterChannelMode;

/** \} */

/** \addtogroup IfxLld_Cif_Std_ispEnum
 * \{ */
/** \brief Enumerator for the ISP CCIR sequence
 * Definition in MODULE_CIF.ISP.ACQ_PROP.B.CCIR_SEQ
 */
typedef enum
{
    IfxCif_IspCcirSequence_YCbYCr = 0,  /**< \brief YCbYCr */
    IfxCif_IspCcirSequence_YCrYCb = 1,  /**< \brief YCrYCb */
    IfxCif_IspCcirSequence_CbYCrY = 2   /**< \brief CbYCrY */
} IfxCif_IspCcirSequence;

/** \brief Enumerator for the clipping range of the crominance for the ISP output
 * Definition in MODULE_CIF.ISP.CTRL.B.ISP_CSM_C_RANGE
 */
typedef enum
{
    IfxCif_IspColorSpaceMatrixCrominanceClippingRange_16To240 = 0,  /**< \brief CbCr range 16..240 according to ITU-R BT.601 standard */
    IfxCif_IspColorSpaceMatrixCrominanceClippingRange_0To255  = 1   /**< \brief full UV range 0..255 */
} IfxCif_IspColorSpaceMatrixCrominanceClippingRange;

/** \brief Enumerator for the clipping range of the luminance for the ISP output
 * Definition in MODULE_CIF.ISP.CTRL.B.ISP_CSM_Y_RANGE
 */
typedef enum
{
    IfxCif_IspColorSpaceMatrixLuminanceClippingRange_16To235 = 0,  /**< \brief Y range 16..235 according to ITU-R BT.601 standard */
    IfxCif_IspColorSpaceMatrixLuminanceClippingRange_0To255  = 1   /**< \brief full Y range 0..255 */
} IfxCif_IspColorSpaceMatrixLuminanceClippingRange;

/** \brief Enumerator for error sources of the ISP module
 */
typedef enum
{
    IfxCif_IspErrorSources_SizeErrorInOutmuxSubmodule             = 0,  /**< \brief Size error is generated in outmux submodule */
    IfxCif_IspErrorSources_SizeErrorInImageStabilizationSubmodule = 1,  /**< \brief Size error is generated in image stabilization submodule */
    IfxCif_IspErrorSources_SizeErrorInInformSubmodule             = 2   /**< \brief ize error is generated in inform submodule */
} IfxCif_IspErrorSources;

/** \brief Enumerator for the sampled input fields
 * Definition in MODULE_CIF.ISP.ACQ_PROP.B.FIELD_SELECTION
 */
typedef enum
{
    IfxCif_IspFieldSelection_AllFields      = 0,  /**< \brief sample all fields (don't care about fields) */
    IfxCif_IspFieldSelection_OnlyEvenFields = 1,  /**< \brief sample only even fields */
    IfxCif_IspFieldSelection_OnlyOddFields  = 2   /**< \brief sample only odd fields */
} IfxCif_IspFieldSelection;

/** \brief Enumerator for current field information
 * Definition in MODULE_CIF.ISP.FLAGS_SHD.B.INFORM_FIELD
 */
typedef enum
{
    IfxCif_IspInformFieldInformation_Odd  = 0, /**< \brief Odd field */
    IfxCif_IspInformFieldInformation_Even = 1  /**< \brief Even field */
} IfxCif_IspInformFieldInformation;

/** \brief Enumerator for the supported input interfaces of the ISP
 * Definition in MODULE_CIF.ISP.ACQ_PROP.B.INPUT_SELECTION
 */
typedef enum
{
    IfxCif_IspInputInterface_8BitExternalInterfaceAppendMsb    = 0,  /**< \brief 8-bit external Interface if enabled append 8 MSBs as LSBs */
    IfxCif_IspInputInterface_8BitExternalInterfaceAppendZeros  = 1,  /**< \brief 8-bit external Interface if enabled append 8 zeroes as LSBs */
    IfxCif_IspInputInterface_10BitExternalInterfaceAppendMsb   = 2,  /**< \brief 10-bit external Interface if enabled append 6 MSBs as LSBs */
    IfxCif_IspInputInterface_10BitExternalInterfaceAppendZeros = 3,  /**< \brief 10-bit external Interface if enabled append 6 zeroes as LSBs */
    IfxCif_IspInputInterface_12BitExternalInterfaceAppendMsb   = 4,  /**< \brief 12-bit external Interface if enabled append 4 MSBs as LSBs */
    IfxCif_IspInputInterface_12BitExternalInterfaceAppendZeros = 5,  /**< \brief 12-bit external Interface if enabled append 4 zeroes as LSBs */
    IfxCif_IspInputInterface_14BitExternalInterfaceAppendMsb   = 6,  /**< \brief 14-bit external Interface if enabled append 2 MSBs as LSBs */
    IfxCif_IspInputInterface_14BitExternalInterfaceAppendZeros = 7,  /**< \brief 14-bit external Interface if enabled append 2 zeroes as LSBs */
    IfxCif_IspInputInterface_16BitExternalInterface            = 8   /**< \brief 16-bit external Interface */
} IfxCif_IspInputInterface;

/** \brief Enumerator for interrupt sources of the ISP submodule
 */
typedef enum
{
    IfxCif_IspInterruptSources_SecurityWatchdogTimeout      = 0,  /**< \brief A watchdog timeout was triggered at the ISP input */
    IfxCif_IspInterruptSources_StartEdgeOfHSync             = 1,  /**< \brief Start Edge of h_sync */
    IfxCif_IspInterruptSources_StartEdgeOfVSync             = 2,  /**< \brief Start Edge of v_sync */
    IfxCif_IspInterruptSources_SampledInputFrameComplete    = 3,  /**< \brief Sampled Input Frame is Complete */
    IfxCif_IspInterruptSources_PictureSizeViolationOccurred = 4,  /**< \brief Picture Size Violation Occurred */
    IfxCif_IspInterruptSources_LossOfData                   = 5,  /**< \brief Loss of Data */
    IfxCif_IspInterruptSources_FrameCompletelyPutOut        = 6,  /**< \brief Frame was Completely Put Out */
    IfxCif_IspInterruptSources_IspTurnedOff                 = 7   /**< \brief Isp was Turned Off (vsynced) */
} IfxCif_IspInterruptSources;

/** \brief Enumerator for the ISP mode
 * Definition in MODULE_CIF.ISP.CTRL.B.ISP_MODE
 */
typedef enum
{
    IfxCif_IspMode_RawPicture                  = 0, /**< \brief RAW picture */
    IfxCif_IspMode_ItuRBT656                   = 1, /**< \brief ITU-R BT.656 (YUV with embedded sync) */
    IfxCif_IspMode_ItuRBT601                   = 2, /**< \brief ITU-R BT.601 (YUV input with H and Vsync signals) */
    IfxCif_IspMode_DataMode                    = 4, /**< \brief datamode (ISP bypass, sync signals interpreted as data enable) */
    IfxCif_IspMode_RawPictureWithItuRBT656Sync = 6  /**< \brief RAW picture mode with ITU-R BT.656 synchronization */
} IfxCif_IspMode;

/** \brief Enumerator for ISP sampling edge
 * Definition in MODULE_CIF.ISP.ACQ_PROP.B.SAMPLE_EDGE and IfxCif_Cam_Config.samplingEdge
 */
typedef enum
{
    IfxCif_IspSamplingEdge_NegativeEdge = 0,  /**< \brief negative edge sampling */
    IfxCif_IspSamplingEdge_PositiveEdge = 1   /**< \brief positive edge sampling */
} IfxCif_IspSamplingEdge;

/** \brief
 * Definition in MODULE_CIF.ISP.ACQ_PROP.B.VSYNC_POL, IfxCif_Cam_Config.hSyncPolarity and IfxCif_Cam_Config.vSyncPolarity
 */
typedef enum
{
    IfxCif_IspSyncPolarity_HighActive = 0,  /**< \brief high active sync polarity */
    IfxCif_IspSyncPolarity_LowActive  = 1   /**< \brief low active sync polarity */
} IfxCif_IspSyncPolarity;

/** \} */

/** \addtogroup IfxLld_Cif_Std_ldsEnumerations
 * \{ */
/** \brief Enumerator for scaling mode of linear downscaler
 * Definition in Ifx_CIF_LDS_CTRL.B.LDS_H_MODE, inIfx_CIF_LDS_CTRL.B.LDS_V_MODE, IfxCif_Cam_Config->downscaling.hMode and IfxCif_Cam_Config->downscaling.vMode
 */
typedef enum
{
    IfxCif_LinearDownscalerScalingMode_SingleSkip = 0,  /**< \brief Scaling mode single skip */
    IfxCif_LinearDownscalerScalingMode_DoubleSkip = 1,  /**< \brief Scaling mode double skip */
    IfxCif_LinearDownscalerScalingMode_SinglePass = 2,  /**< \brief Scaling mode single pass */
    IfxCif_LinearDownscalerScalingMode_DoublePass = 3,  /**< \brief Scaling mode double pass */
    IfxCif_LinearDownscalerScalingMode_Disabled   = -1  /**< \brief Disabled */
} IfxCif_LinearDownscalerScalingMode;

/** \} */

/** \addtogroup IfxLld_Cif_Std_miEnumerations
 * \{ */
/** \brief Enumerator for burst length affecting the write port of the memory interface
 * Definition in MODULE_CIF.MI.CTRL.B.BURST_LEN_LUM and MODULE_CIF.MI.CTRL.B.BURST_LEN_CHROM
 */
typedef enum
{
    IfxCif_MiBurstLength_4BeatBursts = 0,  /**< \brief 4-beat bursts */
    IfxCif_MiBurstLength_8BeatBursts = 1   /**< \brief 8-beat bursts */
} IfxCif_MiBurstLength;

/** \brief Enumerator for data paths of the memory interface
 */
typedef enum
{
    IfxCif_MiDataPaths_RawData         = 0, /**< \brief RAW data path */
    IfxCif_MiDataPaths_JpegData        = 1, /**< \brief JPEG data path */
    IfxCif_MiDataPaths_MainPictureData = 2  /**< \brief main picture data path */
} IfxCif_MiDataPaths;

/** \brief Enumerator for interrupt sources of the memory interface submodule
 * Definition in MODULE_CIF.MI.IMSC
 */
typedef enum
{
    IfxCif_MiInterruptSources_BusError            = 0, /**< \brief Bus write or read error interrupt (from handshake target interfaces) */
    IfxCif_MiInterruptSources_WrapMainPictureCr   = 1, /**< \brief Main picture Cr address wrap interrupt */
    IfxCif_MiInterruptSources_WrapMainPictureCb   = 2, /**< \brief Main picture Cb address wrap interrupt */
    IfxCif_MiInterruptSources_WrapMainPictureY    = 3, /**< \brief Main picture Y address wrap interrupt */
    IfxCif_MiInterruptSources_FillMainPictureY    = 4, /**< \brief Main picture Y address wrap interrupt */
    IfxCif_MiInterruptSources_MacroBlockLine      = 5, /**< \brief Macroblock line interrupt of main picture (16 lines of Y, 8 lines of Cb and 8 lines of Cr are written into RAM) */
    IfxCif_MiInterruptSources_MainPictureFrameEnd = 6  /**< \brief Picture end of frame interrupt */
} IfxCif_MiInterruptSources;

/** \brief Enumerator for main picture path components of the memory interface
 */
typedef enum
{
    IfxCif_MiMainPicturePathComponents_Y  = 0,  /**< \brief Y-component */
    IfxCif_MiMainPicturePathComponents_Cb = 1,  /**< \brief Cb-component */
    IfxCif_MiMainPicturePathComponents_Cr = 2   /**< \brief Cr-component */
} IfxCif_MiMainPicturePathComponents;

/** \brief Enumerator for write formats of data written into memory
 * Definition in MODULE_CIF.MI.CTRL.B.MP_WRITE_FORMAT
 */
typedef enum
{
    IfxCif_MiMainPictureWriteFormat_PlanarOrData8Bit             = 0, /**< \brief planar (YCbCr mode) / RAW & data mode (8 bit) */
    IfxCif_MiMainPictureWriteFormat_SemiPlanarOrData8Bit         = 1, /**< \brief semi-planar for YCbCr 4:2:x / RAW 8 bit */
    IfxCif_MiMainPictureWriteFormat_InterleavedOrDataGreater8Bit = 2  /**< \brief interleaved_combined for YCbCr 4:2:2 only / RAW & data mode (greater 8 up to 16 bit) */
} IfxCif_MiMainPictureWriteFormat;

/** \brief Enumerator for status clear sources of the memory interface module
 */
typedef enum
{
    IfxCif_MiStatusClearSources_ExtraPath5FifoFull    = 0,  /**< \brief FIFO full flag in extra path 5 */
    IfxCif_MiStatusClearSources_ExtraPath4FifoFull    = 1,  /**< \brief FIFO full flag in extra path 4 */
    IfxCif_MiStatusClearSources_ExtraPath3FifoFull    = 2,  /**< \brief FIFO full flag in extra path 3 */
    IfxCif_MiStatusClearSources_ExtraPath2FifoFull    = 3,  /**< \brief FIFO full flag in extra path 2 */
    IfxCif_MiStatusClearSources_ExtraPath1FifoFull    = 4,  /**< \brief FIFO full flag in extra path 1 */
    IfxCif_MiStatusClearSources_BusWriteError         = 5,  /**< \brief Bus write error flag */
    IfxCif_MiStatusClearSources_MainPictureCrFifoFull = 6,  /**< \brief Cr FIFO full flag in main path */
    IfxCif_MiStatusClearSources_MainPictureCbFifoFull = 7,  /**< \brief Cb FIFO full flag in main path */
    IfxCif_MiStatusClearSources_MainPictureYFifoFull  = 8   /**< \brief Y FIFO full flag in main path */
} IfxCif_MiStatusClearSources;

/** \brief Enumerator for status information sources of the memory interface submodule
 */
typedef enum
{
    IfxCif_MiStatusInformationSources_BusWriteError         = 0,  /**< \brief An Bus error occurred while writing to the Bus (main/self path) since last clear */
    IfxCif_MiStatusInformationSources_MainPictureCrFifoFull = 1,  /**< \brief FIFO full flag of Cr FIFO in main path asserted since last clear */
    IfxCif_MiStatusInformationSources_MainPictureCbFifoFull = 2,  /**< \brief FIFO full flag of Cb FIFO in main path asserted since last clear */
    IfxCif_MiStatusInformationSources_MainPictureYFifoFull  = 3   /**< \brief FIFO full flag of Y FIFO in main path asserted since last clear */
} IfxCif_MiStatusInformationSources;

/** \} */

/** \addtogroup IfxLld_Cif_Std_jpeEnumerations
 * \{ */
/** \brief Enumerator for the Huffman Table components
 * Definition in MODULE_CIF.JPE.DC_TABLE_SELECT and MODULE_CIF.JPE.AC_TABLE_SELECT.B.AC_TABLE_SELECT
 */
typedef enum
{
    IfxCif_HuffmanTableComponents_Component0 = 0,  /**< \brief Component 0 */
    IfxCif_HuffmanTableComponents_Component1 = 1,  /**< \brief Component 1 */
    IfxCif_HuffmanTableComponents_Component2 = 2   /**< \brief Component 2 */
} IfxCif_HuffmanTableComponents;

/** \brief Enumerator for the Huffman Tables
 */
typedef enum
{
    IfxCif_HuffmanTables_Table0 = 0,  /**< \brief Huffman Table 0 */
    IfxCif_HuffmanTables_Table1 = 1   /**< \brief Huffman Table 1 */
} IfxCif_HuffmanTables;

/** \brief Enumerator for the debug signal sources
 */
typedef enum
{
    IfxCif_JpeDebugSignalSources_BadTableAccess = 0,  /**< \brief Debug Bad Table Access (set if an access to the TABLE_DATA or to the TABLE_ID register is performed, when the JPEG_ENCODER is busy) */
    IfxCif_JpeDebugSignalSources_VlcTableBusy   = 1,  /**< \brief Debug VLC Table Busy (vlc access to hufftables) */
    IfxCif_JpeDebugSignalSources_R2BMemoryFull  = 2,  /**< \brief R2B Memory Full (line memory status of r2b) */
    IfxCif_JpeDebugSignalSources_VlcEncodeBusy  = 3,  /**< \brief VLC Encode Busy (vlc encode processing active) */
    IfxCif_JpeDebugSignalSources_QiqTableAccess = 4   /**< \brief QiqTableAccess */
} IfxCif_JpeDebugSignalSources;

/** \brief Enumerator for the debug signal state
 * Definition in MODULE_CIF.JPE.DEBUG.B.DEB_BAD_TABLE_ACCESS, MODULE_CIF.JPE.DEBUG.B.DEB_VLC_TABLE_BUSY, MODULE_CIF.JPE.DEBUG.B.DEB_R2B_MEMORY_FULL,
 * MODULE_CIF.JPE.DEBUG.B.DEB_VLC_ENCODE_BUSY, MODULE_CIF.JPE.DEBUG.B.DEB_QIQ_TABLE_ACC.
 */
typedef enum
{
    IfxCif_JpeDebugSignalState_Inactive = 0,  /**< \brief Debug signal is inactive */
    IfxCif_JpeDebugSignalState_Active   = 1   /**< \brief Debug signal is active */
} IfxCif_JpeDebugSignalState;

/** \brief Enumerator for the header generation debug control
 * Definition in MODULE_CIF.JPE.TABLE_FLUSH.B.TABLE_FLUSH
 */
typedef enum
{
    IfxCif_JpeHeaderGenerationMode_WaitForEncodedImage     = 0, /**< \brief wait for encoded image data to fill output buffer */
    IfxCif_JpeHeaderGenerationMode_TransmitLastHeaderBytes = 1  /**< \brief immediately transmit last header bytes */
} IfxCif_JpeHeaderGenerationMode;

/** \brief Enumerator for the JPE header mode
 * Definition in MODULE_CIF.JPE.HEADER_MODE.B.HEADER_MODE
 */
typedef enum
{
    IfxCif_JpeHeaderMode_NoAppnHeader = 0,  /**< \brief no APPn header */
    IfxCif_JpeHeaderMode_JfifHeader   = 2   /**< \brief JFIF header */
} IfxCif_JpeHeaderMode;

/** \brief Enumerator for interrupt sources of the JPEG encoder module
 * Definition in MODULE_CIF.JPE.ERROR_IMR and MODULE_CIF.JPE.STATUS_IMR
 */
typedef enum
{
    IfxCif_JpeInterruptSources_VlcTableError            = 0,  /**< \brief VLC table error */
    IfxCif_JpeInterruptSources_R2BImageSizeError        = 1,  /**< \brief R2B image size error */
    IfxCif_JpeInterruptSources_DcTableError             = 2,  /**< \brief DC Table error */
    IfxCif_JpeInterruptSources_VlcSymbolError           = 3,  /**< \brief VLC symbol error */
    IfxCif_JpeInterruptSources_HeaderGenerationComplete = 4,  /**< \brief Header generation complete */
    IfxCif_JpeInterruptSources_EncodingComplete         = 5   /**< \brief Encoding complete */
} IfxCif_JpeInterruptSources;

/** \brief Enumerator for the Q-Table selector
 * Definition in MODULE_CIF.JPE.TQ_Y_SELECT.B.TQ0_SELECT
 */
typedef enum
{
    IfxCif_JpeQTableSelector_Table0 = 0,  /**< \brief Q-Table 0 */
    IfxCif_JpeQTableSelector_Table1 = 1,  /**< \brief Q-Table 1 */
    IfxCif_JpeQTableSelector_Table2 = 2,  /**< \brief Q-Table 2 */
    IfxCif_JpeQTableSelector_Table3 = 3   /**< \brief Q-Table 3 */
} IfxCif_JpeQTableSelector;

/** \brief Enumerator for the components to select Q-Tables
 */
typedef enum
{
    IfxCif_JpeQTableSelectorComponents_Y = 0,  /**< \brief Y-component */
    IfxCif_JpeQTableSelectorComponents_U = 1,  /**< \brief U-component */
    IfxCif_JpeQTableSelectorComponents_V = 2   /**< \brief V-component */
} IfxCif_JpeQTableSelectorComponents;

/** \brief Enumerator for the input scaling values of the JPEG encoder
 */
typedef enum
{
    IfxCif_JpeScalingValueSources_Y    = 0, /**< \brief scaling Y input from [16..235] to [0..255] */
    IfxCif_JpeScalingValueSources_CbCr = 1  /**< \brief scaling Cb/Cr input from [16..240] to [0..255] */
} IfxCif_JpeScalingValueSources;

/** \brief Enumerator for the codec state
 * Definition in MODULE_CIF.JPE.ENCODER_BUSY.B.CODEC_BUSY
 */
typedef enum
{
    IfxCif_JpeState_Free = 0,  /**< \brief Codec is free (not busy) */
    IfxCif_JpeState_Busy = 1   /**< \brief JPEG codec in process */
} IfxCif_JpeState;

/** \brief Enumerator for the JPE Tables
 * Definition in MODULE_CIF.JPE.TABLE_ID.B.TABLE_ID
 */
typedef enum
{
    IfxCif_JpeTableId_QTable0     = 0,  /**< \brief Q-Table 0 */
    IfxCif_JpeTableId_QTable1     = 1,  /**< \brief Q-Table 1 */
    IfxCif_JpeTableId_QTable2     = 2,  /**< \brief Q-Table 2 */
    IfxCif_JpeTableId_QTable3     = 3,  /**< \brief Q-Table 3 */
    IfxCif_JpeTableId_VlcDcTable0 = 4,  /**< \brief VLC DC Table 0 */
    IfxCif_JpeTableId_VlcAcTable0 = 5,  /**< \brief VLC AC Table 0 */
    IfxCif_JpeTableId_VlcDcTable1 = 6,  /**< \brief VLC DC Table 1 */
    IfxCif_JpeTableId_VlcAcTable1 = 7   /**< \brief VLC AC Table 1 */
} IfxCif_JpeTableId;

/** \brief Enumerator for the JFIF stream encoder continuous mode
 * Definition in MODULE_CIF.JPE.ENCODE.B.CONT_MODE
 */
typedef enum
{
    IfxCif_JpegJfifStreamEncoderContinuousMode_StopAtFrameEnd                      = 0, /**< \brief encoder stops at frame end */
    IfxCif_JpegJfifStreamEncoderContinuousMode_StartAutomatically                  = 1, /**< \brief encoder starts automatically to encode the next frame */
    IfxCif_JpegJfifStreamEncoderContinuousMode_GenerateHeaderAndStartAutomatically = 3  /**< \brief encoder first generates next header and then encodes automatically the next frame */
} IfxCif_JpegJfifStreamEncoderContinuousMode;

/** \brief Enumerator for the picture encoding format
 * Definition in MODULE_CIF.JPE.PIC_FORMAT.B.ENC_PIC_FORMAT
 */
typedef enum
{
    IfxCif_JpegPictureEncodingFormat_422 = 0,  /**< \brief 4:2:2 format */
    IfxCif_JpegPictureEncodingFormat_400 = 1   /**< \brief 4:0:0 format */
} IfxCif_JpegPictureEncodingFormat;

/** \} */

/** \addtogroup IfxLld_Cif_Std_swEnumerations
 * \{ */
/** \brief Enumerator for watchdog counters
 */
typedef enum
{
    IfxCif_SecurityWatchdogCounters_Predivider = 0,  /**< \brief Predivider counter */
    IfxCif_SecurityWatchdogCounters_Vertical   = 1,  /**< \brief Vertical counter */
    IfxCif_SecurityWatchdogCounters_Horizontal = 2   /**< \brief Horizontal counter */
} IfxCif_SecurityWatchdogCounters;

/** \brief Enumerator for interrupt sources of the security watchdog submodule
 */
typedef enum
{
    IfxCif_SecurityWatchdogInterruptSources_VerticalEndStartTimeout   = 0,  /**< \brief Vertical End Start Interrupt */
    IfxCif_SecurityWatchdogInterruptSources_VerticalStartEndTimeout   = 1,  /**< \brief Vertical Start End Interrupt */
    IfxCif_SecurityWatchdogInterruptSources_HorizontalEndStartTimeout = 2,  /**< \brief Horizontal End Start Interrupt */
    IfxCif_SecurityWatchdogInterruptSources_HorizontalStartEndTimeout = 3   /**< \brief Horizontal Start End Interrupt */
} IfxCif_SecurityWatchdogInterruptSources;

/** \brief Enumerator for watchdog timeout counters
 */
typedef enum
{
    IfxCif_SecurityWatchdogTimeoutCounters_EndStart = 0,  /**< \brief Timeout counter for End Start phase */
    IfxCif_SecurityWatchdogTimeoutCounters_StartEnd = 1   /**< \brief Timeout counter for Start End phase */
} IfxCif_SecurityWatchdogTimeoutCounters;

/** \} */

/** \addtogroup IfxLld_Cif_Std_epEnumerations
 * \{ */
/** \brief Enumerator for error sources that can be cleared in the extra paths registers
 */
typedef enum
{
    IfxCif_EpErrorClearSources_ExtraPath5SizeError = 0,  /**< \brief Size error in image cropping unit of extra path 5 */
    IfxCif_EpErrorClearSources_ExtraPath4SizeError = 1,  /**< \brief Size error in image cropping unit of extra path 4 */
    IfxCif_EpErrorClearSources_ExtraPath3SizeError = 2,  /**< \brief Size error in image cropping unit of extra path 3 */
    IfxCif_EpErrorClearSources_ExtraPath2SizeError = 3,  /**< \brief Size error in image cropping unit of extra path 2 */
    IfxCif_EpErrorClearSources_ExtraPath1SizeError = 4   /**< \brief Size error in image cropping unit of extra path 1 */
} IfxCif_EpErrorClearSources;

/** \brief Enumerator for error sources of extra paths
 */
typedef enum
{
    IfxCif_EpErrorSources_ExtraPath5FifoFull  = 0,  /**< \brief FIFO of extra path 5 is full */
    IfxCif_EpErrorSources_ExtraPath4FifoFull  = 1,  /**< \brief FIFO of extra path 4 is full */
    IfxCif_EpErrorSources_ExtraPath3FifoFull  = 2,  /**< \brief FIFO of extra path 3 is full */
    IfxCif_EpErrorSources_ExtraPath2FifoFull  = 3,  /**< \brief FIFO of extra path 2 is full */
    IfxCif_EpErrorSources_ExtraPath1FifoFull  = 4,  /**< \brief FIFO of extra path 1 is full */
    IfxCif_EpErrorSources_ExtraPath5SizeError = 5,  /**< \brief Size error in image cropping unit of extra path 5 */
    IfxCif_EpErrorSources_ExtraPath4SizeError = 6,  /**< \brief Size error in image cropping unit of extra path 4 */
    IfxCif_EpErrorSources_ExtraPath3SizeError = 7,  /**< \brief Size error in image cropping unit of extra path 3 */
    IfxCif_EpErrorSources_ExtraPath2SizeError = 8,  /**< \brief Size error in image cropping unit of extra path 2 */
    IfxCif_EpErrorSources_ExtraPath1SizeError = 9   /**< \brief Size error in image cropping unit of extra path 1 */
} IfxCif_EpErrorSources;

/** \brief Enumerator for extra path features
 */
typedef enum
{
    IfxCif_EpFeatures_InitOffsetCounter = 0,  /**< \brief Init offest counter */
    IfxCif_EpFeatures_InitBaseAddress   = 1,  /**< \brief Init buffer base address */
    IfxCif_EpFeatures_ByteSwap          = 2,  /**< \brief Byte swap feature */
    IfxCif_EpFeatures_PictureDataPath   = 3   /**< \brief enables the extra path picture data path */
} IfxCif_EpFeatures;

/** \brief Enumerator for interrupt sources of the extra paths module
 */
typedef enum
{
    IfxCif_EpInterrupts_FrameEnd       = IFX_CIF_MIEP_MIS_FRAME_END_EP_1_OFF,  /**< \brief Picture end of frame interrupt */
    IfxCif_EpInterrupts_FillLevel      = IFX_CIF_MIEP_MIS_FILL_EP_1_OFF,       /**< \brief Fill level interrupt */
    IfxCif_EpInterrupts_WrapAround     = IFX_CIF_MIEP_MIS_WRAP_EP_1_OFF,       /**< \brief Address wrap interrupt */
    IfxCif_EpInterrupts_MacroBlockLine = IFX_CIF_MIEP_MIS_MBLK_LINE_EP_1_OFF,  /**< \brief Macroblock line interrupt */
    IfxCif_EpInterrupts_Count          = 4                                     /**< \brief Total number of interrupt sources for one extra path */
} IfxCif_EpInterrupts;

/** \brief Enumerator for write formats of extra paths
 * Definition in MODULE_CIF.MIEP.CH_1S[5].CTRL.B.EP_WRITE_FORMAT;
 */
typedef enum
{
    IfxCif_EpWriteFormat_RawAndData = 0,  /**< \brief Raw and data mode (8 bit) */
    IfxCif_EpWriteFormat_Raw8Bit    = 1,  /**< \brief Raw 8 bit mode */
    IfxCif_EpWriteFormat_RawGreater = 2,  /**< \brief RAW & data mode (greater 8 up to 16 bit) */
    IfxCif_EpWriteFormat_YCbCr      = 3   /**< \brief YCbCr 16 bit; YCbCr data is handled interleaved as 16 bit data in extra paths */
} IfxCif_EpWriteFormat;

/** \} */

/** \addtogroup IfxLld_Cif_Std_dpEnumerations
 * \{ */
/** \brief Enumerator for debug path control sources
 */
typedef enum
{
    IfxCif_DpControlSources_UserDefinedSymbol8 = 0,  /**< \brief User defined symbol 8 */
    IfxCif_DpControlSources_UserDefinedSymbol7 = 1,  /**< \brief User defined symbol 7 */
    IfxCif_DpControlSources_UserDefinedSymbol6 = 2,  /**< \brief User defined symbol 6 */
    IfxCif_DpControlSources_UserDefinedSymbol5 = 3,  /**< \brief User defined symbol 5 */
    IfxCif_DpControlSources_UserDefinedSymbol4 = 4,  /**< \brief ser defined symbol 4 */
    IfxCif_DpControlSources_UserDefinedSymbol3 = 5,  /**< \brief User defined symbol 3 */
    IfxCif_DpControlSources_UserDefinedSymbol2 = 6,  /**< \brief User defined symbol 2 */
    IfxCif_DpControlSources_UserDefinedSymbol1 = 7,  /**< \brief User defined symbol 1 */
    IfxCif_DpControlSources_TimestampCounter   = 8,  /**< \brief Timestamp counter */
    IfxCif_DpControlSources_LineNumberCounter  = 9,  /**< \brief Line number counter */
    IfxCif_DpControlSources_FrameNumberCounter = 10  /**< \brief Frame number counter */
} IfxCif_DpControlSources;

/** \brief Enumerator for debug path counters
 */
typedef enum
{
    IfxCif_DpCounters_PredividerCounter  = 0, /**< \brief Predivider counter */
    IfxCif_DpCounters_TimestampCounter   = 1, /**< \brief Timestamp counter */
    IfxCif_DpCounters_LineNumberCounter  = 2, /**< \brief Line number counter */
    IfxCif_DpCounters_FrameNumberCounter = 3  /**< \brief Frame number counter */
} IfxCif_DpCounters;

/** \brief Enumerator for debug path source paths
 * Definition in MODULE_CIF.DP.CTRL.B.DP_SEL
 */
typedef enum
{
    IfxCif_DpSourcePath_MainPath   = 0,  /**< \brief Main data path */
    IfxCif_DpSourcePath_ExtraPath1 = 1,  /**< \brief Extra path 1 */
    IfxCif_DpSourcePath_ExtraPath2 = 2,  /**< \brief Extra path 2 */
    IfxCif_DpSourcePath_ExtraPath4 = 4,  /**< \brief Extra path 4 */
    IfxCif_DpSourcePath_ExtraPath5 = 5   /**< \brief Extra path 5 */
} IfxCif_DpSourcePath;

/** \} */

/******************************************************************************/
/*-----------------------------Data Structures--------------------------------*/
/******************************************************************************/

typedef struct
{
    uint16 priority;		/**< \brief Service Request Priority Number. Range: 0 to 0xFFFF */
    uint16 provider;		/**< \brief Interrupt service provider. Range: 0 to 0xFFFF */
} IfxCif_IsrSetting;

/** \addtogroup IfxLld_Cif_Std_stdFunctions
 * \{ */

/******************************************************************************/
/*-------------------------Inline Function Prototypes-------------------------*/
/******************************************************************************/

/**
 * \brief Clears the kernel reset state, indicating that the reset condition has been addressed.
 *
 * \retval None
 */
IFX_INLINE void IfxCif_clearKernelResetState(void);

/**
 * \brief Retrieves the module ID of the CIF module.
 *
 * \retval uint16 The 16-bit module identifier of the CIF module.
 * 				  Range: 0 to 0xFFFF
 */
IFX_INLINE uint16 IfxCif_getCifModuleId(void);

/**
 * \brief Function to query the port input selection.
 * 
 * \retval IfxCif_PortInputSelection The port input selection configuration.
 *                                   Range: \ref IfxCif_PortInputSelection
 */
IFX_INLINE IfxCif_PortInputSelection IfxCif_getCifModulePortInputSelection(void);

/**
 * \brief Retrieves the revision number of the CIF module.
 * 
 * \retval uint8 The revision number of the CIF module.
 * 		   		 Range: 0 to 0xFF
 */
IFX_INLINE uint8 IfxCif_getCifModuleRevision(void);

/**
 * \brief Retrieves the type of the CIF module ID.
 *
 * \retval uint8 The CIF module type.
 * 				 Range: 0 to 0xFF
 */
IFX_INLINE uint8 IfxCif_getCifModuleType(void);

/**
 * \brief Queries and returns the current clock distribution enabled state.
 *
 * \retval IfxCif_State The current clock control logic state.
 * 						Range: \ref IfxCif_State_Enabled  if clock distribution is enabled.
 * 		   					   \ref IfxCif_State_Disabled if clock distribution is disabled.
 */
IFX_INLINE IfxCif_State IfxCif_getClockControlLogicState(void);

/**
 * \brief Retrieves the data path selector for the main path.
 *
 * \retval IfxCif_DataPathSelectorForMainPath The selector for the main data path.
 * 											  Range: \ref IfxCif_DataPathSelectorForMainPath
 */
IFX_INLINE IfxCif_DataPathSelectorForMainPath IfxCif_getDataPathSelectorForMainPath(void);

/**
 * \brief Retrieves the input interface type configured for the CIF interface.
 *
 * \retval IfxCif_InputInterface The configured input interface type.
 * 								 Range: \ref IfxCif_InputInterface
 */
IFX_INLINE IfxCif_InputInterface IfxCif_getInputInterface(void);

/**
 * \brief Function to query the current level of the ISP input port s_hsync (for testing purposes only).
 * 
 * \retval IfxCif_State The current state of ISP input port s_hsyn.
 * 						Range: \ref IfxCif_State_Enabled  if the s_hsync is high.
 * 							   \ref IfxCif_State_Disabled if the s_hsync is low.
 */
IFX_INLINE IfxCif_State IfxCif_getIspInputPortSHSyncState(void);

/**
 * \brief Queries and returns the current kernel reset status.
 *
 * \retval IfxCif_State The current kernel reset status.
 * 						Range: \ref IfxCif_State_Enabled  if the kernel reset was executed.
 * 						       \ref IfxCif_State_Disabled if the kernel reset was not executed.
 */
IFX_INLINE IfxCif_State IfxCif_getKernelResetStatus(void);

/**
 * \brief Function to query the module number of the CIF interface.
 *
 * \retval uint16 The module number of the CIF interface.
 * 				  Range: 0 to 0xFFFF
 */
IFX_INLINE uint16 IfxCif_getModuleNumber(void);

/**
 * \brief Function to query the revision number of the CIF interface.
 *
 * \retval uint8 The revision number of the CIF interface.
 * 				 Range: 0 to 0xFF
 */
IFX_INLINE uint8 IfxCif_getModuleRevisionNumber(void);

/**
 * \brief Function to query the state of the CIF module.
 *
 * \retval IfxCif_State The current module state.
 * 						Range: \ref IfxCif_State_Enabled  if the module is currently enabled.
 * 		   			           \ref IfxCif_State_Disabled if the module is currently disabled.
 */
IFX_INLINE IfxCif_State IfxCif_getModuleState(void);

/**
 * \brief Queries and returns the module type of the CIF interface.
 *
 * \retval uint8 The module type of the CIF interface.
 * 				 Range: 0 to 0xFF
 */
IFX_INLINE uint8 IfxCif_getModuleType(void);

/**
 * \brief Queries and returns the current channel mode of the Y/C splitter.
 *
 * \retval IfxCif_YCSplitterChannelMode The configured mode of the Y/C splitter channel.
 * 										Range: \ref IfxCif_YCSplitterChannelMode
 */
IFX_INLINE IfxCif_YCSplitterChannelMode IfxCif_getYCSplitterChannelMode(void);

/**
 * \brief Sets the clock control logic state to enable or disable clock distribution to all CIF submodules.
 *
 * \param[in] clockControlLogicState The state to set the clock control logic to.
 * 									 Range: \ref IfxCif_State_Enabled  to Enable clock distribution.
 * 									 		\ref IfxCif_State_Disabled to Disable clock distribution.
 *
 * \retval None
 */
IFX_INLINE void IfxCif_setClockControlLogicState(IfxCif_State clockControlLogicState);

/**
 * \brief Sets the data path selector for the main path, configuring how data flows through the main path.
 *
 * \param[in] pathSelector The selector for the main data path.
 * 						   Range: \ref IfxCif_DataPathSelectorForMainPath
 *
 * \retval None
 */
IFX_INLINE void IfxCif_setDataPathSelectorForMainPath(IfxCif_DataPathSelectorForMainPath pathSelector);

/**
 * \brief Configures the input interface type for the CIF interface.
 *
 * \param[in] interface The type of input interface to be configured.
 * 			  			Range: \ref IfxCif_InputInterface
 *
 * \retval None
 */
IFX_INLINE void IfxCif_setInputInterface(IfxCif_InputInterface interface);

/**
 * \brief Requests a kernel reset or resets the kernel reset request bit based on the provided state.
 *
 * \param[in] state The state parameter determines whether to request a kernel reset.
 * 					Range: \ref IfxCif_State_Enabled  to request a reset.
 * 					       \ref IfxCif_State_Disabled to reset the request bit before a reset was performed.
 *
 * \retval None
 */
IFX_INLINE void IfxCif_setKernelResetRequestState(IfxCif_State state);

/**
 * \brief Sets the mode of operation for the Y/C splitter channel.
 *
 * \param[in] mode The mode of operation to set for the Y/C splitter channel.
 * 				   Range: \ref IfxCif_YCSplitterChannelMode
 *
 * \retval None
 */
IFX_INLINE void IfxCif_setYCSplitterChannelMode(IfxCif_YCSplitterChannelMode mode);

/******************************************************************************/
/*-------------------------Global Function Prototypes-------------------------*/
/******************************************************************************/

/**
 * \brief Function to query the clock state of a submodule.
 *
 * \param[in] submodule The identifier of the submodule to query.
 * 			  			Range: \ref IfxCif_Submodules
 *
 * \retval IfxCif_State The current mode of the internal clock.
 * 						Range: \ref IfxCif_State_Enabled  if the clock of the submodule is enabled.
 * 		   					   \ref	IfxCif_State_Disabled if the clock of the submodule is disabled.
 */
IFX_EXTERN IfxCif_State IfxCif_getInternalClockMode(IfxCif_Submodules submodule);

/**
 * \brief Queries and returns the current state of the kernel reset request bit.
 *
 * \retval IfxCif_State The current state of the Kernel Reset Request.
 * 						Range: \ref IfxCif_State_Enabled  if the kernel reset request bit is set.
 * 		   					   \ref	IfxCif_State_Disabled if the kernel reset request bit is not set.
 */
IFX_EXTERN IfxCif_State IfxCif_getKernelResetRequestState(void);

/**
 * \brief Function to query the reset mode of a submodule.
 *
 * \param[in] submodule The identifier of the submodule to query.
 * 						Range: \ref IfxCif_Submodules
 *
 * \retval IfxCif_State The current mode of the Software Reset.
 * 		   				Range: \ref IfxCif_State_Enabled  if the reset mode of the submodule is enabled.
 * 							   \ref IfxCif_State_Disabled if the reset mode of the submodule is disabled.
 */
IFX_EXTERN IfxCif_State IfxCif_getSoftwareResetMode(IfxCif_Submodules submodule);

/**
 * \brief Resets the CIF kernel to its initial state.
 *
 * \param[inout] cifBbb Pointer to the CIF_BBB registers. This structure contains the configuration and control registers for the CIF module.
 *
 * \retval None
 */
IFX_EXTERN void IfxCif_resetModule(Ifx_CIF_BBB *cifBbb);

/**
 * \brief to Enable or Disables the clock of a submodule.
 *
 * \param[in] submodule  Identifier of the submodule to configure.
 * 						 Range: \ref IfxCif_Submodules
 * \param[in] clockState Specifies the state of the clock.
 * 					     Range: \ref IfxCif_State_Enabled  to enable the clock.
 * 					     		\ref IfxCif_State_Disabled to disable the clock
 * 
 * \retval None
 */
IFX_EXTERN void IfxCif_setInternalClockMode(IfxCif_Submodules submodule, IfxCif_State clockState);

/**
 * \brief Function to request enabling or disabling of the CIF module.
 *
 * \param[in] state Module state to be set.
 * 					Range: \ref IfxCif_State_Enabled  to request the enabling of the module.
 * 						   \ref IfxCif_State_Disabled to request the disabling of the module.
 *
 * \retval None
 */
IFX_EXTERN void IfxCif_setModuleStateRequest(IfxCif_State state);

/**
 * \brief Enables or disables the software reset mode of a specified submodule.
 *
 * \param[in] submodule The identifier of the submodule to configure.
 * 						Range: \ref IfxCif_Submodules
 * \param[in] resetMode Specifies whether to enable or disable the reset mode.
 * 						Range: \ref IfxCif_State_Enabled  to enable the reset of the submodule.
 * 							   \ref IfxCif_State_Disabled to disable the reset.
 *
 * \retval None
 */
IFX_EXTERN void IfxCif_setSoftwareResetMode(IfxCif_Submodules submodule, IfxCif_State resetMode);

/** \} */

/** \addtogroup IfxLld_Cif_Std_ispFunctions
 * \{ */

/******************************************************************************/
/*-------------------------Inline Function Prototypes-------------------------*/
/******************************************************************************/

/**
 * \brief Generates a frame synchronous ISP configuration update signal.
 *
 * \retval None
 */
IFX_INLINE void IfxCif_generateIspFrameSynchronousConfigUpdateSignal(void);

/**
 * \brief Generates an immediate ISP configuration update signal.
 *
 * \retval None
 */
IFX_INLINE void IfxCif_generateIspImmediateConfigUpdateSignal(void);

/**
 * \brief Function to query the current ISP frame count.
 * 
 * \retval uint16 The current frame count of processing.
 * 				  Range: 0 to 0x3FF
 */
IFX_INLINE uint16 IfxCif_getCurrentIspFrameCount(void);

/**
 * \brief Retrieves the current ISP inform field information.
 *
 * \retval IfxCif_IspInformFieldInformation The current field information.
 *  										Range: \ref IfxCif_IspInformFieldInformation_Odd  for odd fields.
 *  											   \ref IfxCif_IspInformFieldInformation_Even for even fields.
 */
IFX_INLINE IfxCif_IspInformFieldInformation IfxCif_getCurrentIspInformFieldInformation(void);

/**
 * \brief Queries and returns the current state of the ISP input formatter.
 *
 * \retval IfxCif_State The current ISP input Formatter Shadow.
 * 						Range: \ref IfxCif_State_Enabled  if the ISP input formatter is currently enabled.
 * 							   \ref IfxCif_State_Disabled if the ISP input formatter is currently disabled.
 */
IFX_INLINE IfxCif_State IfxCif_getCurrentIspInputFormatterState(void);

/**
 * \brief Retrieves the currently configured CCIR sequence for the ISP.
 *
 * \retval IfxCif_IspCcirSequence The currently active CCIR sequence.
 * 								  Range: \ref IfxCif_IspCcirSequence
 */
IFX_INLINE IfxCif_IspCcirSequence IfxCif_getIspCcirSequence(void);

/**
 * \brief Retrieves the currently configured clipping range for the crominance component of the ISP color space matrix.
 *
 * \retval IfxCif_IspColorSpaceMatrixCrominanceClippingRange The currently set clipping range for the crominance component.
 * 															 Range: \ref IfxCif_IspColorSpaceMatrixCrominanceClippingRange
 */
IFX_INLINE IfxCif_IspColorSpaceMatrixCrominanceClippingRange IfxCif_getIspColorSpaceMatrixCrominanceClippingRange(void);

/**
 * \brief Function to query the clipping range of the luminance of the ISP output.
 * 
 * \retval IfxCif_IspColorSpaceMatrixLuminanceClippingRange The currently set clipping range.
 * 														    Range: \ref IfxCif_IspColorSpaceMatrixLuminanceClippingRange
 */
IFX_INLINE IfxCif_IspColorSpaceMatrixLuminanceClippingRange IfxCif_getIspColorSpaceMatrixLuminanceClippingRange(void);

/**
 * \brief Function to query the state of field ID inversion.
 * 
 * \retval IfxCif_State The current state of the ISP field invert.
 * 						Range: \ref IfxCif_State_Enabled  if the Field ID inversion is enabled.
 * 		   					   \ref IfxCif_State_Disabled if the Field ID inversion is disabled.
 */
IFX_INLINE IfxCif_State IfxCif_getIspFieldInvertState(void);

/**
 * \brief Retrieves the currently configured field sample mode for the ISP.
 *
 * \retval IfxCif_IspFieldSelection The currently set fields sample mode.
 * 									Range: \ref IfxCif_IspFieldSelection
 */
IFX_INLINE IfxCif_IspFieldSelection IfxCif_getIspFieldSelection(void);

/**
 * \brief Function to query the currently set polarity of the HSYNC signal.
 *
 * \retval IfxCif_IspSyncPolarity The currently set polarity of the HSYNC signal.
 * 								  Range: \ref IfxCif_IspSyncPolarity_HighActive if the HSYNC is configured as high active.
 * 									     \ref IfxCif_IspSyncPolarity_LowActive  if the HSYNC is configured as low active.
 */
IFX_INLINE IfxCif_IspSyncPolarity IfxCif_getIspHSyncPolarity(void);

/**
 * \brief Queries and returns the current state of the ISP input formatter.
 *
 * \retval IfxCif_State The current state of the ISP input formatter.
 * 						Range: \ref IfxCif_State_Enabled  if the ISP input formatter is enabled.
 *		   					   \ref	IfxCif_State_Disabled if the ISP input formatter is currently disabled.
 */
IFX_INLINE IfxCif_State IfxCif_getIspInputFormatterState(void);

/**
 * \brief Retrieves the configured ISP input interface bit width.
 *
 * \retval IfxCif_IspInputInterface The configured ISP input interface bit width.
 * 									Range: \ref IfxCif_IspInputInterface
 */
IFX_INLINE IfxCif_IspInputInterface IfxCif_getIspInputInterface(void);

/**
 * \brief Queries the current value of the ISP input port s_data (for test purposes only)
 * 
 * \retval uint16 The current state of ISP input port s_data.
 * 				  Range: 0 to 0x3FFF
 */
IFX_INLINE uint16 IfxCif_getIspInputPortSDataState(void);

/**
 * \brief Queries the current state of the ISP input port s_vsync signal (for test purposes only)
 *
 * \retval IfxCif_State The current level of the ISP input port s_vsync.
 * 						Range: \ref IfxCif_State_Enabled  if the s_vsync is high.
 * 		  					   \ref IfxCif_State_Disabled if the s_vsync is low.
 *
 * \note This function is intended for test purposes only
 */
IFX_INLINE IfxCif_State IfxCif_getIspInputPortSVSyncState(void);

/**
 * \brief Retrieves the currently configured ISP mode.
 *
 * \retval IfxCif_State The current ISP mode.
 * 						Range: \ref IfxCif_State
 */
IFX_INLINE IfxCif_State IfxCif_getIspMode(void);

/**
 * \brief Queries and returns the current state of the ISP output.
 *
 * \retval IfxCif_State The current state of the ISP output.
 * 						Range: \ref IfxCif_State_Enabled  if the ISP output is enabled.
 *		  					   \ref IfxCif_State_Disabled if the ISP output is disabled.
 */
IFX_INLINE IfxCif_State IfxCif_getIspOutputState(void);

/**
 * \brief Queries and returns the currently configured ISP sampling edge.
 *
 * \retval IfxCif_IspSamplingEdgeIfxCif_Isp The current state of the configured ISP sampling edge.
 * 											Range: \ref IfxCif_IspSamplingEdge_NegativeEdge if the negative clock edge is configured as sampling edge.
 * 		    									   \ref IfxCif_IspSamplingEdge_PositiveEdge if the positive clock edge is configured as sampling edge.
 */
IFX_INLINE IfxCif_IspSamplingEdge IfxCif_getIspSamplingEdge(void);

/**
 * \brief Queries and returns the current state of the ISP.
 *
 * \retval IfxCif_State The current state of the ISP.
 * 						Range: \ref IfxCif_State_Enabled  if the ISP is currently enabled.
 * 		    				   \ref IfxCif_State_Disabled if the ISP is currently disabled.
 */
IFX_INLINE IfxCif_State IfxCif_getIspState(void);

/**
 * \brief Queries and returns the currently set polarity of the VSYNC signal.
 *
 * \retval IfxCif_IspSyncPolarity The current state of the VSYNC signal polarity.
 * 								  Range: \ref IfxCif_IspSyncPolarity_HighActive if the VSYNC is configured as high active.
 * 		   						 		 \ref IfxCif_IspSyncPolarity_LowActive  if the VSYNC is configured as low active.
 */
IFX_INLINE IfxCif_IspSyncPolarity IfxCif_getIspVSyncPolarity(void);

/**
 * \brief Retrieves the currently set number of acquisition frames.
 *
 * \retval uint16 The currently set number of acquisition frames.
 * 				  Range: 0 to 0x3FF
 */
IFX_INLINE uint16 IfxCif_getNumberOfAcquisitionFrames(void);

/**
 * \brief Configures the horizontal and vertical acquisition offsets for the ISP.
 *
 * \param[in] hOffset Horizontal offset value to be applied during acquisition.
 * 					  Range: 0 to 0x1FFF
 * \param[in] vOffset Vertical offset value to be applied during acquisition.
 * 					  Range: 0 to 0xFFFF
 *
 * \retval None
 */
IFX_INLINE void IfxCif_setIspAcquisitionOffsets(uint16 hOffset, uint16 vOffset);

/**
 * \brief Function to set the horizontal and vertical acquisition size for the ISP.
 *
 * \param[in] hSize Horizontal acquisition size to set.
 * 					Range: 0 to 0x1FFF
 * \param[in] vSize Vertical acquisition size to set.
 * 				    Range: 0 to 0xFFFF
 *
 * \retval None
 */
IFX_INLINE void IfxCif_setIspAcquisitionSizes(uint16 hSize, uint16 vSize);

/**
 * \brief Function to set the CCIR sequence.
 *
 * \param[in] sequence The CCIR sequence to be set.
 * 					   Range: \ref IfxCif_IspCcirSequence
 *
 * \retval None
 */
IFX_INLINE void IfxCif_setIspCcirSequence(IfxCif_IspCcirSequence sequence);

/**
 * \brief Sets the clipping range for the crominance component of the ISP output color space matrix.
 *
 * \param[in] clippingRange Clipping range to be set.
 * 							Range: \ref IfxCif_IspColorSpaceMatrixCrominanceClippingRange
 *
 * \retval None
 */
IFX_INLINE void IfxCif_setIspColorSpaceMatrixCrominanceClippingRange(IfxCif_IspColorSpaceMatrixCrominanceClippingRange clippingRange);

/**
 * \brief Sets the clipping range of the luminance for the ISP output.
 *
 * \param[in] clippingRange Clipping range to set.
 * 							Range: \ref IfxCif_IspColorSpaceMatrixLuminanceClippingRange
 *
 * \retval None
 */
IFX_INLINE void IfxCif_setIspColorSpaceMatrixLuminanceClippingRange(IfxCif_IspColorSpaceMatrixLuminanceClippingRange clippingRange);

/**
 * \brief Function to enable or disable inversion of the field ID.
 *
 * \param[in] fieldInvertState The state to set for field inversion.
 *                             Range: \ref IfxCif_State_Enabled  to enable field ID inversion.
 *                            		  \ref IfxCif_State_Disabled to disable field ID inversion.
 *
 * \retval None
 */
IFX_INLINE void IfxCif_setIspFieldInvertState(IfxCif_State fieldInvertState);

/**
 * \brief Selects the fields to be sampled.
 *
 * \param[in] selection The sampled fields selector.
 * 						Range: \ref IfxCif_IspFieldSelection
 *
 * \retval None
 */
IFX_INLINE void IfxCif_setIspFieldSelection(IfxCif_IspFieldSelection selection);

/**
 * \brief Sets the polarity of the HSYNC signal for the ISP.
 *
 * \param[in] polarity The desired polarity of the HSYNC signal.
 *                     Range: \ref IfxCif_IspSyncPolarity_HighActive for high active HSYNC signal.
 *                    		  \ref IfxCif_IspSyncPolarity_LowActive  for low active HSYNC signal.
 * \retval None
 */
IFX_INLINE void IfxCif_setIspHSyncPolarity(IfxCif_IspSyncPolarity polarity);

/**
 * \brief Function to enable or disable the ISP input formatter.
 *
 * \param[in] inputFormatterState The desired state of the ISP input formatter.
 * 								  Range: \ref IfxCif_State_Enabled  to enable the ISP input formatter.
 *								   		 \ref IfxCif_State_Disabled to disable it.
 * \retval None
 */
IFX_INLINE void IfxCif_setIspInputFormatterState(IfxCif_State inputFormatterState);

/**
 * \brief Sets the ISP input interface bit width.
 *
 * \param[in] input The ISP input interface bit width to configure.
 * 			        Range: \ref IfxCif_IspInputInterface
 *
 * \retval None
 */
IFX_INLINE void IfxCif_setIspInputInterface(IfxCif_IspInputInterface input);

/**
 * \brief Configures the ISP mode according to the specified mode.
 *
 * \param[in] mode The ISP mode to be set.
 * 				   Range: \ref IfxCif_IspMode
 *
 * \retval None
 */
IFX_INLINE void IfxCif_setIspMode(IfxCif_IspMode mode);

/**
 * \brief Enables or disables the ISP output based on the provided state.
 *
 * \param[in] ispOutputState The state to set for the ISP output.
 * 							 Range: \ref IfxCif_State_Enabled  to enable the ISP output.
 * 							 		\ref IfxCif_State_Disabled to disable it.
 *
 * \retval None
 */
IFX_INLINE void IfxCif_setIspOutputState(IfxCif_State ispOutputState);

/**
 * \brief Configures the horizontal and vertical offsets for the ISP output window.
 *
 * \param[in] hOffset The horizontal offset value to be set.
 * 					  Range: 0 to 0xFFF
 * \param[in] vOffset The Vertical offset value to be set.
 * 					  Range: 0 to 0xFFF
 *
 * \retval None
 */
IFX_INLINE void IfxCif_setIspOutputWindowOffsets(uint16 hOffset, uint16 vOffset);

/**
 * \brief Configures the ISP with the specified horizontal and vertical picture sizes.
 *
 * \param[in] hSize The horizontal size of the picture to be set.
 * 					Range: 0 to 0xFFF
 * \param[in] vSize The vertical size of the picture to be set.
 *					Range: 0 to 0xFFF
 * \retval None
 */
IFX_INLINE void IfxCif_setIspPictureSizes(uint16 hSize, uint16 vSize);

/**
 * \brief Configures the sampling edge for the ISP module.
 *
 * \param[in] edge The sampling edge to be configured.
 *           	   Range: \ref IfxCif_IspSamplingEdge_NegativeEdge to sample at negative clock edges.
 *           	   		  \ref IfxCif_IspSamplingEdge_PositiveEdge to sample at positive clock edges.
 *
 * \retval None
 */
IFX_INLINE void IfxCif_setIspSamplingEdge(IfxCif_IspSamplingEdge edge);

/**
 * \brief Sets the polarity of the VSYNC signal for the ISP.
 *
 * \param[in] polarity The desired polarity of the VSYNC signal.
 *                     Range: \ref IfxCif_IspSyncPolarity_HighActive for high active VSYNC signal.
 *                    		  \ref IfxCif_IspSyncPolarity_LowActive  for low active VSYNC signal.
 * \retval None
 */
IFX_INLINE void IfxCif_setIspVSyncPolarity(IfxCif_IspSyncPolarity polarity);

/**
 * \brief Sets the number of frames to be acquired during the acquisition process.
 *
 * \param[in] numberOfFrames Number of frames to set for acquisition.
 * 							 Range: 0 to 0x3FF
 *
 * \retval None
 */
IFX_INLINE void IfxCif_setNumberOfAcquisitionFrames(uint16 numberOfFrames);

/******************************************************************************/
/*-------------------------Global Function Prototypes-------------------------*/
/******************************************************************************/

/**
* \brief Clears the error status bit for a specified error source in the ISP module.
*
* \param[in] errorSource The error source to clear ISP error.
* 						 Range: \ref IfxCif_IspErrorSources
*
* \retval None
*/
IFX_EXTERN void IfxCif_clearIspError(IfxCif_IspErrorSources errorSource);

/**
 * \brief Clears a specific ISP interrupt source.
 *
 * \param[in] interruptSource The source of the interrupt to be cleared.
 * 						      Range: \ref IfxCif_IspInterruptSources
 *
 * \retval None
 */
IFX_EXTERN void IfxCif_clearIspInterrupt(IfxCif_IspInterruptSources interruptSource);

/**
 * \brief Function to query the current ISP picture offset for a specified tier.
 *
 * \param[in] tier The tier for which to query the current ISP picture offset. 
 *                 Range: \ref IfxCif_ImageTiers
 *
 * \retval uint16 The current ISP picture offset for the specified tier.
 * 				  Range: 0 to 0xFFF
 */
IFX_EXTERN uint16 IfxCif_getCurrentIspPictureOffset(IfxCif_ImageTiers tier);

/**
 * \brief Function to query the current ISP picture size for one tier.
 *
 * \param[in] tier The tier for which to query the current ISP picture size.
 *                 Range: \ref IfxCif_ImageTiers
 *
 * \retval uint16 The current ISP picture size for the specified tier.
 * 			      Range: 0 to 0x1FFF
 */
IFX_EXTERN uint16 IfxCif_getCurrentIspPictureSize(IfxCif_ImageTiers tier);

/**
 * \brief Retrieves the currently configured ISP acquisition offset for the specified image tier.
 *
 * \param[in] tier The image tier for which to retrieve the ISP acquisition offset.
 *                 Range: \ref IfxCif_ImageTiers
 *
 * \retval uint16 The currently set ISP acquisition offset for the specified tier.
 * 				  Range: 0 to 0x1FFF
 */
IFX_EXTERN uint16 IfxCif_getIspAcquisitionOffset(IfxCif_ImageTiers tier);

/**
 * \brief Function to query the currently set ISP acquisition size of one tier.
 *
 * \param[in] tier The image tier for which to query the acquisition size.
 *                 Range: \ref IfxCif_ImageTiers
 *
 * \retval uint16 The currently set acquisition size for the specified tier.
 *                Range: 0 to 0x1FFF
 */
IFX_EXTERN uint16 IfxCif_getIspAcquisitionSize(IfxCif_ImageTiers tier);

/**
 * \brief Function to query the error state of a specific ISP error source.
 *
 * \param[in] errorSource The error source to query. 
 * 						  Range: \ref IfxCif_IspErrorSources
 * 
 * \retval IfxCif_ErrorState The current ISP error state of the specified error source.
 *                           Range: \ref IfxCif_ErrorState_Error   if the error occurred.
 *                                  \ref IfxCif_ErrorState_NoError if the error did not occur.
 */
IFX_EXTERN IfxCif_ErrorState IfxCif_getIspErrorState(IfxCif_IspErrorSources errorSource);

/**
 * \brief Queries and returns the current state of the ISP input selection append feature.
 *
 * \retval IfxCif_State The current state of the ISP input selection append feature.
 *                      Range: \ref IfxCif_State_Enabled  if appending is enabled.
 *                             \ref IfxCif_State_Disabled if appending is disabled.
 */
IFX_EXTERN IfxCif_State IfxCif_getIspInputSelectionAppendState(void);

/**
 * \brief Retrieves the enabled state of a specific ISP interrupt source.
 *
 * \param[in] interruptSource The interruptSource Source of the interrupt.
 *                            Range: \ref IfxCif_IspInterruptSources   
 *
 * \retval IfxCif_State The current state of specific ISP interrupt source.
 *                      Range: \ref IfxCif_State_Enabled  if the interrupt is enabled.
 *                             \ref IfxCif_State_Disabled if the interrupt is disabled.
 */
IFX_EXTERN IfxCif_State IfxCif_getIspInterruptEnableState(IfxCif_IspInterruptSources interruptSource);

/**
 * \brief Retrieves the currently set ISP output window offset for a specified tier.
 *
 * \param[in] tier The tier for which to retrieve the ISP output window offset.
 *                 Range: \ref IfxCif_ImageTiers
 *
 * \retval uint16 The currently set ISP output window offset.
 *                Range: 0 to 0xFFF
 */
IFX_EXTERN uint16 IfxCif_getIspOutputWindowOffset(IfxCif_ImageTiers tier);

/**
 * \brief Function to query the currently set ISP picture size of one tier.
 * 
 * \param[in] tier The tier for which to query the ISP picture size.
 *                 Range: \ref IfxCif_ImageTiers
 * 
 * \retval uint16 The currently set ISP picture size for the specified tier.
 *                Range: 0 to 0xFFF 
 */
IFX_EXTERN uint16 IfxCif_getIspPictureSize(IfxCif_ImageTiers tier);

/**
 * \brief Queries the masked state of a specific ISP interrupt source.
 *
 * \param[in] interruptSource The ISP interrupt source to query.
 *                            Range: \ref IfxCif_IspInterruptSources         
 *
 * \retval IfxCif_InterruptTriggeredState The current masked state of the specified ISP interrupt source.
 *                                        Range: \ref IfxCif_InterruptTriggeredState_Triggered    if the interrupt request bit is set and the interrupt is enabled.
 *                                               \ref IfxCif_InterruptTriggeredState_NotTriggered if the interrupt request bit is not set or the interrupt is disabled.
 */
IFX_EXTERN IfxCif_InterruptTriggeredState IfxCif_getMaskedIspInterruptTriggeredState(IfxCif_IspInterruptSources interruptSource);

/**
 * \brief Queries the raw state of an ISP interrupt source.
 *
 * \param[in] interruptSource The source of the interrupt to query.
 *                            Range: \ref IfxCif_IspInterruptSources 
 *
 * \retval IfxCif_InterruptTriggeredState The current raw state of the specified ISP interrupt source.
 *                                        Range: \ref IfxCif_InterruptTriggeredState_Triggered    if the interrupt request bit is set.
 *                                               \ref IfxCif_InterruptTriggeredState_NotTriggered if the interrupt request bit is not set.
 */
IFX_EXTERN IfxCif_InterruptTriggeredState IfxCif_getRawIspInterruptTriggeredState(IfxCif_IspInterruptSources interruptSource);

/**
 * \brief Sets the ISP acquisition offset for a specified image tier.
 *
 * \param[in] tier   The image tier for which to set the acquisition offset.  
 *                   Range: \ref IfxCif_ImageTiers
 * \param[in] offset The acquisition offset value to be set.
 *                   Range: 0 to 0x1FFF
 *
 * \retval None 
 */
IFX_EXTERN void IfxCif_setIspAcquisitionOffset(IfxCif_ImageTiers tier, uint16 offset);

/**
 * \brief Sets the ISP acquisition size for a specified image tier.
 *
 * \param[in] tier The image tier for which to set the acquisition size.
 *                 Range: \ref IfxCif_ImageTiers
 * \param[in] size The acquisition size to be set. 
 *                 Range: 0 to 0x1FFF
 *
 * \retval None
 */
IFX_EXTERN void IfxCif_setIspAcquisitionSize(IfxCif_ImageTiers tier, uint16 size);

/**
 * \brief Enables or disables the appending of bits to the input signal.
 *
 * \param[in] appendState The state specifying whether to enable or disable the appending.
 *                        Range: \ref IfxCif_State_Enabled  to enable appending.
 *                               \ref IfxCif_State_Disabled to disable appending.
 *
 * \retval None
 */
IFX_EXTERN void IfxCif_setIspInputSelectionAppendState(IfxCif_State appendState);

/**
 * \brief Enables or disables a specific interrupt source.
 *
 * \param[in] interruptSource      The source of the interrupt to be enabled or disabled.
 *                                 Range: \ref IfxCif_IspInterruptSources
 * \param[in] interruptEnableState The state to which the interrupt should be set.
 *                                 Range: \ref IfxCif_State_Enabled  to enable the interrupt.
 *                                        \ref IfxCif_State_Disabled to disable the interrupt.
 *
 * \retval None
 */
IFX_EXTERN void IfxCif_setIspInterruptEnableState(IfxCif_IspInterruptSources interruptSource, IfxCif_State interruptEnableState);

/**
 * \brief Sets the specified interrupt request bit for the ISP module (does not necessarily trigger an interrupt).
 *
 * \param[in] interruptSource The source of the interrupt to be set.
 *                            Range: \ref IfxCif_IspInterruptSources
 * \retval None
 */
IFX_EXTERN void IfxCif_setIspInterruptRequestBit(IfxCif_IspInterruptSources interruptSource);

/**
 * \brief Sets the ISP output window offset for a specified image tier.
 *
 * \param[in] tier   The tier for which to set the ISP output window offset.
 *                   Range: \ref IfxCif_ImageTiers
 * \param[in] offset The offset value to be set.
 *                   Range: 0 to 0xFFF
 *
 * \retval None
 */
IFX_EXTERN void IfxCif_setIspOutputWindowOffset(IfxCif_ImageTiers tier, uint16 offset);

/**
 * \brief Sets the ISP picture size for a specified image tier.
 *
 * \param[in] tier        The image tier for which to set the picture size.
 *                        Range: \ref IfxCif_ImageTiers
 * \param[in] pictureSize The size of the picture to be set.
 *                        Range: 0 to 0xFFF
 *
 * \retval None
 */
IFX_EXTERN void IfxCif_setIspPictureSize(IfxCif_ImageTiers tier, uint16 pictureSize);

/** \} */

/** \addtogroup IfxLld_Cif_Std_ldsFunctions
 * \{ */

/******************************************************************************/
/*-------------------------Global Function Prototypes-------------------------*/
/******************************************************************************/

/**
 * \brief Function to query the current state of the linear down scaler for a specific image tier.
 *
 * \param[in] tier The image tier for which to query the linear down scaler state.
 *                 Range: \ref IfxCif_ImageTiers
 *
 * \retval IfxCif_State The current state of the linear down scaler for the specified tier.
 *                      Range: \ref IfxCif_State_Enabled  if the linear down scaler is enabled.
 *                             \ref IfxCif_State_Disabled if the linear down scaler is disabled for the specified tier.
 */
IFX_EXTERN IfxCif_State IfxCif_getLinearDownscalerEnableState(IfxCif_ImageTiers tier);

/**
 * \brief Function to query the currently set scaling factor of the linear down scaler for a specific image tier.
 *
 * \param[in] tier The image tier for which to query the scaling factor of the linear down scaler.
 *                 Range: \ref IfxCif_ImageTiers
 *
 * \retval uint8 The current scaling factor for the specified tier.
 *               Range: 0 to 0xFF
 */
IFX_EXTERN uint8 IfxCif_getLinearDownscalerScalingFactor(IfxCif_ImageTiers tier);

/**
 * \brief Retrieves the currently set scaling mode for the specified image tier.
 *
 * \param[in] tier The image tier for which to query the scaling mode. 
 *                 Range: \ref IfxCif_ImageTiers
 *
 * \retval IfxCif_LinearDownscalerScalingMode The currently set scaling mode for the specified tier.
 *                                            Range: \ref IfxCif_LinearDownscalerScalingMode       
 */
IFX_EXTERN IfxCif_LinearDownscalerScalingMode IfxCif_getLinearDownscalerScalingMode(IfxCif_ImageTiers tier);

/**
 * \brief Function to enable or disable the linear down scaler for a specific image tier.
 *
  * \param[in] tier       The image tier for which to enable or disable the linear down scaler.
 *                        Range: \ref IfxCif_ImageTiers
 * \param[in] enableState The state to set for the linear down scaler.
 *                        Range: \ref IfxCif_State_Enabled  to enable the linear down scaler.
 *                        		 \ref IfxCif_State_Disabled to disable the linear down scaler.
 * 
 * \retval None
 */
IFX_EXTERN void IfxCif_setLinearDownscalerEnableState(IfxCif_ImageTiers tier, IfxCif_State enableState);

/**
 * \brief Sets the scaling factor for the linear downscaler of a specified image tier.
 *
 * \param[in] tier   The image tier for which to set the scaling factor.
 *                   Range: \ref IfxCif_ImageTiers
 * \param[in] factor The factor to be set (depending on the configured scaling mode every factor + 1 pixel or double pixel will be skipped or passed to the next module).
 *                   Range: 0 to 0xFF
 * \retval None
 */
IFX_EXTERN void IfxCif_setLinearDownscalerScalingFactor(IfxCif_ImageTiers tier, uint8 factor);

/**
 * \brief Configures the scaling factors of the linear downscaler module.
 *
 * \param[in] horizFactor The horizontal scaling factor to be set (Depending on the configured mode every lds_h_fac+1th pixel (or double pixel) will be skipped or passed on to the next module).
 *                        Range: 0 to 0xFF
 * \param[in] vertFactor  The vertical scaling factor to be set (Depending on the configured mode every lds_v_fac+1th line (or double line) will be skipped or passed on to the next module).
 *                        Range: 0 to 0xFF
 * \retval None
 */
IFX_EXTERN void IfxCif_setLinearDownscalerScalingFactors(uint8 horizFactor, uint8 vertFactor);

/**
 * \brief Sets the scaling mode for the linear downscaler of a specified image tier.
 *
 * \param[in] tier Tier for which to set the scaling mode.
 *                 Range: \ref IfxCif_ImageTiers
 * \param[in] mode Scaling mode to be set.
 *                 Range: \ref IfxCif_LinearDownscalerScalingMode 
 *
 * \retval None
 */
IFX_EXTERN void IfxCif_setLinearDownscalerScalingMode(IfxCif_ImageTiers tier, IfxCif_LinearDownscalerScalingMode mode);

/**
 * \brief Sets the scaling mode for the horizontal and vertical linear downscaler.
 *
 * \param[in] horizMode Scaling mode to set for horizontal tier.
 *                      Range: \ref IfxCif_LinearDownscalerScalingMode
 * \param[in] vertMode  Scaling mode to set for vertical tier.
 *                      Range: \ref IfxCif_LinearDownscalerScalingMode
 *
 * \retval None
 */
IFX_EXTERN void IfxCif_setLinearDownscalerScalingModes(IfxCif_LinearDownscalerScalingMode horizMode, IfxCif_LinearDownscalerScalingMode vertMode);

/** \} */

/** \addtogroup IfxLld_Cif_Std_miFunctions
 * \{ */

/******************************************************************************/
/*-------------------------Inline Function Prototypes-------------------------*/
/******************************************************************************/

/**
 * \brief Generates an immediate configuration update signal for the memory interface submodule.
 *
 * \retval None 
 */
IFX_INLINE void IfxCif_generateMiImmediateConfigUpdateSignal(void);

/**
 * \brief Queries the enabled state of the update signal of the base address and buffer size shadow registers to the programmed register Initialization values.
 *
 * \retval IfxCif_State The current state of the base address and buffer size shadow registers update signal.
 *                      Range: \ref IfxCif_State_Enabled  if update of the base address and buffer size shadow registers is enabled.
 *                      								  (update will be executed either when a forced software update occurs or when an automatic config update signal arrives at the MI input port).
 *                             \ref IfxCif_State_Disabled if update of the base address and buffer size shadow registers is disabled.
 */
IFX_INLINE IfxCif_State IfxCif_getBaseAddressInitializationEnableState(void);

/**
 * \brief Gets the number of JPEG or RAW data bytes of the last transmitted frame.
 * 
 * \retval uint32 The number of JPEG or RAW data bytes of the last transmitted frame (updated at frame end).
 * 				  Range: 0 to 0xFFFFFF
 */
IFX_INLINE uint32 IfxCif_getMiByteCount(void);

/**
 * \brief Retrieves the current state of the 32-bit output word byte order swapping.
 *
 * \retval IfxCif_State The current state of the Mi byte order swapping.
 *                      Range: \ref IfxCif_State_Enabled  if byte swapping is enabled.
 *                             \ref IfxCif_State_Disabled if byte swapping is disabled.
 */
IFX_INLINE IfxCif_State IfxCif_getMiByteSwapEnableState(void);

/**
 * \brief Queries the currently set burst length for Cb and Cr data.
 *
 * \retval IfxCif_MiBurstLength The length of the Mi Chrominance burst for data transfer.    
 *                              Range: \ref IfxCif_MiBurstLength_4BeatBursts if 4 bytes are transferred.
 *                                     \ref IfxCif_MiBurstLength_8BeatBursts if 8 bytes are transferred.
 */
IFX_INLINE IfxCif_MiBurstLength IfxCif_getMiChrominanceBurstLength(void);

/**
 * \brief Function to query the currently set burst length for Y, JPEG, or RAW data.
 * 
 * \retval IfxCif_MiBurstLength The length of the Mi luminance burst for data transfer.    
 *                              Range: \ref IfxCif_MiBurstLength_4BeatBursts if 4 bytes are transferred.
 *                                     \ref IfxCif_MiBurstLength_8BeatBursts if 8 bytes are transferred.
 */
IFX_INLINE IfxCif_MiBurstLength IfxCif_getMiLuminanceBurstLength(void);

/**
 * \brief Function to query the currently set write format of the main picture path of the memory interface.
 * 
 * \retval IfxCif_MiMainPictureWriteFormat The currently set write format.
 *                                         Range: \ref IfxCif_MiMainPictureWriteFormat                                
 */
IFX_INLINE IfxCif_MiMainPictureWriteFormat IfxCif_getMiMainPictureWriteFormat(void);

/**
 * \brief Function to query the filling level that triggers an interrupt of main picture path Y component.
 * 
 * \retval uint32 The current filling level that triggers an interrupt.
 *                Range: 0 to 0x3FFFFF
 */
IFX_INLINE uint32 IfxCif_getMiMainPictureYInitialFillLevelInterruptOffset(void);

/**
 * \brief Function to query the filling level of the main picture Y component that triggers an interrupt.
 * 
 * \retval uint32 The interrupt offset level for the main picture Y component filling level
 *                Range: 0 to 0x3FFFFF
 */
IFX_INLINE uint32 IfxCif_getMiMainPictureYInterruptOffset(void);

/**
 * \brief Queries the enabled state of the offset counter shadow registers update signal.
 *
 * \retval IfxCif_State The current state of the offset counter shadow registers update signal.
 *                      Range: \ref IfxCif_State_Enabled  if the update of the offset counter shadow registers is enabled.
 *                      								  (update will be executed either when a forced software update occurs or when an automatic config update signal arrives at the MI input port)
 *                             \ref IfxCif_State_Disabled if the update of the offset counter shadow registers is disabled.
 */
IFX_INLINE IfxCif_State IfxCif_getMiOffsetCounterInitializationEnableState(void);

/**
 * \brief Skips the current or next starting main data path picture.
 *
 * \retval None 
 */
IFX_INLINE void IfxCif_miSkipPicture(void);

/**
 * \brief Enables or disables the automatic update of base address and buffer size shadow registers.
 *
 * \param[in] state The state to set.
 *                  Range: \ref IfxCif_State_Enabled  to enable the generation of the update signal.
 *                         \ref IfxCif_State_Disabled to disable the generation of the update signal.
 *
 * \retval None
 */
IFX_INLINE void IfxCif_setMiBaseAddressInitializationEnableState(IfxCif_State state);

/**
 * \brief Enables or disables the byte swapping of the 32-bit output word.
 *
 * \param[in] enableState The current state of the byte swapping.          
 *                        Range: \ref IfxCif_State_Enabled  to enable the byte swapping.
 *                               \ref IfxCif_State_Disabled to disable the byte swapping.
 * 
 * \retval None
 */
IFX_INLINE void IfxCif_setMiByteSwapEnableState(IfxCif_State enableState);

/**
 * \brief Sets the burst length for the chrominance (Cb and Cr) data in the memory interface.
 *
 * \param[in] burstLength The burst length to be set.
 *                        Range: \ref IfxCif_MiBurstLength
 *
 * \retval None
 */
IFX_INLINE void IfxCif_setMiChrominanceBurstLength(IfxCif_MiBurstLength burstLength);

/**
 * \brief Configures the write format for the main picture path in the memory interface.
 *
 * \param[in] format The write format to be set.
 *                   Range: \ref IfxCif_MiMainPictureWriteFormat    
 *
 * \retval None
 */
IFX_INLINE void IfxCif_setMiMainPictureWriteFormat(IfxCif_MiMainPictureWriteFormat format);

/**
 * \brief Sets the filling level to trigger an interrupt for the main picture path Y component.
 *
 * \param[in] interruptOffset The filling level at to be set for triggering an interrupt.
 *                            Range: 0 to 0x3FFFFF
 *
 * \retval None 
 */
IFX_INLINE void IfxCif_setMiMainPictureYInitialFillLevelInterruptOffset(uint32 interruptOffset);

/**
 * \brief Enables or disables the update of the offset counter shadow registers.
 *        The update will be executed either when a forced software update occurs
 *        or when an automatic config update signal arrives at the MI input port.
 *
 * \param[in] state The state to set for the offset counter initialization.   
 *                  Range: \ref IfxCif_State_Enabled  to enable the generation of the update signal.
 *                         \ref IfxCif_State_Disabled to disable the generation of the update signal.
 *
 * \retval None
 */
IFX_INLINE void IfxCif_setMiOffsetCounterInitializationEnableState(IfxCif_State state);

/******************************************************************************/
/*-------------------------Global Function Prototypes-------------------------*/
/******************************************************************************/

/**
 * \brief Clears the specified interrupt source.
 *
 * \param[in] interruptSource The source of the interrupt to be cleared.
 *                            Range: \ref IfxCif_MiInterruptSources
 *
 * \retval None
 */
IFX_EXTERN void IfxCif_clearMiInterrupt(IfxCif_MiInterruptSources interruptSource);

/**
 * \brief Clears the status information for a specified source of the memory interface submodule.
 *
 * \param[in] source The status information source to be cleared.
 *                   Range: \ref IfxCif_MiStatusClearSources
 * \retval None
 */
IFX_EXTERN void IfxCif_clearMiStatus(IfxCif_MiStatusClearSources source);

/**
 * \brief Queries the initial base address of the ring buffer for a specified main picture path component.
 *
 * \param[in] component Main picture path component for which to query the initial base address.
 *                      Range: \ref IfxCif_MiMainPicturePathComponents 
 *
 * \retval uint32 The initial base address of the main picture path component's ring buffer.
 *                Range: 0 to 0xFFFFFFFC
 */
IFX_EXTERN uint32 IfxCif_getMainPictureComponentBaseInitAddress(IfxCif_MiMainPicturePathComponents component);

/**
 * \brief Queries the masked state of a specific memory interface interrupt source.
 *
 * \param[in] interruptSource The MI interrupt source to query.
 * 							  Range: \ref IfxCif_MiInterruptSources
 *
 * \retval IfxCif_InterruptTriggeredState The current masked state of Memory Interrupt Trigger.
 * 										  Range: \ref IfxCif_InterruptTriggeredState_Triggered 	  if the interrupt request bit is set and the interrupt is enabled.
 *  	   								  		 \ref IfxCif_InterruptTriggeredState_NotTriggered if the interrupt request bit is not set or the interrupt is disabled.
 */
IFX_EXTERN IfxCif_InterruptTriggeredState IfxCif_getMaskedMiInterruptTriggeredState(IfxCif_MiInterruptSources interruptSource);

/**
 * \brief Queries the enabled state of a specified main data path component at the memory interface input.
 *
 * \param[in] dataPath Main data path component for which to query the enabled state.
 * 					   Range: \ref IfxCif_MiDataPaths
 *
 * \retval IfxCif_State The current state of Memory interface Data Path Input.
 * 						Range: \ref IfxCif_State_Enabled  if the main data path component is enabled.
 *							   \ref	IfxCif_State_Disabled if the main data path component is disabled.
 */
IFX_EXTERN IfxCif_State IfxCif_getMiDataPathInputEnableState(IfxCif_MiDataPaths dataPath);

/**
 * \brief Function to query the enabled state of one main data path component at the memory interface output
 *
 * \param[in] dataPath Main data path component for which to query the enabled state.
 *                     Range: \ref IfxCif_MiDataPaths
 *
 * \retval IfxCif_State The current state of Memory interface Data Path.
 * 						Range: \ref IfxCif_State_Enabled  if the main data path component is enabled.
 * 		                	   \ref IfxCif_State_Disabled if the main data path component is disabled.
 */
IFX_EXTERN IfxCif_State IfxCif_getMiDataPathOutputEnableState(IfxCif_MiDataPaths dataPath);

/**
 * \brief Function to query the enabled state of a memory interface data path.
 *
 * \param[in] dataPath The data path to query.
 * 					   Range: \ref IfxCif_MiDataPaths
 *
 * \retval IfxCif_State The current state of Memory Interface Feature.
 * 						Range: \ref IfxCif_State_Enabled  if the memory interface data path is enabled.
 * 		   					   \ref IfxCif_State_Disabled if the data path is disabled.
 */
IFX_EXTERN IfxCif_State IfxCif_getMiFeatureEnableState(IfxCif_MiDataPaths dataPath);

/**
 * \brief Retrieves the enabled state of a specific Memory Interface interrupt source.
 *
 * \param[in] interruptSource The Memory Interface interrupt source to query.
 * 							  Range: \ref IfxCif_MiInterruptSources
 *
 * \retval IfxCif_State The current state of Memory Interface Interrupt Source.
 * 						Range: \ref IfxCif_State_Enabled  if the interrupt is enabled.
 * 		   					   \ref IfxCif_State_Disabled if the interrupt is disabled.
 */
IFX_EXTERN IfxCif_State IfxCif_getMiInterruptEnableState(IfxCif_MiInterruptSources interruptSource);

/**
 * \brief Function to query the current base address of the ring buffer of one main picture path component.
 *
 * \param[in] component Main Picture path component for which to query the base address.
 *						Range: \ref IfxCif_MiMainPicturePathComponents
 *
 * \retval uint32 The current base address of the ring buffer of the main picture path component.
 * 		          Range: 0 to 0xFFFFFFFC
 */
IFX_EXTERN uint32 IfxCif_getMiMainPictureComponentBaseAddress(IfxCif_MiMainPicturePathComponents component);

/**
 * \brief Retrieves the initial size of the ring buffer for a specified main picture path component.
 *
 * \param[in] component The main picture path component for which to query the initial size.
 * 						Range: \ref IfxCif_MiMainPicturePathComponents
 *
 * \retval uint32 The initial size of the ring buffer for the specified component in bytes.
 * 				  Range: 0 to 0xFFFFFC
 */
IFX_EXTERN uint32 IfxCif_getMiMainPictureComponentInitSize(IfxCif_MiMainPicturePathComponents component);

/**
 * \brief Retrieves the initial offset counter inside the ring buffer of one main picture path component.
 *
 * \param[in] component The main picture path component for which to retrieve the initial offset counter.
 * 						Range: \ref IfxCif_MiMainPicturePathComponents
 *
 * \retval uint32 The initial offset counter value of the specified main picture path component.
 * 				  Range: 0 to 0xFFFFFC
 */
IFX_EXTERN uint32 IfxCif_getMiMainPictureComponentInitialOffsetCounter(IfxCif_MiMainPicturePathComponents component);

/**
 * \brief Function to query the current offset counter within the ring buffer of one main picture path component.
 *
 * \param[in] component The main picture path component for which to query the offset counter value.
 *                      Range: \ref IfxCif_MiMainPicturePathComponents
 *
 * \retval uint32 The current offset counter within the ring buffer of the specified main picture path component.
 * 				  Range: 0 to 0xFFFFFC
 */
IFX_EXTERN uint32 IfxCif_getMiMainPictureComponentOffsetCounter(IfxCif_MiMainPicturePathComponents component);

/**
 * \brief Retrieves the offset counter pointing to the start address of the previously processed picture for a specified main picture path component.
 *
 * \param[in] component The main picture path component for which to query the offset counter value.
 * 						Range: \ref IfxCif_MiMainPicturePathComponents
 *
 * \retval uint32 The offset counter value pointing to the start address of the previously processed picture for the specified component.
 * 				  Range: 0 to 0xFFFFFC
 */
IFX_EXTERN uint32 IfxCif_getMiMainPictureComponentOffsetCounterStart(IfxCif_MiMainPicturePathComponents component);

/**
 * \brief Queries the current size of the ring buffer for a specified main picture path component.
 *
 * \param[in] component The main picture path component for which to query the main picture path component size.
 *                      Range: \ref IfxCif_MiMainPicturePathComponents
 *
 * \retval uint32 The current size of the ring buffer of the main picture path component.
 * 				  Range: 0 to 0xFFFFFC
 */
IFX_EXTERN uint32 IfxCif_getMiMainPictureComponentSize(IfxCif_MiMainPicturePathComponents component);

/**
 * \brief Function to query the status information of one status information source of the memory interface module.
 *
 * \param[in] source The status information source to query.
 * 					 Range: \ref IfxCif_MiStatusInformationSources
 *
 * \retval IfxCif_ErrorState The current status information source of the memory interface.
 * 							 Range: \ref IfxCif_ErrorState_NoError if no error has occurred since the last clear.
 * 		   				     		\ref IfxCif_ErrorState_Error   if an error has occurred since the last clear.
 */
IFX_EXTERN IfxCif_ErrorState IfxCif_getMiStatusInformation(IfxCif_MiStatusInformationSources source);

/**
 * \brief Function to query the raw state of a specific interrupt source.
 *
 * \param[in] interruptSource The Source of the interrupt.
 * 							  Range: \ref IfxCif_MiInterruptSources
 *
 * \retval IfxCif_InterruptTriggeredState The current state of the interrupt trigger.
 * 										  \ref IfxCif_InterruptTriggeredState_Triggered    if the interrupt request bit is set.
 * 										  \ref IfxCif_InterruptTriggeredState_NotTriggered if the interrupt request bit is not set.
 */
IFX_EXTERN IfxCif_InterruptTriggeredState IfxCif_getRawMiInterruptTriggeredState(IfxCif_MiInterruptSources interruptSource);

/**
 * \brief Enables or disables a specific memory interface data path feature.
 *
 * \param[in] dataPath 	  The data path to be enabled or disabled.
 * 						  Range: \ref IfxCif_MiDataPaths
 * \param[in] enableState The state to set for the specified data path.
 * 						  Range: \ref IfxCif_State_Enabled  to enable the data path.
 * 						 		 \ref IfxCif_State_Disabled to disable the data path
 *
 * \retval None
 */
IFX_EXTERN void IfxCif_setMiFeatureEnableState(IfxCif_MiDataPaths dataPath, IfxCif_State enableState);

/**
 * \brief Function to enable or disable an interrupt.
 *
 * \param[in] interruptSource      The source of the interrupt to be enabled or disabled.
 *                                 Range: \ref IfxCif_MiInterruptSources.
 * \param[in] interruptEnableState The state to set the interrupt to.
 * 								   Range: \ref IfxCif_State_Enabled  to enable the interrupt.
 * 								   		  \ref IfxCif_State_Disabled to disable the interrupt.
 * \retval None
 */
IFX_EXTERN void IfxCif_setMiInterruptEnableState(IfxCif_MiInterruptSources interruptSource, IfxCif_State interruptEnableState);

/**
 * \brief Sets the specified interrupt request bit for the given interrupt source (does not necessarily trigger an interrupt).
 *
 * \param[in] interruptSource The source of the interrupt.
 * 							  Range: \ref IfxCif_MiInterruptSources
 * \retval None
 */
IFX_EXTERN void IfxCif_setMiInterruptRequestBit(IfxCif_MiInterruptSources interruptSource);

/**
 * \brief Sets the burst length for Y, JPEG, or RAW data.
 *
 * \param[in] burstLength Burst length to set.
 * 						  Range: \ref IfxCif_MiBurstLength
 *
 * \retval None
 */
IFX_EXTERN void IfxCif_setMiLuminanceBurstLength(IfxCif_MiBurstLength burstLength);

/**
 * \brief Sets the initial base address of the ring buffer for a specified main picture path component.
 *
 * \param[in] component The main picture path component for which to set the initial base address.
 * 						Range: \ref IfxCif_MiMainPicturePathComponents
 * \param[in] address   Base address to set (must be word-aligned).
 *
 * \retval None
 */
IFX_EXTERN void IfxCif_setMiMainPictureComponentBaseInitAddress(IfxCif_MiMainPicturePathComponents component, Ifx_AddressValue address);

/**
 * \brief Sets the initial size of the ring buffer for a specified main picture path component.
 *
 * \param[in] component The main picture path component for which to set the initial size.
 * 					    Range: \ref IfxCif_MiMainPicturePathComponents
 * \param[in] size      Size to set for the ring buffer (must be word-aligned).
 *               		Range: 0 to 0xFFFFFC
 *
 * \retval None
 */
IFX_EXTERN void IfxCif_setMiMainPictureComponentInitSize(IfxCif_MiMainPicturePathComponents component, uint32 size);

/**
 * \brief Sets the initial offset counter inside the ring buffer for a specified main picture path component.
 *
 * \param[in] component     The main picture path component for which to set the initial offest counter.
 * 						    Range: \ref IfxCif_MiMainPicturePathComponents
 * \param[in] offsetCounter The Offset counter value to set (must be word aligned).
 * 							Range: 0 to 0xFFFFFC
 *
 * \retval None
 */
IFX_EXTERN void IfxCif_setMiMainPictureComponentInitialOffsetCounter(IfxCif_MiMainPicturePathComponents component, uint32 offsetCounter);

/** \} */

/** \addtogroup IfxLld_Cif_Std_jpeFunctions
 * \{ */

/******************************************************************************/
/*-------------------------Inline Function Prototypes-------------------------*/
/******************************************************************************/

/**
 * \brief Queries the current header generation debug control mode.
 * 
 * \retval IfxCif_JpeHeaderGenerationMode The currently set header generation debug control mode.
 * 		   								  Range: \ref IfxCif_JpeHeaderGenerationMode
 */
IFX_INLINE IfxCif_JpeHeaderGenerationMode IfxCif_getJpeHeaderGenerationMode(void);

/**
 * \brief Queries the currently set JPE header mode.
 *
 * \retval IfxCif_JpeHeaderMode The current JPE header mode.
 * 								Range: \ref IfxCif_JpeHeaderMode
 */
IFX_INLINE IfxCif_JpeHeaderMode IfxCif_getJpeHeaderMode(void);

/**
 * \brief Retrieves the current JPE encode mode.
 *
 * \retval IfxCif_State The current JPE encode mode (always returns 1, as this is the encoder-only edition).
 	 	 	 	 	 	Range: \ref IfxCif_State
 */
IFX_INLINE IfxCif_State IfxCif_getJpeMode(void);

/**
 * \brief Retrieves the current JPE restart interval value.
 *
 * \retval uint16 The current JPE restart interval value in internal cycles or counts.
 *				  Range: 0 to 0xFFFF
 */
IFX_INLINE uint16 IfxCif_getJpeRestartInterval(void);

/**
 * \brief Retrieves the current operational state of the JPEG codec.
 *
 * \retval IfxCif_JpeState The current operational state of the JPEG codec.
 * 						   Range: \ref IfxCif_JpeState_Busy if the JPEG codec is currently processing.
 * 		   				   		  \ref IfxCif_JpeState_Free if the JPEG codec is currently idle and free.
 */
IFX_INLINE IfxCif_JpeState IfxCif_getJpeState(void);

/**
 * \brief Retrieves the current JPE (Joint Photographic Experts Group) Table ID used by the CIF (Common Intermediate Format) module.
 *
 * \retval IfxCif_JpeTableId The current JPE Table ID in use.
 * 							 Range: \ref IfxCif_JpeTableId
 */
IFX_INLINE IfxCif_JpeTableId IfxCif_getJpeTableId(void);

/**
 * \brief Queries the current continuous mode setting of the JPEG/JFIF stream encoder.
 *
 * \retval IfxCif_JpegJfifStreamEncoderContinuousMode The current continuous mode of the encoder.
 *                                                    Range: \ref IfxCif_JpegJfifStreamEncoderContinuousMode
 */
IFX_INLINE IfxCif_JpegJfifStreamEncoderContinuousMode IfxCif_getJpegJfifStreamEncoderContinuousMode(void);

/**
 * \brief Queries the current JPEG picture encoding format.
 *
 * \retval IfxCif_JpegPictureEncodingFormat The current picture encoding format.
 * 											Range: \ref IfxCif_JpegPictureEncodingFormat
 */
IFX_INLINE IfxCif_JpegPictureEncodingFormat IfxCif_getJpegPictureEncodingFormat(void);

/**
 * \brief Starts the JPEG encoder immediately.
 *
 * \retval None
 */
IFX_INLINE void IfxCif_initJpegEncoder(void);

/**
 * \brief Function to start generating JPEG stream header. Auto-resets after one clock cycle.
 * 
 * \retval None
 */
IFX_INLINE void IfxCif_jpeGenerateHeader(void);

/**
 * \brief Sets the JPE header generation debug control mode.
 *
 * \param[in] headerGenerationMode The JPE header Header generation debug control mode to be set.
 * 								   Range: \ref IfxCif_JpeHeaderGenerationMode
 * \retval None
 */
IFX_INLINE void IfxCif_setJpeHeaderGenerationMode(IfxCif_JpeHeaderGenerationMode headerGenerationMode);

/**
 * \brief Sets the JPE header mode for image data formatting.
 *
 * \param[in] headerMode The JPE header mode to be set.
 *                		 Range: \ref IfxCif_JpeHeaderMode
 * \retval None
 */
IFX_INLINE void IfxCif_setJpeHeaderMode(IfxCif_JpeHeaderMode headerMode);

/**
 * \brief sets the restart interval for the JPE engine.
 *
 * \param[in] interval Restart interval value to be set for the JPE engine.
 * 					   Range: 0 to 0xFFFF
 *
 * \retval None
 */
IFX_INLINE void IfxCif_setJpeRestartInterval(uint16 interval);

/**
 * \brief Sets the least significant byte (LSB) of the JPE table data.
 *
 * \param[in] data The value to be set for the LSB of the JPE table data.
 * 				   Range: 0 to 0xFF
 *
 * \retval None
 */
IFX_INLINE void IfxCif_setJpeTableDataLsb(uint8 data);

/**
 * \brief Sets the most significant byte (MSB) of the JPE table data.
 *
 * \param[in] data Value to be set as the MSB of the JPE table data.
 * 			       Range: 0 to 0xFF
 *
 * \retval None
 */
IFX_INLINE void IfxCif_setJpeTableDataMsb(uint8 data);

/**
 * \brief Sets the JPE table ID.
 *
 * \param[in] tableId The JPE table ID to be set.
 * 					  Range: \ref IfxCif_JpeTableId
 *
 * \retval None
 */
IFX_INLINE void IfxCif_setJpeTableId(IfxCif_JpeTableId tableId);

/**
 * \brief Configures the horizontal and vertical sizes of the image for the JPEG codec.
 *
 * \param[in] hSize Horizontal size of the image in pixels.
 * 			        Range: 0 to 0xFFF
 * \param[in] vSize Vertical size of the image in pixels.
 * 					Range: 0 to 0xFFF
 *
 * \retval None
 */
IFX_INLINE void IfxCif_setJpegCodecImageSizes(uint16 hSize, uint16 vSize);

/**
 * \brief Configures the continuous mode for the JPEG JFIF stream encoder.
 *
 * \param[in] mode The encoder continuous mode to be set.
 * 				   Range: \ref IfxCif_JpegJfifStreamEncoderContinuousMode
 *
 * \retval None
 */
IFX_INLINE void IfxCif_setJpegJfifStreamEncoderContinuousMode(IfxCif_JpegJfifStreamEncoderContinuousMode mode);

/**
 * \brief Sets the JPEG picture encoding format.
 *
 * \param[in] format The encoding format to set.
 * 					 Range: \ref IfxCif_JpegPictureEncodingFormat
 *
 * \retval None
 */
IFX_INLINE void IfxCif_setJpegPictureEncodingFormat(IfxCif_JpegPictureEncodingFormat format);

/**
 * \brief Starts the JFIF stream encoder for JPEG encoding. The function automatically resets after one clock cycle.
 * 
 * \retval None
 */
IFX_INLINE void IfxCif_startJpegJfifStreamEncoder(void);

/******************************************************************************/
/*-------------------------Global Function Prototypes-------------------------*/
/******************************************************************************/

/**
 * \brief Clears a JPE interrupt based on the specified interrupt source.
 *
 * \param[in] interruptSource The source of the interrupt to be cleared.
 * 							  Range: \ref IfxCif_JpeInterruptSources
 *
 * \retval None
 */
IFX_EXTERN void IfxCif_clearJpeInterrupt(IfxCif_JpeInterruptSources interruptSource);

/**
 * \brief Queries the the currently set Huffman Table length for AC values.
 *
 * \param[in] table The Huffman table for which to query the current length.
 * 					Range: \ref IfxCif_HuffmanTables
 *
 * \retval uint8 The current length of the Huffman table for AC values.
 * 				 Range: 0 to 0xFF
 */
IFX_EXTERN uint8 IfxCif_getHuffmanAcTableLength(IfxCif_HuffmanTables table);

/**
 * \brief Checks if a specified Huffman Table and its component is enabled for AC values.
 *
 * \param[in] table 	The Huffman Table to check.
 * 						Range: \ref IfxCif_HuffmanTables
 * \param[in] component The Huffman Table component to check.
 * 						Range: \ref IfxCif_HuffmanTableComponents
 *
 * \retval IfxCif_State The current state of the queried Huffman Ac Table and component.
 *   					Range: \ref IfxCif_State_Enabled  if the queried Huffman Table and the Huffman Table component is selected.
 *   						   \ref IfxCif_State_Disabled if the queried Huffman Table and the Huffman Table component is not selected.
 */
IFX_EXTERN IfxCif_State IfxCif_getHuffmanAcTableSelectorState(IfxCif_HuffmanTables table, IfxCif_HuffmanTableComponents component);

/**
 * \brief Queries the current length of the Huffman DC table for the specified table identifier.
 *
 * \param[in] table The Huffman table identifier.
 * 					Range: \ref IfxCif_HuffmanTables
 *
 * \retval uint8 The current length of Huffman DC Table.
 * 			     Range: 0 to 0xFF
 */
IFX_EXTERN uint8 IfxCif_getHuffmanDcTableLength(IfxCif_HuffmanTables table);

/**
 * \brief Check if a Huffman Table and a Huffman Table component is enabled for DC values.
 *
 * \param[in] table 	The Huffman table to check.
 * 						Range: \ref IfxCif_HuffmanTables
 * \param[in] component The Huffman table component to check.
 * 						Range: \ref IfxCif_HuffmanTableComponents
 *
 * \retval IfxCif_State The current state of Huffman Dc Table Selector.
 * 						Range: \ref IfxCif_State_Enabled  if the specified Huffman table and component are enabled for DC values.
 * 							   \ref IfxCif_State_Disabled if the specified Huffman table and component are not enabled for DC values.
 */
IFX_EXTERN IfxCif_State IfxCif_getHuffmanDcTableSelectorState(IfxCif_HuffmanTables table, IfxCif_HuffmanTableComponents component);

/**
 * \brief Function to query the state of a JPE debug signal source.
 *
 * \param[in] source The source for which to query the debug signal state.
 * 					 Range: \ref IfxCif_JpeDebugSignalSources
 *
 * \retval IfxCif_JpeDebugSignalState The Current state of an JPE debug signal source.
 * 									  Range: \ref IfxCif_JpeDebugSignalState_Inactive if the debug signal is currently inactive.
 * 									  	     \ref IfxCif_JpeDebugSignalState_Active   if the debug signal is currently active.
 */
IFX_EXTERN IfxCif_JpeDebugSignalState IfxCif_getJpeDebugSignalState(IfxCif_JpeDebugSignalSources source);

/**
 * \brief Function to query the enabled state of a JPE interrupt source.
 *
 * \param[in] interruptSource The JPE interrupt source to query.
 * 							  Range: \ref IfxCif_JpeInterruptSources
 *
 * \retval IfxCif_State The current state of the JPE interrupt source.
 * 						Range: \ref IfxCif_State_Enabled  if the interrupt is enabled.
 * 							   \ref IfxCif_State_Disabled if the interrupt is disabled.
 */
IFX_EXTERN IfxCif_State IfxCif_getJpeInterruptEnableState(IfxCif_JpeInterruptSources interruptSource);

/**
 * \brief Retrieves the currently selected Q-Table for a specified JPEG component.
 *
 * \param[in] component The component for which to query the currently selected Q-Table.
 *						Range: \ref IfxCif_JpeQTableSelectorComponents
 *
 * \retval IfxCif_JpeQTableSelector The currently selected Q-Table for the specified component.
 * 									Range: \ref IfxCif_JpeQTableSelector
 */
IFX_EXTERN IfxCif_JpeQTableSelector IfxCif_getJpeQTableSelector(IfxCif_JpeQTableSelectorComponents component);

/**
 * \brief Queries the enabled state of scaling for a specified input value source.
 *
 * \param[in] source Input value source for which to query the enabled state.
 * 				     Range: \ref IfxCif_JpeScalingValueSources
 *
 * \retval IfxCif_State The current state of the scaling of an input value source.
 * 					    Range: \ref IfxCif_State_Enabled  if the scaling is enabled for the specified source.
 * 		   					   \ref IfxCif_State_Disabled if the scaling is disabled for the specified source.
 */
IFX_EXTERN IfxCif_State IfxCif_getJpeScalingEnableState(IfxCif_JpeScalingValueSources source);

/**
 * \brief Queries the currently set JPEG codec image size for a specified tier.
 *
 * \param[in] tier The tier for which to query the JPEG codec image size.
 * 				   Range: \ref IfxCif_ImageTiers
 *
 * \retval uint16 The currently set image size for R2B and SGEN blocks.
 *                Range: 0 to 0xFFF
 */
IFX_EXTERN uint16 IfxCif_getJpegCodecImageSize(IfxCif_ImageTiers tier);

/**
 * \brief Function to query the masked state of a JPE interrupt.
 *
 * \param[in] interruptSource The JPE interrupt source to query.
 * 							  Range: \ref IfxCif_JpeInterruptSources
 *
 * \retval IfxCif_InterruptTriggeredState The current masked state of a JPE interrupt.
 * 										  Range: \ref IfxCif_InterruptTriggeredState_Triggered    if the interrupt request bit is set and the interrupt is enabled.
 * 										  		 \ref IfxCif_InterruptTriggeredState_NotTriggered if the interrupt request bit is not set or the interrupt is disabled.
 */
IFX_EXTERN IfxCif_InterruptTriggeredState IfxCif_getMaskedJpeInterruptTriggeredState(IfxCif_JpeInterruptSources interruptSource);

/**
 * \brief Function to query the raw state of a JPE interrupt source.
 *
 * \param[in] interruptSource The JPE interrupt source to query.
 *							  Range: \ref IfxCif_JpeInterruptSources
 *
 * \retval IfxCif_InterruptTriggeredState The current raw state of a JPE interrupt source.
 * 										  Range: \ref IfxCif_InterruptTriggeredState_Triggered    if the interrupt request bit for the specified source is set.
 *          							  		 \ref IfxCif_InterruptTriggeredState_NotTriggered if the interrupt request bit for the specified source is not set.
 */
IFX_EXTERN IfxCif_InterruptTriggeredState IfxCif_getRawJpeInterruptTriggeredState(IfxCif_JpeInterruptSources interruptSource);

/**
 * \brief Programs a JPE table with specified data.
 *
 * \param[in] tableId    The identifier of the JPE table to be programmed.
 * 					     Range: \ref IfxCif_JpeTableId
 * \param[in] tableEntry Pointer to the data to be programmed into the specified JPE table.
 * \param[in] length     The number of bytes to be programmed into the table.
 * 						 Range: 0xFF
 *
 * \retval None
 */
IFX_EXTERN void IfxCif_programJpeTable(IfxCif_JpeTableId tableId, const uint8 *tableEntry, uint8 length);

/**
 * \brief Sets the length of the specified AC Huffman table.
 *
 * \param[in] table  The Huffman table to configure.
 * 					 Range: \ref IfxCif_HuffmanTables
 * \param[in] length The length to set for the specified Huffman table.
 * 					 Range: 0xFF
 *
 * \retval None
 */
IFX_EXTERN void IfxCif_setHuffmanAcTableLength(IfxCif_HuffmanTables table, uint8 length);

/**
 * \brief Sets the Huffman Table selector for AC Values.
 *
 * \param[in] table     The Huffman table to select.
 * 					    Range: \ref IfxCif_HuffmanTables
 * \param[in] component The Huffman table component to select.
 * 						Range: \ref IfxCif_HuffmanTableComponents
 *
 * \retval None
 */
IFX_EXTERN void IfxCif_setHuffmanAcTableSelector(IfxCif_HuffmanTables table, IfxCif_HuffmanTableComponents component);

/**
 * \brief Sets the Huffman DC table length for the specified table.
 *
 * \param[in] table  Huffman Table for which length to be set.
 * 					 Range: \ref IfxCif_HuffmanTables
 * \param[in] length The length to be set for the specified Huffman table.
 * 					 Range: 0 to 0xFF
 *
 * \retval None
 */
IFX_EXTERN void IfxCif_setHuffmanDcTableLength(IfxCif_HuffmanTables table, uint8 length);

/**
 * \brief Sets the Huffman Table selector for DC values.
 *
 * \param[in] table     The Huffman table to select.
 * 				        Range: \ref IfxCif_HuffmanTables
 * \param[in] component The Huffman table component to configure.
 * 						Range: \ref IfxCif_HuffmanTableComponents
 *
 * \retval None
 */
IFX_EXTERN void IfxCif_setHuffmanDcTableSelector(IfxCif_HuffmanTables table, IfxCif_HuffmanTableComponents component);

/**
 * \brief Enables or disables a JPE interrupt source.
 *
 * \param[in] interruptSource      The JPE interrupt source to configure.
 * 								   Range: \ref IfxCif_JpeInterruptSources
 * \param[in] interruptEnableState The state to set for the interrupt source.
 *                                 Range: \ref IfxCif_State_Enabled  to enable the interrupt.
 *                                 	      \ref IfxCif_State_Disabled to disable the interrupt.
 *
 * \retval None
 */
IFX_EXTERN void IfxCif_setJpeInterruptEnableState(IfxCif_JpeInterruptSources interruptSource, IfxCif_State interruptEnableState);

/**
 * \brief Sets an interrupt request bit for the specified JPE interrupt source.
 *        This function does not necessarily trigger an interrupt but sets the request bit.
 *
 * \param[in] interruptSource The source of the JPE interrupt to be set.
 * 							  Range: \ref IfxCif_JpeInterruptSources
 *
 * \retval None
 */
IFX_EXTERN void IfxCif_setJpeInterruptRequestBit(IfxCif_JpeInterruptSources interruptSource);

/**
 * \brief Sets the Q-Table selector for a specific component.
 *
 * \param[in] component The color component for which to select the Q-Table.
 * 						Range: \ref IfxCif_JpeQTableSelectorComponents
 * \param[in] selector  The Q-Table to select.
 * 						Range: \ref IfxCif_JpeQTableSelector
 *
 * \retval None
 */
IFX_EXTERN void IfxCif_setJpeQTableSelector(IfxCif_JpeQTableSelectorComponents component, IfxCif_JpeQTableSelector selector);

/**
 * \brief Configures whether scaling is enabled or disabled for a specific input value source.
 *
 * \param[in] source        Input value source for which to configure the scaling state.
 *             		        Range: \ref IfxCif_JpeScalingValueSources
 * \param[in] scalingEnable State to set for scaling.
 *                          Range: \ref IfxCif_State_Enabled  to enable scaling.
 *                          	   \ref IfxCif_State_Disabled to disable scaling
 *
 * \retval None
 */
IFX_EXTERN void IfxCif_setJpeScalingEnableState(IfxCif_JpeScalingValueSources source, IfxCif_State scalingEnable);

/**
 * \brief Sets the JPEG codec image size for a specified tier.
 *
 * \param[in] tier  The tier for which to set the JPEG codec image size.
 * 				    Range: \ref IfxCif_ImageTiers
 * \param [in] size The Image size for R2B and SGEN blocks.
 * 					Range: 0 to 0xFFF
 * \retval None
 */
IFX_EXTERN void IfxCif_setJpegCodecImageSize(IfxCif_ImageTiers tier, uint16 size);

/** \} */

/** \addtogroup IfxLld_Cif_Std_swFunctions
 * \{ */

/******************************************************************************/
/*-------------------------Inline Function Prototypes-------------------------*/
/******************************************************************************/

/**
 * \brief Retrieves the currently configured predivider value for the Security Watchdog Counter.
 *
 * \retval uint16 The currently set predivider value.
 * 				  Range: 0 to 0xFFFF
 */
IFX_INLINE uint16 IfxCif_getSecurityWatchdogCounterPredivider(void);

/**
 * \brief Queries and returns the enabled state of the Security Watchdog unit.
 *
 * \return IfxCif_State The current states of the Security Watchdog unit.
 * 						Range: \ref IfxCif_State_Enabled  if the Security Watchdog is enabled.
 *         					   \ref IfxCif_State_Disabled if the Security Watchdog is disabled.
 */
IFX_INLINE IfxCif_State IfxCif_getSecurityWatchdogEnableState(void);

/**
 * \brief Sets the watchdog predivider counter for the CIF security watchdog. (A value of 0 means the Watchdog Counters are incremented with every CIF clock cycle.
 *        For any other value N, the counters are incremented every N+1th cycle).
 *
 * \param[in] predivider The predivider value to set.
						 Range: 0 to 0xFFFF
 *
 * \retval None
 */
IFX_INLINE void IfxCif_setSecurityWatchdogCounterPredivider(uint16 predivider);

/**
 * \brief Function to enable or disable the security watchdog unit.
 *
 * \param[in] enableState The state to set for the security watchdog unit.
 *                        Range: \ref IfxCif_State_Enabled  to enable the watchdog unit.
 *                        		 \ref IfxCif_State_Disabled to disable the watchdog unit.
 *
 * \retval None
 */
IFX_INLINE void IfxCif_setSecurityWatchdogEnableState(IfxCif_State enableState);

/******************************************************************************/
/*-------------------------Global Function Prototypes-------------------------*/
/******************************************************************************/

/**
 * \brief Clears a security watchdog interrupt.
 *
 * \param[in] interruptSource The source of the interrupt to be cleared.
 *                            Range: \ref IfxCif_SecurityWatchdogInterruptSources
 *
 * \retval None
 */
IFX_EXTERN void IfxCif_clearSecurityWatchdogInterrupt(IfxCif_SecurityWatchdogInterruptSources interruptSource);

/**
 * \brief Gets the masked state of a security watchdog interrupt.
 * 
 * \param[in] interruptSource The source of the security watchdog interrupt to check.
 *                            Range: \ref IfxCif_SecurityWatchdogInterruptSources.
 * 
 * \retval IfxCif_InterruptTriggeredState The current state of the interrupt source.
 * 										  Range: \ref IfxCif_InterruptTriggeredState_Triggered    if the interrupt request bit is set and the interrupt is enabled.
 * 										  		 \ref IfxCif_InterruptTriggeredState_NotTriggered if the interrupt request bit is not set or the interrupt is disabled.
 */
IFX_EXTERN IfxCif_InterruptTriggeredState IfxCif_getMaskedSecurityWatchdogInterruptTriggeredState(IfxCif_SecurityWatchdogInterruptSources interruptSource);

/**
 * \brief Gets the raw state of a security watchdog interrupt.
 *
 * \param[in] interruptSource The source of the security watchdog interrupt to query.
 *                            Range: \ref IfxCif_SecurityWatchdogInterruptSources.
 *
 * \retval IfxCif_InterruptTriggeredState The current state of an interrupt.
 * 		   								  Range: \ref IfxCif_InterruptTriggeredState_Triggered 	  if the interrupt request bit is set.
 *		   								  		 \ref IfxCif_InterruptTriggeredState_NotTriggered if the interrupt request bit is not set.
 */
IFX_EXTERN IfxCif_InterruptTriggeredState IfxCif_getRawSecurityWatchdogInterruptTriggeredState(IfxCif_SecurityWatchdogInterruptSources interruptSource);

/**
 * \brief Retrieves the enabled state of a specified security watchdog interrupt source.
 *
 * \param[in] interruptSource The interrupt source to query.
 * 							  Range: \ref IfxCif_SecurityWatchdogInterruptSources
 *
 * \retval IfxCif_State The current state of the interrupt source.
 * 						Range: \ref IfxCif_State_Enabled  if the interrupt is enabled.
 *  						   \ref IfxCif_State_Disabled if the interrupt is disabled.
 */
IFX_EXTERN IfxCif_State IfxCif_getSecurityWatchdogInterruptEnableState(IfxCif_SecurityWatchdogInterruptSources interruptSource);

/**
 * \brief Retrieves the current timeout value for a specified security watchdog counter in a given tier.
 *
 * \param[in] tier 			 Tier for which to query the timeout counter.
 * 							 Range:\ref IfxCif_ImageTiers
 * \param[in] timeoutCounter The specific timeout counter to query.
 * 							 Range: \ref IfxCif_SecurityWatchdogTimeoutCounters
 *
 * \retval uint16 The current timeout value of the specified counter in the given tier.
 * 				  Range: 0 to 0xFFFF
 */
IFX_EXTERN uint16 IfxCif_getSecurityWatchdogTimeout(IfxCif_ImageTiers tier, IfxCif_SecurityWatchdogTimeoutCounters timeoutCounter);

/**
 * \brief Resets the specified security watchdog counter to its initial state.
 *
 * \param[in] counter The watchdog counter to reset.
 * 					  Range: \ref IfxCif_SecurityWatchdogCounters
 *
 * \retval None
 */
IFX_EXTERN void IfxCif_resetSecurityWatchdogCounter(IfxCif_SecurityWatchdogCounters counter);

/**
 * \brief Configures the enable state of a security watchdog interrupt.
 *
 * \param[in] interruptSource      The source of the interrupt to configure.
 * 								   Range: \ref IfxCif_SecurityWatchdogInterruptSources.
 * \param[in] interruptEnableState The state to set for the interrupt.
 *                                 Range: \ref IfxCif_State_Enabled  if the interrupt is enabled.
 *                                 		  \ref IfxCif_State_Disabled if the interrupt is disabled.
 *
 * \retval None
 */
IFX_EXTERN void IfxCif_setSecurityWatchdogInterruptEnableState(IfxCif_SecurityWatchdogInterruptSources interruptSource, IfxCif_State interruptEnableState);

/**
 * \brief Sets an interrupt request bit for a specified security watchdog interrupt source.
 *        This function does not necessarily trigger an interrupt but sets the request bit.
 *
 * \param[in] interruptSource The source of the interrupt to set the request bit for.
 * 							  Range: \ref IfxCif_SecurityWatchdogInterruptSources
 *
 * \retval None
 */
IFX_EXTERN void IfxCif_setSecurityWatchdogInterruptRequestBit(IfxCif_SecurityWatchdogInterruptSources interruptSource);

/**
 * \brief Sets the timeout for a watchdog timeout counter of a specified tier.
 *        A timeout value of 0 disables the timeout.
 *
 * \param[in] tier           The tier for which to set the timeout.
 * 						     Range: \ref IfxCif_ImageTiers
 * \param[in] timeoutCounter The watchdog timeout counter to configure.
 * 							 Range: \ref IfxCif_SecurityWatchdogTimeoutCounters
 * \param[in] timeout        The timeout value to set.
 * 							 Range: 0 to 0xFFFF
 *
 * \retval None
 */
IFX_EXTERN void IfxCif_setSecurityWatchdogTimeout(IfxCif_ImageTiers tier, IfxCif_SecurityWatchdogTimeoutCounters timeoutCounter, uint16 timeout);

/** \} */

/** \addtogroup IfxLld_Cif_Std_ispisFunctions
 * \{ */

/******************************************************************************/
/*-------------------------Inline Function Prototypes-------------------------*/
/******************************************************************************/

/**
 * \brief Queries and returns the enabled state of image stabilization.
 *
 * \retval IfxCif_State The current state of the Image stabilization.
 * 						Range: \ref IfxCif_State_Enabled  if image stabilization is enabled.
  	  	  	  				   \ref IfxCif_State_Disabled if image stabilization is disabled.
 */
IFX_INLINE IfxCif_State IfxCif_getIspisEnableState(void);

/**
 * \brief Retrieves the current image stabilization recenter value.
 *
 * \retval uint8 The current image stabilization recenter value.
 * 				 Range: 0 Recenter feature switched off For all other values recentering is active (cur_h/v_offs-H/V_OFFS)/2 power(recenter)
 */
IFX_INLINE uint8 IfxCif_getIspisRecenterValue(void);

/**
 * \brief Enables or disables the image stabilization feature.
 *
 * \param[in] enableState The state to set for image stabilization.
 *                        Range: \ref IfxCif_State_Enabled	to enable image stabilization.
 *                        	     \ref IfxCif_State_Disabled to disable image stabilization.
 *
 * \retval None
 */
IFX_INLINE void IfxCif_setIspisEnableState(IfxCif_State enableState);

/**
 * \brief Sets the image stabilization offsets of the output window.
 *
 * \param [in] hOffset The horizontal offset configuration.
 * 					   Range: \ref  IfxCif_ImageTiers
 * \param[in] vOffset  The vertical offset value.
 * 					   Range: 0 to 0xFFF
 *
 * \retval None
 */
IFX_INLINE void IfxCif_setIspisOutputWindowOffsets(IfxCif_ImageTiers hOffset, uint16 vOffset);

/**
 * \brief Configures the ISPIS Picture Sizes with the specified horizontal and vertical picture sizes.
 *
 * \param[in] hSize Horizontal size of the picture.
 * 					Range: 001H (ITU-R BT.656 YUV)
 * 					 	   002H (ITU-R BT.601 YUV)
 * 					 	   003H (ITU-R BT.601 Bayer RGB)
 * 					 	   005H (ITU-R BT.656 Bayer RGB)
 * \param[in] vSize Vertical size of the picture.
 *					Range: 0 to 0xFFF
 * \retval None
 */
IFX_INLINE void IfxCif_setIspisPictureSizes(uint16 hSize, uint16 vSize);

/**
 * \brief Sets the image stabilization recenter value.
 *
 * \param[in] value Recenter value to set.
 * 					Range: 0 to disabled recenter value, for all other values recentering is active (cur_h/v_offs-H/V_OFFS)/2 power(recenter)).
 *
 * \retval None
 */
IFX_INLINE void IfxCif_setIspisRecenterValue(uint8 value);

/******************************************************************************/
/*-------------------------Global Function Prototypes-------------------------*/
/******************************************************************************/

/**
 * \brief Function to query the current camera displacement for one tier.
 * 
 * \param[in] tier The tier for which to query the camera displacement.
 * 				   Range: \ref IfxCif_ImageTiers
 * 
 * \retval uint16 The current camera displacement value.
 *				  Range: 0 to 0xFFF
 */
IFX_EXTERN uint16 IfxCif_getIspisCameraDisplacement(IfxCif_ImageTiers tier);

/**
 * \brief Function to query the offset of the current picture for one tier
 *
 * \param[in] tier The tier for which to query the offset.
 * 				   Range: \ref IfxCif_ImageTiers
 *
 * \retval uint16 The offset of the current picture.
 *				  Range: 0 to 0x1FFF
 */
IFX_EXTERN uint16 IfxCif_getIspisCurrentPictureOffset(IfxCif_ImageTiers tier);

/**
 * \brief Queries the picture size of the current picture for a specified tier.
 *
 * \param[in] tier The tier for which to query the picture size.
 * 				   Range: \ref IfxCif_ImageTiers
 *
 * \retval uint16 The picture size of the current picture for the specified tier.
 * 				  Range: 0 to 0x1FFF
 */
IFX_EXTERN uint16 IfxCif_getIspisCurrentPictureSize(IfxCif_ImageTiers tier);

/**
 * \brief Queries the current maximum displacement for a specified image tier.
 *
 * \param[in] tier The image tier for which to query the maximum displacement.
 * 				   Range: \ref IfxCif_ImageTiers
 *
 * \retval uint16 The current maximum displacement in pixels.
 * 				  Range: 0 to 0xFFF
 */
IFX_EXTERN uint16 IfxCif_getIspisMaximumDisplacement(IfxCif_ImageTiers tier);

/**
 * \brief Function to query the current image stabilization offset of the output window for a specified tier.
 *
 * \param[in] tier The tier for which to query the offset.
 * 					Range: \ref IfxCif_ImageTiers
 *
 * \retval uint16 The current image stabilization offset of the output window for the specified tier.
 * 				  Range: 0 to 0xFFF
 */
IFX_EXTERN uint16 IfxCif_getIspisOffsetOutputWindow(IfxCif_ImageTiers tier);

/**
 * \brief Function to query the current picture size for one tier.
 *
 * \param[in] tier The tier for which to query the picture size.
 * 				   Range: \ref IfxCif_ImageTiers
 *
 * \retval uint16 The current picture size in pixels.
 * 				  Range: 0 to 0xFFF
 */
IFX_EXTERN uint16 IfxCif_getIspisPictureSize(IfxCif_ImageTiers tier);

/**
 * \brief Queries and returns the enabled state of the image stabilization recenter feature.
 *
 * \retval IfxCif_State	The current state of image stabilization recenter feature.
 * 						Range: \ref IfxCif_State_Enabled  if the image stabilization recenter feature is enabled.
 * 							   \ref IfxCif_State_Disabled if the image stabilization recenter feature is disabled.
 */
IFX_EXTERN IfxCif_State IfxCif_getIspisRecenterEnableState(void);

/**
 * \brief Sets the camera displacement value for a specified tier.
 *
 * \param[in] tier 		   The tier for which the camera displacement is to be set.
 * 						   Range: 0 to 0xFFFF
 * \param[in] displacement The camera displacement value to be set for the specified tier.
 * 						   Range: 0 to 0xFFF
 *
 * \retval None
 */
IFX_EXTERN void IfxCif_setIspisCameraDisplacement(uint16 tier, uint16 displacement);

/**
 * \brief Sets the maximum displacement for a specified image tier.
 *
 * \param[in] tier         The image tier for which to set the maximum displacement.
 * 				   		   Range: \ref IfxCif_ImageTiers
 * \param[in] displacement The maximum displacement value to set.
 * 						   Range: 0 to 0xFFF
 *
 * \retval None
 */
IFX_EXTERN void IfxCif_setIspisMaximumDisplacement(IfxCif_ImageTiers tier, uint16 displacement);

/**
 * \brief Sets the image stabilization offset of the output window for a specified tier.
 *
 * \param[in] tier   The tier for which the offset is to be set.
 * 				     Range: \ref IfxCif_ImageTiers
 * \param[in] offset Offset value to be applied to the output window.
 * 					 Range: 0 to 0xFFFF
 *
 * \retval None
 */
IFX_EXTERN void IfxCif_setIspisOutputWindowOffset(IfxCif_ImageTiers tier, uint16 offset);

/**
 * \brief Sets the picture size for a specific image tier.
 *
 * \param[in] tier    The image tier for which to set the size.
 * 					  Range: \ref IfxCif_ImageTiers
 * \param[in] sizeThe size to set for the specified tier.
 * 					  Range: 0 to 0xFFF
 *
 * \retval None
 */
IFX_EXTERN void IfxCif_setIspisPictureSize(IfxCif_ImageTiers tier, uint16 size);

/** \} */

/** \addtogroup IfxLld_Cif_Std_epFunctions
 * \{ */

/******************************************************************************/
/*-------------------------Global Function Prototypes-------------------------*/
/******************************************************************************/

/**
 * \brief Clears a specific extra path error source.
 *
 * \param[in] source The extra path error source to clear.
 * 					 Range: \ref IfxCif_EpErrorClearSources
 *
 * \retval None
 */
IFX_EXTERN void IfxCif_clearEpError(IfxCif_EpErrorClearSources source);

/**
 * \brief Clears the specified endpoint interrupt for the given extra path.
 *
 * \param[in] z 			  The extra path for which the interrupt should be cleared.
 * 							  Range: \ref IfxCif_ExtraPath
 * \param[in] interruptSource The source of the interrupt to be cleared.
 * 							  Range: \ref IfxCif_EpInterrupts
 *
 * \retval None
 */
IFX_EXTERN void IfxCif_clearEpInterrupt(IfxCif_ExtraPath z, IfxCif_EpInterrupts interruptSource);

/**
 * \brief Triggers an immediate configuration update for a specified extra path.
 *
 * \param[in] z Triggers an immediate configuration update for one extra path.
 * 				Range: \ref IfxCif_ExtraPath
 *
 * \retval None
 */
IFX_EXTERN void IfxCif_epForceConfigurationUpdate(IfxCif_ExtraPath z);

/**
 * \brief Function to skip one picture of one extra path.
 * 
 * \param[in] z Extra path for which to skip one picture.
 * 				Range: \ref IfxCif_ExtraPath
 * 
 * \retval None
 */
IFX_EXTERN void IfxCif_epSkipPicture(IfxCif_ExtraPath z);

/**
 * \brief Function to query the current base address of the ring buffer of one extra path.
 *
 * \param[in] z The extra path for which to query the current base address of the ring buffer.
 *              Range: \ref IfxCif_ExtraPath
 *
 * \retval uint32 The current base address of the ring buffer.
 * 				  Range: 0 to 0xFFFFFFFC
 */
IFX_EXTERN uint32 IfxCif_getEpBaseAddress(IfxCif_ExtraPath z);

/**
 * \brief Function to query the initial base address of the ring buffer of one extra path.
 *
 * \param[in] z The extra path for which to query the initial base address.
 * 				Range: \ref IfxCif_ExtraPath
 *
 * \retval uint32 The initial base address of the ring buffer of the specified extra path.
 * 				  Range: 0 to 0xFFFFFFFC
 */
IFX_EXTERN uint32 IfxCif_getEpBaseInitAddress(IfxCif_ExtraPath z);

/**
 * \brief Function to query the image cropping camera displacement of one tier of one extra path.
 *
 * \param[in] z    The extra path for which to query the image cropping camera displacement.
 *             	   Range: \ref IfxCif_ExtraPath
 * \param[in] tier The tier for which to query the image cropping camera displacement.
 *                 Range: \ref IfxCif_ImageTiers
 *
 * \retval uint16 The current image cropping camera displacement value.
 * 				  Range: 0 to 0xFFF
 */
IFX_EXTERN uint16 IfxCif_getEpCroppingCameraDisplacement(IfxCif_ExtraPath z, IfxCif_ImageTiers tier);

/**
 * \brief Function to query the current image cropping picture offset of one tier of one extra path.
 * 
 * \param[in] z    The extra path for which to query the current image cropping picture offset.
 * 				   Range: \ref IfxCif_ExtraPath
 * \param[in] tier The tier for which to query the current image cropping picture offset. 
 * 				   Range: \ref IfxCif_ImageTiers
 *
 * \retval uint16 The current image cropping picture offset.
 * 				  Range: 0 to 0x1FFF
 */
IFX_EXTERN uint16 IfxCif_getEpCroppingCurrentPictureOffset(IfxCif_ExtraPath z, IfxCif_ImageTiers tier);

/**
 * \brief Function to query the current image cropping picture size of one tier of one extra path.
 *
 * \param[in] z    The extra path for which to query the current image cropping picture size.
 *             	   Range: \ref IfxCif_ExtraPath
 * \param[in] tier The tier for which to query the current image cropping picture size.
 * 				   Range: \ref IfxCif_ImageTiers
 *
 * \retval uint16 The current image cropping picture size.
 *				  Range: 0 to 0x1FFF
 */
IFX_EXTERN uint16 IfxCif_getEpCroppingCurrentPictureSize(IfxCif_ExtraPath z, IfxCif_ImageTiers tier);

/**
 * \brief Function to query the image cropping enabled state of one extra path.
 *
 * \param[in] z The extra path for which to query the image cropping enabled state.
 * 				Range: \ref IfxCif_ExtraPath
 *
 * \retval IfxCif_State The current endpoint cropping state.
 * 						Range: \ref IfxCif_State_Enabled  if the image cropping is enabled for the specified extra path.
 * 		  			    	   \ref IfxCif_State_Disabled if the image cropping is disabled for the specified extra path.
 */
IFX_EXTERN IfxCif_State IfxCif_getEpCroppingEnableState(IfxCif_ExtraPath z);

/**
 * \brief Function to query the maximum displacement of one tier of one extra path.
 *
 * \param[in] z    Extra path for which to query the maximum displacement.
 * 				   Range: \ref IfxCif_ExtraPath
 * \param[in] tier Tier for which to query the maximum displacement.
 * 				   Range: \ref IfxCif_ImageTiers
 *
 * \retval uint16 The current maximum displacement as a uint16 value.
 *				  Range: 0 to 0xFFF
 */
IFX_EXTERN uint16 IfxCif_getEpCroppingMaximumDisplacement(IfxCif_ExtraPath z, IfxCif_ImageTiers tier);

/**
 * \brief Function to query the image cropping offset of the output window of one tier of one extra path.
 * 
 * \param[in] z    The extra path for which to query the image cropping offset of the output window.
 *                 Range: \ref IfxCif_ExtraPath
 * \param[in] tier The tier for which to query the image cropping offset of the output window.
 *                 Range: \ref IfxCif_ImageTiers
 * 
 * \retval uint16 The current image cropping offset of the output window.
 * 				  Range: 0 to 0xFFF
 */
IFX_EXTERN uint16 IfxCif_getEpCroppingOffsetOutputWindow(IfxCif_ExtraPath z, IfxCif_ImageTiers tier);

/**
 * \brief Function to query the image cropping picture size of one tier of one extra path.
 *
 * \param[in] z    The extra path for which to query the image cropping picture size.
 *                 Range: \ref IfxCif_ExtraPath
 * \param[in] tier The tier for which to query the image cropping picture size.
 *                 Range: \ref IfxCif_ImageTiers
 *
 * \retval uint16 The cropping picture size for the specified tier of the extra path.
 *				  Range: 0 to 0xFFF
 */
IFX_EXTERN uint16 IfxCif_getEpCroppingPictureSize(IfxCif_ExtraPath z, IfxCif_ImageTiers tier);

/**
 * \brief Function to query the enabled state of the recenter feature of one extra path.
 *
 * \param[in] z The extra path for which to query the recenter feature state.
 * 				Range: \ref IfxCif_ExtraPath
 *
 * \retval IfxCif_State The current endpoint cropping recenter state.
 * 						Range: \ref IfxCif_State_Enabled  if the recenter feature is enabled.
 * 		   					   \ref IfxCif_State_Disabled if the recenter feature is disabled.
 */
IFX_EXTERN IfxCif_State IfxCif_getEpCroppingRecenterState(IfxCif_ExtraPath z);

/**
 * \brief Queries the error state of a specified extra path error source.
 *
 * \param[in] source The error source to query.
 * 					 Range: \ref IfxCif_EpErrorSources
 *
 * \retval IfxCif_ErrorState The current endpoint Error state.
 * 							 Range: \ref IfxCif_ErrorState_NoError if the error did not occur.
 * 		   					 		\ref IfxCif_ErrorState_Error   if the error occurred.
 */
IFX_EXTERN IfxCif_ErrorState IfxCif_getEpErrorState(IfxCif_EpErrorSources source);

/**
 * \brief Function to query the enabled state of a specific feature for a given extra path.
 *
 * \param[in] z       The extra path for which to query the feature state.
 * 					  Range: \ref IfxCif_ExtraPath
 * \param[in] feature The specific feature of the extra path to query.
 * 			  		  Range: \ref IfxCif_EpFeatures
 *
 * \retval IfxCif_State The current endpoint feature state.
 * 						Range: \ref IfxCif_State_Enabled  if the feature is enabled.
 * 		   					   \ref IfxCif_State_Disabled if the feature is disabled.
 */
IFX_EXTERN IfxCif_State IfxCif_getEpFeatureEnableState(IfxCif_ExtraPath z, IfxCif_EpFeatures feature);

/**
 * \brief Function to query the initial size of the ring buffer of one extra path.
 *
 * \param[in] z The extra path for which to query the initial size.
 * 				Range: \ref IfxCif_ExtraPath
 *
 * \retval uint32 The initial size of the ring buffer of the specified extra path.
 * 				  Range: 0 to 0xFFFFFC
 */
IFX_EXTERN uint32 IfxCif_getEpInitSize(IfxCif_ExtraPath z);

/**
 * \brief Retrieves the initial filling level interrupt offset for a specified extra path.
 *
 * \param[in] z The extra path selector.
 * 				Range: \ref IfxCif_ExtraPath
 *
 * \retval uint32 The initial filling level interrupt offset for the specified extra path.
 * 				  Range: 0 to 0xFFFFFC
 */
IFX_EXTERN uint32 IfxCif_getEpInitialFillLevelInterruptOffset(IfxCif_ExtraPath z);

/**
 * \brief Function to query the initial offset counter for a specific extra path.
 *
 * \param[in] z The extra path for which to query the initial offset counter.
 * 				Range: \ref IfxCif_ExtraPath
 *
 * \retval uint32 The initial offset counter of the specified extra path.
 * 				  Range: 0 to 0xFFFFFC
 */
IFX_EXTERN uint32 IfxCif_getEpInitialOffsetCounter(IfxCif_ExtraPath z);

/**
 * \brief Queries the current input enable state for specified extra path.
 *
 * \param[in] z The Extra path for which to query the current input enable state.
 * 				Range: \ref IfxCif_ExtraPath
 *
 * \retval IfxCif_State The current endpoint Interrupt state.
 * 		   				Range: \ref IfxCif_State_Enabled  if the extra path is enabled in MI_IN.
 * 		   					   \ref IfxCif_State_Disabled if the extra path is disabled in MI_IN.
 */
IFX_EXTERN IfxCif_State IfxCif_getEpInputEnableState(IfxCif_ExtraPath z);

/**
 * \brief Queries the enabled state of a specific endpoint interrupt for a given extra path.
 *
 * \param[in] z 			  The extra path for which to query the interrupt state.
 *             				  Range: \ref IfxCif_ExtraPath
 * \param[in] interruptSource The specific interrupt source within the endpoint.
 *                            Range: \ref IfxCif_EpInterrupts
 *
 * \retval IfxCif_State The current endpoint Interrupt state.
 * 						Range: \ref IfxCif_State_Enabled  if the interrupt is enabled.
 * 							   \ref IfxCif_State_Disabled if the interrupt is disabled.
 */
IFX_EXTERN IfxCif_State IfxCif_getEpInterruptEnableState(IfxCif_ExtraPath z, IfxCif_EpInterrupts interruptSource);

/**
 * \brief Function to query the current interrupt offset of one extra path
 * 
 * \param[in] z The extra path for which to query the current interrupt offset. 
 * 				Range: \ref IfxCif_ExtraPath
 *
 * retval uint32 The current offset counter value of the specified extra path.
 * 				 Range: 0 to 0xFFFFFC
 */
IFX_EXTERN uint32 IfxCif_getEpInterruptOffset(IfxCif_ExtraPath z);

/**
 * \brief Function to query the current offset counter of one extra path.
 *
 * \param[in] z The extra path for which to query the current offset counter.
 * 				Range: \ref IfxCif_ExtraPath
 *
 * \retval uint32 The current offset counter value of the specified extra path.
 * 				  Range: 0 to 0xFFFFFC
 */
IFX_EXTERN uint32 IfxCif_getEpOffsetCounter(IfxCif_ExtraPath z);

/**
 * \brief Queries the initial offset counter start value for a specified extra path.
 *
 * \param[in] z The extra path for which to query the initial offset counter start value.
 *              Range: \ref IfxCif_ExtraPath
 *
 * \retval uint32 The initial offset counter start value of the specified extra path.
 * 				  Range: 0 to 0xFFFFFC
 */
IFX_EXTERN uint32 IfxCif_getEpOffsetCounterStart(IfxCif_ExtraPath z);

/**
 * \brief Queries the current output enable state for the specified extra path.
 *
 * \param[in] z The Extra path for which to query the current output enable state.
 * 				Range: \ref IfxCif_State
 *
 * \retval IfxCif_State The current output enable state for the specified extra path.
 * 						Range: \ref IfxCif_State_Enabled  if the extra path is enabled for use in MI_OUT.
 * 		   					   \ref IfxCif_State_Disabled if the extra path is disabled for use in MI_OUT.
 */
IFX_EXTERN IfxCif_State IfxCif_getEpOutputEnableState(IfxCif_ExtraPath z);

/**
 * \brief Function to query the current recenter value of one extra path.
 *
 * \param[in] z The extra path for which to query the current recenter value.
 * 				Range: \ref IfxCif_ExtraPath
 *
 * \retval uint8 The current recenter value.
 * 				 Range: 000B Recenter feature switched off.
 * 				 		For all other values recentering is active (cur_h/v_offs-H/V_OFFS)/2 power(recenter).
 */
IFX_EXTERN uint8 IfxCif_getEpRecenterValue(IfxCif_ExtraPath z);

/**
 * \brief Function to query the current ring buffer size of one extra path
 *
 * \param[in] z The extra path for which to query the ring buffer size. 
 *              Range: \ref IfxCif_ExtraPath
 *
 * \retval uint32 The current ring buffer size of the specified extra path.
 * 				  Range: 0 to 0xFFFFFC
 */
IFX_EXTERN uint32 IfxCif_getEpSize(IfxCif_ExtraPath z);

/**
 * \brief Queries and returns the write format of a specified extra path.
 *
 * \param[in] z The extra path for which to query the write format.
 * 				Range: \ref IfxCif_ExtraPath
 *
 * \retval IfxCif_EpWriteFormat The current write format of the extra path.
 *                              Range: \ref IfxCif_EpWriteFormat
 */
IFX_EXTERN IfxCif_EpWriteFormat IfxCif_getEpWriteFormat(IfxCif_ExtraPath z);

/**
 * \brief Gets the masked state of an nterrupt.
 *
 * \param[in] z 			  The extra path for which to query the interrupt state.
 *              			  Range: \ref IfxCif_ExtraPath
 * \param[in] interruptSource The source of the interrupt to check.
 * 						      Range: \ref IfxCif_EpInterrupts
 *
 * \retval IfxCif_InterruptTriggeredState The current state of masked triggered interrupt.
 * 										  Range: \ref IfxCif_InterruptTriggeredState_Triggered    if the interrupt request bit is set and the interrupt is enabled.
 * 		   								  		 \ref IfxCif_InterruptTriggeredState_NotTriggered if the interrupt request bit is not set or the interrupt is disabled.
 */
IFX_EXTERN IfxCif_InterruptTriggeredState IfxCif_getMaskedEpInterruptTriggeredState(IfxCif_ExtraPath z, IfxCif_EpInterrupts interruptSource);

/**
 * \brief Qery the raw state of an interrupt.
 *
 * \param[in] z 			  The extra path for which to query the interrupt state.
 *                            Range: \ref IfxCif_ExtraPath
 * \param[in] interruptSource The source of the interrupt to check.
 * 						      Range: \ref IfxCif_EpInterrupts
 *
 * \retval IfxCif_InterruptTriggeredState The current Interrupt Trigger State.
 * 										  Range: \ref IfxCif_InterruptTriggeredState_Triggered    if the interrupt request bit is set.
 * 										  		 \ref IfxCif_InterruptTriggeredState_NotTriggered if the interrupt request bit is not set.
 */
IFX_EXTERN IfxCif_InterruptTriggeredState IfxCif_getRawEpInterruptTriggeredState(IfxCif_ExtraPath z, IfxCif_EpInterrupts interruptSource);

/**
 * \brief Sets the initial base address of the ring buffer for a specified extra path.
 *
 * \param[in] z 		  The extra path for which to set the initial base address.
 * 						  Range: \ref IfxCif_ExtraPath
 * \param[in] baseAddress The initial base address to be set for the ring buffer.
 * 					      Range: \ref Ifx_AddressValue
 *
 * \retval None
 */
IFX_EXTERN void IfxCif_setEpBaseInitAddress(IfxCif_ExtraPath z, Ifx_AddressValue baseAddress);

/**
 * \brief Sets the image cropping camera displacement for a specified tier of an extra path.
 *
 * \param[in] z    		   The extra path for which to set the image cropping camera displacement.
 *             	   		   Range: \ref IfxCif_ExtraPath
 * \param[in] tier 		   The tier for which to set the image cropping camera displacement.
 *                 		   Range: \ref IfxCif_ImageTiers
 * \param[in] displacement The image cropping camera displacement value to be set.
 *						   Range: 0 to 0xFFF
 * \retval None
 */
IFX_EXTERN void IfxCif_setEpCroppingCameraDisplacement(IfxCif_ExtraPath z, IfxCif_ImageTiers tier, uint16 displacement);

/**
 * \brief Enables or disables image cropping for a specified extra path.
 *
 * \param[in] z 		  The extra path for which to enable or disable image cropping.
 * 						  Range: \ref IfxCif_ExtraPath
 * \param[in] enableState The state to set for image cropping.
 *                        Range: TRUE  to enable image cropping.
 *                       		 FALSE to disable image cropping.
 *
 * \retval None
 */
IFX_EXTERN void IfxCif_setEpCroppingEnableState(IfxCif_ExtraPath z, uint32 enableState);

/**
 * \brief Sets the Image Cropping Output Picture Size.
 *
 * \param[in] z    		   The extra path for which to set the maximum displacement.
 *             	   		   Range: \ref IfxCif_ExtraPath
 * \param[in] tier         The tier for which to set the maximum displacement.
 *                         Range: \ref IfxCif_ImageTiers
 * \param[in] displacement The maximum displacement value to be set.
 *                         Range: 0 to 0xFFF
 *
 * \retval None
 */
IFX_EXTERN void IfxCif_setEpCroppingMaximumDisplacement(IfxCif_ExtraPath z, IfxCif_ImageTiers tier, uint16 displacement);

/**
 * \brief Configures the image cropping offset for the output window of a specified tier within an extra path.
 *
 * \param[in] z      The extra path for which to configure the cropping offset.
 *                   Range: \ref IfxCif_ExtraPath
 * \param[in] tier   The tier (horizontal or vertical) for which to configure the image cropping offset of the output window.
 * 				     Range: 0 to 0xFFF
 * \param[in] offset The offset value to apply to the output window.
 *                   Range: 0 to 0xFFF
 *
 * \retval None
 */
IFX_EXTERN void IfxCif_setEpCroppingOffsetOutputWindow(IfxCif_ExtraPath z, IfxCif_ImageTiers tier, uint16 offset);

/**
 * \brief Sets the image cropping offsets of the output window for a specified extra path.
 *
 * \param[in] z 	  The extra path for which to set the cropping offsets.
 * 				      Range: \ref IfxCif_ExtraPath
 * \param[in] hOffset Image Cropping Horizontal Offset of Output Window to be set.
 * 					  Range: 0 to 0xFFF
 * \param[in] vOffset Image Cropping Vertical Offset Of Output Window to be set.
 * 					  Range: 0 to 0xFFF
 *
 * \retval None
 */
IFX_EXTERN void IfxCif_setEpCroppingOffsetsOutputWindow(IfxCif_ExtraPath z, uint16 hOffset, uint16 vOffset);

/**
 * \brief Set the image cropping picture size of one tier of one extra path.
 *
 * \param[in] z    The extra path identifier for which to set the image cropping picture size.
 * 				   Range: \ref IfxCif_ExtraPath
 * \param[in] tier The Tier for which to set the image cropping picture size.
 * 				   Range: \ref IfxCif_ImageTiers
 * \param[in] size Image cropping picture size to set.
 * 				   Range: 0 to 0xFFF
 *
 * \retval None
 */
IFX_EXTERN void IfxCif_setEpCroppingPictureSize(IfxCif_ExtraPath z, IfxCif_ImageTiers tier, uint16 size);

/**
 * \brief Sets the Extra Path i Image Cropping Output Horizontal and Vertical Picture Size.
 *
 * \param[in] z 	The extra path for which to set the cropping picture sizes.
 * 					Range: \ref IfxCif_ExtraPath
 * \param[in] hSize The horizontal picture size of the cropping image to be set.
 *                 	Range: 0 to 0xFFF
 * \param[in] vSize The vertical picture size of the cropping image to be set.
 *                 	Range: 0 to 0xFFF
 *
 * \retval None
 */
IFX_EXTERN void IfxCif_setEpCroppingPictureSizes(IfxCif_ExtraPath z, uint16 hSize, uint16 vSize);

/**
 * \brief Function to enable or disable one feature of one extra path.
 *
 * \param[in] z 	      Extra path identifier.
 * 					  	  Range: \ref IfxCif_ExtraPath
 * \param[in] feature 	  Feature to enable or disable.
 * 						  Range: \ref IfxCif_EpFeatures
 * \param[in] enableState State to set the feature to.
 * 						  Range: \ref IfxCif_State_Enabled 	to enable the feature.
 * 						  		 \ref IfxCif_State_Disabled to disable the feature
 *
 * \retval None
 */
IFX_EXTERN void IfxCif_setEpFeatureEnableState(IfxCif_ExtraPath z, IfxCif_EpFeatures feature, IfxCif_State enableState);

/**
 * \brief Sets the initial size of the ring buffer for a specified extra path.
 *
 * \param[in] z    The extra path for which to set the initial size of the ring buffer.
 * 				   Range: \ref IfxCif_ExtraPath
 * \param[in] size The initial size of the ring buffer to set.
 * 				   Range: 0 to 0xFFFFFC
 *
 * \retval None
 */
IFX_EXTERN void IfxCif_setEpInitSize(IfxCif_ExtraPath z, uint32 size);

/**
 * \brief Sets the initial filling level interrupt offset for an extra path.
 *
 * \param[in] z 			  Extra path identifier for which to set the initial filling level interrupt offset.
 * 							  Range: 0 to 0xFFFFFFFF
 * \param[in] interruptOffset Initial filling level interrupt offset value to be set.
 * 							  Range: 0 to 0xFFFFFC
 *
 * \retval None
 */
IFX_EXTERN void IfxCif_setEpInitialFillLevelInterruptOffset(uint32 z, uint32 interruptOffset);

/**
 * \brief Sets the initial offset counter for a specified extra path.
 *
 * \param[in] z 			The extra path for which to set the initial offset counter.
 * 							Range: \ref IfxCif_ExtraPath
 * \param[in] offsetCounter The initial offset counter value to set.
 *                          Range: 0 to 0xFFFFFC
 *
 * \retval None
 */
IFX_EXTERN void IfxCif_setEpInitialOffsetCounter(IfxCif_ExtraPath z, uint32 offsetCounter);

/**
 * \brief Enables or disables an interrupt for a specific extra path.
 *
 * \param[in] z 			       The extra path for which the interrupt state is to be set.
 *              			       Range: \ref IfxCif_ExtraPath
 * \param[in] interruptSource      The source of the interrupt to be enabled or disabled.
 *                                 Range: \ref IfxCif_EpInterrupts
 * \param[in] interruptEnableState The state to which the interrupt is to be set.
 *                                 Range: \ref IfxCif_State_Enabled  to enable the interrupt.
 *                                 		  \ref IfxCif_State_Disabled to disable the interrupt.
 *
 * \retval None
 */
IFX_EXTERN void IfxCif_setEpInterruptEnableState(IfxCif_ExtraPath z, IfxCif_EpInterrupts interruptSource, IfxCif_State interruptEnableState);

/**
 * \brief Sets an interrupt request bit for a specified extra path (does not necessarily trigger an interrupt).
 *
 * \param[in] z 			  The extra path for which to set the interrupt request bit(does not necessarily trigger an interrupt).
 *              			  Range: \ref IfxCif_ExtraPath
 * \param[in] interruptSource The interrupt source to set the interrupt request bit for.
 *                            Range: \ref IfxCif_EpInterrupts.
 *
 * \retval void
 */
IFX_EXTERN void IfxCif_setEpInterruptRequestBit(IfxCif_ExtraPath z, IfxCif_EpInterrupts interruptSource);

/**
 * \brief Sets the initial offset counter start value for a specific extra path.
 *
 * \param[in] z   			The extra path identifier for which to set the initial offset counter start value.
 * 							Range: 0 to 0xFFFFFFFF
 * \param[in] offsetCounter The initial offset counter start value to be set.
 * 							Range: 0 to 0xFFFFFC
 *
 * \retval None
 */
IFX_EXTERN void IfxCif_setEpOffsetCounterStart(uint32 z, uint32 offsetCounter);

/**
 * \brief Sets the recenter value for a specified extra path (0 to switch the recenter feature off, for all other values recentering is active (cur_h/v_offs-H/V_OFFS)/2power(recenter)).
 *
 * \param[in] z     The Extra path for which to set the recenter value.
 * 				    Range: \ref IfxCif_ExtraPath
 * \param[in] value Recenter value to be set.
 * 				    Range: 0x0          Recenter feature switched off.
 * 				    	   0x1 to 0x7   For all other values recentering is active (cur_h/v_offs-H/V_OFFS)/2 power(recenter) recenter feature switched off.
 *
 * \retval None
 */
IFX_EXTERN void IfxCif_setEpRecenterValue(IfxCif_ExtraPath z, uint8 value);

/**
 * \brief Sets the write format for a specified extra path.
 *
 * \param[in] z 		  The extra path to configure.
 * 					      Range: \ref IfxCif_ExtraPath
 * \param[in] writeFormat The write format to set for the extra path.
 *						  Range: \ref IfxCif_EpWriteFormat
 *
 * \retval void
 */
IFX_EXTERN void IfxCif_setEpWriteFormat(IfxCif_ExtraPath z, IfxCif_EpWriteFormat writeFormat);

/** \} */

/** \addtogroup IfxLld_Cif_Std_dpFunctions
 * \{ */

/******************************************************************************/
/*-------------------------Inline Function Prototypes-------------------------*/
/******************************************************************************/

/**
 * \brief Queries and returns the current state of the debug path enabled state.
 *
 * \retval IfxCif_State The currently selected debug path enabled state.
 * 						Range: \ref	IfxCif_State_Enabled  if the debug path is enabled.
 * 		   					   \ref IfxCif_State_Disabled if the debug path is disabled.
 */
IFX_INLINE IfxCif_State IfxCif_getDpEnableState(void);

/**
 * \brief Retrieves the currently selected debug path source path.
 *
 * \retval IfxCif_DpSourcePath The currently selected debug path source path.
 * 							   Range: \ref IfxCif_DpSourcePath
 */
IFX_INLINE IfxCif_DpSourcePath IfxCif_getDpSourcePath(void);

/**
 * \brief Enables or disables the debug path based on the provided state.
 *
 * \param[in] enableState State to be specified.
 * 						  Range: \ref IfxCif_State_Enabled  to enable the debug path.
 * 						  		 \ref IfxCif_State_Disabled to disable the debug path
 * \retval None
 */
IFX_INLINE void IfxCif_setDpEnableState(IfxCif_State enableState);

/**
 * \brief Function to select one debug path source path.
 *
 * \param[in] sourcePath The source path to be selected.
 * 						 Range: \ref IfxCif_DpSourcePath
 *
 * \retval None
 */
IFX_INLINE void IfxCif_setDpSourcePath(IfxCif_DpSourcePath sourcePath);

/******************************************************************************/
/*-------------------------Global Function Prototypes-------------------------*/
/******************************************************************************/

/**
 * \brief Function to reset one debug path counter
 *
 * \param[in] counter Debug path counter to reset.
 * 					  Range: \ref IfxCif_DpCounters
 *
 * \retval None
 */
IFX_EXTERN void IfxCif_dpResetCounter(IfxCif_DpCounters counter);

/**
 * \brief Function to query the transmission enabled state of one debug path control source
 *
 * \param[in] source Source for which to query the transmission enabled state.
 * 				     Range: \ref IfxCif_DpControlSources
 *
 * \retval IfxCif_State The current transmission state status.
 * 						Range: \ref IfxCif_State_Enabled  if transmission is enabled for the specified source.
 * 							   \ref IfxCif_State_Disabled if transmission is disabled for the specified source.
 */
IFX_EXTERN IfxCif_State IfxCif_getDpControlEnableState(IfxCif_DpControlSources source);

/**
 * \brief Function to query the current counter value of a specified debug path counter.
 *
 * \param[in] counter Counter for which to query the value.
 * 					  Range: \ref IfxCif_DpCounters
 *
 * \retval uint32 The current counter value of the specified debug path counter.
 * 				  Range: 0 to 0xFFFFFFFF
 */
IFX_EXTERN uint32 IfxCif_getDpCounter(IfxCif_DpCounters counter);

/**
 * \brief Retrieves the value of a user-defined debug symbol based on the given index.
 *
 * \param[in] x The index of the user-defined debug symbol to query.
 * 				Range: 0 to 0xFF
 *
 * \retval uint16 The value of the user defined debug symbol.
 * 				  Range: 0 to 0x7FFF
 */
IFX_EXTERN uint16 IfxCif_getDpUserDefinedSymbol(uint8 x);

/**
 * \brief Enables or disables the transmission of a specified debug path control source.
 *
 * \param[in] source      Source for which to enable or disable transmission.
 *               	      Range: \ref IfxCif_DpControlSources
 * \param[in] enableState The state to set for the debug path control source transmission.
 *                        Range: \ref IfxCif_State_Enabled  to enable transmission.
 *                        		 \ref IfxCif_State_Disabled to disable transmission
 *
 * \retval None
 */
IFX_EXTERN void IfxCif_setDpControlEnableState(IfxCif_DpControlSources source, IfxCif_State enableState);

/**
 * \brief Sets a debug path counter to a specified counter value.
 *
 * \param[in] counter      The debug path counter to be set.
 * 					       Range: \ref IfxCif_DpCounters
 * \param[in] counterValue The value to be assigned to the specified counter.
 *                         Range: 0 to 0xFFFFFFFF
 *
 * \retval None
 */
IFX_EXTERN void IfxCif_setDpCounter(IfxCif_DpCounters counter, uint32 counterValue);

/**
 * \brief Sets a user-defined debug symbol for the CIF module with a specified value.
 *
 * \param[in] x     User defined symbol to set.
 * 					Range: 0 to 0xFF
 * \param[in] value Value to assign to the user-defined symbol.
 * 					Range: 0 to 0x7FFF
 *
 * \retval None
 */
IFX_EXTERN void IfxCif_setDpUserDefinedSymbol(uint8 x, uint16 value);
/** \} */

/******************************************************************************/
/*---------------------Inline Function Implementations------------------------*/
/******************************************************************************/

IFX_INLINE void IfxCif_clearKernelResetState(void)
{
    MODULE_CIF.BBB.KRSTCLR.B.CLR = 1;
}


IFX_INLINE void IfxCif_generateIspFrameSynchronousConfigUpdateSignal(void)
{
    MODULE_CIF.ISP.CTRL.B.ISP_GEN_CFG_UPD = 1;
}


IFX_INLINE void IfxCif_generateIspImmediateConfigUpdateSignal(void)
{
    MODULE_CIF.ISP.CTRL.B.ISP_CFG_UPD = 1;
}


IFX_INLINE void IfxCif_generateMiImmediateConfigUpdateSignal(void)
{
    MODULE_CIF.MI.INIT.B.MI_CFG_UPD = 1;
}


IFX_INLINE IfxCif_State IfxCif_getBaseAddressInitializationEnableState(void)
{
    return (IfxCif_State)MODULE_CIF.MI.CTRL.B.INIT_BASE_EN;
}


IFX_INLINE uint16 IfxCif_getCifModuleId(void)
{
    return MODULE_CIF.BBB.MODID.B.MOD_NUMBER;
}


IFX_INLINE IfxCif_PortInputSelection IfxCif_getCifModulePortInputSelection(void)
{
    return IfxCif_PortInputSelection_PinMapping0;
}


IFX_INLINE uint8 IfxCif_getCifModuleRevision(void)
{
    return MODULE_CIF.BBB.MODID.B.MOD_REV;
}


IFX_INLINE uint8 IfxCif_getCifModuleType(void)
{
    return MODULE_CIF.BBB.MODID.B.MOD_TYPE;
}


IFX_INLINE IfxCif_State IfxCif_getClockControlLogicState(void)
{
    /* bit is inverted */
    return (1 != MODULE_CIF.CCL.B.CIF_CCLDISS) ? IfxCif_State_Enabled : IfxCif_State_Disabled;
}


IFX_INLINE uint16 IfxCif_getCurrentIspFrameCount(void)
{
    return MODULE_CIF.ISP.FRAME_COUNT.B.FRAME_COUNTER;
}


IFX_INLINE IfxCif_IspInformFieldInformation IfxCif_getCurrentIspInformFieldInformation(void)
{
    return (IfxCif_IspInformFieldInformation)MODULE_CIF.ISP.FLAGS_SHD.B.INFORM_FIELD;
}


IFX_INLINE IfxCif_State IfxCif_getCurrentIspInputFormatterState(void)
{
    return (IfxCif_State)MODULE_CIF.ISP.FLAGS_SHD.B.ISP_INFORM_ENABLE_SHD;
}


IFX_INLINE IfxCif_DataPathSelectorForMainPath IfxCif_getDataPathSelectorForMainPath(void)
{
    return (IfxCif_DataPathSelectorForMainPath)MODULE_CIF.DPCL.B.CIF_MP_MUX;
}


IFX_INLINE IfxCif_State IfxCif_getDpEnableState(void)
{
    return (IfxCif_State)MODULE_CIF.DP.CTRL.B.DP_EN;
}


IFX_INLINE IfxCif_DpSourcePath IfxCif_getDpSourcePath(void)
{
    return (IfxCif_DpSourcePath)MODULE_CIF.DP.CTRL.B.DP_SEL;
}


IFX_INLINE IfxCif_InputInterface IfxCif_getInputInterface(void)
{
    return (IfxCif_InputInterface)MODULE_CIF.DPCL.B.IF_SELECT;
}


IFX_INLINE IfxCif_IspCcirSequence IfxCif_getIspCcirSequence(void)
{
    return (IfxCif_IspCcirSequence)MODULE_CIF.ISP.ACQ_PROP.B.CCIR_SEQ;
}


IFX_INLINE IfxCif_IspColorSpaceMatrixCrominanceClippingRange IfxCif_getIspColorSpaceMatrixCrominanceClippingRange(void)
{
    return (IfxCif_IspColorSpaceMatrixCrominanceClippingRange)MODULE_CIF.ISP.CTRL.B.ISP_CSM_C_RANGE;
}


IFX_INLINE IfxCif_IspColorSpaceMatrixLuminanceClippingRange IfxCif_getIspColorSpaceMatrixLuminanceClippingRange(void)
{
    return (IfxCif_IspColorSpaceMatrixLuminanceClippingRange)MODULE_CIF.ISP.CTRL.B.ISP_CSM_Y_RANGE;
}


IFX_INLINE IfxCif_State IfxCif_getIspFieldInvertState(void)
{
    return (IfxCif_State)MODULE_CIF.ISP.ACQ_PROP.B.FIELD_INVERT;
}


IFX_INLINE IfxCif_IspFieldSelection IfxCif_getIspFieldSelection(void)
{
    return (IfxCif_IspFieldSelection)MODULE_CIF.ISP.ACQ_PROP.B.FIELD_SELECTION;
}


IFX_INLINE IfxCif_IspSyncPolarity IfxCif_getIspHSyncPolarity(void)
{
    return (IfxCif_IspSyncPolarity)MODULE_CIF.ISP.ACQ_PROP.B.HSYNC_POL;
}


IFX_INLINE IfxCif_State IfxCif_getIspInputFormatterState(void)
{
    return (IfxCif_State)MODULE_CIF.ISP.CTRL.B.ISP_INFORM_ENABLE;
}


IFX_INLINE IfxCif_IspInputInterface IfxCif_getIspInputInterface(void)
{
    return (IfxCif_IspInputInterface)MODULE_CIF.ISP.ACQ_PROP.B.INPUT_SELECTION;
}


IFX_INLINE uint16 IfxCif_getIspInputPortSDataState(void)
{
    return MODULE_CIF.ISP.FLAGS_SHD.B.S_DATA;
}


IFX_INLINE IfxCif_State IfxCif_getIspInputPortSHSyncState(void)
{
    return (IfxCif_State)MODULE_CIF.ISP.FLAGS_SHD.B.S_HSYNC;
}


IFX_INLINE IfxCif_State IfxCif_getIspInputPortSVSyncState(void)
{
    return (IfxCif_State)MODULE_CIF.ISP.FLAGS_SHD.B.S_VSYNC;
}


IFX_INLINE IfxCif_State IfxCif_getIspMode(void)
{
    return (IfxCif_State)MODULE_CIF.ISP.CTRL.B.ISP_MODE;
}


IFX_INLINE IfxCif_State IfxCif_getIspOutputState(void)
{
    return (IfxCif_State)MODULE_CIF.ISP.CTRL.B.ISP_ENABLE;
}


IFX_INLINE IfxCif_IspSamplingEdge IfxCif_getIspSamplingEdge(void)
{
    return (IfxCif_IspSamplingEdge)MODULE_CIF.ISP.ACQ_PROP.B.SAMPLE_EDGE;
}


IFX_INLINE IfxCif_State IfxCif_getIspState(void)
{
    return (IfxCif_State)MODULE_CIF.ISP.FLAGS_SHD.B.ISP_ENABLE_SHD;
}


IFX_INLINE IfxCif_IspSyncPolarity IfxCif_getIspVSyncPolarity(void)
{
    return (IfxCif_IspSyncPolarity)MODULE_CIF.ISP.ACQ_PROP.B.VSYNC_POL;
}


IFX_INLINE IfxCif_State IfxCif_getIspisEnableState(void)
{
    return (IfxCif_State)MODULE_CIF.ISPIS.CTRL.B.IS_EN;
}


IFX_INLINE uint8 IfxCif_getIspisRecenterValue(void)
{
    return MODULE_CIF.ISPIS.RECENTER.B.RECENTER;
}


IFX_INLINE IfxCif_JpeHeaderGenerationMode IfxCif_getJpeHeaderGenerationMode(void)
{
    return (IfxCif_JpeHeaderGenerationMode)MODULE_CIF.JPE.TABLE_FLUSH.B.TABLE_FLUSH;
}


IFX_INLINE IfxCif_JpeHeaderMode IfxCif_getJpeHeaderMode(void)
{
    return (IfxCif_JpeHeaderMode)MODULE_CIF.JPE.HEADER_MODE.B.HEADER_MODE;
}


IFX_INLINE IfxCif_State IfxCif_getJpeMode(void)
{
    return (IfxCif_State)MODULE_CIF.JPE.ENCODE_MODE.B.ENCODE_MODE;
}


IFX_INLINE uint16 IfxCif_getJpeRestartInterval(void)
{
    return MODULE_CIF.JPE.RESTART_INTERVAL.B.RESTART_INTERVAL;
}


IFX_INLINE IfxCif_JpeState IfxCif_getJpeState(void)
{
    return (IfxCif_JpeState)MODULE_CIF.JPE.ENCODER_BUSY.B.CODEC_BUSY;
}


IFX_INLINE IfxCif_JpeTableId IfxCif_getJpeTableId(void)
{
    return (IfxCif_JpeTableId)MODULE_CIF.JPE.TABLE_ID.B.TABLE_ID;
}


IFX_INLINE IfxCif_JpegJfifStreamEncoderContinuousMode IfxCif_getJpegJfifStreamEncoderContinuousMode(void)
{
    return (IfxCif_JpegJfifStreamEncoderContinuousMode)MODULE_CIF.JPE.ENCODE.B.CONT_MODE;
}


IFX_INLINE IfxCif_JpegPictureEncodingFormat IfxCif_getJpegPictureEncodingFormat(void)
{
    return (IfxCif_JpegPictureEncodingFormat)MODULE_CIF.JPE.PIC_FORMAT.B.ENC_PIC_FORMAT;
}


IFX_INLINE IfxCif_State IfxCif_getKernelResetStatus(void)
{
    return (IfxCif_State)MODULE_CIF.BBB.KRST0.B.RSTSTAT;
}


IFX_INLINE uint32 IfxCif_getMiByteCount(void)
{
    return MODULE_CIF.MI.BYTE_CNT.B.BYTE_CNT;
}


IFX_INLINE IfxCif_State IfxCif_getMiByteSwapEnableState(void)
{
    return (IfxCif_State)MODULE_CIF.MI.CTRL.B.BYTE_SWAP;
}


IFX_INLINE IfxCif_MiBurstLength IfxCif_getMiChrominanceBurstLength(void)
{
    return (IfxCif_MiBurstLength)MODULE_CIF.MI.CTRL.B.BURST_LEN_CHROM;
}


IFX_INLINE IfxCif_MiBurstLength IfxCif_getMiLuminanceBurstLength(void)
{
    return (IfxCif_MiBurstLength)MODULE_CIF.MI.CTRL.B.BURST_LEN_LUM;
}


IFX_INLINE IfxCif_MiMainPictureWriteFormat IfxCif_getMiMainPictureWriteFormat(void)
{
    return (IfxCif_MiMainPictureWriteFormat)MODULE_CIF.MI.CTRL.B.MP_WRITE_FORMAT;
}


IFX_INLINE uint32 IfxCif_getMiMainPictureYInitialFillLevelInterruptOffset(void)
{
    /* read value from unsigned component of the register structure because lower bits are tied to 0
     * as interrupt offset needs to be a word aligned value */
    return MODULE_CIF.MI.MP_Y_IRQ_OFFS_INIT.U;
}


IFX_INLINE uint32 IfxCif_getMiMainPictureYInterruptOffset(void)
{
    return MODULE_CIF.MI.MP_Y_IRQ_OFFS_SHD.B.MP_Y_IRQ_OFFS;
}


IFX_INLINE IfxCif_State IfxCif_getMiOffsetCounterInitializationEnableState(void)
{
    return (IfxCif_State)MODULE_CIF.MI.CTRL.B.INIT_OFFSET_EN;
}


IFX_INLINE uint16 IfxCif_getModuleNumber(void)
{
    return MODULE_CIF.ID.B.MODNUM;
}


IFX_INLINE uint8 IfxCif_getModuleRevisionNumber(void)
{
    return MODULE_CIF.ID.B.MODREV;
}


IFX_INLINE IfxCif_State IfxCif_getModuleState(void)
{
    /* bit is inverted */
    return (IfxCif_State)(1 != MODULE_CIF.BBB.CLC.B.DISS) ? IfxCif_State_Enabled : IfxCif_State_Disabled;
}


IFX_INLINE uint8 IfxCif_getModuleType(void)
{
    return MODULE_CIF.ID.B.MODTYPE;
}


IFX_INLINE uint16 IfxCif_getNumberOfAcquisitionFrames(void)
{
    return MODULE_CIF.ISP.ACQ_NR_FRAMES.B.ACQ_NR_FRAMES;
}


IFX_INLINE uint16 IfxCif_getSecurityWatchdogCounterPredivider(void)
{
    return MODULE_CIF.WD.CTRL.B.WD_PREDIV;
}


IFX_INLINE IfxCif_State IfxCif_getSecurityWatchdogEnableState(void)
{
    return (IfxCif_State)MODULE_CIF.WD.CTRL.B.WD_EN;
}


IFX_INLINE IfxCif_YCSplitterChannelMode IfxCif_getYCSplitterChannelMode(void)
{
    return (IfxCif_YCSplitterChannelMode)MODULE_CIF.DPCL.B.CIF_CHAN_MODE;
}


IFX_INLINE void IfxCif_initJpegEncoder(void)
{
    MODULE_CIF.JPE.INIT.B.JP_INIT = 1;
}


IFX_INLINE void IfxCif_jpeGenerateHeader(void)
{
    MODULE_CIF.JPE.GEN_HEADER.B.GEN_HEADER = 1;
}


IFX_INLINE void IfxCif_miSkipPicture(void)
{
    MODULE_CIF.MI.INIT.B.MI_SKIP = 1;
}


IFX_INLINE void IfxCif_setClockControlLogicState(IfxCif_State clockControlLogicState)
{
    /* bit is inverted */
    MODULE_CIF.CCL.B.CIF_CCLFDIS = (clockControlLogicState == IfxCif_State_Disabled) ? 1 : 0;
}


IFX_INLINE void IfxCif_setDataPathSelectorForMainPath(IfxCif_DataPathSelectorForMainPath pathSelector)
{
    MODULE_CIF.DPCL.B.CIF_MP_MUX = pathSelector;
}


IFX_INLINE void IfxCif_setDpEnableState(IfxCif_State enableState)
{
    MODULE_CIF.DP.CTRL.B.DP_EN = enableState;
}


IFX_INLINE void IfxCif_setDpSourcePath(IfxCif_DpSourcePath sourcePath)
{
    MODULE_CIF.DP.CTRL.B.DP_SEL = sourcePath;
}


IFX_INLINE void IfxCif_setInputInterface(IfxCif_InputInterface interface)
{
    IFX_UNUSED_PARAMETER(interface);
    MODULE_CIF.DPCL.B.IF_SELECT = IfxCif_InputInterface_ParallelInterface;
}


IFX_INLINE void IfxCif_setIspAcquisitionOffsets(uint16 hOffset, uint16 vOffset)
{
    MODULE_CIF.ISP.ACQ_H_OFFS.B.ACQ_H_OFFS = hOffset;
    MODULE_CIF.ISP.ACQ_V_OFFS.B.ACQ_V_OFFS = vOffset;
}


IFX_INLINE void IfxCif_setIspAcquisitionSizes(uint16 hSize, uint16 vSize)
{
    MODULE_CIF.ISP.ACQ_H_SIZE.U = hSize;
    MODULE_CIF.ISP.ACQ_V_SIZE.U = vSize;
}


IFX_INLINE void IfxCif_setIspCcirSequence(IfxCif_IspCcirSequence sequence)
{
    MODULE_CIF.ISP.ACQ_PROP.B.CCIR_SEQ = sequence;
}


IFX_INLINE void IfxCif_setIspColorSpaceMatrixCrominanceClippingRange(IfxCif_IspColorSpaceMatrixCrominanceClippingRange clippingRange)
{
    MODULE_CIF.ISP.CTRL.B.ISP_CSM_C_RANGE = clippingRange;
}


IFX_INLINE void IfxCif_setIspColorSpaceMatrixLuminanceClippingRange(IfxCif_IspColorSpaceMatrixLuminanceClippingRange clippingRange)
{
    MODULE_CIF.ISP.CTRL.B.ISP_CSM_Y_RANGE = clippingRange;
}


IFX_INLINE void IfxCif_setIspFieldInvertState(IfxCif_State fieldInvertState)
{
    MODULE_CIF.ISP.ACQ_PROP.B.FIELD_INVERT = fieldInvertState;
}


IFX_INLINE void IfxCif_setIspFieldSelection(IfxCif_IspFieldSelection selection)
{
    MODULE_CIF.ISP.ACQ_PROP.B.FIELD_SELECTION = selection;
}


IFX_INLINE void IfxCif_setIspHSyncPolarity(IfxCif_IspSyncPolarity polarity)
{
    MODULE_CIF.ISP.ACQ_PROP.B.HSYNC_POL = polarity;
}


IFX_INLINE void IfxCif_setIspInputFormatterState(IfxCif_State inputFormatterState)
{
    MODULE_CIF.ISP.CTRL.B.ISP_INFORM_ENABLE = inputFormatterState;
}


IFX_INLINE void IfxCif_setIspInputInterface(IfxCif_IspInputInterface input)
{
    MODULE_CIF.ISP.ACQ_PROP.B.INPUT_SELECTION = input;
}


IFX_INLINE void IfxCif_setIspMode(IfxCif_IspMode mode)
{
    MODULE_CIF.ISP.CTRL.B.ISP_MODE = mode;
}


IFX_INLINE void IfxCif_setIspOutputState(IfxCif_State ispOutputState)
{
    MODULE_CIF.ISP.CTRL.B.ISP_ENABLE = ispOutputState;
}


IFX_INLINE void IfxCif_setIspOutputWindowOffsets(uint16 hOffset, uint16 vOffset)
{
    MODULE_CIF.ISP.OUT_H_OFFS.B.ISP_OUT_H_OFFS = hOffset;
    MODULE_CIF.ISP.OUT_V_OFFS.B.ISP_OUT_V_OFFS = vOffset;
}


IFX_INLINE void IfxCif_setIspPictureSizes(uint16 hSize, uint16 vSize)
{
    MODULE_CIF.ISP.OUT_H_SIZE.B.ISP_OUT_H_SIZE = hSize;
    MODULE_CIF.ISP.OUT_V_SIZE.B.ISP_OUT_V_SIZE = vSize;
}


IFX_INLINE void IfxCif_setIspSamplingEdge(IfxCif_IspSamplingEdge edge)
{
    MODULE_CIF.ISP.ACQ_PROP.B.SAMPLE_EDGE = edge;
}


IFX_INLINE void IfxCif_setIspVSyncPolarity(IfxCif_IspSyncPolarity polarity)
{
    MODULE_CIF.ISP.ACQ_PROP.B.VSYNC_POL = polarity;
}


IFX_INLINE void IfxCif_setIspisEnableState(IfxCif_State enableState)
{
    MODULE_CIF.ISPIS.CTRL.B.IS_EN = enableState;
}


IFX_INLINE void IfxCif_setIspisOutputWindowOffsets(IfxCif_ImageTiers hOffset, uint16 vOffset)
{
    MODULE_CIF.ISPIS.H_OFFS.U = hOffset;
    MODULE_CIF.ISPIS.V_OFFS.U = vOffset;
}


IFX_INLINE void IfxCif_setIspisPictureSizes(uint16 hSize, uint16 vSize)
{
    MODULE_CIF.ISPIS.H_SIZE.U = hSize;
    MODULE_CIF.ISPIS.V_SIZE.U = vSize;
}


IFX_INLINE void IfxCif_setIspisRecenterValue(uint8 value)
{
    MODULE_CIF.ISPIS.RECENTER.B.RECENTER = value;
}


IFX_INLINE void IfxCif_setJpeHeaderGenerationMode(IfxCif_JpeHeaderGenerationMode headerGenerationMode)
{
    MODULE_CIF.JPE.TABLE_FLUSH.B.TABLE_FLUSH = headerGenerationMode;
}


IFX_INLINE void IfxCif_setJpeHeaderMode(IfxCif_JpeHeaderMode headerMode)
{
    MODULE_CIF.JPE.HEADER_MODE.B.HEADER_MODE = headerMode;
}


IFX_INLINE void IfxCif_setJpeRestartInterval(uint16 interval)
{
    MODULE_CIF.JPE.RESTART_INTERVAL.B.RESTART_INTERVAL = interval;
}


IFX_INLINE void IfxCif_setJpeTableDataLsb(uint8 data)
{
    MODULE_CIF.JPE.TABLE_DATA.B.TABLE_WDATA_L = data;
}


IFX_INLINE void IfxCif_setJpeTableDataMsb(uint8 data)
{
    MODULE_CIF.JPE.TABLE_DATA.B.TABLE_WDATA_H = data;
}


IFX_INLINE void IfxCif_setJpeTableId(IfxCif_JpeTableId tableId)
{
    MODULE_CIF.JPE.TABLE_ID.B.TABLE_ID = tableId;
}


IFX_INLINE void IfxCif_setJpegCodecImageSizes(uint16 hSize, uint16 vSize)
{
    MODULE_CIF.JPE.ENC_HSIZE.B.ENC_HSIZE = hSize;
    MODULE_CIF.JPE.ENC_VSIZE.B.ENC_VSIZE = vSize;
}


IFX_INLINE void IfxCif_setJpegJfifStreamEncoderContinuousMode(IfxCif_JpegJfifStreamEncoderContinuousMode mode)
{
    MODULE_CIF.JPE.ENCODE.B.CONT_MODE = mode;
}


IFX_INLINE void IfxCif_setJpegPictureEncodingFormat(IfxCif_JpegPictureEncodingFormat format)
{
    MODULE_CIF.JPE.PIC_FORMAT.B.ENC_PIC_FORMAT = format;
}


IFX_INLINE void IfxCif_setKernelResetRequestState(IfxCif_State state)
{
    MODULE_CIF.BBB.KRST0.B.RST = state;
    MODULE_CIF.BBB.KRST1.B.RST = state;
}


IFX_INLINE void IfxCif_setMiBaseAddressInitializationEnableState(IfxCif_State state)
{
    MODULE_CIF.MI.CTRL.B.INIT_BASE_EN = state;
}


IFX_INLINE void IfxCif_setMiByteSwapEnableState(IfxCif_State enableState)
{
    MODULE_CIF.MI.CTRL.B.BYTE_SWAP = enableState;
}


IFX_INLINE void IfxCif_setMiChrominanceBurstLength(IfxCif_MiBurstLength burstLength)
{
    MODULE_CIF.MI.CTRL.B.BURST_LEN_CHROM = burstLength;
}


IFX_INLINE void IfxCif_setMiMainPictureWriteFormat(IfxCif_MiMainPictureWriteFormat format)
{
    MODULE_CIF.MI.CTRL.B.MP_WRITE_FORMAT = format;
}


IFX_INLINE void IfxCif_setMiMainPictureYInitialFillLevelInterruptOffset(uint32 interruptOffset)
{
    /* write value to unsigned component of the register structure because lower bits are tied to 0
     * as interrupt offset needs to be a word aligned value */
    MODULE_CIF.MI.MP_Y_IRQ_OFFS_INIT.U = interruptOffset;
}


IFX_INLINE void IfxCif_setMiOffsetCounterInitializationEnableState(IfxCif_State state)
{
    MODULE_CIF.MI.CTRL.B.INIT_OFFSET_EN = state;
}


IFX_INLINE void IfxCif_setNumberOfAcquisitionFrames(uint16 numberOfFrames)
{
    MODULE_CIF.ISP.ACQ_NR_FRAMES.B.ACQ_NR_FRAMES = numberOfFrames;
}


IFX_INLINE void IfxCif_setSecurityWatchdogCounterPredivider(uint16 predivider)
{
    MODULE_CIF.WD.CTRL.B.WD_PREDIV = predivider;
}


IFX_INLINE void IfxCif_setSecurityWatchdogEnableState(IfxCif_State enableState)
{
    MODULE_CIF.WD.CTRL.B.WD_EN = enableState;
}


IFX_INLINE void IfxCif_setYCSplitterChannelMode(IfxCif_YCSplitterChannelMode mode)
{
    MODULE_CIF.DPCL.B.CIF_CHAN_MODE = mode;
}


IFX_INLINE void IfxCif_startJpegJfifStreamEncoder(void)
{
    MODULE_CIF.JPE.ENCODE.B.ENCODE = 1;
}


#endif /* IFXCIF_H */
