/**
 * \file Ifx_AngleTrkF32.h
 * \brief Angle-tracking observer for sin/cos analog position sensor
 *
 *
 *
 * \version disabled
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
 * \defgroup library_srvsw_sysse_math_f32_angletrk Angle-Tracking Observer
 * This driver implements \ref library_srvsw_stdif_posif using 3rd order Angle-Tracking Observer algorithm.
 * \ingroup library_srvsw_sysse_math_f32
 *
 */

#ifndef IFX_ANGLETRKF32_H
#define IFX_ANGLETRKF32_H

//________________________________________________________________________________________
// INCLUDES

#include "StdIf/IfxStdIf_Pos.h"
#include "SysSe/Math/Ifx_LowPassPt1F32.h"

//________________________________________________________________________________________
// CONFIGURATION DEFINES

#ifndef IFX_CFG_ANGLETRKF32_SPEED_FILTER
#define IFX_CFG_ANGLETRKF32_SPEED_FILTER (1)
#endif

//________________________________________________________________________________________
// DATA STRUCTURES

/** \brief Angle Tracking Observer configuration */
typedef struct
{
    float32               kp;                /**< \brief Proportional gain */
    float32               ki;                /**< \brief Integrator gain */
    float32               kd;                /**< \brief Derivative gain */
    float32               speedLpfFc;        /**< \brief Cut-off frequency of speed low-pass filter. */
    float32               errorThreshold;    /**< \brief Threshold of error value in the tracking loop */
    sint32                sqrAmplMax;        /**< \brief Maximum value for square of signal amplitudes */
    sint32                sqrAmplMin;        /**< \brief Minimum value for square of signal amplitudes */
    uint16                periodPerRotation; /**< \brief Number of electrical periods per mechanical rotation */
    boolean               reversed;          /**< \brief TRUE: reversed direction, FALSE: straight direction */
    sint32                resolution;        /**< \brief Sensor resolution */
    IfxStdIf_Pos_RawAngle offset;            /**< \brief Offset in ticks. [0 .. (\ref Ifx_AngleTrkF32_Config.resolution - 1)] */
    sint16               *sinIn;             /**< \brief Pointer to SIN input variable */
    sint16               *cosIn;             /**< \brief Pointer to COS input variable */
} Ifx_AngleTrkF32_Config;

typedef struct
{
    float32 kp;                   /**< \brief Proportional gain */
    float32 ki;                   /**< \brief Integrator gain */
    float32 kd;                   /**< \brief Derivative gain */
    float32 errorThreshold;       /**< \brief Threshold of error value in the tracking loop */
    sint32  sqrAmplMax;           /**< \brief Maximum value for square of signal amplitudes */
    sint32  sqrAmplMin;           /**< \brief Minimum value for square of signal amplitudes */
} Ifx_AngleTrkF32_CfgData;

typedef struct
{
    IfxStdIf_Pos_RawAngle rawPosition;       /**< \brief raw position in ticks. \note: the value already contains the offset */
    sint32                turn;              /**< \brief number of mechanical turns. FIXME to be implemented */
    IfxStdIf_Pos_Dir      direction;         /**< \brief rotation direction */
    IfxStdIf_Pos_Status   status;            /**< \brief error code (0 = no error) */
    /* configuration */
    IfxStdIf_Pos_RawAngle offset;            /**< \brief raw position offset */
    boolean               reversed;          /**< \brief reverse direction */
    uint16                periodPerRotation; /**< \brief sensor 'electrical' periods per mechanical rotation */
    IfxStdIf_Pos_RawAngle resolution;        /**< \brief resolution of this position sensor interface */
    float32               Ts;                /**< \brief update period in seconds */
    float32               positionConst;     /**< \brief constant for calculating mechanical position (in rad) from raw position */
} Ifx_AngleTrkF32_PosIf;

