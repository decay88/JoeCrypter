#include <rpc.h>
#include <rpcndr.h>

#if (NTDDI_VERSION >= NTDDI_VISTA && !defined(_WIN32_WINNT))
#define _WIN32_WINNT 0x0600
#endif

#if (NTDDI_VERSION >= NTDDI_WS03 && !defined(_WIN32_WINNT))
#define _WIN32_WINNT 0x0502
#endif

#if (NTDDI_VERSION >= NTDDI_WINXP && !defined(_WIN32_WINNT))
#define _WIN32_WINNT 0x0501
#endif

#if (NTDDI_VERSION >= NTDDI_WIN2K && !defined(_WIN32_WINNT))
#define _WIN32_WINNT 0x0500
#endif

#ifndef _OBJBASE_H
#define _OBJBASE_H

/* Windows Component Object Model defintions */

#if __POCC__ >= 500
#pragma once
#endif

#include <pshpack8.h>

#define WINOLEAPI        EXTERN_C DECLSPEC_IMPORT HRESULT STDAPICALLTYPE
#define WINOLEAPI_(type) EXTERN_C DECLSPEC_IMPORT type STDAPICALLTYPE

#ifndef DECLSPEC_RELEASE
#if __POCC__ >= 700
#define DECLSPEC_RELEASE(X)  __declspec(release(X))
#else
#define DECLSPEC_RELEASE(X)
#endif
#endif /* DECLSPEC_RELEASE */

#if defined(__cplusplus) && !defined(CINTERFACE)

#ifdef COM_STDMETHOD_CAN_THROW
#define COM_DECLSPEC_NOTHROW
#else
#define COM_DECLSPEC_NOTHROW DECLSPEC_NOTHROW
#endif

#define __STRUCT__ struct
#define interface __STRUCT__
#define STDMETHOD(method)         virtual COM_DECLSPEC_NOTHROW HRESULT STDMETHODCALLTYPE method
#define STDMETHOD_(type,method)   virtual COM_DECLSPEC_NOTHROW type STDMETHODCALLTYPE method
#define STDMETHODV(method)        virtual COM_DECLSPEC_NOTHROW HRESULT STDMETHODVCALLTYPE method
#define STDMETHODV_(type,method)  virtual COM_DECLSPEC_NOTHROW type STDMETHODVCALLTYPE method
#define PURE  = 0
#define THIS_
#define THIS  void
#define DECLARE_INTERFACE(iface)                       interface DECLSPEC_NOVTABLE iface
#define DECLARE_INTERFACE_(iface, baseiface)           interface DECLSPEC_NOVTABLE iface : public baseiface
#define DECLARE_INTERFACE_IID(iface, iid)              interface DECLSPEC_UUID(iid) DECLSPEC_NOVTABLE iface
#define DECLARE_INTERFACE_IID_(iface, baseiface, iid)  interface DECLSPEC_UUID(iid) DECLSPEC_NOVTABLE iface : public baseiface

#define IFACEMETHOD(method)         __override STDMETHOD(method)
#define IFACEMETHOD_(type,method)   __override STDMETHOD_(type,method)
#define IFACEMETHODV(method)        __override STDMETHODV(method)
#define IFACEMETHODV_(type,method)  __override STDMETHODV_(type,method)

#if !defined(BEGIN_INTERFACE)
#define BEGIN_INTERFACE
#define END_INTERFACE
#endif

extern "C++"
{
    template<typename T> void** IID_PPV_ARGS_Helper(T** pp) 
    {
        static_cast<IUnknown*>(*pp);
        return reinterpret_cast<void**>(pp);
    }
}

#define IID_PPV_ARGS(ppType)  __uuidof(**(ppType)), IID_PPV_ARGS_Helper(ppType)

#else

#define interface  struct

