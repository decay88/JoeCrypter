#ifndef _UNISTD_H
#define _UNISTD_H

/* unistd.h - private "POSIX" header */

#if __POCC__ >= 500
#pragma once
#endif

#ifndef __POCC__OLDNAMES
#pragma message("<unistd.h> require the -Go compiler option!")
#else /* __POCC__OLDNAMES */

/* macros */
#ifndef NULL
#define NULL  ((void *)0)
#endif

/* constants for access() */
#define F_OK  0x0000
#define X_OK  0x0001
#define W_OK  0x0002
#define R_OK  0x0004

/* constants for lseek() */
#define SEEK_SET  0
#define SEEK_CUR  1
#define SEEK_END  2

/* constants for streams */
#define STDIN_FILENO  0
#define STDOUT_FILENO  1
#define STDERR_FILENO  2

/* type definitions */
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
typedef long long off_t;
#else
typedef long _off_t;
typedef long off_t;
#endif /* __POCC_TARGET */
#endif /* _OFF_T_DEFINED */

#ifndef _SSIZE_T_DEFINED
#define _SSIZE_T_DEFINED
#if __POCC_TARGET__ == 3
typedef long long _ssize_t;
typedef long long ssize_t;
#else
typedef int _ssize_t;
typedef int ssize_t;
#endif /* __POCC_TARGET */
#endif /* SSIZE_T_DEFINED */

#ifndef _INTPTR_T_DEFINED
#define _INTPTR_T_DEFINED
#if __POCC_TARGET__ == 3
typedef signed long long intptr_t;  /* see stdint.h */
#else
typedef signed int intptr_t;  /* see stdint.h */
#endif /* __POCC_TARGET */
#endif /* _INTPTR_T_DEFINED */

/* uid_t */
/* gid_t */
/* pid_t */
/* useconds_t */

/* data declarations */
extern char *optarg;
extern int optind, opterr, optopt;

/* declarations */
extern int __cdecl access(const char *, int);
/* unsigned alarm(unsigned); */
extern int __cdecl chdir(const char *);
/* int chown(const char *, uid_t, gid_t); */
extern int __cdecl close(int);
/* size_t confstr(int, char *, size_t); */
extern int __cdecl dup(int);
extern int __cdecl dup2(int, int);
extern intptr_t /*int*/ __cdecl execl(const char *, const char *, ...);
extern intptr_t /*int*/ __cdecl execle(const char *, const char *, ...);
extern intptr_t /*int*/ __cdecl execlp(const char *, const char *, ...);
extern intptr_t /*int*/ __cdecl execv(const char *, char * const *);
extern intptr_t /*int*/ __cdecl execve(const char *, char * const *, char * const *);
extern intptr_t /*int*/ __cdecl execvp(const char *, char * const *);
/* void _exit(int); */
/* int fchown(int, uid_t, gid_t); */
/* pid_t fork(void); */
/* long fpathconf(int, int); */
extern int __cdecl ftruncate(int, off_t);
extern char * __cdecl getcwd(char *, size_t);
/* gid_t getegid(void); */
/* uid_t geteuid(void); */
/* gid_t getgid(void); */
/* int getgroups(int, gid_t []); */
/* int gethostname(char *, size_t); */
/* char *getlogin(void); */
/* int getlogin_r(char *, size_t); */
extern int __cdecl getopt(int, char * const [], const char *);
/* pid_t getpgrp(void); */
/* pid_t getpid(void); */
/* pid_t getppid(void); */
/* uid_t getuid(void); */
extern int __cdecl isatty(int);
/* int link(const char *, const char *); */
extern off_t __cdecl lseek(int, off_t, int);
extern int __cdecl open(const char *, int, ...);
/* long pathconf(const char *, int); */
/* int pause(void); */
/* int pipe(int [2]); */
extern ssize_t __cdecl read(int, void *, size_t);
/* ssize_t readlink(const char * restrict, char * restrict, size_t); */
extern int __cdecl rmdir(const char *);
/* int setegid(gid_t); */
/* int seteuid(uid_t); */
/* int setgid(gid_t); */
/* int setpgid(pid_t, pid_t); */
/* pid_t setsid(void); */
/* int setuid(uid_t); */
extern unsigned int sleep(unsigned int);
/* int symlink(const char *, const char *); */
/* long sysconf(int); */
/* pid_t tcgetpgrp(int); */
/* int tcsetpgrp(int, pid_t); */
/* char *ttyname(int); */
/* int ttyname_r(int, char *, size_t); */
extern int __cdecl unlink(const char *);
extern ssize_t __cdecl write(int, const void *, size_t);

#endif /* __POCC__OLDNAMES */

#endif /* _UNISTD_H */
