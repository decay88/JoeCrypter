#ifndef _MATH_H
#define _MATH_H

/* math.h - C99 standard header */

#if __POCC__ >= 500
#pragma once
#else
#define __tgeneric__(e1,e2,e3,f,d,ld,cf,cd,cld)  (__tgeneric__lost_in_space)
#endif

/* macros */
#if __POCC__ >= 500
#define HUGE_VAL   ((double)__INFINITY__)
#define HUGE_VALF  __INFINITY__
#define HUGE_VALL  ((long double)__INFINITY__)
#define INFINITY   __INFINITY__
#define NAN        __NAN__
#else /* __POCC__ < 500 */
#define HUGE_VAL   (1.0 / (1.0, 0.0))
#define HUGE_VALF  (1.0F / (1.0, 0.0F))
#define HUGE_VALL  (1.0L / (1.0, 0.0L))
#define INFINITY   (1.0F / (1.0, 0.0F))
#define NAN        (0.0 / (1.0, 0.0))
#endif /* __POCC__ < 500 */

#define FP_INFINITE   1
#define FP_NAN        2
#define FP_NORMAL     (-1)
#define FP_SUBNORMAL  (-2)
#define FP_ZERO       0

#define FP_ILOGB0    (-0x7fffffff - 1)
#define FP_ILOGBNAN  0x7fffffff

#define MATH_ERRNO        1
#define MATH_ERREXCEPT    2
#define math_errhandling  (MATH_ERRNO|MATH_ERREXCEPT)

#define _FP_LT  1
#define _FP_EQ  2
#define _FP_GT  4

/* non-standard common math constants */
#ifdef _USE_MATH_DEFINES
#ifndef _MATH_DEFINES_DEFINED
#define _MATH_DEFINES_DEFINED
#define M_E         2.7182818284590452354   /* e */
#define M_LOG2E     1.4426950408889634074   /* log2(e) */
#define M_LOG10E    0.43429448190325182765  /* log10(e) */
#define M_LN2       0.69314718055994530942  /* log(2) */
#define M_LN10      2.30258509299404568402  /* log(10) */
#define M_PI        3.14159265358979323846  /* pi */
#define M_PI_2      1.57079632679489661923  /* pi/2 */
#define M_PI_4      0.78539816339744830962  /* pi/4 */
#define M_1_PI      0.31830988618379067154  /* 1/pi */
#define M_2_PI      0.63661977236758134308  /* 2/pi */
#define M_2_SQRTPI  1.12837916709551257390  /* 2/sqrt(pi) */
#define M_SQRT2     1.41421356237309504880  /* sqrt(2) */
#define M_SQRT1_2   0.70710678118654752440  /* 1/sqrt(2) */
#endif /* _MATH_DEFINES_DEFINED */
#endif /* _USE_MATH_DEFINES */

/* type definitions */
#if __POCC_FLTEVAL__ == 1
typedef double float_t;
typedef double double_t;
#elif __POCC_FLTEVAL__ == 2
typedef long double float_t;
typedef long double double_t;
#else /* __POCC_FLTEVAL__ <= 0 */
typedef float float_t;
typedef double double_t;
#endif

/* helper functions */
extern int __cdecl __fpclass(double);
extern int __cdecl __fpclassf(float);
extern int __cdecl __fpclassl(long double);
extern int __cdecl __fpcomp(double, double);
extern int __cdecl __fpcompf(float, float);
extern int __cdecl __fpcompl(long double, long double);
extern int __cdecl __fpsign(double);
extern int __cdecl __fpsignf(float);
extern int __cdecl __fpsignl(long double);

#define isfinite(x)  (fpclassify(x) <= 0)
#define isinf(x)     (fpclassify(x) == FP_INFINITE)
#define isnan(x)     (fpclassify(x) == FP_NAN)
#define isnormal(x)  (fpclassify(x) == FP_NORMAL)

#define isgreater(x,y)  (_FPCOMP(x,y) & _FP_GT)
#define isgreaterequal(x,y)  (_FPCOMP(x,y) & (_FP_EQ|_FP_GT))
#define isless(x,y)  (_FPCOMP(x,y) & _FP_LT)
#define islessequal(x,y)  (_FPCOMP(x,y) & (_FP_LT|_FP_EQ))
#define islessgreater(x,y)  (_FPCOMP(x,y) & (_FP_LT|_FP_GT))
#define isunordered(x,y)  (_FPCOMP(x,y) == 0)

#define fpclassify(x)  __tgeneric__(x,,,__fpclassf,__fpclass,__fpclassl,,,)(x)
#define signbit(x)  __tgeneric__(x,,,__fpsignf,__fpsign,__fpsignl,,,)(x)
#define _FPCOMP(x,y)  __tgeneric__(x,y,,__fpcompf,__fpcomp,__fpcompl,,,)(x,y)

