#ifndef _STDATOMIC_H
#define _STDATOMIC_H

/* stdatomic.h - C11 standard header */

#if __POCC__ >= 500
#pragma once
#endif

#if __POCC_STDC_VERSION__ < 201101L

#error <stdatomic.h> is only supported in C11 mode

#else /* __POCC_STDC_VERSION__ >= 201101L */

/* type definitions */
#ifndef _CHAR16_T_DEFINED
#define _CHAR16_T_DEFINED
typedef unsigned short char16_t;
#endif /* _CHAR16_T_DEFINED */

#ifndef _CHAR32_T_DEFINED
#define _CHAR32_T_DEFINED
typedef unsigned int char32_t;
#endif /* _CHAR32_T_DEFINED */

#ifndef _WCHAR_T_DEFINED
#define _WCHAR_T_DEFINED
typedef unsigned short wchar_t;
#endif /* _WCHAR_T_DEFINED */

typedef _Atomic struct atomic_flag { _Bool __f__; } atomic_flag;

typedef _Atomic _Bool atomic_bool;
typedef _Atomic char atomic_char;
typedef _Atomic signed char atomic_schar;
typedef _Atomic unsigned char atomic_uchar;
typedef _Atomic short atomic_short;
typedef _Atomic unsigned short atomic_ushort;
typedef _Atomic int atomic_int;
typedef _Atomic unsigned int atomic_uint;
typedef _Atomic long atomic_long;
typedef _Atomic unsigned long atomic_ulong;
typedef _Atomic long long atomic_llong;
typedef _Atomic unsigned long long atomic_ullong;
typedef _Atomic char16_t atomic_char16_t;
typedef _Atomic char32_t atomic_char32_t;
typedef _Atomic wchar_t atomic_wchar_t;
typedef _Atomic signed char atomic_int_least8_t;
typedef _Atomic unsigned char atomic_uint_least8_t;
typedef _Atomic signed short atomic_int_least16_t;
typedef _Atomic unsigned short atomic_uint_least16_t;
typedef _Atomic signed int atomic_int_least32_t;
typedef _Atomic unsigned int atomic_uint_least32_t;
typedef _Atomic signed long long atomic_int_least64_t;
typedef _Atomic unsigned long long atomic_uint_least64_t;
typedef _Atomic signed int atomic_int_fast8_t;
typedef _Atomic unsigned int atomic_uint_fast8_t;
typedef _Atomic signed int atomic_int_fast16_t;
typedef _Atomic unsigned int atomic_uint_fast16_t;
typedef _Atomic signed int atomic_int_fast32_t;
typedef _Atomic unsigned int atomic_uint_fast32_t;
typedef _Atomic signed long long atomic_int_fast64_t;
typedef _Atomic unsigned long long atomic_uint_fast64_t;
#if __POCC_TARGET__ == 3
typedef _Atomic signed long long atomic_intptr_t;
typedef _Atomic unsigned long long atomic_uintptr_t;
typedef _Atomic unsigned long long atomic_size_t;
typedef signed long long __ptrdiff;
#else /* __POCC_TARGET__ != 3 */
typedef _Atomic signed int atomic_intptr_t;
typedef _Atomic unsigned int atomic_uintptr_t;
typedef _Atomic unsigned int atomic_size_t;
typedef signed int __ptrdiff;
#endif /* __POCC_TARGET__ != 3 */
typedef _Atomic __ptrdiff atomic_ptrdiff_t;
typedef _Atomic signed long long atomic_intmax_t;
typedef _Atomic unsigned long long atomic_uintmax_t;

typedef enum memory_order {
    memory_order_relaxed = 0,
    memory_order_consume = 1,
    memory_order_acquire = 2,
    memory_order_release = 3,
    memory_order_acq_rel = 4,
    memory_order_seq_cst = 5,
} memory_order;

#define ATOMIC_FLAG_INIT  {0}
#define ATOMIC_VAR_INIT(X)  {X}

#if __POCC_TARGET__ == 1 || __POCC_TARGET__ == 3

/* macros */

/* a value of 0 indicates that the type is never lock-free;
 * a value of 1 indicates that the type is sometimes lock-free;
 * a value of 2 indicates that the type is always lock-free
 */
