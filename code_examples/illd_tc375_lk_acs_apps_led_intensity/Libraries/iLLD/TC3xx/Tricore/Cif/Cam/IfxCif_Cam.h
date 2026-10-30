/**
 * \file IfxCif_Cam.h
 * \brief CIF CAM details
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
 * \defgroup IfxLld_Cif_Cam CAM
 * \ingroup IfxLld_Cif
 * \defgroup IfxLld_Cif_Cam_camEnumerations Camera Enumerations
 * \ingroup IfxLld_Cif_Cam
 * \defgroup IfxLld_Cif_Cam_camFunctions Camera Functions
 * \ingroup IfxLld_Cif_Cam
 * \defgroup IfxLld_Cif_Cam_camStructures Camera Structures
 * \ingroup IfxLld_Cif_Cam
 */

#ifndef IFXCIF_CAM_H
#define IFXCIF_CAM_H 1

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include "Cif/Std/IfxCif.h"
#include "_PinMap/IfxCif_PinMap.h"
#include "Emem/Std/IfxEmem.h"
#include "I2c/I2c/IfxI2c_I2c.h"
#include "string.h"

/******************************************************************************/
/*-----------------------------------Macros-----------------------------------*/
/******************************************************************************/

#define IFXCIF_CAM_MEM_ALIGN_SIZE (64)

#define IFXCIF_CAM_MEM_GAPSIZE    0x0

/******************************************************************************/
/*--------------------------------Enumerations--------------------------------*/
/******************************************************************************/

/** \addtogroup IfxLld_Cif_Cam_camEnumerations
 * \{ */
/** \brief CIF ISP mode
 */
typedef enum
{
    IfxCif_Cam_IspMode_undefined      = -1, /**< \brief undefined */
    IfxCif_Cam_IspMode_raw            = 0,  /**< \brief raw */
    IfxCif_Cam_IspMode_yuvInterleaved = 1,  /**< \brief yuv interleaved */
    IfxCif_Cam_IspMode_yuvPlanar      = 2   /**< \brief yuv planar */
} IfxCif_Cam_IspMode;

/** \brief Driver acquisition state
 */
typedef enum
{
    IfxCif_Cam_State_stopped = 0,  /**< \brief stopped */
    IfxCif_Cam_State_running = 1   /**< \brief running */
} IfxCif_Cam_State;

/** \brief Driver status
 */
typedef enum
{
    IfxCif_Cam_Status_ok              = 0,  /**< \brief ok */
    IfxCif_Cam_Status_notEnoughMemory = 1,  /**< \brief not enough Memory */
    IfxCif_Cam_Status_cameraCommError = 2,  /**< \brief camera comm Error */
    IfxCif_Cam_Status_notAvailable    = 3   /**< \brief not available */
} IfxCif_Cam_Status;

/** \} */

/******************************************************************************/
/*-----------------------------Data Structures--------------------------------*/
/******************************************************************************/

/** \addtogroup IfxLld_Cif_Cam_camStructures
 * \{ */
typedef struct
{
    uint8            length;       /**< \brief length. Range: 0 to 0xFF */
    IFX_CONST uint8 *entry;        /**< \brief entry */
} IfxCif_Cam_TableInfo;

/** \} */

/** \addtogroup IfxLld_Cif_Cam_camStructures
 * \{ */
/** \brief Single component JPEG tables
 */
typedef struct
{
    IfxCif_Cam_TableInfo q;        /**< \brief q */
    IfxCif_Cam_TableInfo dc;       /**< \brief dc */
    IfxCif_Cam_TableInfo ac;       /**< \brief ac */
} IfxCif_Cam_JpegTable;

/** \brief Picture info
 */