/** \brief Angle Tracking Observer object */
typedef struct
{
    Ifx_AngleTrkF32_PosIf   base;
    Ifx_AngleTrkF32_CfgData cfgData;
    sint16                  *sinIn; /**< \brief Pointer to SIN input variable */
    sint16                  *cosIn; /**< \brief Pointer to COS input variable */
    float32                  halfTs;
    float32                  angleAtan;
    float32                  angleRef;
    float32                  angleEst;
    float32                  speedEstA;
    float32                  speedEstB;
    float32                  accelEst;
    float32                  angleErr;
    Ifx_LowPassPt1F32       speedLpf; /**< Only used if IFX_CFG_ANGLETRKF32_SPEED_FILTER is set */
} Ifx_AngleTrkF32;

/** \addtogroup library_srvsw_sysse_math_f32_angletrk
 * \{ */

//________________________________________________________________________________________
// PUBLIC FUNCTION PROTOTYPES

/** \name Initialisation functions
 * Example use:
 * \code
 * extern sint16    g_SinInput, g_CosInput;
 * Ifx_AngleTrkF32_Config  driverConfig;
 * Ifx_AngleTrkF32         driverData;
 * Ifx_AngleTrkF32_initConfig(&driverConfig, &g_SinInput, g_CosInput);
 * driverConfig.errorThreshold    = 5.0 / 180 * IFX_PI; // 5 degree error
 * driverConfig.sqrAmplMax        = 1.01 * 1.01;
 * driverConfig.sqrAmplMin        = 0.99 * 0.99;
 * driverConfig.speedLpfFc        = 100;
 * driverConfig.periodPerRotation = 1;
 * driverConfig.reversed          = FALSE;
 * driverConfig.offset            = 0;
 * Ifx_AngleTrkF32_init(&driverData, &driverConfig);
 * \endcode
 * Prototypes:
 * \{ */
IFX_EXTERN void Ifx_AngleTrkF32_init(Ifx_AngleTrkF32 *aObsv, const Ifx_AngleTrkF32_Config *config, float32 Ts);
IFX_EXTERN void Ifx_AngleTrkF32_initConfig(Ifx_AngleTrkF32_Config *config, sint16 *sinIn, sint16 *cosIn);
/** \} */

/** \name Protected functions
 * These functions are not for end-user but may be used by another driver which extends
 * the functionality of library_srvsw_sysse_math_f32_angletrk
 * \{ */
IFX_EXTERN float32 Ifx_AngleTrkF32_step(Ifx_AngleTrkF32 *aObsv, sint16 sinIn, sint16 cosIn, float32 phase);
IFX_EXTERN void    Ifx_AngleTrkF32_updateStatus(Ifx_AngleTrkF32 *aObsv, sint16 sinIn, sint16 cosIn);
IFX_INLINE float32 Ifx_AngleTrkF32_getLoopSpeed(Ifx_AngleTrkF32 *aObsv);
/** \} */

/** \} */

/** \brief get the speed.
 * \param aObsv Pointer to the Ifx_AngleTrkF32 object
 */
IFX_INLINE float32 Ifx_AngleTrkF32_getLoopSpeed(Ifx_AngleTrkF32 *aObsv)
{
    return aObsv->speedEstB;   /* note: using speedEstB has better dynamic */
    /* return aObsv->speedLpf.out; */
}


/** \addtogroup library_srvsw_sysse_math_f32_angletrk
 * \{ */

/******************************************************************************/
/*-------------------------Global Function Prototypes-------------------------*/
/******************************************************************************/

/** \brief \see IfxStdIf_Pos_GetAbsolutePosition
 * \param driver driver handle
 * \return absolute position
 */
IFX_EXTERN float32 Ifx_AngleTrkF32_getAbsolutePosition(Ifx_AngleTrkF32 *driver);

/** \brief \see IfxStdIf_Pos_GetDirection
 * \param driver driver handle
 * \return direction
 */
IFX_EXTERN IfxStdIf_Pos_Dir Ifx_AngleTrkF32_getDirection(Ifx_AngleTrkF32 *driver);

/** \brief \see IfxStdIf_Pos_GetFault
 * \param driver driver handle
 * \return Fault
 */
IFX_EXTERN IfxStdIf_Pos_Status Ifx_AngleTrkF32_getFault(Ifx_AngleTrkF32 *driver);

/** \brief \see IfxStdIf_Pos_GetOffset
 * \param driver driver handle
 * \return offset address
 */
