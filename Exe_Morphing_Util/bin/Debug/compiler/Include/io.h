#ifndef _IO_H
#define _IO_H

/* io.h - private header for low-level I/O definitions */

#if __POCC__ >= 500
#pragma once
#endif

/* type definitions */
#ifndef _TIME_T_DEFINED
#define _TIME_T_DEFINED
typedef unsigned long time_t;
#endif /* _TIME_T_DEFINED */

#ifndef _WCHAR_T_DEFINED
#define _WCHAR_T_DEFINED
typedef unsigned short wchar_t;
#endif /* _WCHAR_T_DEFINED */

#ifndef _INTPTR_T_DEFINED
#define _INTPTR_T_DEFINED
#if __POCC_TARGET__ == 3
typedef signed long long intptr_t;
#else
typedef signed int intptr_t;
#endif /* __POCC_TARGET__ */
#endif /* _INTPTR_T_DEFINED */

#ifndef _SIZE_T_DEFINED
#define _SIZE_T_DEFINED
#if __POCC_TARGET__ == 3
typedef unsigned long long size_t;
#else
typedef unsigned int size_t;
#endif
#endif /* _SIZE_T_DEFINED */

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

struct _finddata_t {
    unsigned int attrib;
    time_t time_create;
    time_t time_access;
    time_t time_write;
    unsigned long size;
    char name[260];
};

struct _wfinddata_t {
    unsigned int attrib;
    time_t time_create;
    time_t time_access;
    time_t time_write;
    unsigned long size;
    wchar_t name[260];
};

struct _finddata64_t {  /* 06-03-02 */
    unsigned int attrib;
    time_t time_create;
    time_t time_access;
    time_t time_write;
    unsigned long long size;
    char name[260];
};

struct _wfinddata64_t {  /* 06-03-02 */
    unsigned int attrib;
    time_t time_create;
    time_t time_access;
    time_t time_write;
    unsigned long long size;
    wchar_t name[260];
};

/* attributes for _findfirst() */
#define _A_NORMAL   0x00
#define _A_RDONLY   0x01
#define _A_HIDDEN   0x02
#define _A_SYSTEM   0x04
#define _A_SUBDIR   0x10
#define _A_ARCH     0x20

/* sharing modes for _sopen() */
#define _SH_DENYRW  0x10
#define _SH_DENYWR  0x20
#define _SH_DENYRD  0x30
#define _SH_DENYNO  0x40

/* flags for _open() and _chmod() */
#define _S_IREAD    0x100
#define _S_IWRITE   0x80

/* locking modes for _locking() and _locking64() */
#define _LK_UNLCK   0
#define _LK_LOCK    1
#define _LK_NBLCK   2
#define _LK_RLCK    3
#define _LK_NBRLCK  4

/* declarations */
extern int __cdecl _access(const char *, int);
extern int __cdecl _chmod(const char *, int);
extern int __cdecl _chsize(int, long);
extern int __cdecl _close(int);
extern int __cdecl _commit(int);
extern int __cdecl _creat(const char *, int);
extern int __cdecl _dup(int);
extern int __cdecl _dup2(int, int);
extern int __cdecl _eof(int);
extern long __cdecl _filelength(int);
extern long long __cdecl _filelength64(int);
extern intptr_t __cdecl _findfirst(const char *, struct _finddata_t *);
extern intptr_t __cdecl _findfirst64(const char *, struct _finddata64_t *);
extern int __cdecl _findnext(intptr_t, struct _finddata_t *);
extern int __cdecl _findnext64(intptr_t, struct _finddata64_t *);
extern int __cdecl _findclose(intptr_t);
extern int __cdecl _ftruncate(int, _off_t);
extern intptr_t __cdecl _get_osfhandle(int);
extern int __cdecl _open_osfhandle(intptr_t, int);
extern int __cdecl _isatty(int);
extern int __cdecl _locking(int, int, long);
extern int __cdecl _locking64(int, int, long long);
#if __POCC__ >= 500
extern _off_t __cdecl _lseek(int, _off_t, int);
#else /* __POCC__ < 500 */
extern long __cdecl _lseek(int, long, int);
#endif /* __POCC__ < 500 */
extern long long __cdecl _lseek64(int, long long, int);
extern int __cdecl _open(const char *, int, ...);
extern int __cdecl _pipe(int *, unsigned int, int);
extern _ssize_t __cdecl _read(int, void *, size_t);
extern int __cdecl _setmode(int, int);
extern int __cdecl _sopen(const char *, int, int, ...);
extern long __cdecl _tell(int);
extern long long __cdecl _tell64(int);
extern int __cdecl _unlink(const char *);
extern _ssize_t __cdecl _write(int, const void *, size_t);