typedef struct
{
    uint16 hSize;         /**< \brief horizontal (number of pixel). Range: 0 to 0xFFFF */
    uint16 vSize;         /**< \brief vertical (number of lines). Range: 0 to 0xFFFF */
    uint16 hOffset;       /**< \brief horizontal offset. Range: 0 to 0xFFFF */
    uint16 vOffset;       /**< \brief vertical offset. Range: 0 to 0xFFFF */
} IfxCif_Cam_PictureInfo;

/** \} */

/** \addtogroup IfxLld_Cif_Cam_camStructures
 * \{ */
/** \brief JPEG tables for all components
 */
typedef struct
{
    IfxCif_Cam_JpegTable y;        /**< \brief y */
    IfxCif_Cam_JpegTable uv;       /**< \brief uv */
} IfxCif_Cam_JpegTables;

/** \brief Single path memory interface configuration (used in initialisation/configuration)
 */
typedef struct
{
    float32 memFactor;       /**< \brief multiples of frame count for memory allocation */
    uint16  hSize;           /**< \brief horizontal (number of pixel). Range: 0 to 0xFFF */
    uint16  vSize;           /**< \brief vertical (number of lines). Range: 0 to 0xFFF */
    uint16  hOffset;         /**< \brief horizontal offset. Range: 0 to 0xFFF */
    uint16  vOffset;         /**< \brief vertical offset. Range: 0 to 0xFFF */
    boolean byteSwap;        /**< \brief byte swapping. Range: True -> Byte swapping feature enabled, False -> Byte swapping feature disabled */
} IfxCif_Cam_MemConfig;

/** \brief Single path memory interface information (used in Runtime)
 */
typedef struct
{
    Ifx_AddressValue       start;       /**< \brief start address */
    uint32                 size;        /**< \brief size in bytes Range: 0 to 0xFFFFFFFF */
    IfxCif_Cam_PictureInfo image;       /**< \brief image */
} IfxCif_Cam_MemInfo;

/** \} */

/** \addtogroup IfxLld_Cif_Cam_camStructures
 * \{ */
/** \brief Common configuration
 */
typedef struct
{
    IfxCif_Cam_PictureInfo           ispIn;                                /**< \brief ispIn */
    IfxCif_Cam_MemConfig             mainPath;                             /**< \brief main path */
    IfxCif_Cam_MemConfig             extraPaths[IFXCIF_EXTRA_PATHS];       /**< \brief extra paths */
    IfxCif_InputInterface            inputInterface;                       /**< \brief input interface */
    IfxCif_IsrSetting                ispInterrupt;                         /**< \brief isp interrupt */
    boolean                          debugPathEnabled;                     /**< \brief debug path enabled. Range: TRUE -> Debug path is enabled, FALSE -> Debug path is disabled */
    boolean                          watchdogEnabled;                      /**< \brief watchdog enabled. Range: TRUE -> The watchdog is enabled, FALSE -> The watchdog is disabled */
    IFX_CONST IfxCif_Cam_JpegTables *jpegTables;                           /**< \brief jpeg tables */
    boolean                          jpegEnabled;                          /**< \brief jpeg enabled Range: TRUE -> The Jpeg is enabled, FALSE -> The Jpeg is disabled */
} IfxCif_Cam_Common;

/** \brief Downscaler configuration
 */
typedef struct
{
    boolean                            enabled;          /**< \brief enable */
    IfxCif_LinearDownscalerScalingMode hMode;            /**< \brief hMode */
    IfxCif_LinearDownscalerScalingMode vMode;            /**< \brief vMode */
    uint8                              hFactor;          /**< \brief horizontal factor to program into IfxCif_setLinearDownscalerScalingFactors(). Range: 0 to 0xFF */
    uint8                              vFactor;          /**< \brief vertical factor to program into IfxCif_setLinearDownscalerScalingFactors(). Range: 0 to 0xFF */
    uint8                              sizeFactor;       /**< \brief memory size factor, e.g. half in both H and V usually gives factor of 4. Range: 0x2 or 0x4 */
} IfxCif_Cam_Downscaling;

/** \brief JPEG JFIF header structure
 */
