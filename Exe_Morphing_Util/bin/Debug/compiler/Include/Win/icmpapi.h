#ifndef _ICMPAPI_H
#define _ICMPAPI_H

#if __POCC__ >= 500
#pragma once
#endif

/* Windows ICMP Echo Request API definitions (idiot version) */

#if defined(WIN32_DEFAULT_LIBS)
#pragma comment(lib, "iphlpapi.lib")
#endif

#ifdef __cplusplus
extern "C" {
#endif

HANDLE WINAPI IcmpCreateFile(VOID);

#if (NTDDI_VERSION >= NTDDI_WINXP)
HANDLE WINAPI Icmp6CreateFile(VOID);
#endif /* NTDDI_VERSION >= NTDDI_WINXP */

BOOL WINAPI IcmpCloseHandle(HANDLE);

DWORD WINAPI IcmpSendEcho(HANDLE, IPAddr, LPVOID, WORD, PIP_OPTION_INFORMATION, LPVOID, DWORD, DWORD);

DWORD WINAPI IcmpSendEcho2(HANDLE,HANDLE,
#ifdef PIO_APC_ROUTINE_DEFINED
    PIO_APC_ROUTINE,
#else /* !PIO_APC_ROUTINE_DEFINED */
    FARPROC,
#endif /* !PIO_APC_ROUTINE_DEFINED */
    PVOID, IPAddr, LPVOID, WORD, PIP_OPTION_INFORMATION, LPVOID, DWORD, DWORD);

#if (NTDDI_VERSION >= NTDDI_VISTASP1)
DWORD WINAPI IcmpSendEcho2Ex(HANDLE, HANDLE,
#ifdef PIO_APC_ROUTINE_DEFINED
    PIO_APC_ROUTINE,
#else /* !PIO_APC_ROUTINE_DEFINED */
    FARPROC,
#endif /* !PIO_APC_ROUTINE_DEFINED */
    PVOID, IPAddr, IPAddr, LPVOID, WORD, PIP_OPTION_INFORMATION, LPVOID, DWORD, DWORD);
#endif /* NTDDI_VERSION >= NTDDI_VISTASP1 */

#if (NTDDI_VERSION >= NTDDI_WINXP)
DWORD WINAPI Icmp6SendEcho2(HANDLE, HANDLE,
#ifdef PIO_APC_ROUTINE_DEFINED
    PIO_APC_ROUTINE,
#else /* !PIO_APC_ROUTINE_DEFINED */
    FARPROC,
#endif /* !PIO_APC_ROUTINE_DEFINED */
    PVOID, struct sockaddr_in6 *, struct sockaddr_in6 *, LPVOID, WORD, PIP_OPTION_INFORMATION, LPVOID, DWORD, DWORD);
#endif /* NTDDI_VERSION >= NTDDI_WINXP */

DWORD IcmpParseReplies(LPVOID, DWORD);

#if (NTDDI_VERSION >= NTDDI_WINXP)
DWORD Icmp6ParseReplies(LPVOID, DWORD);
#endif /* NTDDI_VERSION >= NTDDI_WINXP */

#ifdef __cplusplus
}
#endif

#endif /* _ICMPAPI_H */