/* wide-character */
extern int __cdecl _waccess(const wchar_t *, int);
extern int __cdecl _wchmod(const wchar_t *, int);
extern int __cdecl _wcreat(const wchar_t *, int);
extern intptr_t __cdecl _wfindfirst(const wchar_t *, struct _wfinddata_t *);
extern intptr_t __cdecl _wfindfirst64(const wchar_t *, struct _wfinddata64_t *);
extern int __cdecl _wfindnext(intptr_t, struct _wfinddata_t *);
extern int __cdecl _wfindnext64(intptr_t, struct _wfinddata64_t *);
extern int __cdecl _wopen(const wchar_t *, int, ...);
extern int __cdecl _wsopen(const wchar_t *, int, int, ...);
extern int __cdecl _wunlink(const wchar_t *);

/* macros */
#define _tell(fh)  _lseek((fh),0L,/*SEEK_CUR*/1)
#define _tell64(fh)  _lseek64((fh),0LL,/*SEEK_CUR*/1)

/* compatibility names */
#ifdef __POCC__OLDNAMES
#define SH_DENYRW  _SH_DENYRW
#define SH_DENYWR  _SH_DENYWR
#define SH_DENYRD  _SH_DENYRD
#define SH_DENYNO  _SH_DENYNO
#define S_IREAD  _S_IREAD
#define S_IWRITE  _S_IWRITE
#define LK_UNLCK  _LK_UNLCK
#define LK_LOCK  _LK_LOCK
#define LK_NBLCK  _LK_NBLCK
#define LK_RLCK  _LK_RLCK
#define LK_NBRLCK  _LK_NBRLCK

extern int __cdecl access(const char *, int);
extern int __cdecl chmod(const char *, int);
extern int __cdecl chsize(int, long);
extern int __cdecl close(int);
extern int __cdecl creat(const char *, int);
extern int __cdecl dup(int);
extern int __cdecl dup2(int, int);
extern int __cdecl eof(int);
extern long __cdecl filelength(int);
extern int __cdecl ftruncate(int, off_t);
extern int __cdecl isatty(int);
extern int __cdecl locking(int, int, long);
#if __POCC__ >= 500
extern off_t __cdecl lseek(int, off_t, int);
#else /* __POCC__ < 500 */
extern long __cdecl lseek(int, long, int);
#endif /* __POCC__ < 500 */
extern int __cdecl open(const char *, int, ...);
extern ssize_t __cdecl read(int, void *, size_t);
extern int __cdecl setmode(int, int);
extern int __cdecl sopen(const char *, int, int, ...);
extern long __cdecl tell(int);
extern int __cdecl unlink(const char *);
extern ssize_t __cdecl write(int, const void *, size_t);
#endif /* __POCC__OLDNAMES */

#ifdef _MSC_EXTENSIONS
#define _filelengthi64(h)  _filelength64(h)
#define _lseeki64(h,o,m)  _lseek64(h,o,m)
#define _telli64(h)  _tell64(h)
#endif /* _MSC_EXTENSIONS */

#endif /* _IO_H */
