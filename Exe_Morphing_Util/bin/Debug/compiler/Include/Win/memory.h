#ifndef _MEMORY_H
#define _MEMORY_H

/* memory.h - private header for memory definitions */

#if __POCC__ >= 500
#pragma once
#endif

#pragma message("Use <string.h> instead of non-standard <memory.h>")

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
extern void * __cdecl memcpy(void * restrict, const void * restrict, size_t);
extern void * __cdecl memmove(void *, const void *, size_t);
extern void * __cdecl memset(void *, int, size_t);

#endif /* _MEMORY_H */

