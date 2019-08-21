#ifndef _FTW_H
#define _FTW_H

/* ftw.h - private header for file tree traversal */

#if __POCC__ >= 500
#pragma once
#endif

#include <sys/stat.h>

/* classification */
#define _FTW_NS  0  /* unknown type; stat() failed */
#define _FTW_F  1   /* file */
#define _FTW_D  2   /* directory */

/* declarations */
extern int __cdecl _ftw(const char *, int (__cdecl *)(const char *, const struct _stat *, int), int);
extern int __cdecl _wftw(const wchar_t *, int (__cdecl *)(const wchar_t *, const struct _stat *, int), int);

/* compatibility names */
#ifdef __POCC__OLDNAMES
#define FTW_NS  _FTW_NS
#define FTW_F  _FTW_F
#define FTW_D  _FTW_D

extern int __cdecl ftw(const char *, int (__cdecl *)(const char *, const struct stat *, int), int);
#endif /* __POCC__OLDNAMES */

#endif /* _FTW_H */