#define ATOMIC_BOOL_LOCK_FREE  2
#define ATOMIC_CHAR_LOCK_FREE  2
#define ATOMIC_CHAR16_T_LOCK_FREE  2
#define ATOMIC_CHAR32_T_LOCK_FREE  2
#define ATOMIC_WCHAR_T_LOCK_FREE  2
#define ATOMIC_SHORT_LOCK_FREE  2
#define ATOMIC_INT_LOCK_FREE  2
#define ATOMIC_LONG_LOCK_FREE  2
#define ATOMIC_LLONG_LOCK_FREE  2
#define ATOMIC_POINTER_LOCK_FREE  2

/* fence functions */
extern void __cdecl atomic_thread_fence(memory_order);
extern void __cdecl atomic_signal_fence(memory_order);

/* atomic_flag functions */
extern _Bool __cdecl atomic_flag_test_and_set_explicit(volatile atomic_flag *, memory_order);
static inline _Bool __cdecl atomic_flag_test_and_set(volatile atomic_flag *X) { return atomic_flag_test_and_set_explicit(X, memory_order_seq_cst); }
extern void __cdecl atomic_flag_clear_explicit(volatile atomic_flag *, memory_order);
static inline void __cdecl atomic_flag_clear(volatile atomic_flag *X) { atomic_flag_clear_explicit(X, memory_order_seq_cst); }

/* kill_dependency macro */
#define kill_dependency(X)  (X)  /*TODO*/

/*
 * atomic_load generic functions
 */
#define atomic_load(X)  atomic_load_explicit(X, memory_order_seq_cst)

#define atomic_load_explicit(X,M)  _Generic(*X, \
    _Bool              : *(const volatile atomic_bool *)(X), \
    char               : *(const volatile atomic_char *)(X), \
    char signed        : *(const volatile atomic_schar *)(X), \
    char unsigned      : *(const volatile atomic_uchar *)(X), \
    short              : *(const volatile atomic_short *)(X), \
    short unsigned     : *(const volatile atomic_ushort *)(X), \
    int                : *(const volatile atomic_int *)(X), \
    int unsigned       : *(const volatile atomic_uint *)(X), \
    long               : *(const volatile atomic_long *)(X), \
    long unsigned      : *(const volatile atomic_ulong *)(X), \
    long long          : *(const volatile atomic_llong *)(X), \
    long long unsigned : *(const volatile atomic_ullong *)(X), \
    char16_t           : *(const volatile atomic_char16_t *)(X), \
    char32_t           : *(const volatile atomic_char32_t *)(X), \
    wchar_t            : *(const volatile atomic_wchar_t *)(X), \
    void*              : *(void* const volatile _Atomic *)(X))

/*
 * atomic_store generic functions
 */
#define atomic_store(X,Y)  atomic_store_explicit(X, Y, memory_order_seq_cst)

#define atomic_store_explicit(X,Y,M)  (void)(_Generic(*X, \
    _Bool              : *((volatile atomic_bool *)(X)), \
    char               : *((volatile atomic_char *)(X)), \
    char signed        : *((volatile atomic_schar *)(X)), \
    char unsigned      : *((volatile atomic_uchar *)(X)), \
    short              : *((volatile atomic_short *)(X)), \
    short unsigned     : *((volatile atomic_ushort *)(X)), \
    int                : *((volatile atomic_int *)(X)), \
    int unsigned       : *((volatile atomic_uint *)(X)), \
    long               : *((volatile atomic_long *)(X)), \
    long unsigned      : *((volatile atomic_ulong *)(X)), \
    long long          : *((volatile atomic_llong *)(X)), \
    long long unsigned : *((volatile atomic_ullong *)(X)), \
    char16_t           : *((volatile atomic_char16_t *)(X)), \
    char32_t           : *((volatile atomic_char32_t *)(X)), \
    wchar_t            : *((volatile atomic_wchar_t *)(X)), \
    void*              : *((void* volatile _Atomic *)(X))) = (Y))

/*
 * atomic_is_lock_free generic function
 */
#define atomic_is_lock_free(X)  (_Bool)(_Generic(*X, \
    _Bool              : 1, \
    char               : 1, \
    char signed        : 1, \
    char unsigned      : 1, \
    short              : 1, \
    short unsigned     : 1, \
    int                : 1, \
    int unsigned       : 1, \
    long               : 1, \
    long unsigned      : 1, \
    long long          : 1, \
    long long unsigned : 1, \
    char16_t           : 1, \
    char32_t           : 1, \
    wchar_t            : 1, \
    void*              : 1, \
    default            : 0))