/* double declarations */
extern double __cdecl acos(double);
extern double __cdecl acosh(double);
extern double __cdecl asin(double);
extern double __cdecl asinh(double);
extern double __cdecl atan(double);
extern double __cdecl atan2(double, double);
extern double __cdecl atanh(double);
extern double __cdecl cbrt(double);
extern double __cdecl ceil(double);
extern double __cdecl copysign(double, double);
extern double __cdecl erf(double);
extern double __cdecl erfc(double);
extern double __cdecl exp(double);
extern double __cdecl exp2(double);
extern double __cdecl expm1(double);
extern double __cdecl fabs(double);
extern double __cdecl fdim(double, double);
extern double __cdecl floor(double);
extern double __cdecl fma(double, double, double);
extern double __cdecl fmax(double, double);
extern double __cdecl fmin(double, double);
extern double __cdecl fmod(double, double);
extern double __cdecl frexp(double, int *);
extern double __cdecl hypot(double, double);
extern int __cdecl ilogb(double);
extern double __cdecl ldexp(double, int);
extern double __cdecl lgamma(double);
extern long long __cdecl llrint(double);
extern long long __cdecl llround(double);
extern double __cdecl log1p(double);
extern double __cdecl logb(double);
extern long __cdecl lrint(double);
extern long __cdecl lround(double);
extern double __cdecl modf(double, double *);
extern double __cdecl nan(const char *);
extern double __cdecl nearbyint(double);
extern double __cdecl nextafter(double, double);
extern double __cdecl nexttoward(double, long double);
extern double __cdecl pow(double, double);
extern double __cdecl remainder(double, double);
extern double __cdecl remquo(double, double, int *);
extern double __cdecl rint(double);
extern double __cdecl round(double);
extern double __cdecl scalbn(double, int);
extern double __cdecl scalbln(double, long);
extern double __cdecl sqrt(double);
extern double __cdecl tan(double);
extern double __cdecl tanh(double);
extern double __cdecl tgamma(double);
extern double __cdecl trunc(double);

/* float declarations */
extern float __cdecl acosf(float);
extern float __cdecl acoshf(float);
extern float __cdecl asinf(float);
extern float __cdecl asinhf(float);
extern float __cdecl atanf(float);
extern float __cdecl atanhf(float);
extern float __cdecl atan2f(float, float);
extern float __cdecl cbrtf(float);
extern float __cdecl ceilf(float);
extern float __cdecl copysignf(float, float);
extern float __cdecl erff(float);
extern float __cdecl erfcf(float);
extern float __cdecl expf(float);
extern float __cdecl exp2f(float);
extern float __cdecl expm1f(float);
extern float __cdecl fabsf(float);
extern float __cdecl fdimf(float, float);
extern float __cdecl floorf(float);
extern float __cdecl fmaf(float, float, float);
extern float __cdecl fmaxf(float, float);
extern float __cdecl fminf(float, float);
extern float __cdecl fmodf(float, float);
extern float __cdecl frexpf(float, int *);
extern float __cdecl hypotf(float, float);
extern int __cdecl ilogbf(float);
extern float __cdecl ldexpf(float, int);
extern float __cdecl lgammaf(float);
extern long long __cdecl llrintf(float);
extern long long __cdecl llroundf(float);
extern float __cdecl log1pf(float);
extern float __cdecl logbf(float);
extern long __cdecl lrintf(float);
extern long __cdecl lroundf(float);
extern float __cdecl modff(float, float *);
extern float __cdecl nanf(const char *);
extern float __cdecl nearbyintf(float);
extern float __cdecl nextafterf(float, float);
extern float __cdecl nexttowardf(float, long double);
extern float __cdecl powf(float, float);
extern float __cdecl remainderf(float, float);
extern float __cdecl remquof(float, float, int *);
extern float __cdecl rintf(float);
extern float __cdecl roundf(float);
extern float __cdecl scalbnf(float, int);
extern float __cdecl scalblnf(float, long);
extern float __cdecl sqrtf(float);
extern float __cdecl tanf(float);
extern float __cdecl tanhf(float);
extern float __cdecl tgammaf(float);
extern float __cdecl truncf(float);

