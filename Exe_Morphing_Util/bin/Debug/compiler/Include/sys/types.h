#ifndef _SYS_TYPES_H
#define _SYS_TYPES_H

/* sys/types.h - private header for system types */

#if __POCC__ >= 500
#pragma once
#endif

/* type definitions */
#ifndef _CLOCK_T_DEFINED
#define _CLOCK_T_DEFINED
typedef unsigned int clock_t;
#endif /* _CLOCK_T_DEFINED */

#ifndef _TIME_T_DEFINED
#define _TIME_T_DEFINED
typedef unsigned long time_t;
#endif /* _TIME_T_DEFINED */

#ifndef _SUSECONDS_T_DEFINED
#define _SUSECONDS_T_DEFINED
typedef signed long _suseconds_t;
#ifdef __POCC__OLDNAMES
typedef signed long suseconds_t;
#endif /* __POCC__OLDNAMES */
#endif /* _SUSECONDS_T_DEFINED */

#ifndef _SIZE_T_DEFINED
#define _SIZE_T_DEFINED
#if __POCC_TARGET__ == 3
typedef unsigned long long size_t;
#else
typedef unsigned int size_t;
#endif /* __POCC_TARGET__ */
#endif /* _SIZE_T_DEFINED */

#ifndef _SSIZE_T_DEFINED
#define _SSIZE_T_DEFINED
#if __POCC_TARGET__ == 3
typedef long long _ssize_t;
#else
typedef int _ssize_t;
#endif /* __POCC_TARGET */
#ifdef __POCC__OLDNAMES
#if __POCC_TARGET__ == 3
typedef long long ssize_t;
#else
typedef long ssize_t;
#endif /* __POCC_TARGET */
#endif /* __POCC__OLDNAMES */
#endif /* SSIZE_T_DEFINED */

#ifndef _DEV_T_DEFINED
#define _DEV_T_DEFINED
typedef unsigned int _dev_t;
#ifdef __POCC__OLDNAMES
typedef unsigned int dev_t;
#endif /* __POCC__OLDNAMES */
#endif /* _DEV_T_DEFINED */

#ifndef _INO_T_DEFINED
#define _INO_T_DEFINED
typedef unsigned short _ino_t;
#ifdef __POCC__OLDNAMES
typedef unsigned short ino_t;
#endif /* __POCC__OLDNAMES */
#endif /* _INO_T_DEFINED */

#ifndef _OFF_T_DEFINED
#define _OFF_T_DEFINED
#if __POCC_TARGET__ == 3
typedef long long _off_t;
#else
typedef long _off_t;
#endif /* __POCC_TARGET */
#ifdef __POCC__OLDNAMES
#if __POCC_TARGET__ == 3
typedef long long off_t;
#else
typedef long off_t;
#endif /* __POCC_TARGET */
#endif /* __POCC__OLDNAMES */
#endif /* _OFF_T_DEFINED */

#ifndef _PID_T_DEFINED
#define _PID_T_DEFINED
#if __POCC_TARGET__ == 3
typedef long long _pid_t;
#else
typedef int _pid_t;
#endif /* __POCC_TARGET */
#ifdef __POCC__OLDNAMES
#if __POCC_TARGET__ == 3
typedef long long pid_t;
#else
typedef int pid_t;
#endif /* __POCC_TARGET */
#endif /* __POCC__OLDNAMES */
#endif /* _PID_T_DEFINED */

#endif /* _SYS_TYPES_H */