/*
 * atomic_exchange generic functions
 */
#define atomic_exchange(X,Y)  atomic_exchange_explicit(X, Y, memory_order_seq_cst)

#define atomic_exchange_explicit(X,Y,M)  _Generic(*X, \
    _Bool              :                     __atomic_exchangebool_explicit((volatile atomic_bool *)(X), (_Bool)(Y), M), \
    char               :               (char)__atomic_exchange8_explicit((volatile atomic_uchar *)(X), (unsigned char)(Y), M), \
    char signed        :        (signed char)__atomic_exchange8_explicit((volatile atomic_uchar *)(X), (unsigned char)(Y), M), \
    char unsigned      :      (unsigned char)__atomic_exchange8_explicit((volatile atomic_uchar *)(X), (unsigned char)(Y), M), \
    short              :              (short)__atomic_exchange16_explicit((volatile atomic_ushort *)(X), (unsigned short)(Y), M), \
    short unsigned     :     (unsigned short)__atomic_exchange16_explicit((volatile atomic_ushort *)(X), (unsigned short)(Y), M), \
    int                :                (int)__atomic_exchange32_explicit((volatile atomic_ulong *)(X), (unsigned long)(Y), M), \
    int unsigned       :       (unsigned int)__atomic_exchange32_explicit((volatile atomic_ulong *)(X), (unsigned long)(Y), M), \
    long               :               (long)__atomic_exchange32_explicit((volatile atomic_ulong *)(X), (unsigned long)(Y), M), \
    long unsigned      :      (unsigned long)__atomic_exchange32_explicit((volatile atomic_ulong *)(X), (unsigned long)(Y), M), \
    long long          :          (long long)__atomic_exchange64_explicit((volatile atomic_ullong *)(X), (unsigned long long)(Y), M), \
    long long unsigned : (unsigned long long)__atomic_exchange64_explicit((volatile atomic_ullong *)(X), (unsigned long long)(Y), M), \
    char16_t           :           (char16_t)__atomic_exchange16_explicit((volatile atomic_ushort *)(X), (unsigned short)(Y), M), \
    char32_t           :           (char32_t)__atomic_exchange32_explicit((volatile atomic_ulong *)(X), (unsigned long)(Y), M), \
    wchar_t            :            (wchar_t)__atomic_exchange16_explicit((volatile atomic_ushort *)(X), (unsigned short)(Y), M), \
    void*              :                     __atomic_exchangeaddr_explicit((void* volatile _Atomic *)(X), (void *)(Y), M))

extern unsigned char __cdecl __atomic_exchange8_explicit(volatile atomic_uchar *, unsigned char, memory_order);
extern unsigned short __cdecl __atomic_exchange16_explicit(volatile atomic_ushort *, unsigned short, memory_order);
extern unsigned long __cdecl __atomic_exchange32_explicit(volatile atomic_ulong *, unsigned long, memory_order);
extern unsigned long long __cdecl __atomic_exchange64_explicit(volatile atomic_ullong *, unsigned long long, memory_order);
extern _Bool __cdecl __atomic_exchangebool_explicit(volatile atomic_bool *, _Bool, memory_order);
extern void * __cdecl __atomic_exchangeaddr_explicit(void* volatile _Atomic *, void *, memory_order);

/*
 * atomic_init generic function
 */
#define atomic_init(X,Y)  (void)(_Generic(*X, \
    _Bool              : *((volatile atomic_bool *)(X)), \
    char               : *((volatile atomic_char *)(X)), \
    char signed        : *((volatile atomic_schar *)(X)), \
    char unsigned      : *((volatile atomic_uchar *)(X)), \
    short              : *((volatile atomic_short *)(X)), \
    short unsigned     : *((volatile atomic_ushort *)(X)), \
    int                : *((volatile atomic_int *)(X)), \
    int unsigned       : *((volatile atomic_uint *)(X)), \
    long               : *((volatile atomic_long *)(X)), \
    long unsigned      : *((volatile atomic_ulong *)(X)), \
    long long          : *((volatile atomic_llong *)(X)), \
    long long unsigned : *((volatile atomic_ullong *)(X)), \
    char16_t           : *((volatile atomic_char16_t *)(X)), \
    char32_t           : *((volatile atomic_char32_t *)(X)), \
    wchar_t            : *((volatile atomic_wchar_t *)(X)), \
    void*              : *((volatile void* _Atomic *)(X))) = (Y))

