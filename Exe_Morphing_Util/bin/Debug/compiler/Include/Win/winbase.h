#ifndef _WINBASE_H
#define _WINBASE_H

#if __POCC__ >= 500
#pragma once
#endif

/* Windows Base API definitions */

#if !defined(_ADVAPI32_)
#define WINADVAPI DECLSPEC_IMPORT
#else
#define WINADVAPI
#endif

#if !defined(_KERNEL32_)
#define WINBASEAPI DECLSPEC_IMPORT
#else
#define WINBASEAPI
#endif

#if !defined(_ZAWPROXY_)
#define ZAWPROXYAPI DECLSPEC_IMPORT
#else
#define ZAWPROXYAPI
#endif

#if defined(WIN32_DEFAULT_LIBS)
#pragma comment(lib, "kernel32.lib")
#pragma comment(lib, "advapi32.lib")
#endif

#ifndef DECLSPEC_RELEASE
#if __POCC__ >= 700
#define DECLSPEC_RELEASE(X)  __declspec(release(X))
#else
#define DECLSPEC_RELEASE(X)
#endif
#endif /* DECLSPEC_RELEASE */

#ifdef __cplusplus
extern "C" {
#endif

#if __POCC__ >= 290
#pragma warn(push)
#pragma warn(disable:2027 2028)  /* Missing prototype */
#pragma warn(disable:2197)  /* 'type' is not a standard bit-field type */
#pragma warn(disable:2198)  /* Nameless field is not standard */
#endif

#define DefineHandleTable(w)  ((w),TRUE)
#define LimitEmsPages(dw)
#define SetSwapAreaSize(w)  (w)
#define LockSegment(w)  GlobalFix((HANDLE)(w))
#define UnlockSegment(w)  GlobalUnfix((HANDLE)(w))
#define GetCurrentTime()  GetTickCount()

#define Yield()

#define INVALID_HANDLE_VALUE ((HANDLE)(LONG_PTR)-1)
#define INVALID_FILE_SIZE ((DWORD)0xFFFFFFFF)
#define INVALID_SET_FILE_POINTER ((DWORD)-1)
#define INVALID_FILE_ATTRIBUTES ((DWORD)-1)

#define FILE_BEGIN  0
#define FILE_CURRENT  1
#define FILE_END  2

#define TIME_ZONE_ID_INVALID ((DWORD)0xFFFFFFFF)

#define WAIT_FAILED ((DWORD)0xFFFFFFFF)
#define WAIT_OBJECT_0  ((STATUS_WAIT_0 ) + 0)

#define WAIT_ABANDONED  ((STATUS_ABANDONED_WAIT_0 ) + 0)
#define WAIT_ABANDONED_0  ((STATUS_ABANDONED_WAIT_0 ) + 0)

#define WAIT_IO_COMPLETION  STATUS_USER_APC
#define STILL_ACTIVE  STATUS_PENDING
#define EXCEPTION_ACCESS_VIOLATION  STATUS_ACCESS_VIOLATION
#define EXCEPTION_DATATYPE_MISALIGNMENT  STATUS_DATATYPE_MISALIGNMENT
#define EXCEPTION_BREAKPOINT  STATUS_BREAKPOINT
#define EXCEPTION_SINGLE_STEP  STATUS_SINGLE_STEP
#define EXCEPTION_ARRAY_BOUNDS_EXCEEDED  STATUS_ARRAY_BOUNDS_EXCEEDED
#define EXCEPTION_FLT_DENORMAL_OPERAND  STATUS_FLOAT_DENORMAL_OPERAND
#define EXCEPTION_FLT_DIVIDE_BY_ZERO  STATUS_FLOAT_DIVIDE_BY_ZERO
#define EXCEPTION_FLT_INEXACT_RESULT  STATUS_FLOAT_INEXACT_RESULT
#define EXCEPTION_FLT_INVALID_OPERATION  STATUS_FLOAT_INVALID_OPERATION
#define EXCEPTION_FLT_OVERFLOW  STATUS_FLOAT_OVERFLOW
#define EXCEPTION_FLT_STACK_CHECK  STATUS_FLOAT_STACK_CHECK
#define EXCEPTION_FLT_UNDERFLOW  STATUS_FLOAT_UNDERFLOW
#define EXCEPTION_INT_DIVIDE_BY_ZERO  STATUS_INTEGER_DIVIDE_BY_ZERO
#define EXCEPTION_INT_OVERFLOW  STATUS_INTEGER_OVERFLOW
#define EXCEPTION_PRIV_INSTRUCTION  STATUS_PRIVILEGED_INSTRUCTION
#define EXCEPTION_IN_PAGE_ERROR  STATUS_IN_PAGE_ERROR
#define EXCEPTION_ILLEGAL_INSTRUCTION  STATUS_ILLEGAL_INSTRUCTION
#define EXCEPTION_NONCONTINUABLE_EXCEPTION  STATUS_NONCONTINUABLE_EXCEPTION
#define EXCEPTION_STACK_OVERFLOW  STATUS_STACK_OVERFLOW
#define EXCEPTION_INVALID_DISPOSITION  STATUS_INVALID_DISPOSITION
#define EXCEPTION_GUARD_PAGE  STATUS_GUARD_PAGE_VIOLATION
#define EXCEPTION_INVALID_HANDLE  STATUS_INVALID_HANDLE
#define EXCEPTION_POSSIBLE_DEADLOCK  STATUS_POSSIBLE_DEADLOCK
#define CONTROL_C_EXIT  STATUS_CONTROL_C_EXIT

#define MoveMemory RtlMoveMemory
#define CopyMemory RtlCopyMemory
#define FillMemory RtlFillMemory
#define ZeroMemory RtlZeroMemory
#define SecureZeroMemory RtlSecureZeroMemory
#define CaptureStackBackTrace RtlCaptureStackBackTrace

#define FILE_FLAG_WRITE_THROUGH  0x80000000
#define FILE_FLAG_OVERLAPPED  0x40000000
#define FILE_FLAG_NO_BUFFERING  0x20000000
#define FILE_FLAG_RANDOM_ACCESS  0x10000000
#define FILE_FLAG_SEQUENTIAL_SCAN  0x08000000
#define FILE_FLAG_DELETE_ON_CLOSE  0x04000000
#define FILE_FLAG_BACKUP_SEMANTICS  0x02000000
#define FILE_FLAG_POSIX_SEMANTICS  0x01000000
#define FILE_FLAG_OPEN_REPARSE_POINT  0x00200000
#define FILE_FLAG_OPEN_NO_RECALL  0x00100000
#define FILE_FLAG_FIRST_PIPE_INSTANCE  0x00080000
#if (_WIN32_WINNT >= _WIN32_WINNT_WIN8)
#define FILE_FLAG_OPEN_REQUIRING_OPLOCK 0x00040000
#endif /* _WIN32_WINNT >= _WIN32_WINNT_WIN8 */

#define CREATE_NEW  1
#define CREATE_ALWAYS  2
#define OPEN_EXISTING  3
#define OPEN_ALWAYS  4
#define TRUNCATE_EXISTING  5

#if (_WIN32_WINNT >= 0x0400)

#define PROGRESS_CONTINUE  0
#define PROGRESS_CANCEL  1
#define PROGRESS_STOP  2
#define PROGRESS_QUIET  3

#define CALLBACK_CHUNK_FINISHED  0x00000000
#define CALLBACK_STREAM_SWITCH  0x00000001

#define COPY_FILE_FAIL_IF_EXISTS  0x00000001
#define COPY_FILE_RESTARTABLE  0x00000002
#define COPY_FILE_OPEN_SOURCE_FOR_WRITE  0x00000004
#define COPY_FILE_ALLOW_DECRYPTED_DESTINATION 0x00000008
#if (_WIN32_WINNT >= 0x0600)
#define COPY_FILE_COPY_SYMLINK  0x00000800
#define COPY_FILE_NO_BUFFERING  0x00001000
#endif /* _WIN32_WINNT >= 0x0600 */
#if (_WIN32_WINNT >= _WIN32_WINNT_WIN8)
#define COPY_FILE_REQUEST_SECURITY_PRIVILEGES  0x00002000
#define COPY_FILE_RESUME_FROM_PAUSE  0x00004000
#define COPY_FILE_NO_OFFLOAD  0x00040000
#endif /* _WIN32_WINNT >= _WIN32_WINNT_WIN8 */

#endif /* _WIN32_WINNT >= 0x0400 */

#if (_WIN32_WINNT >= 0x0500)
#define REPLACEFILE_WRITE_THROUGH  0x00000001
#define REPLACEFILE_IGNORE_MERGE_ERRORS 0x00000002

#if (_WIN32_WINNT >= 0x0600)
#define REPLACEFILE_IGNORE_ACL_ERRORS  0x00000004
#endif

#endif /* _WIN32_WINNT >= 0x0500 */

#define PIPE_ACCESS_INBOUND  0x00000001
#define PIPE_ACCESS_OUTBOUND  0x00000002
#define PIPE_ACCESS_DUPLEX  0x00000003

#define PIPE_CLIENT_END  0x00000000
#define PIPE_SERVER_END  0x00000001

#define PIPE_WAIT  0x00000000
#define PIPE_NOWAIT  0x00000001
#define PIPE_READMODE_BYTE  0x00000000
#define PIPE_READMODE_MESSAGE  0x00000002
#define PIPE_TYPE_BYTE  0x00000000
#define PIPE_TYPE_MESSAGE  0x00000004
#define PIPE_ACCEPT_REMOTE_CLIENTS  0x00000000
#define PIPE_REJECT_REMOTE_CLIENTS  0x00000008

#define PIPE_UNLIMITED_INSTANCES  255

#define SECURITY_ANONYMOUS  (SecurityAnonymous  << 16)
#define SECURITY_IDENTIFICATION  (SecurityIdentification << 16)
#define SECURITY_IMPERSONATION  (SecurityImpersonation  << 16)
#define SECURITY_DELEGATION  (SecurityDelegation  << 16)

#define SECURITY_CONTEXT_TRACKING  0x00040000
#define SECURITY_EFFECTIVE_ONLY  0x00080000

#define SECURITY_SQOS_PRESENT  0x00100000
#define SECURITY_VALID_SQOS_FLAGS  0x001F0000

typedef struct _OVERLAPPED {
    ULONG_PTR Internal;
    ULONG_PTR InternalHigh;
    union {
        struct {
            DWORD Offset;
            DWORD OffsetHigh;
        } DUMMYSTRUCTNAME;
        PVOID Pointer;
    } DUMMYUNIONNAME;
    HANDLE hEvent;
} OVERLAPPED, *LPOVERLAPPED;

typedef struct _OVERLAPPED_ENTRY {
    ULONG_PTR lpCompletionKey;
    LPOVERLAPPED lpOverlapped;
    ULONG_PTR Internal;
    DWORD dwNumberOfBytesTransferred;
} OVERLAPPED_ENTRY, *LPOVERLAPPED_ENTRY;

typedef struct _SECURITY_ATTRIBUTES {
    DWORD nLength;
    LPVOID lpSecurityDescriptor;
    BOOL bInheritHandle;
} SECURITY_ATTRIBUTES, *PSECURITY_ATTRIBUTES, *LPSECURITY_ATTRIBUTES;

typedef struct _PROCESS_INFORMATION {
    HANDLE hProcess;
    HANDLE hThread;
    DWORD dwProcessId;
    DWORD dwThreadId;
} PROCESS_INFORMATION, *PPROCESS_INFORMATION, *LPPROCESS_INFORMATION;

#ifndef _FILETIME_
#define _FILETIME_
typedef struct _FILETIME {
    DWORD dwLowDateTime;
    DWORD dwHighDateTime;
} FILETIME, *PFILETIME, *LPFILETIME;
#endif /* _FILETIME_ */

typedef struct _SYSTEMTIME {
    WORD wYear;
    WORD wMonth;
    WORD wDayOfWeek;
    WORD wDay;
    WORD wHour;
    WORD wMinute;
    WORD wSecond;
    WORD wMilliseconds;
} SYSTEMTIME, *PSYSTEMTIME, *LPSYSTEMTIME;

typedef DWORD(WINAPI *PTHREAD_START_ROUTINE)(LPVOID);
typedef PTHREAD_START_ROUTINE LPTHREAD_START_ROUTINE;

#if (_WIN32_WINNT >= 0x0400)
typedef VOID(WINAPI *PFIBER_START_ROUTINE)(LPVOID);
typedef PFIBER_START_ROUTINE LPFIBER_START_ROUTINE;
#endif /* _WIN32_WINNT >= 0x0400 */

typedef RTL_CRITICAL_SECTION CRITICAL_SECTION;
typedef PRTL_CRITICAL_SECTION PCRITICAL_SECTION;
typedef PRTL_CRITICAL_SECTION LPCRITICAL_SECTION;

typedef RTL_CRITICAL_SECTION_DEBUG CRITICAL_SECTION_DEBUG;
typedef PRTL_CRITICAL_SECTION_DEBUG PCRITICAL_SECTION_DEBUG;
typedef PRTL_CRITICAL_SECTION_DEBUG LPCRITICAL_SECTION_DEBUG;

#if (_WIN32_WINNT >= 0x0600)

typedef RTL_RUN_ONCE INIT_ONCE;
typedef PRTL_RUN_ONCE PINIT_ONCE;
typedef PRTL_RUN_ONCE LPINIT_ONCE;

#define INIT_ONCE_STATIC_INIT  RTL_RUN_ONCE_INIT

#define INIT_ONCE_CHECK_ONLY  RTL_RUN_ONCE_CHECK_ONLY
#define INIT_ONCE_ASYNC  RTL_RUN_ONCE_ASYNC
#define INIT_ONCE_INIT_FAILED  RTL_RUN_ONCE_INIT_FAILED

#define INIT_ONCE_CTX_RESERVED_BITS  RTL_RUN_ONCE_CTX_RESERVED_BITS

#define FAIL_FAST_GENERATE_EXCEPTION_ADDRESS  0x1
#define FAIL_FAST_NO_HARD_ERROR_DLG  0x2

typedef BOOL (WINAPI *PINIT_ONCE_FN)(PINIT_ONCE, PVOID, PVOID *);

WINBASEAPI VOID WINAPI InitOnceInitialize(PINIT_ONCE);
WINBASEAPI BOOL WINAPI InitOnceExecuteOnce(PINIT_ONCE, PINIT_ONCE_FN, PVOID, LPVOID *);
WINBASEAPI BOOL WINAPI InitOnceBeginInitialize(LPINIT_ONCE, DWORD, PBOOL, LPVOID *);
WINBASEAPI BOOL WINAPI InitOnceComplete(LPINIT_ONCE, DWORD, LPVOID);

#endif /* _WIN32_WINNT >= 0x0600 */

typedef RTL_SRWLOCK SRWLOCK, *PSRWLOCK;

#define SRWLOCK_INIT  RTL_SRWLOCK_INIT

WINBASEAPI VOID WINAPI InitializeSRWLock(PSRWLOCK);
WINBASEAPI VOID WINAPI ReleaseSRWLockExclusive(PSRWLOCK);
WINBASEAPI VOID WINAPI ReleaseSRWLockShared(PSRWLOCK);
WINBASEAPI VOID WINAPI AcquireSRWLockExclusive(PSRWLOCK);
WINBASEAPI VOID WINAPI AcquireSRWLockShared(PSRWLOCK);
WINBASEAPI BOOLEAN WINAPI TryAcquireSRWLockExclusive(PSRWLOCK);
WINBASEAPI BOOLEAN WINAPI TryAcquireSRWLockShared(PSRWLOCK);

typedef RTL_CONDITION_VARIABLE CONDITION_VARIABLE, *PCONDITION_VARIABLE;

WINBASEAPI VOID WINAPI InitializeConditionVariable(PCONDITION_VARIABLE);
WINBASEAPI VOID WINAPI WakeConditionVariable(PCONDITION_VARIABLE);
WINBASEAPI VOID WINAPI WakeAllConditionVariable(PCONDITION_VARIABLE);
WINBASEAPI BOOL WINAPI SleepConditionVariableCS(PCONDITION_VARIABLE, PCRITICAL_SECTION, DWORD);
WINBASEAPI BOOL WINAPI SleepConditionVariableSRW(PCONDITION_VARIABLE, PSRWLOCK, DWORD, ULONG);

#define CONDITION_VARIABLE_INIT  RTL_CONDITION_VARIABLE_INIT
#define CONDITION_VARIABLE_LOCKMODE_SHARED  RTL_CONDITION_VARIABLE_LOCKMODE_SHARED

WINBASEAPI PVOID WINAPI EncodePointer(PVOID);
WINBASEAPI PVOID WINAPI DecodePointer(PVOID);
WINBASEAPI PVOID WINAPI EncodeSystemPointer(PVOID);
WINBASEAPI PVOID WINAPI DecodeSystemPointer(PVOID);

#if defined(_X86_)
typedef PLDT_ENTRY LPLDT_ENTRY;
#else
typedef LPVOID LPLDT_ENTRY;
#endif

#define MUTEX_MODIFY_STATE  MUTANT_QUERY_STATE
#define MUTEX_ALL_ACCESS  MUTANT_ALL_ACCESS

#define SP_SERIALCOMM  ((DWORD)0x00000001)

#define PST_UNSPECIFIED  ((DWORD)0x00000000)
#define PST_RS232  ((DWORD)0x00000001)
#define PST_PARALLELPORT  ((DWORD)0x00000002)
#define PST_RS422  ((DWORD)0x00000003)
#define PST_RS423  ((DWORD)0x00000004)
#define PST_RS449  ((DWORD)0x00000005)
#define PST_MODEM  ((DWORD)0x00000006)
#define PST_FAX  ((DWORD)0x00000021)
#define PST_SCANNER  ((DWORD)0x00000022)
#define PST_NETWORK_BRIDGE  ((DWORD)0x00000100)
#define PST_LAT  ((DWORD)0x00000101)
#define PST_TCPIP_TELNET  ((DWORD)0x00000102)
#define PST_X25  ((DWORD)0x00000103)

#define PCF_DTRDSR  ((DWORD)0x0001)
#define PCF_RTSCTS  ((DWORD)0x0002)
#define PCF_RLSD  ((DWORD)0x0004)
#define PCF_PARITY_CHECK  ((DWORD)0x0008)
#define PCF_XONXOFF  ((DWORD)0x0010)
#define PCF_SETXCHAR  ((DWORD)0x0020)
#define PCF_TOTALTIMEOUTS ((DWORD)0x0040)
#define PCF_INTTIMEOUTS  ((DWORD)0x0080)
#define PCF_SPECIALCHARS  ((DWORD)0x0100)
#define PCF_16BITMODE  ((DWORD)0x0200)

#define SP_PARITY  ((DWORD)0x0001)
#define SP_BAUD  ((DWORD)0x0002)
#define SP_DATABITS  ((DWORD)0x0004)
#define SP_STOPBITS  ((DWORD)0x0008)
#define SP_HANDSHAKING  ((DWORD)0x0010)
#define SP_PARITY_CHECK  ((DWORD)0x0020)
#define SP_RLSD  ((DWORD)0x0040)

#define BAUD_075  ((DWORD)0x00000001)
#define BAUD_110  ((DWORD)0x00000002)
#define BAUD_134_5  ((DWORD)0x00000004)
#define BAUD_150  ((DWORD)0x00000008)
#define BAUD_300  ((DWORD)0x00000010)
#define BAUD_600  ((DWORD)0x00000020)
#define BAUD_1200  ((DWORD)0x00000040)
#define BAUD_1800  ((DWORD)0x00000080)
#define BAUD_2400  ((DWORD)0x00000100)
#define BAUD_4800  ((DWORD)0x00000200)
#define BAUD_7200  ((DWORD)0x00000400)
#define BAUD_9600  ((DWORD)0x00000800)
#define BAUD_14400  ((DWORD)0x00001000)
#define BAUD_19200  ((DWORD)0x00002000)
#define BAUD_38400  ((DWORD)0x00004000)
#define BAUD_56K  ((DWORD)0x00008000)
#define BAUD_128K  ((DWORD)0x00010000)
#define BAUD_115200  ((DWORD)0x00020000)
#define BAUD_57600  ((DWORD)0x00040000)
#define BAUD_USER  ((DWORD)0x10000000)

#define DATABITS_5  ((WORD)0x0001)
#define DATABITS_6  ((WORD)0x0002)
#define DATABITS_7  ((WORD)0x0004)
#define DATABITS_8  ((WORD)0x0008)
#define DATABITS_16  ((WORD)0x0010)
#define DATABITS_16X  ((WORD)0x0020)

#define STOPBITS_10  ((WORD)0x0001)
#define STOPBITS_15  ((WORD)0x0002)
#define STOPBITS_20  ((WORD)0x0004)
#define PARITY_NONE  ((WORD)0x0100)
#define PARITY_ODD  ((WORD)0x0200)
#define PARITY_EVEN  ((WORD)0x0400)
#define PARITY_MARK  ((WORD)0x0800)
#define PARITY_SPACE  ((WORD)0x1000)

typedef struct _COMMPROP {
    WORD wPacketLength;
    WORD wPacketVersion;
    DWORD dwServiceMask;
    DWORD dwReserved1;
    DWORD dwMaxTxQueue;
    DWORD dwMaxRxQueue;
    DWORD dwMaxBaud;
    DWORD dwProvSubType;
    DWORD dwProvCapabilities;
    DWORD dwSettableParams;
    DWORD dwSettableBaud;
    WORD wSettableData;
    WORD wSettableStopParity;
    DWORD dwCurrentTxQueue;
    DWORD dwCurrentRxQueue;
    DWORD dwProvSpec1;
    DWORD dwProvSpec2;
    WCHAR wcProvChar[1];
} COMMPROP, *LPCOMMPROP;

#define COMMPROP_INITIALIZED  ((DWORD)0xE73CF52E)

typedef struct _COMSTAT {
    DWORD fCtsHold:1;
    DWORD fDsrHold:1;
    DWORD fRlsdHold:1;
    DWORD fXoffHold:1;
    DWORD fXoffSent:1;
    DWORD fEof:1;
    DWORD fTxim:1;
    DWORD fReserved:25;
    DWORD cbInQue;
    DWORD cbOutQue;
} COMSTAT, *LPCOMSTAT;

#define DTR_CONTROL_DISABLE  0x00
#define DTR_CONTROL_ENABLE  0x01
#define DTR_CONTROL_HANDSHAKE  0x02

#define RTS_CONTROL_DISABLE  0x00
#define RTS_CONTROL_ENABLE  0x01
#define RTS_CONTROL_HANDSHAKE  0x02
#define RTS_CONTROL_TOGGLE  0x03

typedef struct _DCB {
    DWORD DCBlength;
    DWORD BaudRate;
    DWORD fBinary:1;
    DWORD fParity:1;
    DWORD fOutxCtsFlow:1;
    DWORD fOutxDsrFlow:1;
    DWORD fDtrControl:2;
    DWORD fDsrSensitivity:1;
    DWORD fTXContinueOnXoff:1;
    DWORD fOutX:1;
    DWORD fInX:1;
    DWORD fErrorChar:1;
    DWORD fNull:1;
    DWORD fRtsControl:2;
    DWORD fAbortOnError:1;
    DWORD fDummy2:17;
    WORD wReserved;
    WORD XonLim;
    WORD XoffLim;
    BYTE ByteSize;
    BYTE Parity;
    BYTE StopBits;
    char XonChar;
    char XoffChar;
    char ErrorChar;
    char EofChar;
    char EvtChar;
    WORD wReserved1;
} DCB, *LPDCB;

typedef struct _COMMTIMEOUTS {
    DWORD ReadIntervalTimeout;
    DWORD ReadTotalTimeoutMultiplier;
    DWORD ReadTotalTimeoutConstant;
    DWORD WriteTotalTimeoutMultiplier;
    DWORD WriteTotalTimeoutConstant;
} COMMTIMEOUTS, *LPCOMMTIMEOUTS;

typedef struct _COMMCONFIG {
    DWORD dwSize;
    WORD wVersion;
    WORD wReserved;
    DCB dcb;
    DWORD dwProviderSubType;
    DWORD dwProviderOffset;
    DWORD dwProviderSize;
    WCHAR wcProviderData[1];
} COMMCONFIG, *LPCOMMCONFIG;

typedef struct _SYSTEM_INFO {
    union {
        DWORD dwOemId;
        struct {
            WORD wProcessorArchitecture;
            WORD wReserved;
        } DUMMYSTRUCTNAME;
    } DUMMYUNIONNAME;
    DWORD dwPageSize;
    LPVOID lpMinimumApplicationAddress;
    LPVOID lpMaximumApplicationAddress;
    DWORD_PTR dwActiveProcessorMask;
    DWORD dwNumberOfProcessors;
    DWORD dwProcessorType;
    DWORD dwAllocationGranularity;
    WORD wProcessorLevel;
    WORD wProcessorRevision;
} SYSTEM_INFO, *LPSYSTEM_INFO;

#define FreeModule(hLibModule)  FreeLibrary((hLibModule))
#define MakeProcInstance(lpProc,hInstance)  (lpProc)
#define FreeProcInstance(lpProc)  (lpProc)

#define GMEM_FIXED  0x0000
#define GMEM_MOVEABLE  0x0002
#define GMEM_NOCOMPACT  0x0010
#define GMEM_NODISCARD  0x0020
#define GMEM_ZEROINIT  0x0040
#define GMEM_MODIFY  0x0080
#define GMEM_DISCARDABLE  0x0100
#define GMEM_NOT_BANKED  0x1000
#define GMEM_SHARE  0x2000
#define GMEM_DDESHARE  0x2000
#define GMEM_NOTIFY  0x4000
#define GMEM_LOWER  GMEM_NOT_BANKED
#define GMEM_VALID_FLAGS  0x7F72
#define GMEM_INVALID_HANDLE 0x8000

#define GHND  (GMEM_MOVEABLE|GMEM_ZEROINIT)
#define GPTR  (GMEM_FIXED|GMEM_ZEROINIT)

#define GlobalLRUNewest(h)  ((HANDLE)(h))
#define GlobalLRUOldest(h)  ((HANDLE)(h))
#define GlobalDiscard(h)  GlobalReAlloc((h),0,GMEM_MOVEABLE)

#define GMEM_DISCARDED  0x4000
#define GMEM_LOCKCOUNT  0x00FF

typedef struct _MEMORYSTATUS {
    DWORD dwLength;
    DWORD dwMemoryLoad;
    SIZE_T dwTotalPhys;
    SIZE_T dwAvailPhys;
    SIZE_T dwTotalPageFile;
    SIZE_T dwAvailPageFile;
    SIZE_T dwTotalVirtual;
    SIZE_T dwAvailVirtual;
} MEMORYSTATUS, *LPMEMORYSTATUS;

#define LMEM_FIXED  0x0000
#define LMEM_MOVEABLE  0x0002
#define LMEM_NOCOMPACT  0x0010
#define LMEM_NODISCARD  0x0020
#define LMEM_ZEROINIT  0x0040
#define LMEM_MODIFY  0x0080
#define LMEM_DISCARDABLE  0x0F00
#define LMEM_VALID_FLAGS  0x0F72
#define LMEM_INVALID_HANDLE 0x8000

#define LHND  (LMEM_MOVEABLE|LMEM_ZEROINIT)
#define LPTR  (LMEM_FIXED|LMEM_ZEROINIT)

#define NONZEROLHND  (LMEM_MOVEABLE)
#define NONZEROLPTR  (LMEM_FIXED)

#define LocalDiscard(h)  LocalReAlloc((h),0,LMEM_MOVEABLE)

#define LMEM_DISCARDED  0x4000
#define LMEM_LOCKCOUNT  0x00FF

#define NUMA_NO_PREFERRED_NODE  ((DWORD)-1)

#define DEBUG_PROCESS  0x00000001
#define DEBUG_ONLY_THIS_PROCESS  0x00000002
#define CREATE_SUSPENDED  0x00000004
#define DETACHED_PROCESS  0x00000008

#define CREATE_NEW_CONSOLE  0x00000010
#define NORMAL_PRIORITY_CLASS  0x00000020
#define IDLE_PRIORITY_CLASS  0x00000040
#define HIGH_PRIORITY_CLASS  0x00000080

#define REALTIME_PRIORITY_CLASS  0x00000100
#define CREATE_NEW_PROCESS_GROUP  0x00000200
#define CREATE_UNICODE_ENVIRONMENT  0x00000400
#define CREATE_SEPARATE_WOW_VDM  0x00000800

#define CREATE_SHARED_WOW_VDM  0x00001000
#define CREATE_FORCEDOS  0x00002000
#define BELOW_NORMAL_PRIORITY_CLASS  0x00004000
#define ABOVE_NORMAL_PRIORITY_CLASS  0x00008000

#define INHERIT_PARENT_AFFINITY  0x00010000
#define INHERIT_CALLER_PRIORITY  0x00020000
#define CREATE_PROTECTED_PROCESS  0x00040000
#define EXTENDED_STARTUPINFO_PRESENT  0x00080000

#define PROCESS_MODE_BACKGROUND_BEGIN  0x00100000
#define PROCESS_MODE_BACKGROUND_END  0x00200000

#define CREATE_BREAKAWAY_FROM_JOB  0x01000000
#define CREATE_PRESERVE_CODE_AUTHZ_LEVEL  0x02000000
#define CREATE_DEFAULT_ERROR_MODE  0x04000000
#define CREATE_NO_WINDOW  0x08000000

#define PROFILE_USER  0x10000000
#define PROFILE_KERNEL  0x20000000
#define PROFILE_SERVER  0x40000000
#define CREATE_IGNORE_SYSTEM_DEFAULT  0x80000000

#define STACK_SIZE_PARAM_IS_A_RESERVATION  0x00010000

#define THREAD_PRIORITY_LOWEST  THREAD_BASE_PRIORITY_MIN
#define THREAD_PRIORITY_BELOW_NORMAL  (THREAD_PRIORITY_LOWEST+1)
#define THREAD_PRIORITY_NORMAL  0
#define THREAD_PRIORITY_HIGHEST  THREAD_BASE_PRIORITY_MAX
#define THREAD_PRIORITY_ABOVE_NORMAL  (THREAD_PRIORITY_HIGHEST-1)
#define THREAD_PRIORITY_ERROR_RETURN  (MAXLONG)

#define THREAD_PRIORITY_TIME_CRITICAL  THREAD_BASE_PRIORITY_LOWRT
#define THREAD_PRIORITY_IDLE  THREAD_BASE_PRIORITY_IDLE

#define THREAD_MODE_BACKGROUND_BEGIN  0x00010000
#define THREAD_MODE_BACKGROUND_END  0x00020000

#define VOLUME_NAME_DOS  0x0
#define VOLUME_NAME_GUID 0x1
#define VOLUME_NAME_NT  0x2
#define VOLUME_NAME_NONE 0x4

#define FILE_NAME_NORMALIZED 0x0
#define FILE_NAME_OPENED  0x8

#define EXCEPTION_DEBUG_EVENT  1
#define CREATE_THREAD_DEBUG_EVENT  2
#define CREATE_PROCESS_DEBUG_EVENT  3
#define EXIT_THREAD_DEBUG_EVENT  4
#define EXIT_PROCESS_DEBUG_EVENT  5
#define LOAD_DLL_DEBUG_EVENT  6
#define UNLOAD_DLL_DEBUG_EVENT  7
#define OUTPUT_DEBUG_STRING_EVENT  8
#define RIP_EVENT  9

typedef struct _EXCEPTION_DEBUG_INFO {
    EXCEPTION_RECORD ExceptionRecord;
    DWORD dwFirstChance;
} EXCEPTION_DEBUG_INFO, *LPEXCEPTION_DEBUG_INFO;

typedef struct _CREATE_THREAD_DEBUG_INFO {
    HANDLE hThread;
    LPVOID lpThreadLocalBase;
    LPTHREAD_START_ROUTINE lpStartAddress;
} CREATE_THREAD_DEBUG_INFO, *LPCREATE_THREAD_DEBUG_INFO;

typedef struct _CREATE_PROCESS_DEBUG_INFO {
    HANDLE hFile;
    HANDLE hProcess;
    HANDLE hThread;
    LPVOID lpBaseOfImage;
    DWORD dwDebugInfoFileOffset;
    DWORD nDebugInfoSize;
    LPVOID lpThreadLocalBase;
    LPTHREAD_START_ROUTINE lpStartAddress;
    LPVOID lpImageName;
    WORD fUnicode;
} CREATE_PROCESS_DEBUG_INFO, *LPCREATE_PROCESS_DEBUG_INFO;

typedef struct _EXIT_THREAD_DEBUG_INFO {
    DWORD dwExitCode;
} EXIT_THREAD_DEBUG_INFO, *LPEXIT_THREAD_DEBUG_INFO;

typedef struct _EXIT_PROCESS_DEBUG_INFO {
    DWORD dwExitCode;
} EXIT_PROCESS_DEBUG_INFO, *LPEXIT_PROCESS_DEBUG_INFO;

typedef struct _LOAD_DLL_DEBUG_INFO {
    HANDLE hFile;
    LPVOID lpBaseOfDll;
    DWORD dwDebugInfoFileOffset;
    DWORD nDebugInfoSize;
    LPVOID lpImageName;
    WORD fUnicode;
} LOAD_DLL_DEBUG_INFO, *LPLOAD_DLL_DEBUG_INFO;

typedef struct _UNLOAD_DLL_DEBUG_INFO {
    LPVOID lpBaseOfDll;
} UNLOAD_DLL_DEBUG_INFO, *LPUNLOAD_DLL_DEBUG_INFO;

typedef struct _OUTPUT_DEBUG_STRING_INFO {
    LPSTR lpDebugStringData;
    WORD fUnicode;
    WORD nDebugStringLength;
} OUTPUT_DEBUG_STRING_INFO, *LPOUTPUT_DEBUG_STRING_INFO;

typedef struct _RIP_INFO {
    DWORD dwError;
    DWORD dwType;
} RIP_INFO, *LPRIP_INFO;

typedef struct _DEBUG_EVENT {
    DWORD dwDebugEventCode;
    DWORD dwProcessId;
    DWORD dwThreadId;
    union {
        EXCEPTION_DEBUG_INFO Exception;
        CREATE_THREAD_DEBUG_INFO CreateThread;
        CREATE_PROCESS_DEBUG_INFO CreateProcessInfo;
        EXIT_THREAD_DEBUG_INFO ExitThread;
        EXIT_PROCESS_DEBUG_INFO ExitProcess;
        LOAD_DLL_DEBUG_INFO LoadDll;
        UNLOAD_DLL_DEBUG_INFO UnloadDll;
        OUTPUT_DEBUG_STRING_INFO DebugString;
        RIP_INFO RipInfo;
    } u;
} DEBUG_EVENT, *LPDEBUG_EVENT;

typedef struct _JIT_DEBUG_INFO {
    DWORD dwSize;
    DWORD dwProcessorArchitecture;
    DWORD dwThreadID;
    DWORD dwReserved0;
    ULONG64 lpExceptionAddress;
    ULONG64 lpExceptionRecord;
    ULONG64 lpContextRecord;
} JIT_DEBUG_INFO, *LPJIT_DEBUG_INFO;

typedef JIT_DEBUG_INFO JIT_DEBUG_INFO32, *LPJIT_DEBUG_INFO32;
typedef JIT_DEBUG_INFO JIT_DEBUG_INFO64, *LPJIT_DEBUG_INFO64;

typedef PCONTEXT LPCONTEXT;
typedef PEXCEPTION_RECORD LPEXCEPTION_RECORD;
typedef PEXCEPTION_POINTERS LPEXCEPTION_POINTERS;

#define DRIVE_UNKNOWN  0
#define DRIVE_NO_ROOT_DIR 1
#define DRIVE_REMOVABLE  2
#define DRIVE_FIXED  3
#define DRIVE_REMOTE  4
#define DRIVE_CDROM  5
#define DRIVE_RAMDISK  6

#define GetFreeSpace(w)  (0x100000L)

#define FILE_TYPE_UNKNOWN  0x0000
#define FILE_TYPE_DISK  0x0001
#define FILE_TYPE_CHAR  0x0002
#define FILE_TYPE_PIPE  0x0003
#define FILE_TYPE_REMOTE  0x8000

#define STD_INPUT_HANDLE  ((DWORD)-10)
#define STD_OUTPUT_HANDLE  ((DWORD)-11)
#define STD_ERROR_HANDLE  ((DWORD)-12)

#define NOPARITY  0
#define ODDPARITY  1
#define EVENPARITY  2
#define MARKPARITY  3
#define SPACEPARITY  4

#define ONESTOPBIT  0
#define ONE5STOPBITS  1
#define TWOSTOPBITS  2

#define IGNORE  0
#define INFINITE  0xFFFFFFFF

#define CBR_110  110
#define CBR_300  300
#define CBR_600  600
#define CBR_1200  1200
#define CBR_2400  2400
#define CBR_4800  4800
#define CBR_9600  9600
#define CBR_14400  14400
#define CBR_19200  19200
#define CBR_38400  38400
#define CBR_56000  56000
#define CBR_57600  57600
#define CBR_115200  115200
#define CBR_128000  128000
#define CBR_256000  256000

#define CE_RXOVER  0x0001
#define CE_OVERRUN  0x0002
#define CE_RXPARITY  0x0004
#define CE_FRAME  0x0008
#define CE_BREAK  0x0010
#define CE_TXFULL  0x0100
#define CE_PTO  0x0200
#define CE_IOE  0x0400
#define CE_DNS  0x0800
#define CE_OOP  0x1000
#define CE_MODE  0x8000

#define IE_BADID  (-1)
#define IE_OPEN  (-2)
#define IE_NOPEN  (-3)
#define IE_MEMORY  (-4)
#define IE_DEFAULT  (-5)
#define IE_HARDWARE  (-10)
#define IE_BYTESIZE  (-11)
#define IE_BAUDRATE  (-12)

#define EV_RXCHAR  0x0001
#define EV_RXFLAG  0x0002
#define EV_TXEMPTY  0x0004
#define EV_CTS  0x0008
#define EV_DSR  0x0010
#define EV_RLSD  0x0020
#define EV_BREAK  0x0040
#define EV_ERR  0x0080
#define EV_RING  0x0100
#define EV_PERR  0x0200
#define EV_RX80FULL  0x0400
#define EV_EVENT1  0x0800
#define EV_EVENT2  0x1000

#define SETXOFF  1
#define SETXON  2
#define SETRTS  3
#define CLRRTS  4
#define SETDTR  5
#define CLRDTR  6
#define RESETDEV  7
#define SETBREAK  8
#define CLRBREAK  9

#define PURGE_TXABORT  0x0001
#define PURGE_RXABORT  0x0002
#define PURGE_TXCLEAR  0x0004
#define PURGE_RXCLEAR  0x0008

#define LPTx  0x80

#define MS_CTS_ON  ((DWORD)0x0010)
#define MS_DSR_ON  ((DWORD)0x0020)
#define MS_RING_ON  ((DWORD)0x0040)
#define MS_RLSD_ON  ((DWORD)0x0080)

#define S_QUEUEEMPTY  0
#define S_THRESHOLD  1
#define S_ALLTHRESHOLD  2

#define S_NORMAL  0
#define S_LEGATO  1
#define S_STACCATO  2

#define S_PERIOD512  0
#define S_PERIOD1024  1
#define S_PERIOD2048  2
#define S_PERIODVOICE 3
#define S_WHITE512  4
#define S_WHITE1024  5
#define S_WHITE2048  6
#define S_WHITEVOICE  7

#define S_SERDVNA  (-1)
#define S_SEROFM  (-2)
#define S_SERMACT  (-3)
#define S_SERQFUL  (-4)
#define S_SERBDNT  (-5)
#define S_SERDLN  (-6)
#define S_SERDCC  (-7)
#define S_SERDTP  (-8)
#define S_SERDVL  (-9)
#define S_SERDMD  (-10)
#define S_SERDSH  (-11)
#define S_SERDPT  (-12)
#define S_SERDFQ  (-13)
#define S_SERDDR  (-14)
#define S_SERDSR  (-15)
#define S_SERDST  (-16)

#define NMPWAIT_WAIT_FOREVER  0xffffffff
#define NMPWAIT_NOWAIT  0x00000001
#define NMPWAIT_USE_DEFAULT_WAIT  0x00000000

#define FS_CASE_IS_PRESERVED  FILE_CASE_PRESERVED_NAMES
#define FS_CASE_SENSITIVE  FILE_CASE_SENSITIVE_SEARCH
#define FS_UNICODE_STORED_ON_DISK  FILE_UNICODE_ON_DISK
#define FS_PERSISTENT_ACLS  FILE_PERSISTENT_ACLS
#define FS_VOL_IS_COMPRESSED  FILE_VOLUME_IS_COMPRESSED
#define FS_FILE_COMPRESSION  FILE_FILE_COMPRESSION
#define FS_FILE_ENCRYPTION  FILE_SUPPORTS_ENCRYPTION

#define FILE_MAP_COPY  SECTION_QUERY
#define FILE_MAP_WRITE  SECTION_MAP_WRITE
#define FILE_MAP_READ  SECTION_MAP_READ
#define FILE_MAP_ALL_ACCESS SECTION_ALL_ACCESS
#define FILE_MAP_EXECUTE  SECTION_MAP_EXECUTE_EXPLICIT

#define OF_READ  0x00000000
#define OF_WRITE  0x00000001
#define OF_READWRITE  0x00000002
#define OF_SHARE_COMPAT  0x00000000
#define OF_SHARE_EXCLUSIVE  0x00000010
#define OF_SHARE_DENY_WRITE 0x00000020
#define OF_SHARE_DENY_READ  0x00000030
#define OF_SHARE_DENY_NONE  0x00000040
#define OF_PARSE  0x00000100
#define OF_DELETE  0x00000200
#define OF_VERIFY  0x00000400
#define OF_CANCEL  0x00000800
#define OF_CREATE  0x00001000
#define OF_PROMPT  0x00002000
#define OF_EXIST  0x00004000
#define OF_REOPEN  0x00008000

#define OFS_MAXPATHNAME  128
typedef struct _OFSTRUCT {
    BYTE cBytes;
    BYTE fFixedDisk;
    WORD nErrCode;
    WORD Reserved1;
    WORD Reserved2;
    CHAR szPathName[OFS_MAXPATHNAME];
} OFSTRUCT, *LPOFSTRUCT, *POFSTRUCT;

#ifndef NOWINBASEINTERLOCK

#ifndef _NTOS_

#if defined(_M_IA64)

#define InterlockedIncrement _InterlockedIncrement
#define InterlockedIncrementAcquire _InterlockedIncrement_acq
#define InterlockedIncrementRelease _InterlockedIncrement_rel
#define InterlockedDecrement _InterlockedDecrement
#define InterlockedDecrementAcquire _InterlockedDecrement_acq
#define InterlockedDecrementRelease _InterlockedDecrement_rel
#define InterlockedExchange _InterlockedExchange
#define InterlockedExchangeAdd _InterlockedExchangeAdd
#define InterlockedCompareExchange _InterlockedCompareExchange
#define InterlockedCompareExchangeAcquire _InterlockedCompareExchange_acq
#define InterlockedCompareExchangeRelease _InterlockedCompareExchange_rel
#define InterlockedExchangePointer _InterlockedExchangePointer
#define InterlockedCompareExchangePointer _InterlockedCompareExchangePointer
#define InterlockedCompareExchangePointerRelease _InterlockedCompareExchangePointer_rel
#define InterlockedCompareExchangePointerAcquire _InterlockedCompareExchangePointer_acq

#define InterlockedIncrement64 _InterlockedIncrement64
#define InterlockedDecrement64 _InterlockedDecrement64
#define InterlockedExchange64 _InterlockedExchange64
#define InterlockedExchangeAcquire64 _InterlockedExchange64_acq
#define InterlockedExchangeAdd64 _InterlockedExchangeAdd64
#define InterlockedCompareExchange64 _InterlockedCompareExchange64
#define InterlockedCompareExchangeAcquire64 _InterlockedCompareExchange64_acq
#define InterlockedCompareExchangeRelease64 _InterlockedCompareExchange64_rel
#define InterlockedCompare64Exchange128  _InterlockedCompare64Exchange128
#define InterlockedCompare64ExchangeAcquire128  _InterlockedCompare64Exchange128_acq
#define InterlockedCompare64ExchangeRelease128  _InterlockedCompare64Exchange128_rel

#define InterlockedOr _InterlockedOr
#define InterlockedOrAcquire _InterlockedOr_acq
#define InterlockedOrRelease _InterlockedOr_rel
#define InterlockedOr8 _InterlockedOr8
#define InterlockedOr8Acquire _InterlockedOr8_acq
#define InterlockedOr8Release _InterlockedOr8_rel
#define InterlockedOr16 _InterlockedOr16
#define InterlockedOr16Acquire _InterlockedOr16_acq
#define InterlockedOr16Release _InterlockedOr16_rel
#define InterlockedOr64 _InterlockedOr64
#define InterlockedOr64Acquire _InterlockedOr64_acq
#define InterlockedOr64Release _InterlockedOr64_rel
#define InterlockedXor _InterlockedXor
#define InterlockedXorAcquire _InterlockedXor_acq
#define InterlockedXorRelease _InterlockedXor_rel
#define InterlockedXor8 _InterlockedXor8
#define InterlockedXor8Acquire _InterlockedXor8_acq
#define InterlockedXor8Release _InterlockedXor8_rel
#define InterlockedXor16 _InterlockedXor16
#define InterlockedXor16Acquire _InterlockedXor16_acq
#define InterlockedXor16Release _InterlockedXor16_rel
#define InterlockedXor64 _InterlockedXor64
#define InterlockedXor64Acquire _InterlockedXor64_acq
#define InterlockedXor64Release _InterlockedXor64_rel
#define InterlockedAnd _InterlockedAnd
#define InterlockedAndAcquire _InterlockedAnd_acq
#define InterlockedAndRelease _InterlockedAnd_rel
#define InterlockedAnd8 _InterlockedAnd8
#define InterlockedAnd8Acquire _InterlockedAnd8_acq
#define InterlockedAnd8Release _InterlockedAnd8_rel
#define InterlockedAnd16 _InterlockedAnd16
#define InterlockedAnd16Acquire _InterlockedAnd16_acq
#define InterlockedAnd16Release _InterlockedAnd16_rel
#define InterlockedAnd64 _InterlockedAnd64
#define InterlockedAnd64Acquire _InterlockedAnd64_acq
#define InterlockedAnd64Release _InterlockedAnd64_rel

LONG __cdecl InterlockedOr(LONG volatile *, LONG);
LONG __cdecl InterlockedOrAcquire(LONG volatile *, LONG);
LONG __cdecl InterlockedOrRelease(LONG volatile *, LONG);
char __cdecl InterlockedOr8(char volatile *, char);
char __cdecl InterlockedOr8Acquire(char volatile *, char);
char __cdecl InterlockedOr8Release(char volatile *, char);
SHORT __cdecl InterlockedOr16(SHORT volatile *, SHORT);
SHORT __cdecl InterlockedOr16Acquire(SHORT volatile *, SHORT);
SHORT __cdecl InterlockedOr16Release(SHORT volatile *, SHORT);
LONGLONG __cdecl InterlockedOr64(LONGLONG volatile *, LONGLONG);
LONGLONG __cdecl InterlockedOr64Acquire(LONGLONG volatile *, LONGLONG);
LONGLONG __cdecl InterlockedOr64Release(LONGLONG volatile *, LONGLONG);
LONG __cdecl InterlockedXor(LONG volatile *, LONG);
LONG __cdecl InterlockedXorAcquire(LONG volatile *, LONG);
LONG __cdecl InterlockedXorRelease(LONG volatile *, LONG);
char __cdecl InterlockedXor8(char volatile *, char);
char __cdecl InterlockedXor8Acquire(char volatile *, char);
char __cdecl InterlockedXor8Release(char volatile *, char);
SHORT __cdecl InterlockedXor16(SHORT volatile *, SHORT);
SHORT __cdecl InterlockedXor16Acquire(SHORT volatile *, SHORT);
SHORT __cdecl InterlockedXor16Release(SHORT volatile *, SHORT);
LONGLONG __cdecl InterlockedXor64(LONGLONG volatile *, LONGLONG);
LONGLONG __cdecl InterlockedXor64Acquire(LONGLONG volatile *, LONGLONG);
LONGLONG __cdecl InterlockedXor64Release(LONGLONG volatile *, LONGLONG);
LONG __cdecl InterlockedAnd(LONG volatile *, LONG);
LONG __cdecl InterlockedAndAcquire(LONG volatile *, LONG);
LONG __cdecl InterlockedAndRelease(LONG volatile *, LONG);
char __cdecl InterlockedAnd8(char volatile *, char);
char __cdecl InterlockedAnd8Acquire(char volatile *, char);
char __cdecl InterlockedAnd8Release(char volatile *, char);
SHORT __cdecl InterlockedAnd16(SHORT volatile *, SHORT);
SHORT __cdecl InterlockedAnd16Acquire(SHORT volatile *, SHORT);
SHORT __cdecl InterlockedAnd16Release(SHORT volatile *, SHORT);
LONGLONG __cdecl InterlockedAnd64(LONGLONG volatile *, LONGLONG);
LONGLONG __cdecl InterlockedAnd64Acquire(LONGLONG volatile *, LONGLONG);
LONGLONG __cdecl InterlockedAnd64Release(LONGLONG volatile *, LONGLONG);
LONGLONG __cdecl InterlockedIncrement64(LONGLONG volatile *);
LONGLONG __cdecl InterlockedDecrement64(LONGLONG volatile *);
LONG __cdecl InterlockedIncrementAcquire(LONG volatile *);
LONG __cdecl InterlockedDecrementAcquire(LONG volatile *);
LONG __cdecl InterlockedIncrementRelease(LONG volatile *);
LONG __cdecl InterlockedDecrementRelease(LONG volatile *);
LONGLONG __cdecl InterlockedExchange64(LONGLONG volatile *, LONGLONG);
LONGLONG __cdecl InterlockedExchangeAcquire64(LONGLONG volatile *, LONGLONG);
LONGLONG __cdecl InterlockedExchangeAdd64(LONGLONG volatile *, LONGLONG);
LONGLONG __cdecl InterlockedCompareExchange64(LONGLONG volatile *, LONGLONG, LONGLONG);
LONGLONG __cdecl InterlockedCompareExchangeAcquire64(LONGLONG volatile *, LONGLONG, LONGLONG);
LONGLONG __cdecl InterlockedCompareExchangeRelease64(LONGLONG volatile *, LONGLONG, LONGLONG);
LONG64 __cdecl InterlockedCompare64Exchange128(LONG64 volatile *, LONG64, LONG64, LONG64);
LONG64 __cdecl InterlockedCompare64ExchangeAcquire128(LONG64 volatile *, LONG64, LONG64, LONG64);
LONG64 __cdecl InterlockedCompare64ExchangeRelease128(LONG64 volatile *, LONG64, LONG64, LONG64);
LONG __cdecl InterlockedIncrement(LONG volatile *);
LONG __cdecl InterlockedDecrement(LONG volatile *);
LONG __cdecl InterlockedExchange(LONG volatile *, LONG);
LONG __cdecl InterlockedExchangeAdd(LONG volatile *, LONG);
LONG __cdecl InterlockedCompareExchange(LONG volatile *, LONG, LONG);
LONG __cdecl InterlockedCompareExchangeRelease(LONG volatile *, LONG, LONG);
LONG __cdecl InterlockedCompareExchangeAcquire(LONG volatile *, LONG, LONG);
PVOID __cdecl InterlockedExchangePointer(PVOID volatile *, PVOID);
PVOID __cdecl InterlockedCompareExchangePointer(PVOID volatile *, PVOID, PVOID);
PVOID __cdecl InterlockedCompareExchangePointerAcquire(PVOID volatile *, PVOID, PVOID);
PVOID __cdecl InterlockedCompareExchangePointerRelease(PVOID volatile *, PVOID, PVOID);

#ifndef InterlockedAnd
#define InterlockedAnd  InterlockedAnd_Inline
FORCEINLINE LONG InterlockedAnd_Inline(LONG volatile *Target, LONG Set) {
    LONG i, j;
    j = *Target;
    do
    {
        i = j;
        j = InterlockedCompareExchange(Target, i & Set, i);
    } while (i != j);
    return j;
}
#endif /* InterlockedAnd */

#ifndef InterlockedOr
#define InterlockedOr  InterlockedOr_Inline
FORCEINLINE LONG InterlockedOr_Inline(LONG volatile *Target, LONG Set) {
    LONG i, j;
    j = *Target;
    do
    {
        i = j;
        j = InterlockedCompareExchange(Target, i | Set, i);
    } while (i != j);
    return j;
}
#endif /* InterlockedOr */

#ifndef InterlockedXor
#define InterlockedXor  InterlockedXor_Inline
FORCEINLINE LONG InterlockedXor_Inline(LONG volatile *Target, LONG Set) {
    LONG i, j;
    j = *Target;
    do
    {
        i = j;
        j = InterlockedCompareExchange(Target, i ^ Set, i);
    } while (i != j);
    return j;
}
#endif /* InterlockedXor */

#ifndef InterlockedAnd64
#define InterlockedAnd64  InterlockedAnd64_Inline
FORCEINLINE LONGLONG InterlockedAnd64_Inline(LONGLONG volatile *Destination, LONGLONG Value) {
    LONGLONG Old;
    do
    {
        Old = *Destination;
    } while (InterlockedCompareExchange64(Destination, Old & Value, Old) != Old);
    return Old;
}
#endif /* InterlockedAnd64 */

#ifndef InterlockedOr64
#define InterlockedOr64  InterlockedOr64_Inline
FORCEINLINE LONGLONG InterlockedOr64_Inline(LONGLONG volatile *Destination, LONGLONG Value) {
    LONGLONG Old;
    do
    {
        Old = *Destination;
    } while (InterlockedCompareExchange64(Destination, Old | Value, Old) != Old);
    return Old;
}
#endif /* InterlockedOr64 */

#ifndef InterlockedXor64
#define InterlockedXor64  InterlockedXor64_Inline
FORCEINLINE LONGLONG InterlockedXor64_Inline(LONGLONG volatile *Destination, LONGLONG Value) {
    LONGLONG Old;
    do
    {
        Old = *Destination;
    } while (InterlockedCompareExchange64(Destination, Old ^ Value, Old) != Old);
    return Old;
}
#endif /* InterlockedXor64 */

#ifndef InterlockedBitTestAndSet
#define InterlockedBitTestAndSet  InterlockedBitTestAndSet_Inline
FORCEINLINE BOOLEAN InterlockedBitTestAndSet_Inline(LONG volatile *Base, LONG Bit) {
    LONG tBit;
    tBit = 1 << (Bit & (sizeof(*Base) * 8 - 1));
    return (BOOLEAN)((InterlockedOr(&Base[Bit / (sizeof(*Base) * 8)], tBit) & tBit) != 0);
}
#endif /* InterlockedBitTestAndSet */

#ifndef InterlockedBitTestAndReset
#define InterlockedBitTestAndReset  InterlockedBitTestAndReset_Inline
FORCEINLINE BOOLEAN InterlockedBitTestAndReset_Inline(LONG volatile *Base, LONG Bit) {
    LONG tBit;
    tBit = 1 << (Bit & (sizeof(*Base) * 8 - 1));
    return (BOOLEAN) ((InterlockedAnd(&Base[Bit / (sizeof(*Base) * 8)], ~tBit) & tBit) != 0);
}
#endif /* InterlockedBitTestAndReset */

#ifndef InterlockedBitTestAndComplement
#define InterlockedBitTestAndComplement  InterlockedBitTestAndComplement_Inline
FORCEINLINE BOOLEAN InterlockedBitTestAndComplement_Inline(LONG volatile *Base, LONG Bit) {
    LONG tBit;
    tBit = 1 << (Bit & (sizeof(*Base) * 8 - 1));
    return (BOOLEAN) ((InterlockedXor(&Base[Bit / (sizeof(*Base) * 8)], tBit) & tBit) != 0);
}
#endif /* InterlockedBitTestAndComplement */

#pragma intrinsic(_InterlockedIncrement)
#pragma intrinsic(_InterlockedIncrement_acq)
#pragma intrinsic(_InterlockedIncrement_rel)
#pragma intrinsic(_InterlockedDecrement)
#pragma intrinsic(_InterlockedDecrement_acq)
#pragma intrinsic(_InterlockedDecrement_rel)
#pragma intrinsic(_InterlockedExchange)
#pragma intrinsic(_InterlockedExchangeAdd)
#pragma intrinsic(_InterlockedCompareExchange)
#pragma intrinsic(_InterlockedCompareExchange_acq)
#pragma intrinsic(_InterlockedCompareExchange_rel)
#pragma intrinsic(_InterlockedExchangePointer)
#pragma intrinsic(_InterlockedCompareExchangePointer)
#pragma intrinsic(_InterlockedCompareExchangePointer_acq)
#pragma intrinsic(_InterlockedCompareExchangePointer_rel)
#pragma intrinsic(_InterlockedIncrement64)
#pragma intrinsic(_InterlockedDecrement64)
#pragma intrinsic(_InterlockedExchange64)
#pragma intrinsic(_InterlockedExchange64_acq)
#pragma intrinsic(_InterlockedCompareExchange64)
#pragma intrinsic(_InterlockedCompareExchange64_acq)
#pragma intrinsic(_InterlockedCompareExchange64_rel)
#pragma intrinsic(_InterlockedExchangeAdd64)
#pragma intrinsic(_InterlockedOr)
#pragma intrinsic(_InterlockedOr_acq)
#pragma intrinsic(_InterlockedOr_rel)
#pragma intrinsic(_InterlockedOr8)
#pragma intrinsic(_InterlockedOr8_acq)
#pragma intrinsic(_InterlockedOr8_rel)
#pragma intrinsic(_InterlockedOr16)
#pragma intrinsic(_InterlockedOr16_acq)
#pragma intrinsic(_InterlockedOr16_rel)
#pragma intrinsic(_InterlockedOr64)
#pragma intrinsic(_InterlockedOr64_acq)
#pragma intrinsic(_InterlockedOr64_rel)
#pragma intrinsic(_InterlockedXor)
#pragma intrinsic(_InterlockedXor_acq)
#pragma intrinsic(_InterlockedXor_rel)
#pragma intrinsic(_InterlockedXor8)
#pragma intrinsic(_InterlockedXor8_acq)
#pragma intrinsic(_InterlockedXor8_rel)
#pragma intrinsic(_InterlockedXor16)
#pragma intrinsic(_InterlockedXor16_acq)
#pragma intrinsic(_InterlockedXor16_rel)
#pragma intrinsic(_InterlockedXor64)
#pragma intrinsic(_InterlockedXor64_acq)
#pragma intrinsic(_InterlockedXor64_rel)
#pragma intrinsic(_InterlockedAnd)
#pragma intrinsic(_InterlockedAnd_acq)
#pragma intrinsic(_InterlockedAnd_rel)
#pragma intrinsic(_InterlockedAnd8)
#pragma intrinsic(_InterlockedAnd8_acq)
#pragma intrinsic(_InterlockedAnd8_rel)
#pragma intrinsic(_InterlockedAnd16)
#pragma intrinsic(_InterlockedAnd16_acq)
#pragma intrinsic(_InterlockedAnd16_rel)
#pragma intrinsic(_InterlockedAnd64)
#pragma intrinsic(_InterlockedAnd64_acq)
#pragma intrinsic(_InterlockedAnd64_rel)

#elif defined(_M_AMD64)

#define InterlockedAnd _InterlockedAnd
#define InterlockedOr _InterlockedOr
#define InterlockedXor _InterlockedXor
#define InterlockedIncrement _InterlockedIncrement
#define InterlockedIncrementAcquire InterlockedIncrement
#define InterlockedIncrementRelease InterlockedIncrement
#define InterlockedDecrement _InterlockedDecrement
#define InterlockedDecrementAcquire InterlockedDecrement
#define InterlockedDecrementRelease InterlockedDecrement
#define InterlockedExchange _InterlockedExchange
#define InterlockedExchangeAdd _InterlockedExchangeAdd
#define InterlockedCompareExchange _InterlockedCompareExchange
#define InterlockedCompareExchangeAcquire InterlockedCompareExchange
#define InterlockedCompareExchangeRelease InterlockedCompareExchange
#define InterlockedExchangePointer _InterlockedExchangePointer
#define InterlockedCompareExchangePointer _InterlockedCompareExchangePointer
#define InterlockedCompareExchangePointerAcquire _InterlockedCompareExchangePointer
#define InterlockedCompareExchangePointerRelease _InterlockedCompareExchangePointer

#define InterlockedAnd64 _InterlockedAnd64
#define InterlockedOr64 _InterlockedOr64
#define InterlockedXor64 _InterlockedXor64
#define InterlockedIncrement64 _InterlockedIncrement64
#define InterlockedDecrement64 _InterlockedDecrement64
#define InterlockedExchange64 _InterlockedExchange64
#define InterlockedExchangeAdd64 _InterlockedExchangeAdd64
#define InterlockedCompareExchange64 _InterlockedCompareExchange64
#define InterlockedCompareExchangeAcquire64 InterlockedCompareExchange64
#define InterlockedCompareExchangeRelease64 InterlockedCompareExchange64

/*
LONG InterlockedAnd(LONG volatile *, LONG);
LONG InterlockedOr(LONG volatile *, LONG);
LONG InterlockedXor(LONG volatile *, LONG);
LONG InterlockedIncrement(LONG volatile *);
LONG InterlockedDecrement(LONG volatile *);
LONG InterlockedExchange(LONG volatile *, LONG);
LONG InterlockedExchangeAdd(LONG volatile *, LONG);
LONG InterlockedCompareExchange(LONG volatile *, LONG, LONG);
PVOID InterlockedCompareExchangePointer(PVOID volatile *, PVOID, PVOID);
PVOID InterlockedExchangePointer(PVOID volatile *, PVOID);
LONG64 InterlockedAnd64(LONG64 volatile *, LONG64);
LONG64 InterlockedOr64(LONG64 volatile *, LONG64);
LONG64 InterlockedXor64(LONG64 volatile *, LONG64);
LONG64 InterlockedIncrement64(LONG64 volatile *);
LONG64 InterlockedDecrement64(LONG64 volatile *);
LONG64 InterlockedExchange64(LONG64 volatile *, LONG64);
LONG64 InterlockedExchangeAdd64(LONG64 volatile *, LONG64);
LONG64 InterlockedCompareExchange64(LONG64 volatile *, LONG64, LONG64);
*/

/* #pragma intrinsic(_InterlockedAnd) */
/* #pragma intrinsic(_InterlockedOr) */
/* #pragma intrinsic(_InterlockedXor) */
#pragma intrinsic(_InterlockedIncrement)
#pragma intrinsic(_InterlockedDecrement)
#pragma intrinsic(_InterlockedExchange)
#pragma intrinsic(_InterlockedExchangeAdd)
#pragma intrinsic(_InterlockedCompareExchange)
#pragma intrinsic(_InterlockedExchangePointer)
#pragma intrinsic(_InterlockedCompareExchangePointer)
/* #pragma intrinsic(_InterlockedAnd64) */
/* #pragma intrinsic(_InterlockedOr64) */
/* #pragma intrinsic(_InterlockedXor64) */
#pragma intrinsic(_InterlockedIncrement64)
#pragma intrinsic(_InterlockedDecrement64)
#pragma intrinsic(_InterlockedExchange64)
#pragma intrinsic(_InterlockedExchangeAdd64)
#pragma intrinsic(_InterlockedCompareExchange64)

#if __POCC__ >= 1500

#define InterlockedAnd8 _InterlockedAnd8
#define InterlockedOr8 _InterlockedOr8
#define InterlockedXor8 _InterlockedXor8
#define InterlockedAnd16 _InterlockedAnd16
#define InterlockedOr16 _InterlockedOr16
#define InterlockedXor16 _InterlockedXor16

char InterlockedAnd8(char volatile *, char);
char InterlockedOr8(char volatile *, char);
char InterlockedXor8(char volatile *, char);
SHORT InterlockedAnd16(SHORT volatile *, SHORT);
SHORT InterlockedOr16(SHORT volatile *, SHORT);
SHORT InterlockedXor16(SHORT volatile *, SHORT);

#pragma intrinsic(_InterlockedAnd8)
#pragma intrinsic(_InterlockedOr8)
#pragma intrinsic(_InterlockedXor8)
#pragma intrinsic(_InterlockedAnd16)
#pragma intrinsic(_InterlockedOr16)
#pragma intrinsic(_InterlockedXor16)

#endif /* __POCC__ >= 1500 */

#else /* X86 interlocked */

WINBASEAPI LONG WINAPI InterlockedIncrement(LONG volatile *);
WINBASEAPI LONG WINAPI InterlockedDecrement(LONG volatile *);
WINBASEAPI LONG WINAPI InterlockedExchange(LONG volatile *, LONG);

#define InterlockedExchangePointer(Target,Value)  (PVOID)InterlockedExchange((PLONG)(Target),(LONG)(Value))

WINBASEAPI LONG WINAPI InterlockedExchangeAdd(LONG volatile *, LONG);
WINBASEAPI LONG WINAPI InterlockedCompareExchange(LONG volatile *, LONG, LONG);

#if (_WIN32_WINNT >= 0x0502)
WINBASEAPI LONGLONG WINAPI InterlockedCompareExchange64(LONGLONG volatile *, LONGLONG, LONGLONG);

FORCEINLINE LONGLONG InterlockedAnd64(LONGLONG volatile *Destination, LONGLONG Value) {
    LONGLONG Old;
    do
    {
        Old = *Destination;
    } while (InterlockedCompareExchange64(Destination, Old & Value, Old) != Old);
    return Old;
}

FORCEINLINE LONGLONG InterlockedOr64(LONGLONG volatile *Destination, LONGLONG Value) {
    LONGLONG Old;
    do
    {
        Old = *Destination;
    } while (InterlockedCompareExchange64(Destination, Old | Value, Old) != Old);
    return Old;
}

FORCEINLINE LONGLONG InterlockedXor64(LONGLONG volatile *Destination, LONGLONG Value) {
    LONGLONG Old;
    do
    {
        Old = *Destination;
    } while (InterlockedCompareExchange64(Destination, Old ^ Value, Old) != Old);
    return Old;
}

FORCEINLINE LONGLONG InterlockedIncrement64(LONGLONG volatile *Addend) {
    LONGLONG Old;
    do
    {
        Old = *Addend;
    } while (InterlockedCompareExchange64(Addend, Old + 1, Old) != Old);
    return Old + 1;
}

FORCEINLINE LONGLONG InterlockedDecrement64(LONGLONG volatile *Addend) {
    LONGLONG Old;
    do
    {
        Old = *Addend;
    } while (InterlockedCompareExchange64(Addend, Old - 1, Old) != Old);
    return Old - 1;
}

FORCEINLINE LONGLONG InterlockedExchange64(LONGLONG volatile *Target, LONGLONG Value) {
    LONGLONG Old;
    do
    {
        Old = *Target;
    } while (InterlockedCompareExchange64(Target, Value, Old) != Old);
    return Old;
}

FORCEINLINE LONGLONG InterlockedExchangeAdd64(LONGLONG volatile *Addend, LONGLONG Value) {
    LONGLONG Old;
    do
    {
        Old = *Addend;
    } while (InterlockedCompareExchange64(Addend, Old + Value, Old) != Old);
    return Old;
}

#endif /* _WIN32_WINNT >= 0x0502 */

#ifdef __cplusplus
FORCEINLINE PVOID __cdecl __InlineInterlockedCompareExchangePointer(PVOID volatile *Destination, PVOID ExChange, PVOID Comperand) {
    return ((PVOID)(LONG_PTR)InterlockedCompareExchange((LONG volatile *)Destination, (LONG)(LONG_PTR)ExChange, (LONG)(LONG_PTR)Comperand));
}
#define InterlockedCompareExchangePointer __InlineInterlockedCompareExchangePointer
#else /* !__cplusplus */
#define InterlockedCompareExchangePointer(Destination, ExChange, Comperand) \
    (PVOID)(LONG_PTR)InterlockedCompareExchange((LONG volatile *)(Destination), (LONG)(LONG_PTR)(ExChange), (LONG)(LONG_PTR)(Comperand))
#endif /* !__cplusplus */

#define InterlockedIncrementAcquire InterlockedIncrement
#define InterlockedIncrementRelease InterlockedIncrement
#define InterlockedDecrementAcquire InterlockedDecrement
#define InterlockedDecrementRelease InterlockedDecrement
#define InterlockedIncrementAcquire InterlockedIncrement
#define InterlockedIncrementRelease InterlockedIncrement
#define InterlockedCompareExchangeAcquire InterlockedCompareExchange
#define InterlockedCompareExchangeRelease InterlockedCompareExchange
#define InterlockedCompareExchangeAcquire64 InterlockedCompareExchange64
#define InterlockedCompareExchangeRelease64 InterlockedCompareExchange64
#define InterlockedCompareExchangePointerAcquire InterlockedCompareExchangePointer
#define InterlockedCompareExchangePointerRelease InterlockedCompareExchangePointer

#endif /* X86 | IA64 */

#if defined(_SLIST_HEADER_) && !defined(_NTOSP_)

WINBASEAPI VOID WINAPI InitializeSListHead(PSLIST_HEADER);
WINBASEAPI PSLIST_ENTRY WINAPI InterlockedPopEntrySList(PSLIST_HEADER);
WINBASEAPI PSLIST_ENTRY WINAPI InterlockedPushEntrySList(PSLIST_HEADER, PSLIST_ENTRY);
WINBASEAPI PSLIST_ENTRY WINAPI InterlockedFlushSList(PSLIST_HEADER);
WINBASEAPI USHORT WINAPI QueryDepthSList(PSLIST_HEADER);

#endif /* _SLIST_HEADER_ */

#endif /* _NTOS_ */

#endif /* NOWINBASEINTERLOCK */

WINBASEAPI BOOL WINAPI FreeResource(HGLOBAL);
WINBASEAPI LPVOID WINAPI LockResource(HGLOBAL);

#define UnlockResource(hResData)  ((hResData),0)
#define MAXINTATOM  0xC000
#define MAKEINTATOM(i)  (LPTSTR)((ULONG_PTR)((WORD)(i)))
#define INVALID_ATOM ((ATOM)0)

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd);
int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPWSTR lpCmdLine, int nShowCmd);