typedef struct
{
    uint16 unknown;             /**< \brief unknown. Range: 0 to 0xFFFF */
    uint16 app0;                /**< \brief app0.  Range: 0 to 0xFFFF */
    uint16 length;              /**< \brief length. Range: 0 to 0xFFFF */
    uint8  ident[5];            /**< \brief ident. Range: 0 to 0xFF */
    uint16 version;             /**< \brief version. Range: 0 to 0xFFFF */
    uint8  density;             /**< \brief density. Range: 0 to 0xFF */
    uint16 densityX;            /**< \brief densityX. Range: 0 to 0xFFFF */
    uint16 densityY;            /**< \brief densityY. Range: 0 to 0xFFFF */
    uint8  thumbX;              /**< \brief thumbX. Range: 0 to 0xFF */
    uint8  thumbY;              /**< \brief thumbY. Range: 0 to 0xFF */
    uint8  thumbData[20];       /**< \brief thumbData. Range: 0 to 0xFF */
} IfxCif_Cam_JfifHeader;

/** \brief All paths memory partitioning
 */
typedef struct
{
    IfxCif_Cam_MemInfo y;                            /**< \brief y */
    IfxCif_Cam_MemInfo cb;                           /**< \brief cb */
    IfxCif_Cam_MemInfo cr;                           /**< \brief cr */
    IfxCif_Cam_MemInfo ep[IFXCIF_EXTRA_PATHS];       /**< \brief ep */
} IfxCif_Cam_MemAreas;

/** \} */

/** \addtogroup IfxLld_Cif_Cam_camStructures
 * \{ */
/** \brief Structure which is used as handle for the CIF-CAM functions.
 * This stores cached variables useful for run-time operations.
 */
typedef struct
{
    IfxCif_Cam_MemAreas    memAreas;              /**< \brief memory area definition */
    uint32                 totalMemSize;          /**< \brief total occupied memory area (in bytes). Range: 0 to 0xFFFFFFFF */
    Ifx_AddressValue       nextFreeAddress;       /**< \brief next free storage address */
    uint32                 availMemSize;          /**< \brief total available RAM space left (in bytes). Range: 0 to 0xFFFFFFFF */
    Ifx_CIF               *cif;                   /**< \brief pointer to base address of CIF module SFRs */
    Ifx_EMEM              *emem;                  /**< \brief pointer to base address of EMEM module SFRs */
    IfxCif_Cam_JfifHeader *jfif;                  /**< \brief pointer to the last acquired JPEG header */
    IfxCif_Cam_Status      configResult;          /**< \brief status of last configuration (or initialisation) */
    IfxCif_Cam_IspMode     ispMode;               /**< \brief actual ISP mode */
    boolean                ispBpp;                /**< \brief byte per pixel */
} IfxCif_Cam;

/** \brief Camera specific configuration
 */
typedef struct
{
    IFX_CONST IfxCif_Cam_Common      *common;               /**< \brief pointer to common configuration */
    IfxCif_Cam_IspMode                ispMode;              /**< \brief ISP mode */
    uint16                            ispRawBpp;            /**< \brief bytes per pixel of the input stream. Range: 0 to 0xFFFF */
    IfxCif_IspSyncPolarity            hSyncPolarity;        /**< \brief polarity of HSYNC signal */
    IfxCif_IspSyncPolarity            vSyncPolarity;        /**< \brief polarity of VSYNC signal */
    IfxCif_IspSamplingEdge            samplingEdge;         /**< \brief sampling edge */
    uint16                            setupDataCount;       /**< \brief number of camera-specific configuration data (in DWORDS). Range: 0 to 0xFFFF */
    IFX_CONST uint32                 *setupDataTable;       /**< \brief pointer to the first entry of camera-specific configuration data */
    IFX_CONST IfxCif_Cam_Downscaling *downscaling;          /**< \brief downscaling settings for ExtraPath 1 */
} IfxCif_Cam_Config;

