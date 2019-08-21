#ifndef _WCHAR_H
#define _WCHAR_H

/* wchar.h - C99 standard header */

#if __POCC__ >= 500
#pragma once
#endif

#include <crtdef.h>

/* macros */
#ifndef NULL
#define NULL  ((void *)0)
#endif

#define WCHAR_MIN  0
#define WCHAR_MAX  0xffff

#define WEOF  ((wint_t)(-1))

/* type definitions */
#ifndef _MBSTATE_T_DEFINED
#define _MBSTATE_T_DEFINED
typedef struct mbstate_t {
    unsigned long wchar;
    unsigned short rsrv, state;
} mbstate_t;
#endif /* _MBSTATE_T_DEFINED */

#ifndef _SIZE_T_DEFINED
#define _SIZE_T_DEFINED
#if __POCC_TARGET__ == 3
typedef unsigned long long size_t;
#else
typedef unsigned int size_t;
#endif
#endif /* _SIZE_T_DEFINED */

#ifndef _VA_LIST_DEFINED
#define _VA_LIST_DEFINED
typedef _CRTVAP char *va_list;
#endif /* _VA_LIST_DEFINED */

#ifndef _WCHAR_T_DEFINED
#define _WCHAR_T_DEFINED
typedef unsigned short wchar_t;
#endif /* _WCHAR_T_DEFINED */

#ifndef _WINT_T_DEFINED
#define _WINT_T_DEFINED
typedef unsigned short wint_t;
#endif /* _WINT_T_DEFINED */

struct tm;
struct FILE;

/* formatted wide-character input/output functions */
extern _CRTCHK(printf,2,3) int __cdecl fwprintf(struct FILE * restrict, const wchar_t * restrict, ...);
extern _CRTCHK(scanf,2,3) int __cdecl fwscanf(struct FILE * restrict, const wchar_t * restrict, ...);
extern _CRTCHK(scanf,2,3) int __cdecl swscanf(const wchar_t * restrict, const wchar_t * restrict, ...);
extern int __cdecl vfwprintf(struct FILE * restrict, const wchar_t * restrict, va_list);
extern _CRTNOP int __cdecl vwprintf(const wchar_t * restrict, va_list);
extern _CRTCHK(printf,1,2) _CRTNOP int __cdecl wprintf(const wchar_t * restrict, ...);
extern _CRTCHK(scanf,1,2) int __cdecl wscanf(const wchar_t * restrict, ...);
extern _CRTCHK(printf,3,4) int __cdecl swprintf(wchar_t * restrict, size_t, const wchar_t * restrict, ...);
extern int __cdecl vfwscanf(struct FILE * restrict, const wchar_t * restrict, va_list);
extern int __cdecl vswprintf(wchar_t * restrict, size_t, const wchar_t * restrict, va_list);
extern int __cdecl vswscanf(const wchar_t * restrict, const wchar_t * restrict, va_list);
extern int __cdecl vwscanf(const wchar_t * restrict, va_list);

/* wide character input/output functions */
extern wint_t __cdecl fgetwc(struct FILE *);
extern wchar_t * __cdecl fgetws(wchar_t * restrict, int, struct FILE * restrict);
extern wint_t __cdecl fputwc(wchar_t, struct FILE *);
extern int __cdecl fputws(const wchar_t * restrict, struct FILE * restrict);
extern wint_t __cdecl getwchar(void);
extern _CRTNOP wint_t __cdecl putwchar(wchar_t);
extern wint_t __cdecl ungetwc(wint_t, struct FILE *);
extern int __cdecl fwide(struct FILE *, int);
extern wint_t __cdecl getwc(struct FILE *);
extern wint_t __cdecl putwc(wchar_t, struct FILE *);