WINBASEAPI BOOL WINAPI FreeLibrary(HMODULE);
WINBASEAPI DECLSPEC_NORETURN VOID WINAPI FreeLibraryAndExitThread(HMODULE, DWORD);
WINBASEAPI BOOL WINAPI DisableThreadLibraryCalls(HMODULE);
WINBASEAPI FARPROC WINAPI GetProcAddress(HMODULE, LPCSTR);
WINBASEAPI DWORD WINAPI GetVersion(VOID);
WINBASEAPI HGLOBAL WINAPI GlobalAlloc(UINT, SIZE_T);
WINBASEAPI HGLOBAL WINAPI GlobalReAlloc(HGLOBAL, SIZE_T, UINT);
WINBASEAPI SIZE_T WINAPI GlobalSize(HGLOBAL);
WINBASEAPI UINT WINAPI GlobalFlags(HGLOBAL);
WINBASEAPI LPVOID WINAPI GlobalLock(HGLOBAL);
WINBASEAPI HGLOBAL WINAPI GlobalHandle(LPCVOID);
WINBASEAPI BOOL WINAPI GlobalUnlock(HGLOBAL);
WINBASEAPI HGLOBAL WINAPI GlobalFree(HGLOBAL);
WINBASEAPI SIZE_T WINAPI GlobalCompact(DWORD);
WINBASEAPI VOID WINAPI GlobalFix(HGLOBAL);
WINBASEAPI VOID WINAPI GlobalUnfix(HGLOBAL);
WINBASEAPI LPVOID WINAPI GlobalWire(HGLOBAL);
WINBASEAPI BOOL WINAPI GlobalUnWire(HGLOBAL);
WINBASEAPI VOID WINAPI GlobalMemoryStatus(LPMEMORYSTATUS);

typedef struct _MEMORYSTATUSEX {
    DWORD dwLength;
    DWORD dwMemoryLoad;
    DWORDLONG ullTotalPhys;
    DWORDLONG ullAvailPhys;
    DWORDLONG ullTotalPageFile;
    DWORDLONG ullAvailPageFile;
    DWORDLONG ullTotalVirtual;
    DWORDLONG ullAvailVirtual;
    DWORDLONG ullAvailExtendedVirtual;
} MEMORYSTATUSEX, *LPMEMORYSTATUSEX;

WINBASEAPI BOOL WINAPI GlobalMemoryStatusEx(LPMEMORYSTATUSEX);
WINBASEAPI HLOCAL WINAPI LocalAlloc(UINT, SIZE_T);
WINBASEAPI HLOCAL WINAPI LocalReAlloc(HLOCAL, SIZE_T, UINT);
WINBASEAPI LPVOID WINAPI LocalLock(HLOCAL);
WINBASEAPI HLOCAL WINAPI LocalHandle(LPCVOID);
WINBASEAPI BOOL WINAPI LocalUnlock(HLOCAL);
WINBASEAPI SIZE_T WINAPI LocalSize(HLOCAL);
WINBASEAPI UINT WINAPI LocalFlags(HLOCAL);
WINBASEAPI HLOCAL WINAPI LocalFree(HLOCAL);
WINBASEAPI SIZE_T WINAPI LocalShrink(HLOCAL, UINT);
WINBASEAPI SIZE_T WINAPI LocalCompact(UINT);
WINBASEAPI BOOL WINAPI FlushInstructionCache(HANDLE, LPCVOID, SIZE_T);

#if (_WIN32_WINNT >= 0x0600)
WINBASEAPI VOID WINAPI FlushProcessWriteBuffers(VOID);
WINBASEAPI BOOL WINAPI QueryThreadCycleTime(HANDLE, PULONG64);
WINBASEAPI BOOL WINAPI QueryProcessCycleTime(HANDLE, PULONG64);
WINBASEAPI BOOL WINAPI QueryIdleProcessorCycleTime(PULONG, PULONG64);
#endif /* _WIN32_WINNT >= 0x0600 */

#if (_WIN32_WINNT >= 0x0601)
WINBASEAPI BOOL WINAPI QueryIdleProcessorCycleTimeEx(USHORT, PULONG, PULONG64);
WINBASEAPI BOOL WINAPI QueryUnbiasedInterruptTime(PULONGLONG);
WINBASEAPI BOOL WINAPI GetProcessorSystemCycleTime(USHORT, PSYSTEM_PROCESSOR_CYCLE_TIME_INFORMATION, PDWORD);
#endif /* _WIN32_WINNT >= 0x0601 */

WINBASEAPI LPVOID WINAPI VirtualAlloc(LPVOID, SIZE_T, DWORD, DWORD);
WINBASEAPI BOOL WINAPI VirtualFree(LPVOID, SIZE_T, DWORD);
WINBASEAPI BOOL WINAPI VirtualProtect(LPVOID, SIZE_T, DWORD, PDWORD);
WINBASEAPI SIZE_T WINAPI VirtualQuery(LPCVOID, PMEMORY_BASIC_INFORMATION, SIZE_T);
WINBASEAPI LPVOID WINAPI VirtualAllocEx(HANDLE, LPVOID, SIZE_T, DWORD, DWORD);

#if _WIN32_WINNT >= 0x0600
WINBASEAPI LPVOID WINAPI VirtualAllocExNuma(HANDLE, LPVOID, SIZE_T, DWORD, DWORD, DWORD);
#endif /* _WIN32_WINNT >= 0x0600 */

WINBASEAPI UINT WINAPI GetWriteWatch(DWORD, PVOID, SIZE_T, PVOID *, ULONG_PTR *, PULONG);
WINBASEAPI UINT WINAPI ResetWriteWatch(LPVOID, SIZE_T);
WINBASEAPI SIZE_T WINAPI GetLargePageMinimum(VOID);
WINBASEAPI UINT WINAPI EnumSystemFirmwareTables(DWORD, PVOID, DWORD);
WINBASEAPI UINT WINAPI GetSystemFirmwareTable(DWORD, DWORD, PVOID, DWORD);
WINBASEAPI BOOL WINAPI GetPhysicallyInstalledSystemMemory(PULONGLONG);
WINBASEAPI BOOL WINAPI VirtualFreeEx(HANDLE, LPVOID, SIZE_T, DWORD);
WINBASEAPI BOOL WINAPI VirtualProtectEx(HANDLE, LPVOID, SIZE_T, DWORD, PDWORD);
WINBASEAPI SIZE_T WINAPI VirtualQueryEx(HANDLE, LPCVOID, PMEMORY_BASIC_INFORMATION, SIZE_T);
WINBASEAPI HANDLE WINAPI HeapCreate(DWORD, SIZE_T, SIZE_T);
WINBASEAPI BOOL WINAPI HeapDestroy(HANDLE);
WINBASEAPI LPVOID WINAPI HeapAlloc(HANDLE, DWORD, SIZE_T);
WINBASEAPI LPVOID WINAPI HeapReAlloc(HANDLE, DWORD, LPVOID, SIZE_T);
DECLSPEC_RELEASE(3) WINBASEAPI BOOL WINAPI HeapFree(HANDLE, DWORD, LPVOID);
WINBASEAPI SIZE_T WINAPI HeapSize(HANDLE, DWORD, LPCVOID);
WINBASEAPI BOOL WINAPI HeapValidate(HANDLE, DWORD, LPCVOID);
WINBASEAPI SIZE_T WINAPI HeapCompact(HANDLE, DWORD);
WINBASEAPI HANDLE WINAPI GetProcessHeap(VOID);
WINBASEAPI DWORD WINAPI GetProcessHeaps(DWORD, PHANDLE);