#define STDMETHOD(method)  HRESULT (STDMETHODCALLTYPE * method)
#define STDMETHOD_(type,method)  type (STDMETHODCALLTYPE * method)
#define STDMETHODV(method)  HRESULT (STDMETHODVCALLTYPE * method)
#define STDMETHODV_(type,method)  type (STDMETHODVCALLTYPE * method)

#define IFACEMETHOD(method)   __override STDMETHOD(method)
#define IFACEMETHOD_(type,method)  __override STDMETHOD_(type,method)
#define IFACEMETHODV(method)  __override STDMETHODV(method)
#define IFACEMETHODV_(type,method)  __override STDMETHODV_(type,method)

#if !defined(BEGIN_INTERFACE)
#define BEGIN_INTERFACE
#define END_INTERFACE
#endif

#define PURE
#define THIS_  INTERFACE *This,
#define THIS   INTERFACE *This
#ifdef CONST_VTABLE
#undef CONST_VTBL
#define CONST_VTBL const
#define DECLARE_INTERFACE(iface) \
    typedef interface iface { \
        const struct iface##Vtbl FAR* lpVtbl; \
    } iface; \
    typedef const struct iface##Vtbl iface##Vtbl; \
    const struct iface##Vtbl
#else
#undef CONST_VTBL
#define CONST_VTBL
#define DECLARE_INTERFACE(iface) \
    typedef interface iface { \
        struct iface##Vtbl FAR* lpVtbl; \
    } iface; \
    typedef struct iface##Vtbl iface##Vtbl; \
    struct iface##Vtbl
#endif
#define DECLARE_INTERFACE_(iface, baseiface)  DECLARE_INTERFACE(iface)
#define DECLARE_INTERFACE_IID(iface, iid)  DECLARE_INTERFACE(iface)
#define DECLARE_INTERFACE_IID_(iface, baseiface, iid)  DECLARE_INTERFACE_(iface, baseiface)
#endif

#ifndef FARSTRUCT
#ifdef __cplusplus
#define FARSTRUCT  FAR
#else
#define FARSTRUCT
#endif /* __cplusplus */
#endif /* FARSTRUCT */

#ifndef HUGEP
#define HUGEP
#endif /* HUGEP */

#include <stdlib.h>

#define LISet32(li,v)  ((li).HighPart = ((LONG) (v)) < 0 ? -1 : 0, (li).LowPart = (v))
#define ULISet32(li,v)  ((li).HighPart = 0, (li).LowPart = (v))

#define CLSCTX_INPROC  (CLSCTX_INPROC_SERVER|CLSCTX_INPROC_HANDLER)

#if (_WIN32_WINNT >= 0x0400 ) || defined(_WIN32_DCOM)
#define CLSCTX_ALL  (CLSCTX_INPROC_SERVER|CLSCTX_INPROC_HANDLER|CLSCTX_LOCAL_SERVER|CLSCTX_REMOTE_SERVER)
#define CLSCTX_SERVER  (CLSCTX_INPROC_SERVER|CLSCTX_LOCAL_SERVER|CLSCTX_REMOTE_SERVER)
#else
#define CLSCTX_ALL  (CLSCTX_INPROC_SERVER|CLSCTX_INPROC_HANDLER|CLSCTX_LOCAL_SERVER)
#define CLSCTX_SERVER  (CLSCTX_INPROC_SERVER|CLSCTX_LOCAL_SERVER)
#endif

typedef enum tagREGCLS {
    REGCLS_SINGLEUSE = 0,
    REGCLS_MULTIPLEUSE = 1,
    REGCLS_MULTI_SEPARATE = 2,
    REGCLS_SUSPENDED = 4,
    REGCLS_SURROGATE = 8
} REGCLS;

#define MARSHALINTERFACE_MIN  500

#define CWCSTORAGENAME  32

#define STGM_DIRECT  0x00000000L
#define STGM_TRANSACTED  0x00010000L
#define STGM_SIMPLE  0x08000000L

