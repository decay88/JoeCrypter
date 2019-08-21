#ifndef _SYS_TIME_H
#define _SYS_TIME_H

/* sys/time.h - private header for time definitions */

#if __POCC__ >= 500
#pragma once
#endif

/* type definitions */
#ifndef _TIME_T_DEFINED
#define _TIME_T_DEFINED
typedef unsigned long time_t;
#endif

#ifndef _SUSECONDS_T_DEFINED
#define _SUSECONDS_T_DEFINED
typedef signed long _suseconds_t;
#ifdef __POCC__OLDNAMES
typedef signed long suseconds_t;
#endif /* __POCC__OLDNAMES */
#endif /* _SUSECONDS_T_DEFINED */

#ifndef _TIMEVAL_DEFINED
#define _TIMEVAL_DEFINED
struct _timeval {
    time_t tv_sec;
    _suseconds_t tv_usec;
};

#if defined(_WINSOCK_H_TIMEVAL) && defined(__POCC__OLDNAMES)
#error please include <sys/time.h> before <winsock.h> or <winsock2.h>
#endif /* _WINSOCK_H_TIMEVAL && __POCC__OLDNAMES */

#ifdef __POCC__OLDNAMES
struct timeval {
    time_t tv_sec;
    suseconds_t tv_usec;
};
#endif /* __POCC__OLDNAMES */
#endif /* _TIMEVAL_DEFINED */

/* declarations */
int __cdecl _gettimeofday(struct _timeval * restrict, void * restrict);

/* compatibility names */
#ifdef __POCC__OLDNAMES
int __cdecl gettimeofday(struct timeval * restrict, void * restrict);
#endif /* __POCC__OLDNAMES */

#endif /* _SYS_TIME_H */