/* long double declarations */
extern long double __cdecl acosl(long double);
extern long double __cdecl acoshl(long double);
extern long double __cdecl asinl(long double);
extern long double __cdecl asinhl(long double);
extern long double __cdecl atanl(long double);
extern long double __cdecl atanhl(long double);
extern long double __cdecl atan2l(long double, long double);
extern long double __cdecl cbrtl(long double);
extern long double __cdecl ceill(long double);
extern long double __cdecl copysignl(long double, long double);
extern long double __cdecl erfl(long double);
extern long double __cdecl erfcl(long double);
extern long double __cdecl expl(long double);
extern long double __cdecl exp2l(long double);
extern long double __cdecl expm1l(long double);
extern long double __cdecl fabsl(long double);
extern long double __cdecl fdiml(long double, long double);
extern long double __cdecl floorl(long double);
extern long double __cdecl fmal(long double, long double, long double);
extern long double __cdecl fmaxl(long double, long double);
extern long double __cdecl fminl(long double, long double);
extern long double __cdecl fmodl(long double, long double);
extern long double __cdecl frexpl(long double, int *);
extern long double __cdecl hypotl(long double, long double);
extern int __cdecl ilogbl(long double);
extern long double __cdecl ldexpl(long double, int);
extern long double __cdecl lgammal(long double);
extern long long __cdecl llrintl(long double);
extern long long __cdecl llroundl(long double);
extern long double __cdecl log1pl(long double);
extern long double __cdecl logbl(long double);
extern long __cdecl lrintl(long double);
extern long __cdecl lroundl(long double);
extern long double __cdecl modfl(long double, long double *);
extern long double __cdecl nanl(const char *);
extern long double __cdecl nearbyintl(long double);
extern long double __cdecl nextafterl(long double, long double);
extern long double __cdecl nexttowardl(long double, long double);
extern long double __cdecl powl(long double, long double);
extern long double __cdecl remainderl(long double, long double);
extern long double __cdecl remquol(long double, long double, int *);
extern long double __cdecl rintl(long double);
extern long double __cdecl roundl(long double);
extern long double __cdecl scalbnl(long double, int);
extern long double __cdecl scalblnl(long double, long);
extern long double __cdecl sqrtl(long double);
extern long double __cdecl tanl(long double);
extern long double __cdecl tanhl(long double);
extern long double __cdecl tgammal(long double);
extern long double __cdecl truncl(long double);

extern double __cdecl cos(double);
extern double __cdecl cosh(double);
extern double __cdecl log(double);
extern double __cdecl log10(double);
extern double __cdecl log2(double);
extern double __cdecl sin(double);
extern double __cdecl sinh(double);

/* double macro overrides */
#if __POCC_TARGET__ != 3
#define cos(x)  __sin(x,1)
#define cosh(x)  __cosh(x,1)
#define log(x)  __log(x,0)
#define log10(x)  __log(x,1)
#define log2(x)  __log(x,2)
#define sin(x)  __sin(x,0)
#define sinh(x)  __sinh(x,1)
#endif /* __POCC_TARGET */

extern float __cdecl cosf(float);
extern float __cdecl coshf(float);
extern float __cdecl logf(float);
extern float __cdecl log10f(float);
extern float __cdecl log2f(float);
extern float __cdecl sinf(float);
extern float __cdecl sinhf(float);

/* float macro overrides */
#if __POCC_TARGET__ != 3
#define cosf(x)  __sinf(x,1)
#define coshf(x)  __coshf(x,1)
#define logf(x)  __logf(x,0)
#define log10f(x)  __logf(x,1)
#define log2f(x)  __logf(x,2)
#define sinf(x)  __sinf(x,0)
#define sinhf(x)  __sinhf(x,1)
#endif /* __POCC_TARGET */

extern long double __cdecl cosl(long double);
extern long double __cdecl coshl(long double);
extern long double __cdecl logl(long double);
extern long double __cdecl log10l(long double);
extern long double __cdecl log2l(long double);
extern long double __cdecl sinl(long double);
extern long double __cdecl sinhl(long double);

/* long double macro overrides */
#if __POCC_TARGET__ != 3
#define cosl(x)  __sinl(x,1)
#define coshl(x)  __coshl(x,1)
#define logl(x)  __logl(x,0)
#define log10l(x)  __logl(x,1)
#define log2l(x)  __logl(x,2)
#define sinl(x)  __sinl(x,0)
#define sinhl(x)  __sinhl(x,1)
#endif /* __POCC_TARGET */

/* double declarations */
extern double __cdecl __cosh(double, double);
extern double __cdecl __log(double, int);
extern double __cdecl __sin(double, unsigned int);
extern double __cdecl __sinh(double, double);

/* float declarations */
extern float __cdecl __coshf(float, float);
extern float __cdecl __logf(float, int);
extern float __cdecl __sinf(float, unsigned int);
extern float __cdecl __sinhf(float, float);

/* long double declarations */
extern long double __cdecl __coshl(long double, long double);
extern long double __cdecl __logl(long double, int);
extern long double __cdecl __sinl(long double, unsigned int);
extern long double __cdecl __sinhl(long double, long double);

#ifdef _MSC_EXTENSIONS
/* values for _exception type */
#define _DOMAIN  1
#define _SING  2
#define _OVERFLOW  3
#define _UNDERFLOW  4
#define _TLOSS  5
#define _PLOSS  6

/* compatibility names */
#ifdef __POCC__OLDNAMES
#define DOMAIN  _DOMAIN
#define SING  _SING
#define OVERFLOW  _OVERFLOW
#define UNDERFLOW  _UNDERFLOW
#define TLOSS  _TLOSS
#define PLOSS  _PLOSS
#endif /* __POCC__OLDNAMES */

/* passed to _matherr() when a fp exception is detected */
struct _exception {
    int type;
    const char *name;
    double arg1;
    double arg2;
    double retval;
};

extern int __cdecl _matherr(struct _exception *);
#endif /* _MSC_EXTENSIONS */

#endif /* _MATH_H */