typedef struct _PROCESS_HEAP_ENTRY {
    PVOID lpData;
    DWORD cbData;
    BYTE cbOverhead;
    BYTE iRegionIndex;
    WORD wFlags;
    union {
        struct {
            HANDLE hMem;
            DWORD dwReserved[3];
        } Block;
        struct {
            DWORD dwCommittedSize;
            DWORD dwUnCommittedSize;
            LPVOID lpFirstBlock;
            LPVOID lpLastBlock;
        } Region;
    } DUMMYUNIONNAME;
} PROCESS_HEAP_ENTRY, *LPPROCESS_HEAP_ENTRY, *PPROCESS_HEAP_ENTRY;

#define PROCESS_HEAP_REGION  0x0001
#define PROCESS_HEAP_UNCOMMITTED_RANGE  0x0002
#define PROCESS_HEAP_ENTRY_BUSY  0x0004
#define PROCESS_HEAP_ENTRY_MOVEABLE  0x0010
#define PROCESS_HEAP_ENTRY_DDESHARE  0x0020

WINBASEAPI BOOL WINAPI HeapLock(HANDLE);
WINBASEAPI BOOL WINAPI HeapUnlock(HANDLE);
WINBASEAPI BOOL WINAPI HeapWalk(HANDLE, LPPROCESS_HEAP_ENTRY);
WINBASEAPI BOOL WINAPI HeapSetInformation(HANDLE, HEAP_INFORMATION_CLASS, PVOID, SIZE_T);
WINBASEAPI BOOL WINAPI HeapQueryInformation(HANDLE, HEAP_INFORMATION_CLASS, PVOID, SIZE_T, PSIZE_T);

#define SCS_32BIT_BINARY  0
#define SCS_DOS_BINARY  1
#define SCS_WOW_BINARY  2
#define SCS_PIF_BINARY  3
#define SCS_POSIX_BINARY  4
#define SCS_OS216_BINARY  5
#define SCS_64BIT_BINARY  6

#if defined(_WIN64)
# define SCS_THIS_PLATFORM_BINARY  SCS_64BIT_BINARY
#else
# define SCS_THIS_PLATFORM_BINARY  SCS_32BIT_BINARY
#endif

WINBASEAPI BOOL WINAPI GetBinaryTypeA(LPCSTR, LPDWORD);
WINBASEAPI BOOL WINAPI GetBinaryTypeW(LPCWSTR, LPDWORD);
WINBASEAPI DWORD WINAPI GetShortPathNameA(LPCSTR, LPSTR, DWORD);
WINBASEAPI DWORD WINAPI GetShortPathNameW(LPCWSTR, LPWSTR, DWORD);
WINBASEAPI DWORD WINAPI GetLongPathNameA(LPCSTR, LPSTR, DWORD);
WINBASEAPI DWORD WINAPI GetLongPathNameW(LPCWSTR, LPWSTR, DWORD);

#ifdef UNICODE
#define GetBinaryType  GetBinaryTypeW
#define GetShortPathName  GetShortPathNameW
#define GetLongPathName  GetLongPathNameW
#else /* !UNICODE */
#define GetBinaryType  GetBinaryTypeA
#define GetShortPathName  GetShortPathNameA
#define GetLongPathName  GetLongPathNameA
#endif /* !UNICODE */

#if _WIN32_WINNT >= 0x0600
WINBASEAPI DWORD WINAPI GetLongPathNameTransactedA(LPCSTR, LPSTR, DWORD, HANDLE);
WINBASEAPI DWORD WINAPI GetLongPathNameTransactedW(LPCWSTR, LPWSTR, DWORD, HANDLE);
#ifdef UNICODE
#define GetLongPathNameTransacted  GetLongPathNameTransactedW
#else
#define GetLongPathNameTransacted  GetLongPathNameTransactedA
#endif // !UNICODE
#endif /* _WIN32_WINNT >= 0x0600 */

WINBASEAPI BOOL WINAPI GetProcessAffinityMask(HANDLE, PDWORD_PTR, PDWORD_PTR);
WINBASEAPI BOOL WINAPI SetProcessAffinityMask(HANDLE, DWORD_PTR);

#if _WIN32_WINNT >= 0x0601
BOOL WINAPI GetProcessGroupAffinity(HANDLE, PUSHORT, PUSHORT);
#endif /* _WIN32_WINNT >= 0x0601 */

#if _WIN32_WINNT >= 0x0501
WINBASEAPI BOOL WINAPI GetProcessHandleCount(HANDLE, PDWORD);
#endif /* _WIN32_WINNT >= 0x0501 */

WINBASEAPI BOOL WINAPI GetProcessTimes(HANDLE, LPFILETIME, LPFILETIME, LPFILETIME, LPFILETIME);
WINBASEAPI BOOL WINAPI GetProcessIoCounters(HANDLE, PIO_COUNTERS);
WINBASEAPI BOOL WINAPI GetProcessWorkingSetSize(HANDLE, PSIZE_T, PSIZE_T);
WINBASEAPI BOOL WINAPI GetProcessWorkingSetSizeEx(HANDLE, PSIZE_T, PSIZE_T, PDWORD);
WINBASEAPI BOOL WINAPI SetProcessWorkingSetSize(HANDLE, SIZE_T, SIZE_T);
WINBASEAPI BOOL WINAPI SetProcessWorkingSetSizeEx(HANDLE, SIZE_T, SIZE_T, DWORD);

#if (_WIN32_WINNT >= 0x0600)
#define PROCESS_AFFINITY_ENABLE_AUTO_UPDATE  0x00000001UL
WINBASEAPI BOOL WINAPI SetProcessAffinityUpdateMode(HANDLE, DWORD);
WINBASEAPI BOOL WINAPI QueryProcessAffinityUpdateMode(HANDLE, LPDWORD);
#endif /* _WIN32_WINNT >= 0x0600 */

WINBASEAPI HANDLE WINAPI OpenProcess(DWORD, BOOL, DWORD);
WINBASEAPI HANDLE WINAPI GetCurrentProcess(VOID);
WINBASEAPI DWORD WINAPI GetCurrentProcessId(VOID);
WINBASEAPI DECLSPEC_NORETURN VOID WINAPI ExitProcess(UINT);
WINBASEAPI BOOL WINAPI TerminateProcess(HANDLE, UINT);
WINBASEAPI BOOL WINAPI GetExitCodeProcess(HANDLE, LPDWORD);
WINBASEAPI VOID WINAPI FatalExit(int);
WINBASEAPI LPCH WINAPI GetEnvironmentStrings(VOID);
WINBASEAPI LPWCH WINAPI GetEnvironmentStringsW(VOID);
WINBASEAPI BOOL WINAPI SetEnvironmentStringsA(LPCH);
WINBASEAPI BOOL WINAPI SetEnvironmentStringsW(LPWCH);
WINBASEAPI BOOL WINAPI FreeEnvironmentStringsA(LPCH);
WINBASEAPI BOOL WINAPI FreeEnvironmentStringsW(LPWCH);

#ifdef UNICODE
#define GetEnvironmentStrings  GetEnvironmentStringsW
#define SetEnvironmentStrings  SetEnvironmentStringsW
#define FreeEnvironmentStrings  FreeEnvironmentStringsW
#else /* !UNICODE */
#define GetEnvironmentStringsA  GetEnvironmentStrings
#define SetEnvironmentStrings  SetEnvironmentStringsA
#define FreeEnvironmentStrings  FreeEnvironmentStringsA
#endif /* !UNICODE */

WINBASEAPI VOID WINAPI RaiseException(DWORD, DWORD, DWORD, CONST ULONG_PTR *);
WINBASEAPI VOID WINAPI RaiseFailFastException(PEXCEPTION_RECORD, PCONTEXT, DWORD);
WINBASEAPI LONG WINAPI UnhandledExceptionFilter(struct _EXCEPTION_POINTERS *);

typedef LONG(WINAPI *PTOP_LEVEL_EXCEPTION_FILTER)(struct _EXCEPTION_POINTERS *);
typedef PTOP_LEVEL_EXCEPTION_FILTER LPTOP_LEVEL_EXCEPTION_FILTER;

WINBASEAPI LPTOP_LEVEL_EXCEPTION_FILTER WINAPI SetUnhandledExceptionFilter(LPTOP_LEVEL_EXCEPTION_FILTER);

#if (_WIN32_WINNT >= 0x0400)

#define FIBER_FLAG_FLOAT_SWITCH  0x1

WINBASEAPI LPVOID WINAPI CreateFiber(SIZE_T dwStackSize, LPFIBER_START_ROUTINE, LPVOID);
WINBASEAPI LPVOID WINAPI CreateFiberEx(SIZE_T, SIZE_T, DWORD, LPFIBER_START_ROUTINE, LPVOID);
WINBASEAPI VOID WINAPI DeleteFiber(LPVOID);
WINBASEAPI LPVOID WINAPI ConvertThreadToFiber(LPVOID);
WINBASEAPI LPVOID WINAPI ConvertThreadToFiberEx(LPVOID, DWORD);
#if (_WIN32_WINNT >= 0x0501)
WINBASEAPI BOOL WINAPI ConvertFiberToThread(VOID);
#endif /* _WIN32_WINNT >= 0x0501 */
#if (_WIN32_WINNT >= 0x0600)
WINBASEAPI BOOL WINAPI IsThreadAFiber(VOID);
#endif /* _WIN32_WINNT >= 0x0600 */
WINBASEAPI VOID WINAPI SwitchToFiber(LPVOID);
WINBASEAPI BOOL WINAPI SwitchToThread(VOID);

#if (_WIN32_WINNT >= 0x0601)

#define UMS_VERSION  RTL_UMS_VERSION

typedef void *PUMS_CONTEXT;
typedef void *PUMS_COMPLETION_LIST;
typedef enum _RTL_UMS_THREAD_INFO_CLASS UMS_THREAD_INFO_CLASS, *PUMS_THREAD_INFO_CLASS;
typedef enum _RTL_UMS_SCHEDULER_REASON UMS_SCHEDULER_REASON;
typedef PRTL_UMS_SCHEDULER_ENTRY_POINT PUMS_SCHEDULER_ENTRY_POINT;

typedef struct _UMS_SCHEDULER_STARTUP_INFO {
    ULONG UmsVersion;
    PUMS_COMPLETION_LIST CompletionList;
    PUMS_SCHEDULER_ENTRY_POINT SchedulerProc;
    PVOID SchedulerParam;
} UMS_SCHEDULER_STARTUP_INFO, *PUMS_SCHEDULER_STARTUP_INFO;

WINBASEAPI BOOL WINAPI CreateUmsCompletionList(PUMS_COMPLETION_LIST *);
WINBASEAPI BOOL WINAPI DequeueUmsCompletionListItems(PUMS_COMPLETION_LIST, DWORD, PUMS_CONTEXT *);
WINBASEAPI BOOL WINAPI GetUmsCompletionListEvent(PUMS_COMPLETION_LIST, PHANDLE);
WINBASEAPI BOOL WINAPI ExecuteUmsThread(PUMS_CONTEXT);
WINBASEAPI BOOL WINAPI UmsThreadYield(PVOID);
WINBASEAPI BOOL WINAPI DeleteUmsCompletionList(PUMS_COMPLETION_LIST);
WINBASEAPI PUMS_CONTEXT WINAPI GetCurrentUmsThread(VOID);
WINBASEAPI PUMS_CONTEXT WINAPI GetNextUmsListItem(PUMS_CONTEXT);
WINBASEAPI BOOL WINAPI QueryUmsThreadInformation(PUMS_CONTEXT, UMS_THREAD_INFO_CLASS, PVOID, ULONG, PULONG);
WINBASEAPI BOOL WINAPI SetUmsThreadInformation(PUMS_CONTEXT, UMS_THREAD_INFO_CLASS, PVOID, ULONG);
WINBASEAPI BOOL WINAPI DeleteUmsThreadContext(PUMS_CONTEXT);
WINBASEAPI BOOL WINAPI CreateUmsThreadContext(PUMS_CONTEXT *);
WINBASEAPI BOOL WINAPI EnterUmsSchedulingMode(PUMS_SCHEDULER_STARTUP_INFO);

#endif /* _WIN32_WINNT >= 0x0601 */

#endif /* _WIN32_WINNT >= 0x0400 */

typedef struct _PROC_THREAD_ATTRIBUTE_LIST *PPROC_THREAD_ATTRIBUTE_LIST, *LPPROC_THREAD_ATTRIBUTE_LIST;

WINBASEAPI HANDLE WINAPI CreateThread(LPSECURITY_ATTRIBUTES, SIZE_T, LPTHREAD_START_ROUTINE, LPVOID, DWORD, LPDWORD);
WINBASEAPI HANDLE WINAPI CreateRemoteThread(HANDLE, LPSECURITY_ATTRIBUTES, SIZE_T, LPTHREAD_START_ROUTINE, LPVOID, DWORD, LPDWORD);
WINBASEAPI HANDLE WINAPI CreateRemoteThreadEx(HANDLE, LPSECURITY_ATTRIBUTES, SIZE_T, LPTHREAD_START_ROUTINE, LPVOID, DWORD, LPPROC_THREAD_ATTRIBUTE_LIST, LPDWORD);
WINBASEAPI HANDLE WINAPI GetCurrentThread(VOID);
WINBASEAPI DWORD WINAPI GetCurrentThreadId(VOID);
WINBASEAPI BOOL WINAPI SetThreadStackGuarantee(PULONG);
WINBASEAPI DWORD WINAPI GetProcessIdOfThread(HANDLE);
#if (_WIN32_WINNT >= 0x0502)
WINBASEAPI DWORD WINAPI GetThreadId(HANDLE);
#endif /* _WIN32_WINNT >= 0x0502 */
WINBASEAPI DWORD WINAPI GetProcessId(HANDLE);
WINBASEAPI DWORD WINAPI GetCurrentProcessorNumber(VOID);
#if (_WIN32_WINNT >= 0x0601)
WINBASEAPI VOID WINAPI GetCurrentProcessorNumberEx(PPROCESSOR_NUMBER);
#endif /* _WIN32_WINNT >= 0x0601 */
#if (_WIN32_WINNT >= 0x0601)
WINBASEAPI BOOL WINAPI GetThreadGroupAffinity(HANDLE, PGROUP_AFFINITY);
#endif /* _WIN32_WINNT >= 0x0601 */
WINBASEAPI DWORD_PTR WINAPI SetThreadAffinityMask(HANDLE, DWORD_PTR);
#if (_WIN32_WINNT >= 0x0601)
WINBASEAPI BOOL WINAPI SetThreadGroupAffinity(HANDLE, CONST GROUP_AFFINITY *, PGROUP_AFFINITY);
WINBASEAPI BOOL WINAPI SetThreadIdealProcessorEx(HANDLE, PPROCESSOR_NUMBER, PPROCESSOR_NUMBER);
WINBASEAPI BOOL WINAPI GetThreadIdealProcessorEx(HANDLE, PPROCESSOR_NUMBER);
#endif /* _WIN32_WINNT >= 0x0601 */
#if (_WIN32_WINNT >= 0x0400)
WINBASEAPI DWORD WINAPI SetThreadIdealProcessor(HANDLE, DWORD);
#endif /* _WIN32_WINNT >= 0x0400 */
#if (_WIN32_WINNT >= 0x0600)
#define PROCESS_DEP_ENABLE  0x00000001
#define PROCESS_DEP_DISABLE_ATL_THUNK_EMULATION  0x00000002
WINBASEAPI BOOL WINAPI SetProcessDEPPolicy(DWORD);
WINBASEAPI BOOL WINAPI GetProcessDEPPolicy(HANDLE, LPDWORD, PBOOL);
#endif /* _WIN32_WINNT >= 0x0600 */
WINBASEAPI BOOL WINAPI SetProcessPriorityBoost(HANDLE, BOOL);
WINBASEAPI BOOL WINAPI GetProcessPriorityBoost(HANDLE, PBOOL);
WINBASEAPI BOOL WINAPI RequestWakeupLatency(LATENCY_TIME);
WINBASEAPI BOOL WINAPI IsSystemResumeAutomatic(VOID);
WINBASEAPI HANDLE WINAPI OpenThread(DWORD, BOOL, DWORD);
WINBASEAPI BOOL WINAPI SetThreadPriority(HANDLE, int);
WINBASEAPI BOOL WINAPI SetThreadPriorityBoost(HANDLE, BOOL);
WINBASEAPI BOOL WINAPI GetThreadPriorityBoost(HANDLE, PBOOL);
WINBASEAPI int WINAPI GetThreadPriority(HANDLE);
WINBASEAPI BOOL WINAPI GetThreadTimes(HANDLE, LPFILETIME, LPFILETIME, LPFILETIME, LPFILETIME);
#if _WIN32_WINNT >= 0x0501
WINBASEAPI BOOL WINAPI GetThreadIOPendingFlag(HANDLE, PBOOL);
#endif /* _WIN32_WINNT >= 0x0501 */

#if (_WIN32_WINNT >= _WIN32_WINNT_WIN8)
typedef enum _THREAD_INFORMATION_CLASS {
    ThreadMemoryPriority,
    ThreadAbsoluteCpuPriority,
    ThreadInformationClassMax
} THREAD_INFORMATION_CLASS;

WINBASEAPI BOOL WINAPI GetThreadInformation(HANDLE, THREAD_INFORMATION_CLASS, LPVOID, DWORD);
WINBASEAPI BOOL WINAPI SetThreadInformation(HANDLE, THREAD_INFORMATION_CLASS, LPVOID, DWORD);

#define MEMORY_PRIORITY_LOWEST  0
#define MEMORY_PRIORITY_VERY_LOW  1
#define MEMORY_PRIORITY_LOW  2
#define MEMORY_PRIORITY_MEDIUM  3
#define MEMORY_PRIORITY_BELOW_NORMAL  4
#define MEMORY_PRIORITY_NORMAL  5

typedef struct _MEMORY_PRIORITY_INFORMATION {
    ULONG MemoryPriority;
} MEMORY_PRIORITY_INFORMATION, *PMEMORY_PRIORITY_INFORMATION;

#endif /* _WIN32_WINNT >= _WIN32_WINNT_WIN8 */

#if (_WIN32_WINNT >= _WIN32_WINNT_WINBLUE)
WINBASEAPI BOOL WINAPI IsProcessCritical(HANDLE, PBOOL);
#endif /* _WIN32_WINNT >= _WIN32_WINNT_WINBLUE */

WINBASEAPI DECLSPEC_NORETURN VOID WINAPI ExitThread(DWORD);
WINBASEAPI BOOL WINAPI TerminateThread(HANDLE, DWORD);
WINBASEAPI BOOL WINAPI GetExitCodeThread(HANDLE, LPDWORD);
WINBASEAPI BOOL WINAPI GetThreadSelectorEntry(HANDLE, DWORD, LPLDT_ENTRY);
WINBASEAPI EXECUTION_STATE WINAPI SetThreadExecutionState(EXECUTION_STATE);

#if (_WIN32_WINNT >= _WIN32_WINNT_WIN7)
typedef struct _REASON_CONTEXT {
    ULONG Version;
    DWORD Flags;
    union {
        struct {
            HMODULE LocalizedReasonModule;
            ULONG LocalizedReasonId;
            ULONG ReasonStringCount;
            LPWSTR *ReasonStrings;
        } Detailed;
        LPWSTR SimpleReasonString;
    } Reason;
} REASON_CONTEXT, *PREASON_CONTEXT;
typedef REASON_CONTEXT POWER_REQUEST_CONTEXT, *PPOWER_REQUEST_CONTEXT, *LPPOWER_REQUEST_CONTEXT;

WINBASEAPI HANDLE WINAPI PowerCreateRequest(PREASON_CONTEXT);
WINBASEAPI BOOL WINAPI PowerSetRequest(HANDLE, POWER_REQUEST_TYPE);
WINBASEAPI BOOL WINAPI PowerClearRequest(HANDLE, POWER_REQUEST_TYPE);
#endif /* _WIN32_WINNT >= _WIN32_WINNT_WIN7 */

WINBASEAPI DWORD WINAPI GetLastError(VOID);
WINBASEAPI VOID WINAPI SetLastError(DWORD dwErrCode);

/*#ifdef WINBASE_DECLARE_RESTORE_LAST_ERROR
WINBASEAPI VOID WINAPI RestoreLastError(DWORD);
typedef VOID(WINAPI *PRESTORE_LAST_ERROR)(DWORD);
#define RESTORE_LAST_ERROR_NAME_A  "RestoreLastError"
#define RESTORE_LAST_ERROR_NAME_W  L"RestoreLastError"
#define RESTORE_LAST_ERROR_NAME  TEXT("RestoreLastError")
#endif*/ /* WINBASE_DECLARE_RESTORE_LAST_ERROR */

#define HasOverlappedIoCompleted(lpOverlapped)  (((DWORD)(lpOverlapped)->Internal) != STATUS_PENDING)

WINBASEAPI BOOL WINAPI GetOverlappedResult(HANDLE, LPOVERLAPPED, LPDWORD, BOOL);
WINBASEAPI HANDLE WINAPI CreateIoCompletionPort(HANDLE, HANDLE, ULONG_PTR, DWORD);
WINBASEAPI BOOL WINAPI GetQueuedCompletionStatus(HANDLE, LPDWORD, PULONG_PTR, LPOVERLAPPED *, DWORD);
#if (_WIN32_WINNT >= 0x0600)
WINBASEAPI BOOL WINAPI GetQueuedCompletionStatusEx(HANDLE, LPOVERLAPPED_ENTRY, ULONG, PULONG, DWORD, BOOL);
#endif /* _WIN32_WINNT >= 0x0600 */
WINBASEAPI BOOL WINAPI PostQueuedCompletionStatus(HANDLE, DWORD, ULONG_PTR, LPOVERLAPPED);
#if (_WIN32_WINNT >= 0x0600)
#define FILE_SKIP_COMPLETION_PORT_ON_SUCCESS  0x1
#define FILE_SKIP_SET_EVENT_ON_HANDLE  0x2
WINBASEAPI BOOL WINAPI SetFileCompletionNotificationModes(HANDLE, UCHAR);
WINBASEAPI BOOL WINAPI SetFileIoOverlappedRange(HANDLE, PUCHAR, ULONG);
#endif /* _WIN32_WINNT >= 0x0600 */

#define SEM_FAILCRITICALERRORS  0x0001
#define SEM_NOGPFAULTERRORBOX  0x0002
#define SEM_NOALIGNMENTFAULTEXCEPT  0x0004
#define SEM_NOOPENFILEERRORBOX  0x8000

WINBASEAPI UINT WINAPI GetErrorMode(VOID);
WINBASEAPI UINT WINAPI SetErrorMode(UINT);
WINBASEAPI DWORD WINAPI GetThreadErrorMode(VOID);
WINBASEAPI BOOL WINAPI SetThreadErrorMode(DWORD, LPDWORD);

WINBASEAPI BOOL WINAPI ReadProcessMemory(HANDLE, LPCVOID, LPVOID, SIZE_T, SIZE_T *);
WINBASEAPI BOOL WINAPI WriteProcessMemory(HANDLE, LPVOID, LPCVOID, SIZE_T, SIZE_T *);
WINBASEAPI BOOL WINAPI GetThreadContext(HANDLE, LPCONTEXT);
WINBASEAPI BOOL WINAPI SetThreadContext(HANDLE, CONST CONTEXT *);
WINBASEAPI BOOL WINAPI Wow64GetThreadContext(HANDLE, PWOW64_CONTEXT);
#if (_WIN32_WINNT >= 0x0601)
WINBASEAPI BOOL WINAPI Wow64GetThreadSelectorEntry(HANDLE, DWORD, PWOW64_LDT_ENTRY lpSeectorEntry);
#endif /* _WIN32_WINNT >= 0x0601 */
WINBASEAPI BOOL WINAPI Wow64SetThreadContext(HANDLE, CONST WOW64_CONTEXT *);
WINBASEAPI DWORD WINAPI SuspendThread(HANDLE);
WINBASEAPI DWORD WINAPI Wow64SuspendThread(HANDLE);
WINBASEAPI DWORD WINAPI ResumeThread(HANDLE hThread);
#if (_WIN32_WINNT >= 0x0400) || (_WIN32_WINDOWS > 0x0400)
WINBASEAPI DWORD WINAPI QueueUserAPC(PAPCFUNC, HANDLE, ULONG_PTR);
WINBASEAPI BOOL WINAPI IsDebuggerPresent(VOID);
#endif
#if _WIN32_WINNT >= 0x0501
WINBASEAPI BOOL WINAPI CheckRemoteDebuggerPresent(HANDLE, PBOOL);
#endif /* _WIN32_WINNT >= 0x0501 */
WINBASEAPI VOID WINAPI DebugBreak(VOID);
WINBASEAPI BOOL WINAPI WaitForDebugEvent(LPDEBUG_EVENT, DWORD);
WINBASEAPI BOOL WINAPI ContinueDebugEvent(DWORD, DWORD, DWORD);
WINBASEAPI BOOL WINAPI DebugActiveProcess(DWORD);
WINBASEAPI BOOL WINAPI DebugActiveProcessStop(DWORD);
WINBASEAPI BOOL WINAPI DebugSetProcessKillOnExit(BOOL);
WINBASEAPI BOOL WINAPI DebugBreakProcess(HANDLE);

WINBASEAPI VOID WINAPI InitializeCriticalSection(LPCRITICAL_SECTION);
WINBASEAPI VOID WINAPI EnterCriticalSection(LPCRITICAL_SECTION);
WINBASEAPI VOID WINAPI LeaveCriticalSection(LPCRITICAL_SECTION);

#if (_WIN32_WINNT >= 0x0403)
#define CRITICAL_SECTION_NO_DEBUG_INFO  RTL_CRITICAL_SECTION_FLAG_NO_DEBUG_INFO
WINBASEAPI BOOL WINAPI InitializeCriticalSectionAndSpinCount(LPCRITICAL_SECTION, DWORD);
WINBASEAPI BOOL WINAPI InitializeCriticalSectionEx(LPCRITICAL_SECTION, DWORD, DWORD);
WINBASEAPI DWORD WINAPI SetCriticalSectionSpinCount(LPCRITICAL_SECTION, DWORD);
#endif /* _WIN32_WINNT >= 0x0403 */
#if (_WIN32_WINNT >= 0x0400)
WINBASEAPI BOOL WINAPI TryEnterCriticalSection(LPCRITICAL_SECTION);
#endif /* _WIN32_WINNT >= 0x0400 */
WINBASEAPI VOID WINAPI DeleteCriticalSection(LPCRITICAL_SECTION);
WINBASEAPI BOOL WINAPI SetEvent(HANDLE);
WINBASEAPI BOOL WINAPI ResetEvent(HANDLE);
WINBASEAPI BOOL WINAPI PulseEvent(HANDLE);
WINBASEAPI BOOL WINAPI ReleaseSemaphore(HANDLE, LONG, LPLONG);
WINBASEAPI BOOL WINAPI ReleaseMutex(HANDLE);
WINBASEAPI DWORD WINAPI WaitForSingleObject(HANDLE, DWORD);
WINBASEAPI DWORD WINAPI WaitForMultipleObjects(DWORD, CONST HANDLE *, BOOL, DWORD);
WINBASEAPI VOID WINAPI Sleep(DWORD);

WINBASEAPI HGLOBAL WINAPI LoadResource(HMODULE, HRSRC);
WINBASEAPI DWORD WINAPI SizeofResource(HMODULE, HRSRC);

WINBASEAPI ATOM WINAPI GlobalDeleteAtom(ATOM);
WINBASEAPI BOOL WINAPI InitAtomTable(DWORD);
WINBASEAPI ATOM WINAPI DeleteAtom(ATOM);

WINBASEAPI UINT WINAPI SetHandleCount(UINT);
WINBASEAPI DWORD WINAPI GetLogicalDrives(VOID);

#define LOCKFILE_FAIL_IMMEDIATELY  0x00000001
#define LOCKFILE_EXCLUSIVE_LOCK  0x00000002

WINBASEAPI BOOL WINAPI LockFile(HANDLE, DWORD, DWORD, DWORD, DWORD);
WINBASEAPI BOOL WINAPI UnlockFile(HANDLE, DWORD, DWORD, DWORD, DWORD);
WINBASEAPI BOOL WINAPI LockFileEx(HANDLE, DWORD, DWORD, DWORD, DWORD, LPOVERLAPPED);
WINBASEAPI BOOL WINAPI UnlockFileEx(HANDLE, DWORD, DWORD, DWORD, LPOVERLAPPED);

typedef struct _BY_HANDLE_FILE_INFORMATION {
    DWORD dwFileAttributes;
    FILETIME ftCreationTime;
    FILETIME ftLastAccessTime;
    FILETIME ftLastWriteTime;
    DWORD dwVolumeSerialNumber;
    DWORD nFileSizeHigh;
    DWORD nFileSizeLow;
    DWORD nNumberOfLinks;
    DWORD nFileIndexHigh;
    DWORD nFileIndexLow;
} BY_HANDLE_FILE_INFORMATION, *PBY_HANDLE_FILE_INFORMATION, *LPBY_HANDLE_FILE_INFORMATION;

WINBASEAPI BOOL WINAPI GetFileInformationByHandle(HANDLE, LPBY_HANDLE_FILE_INFORMATION);
WINBASEAPI DWORD WINAPI GetFileType(HANDLE);
WINBASEAPI DWORD WINAPI GetFileSize(HANDLE, LPDWORD);
WINBASEAPI BOOL WINAPI GetFileSizeEx(HANDLE, PLARGE_INTEGER);
WINBASEAPI HANDLE WINAPI GetStdHandle(DWORD);
WINBASEAPI BOOL WINAPI SetStdHandle(DWORD, HANDLE);
#if (_WIN32_WINNT >= 0x0600)
WINBASEAPI BOOL WINAPI SetStdHandleEx(DWORD, HANDLE, PHANDLE);
#endif /* _WIN32_WINNT >= 0x0600 */
WINBASEAPI BOOL WINAPI WriteFile(HANDLE, LPCVOID, DWORD, LPDWORD, LPOVERLAPPED);
WINBASEAPI BOOL WINAPI ReadFile(HANDLE, LPVOID, DWORD, LPDWORD, LPOVERLAPPED);
WINBASEAPI BOOL WINAPI FlushFileBuffers(HANDLE);
WINBASEAPI BOOL WINAPI DeviceIoControl(HANDLE, DWORD, LPVOID, DWORD, LPVOID, DWORD, LPDWORD, LPOVERLAPPED);
WINBASEAPI BOOL WINAPI RequestDeviceWakeup(HANDLE);
WINBASEAPI BOOL WINAPI CancelDeviceWakeupRequest(HANDLE);
WINBASEAPI BOOL WINAPI GetDevicePowerState(HANDLE, BOOL *);
WINBASEAPI BOOL WINAPI SetMessageWaitingIndicator(HANDLE, ULONG);
WINBASEAPI BOOL WINAPI SetEndOfFile(HANDLE);
WINBASEAPI DWORD WINAPI SetFilePointer(HANDLE, LONG, PLONG, DWORD);
WINBASEAPI BOOL WINAPI SetFilePointerEx(HANDLE, LARGE_INTEGER, PLARGE_INTEGER, DWORD);
WINBASEAPI BOOL WINAPI FindClose(HANDLE);
WINBASEAPI BOOL WINAPI GetFileTime(HANDLE, LPFILETIME, LPFILETIME, LPFILETIME);
WINBASEAPI BOOL WINAPI SetFileTime(HANDLE, CONST FILETIME *, CONST FILETIME *, CONST FILETIME *);
#if _WIN32_WINNT >= 0x0501
WINBASEAPI BOOL WINAPI SetFileValidData(HANDLE, LONGLONG);
#endif /* _WIN32_WINNT >= 0x0501 */
WINBASEAPI BOOL WINAPI SetFileShortNameA(HANDLE, LPCSTR);
WINBASEAPI BOOL WINAPI SetFileShortNameW(HANDLE, LPCWSTR);

#ifdef UNICODE
#define SetFileShortName  SetFileShortNameW
#else
#define SetFileShortName  SetFileShortNameA
#endif // !UNICODE

WINBASEAPI BOOL WINAPI CloseHandle(HANDLE);
WINBASEAPI BOOL WINAPI DuplicateHandle(HANDLE, HANDLE, HANDLE,   LPHANDLE, DWORD, BOOL, DWORD);
WINBASEAPI BOOL WINAPI GetHandleInformation(HANDLE, LPDWORD);
WINBASEAPI BOOL WINAPI SetHandleInformation(HANDLE, DWORD, DWORD);

#define HANDLE_FLAG_INHERIT  0x00000001
#define HANDLE_FLAG_PROTECT_FROM_CLOSE  0x00000002

#define HINSTANCE_ERROR 32

WINBASEAPI DWORD WINAPI LoadModule(LPCSTR, LPVOID);
WINBASEAPI UINT WINAPI WinExec(LPCSTR, UINT);
WINBASEAPI BOOL WINAPI ClearCommBreak(HANDLE);
WINBASEAPI BOOL WINAPI ClearCommError(HANDLE, LPDWORD, LPCOMSTAT);
WINBASEAPI BOOL WINAPI SetupComm(HANDLE, DWORD, DWORD);
WINBASEAPI BOOL WINAPI EscapeCommFunction(HANDLE, DWORD);
WINBASEAPI BOOL WINAPI GetCommConfig(HANDLE, LPCOMMCONFIG, LPDWORD);
WINBASEAPI BOOL WINAPI GetCommMask(HANDLE, LPDWORD);
WINBASEAPI BOOL WINAPI GetCommProperties(HANDLE, LPCOMMPROP);
WINBASEAPI BOOL WINAPI GetCommModemStatus(HANDLE, LPDWORD);
WINBASEAPI BOOL WINAPI GetCommState(HANDLE, LPDCB);
WINBASEAPI BOOL WINAPI GetCommTimeouts(HANDLE, LPCOMMTIMEOUTS);
WINBASEAPI BOOL WINAPI PurgeComm(HANDLE, DWORD);
WINBASEAPI BOOL WINAPI SetCommBreak(HANDLE);
WINBASEAPI BOOL WINAPI SetCommConfig(HANDLE, LPCOMMCONFIG, DWORD);
WINBASEAPI BOOL WINAPI SetCommMask(HANDLE, DWORD);
WINBASEAPI BOOL WINAPI SetCommState(HANDLE, LPDCB);
WINBASEAPI BOOL WINAPI SetCommTimeouts(HANDLE, LPCOMMTIMEOUTS);
WINBASEAPI BOOL WINAPI TransmitCommChar(HANDLE, char);
WINBASEAPI BOOL WINAPI WaitCommEvent(HANDLE, LPDWORD, LPOVERLAPPED);
WINBASEAPI DWORD WINAPI SetTapePosition(HANDLE, DWORD, DWORD, DWORD, DWORD, BOOL);
WINBASEAPI DWORD WINAPI GetTapePosition(HANDLE, DWORD, LPDWORD, LPDWORD, LPDWORD);
WINBASEAPI DWORD WINAPI PrepareTape(HANDLE, DWORD, BOOL);
WINBASEAPI DWORD WINAPI EraseTape(HANDLE, DWORD, BOOL);
WINBASEAPI DWORD WINAPI CreateTapePartition(HANDLE, DWORD, DWORD, DWORD);
WINBASEAPI DWORD WINAPI WriteTapemark(HANDLE, DWORD, DWORD, BOOL);
WINBASEAPI DWORD WINAPI GetTapeStatus(HANDLE);
WINBASEAPI DWORD WINAPI GetTapeParameters(HANDLE, DWORD, LPDWORD, LPVOID);

#define GET_TAPE_MEDIA_INFORMATION  0
#define GET_TAPE_DRIVE_INFORMATION  1

WINBASEAPI DWORD WINAPI SetTapeParameters(HANDLE, DWORD, LPVOID);

#define SET_TAPE_MEDIA_INFORMATION  0
#define SET_TAPE_DRIVE_INFORMATION  1

WINBASEAPI BOOL WINAPI Beep(DWORD, DWORD);
WINBASEAPI int WINAPI MulDiv(int, int, int);
WINBASEAPI VOID WINAPI GetSystemTime(LPSYSTEMTIME);
WINBASEAPI VOID WINAPI GetSystemTimeAsFileTime(LPFILETIME);
WINBASEAPI BOOL WINAPI SetSystemTime(CONST SYSTEMTIME *);
WINBASEAPI VOID WINAPI GetLocalTime(LPSYSTEMTIME);
WINBASEAPI BOOL WINAPI SetLocalTime(CONST SYSTEMTIME *);
WINBASEAPI VOID WINAPI GetSystemInfo(LPSYSTEM_INFO);

typedef enum _DEP_SYSTEM_POLICY_TYPE {
    DEPPolicyAlwaysOff = 0,
    DEPPolicyAlwaysOn,
    DEPPolicyOptIn,
    DEPPolicyOptOut,
    DEPTotalPolicyCount
} DEP_SYSTEM_POLICY_TYPE;

WINBASEAPI DEP_SYSTEM_POLICY_TYPE WINAPI GetSystemDEPPolicy(VOID);

#if _WIN32_WINNT >= 0x0502
#define FILE_CACHE_FLAGS_DEFINED

#define FILE_CACHE_MAX_HARD_ENABLE  0x00000001
#define FILE_CACHE_MAX_HARD_DISABLE  0x00000002
#define FILE_CACHE_MIN_HARD_ENABLE  0x00000004
#define FILE_CACHE_MIN_HARD_DISABLE  0x00000008

WINBASEAPI BOOL WINAPI SetSystemFileCacheSize(SIZE_T, SIZE_T, DWORD);
WINBASEAPI BOOL WINAPI GetSystemFileCacheSize(PSIZE_T, PSIZE_T, PDWORD);
#endif /* _WIN32_WINNT >= 0x0502 */

#if _WIN32_WINNT >= 0x0501
WINBASEAPI BOOL WINAPI GetSystemRegistryQuota(PDWORD, PDWORD);
WINBASEAPI BOOL WINAPI GetSystemTimes(LPFILETIME, LPFILETIME, LPFILETIME);
WINBASEAPI VOID WINAPI GetNativeSystemInfo(LPSYSTEM_INFO);
#endif /* _WIN32_WINNT >= 0x0501 */

