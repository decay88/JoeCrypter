#ifndef _THREADS_H
#define _THREADS_H

/* threads.h - C11 standard header */

#if __POCC__ >= 500
#pragma once
#endif

#if __POCC_STDC_VERSION__ < 201101L

#error <threads.h> is only supported in C11 mode

#else /* __POCC_STDC_VERSION__ >= 201101L */

#include <time.h>

#ifdef __MT__

#if __POCC_TARGET__ == 1 || __POCC_TARGET__ == 3

/* macros */
#define thread_local  _Thread_local
#define ONCE_FLAG_INIT  {0}
#define TSS_DTOR_ITERATIONS  4

/* return codes */
enum {
    thrd_success = 0,
    thrd_error = 1,
    thrd_busy = 2,
    thrd_nomem = 3,
    thrd_timedout = 4,
};

/* mutex types */
enum {
    mtx_plain = 0x01,
    mtx_timed = 0x02,
    mtx_recursive = 0x10,
};

/* type definitions */
typedef struct cnd_t *cnd_t;
#if __POCC_TARGET__ == 3
typedef struct thrd_t { void *p; long long n; } thrd_t;
#else /* __POCC_TARGET__ != 3 */
typedef struct thrd_t { void *p; long n; } thrd_t;
#endif /* __POCC_TARGET__ != 3 */
typedef struct tss_t *tss_t;
typedef struct mtx_t *mtx_t;

typedef void (__cdecl *tss_dtor_t)(void *);
typedef int (__cdecl *thrd_start_t)(void *);

typedef struct once_flag { void *p; long once; } once_flag;

/* initialization functions */
extern void __cdecl call_once(once_flag *, void (__cdecl *)(void));

/* condition variable functions */
extern int __cdecl cnd_broadcast(cnd_t *);
extern void __cdecl cnd_destroy(cnd_t *);
extern int __cdecl cnd_init(cnd_t *);
extern int __cdecl cnd_signal(cnd_t *);
extern int __cdecl cnd_timedwait(cnd_t * restrict, mtx_t * restrict, const struct timespec * restrict);
extern int __cdecl cnd_wait(cnd_t *, mtx_t *);

/* mutex functions */
extern void __cdecl mtx_destroy(mtx_t *);
extern int __cdecl mtx_init(mtx_t *, int);
extern int __cdecl mtx_lock(mtx_t *);
extern int __cdecl mtx_timedlock(mtx_t * restrict, const struct timespec * restrict);
extern int __cdecl mtx_trylock(mtx_t *);
extern int __cdecl mtx_unlock(mtx_t *);

/* thread functions */
extern int __cdecl thrd_create(thrd_t *, thrd_start_t, void *);
extern thrd_t __cdecl thrd_current(void);
extern int __cdecl thrd_detach(thrd_t);
extern int __cdecl thrd_equal(thrd_t, thrd_t);
extern _Noreturn void __cdecl thrd_exit(int);
extern int __cdecl thrd_join(thrd_t, int *);
extern int __cdecl thrd_sleep(const struct timespec *, struct timespec *);
extern void __cdecl thrd_yield(void);

/* thread-specific storage functions */
extern int __cdecl tss_create(tss_t *, tss_dtor_t);
extern void __cdecl tss_delete(tss_t);
extern void * __cdecl tss_get(tss_t);
extern int __cdecl tss_set(tss_t, void *);

#else /* __POCC_TARGET__ */

#error <threads.h> is not supported on this target

#endif /* __POCC_TARGET__ */

#else /* !__MT__ */

#error must use option /MT or /MD with <threads.h>

#endif /* !__MT__ */

#endif /* __POCC_STDC_VERSION__ >= 201101L */

#endif /* _THREADS_H */
