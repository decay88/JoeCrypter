#ifndef _SYS_WAIT_H
#define _SYS_WAIT_H

/* sys/wait.h - private header for waiting */

#if __POCC__ >= 500
#pragma once
#endif

#include <sys/types.h>

/* flags for _waitpid() */
#define _WNOHANG    0x0001
#define _WUNTRACED  0x0002

#define _WIFEXITED(n)  ((n) != -1)
#define _WEXITSTATUS(n)  (n)
#define _WIFSIGNALED(n)  (0)
#define _WTERMSIG(n)  (0)
#define _WIFSTOPPED(n)  (0)
#define _WSTOPSIG(n)  (0)

/* pid_t __cdecl _wait(int *); */
_pid_t __cdecl _waitpid(_pid_t, int *, int);

/* compatibility names */
#ifdef __POCC__OLDNAMES
#define WNOHANG  _WNOHANG
#define WUNTRACED  _WUNTRACED

#define WIFEXITED(n)  _WIFEXITED(n)
#define WEXITSTATUS(n)  _WEXITSTATUS(n)
#define WIFSIGNALED(n)  _WIFSIGNALED(n)
#define WTERMSIG(n)  _WTERMSIG(n)
#define WIFSTOPPED(n)  _WIFSTOPPED(n)
#define WSTOPSIG(n)  _WSTOPSIG(n)

/* pid_t  wait(int *); */
pid_t __cdecl waitpid(pid_t, int *, int);
#endif /* __POCC__OLDNAMES */

#endif /* _SYS_WAIT_H */