/** \} */

/** \addtogroup IfxLld_Cif_Cam_camFunctions
 * \{ */

/******************************************************************************/
/*-------------------------Inline Function Prototypes-------------------------*/
/******************************************************************************/

/**
 * \brief Clears the frame reception flag associated with the given CIF-CAM handle.
 *
 * \param[in] cam Pointer to the CIF-CAM module handle. This structure contains runtime configuration and state information for the CIF-CAM module.
 *
 * \retval None
 */
IFX_INLINE void IfxCif_Cam_clearFrameReceptionFlag(const IfxCif_Cam *cam);

/**
 * \brief Clears the JPEG encoding complete flag.
 *
 * \param[in] cam Pointer to the CIF-CAM module handle.
 *
 * \retval None
 */
IFX_INLINE void IfxCif_Cam_clearJpegEncodingCompleteFlag(const IfxCif_Cam *cam);

/**
 * \brief Converts a CPU address to the corresponding BBB address.
 *
 * \param[in] cam  		 Pointer to the CIF-CAM module handle.
 * \param[in] cpuAddress CPU address to be converted to BBB address.
 *
 * \retval Ifx_AddressValue The converted BBB address corresponding to the provided CPU address.
 */
IFX_INLINE Ifx_AddressValue IfxCif_Cam_getBbbAddress(const IfxCif_Cam *cam, Ifx_AddressValue cpuAddress);

/**
 * \brief Returns the size (in bytes) of one last acquired extra-path image data.
 *
 * \param[in] cam Pointer to the CIF-CAM module handle.
 * \param[in] z   Extra path selector.
 * 				  Range: \ref IfxCif_ExtraPath
 *
 * \retval uint32 The size of the last acquired extra-path image data in bytes.
 * 				  Range: 0 to 0xFFFFFFFF
 */
IFX_INLINE uint32 IfxCif_Cam_getExtraFrameSize(const IfxCif_Cam *cam, IfxCif_ExtraPath z);

/**
 * \brief Returns the extra path memory interface information.
 *
 * \param[in] cam Pointer to the CIF-CAM module handle.
 * \param[in] z   Extra path selector.
 * 				  Range: \ref IfxCif_ExtraPath
 *
 * \retval uint32 The current single path memory interface information.
 * 				  Range: \ref IfxCif_Cam_MemInfo
 */
IFX_INLINE IFX_CONST IfxCif_Cam_MemInfo *IfxCif_Cam_getExtraPathMemInfo(const IfxCif_Cam *cam, IfxCif_ExtraPath z);

/**
 * \brief Returns the size of the last acquired main-path image data.
 *
 * \param[in] cam Pointer to the CIF-CAM module handle.
 *
 * \retval uint32 The size of the last acquired image data in bytes.
 * 				  Range: 0 to 0xFFFFFFFC
 */
IFX_INLINE uint32 IfxCif_Cam_getFrameSize(const IfxCif_Cam *cam);

/**
 * \brief Returns the size in bytes of the last encoded main-path JPEG image data.
 *
 * \param[in] cam Pointer to the CIF-CAM module handle.
 *
 * \retval uint32 The size in bytes of the last encoded JPEG image data.
 * 				  Range: 0 to 0xFFFFFFFF
 */
IFX_INLINE uint32 IfxCif_Cam_getJpegEncodedSize(const IfxCif_Cam *cam);

/**
 * \brief Returns the address location of the last acquired extra-path image frame data.
 *
 * \param[in] cam Pointer to the CIF-CAM module handle.
 * \param[in] z   Extra path identifier.
 * 				  Range: \ref IfxCif_ExtraPath
 *
 * \retval Ifx_AddressValue The memory address of the last acquired extra-path image frame data.
 */
IFX_INLINE Ifx_AddressValue IfxCif_Cam_getLastExtraAddress(const IfxCif_Cam *cam, IfxCif_ExtraPath z);

