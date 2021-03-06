#ifndef _SYS_LOCKING_H
#define _SYS_LOCKING_H

/* sys/locking.h - private header for locking definitions */

#if __POCC__ >= 500
#pragma once
#endif

/* locking modes for _locking() and _locking64() */
#define _LK_UNLCK   0
#define _LK_LOCK    1
#define _LK_NBLCK   2
#define _LK_RLCK    3
#define _LK_NBRLCK  4

/* compatibility names */
#ifdef __POCC__OLDNAMES
#define LK_UNLCK  _LK_UNLCK
#define LK_LOCK  _LK_LOCK
#define LK_NBLCK  _LK_NBLCK
#define LK_RLCK  _LK_RLCK
#define LK_NBRLCK  _LK_NBRLCK
#endif /* __POCC__OLDNAMES */

#endif /* _SYS_LOCKING_H */
