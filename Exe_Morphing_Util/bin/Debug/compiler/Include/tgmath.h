#ifndef _TGMATH_H
#define _TGMATH_H

/* tgmath.h - C99 standard header */

#if __POCC__ >= 500
#pragma once
#endif

#include <math.h>
#include <complex.h>

#if __POCC_STDC_VERSION__ < 201101L

#define __TGMATH_UNARY_REAL_ONLY(x,fn)  __tgeneric__(x,,,fn##f,fn,fn##l,,,)(x)
#define __TGMATH_BINARY_FIRST_REAL_ONLY(x,y,fn)  __tgeneric__(x,,,fn##f,fn,fn##l,,,)(x,y)
#define __TGMATH_BINARY_REAL_ONLY(x,y,fn)  __tgeneric__(x,y,,fn##f,fn,fn##l,,,)(x,y)
#define __TGMATH_TERNARY_FIRST_SECOND_REAL_ONLY(x,y,z,fn)  __tgeneric__(x,y,,fn##f,fn,fn##l,,,)(x,y,z)
#define __TGMATH_TERNARY_REAL_ONLY(x,y,z,fn)  __tgeneric__(x,y,z,fn##f,fn,fn##l,,,)(x,y,z)
#define __TGMATH_UNARY_REAL_IMAG(x,fn,cfn)  __tgeneric__(x,,,fn##f,fn,fn##l,cfn##f,cfn,cfn##l)(x)
#define __TGMATH_UNARY_IMAG_ONLY(x,cfn)  __tgeneric__(x,,,,,,cfn##f,cfn,cfn##l)(x)
#define __TGMATH_BINARY_REAL_IMAG(x,y,fn,cfn)  __tgeneric__(x,y,,fn##f,fn,fn##l,cfn##f,cfn,cfn##l)(x,y)

#else /* __POCC_STDC_VERSION__ >= 201101L */

/* C11 got _Generic(), so may as well use it... */

#define __TGMATH_REAL(x,f,d,ld) \
    _Generic(x, float:f, default:d, long double:ld)

#define __TGMATH_REAL_IMAG(x,f,d,ld,fc,dc,ldc) \
    _Generic(x, float:f, default:d, long double:ld, float complex:fc, double complex:dc, long double complex:ldc)

#define __TGMATH_REAL_BINARY(x,y,f,d,ld) \
    __TGMATH_REAL(x, \
        __TGMATH_REAL(y,  f,  d, ld), \
        __TGMATH_REAL(y,  d,  d, ld), \
        __TGMATH_REAL(y, ld, ld, ld))

#define __TGMATH_REAL_IMAG_BINARY(x,y,f,d,ld,fc,dc,ldc) \
    __TGMATH_REAL_IMAG(x, \
        __TGMATH_REAL_IMAG(y,   f,   d, ld,   fc,  dc, ldc), \
        __TGMATH_REAL_IMAG(y,   d,   d, ld,   dc,  dc, ldc), \
        __TGMATH_REAL_IMAG(y,  ld,  ld, ld,  ldc, ldc, ldc), \
        __TGMATH_REAL_IMAG(y,  fc,  dc, ldc,  fc,  dc, ldc), \
        __TGMATH_REAL_IMAG(y,  dc,  dc, ldc,  dc,  dc, ldc), \
        __TGMATH_REAL_IMAG(y, ldc, ldc, ldc, ldc, ldc, ldc))

#define __TGMATH_REAL_TERNARY(x,y,z,f,d,ld) \
    __TGMATH_REAL(x, \
        __TGMATH_REAL(y, \
            __TGMATH_REAL(z,  f,  d, ld), \
            __TGMATH_REAL(z,  d,  d, ld), \
            __TGMATH_REAL(z, ld, ld, ld)), \
        __TGMATH_REAL(y, \
            __TGMATH_REAL(z,  d,  d, ld), \
            __TGMATH_REAL(z,  d,  d, ld), \
            __TGMATH_REAL(z, ld, ld, ld)), \
        __TGMATH_REAL(y, \
            __TGMATH_REAL(z, ld, ld, ld), \
            __TGMATH_REAL(z, ld, ld, ld), \
            __TGMATH_REAL(z, ld, ld, ld)))

