/**
 * \file Ifx_RampF32.h
 * \brief Ramp function
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
 * \defgroup library_srvsw_sysse_math_f32_ramp Ramp
 * \ingroup library_srvsw_sysse_math_f32
 *
 */

#ifndef IFX_RAMPF32_H
#define IFX_RAMPF32_H

#include "Cpu/Std/IfxCpu_Intrinsics.h"

/**
 * \brief Ifx_RampF32 object definition
 */
typedef struct
{
    float32 uk;
    float32 ik;
    float32 delta;
} Ifx_RampF32;

//________________________________________________________________________________________
// FUNCTION PROTOTYPES

/** \addtogroup library_srvsw_sysse_math_f32_ramp
 * \{ */
IFX_INLINE void    Ifx_RampF32_init(Ifx_RampF32 *ramp, float32 slewRate, float32 period);
IFX_INLINE void    Ifx_RampF32_reset(Ifx_RampF32 *ramp);
IFX_INLINE void    Ifx_RampF32_setSlewRate(Ifx_RampF32 *ramp, float32 slewRate, float32 period);
IFX_INLINE void    Ifx_RampF32_setRef(Ifx_RampF32 *ramp, float32 ref);
IFX_INLINE float32 Ifx_RampF32_getValue(Ifx_RampF32 *ramp);
IFX_EXTERN float32 Ifx_RampF32_step(Ifx_RampF32 *ramp);
/** \} */

//________________________________________________________________________________________
// INLINE FUNCTION IMPLEMENTATION

/**
 * \brief Reset internal values
 * \param ramp Pointer to the Ifx_RampF32 object
 */
IFX_INLINE void Ifx_RampF32_reset(Ifx_RampF32 *ramp)
{
    ramp->ik = 0;
    ramp->uk = 0;
}


/**
 * \brief Get the reference value
 * \param ramp Pointer to the Ifx_RampF32 object
 * \return Returns the ref value
 */
IFX_INLINE float32 Ifx_RampF32_getRef(Ifx_RampF32 *ramp)
{
    return ramp->ik;
}


/**
 * \brief Set the maximum slew rate
 * \param ramp Pointer to the Ifx_RampF32 object
 * \param slewRate Maximum slew rate, value per second
 * \param period Sampling period of the Ifx_RampF32_step() function
 */
IFX_INLINE void Ifx_RampF32_setSlewRate(Ifx_RampF32 *ramp, float32 slewRate, float32 period)
{
    ramp->delta = slewRate * period;
}


/**
 * \brief Initialize the Ifx_RampF32 object.
 * \param ramp Pointer to the Ifx_RampF32 object
 * \param slewRate Maximum slew rate, value per second
 * \param period Sampling period of the Ifx_RampF32_step() function
 */
IFX_INLINE void Ifx_RampF32_init(Ifx_RampF32 *ramp, float32 slewRate, float32 period)
{
    Ifx_RampF32_setSlewRate(ramp, slewRate, period);
    Ifx_RampF32_reset(ramp);
}


/**
 * \brief Set the reference value
 * \param ramp Pointer to the Ifx_RampF32 object
 * \param ref Reference value
 */
IFX_INLINE void Ifx_RampF32_setRef(Ifx_RampF32 *ramp, float32 ref)
{
    ramp->ik = ref;
}


/**
 * \brief Get the actual output value
 * \param ramp Pointer to the Ifx_RampF32 object
 * \return Actual value
 */
IFX_INLINE float32 Ifx_RampF32_getValue(Ifx_RampF32 *ramp)
{
    return ramp->uk;
}


#endif /* IFX_RAMPF32_H */