WINBASEAPI BOOL WINAPI IsProcessorFeaturePresent(DWORD);

typedef struct _TIME_ZONE_INFORMATION {
    LONG Bias;
    WCHAR StandardName[32];
    SYSTEMTIME StandardDate;
    LONG StandardBias;
    WCHAR DaylightName[32];
    SYSTEMTIME DaylightDate;
    LONG DaylightBias;
} TIME_ZONE_INFORMATION, *PTIME_ZONE_INFORMATION, *LPTIME_ZONE_INFORMATION;

typedef struct _TIME_DYNAMIC_ZONE_INFORMATION {
    LONG Bias;
    WCHAR StandardName[32];
    SYSTEMTIME StandardDate;
    LONG StandardBias;
    WCHAR DaylightName[32];
    SYSTEMTIME DaylightDate;
    LONG DaylightBias;
    WCHAR TimeZoneKeyName[128];
    BOOLEAN DynamicDaylightTimeDisabled;
} DYNAMIC_TIME_ZONE_INFORMATION, *PDYNAMIC_TIME_ZONE_INFORMATION;

WINBASEAPI BOOL WINAPI SystemTimeToTzSpecificLocalTime(CONST TIME_ZONE_INFORMATION *, CONST SYSTEMTIME *, LPSYSTEMTIME);
WINBASEAPI BOOL WINAPI TzSpecificLocalTimeToSystemTime(CONST TIME_ZONE_INFORMATION *, CONST SYSTEMTIME *, LPSYSTEMTIME);
BOOL WINAPI GetTimeZoneInformationForYear(USHORT wYear, PDYNAMIC_TIME_ZONE_INFORMATION, LPTIME_ZONE_INFORMATION);
WINBASEAPI DWORD WINAPI GetTimeZoneInformation(LPTIME_ZONE_INFORMATION);
WINBASEAPI BOOL WINAPI SetTimeZoneInformation(CONST TIME_ZONE_INFORMATION *);
WINBASEAPI DWORD WINAPI GetDynamicTimeZoneInformation(PDYNAMIC_TIME_ZONE_INFORMATION);
WINBASEAPI BOOL WINAPI SetDynamicTimeZoneInformation(CONST DYNAMIC_TIME_ZONE_INFORMATION *);
WINBASEAPI BOOL WINAPI SystemTimeToFileTime(CONST SYSTEMTIME *, LPFILETIME);
WINBASEAPI BOOL WINAPI FileTimeToLocalFileTime(CONST FILETIME *, LPFILETIME);
WINBASEAPI BOOL WINAPI LocalFileTimeToFileTime(CONST FILETIME *, LPFILETIME);
WINBASEAPI BOOL WINAPI FileTimeToSystemTime(CONST FILETIME *, LPSYSTEMTIME);
WINBASEAPI LONG WINAPI CompareFileTime(CONST FILETIME *, CONST FILETIME *);
WINBASEAPI BOOL WINAPI FileTimeToDosDateTime(CONST FILETIME *, LPWORD, LPWORD);
WINBASEAPI BOOL WINAPI DosDateTimeToFileTime(WORD, WORD, LPFILETIME);
WINBASEAPI DWORD WINAPI GetTickCount(VOID);
#if (_WIN32_WINNT >= 0x0600)
WINBASEAPI ULONGLONG WINAPI GetTickCount64(VOID);
#endif /* _WIN32_WINNT >= 0x0600 */
WINBASEAPI BOOL WINAPI SetSystemTimeAdjustment(DWORD, BOOL);
WINBASEAPI BOOL WINAPI GetSystemTimeAdjustment(PDWORD, PDWORD, PBOOL);

WINBASEAPI DWORD WINAPI FormatMessageA(DWORD, LPCVOID, DWORD, DWORD, LPSTR, DWORD, va_list *);
WINBASEAPI DWORD WINAPI FormatMessageW(DWORD, LPCVOID, DWORD, DWORD, LPWSTR, DWORD, va_list *);

#ifdef UNICODE
#define FormatMessage  FormatMessageW
#else /* !UNICODE */
#define FormatMessage  FormatMessageA
#endif /* !UNICODE */

#define FORMAT_MESSAGE_ALLOCATE_BUFFER  0x00000100
#define FORMAT_MESSAGE_IGNORE_INSERTS  0x00000200
#define FORMAT_MESSAGE_FROM_STRING  0x00000400
#define FORMAT_MESSAGE_FROM_HMODULE  0x00000800
#define FORMAT_MESSAGE_FROM_SYSTEM  0x00001000
#define FORMAT_MESSAGE_ARGUMENT_ARRAY  0x00002000
#define FORMAT_MESSAGE_MAX_WIDTH_MASK  0x000000FF

WINBASEAPI BOOL WINAPI CreatePipe(PHANDLE, PHANDLE, LPSECURITY_ATTRIBUTES, DWORD);
WINBASEAPI BOOL WINAPI ConnectNamedPipe(HANDLE, LPOVERLAPPED);
WINBASEAPI BOOL WINAPI DisconnectNamedPipe(HANDLE);
WINBASEAPI BOOL WINAPI SetNamedPipeHandleState(HANDLE, LPDWORD, LPDWORD, LPDWORD);
WINBASEAPI BOOL WINAPI GetNamedPipeInfo(HANDLE, LPDWORD, LPDWORD, LPDWORD, LPDWORD);
WINBASEAPI BOOL WINAPI PeekNamedPipe(HANDLE, LPVOID, DWORD, LPDWORD, LPDWORD, LPDWORD);
WINBASEAPI BOOL WINAPI TransactNamedPipe(HANDLE, LPVOID, DWORD, LPVOID, DWORD, LPDWORD, LPOVERLAPPED);
WINBASEAPI HANDLE WINAPI CreateMailslotA(LPCSTR, DWORD, DWORD, LPSECURITY_ATTRIBUTES);
WINBASEAPI HANDLE WINAPI CreateMailslotW(LPCWSTR, DWORD, DWORD, LPSECURITY_ATTRIBUTES);

#ifdef UNICODE
#define CreateMailslot  CreateMailslotW
#else /* !UNICODE */
#define CreateMailslot  CreateMailslotA
#endif /* !UNICODE */

WINBASEAPI BOOL WINAPI GetMailslotInfo(HANDLE, LPDWORD, LPDWORD, LPDWORD, LPDWORD);
WINBASEAPI BOOL WINAPI SetMailslotInfo(HANDLE, DWORD);
WINBASEAPI LPVOID WINAPI MapViewOfFile(HANDLE, DWORD, DWORD, DWORD, SIZE_T);
WINBASEAPI BOOL WINAPI FlushViewOfFile(LPCVOID, SIZE_T);
WINBASEAPI BOOL WINAPI UnmapViewOfFile(LPCVOID);

#define FILE_ENCRYPTABLE  0
#define FILE_IS_ENCRYPTED  1
#define FILE_SYSTEM_ATTR  2
#define FILE_ROOT_DIR  3
#define FILE_SYSTEM_DIR  4
#define FILE_UNKNOWN  5
#define FILE_SYSTEM_NOT_SUPPORT  6
#define FILE_USER_DISALLOWED  7
#define FILE_READ_ONLY  8
#define FILE_DIR_DISALLOWED  9

WINADVAPI BOOL WINAPI EncryptFileA(LPCSTR);
WINADVAPI BOOL WINAPI EncryptFileW(LPCWSTR);
WINADVAPI BOOL WINAPI DecryptFileA(LPCSTR, DWORD);
WINADVAPI BOOL WINAPI DecryptFileW(LPCWSTR, DWORD);
WINADVAPI BOOL WINAPI FileEncryptionStatusA(LPCSTR, LPDWORD);
WINADVAPI BOOL WINAPI FileEncryptionStatusW(LPCWSTR, LPDWORD);

#ifdef UNICODE
#define EncryptFile  EncryptFileW
#define DecryptFile  DecryptFileW
#define FileEncryptionStatus  FileEncryptionStatusW
#else /* !UNICODE */
#define EncryptFile  EncryptFileA
#define DecryptFile  DecryptFileA
#define FileEncryptionStatus  FileEncryptionStatusA
#endif /* !UNICODE */

#define EFS_USE_RECOVERY_KEYS  (0x1)

typedef DWORD (WINAPI *PFE_EXPORT_FUNC)(PBYTE, PVOID, ULONG);
typedef DWORD (WINAPI *PFE_IMPORT_FUNC)(PBYTE, PVOID, PULONG);

#define CREATE_FOR_IMPORT  (1)
#define CREATE_FOR_DIR  (2)
#define OVERWRITE_HIDDEN  (4)
#define EFSRPC_SECURE_ONLY  (8)

WINADVAPI DWORD WINAPI OpenEncryptedFileRawA(LPCSTR, ULONG, PVOID *);
WINADVAPI DWORD WINAPI OpenEncryptedFileRawW(LPCWSTR, ULONG, PVOID *);

#ifdef UNICODE
#define OpenEncryptedFileRaw  OpenEncryptedFileRawW
#else /* !UNICODE */
#define OpenEncryptedFileRaw  OpenEncryptedFileRawA
#endif /* !UNICODE */

WINADVAPI DWORD WINAPI ReadEncryptedFileRaw(PFE_EXPORT_FUNC, PVOID, PVOID);
WINADVAPI DWORD WINAPI WriteEncryptedFileRaw(PFE_IMPORT_FUNC, PVOID, PVOID);
WINADVAPI VOID WINAPI CloseEncryptedFileRaw(PVOID);

WINBASEAPI int WINAPI lstrcmpA(LPCSTR, LPCSTR);
WINBASEAPI int WINAPI lstrcmpW(LPCWSTR, LPCWSTR);
WINBASEAPI int WINAPI lstrcmpiA(LPCSTR, LPCSTR);
WINBASEAPI int WINAPI lstrcmpiW(LPCWSTR, LPCWSTR);
WINBASEAPI LPSTR WINAPI lstrcpynA(LPSTR, LPCSTR, int);
WINBASEAPI LPWSTR WINAPI lstrcpynW(LPWSTR, LPCWSTR, int);
WINBASEAPI LPSTR WINAPI lstrcpyA(LPSTR, LPCSTR);
WINBASEAPI LPWSTR WINAPI lstrcpyW(LPWSTR, LPCWSTR);
WINBASEAPI LPSTR WINAPI lstrcatA(LPSTR, LPCSTR);
WINBASEAPI LPWSTR WINAPI lstrcatW(LPWSTR, LPCWSTR);
WINBASEAPI int WINAPI lstrlenA(LPCSTR);
WINBASEAPI int WINAPI lstrlenW(LPCWSTR);

#ifdef UNICODE
#define lstrcmp  lstrcmpW
#define lstrcmpi  lstrcmpiW
#define lstrcpyn  lstrcpynW
#define lstrcpy  lstrcpyW
#define lstrcat  lstrcatW
#define lstrlen  lstrlenW
#else
#define lstrcmp  lstrcmpA
#define lstrcmpi  lstrcmpiA
#define lstrcpyn  lstrcpynA
#define lstrcpy  lstrcpyA
#define lstrcat  lstrcatA
#define lstrlen  lstrlenA
#endif // !UNICODE

WINBASEAPI HFILE WINAPI OpenFile(LPCSTR, LPOFSTRUCT, UINT);
WINBASEAPI HFILE WINAPI _lopen(LPCSTR, int);
WINBASEAPI HFILE WINAPI _lcreat(LPCSTR, int);
WINBASEAPI UINT WINAPI _lread(HFILE, LPVOID, UINT);
WINBASEAPI UINT WINAPI _lwrite(HFILE, LPCCH, UINT);
WINBASEAPI long WINAPI _hread(HFILE, LPVOID, long);
WINBASEAPI long WINAPI _hwrite(HFILE, LPCCH, long);
WINBASEAPI HFILE WINAPI _lclose(HFILE);
WINBASEAPI LONG WINAPI _llseek(HFILE, LONG, int);
WINADVAPI BOOL WINAPI IsTextUnicode(CONST VOID *, int, LPINT);

#define FLS_OUT_OF_INDEXES  ((DWORD)0xFFFFFFFF)

WINBASEAPI DWORD WINAPI FlsAlloc(PFLS_CALLBACK_FUNCTION);
WINBASEAPI PVOID WINAPI FlsGetValue(DWORD);
WINBASEAPI BOOL WINAPI FlsSetValue(DWORD, PVOID);
WINBASEAPI BOOL WINAPI FlsFree(DWORD);

#define TLS_OUT_OF_INDEXES  ((DWORD)0xFFFFFFFF)

WINBASEAPI DWORD WINAPI TlsAlloc(VOID);
WINBASEAPI LPVOID WINAPI TlsGetValue(DWORD);
WINBASEAPI BOOL WINAPI TlsSetValue(DWORD, LPVOID);
WINBASEAPI BOOL WINAPI TlsFree(DWORD);

typedef VOID(WINAPI *LPOVERLAPPED_COMPLETION_ROUTINE) (DWORD, DWORD, LPOVERLAPPED);

WINBASEAPI DWORD WINAPI SleepEx(DWORD, BOOL);
WINBASEAPI DWORD WINAPI WaitForSingleObjectEx(HANDLE, DWORD, BOOL);
WINBASEAPI DWORD WINAPI WaitForMultipleObjectsEx(DWORD, CONST HANDLE *, BOOL, DWORD, BOOL);
#if (_WIN32_WINNT >= 0x0400)
WINBASEAPI DWORD WINAPI SignalObjectAndWait(HANDLE, HANDLE, DWORD, BOOL);
#endif /* _WIN32_WINNT >= 0x0400 */

WINBASEAPI BOOL WINAPI ReadFileEx(HANDLE, LPVOID, DWORD, LPOVERLAPPED, LPOVERLAPPED_COMPLETION_ROUTINE);
WINBASEAPI BOOL WINAPI WriteFileEx(HANDLE, LPCVOID, DWORD, LPOVERLAPPED, LPOVERLAPPED_COMPLETION_ROUTINE);
WINBASEAPI BOOL WINAPI BackupRead(HANDLE, LPBYTE, DWORD, LPDWORD, BOOL, BOOL, LPVOID *);
WINBASEAPI BOOL WINAPI BackupSeek(HANDLE, DWORD, DWORD, LPDWORD, LPDWORD, LPVOID *);
WINBASEAPI BOOL WINAPI BackupWrite(HANDLE, LPBYTE, DWORD, LPDWORD, BOOL, BOOL, LPVOID *);

typedef struct _WIN32_STREAM_ID {
    DWORD dwStreamId;
    DWORD dwStreamAttributes;
    LARGE_INTEGER Size;
    DWORD dwStreamNameSize;
    WCHAR cStreamName[ANYSIZE_ARRAY];
} WIN32_STREAM_ID, *LPWIN32_STREAM_ID;

#define BACKUP_INVALID  0x00000000
#define BACKUP_DATA  0x00000001
#define BACKUP_EA_DATA  0x00000002
#define BACKUP_SECURITY_DATA  0x00000003
#define BACKUP_ALTERNATE_DATA  0x00000004
#define BACKUP_LINK  0x00000005
#define BACKUP_PROPERTY_DATA  0x00000006
#define BACKUP_OBJECT_ID  0x00000007
#define BACKUP_REPARSE_DATA  0x00000008
#define BACKUP_SPARSE_BLOCK  0x00000009
#define BACKUP_TXFS_DATA  0x0000000a

#define STREAM_NORMAL_ATTRIBUTE  0x00000000
#define STREAM_MODIFIED_WHEN_READ  0x00000001
#define STREAM_CONTAINS_SECURITY  0x00000002
#define STREAM_CONTAINS_PROPERTIES  0x00000004
#define STREAM_SPARSE_ATTRIBUTE  0x00000008

WINBASEAPI BOOL WINAPI ReadFileScatter(HANDLE, FILE_SEGMENT_ELEMENT[], DWORD, LPDWORD, LPOVERLAPPED);
WINBASEAPI BOOL WINAPI WriteFileGather(HANDLE, FILE_SEGMENT_ELEMENT[], DWORD, LPDWORD, LPOVERLAPPED);

#define STARTF_USESHOWWINDOW  0x00000001
#define STARTF_USESIZE  0x00000002
#define STARTF_USEPOSITION  0x00000004
#define STARTF_USECOUNTCHARS  0x00000008
#define STARTF_USEFILLATTRIBUTE 0x00000010
#define STARTF_RUNFULLSCREEN  0x00000020
#define STARTF_FORCEONFEEDBACK  0x00000040
#define STARTF_FORCEOFFFEEDBACK 0x00000080
#define STARTF_USESTDHANDLES  0x00000100

#if (WINVER >= 0x0400)
#define STARTF_USEHOTKEY  0x00000200
#define STARTF_TITLEISLINKNAME  0x00000800
#define STARTF_TITLEISAPPID  0x00001000
#define STARTF_PREVENTPINNING  0x00002000
#endif /* WINVER >= 0x0400 */

typedef struct _STARTUPINFOA {
    DWORD cb;
    LPSTR lpReserved;
    LPSTR lpDesktop;
    LPSTR lpTitle;
    DWORD dwX;
    DWORD dwY;
    DWORD dwXSize;
    DWORD dwYSize;
    DWORD dwXCountChars;
    DWORD dwYCountChars;
    DWORD dwFillAttribute;
    DWORD dwFlags;
    WORD wShowWindow;
    WORD cbReserved2;
    LPBYTE lpReserved2;
    HANDLE hStdInput;
    HANDLE hStdOutput;
    HANDLE hStdError;
} STARTUPINFOA, *LPSTARTUPINFOA;

typedef struct _STARTUPINFOW {
    DWORD cb;
    LPWSTR lpReserved;
    LPWSTR lpDesktop;
    LPWSTR lpTitle;
    DWORD dwX;
    DWORD dwY;
    DWORD dwXSize;
    DWORD dwYSize;
    DWORD dwXCountChars;
    DWORD dwYCountChars;
    DWORD dwFillAttribute;
    DWORD dwFlags;
    WORD wShowWindow;
    WORD cbReserved2;
    LPBYTE lpReserved2;
    HANDLE hStdInput;
    HANDLE hStdOutput;
    HANDLE hStdError;
} STARTUPINFOW, *LPSTARTUPINFOW;

#ifdef UNICODE
typedef STARTUPINFOW STARTUPINFO;
typedef LPSTARTUPINFOW LPSTARTUPINFO;
#else /* !UNICODE */
typedef STARTUPINFOA STARTUPINFO;
typedef LPSTARTUPINFOA LPSTARTUPINFO;
#endif /* !UNICODE */

#if (_WIN32_WINNT >= 0x0600)
typedef struct _STARTUPINFOEXA {
    STARTUPINFOA StartupInfo;
    LPPROC_THREAD_ATTRIBUTE_LIST lpAttributeList;
} STARTUPINFOEXA, *LPSTARTUPINFOEXA;

typedef struct _STARTUPINFOEXW {
    STARTUPINFOW StartupInfo;
    LPPROC_THREAD_ATTRIBUTE_LIST lpAttributeList;
} STARTUPINFOEXW, *LPSTARTUPINFOEXW;

#ifdef UNICODE
typedef STARTUPINFOEXW STARTUPINFOEX;
typedef LPSTARTUPINFOEXW LPSTARTUPINFOEX;
#else /* !UNICODE */
typedef STARTUPINFOEXA STARTUPINFOEX;
typedef LPSTARTUPINFOEXA LPSTARTUPINFOEX;
#endif /* !UNICODE */
#endif /* _WIN32_WINNT >= 0x0600 */

#define SHUTDOWN_NORETRY  0x00000001

typedef struct _WIN32_FIND_DATAA {
    DWORD dwFileAttributes;
    FILETIME ftCreationTime;
    FILETIME ftLastAccessTime;
    FILETIME ftLastWriteTime;
    DWORD nFileSizeHigh;
    DWORD nFileSizeLow;
    DWORD dwReserved0;
    DWORD dwReserved1;
    CHAR cFileName[MAX_PATH];
    CHAR cAlternateFileName[14];
} WIN32_FIND_DATAA, *PWIN32_FIND_DATAA, *LPWIN32_FIND_DATAA;

typedef struct _WIN32_FIND_DATAW {
    DWORD dwFileAttributes;
    FILETIME ftCreationTime;
    FILETIME ftLastAccessTime;
    FILETIME ftLastWriteTime;
    DWORD nFileSizeHigh;
    DWORD nFileSizeLow;
    DWORD dwReserved0;
    DWORD dwReserved1;
    WCHAR cFileName[MAX_PATH];
    WCHAR cAlternateFileName[14];
} WIN32_FIND_DATAW, *PWIN32_FIND_DATAW, *LPWIN32_FIND_DATAW;

#ifdef UNICODE
typedef WIN32_FIND_DATAW WIN32_FIND_DATA;
typedef PWIN32_FIND_DATAW PWIN32_FIND_DATA;
typedef LPWIN32_FIND_DATAW LPWIN32_FIND_DATA;
#else /* !UNICODE */
typedef WIN32_FIND_DATAA WIN32_FIND_DATA;
typedef PWIN32_FIND_DATAA PWIN32_FIND_DATA;
typedef LPWIN32_FIND_DATAA LPWIN32_FIND_DATA;
#endif /* !UNICODE */

typedef struct _WIN32_FILE_ATTRIBUTE_DATA {
    DWORD dwFileAttributes;
    FILETIME ftCreationTime;
    FILETIME ftLastAccessTime;
    FILETIME ftLastWriteTime;
    DWORD nFileSizeHigh;
    DWORD nFileSizeLow;
} WIN32_FILE_ATTRIBUTE_DATA, *LPWIN32_FILE_ATTRIBUTE_DATA;

WINBASEAPI
 
HANDLE WINAPI CreateMutexA(LPSECURITY_ATTRIBUTES, BOOL, LPCSTR);
WINBASEAPI HANDLE WINAPI CreateMutexW(LPSECURITY_ATTRIBUTES, BOOL, LPCWSTR);
WINBASEAPI HANDLE WINAPI OpenMutexA(DWORD, BOOL, LPCSTR);
WINBASEAPI HANDLE WINAPI OpenMutexW(DWORD, BOOL, LPCWSTR);
WINBASEAPI HANDLE WINAPI CreateEventA(LPSECURITY_ATTRIBUTES, BOOL, BOOL, LPCSTR);
WINBASEAPI HANDLE WINAPI CreateEventW(LPSECURITY_ATTRIBUTES, BOOL, BOOL, LPCWSTR);
WINBASEAPI HANDLE WINAPI OpenEventA(DWORD, BOOL, LPCSTR);
WINBASEAPI HANDLE WINAPI OpenEventW(DWORD, BOOL, LPCWSTR);
WINBASEAPI HANDLE WINAPI CreateSemaphoreA(LPSECURITY_ATTRIBUTES, LONG, LONG, LPCSTR);
WINBASEAPI HANDLE WINAPI CreateSemaphoreW(LPSECURITY_ATTRIBUTES, LONG, LONG, LPCWSTR);
WINBASEAPI HANDLE WINAPI OpenSemaphoreA(DWORD, BOOL, LPCSTR);
WINBASEAPI HANDLE WINAPI OpenSemaphoreW(DWORD, BOOL, LPCWSTR);

#ifdef UNICODE
#define CreateMutex  CreateMutexW
#define OpenMutex  OpenMutexW
#define CreateEvent  CreateEventW
#define OpenEvent  OpenEventW
#define CreateSemaphore  CreateSemaphoreW
#define OpenSemaphore  OpenSemaphoreW
#else /* !UNICODE */
#define CreateMutex  CreateMutexA
#define OpenMutex  OpenMutexA
#define CreateEvent  CreateEventA
#define OpenEvent  OpenEventA
#define CreateSemaphore  CreateSemaphoreA
#define OpenSemaphore  OpenSemaphoreA
#endif /* !UNICODE */

#if (_WIN32_WINNT >= 0x0400) || (_WIN32_WINDOWS > 0x0400)
typedef VOID (APIENTRY *PTIMERAPCROUTINE)(LPVOID, DWORD, DWORD);

WINBASEAPI HANDLE WINAPI CreateWaitableTimerA(LPSECURITY_ATTRIBUTES, BOOL, LPCSTR);
WINBASEAPI HANDLE WINAPI CreateWaitableTimerW(LPSECURITY_ATTRIBUTES, BOOL, LPCWSTR);
WINBASEAPI HANDLE WINAPI OpenWaitableTimerA(DWORD, BOOL, LPCSTR);
WINBASEAPI HANDLE WINAPI OpenWaitableTimerW(DWORD, BOOL, LPCWSTR);

#ifdef UNICODE
#define CreateWaitableTimer  CreateWaitableTimerW
#define OpenWaitableTimer  OpenWaitableTimerW
#else /* !UNICODE */
#define CreateWaitableTimer  CreateWaitableTimerA
#define OpenWaitableTimer  OpenWaitableTimerA
#endif /* !UNICODE */

#if (_WIN32_WINNT >= _WIN32_WINNT_WIN7)
BOOL WINAPI SetWaitableTimerEx(HANDLE, const LARGE_INTEGER *, LONG, PTIMERAPCROUTINE, LPVOID, PREASON_CONTEXT, ULONG);
#endif /* _WIN32_WINNT >= _WIN32_WINNT_WIN7 */

WINBASEAPI BOOL WINAPI SetWaitableTimer(HANDLE, const LARGE_INTEGER *, LONG, PTIMERAPCROUTINE, LPVOID, BOOL);
WINBASEAPI BOOL WINAPI CancelWaitableTimer(HANDLE);

#if (_WIN32_WINNT >= 0x0600)

#define CREATE_MUTEX_INITIAL_OWNER  0x00000001

#define CREATE_EVENT_MANUAL_RESET  0x00000001
#define CREATE_EVENT_INITIAL_SET  0x00000002

#define CREATE_WAITABLE_TIMER_MANUAL_RESET  0x00000001

WINBASEAPI HANDLE WINAPI CreateMutexExA(LPSECURITY_ATTRIBUTES, LPCSTR, DWORD, DWORD);
WINBASEAPI HANDLE WINAPI CreateMutexExW(LPSECURITY_ATTRIBUTES, LPCWSTR, DWORD, DWORD);
WINBASEAPI HANDLE WINAPI CreateEventExA(LPSECURITY_ATTRIBUTES, LPCSTR, DWORD, DWORD);
WINBASEAPI HANDLE WINAPI CreateEventExW(LPSECURITY_ATTRIBUTES, LPCWSTR, DWORD, DWORD);
WINBASEAPI HANDLE WINAPI CreateSemaphoreExA(LPSECURITY_ATTRIBUTES, LONG, LONG, LPCSTR, DWORD, DWORD);
WINBASEAPI HANDLE WINAPI CreateSemaphoreExW(LPSECURITY_ATTRIBUTES, LONG, LONG, LPCWSTR, DWORD, DWORD);
WINBASEAPI HANDLE WINAPI CreateWaitableTimerExA(LPSECURITY_ATTRIBUTES, LPCSTR, DWORD, DWORD);
WINBASEAPI HANDLE WINAPI CreateWaitableTimerExW(LPSECURITY_ATTRIBUTES, LPCWSTR, DWORD, DWORD);

#ifdef UNICODE
#define CreateMutexEx  CreateMutexExW
#define CreateEventEx  CreateEventExW
#define CreateSemaphoreEx  CreateSemaphoreExW
#define CreateWaitableTimerEx  CreateWaitableTimerExW
#else /* !UNICODE */
#define CreateMutexEx  CreateMutexExA
#define CreateEventEx  CreateEventExA
#define CreateSemaphoreEx  CreateSemaphoreExA
#define CreateWaitableTimerEx  CreateWaitableTimerExA
#endif /* !UNICODE */

#endif /* _WIN32_WINNT >= 0x0600 */
#endif /* (_WIN32_WINNT >= 0x0400) || (_WIN32_WINDOWS > 0x0400) */

WINBASEAPI HANDLE WINAPI CreateFileMappingA(HANDLE, LPSECURITY_ATTRIBUTES, DWORD, DWORD, DWORD, LPCSTR);
WINBASEAPI HANDLE WINAPI CreateFileMappingW(HANDLE, LPSECURITY_ATTRIBUTES, DWORD, DWORD, DWORD, LPCWSTR);

#ifdef UNICODE
#define CreateFileMapping  CreateFileMappingW
#else /* !UNICODE */
#define CreateFileMapping  CreateFileMappingA
#endif /* !UNICODE */

#if _WIN32_WINNT >= 0x0600
WINBASEAPI HANDLE WINAPI CreateFileMappingNumaA(HANDLE, LPSECURITY_ATTRIBUTES, DWORD, DWORD, DWORD, LPCSTR, DWORD);
WINBASEAPI HANDLE WINAPI CreateFileMappingNumaW(HANDLE, LPSECURITY_ATTRIBUTES, DWORD, DWORD, DWORD, LPCWSTR, DWORD);
#ifdef UNICODE
#define CreateFileMappingNuma  CreateFileMappingNumaW
#else /* !UNICODE */
#define CreateFileMappingNuma  CreateFileMappingNumaA
#endif /* !UNICODE */
#endif /* _WIN32_WINNT >= 0x0600 */

WINBASEAPI HANDLE WINAPI OpenFileMappingA(DWORD, BOOL, LPCSTR);
WINBASEAPI HANDLE WINAPI OpenFileMappingW(DWORD, BOOL, LPCWSTR);
#ifdef UNICODE
#define OpenFileMapping  OpenFileMappingW
#else /* !UNICODE */
#define OpenFileMapping  OpenFileMappingA
#endif /* !UNICODE */

WINBASEAPI DWORD WINAPI GetLogicalDriveStringsA(DWORD, LPSTR);
WINBASEAPI DWORD WINAPI GetLogicalDriveStringsW(DWORD, LPWSTR);
#ifdef UNICODE
#define GetLogicalDriveStrings  GetLogicalDriveStringsW
#else /* !UNICODE */
#define GetLogicalDriveStrings  GetLogicalDriveStringsA
#endif /* !UNICODE */

#if _WIN32_WINNT >= 0x0501
typedef enum _MEMORY_RESOURCE_NOTIFICATION_TYPE {
    LowMemoryResourceNotification,
    HighMemoryResourceNotification
} MEMORY_RESOURCE_NOTIFICATION_TYPE;

WINBASEAPI HANDLE WINAPI CreateMemoryResourceNotification(MEMORY_RESOURCE_NOTIFICATION_TYPE);
WINBASEAPI BOOL WINAPI QueryMemoryResourceNotification(HANDLE, PBOOL);
#endif /* _WIN32_WINNT >= 0x0501 */

#define DONT_RESOLVE_DLL_REFERENCES  0x00000001
#define LOAD_LIBRARY_AS_DATAFILE  0x00000002
#define LOAD_WITH_ALTERED_SEARCH_PATH  0x00000008
#define LOAD_IGNORE_CODE_AUTHZ_LEVEL  0x00000010
#define LOAD_LIBRARY_AS_IMAGE_RESOURCE  0x00000020
#define LOAD_LIBRARY_AS_DATAFILE_EXCLUSIVE  0x00000040
#define LOAD_LIBRARY_REQUIRE_SIGNED_TARGET  0x00000080

WINBASEAPI HMODULE WINAPI LoadLibraryA(LPCSTR);
WINBASEAPI HMODULE WINAPI LoadLibraryW(LPCWSTR);
WINBASEAPI HMODULE WINAPI LoadLibraryExA(LPCSTR, HANDLE, DWORD);
WINBASEAPI HMODULE WINAPI LoadLibraryExW(LPCWSTR, HANDLE, DWORD);
WINBASEAPI DWORD WINAPI GetModuleFileNameA(HMODULE, LPSTR, DWORD);
WINBASEAPI DWORD WINAPI GetModuleFileNameW(HMODULE, LPWSTR, DWORD);
WINBASEAPI HMODULE WINAPI GetModuleHandleA(LPCSTR);
WINBASEAPI HMODULE WINAPI GetModuleHandleW(LPCWSTR);

#ifdef UNICODE
#define LoadLibrary  LoadLibraryW
#define LoadLibraryEx  LoadLibraryExW
#define GetModuleFileName  GetModuleFileNameW
#define GetModuleHandle  GetModuleHandleW
#else /* !UNICODE */
#define LoadLibrary  LoadLibraryA
#define LoadLibraryEx  LoadLibraryExA
#define GetModuleFileName  GetModuleFileNameA
#define GetModuleHandle  GetModuleHandleA
#endif /* !UNICODE */

#if _WIN32_WINNT > 0x0500 || defined(WINBASE_DECLARE_GET_MODULE_HANDLE_EX) || ISOLATION_AWARE_ENABLED

#define GET_MODULE_HANDLE_EX_FLAG_PIN  (0x00000001)
#define GET_MODULE_HANDLE_EX_FLAG_UNCHANGED_REFCOUNT  (0x00000002)
#define GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS  (0x00000004)

typedef BOOL (WINAPI *PGET_MODULE_HANDLE_EXA)(DWORD, LPCSTR, HMODULE *);
typedef BOOL (WINAPI *PGET_MODULE_HANDLE_EXW)(DWORD, LPCWSTR, HMODULE *);

WINBASEAPI BOOL WINAPI GetModuleHandleExA(DWORD, LPCSTR, HMODULE *);
WINBASEAPI BOOL WINAPI GetModuleHandleExW(DWORD, LPCWSTR, HMODULE *);

#ifdef UNICODE
#define PGET_MODULE_HANDLE_EX  PGET_MODULE_HANDLE_EXW
#define GetModuleHandleEx  GetModuleHandleExW
#else /* !UNICODE */
#define PGET_MODULE_HANDLE_EX  PGET_MODULE_HANDLE_EXA
#define GetModuleHandleEx  GetModuleHandleExA
#endif /* !UNICODE */

#endif /* _WIN32_WINNT > 0x0500 || defined(WINBASE_DECLARE_GET_MODULE_HANDLE_EX) || ISOLATION_AWARE_ENABLED */

#if _WIN32_WINNT >= 0x0502
WINBASEAPI BOOL WINAPI NeedCurrentDirectoryForExePathA(LPCSTR);
WINBASEAPI BOOL WINAPI NeedCurrentDirectoryForExePathW(LPCWSTR);
#ifdef UNICODE
#define NeedCurrentDirectoryForExePath  NeedCurrentDirectoryForExePathW
#else /* !UNICODE */
#define NeedCurrentDirectoryForExePath  NeedCurrentDirectoryForExePathA
#endif /* !UNICODE */
#endif /* _WIN32_WINNT >= 0x0502 */

#if _WIN32_WINNT >= 0x0600
#define PROCESS_NAME_NATIVE  0x00000001
WINBASEAPI BOOL WINAPI QueryFullProcessImageNameA(HANDLE, DWORD, LPSTR, PDWORD);
WINBASEAPI BOOL WINAPI QueryFullProcessImageNameW(HANDLE, DWORD, LPWSTR, PDWORD);
#ifdef UNICODE
#define QueryFullProcessImageName  QueryFullProcessImageNameW
#else /* !UNICODE */
#define QueryFullProcessImageName  QueryFullProcessImageNameA
#endif /* !UNICODE */
#endif /* _WIN32_WINNT >= 0x0600 */

#if (_WIN32_WINNT >= 0x0600)

#define PROC_THREAD_ATTRIBUTE_NUMBER  0x0000FFFF
#define PROC_THREAD_ATTRIBUTE_THREAD  0x00010000
#define PROC_THREAD_ATTRIBUTE_INPUT  0x00020000
#define PROC_THREAD_ATTRIBUTE_ADDITIVE  0x00040000

typedef enum _PROC_THREAD_ATTRIBUTE_NUM {
    ProcThreadAttributeParentProcess = 0,
    ProcThreadAttributeExtendedFlags = 1,
    ProcThreadAttributeHandleList = 2,
#if (_WIN32_WINNT >= _WIN32_WINNT_WIN7)
    ProcThreadAttributeGroupAffinity = 3,
    ProcThreadAttributePreferredNode = 4,
    ProcThreadAttributeIdealProcessor = 5,
    ProcThreadAttributeUmsThread = 6,
    ProcThreadAttributeMitigationPolicy = 7,
#endif /* _WIN32_WINNT >= _WIN32_WINNT_WIN7 */
#if (_WIN32_WINNT >= _WIN32_WINNT_WIN8)
    ProcThreadAttributeSecurityCapabilities = 9,
#endif
    ProcThreadAttributeProtectionLevel = 11,
    ProcThreadAttributeMax
} PROC_THREAD_ATTRIBUTE_NUM;

#define ProcThreadAttributeValue(Number,Thread,Input,Additive) \
  (((Number) & PROC_THREAD_ATTRIBUTE_NUMBER) | \
  ((Thread != FALSE) ? PROC_THREAD_ATTRIBUTE_THREAD : 0) | \
  ((Input != FALSE) ? PROC_THREAD_ATTRIBUTE_INPUT : 0) | \
  ((Additive != FALSE) ? PROC_THREAD_ATTRIBUTE_ADDITIVE : 0))

#define PROC_THREAD_ATTRIBUTE_PARENT_PROCESS \
  ProcThreadAttributeValue (ProcThreadAttributeParentProcess, FALSE, TRUE, FALSE)
#define PROC_THREAD_ATTRIBUTE_EXTENDED_FLAGS \
  ProcThreadAttributeValue (ProcThreadAttributeExtendedFlags, FALSE, TRUE, TRUE)
#define PROC_THREAD_ATTRIBUTE_HANDLE_LIST \
  ProcThreadAttributeValue (ProcThreadAttributeHandleList, FALSE, TRUE, FALSE)

#if (_WIN32_WINNT >= _WIN32_WINNT_WIN7)
#define PROC_THREAD_ATTRIBUTE_GROUP_AFFINITY \
  ProcThreadAttributeValue (ProcThreadAttributeGroupAffinity, TRUE, TRUE, FALSE)
#define PROC_THREAD_ATTRIBUTE_PREFERRED_NODE \
  ProcThreadAttributeValue (ProcThreadAttributePreferredNode, FALSE, TRUE, FALSE)
#define PROC_THREAD_ATTRIBUTE_IDEAL_PROCESSOR \
  ProcThreadAttributeValue (ProcThreadAttributeIdealProcessor, TRUE, TRUE, FALSE)
#define PROC_THREAD_ATTRIBUTE_UMS_THREAD \
  ProcThreadAttributeValue (ProcThreadAttributeUmsThread, TRUE, TRUE, FALSE)
#define PROC_THREAD_ATTRIBUTE_MITIGATION_POLICY \
  ProcThreadAttributeValue (ProcThreadAttributeMitigationPolicy, FALSE, TRUE, FALSE)
#endif /* _WIN32_WINNT >= _WIN32_WINNT_WIN7 */

#if (_WIN32_WINNT >= _WIN32_WINNT_WIN8)
#define PROC_THREAD_ATTRIBUTE_SECURITY_CAPABILITIES \
    ProcThreadAttributeValue (ProcThreadAttributeSecurityCapabilities, FALSE, TRUE, FALSE)
