#ifndef _SYS_UTIME_H
#define _SYS_UTIME_H

/* sys/utime.h - private header for file timestamp definitions */

#if __POCC__ >= 500
#pragma once
#endif

/* type definitions */
#ifndef _TIME_T_DEFINED
#define _TIME_T_DEFINED
typedef unsigned long time_t;
#endif

#ifndef _WCHAR_T_DEFINED
#define _WCHAR_T_DEFINED
typedef unsigned short wchar_t;
#endif

#ifndef _UTIMBUF_DEFINED
#define _UTIMBUF_DEFINED
struct _utimbuf {
    time_t actime;
    time_t modtime;
};

#ifdef __POCC__OLDNAMES
struct utimbuf {
    time_t actime;
    time_t modtime;
};
#endif /* __POCC__OLDNAMES */
#endif /* _UTIMBUF_DEFINED */

/* declarations */
int __cdecl _utime(const char *, struct _utimbuf *);
int __cdecl _futime(int, struct _utimbuf *);
int __cdecl _wutime(const wchar_t *, struct _utimbuf *);

/* compatibility names */
#ifdef __POCC__OLDNAMES
int __cdecl utime(const char *, struct utimbuf *);
#endif /* __POCC__OLDNAMES */

#endif /* _SYS_UTIME_H */