IFX_EXTERN sint32 Ifx_AngleTrkF32_getOffset(Ifx_AngleTrkF32 *driver);

/** \brief \see IfxStdIf_Pos_GetPeriodPerRotation
 * \param driver driver handle
 * \return Period per rotation
 */
IFX_EXTERN uint16 Ifx_AngleTrkF32_getPeriodPerRotation(Ifx_AngleTrkF32 *driver);

/** \brief \see IfxStdIf_Pos_GetPosition
 * \param driver driver handle
 * \return position
 */
IFX_EXTERN float32 Ifx_AngleTrkF32_getPosition(Ifx_AngleTrkF32 *driver);

/** \brief \see IfxStdIf_Pos_GetRawPosition
 * \param aObsv Pointer to the Ifx_AngleTrkF32 object
 * \return position in ticks
 */
IFX_EXTERN IfxStdIf_Pos_RawAngle Ifx_AngleTrkF32_getRawPosition(Ifx_AngleTrkF32 *aObsv);

/** \brief \see IfxStdIf_Pos_GetRefreshPeriod
 * \param driver driver handle
 * \return update period
 */
IFX_EXTERN float32 Ifx_AngleTrkF32_getRefreshPeriod(Ifx_AngleTrkF32 *driver);

/** \brief \see IfxStdIf_Pos_GetResolution
 * \param driver driver handle
 * \return resolution
 */
IFX_EXTERN sint32 Ifx_AngleTrkF32_getResolution(Ifx_AngleTrkF32 *driver);

/** \brief \see IfxStdIf_Pos_GetTurn
 * \param driver driver handle
 * \return Returns the number of turns
 */
IFX_EXTERN sint32 Ifx_AngleTrkF32_getTurn(Ifx_AngleTrkF32 *driver);

/** \brief \see IfxStdIf_Pos_GetSensorType
 * \param driver driver handle
 * \return sensor type
 */
IFX_EXTERN IfxStdIf_Pos_SensorType Ifx_AngleTrkF32_getSensorType(Ifx_AngleTrkF32 *driver);

/** \brief \see IfxStdIf_Pos_GetSpeed
 * \param aObsv Pointer to the Ifx_AngleTrkF32 object
 * \return speed
 */
IFX_EXTERN float32 Ifx_AngleTrkF32_getSpeed(Ifx_AngleTrkF32 *aObsv);

/** \brief \see IfxStdIf_Pos_Reset
 * \param driver driver handle
 * \return None
 */
IFX_EXTERN void Ifx_AngleTrkF32_reset(Ifx_AngleTrkF32 *driver);

/** \brief \see IfxStdIf_Pos_ResetFaults
 * \param driver driver handle
 * \return None
 */
IFX_EXTERN void Ifx_AngleTrkF32_resetFaults(Ifx_AngleTrkF32 *driver);

/** \brief \see IfxStdIf_Pos_SetOffset
 * \param aObsv driver handle
 * \param offset offset
 * \return None
 */
IFX_EXTERN void Ifx_AngleTrkF32_setOffset(Ifx_AngleTrkF32 *aObsv, IfxStdIf_Pos_RawAngle offset);

/** \brief \see IfxStdIf_Pos_SetRefreshPeriod
 * \param driver driver handle
 * \param updatePeriod update period
 * \return None
 */
IFX_EXTERN void Ifx_AngleTrkF32_setRefreshPeriod(Ifx_AngleTrkF32 *driver, float32 updatePeriod);

/** \brief \see IfxStdIf_Pos_Update
 * \param aObsv driver handle
 * \return None
 */
IFX_EXTERN void Ifx_AngleTrkF32_update(Ifx_AngleTrkF32 *aObsv);

/** \} */

/******************************************************************************/
/*-------------------------Global Function Prototypes-------------------------*/
/******************************************************************************/

/** \brief Initializes the standard interface "Pos"
 * \param stdif Standard interface position object
 * \param driver Virtual position sensor
 * \return TRUE on success else FALSE
 */
IFX_EXTERN boolean Ifx_AngleTrkF32_stdIfPosInit(IfxStdIf_Pos *stdif, Ifx_AngleTrkF32 *driver);

#endif /* IFX_ANGLETRKF32_H */