#define STGM_READ  0x00000000L
#define STGM_WRITE  0x00000001L
#define STGM_READWRITE  0x00000002L

#define STGM_SHARE_DENY_NONE  0x00000040L
#define STGM_SHARE_DENY_READ  0x00000030L
#define STGM_SHARE_DENY_WRITE  0x00000020L
#define STGM_SHARE_EXCLUSIVE  0x00000010L

#define STGM_PRIORITY  0x00040000L
#define STGM_DELETEONRELEASE  0x04000000L
#if (WINVER >= 400)
#define STGM_NOSCRATCH  0x00100000L
#endif /* WINVER */

#define STGM_CREATE  0x00001000L
#define STGM_CONVERT  0x00020000L
#define STGM_FAILIFTHERE  0x00000000L

#define STGM_NOSNAPSHOT  0x00200000L
#if (_WIN32_WINNT >= 0x0500)
#define STGM_DIRECT_SWMR  0x00400000L
#endif

#define ASYNC_MODE_COMPATIBILITY  0x00000001L
#define ASYNC_MODE_DEFAULT  0x00000000L

#define STGTY_REPEAT  0x00000100L
#define STG_TOEND  0xFFFFFFFFL

#define STG_LAYOUT_SEQUENTIAL  0x00000000L
#define STG_LAYOUT_INTERLEAVED  0x00000001L

typedef DWORD STGFMT;

#define STGFMT_STORAGE  0
#define STGFMT_NATIVE  1
#define STGFMT_FILE  3
#define STGFMT_ANY  4
#define STGFMT_DOCFILE  5

#define STGFMT_DOCUMENT  0

typedef interface IRpcStubBuffer IRpcStubBuffer;
typedef interface IRpcChannelBuffer IRpcChannelBuffer;

#include <wtypes.h>
#include <unknwn.h>
#include <objidl.h>

#include <guiddef.h>

#ifndef INITGUID
#include <cguid.h>
#endif

typedef enum tagCOINIT {
  COINIT_APARTMENTTHREADED = 0x2,
#if (_WIN32_WINNT >= 0x0400) || defined(_WIN32_DCOM)
  COINIT_MULTITHREADED = 0x0,
  COINIT_DISABLE_OLE1DDE = 0x4,
  COINIT_SPEED_OVER_MEMORY = 0x8,
#endif
} COINIT;

WINOLEAPI_(DWORD) CoBuildVersion(VOID);

WINOLEAPI CoInitialize(LPVOID);
WINOLEAPI_(void) CoUninitialize(void);
WINOLEAPI CoGetMalloc(DWORD,LPMALLOC*);
WINOLEAPI_(DWORD) CoGetCurrentProcess(void);
WINOLEAPI CoRegisterMallocSpy(LPMALLOCSPY);
WINOLEAPI CoRevokeMallocSpy(void);
WINOLEAPI CoCreateStandardMalloc(DWORD,IMalloc**);

#if (_WIN32_WINNT >= 0x0400) || defined(_WIN32_DCOM)
WINOLEAPI  CoInitializeEx(LPVOID,DWORD);
WINOLEAPI CoGetCallerTID(LPDWORD);
WINOLEAPI CoGetCurrentLogicalThreadId(GUID*);
#endif /* (_WIN32_WINNT >= 0x0400) || defined(_WIN32_DCOM) */

#if (_WIN32_WINNT >= 0x0501)
WINOLEAPI CoRegisterInitializeSpy(LPINITIALIZESPY,ULARGE_INTEGER*);
WINOLEAPI CoRevokeInitializeSpy(ULARGE_INTEGER);
WINOLEAPI CoGetContextToken(ULONG_PTR*);

typedef enum tagCOMSD {
    SD_LAUNCHPERMISSIONS = 0,
    SD_ACCESSPERMISSIONS = 1,
    SD_LAUNCHRESTRICTIONS = 2,
    SD_ACCESSRESTRICTIONS = 3
} COMSD;

