#ifndef _STDDEF_H
#define _STDDEF_H

/* stddef.h - C99 standard header */

#if __POCC__ >= 500
#pragma once
#endif

/* macros */
#ifndef NULL
#define NULL  ((void *)0)
#endif

#ifndef offsetof
#define offsetof(ty,m)  ((size_t)&(((ty*)0)->m))
#endif

/* type definitions */
#ifndef _PTRDIFF_T_DEFINED
#define _PTRDIFF_T_DEFINED
#if __POCC_TARGET__ == 3
typedef long long ptrdiff_t;
#else
typedef int ptrdiff_t;
#endif
#endif /* _PTRDIFF_T_DEFINED */

#ifndef _SIZE_T_DEFINED
#define _SIZE_T_DEFINED
#if __POCC_TARGET__ == 3
typedef unsigned long long size_t;
#else
typedef unsigned int size_t;
#endif
#endif /* _SIZE_T_DEFINED */

#if __POCC_STDC_VERSION__ >= 201101L
#pragma warn(push)
#pragma warn(disable:2225)  /* type padded, so there */
typedef union __declspec(align(16)) { long double d; long long n; void *p; void (*f)(void); } max_align_t;
#pragma warn(pop)
#endif /* __POCC_STDC_VERSION__ >= 201101L */

#ifndef _WCHAR_T_DEFINED
#define _WCHAR_T_DEFINED
typedef unsigned short wchar_t;
#endif /* _WCHAR_T_DEFINED */

/* bounds-checking interfaces (TR24731-1, C11 annex K) */
#if __STDC_WANT_LIB_EXT1__

#ifndef _RSIZE_T_DEFINED
#define _RSIZE_T_DEFINED
#if __POCC_TARGET__ == 3
typedef unsigned long long rsize_t;
#else
typedef unsigned int rsize_t;
#endif
#endif /* _RSIZE_T_DEFINED */

#endif /* __STDC_WANT_LIB_EXT1__ */

#endif /* _STDDEF_H */