/*
 * atomic_compare_exchange generic functions
 */
#define atomic_compare_exchange_strong(X,Y,Z)  atomic_compare_exchange_strong_explicit(X, Y, Z, memory_order_seq_cst, memory_order_seq_cst)

#define atomic_compare_exchange_strong_explicit(X,Y,Z,M1,M2)  _Generic(*X, \
    _Bool              : __atomic_compare_exchangebool_strong_explicit((atomic_bool *)(X), (_Bool *)(Y), (_Bool)(Z), M1, M2), \
    char               : __atomic_compare_exchange8_strong_explicit((atomic_uchar *)(X), (unsigned char *)(Y), (unsigned char)(Z), M1, M2), \
    char signed        : __atomic_compare_exchange8_strong_explicit((atomic_uchar *)(X), (unsigned char *)(Y), (unsigned char)(Z), M1, M2), \
    char unsigned      : __atomic_compare_exchange8_strong_explicit((atomic_uchar *)(X), (unsigned char *)(Y), (unsigned char)(Z), M1, M2), \
    short              : __atomic_compare_exchange16_strong_explicit((atomic_ushort *)(X), (unsigned short *)(Y), (unsigned short)(Z), M1, M2), \
    short unsigned     : __atomic_compare_exchange16_strong_explicit((atomic_ushort *)(X), (unsigned short *)(Y), (unsigned short)(Z), M1, M2), \
    int                : __atomic_compare_exchange32_strong_explicit((atomic_ulong *)(X), (unsigned long *)(Y), (unsigned long)(Z), M1, M2), \
    int unsigned       : __atomic_compare_exchange32_strong_explicit((atomic_ulong *)(X), (unsigned long *)(Y), (unsigned long)(Z), M1, M2), \
    long               : __atomic_compare_exchange32_strong_explicit((atomic_ulong *)(X), (unsigned long *)(Y), (unsigned long)(Z), M1, M2), \
    long unsigned      : __atomic_compare_exchange32_strong_explicit((atomic_ulong *)(X), (unsigned long *)(Y), (unsigned long)(Z), M1, M2), \
    long long          : __atomic_compare_exchange64_strong_explicit((atomic_ullong *)(X), (unsigned long long *)(Y), (unsigned long long)(Z), M1, M2), \
    long long unsigned : __atomic_compare_exchange64_strong_explicit((atomic_ullong *)(X), (unsigned long long *)(Y), (unsigned long long)(Z), M1, M2), \
    char16_t           : __atomic_compare_exchange16_strong_explicit((atomic_ushort *)(X), (unsigned short *)(Y), (unsigned short)(Z), M1, M2), \
    char32_t           : __atomic_compare_exchange32_strong_explicit((atomic_ulong *)(X), (unsigned long *)(Y), (unsigned long)(Z), M1, M2), \
    wchar_t            : __atomic_compare_exchange16_strong_explicit((atomic_ushort *)(X), (unsigned short *)(Y), (unsigned short)(Z), M1, M2), \
    void*              : __atomic_compare_exchangeaddr_strong_explicit((void* _Atomic *)(X), (void **)(Y), (void *)(Z), M1, M2))

#define atomic_compare_exchange_weak(X,Y,Z)  atomic_compare_exchange_weak_explicit(X, Y, Z, memory_order_seq_cst, memory_order_seq_cst)

