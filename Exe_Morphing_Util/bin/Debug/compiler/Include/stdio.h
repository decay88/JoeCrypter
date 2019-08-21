#ifndef _STDIO_H
#define _STDIO_H

/* stdio.h - C99 standard header */

#if __POCC__ >= 500
#pragma once
#endif

#include <crtdef.h>

/* macros */
#ifndef NULL
#define NULL  ((void *)0)
#endif

#define EOF  (-1)

#define FILENAME_MAX  260

#define _IOFBF  0
#define _IOLBF  1
#define _IONBF  2

#define BUFSIZ  512

#define FOPEN_MAX  256

#if __POCC__ >= 600
#define L_tmpnam  260
#else
#define L_tmpnam  16
#endif
#define TMP_MAX  32

#define SEEK_SET  0
#define SEEK_CUR  1
#define SEEK_END  2

#define stdin   (&__stdin)
#define stdout  (&__stdout)
#define stderr  (&__stderr)

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

#ifndef _WCHAR_T_DEFINED
#define _WCHAR_T_DEFINED
typedef unsigned short wchar_t;
#endif /* _WCHAR_T_DEFINED */

#ifndef _VA_LIST_DEFINED
#define _VA_LIST_DEFINED
typedef _CRTVAP char *va_list;
#endif /* _VA_LIST_DEFINED */

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

typedef struct FILE {
#if __POCC__ >= 500
    unsigned int mode;
#else
    unsigned short mode;
    unsigned short pad;
#endif /* __POCC__ */
    int fh;
    unsigned char *buf, *bufend, *ptr;
    unsigned char *getend, *putend, *backptr;
    wchar_t *wbackptr, wbackbuf[2];
    unsigned char *getback, *wgetend, *wputend;
    mbstate_t wstate;
    char *tmpnam;
    unsigned char backbuf[8], cbuf;
#if __POCC__ >= 500
    int locknum;
#endif /* __POCC__ >= 500 */
} FILE;

typedef struct fpos_t {
#if __POCC__ >= 500
    long long off;
#else /* __POCC__ < 500 */
    long off;
#endif /* __POCC__ < 500 */
    mbstate_t wstate;
} fpos_t;

/* operations on files */
extern int __cdecl remove(const char *);
extern int __cdecl rename(const char *, const char *);
extern FILE * __cdecl tmpfile(void);
extern char * __cdecl tmpnam(char *);
extern wchar_t * __cdecl _wtmpnam(wchar_t *);

/* file access functions */
extern _CRTFRE(1) int __cdecl fclose(FILE *);
extern int __cdecl fflush(FILE *);
extern FILE * __cdecl fopen(const char * restrict, const char * restrict);
extern int __cdecl setvbuf(FILE * restrict, char * restrict, int, size_t);
extern FILE * __cdecl freopen(const char * restrict, const char * restrict, FILE * restrict);
extern void __cdecl setbuf(FILE * restrict, char * restrict);

/* formatted input/output functions */
extern _CRTCHK(printf,2,3) int __cdecl fprintf(FILE * restrict, const char * restrict, ...);
extern _CRTCHK(scanf,2,3) int __cdecl fscanf(FILE * restrict, const char * restrict, ...);
extern _CRTCHK(printf,2,3) int __cdecl sprintf(char * restrict, const char * restrict, ...);
extern _CRTCHK(scanf,2,3) int __cdecl sscanf(const char * restrict, const char * restrict, ...);
extern int __cdecl vfprintf(FILE * restrict, const char * restrict, va_list);
extern int __cdecl vsprintf(char * restrict, const char * restrict, va_list);
extern _CRTNOP int __cdecl vprintf(const char * restrict, va_list);
extern _CRTCHK(printf,1,2) _CRTNOP int __cdecl printf(const char * restrict, ...);
extern _CRTCHK(scanf,1,2) int __cdecl scanf(const char * restrict, ...);
extern int __cdecl vfscanf(FILE * restrict, const char * restrict, va_list);
extern int __cdecl vsscanf(const char * restrict, const char * restrict, va_list);
extern int __cdecl vscanf(const char * restrict, va_list);
extern _CRTCHK(printf,3,4) int __cdecl snprintf(char * restrict, size_t, const char * restrict, ...);
extern int __cdecl vsnprintf(char * restrict, size_t, const char * restrict, va_list);

