#ifndef _COMPLEX_H
#define _COMPLEX_H

/* complex.h - C99 standard header */

#if __POCC__ >= 500
#pragma once
#endif

/* macros */
#define complex  _Complex
#define _Complex_I  ((const float _Complex)__I__)
#define I  _Complex_I

#if __POCC_STDC_VERSION__ >= 201101L
#define CMPLX(x,y)   ((double complex)((double)(x) + __I__ * (double)(y)))
#define CMPLXF(x,y)  ((float complex)((float)(x) + __I__ * (float)(y)))
#define CMPLXL(x,y)  ((long double complex)((long double)(x) + __I__ * (long double)(y)))
#endif /* __POCC_STDC_VERSION__ >= 201101L */

#if (__POCC_TARGET__ == 1 || __POCC_TARGET__ == 3)

/* double declarations */
extern double __cdecl cabs(double complex);
extern double complex __cdecl cacos(double complex);
extern double complex __cdecl cacosh(double complex);
extern double __cdecl carg(double complex);
extern double complex __cdecl casin(double complex);
extern double complex __cdecl casinh(double complex);
extern double complex __cdecl catan(double complex);
extern double complex __cdecl catanh(double complex);
extern double complex __cdecl ccos(double complex);
extern double complex __cdecl ccosh(double complex);
extern double complex __cdecl cexp(double complex);
extern double __cdecl cimag(double complex);
extern double complex __cdecl clog(double complex);
extern double complex __cdecl conj(double complex);
extern double complex __cdecl cpow(double complex, double complex);
extern double complex __cdecl cproj(double complex);
extern double __cdecl creal(double complex);
extern double complex __cdecl csin(double complex);
extern double complex __cdecl csinh(double complex);
extern double complex __cdecl csqrt(double complex);
extern double complex __cdecl ctan(double complex);
extern double complex __cdecl ctanh(double complex);

/* float declarations */
extern float __cdecl cabsf(float complex);
extern float complex __cdecl cacosf(float complex);
extern float complex __cdecl cacoshf(float complex);
extern float __cdecl cargf(float complex);
extern float complex __cdecl casinf(float complex);
extern float complex __cdecl casinhf(float complex);
extern float complex __cdecl catanf(float complex);
extern float complex __cdecl catanhf(float complex);
extern float complex __cdecl ccosf(float complex);
extern float complex __cdecl ccoshf(float complex);
extern float complex __cdecl cexpf(float complex);
extern float __cdecl cimagf(float complex);
extern float complex __cdecl clogf(float complex);
extern float complex __cdecl conjf(float complex);
extern float complex __cdecl cpowf(float complex, float complex);
extern float complex __cdecl cprojf(float complex);
extern float __cdecl crealf(float complex);
extern float complex __cdecl csinf(float complex);
extern float complex __cdecl csinhf(float complex);
extern float complex __cdecl csqrtf(float complex);
extern float complex __cdecl ctanf(float complex);
extern float complex __cdecl ctanhf(float complex);

/* long double declarations */
extern long double __cdecl cabsl(long double complex);
extern long double complex __cdecl cacosl(long double complex);
extern long double complex __cdecl cacoshl(long double complex);
extern long double __cdecl cargl(long double complex);
extern long double complex __cdecl casinl(long double complex);
extern long double complex __cdecl casinhl(long double complex);
extern long double complex __cdecl catanl(long double complex);
extern long double complex __cdecl catanhl(long double complex);
extern long double complex __cdecl ccosl(long double complex);
extern long double complex __cdecl ccoshl(long double complex);
extern long double complex __cdecl cexpl(long double complex);
extern long double __cdecl cimagl(long double complex);
extern long double complex __cdecl clogl(long double complex);
extern long double complex __cdecl conjl(long double complex);
extern long double complex __cdecl cpowl(long double complex, long double complex);
extern long double complex __cdecl cprojl(long double complex);
extern long double __cdecl creall(long double complex);
extern long double complex __cdecl csinl(long double complex);
extern long double complex __cdecl csinhl(long double complex);
extern long double complex __cdecl csqrtl(long double complex);
extern long double complex __cdecl ctanl(long double complex);
extern long double complex __cdecl ctanhl(long double complex);

#endif /* (__POCC_TARGET__ == 1 || __POCC_TARGET__ == 3) */

#endif /* _COMPLEX_H */
