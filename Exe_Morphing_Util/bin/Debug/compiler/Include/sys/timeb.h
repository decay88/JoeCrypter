#ifndef _SYS_TIMEB_H
#define _SYS_TIMEB_H

/* sys/timeb.h - private header for _ftime() definitions */

#if __POCC__ >= 500
#pragma once
#endif

/* type definitions */
#ifndef _TIME_T_DEFINED
#define _TIME_T_DEFINED
typedef unsigned long time_t;
#endif

#ifndef _TIMEB_DEFINED
#define _TIMEB_DEFINED
struct _timeb {
    time_t time;
    unsigned short millitm;
    short timezone;
    short dstflag;
};

#ifdef __POCC__OLDNAMES
struct timeb {
    time_t time;
    unsigned short millitm;
    short timezone;
    short dstflag;
};
#endif /* __POCC__OLDNAMES */
#endif /* _TIMEB_DEFINED */

/* declarations */
void __cdecl _ftime(struct _timeb *);

/* compatibility names */
#ifdef __POCC__OLDNAMES
void __cdecl ftime(struct timeb *);
#endif /* __POCC__OLDNAMES */

#endif /* _SYS_TIMEB_H */