#define atomic_compare_exchange_weak_explicit(X,Y,Z,M1,M2)  _Generic(*X, \
    _Bool              : __atomic_compare_exchangebool_weak_explicit((atomic_bool *)(X), (_Bool *)(Y), (_Bool)(Z), M1, M2), \
    char               : __atomic_compare_exchange8_weak_explicit((atomic_uchar *)(X), (unsigned char *)(Y), (unsigned char)(Z), M1, M2), \
    char signed        : __atomic_compare_exchange8_weak_explicit((atomic_uchar *)(X), (unsigned char *)(Y), (unsigned char)(Z), M1, M2), \
    char unsigned      : __atomic_compare_exchange8_weak_explicit((atomic_uchar *)(X), (unsigned char *)(Y), (unsigned char)(Z), M1, M2), \
    short              : __atomic_compare_exchange16_weak_explicit((atomic_ushort *)(X), (unsigned short *)(Y), (unsigned short)(Z), M1, M2), \
    short unsigned     : __atomic_compare_exchange16_weak_explicit((atomic_ushort *)(X), (unsigned short *)(Y), (unsigned short)(Z), M1, M2), \
    int                : __atomic_compare_exchange32_weak_explicit((atomic_ulong *)(X), (unsigned long *)(Y), (unsigned long)(Z), M1, M2), \
    int unsigned       : __atomic_compare_exchange32_weak_explicit((atomic_ulong *)(X), (unsigned long *)(Y), (unsigned long)(Z), M1, M2), \
    long               : __atomic_compare_exchange32_weak_explicit((atomic_ulong *)(X), (unsigned long *)(Y), (unsigned long)(Z), M1, M2), \
    long unsigned      : __atomic_compare_exchange32_weak_explicit((atomic_ulong *)(X), (unsigned long *)(Y), (unsigned long)(Z), M1, M2), \
    long long          : __atomic_compare_exchange64_weak_explicit((atomic_ullong *)(X), (unsigned long long *)(Y), (unsigned long long)(Z), M1, M2), \
    long long unsigned : __atomic_compare_exchange64_weak_explicit((atomic_ullong *)(X), (unsigned long long *)(Y), (unsigned long long)(Z), M1, M2), \
    char16_t           : __atomic_compare_exchange16_weak_explicit((atomic_ushort *)(X), (unsigned short *)(Y), (unsigned short)(Z), M1, M2), \
    char32_t           : __atomic_compare_exchange32_weak_explicit((atomic_ulong *)(X), (unsigned long *)(Y), (unsigned long)(Z), M1, M2), \
    wchar_t            : __atomic_compare_exchange16_weak_explicit((atomic_ushort *)(X), (unsigned short *)(Y), (unsigned short)(Z), M1, M2), \
    void*              : __atomic_compare_exchangeaddr_weak_explicit((void* _Atomic *)(X), (void **)(Y), (void *)(Z), M1, M2))

extern _Bool __cdecl __atomic_compare_exchange8_strong_explicit(volatile atomic_uchar *, unsigned char *, unsigned char, memory_order, memory_order);
extern _Bool __cdecl __atomic_compare_exchange16_strong_explicit(volatile atomic_ushort *, unsigned short *, unsigned short, memory_order, memory_order);
extern _Bool __cdecl __atomic_compare_exchange32_strong_explicit(volatile atomic_ulong *, unsigned long *, unsigned long, memory_order, memory_order);
extern _Bool __cdecl __atomic_compare_exchange64_strong_explicit(volatile atomic_ullong *, unsigned long long *, unsigned long long, memory_order, memory_order);
extern _Bool __cdecl __atomic_compare_exchangeaddr_strong_explicit(void* volatile _Atomic *, void **, void *, memory_order, memory_order);
extern _Bool __cdecl __atomic_compare_exchangebool_strong_explicit(volatile atomic_bool *, _Bool *, _Bool, memory_order, memory_order);

extern _Bool __cdecl __atomic_compare_exchange8_weak_explicit(volatile atomic_uchar *, unsigned char *, unsigned char, memory_order, memory_order);
extern _Bool __cdecl __atomic_compare_exchange16_weak_explicit(volatile atomic_ushort *, unsigned short *, unsigned short, memory_order, memory_order);
extern _Bool __cdecl __atomic_compare_exchange32_weak_explicit(volatile atomic_ulong *, unsigned long *, unsigned long, memory_order, memory_order);
extern _Bool __cdecl __atomic_compare_exchange64_weak_explicit(volatile atomic_ullong *, unsigned long long *, unsigned long long, memory_order, memory_order);
extern _Bool __cdecl __atomic_compare_exchangeaddr_weak_explicit(void* volatile _Atomic *, void **, void *, memory_order, memory_order);
extern _Bool __cdecl __atomic_compare_exchangebool_weak_explicit(volatile atomic_bool *, _Bool *, _Bool, memory_order, memory_order);