#endif /* _WIN32_WINNT >= _WIN32_WINNT_WIN8 */

#if (_WIN32_WINNT >= _WIN32_WINNT_WIN7)
#define PROCESS_CREATION_MITIGATION_POLICY_DEP_ENABLE  0x01
#define PROCESS_CREATION_MITIGATION_POLICY_DEP_ATL_THUNK_ENABLE  0x02
#define PROCESS_CREATION_MITIGATION_POLICY_SEHOP_ENABLE  0x04
#endif /* _WIN32_WINNT >= _WIN32_WINNT_WIN7 */

#if (_WIN32_WINNT >= _WIN32_WINNT_WIN8)

#define PROCESS_CREATION_MITIGATION_POLICY_FORCE_RELOCATE_IMAGES_MASK  (0x00000003 <<  8)
#define PROCESS_CREATION_MITIGATION_POLICY_FORCE_RELOCATE_IMAGES_DEFER  (0x00000000 <<  8)
#define PROCESS_CREATION_MITIGATION_POLICY_FORCE_RELOCATE_IMAGES_ALWAYS_ON  (0x00000001 <<  8)
#define PROCESS_CREATION_MITIGATION_POLICY_FORCE_RELOCATE_IMAGES_ALWAYS_OFF  (0x00000002 <<  8)
#define PROCESS_CREATION_MITIGATION_POLICY_FORCE_RELOCATE_IMAGES_ALWAYS_ON_REQ_RELOCS  (0x00000003 <<  8)

#define PROCESS_CREATION_MITIGATION_POLICY_HEAP_TERMINATE_MASK  (0x00000003 << 12)
#define PROCESS_CREATION_MITIGATION_POLICY_HEAP_TERMINATE_DEFER  (0x00000000 << 12)
#define PROCESS_CREATION_MITIGATION_POLICY_HEAP_TERMINATE_ALWAYS_ON  (0x00000001 << 12)
#define PROCESS_CREATION_MITIGATION_POLICY_HEAP_TERMINATE_ALWAYS_OFF  (0x00000002 << 12)
#define PROCESS_CREATION_MITIGATION_POLICY_HEAP_TERMINATE_RESERVED  (0x00000003 << 12)

#define PROCESS_CREATION_MITIGATION_POLICY_BOTTOM_UP_ASLR_MASK  (0x00000003 << 16)
#define PROCESS_CREATION_MITIGATION_POLICY_BOTTOM_UP_ASLR_DEFER  (0x00000000 << 16)
#define PROCESS_CREATION_MITIGATION_POLICY_BOTTOM_UP_ASLR_ALWAYS_ON  (0x00000001 << 16)
#define PROCESS_CREATION_MITIGATION_POLICY_BOTTOM_UP_ASLR_ALWAYS_OFF  (0x00000002 << 16)
#define PROCESS_CREATION_MITIGATION_POLICY_BOTTOM_UP_ASLR_RESERVED  (0x00000003 << 16)

#define PROCESS_CREATION_MITIGATION_POLICY_HIGH_ENTROPY_ASLR_MASK  (0x00000003 << 20)
#define PROCESS_CREATION_MITIGATION_POLICY_HIGH_ENTROPY_ASLR_DEFER  (0x00000000 << 20)
#define PROCESS_CREATION_MITIGATION_POLICY_HIGH_ENTROPY_ASLR_ALWAYS_ON  (0x00000001 << 20)
#define PROCESS_CREATION_MITIGATION_POLICY_HIGH_ENTROPY_ASLR_ALWAYS_OFF  (0x00000002 << 20)
#define PROCESS_CREATION_MITIGATION_POLICY_HIGH_ENTROPY_ASLR_RESERVED  (0x00000003 << 20)

#define PROCESS_CREATION_MITIGATION_POLICY_STRICT_HANDLE_CHECKS_MASK  (0x00000003 << 24)
#define PROCESS_CREATION_MITIGATION_POLICY_STRICT_HANDLE_CHECKS_DEFER  (0x00000000 << 24)
#define PROCESS_CREATION_MITIGATION_POLICY_STRICT_HANDLE_CHECKS_ALWAYS_ON  (0x00000001 << 24)
#define PROCESS_CREATION_MITIGATION_POLICY_STRICT_HANDLE_CHECKS_ALWAYS_OFF  (0x00000002 << 24)
#define PROCESS_CREATION_MITIGATION_POLICY_STRICT_HANDLE_CHECKS_RESERVED  (0x00000003 << 24)

#define PROCESS_CREATION_MITIGATION_POLICY_WIN32K_SYSTEM_CALL_DISABLE_MASK  (0x00000003 << 28)
#define PROCESS_CREATION_MITIGATION_POLICY_WIN32K_SYSTEM_CALL_DISABLE_DEFER  (0x00000000 << 28)
#define PROCESS_CREATION_MITIGATION_POLICY_WIN32K_SYSTEM_CALL_DISABLE_ALWAYS_ON  (0x00000001 << 28)
#define PROCESS_CREATION_MITIGATION_POLICY_WIN32K_SYSTEM_CALL_DISABLE_ALWAYS_OFF  (0x00000002 << 28)
#define PROCESS_CREATION_MITIGATION_POLICY_WIN32K_SYSTEM_CALL_DISABLE_RESERVED  (0x00000003 << 28)

#define PROCESS_CREATION_MITIGATION_POLICY_EXTENSION_POINT_DISABLE_MASK  (0x00000003ui64 << 32)
#define PROCESS_CREATION_MITIGATION_POLICY_EXTENSION_POINT_DISABLE_DEFER  (0x00000000ui64 << 32)
#define PROCESS_CREATION_MITIGATION_POLICY_EXTENSION_POINT_DISABLE_ALWAYS_ON  (0x00000001ui64 << 32)
#define PROCESS_CREATION_MITIGATION_POLICY_EXTENSION_POINT_DISABLE_ALWAYS_OFF  (0x00000002ui64 << 32)
#define PROCESS_CREATION_MITIGATION_POLICY_EXTENSION_POINT_DISABLE_RESERVED  (0x00000003ui64 << 32)

#if (_WIN32_WINNT >= _WIN32_WINNT_WINBLUE)
#define PROCESS_CREATION_MITIGATION_POLICY_PROHIBIT_DYNAMIC_CODE_MASK  (0x00000003ui64 << 36)
#define PROCESS_CREATION_MITIGATION_POLICY_PROHIBIT_DYNAMIC_CODE_DEFER  (0x00000000ui64 << 36)
#define PROCESS_CREATION_MITIGATION_POLICY_PROHIBIT_DYNAMIC_CODE_ALWAYS_ON  (0x00000001ui64 << 36)
#define PROCESS_CREATION_MITIGATION_POLICY_PROHIBIT_DYNAMIC_CODE_ALWAYS_OFF  (0x00000002ui64 << 36)
#define PROCESS_CREATION_MITIGATION_POLICY_PROHIBIT_DYNAMIC_CODE_RESERVED  (0x00000003ui64 << 36)

#define PROCESS_CREATION_MITIGATION_POLICY_BLOCK_NON_MICROSOFT_BINARIES_MASK  (0x00000003ui64 << 44)
#define PROCESS_CREATION_MITIGATION_POLICY_BLOCK_NON_MICROSOFT_BINARIES_DEFER  (0x00000000ui64 << 44)
#define PROCESS_CREATION_MITIGATION_POLICY_BLOCK_NON_MICROSOFT_BINARIES_ALWAYS_ON  (0x00000001ui64 << 44)
#define PROCESS_CREATION_MITIGATION_POLICY_BLOCK_NON_MICROSOFT_BINARIES_ALWAYS_OFF  (0x00000002ui64 << 44)
#define PROCESS_CREATION_MITIGATION_POLICY_BLOCK_NON_MICROSOFT_BINARIES_RESERVED  (0x00000003ui64 << 44)
#endif /* _WIN32_WINNT_WINBLUE */

#endif /* _WIN32_WINNT_WIN8 */

#define PROC_THREAD_ATTRIBUTE_REPLACE_VALUE  0x00000001

WINBASEAPI BOOL WINAPI InitializeProcThreadAttributeList(LPPROC_THREAD_ATTRIBUTE_LIST, DWORD, DWORD, PSIZE_T);
WINBASEAPI VOID WINAPI DeleteProcThreadAttributeList(LPPROC_THREAD_ATTRIBUTE_LIST);
WINBASEAPI BOOL WINAPI UpdateProcThreadAttribute(LPPROC_THREAD_ATTRIBUTE_LIST, DWORD, DWORD_PTR, PVOID, SIZE_T, PVOID, PSIZE_T);

#endif /* _WIN32_WINNT >= 0x0600 */

WINBASEAPI BOOL WINAPI CreateProcessA(LPCSTR, LPSTR, LPSECURITY_ATTRIBUTES, LPSECURITY_ATTRIBUTES, BOOL, DWORD, LPVOID, LPCSTR, LPSTARTUPINFOA, LPPROCESS_INFORMATION);
WINBASEAPI BOOL WINAPI CreateProcessW(LPCWSTR, LPWSTR, LPSECURITY_ATTRIBUTES, LPSECURITY_ATTRIBUTES, BOOL, DWORD, LPVOID, LPCWSTR, LPSTARTUPINFOW, LPPROCESS_INFORMATION);
WINBASEAPI BOOL WINAPI SetProcessShutdownParameters(DWORD, DWORD);
WINBASEAPI BOOL WINAPI GetProcessShutdownParameters(LPDWORD, LPDWORD);
WINBASEAPI DWORD WINAPI GetProcessVersion(DWORD);
WINBASEAPI VOID WINAPI FatalAppExitA(UINT, LPCSTR);
WINBASEAPI VOID WINAPI FatalAppExitW(UINT, LPCWSTR);
WINBASEAPI VOID WINAPI GetStartupInfoA(LPSTARTUPINFOA);
WINBASEAPI VOID WINAPI GetStartupInfoW(LPSTARTUPINFOW);
WINBASEAPI LPSTR WINAPI GetCommandLineA(VOID);
WINBASEAPI LPWSTR WINAPI GetCommandLineW(VOID);
WINBASEAPI DWORD WINAPI GetEnvironmentVariableA(LPCSTR, LPSTR, DWORD);
WINBASEAPI DWORD WINAPI GetEnvironmentVariableW(LPCWSTR, LPWSTR, DWORD);
WINBASEAPI BOOL WINAPI SetEnvironmentVariableA(LPCSTR, LPCSTR);
WINBASEAPI BOOL WINAPI SetEnvironmentVariableW(LPCWSTR, LPCWSTR);
WINBASEAPI DWORD WINAPI ExpandEnvironmentStringsA(LPCSTR, LPSTR, DWORD);
WINBASEAPI DWORD WINAPI ExpandEnvironmentStringsW(LPCWSTR, LPWSTR, DWORD);
WINBASEAPI DWORD WINAPI GetFirmwareEnvironmentVariableA(LPCSTR, LPCSTR, PVOID, DWORD);
WINBASEAPI DWORD WINAPI GetFirmwareEnvironmentVariableW(LPCWSTR, LPCWSTR, PVOID, DWORD);
#if (_WIN32_WINNT >= _WIN32_WINNT_WIN8)
WINBASEAPI DWORD WINAPI GetFirmwareEnvironmentVariableExA(LPCSTR, LPCSTR, PVOID, DWORD, PDWORD);
WINBASEAPI DWORD WINAPI GetFirmwareEnvironmentVariableExW(LPCWSTR, LPCWSTR, PVOID, DWORD, PDWORD);
#endif /* _WIN32_WINNT >= _WIN32_WINNT_WIN8 */
WINBASEAPI BOOL WINAPI SetFirmwareEnvironmentVariableA(LPCSTR, LPCSTR, PVOID, DWORD);
WINBASEAPI BOOL WINAPI SetFirmwareEnvironmentVariableW(LPCWSTR, LPCWSTR, PVOID, DWORD);
#if (_WIN32_WINNT >= _WIN32_WINNT_WIN8)
WINBASEAPI BOOL WINAPI SetFirmwareEnvironmentVariableExA(LPCSTR, LPCSTR, PVOID, DWORD, DWORD);
WINBASEAPI BOOL WINAPI SetFirmwareEnvironmentVariableExW(LPCWSTR, LPCWSTR, PVOID, DWORD, DWORD);
WINBASEAPI BOOL WINAPI GetFirmwareType(PFIRMWARE_TYPE);
WINBASEAPI BOOL WINAPI IsNativeVhdBoot(PBOOL);
#endif /* _WIN32_WINNT >= _WIN32_WINNT_WIN8 */

#ifdef UNICODE
#define CreateProcess  CreateProcessW
#define FatalAppExit  FatalAppExitW
#define GetStartupInfo  GetStartupInfoW
#define GetCommandLine  GetCommandLineW
#define GetEnvironmentVariable  GetEnvironmentVariableW
#define SetEnvironmentVariable  SetEnvironmentVariableW
#define ExpandEnvironmentStrings  ExpandEnvironmentStringsW
#define GetFirmwareEnvironmentVariable  GetFirmwareEnvironmentVariableW
#define GetFirmwareEnvironmentVariableEx  GetFirmwareEnvironmentVariableExW
#define SetFirmwareEnvironmentVariable  SetFirmwareEnvironmentVariableW
#define SetFirmwareEnvironmentVariableEx  SetFirmwareEnvironmentVariableExW
#else /* !UNICODE */
#define CreateProcess  CreateProcessA
#define FatalAppExit  FatalAppExitA
#define GetStartupInfo  GetStartupInfoA
#define GetCommandLine  GetCommandLineA
#define GetEnvironmentVariable  GetEnvironmentVariableA
#define SetEnvironmentVariable  SetEnvironmentVariableA
#define ExpandEnvironmentStrings  ExpandEnvironmentStringsA
#define GetFirmwareEnvironmentVariable  GetFirmwareEnvironmentVariableA
#define GetFirmwareEnvironmentVariableEx  GetFirmwareEnvironmentVariableExA
#define SetFirmwareEnvironmentVariable  SetFirmwareEnvironmentVariableA
#define SetFirmwareEnvironmentVariableEx  SetFirmwareEnvironmentVariableExA
#endif /* !UNICODE */

WINBASEAPI VOID WINAPI OutputDebugStringA(LPCSTR);
WINBASEAPI VOID WINAPI OutputDebugStringW(LPCWSTR);
#ifdef UNICODE
#define OutputDebugString  OutputDebugStringW
#else
#define OutputDebugString  OutputDebugStringA
#endif // !UNICODE

WINBASEAPI HRSRC WINAPI FindResourceA(HMODULE, LPCSTR, LPCSTR);
WINBASEAPI HRSRC WINAPI FindResourceW(HMODULE, LPCWSTR, LPCWSTR);
WINBASEAPI HRSRC WINAPI FindResourceExA(HMODULE, LPCSTR, LPCSTR, WORD);
WINBASEAPI HRSRC WINAPI FindResourceExW(HMODULE, LPCWSTR, LPCWSTR, WORD);

#ifdef UNICODE
#define FindResource  FindResourceW
#define FindResourceEx  FindResourceExW
#else /* !UNICODE */
#define FindResource  FindResourceA
#define FindResourceEx  FindResourceExA
#endif /* !UNICODE */

#ifdef STRICT
typedef BOOL(CALLBACK *ENUMRESTYPEPROCA)(HMODULE, LPSTR, LONG_PTR);
typedef BOOL(CALLBACK *ENUMRESTYPEPROCW)(HMODULE, LPWSTR, LONG_PTR);
typedef BOOL(CALLBACK *ENUMRESNAMEPROCA)(HMODULE, LPCSTR, LPSTR, LONG_PTR);
typedef BOOL(CALLBACK *ENUMRESNAMEPROCW)(HMODULE, LPCWSTR, LPWSTR, LONG_PTR);
typedef BOOL(CALLBACK *ENUMRESLANGPROCA)(HMODULE, LPCSTR, LPCSTR, WORD, LONG_PTR);
typedef BOOL(CALLBACK *ENUMRESLANGPROCW)(HMODULE, LPCWSTR, LPCWSTR, WORD, LONG_PTR);
#ifdef UNICODE
#define ENUMRESTYPEPROC  ENUMRESTYPEPROCW
#define ENUMRESNAMEPROC  ENUMRESNAMEPROCW
#define ENUMRESLANGPROC  ENUMRESLANGPROCW
#else /* !UNICODE */
#define ENUMRESTYPEPROC  ENUMRESTYPEPROCA
#define ENUMRESNAMEPROC  ENUMRESNAMEPROCA
#define ENUMRESLANGPROC  ENUMRESLANGPROCA
#endif /* !UNICODE */
#else /* !STRICT */
typedef FARPROC ENUMRESTYPEPROCA;
typedef FARPROC ENUMRESTYPEPROCW;
typedef FARPROC ENUMRESNAMEPROCA;
typedef FARPROC ENUMRESNAMEPROCW;
typedef FARPROC ENUMRESLANGPROCA;
typedef FARPROC ENUMRESLANGPROCW;
#ifdef UNICODE
typedef ENUMRESTYPEPROCW ENUMRESTYPEPROC;
typedef ENUMRESNAMEPROCW ENUMRESNAMEPROC;
typedef ENUMRESLANGPROCW ENUMRESLANGPROC;
#else /* !UNICODE */
typedef ENUMRESTYPEPROCA ENUMRESTYPEPROC;
typedef ENUMRESNAMEPROCA ENUMRESNAMEPROC;
typedef ENUMRESLANGPROCA ENUMRESLANGPROC;
#endif /* !UNICODE */
#endif /* !STRICT */

#define  RESOURCE_ENUM_LN  (0x0001)
#define  RESOURCE_ENUM_MUI  (0x0002)
#define  RESOURCE_ENUM_MUI_SYSTEM  (0x0004)
#define  RESOURCE_ENUM_VALIDATE  (0x0008)
#define  RESOURCE_ENUM_MODULE_EXACT  (0x0010)

WINBASEAPI BOOL WINAPI EnumResourceTypesA(HMODULE, ENUMRESTYPEPROCA, LONG_PTR);
WINBASEAPI BOOL WINAPI EnumResourceTypesW(HMODULE, ENUMRESTYPEPROCW, LONG_PTR);
WINBASEAPI BOOL WINAPI EnumResourceNamesA(HMODULE, LPCSTR, ENUMRESNAMEPROCA, LONG_PTR);
WINBASEAPI BOOL WINAPI EnumResourceNamesW(HMODULE, LPCWSTR, ENUMRESNAMEPROCW, LONG_PTR);
WINBASEAPI BOOL WINAPI EnumResourceLanguagesA(HMODULE, LPCSTR, LPCSTR, ENUMRESLANGPROCA, LONG_PTR);
WINBASEAPI BOOL WINAPI EnumResourceLanguagesW(HMODULE, LPCWSTR, LPCWSTR, ENUMRESLANGPROCW, LONG_PTR);
WINBASEAPI BOOL WINAPI EnumResourceTypesExA(HMODULE, ENUMRESTYPEPROCA, LONG_PTR, DWORD, LANGID);
WINBASEAPI BOOL WINAPI EnumResourceTypesExW(HMODULE, ENUMRESTYPEPROCW, LONG_PTR, DWORD, LANGID);
WINBASEAPI BOOL WINAPI EnumResourceNamesExA(HMODULE, LPCSTR, ENUMRESNAMEPROCA, LONG_PTR, DWORD, LANGID);
WINBASEAPI BOOL WINAPI EnumResourceNamesExW(HMODULE, LPCWSTR, ENUMRESNAMEPROCW, LONG_PTR, DWORD, LANGID);
WINBASEAPI BOOL WINAPI EnumResourceLanguagesExA(HMODULE, LPCSTR, LPCSTR, ENUMRESLANGPROCA, LONG_PTR, DWORD, LANGID);
WINBASEAPI BOOL WINAPI EnumResourceLanguagesExW(HMODULE, LPCWSTR, LPCWSTR, ENUMRESLANGPROCW, LONG_PTR, DWORD, LANGID);
WINBASEAPI HANDLE WINAPI BeginUpdateResourceA(LPCSTR, BOOL);
WINBASEAPI HANDLE WINAPI BeginUpdateResourceW(LPCWSTR, BOOL);
WINBASEAPI BOOL WINAPI UpdateResourceA(HANDLE, LPCSTR, LPCSTR, WORD, LPVOID, DWORD);
WINBASEAPI BOOL WINAPI UpdateResourceW(HANDLE, LPCWSTR, LPCWSTR, WORD, LPVOID, DWORD);
WINBASEAPI BOOL WINAPI EndUpdateResourceA(HANDLE, BOOL);
WINBASEAPI BOOL WINAPI EndUpdateResourceW(HANDLE, BOOL);

#ifdef UNICODE
#define EnumResourceTypes  EnumResourceTypesW
#define EnumResourceNames  EnumResourceNamesW
#define EnumResourceLanguages  EnumResourceLanguagesW
#define EnumResourceTypesEx  EnumResourceTypesExW
#define EnumResourceNamesEx  EnumResourceNamesExW
#define EnumResourceLanguagesEx  EnumResourceLanguagesExW
#define BeginUpdateResource  BeginUpdateResourceW
#define UpdateResource  UpdateResourceW
#define EndUpdateResource  EndUpdateResourceW
#else /* !UNICODE */
#define EnumResourceTypes  EnumResourceTypesA
#define EnumResourceNames  EnumResourceNamesA
#define EnumResourceLanguages  EnumResourceLanguagesA
#define EnumResourceTypesEx  EnumResourceTypesExA
#define EnumResourceNamesEx  EnumResourceNamesExA
#define EnumResourceLanguagesEx  EnumResourceLanguagesExA
#define BeginUpdateResource  BeginUpdateResourceA
#define UpdateResource  UpdateResourceA
#define EndUpdateResource  EndUpdateResourceA
#endif /* !UNICODE */

WINBASEAPI ATOM WINAPI GlobalAddAtomA(LPCSTR);
WINBASEAPI ATOM WINAPI GlobalAddAtomW(LPCWSTR);
WINBASEAPI ATOM WINAPI GlobalFindAtomA(LPCSTR);
WINBASEAPI ATOM WINAPI GlobalFindAtomW(LPCWSTR);
WINBASEAPI UINT WINAPI GlobalGetAtomNameA(ATOM, LPSTR, int);
WINBASEAPI UINT WINAPI GlobalGetAtomNameW(ATOM, LPWSTR, int);
WINBASEAPI ATOM WINAPI AddAtomA(LPCSTR);
WINBASEAPI ATOM WINAPI AddAtomW(LPCWSTR);
WINBASEAPI ATOM WINAPI FindAtomA(LPCSTR);
WINBASEAPI ATOM WINAPI FindAtomW(LPCWSTR);
WINBASEAPI UINT WINAPI GetAtomNameA(ATOM, LPSTR, int);
WINBASEAPI UINT WINAPI GetAtomNameW(ATOM, LPWSTR, int);

#ifdef UNICODE
#define GlobalAddAtom  GlobalAddAtomW
#define GlobalFindAtom  GlobalFindAtomW
#define GlobalGetAtomName  GlobalGetAtomNameW
#define AddAtom  AddAtomW
#define FindAtom  FindAtomW
#define GetAtomName  GetAtomNameW
#else /* !UNICODE */
#define GlobalAddAtom  GlobalAddAtomA
#define GlobalFindAtom  GlobalFindAtomA
#define GlobalGetAtomName  GlobalGetAtomNameA
#define AddAtom  AddAtomA
#define FindAtom  FindAtomA
#define GetAtomName  GetAtomNameA
#endif /* !UNICODE */

WINBASEAPI UINT WINAPI GetProfileIntA(LPCSTR, LPCSTR, INT);
WINBASEAPI UINT WINAPI GetProfileIntW(LPCWSTR, LPCWSTR, INT);
WINBASEAPI DWORD WINAPI GetProfileStringA(LPCSTR, LPCSTR, LPCSTR, LPSTR, DWORD);
WINBASEAPI DWORD WINAPI GetProfileStringW(LPCWSTR, LPCWSTR, LPCWSTR, LPWSTR, DWORD);
WINBASEAPI BOOL WINAPI WriteProfileStringA(LPCSTR, LPCSTR, LPCSTR);
WINBASEAPI BOOL WINAPI WriteProfileStringW(LPCWSTR, LPCWSTR, LPCWSTR);
WINBASEAPI DWORD WINAPI GetProfileSectionA(LPCSTR, LPSTR, DWORD);
WINBASEAPI DWORD WINAPI GetProfileSectionW(LPCWSTR, LPWSTR, DWORD);
WINBASEAPI BOOL WINAPI WriteProfileSectionA(LPCSTR, LPCSTR);
WINBASEAPI BOOL WINAPI WriteProfileSectionW(LPCWSTR, LPCWSTR);
WINBASEAPI UINT WINAPI GetPrivateProfileIntA(LPCSTR, LPCSTR, INT, LPCSTR);
WINBASEAPI UINT WINAPI GetPrivateProfileIntW(LPCWSTR, LPCWSTR, INT, LPCWSTR);
WINBASEAPI DWORD WINAPI GetPrivateProfileStringA(LPCSTR, LPCSTR, LPCSTR, LPSTR, DWORD, LPCSTR);
WINBASEAPI DWORD WINAPI GetPrivateProfileStringW(LPCWSTR, LPCWSTR, LPCWSTR, LPWSTR, DWORD, LPCWSTR);
WINBASEAPI BOOL WINAPI WritePrivateProfileStringA(LPCSTR, LPCSTR, LPCSTR, LPCSTR);
WINBASEAPI BOOL WINAPI WritePrivateProfileStringW(LPCWSTR, LPCWSTR, LPCWSTR, LPCWSTR);
WINBASEAPI DWORD WINAPI GetPrivateProfileSectionA(LPCSTR, LPSTR, DWORD, LPCSTR);
WINBASEAPI DWORD WINAPI GetPrivateProfileSectionW(LPCWSTR, LPWSTR, DWORD, LPCWSTR);
WINBASEAPI BOOL WINAPI WritePrivateProfileSectionA(LPCSTR, LPCSTR, LPCSTR);
WINBASEAPI BOOL WINAPI WritePrivateProfileSectionW(LPCWSTR, LPCWSTR, LPCWSTR);
WINBASEAPI DWORD WINAPI GetPrivateProfileSectionNamesA(LPSTR, DWORD, LPCSTR);
WINBASEAPI DWORD WINAPI GetPrivateProfileSectionNamesW(LPWSTR, DWORD, LPCWSTR);
WINBASEAPI BOOL WINAPI GetPrivateProfileStructA(LPCSTR, LPCSTR, LPVOID, UINT, LPCSTR);
WINBASEAPI BOOL WINAPI GetPrivateProfileStructW(LPCWSTR, LPCWSTR, LPVOID, UINT, LPCWSTR);
WINBASEAPI BOOL WINAPI WritePrivateProfileStructA(LPCSTR, LPCSTR, LPVOID, UINT, LPCSTR);
WINBASEAPI BOOL WINAPI WritePrivateProfileStructW(LPCWSTR, LPCWSTR, LPVOID, UINT, LPCWSTR);

#ifdef UNICODE
#define GetProfileInt  GetProfileIntW
#define GetProfileString  GetProfileStringW
#define WriteProfileString  WriteProfileStringW
#define GetProfileSection  GetProfileSectionW
#define WriteProfileSection  WriteProfileSectionW
#define GetPrivateProfileInt  GetPrivateProfileIntW
#define GetPrivateProfileString  GetPrivateProfileStringW
#define WritePrivateProfileString  WritePrivateProfileStringW
#define GetPrivateProfileSection  GetPrivateProfileSectionW
#define WritePrivateProfileSection  WritePrivateProfileSectionW
#define GetPrivateProfileSectionNames  GetPrivateProfileSectionNamesW
#define GetPrivateProfileStruct  GetPrivateProfileStructW
#define WritePrivateProfileStruct  WritePrivateProfileStructW
#else /* !UNICODE */
#define GetProfileInt  GetProfileIntA
#define GetProfileString  GetProfileStringA
#define WriteProfileString  WriteProfileStringA
#define GetProfileSection  GetProfileSectionA
#define WriteProfileSection  WriteProfileSectionA
#define GetPrivateProfileInt  GetPrivateProfileIntA
#define GetPrivateProfileString  GetPrivateProfileStringA
#define WritePrivateProfileString  WritePrivateProfileStringA
#define GetPrivateProfileSection  GetPrivateProfileSectionA
#define WritePrivateProfileSection  WritePrivateProfileSectionA
#define GetPrivateProfileSectionNames  GetPrivateProfileSectionNamesA
#define GetPrivateProfileStruct  GetPrivateProfileStructA
#define WritePrivateProfileStruct  WritePrivateProfileStructA
#endif /* !UNICODE */

WINBASEAPI UINT WINAPI GetDriveTypeA(LPCSTR);
WINBASEAPI UINT WINAPI GetDriveTypeW(LPCWSTR);
WINBASEAPI UINT WINAPI GetSystemDirectoryA(LPSTR, UINT);
WINBASEAPI UINT WINAPI GetSystemDirectoryW(LPWSTR, UINT);
WINBASEAPI DWORD WINAPI GetTempPathA(DWORD, LPSTR);
WINBASEAPI DWORD WINAPI GetTempPathW(DWORD, LPWSTR);
WINBASEAPI UINT WINAPI GetTempFileNameA(LPCSTR, LPCSTR, UINT, LPSTR);
WINBASEAPI UINT WINAPI GetTempFileNameW(LPCWSTR, LPCWSTR, UINT, LPWSTR);
WINBASEAPI UINT WINAPI GetWindowsDirectoryA(LPSTR, UINT);
WINBASEAPI UINT WINAPI GetWindowsDirectoryW(LPWSTR, UINT);
WINBASEAPI UINT WINAPI GetSystemWindowsDirectoryA(LPSTR, UINT);
WINBASEAPI UINT WINAPI GetSystemWindowsDirectoryW(LPWSTR, UINT);

#ifdef UNICODE
#define GetDriveType  GetDriveTypeW
#define GetSystemDirectory  GetSystemDirectoryW
#define GetTempPath  GetTempPathW
#define GetTempFileName  GetTempFileNameW
#define GetWindowsDirectory  GetWindowsDirectoryW
#define GetSystemWindowsDirectory  GetSystemWindowsDirectoryW
#else /* !UNICODE */
#define GetDriveType  GetDriveTypeA
#define GetSystemDirectory  GetSystemDirectoryA
#define GetTempPath  GetTempPathA
#define GetTempFileName  GetTempFileNameA
#define GetWindowsDirectory  GetWindowsDirectoryA
#define GetSystemWindowsDirectory  GetSystemWindowsDirectoryA
#endif /* !UNICODE */

#if _WIN32_WINNT >= 0x0501 || defined(WINBASE_DECLARE_GET_SYSTEM_WOW64_DIRECTORY)

WINBASEAPI UINT WINAPI GetSystemWow64DirectoryA(LPSTR, UINT);
WINBASEAPI UINT WINAPI GetSystemWow64DirectoryW(LPWSTR, UINT);
WINBASEAPI BOOLEAN WINAPI Wow64EnableWow64FsRedirection(BOOLEAN);
WINBASEAPI BOOL WINAPI Wow64DisableWow64FsRedirection(PVOID *);
WINBASEAPI BOOL WINAPI Wow64RevertWow64FsRedirection(PVOID);

#ifdef UNICODE
#define GetSystemWow64Directory  GetSystemWow64DirectoryW
#else /* !UNICODE */
#define GetSystemWow64Directory  GetSystemWow64DirectoryA
#endif /* !UNICODE */

typedef UINT (WINAPI *PGET_SYSTEM_WOW64_DIRECTORY_A)(LPSTR, UINT);
typedef UINT (WINAPI *PGET_SYSTEM_WOW64_DIRECTORY_W)(LPWSTR, UINT);

#define GET_SYSTEM_WOW64_DIRECTORY_NAME_A_A  "GetSystemWow64DirectoryA"
#define GET_SYSTEM_WOW64_DIRECTORY_NAME_A_W  L"GetSystemWow64DirectoryA"
#define GET_SYSTEM_WOW64_DIRECTORY_NAME_A_T TEXT("GetSystemWow64DirectoryA")
#define GET_SYSTEM_WOW64_DIRECTORY_NAME_W_A  "GetSystemWow64DirectoryW"
#define GET_SYSTEM_WOW64_DIRECTORY_NAME_W_W  L"GetSystemWow64DirectoryW"
#define GET_SYSTEM_WOW64_DIRECTORY_NAME_W_T TEXT("GetSystemWow64DirectoryW")

#ifdef UNICODE
#define GET_SYSTEM_WOW64_DIRECTORY_NAME_T_A GET_SYSTEM_WOW64_DIRECTORY_NAME_W_A
#define GET_SYSTEM_WOW64_DIRECTORY_NAME_T_W GET_SYSTEM_WOW64_DIRECTORY_NAME_W_W
#define GET_SYSTEM_WOW64_DIRECTORY_NAME_T_T GET_SYSTEM_WOW64_DIRECTORY_NAME_W_T
#else /* !UNICODE */
#define GET_SYSTEM_WOW64_DIRECTORY_NAME_T_A GET_SYSTEM_WOW64_DIRECTORY_NAME_A_A
#define GET_SYSTEM_WOW64_DIRECTORY_NAME_T_W GET_SYSTEM_WOW64_DIRECTORY_NAME_A_W
#define GET_SYSTEM_WOW64_DIRECTORY_NAME_T_T GET_SYSTEM_WOW64_DIRECTORY_NAME_A_T
#endif /* !UNICODE */

#endif /* _WIN32_WINNT >= 0x0501 || defined(WINBASE_DECLARE_GET_SYSTEM_WOW64_DIRECTORY) */

WINBASEAPI BOOL WINAPI SetCurrentDirectoryA(LPCSTR);
WINBASEAPI BOOL WINAPI SetCurrentDirectoryW(LPCWSTR);
WINBASEAPI DWORD WINAPI GetCurrentDirectoryA(DWORD, LPSTR);
WINBASEAPI DWORD WINAPI GetCurrentDirectoryW(DWORD, LPWSTR);

#ifdef UNICODE
#define SetCurrentDirectory  SetCurrentDirectoryW
#define GetCurrentDirectory  GetCurrentDirectoryW
#else /* !UNICODE */
#define SetCurrentDirectory  SetCurrentDirectoryA
#define GetCurrentDirectory  GetCurrentDirectoryA
#endif /* !UNICODE */

#if _WIN32_WINNT >= 0x0502

WINBASEAPI BOOL WINAPI SetDllDirectoryA(LPCSTR);
WINBASEAPI BOOL WINAPI SetDllDirectoryW(LPCWSTR);
WINBASEAPI DWORD WINAPI GetDllDirectoryA(DWORD, LPSTR);
WINBASEAPI DWORD WINAPI GetDllDirectoryW(DWORD, LPWSTR);

#ifdef UNICODE
#define SetDllDirectory  SetDllDirectoryW
#define GetDllDirectory  GetDllDirectoryW
#else /* !UNICODE */
#define SetDllDirectory  SetDllDirectoryA
#define GetDllDirectory  GetDllDirectoryA
#endif /* !UNICODE */

#endif /* _WIN32_WINNT >= 0x0502 */

#define BASE_SEARCH_PATH_ENABLE_SAFE_SEARCHMODE 0x1
#define BASE_SEARCH_PATH_DISABLE_SAFE_SEARCHMODE 0x10000
#define BASE_SEARCH_PATH_PERMANENT 0x8000
#define BASE_SEARCH_PATH_INVALID_FLAGS ~0x18001

WINBASEAPI BOOL WINAPI SetSearchPathMode(DWORD);

WINBASEAPI BOOL WINAPI GetDiskFreeSpaceA(LPCSTR, LPDWORD, LPDWORD, LPDWORD, LPDWORD);
WINBASEAPI BOOL WINAPI GetDiskFreeSpaceW(LPCWSTR, LPDWORD, LPDWORD, LPDWORD, LPDWORD);
WINBASEAPI BOOL WINAPI GetDiskFreeSpaceExA(LPCSTR, PULARGE_INTEGER, PULARGE_INTEGER, PULARGE_INTEGER);
WINBASEAPI BOOL WINAPI GetDiskFreeSpaceExW(LPCWSTR, PULARGE_INTEGER, PULARGE_INTEGER, PULARGE_INTEGER);

#ifdef UNICODE
#define GetDiskFreeSpace  GetDiskFreeSpaceW
#define GetDiskFreeSpaceEx  GetDiskFreeSpaceExW
#else /* !UNICODE */
#define GetDiskFreeSpace  GetDiskFreeSpaceA
#define GetDiskFreeSpaceEx  GetDiskFreeSpaceExA
#endif /* !UNICODE */

WINBASEAPI BOOL WINAPI CreateDirectoryA(LPCSTR, LPSECURITY_ATTRIBUTES);
WINBASEAPI BOOL WINAPI CreateDirectoryW(LPCWSTR, LPSECURITY_ATTRIBUTES);
WINBASEAPI BOOL WINAPI CreateDirectoryExA(LPCSTR, LPCSTR, LPSECURITY_ATTRIBUTES);
WINBASEAPI BOOL WINAPI CreateDirectoryExW(LPCWSTR, LPCWSTR, LPSECURITY_ATTRIBUTES);
WINBASEAPI BOOL WINAPI RemoveDirectoryA(LPCSTR);
WINBASEAPI BOOL WINAPI RemoveDirectoryW(LPCWSTR);
WINBASEAPI DWORD WINAPI GetFullPathNameA(LPCSTR, DWORD, LPSTR, LPSTR *);
WINBASEAPI DWORD WINAPI GetFullPathNameW(LPCWSTR, DWORD, LPWSTR, LPWSTR *);

#ifdef UNICODE
#define CreateDirectory  CreateDirectoryW
#define CreateDirectoryEx  CreateDirectoryExW
#define RemoveDirectory  RemoveDirectoryW
#define GetFullPathName  GetFullPathNameW
#else /* !UNICODE */
#define CreateDirectory  CreateDirectoryA
#define CreateDirectoryEx  CreateDirectoryExA
#define RemoveDirectory  RemoveDirectoryA
#define GetFullPathName  GetFullPathNameA
#endif /* !UNICODE */

#if _WIN32_WINNT >= 0x0600

