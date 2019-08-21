#ifndef _SEARCH_H
#define _SEARCH_H

/* search.h - private header for search tables */

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

typedef struct {
    char *key;
    void *data;
} _ENTRY;

typedef enum { _FIND, _ENTER } _ACTION;
typedef enum { _preorder, _postorder, _endorder, _leaf } _VISIT;

/* declarations */
extern int __cdecl _hcreate(size_t);
extern void __cdecl _hdestroy(void);
extern _ENTRY * __cdecl _hsearch(_ENTRY, _ACTION);
extern void __cdecl _insque(void *, void *);
extern void * __cdecl _lfind(const void *, const void *, size_t *, size_t, int (__cdecl *)(const void *, const void *));
extern void * __cdecl _lsearch(const void *, void *, size_t *, size_t, int (__cdecl *)(const void *, const void *));
extern void __cdecl _remque(void *);
extern void * __cdecl _tdelete(const void * restrict, void ** restrict, int (__cdecl *)(const void *, const void *));
extern void * __cdecl _tfind(const void *, void * const *, int (__cdecl *)(const void *, const void *));
extern void * __cdecl _tsearch(const void *, void **, int (__cdecl *)(const void *, const void *));
extern void __cdecl _twalk(const void *, void (__cdecl *)(const void *, _VISIT, int));

/* compatibility names */
#ifdef __POCC__OLDNAMES
typedef struct {
    char *key;
    void *data;
} ENTRY;

typedef enum { FIND, ENTER } ACTION;
typedef enum { preorder, postorder, endorder, leaf } VISIT;

/* declarations */
extern int __cdecl hcreate(size_t);
extern void __cdecl hdestroy(void);
extern ENTRY * __cdecl hsearch(ENTRY, ACTION);
extern void __cdecl insque(void *, void *);
extern void * __cdecl lfind(const void *, const void *, size_t *, size_t, int (__cdecl *)(const void *, const void *));
extern void * __cdecl lsearch(const void *, void *, size_t *, size_t, int (__cdecl *)(const void *, const void *));
extern void __cdecl remque(void *);
extern void * __cdecl tdelete(const void * restrict, void ** restrict, int (__cdecl *)(const void *, const void *));
extern void * __cdecl tfind(const void *, void * const *, int (__cdecl *)(const void *, const void *));
extern void * __cdecl tsearch(const void *, void **, int (__cdecl *)(const void *, const void *));
extern void __cdecl twalk(const void *, void (__cdecl *)(const void *, VISIT, int ));
#endif /* __POCC__OLDNAMES */

#endif /* _SEARCH_H */
