/**
 * \file Ifx_LutLinearF32.c
 * \brief Linear look-up function
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
 */

#include "Ifx_LutLinearF32.h"

/** \brief Look-up table with binary search implementation
 *
 * Value inside table will be linearly interpolated.
 * Value outside table will be linearly extrapolated.
 *
 * \param ml pointer to the multi-segment object
 * \param index
 * \return linear interpolated value */
float32 Ifx_LutLinearF32_searchBin(const Ifx_LutLinearF32 *ml, float32 index)
{
    sint16 imin;
    sint16 imax;
    sint16 imid;

    imin = 0;
    imax = ml->segmentCount - 1;

    if (ml->segments[1].boundary > ml->segments[0].boundary)
    {
        while (imin < imax)
        {
            imid = imin + (imax - imin) / 2;

            if (index > ml->segments[imid].boundary)
            {
                imin = imid + 1;
            }
            else
            {
                imax = imid;
            }
        }
    }
    else
    {
        while (imin < imax)
        {
            imid = imin + (imax - imin) / 2;

            if (index < ml->segments[imid].boundary)
            {
                imin = imid + 1;
            }
            else
            {
                imax = imid;
            }
        }
    }

    return (ml->segments[imin].gain * index) + ml->segments[imin].offset;
}