/**
 * \brief Returns the Extra capture Info last acquired extra-path image frame data.
 * 
 * \param[in]  cam     Pointer to the CIF-CAM module handle.
 * \param[in]  z       Extra path identifier.
 * 					   Range: \ref IfxCif_ExtraPath
 * \param[out] address Address Value.
 * \param[out] size    Size value.
 *
 * \retval IfxCif_Cam_MemInfo Pointer to single path memory interface information (used in Runtime).
 */
IFX_INLINE IFX_CONST IfxCif_Cam_MemInfo *IfxCif_Cam_getLastExtraCaptureInfo(const IfxCif_Cam *cam, IfxCif_ExtraPath z, Ifx_AddressValue *address, uint32 *size);

/**
 * \brief Retrieves the memory address of the last acquired main-path image frame data.
 *
 * \param[in] cam Pointer to the CIF-CAM module handle.
 *
 * \retval Ifx_AddressValue The memory address of the last acquired image frame data.
 */
IFX_INLINE Ifx_AddressValue IfxCif_Cam_getLastFrameAddress(const IfxCif_Cam *cam);

/**
 * \brief Retrieves the lastFrame capture Information.
 *
 * \param[in]  cam 	   Pointer to the CIF-CAM module handle.
 * \param[out] address Pointer to a variable where the memory address of the last acquired image frame will be stored.
 * \param[out] size    Pointer to a variable where the size of the last acquired image frame will be stored.
 *
 * \retval IfxCif_Cam_MemInfo The memory address of the last acquired image frame data.
 */
IFX_INLINE IFX_CONST IfxCif_Cam_MemInfo *IfxCif_Cam_getLastFrameCaptureInfo(const IfxCif_Cam *cam, Ifx_AddressValue *address, uint32 *size);

/**
 * \brief Returns the address location of the next acquired main-path image frame data.
 *
 * \param[in] cam Pointer to the CIF-CAM module handle.
 *
 * \retval Ifx_AddressValue The memory address of the next frame's image data.
 */
IFX_INLINE Ifx_AddressValue IfxCif_Cam_getNextFrameAddress(const IfxCif_Cam *cam);

/**
 * \brief Retrieves the memory address where the next acquired JPEG image frame data will be stored.
 *
 * \param[inout] cam Pointer to the CIF-CAM module handle.
 *
 * \retval Ifx_AddressValue The memory address of the next JPEG frame data buffer.
 */
IFX_INLINE Ifx_AddressValue IfxCif_Cam_getNextJpegFrameAddress(IfxCif_Cam *cam);

/**
 * \brief Increments the address related to the memory interface for the main-path, with wrap-around at the boundary of the allocated RAM size.
 *
 * \param[in]  cam     Pointer to the CIF-CAM module handle.
 * \param[out] address The current address value to be incremented.
 *
 * \retval Ifx_AddressValue The incremented address value, considering the wrap-around behavior at the RAM boundary.
 */
IFX_INLINE Ifx_AddressValue IfxCif_Cam_incrementAddress(const IfxCif_Cam *cam, Ifx_AddressValue address);

/**
 * \brief Checks if the reception of a frame is complete.
 *
 * \param[in] cam Pointer to the CIF-CAM module handle.
 *
 * \retval The current status indicating whether frame reception is complete.
 * 		   Range: TRUE  if the frame reception is complete.
 * 		   		  FALSE if the frame reception is not yet complete.
 */
IFX_INLINE boolean IfxCif_Cam_isFrameReceptionComplete(const IfxCif_Cam *cam);

/**
 * \brief Checks if the JPEG encoding process has completed.
 *
 * \param[in] cam Pointer to the CIF-CAM module handle.
 *
 * \retval The current status indicating whether jpeg encoding is complete.
 * 		   Range: TRUE  if the JPEG encoding process is complete.
 * 		   		  FALSE if the JPEG encoding process is still in progress.
 */
