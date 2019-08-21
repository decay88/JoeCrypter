#ifndef _ADPTIF_H
#define _ADPTIF_H

#if __POCC__ >= 500
#pragma once
#endif

/* Router interface with IPX stack */

#if defined(WIN32_DEFAULT_LIBS) && !defined(_WIN64)
#pragma comment(lib, "adptif.lib")
#endif

#define  GetNicIdx(pReserved)   ((ULONG)*((USHORT*)(pReserved+2)))

typedef struct _ADDRESS_RESERVED {
    UCHAR Reserved[28];
} ADDRESS_RESERVED, *PADDRESS_RESERVED;

HANDLE WINAPI CreateSocketPort(USHORT);
DWORD WINAPI DeleteSocketPort(HANDLE);
DWORD WINAPI IpxRecvPacket(HANDLE,PUCHAR,ULONG,PADDRESS_RESERVED,LPOVERLAPPED,LPOVERLAPPED_COMPLETION_ROUTINE);
DWORD WINAPI IpxSendPacket(HANDLE,ULONG,PUCHAR,ULONG,PADDRESS_RESERVED,LPOVERLAPPED,LPOVERLAPPED_COMPLETION_ROUTINE);

#endif /* _ADPTIF_H */