WINOLEAPI CoGetSystemSecurityPermissions(COMSD,PSECURITY_DESCRIPTOR*);
#endif /* (_WIN32_WINNT >= 0x0501) */

#if (_WIN32_WINNT >= _NT_TARGET_VERSION_WIN7)
WINOLEAPI CoGetApartmentType(APTTYPE*,APTTYPEQUALIFIER*);
#endif /* _WIN32_WINNT >= _NT_TARGET_VERSION_WIN7 */

#if DBG == 1
WINOLEAPI_(ULONG) DebugCoGetRpcFault(void);
WINOLEAPI_(void) DebugCoSetRpcFault(ULONG);
#endif

#if (_WIN32_WINNT >= 0x0500)
typedef struct tagSOleTlsDataPublic {
    void *pvReserved0[2];
    DWORD dwReserved0[3];
    void *pvReserved1[1];
    DWORD dwReserved1[3];
    void *pvReserved2[4];
    DWORD dwReserved2[1];
    void *pCurrentCtx;
} SOleTlsDataPublic;
#endif /* (_WIN32_WINNT >= 0x0500) */

WINOLEAPI CoGetObjectContext(REFIID,LPVOID*);
WINOLEAPI CoGetClassObject(REFCLSID,DWORD,LPVOID,REFIID,LPVOID*);
WINOLEAPI CoRegisterClassObject(REFCLSID,LPUNKNOWN,DWORD,DWORD,LPDWORD);
WINOLEAPI CoRevokeClassObject(DWORD);
WINOLEAPI CoResumeClassObjects(void);
WINOLEAPI CoSuspendClassObjects(void);
WINOLEAPI_(ULONG) CoAddRefServerProcess(void);
WINOLEAPI_(ULONG) CoReleaseServerProcess(void);
WINOLEAPI CoGetPSClsid(REFIID,CLSID*);
WINOLEAPI CoRegisterPSClsid(REFIID,REFCLSID);
WINOLEAPI CoRegisterSurrogate(LPSURROGATE);
WINOLEAPI CoGetMarshalSizeMax(ULONG*,REFIID,LPUNKNOWN,DWORD,LPVOID,DWORD);
WINOLEAPI CoMarshalInterface(LPSTREAM,REFIID,LPUNKNOWN,DWORD,LPVOID,DWORD);
WINOLEAPI CoUnmarshalInterface(LPSTREAM,REFIID,LPVOID*);
WINOLEAPI CoMarshalHresult(LPSTREAM,HRESULT);
WINOLEAPI CoUnmarshalHresult(LPSTREAM,HRESULT*);
WINOLEAPI CoReleaseMarshalData(LPSTREAM);
WINOLEAPI CoDisconnectObject(LPUNKNOWN,DWORD);
WINOLEAPI CoLockObjectExternal(LPUNKNOWN,BOOL,BOOL);
WINOLEAPI CoGetStandardMarshal(REFIID,LPUNKNOWN,DWORD,LPVOID,DWORD,LPMARSHAL*);
WINOLEAPI CoGetStdMarshalEx(LPUNKNOWN,DWORD,LPUNKNOWN*);

typedef enum tagSTDMSHLFLAGS {
    SMEXF_SERVER = 0x01,
    SMEXF_HANDLER = 0x02
} STDMSHLFLAGS;

WINOLEAPI_(BOOL) CoIsHandlerConnected(LPUNKNOWN);
WINOLEAPI CoMarshalInterThreadInterfaceInStream(REFIID,LPUNKNOWN,LPSTREAM*);
WINOLEAPI CoGetInterfaceAndReleaseStream(LPSTREAM,REFIID,LPVOID*);
WINOLEAPI CoCreateFreeThreadedMarshaler(LPUNKNOWN,LPUNKNOWN *);