IFX_INLINE boolean IfxCif_Cam_isJpegEncodingComplete(const IfxCif_Cam *cam);

/**
 * \brief Skips the next picture in the CIF-CAM capture sequence.
 *
 * \param[in] cam Pointer to the CIF-CAM module handle.
 *
 * \retval None
 */
IFX_INLINE void IfxCif_Cam_skipPicture(const IfxCif_Cam *cam);

/******************************************************************************/
/*-------------------------Global Function Prototypes-------------------------*/
/******************************************************************************/

/**
 * \brief Clears all notification flags associated with the CIF-CAM module.
 *
 * \param[in] cam Pointer to the CIF-CAM module handle.
 *
 * \retval None
 */
IFX_EXTERN void IfxCif_Cam_clearAllFlags(const IfxCif_Cam *cam);

/**
 * \brief Disables the JPEG encoder and reverts the acquisition path to its original configuration, such as RAW or main path.
 *
 * \param[in] cam Pointer to the CIF-CAM module handle.
 *
 * \retval None
 */
IFX_EXTERN void IfxCif_Cam_disableJpegEncoder(const IfxCif_Cam *cam);

/**
 * \brief Enable the JPEG encoder and route the acquisition path accordingly
 * 
 * \param[in] cam Pointer to the CIF-CAM module handle.
 * 
 * \retval None
 */
IFX_EXTERN void IfxCif_Cam_enableJpegEncoder(const IfxCif_Cam *cam);

/**
 * \brief Returns pointer to the variable storing picture info of an extra-path.
 *
 * \param[in] cam Pointer to the CIF-CAM module handle.
 * \param[in] z   Extra Path.
 * 				  Range: \ref IfxCif_ExtraPath
 *
 * \retval IfxCif_Cam_PictureInfo pointer to the variable storing picture info of an extra-path.
 */
IFX_EXTERN IFX_CONST IfxCif_Cam_PictureInfo *IfxCif_Cam_getExtraPathPictureInfo(const IfxCif_Cam *cam, IfxCif_ExtraPath z);

/**
 * \brief Retrieves information about the last JPEG encoding process, including the memory address and size of the encoded frame.
 *
 * \param[inout] cam     Pointer to the CIF-CAM module handle.
 * \param[out]   address Pointer to the EMEM address where the last JPEG frame is stored.
 * \param[out]   size    Pointer to the size of the last JPEG frame (in bytes).
 *
 * \retval The current information about the last JPEG encoding process.
 * 		   Range: TRUE  Indicates that a new frame was encoded since the last call to this function.
 * 		   	      FALSE Indicates that no new frame was encoded since the last call to this function.
 */
IFX_EXTERN boolean IfxCif_Cam_getLastJpegEncodingInfo(IfxCif_Cam *cam, Ifx_AddressValue *address, sint32 *size);

/**
 * \brief Initialises the CIF, EMEM, PORT, I2C, and the camera itself.
 *
 * \param[inout] cam     Pointer to the CIF-CAM module handle.
 * \param[in]    config  Pointer to the configuration structure containing camera-specific settings such
 *                       as ISP mode, synchronization polarities, and other camera configuration parameters.
 * \param[in]    initCam Status of camera Initialisation.
 * 					     Range: TRUE  The camera will be reconfigured.
 * 					     	    FALSE The camera configuration will be skipped.
 *
 * \retval IfxCif_Cam_Status The success or failure status of the initialization process.
 * 							 Range: \ref IfxCif_Cam_Status
 */
IFX_EXTERN IfxCif_Cam_Status IfxCif_Cam_init(IfxCif_Cam *cam, const IfxCif_Cam_Config *config, boolean initCam);

/**
 * \brief Restarts the capture process by enabling the ISP output.
 *
 * \param[in] cam    Pointer to the CIF-CAM module handle.
 * \param[in] frames The number of frames to capture. This parameter determines how
 *                   many images will be captured in a single run. Setting this
 *                   parameter to zero will result in continuous capture.
 *                   Range: 0 to 0x3FF
 *
 * \retval None
 */