/* character input/output functions */
extern int __cdecl fgetc(FILE *);
extern char * __cdecl fgets(char * restrict, int, FILE * restrict);
extern int __cdecl fputc(int, FILE *);
extern int __cdecl fputs(const char * restrict, FILE * restrict);
extern int __cdecl getchar(void);
#if __POCC_STDC_VERSION__ < 201101L
extern _CRTBAD char * __cdecl gets(char *);
#endif /* __POCC_STDC_VERSION__ < 201101L */
extern _CRTNOP int __cdecl putchar(int);
extern _CRTNOP int __cdecl puts(const char *);
extern int __cdecl ungetc(int, FILE *);
extern int __cdecl getc(FILE *);
extern int __cdecl putc(int, FILE *);

/* direct input/output functions */
extern size_t __cdecl fread(void * restrict, size_t, size_t, FILE * restrict);
extern size_t __cdecl fwrite(const void * restrict, size_t, size_t, FILE * restrict);

/* file positioning functions */
extern int __cdecl fgetpos(FILE * restrict, fpos_t * restrict);
extern int __cdecl fseek(FILE *, long, int);
extern int __cdecl fsetpos(FILE *, const fpos_t *);
extern long __cdecl ftell(FILE *);
extern void __cdecl rewind(FILE *);

/* error-handling functions */
extern void __cdecl clearerr(FILE *);
extern int __cdecl feof(FILE *);
extern int __cdecl ferror(FILE *);
extern void __cdecl perror(const char *);
extern void __cdecl _wperror(const wchar_t *);

/* private extensions to standard C */
extern int __cdecl _fileno(FILE *);
extern int __cdecl _fcloseall(void);
extern FILE * __cdecl _wfopen(const wchar_t * restrict, const wchar_t * restrict);
extern FILE * __cdecl _wfreopen(const wchar_t * restrict, const wchar_t * restrict, FILE * restrict);
extern FILE * __cdecl _fdopen(int, const char *);
extern FILE * __cdecl _wfdopen(int, const wchar_t *);
extern FILE * __cdecl _popen(const char *, const char *);  /* 06-03-13 */
extern _CRTFRE(1) int __cdecl _pclose(FILE *);  /* 06-03-13 */
extern _CRTCHK(printf,3,4) int __cdecl _snprintf(char * restrict, size_t, const char * restrict, ...);
extern int __cdecl _vsnprintf(char * restrict, size_t, const char * restrict, va_list);
extern int __cdecl _wremove(const wchar_t *);
extern int __cdecl _wrename(const wchar_t *, const wchar_t *);
extern int __cdecl _fseeko(FILE *, _off_t, int);
extern _off_t __cdecl _ftello(FILE *);
extern int __cdecl _fseek64(FILE *, long long, int);  /* 14-06-29 */
extern long long __cdecl _ftell64(FILE *);  /* 14-06-29 */

/* data declarations */
extern _CRTIMP FILE __stdin, __stdout, __stderr;
#if !defined(_DLL)
extern FILE *__filetab[FOPEN_MAX];
#endif

/* macro overrides */
#if !defined(__MT__) && !defined(_DLL)
#define getc(str)     ((str)->ptr < (str)->getend ? *(str)->ptr++ : (fgetc)(str))
#define getchar()     (__filetab[0]->ptr < __filetab[0]->getend ? *__filetab[0]->ptr++ : (fgetc)(__filetab[0]))
#define putc(c,str)   ((str)->ptr < (str)->putend ? (*(str)->ptr++ = c) : (fputc)(c, str))
#define putchar(c)    (__filetab[1]->ptr < __filetab[1]->putend ? (*__filetab[1]->ptr++ = c) : (fputc)(c, __filetab[1]))
#define _fileno(str)  ((str)->fh)
#endif