/* general wide-string utilities */
extern double __cdecl wcstod(const wchar_t * restrict, wchar_t ** restrict);
extern long __cdecl wcstol(const wchar_t * restrict, wchar_t ** restrict, int);
extern unsigned long __cdecl wcstoul(const wchar_t * restrict, wchar_t ** restrict, int);
extern _CRTNOP wchar_t * __cdecl wcscpy(wchar_t * restrict, const wchar_t * restrict);
extern wchar_t * __cdecl wcsncpy(wchar_t * restrict, const wchar_t * restrict, size_t);
extern wchar_t * __cdecl wcscat(wchar_t * restrict, const wchar_t * restrict);
extern wchar_t * __cdecl wcsncat(wchar_t * restrict, const wchar_t * restrict, size_t);
extern int __cdecl wcscmp(const wchar_t *, const wchar_t *);
extern int __cdecl wcsncmp(const wchar_t *, const wchar_t *, size_t);
extern wchar_t * __cdecl wcschr(const wchar_t *, wchar_t);
extern size_t __cdecl wcscspn(const wchar_t *, const wchar_t *);
extern size_t __cdecl wcslen(const wchar_t *);
extern wchar_t * __cdecl wcspbrk(const wchar_t *, const wchar_t *);
extern wchar_t * __cdecl wcsrchr(const wchar_t *, wchar_t);
extern size_t __cdecl wcsspn(const wchar_t *, const wchar_t *);
extern wchar_t * __cdecl wcsstr(const wchar_t *, const wchar_t *);
extern wchar_t * __cdecl wcstok(wchar_t * restrict, const wchar_t * restrict, wchar_t ** restrict);

extern float __cdecl wcstof(const wchar_t * restrict, wchar_t ** restrict);
extern long double __cdecl wcstold(const wchar_t * restrict, wchar_t ** restrict);
extern long long __cdecl wcstoll(const wchar_t * restrict, wchar_t ** restrict, int);
extern unsigned long long __cdecl wcstoull(const wchar_t * restrict, wchar_t ** restrict, int);
extern int __cdecl wcscoll(const wchar_t *, const wchar_t *);
extern size_t __cdecl wcsxfrm(wchar_t * restrict, const wchar_t * restrict, size_t);

extern wchar_t * __cdecl wmemchr(const wchar_t *, wchar_t, size_t);
extern int __cdecl wmemcmp(const wchar_t *, const wchar_t *, size_t);
extern _CRTNOP wchar_t * __cdecl wmemcpy(wchar_t * restrict, const wchar_t * restrict, size_t);
extern _CRTNOP wchar_t * __cdecl wmemmove(wchar_t *, const wchar_t *, size_t);
extern _CRTNOP wchar_t * __cdecl wmemset(wchar_t *, wchar_t, size_t);

/* wide-character time conversion functions */
extern size_t __cdecl wcsftime(wchar_t * restrict, size_t, const wchar_t * restrict, const struct tm * restrict);

/* extended multibyte and wide-character conversion utilities */
extern wint_t __cdecl btowc(int);
extern int __cdecl wctob(wint_t);
extern int __cdecl mbsinit(const mbstate_t *);
extern size_t __cdecl mbrlen(const char * restrict, size_t, mbstate_t * restrict);
extern size_t __cdecl mbrtowc(wchar_t * restrict, const char * restrict, size_t, mbstate_t * restrict);
extern size_t __cdecl wcrtomb(char * restrict, wchar_t, mbstate_t * restrict);
extern size_t __cdecl mbsrtowcs(wchar_t * restrict, const char ** restrict, size_t, mbstate_t * restrict);
extern size_t __cdecl wcsrtombs(char * restrict, const wchar_t ** restrict, size_t, mbstate_t * restrict);