WINOLEAPI_(HINSTANCE) CoLoadLibrary(LPOLESTR,BOOL);
WINOLEAPI_(void) CoFreeLibrary(HINSTANCE);
WINOLEAPI_(void) CoFreeAllLibraries(void);
WINOLEAPI_(void) CoFreeUnusedLibraries(void);
#if (_WIN32_WINNT >= 0x0501)
WINOLEAPI_(void) CoFreeUnusedLibrariesEx(DWORD,DWORD);
#endif /* (_WIN32_WINNT >= 0x0501) */

#if (_WIN32_WINNT >= 0x0600)
WINOLEAPI CoDisconnectContext(DWORD);
#endif /* (_WIN32_WINNT >= 0x0600) */

#if (_WIN32_WINNT >= 0x0400 ) || defined(_WIN32_DCOM)
WINOLEAPI CoInitializeSecurity(PSECURITY_DESCRIPTOR,LONG,SOLE_AUTHENTICATION_SERVICE*,void*,DWORD,DWORD,void*,DWORD,void*);
WINOLEAPI CoGetCallContext(REFIID,void**);
WINOLEAPI CoQueryProxyBlanket(IUnknown*,DWORD*,DWORD*,OLECHAR**,DWORD*,DWORD*,RPC_AUTH_IDENTITY_HANDLE*,DWORD*);
WINOLEAPI CoSetProxyBlanket(IUnknown*,DWORD,DWORD,OLECHAR*,DWORD,DWORD,RPC_AUTH_IDENTITY_HANDLE,DWORD);
WINOLEAPI CoCopyProxy(IUnknown*,IUnknown**);
WINOLEAPI CoQueryClientBlanket(DWORD*,DWORD*,OLECHAR**,DWORD*,DWORD*,RPC_AUTHZ_HANDLE*,DWORD*);
WINOLEAPI CoImpersonateClient(void);
WINOLEAPI CoRevertToSelf(void);
WINOLEAPI CoQueryAuthenticationServices(DWORD*,SOLE_AUTHENTICATION_SERVICE**);
WINOLEAPI CoSwitchCallContext(IUnknown*,IUnknown **);

#define COM_RIGHTS_EXECUTE 1
#define COM_RIGHTS_EXECUTE_LOCAL 2
#define COM_RIGHTS_EXECUTE_REMOTE 4
#define COM_RIGHTS_ACTIVATE_LOCAL 8
#define COM_RIGHTS_ACTIVATE_REMOTE 16
#endif /* (_WIN32_WINNT >= 0x0400 ) || defined(_WIN32_DCOM) */

WINOLEAPI CoCreateInstance(REFCLSID,LPUNKNOWN,DWORD,REFIID,LPVOID*);

#if (_WIN32_WINNT >= 0x0400 ) || defined(_WIN32_DCOM)
WINOLEAPI CoGetInstanceFromFile(COSERVERINFO*,CLSID*,IUnknown*,DWORD,DWORD,OLECHAR*,DWORD,MULTI_QI*);
WINOLEAPI CoGetInstanceFromIStorage(COSERVERINFO*,CLSID*,IUnknown*,DWORD,struct IStorage*,DWORD,MULTI_QI*);
WINOLEAPI CoCreateInstanceEx(REFCLSID,IUnknown*,DWORD,COSERVERINFO*,DWORD,MULTI_QI*);
#endif /* (_WIN32_WINNT >= 0x0400 ) || defined(_WIN32_DCOM) */

#if (_WIN32_WINNT >= 0x0500 ) || defined(_WIN32_DCOM)
WINOLEAPI CoGetCancelObject(DWORD,REFIID,void **);
WINOLEAPI CoSetCancelObject(IUnknown *);
WINOLEAPI CoCancelCall(DWORD,ULONG);
WINOLEAPI CoTestCancel(void);
WINOLEAPI CoEnableCallCancellation(LPVOID);
WINOLEAPI CoDisableCallCancellation(LPVOID);
WINOLEAPI CoAllowSetForegroundWindow(IUnknown *,LPVOID);
WINOLEAPI DcomChannelSetHResult(LPVOID,ULONG*,HRESULT);
#endif /* (_WIN32_WINNT >= 0x0500 ) || defined(_WIN32_DCOM) */

