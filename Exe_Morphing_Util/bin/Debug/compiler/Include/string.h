#ifndef _STRING_H
#define _STRING_H

/* string.h - C99 standard header */

#if __POCC__ >= 500
#pragma once
#endif

#include <crtdef.h>

/* macros */
#ifndef NULL
#define NULL  ((void *)0)
#endif

/* type definitions */
#ifndef _SIZE_T_DEFINED
#define _SIZE_T_DEFINED
#if __POCC_TARGET__ == 3
typedef unsigned long long size_t;
#else
typedef unsigned int size_t;
#endif
#endif /* _SIZE_T_DEFINED */

/* declarations */
extern void * __cdecl memchr(const void *, int, size_t);
extern int __cdecl memcmp(const void *, const void *, size_t);
extern _CRTNOP void * __cdecl memcpy(void * restrict, const void * restrict, size_t);
extern _CRTNOP void * __cdecl memmove(void *, const void *, size_t);
extern _CRTNOP void * __cdecl memset(void *, int, size_t);
extern _CRTNOP char * __cdecl strcat(char * restrict, const char * restrict);
extern char * __cdecl strchr(const char *, int);
extern int __cdecl strcmp(const char *, const char *);
extern _CRTNOP char * __cdecl strcpy(char * restrict, const char * restrict);
extern size_t __cdecl strcspn(const char *, const char *);
extern size_t __cdecl strlen(const char *);
extern _CRTNOP char * __cdecl strncat(char * restrict, const char * restrict, size_t);
extern int __cdecl strncmp(const char *, const char *, size_t);
extern _CRTNOP char * __cdecl strncpy(char * restrict, const char * restrict, size_t);
extern char * __cdecl strpbrk(const char *, const char *);
extern char * __cdecl strrchr(const char *, int);
extern size_t __cdecl strspn(const char *, const char *);
extern char * __cdecl strstr(const char *, const char *);
extern char * __cdecl strtok(char * restrict, const char * restrict);
extern int __cdecl strcoll(const char *, const char *);
extern char * __cdecl strerror(int);
extern size_t __cdecl strxfrm(char * restrict, const char * restrict, size_t);

/* private extensions to standard C */
extern int __cdecl _memicmp(const void *, const void *, size_t);
extern char * __cdecl _strdup(const char *);
extern int __cdecl _stricmp(const char *, const char *);
extern _CRTNOP char * __cdecl _strlwr(char *);
extern char * __cdecl _strndup(const char *, size_t);
extern int __cdecl _strnicmp(const char *, const char *, size_t);
extern _CRTNOP char * __cdecl _strnset(char *, int, size_t);
extern _CRTNOP char * __cdecl _strrev(char *);
extern _CRTNOP char * __cdecl _strupr(char *);
extern void * __cdecl _memichr(const void *, int, size_t);
extern char * __cdecl _strichr(const char *, int);
extern char * __cdecl _stristr(const char *, const char *);
extern char * __cdecl _strrichr(const char *, int);

/* compatibility names */
#ifdef __POCC__OLDNAMES
extern int __cdecl memicmp(const void *, const void *, size_t);
extern char * __cdecl strdup(const char *);
extern int __cdecl stricmp(const char *, const char *);
extern _CRTNOP char * __cdecl strlwr(char *);
extern int __cdecl strnicmp(const char *, const char *, size_t);
extern _CRTNOP char * __cdecl strnset(char *, int, size_t);
extern _CRTNOP char * __cdecl strrev(char *);
extern _CRTNOP char * __cdecl strupr(char *);
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

/* declarations */
extern errno_t __cdecl memcpy_s(void * restrict, rsize_t, const void * restrict, rsize_t);
extern errno_t __cdecl memmove_s(void *, rsize_t, const void *, rsize_t);
#if __POCC_STDC_VERSION__ >= 201101L
extern errno_t __cdecl memset_s(void * restrict, rsize_t, int, rsize_t);
#endif /* __POCC_STDC_VERSION__ >= 201101L */
extern errno_t __cdecl strcpy_s(char * restrict, rsize_t, const char * restrict);
extern errno_t __cdecl strncpy_s(char * restrict, rsize_t, const char * restrict, rsize_t);
extern errno_t __cdecl strcat_s(char * restrict, rsize_t, const char * restrict);
extern errno_t __cdecl strncat_s(char * restrict, rsize_t, const char * restrict, rsize_t);
extern char * __cdecl strtok_s(char * restrict, rsize_t * restrict, const char * restrict, char ** restrict);
extern errno_t __cdecl strerror_s(char *, rsize_t, errno_t);
extern size_t __cdecl strerrorlen_s(errno_t);
extern size_t __cdecl strnlen_s(const char *, size_t);

#endif /* __STDC_WANT_LIB_EXT1__ */

/* dynamic allocation functions (TR24731-2) */
#if __STDC_WANT_LIB_EXT2__

#ifndef __POCC__OLDNAMES
extern char * __cdecl strdup(const char *);
#endif /* !__POCC__OLDNAMES */
extern char * __cdecl strndup(const char *, size_t);

#endif /* __STDC_WANT_LIB_EXT2__ */

#endif /* _STRING_H */