WINBASEAPI BOOL WINAPI CreateDirectoryTransactedA(LPCSTR, LPCSTR, LPSECURITY_ATTRIBUTES, HANDLE);
WINBASEAPI BOOL WINAPI CreateDirectoryTransactedW(LPCWSTR, LPCWSTR, LPSECURITY_ATTRIBUTES, HANDLE);
WINBASEAPI BOOL WINAPI RemoveDirectoryTransactedA(LPCSTR, HANDLE);
WINBASEAPI BOOL WINAPI RemoveDirectoryTransactedW(LPCWSTR, HANDLE);
WINBASEAPI DWORD WINAPI GetFullPathNameTransactedA(LPCSTR, DWORD, LPSTR, LPSTR *, HANDLE);
WINBASEAPI DWORD WINAPI GetFullPathNameTransactedW(LPCWSTR, DWORD, LPWSTR, LPWSTR *, HANDLE);

#ifdef UNICODE
#define CreateDirectoryTransacted  CreateDirectoryTransactedW
#define RemoveDirectoryTransacted  RemoveDirectoryTransactedW
#define GetFullPathNameTransacted  GetFullPathNameTransactedW
#else /* !UNICODE */
#define CreateDirectoryTransacted  CreateDirectoryTransactedA
#define RemoveDirectoryTransacted  RemoveDirectoryTransactedA
#define GetFullPathNameTransacted  GetFullPathNameTransactedA
#endif /* !UNICODE */

#endif /* _WIN32_WINNT >= 0x0600 */

#define DDD_RAW_TARGET_PATH  0x00000001
#define DDD_REMOVE_DEFINITION  0x00000002
#define DDD_EXACT_MATCH_ON_REMOVE  0x00000004
#define DDD_NO_BROADCAST_SYSTEM  0x00000008
#define DDD_LUID_BROADCAST_DRIVE  0x00000010

WINBASEAPI BOOL WINAPI DefineDosDeviceA(DWORD, LPCSTR, LPCSTR);
WINBASEAPI BOOL WINAPI DefineDosDeviceW(DWORD, LPCWSTR, LPCWSTR);
WINBASEAPI DWORD WINAPI QueryDosDeviceA(LPCSTR, LPSTR, DWORD);
WINBASEAPI DWORD WINAPI QueryDosDeviceW(LPCWSTR, LPWSTR, DWORD);

#ifdef UNICODE
#define DefineDosDevice  DefineDosDeviceW
#define QueryDosDevice  QueryDosDeviceW
#else /* !UNICODE */
#define DefineDosDevice  DefineDosDeviceA
#define QueryDosDevice  QueryDosDeviceA
#endif /* !UNICODE */

#define EXPAND_LOCAL_DRIVES

WINBASEAPI HANDLE WINAPI CreateFileA(LPCSTR, DWORD, DWORD, LPSECURITY_ATTRIBUTES, DWORD, DWORD, HANDLE);
WINBASEAPI HANDLE WINAPI CreateFileW(LPCWSTR, DWORD, DWORD, LPSECURITY_ATTRIBUTES, DWORD, DWORD, HANDLE);

#ifdef UNICODE
#define CreateFile  CreateFileW
#else /* !UNICODE */
#define CreateFile  CreateFileA
#endif /* !UNICODE */

#if _WIN32_WINNT >= 0x0600
WINBASEAPI HANDLE WINAPI CreateFileTransactedA(LPCSTR, DWORD, DWORD, LPSECURITY_ATTRIBUTES, DWORD, DWORD, HANDLE, HANDLE, PUSHORT, PVOID);
WINBASEAPI HANDLE WINAPI CreateFileTransactedW(LPCWSTR, DWORD, DWORD, LPSECURITY_ATTRIBUTES, DWORD, DWORD, HANDLE, HANDLE, PUSHORT, PVOID);
#ifdef UNICODE
#define CreateFileTransacted  CreateFileTransactedW
#else /* !UNICODE */
#define CreateFileTransacted  CreateFileTransactedA
#endif /* !UNICODE */
#endif /* _WIN32_WINNT >= 0x0600 */

#if _WIN32_WINNT >= 0x0502
WINBASEAPI HANDLE WINAPI ReOpenFile(HANDLE, DWORD, DWORD, DWORD);
#endif /* _WIN32_WINNT >= 0x0502 */

WINBASEAPI BOOL WINAPI SetFileAttributesA(LPCSTR, DWORD);
WINBASEAPI BOOL WINAPI SetFileAttributesW(LPCWSTR, DWORD);
WINBASEAPI DWORD WINAPI GetFileAttributesA(LPCSTR);
WINBASEAPI DWORD WINAPI GetFileAttributesW(LPCWSTR);

#ifdef UNICODE
#define SetFileAttributes  SetFileAttributesW
#define GetFileAttributes  GetFileAttributesW
#else /* !UNICODE */
#define SetFileAttributes  SetFileAttributesA
#define GetFileAttributes  GetFileAttributesA
#endif /* !UNICODE */

#if (_WIN32_WINNT >= 0x0600)
WINBASEAPI BOOL WINAPI SetFileAttributesTransactedA(LPCSTR, DWORD, HANDLE);
WINBASEAPI BOOL WINAPI SetFileAttributesTransactedW(LPCWSTR, DWORD, HANDLE);
#ifdef UNICODE
#define SetFileAttributesTransacted  SetFileAttributesTransactedW
#else /* !UNICODE */
#define SetFileAttributesTransacted  SetFileAttributesTransactedA
#endif /* !UNICODE */
#endif /* _WIN32_WINNT >= 0x0600 */

typedef enum _GET_FILEEX_INFO_LEVELS {
    GetFileExInfoStandard,
    GetFileExMaxInfoLevel
} GET_FILEEX_INFO_LEVELS;

#if (_WIN32_WINNT >= 0x0600)
WINBASEAPI BOOL WINAPI GetFileAttributesTransactedA(LPCSTR, GET_FILEEX_INFO_LEVELS, LPVOID, HANDLE);
WINBASEAPI BOOL WINAPI GetFileAttributesTransactedW(LPCWSTR, GET_FILEEX_INFO_LEVELS, LPVOID, HANDLE);
#ifdef UNICODE
#define GetFileAttributesTransacted  GetFileAttributesTransactedW
#else /* !UNICODE */
#define GetFileAttributesTransacted  GetFileAttributesTransactedA
#endif /* !UNICODE */
#endif /* _WIN32_WINNT >= 0x0600 */

WINBASEAPI BOOL WINAPI GetFileAttributesExA(LPCSTR, GET_FILEEX_INFO_LEVELS, LPVOID);
WINBASEAPI BOOL WINAPI GetFileAttributesExW(LPCWSTR, GET_FILEEX_INFO_LEVELS, LPVOID);
#ifdef UNICODE
#define GetFileAttributesEx  GetFileAttributesExW
#else /* !UNICODE */
#define GetFileAttributesEx  GetFileAttributesExA
#endif /* !UNICODE */

WINBASEAPI DWORD WINAPI GetCompressedFileSizeA(LPCSTR, LPDWORD);
WINBASEAPI DWORD WINAPI GetCompressedFileSizeW(LPCWSTR, LPDWORD);
#ifdef UNICODE
#define GetCompressedFileSize  GetCompressedFileSizeW
#else /* !UNICODE */
#define GetCompressedFileSize  GetCompressedFileSizeA
#endif /* !UNICODE */

#if (_WIN32_WINNT >= 0x0600)
WINBASEAPI DWORD WINAPI GetCompressedFileSizeTransactedA(LPCSTR, LPDWORD, HANDLE);
WINBASEAPI DWORD WINAPI GetCompressedFileSizeTransactedW(LPCWSTR, LPDWORD, HANDLE);
#ifdef UNICODE
#define GetCompressedFileSizeTransacted  GetCompressedFileSizeTransactedW
#else /* !UNICODE */
#define GetCompressedFileSizeTransacted  GetCompressedFileSizeTransactedA
#endif /* !UNICODE */
#endif /* _WIN32_WINNT >= 0x0600 */

WINBASEAPI BOOL WINAPI DeleteFileA(LPCSTR);
WINBASEAPI BOOL WINAPI DeleteFileW(LPCWSTR);
#ifdef UNICODE
#define DeleteFile  DeleteFileW
#else /* !UNICODE */
#define DeleteFile  DeleteFileA
#endif /* !UNICODE */

#if (_WIN32_WINNT >= 0x0600)
WINBASEAPI BOOL WINAPI DeleteFileTransactedA(LPCSTR, HANDLE);
WINBASEAPI BOOL WINAPI DeleteFileTransactedW(LPCWSTR, HANDLE);
#ifdef UNICODE
#define DeleteFileTransacted  DeleteFileTransactedW
#else /* !UNICODE */
#define DeleteFileTransacted  DeleteFileTransactedA
#endif /* !UNICODE */
#endif /* _WIN32_WINNT >= 0x0600 */

#if (_WIN32_WINNT >= 0x0501)
WINBASEAPI BOOL WINAPI CheckNameLegalDOS8Dot3A(LPCSTR, LPSTR, DWORD, PBOOL, PBOOL);
WINBASEAPI BOOL WINAPI CheckNameLegalDOS8Dot3W(LPCWSTR, LPSTR, DWORD, PBOOL, PBOOL);
#ifdef UNICODE
#define CheckNameLegalDOS8Dot3  CheckNameLegalDOS8Dot3W
#else /* !UNICODE */
#define CheckNameLegalDOS8Dot3  CheckNameLegalDOS8Dot3A
#endif /* !UNICODE */
#endif /* _WIN32_WINNT >= 0x0501 */

#if (_WIN32_WINNT >= 0x0400)
typedef enum _FINDEX_INFO_LEVELS {
    FindExInfoStandard,
    FindExInfoBasic,
    FindExInfoMaxInfoLevel
} FINDEX_INFO_LEVELS;

typedef enum _FINDEX_SEARCH_OPS {
    FindExSearchNameMatch,
    FindExSearchLimitToDirectories,
    FindExSearchLimitToDevices,
    FindExSearchMaxSearchOp
} FINDEX_SEARCH_OPS;

#define FIND_FIRST_EX_CASE_SENSITIVE  0x00000001
#define FIND_FIRST_EX_LARGE_FETCH  0x00000002

WINBASEAPI HANDLE WINAPI FindFirstFileExA(LPCSTR, FINDEX_INFO_LEVELS, LPVOID, FINDEX_SEARCH_OPS, LPVOID, DWORD);
WINBASEAPI HANDLE WINAPI FindFirstFileExW(LPCWSTR, FINDEX_INFO_LEVELS, LPVOID, FINDEX_SEARCH_OPS, LPVOID, DWORD);
#ifdef UNICODE
#define FindFirstFileEx  FindFirstFileExW
#else /* !UNICODE */
#define FindFirstFileEx  FindFirstFileExA
#endif /* !UNICODE */

#if (_WIN32_WINNT >= 0x0600)
WINBASEAPI HANDLE WINAPI FindFirstFileTransactedA(LPCSTR, FINDEX_INFO_LEVELS, LPVOID, FINDEX_SEARCH_OPS, LPVOID, DWORD, HANDLE);
WINBASEAPI HANDLE WINAPI FindFirstFileTransactedW(LPCWSTR, FINDEX_INFO_LEVELS, LPVOID, FINDEX_SEARCH_OPS, LPVOID, DWORD, HANDLE);
#ifdef UNICODE
#define FindFirstFileTransacted  FindFirstFileTransactedW
#else /* !UNICODE */
#define FindFirstFileTransacted  FindFirstFileTransactedA
#endif /* !UNICODE */
#endif /* _WIN32_WINNT >= 0x0600 */

#endif /* _WIN32_WINNT >= 0x0400 */

WINBASEAPI HANDLE WINAPI FindFirstFileA(LPCSTR, LPWIN32_FIND_DATAA);
WINBASEAPI HANDLE WINAPI FindFirstFileW(LPCWSTR, LPWIN32_FIND_DATAW);
WINBASEAPI BOOL WINAPI FindNextFileA(HANDLE, LPWIN32_FIND_DATAA);
WINBASEAPI BOOL WINAPI FindNextFileW(HANDLE, LPWIN32_FIND_DATAW);

#ifdef UNICODE
#define FindFirstFile  FindFirstFileW
#define FindNextFile  FindNextFileW
#else /* !UNICODE */
#define FindFirstFile  FindFirstFileA
#define FindNextFile  FindNextFileA
#endif /* !UNICODE */

WINBASEAPI DWORD WINAPI SearchPathA(LPCSTR, LPCSTR, LPCSTR, DWORD, LPSTR, LPSTR *);
WINBASEAPI DWORD WINAPI SearchPathW(LPCWSTR, LPCWSTR, LPCWSTR, DWORD, LPWSTR, LPWSTR *);
#ifdef UNICODE
#define SearchPath  SearchPathW
#else /* !UNICODE */
#define SearchPath  SearchPathA
#endif /* !UNICODE */

WINBASEAPI BOOL WINAPI CopyFileA(LPCSTR, LPCSTR, BOOL);
WINBASEAPI BOOL WINAPI CopyFileW(LPCWSTR, LPCWSTR, BOOL);
#ifdef UNICODE
#define CopyFile  CopyFileW
#else /* !UNICODE */
#define CopyFile  CopyFileA
#endif /* !UNICODE */

#if (_WIN32_WINNT >= 0x0400)
typedef DWORD (WINAPI *LPPROGRESS_ROUTINE)(LARGE_INTEGER, LARGE_INTEGER, LARGE_INTEGER, LARGE_INTEGER, DWORD, DWORD, HANDLE, HANDLE, LPVOID);

WINBASEAPI BOOL WINAPI CopyFileExA(LPCSTR, LPCSTR, LPPROGRESS_ROUTINE, LPVOID, LPBOOL, DWORD);
WINBASEAPI BOOL WINAPI CopyFileExW(LPCWSTR, LPCWSTR, LPPROGRESS_ROUTINE, LPVOID, LPBOOL, DWORD);
#ifdef UNICODE
#define CopyFileEx  CopyFileExW
#else /* !UNICODE */
#define CopyFileEx  CopyFileExA
#endif /* !UNICODE */

#if (_WIN32_WINNT >= 0x0600)
WINBASEAPI BOOL WINAPI CopyFileTransactedA(LPCSTR, LPCSTR, LPPROGRESS_ROUTINE, LPVOID, LPBOOL, DWORD, HANDLE);
WINBASEAPI BOOL WINAPI CopyFileTransactedW(LPCWSTR, LPCWSTR, LPPROGRESS_ROUTINE, LPVOID, LPBOOL, DWORD, HANDLE);
#ifdef UNICODE
#define CopyFileTransacted  CopyFileTransactedW
#else /* !UNICODE */
#define CopyFileTransacted  CopyFileTransactedA
#endif /* !UNICODE */
#endif /* _WIN32_WINNT >= 0x0600 */

#endif /* _WIN32_WINNT >= 0x0400 */

WINBASEAPI BOOL WINAPI MoveFileA(LPCSTR, LPCSTR);
WINBASEAPI BOOL WINAPI MoveFileW(LPCWSTR, LPCWSTR);
WINBASEAPI BOOL WINAPI MoveFileExA(LPCSTR, LPCSTR, DWORD);
WINBASEAPI BOOL WINAPI MoveFileExW(LPCWSTR, LPCWSTR, DWORD);

#ifdef UNICODE
#define MoveFile  MoveFileW
#define MoveFileEx  MoveFileExW
#else /* !UNICODE */
#define MoveFile  MoveFileA
#define MoveFileEx  MoveFileExA
#endif /* !UNICODE */

#if (_WIN32_WINNT >= 0x0500)
WINBASEAPI BOOL WINAPI MoveFileWithProgressA(LPCSTR, LPCSTR, LPPROGRESS_ROUTINE, LPVOID, DWORD);
WINBASEAPI BOOL WINAPI MoveFileWithProgressW(LPCWSTR, LPCWSTR, LPPROGRESS_ROUTINE, LPVOID, DWORD);
#ifdef UNICODE
#define MoveFileWithProgress  MoveFileWithProgressW
#else /* !UNICODE */
#define MoveFileWithProgress  MoveFileWithProgressA
#endif /* !UNICODE */
#endif /* _WIN32_WINNT >= 0x0500 */

#if (_WIN32_WINNT >= 0x0600)
WINBASEAPI BOOL WINAPI MoveFileTransactedA(LPCSTR, LPCSTR, LPPROGRESS_ROUTINE, LPVOID, DWORD, HANDLE);
WINBASEAPI BOOL WINAPI MoveFileTransactedW(LPCWSTR, LPCWSTR, LPPROGRESS_ROUTINE, LPVOID, DWORD, HANDLE);
#ifdef UNICODE
#define MoveFileTransacted  MoveFileTransactedW
#else /* !UNICODE */
#define MoveFileTransacted  MoveFileTransactedA
#endif /* !UNICODE */
#endif /* _WIN32_WINNT >= 0x0600 */

#define MOVEFILE_REPLACE_EXISTING  0x00000001
#define MOVEFILE_COPY_ALLOWED  0x00000002
#define MOVEFILE_DELAY_UNTIL_REBOOT  0x00000004
#define MOVEFILE_WRITE_THROUGH  0x00000008
#if (_WIN32_WINNT >= 0x0500)
#define MOVEFILE_CREATE_HARDLINK  0x00000010
#define MOVEFILE_FAIL_IF_NOT_TRACKABLE  0x00000020
#endif /* _WIN32_WINNT >= 0x0500 */

#if (_WIN32_WINNT >= 0x0500)
WINBASEAPI BOOL WINAPI ReplaceFileA(LPCSTR, LPCSTR, LPCSTR, DWORD, LPVOID, LPVOID);
WINBASEAPI BOOL WINAPI ReplaceFileW(LPCWSTR, LPCWSTR, LPCWSTR, DWORD, LPVOID, LPVOID);
#ifdef UNICODE
#define ReplaceFile  ReplaceFileW
#else /* !UNICODE */
#define ReplaceFile  ReplaceFileA
#endif /* !UNICODE */
#endif /* _WIN32_WINNT >= 0x0500 */

#if (_WIN32_WINNT >= 0x0500)
WINBASEAPI BOOL WINAPI CreateHardLinkA(LPCSTR, LPCSTR, LPSECURITY_ATTRIBUTES);
WINBASEAPI BOOL WINAPI CreateHardLinkW(LPCWSTR, LPCWSTR, LPSECURITY_ATTRIBUTES);
#ifdef UNICODE
#define CreateHardLink  CreateHardLinkW
#else /* !UNICODE */
#define CreateHardLink  CreateHardLinkA
#endif /* !UNICODE */
#endif /* _WIN32_WINNT >= 0x0500 */

#if (_WIN32_WINNT >= 0x0600)
WINBASEAPI BOOL WINAPI CreateHardLinkTransactedA(LPCSTR, LPCSTR, LPSECURITY_ATTRIBUTES, HANDLE);
WINBASEAPI BOOL WINAPI CreateHardLinkTransactedW(LPCWSTR, LPCWSTR, LPSECURITY_ATTRIBUTES, HANDLE);
#ifdef UNICODE
#define CreateHardLinkTransacted  CreateHardLinkTransactedW
#else /* !UNICODE */
#define CreateHardLinkTransacted  CreateHardLinkTransactedA
#endif /* !UNICODE */
#endif /* _WIN32_WINNT >= 0x0600 */

#if (_WIN32_WINNT >= 0x0501)
typedef enum _STREAM_INFO_LEVELS {
    FindStreamInfoStandard,
    FindStreamInfoMaxInfoLevel
} STREAM_INFO_LEVELS;

typedef struct _WIN32_FIND_STREAM_DATA {
    LARGE_INTEGER StreamSize;
    WCHAR cStreamName[MAX_PATH + 36];
} WIN32_FIND_STREAM_DATA, *PWIN32_FIND_STREAM_DATA;

WINBASEAPI HANDLE WINAPI FindFirstStreamW(LPCWSTR, STREAM_INFO_LEVELS, LPVOID, DWORD);
#if (_WIN32_WINNT >= 0x0600)
WINBASEAPI HANDLE WINAPI FindFirstStreamTransactedW(LPCWSTR, STREAM_INFO_LEVELS, LPVOID, DWORD, HANDLE);
#endif /* _WIN32_WINNT >= 0x600 */
WINBASEAPI BOOL APIENTRY FindNextStreamW(HANDLE, LPVOID);
#endif /* _WIN32_WINNT >= 0x0501 */

#if (_WIN32_WINNT >= 0x0600)
WINBASEAPI HANDLE WINAPI FindFirstFileNameW(LPCWSTR, DWORD, LPDWORD, PWCHAR);
WINBASEAPI BOOL APIENTRY FindNextFileNameW(HANDLE, LPDWORD, PWCHAR);
WINBASEAPI HANDLE WINAPI FindFirstFileNameTransactedW(LPCWSTR, DWORD, LPDWORD, PWCHAR, HANDLE);
#endif /* _WIN32_WINNT >= 0x0600 */

typedef enum {
    PipeAttribute,
    PipeConnectionAttribute,
    PipeHandleAttribute
} PIPE_ATTRIBUTE_TYPE;

WINBASEAPI HANDLE WINAPI CreateNamedPipeA(LPCSTR, DWORD, DWORD, DWORD, DWORD, DWORD, DWORD, LPSECURITY_ATTRIBUTES);
WINBASEAPI HANDLE WINAPI CreateNamedPipeW(LPCWSTR, DWORD, DWORD, DWORD, DWORD, DWORD, DWORD, LPSECURITY_ATTRIBUTES);
WINBASEAPI BOOL WINAPI GetNamedPipeHandleStateA(HANDLE, LPDWORD, LPDWORD, LPDWORD, LPDWORD, LPSTR, DWORD);
WINBASEAPI BOOL WINAPI GetNamedPipeHandleStateW(HANDLE, LPDWORD, LPDWORD, LPDWORD, LPDWORD, LPWSTR, DWORD);
WINBASEAPI BOOL WINAPI CallNamedPipeA(LPCSTR, LPVOID, DWORD, LPVOID, DWORD, LPDWORD, DWORD);
WINBASEAPI BOOL WINAPI CallNamedPipeW(LPCWSTR, LPVOID, DWORD, LPVOID, DWORD, LPDWORD, DWORD);
WINBASEAPI BOOL WINAPI WaitNamedPipeA(LPCSTR, DWORD);
WINBASEAPI BOOL WINAPI WaitNamedPipeW(LPCWSTR, DWORD);
WINBASEAPI BOOL WINAPI GetNamedPipeAttribute(HANDLE, PIPE_ATTRIBUTE_TYPE, PSTR, PVOID, PSIZE_T);
WINBASEAPI BOOL WINAPI SetNamedPipeAttribute(HANDLE, PIPE_ATTRIBUTE_TYPE, PSTR, PVOID, SIZE_T);
WINBASEAPI BOOL WINAPI GetNamedPipeClientComputerNameA(HANDLE, LPSTR, ULONG);
WINBASEAPI BOOL WINAPI GetNamedPipeClientComputerNameW(HANDLE, LPWSTR, ULONG);
WINBASEAPI BOOL WINAPI GetNamedPipeClientProcessId(HANDLE, PULONG);
WINBASEAPI BOOL WINAPI GetNamedPipeClientSessionId(HANDLE, PULONG);
WINBASEAPI BOOL WINAPI GetNamedPipeServerProcessId(HANDLE, PULONG);
WINBASEAPI BOOL WINAPI GetNamedPipeServerSessionId(HANDLE, PULONG);

#ifdef UNICODE
#define CreateNamedPipe  CreateNamedPipeW
#define GetNamedPipeHandleState  GetNamedPipeHandleStateW
#define CallNamedPipe  CallNamedPipeW
#define WaitNamedPipe  WaitNamedPipeW
#define GetNamedPipeClientComputerName  GetNamedPipeClientComputerNameW
#else /* !UNICODE */
#define CreateNamedPipe  CreateNamedPipeA
#define GetNamedPipeHandleState  GetNamedPipeHandleStateA
#define CallNamedPipe  CallNamedPipeA
#define WaitNamedPipe  WaitNamedPipeA
#define GetNamedPipeClientComputerName  GetNamedPipeClientComputerNameA
#endif /* !UNICODE */

WINBASEAPI BOOL WINAPI SetVolumeLabelA(LPCSTR, LPCSTR);
WINBASEAPI BOOL WINAPI SetVolumeLabelW(LPCWSTR, LPCWSTR);
#ifdef UNICODE
#define SetVolumeLabel  SetVolumeLabelW
#else /* !UNICODE */
#define SetVolumeLabel  SetVolumeLabelA
#endif /* !UNICODE */

WINBASEAPI VOID WINAPI SetFileApisToOEM(VOID);
WINBASEAPI VOID WINAPI SetFileApisToANSI(VOID);
WINBASEAPI BOOL WINAPI AreFileApisANSI(VOID);

WINBASEAPI BOOL WINAPI GetVolumeInformationA(LPCSTR, LPSTR, DWORD, LPDWORD, LPDWORD, LPDWORD, LPSTR, DWORD);
WINBASEAPI BOOL WINAPI GetVolumeInformationW(LPCWSTR, LPWSTR, DWORD, LPDWORD, LPDWORD, LPDWORD, LPWSTR, DWORD);
#ifdef UNICODE
#define GetVolumeInformation  GetVolumeInformationW
#else /* !UNICODE */
#define GetVolumeInformation  GetVolumeInformationA
#endif /* !UNICODE */

#if (_WIN32_WINNT >= 0x0600)
WINBASEAPI BOOL WINAPI GetVolumeInformationByHandleW(HANDLE, LPWSTR, DWORD, LPDWORD, LPDWORD, LPDWORD, LPWSTR, DWORD);
#endif /* _WIN32_WINNT >=  0x0600 */

WINBASEAPI BOOL WINAPI CancelSynchronousIo(HANDLE);
WINBASEAPI BOOL WINAPI CancelIoEx(HANDLE, LPOVERLAPPED);
WINBASEAPI BOOL WINAPI CancelIo(HANDLE);

WINBASEAPI BOOL WINAPI SetFileBandwidthReservation(HANDLE, DWORD, DWORD, BOOL, LPDWORD, LPDWORD);
WINBASEAPI BOOL WINAPI GetFileBandwidthReservation(HANDLE, LPDWORD, LPDWORD, LPBOOL, LPDWORD, LPDWORD);

#define EVENTLOG_FULL_INFO  0

typedef struct _EVENTLOG_FULL_INFORMATION {
    DWORD dwFull;
} EVENTLOG_FULL_INFORMATION, *LPEVENTLOG_FULL_INFORMATION;

WINADVAPI BOOL WINAPI ClearEventLogA(HANDLE, LPCSTR);
WINADVAPI BOOL WINAPI ClearEventLogW(HANDLE, LPCWSTR);
WINADVAPI BOOL WINAPI BackupEventLogA(HANDLE, LPCSTR);
WINADVAPI BOOL WINAPI BackupEventLogW(HANDLE, LPCWSTR);
WINADVAPI BOOL WINAPI CloseEventLog(HANDLE);
WINADVAPI BOOL WINAPI DeregisterEventSource(HANDLE);
WINADVAPI BOOL WINAPI NotifyChangeEventLog(HANDLE, HANDLE);
WINADVAPI BOOL WINAPI GetNumberOfEventLogRecords(HANDLE, PDWORD);
WINADVAPI BOOL WINAPI GetOldestEventLogRecord(HANDLE, PDWORD);
WINADVAPI HANDLE WINAPI OpenEventLogA(LPCSTR, LPCSTR);
WINADVAPI HANDLE WINAPI OpenEventLogW(LPCWSTR, LPCWSTR);
WINADVAPI HANDLE WINAPI RegisterEventSourceA(LPCSTR, LPCSTR);
WINADVAPI HANDLE WINAPI RegisterEventSourceW(LPCWSTR, LPCWSTR);
WINADVAPI HANDLE WINAPI OpenBackupEventLogA(LPCSTR, LPCSTR);
WINADVAPI HANDLE WINAPI OpenBackupEventLogW(LPCWSTR, LPCWSTR);
WINADVAPI BOOL WINAPI ReadEventLogA(HANDLE, DWORD, DWORD, LPVOID, DWORD, DWORD *, DWORD *);
WINADVAPI BOOL WINAPI ReadEventLogW(HANDLE, DWORD, DWORD, LPVOID, DWORD, DWORD *, DWORD *);
WINADVAPI BOOL WINAPI ReportEventA(HANDLE, WORD, WORD, DWORD, PSID, WORD, DWORD, LPCSTR *, LPVOID);
WINADVAPI BOOL WINAPI ReportEventW(HANDLE, WORD, WORD, DWORD, PSID, WORD, DWORD, LPCWSTR *, LPVOID);
WINADVAPI BOOL WINAPI GetEventLogInformation(HANDLE, DWORD, LPVOID, DWORD, LPDWORD);

#ifdef UNICODE
#define ClearEventLog  ClearEventLogW
#define BackupEventLog  BackupEventLogW
#define OpenEventLog  OpenEventLogW
#define RegisterEventSource  RegisterEventSourceW
#define OpenBackupEventLog  OpenBackupEventLogW
#define ReadEventLog  ReadEventLogW
#define ReportEvent  ReportEventW
#else /* !UNICODE */
#define ClearEventLog  ClearEventLogA
#define BackupEventLog  BackupEventLogA
#define OpenEventLog  OpenEventLogA
#define RegisterEventSource  RegisterEventSourceA
#define OpenBackupEventLog  OpenBackupEventLogA
#define ReadEventLog  ReadEventLogA
#define ReportEvent  ReportEventA
#endif /* !UNICODE */

WINADVAPI BOOL WINAPI DuplicateToken(HANDLE, SECURITY_IMPERSONATION_LEVEL, PHANDLE);
WINADVAPI BOOL WINAPI GetKernelObjectSecurity(HANDLE, SECURITY_INFORMATION, PSECURITY_DESCRIPTOR, DWORD, LPDWORD);
WINADVAPI BOOL WINAPI ImpersonateNamedPipeClient(HANDLE);
WINADVAPI BOOL WINAPI ImpersonateSelf(SECURITY_IMPERSONATION_LEVEL);
WINADVAPI BOOL WINAPI RevertToSelf(VOID);
WINADVAPI BOOL APIENTRY SetThreadToken(PHANDLE, HANDLE);
WINADVAPI BOOL WINAPI AccessCheck(PSECURITY_DESCRIPTOR, HANDLE, DWORD, PGENERIC_MAPPING, PPRIVILEGE_SET, LPDWORD, LPDWORD, LPBOOL);
#if (_WIN32_WINNT >= 0x0500)
WINADVAPI BOOL WINAPI AccessCheckByType(PSECURITY_DESCRIPTOR, PSID, HANDLE, DWORD, POBJECT_TYPE_LIST, DWORD, PGENERIC_MAPPING, PPRIVILEGE_SET, LPDWORD, LPDWORD, LPBOOL);
WINADVAPI BOOL WINAPI AccessCheckByTypeResultList(PSECURITY_DESCRIPTOR, PSID, HANDLE, DWORD, POBJECT_TYPE_LIST, DWORD, PGENERIC_MAPPING, PPRIVILEGE_SET, LPDWORD, LPDWORD, LPDWORD);
#endif /* _WIN32_WINNT >=  0x0500 */
WINADVAPI BOOL WINAPI OpenProcessToken(HANDLE, DWORD, PHANDLE);
WINADVAPI BOOL WINAPI OpenThreadToken(HANDLE, DWORD, BOOL, PHANDLE);
WINADVAPI BOOL WINAPI GetTokenInformation(HANDLE, TOKEN_INFORMATION_CLASS, LPVOID, DWORD, PDWORD);
WINADVAPI BOOL WINAPI SetTokenInformation(HANDLE, TOKEN_INFORMATION_CLASS, LPVOID, DWORD);
WINADVAPI BOOL WINAPI AdjustTokenPrivileges(HANDLE, BOOL, PTOKEN_PRIVILEGES, DWORD, PTOKEN_PRIVILEGES, PDWORD);
WINADVAPI BOOL WINAPI AdjustTokenGroups(HANDLE, BOOL, PTOKEN_GROUPS, DWORD, PTOKEN_GROUPS, PDWORD);
WINADVAPI BOOL WINAPI PrivilegeCheck(HANDLE, PPRIVILEGE_SET, LPBOOL);
WINADVAPI BOOL WINAPI AccessCheckAndAuditAlarmA(LPCSTR, LPVOID, LPSTR, LPSTR, PSECURITY_DESCRIPTOR, DWORD, PGENERIC_MAPPING, BOOL, LPDWORD, LPBOOL, LPBOOL);
WINADVAPI BOOL WINAPI AccessCheckAndAuditAlarmW(LPCWSTR, LPVOID, LPWSTR, LPWSTR, PSECURITY_DESCRIPTOR, DWORD, PGENERIC_MAPPING, BOOL, LPDWORD, LPBOOL, LPBOOL);

#ifdef UNICODE
#define AccessCheckAndAuditAlarm  AccessCheckAndAuditAlarmW
#else /* !UNICODE */
#define AccessCheckAndAuditAlarm  AccessCheckAndAuditAlarmA
#endif /* !UNICODE */

#if (_WIN32_WINNT >= 0x0500)

WINADVAPI BOOL WINAPI AccessCheckByTypeAndAuditAlarmA(LPCSTR, LPVOID, LPCSTR, LPCSTR, PSECURITY_DESCRIPTOR, PSID, DWORD, AUDIT_EVENT_TYPE, DWORD, POBJECT_TYPE_LIST, DWORD, PGENERIC_MAPPING, BOOL, LPDWORD, LPBOOL, LPBOOL);
WINADVAPI BOOL WINAPI AccessCheckByTypeAndAuditAlarmW(LPCWSTR, LPVOID, LPCWSTR, LPCWSTR, PSECURITY_DESCRIPTOR, PSID, DWORD, AUDIT_EVENT_TYPE, DWORD, POBJECT_TYPE_LIST, DWORD, PGENERIC_MAPPING, BOOL, LPDWORD, LPBOOL, LPBOOL);
WINADVAPI BOOL WINAPI AccessCheckByTypeResultListAndAuditAlarmA(LPCSTR, LPVOID, LPCSTR, LPCSTR, PSECURITY_DESCRIPTOR, PSID, DWORD, AUDIT_EVENT_TYPE, DWORD, POBJECT_TYPE_LIST, DWORD, PGENERIC_MAPPING, BOOL, LPDWORD, LPDWORD, LPBOOL);
WINADVAPI BOOL WINAPI AccessCheckByTypeResultListAndAuditAlarmW(LPCWSTR, LPVOID, LPCWSTR, LPCWSTR, PSECURITY_DESCRIPTOR, PSID, DWORD, AUDIT_EVENT_TYPE, DWORD, POBJECT_TYPE_LIST, DWORD, PGENERIC_MAPPING, BOOL, LPDWORD, LPDWORD, LPBOOL);
WINADVAPI BOOL WINAPI AccessCheckByTypeResultListAndAuditAlarmByHandleA(LPCSTR, LPVOID, HANDLE, LPCSTR, LPCSTR, PSECURITY_DESCRIPTOR, PSID, DWORD, AUDIT_EVENT_TYPE, DWORD, POBJECT_TYPE_LIST, DWORD, PGENERIC_MAPPING, BOOL, LPDWORD, LPDWORD, LPBOOL);
WINADVAPI BOOL WINAPI AccessCheckByTypeResultListAndAuditAlarmByHandleW(LPCWSTR, LPVOID, HANDLE, LPCWSTR, LPCWSTR, PSECURITY_DESCRIPTOR, PSID, DWORD, AUDIT_EVENT_TYPE, DWORD, POBJECT_TYPE_LIST, DWORD, PGENERIC_MAPPING, BOOL, LPDWORD, LPDWORD, LPBOOL);

#ifdef UNICODE
#define AccessCheckByTypeAndAuditAlarm  AccessCheckByTypeAndAuditAlarmW
#define AccessCheckByTypeResultListAndAuditAlarm  AccessCheckByTypeResultListAndAuditAlarmW
#define AccessCheckByTypeResultListAndAuditAlarmByHandle  AccessCheckByTypeResultListAndAuditAlarmByHandleW
#else /* !UNICODE */
#define AccessCheckByTypeAndAuditAlarm  AccessCheckByTypeAndAuditAlarmA
#define AccessCheckByTypeResultListAndAuditAlarm  AccessCheckByTypeResultListAndAuditAlarmA
#define AccessCheckByTypeResultListAndAuditAlarmByHandle  AccessCheckByTypeResultListAndAuditAlarmByHandleA
#endif /* !UNICODE */

#endif /* _WIN32_WINNT >= 0x0500 */

WINADVAPI BOOL WINAPI ObjectOpenAuditAlarmA(LPCSTR, LPVOID, LPSTR, LPSTR, PSECURITY_DESCRIPTOR, HANDLE, DWORD, DWORD, PPRIVILEGE_SET, BOOL, BOOL, LPBOOL);
WINADVAPI BOOL WINAPI ObjectOpenAuditAlarmW(LPCWSTR, LPVOID, LPWSTR, LPWSTR, PSECURITY_DESCRIPTOR, HANDLE, DWORD, DWORD, PPRIVILEGE_SET, BOOL, BOOL, LPBOOL);
WINADVAPI BOOL WINAPI ObjectPrivilegeAuditAlarmA(LPCSTR, LPVOID, HANDLE, DWORD, PPRIVILEGE_SET, BOOL);
WINADVAPI BOOL WINAPI ObjectPrivilegeAuditAlarmW(LPCWSTR, LPVOID, HANDLE, DWORD, PPRIVILEGE_SET, BOOL);
WINADVAPI BOOL WINAPI ObjectCloseAuditAlarmA(LPCSTR, LPVOID, BOOL);
WINADVAPI BOOL WINAPI ObjectCloseAuditAlarmW(LPCWSTR, LPVOID, BOOL);
WINADVAPI BOOL WINAPI ObjectDeleteAuditAlarmA(LPCSTR, LPVOID, BOOL);
WINADVAPI BOOL WINAPI ObjectDeleteAuditAlarmW(LPCWSTR, LPVOID, BOOL);
WINADVAPI BOOL WINAPI PrivilegedServiceAuditAlarmA(LPCSTR, LPCSTR, HANDLE, PPRIVILEGE_SET, BOOL);
WINADVAPI BOOL WINAPI PrivilegedServiceAuditAlarmW(LPCWSTR, LPCWSTR, HANDLE, PPRIVILEGE_SET, BOOL);

#ifdef UNICODE
#define ObjectOpenAuditAlarm  ObjectOpenAuditAlarmW
#define ObjectPrivilegeAuditAlarm  ObjectPrivilegeAuditAlarmW
#define ObjectCloseAuditAlarm  ObjectCloseAuditAlarmW
#define ObjectDeleteAuditAlarm  ObjectDeleteAuditAlarmW
#define PrivilegedServiceAuditAlarm  PrivilegedServiceAuditAlarmW
#else /* !UNICODE */
#define ObjectOpenAuditAlarm  ObjectOpenAuditAlarmA
#define ObjectPrivilegeAuditAlarm  ObjectPrivilegeAuditAlarmA
#define ObjectCloseAuditAlarm  ObjectCloseAuditAlarmA
#define ObjectDeleteAuditAlarm  ObjectDeleteAuditAlarmA
#define PrivilegedServiceAuditAlarm  PrivilegedServiceAuditAlarmA
#endif /* !UNICODE */

