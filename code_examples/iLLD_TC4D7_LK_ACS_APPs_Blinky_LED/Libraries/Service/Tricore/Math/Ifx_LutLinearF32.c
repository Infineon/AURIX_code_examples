/**
 * \file Ifx_LutLinearF32.c
 * \brief Linear look-up function
 *
 *
 * \version iLLD-TC4-v2.6.0
 * \copyright Copyright (c) 2026 Infineon Technologies AG. All rights reserved.
 *
 *
  *                                 IMPORTANT NOTICE
 *
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