IFX_EXTERN void IfxCif_Cam_restartCapture(const IfxCif_Cam *cam, uint16 frames);

/**
 * \brief Starts the camera capture process by enabling the ISP output and initializing the MI counter.
 *
 * \param[in] cam    Pointer to the CIF-CAM module handle.
 * \param[in] frames Number of acquisitions. Set to zero for continuous acquisition.
 * 					 Range: 0 to 0x3FF
 *
 * \retval None
 */
IFX_EXTERN void IfxCif_Cam_startCapture(const IfxCif_Cam *cam, uint16 frames);

/**
 * \brief Stops the capture process by disabling the ISP output.
 *
 * \param[in] cam Pointer to the CIF-CAM module handle.
 *
 * \retval None
 */
IFX_EXTERN void IfxCif_Cam_stopCapture(const IfxCif_Cam *cam);

/** \} */

/******************************************************************************/
/*---------------------Inline Function Implementations------------------------*/
/******************************************************************************/

IFX_INLINE void IfxCif_Cam_clearFrameReceptionFlag(const IfxCif_Cam *cam)
{
    (void)cam;
    MODULE_CIF.ISP.ICR.U = (IFX_CIF_ISP_ICR_ICR_FRAME_MSK << IFX_CIF_ISP_ICR_ICR_FRAME_OFF);
}


IFX_INLINE void IfxCif_Cam_clearJpegEncodingCompleteFlag(const IfxCif_Cam *cam)
{
    (void)cam;
    MODULE_CIF.JPE.STATUS_ICR.U = (IFX_CIF_JPE_STATUS_ICR_ENCODE_DONE_MSK << IFX_CIF_JPE_STATUS_ICR_ENCODE_DONE_OFF);
}


IFX_INLINE Ifx_AddressValue IfxCif_Cam_getBbbAddress(const IfxCif_Cam *cam, Ifx_AddressValue cpuAddress)
{
    (void)cam;

    return (Ifx_AddressValue)(((uint32)cpuAddress & 0x00FFFFFFU) + IFXEMEM_START_ADDR_BBB);
}


IFX_INLINE uint32 IfxCif_Cam_getExtraFrameSize(const IfxCif_Cam *cam, IfxCif_ExtraPath z)
{
    sint32 size = 0;

    if (z <= IfxCif_ExtraPath_5)
    {
        size = cam->memAreas.ep[z].image.hSize * cam->memAreas.ep[z].image.vSize;

        if ((cam->ispMode != IfxCif_Cam_IspMode_raw) || (cam->ispBpp > 1))
        {
            size = size * 2;
        }
    }
    else
    {
        IFXCIF_DEBUG;
    }

    return (uint32)size;
}


IFX_INLINE IFX_CONST IfxCif_Cam_MemInfo *IfxCif_Cam_getExtraPathMemInfo(const IfxCif_Cam *cam, IfxCif_ExtraPath z)
{
    return &(cam->memAreas.ep[z]);
}


IFX_INLINE uint32 IfxCif_Cam_getFrameSize(const IfxCif_Cam *cam)
{
    (void)cam;
    sint32 size = MODULE_CIF.MI.MP_Y_OFFS_CNT_SHD.U - MODULE_CIF.MI.MP_Y_OFFS_CNT_START.U;

    if (size <= 0)
    {
        size += MODULE_CIF.MI.MP_Y_SIZE_INIT.U;
    }

    return (uint32)size;
}


IFX_INLINE uint32 IfxCif_Cam_getJpegEncodedSize(const IfxCif_Cam *cam)
{
    (void)cam;

    /* 0x240 is size of JFIF header. */
    return 0x240 + IfxCif_Cam_getFrameSize(cam);
}