/*
 * atomic_fetch and modify generic functions
 */
#define atomic_fetch_add(X,Y)  atomic_fetch_add_explicit(X, Y, memory_order_seq_cst)
#define atomic_fetch_sub(X,Y)  atomic_fetch_sub_explicit(X, Y, memory_order_seq_cst)
#define atomic_fetch_or(X,Y)   atomic_fetch_or_explicit(X, Y, memory_order_seq_cst)
#define atomic_fetch_xor(X,Y)  atomic_fetch_xor_explicit(X, Y, memory_order_seq_cst)
#define atomic_fetch_and(X,Y)  atomic_fetch_and_explicit(X, Y, memory_order_seq_cst)

#define atomic_fetch_add_explicit(X,Y,M)  _Generic(*X, \
    char               :               (char)__atomic_fetch_add8_explicit((volatile atomic_uchar *)(X), (unsigned char)(Y), M), \
    char signed        :        (signed char)__atomic_fetch_add8_explicit((volatile atomic_uchar *)(X), (unsigned char)(Y), M), \
    char unsigned      :      (unsigned char)__atomic_fetch_add8_explicit((volatile atomic_uchar *)(X), (unsigned char)(Y), M), \
    short              :              (short)__atomic_fetch_add16_explicit((volatile atomic_ushort *)(X), (unsigned short)(Y), M), \
    short unsigned     :     (unsigned short)__atomic_fetch_add16_explicit((volatile atomic_ushort *)(X), (unsigned short)(Y), M), \
    int                :                (int)__atomic_fetch_add32_explicit((volatile atomic_ulong *)(X), (unsigned long)(Y), M), \
    int unsigned       :       (unsigned int)__atomic_fetch_add32_explicit((volatile atomic_ulong *)(X), (unsigned long)(Y), M), \
    long               :               (long)__atomic_fetch_add32_explicit((volatile atomic_ulong *)(X), (unsigned long)(Y), M), \
    long unsigned      :      (unsigned long)__atomic_fetch_add32_explicit((volatile atomic_ulong *)(X), (unsigned long)(Y), M), \
    long long          :          (long long)__atomic_fetch_add64_explicit((volatile atomic_ullong *)(X), (unsigned long long)(Y), M), \
    long long unsigned : (unsigned long long)__atomic_fetch_add64_explicit((volatile atomic_ullong *)(X), (unsigned long long)(Y), M), \
    void*              :                     __atomic_fetch_addaddr_explicit((void* volatile _Atomic *)(X), (__ptrdiff)(Y), M))

extern unsigned char __cdecl __atomic_fetch_add8_explicit(volatile atomic_uchar *, unsigned char, memory_order);
extern unsigned short __cdecl __atomic_fetch_add16_explicit(volatile atomic_ushort *, unsigned short, memory_order);
extern unsigned long __cdecl __atomic_fetch_add32_explicit(volatile atomic_ulong *, unsigned long, memory_order);
extern unsigned long long __cdecl __atomic_fetch_add64_explicit(volatile atomic_ullong *, unsigned long long, memory_order);
extern void * __cdecl __atomic_fetch_addaddr_explicit(void* volatile _Atomic *, __ptrdiff, memory_order);

#define atomic_fetch_sub_explicit(X,Y,M)  _Generic(*X, \
    char               :               (char)__atomic_fetch_sub8_explicit((volatile atomic_uchar *)(X), (unsigned char)(Y), M), \
    char signed        :        (signed char)__atomic_fetch_sub8_explicit((volatile atomic_uchar *)(X), (unsigned char)(Y), M), \
    char unsigned      :      (unsigned char)__atomic_fetch_sub8_explicit((volatile atomic_uchar *)(X), (unsigned char)(Y), M), \
    short              :              (short)__atomic_fetch_sub16_explicit((volatile atomic_ushort *)(X), (unsigned short)(Y), M), \
    short unsigned     :     (unsigned short)__atomic_fetch_sub16_explicit((volatile atomic_ushort *)(X), (unsigned short)(Y), M), \
    int                :                (int)__atomic_fetch_sub32_explicit((volatile atomic_ulong *)(X), (unsigned long)(Y), M), \
    int unsigned       :       (unsigned int)__atomic_fetch_sub32_explicit((volatile atomic_ulong *)(X), (unsigned long)(Y), M), \
    long               :               (long)__atomic_fetch_sub32_explicit((volatile atomic_ulong *)(X), (unsigned long)(Y), M), \
    long unsigned      :      (unsigned long)__atomic_fetch_sub32_explicit((volatile atomic_ulong *)(X), (unsigned long)(Y), M), \
    long long          :          (long long)__atomic_fetch_sub64_explicit((volatile atomic_ullong *)(X), (unsigned long long)(Y), M), \
    long long unsigned : (unsigned long long)__atomic_fetch_sub64_explicit((volatile atomic_ullong *)(X), (unsigned long long)(Y), M), \
    void*              :                     __atomic_fetch_subaddr_explicit((void* volatile _Atomic *)(X), (__ptrdiff)(Y), M))