#define __TGMATH_UNARY_REAL_ONLY(x,fn)  __TGMATH_REAL(x,fn##f,fn,fn##l)(x)
#define __TGMATH_BINARY_FIRST_REAL_ONLY(x,y,fn)  __TGMATH_REAL(x,fn##f,fn,fn##l)(x,y)
#define __TGMATH_BINARY_REAL_ONLY(x,y,fn)  __TGMATH_REAL_BINARY(x,y,fn##f,fn,fn##l)(x,y)
#define __TGMATH_TERNARY_FIRST_SECOND_REAL_ONLY(x,y,z,fn)  __TGMATH_REAL_BINARY(x,y,fn##f,fn,fn##l)(x,y,z)
#define __TGMATH_TERNARY_REAL_ONLY(x,y,z,fn)  __TGMATH_REAL_TERNARY(x,y,z,fn##f,fn,fn##l)(x,y,z)
#define __TGMATH_UNARY_REAL_IMAG(x,fn,cfn)  __TGMATH_REAL_IMAG(x,fn##f,fn,fn##l,cfn##f,cfn,cfn##l)(x)
#define __TGMATH_UNARY_IMAG_ONLY(x,cfn)  __TGMATH_REAL_IMAG(x,cfn##f,cfn,cfn##l,cfn##f,cfn,cfn##l)(x)
#define __TGMATH_BINARY_REAL_IMAG(x,y,fn,cfn)  __TGMATH_REAL_IMAG_BINARY(x,y,fn##f,fn,fn##l,cfn##f,cfn,cfn##l)(x,y)

#endif /* __POCC_STDC_VERSION__ >= 201101L */

/* trigonometric functions */
#undef acos
#define acos(x)  __TGMATH_UNARY_REAL_IMAG(x,acos,cacos)
#undef asin
#define asin(x)  __TGMATH_UNARY_REAL_IMAG(x,asin,casin)
#undef atan
#define atan(x)  __TGMATH_UNARY_REAL_IMAG(x,atan,catan)
#undef atan2
#define atan2(x,y)  __TGMATH_BINARY_REAL_ONLY(x,y,atan2)
#undef cos
#define cos(x)  __TGMATH_UNARY_REAL_IMAG(x,cos,ccos)
#undef sin
#define sin(x)  __TGMATH_UNARY_REAL_IMAG(x,sin,csin)
#undef tan
#define tan(x)  __TGMATH_UNARY_REAL_IMAG(x,tan,ctan)

/* hyperbolic functions */
#undef acosh
#define acosh(x)  __TGMATH_UNARY_REAL_IMAG(x,acosh,cacosh)
#undef asinh
#define asinh(x)  __TGMATH_UNARY_REAL_IMAG(x,asinh,casinh)
#undef atanh
#define atanh(x)  __TGMATH_UNARY_REAL_IMAG(x,atanh,catanh)
#undef cosh
#define cosh(x)  __TGMATH_UNARY_REAL_IMAG(x,cosh,ccosh)
#undef sinh
#define sinh(x)  __TGMATH_UNARY_REAL_IMAG(x,sinh,csinh)
#undef tanh
#define tanh(x)  __TGMATH_UNARY_REAL_IMAG(x,tanh,ctanh)

/* exponential and logarithmic functions */
#undef exp
#define exp(x)  __TGMATH_UNARY_REAL_IMAG(x,exp,cexp)
#undef exp2
#define exp2(x)  __TGMATH_UNARY_REAL_ONLY(x,exp2)
#undef expm1
#define expm1(x)  __TGMATH_UNARY_REAL_ONLY(x,expm1)
#undef frexp
#define frexp(x,y)  __TGMATH_BINARY_FIRST_REAL_ONLY(x,y,frexp)
#undef ldexp
#define ldexp(x,y)  __TGMATH_BINARY_FIRST_REAL_ONLY(x,y,ldexp)
#undef log
#define log(x)  __TGMATH_UNARY_REAL_IMAG(x,log,clog)
#undef log10
#define log10(x)  __TGMATH_UNARY_REAL_ONLY(x,log10)
#undef log1p
#define log1p(x)  __TGMATH_UNARY_REAL_ONLY(x,log1p)
#undef logb
#define logb(x)  __TGMATH_UNARY_REAL_ONLY(x,logb)
#undef log2
#define log2(x)  __TGMATH_UNARY_REAL_ONLY(x,log2)

