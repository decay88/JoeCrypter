#ifndef _STRINGS_H
#define _STRINGS_H

/* strings.h - private header for string operations */

#if __POCC__ >= 500
#pragma once
#endif

#ifndef _SIZE_T_DEFINED
#define _SIZE_T_DEFINED
#if __POCC_TARGET__ == 3
typedef unsigned long long size_t;
#else
typedef unsigned int size_t;
#endif
#endif /* _SIZE_T_DEFINED */

/* declarations */
extern int __cdecl _ffs(int);
extern int __cdecl _strcasecmp(const char *, const char *);
extern int __cdecl _strncasecmp(const char *, const char *, size_t);

/* compatibility names */
#ifdef __POCC__OLDNAMES
extern int __cdecl ffs(int);
extern int __cdecl strcasecmp(const char *, const char *);
extern int __cdecl strncasecmp(const char *, const char *, size_t);
#endif /* __POCC__OLDNAMES */

#endif /* _STRINGS_H */