WINOLEAPI StringFromCLSID(REFCLSID,LPOLESTR*);
WINOLEAPI CLSIDFromString(LPOLESTR,LPCLSID);
WINOLEAPI StringFromIID(REFIID,LPOLESTR*);
WINOLEAPI IIDFromString(LPOLESTR,LPIID);
WINOLEAPI_(BOOL) CoIsOle1Class(REFCLSID);
WINOLEAPI ProgIDFromCLSID(REFCLSID,LPOLESTR*);
WINOLEAPI CLSIDFromProgID(LPCOLESTR,LPCLSID);
WINOLEAPI CLSIDFromProgIDEx(LPCOLESTR,LPCLSID);
WINOLEAPI_(int) StringFromGUID2(REFGUID,LPOLESTR,int);
WINOLEAPI CoCreateGuid(GUID*);
WINOLEAPI_(BOOL) CoFileTimeToDosDateTime(FILETIME*,LPWORD,LPWORD);
WINOLEAPI_(BOOL) CoDosDateTimeToFileTime(WORD,WORD,FILETIME*);
WINOLEAPI  CoFileTimeNow(FILETIME*);
WINOLEAPI CoRegisterMessageFilter(LPMESSAGEFILTER,LPMESSAGEFILTER*);

#if (_WIN32_WINNT >= 0x0400 ) || defined(_WIN32_DCOM)
WINOLEAPI CoRegisterChannelHook( REFGUID,IChannelHook*);
#endif /* (_WIN32_WINNT >= 0x0400 ) || defined(_WIN32_DCOM) */

#if (_WIN32_WINNT >= 0x0400 ) || defined(_WIN32_DCOM)
WINOLEAPI CoWaitForMultipleHandles(DWORD,DWORD,ULONG,LPHANDLE,LPDWORD);

typedef enum tagCOWAIT_FLAGS {
    COWAIT_WAITALL = 1,
    COWAIT_ALERTABLE = 2,
    COWAIT_INPUTAVAILABLE = 4
} COWAIT_FLAGS;
#endif

#if  (_WIN32_WINNT >= 0x0501)
WINOLEAPI CoInvalidateRemoteMachineBindings(LPOLESTR);
#endif

WINOLEAPI CoGetTreatAsClass(REFCLSID, LPCLSID);
WINOLEAPI CoTreatAsClass(REFCLSID, REFCLSID);

typedef HRESULT (STDAPICALLTYPE * LPFNGETCLASSOBJECT) (REFCLSID, REFIID, LPVOID *);
typedef HRESULT (STDAPICALLTYPE * LPFNCANUNLOADNOW)(void);

STDAPI  DllGetClassObject(REFCLSID,REFIID,LPVOID*);
STDAPI  DllCanUnloadNow(void);

WINOLEAPI_(LPVOID) CoTaskMemAlloc(SIZE_T);
WINOLEAPI_(LPVOID) CoTaskMemRealloc(LPVOID,SIZE_T);
DECLSPEC_RELEASE(1) WINOLEAPI_(void) CoTaskMemFree(LPVOID);

WINOLEAPI CreateDataAdviseHolder(LPDATAADVISEHOLDER*);
WINOLEAPI CreateDataCache(LPUNKNOWN,REFCLSID,REFIID,LPVOID*);