IFX_INLINE Ifx_AddressValue IfxCif_Cam_getLastExtraAddress(const IfxCif_Cam *cam, IfxCif_ExtraPath z)
{
    Ifx_AddressValue address = 0;

    if (z <= IfxCif_ExtraPath_5)
    {
        address = (Ifx_AddressValue)((uint32)cam->memAreas.ep[z].start + MODULE_CIF.MIEP.CH_1S[z].OFFS_CNT_START.U);
    }

    return address;
}


IFX_INLINE IFX_CONST IfxCif_Cam_MemInfo *IfxCif_Cam_getLastExtraCaptureInfo(const IfxCif_Cam *cam, IfxCif_ExtraPath z, Ifx_AddressValue *address, uint32 *size)
{
    const IfxCif_Cam_MemInfo *m;
    *size    = IfxCif_Cam_getExtraFrameSize(cam, z);
    *address = IfxCif_Cam_getLastExtraAddress(cam, z);
    m        = IfxCif_Cam_getExtraPathMemInfo(cam, z);
    return m;
}


IFX_INLINE Ifx_AddressValue IfxCif_Cam_getLastFrameAddress(const IfxCif_Cam *cam)
{
    (void)cam;

    return (Ifx_AddressValue)(IFXEMEM_START_ADDR_CPU_CACHED + MODULE_CIF.MI.MP_Y_OFFS_CNT_START.U);
}


IFX_INLINE IFX_CONST IfxCif_Cam_MemInfo *IfxCif_Cam_getLastFrameCaptureInfo(const IfxCif_Cam *cam, Ifx_AddressValue *address, uint32 *size)
{
    const IfxCif_Cam_MemInfo *m;
    *size    = IfxCif_Cam_getFrameSize(cam);
    *address = IfxCif_Cam_getLastFrameAddress(cam);
    m        = &(cam->memAreas.y);
    return m;
}


IFX_INLINE Ifx_AddressValue IfxCif_Cam_getNextFrameAddress(const IfxCif_Cam *cam)
{
    (void)cam;

    return (Ifx_AddressValue)(IFXEMEM_START_ADDR_CPU_CACHED + MODULE_CIF.MI.MP_Y_OFFS_CNT_SHD.U);
}


IFX_INLINE Ifx_AddressValue IfxCif_Cam_getNextJpegFrameAddress(IfxCif_Cam *cam)
{
    Ifx_AddressValue address = IfxCif_Cam_getNextFrameAddress(cam);
    cam->jfif = (IfxCif_Cam_JfifHeader *)address; /* note: no cast to (void *) to satisfy C++ compilers */
    return address;
}


IFX_INLINE Ifx_AddressValue IfxCif_Cam_incrementAddress(const IfxCif_Cam *cam, Ifx_AddressValue address)
{
    address = (Ifx_AddressValue)((uint32)address + 4U);

    if ((uint32)address >= (IFXEMEM_START_ADDR_CPU_CACHED + cam->memAreas.y.size))
    {   /* back to base */
        address = (Ifx_AddressValue)IFXEMEM_START_ADDR_CPU_CACHED;
    }

    return address;
}


IFX_INLINE boolean IfxCif_Cam_isFrameReceptionComplete(const IfxCif_Cam *cam)
{
    (void)cam;

    return MODULE_CIF.ISP.RIS.B.RIS_FRAME != 0;
}


IFX_INLINE boolean IfxCif_Cam_isJpegEncodingComplete(const IfxCif_Cam *cam)
{
    (void)cam;

    return MODULE_CIF.JPE.STATUS_RIS.B.ENCODE_DONE != 0;
}


IFX_INLINE void IfxCif_Cam_skipPicture(const IfxCif_Cam *cam)
{
    (void)cam;
    IfxCif_setMiOffsetCounterInitializationEnableState(IfxCif_State_Disabled);
    IfxCif_miSkipPicture();
}


#endif /* IFXCIF_CAM_H */