/* private extensions to standard C */
extern wchar_t * __cdecl _itow(int, wchar_t *, int);
extern wchar_t * __cdecl _ltow(long, wchar_t *, int);
extern wchar_t * __cdecl _ultow(unsigned long, wchar_t *, int);
extern _CRTCHK(printf,3,4) int __cdecl _snwprintf(wchar_t * restrict, size_t, const wchar_t * restrict, ...);
extern int __cdecl _vsnwprintf(wchar_t * restrict, size_t, const wchar_t * restrict, va_list);
extern int __cdecl _wcsicmp(const wchar_t *, const wchar_t *);
extern int __cdecl _wcsnicmp(const wchar_t *, const wchar_t *, size_t);
extern wchar_t * __cdecl _wcsdup(const wchar_t *);
extern wchar_t * __cdecl _wcsupr(wchar_t *);
extern wchar_t * __cdecl _wcslwr(wchar_t *);
extern wchar_t * __cdecl _wcsndup(const wchar_t *, size_t);
extern wchar_t * __cdecl _wcsnset(wchar_t *, wchar_t, size_t);
extern wchar_t * __cdecl _wcsrev(wchar_t *);
extern long __cdecl _wtol(const wchar_t *);
extern long long __cdecl _wtoll(const wchar_t *);
extern wchar_t * __cdecl _wcsdate(wchar_t *);
extern wchar_t * __cdecl _wcserror(int);
extern wchar_t * __cdecl _wcsichr(const wchar_t *, wchar_t);
extern wchar_t * __cdecl _wcsistr(const wchar_t *, const wchar_t *);
extern wchar_t * __cdecl _wcsrichr(const wchar_t *, wchar_t);
extern wchar_t * __cdecl _wcstime(wchar_t *);
extern wchar_t * __cdecl _wcstok_ms(wchar_t * restrict, const wchar_t * restrict);  /* 06-03-28 */
extern wchar_t * __cdecl _wmemichr(const wchar_t *, wchar_t, size_t);
extern int __cdecl _wmemicmp(const wchar_t *, const wchar_t *, size_t);
extern int __cdecl _wtoi(const wchar_t *);

/* internal stuff */
extern wint_t __cdecl __btowc(int);
extern int __cdecl __wctob(wint_t);
extern double __cdecl __wcstod(const wchar_t *, wchar_t **, long);
extern float __cdecl __wcstof(const wchar_t *, wchar_t **, long);
extern long double __cdecl __wcstold(const wchar_t *, wchar_t **, long);
extern unsigned long __cdecl __wcstoul(const wchar_t *, wchar_t **, int);
extern unsigned long long __cdecl __wcstoull(const wchar_t *, wchar_t **, int);

/* macro overrides */
#define btowc(c)  __btowc(c)
#define wcstod(nptr,endptr)  __wcstod(nptr,endptr,0)
#define wcstoul(nptr,endptr,base)  __wcstoul(nptr,endptr,base)
#define wcstof(nptr,endptr)  __wcstof(nptr,endptr,0)
#define wcstold(nptr,endptr)  __wcstold(nptr,endptr,0)
#define wctob(wc)  __wctob(wc)
#define _wtoi(s)  (int)__wcstoul(s,0,10)
#define _wtol(s)  (long)__wcstoul(s,0,10)
#define _wtoll(s)  (long long)__wcstoull(s,0,10)

/* compatibility names */
#ifdef __POCC__OLDNAMES
extern int __cdecl wcsicmp(const wchar_t *, const wchar_t *);
extern int __cdecl wcsnicmp(const wchar_t *, const wchar_t *, size_t);
extern wchar_t * __cdecl wcsdup(const wchar_t *);
extern wchar_t * __cdecl wcsupr(wchar_t *);
extern wchar_t * __cdecl wcslwr(wchar_t *);
extern wchar_t * __cdecl wcsnset(wchar_t *, wchar_t, size_t);
extern wchar_t * __cdecl wcsrev(wchar_t *);
#endif /* __POCC__OLDNAMES */

/* bounds-checking interfaces (TR24731-1, C11 annex K) */
#if __STDC_WANT_LIB_EXT1__

#ifndef _ERRNO_T_DEFINED
#define _ERRNO_T_DEFINED
typedef int errno_t;
#endif /* _ERRNO_T_DEFINED */

#ifndef _RSIZE_T_DEFINED
#define _RSIZE_T_DEFINED
#if __POCC_TARGET__ == 3
typedef unsigned long long rsize_t;
#else
typedef unsigned int rsize_t;
#endif
#endif /* _RSIZE_T_DEFINED */