extern unsigned char __cdecl __atomic_fetch_sub8_explicit(volatile atomic_uchar *, unsigned char, memory_order);
extern unsigned short __cdecl __atomic_fetch_sub16_explicit(volatile atomic_ushort *, unsigned short, memory_order);
extern unsigned long __cdecl __atomic_fetch_sub32_explicit(volatile atomic_ulong *, unsigned long, memory_order);
extern unsigned long long __cdecl __atomic_fetch_sub64_explicit(volatile atomic_ullong *, unsigned long long, memory_order);
extern void * __cdecl __atomic_fetch_subaddr_explicit(void* volatile _Atomic *, __ptrdiff, memory_order);

#define atomic_fetch_or_explicit(X,Y,M)  _Generic(*X, \
    char               :               (char)__atomic_fetch_or8_explicit((volatile atomic_uchar *)(X), (unsigned char)(Y), M), \
    char signed        :        (signed char)__atomic_fetch_or8_explicit((volatile atomic_uchar *)(X), (unsigned char)(Y), M), \
    char unsigned      :      (unsigned char)__atomic_fetch_or8_explicit((volatile atomic_uchar *)(X), (unsigned char)(Y), M), \
    short              :              (short)__atomic_fetch_or16_explicit((volatile atomic_ushort *)(X), (unsigned short)(Y), M), \
    short unsigned     :     (unsigned short)__atomic_fetch_or16_explicit((volatile atomic_ushort *)(X), (unsigned short)(Y), M), \
    int                :                (int)__atomic_fetch_or32_explicit((volatile atomic_ulong *)(X), (unsigned long)(Y), M), \
    int unsigned       :       (unsigned int)__atomic_fetch_or32_explicit((volatile atomic_ulong *)(X), (unsigned long)(Y), M), \
    long               :               (long)__atomic_fetch_or32_explicit((volatile atomic_ulong *)(X), (unsigned long)(Y), M), \
    long unsigned      :      (unsigned long)__atomic_fetch_or32_explicit((volatile atomic_ulong *)(X), (unsigned long)(Y), M), \
    long long          :          (long long)__atomic_fetch_or64_explicit((volatile atomic_ullong *)(X), (unsigned long long)(Y), M), \
    long long unsigned : (unsigned long long)__atomic_fetch_or64_explicit((volatile atomic_ullong *)(X), (unsigned long long)(Y), M))

extern unsigned char __cdecl __atomic_fetch_or8_explicit(volatile atomic_uchar *, unsigned char, memory_order);
extern unsigned short __cdecl __atomic_fetch_or16_explicit(volatile atomic_ushort *, unsigned short, memory_order);
extern unsigned long __cdecl __atomic_fetch_or32_explicit(volatile atomic_ulong *, unsigned long, memory_order);
extern unsigned long long __cdecl __atomic_fetch_or64_explicit(volatile atomic_ullong *, unsigned long long, memory_order);

