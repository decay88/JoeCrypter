#ifndef _EXCPT_H
#define _EXCPT_H

/* excpt.h - private header for SEH definitions */

#if __POCC__ >= 500
#pragma once
#endif

#define EXCEPTION_EXECUTE_HANDLER  1
#define EXCEPTION_CONTINUE_SEARCH  0
#define EXCEPTION_CONTINUE_EXECUTION  (-1)

typedef enum _EXCEPTION_DISPOSITION {
    ExceptionContinueExecution,
    ExceptionContinueSearch,
    ExceptionNestedException,
    ExceptionCollidedUnwind,
    ExceptionExecuteHandler
} EXCEPTION_DISPOSITION;

/* keep compiler happy */
struct _EXCEPTION_POINTERS;
struct _EXCEPTION_RECORD;
struct _CONTEXT;

#if __POCC_TARGET__ == 1
EXCEPTION_DISPOSITION __cdecl _except_handler(struct _EXCEPTION_RECORD *, void *, struct _CONTEXT *, void *);
#elif __POCC_TARGET__ == 3
struct _DISPATCHER_CONTEXT;  /* keep smiling */
EXCEPTION_DISPOSITION __C_specific_handler(struct _EXCEPTION_RECORD *, void *, struct _CONTEXT *, struct _DISPATCHER_CONTEXT *);
#endif /* __POCC_TARGET__ */

/* declarations */
extern unsigned long __cdecl _exception_code(void);
extern void * __cdecl _exception_info(void);
extern int __cdecl _abnormal_termination(void);

/* macros */
#define GetExceptionCode  _exception_code
#define exception_code  _exception_code
#define GetExceptionInformation  (struct _EXCEPTION_POINTERS *)_exception_info
#define exception_info  (struct _EXCEPTION_POINTERS *)_exception_info
#define AbnormalTermination  _abnormal_termination
#define abnormal_termination  _abnormal_termination

#endif /* _EXCPT_H */
