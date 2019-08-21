#ifndef _FAXROUTE_H
#define _FAXROUTE_H

#if __POCC__ >= 500
#pragma once
#endif

/* FAX routing extension API definitions */

#include <commctrl.h>

#ifdef __cplusplus
extern "C" {
#endif

#define MS_FAXROUTE_PRINTING_GUID  TEXT("{aec1b37c-9af2-11d0-abf7-00c04fd91a4e}")
#define MS_FAXROUTE_INBOX_GUID  TEXT("{9d3d0c32-9af2-11d0-abf7-00c04fd91a4e}")
#define MS_FAXROUTE_FOLDER_GUID  TEXT("{92041a90-9af2-11d0-abf7-00c04fd91a4e}")
#define MS_FAXROUTE_EMAIL_GUID  TEXT("{6bbf7bfe-9af2-11d0-abf7-00c04fd91a4e}")

typedef LONG (WINAPI *PFAXROUTEADDFILE)(DWORD,LPCWSTR,GUID*);
typedef LONG (WINAPI *PFAXROUTEDELETEFILE)(DWORD,LPCWSTR);
typedef BOOL (WINAPI *PFAXROUTEGETFILE)(DWORD,DWORD,LPWSTR,LPDWORD);
typedef BOOL (WINAPI *PFAXROUTEENUMFILE)(DWORD,GUID*,GUID*,LPCWSTR,PVOID);
typedef BOOL (WINAPI *PFAXROUTEENUMFILES)(DWORD,GUID*,PFAXROUTEENUMFILE,PVOID);
typedef BOOL (WINAPI *PFAXROUTEMODIFYROUTINGDATA)(DWORD,LPCWSTR,LPBYTE,DWORD);

typedef struct _FAX_ROUTE_CALLBACKROUTINES {
    DWORD SizeOfStruct;
    PFAXROUTEADDFILE FaxRouteAddFile;
    PFAXROUTEDELETEFILE FaxRouteDeleteFile;
    PFAXROUTEGETFILE FaxRouteGetFile;
    PFAXROUTEENUMFILES FaxRouteEnumFiles;
    PFAXROUTEMODIFYROUTINGDATA FaxRouteModifyRoutingData;
} FAX_ROUTE_CALLBACKROUTINES, *PFAX_ROUTE_CALLBACKROUTINES;

typedef struct _FAX_ROUTE {
    DWORD SizeOfStruct;
    DWORD JobId;
    DWORDLONG ElapsedTime;
    DWORDLONG ReceiveTime;
    DWORD PageCount;
    LPCWSTR Csid;
    LPCWSTR Tsid;
    LPCWSTR CallerId;
    LPCWSTR RoutingInfo;
    LPCWSTR ReceiverName;
    LPCWSTR ReceiverNumber;
    LPCWSTR DeviceName;
    DWORD DeviceId;
    LPBYTE RoutingInfoData;
    DWORD RoutingInfoDataSize;
} FAX_ROUTE, *PFAX_ROUTE;

enum FAXROUTE_ENABLE {
    QUERY_STATUS = -1,
    STATUS_DISABLE = 0,
    STATUS_ENABLE = 1
};

typedef BOOL (WINAPI *PFAXROUTEINITIALIZE)(HANDLE,PFAX_ROUTE_CALLBACKROUTINES);
typedef BOOL (WINAPI *PFAXROUTEMETHOD)(const FAX_ROUTE*,PVOID*,LPDWORD);
typedef BOOL (WINAPI *PFAXROUTEDEVICEENABLE)(LPCWSTR,DWORD,LONG);
typedef BOOL (WINAPI *PFAXROUTEDEVICECHANGENOTIFICATION)(DWORD,BOOL);
typedef BOOL (WINAPI *PFAXROUTEGETROUTINGINFO)(LPCWSTR,DWORD,LPBYTE,LPDWORD);
typedef BOOL (WINAPI *PFAXROUTESETROUTINGINFO)(LPCWSTR,DWORD,const BYTE*,DWORD);

BOOL WINAPI FaxRouteInitialize(HANDLE,PFAX_ROUTE_CALLBACKROUTINES);
BOOL WINAPI FaxRouteDeviceEnable(LPCWSTR,DWORD,LONG);
BOOL WINAPI FaxRouteDeviceChangeNotification(DWORD,BOOL);
BOOL WINAPI FaxRouteGetRoutingInfo(LPCWSTR,DWORD,LPBYTE,LPDWORD);
BOOL WINAPI FaxRouteSetRoutingInfo(LPCWSTR,DWORD,const BYTE*,DWORD);

#ifdef __cplusplus
}
#endif

#endif /* _FAXROUTE_H */