#if (_WIN32_WINNT >= 0x0501)
WINADVAPI BOOL WINAPI IsWellKnownSid(PSID, WELL_KNOWN_SID_TYPE);
WINADVAPI BOOL WINAPI CreateWellKnownSid(WELL_KNOWN_SID_TYPE, PSID, PSID, DWORD *);
WINADVAPI BOOL WINAPI EqualDomainSid(PSID, PSID, BOOL *);
WINADVAPI BOOL WINAPI GetWindowsAccountDomainSid(PSID, PSID, DWORD *);
#endif /* _WIN32_WINNT >= 0x0501 */

WINADVAPI BOOL WINAPI IsValidSid(PSID);
WINADVAPI BOOL WINAPI EqualSid(PSID, PSID);
WINADVAPI BOOL WINAPI EqualPrefixSid(PSID, PSID);
WINADVAPI DWORD WINAPI GetSidLengthRequired(UCHAR);
WINADVAPI BOOL WINAPI AllocateAndInitializeSid(PSID_IDENTIFIER_AUTHORITY, BYTE, DWORD, DWORD, DWORD, DWORD, DWORD, DWORD, DWORD, DWORD, PSID *);
WINADVAPI PVOID WINAPI FreeSid(PSID);
WINADVAPI BOOL WINAPI InitializeSid(PSID, PSID_IDENTIFIER_AUTHORITY, BYTE);
WINADVAPI PSID_IDENTIFIER_AUTHORITY WINAPI GetSidIdentifierAuthority(PSID);
WINADVAPI PDWORD WINAPI GetSidSubAuthority(PSID, DWORD);
WINADVAPI PUCHAR WINAPI GetSidSubAuthorityCount(PSID);
WINADVAPI DWORD WINAPI GetLengthSid(PSID);
WINADVAPI BOOL WINAPI CopySid(DWORD, PSID, PSID);
WINADVAPI BOOL WINAPI AreAllAccessesGranted(DWORD, DWORD);
WINADVAPI BOOL WINAPI AreAnyAccessesGranted(DWORD, DWORD);
WINADVAPI VOID WINAPI MapGenericMask(PDWORD, PGENERIC_MAPPING);
WINADVAPI BOOL WINAPI IsValidAcl(PACL);
WINADVAPI BOOL WINAPI InitializeAcl(PACL, DWORD, DWORD);
WINADVAPI BOOL WINAPI GetAclInformation(PACL, LPVOID, DWORD, ACL_INFORMATION_CLASS);
WINADVAPI BOOL WINAPI SetAclInformation(PACL, LPVOID, DWORD, ACL_INFORMATION_CLASS);
WINADVAPI BOOL WINAPI AddAce(PACL, DWORD, DWORD, LPVOID, DWORD);
WINADVAPI BOOL WINAPI DeleteAce(PACL, DWORD);
WINADVAPI BOOL WINAPI GetAce(PACL, DWORD, LPVOID *);
WINADVAPI BOOL WINAPI AddAccessAllowedAce(PACL, DWORD, DWORD, PSID);
#if (_WIN32_WINNT >= 0x0500)
WINADVAPI BOOL WINAPI AddAccessAllowedAceEx(PACL, DWORD, DWORD, DWORD, PSID);
#endif /* _WIN32_WINNT >=  0x0500 */
#if (_WIN32_WINNT >= 0x0600)
WINADVAPI BOOL WINAPI AddMandatoryAce(PACL, DWORD, DWORD, DWORD, PSID);
#endif /* _WIN32_WINNT >=  0x0600 */
#if (_WIN32_WINNT >= 0x0601)
WINADVAPI BOOL WINAPI AddConditionalAce(PACL, DWORD, DWORD, UCHAR, DWORD, PSID, PWCHAR, DWORD *);
#endif /* _WIN32_WINNT >=  0x0601 */
WINADVAPI BOOL WINAPI AddAccessDeniedAce(PACL, DWORD, DWORD, PSID);
#if (_WIN32_WINNT >= 0x0500)
WINADVAPI BOOL WINAPI AddAccessDeniedAceEx(PACL, DWORD, DWORD, DWORD, PSID);
#endif /* _WIN32_WINNT >=  0x0500 */
WINADVAPI BOOL WINAPI AddAuditAccessAce(PACL, DWORD, DWORD, PSID, BOOL, BOOL);
#if (_WIN32_WINNT >= 0x0500)
WINADVAPI BOOL WINAPI AddAuditAccessAceEx(PACL, DWORD, DWORD, DWORD, PSID, BOOL, BOOL);
WINADVAPI BOOL WINAPI AddAccessAllowedObjectAce(PACL, DWORD, DWORD, DWORD, GUID *, GUID *, PSID);
WINADVAPI BOOL WINAPI AddAccessDeniedObjectAce(PACL, DWORD, DWORD, DWORD, GUID *, GUID *, PSID);
WINADVAPI BOOL WINAPI AddAuditAccessObjectAce(PACL, DWORD, DWORD, DWORD, GUID *, GUID *, PSID, BOOL, BOOL);
#endif /* _WIN32_WINNT >=  0x0500 */
WINADVAPI BOOL WINAPI FindFirstFreeAce(PACL, LPVOID *);
WINADVAPI BOOL WINAPI InitializeSecurityDescriptor(PSECURITY_DESCRIPTOR, DWORD);
WINADVAPI BOOL WINAPI IsValidSecurityDescriptor(PSECURITY_DESCRIPTOR);
WINADVAPI BOOL WINAPI IsValidRelativeSecurityDescriptor(PSECURITY_DESCRIPTOR, ULONG, SECURITY_INFORMATION);
WINADVAPI DWORD WINAPI GetSecurityDescriptorLength(PSECURITY_DESCRIPTOR);
WINADVAPI BOOL WINAPI GetSecurityDescriptorControl(PSECURITY_DESCRIPTOR, PSECURITY_DESCRIPTOR_CONTROL, LPDWORD);
#if (_WIN32_WINNT >= 0x0500)
WINADVAPI BOOL WINAPI SetSecurityDescriptorControl(PSECURITY_DESCRIPTOR, SECURITY_DESCRIPTOR_CONTROL, SECURITY_DESCRIPTOR_CONTROL);
#endif /* _WIN32_WINNT >=  0x0500 */
WINADVAPI BOOL WINAPI SetSecurityDescriptorDacl(PSECURITY_DESCRIPTOR, BOOL, PACL, BOOL);
WINADVAPI BOOL WINAPI GetSecurityDescriptorDacl(PSECURITY_DESCRIPTOR, LPBOOL, PACL *, LPBOOL);
WINADVAPI BOOL WINAPI SetSecurityDescriptorSacl(PSECURITY_DESCRIPTOR, BOOL, PACL, BOOL);
WINADVAPI BOOL WINAPI GetSecurityDescriptorSacl(PSECURITY_DESCRIPTOR, LPBOOL, PACL *, LPBOOL);
WINADVAPI BOOL WINAPI SetSecurityDescriptorOwner(PSECURITY_DESCRIPTOR, PSID, BOOL);
WINADVAPI BOOL WINAPI GetSecurityDescriptorOwner(PSECURITY_DESCRIPTOR, PSID *, LPBOOL);
WINADVAPI BOOL WINAPI SetSecurityDescriptorGroup(PSECURITY_DESCRIPTOR, PSID, BOOL);
WINADVAPI BOOL WINAPI GetSecurityDescriptorGroup(PSECURITY_DESCRIPTOR, PSID *, LPBOOL);
WINADVAPI DWORD WINAPI SetSecurityDescriptorRMControl(PSECURITY_DESCRIPTOR, PUCHAR);
WINADVAPI DWORD WINAPI GetSecurityDescriptorRMControl(PSECURITY_DESCRIPTOR, PUCHAR);
WINADVAPI BOOL WINAPI CreatePrivateObjectSecurity(PSECURITY_DESCRIPTOR, PSECURITY_DESCRIPTOR, PSECURITY_DESCRIPTOR *, BOOL, HANDLE, PGENERIC_MAPPING);
#if (_WIN32_WINNT >= 0x0500)
WINADVAPI BOOL WINAPI ConvertToAutoInheritPrivateObjectSecurity(PSECURITY_DESCRIPTOR, PSECURITY_DESCRIPTOR, PSECURITY_DESCRIPTOR *, GUID *, BOOLEAN, PGENERIC_MAPPING);
WINADVAPI BOOL WINAPI CreatePrivateObjectSecurityEx(PSECURITY_DESCRIPTOR, PSECURITY_DESCRIPTOR, PSECURITY_DESCRIPTOR *, GUID *, BOOL, ULONG, HANDLE, PGENERIC_MAPPING);
WINADVAPI BOOL WINAPI CreatePrivateObjectSecurityWithMultipleInheritance(PSECURITY_DESCRIPTOR, PSECURITY_DESCRIPTOR, PSECURITY_DESCRIPTOR *, GUID **, ULONG, BOOL, ULONG, HANDLE, PGENERIC_MAPPING);
#endif /* _WIN32_WINNT >=  0x0500 */
WINADVAPI BOOL WINAPI SetPrivateObjectSecurity(SECURITY_INFORMATION, PSECURITY_DESCRIPTOR, PSECURITY_DESCRIPTOR *, PGENERIC_MAPPING, HANDLE);
#if (_WIN32_WINNT >= 0x0500)
WINADVAPI BOOL WINAPI SetPrivateObjectSecurityEx(SECURITY_INFORMATION, PSECURITY_DESCRIPTOR, PSECURITY_DESCRIPTOR *, ULONG, PGENERIC_MAPPING, HANDLE);
#endif /* _WIN32_WINNT >=  0x0500 */
WINADVAPI BOOL WINAPI GetPrivateObjectSecurity(PSECURITY_DESCRIPTOR, SECURITY_INFORMATION, PSECURITY_DESCRIPTOR, DWORD, PDWORD);
WINADVAPI BOOL WINAPI DestroyPrivateObjectSecurity(PSECURITY_DESCRIPTOR *);
WINADVAPI BOOL WINAPI MakeSelfRelativeSD(PSECURITY_DESCRIPTOR, PSECURITY_DESCRIPTOR, LPDWORD);
WINADVAPI BOOL WINAPI MakeAbsoluteSD(PSECURITY_DESCRIPTOR, PSECURITY_DESCRIPTOR, LPDWORD, PACL, LPDWORD, PACL, LPDWORD, PSID, LPDWORD, PSID, LPDWORD);
WINADVAPI BOOL WINAPI MakeAbsoluteSD2(PSECURITY_DESCRIPTOR, LPDWORD);
WINADVAPI VOID WINAPI QuerySecurityAccessMask(SECURITY_INFORMATION, LPDWORD);
WINADVAPI VOID WINAPI SetSecurityAccessMask(SECURITY_INFORMATION, LPDWORD);
WINADVAPI BOOL WINAPI SetFileSecurityA(LPCSTR, SECURITY_INFORMATION, PSECURITY_DESCRIPTOR);
WINADVAPI BOOL WINAPI SetFileSecurityW(LPCWSTR, SECURITY_INFORMATION, PSECURITY_DESCRIPTOR);
WINADVAPI BOOL WINAPI GetFileSecurityA(LPCSTR, SECURITY_INFORMATION, PSECURITY_DESCRIPTOR, DWORD, LPDWORD);
WINADVAPI BOOL WINAPI GetFileSecurityW(LPCWSTR, SECURITY_INFORMATION, PSECURITY_DESCRIPTOR, DWORD, LPDWORD);
WINADVAPI BOOL WINAPI SetKernelObjectSecurity(HANDLE, SECURITY_INFORMATION, PSECURITY_DESCRIPTOR);

#ifdef UNICODE
#define SetFileSecurity  SetFileSecurityW
#define GetFileSecurity  GetFileSecurityW
#else /* !UNICODE */
#define SetFileSecurity  SetFileSecurityA
#define GetFileSecurity  GetFileSecurityA
#endif /* !UNICODE */

WINBASEAPI HANDLE WINAPI FindFirstChangeNotificationA(LPCSTR, BOOL, DWORD);
WINBASEAPI HANDLE WINAPI FindFirstChangeNotificationW(LPCWSTR, BOOL, DWORD);
WINBASEAPI BOOL WINAPI FindNextChangeNotification(HANDLE);
WINBASEAPI BOOL WINAPI FindCloseChangeNotification(HANDLE);

#ifdef UNICODE
#define FindFirstChangeNotification  FindFirstChangeNotificationW
#else /* !UNICODE */
#define FindFirstChangeNotification  FindFirstChangeNotificationA
#endif /* !UNICODE */

#if (_WIN32_WINNT >= 0x0400)
WINBASEAPI BOOL WINAPI ReadDirectoryChangesW(HANDLE, LPVOID, DWORD, BOOL, DWORD, LPDWORD, LPOVERLAPPED, LPOVERLAPPED_COMPLETION_ROUTINE);
#endif /* _WIN32_WINNT >= 0x0400 */

WINBASEAPI BOOL WINAPI VirtualLock(LPVOID, SIZE_T);
WINBASEAPI BOOL WINAPI VirtualUnlock(LPVOID, SIZE_T);
WINBASEAPI LPVOID WINAPI MapViewOfFileEx(HANDLE, DWORD, DWORD, DWORD, SIZE_T, LPVOID);
#if _WIN32_WINNT >= 0x0600
WINBASEAPI LPVOID WINAPI MapViewOfFileExNuma(HANDLE, DWORD, DWORD, DWORD, SIZE_T, LPVOID, DWORD);
#endif /* _WIN32_WINNT >= 0x0600 */

WINBASEAPI BOOL WINAPI SetPriorityClass(HANDLE, DWORD);
WINBASEAPI DWORD WINAPI GetPriorityClass(HANDLE);

WINBASEAPI BOOL WINAPI IsBadReadPtr(CONST VOID *, UINT_PTR);
WINBASEAPI BOOL WINAPI IsBadWritePtr(LPVOID, UINT_PTR);
WINBASEAPI BOOL WINAPI IsBadHugeReadPtr(CONST VOID *, UINT_PTR);
WINBASEAPI BOOL WINAPI IsBadHugeWritePtr(LPVOID, UINT_PTR);
WINBASEAPI BOOL WINAPI IsBadCodePtr(FARPROC);
WINBASEAPI BOOL WINAPI IsBadStringPtrA(LPCSTR, UINT_PTR);
WINBASEAPI BOOL WINAPI IsBadStringPtrW(LPCWSTR, UINT_PTR);
#ifdef UNICODE
#define IsBadStringPtr  IsBadStringPtrW
#else /* !UNICODE */
#define IsBadStringPtr  IsBadStringPtrA
#endif /* !UNICODE */

WINADVAPI BOOL WINAPI LookupAccountSidA(LPCSTR, PSID, LPSTR, LPDWORD, LPSTR, LPDWORD, PSID_NAME_USE);
WINADVAPI BOOL WINAPI LookupAccountSidW(LPCWSTR, PSID, LPWSTR, LPDWORD, LPWSTR, LPDWORD, PSID_NAME_USE);
WINADVAPI BOOL WINAPI LookupAccountSidLocalA(PSID, LPSTR, LPDWORD, LPSTR, LPDWORD, PSID_NAME_USE);
WINADVAPI BOOL WINAPI LookupAccountSidLocalW(PSID, LPWSTR, LPDWORD, LPWSTR, LPDWORD, PSID_NAME_USE);
WINADVAPI BOOL WINAPI LookupAccountNameA(LPCSTR, LPCSTR, PSID, LPDWORD, LPSTR, LPDWORD, PSID_NAME_USE);
WINADVAPI BOOL WINAPI LookupAccountNameW(LPCWSTR, LPCWSTR, PSID, LPDWORD, LPWSTR, LPDWORD, PSID_NAME_USE);
WINADVAPI BOOL WINAPI LookupAccountNameLocalA(LPCSTR, PSID, LPDWORD, LPSTR, LPDWORD, PSID_NAME_USE);
WINADVAPI BOOL WINAPI LookupAccountNameLocalW(LPCWSTR, PSID, LPDWORD, LPWSTR, LPDWORD, PSID_NAME_USE);
WINADVAPI BOOL WINAPI LookupPrivilegeValueA(LPCSTR, LPCSTR, PLUID);
WINADVAPI BOOL WINAPI LookupPrivilegeValueW(LPCWSTR, LPCWSTR, PLUID);
WINADVAPI BOOL WINAPI LookupPrivilegeNameA(LPCSTR, PLUID, LPSTR, LPDWORD);
WINADVAPI BOOL WINAPI LookupPrivilegeNameW(LPCWSTR, PLUID, LPWSTR, LPDWORD);
WINADVAPI BOOL WINAPI LookupPrivilegeDisplayNameA(LPCSTR, LPCSTR, LPSTR, LPDWORD, LPDWORD);
WINADVAPI BOOL WINAPI LookupPrivilegeDisplayNameW(LPCWSTR, LPCWSTR, LPWSTR, LPDWORD, LPDWORD);
WINADVAPI BOOL WINAPI AllocateLocallyUniqueId(PLUID);

#ifdef UNICODE
#define LookupAccountSid  LookupAccountSidW
#define LookupAccountSidLocal  LookupAccountSidLocalW
#define LookupAccountName  LookupAccountNameW
#define LookupAccountNameLocal  LookupAccountNameLocalW
#define LookupPrivilegeValue  LookupPrivilegeValueW
#define LookupPrivilegeName  LookupPrivilegeNameW
#define LookupPrivilegeDisplayName  LookupPrivilegeDisplayNameW
#else /* !UNICODE */
#define LookupAccountSid  LookupAccountSidA
#define LookupAccountSidLocal  LookupAccountSidLocalA
#define LookupAccountName  LookupAccountNameA
#define LookupAccountNameLocal  LookupAccountNameLocalA
#define LookupPrivilegeValue  LookupPrivilegeValueA
#define LookupPrivilegeName  LookupPrivilegeNameA
#define LookupPrivilegeDisplayName  LookupPrivilegeDisplayNameA
#endif /* !UNICODE */

WINBASEAPI BOOL WINAPI BuildCommDCBA(LPCSTR, LPDCB);
WINBASEAPI BOOL WINAPI BuildCommDCBW(LPCWSTR, LPDCB);
WINBASEAPI BOOL WINAPI BuildCommDCBAndTimeoutsA(LPCSTR, LPDCB, LPCOMMTIMEOUTS);
WINBASEAPI BOOL WINAPI BuildCommDCBAndTimeoutsW(LPCWSTR, LPDCB, LPCOMMTIMEOUTS);
WINBASEAPI BOOL WINAPI CommConfigDialogA(LPCSTR, HWND, LPCOMMCONFIG);
WINBASEAPI BOOL WINAPI CommConfigDialogW(LPCWSTR, HWND, LPCOMMCONFIG);
WINBASEAPI BOOL WINAPI GetDefaultCommConfigA(LPCSTR, LPCOMMCONFIG, LPDWORD);
WINBASEAPI BOOL WINAPI GetDefaultCommConfigW(LPCWSTR, LPCOMMCONFIG, LPDWORD);
WINBASEAPI BOOL WINAPI SetDefaultCommConfigA(LPCSTR, LPCOMMCONFIG, DWORD);
WINBASEAPI BOOL WINAPI SetDefaultCommConfigW(LPCWSTR, LPCOMMCONFIG, DWORD);

#ifdef UNICODE
#define BuildCommDCB  BuildCommDCBW
#define BuildCommDCBAndTimeouts  BuildCommDCBAndTimeoutsW
#define CommConfigDialog  CommConfigDialogW
#define GetDefaultCommConfig  GetDefaultCommConfigW
#define SetDefaultCommConfig  SetDefaultCommConfigW
#else /* !UNICODE */
#define BuildCommDCB  BuildCommDCBA
#define BuildCommDCBAndTimeouts  BuildCommDCBAndTimeoutsA
#define CommConfigDialog  CommConfigDialogA
#define GetDefaultCommConfig  GetDefaultCommConfigA
#define SetDefaultCommConfig  SetDefaultCommConfigA
#endif /* !UNICODE */

#define MAX_COMPUTERNAME_LENGTH  15

WINBASEAPI BOOL WINAPI GetComputerNameA(LPSTR, LPDWORD);
WINBASEAPI BOOL WINAPI GetComputerNameW(LPWSTR, LPDWORD);
WINBASEAPI BOOL WINAPI SetComputerNameA(LPCSTR);
WINBASEAPI BOOL WINAPI SetComputerNameW(LPCWSTR);

#ifdef UNICODE
#define GetComputerName  GetComputerNameW
#define SetComputerName  SetComputerNameW
#else /* !UNICODE */
#define GetComputerName  GetComputerNameA
#define SetComputerName  SetComputerNameA
#endif /* !UNICODE */

#if (_WIN32_WINNT >= 0x0500)

typedef enum _COMPUTER_NAME_FORMAT {
    ComputerNameNetBIOS,
    ComputerNameDnsHostname,
    ComputerNameDnsDomain,
    ComputerNameDnsFullyQualified,
    ComputerNamePhysicalNetBIOS,
    ComputerNamePhysicalDnsHostname,
    ComputerNamePhysicalDnsDomain,
    ComputerNamePhysicalDnsFullyQualified,
    ComputerNameMax
} COMPUTER_NAME_FORMAT;

WINBASEAPI BOOL WINAPI GetComputerNameExA(COMPUTER_NAME_FORMAT, LPSTR, LPDWORD);
WINBASEAPI BOOL WINAPI GetComputerNameExW(COMPUTER_NAME_FORMAT, LPWSTR, LPDWORD);
WINBASEAPI BOOL WINAPI SetComputerNameExA(COMPUTER_NAME_FORMAT, LPCSTR);
WINBASEAPI BOOL WINAPI SetComputerNameExW(COMPUTER_NAME_FORMAT, LPCWSTR);
WINBASEAPI BOOL WINAPI DnsHostnameToComputerNameA(LPCSTR, LPSTR, LPDWORD);
WINBASEAPI BOOL WINAPI DnsHostnameToComputerNameW(LPCWSTR, LPWSTR, LPDWORD);

#ifdef UNICODE
#define GetComputerNameEx  GetComputerNameExW
#define SetComputerNameEx  SetComputerNameExW
#define DnsHostnameToComputerName  DnsHostnameToComputerNameW
#else /* !UNICODE */
#define GetComputerNameEx  GetComputerNameExA
#define SetComputerNameEx  SetComputerNameExA
#define DnsHostnameToComputerName  DnsHostnameToComputerNameA
#endif /* !UNICODE */

#endif /* _WIN32_WINNT >= 0x0500 */

WINADVAPI BOOL WINAPI GetUserNameA(LPSTR, LPDWORD);
WINADVAPI BOOL WINAPI GetUserNameW(LPWSTR, LPDWORD);

#ifdef UNICODE
#define GetUserName  GetUserNameW
#else /* !UNICODE */
#define GetUserName  GetUserNameA
#endif /* !UNICODE */

#define LOGON32_LOGON_INTERACTIVE  2
#define LOGON32_LOGON_NETWORK  3
#define LOGON32_LOGON_BATCH  4
#define LOGON32_LOGON_SERVICE  5
#define LOGON32_LOGON_UNLOCK  7
#if (_WIN32_WINNT >= 0x0500)
#define LOGON32_LOGON_NETWORK_CLEARTEXT  8
#define LOGON32_LOGON_NEW_CREDENTIALS  9
#endif /* _WIN32_WINNT >= 0x0500 */

#define LOGON32_PROVIDER_DEFAULT  0
#define LOGON32_PROVIDER_WINNT35  1
#if (_WIN32_WINNT >= 0x0400)
#define LOGON32_PROVIDER_WINNT40  2
#endif /* _WIN32_WINNT >= 0x0400 */
#if (_WIN32_WINNT >= 0x0500)
#define LOGON32_PROVIDER_WINNT50  3
#endif /* _WIN32_WINNT >= 0x0500 */
#if (_WIN32_WINNT >= 0x0600)
#define LOGON32_PROVIDER_VIRTUAL  4
#endif /* _WIN32_WINNT >= 0x0600 */

WINADVAPI BOOL WINAPI LogonUserA(LPCSTR, LPCSTR, LPCSTR, DWORD, DWORD, PHANDLE);
WINADVAPI BOOL WINAPI LogonUserW(LPCWSTR, LPCWSTR, LPCWSTR, DWORD, DWORD, PHANDLE);
WINADVAPI BOOL WINAPI LogonUserExA(LPCSTR, LPCSTR, LPCSTR, DWORD, DWORD, PHANDLE, PSID *, PVOID *, LPDWORD, PQUOTA_LIMITS);
WINADVAPI BOOL WINAPI LogonUserExW(LPCWSTR, LPCWSTR, LPCWSTR, DWORD, DWORD, PHANDLE, PSID *, PVOID *, LPDWORD, PQUOTA_LIMITS);
WINADVAPI BOOL WINAPI ImpersonateLoggedOnUser(HANDLE hToken);
WINADVAPI BOOL WINAPI CreateProcessAsUserA(HANDLE, LPCSTR, LPSTR, LPSECURITY_ATTRIBUTES, LPSECURITY_ATTRIBUTES, BOOL, DWORD, LPVOID, LPCSTR, LPSTARTUPINFOA, LPPROCESS_INFORMATION);
WINADVAPI BOOL WINAPI CreateProcessAsUserW(HANDLE, LPCWSTR, LPWSTR, LPSECURITY_ATTRIBUTES, LPSECURITY_ATTRIBUTES, BOOL, DWORD, LPVOID, LPCWSTR, LPSTARTUPINFOW, LPPROCESS_INFORMATION);

#ifdef UNICODE
#define LogonUser  LogonUserW
#define LogonUserEx  LogonUserExW
#define CreateProcessAsUser  CreateProcessAsUserW
#else /* !UNICODE */
#define LogonUser  LogonUserA
#define LogonUserEx  LogonUserExA
#define CreateProcessAsUser  CreateProcessAsUserA
#endif /* !UNICODE */

#if (_WIN32_WINNT >= 0x0500)
#define LOGON_WITH_PROFILE  0x00000001
#define LOGON_NETCREDENTIALS_ONLY  0x00000002
#define LOGON_ZERO_PASSWORD_BUFFER  0x80000000

WINADVAPI BOOL WINAPI CreateProcessWithLogonW(LPCWSTR, LPCWSTR, LPCWSTR, DWORD, LPCWSTR, LPWSTR, DWORD, LPVOID, LPCWSTR, LPSTARTUPINFOW, LPPROCESS_INFORMATION);
WINADVAPI BOOL WINAPI CreateProcessWithTokenW(HANDLE, DWORD, LPCWSTR, LPWSTR, DWORD, LPVOID, LPCWSTR, LPSTARTUPINFOW, LPPROCESS_INFORMATION);
#endif /* _WIN32_WINNT >= 0x0500 */

WINADVAPI BOOL APIENTRY ImpersonateAnonymousToken(HANDLE);
WINADVAPI BOOL WINAPI DuplicateTokenEx(HANDLE, DWORD, LPSECURITY_ATTRIBUTES, SECURITY_IMPERSONATION_LEVEL, TOKEN_TYPE, PHANDLE);
WINADVAPI BOOL APIENTRY CreateRestrictedToken(HANDLE, DWORD, DWORD, PSID_AND_ATTRIBUTES, DWORD, PLUID_AND_ATTRIBUTES, DWORD, PSID_AND_ATTRIBUTES, PHANDLE);
WINADVAPI BOOL WINAPI IsTokenRestricted(HANDLE);
WINADVAPI BOOL WINAPI IsTokenUntrusted(HANDLE);
WINADVAPI BOOL APIENTRY CheckTokenMembership(HANDLE, PSID, PBOOL);

#if (_WIN32_WINNT >= 0x0500)

typedef WAITORTIMERCALLBACKFUNC WAITORTIMERCALLBACK;

WINBASEAPI BOOL WINAPI RegisterWaitForSingleObject(PHANDLE, HANDLE, WAITORTIMERCALLBACK, PVOID, ULONG, ULONG);
WINBASEAPI HANDLE WINAPI RegisterWaitForSingleObjectEx(HANDLE, WAITORTIMERCALLBACK, PVOID, ULONG, ULONG);
WINBASEAPI BOOL WINAPI UnregisterWait(HANDLE);
WINBASEAPI BOOL WINAPI UnregisterWaitEx(HANDLE, HANDLE);
WINBASEAPI BOOL WINAPI QueueUserWorkItem(LPTHREAD_START_ROUTINE, PVOID, ULONG);
WINBASEAPI BOOL WINAPI BindIoCompletionCallback(HANDLE, LPOVERLAPPED_COMPLETION_ROUTINE, ULONG);
WINBASEAPI HANDLE WINAPI CreateTimerQueue(VOID);
WINBASEAPI BOOL WINAPI CreateTimerQueueTimer(PHANDLE, HANDLE, WAITORTIMERCALLBACK, PVOID, DWORD, DWORD, ULONG);
WINBASEAPI BOOL WINAPI ChangeTimerQueueTimer(HANDLE, HANDLE, ULONG, ULONG);
WINBASEAPI BOOL WINAPI DeleteTimerQueueTimer(HANDLE, HANDLE, HANDLE);
WINBASEAPI BOOL WINAPI DeleteTimerQueueEx(HANDLE, HANDLE);
WINBASEAPI HANDLE WINAPI SetTimerQueueTimer(HANDLE, WAITORTIMERCALLBACK, PVOID, DWORD, DWORD, BOOL);
WINBASEAPI BOOL WINAPI CancelTimerQueueTimer(HANDLE, HANDLE);
WINBASEAPI BOOL WINAPI DeleteTimerQueue(HANDLE);

#if (_WIN32_WINNT >= 0x0600)

typedef VOID(WINAPI *PTP_WIN32_IO_CALLBACK) (PTP_CALLBACK_INSTANCE, PVOID, PVOID, ULONG, ULONG_PTR, PTP_IO);

WINBASEAPI PTP_POOL WINAPI CreateThreadpool(PVOID);
WINBASEAPI VOID WINAPI SetThreadpoolThreadMaximum(PTP_POOL, DWORD);
WINBASEAPI BOOL WINAPI SetThreadpoolThreadMinimum(PTP_POOL, DWORD);
WINBASEAPI BOOL WINAPI SetThreadpoolStackInformation(PTP_POOL, PTP_POOL_STACK_INFORMATION);
WINBASEAPI BOOL WINAPI QueryThreadpoolStackInformation(PTP_POOL, PTP_POOL_STACK_INFORMATION);
WINBASEAPI VOID WINAPI CloseThreadpool(PTP_POOL);
WINBASEAPI PTP_CLEANUP_GROUP WINAPI CreateThreadpoolCleanupGroup(VOID);
WINBASEAPI VOID WINAPI CloseThreadpoolCleanupGroupMembers(PTP_CLEANUP_GROUP, BOOL, PVOID);
WINBASEAPI VOID WINAPI CloseThreadpoolCleanupGroup(PTP_CLEANUP_GROUP);

FORCEINLINE VOID InitializeThreadpoolEnvironment(PTP_CALLBACK_ENVIRON pcbe) {
    TpInitializeCallbackEnviron(pcbe);
}

FORCEINLINE VOID SetThreadpoolCallbackPool(PTP_CALLBACK_ENVIRON pcbe, PTP_POOL ptpp) {
    TpSetCallbackThreadpool(pcbe, ptpp);
}

FORCEINLINE VOID SetThreadpoolCallbackCleanupGroup(PTP_CALLBACK_ENVIRON pcbe, PTP_CLEANUP_GROUP ptpcg, PTP_CLEANUP_GROUP_CANCEL_CALLBACK pfng) {
    TpSetCallbackCleanupGroup(pcbe, ptpcg, pfng);
}

FORCEINLINE VOID SetThreadpoolCallbackRunsLong(PTP_CALLBACK_ENVIRON pcbe) {
    TpSetCallbackLongFunction(pcbe);
}

FORCEINLINE VOID SetThreadpoolCallbackLibrary(PTP_CALLBACK_ENVIRON pcbe, PVOID mod) {
    TpSetCallbackRaceWithDll(pcbe, mod);
}

#if (_WIN32_WINNT >= _WIN32_WINNT_WIN7)
FORCEINLINE VOID SetThreadpoolCallbackPriority(PTP_CALLBACK_ENVIRON pcbe, TP_CALLBACK_PRIORITY Priority) {
    TpSetCallbackPriority(pcbe, Priority);
}
#endif /* _WIN32_WINNT >= _WIN32_WINNT_WIN7 */

FORCEINLINE VOID SetThreadpoolCallbackPersistent(PTP_CALLBACK_ENVIRON pcbe) {
    TpSetCallbackPersistent(pcbe);
}

FORCEINLINE VOID DestroyThreadpoolEnvironment(PTP_CALLBACK_ENVIRON pcbe) {
    TpDestroyCallbackEnviron(pcbe);
}

WINBASEAPI VOID WINAPI SetEventWhenCallbackReturns(PTP_CALLBACK_INSTANCE, HANDLE);
WINBASEAPI VOID WINAPI ReleaseSemaphoreWhenCallbackReturns(PTP_CALLBACK_INSTANCE, HANDLE, DWORD);
WINBASEAPI VOID WINAPI ReleaseMutexWhenCallbackReturns(PTP_CALLBACK_INSTANCE, HANDLE);
WINBASEAPI VOID WINAPI LeaveCriticalSectionWhenCallbackReturns(PTP_CALLBACK_INSTANCE, PCRITICAL_SECTION);
WINBASEAPI VOID WINAPI FreeLibraryWhenCallbackReturns(PTP_CALLBACK_INSTANCE, HMODULE);
WINBASEAPI BOOL WINAPI CallbackMayRunLong(PTP_CALLBACK_INSTANCE);
WINBASEAPI VOID WINAPI DisassociateCurrentThreadFromCallback(PTP_CALLBACK_INSTANCE);
WINBASEAPI BOOL WINAPI TrySubmitThreadpoolCallback(PTP_SIMPLE_CALLBACK, PVOID, PTP_CALLBACK_ENVIRON);
WINBASEAPI PTP_WORK WINAPI CreateThreadpoolWork(PTP_WORK_CALLBACK, PVOID, PTP_CALLBACK_ENVIRON);
WINBASEAPI VOID WINAPI SubmitThreadpoolWork(PTP_WORK);
WINBASEAPI VOID WINAPI WaitForThreadpoolWorkCallbacks(PTP_WORK, BOOL);
WINBASEAPI VOID WINAPI CloseThreadpoolWork(PTP_WORK);
WINBASEAPI PTP_TIMER WINAPI CreateThreadpoolTimer(PTP_TIMER_CALLBACK, PVOID, PTP_CALLBACK_ENVIRON);
WINBASEAPI VOID WINAPI SetThreadpoolTimer(PTP_TIMER, PFILETIME, DWORD, DWORD);
WINBASEAPI BOOL WINAPI IsThreadpoolTimerSet(PTP_TIMER);
WINBASEAPI VOID WINAPI WaitForThreadpoolTimerCallbacks(PTP_TIMER, BOOL);
WINBASEAPI VOID WINAPI CloseThreadpoolTimer(PTP_TIMER);
WINBASEAPI PTP_WAIT WINAPI CreateThreadpoolWait(PTP_WAIT_CALLBACK, PVOID, PTP_CALLBACK_ENVIRON);
WINBASEAPI VOID WINAPI SetThreadpoolWait(PTP_WAIT, HANDLE, PFILETIME);
WINBASEAPI VOID WINAPI WaitForThreadpoolWaitCallbacks(PTP_WAIT, BOOL);
WINBASEAPI VOID WINAPI CloseThreadpoolWait(PTP_WAIT);
WINBASEAPI PTP_IO WINAPI CreateThreadpoolIo(HANDLE, PTP_WIN32_IO_CALLBACK, PVOID, PTP_CALLBACK_ENVIRON);
WINBASEAPI VOID WINAPI StartThreadpoolIo(PTP_IO);
WINBASEAPI VOID WINAPI CancelThreadpoolIo(PTP_IO);
WINBASEAPI VOID WINAPI WaitForThreadpoolIoCallbacks(PTP_IO, BOOL);
WINBASEAPI VOID WINAPI CloseThreadpoolIo(PTP_IO);

#define PRIVATE_NAMESPACE_FLAG_DESTROY  0x00000001

WINBASEAPI HANDLE WINAPI CreatePrivateNamespaceA(LPSECURITY_ATTRIBUTES, LPVOID, LPCSTR);
WINBASEAPI HANDLE WINAPI CreatePrivateNamespaceW(LPSECURITY_ATTRIBUTES, LPVOID, LPCWSTR);
WINBASEAPI HANDLE WINAPI OpenPrivateNamespaceA(LPVOID, LPCSTR);
WINBASEAPI HANDLE WINAPI OpenPrivateNamespaceW(LPVOID, LPCWSTR);
WINBASEAPI BOOLEAN WINAPI ClosePrivateNamespace(HANDLE, ULONG);

#ifdef UNICODE
#define CreatePrivateNamespace  CreatePrivateNamespaceW
#define OpenPrivateNamespace  OpenPrivateNamespaceW
#else /* !UNICODE */
#define CreatePrivateNamespace  CreatePrivateNamespaceA
#define OpenPrivateNamespace  OpenPrivateNamespaceA
#endif /* !UNICODE */

WINBASEAPI HANDLE APIENTRY CreateBoundaryDescriptorA(LPCSTR, ULONG);
WINBASEAPI HANDLE APIENTRY CreateBoundaryDescriptorW(LPCWSTR, ULONG);
WINBASEAPI BOOL WINAPI AddSIDToBoundaryDescriptor(HANDLE *, PSID);
WINBASEAPI BOOL WINAPI AddIntegrityLabelToBoundaryDescriptor(HANDLE *, PSID);
WINBASEAPI VOID WINAPI DeleteBoundaryDescriptor(HANDLE);

#ifdef UNICODE
#define CreateBoundaryDescriptor  CreateBoundaryDescriptorW
#else /* !UNICODE */
#define CreateBoundaryDescriptor  CreateBoundaryDescriptorA
#endif /* !UNICODE */

#endif /* _WIN32_WINNT >= 0x0600 */
#endif /* _WIN32_WINNT >= 0x0500 */

#if (_WIN32_WINNT >= 0x0400)

#define HW_PROFILE_GUIDLEN  39
#define MAX_PROFILE_LEN  80