/* compatibility names */
#ifdef __POCC__OLDNAMES
extern int __cdecl fcloseall(void);
extern int __cdecl fileno(FILE *);
extern FILE * __cdecl fdopen(int, const char *);
extern int __cdecl fseeko(FILE *, off_t, int);
extern off_t __cdecl ftello(FILE *);
extern FILE * __cdecl popen(const char *, const char *);
extern _CRTFRE(1) int __cdecl pclose(FILE *);
#endif /* __POCC__OLDNAMES */

#ifdef _MSC_EXTENSIONS
#define _fseeki64  _fseek64
#define _ftelli64  _ftell64
#endif /* _MSC_EXTENSIONS */

/* bounds-checking interfaces (TR24731-1, C11 annex K) */
#if __STDC_WANT_LIB_EXT1__

#define L_tmpnam_s  L_tmpnam
#define TMP_MAX_S  TMP_MAX

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

/* operations on files */
extern errno_t __cdecl tmpfile_s(FILE * restrict * restrict);
extern errno_t __cdecl tmpnam_s(char *, rsize_t);

/* file access functions */
extern errno_t __cdecl fopen_s(FILE * restrict * restrict, const char * restrict, const char * restrict);
extern errno_t __cdecl freopen_s(FILE * restrict * restrict, const char * restrict, const char * restrict, FILE * restrict);

/* formatted input/output functions */
extern _CRTCHK(printf,2,3) int __cdecl fprintf_s(FILE * restrict, const char * restrict, ...);
extern _CRTCHK(scanf_s,2,3) int __cdecl fscanf_s(FILE * restrict, const char * restrict, ...);
extern _CRTCHK(printf,1,2) int __cdecl printf_s(const char * restrict, ...);
extern _CRTCHK(scanf_s,1,2) int __cdecl scanf_s(const char * restrict, ...);
extern _CRTCHK(printf,3,4) int __cdecl snprintf_s(char * restrict, rsize_t, const char * restrict, ...);
extern _CRTCHK(printf,3,4) int __cdecl sprintf_s(char * restrict, rsize_t, const char * restrict, ...);
extern _CRTCHK(scanf_s,2,3) int __cdecl sscanf_s(const char * restrict, const char * restrict, ...);
extern int __cdecl vfprintf_s(FILE * restrict, const char * restrict, va_list);
extern int __cdecl vfscanf_s(FILE * restrict, const char * restrict, va_list);
extern int __cdecl vprintf_s(const char * restrict, va_list);
extern int __cdecl vscanf_s(const char * restrict, va_list);
extern int __cdecl vsnprintf_s(char * restrict, rsize_t, const char * restrict, va_list);
extern int __cdecl vsprintf_s(char * restrict, rsize_t, const char * restrict, va_list);
extern int __cdecl vsscanf_s(const char * restrict, const char * restrict, va_list);

/* character input/output functions */
extern char * __cdecl gets_s(char *, rsize_t);

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

extern FILE * __cdecl fmemopen(void * restrict, size_t, const char * restrict);
extern FILE * __cdecl open_memstream(char ** restrict, size_t * restrict);

extern _CRTCHK(printf,2,3) int __cdecl asprintf(char ** restrict, const char * restrict, ...);
extern int __cdecl vasprintf(char ** restrict, const char * restrict, va_list);

extern ssize_t __cdecl getdelim(char ** restrict, size_t * restrict, int, FILE *);
extern ssize_t __cdecl getline(char **, size_t *, FILE *);

#endif /* __STDC_WANT_LIB_EXT2__ */

#endif /* _STDIO_H */
