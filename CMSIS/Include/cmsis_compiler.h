#ifndef CMSIS_COMPILER_H
#define CMSIS_COMPILER_H

/* Minimal cmsis_compiler.h for x86 GCC (no ARM intrinsics) */

#define __ASM            __asm
#define __INLINE         inline
#define __STATIC_INLINE  static inline

#ifndef __STATIC_FORCEINLINE
#define __STATIC_FORCEINLINE static inline __attribute__((always_inline))
#endif


#define __ALIGN(x)       __attribute__((aligned(x)))
#define __PACKED         __attribute__((__packed__))
#define __WEAK           __attribute__((weak))

/* NOP instruction stub */
#define __NOP()          do {} while(0)

/* Data memory barrier and instruction barrier stubs */
#define __DMB()          do {} while(0)
#define __DSB()          do {} while(0)
#define __ISB()          do {} while(0)

/* Intrinsic function stubs that CMSIS might use */

/* Saturate to Q15 */
__STATIC_INLINE int16_t __SSAT(int32_t val, uint32_t sat)
{
    int32_t max = (1 << (sat - 1)) - 1;
    int32_t min = -(1 << (sat - 1));
    if (val > max) return (int16_t)max;
    else if (val < min) return (int16_t)min;
    else return (int16_t)val;
}

/* Saturate to Q31 */
__STATIC_INLINE int32_t __SSAT32(int32_t val, uint32_t sat)
{
    int32_t max = (1 << (sat - 1)) - 1;
    int32_t min = -(1 << (sat - 1));
    if (val > max) return max;
    else if (val < min) return min;
    else return val;
}

/* Count leading zeros */
__STATIC_INLINE uint32_t __CLZ(uint32_t x)
{
    if (x == 0) return 32;
    uint32_t n = 0;
    while ((x & 0x80000000) == 0) {
        n++;
        x <<= 1;
    }
    return n;
}

/* Rotate right */
__STATIC_INLINE uint32_t __ROR(uint32_t value, uint32_t amount)
{
    amount &= 31;
    return (value >> amount) | (value << (32 - amount));
}

/* No intrinsic multiply accumulate */
#define __SMLABB(a,b,c) ((int32_t)(((int16_t)(a)) * ((int16_t)(b)) + (c)))
#define __SMLAWB(a,b,c) ((int32_t)(((int32_t)(a) >> 16) * ((int16_t)(b)) + (c)))

#endif /* CMSIS_COMPILER_H */