#define DOCKINFO_UNDOCKED  (0x1)
#define DOCKINFO_DOCKED  (0x2)
#define DOCKINFO_USER_SUPPLIED  (0x4)
#define DOCKINFO_USER_UNDOCKED  (DOCKINFO_USER_SUPPLIED|DOCKINFO_UNDOCKED)
#define DOCKINFO_USER_DOCKED  (DOCKINFO_USER_SUPPLIED|DOCKINFO_DOCKED)

typedef struct tagHW_PROFILE_INFOA {
    DWORD dwDockInfo;
    CHAR szHwProfileGuid[HW_PROFILE_GUIDLEN];
    CHAR szHwProfileName[MAX_PROFILE_LEN];
} HW_PROFILE_INFOA , *LPHW_PROFILE_INFOA;

typedef struct tagHW_PROFILE_INFOW {
    DWORD dwDockInfo;
    WCHAR szHwProfileGuid[HW_PROFILE_GUIDLEN];
    WCHAR szHwProfileName[MAX_PROFILE_LEN];
} HW_PROFILE_INFOW , *LPHW_PROFILE_INFOW;

WINADVAPI BOOL WINAPI GetCurrentHwProfileA(LPHW_PROFILE_INFOA);
WINADVAPI BOOL WINAPI GetCurrentHwProfileW(LPHW_PROFILE_INFOW);

#ifdef UNICODE
typedef HW_PROFILE_INFOW HW_PROFILE_INFO;
typedef LPHW_PROFILE_INFOW LPHW_PROFILE_INFO;
#define GetCurrentHwProfile  GetCurrentHwProfileW
#else /* !UNICODE */
typedef HW_PROFILE_INFOA HW_PROFILE_INFO;
typedef LPHW_PROFILE_INFOA LPHW_PROFILE_INFO;
#define GetCurrentHwProfile  GetCurrentHwProfileA
#endif /* !UNICODE */

#endif /* _WIN32_WINNT >= 0x0400 */

WINBASEAPI BOOL WINAPI QueryPerformanceCounter(LARGE_INTEGER *);
WINBASEAPI BOOL WINAPI QueryPerformanceFrequency(LARGE_INTEGER *);

WINBASEAPI BOOL WINAPI GetVersionExA(LPOSVERSIONINFOA);
WINBASEAPI BOOL WINAPI GetVersionExW(LPOSVERSIONINFOW);
WINBASEAPI BOOL WINAPI VerifyVersionInfoA(LPOSVERSIONINFOEXA, DWORD, DWORDLONG);
WINBASEAPI BOOL WINAPI VerifyVersionInfoW(LPOSVERSIONINFOEXW, DWORD, DWORDLONG);
#if (_WIN32_WINNT >= 0x0600)
WINBASEAPI BOOL WINAPI GetProductInfo(DWORD, DWORD, DWORD, DWORD, PDWORD);
#endif /* _WIN32_WINNT >= 0x0600 */

#ifdef UNICODE
#define GetVersionEx  GetVersionExW
#define VerifyVersionInfo  VerifyVersionInfoW
#else /* !UNICODE */
#define GetVersionEx  GetVersionExA
#define VerifyVersionInfo  VerifyVersionInfoA
#endif /* !UNICODE */

#include <winerror.h>

#define TC_NORMAL  0
#define TC_HARDERR  1
#define TC_GP_TRAP  2
#define TC_SIGNAL  3

#if (WINVER >= 0x0400)

#define AC_LINE_OFFLINE  0x00
#define AC_LINE_ONLINE  0x01
#define AC_LINE_BACKUP_POWER  0x02
#define AC_LINE_UNKNOWN  0xFF

#define BATTERY_FLAG_HIGH  0x01
#define BATTERY_FLAG_LOW  0x02
#define BATTERY_FLAG_CRITICAL  0x04
#define BATTERY_FLAG_CHARGING  0x08
#define BATTERY_FLAG_NO_BATTERY  0x80
#define BATTERY_FLAG_UNKNOWN  0xFF

#define BATTERY_PERCENTAGE_UNKNOWN  0xFF

#define BATTERY_LIFE_UNKNOWN  0xFFFFFFFF

typedef struct _SYSTEM_POWER_STATUS {
    BYTE ACLineStatus;
    BYTE BatteryFlag;
    BYTE BatteryLifePercent;
    BYTE Reserved1;
    DWORD BatteryLifeTime;
    DWORD BatteryFullLifeTime;
} SYSTEM_POWER_STATUS, *LPSYSTEM_POWER_STATUS;

WINBASEAPI BOOL WINAPI GetSystemPowerStatus(LPSYSTEM_POWER_STATUS);
WINBASEAPI BOOL WINAPI SetSystemPowerState(BOOL, BOOL);

#endif /* WINVER >= 0x0400 */

#if (_WIN32_WINNT >= 0x0500)

WINBASEAPI BOOL WINAPI AllocateUserPhysicalPages(HANDLE, PULONG_PTR, PULONG_PTR);
#if (_WIN32_WINNT >= 0x0600)
WINBASEAPI BOOL WINAPI AllocateUserPhysicalPagesNuma(HANDLE, PULONG_PTR, PULONG_PTR, DWORD);
#endif /* _WIN32_WINNT >= 0x0600 */

WINBASEAPI BOOL WINAPI FreeUserPhysicalPages(HANDLE, PULONG_PTR, PULONG_PTR);
WINBASEAPI BOOL WINAPI MapUserPhysicalPages(PVOID, ULONG_PTR, PULONG_PTR);
WINBASEAPI BOOL WINAPI MapUserPhysicalPagesScatter(PVOID *, ULONG_PTR, PULONG_PTR);

WINBASEAPI HANDLE WINAPI CreateJobObjectA(LPSECURITY_ATTRIBUTES, LPCSTR);
WINBASEAPI HANDLE WINAPI CreateJobObjectW(LPSECURITY_ATTRIBUTES, LPCWSTR);
WINBASEAPI HANDLE WINAPI OpenJobObjectA(DWORD, BOOL, LPCSTR);
WINBASEAPI HANDLE WINAPI OpenJobObjectW(DWORD, BOOL, LPCWSTR);
WINBASEAPI BOOL WINAPI AssignProcessToJobObject(HANDLE, HANDLE);
WINBASEAPI BOOL WINAPI TerminateJobObject(HANDLE, UINT);
WINBASEAPI BOOL WINAPI QueryInformationJobObject(HANDLE hJob, JOBOBJECTINFOCLASS, LPVOID, DWORD, LPDWORD);
WINBASEAPI BOOL WINAPI SetInformationJobObject(HANDLE, JOBOBJECTINFOCLASS, LPVOID, DWORD);
#if (_WIN32_WINNT >= 0x0501)
WINBASEAPI BOOL WINAPI IsProcessInJob(HANDLE, HANDLE, PBOOL);
#endif /* _WIN32_WINNT >= 0x0501 */
WINBASEAPI BOOL WINAPI CreateJobSet(ULONG, PJOB_SET_ARRAY, ULONG);

#ifdef UNICODE
#define CreateJobObject  CreateJobObjectW
#define OpenJobObject  OpenJobObjectW
#else /* !UNICODE */
#define CreateJobObject  CreateJobObjectA
#define OpenJobObject  OpenJobObjectA
#endif /* !UNICODE */

WINBASEAPI PVOID WINAPI AddVectoredExceptionHandler(ULONG, PVECTORED_EXCEPTION_HANDLER);
WINBASEAPI ULONG WINAPI RemoveVectoredExceptionHandler(PVOID);
WINBASEAPI PVOID WINAPI AddVectoredContinueHandler(ULONG, PVECTORED_EXCEPTION_HANDLER);
WINBASEAPI ULONG WINAPI RemoveVectoredContinueHandler(PVOID);

WINBASEAPI HANDLE WINAPI FindFirstVolumeA(LPSTR, DWORD);
WINBASEAPI HANDLE WINAPI FindFirstVolumeW(LPWSTR, DWORD);
WINBASEAPI BOOL WINAPI FindNextVolumeA(HANDLE, LPSTR, DWORD);
WINBASEAPI BOOL WINAPI FindNextVolumeW(HANDLE, LPWSTR, DWORD);
WINBASEAPI BOOL WINAPI FindVolumeClose(HANDLE);
WINBASEAPI HANDLE WINAPI FindFirstVolumeMountPointA(LPCSTR, LPSTR, DWORD);
WINBASEAPI HANDLE WINAPI FindFirstVolumeMountPointW(LPCWSTR, LPWSTR, DWORD);
WINBASEAPI BOOL WINAPI FindNextVolumeMountPointA(HANDLE, LPSTR, DWORD);
WINBASEAPI BOOL WINAPI FindNextVolumeMountPointW(HANDLE, LPWSTR, DWORD);
WINBASEAPI BOOL WINAPI FindVolumeMountPointClose(HANDLE);
WINBASEAPI BOOL WINAPI SetVolumeMountPointA(LPCSTR, LPCSTR);
WINBASEAPI BOOL WINAPI SetVolumeMountPointW(LPCWSTR, LPCWSTR);
WINBASEAPI BOOL WINAPI DeleteVolumeMountPointA(LPCSTR);
WINBASEAPI BOOL WINAPI DeleteVolumeMountPointW(LPCWSTR);
WINBASEAPI BOOL WINAPI GetVolumeNameForVolumeMountPointA(LPCSTR, LPSTR, DWORD);
WINBASEAPI BOOL WINAPI GetVolumeNameForVolumeMountPointW(LPCWSTR, LPWSTR, DWORD);
WINBASEAPI BOOL WINAPI GetVolumePathNameA(LPCSTR, LPSTR, DWORD);
WINBASEAPI BOOL WINAPI GetVolumePathNameW(LPCWSTR, LPWSTR, DWORD);

#if (_WIN32_WINNT >= 0x0501)
WINBASEAPI BOOL WINAPI GetVolumePathNamesForVolumeNameA(LPCSTR, LPCH, DWORD, PDWORD);
WINBASEAPI BOOL WINAPI GetVolumePathNamesForVolumeNameW(LPCWSTR, LPWCH, DWORD, PDWORD);
#ifdef UNICODE
#define GetVolumePathNamesForVolumeName  GetVolumePathNamesForVolumeNameW
#else /* !UNICODE */
#define GetVolumePathNamesForVolumeName  GetVolumePathNamesForVolumeNameA
#endif /* !UNICODE */
#endif /* _WIN32_WINNT >= 0x0501 */

#ifdef UNICODE
#define FindFirstVolume FindFirstVolumeW
#define FindNextVolume FindNextVolumeW
#define FindFirstVolumeMountPoint FindFirstVolumeMountPointW
#define FindNextVolumeMountPoint FindNextVolumeMountPointW
#define SetVolumeMountPoint  SetVolumeMountPointW
#define DeleteVolumeMountPoint  DeleteVolumeMountPointW
#define GetVolumeNameForVolumeMountPoint  GetVolumeNameForVolumeMountPointW
#define GetVolumePathName  GetVolumePathNameW
#else /* !UNICODE */
#define FindFirstVolume FindFirstVolumeA
#define FindNextVolume FindNextVolumeA
#define FindFirstVolumeMountPoint FindFirstVolumeMountPointA
#define FindNextVolumeMountPoint FindNextVolumeMountPointA
#define SetVolumeMountPoint  SetVolumeMountPointA
#define DeleteVolumeMountPoint  DeleteVolumeMountPointA
#define GetVolumeNameForVolumeMountPoint  GetVolumeNameForVolumeMountPointA
#define GetVolumePathName  GetVolumePathNameA
#endif /* !UNICODE */

#endif /* _WIN32_WINNT >= 0x0500 */

#if (_WIN32_WINNT >= 0x0500) || (_WIN32_FUSION >= 0x0100) || ISOLATION_AWARE_ENABLED

#define ACTCTX_FLAG_PROCESSOR_ARCHITECTURE_VALID  (0x00000001)
#define ACTCTX_FLAG_LANGID_VALID  (0x00000002)
#define ACTCTX_FLAG_ASSEMBLY_DIRECTORY_VALID  (0x00000004)
#define ACTCTX_FLAG_RESOURCE_NAME_VALID  (0x00000008)
#define ACTCTX_FLAG_SET_PROCESS_DEFAULT  (0x00000010)
#define ACTCTX_FLAG_APPLICATION_NAME_VALID  (0x00000020)
#define ACTCTX_FLAG_SOURCE_IS_ASSEMBLYREF  (0x00000040)
#define ACTCTX_FLAG_HMODULE_VALID  (0x00000080)

#define DEACTIVATE_ACTCTX_FLAG_FORCE_EARLY_DEACTIVATION  (0x00000001)

#define FIND_ACTCTX_SECTION_KEY_RETURN_HACTCTX  (0x00000001)
#define FIND_ACTCTX_SECTION_KEY_RETURN_FLAGS  (0x00000002)
#define FIND_ACTCTX_SECTION_KEY_RETURN_ASSEMBLY_METADATA  (0x00000004)

typedef struct tagACTCTXA {
    ULONG cbSize;
    DWORD dwFlags;
    LPCSTR lpSource;
    USHORT wProcessorArchitecture;
    LANGID wLangId;
    LPCSTR lpAssemblyDirectory;
    LPCSTR lpResourceName;
    LPCSTR lpApplicationName;
    HMODULE hModule;
} ACTCTXA, *PACTCTXA;
typedef const ACTCTXA *PCACTCTXA;

typedef struct tagACTCTXW {
    ULONG cbSize;
    DWORD dwFlags;
    LPCWSTR lpSource;
    USHORT wProcessorArchitecture;
    LANGID wLangId;
    LPCWSTR lpAssemblyDirectory;
    LPCWSTR lpResourceName;
    LPCWSTR lpApplicationName;
    HMODULE hModule;
} ACTCTXW, *PACTCTXW;
typedef const ACTCTXW *PCACTCTXW;

typedef struct tagACTCTX_SECTION_KEYED_DATA_2600 {
    ULONG cbSize;
    ULONG ulDataFormatVersion;
    PVOID lpData;
    ULONG ulLength;
    PVOID lpSectionGlobalData;
    ULONG ulSectionGlobalDataLength;
    PVOID lpSectionBase;
    ULONG ulSectionTotalLength;
    HANDLE hActCtx;
    ULONG ulAssemblyRosterIndex;
} ACTCTX_SECTION_KEYED_DATA_2600 , *PACTCTX_SECTION_KEYED_DATA_2600;
typedef const ACTCTX_SECTION_KEYED_DATA_2600 *PCACTCTX_SECTION_KEYED_DATA_2600;

typedef struct tagACTCTX_SECTION_KEYED_DATA_ASSEMBLY_METADATA {
    PVOID lpInformation;
    PVOID lpSectionBase;
    ULONG ulSectionLength;
    PVOID lpSectionGlobalDataBase;
    ULONG ulSectionGlobalDataLength;
} ACTCTX_SECTION_KEYED_DATA_ASSEMBLY_METADATA , *PACTCTX_SECTION_KEYED_DATA_ASSEMBLY_METADATA;
typedef const ACTCTX_SECTION_KEYED_DATA_ASSEMBLY_METADATA *PCACTCTX_SECTION_KEYED_DATA_ASSEMBLY_METADATA;

typedef struct tagACTCTX_SECTION_KEYED_DATA {
    ULONG cbSize;
    ULONG ulDataFormatVersion;
    PVOID lpData;
    ULONG ulLength;
    PVOID lpSectionGlobalData;
    ULONG ulSectionGlobalDataLength;
    PVOID lpSectionBase;
    ULONG ulSectionTotalLength;
    HANDLE hActCtx;
    ULONG ulAssemblyRosterIndex;
    ULONG ulFlags;
    ACTCTX_SECTION_KEYED_DATA_ASSEMBLY_METADATA AssemblyMetadata;
} ACTCTX_SECTION_KEYED_DATA , *PACTCTX_SECTION_KEYED_DATA;
typedef const ACTCTX_SECTION_KEYED_DATA *PCACTCTX_SECTION_KEYED_DATA;

WINBASEAPI HANDLE WINAPI CreateActCtxA(PCACTCTXA);
WINBASEAPI HANDLE WINAPI CreateActCtxW(PCACTCTXW);
WINBASEAPI VOID WINAPI AddRefActCtx(HANDLE);
WINBASEAPI VOID WINAPI ReleaseActCtx(HANDLE);
WINBASEAPI BOOL WINAPI ZombifyActCtx(HANDLE);
WINBASEAPI BOOL WINAPI ActivateActCtx(HANDLE, ULONG_PTR *);
WINBASEAPI BOOL WINAPI DeactivateActCtx(DWORD, ULONG_PTR);
WINBASEAPI BOOL WINAPI GetCurrentActCtx(HANDLE *);
WINBASEAPI BOOL WINAPI FindActCtxSectionStringA(DWORD, const GUID *, ULONG, LPCSTR, PACTCTX_SECTION_KEYED_DATA);
WINBASEAPI BOOL WINAPI FindActCtxSectionStringW(DWORD, const GUID *, ULONG, LPCWSTR, PACTCTX_SECTION_KEYED_DATA);
WINBASEAPI BOOL WINAPI FindActCtxSectionGuid(DWORD, const GUID *, ULONG, const GUID *, PACTCTX_SECTION_KEYED_DATA);

#ifdef UNICODE
typedef ACTCTXW ACTCTX;
typedef PACTCTXW PACTCTX;
typedef PCACTCTXW PCACTCTX;
#define CreateActCtx  CreateActCtxW
#define FindActCtxSectionString  FindActCtxSectionStringW
#else /* !UNICODE */
typedef ACTCTXA ACTCTX;
typedef PACTCTXA PACTCTX;
typedef PCACTCTXA PCACTCTX;
#define CreateActCtx  CreateActCtxA
#define FindActCtxSectionString  FindActCtxSectionStringA
#endif /* !UNICODE */

#ifndef ACTIVATION_CONTEXT_BASIC_INFORMATION_DEFINED
#define ACTIVATION_CONTEXT_BASIC_INFORMATION_DEFINED  1
typedef struct _ACTIVATION_CONTEXT_BASIC_INFORMATION {
    HANDLE  hActCtx;
    DWORD  dwFlags;
} ACTIVATION_CONTEXT_BASIC_INFORMATION, *PACTIVATION_CONTEXT_BASIC_INFORMATION;
typedef const struct _ACTIVATION_CONTEXT_BASIC_INFORMATION *PCACTIVATION_CONTEXT_BASIC_INFORMATION;
#endif /* !ACTIVATION_CONTEXT_BASIC_INFORMATION_DEFINED */

#define QUERY_ACTCTX_FLAG_USE_ACTIVE_ACTCTX  (0x00000004)
#define QUERY_ACTCTX_FLAG_ACTCTX_IS_HMODULE  (0x00000008)
#define QUERY_ACTCTX_FLAG_ACTCTX_IS_ADDRESS  (0x00000010)
#define QUERY_ACTCTX_FLAG_NO_ADDREF  (0x80000000)

WINBASEAPI BOOL WINAPI QueryActCtxW(DWORD, HANDLE, PVOID, ULONG, PVOID, SIZE_T, SIZE_T *);
typedef BOOL(WINAPI *PQUERYACTCTXW_FUNC)(DWORD, HANDLE, PVOID, ULONG, PVOID, SIZE_T, SIZE_T *);

#endif /* (_WIN32_WINNT >= 0x0500) || (_WIN32_FUSION >= 0x0100) || ISOLATION_AWARE_ENABLED */

WINBASEAPI BOOL WINAPI ProcessIdToSessionId(DWORD, DWORD *);
#if (_WIN32_WINNT >= 0x0501)
WINBASEAPI DWORD WINAPI WTSGetActiveConsoleSessionId(VOID);
WINBASEAPI BOOL WINAPI IsWow64Process(HANDLE, PBOOL);
#endif /* _WIN32_WINNT >= 0x0501 */

WINBASEAPI BOOL WINAPI GetLogicalProcessorInformation(PSYSTEM_LOGICAL_PROCESSOR_INFORMATION, PDWORD);
#if _WIN32_WINNT >= 0x0601
WINBASEAPI BOOL WINAPI GetLogicalProcessorInformationEx(LOGICAL_PROCESSOR_RELATIONSHIP, PSYSTEM_LOGICAL_PROCESSOR_INFORMATION_EX, PDWORD);
WINBASEAPI WORD WINAPI GetActiveProcessorGroupCount(VOID);
WINBASEAPI WORD WINAPI GetMaximumProcessorGroupCount(VOID);
WINBASEAPI DWORD WINAPI GetActiveProcessorCount(WORD);
WINBASEAPI DWORD WINAPI GetMaximumProcessorCount(WORD);
#endif /* _WIN32_WINNT >=0x0601 */

WINBASEAPI BOOL WINAPI GetNumaHighestNodeNumber(PULONG);
WINBASEAPI BOOL WINAPI GetNumaProcessorNode(UCHAR, PUCHAR);

#if (_WIN32_WINNT >= 0x0601)
WINBASEAPI BOOL WINAPI GetNumaNodeNumberFromHandle(HANDLE, PUSHORT);
WINBASEAPI BOOL WINAPI GetNumaProcessorNodeEx(PPROCESSOR_NUMBER, PUSHORT);
#endif /* _WIN32_WINNT >=0x0601 */
WINBASEAPI BOOL WINAPI GetNumaNodeProcessorMask(UCHAR, PULONGLONG);
#if (_WIN32_WINNT >= 0x0601)
WINBASEAPI BOOL WINAPI GetNumaNodeProcessorMaskEx(USHORT, PGROUP_AFFINITY);
#endif /* _WIN32_WINNT >=0x0601 */
WINBASEAPI BOOL WINAPI GetNumaAvailableMemoryNode(UCHAR, PULONGLONG);
#if (_WIN32_WINNT >= 0x0601)
WINBASEAPI BOOL WINAPI GetNumaAvailableMemoryNodeEx(USHORT, PULONGLONG);
#endif /* _WIN32_WINNT >=0x0601 */
#if (_WIN32_WINNT >= 0x0600)
WINBASEAPI BOOL WINAPI GetNumaProximityNode(ULONG, PUCHAR);
#endif /* _WIN32_WINNT >= 0x0600 */
#if (_WIN32_WINNT >= 0x0601)
WINBASEAPI BOOL WINAPI GetNumaProximityNodeEx(ULONG, PUSHORT);
#endif /* _WIN32_WINNT >=0x0601 */

typedef DWORD (WINAPI *APPLICATION_RECOVERY_CALLBACK)(PVOID);

#define RESTART_MAX_CMD_LINE  1024

#define RESTART_NO_CRASH  1
#define RESTART_NO_HANG  2
#define RESTART_NO_PATCH  4
#define RESTART_NO_REBOOT  8

WINBASEAPI HRESULT WINAPI RegisterApplicationRecoveryCallback(APPLICATION_RECOVERY_CALLBACK, PVOID, DWORD, DWORD);
WINBASEAPI HRESULT WINAPI UnregisterApplicationRecoveryCallback(void);
WINBASEAPI HRESULT WINAPI RegisterApplicationRestart(PCWSTR, DWORD);
WINBASEAPI HRESULT WINAPI UnregisterApplicationRestart(void);

#define RECOVERY_DEFAULT_PING_INTERVAL  5000
#define RECOVERY_MAX_PING_INTERVAL  (5 * 60 * 1000)

WINBASEAPI HRESULT WINAPI GetApplicationRecoveryCallback(HANDLE, APPLICATION_RECOVERY_CALLBACK *, PVOID *, PDWORD, PDWORD);
WINBASEAPI HRESULT WINAPI GetApplicationRestartSettings(HANDLE, PWSTR, PDWORD, PDWORD);
WINBASEAPI HRESULT WINAPI ApplicationRecoveryInProgress(PBOOL);
WINBASEAPI VOID WINAPI ApplicationRecoveryFinished(BOOL);

#if (_WIN32_WINNT >= 0x0600)

typedef enum _FILE_INFO_BY_HANDLE_CLASS {
    FileBasicInfo,
    FileStandardInfo,
    FileNameInfo,
    FileRenameInfo,
    FileDispositionInfo,
    FileAllocationInfo,
    FileEndOfFileInfo,
    FileStreamInfo,
    FileCompressionInfo,
    FileAttributeTagInfo,
    FileIdBothDirectoryInfo,
    FileIdBothDirectoryRestartInfo,
    FileIoPriorityHintInfo,
    FileRemoteProtocolInfo,
    MaximumFileInfoByHandleClass
} FILE_INFO_BY_HANDLE_CLASS, *PFILE_INFO_BY_HANDLE_CLASS;

typedef struct _FILE_BASIC_INFO {
    LARGE_INTEGER CreationTime;
    LARGE_INTEGER LastAccessTime;
    LARGE_INTEGER LastWriteTime;
    LARGE_INTEGER ChangeTime;
    DWORD FileAttributes;
} FILE_BASIC_INFO, *PFILE_BASIC_INFO;

typedef struct _FILE_STANDARD_INFO {
    LARGE_INTEGER AllocationSize;
    LARGE_INTEGER EndOfFile;
    DWORD NumberOfLinks;
    BOOLEAN DeletePending;
    BOOLEAN Directory;
} FILE_STANDARD_INFO, *PFILE_STANDARD_INFO;

typedef struct _FILE_NAME_INFO {
    DWORD FileNameLength;
    WCHAR FileName[1];
} FILE_NAME_INFO, *PFILE_NAME_INFO;

typedef struct _FILE_RENAME_INFO {
    BOOLEAN ReplaceIfExists;
    HANDLE RootDirectory;
    DWORD FileNameLength;
    WCHAR FileName[1];
} FILE_RENAME_INFO, *PFILE_RENAME_INFO;

typedef struct _FILE_ALLOCATION_INFO {
    LARGE_INTEGER AllocationSize;
} FILE_ALLOCATION_INFO, *PFILE_ALLOCATION_INFO;

typedef struct _FILE_END_OF_FILE_INFO {
    LARGE_INTEGER EndOfFile;
} FILE_END_OF_FILE_INFO, *PFILE_END_OF_FILE_INFO;

typedef struct _FILE_STREAM_INFO {
    DWORD NextEntryOffset;
    DWORD StreamNameLength;
    LARGE_INTEGER StreamSize;
    LARGE_INTEGER StreamAllocationSize;
    WCHAR StreamName[1];
} FILE_STREAM_INFO, *PFILE_STREAM_INFO;

typedef struct _FILE_COMPRESSION_INFO {
    LARGE_INTEGER CompressedFileSize;
    WORD CompressionFormat;
    UCHAR CompressionUnitShift;
    UCHAR ChunkShift;
    UCHAR ClusterShift;
    UCHAR Reserved[3];
} FILE_COMPRESSION_INFO, *PFILE_COMPRESSION_INFO;

typedef struct _FILE_ATTRIBUTE_TAG_INFO {
    DWORD FileAttributes;
    DWORD ReparseTag;
} FILE_ATTRIBUTE_TAG_INFO, *PFILE_ATTRIBUTE_TAG_INFO;

typedef struct _FILE_DISPOSITION_INFO {
    BOOLEAN DeleteFile;
} FILE_DISPOSITION_INFO, *PFILE_DISPOSITION_INFO;

typedef struct _FILE_ID_BOTH_DIR_INFO {
    DWORD NextEntryOffset;
    DWORD FileIndex;
    LARGE_INTEGER CreationTime;
    LARGE_INTEGER LastAccessTime;
    LARGE_INTEGER LastWriteTime;
    LARGE_INTEGER ChangeTime;
    LARGE_INTEGER EndOfFile;
    LARGE_INTEGER AllocationSize;
    DWORD FileAttributes;
    DWORD FileNameLength;
    DWORD EaSize;
    CCHAR ShortNameLength;
    WCHAR ShortName[12];
    LARGE_INTEGER FileId;
    WCHAR FileName[1];
} FILE_ID_BOTH_DIR_INFO, *PFILE_ID_BOTH_DIR_INFO;

typedef enum _PRIORITY_HINT {
    IoPriorityHintVeryLow = 0,
    IoPriorityHintLow,
    IoPriorityHintNormal,
    MaximumIoPriorityHintType
} PRIORITY_HINT;

typedef struct _FILE_IO_PRIORITY_HINT_INFO {
    PRIORITY_HINT PriorityHint;
} FILE_IO_PRIORITY_HINT_INFO, *PFILE_IO_PRIORITY_HINT_INFO;

#if (_WIN32_WINNT >= _WIN32_WINNT_WIN8)

typedef struct _FILE_ALIGNMENT_INFO {
    ULONG AlignmentRequirement;
} FILE_ALIGNMENT_INFO, *PFILE_ALIGNMENT_INFO;

#define STORAGE_INFO_FLAGS_ALIGNED_DEVICE  0x00000001
#define STORAGE_INFO_FLAGS_PARTITION_ALIGNED_ON_DEVICE  0x00000002

#define STORAGE_INFO_OFFSET_UNKNOWN  (0xffffffff)

typedef struct _FILE_STORAGE_INFO {
    ULONG LogicalBytesPerSector;
    ULONG PhysicalBytesPerSectorForAtomicity;
    ULONG PhysicalBytesPerSectorForPerformance;
    ULONG FileSystemEffectivePhysicalBytesPerSectorForAtomicity;
    ULONG Flags;
    ULONG ByteOffsetForSectorAlignment;
    ULONG ByteOffsetForPartitionAlignment;
} FILE_STORAGE_INFO, *PFILE_STORAGE_INFO;

typedef struct _FILE_ID_INFO {
    ULONGLONG VolumeSerialNumber;
    FILE_ID_128 FileId;
} FILE_ID_INFO, *PFILE_ID_INFO;

typedef struct _FILE_ID_EXTD_DIR_INFO {
    ULONG NextEntryOffset;
    ULONG FileIndex;
    LARGE_INTEGER CreationTime;
    LARGE_INTEGER LastAccessTime;
    LARGE_INTEGER LastWriteTime;
    LARGE_INTEGER ChangeTime;
    LARGE_INTEGER EndOfFile;
    LARGE_INTEGER AllocationSize;
    ULONG FileAttributes;
    ULONG FileNameLength;
    ULONG EaSize;
    ULONG ReparsePointTag;
    FILE_ID_128 FileId;
    WCHAR FileName[1];
} FILE_ID_EXTD_DIR_INFO, *PFILE_ID_EXTD_DIR_INFO;

#endif /* _WIN32_WINNT >= _WIN32_WINNT_WIN8 */

#define REMOTE_PROTOCOL_INFO_FLAG_LOOPBACK  0x00000001
#define REMOTE_PROTOCOL_INFO_FLAG_OFFLINE  0x00000002
#if (_WIN32_WINNT >= _WIN32_WINNT_WIN8)
#define REMOTE_PROTOCOL_INFO_FLAG_PERSISTENT_HANDLE  0x00000004
#endif /* _WIN32_WINNT >= _WIN32_WINNT_WIN8 */

#if (_WIN32_WINNT >= _WIN32_WINNT_WIN8)
#define RPI_FLAG_SMB2_SHARECAP_TIMEWARP  0x00000002
#define RPI_FLAG_SMB2_SHARECAP_DFS  0x00000008
#define RPI_FLAG_SMB2_SHARECAP_CONTINUOUS_AVAILABILITY  0x00000010
#define RPI_FLAG_SMB2_SHARECAP_SCALEOUT  0x00000020
#define RPI_FLAG_SMB2_SHARECAP_CLUSTER  0x00000040
#endif /* _WIN32_WINNT >= _WIN32_WINNT_WIN8 */

#if (_WIN32_WINNT >= _WIN32_WINNT_WIN8)
#define RPI_SMB2_FLAG_SERVERCAP_DFS  0x00000001
#define RPI_SMB2_FLAG_SERVERCAP_LEASING  0x00000002
#define RPI_SMB2_FLAG_SERVERCAP_LARGEMTU  0x00000004
#define RPI_SMB2_FLAG_SERVERCAP_MULTICHANNEL  0x00000008
#define RPI_SMB2_FLAG_SERVERCAP_PERSISTENT_HANDLES  0x00000010
#define RPI_SMB2_FLAG_SERVERCAP_DIRECTORY_LEASING  0x00000020
#endif /* _WIN32_WINNT >= _WIN32_WINNT_WIN8 */

typedef struct _FILE_REMOTE_PROTOCOL_INFO {
    USHORT StructureVersion;
    USHORT StructureSize;
    DWORD Protocol;
    USHORT ProtocolMajorVersion;
    USHORT ProtocolMinorVersion;
    USHORT ProtocolRevision;
    USHORT Reserved;
    DWORD Flags;
    struct {
        DWORD Reserved[8];
    } GenericReserved;
#if (_WIN32_WINNT < _WIN32_WINNT_WIN8)
    struct {
        DWORD Reserved[16];
    } ProtocolSpecificReserved;
#else /* _WIN32_WINNT >= _WIN32_WINNT_WIN8 */
    union {
        struct {
            struct {
                ULONG Capabilities;
            } Server;
            struct {
                ULONG Capabilities;
                ULONG CachingFlags;
            } Share;
        } Smb2;
        ULONG Reserved[16];
    } ProtocolSpecific;
#endif /* _WIN32_WINNT >= _WIN32_WINNT_WIN8 */
} FILE_REMOTE_PROTOCOL_INFO, *PFILE_REMOTE_PROTOCOL_INFO;

WINBASEAPI BOOL WINAPI SetFileInformationByHandle(HANDLE, FILE_INFO_BY_HANDLE_CLASS, LPVOID, DWORD);
WINBASEAPI BOOL WINAPI GetFileInformationByHandleEx(HANDLE, FILE_INFO_BY_HANDLE_CLASS, LPVOID, DWORD);

typedef enum _FILE_ID_TYPE {
    FileIdType,
    ObjectIdType,
    MaximumFileIdType
} FILE_ID_TYPE, *PFILE_ID_TYPE;

typedef struct FILE_ID_DESCRIPTOR {
    DWORD dwSize;
    FILE_ID_TYPE Type;
    union {
        LARGE_INTEGER FileId;
        GUID ObjectId;
#if (_WIN32_WINNT >= _WIN32_WINNT_WIN8)
        FILE_ID_128 ExtendedFileId;
#endif /* _WIN32_WINNT >= _WIN32_WINNT_WIN8 */
    } DUMMYUNIONNAME;
} FILE_ID_DESCRIPTOR, *LPFILE_ID_DESCRIPTOR;

WINBASEAPI HANDLE WINAPI OpenFileById(HANDLE, LPFILE_ID_DESCRIPTOR, DWORD, DWORD, LPSECURITY_ATTRIBUTES, DWORD);

#endif /* _WIN32_WINNT >= 0x0600 */

#if (_WIN32_WINNT >= 0x0600)

#define SYMBOLIC_LINK_FLAG_DIRECTORY  (0x1)
#define VALID_SYMBOLIC_LINK_FLAGS  SYMBOLIC_LINK_FLAG_DIRECTORY

WINBASEAPI BOOLEAN APIENTRY CreateSymbolicLinkA(LPCSTR, LPCSTR, DWORD);
WINBASEAPI BOOLEAN APIENTRY CreateSymbolicLinkW(LPCWSTR, LPCWSTR, DWORD);
WINBASEAPI BOOLEAN APIENTRY CreateSymbolicLinkTransactedA(LPCSTR, LPCSTR, DWORD, HANDLE);
WINBASEAPI BOOLEAN APIENTRY CreateSymbolicLinkTransactedW(LPCWSTR, LPCWSTR, DWORD, HANDLE);
WINBASEAPI DWORD WINAPI GetFinalPathNameByHandleA(HANDLE, LPSTR, DWORD, DWORD);
WINBASEAPI DWORD WINAPI GetFinalPathNameByHandleW(HANDLE, LPWSTR, DWORD, DWORD);

#ifdef UNICODE
#define CreateSymbolicLink  CreateSymbolicLinkW
#define CreateSymbolicLinkTransacted  CreateSymbolicLinkTransactedW
#define GetFinalPathNameByHandle  GetFinalPathNameByHandleW
#else /* !UNICODE */
#define CreateSymbolicLink  CreateSymbolicLinkA
#define CreateSymbolicLinkTransacted  CreateSymbolicLinkTransactedA
#define GetFinalPathNameByHandle  GetFinalPathNameByHandleA
#endif /* !UNICODE */

#endif /* _WIN32_WINNT >= 0x0600 */

#if (_WIN32_WINNT >= 0x0600)
WINBASEAPI BOOL WINAPI QueryActCtxSettingsW(DWORD, HANDLE, PCWSTR, PCWSTR, PWSTR, SIZE_T, SIZE_T *);
#endif
#if (_WIN32_WINNT >= 0x0600)
WINBASEAPI BOOL WINAPI ReplacePartitionUnit(PWSTR, PWSTR, ULONG);
#endif
#if (_WIN32_WINNT >= 0x0600)
WINBASEAPI BOOL WINAPI AddSecureMemoryCacheCallback(PSECURE_MEMORY_CACHE_CALLBACK);
WINBASEAPI BOOL WINAPI RemoveSecureMemoryCacheCallback(PSECURE_MEMORY_CACHE_CALLBACK);
#endif /* _WIN32_WINNT >= 0x0600 */

#if (_WIN32_WINNT >= 0x0601)
WINBASEAPI BOOL WINAPI CopyExtendedContext(PCONTEXT_EX, DWORD, PCONTEXT_EX);
WINBASEAPI BOOL WINAPI InitializeExtendedContext(PVOID, DWORD, PCONTEXT_EX *);
WINBASEAPI DWORD64 WINAPI GetEnabledExtendedFeatures(DWORD64);
WINBASEAPI BOOL WINAPI GetExtendedContextLength(DWORD, PDWORD);
WINBASEAPI DWORD64 WINAPI GetExtendedFeaturesMask(PCONTEXT_EX);
WINBASEAPI PVOID WINAPI LocateExtendedFeature(PCONTEXT_EX, DWORD, PDWORD);
WINBASEAPI PCONTEXT WINAPI LocateLegacyContext(PCONTEXT_EX, PDWORD);
WINBASEAPI VOID WINAPI SetExtendedFeaturesMask(PCONTEXT_EX, DWORD64);
WINBASEAPI DWORD APIENTRY EnableThreadProfiling(HANDLE, DWORD, DWORD64, HANDLE *);
WINBASEAPI DWORD APIENTRY DisableThreadProfiling(HANDLE);
WINBASEAPI DWORD APIENTRY QueryThreadProfiling(HANDLE, PBOOLEAN);
WINBASEAPI DWORD APIENTRY ReadThreadProfilingData(HANDLE, DWORD, PPERFORMANCE_DATA);
#endif /* _WIN32_WINNT >= 0x0601 */

#if defined(ISOLATION_AWARE_ENABLED) && (ISOLATION_AWARE_ENABLED != 0)
/* #include "winbase.inl" --- sicko */
#endif /* ISOLATION_AWARE_ENABLED */

#if __POCC__ >= 290
#pragma warn(pop)
#endif

#ifdef __cplusplus
}
#endif

#endif /* _WINBASE_H */
