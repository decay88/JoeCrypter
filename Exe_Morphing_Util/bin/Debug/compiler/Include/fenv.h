#ifndef _FENV_H
#define _FENV_H

/* fenv.h - C99 standard header; TC1 changes added */

#if __POCC__ >= 500
#pragma once
#endif

#include <crtdef.h>

typedef unsigned long fexcept_t;

typedef struct fenv_t {
    fexcept_t control, status, reserved[5];
} fenv_t;

/* macros */
#define FE_TONEAREST   0x00
#define FE_DOWNWARD    0x01
#define FE_UPWARD      0x02
#define FE_TOWARDZERO  0x03

#define FE_INVALID     0x01
#define FE_DIVBYZERO   0x04
#define FE_OVERFLOW    0x08
#define FE_UNDERFLOW   0x10
#define FE_INEXACT     0x20
#define FE_ALL_EXCEPT  (FE_INVALID|FE_DIVBYZERO|FE_OVERFLOW|FE_UNDERFLOW|FE_INEXACT)

#define FE_DFL_ENV  (&__dfl_fenv)

/* floating-point exception handling */
extern int __cdecl feclearexcept(int);  /* return type changed to int in TC1 */
extern int __cdecl fegetexceptflag(fexcept_t *, int);  /* return type changed to int in TC1 */
extern int __cdecl feraiseexcept(int);  /* return type changed to int in TC1 */
extern int __cdecl fesetexceptflag(const fexcept_t *, int);  /* return type changed to int in TC1 */
extern int __cdecl fetestexcept(int);

/* rounding control */
extern int __cdecl fegetround(void);
extern int __cdecl fesetround(int);

/* floating-point environment */
extern int __cdecl fegetenv(fenv_t *);  /* return type changed to int in TC1 */
extern int __cdecl fesetenv(const fenv_t *);  /* return type changed to int in TC1 */
extern int __cdecl feupdateenv(const fenv_t *);  /* return type changed to int in TC1 */
extern int __cdecl feholdexcept(fenv_t *);

/* data declarations */
extern _CRTIMP const fenv_t __dfl_fenv;
extern _CRTIMP fenv_t __fenv;

#endif /* _FENV_H */