WINOLEAPI StgCreateDocfile(const WCHAR*,DWORD,DWORD,IStorage**);
WINOLEAPI StgCreateDocfileOnILockBytes(ILockBytes*,DWORD,DWORD,IStorage**);
WINOLEAPI StgOpenStorage(const WCHAR*,IStorage*,DWORD,SNB,DWORD,IStorage**);
WINOLEAPI StgOpenStorageOnILockBytes(ILockBytes*,IStorage*,DWORD,SNB,DWORD,IStorage**);
WINOLEAPI StgIsStorageFile(const WCHAR*);
WINOLEAPI StgIsStorageILockBytes(ILockBytes*);
WINOLEAPI StgSetTimes(const WCHAR*,const FILETIME*,const FILETIME*,const FILETIME*);
WINOLEAPI StgOpenAsyncDocfileOnIFillLockBytes(IFillLockBytes*,DWORD,DWORD,IStorage**);
WINOLEAPI StgGetIFillLockBytesOnILockBytes(ILockBytes*,IFillLockBytes**);
WINOLEAPI StgGetIFillLockBytesOnFile(OLECHAR const *,IFillLockBytes**);
WINOLEAPI StgOpenLayoutDocfile(OLECHAR const *,DWORD,DWORD,IStorage**);

#if _WIN32_WINNT == 0x500
#define STGOPTIONS_VERSION  1
#elif _WIN32_WINNT > 0x500
#define STGOPTIONS_VERSION  2
#else
#define STGOPTIONS_VERSION  0
#endif

typedef struct tagSTGOPTIONS {
    USHORT usVersion;
    USHORT reserved;
    ULONG ulSectorSize;
#if STGOPTIONS_VERSION >= 2
    const WCHAR *pwcsTemplateFile;
#endif
} STGOPTIONS;

WINOLEAPI StgCreateStorageEx (const WCHAR *,DWORD,DWORD,DWORD,STGOPTIONS*,PSECURITY_DESCRIPTOR,REFIID,void**);
WINOLEAPI StgOpenStorageEx(const WCHAR*,DWORD,DWORD,DWORD,STGOPTIONS*,PSECURITY_DESCRIPTOR,REFIID,void**);

WINOLEAPI BindMoniker(LPMONIKER,DWORD,REFIID,LPVOID*);
WINOLEAPI CoInstall(IBindCtx*,DWORD,uCLSSPEC*,QUERYCONTEXT*,LPWSTR);
WINOLEAPI CoGetObject(LPCWSTR,BIND_OPTS*,REFIID,void**);
WINOLEAPI MkParseDisplayName(LPBC,LPCOLESTR,ULONG*,LPMONIKER*);
WINOLEAPI MonikerRelativePathTo(LPMONIKER,LPMONIKER,LPMONIKER*,BOOL);
WINOLEAPI MonikerCommonPrefixWith(LPMONIKER,LPMONIKER,LPMONIKER*);
WINOLEAPI CreateBindCtx(DWORD,LPBC*);
WINOLEAPI CreateGenericComposite(LPMONIKER,LPMONIKER,LPMONIKER*);
WINOLEAPI GetClassFile(LPCOLESTR,CLSID*);
WINOLEAPI CreateClassMoniker(REFCLSID,LPMONIKER*);
WINOLEAPI CreateFileMoniker(LPCOLESTR,LPMONIKER*);
WINOLEAPI CreateItemMoniker(LPCOLESTR,LPCOLESTR,LPMONIKER*);
WINOLEAPI CreateAntiMoniker(LPMONIKER*);
WINOLEAPI CreatePointerMoniker(LPUNKNOWN,LPMONIKER*);
WINOLEAPI CreateObjrefMoniker(LPUNKNOWN,LPMONIKER*);
WINOLEAPI GetRunningObjectTable(DWORD,LPRUNNINGOBJECTTABLE*);

#include <urlmon.h>
#include <propidl.h>

WINOLEAPI CreateStdProgressIndicator(HWND,LPCOLESTR,IBindStatusCallback*,IBindStatusCallback**);

#include <poppack.h>

#endif /* _OBJBASE_H */