/* formatted wide-character input/output functions */
extern _CRTCHK(printf,2,3) int __cdecl fwprintf_s(struct FILE * restrict, const wchar_t * restrict, ...);
extern _CRTCHK(scanf_s,2,3) int __cdecl fwscanf_s(struct FILE * restrict, const wchar_t * restrict, ...);
extern _CRTCHK(printf,3,4) int __cdecl snwprintf_s(wchar_t * restrict, rsize_t, const wchar_t * restrict, ...);
extern _CRTCHK(printf,3,4) int __cdecl swprintf_s(wchar_t * restrict, rsize_t, const wchar_t * restrict, ...);
extern _CRTCHK(scanf_s,2,3) int __cdecl swscanf_s(const wchar_t * restrict, const wchar_t * restrict, ...);
extern int __cdecl vfwprintf_s(struct FILE * restrict, const wchar_t * restrict, va_list);
extern int __cdecl vfwscanf_s(struct FILE * restrict, const wchar_t * restrict, va_list);
extern int __cdecl vsnwprintf_s(wchar_t * restrict, rsize_t, const wchar_t * restrict, va_list);
extern int __cdecl vswprintf_s(wchar_t * restrict, rsize_t, const wchar_t * restrict, va_list);
extern int __cdecl vswscanf_s(const wchar_t * restrict, const wchar_t * restrict, va_list);
extern int __cdecl vwprintf_s(const wchar_t * restrict, va_list);
extern int __cdecl vwscanf_s(const wchar_t * restrict, va_list);
extern _CRTCHK(printf,1,2) int __cdecl wprintf_s(const wchar_t * restrict, ...);
extern _CRTCHK(scanf_s,1,2) int __cdecl wscanf_s(const wchar_t * restrict, ...);

/* general wide-string utilities */
extern errno_t __cdecl wcscpy_s(wchar_t * restrict, rsize_t, const wchar_t * restrict);
extern errno_t __cdecl wcsncpy_s(wchar_t * restrict, rsize_t, const wchar_t * restrict, rsize_t);
extern errno_t __cdecl wmemcpy_s(wchar_t * restrict, rsize_t, const wchar_t * restrict, rsize_t);
extern errno_t __cdecl wmemmove_s(wchar_t *, rsize_t, const wchar_t *, rsize_t);
extern errno_t __cdecl wcscat_s(wchar_t * restrict, rsize_t, const wchar_t * restrict);
extern errno_t __cdecl wcsncat_s(wchar_t * restrict, rsize_t, const wchar_t * restrict, rsize_t);
extern wchar_t * __cdecl wcstok_s(wchar_t * restrict, rsize_t * restrict, const wchar_t * restrict, wchar_t ** restrict);
extern size_t __cdecl wcsnlen_s(const wchar_t *, size_t);

/* extended multibyte and wide-character conversion utilities */
extern errno_t __cdecl wcrtomb_s(size_t * restrict, char * restrict, rsize_t, wchar_t, mbstate_t * restrict);
extern errno_t __cdecl mbsrtowcs_s(size_t * restrict, wchar_t * restrict, rsize_t, const char ** restrict, rsize_t, mbstate_t * restrict);
extern errno_t __cdecl wcsrtombs_s(size_t * restrict, char * restrict, rsize_t, const wchar_t ** restrict, rsize_t, mbstate_t * restrict);

#endif /* __STDC_WANT_LIB_EXT1__ */

/* dynamic allocation functions (TR24731-2) */
#if __STDC_WANT_LIB_EXT2__

#ifndef _SSIZE_T_DEFINED
#define _SSIZE_T_DEFINED
#if __POCC_TARGET__ == 3
typedef long long _ssize_t;
#else
typedef int _ssize_t;
#endif /* __POCC_TARGET */
#if __POCC_TARGET__ == 3
typedef long long ssize_t;
#else
typedef long ssize_t;
#endif /* __POCC_TARGET */
#else /* SSIZE_T_DEFINED */
#ifndef __POCC__OLDNAMES
#if __POCC_TARGET__ == 3
typedef long long ssize_t;
#else
typedef long ssize_t;
#endif /* __POCC_TARGET */
#endif /* __POCC__OLDNAMES */
#endif /* SSIZE_T_DEFINED */

/* FILE * __cdecl open_wmemstream(wchar_t **, size_t *); */

extern _CRTCHK(printf,2,3) int __cdecl aswprintf(wchar_t ** restrict, const wchar_t * restrict, ...);
extern int __cdecl vaswprintf(wchar_t ** restrict, const wchar_t * restrict, va_list);

extern ssize_t __cdecl getwdelim(wchar_t ** restrict, size_t * restrict, wint_t, FILE *);
extern ssize_t __cdecl getwline(wchar_t **, size_t *, FILE *);

#endif /* __STDC_WANT_LIB_EXT2__ */

#endif /* _WCHAR_H */
