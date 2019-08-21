#ifndef _ERRNO_H
#define _ERRNO_H

/* errno.h - C99 standard header */

#if __POCC__ >= 500
#pragma once
#endif

/* error codes */
#define EPERM         1
#define ENOENT        2
#define ESRCH         3
#define EINTR         4
#define EIO           5
#define ENXIO         6
#define E2BIG         7
#define ENOEXEC       8
#define EBADF         9
#define ECHILD        10
#define EAGAIN        11
#define ENOMEM        12
#define EACCES        13
#define EFAULT        14
#define EBUSY         16
#define EEXIST        17
#define EXDEV         18
#define ENODEV        19
#define ENOTDIR       20
#define EISDIR        21
#define EINVAL        22
#define ENFILE        23
#define EMFILE        24
#define ENOTTY        25
#define EFBIG         27
#define ENOSPC        28
#define ESPIPE        29
#define EROFS         30
#define EMLINK        31
#define EPIPE         32
#define EDOM          33
#define ERANGE        34
#define EFPOS         35
#define EDEADLK       36
#define ENAMETOOLONG  38
#define ENOLCK        39
#define ENOSYS        40
#define ENOTEMPTY     41
#define EILSEQ        42

/*
 Unsupported "POSIX" error codes.
#define EADDRINUSE    0
#define EADDRNOTAVAIL 0
#define EAFNOSUPPORT  0
#define EALREADY      0
#define EBADMSG       0
#define ECANCELED     0
#define ECONNABORTED  0
#define ECONNREFUSED  0
#define ECONNRESET    0
#define EDESTADDRREQ  0
#define EHOSTUNREACH  0
#define EIDRM         0
#define EINPROGRESS   0
#define EISCONN       0
#define ELOOP         0
#define EMSGSIZE      0
#define ENETDOWN      0
#define ENETRESET     0
#define ENETUNREACH   0
#define ENOBUFS       0
#define ENOMSG        0
#define ENOPROTOOPT   0
#define ENOTCONN      0
#define ENOTSOCK      0
#define ENOTSUP       0
#define EOPNOTSUPP    0
#define EOVERFLOW     0
#define EPROTO        0
#define EPROTONOSUPPORT  0
#define EPROTOTYPE    0
#define ETIMEDOUT     0
#define ETXTBSY       0
#define EWOULDBLOCK   EAGAIN
*/

#if defined(__MT__) || defined(_DLL)
extern int * __cdecl __errno(void);
#define errno  (*__errno())
#else
extern int errno;
#endif /* __MT__ */

/* bounds-checking interfaces (TR24731-1, C11 annex K) */
#if __STDC_WANT_LIB_EXT1__

#ifndef _ERRNO_T_DEFINED
#define _ERRNO_T_DEFINED
typedef int errno_t;
#endif /* _ERRNO_T_DEFINED */

#endif /* __STDC_WANT_LIB_EXT1__ */

#endif /* _ERRNO_H */