/* power functions */
#undef pow
#define pow(x,y)  __TGMATH_BINARY_REAL_IMAG(x,y,pow,cpow)
#undef sqrt
#define sqrt(x)  __TGMATH_UNARY_REAL_IMAG(x,sqrt,csqrt)
#undef hypot
#define hypot(x,y)  __TGMATH_BINARY_REAL_ONLY(x,y,hypot)
#undef cbrt
#define cbrt(x)  __TGMATH_UNARY_REAL_ONLY(x,cbrt)

/* nearest integer, absolute value, and remainder functions */
#undef ceil
#define ceil(x)  __TGMATH_UNARY_REAL_ONLY(x,ceil)
#undef fabs
#define fabs(x)  __TGMATH_UNARY_REAL_IMAG(x,fabs,cabs)
#undef floor
#define floor(x)  __TGMATH_UNARY_REAL_ONLY(x,floor)
#undef fmod
#define fmod(x,y)  __TGMATH_BINARY_REAL_ONLY(x,y,fmod)
#undef nearbyint
#define nearbyint(x)  __TGMATH_UNARY_REAL_ONLY(x,nearbyint)
#undef round
#define round(x)  __TGMATH_UNARY_REAL_ONLY(x,round)
#undef trunc
#define trunc(x)  __TGMATH_UNARY_REAL_ONLY(x,trunc)
#undef remquo
#define remquo(x,y,z)  __TGMATH_TERNARY_FIRST_SECOND_REAL_ONLY(x,y,z,remquo)
#undef lrint
#define lrint(x)  __TGMATH_UNARY_REAL_ONLY(x,lrint)
#undef llrint
#define llrint(x)  __TGMATH_UNARY_REAL_ONLY(x,llrint)
#undef lround
#define lround(x)  __TGMATH_UNARY_REAL_ONLY(x,lround)
#undef llround
#define llround(x)  __TGMATH_UNARY_REAL_ONLY(x,llround)
#undef copysign
#define copysign(x,y)  __TGMATH_BINARY_REAL_ONLY(x,y,copysign)
#undef erf
#define erf(x)  __TGMATH_UNARY_REAL_ONLY(x,erf)
#undef erfc
#define erfc(x)  __TGMATH_UNARY_REAL_ONLY(x,erfc)
#undef gamma
#define gamma(x)  __TGMATH_UNARY_REAL_ONLY(x,gamma)
#undef lgamma
#define lgamma(x)  __TGMATH_UNARY_REAL_ONLY(x,lgamma)
#undef rint
#define rint(x)  __TGMATH_UNARY_REAL_ONLY(x,rint)
#undef nextafter
#define nextafter(x,y)  __TGMATH_BINARY_REAL_ONLY(x,y,nextafter)
#undef nexttoward
#define nexttoward(x,y)  __TGMATH_BINARY_FIRST_REAL_ONLY(x,y,nexttoward)
#undef remainder
#define remainder(x,y)  __TGMATH_BINARY_REAL_ONLY(x,y,remainder)
#undef scalbn
#define scalbn(x,y)  __TGMATH_BINARY_FIRST_REAL_ONLY(x,y,scalbn)
#undef scalbln
#define scalbln(x,y)  __TGMATH_BINARY_FIRST_REAL_ONLY(x,y,scalbln)
#undef ilogb
#define ilogb(x)  __TGMATH_UNARY_REAL_ONLY(x,ilogb)
#undef fdim
#define fdim(x,y)  __TGMATH_BINARY_REAL_ONLY(x,y,fdim)
#undef fmax
#define fmax(x,y)  __TGMATH_BINARY_REAL_ONLY(x,y,fmax)
#undef fmin
#define fmin(x,y)  __TGMATH_BINARY_REAL_ONLY(x,y,fmin)
#undef fma
#define fma(x,y,z)  __TGMATH_TERNARY_REAL_ONLY(x,y,z,fma)

/* conjugates and projection */
#undef carg
#define carg(x)  __TGMATH_UNARY_IMAG_ONLY(x,carg)
#undef conj
#define conj(x)  __TGMATH_UNARY_IMAG_ONLY(x,conj)
#undef cproj
#define cproj(x)  __TGMATH_UNARY_IMAG_ONLY(x,cproj)

/* decomposing complex values */
#undef cimag
#define cimag(x)  __TGMATH_UNARY_IMAG_ONLY(x,cimag)
#undef creal
#define creal(x)  __TGMATH_UNARY_IMAG_ONLY(x,creal)

#endif /* _TGMATH_H */
