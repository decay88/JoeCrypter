#ifndef _DIRECT_H
#define _DIRECT_H

/* direct.h - private header for directory handling */

#if __POCC__ >= 500
#pragma once
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

#ifndef _WCHAR_T_DEFINED
#define _WCHAR_T_DEFINED
typedef unsigned short wchar_t;
#endif

/* declarations */
extern int __cdecl _chdir(const char *);
extern int __cdecl _chdrive(int);
extern char * __cdecl _getcwd(char *, size_t);
extern wchar_t * __cdecl _wgetcwd(wchar_t *, size_t);
extern int __cdecl _getdrive(void);
extern int __cdecl _mkdir(const char *);
extern int __cdecl _rmdir(const char *);
extern int __cdecl _wchdir(const wchar_t *);
extern int __cdecl _wmkdir(const wchar_t *);
extern int __cdecl _wrmdir(const wchar_t *);

/* compatibility names */
#ifdef __POCC__OLDNAMES
extern int __cdecl chdir(const char *);
extern char * __cdecl getcwd(char *, size_t);
extern int __cdecl mkdir(const char *);
extern int __cdecl rmdir(const char *);
#endif /* __POCC__OLDNAMES */

#endif /* _DIRECT_H */