#define atomic_fetch_xor_explicit(X,Y,M)  _Generic(*X, \
    char               :               (char)__atomic_fetch_xor8_explicit((volatile atomic_uchar *)(X), (unsigned char)(Y), M), \
    char signed        :        (signed char)__atomic_fetch_xor8_explicit((volatile atomic_uchar *)(X), (unsigned char)(Y), M), \
    char unsigned      :      (unsigned char)__atomic_fetch_xor8_explicit((volatile atomic_uchar *)(X), (unsigned char)(Y), M), \
    short              :              (short)__atomic_fetch_xor16_explicit((volatile atomic_ushort *)(X), (unsigned short)(Y), M), \
    short unsigned     :     (unsigned short)__atomic_fetch_xor16_explicit((volatile atomic_ushort *)(X), (unsigned short)(Y), M), \
    int                :                (int)__atomic_fetch_xor32_explicit((volatile atomic_ulong *)(X), (unsigned long)(Y), M), \
    int unsigned       :       (unsigned int)__atomic_fetch_xor32_explicit((volatile atomic_ulong *)(X), (unsigned long)(Y), M), \
    long               :               (long)__atomic_fetch_xor32_explicit((volatile atomic_ulong *)(X), (unsigned long)(Y), M), \
    long unsigned      :      (unsigned long)__atomic_fetch_xor32_explicit((volatile atomic_ulong *)(X), (unsigned long)(Y), M), \
    long long          :          (long long)__atomic_fetch_xor64_explicit((volatile atomic_ullong *)(X), (unsigned long long)(Y), M), \
    long long unsigned : (unsigned long long)__atomic_fetch_xor64_explicit((volatile atomic_ullong *)(X), (unsigned long long)(Y), M))

extern unsigned char __cdecl __atomic_fetch_xor8_explicit(volatile atomic_uchar *, unsigned char, memory_order);
extern unsigned short __cdecl __atomic_fetch_xor16_explicit(volatile atomic_ushort *, unsigned short, memory_order);
extern unsigned long __cdecl __atomic_fetch_xor32_explicit(volatile atomic_ulong *, unsigned long, memory_order);
extern unsigned long long __cdecl __atomic_fetch_xor64_explicit(volatile atomic_ullong *, unsigned long long, memory_order);

#define atomic_fetch_and_explicit(X,Y,M)  _Generic(*X, \
    char               :               (char)__atomic_fetch_and8_explicit((volatile atomic_uchar *)(X), (unsigned char)(Y), M), \
    char signed        :        (signed char)__atomic_fetch_and8_explicit((volatile atomic_uchar *)(X), (unsigned char)(Y), M), \
    char unsigned      :      (unsigned char)__atomic_fetch_and8_explicit((volatile atomic_uchar *)(X), (unsigned char)(Y), M), \
    short              :              (short)__atomic_fetch_and16_explicit((volatile atomic_ushort *)(X), (unsigned short)(Y), M), \
    short unsigned     :     (unsigned short)__atomic_fetch_and16_explicit((volatile atomic_ushort *)(X), (unsigned short)(Y), M), \
    int                :                (int)__atomic_fetch_and32_explicit((volatile atomic_ulong *)(X), (unsigned long)(Y), M), \
    int unsigned       :       (unsigned int)__atomic_fetch_and32_explicit((volatile atomic_ulong *)(X), (unsigned long)(Y), M), \
    long               :               (long)__atomic_fetch_and32_explicit((volatile atomic_ulong *)(X), (unsigned long)(Y), M), \
    long unsigned      :      (unsigned long)__atomic_fetch_and32_explicit((volatile atomic_ulong *)(X), (unsigned long)(Y), M), \
    long long          :          (long long)__atomic_fetch_and64_explicit((volatile atomic_ullong *)(X), (unsigned long long)(Y), M), \
    long long unsigned : (unsigned long long)__atomic_fetch_and64_explicit((volatile atomic_ullong *)(X), (unsigned long long)(Y), M))

extern unsigned char __cdecl __atomic_fetch_and8_explicit(volatile atomic_uchar *, unsigned char, memory_order);
extern unsigned short __cdecl __atomic_fetch_and16_explicit(volatile atomic_ushort *, unsigned short, memory_order);
extern unsigned long __cdecl __atomic_fetch_and32_explicit(volatile atomic_ulong *, unsigned long, memory_order);
extern unsigned long long __cdecl __atomic_fetch_and64_explicit(volatile atomic_ullong *, unsigned long long, memory_order);

#else /* __POCC_TARGET__ */

#error <stdatomic.h> is not supported on this target

#endif /* __POCC_TARGET__ */

#endif /* __POCC_STDC_VERSION__ >= 201101L */

#endif /* _STDATOMIC_H */
