/**
 * \file IfxPpu_Intrinsics.h
 * \ingroup IfxLld_Ppu_Intrinsics Intrinsics
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
 * \defgroup IfxLld_Ppu_Intrinsics Intrinsics
 * \ingroup IfxLld_Ppu_Std
 *
 */
#ifndef IFXPPU_INTRINSICS_H
#define IFXPPU_INTRINSICS_H 1
/******************************************************************************/
#include "Ifx_Types.h"

#if defined(__DCC__)
#include "IfxCpu_IntrinsicsWindriver.h"

#elif defined(__TASKING__)
#if defined(__CTC__)
#include "IfxCpu_IntrinsicsTasking.h"
#else
#include "IfxPpu_IntrinsicsTasking.h"
#endif	

#elif defined(__HIGHTEC__) && !defined(__clang__)
#include "IfxCpu_IntrinsicsGnuc.h"

#elif defined(__HIGHTEC__) && defined(__clang__)
#include "IfxCpu_IntrinsicsHighTec.h"

#elif defined(__GNUC__) && !defined(__HIGHTEC__) && !defined(__CCAC__)
#include "IfxCpu_IntrinsicsGcc.h"

#elif defined(__ghs__)
#include "IfxCpu_IntrinsicsGhs.h"

#elif defined(__CCAC__)
#include "IfxPpu_IntrinsicsMw.h"
#else
#error Compiler unsupported
#endif

#define IFX_ALIGN_8   (1)            // Align on 8 bit Boundary
#define IFX_ALIGN_16  (2)            // Align on 16 bit Boundary
#define IFX_ALIGN_32  (4)            // Align on 32 bit Boundary
#define IFX_ALIGN_64  (8)            // Align on 64 bit Boundary
#define IFX_ALIGN_128 (16)           // Align on 128 bit Boundary
#define IFX_ALIGN_256 (32)           // Align on 256 bit Boundary

#define Ifx_AlignOn256(Size) ((((Size) + (IFX_ALIGN_256 - 1)) & (~(IFX_ALIGN_256 - 1))))
#define Ifx_AlignOn128(Size) ((((Size) + (IFX_ALIGN_128 - 1)) & (~(IFX_ALIGN_128 - 1))))
#define Ifx_AlignOn64(Size)  ((((Size) + (IFX_ALIGN_64 - 1)) & (~(IFX_ALIGN_64 - 1))))
#define Ifx_AlignOn32(Size)  ((((Size) + (IFX_ALIGN_32 - 1)) & (~(IFX_ALIGN_32 - 1))))
#define Ifx_AlignOn16(Size)  ((((Size) + (IFX_ALIGN_16 - 1)) & (~(IFX_ALIGN_16 - 1))))
#define Ifx_AlignOn8(Size)   ((((Size) + (IFX_ALIGN_8 - 1)) & (~(IFX_ALIGN_8 - 1))))

#define Ifx_COUNTOF(x)       (sizeof(x) / sizeof(x[0]))

//______________________________________________________________________________
#if !defined(__CCAC__) &&  !defined(__CARC__)
/** Convert context pointer to address pointer
 * \param[in] cx context pointer
 * \return address pointer
 */
IFX_INLINE void *__cx_to_addr(uint32 cx)
{
    uint32 seg_nr = __extru(cx, 16, 4);
    return (void *)__insert(seg_nr << 28, cx, 6, 16);
}


/** Convert address pointer to context pointer
 * \param[in] addr address pointer
 * \return context pointer
 */
IFX_INLINE uint32 __addr_to_cx(void *addr)
{
    uint32 seg_nr, seg_idx;
    seg_nr  = __extru((int)addr, 28, 4) << 16;
    seg_idx = __extru((int)addr, 6, 16);
    return seg_nr | seg_idx;
}

#endif
/******************************************************************************/
#if defined(__CCAC__)
IFX_INLINE void Ifx__ldmst(volatile void *address, unsigned mask, unsigned value)
{
    *(volatile uint32 *)address = (*(volatile uint32 *)address & ~(mask)) | (mask & value);
}

IFX_INLINE uint32 __clz(sint32 x)
{
	uint32 n = 0;
    uint32 bits = sizeof(x) * 8;
    for (int i = 1; i < bits; i ++) {
        if (x < 0) break;
        n ++;
        x <<= 1;
    }
    return n;
}

IFX_INLINE void Ifx__imaskldmst(volatile void *address, unsigned value, unsigned bitoffset, unsigned bits)
{
	uint32 mask = (((1u << bits) - 1u) << bitoffset);
	uint32 shiftValue = (value << bitoffset);
	*(volatile uint32 *)address = (*(volatile uint32 *)address & ~(mask)) | (mask & shiftValue);
}
#endif


/** 32bit load operation
 */
IFX_INLINE uint32 __ld32(void *addr)
{
    return *(volatile uint32 *)addr;
}


/** 32bit store operation
 */
IFX_INLINE void __st32(void *addr, uint32 value)
{
    *(volatile uint32 *)addr = value;
}


/** 64bit load operation
 */
IFX_INLINE uint64 __ld64(void *addr)
{
    return *(volatile uint64 *)addr;
}


/** 64bit store operation
 */
IFX_INLINE void __st64(void *addr, uint64 value)
{
    *(volatile uint64 *)addr = value;
}


/** 64bit load operation which returns the lower and upper 32bit word
 */
IFX_INLINE void __ld64_lu(void *addr, uint32 *valueLower, uint32 *valueUpper)
{
    uint64 value;
    value       = __ld64(addr);
    *valueLower = (uint32)value;
    *valueUpper = (uint32)(value >> 32);
}


/** 64bit store operation which stores a lower and upper 32bit word
 */
IFX_INLINE void __st64_lu(void *addr, uint32 valueLower, uint32 valueUpper)
{
    uint64 value = ((uint64)valueUpper << 32) | valueLower;
    __st64(addr, value);
}


/******************************************************************************/
#endif /* IFXPPU_INTRINSICS_H */
