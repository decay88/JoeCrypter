#ifndef _MFAPI_H
#define _MFAPI_H

#if __POCC__ >= 500
#pragma once
#endif

/* Windows Media Foundation API definitions */

#if defined(WIN32_DEFAULT_LIBS)
#pragma comment(lib, "mfplat.lib")
#endif

#pragma pack(push, mfhrds)
#include <mfobjects.h>
#pragma pack(pop, mfhrds)

#include "mmreg.h"

#include <avrt.h>

#ifndef AVRT_DATA
#define AVRT_DATA
#endif
#ifndef AVRT_BSS
#define AVRT_BSS
#endif

#ifndef MF_VERSION
#if (WINVER >= _WIN32_WINNT_WIN7)
#define MF_SDK_VERSION 0x0002
#else /* Windows Vista */
#define MF_SDK_VERSION 0x0001
#endif /* WINVER >= _WIN32_WINNT_WIN7 */
#define MF_API_VERSION  0x0070
#define MF_VERSION  (MF_SDK_VERSION<<16|MF_API_VERSION)
#endif /* !MF_VERSION */

#define MFSTARTUP_NOSOCKET  0x1
#define MFSTARTUP_LITE  (MFSTARTUP_NOSOCKET)
#define MFSTARTUP_FULL  0

#if defined(__cplusplus)
extern "C" {
#endif

#define MF_1_BYTE_ALIGNMENT  0x00000000
#define MF_2_BYTE_ALIGNMENT  0x00000001
#define MF_4_BYTE_ALIGNMENT  0x00000003
#define MF_8_BYTE_ALIGNMENT  0x00000007
#define MF_16_BYTE_ALIGNMENT  0x0000000f
#define MF_32_BYTE_ALIGNMENT  0x0000001f
#define MF_64_BYTE_ALIGNMENT  0x0000003f
#define MF_128_BYTE_ALIGNMENT  0x0000007f
#define MF_256_BYTE_ALIGNMENT  0x000000ff
#define MF_512_BYTE_ALIGNMENT  0x000001ff

#define MFSESSIONCAP_START  0x00000001
#define MFSESSIONCAP_SEEK  0x00000002
#define MFSESSIONCAP_PAUSE  0x00000004
#define MFSESSIONCAP_RATE_FORWARD  0x00000010
#define MFSESSIONCAP_RATE_REVERSE  0x00000020

#ifndef FCC
#define FCC(ch4) ((((DWORD)(ch4) & 0xFF) << 24) | \
                  (((DWORD)(ch4) & 0xFF00) << 8) | \
                  (((DWORD)(ch4) & 0xFF0000) >> 8) | \
                  (((DWORD)(ch4) & 0xFF000000) >> 24))
#endif /* FCC */

#ifndef DEFINE_MEDIATYPE_GUID
#define DEFINE_MEDIATYPE_GUID(name,format) \
    DEFINE_GUID(name, format, 0x0000, 0x0010, 0x80, 0x00, 0x00, 0xaa, 0x00, 0x38, 0x9b, 0x71)
#endif

#ifndef DIRECT3D_VERSION
#define D3DFMT_R8G8B8  20
#define D3DFMT_A8R8G8B8  21
#define D3DFMT_X8R8G8B8  22
#define D3DFMT_R5G6B5  23
#define D3DFMT_X1R5G5B5  24
#define D3DFMT_P8  41
#define LOCAL_D3DFMT_DEFINES 1
#endif

#ifdef LOCAL_D3DFMT_DEFINES
#undef D3DFMT_R8G8B8
#undef D3DFMT_A8R8G8B8
#undef D3DFMT_X8R8G8B8
#undef D3DFMT_R5G6B5
#undef D3DFMT_X1R5G5B5
#undef D3DFMT_P8
#undef LOCAL_D3DFMT_DEFINES
#endif

typedef unsigned __int64 MFWORKITEM_KEY;

typedef void (*MFPERIODICCALLBACK)(IUnknown *);

#if (WINVER >= _WIN32_WINNT_WIN7)
typedef enum {
    MF_STANDARD_WORKQUEUE = 0,
    MF_WINDOW_WORKQUEUE = 1,
} MFASYNC_WORKQUEUE_TYPE;
#endif /* WINVER >= _WIN32_WINNT_WIN7 */

typedef struct tagMFASYNCRESULT {
    IMFAsyncResult AsyncResult;
    OVERLAPPED overlapped;
    IMFAsyncCallback * pCallback;
    HRESULT hrStatusResult;
    DWORD dwBytesTransferred;
    HANDLE hEvent;
}   MFASYNCRESULT;

typedef enum {
    MF_TOPOSTATUS_INVALID = 0,
    MF_TOPOSTATUS_READY = 100,
    MF_TOPOSTATUS_STARTED_SOURCE = 200,
#if (WINVER >= _WIN32_WINNT_WIN7)
    MF_TOPOSTATUS_DYNAMIC_CHANGED = 210,
#endif /* WINVER >= _WIN32_WINNT_WIN7 */
    MF_TOPOSTATUS_SINK_SWITCHED = 300,
    MF_TOPOSTATUS_ENDED = 400,
} MF_TOPOSTATUS;

#if (WINVER >= _WIN32_WINNT_WIN7)
enum _MFT_ENUM_FLAG {
    MFT_ENUM_FLAG_SYNCMFT = 0x00000001,
    MFT_ENUM_FLAG_ASYNCMFT = 0x00000002,
    MFT_ENUM_FLAG_HARDWARE = 0x00000004,
    MFT_ENUM_FLAG_FIELDOFUSE = 0x00000008,
    MFT_ENUM_FLAG_LOCALMFT = 0x00000010,
    MFT_ENUM_FLAG_TRANSCODE_ONLY = 0x00000020,
    MFT_ENUM_FLAG_SORTANDFILTER = 0x00000040,
    MFT_ENUM_FLAG_ALL = 0x0000003F
};
#endif /* WINVER >= _WIN32_WINNT_WIN7 */

typedef struct _MFFOLDDOWN_MATRIX {
    UINT32 cbSize;
    UINT32 cSrcChannels;
    UINT32 cDstChannels;
    UINT32 dwChannelMask;
    LONG Coeff[64];
} MFFOLDDOWN_MATRIX;

typedef enum _MFVideoDRMFlags {
    MFVideoDRMFlag_None = 0,
    MFVideoDRMFlag_AnalogProtected = 1,
    MFVideoDRMFlag_DigitallyProtected = 2,
} MFVideoDRMFlags;

typedef enum _MFVideoPadFlags {
    MFVideoPadFlag_PAD_TO_None = 0,
    MFVideoPadFlag_PAD_TO_4x3 = 1,
    MFVideoPadFlag_PAD_TO_16x9 = 2
} MFVideoPadFlags;

typedef enum _MFVideoSrcContentHintFlags {
    MFVideoSrcContentHintFlag_None = 0,
    MFVideoSrcContentHintFlag_16x9 = 1,
    MFVideoSrcContentHintFlag_235_1 = 2
} MFVideoSrcContentHintFlags;

typedef struct _MT_CUSTOM_VIDEO_PRIMARIES {
    float fRx;
    float fRy;
    float fGx;
    float fGy;
    float fBx;
    float fBy;
    float fWx;
    float fWy;
} MT_CUSTOM_VIDEO_PRIMARIES;

#if (WINVER >= _WIN32_WINNT_WIN7)
typedef struct _MT_ARBITRARY_HEADER {
    GUID majortype;
    GUID subtype;
    BOOL bFixedSizeSamples;
    BOOL bTemporalCompression;
    ULONG lSampleSize;
    GUID formattype;
} MT_ARBITRARY_HEADER;
#endif /* WINVER >= _WIN32_WINNT_WIN7 */

struct tagVIDEOINFOHEADER;
typedef struct tagVIDEOINFOHEADER VIDEOINFOHEADER;
struct tagVIDEOINFOHEADER2;
typedef struct tagVIDEOINFOHEADER2 VIDEOINFOHEADER2;
struct tagMPEG1VIDEOINFO;
typedef struct tagMPEG1VIDEOINFO MPEG1VIDEOINFO;
struct tagMPEG2VIDEOINFO;
typedef struct tagMPEG2VIDEOINFO MPEG2VIDEOINFO;
struct _AMMediaType;
typedef struct _AMMediaType AM_MEDIA_TYPE;

typedef enum _MFWaveFormatExConvertFlags {
    MFWaveFormatExConvertFlag_Normal = 0,
    MFWaveFormatExConvertFlag_ForceExtensible = 1
} MFWaveFormatExConvertFlags;

typedef enum _EAllocationType {
    eAllocationTypeDynamic,
    eAllocationTypeRT,
    eAllocationTypePageable,
    eAllocationTypeIgnore
} EAllocationType;

STDAPI MFStartup(ULONG,DWORD);
STDAPI MFShutdown(void);
STDAPI MFLockPlatform(void);
STDAPI MFUnlockPlatform(void);
STDAPI MFPutWorkItem(DWORD, IMFAsyncCallback *, IUnknown *);
STDAPI MFPutWorkItemEx(DWORD, IMFAsyncResult *);
STDAPI MFScheduleWorkItem(IMFAsyncCallback *, IUnknown *, INT64, MFWORKITEM_KEY *);
STDAPI MFScheduleWorkItemEx(IMFAsyncResult *, INT64, MFWORKITEM_KEY *);
STDAPI MFCancelWorkItem(MFWORKITEM_KEY);
STDAPI MFGetTimerPeriodicity(DWORD *);
STDAPI MFAddPeriodicCallback(MFPERIODICCALLBACK, IUnknown *, DWORD *);
STDAPI MFRemovePeriodicCallback(DWORD);
#if (WINVER >= _WIN32_WINNT_WIN7)
STDAPI MFAllocateWorkQueueEx(MFASYNC_WORKQUEUE_TYPE, DWORD *);
#endif /* WINVER >= _WIN32_WINNT_WIN7 */
STDAPI MFAllocateWorkQueue(DWORD *);
STDAPI MFLockWorkQueue(DWORD);
STDAPI MFUnlockWorkQueue(DWORD);
STDAPI MFBeginRegisterWorkQueueWithMMCSS(DWORD, LPCWSTR, DWORD, IMFAsyncCallback *, IUnknown *);
STDAPI MFEndRegisterWorkQueueWithMMCSS(IMFAsyncResult *, DWORD *);
STDAPI MFBeginUnregisterWorkQueueWithMMCSS(DWORD, IMFAsyncCallback *, IUnknown *);
STDAPI MFEndUnregisterWorkQueueWithMMCSS(IMFAsyncResult *);
STDAPI MFGetWorkQueueMMCSSClass(DWORD, LPWSTR, DWORD *);
STDAPI MFGetWorkQueueMMCSSTaskId(DWORD, LPDWORD);
STDAPI MFCreateAsyncResult(IUnknown *, IMFAsyncCallback *, IUnknown *, IMFAsyncResult **);
STDAPI MFInvokeCallback(IMFAsyncResult *);
STDAPI MFCreateFile(MF_FILE_ACCESSMODE, MF_FILE_OPENMODE, MF_FILE_FLAGS, LPCWSTR, IMFByteStream **);
STDAPI MFCreateTempFile(MF_FILE_ACCESSMODE, MF_FILE_OPENMODE, MF_FILE_FLAGS, IMFByteStream **);
STDAPI MFBeginCreateFile(MF_FILE_ACCESSMODE, MF_FILE_OPENMODE, MF_FILE_FLAGS, LPCWSTR, IMFAsyncCallback *, IUnknown *, IUnknown **);
STDAPI MFEndCreateFile(IMFAsyncResult *pResult, IMFByteStream **);
STDAPI MFCancelCreateFile(IUnknown *);
STDAPI MFCreateMemoryBuffer(DWORD, IMFMediaBuffer **);
STDAPI MFCreateMediaBufferWrapper(IMFMediaBuffer *, DWORD, DWORD, IMFMediaBuffer **);
STDAPI MFCreateLegacyMediaBufferOnMFMediaBuffer(IMFSample *, IMFMediaBuffer *, DWORD, IMediaBuffer **);
STDAPI MFCreateDXSurfaceBuffer(REFIID, IUnknown *, BOOL, IMFMediaBuffer **);
STDAPI MFCreateAlignedMemoryBuffer(DWORD, DWORD, IMFMediaBuffer **);
STDAPI MFCreateMediaEvent(MediaEventType, REFGUID, HRESULT, const PROPVARIANT *, IMFMediaEvent **);
STDAPI MFCreateEventQueue(IMFMediaEventQueue **);
STDAPI MFCreateSample(IMFSample **);
STDAPI MFCreateAttributes(IMFAttributes **, UINT32);
STDAPI MFInitAttributesFromBlob(IMFAttributes *, const UINT8 *, UINT);
STDAPI MFGetAttributesAsBlobSize(IMFAttributes *, UINT32 *);
STDAPI MFGetAttributesAsBlob(IMFAttributes *, UINT8 *, UINT);
STDAPI MFTRegister(CLSID, GUID, LPWSTR, UINT32, UINT32, MFT_REGISTER_TYPE_INFO *, UINT32, MFT_REGISTER_TYPE_INFO *, IMFAttributes *);
STDAPI MFTUnregister(CLSID);
#if (WINVER >= _WIN32_WINNT_WIN7)
STDAPI MFTRegisterLocal(IClassFactory *, REFGUID, LPCWSTR, UINT32, UINT32, const MFT_REGISTER_TYPE_INFO *, UINT32, const MFT_REGISTER_TYPE_INFO *);
STDAPI MFTUnregisterLocal(IClassFactory *);
STDAPI MFTRegisterLocalByCLSID(REFCLSID, REFGUID, LPCWSTR, UINT32, UINT32, const MFT_REGISTER_TYPE_INFO *, UINT32, const MFT_REGISTER_TYPE_INFO *);
STDAPI MFTUnregisterLocalByCLSID(CLSID);
#endif /* WINVER >= _WIN32_WINNT_WIN7 */
STDAPI MFTEnum(GUID, UINT32, MFT_REGISTER_TYPE_INFO *, MFT_REGISTER_TYPE_INFO *, IMFAttributes *, CLSID **, UINT32 *);
#if (WINVER >= _WIN32_WINNT_WIN7)
STDAPI MFTEnumEx(GUID, UINT32, const MFT_REGISTER_TYPE_INFO *, const MFT_REGISTER_TYPE_INFO *, IMFActivate ***, UINT32 *);
#endif /* WINVER >= _WIN32_WINNT_WIN7 */
STDAPI MFTGetInfo(CLSID, LPWSTR *, MFT_REGISTER_TYPE_INFO **, UINT32 *, MFT_REGISTER_TYPE_INFO **, UINT32 *, IMFAttributes **);
#if (WINVER >= _WIN32_WINNT_WIN7)
STDAPI MFGetPluginControl(IMFPluginControl **);
STDAPI MFGetMFTMerit(IUnknown *, UINT32, const BYTE *, DWORD *);
#endif /* WINVER >= _WIN32_WINNT_WIN7 */
#if (WINVER >= _WIN32_WINNT_WIN8)
STDAPI MFRegisterLocalSchemeHandler(PCWSTR, IMFActivate *);
STDAPI MFRegisterLocalByteStreamHandler(PCWSTR, PCWSTR, IMFActivate *);
STDAPI MFCreateMFByteStreamWrapper(IMFByteStream *, IMFByteStream **);
STDAPI MFCreateMediaExtensionActivate(PCWSTR, IUnknown *, REFIID, LPVOID *);
#endif /* WINVER >= _WIN32_WINNT_WIN8 */
STDAPI MFValidateMediaTypeSize(GUID, UINT8 *, UINT32);
STDAPI MFCreateMediaType(IMFMediaType **);
STDAPI MFCreateMFVideoFormatFromMFMediaType(IMFMediaType *, MFVIDEOFORMAT **, UINT32 *);
STDAPI MFCreateWaveFormatExFromMFMediaType(IMFMediaType *, WAVEFORMATEX **, UINT32 *, UINT32);
STDAPI MFInitMediaTypeFromVideoInfoHeader(IMFMediaType *, const VIDEOINFOHEADER *, UINT32, const GUID *);
STDAPI MFInitMediaTypeFromVideoInfoHeader2(IMFMediaType *, const VIDEOINFOHEADER2 *, UINT32, const GUID *);
STDAPI MFInitMediaTypeFromMPEG1VideoInfo(IMFMediaType *, const MPEG1VIDEOINFO *, UINT32, const GUID *);
STDAPI MFInitMediaTypeFromMPEG2VideoInfo(IMFMediaType *, const MPEG2VIDEOINFO *, UINT32, const GUID *);
STDAPI MFCalculateBitmapImageSize(const BITMAPINFOHEADER *, UINT32, UINT32 *, BOOL *);
STDAPI MFCalculateImageSize(REFGUID, UINT32, UINT32, UINT32 *);
STDAPI MFFrameRateToAverageTimePerFrame(UINT32, UINT32, UINT64 *);
STDAPI MFAverageTimePerFrameToFrameRate(UINT64, UINT32 *, UINT32 *);
STDAPI MFInitMediaTypeFromMFVideoFormat(IMFMediaType *, const MFVIDEOFORMAT *, UINT32);
STDAPI MFInitMediaTypeFromWaveFormatEx(IMFMediaType *, const WAVEFORMATEX *, UINT32);
STDAPI MFInitMediaTypeFromAMMediaType(IMFMediaType *, const AM_MEDIA_TYPE *);
STDAPI MFInitAMMediaTypeFromMFMediaType(IMFMediaType *, GUID, AM_MEDIA_TYPE *);
STDAPI MFCreateAMMediaTypeFromMFMediaType(IMFMediaType *, GUID, AM_MEDIA_TYPE **);
STDAPI_(BOOL)MFCompareFullToPartialMediaType(IMFMediaType *, IMFMediaType *);
STDAPI MFWrapMediaType(IMFMediaType *, REFGUID, REFGUID, IMFMediaType **);
STDAPI MFUnwrapMediaType(IMFMediaType *, IMFMediaType **);
#ifdef _KSMEDIA_H
STDAPI MFCreateVideoMediaTypeFromVideoInfoHeader(const KS_VIDEOINFOHEADER *, DWORD, DWORD, DWORD, MFVideoInterlaceMode, QWORD, const GUID *, IMFVideoMediaType **);
STDAPI MFCreateVideoMediaTypeFromVideoInfoHeader2(const KS_VIDEOINFOHEADER2 *, DWORD, QWORD, const GUID *, IMFVideoMediaType **);
#endif /* _KSMEDIA_H */
STDAPI MFCreateVideoMediaType(const MFVIDEOFORMAT *, IMFVideoMediaType **);
STDAPI MFCreateVideoMediaTypeFromSubtype(const GUID *, IMFVideoMediaType **);
STDAPI_(BOOL)MFIsFormatYUV(DWORD);
STDAPI MFCreateVideoMediaTypeFromBitMapInfoHeader(const BITMAPINFOHEADER *, DWORD, DWORD, MFVideoInterlaceMode, QWORD, QWORD, QWORD, DWORD, IMFVideoMediaType **);
STDAPI MFGetStrideForBitmapInfoHeader(DWORD, DWORD, LONG *);
STDAPI MFGetPlaneSize(DWORD, DWORD, DWORD, DWORD *);
#if (WINVER >= _WIN32_WINNT_WIN7)
STDAPI MFCreateVideoMediaTypeFromBitMapInfoHeaderEx(const BITMAPINFOHEADER *, UINT32, DWORD, DWORD, MFVideoInterlaceMode, QWORD, DWORD, DWORD, DWORD, IMFVideoMediaType **);
#endif /* WINVER >= _WIN32_WINNT_WIN7 */
STDAPI MFCreateMediaTypeFromRepresentation(GUID, LPVOID, IMFMediaType **);
STDAPI MFCreateAudioMediaType(const WAVEFORMATEX *, IMFAudioMediaType **);
DWORD STDMETHODCALLTYPE MFGetUncompressedVideoFormat(const MFVIDEOFORMAT *);
STDAPI MFInitVideoFormat(MFVIDEOFORMAT *, MFStandardVideoFormat);
STDAPI MFInitVideoFormat_RGB(MFVIDEOFORMAT *, DWORD, DWORD, DWORD);
STDAPI MFConvertColorInfoToDXVA(DWORD *, const MFVIDEOFORMAT *);
STDAPI MFConvertColorInfoFromDXVA(MFVIDEOFORMAT *, DWORD);
STDAPI MFCopyImage(BYTE *, LONG, const BYTE *, LONG, DWORD, DWORD);
STDAPI MFConvertFromFP16Array(float *, const WORD *, DWORD);
STDAPI MFConvertToFP16Array(WORD *, const float *, DWORD);
STDAPI MFCreateCollection(IMFCollection **);

#ifdef MF_INIT_GUIDS
#include <initguid.h>
#endif

DEFINE_GUID(MF_EVENT_SESSIONCAPS,0x7e5ebcd0, 0x11b8, 0x4abe, 0xaf, 0xad, 0x10, 0xf6, 0x59, 0x9a, 0x7f, 0x42);
DEFINE_GUID(MF_EVENT_SESSIONCAPS_DELTA,0x7e5ebcd1, 0x11b8, 0x4abe, 0xaf, 0xad, 0x10, 0xf6, 0x59, 0x9a, 0x7f, 0x42);

DEFINE_GUID(MF_EVENT_TOPOLOGY_STATUS,0x30c5018d, 0x9a53, 0x454b, 0xad, 0x9e, 0x6d, 0x5f, 0x8f, 0xa7, 0xc4, 0x3b);
DEFINE_GUID(MF_EVENT_START_PRESENTATION_TIME,0x5ad914d0, 0x9b45, 0x4a8d, 0xa2, 0xc0, 0x81, 0xd1, 0xe5, 0xb, 0xfb, 0x7);
DEFINE_GUID(MF_EVENT_PRESENTATION_TIME_OFFSET,0x5ad914d1, 0x9b45, 0x4a8d, 0xa2, 0xc0, 0x81, 0xd1, 0xe5, 0xb, 0xfb, 0x7);
DEFINE_GUID(MF_EVENT_START_PRESENTATION_TIME_AT_OUTPUT,0x5ad914d2, 0x9b45, 0x4a8d, 0xa2, 0xc0, 0x81, 0xd1, 0xe5, 0xb, 0xfb, 0x7);
DEFINE_GUID(MF_EVENT_SOURCE_FAKE_START,0xa8cc55a7, 0x6b31, 0x419f, 0x84, 0x5d, 0xff, 0xb3, 0x51, 0xa2, 0x43, 0x4b);
DEFINE_GUID(MF_EVENT_SOURCE_PROJECTSTART,0xa8cc55a8, 0x6b31, 0x419f, 0x84, 0x5d, 0xff, 0xb3, 0x51, 0xa2, 0x43, 0x4b);
DEFINE_GUID(MF_EVENT_SOURCE_ACTUAL_START,0xa8cc55a9, 0x6b31, 0x419f, 0x84, 0x5d, 0xff, 0xb3, 0x51, 0xa2, 0x43, 0x4b);
DEFINE_GUID(MF_EVENT_SOURCE_TOPOLOGY_CANCELED,0xdb62f650, 0x9a5e, 0x4704, 0xac, 0xf3, 0x56, 0x3b, 0xc6, 0xa7, 0x33, 0x64);
DEFINE_GUID(MF_EVENT_SOURCE_CHARACTERISTICS,0x47db8490, 0x8b22, 0x4f52, 0xaf, 0xda, 0x9c, 0xe1, 0xb2, 0xd3, 0xcf, 0xa8);
DEFINE_GUID(MF_EVENT_SOURCE_CHARACTERISTICS_OLD,0x47db8491, 0x8b22, 0x4f52, 0xaf, 0xda, 0x9c, 0xe1, 0xb2, 0xd3, 0xcf, 0xa8);
DEFINE_GUID(MF_EVENT_DO_THINNING,0x321ea6fb, 0xdad9, 0x46e4, 0xb3, 0x1d, 0xd2, 0xea, 0xe7, 0x9, 0xe, 0x30);
DEFINE_GUID(MF_EVENT_SCRUBSAMPLE_TIME,0x9ac712b3, 0xdcb8, 0x44d5, 0x8d, 0xc, 0x37, 0x45, 0x5a, 0x27, 0x82, 0xe3);
DEFINE_GUID(MF_EVENT_OUTPUT_NODE,0x830f1a8b, 0xc060, 0x46dd, 0xa8, 0x01, 0x1c, 0x95, 0xde, 0xc9, 0xb1, 0x07);

#if (WINVER >= _WIN32_WINNT_WIN7)
DEFINE_GUID(MF_EVENT_MFT_INPUT_STREAM_ID,0xf29c2cca, 0x7ae6, 0x42d2, 0xb2, 0x84, 0xbf, 0x83, 0x7c, 0xc8, 0x74, 0xe2);
DEFINE_GUID(MF_EVENT_MFT_CONTEXT,0xb7cd31f1, 0x899e, 0x4b41, 0x80, 0xc9, 0x26, 0xa8, 0x96, 0xd3, 0x29, 0x77);
#endif /* WINVER >= _WIN32_WINNT_WIN7 */

#if (WINVER >= _WIN32_WINNT_WINBLUE)
DEFINE_GUID(MF_EVENT_STREAM_METADATA_KEYDATA,0xcd59a4a1, 0x4a3b, 0x4bbd, 0x86, 0x65, 0x72, 0xa4, 0xf, 0xbe, 0xa7, 0x76);
DEFINE_GUID(MF_EVENT_STREAM_METADATA_CONTENT_KEYIDS,0x5063449d, 0xcc29, 0x4fc6, 0xa7, 0x5a, 0xd2, 0x47, 0xb3, 0x5a, 0xf8, 0x5c);
DEFINE_GUID(MF_EVENT_STREAM_METADATA_SYSTEMID,0x1ea2ef64, 0xba16, 0x4a36, 0x87, 0x19, 0xfe, 0x75, 0x60, 0xba, 0x32, 0xad);
#endif /* WINVER >= _WIN32_WINNT_WINBLUE */

DEFINE_GUID(MFSampleExtension_CleanPoint,0x9cdf01d8, 0xa0f0, 0x43ba, 0xb0, 0x77, 0xea, 0xa0, 0x6c, 0xbd, 0x72, 0x8a);
DEFINE_GUID(MFSampleExtension_Discontinuity,0x9cdf01d9, 0xa0f0, 0x43ba, 0xb0, 0x77, 0xea, 0xa0, 0x6c, 0xbd, 0x72, 0x8a);
DEFINE_GUID(MFSampleExtension_Token,0x8294da66, 0xf328, 0x4805, 0xb5, 0x51, 0x00, 0xde, 0xb4, 0xc5, 0x7a, 0x61);
DEFINE_GUID(MFSampleExtension_DescrambleData,0x43483be6, 0x4903, 0x4314, 0xb0, 0x32, 0x29, 0x51, 0x36, 0x59, 0x36, 0xfc);
DEFINE_GUID(MFSampleExtension_SampleKeyID,0x9ed713c8, 0x9b87, 0x4b26, 0x82, 0x97, 0xa9, 0x3b, 0x0c, 0x5a, 0x8a, 0xcc);
DEFINE_GUID(MFSampleExtension_GenKeyFunc,0x441ca1ee, 0x6b1f, 0x4501, 0x90, 0x3a, 0xde, 0x87, 0xdf, 0x42, 0xf6, 0xed);
DEFINE_GUID(MFSampleExtension_GenKeyCtx,0x188120cb, 0xd7da, 0x4b59, 0x9b, 0x3e, 0x92, 0x52, 0xfd, 0x37, 0x30, 0x1c);
DEFINE_GUID(MFSampleExtension_PacketCrossOffsets,0x2789671d, 0x389f, 0x40bb, 0x90, 0xd9, 0xc2, 0x82, 0xf7, 0x7f, 0x9a, 0xbd);
DEFINE_GUID(MFSampleExtension_Interlaced,0xb1d5830a, 0xdeb8, 0x40e3, 0x90, 0xfa, 0x38, 0x99, 0x43, 0x71, 0x64, 0x61);
DEFINE_GUID(MFSampleExtension_BottomFieldFirst,0x941ce0a3, 0x6ae3, 0x4dda, 0x9a, 0x08, 0xa6, 0x42, 0x98, 0x34, 0x06, 0x17);
DEFINE_GUID(MFSampleExtension_RepeatFirstField,0x304d257c, 0x7493, 0x4fbd, 0xb1, 0x49, 0x92, 0x28, 0xde, 0x8d, 0x9a, 0x99);
DEFINE_GUID(MFSampleExtension_SingleField,0x9d85f816, 0x658b, 0x455a, 0xbd, 0xe0, 0x9f, 0xa7, 0xe1, 0x5a, 0xb8, 0xf9);
DEFINE_GUID(MFSampleExtension_DerivedFromTopField,0x6852465a, 0xae1c, 0x4553, 0x8e, 0x9b, 0xc3, 0x42, 0x0f, 0xcb, 0x16, 0x37);

DEFINE_GUID(MFT_CATEGORY_VIDEO_DECODER,0xd6c02d4b, 0x6833, 0x45b4, 0x97, 0x1a, 0x05, 0xa4, 0xb0, 0x4b, 0xab, 0x91);
DEFINE_GUID(MFT_CATEGORY_VIDEO_ENCODER,0xf79eac7d, 0xe545, 0x4387, 0xbd, 0xee, 0xd6, 0x47, 0xd7, 0xbd, 0xe4, 0x2a);
DEFINE_GUID(MFT_CATEGORY_VIDEO_EFFECT,0x12e17c21, 0x532c, 0x4a6e, 0x8a, 0x1c, 0x40, 0x82, 0x5a, 0x73, 0x63, 0x97);
DEFINE_GUID(MFT_CATEGORY_MULTIPLEXER,0x059c561e, 0x05ae, 0x4b61, 0xb6, 0x9d, 0x55, 0xb6, 0x1e, 0xe5, 0x4a, 0x7b);
DEFINE_GUID(MFT_CATEGORY_DEMULTIPLEXER,0xa8700a7a, 0x939b, 0x44c5, 0x99, 0xd7, 0x76, 0x22, 0x6b, 0x23, 0xb3, 0xf1);
DEFINE_GUID(MFT_CATEGORY_AUDIO_DECODER,0x9ea73fb4, 0xef7a, 0x4559, 0x8d, 0x5d, 0x71, 0x9d, 0x8f, 0x04, 0x26, 0xc7);
DEFINE_GUID(MFT_CATEGORY_AUDIO_ENCODER,0x91c64bd0, 0xf91e, 0x4d8c, 0x92, 0x76, 0xdb, 0x24, 0x82, 0x79, 0xd9, 0x75);
DEFINE_GUID(MFT_CATEGORY_AUDIO_EFFECT,0x11064c48, 0x3648, 0x4ed0, 0x93, 0x2e, 0x05, 0xce, 0x8a, 0xc8, 0x11, 0xb7);
#if (WINVER >= _WIN32_WINNT_WIN7)
DEFINE_GUID(MFT_CATEGORY_VIDEO_PROCESSOR,0x302ea3fc, 0xaa5f, 0x47f9, 0x9f, 0x7a, 0xc2, 0x18, 0x8b, 0xb1, 0x63, 0x2);
#endif /* WINVER >= _WIN32_WINNT_WIN7 */
DEFINE_GUID(MFT_CATEGORY_OTHER,0x90175d57, 0xb7ea, 0x4901, 0xae, 0xb3, 0x93, 0x3a, 0x87, 0x47, 0x75, 0x6f);

DEFINE_GUID(MFT_SUPPORT_DYNAMIC_FORMAT_CHANGE,0x53476a11, 0x3f13, 0x49fb, 0xac, 0x42, 0xee, 0x27, 0x33, 0xc9, 0x67, 0x41);

DEFINE_MEDIATYPE_GUID(MFVideoFormat_Base, 0x00000000);
DEFINE_MEDIATYPE_GUID(MFVideoFormat_RGB32, D3DFMT_X8R8G8B8);
DEFINE_MEDIATYPE_GUID(MFVideoFormat_ARGB32, D3DFMT_A8R8G8B8);
DEFINE_MEDIATYPE_GUID(MFVideoFormat_RGB24, D3DFMT_R8G8B8);
DEFINE_MEDIATYPE_GUID(MFVideoFormat_RGB555, D3DFMT_X1R5G5B5);
DEFINE_MEDIATYPE_GUID(MFVideoFormat_RGB565, D3DFMT_R5G6B5);
DEFINE_MEDIATYPE_GUID(MFVideoFormat_RGB8, D3DFMT_P8);
DEFINE_MEDIATYPE_GUID(MFVideoFormat_AI44, FCC('AI44'));
DEFINE_MEDIATYPE_GUID(MFVideoFormat_AYUV, FCC('AYUV'));
DEFINE_MEDIATYPE_GUID(MFVideoFormat_YUY2, FCC('YUY2'));
DEFINE_MEDIATYPE_GUID(MFVideoFormat_YVYU, FCC('YVYU'));
DEFINE_MEDIATYPE_GUID(MFVideoFormat_YVU9, FCC('YVU9'));
DEFINE_MEDIATYPE_GUID(MFVideoFormat_UYVY, FCC('UYVY'));
DEFINE_MEDIATYPE_GUID(MFVideoFormat_NV11, FCC('NV11'));
DEFINE_MEDIATYPE_GUID(MFVideoFormat_NV12, FCC('NV12'));
DEFINE_MEDIATYPE_GUID(MFVideoFormat_YV12, FCC('YV12'));
DEFINE_MEDIATYPE_GUID(MFVideoFormat_I420, FCC('I420'));
DEFINE_MEDIATYPE_GUID(MFVideoFormat_IYUV, FCC('IYUV'));
DEFINE_MEDIATYPE_GUID(MFVideoFormat_Y210, FCC('Y210'));
DEFINE_MEDIATYPE_GUID(MFVideoFormat_Y216, FCC('Y216'));
DEFINE_MEDIATYPE_GUID(MFVideoFormat_Y410, FCC('Y410'));
DEFINE_MEDIATYPE_GUID(MFVideoFormat_Y416, FCC('Y416'));
DEFINE_MEDIATYPE_GUID(MFVideoFormat_Y41P, FCC('Y41P'));
DEFINE_MEDIATYPE_GUID(MFVideoFormat_Y41T, FCC('Y41T'));
DEFINE_MEDIATYPE_GUID(MFVideoFormat_Y42T, FCC('Y42T'));
DEFINE_MEDIATYPE_GUID(MFVideoFormat_P210, FCC('P210'));
DEFINE_MEDIATYPE_GUID(MFVideoFormat_P216, FCC('P216'));
DEFINE_MEDIATYPE_GUID(MFVideoFormat_P010, FCC('P010'));
DEFINE_MEDIATYPE_GUID(MFVideoFormat_P016, FCC('P016'));
DEFINE_MEDIATYPE_GUID(MFVideoFormat_v210, FCC('v210'));
DEFINE_MEDIATYPE_GUID(MFVideoFormat_v216, FCC('v216'));
DEFINE_MEDIATYPE_GUID(MFVideoFormat_v410, FCC('v410'));
DEFINE_MEDIATYPE_GUID(MFVideoFormat_MP43, FCC('MP43'));
DEFINE_MEDIATYPE_GUID(MFVideoFormat_MP4S, FCC('MP4S'));
DEFINE_MEDIATYPE_GUID(MFVideoFormat_M4S2, FCC('M4S2'));
DEFINE_MEDIATYPE_GUID(MFVideoFormat_MP4V, FCC('MP4V'));
DEFINE_MEDIATYPE_GUID(MFVideoFormat_WMV1, FCC('WMV1'));
DEFINE_MEDIATYPE_GUID(MFVideoFormat_WMV2, FCC('WMV2'));
DEFINE_MEDIATYPE_GUID(MFVideoFormat_WMV3, FCC('WMV3'));
DEFINE_MEDIATYPE_GUID(MFVideoFormat_WVC1, FCC('WVC1'));
DEFINE_MEDIATYPE_GUID(MFVideoFormat_MSS1, FCC('MSS1'));
DEFINE_MEDIATYPE_GUID(MFVideoFormat_MSS2, FCC('MSS2'));
DEFINE_MEDIATYPE_GUID(MFVideoFormat_MPG1, FCC('MPG1'));
DEFINE_MEDIATYPE_GUID(MFVideoFormat_DVSL, FCC('dvsl'));
DEFINE_MEDIATYPE_GUID(MFVideoFormat_DVSD, FCC('dvsd'));
DEFINE_MEDIATYPE_GUID(MFVideoFormat_DVHD, FCC('dvhd'));
DEFINE_MEDIATYPE_GUID(MFVideoFormat_DV25, FCC('dv25'));
DEFINE_MEDIATYPE_GUID(MFVideoFormat_DV50, FCC('dv50'));
DEFINE_MEDIATYPE_GUID(MFVideoFormat_DVH1, FCC('dvh1'));
DEFINE_MEDIATYPE_GUID(MFVideoFormat_DVC, FCC('dvc '));
DEFINE_MEDIATYPE_GUID(MFVideoFormat_H264, FCC('H264'));
DEFINE_MEDIATYPE_GUID(MFVideoFormat_MJPG, FCC('MJPG'));
DEFINE_MEDIATYPE_GUID(MFVideoFormat_420O, FCC('420O'));
DEFINE_MEDIATYPE_GUID(MFVideoFormat_HEVC, FCC('HEVC'));
DEFINE_MEDIATYPE_GUID(MFVideoFormat_HEVC_ES, FCC('HEVS'));
#if (WINVER >= _WIN32_WINNT_WIN8)
DEFINE_MEDIATYPE_GUID(MFVideoFormat_H263, FCC('H263'));
#endif /* WINVER >= _WIN32_WINNT_WIN8 */

DEFINE_GUID(MFVideoFormat_MPEG2,0xe06d8026, 0xdb46, 0x11cf, 0xb4, 0xd1, 0x00, 0x80, 0x5f, 0x6c, 0xbb, 0xea);

#define MFVideoFormat_MPG2 MFVideoFormat_MPEG2

DEFINE_MEDIATYPE_GUID(MFAudioFormat_Base, 0x00000000);
DEFINE_MEDIATYPE_GUID(MFAudioFormat_PCM, WAVE_FORMAT_PCM);
DEFINE_MEDIATYPE_GUID(MFAudioFormat_Float, WAVE_FORMAT_IEEE_FLOAT);
DEFINE_MEDIATYPE_GUID(MFAudioFormat_DTS, WAVE_FORMAT_DTS);
DEFINE_MEDIATYPE_GUID(MFAudioFormat_Dolby_AC3_SPDIF, WAVE_FORMAT_DOLBY_AC3_SPDIF);
DEFINE_MEDIATYPE_GUID(MFAudioFormat_DRM, WAVE_FORMAT_DRM);
DEFINE_MEDIATYPE_GUID(MFAudioFormat_WMAudioV8, WAVE_FORMAT_WMAUDIO2);
DEFINE_MEDIATYPE_GUID(MFAudioFormat_WMAudioV9, WAVE_FORMAT_WMAUDIO3);
DEFINE_MEDIATYPE_GUID(MFAudioFormat_WMAudio_Lossless, WAVE_FORMAT_WMAUDIO_LOSSLESS);
DEFINE_MEDIATYPE_GUID(MFAudioFormat_WMASPDIF, WAVE_FORMAT_WMASPDIF);
DEFINE_MEDIATYPE_GUID(MFAudioFormat_MSP1, WAVE_FORMAT_WMAVOICE9);
DEFINE_MEDIATYPE_GUID(MFAudioFormat_MP3, WAVE_FORMAT_MPEGLAYER3);
DEFINE_MEDIATYPE_GUID(MFAudioFormat_MPEG, WAVE_FORMAT_MPEG);
DEFINE_MEDIATYPE_GUID(MFAudioFormat_AAC, WAVE_FORMAT_MPEG_HEAAC);
DEFINE_MEDIATYPE_GUID(MFAudioFormat_ADTS, WAVE_FORMAT_MPEG_ADTS_AAC);

DEFINE_GUID(MFMPEG4Format_Base,0x00000000, 0x767a, 0x494d, 0xb4, 0x78, 0xf2, 0x9d, 0x25, 0xdc, 0x90, 0x37);
DEFINE_GUID(MF_MT_MAJOR_TYPE,0x48eba18e, 0xf8c9, 0x4687, 0xbf, 0x11, 0x0a, 0x74, 0xc9, 0xf9, 0x6a, 0x8f);
DEFINE_GUID(MF_MT_SUBTYPE,0xf7e34c9a, 0x42e8, 0x4714, 0xb7, 0x4b, 0xcb, 0x29, 0xd7, 0x2c, 0x35, 0xe5);
DEFINE_GUID(MF_MT_ALL_SAMPLES_INDEPENDENT,0xc9173739, 0x5e56, 0x461c, 0xb7, 0x13, 0x46, 0xfb, 0x99, 0x5c, 0xb9, 0x5f);
DEFINE_GUID(MF_MT_FIXED_SIZE_SAMPLES,0xb8ebefaf, 0xb718, 0x4e04, 0xb0, 0xa9, 0x11, 0x67, 0x75, 0xe3, 0x32, 0x1b);
DEFINE_GUID(MF_MT_COMPRESSED,0x3afd0cee, 0x18f2, 0x4ba5, 0xa1, 0x10, 0x8b, 0xea, 0x50, 0x2e, 0x1f, 0x92);
DEFINE_GUID(MF_MT_SAMPLE_SIZE,0xdad3ab78, 0x1990, 0x408b, 0xbc, 0xe2, 0xeb, 0xa6, 0x73, 0xda, 0xcc, 0x10);
DEFINE_GUID(MF_MT_WRAPPED_TYPE,0x4d3f7b23, 0xd02f, 0x4e6c, 0x9b, 0xee, 0xe4, 0xbf, 0x2c, 0x6c, 0x69, 0x5d);

#if (WINVER >= _WIN32_WINNT_WIN8)

DEFINE_GUID( MF_MT_VIDEO_3D, 0xcb5e88cf, 0x7b5b, 0x476b, 0x85, 0xaa, 0x1c, 0xa5, 0xae, 0x18, 0x75, 0x55);

typedef enum _MFVideo3DFormat {
    MFVideo3DSampleFormat_BaseView = 0,
    MFVideo3DSampleFormat_MultiView = 1,
    MFVideo3DSampleFormat_Packed_LeftRight = 2,
    MFVideo3DSampleFormat_Packed_TopBottom = 3,
} MFVideo3DFormat;

DEFINE_GUID(MF_MT_VIDEO_3D_FORMAT, 0x5315d8a0, 0x87c5, 0x4697, 0xb7, 0x93, 0x66, 0x6, 0xc6, 0x7c, 0x4, 0x9b);
DEFINE_GUID( MF_MT_VIDEO_3D_NUM_VIEWS, 0xbb077e8a, 0xdcbf, 0x42eb, 0xaf, 0x60, 0x41, 0x8d, 0xf9, 0x8a, 0xa4, 0x95);
DEFINE_GUID( MF_MT_VIDEO_3D_LEFT_IS_BASE, 0x6d4b7bff, 0x5629, 0x4404, 0x94, 0x8c, 0xc6, 0x34, 0xf4, 0xce, 0x26, 0xd4);
DEFINE_GUID( MF_MT_VIDEO_3D_FIRST_IS_LEFT, 0xec298493, 0xada, 0x4ea1, 0xa4, 0xfe, 0xcb, 0xbd, 0x36, 0xce, 0x93, 0x31);
DEFINE_GUID( MFSampleExtension_3DVideo, 0xf86f97a4, 0xdd54, 0x4e2e, 0x9a, 0x5e, 0x55, 0xfc, 0x2d, 0x74, 0xa0, 0x05);

typedef enum _MFVideo3DSampleFormat {
    MFSampleExtension_3DVideo_MultiView = 1,
    MFSampleExtension_3DVideo_Packed = 0,
} MFVideo3DSampleFormat;

DEFINE_GUID( MFSampleExtension_3DVideo_SampleFormat, 0x8671772, 0xe36f, 0x4cff, 0x97, 0xb3, 0xd7, 0x2e, 0x20, 0x98, 0x7a, 0x48);

typedef enum _MFVideoRotationFormat {
    MFVideoRotationFormat_0 = 0,
    MFVideoRotationFormat_90 = 90,
    MFVideoRotationFormat_180 = 180,
    MFVideoRotationFormat_270 = 270,
} MFVideoRotationFormat;

DEFINE_GUID(MF_MT_VIDEO_ROTATION, 0xc380465d, 0x2271, 0x428c, 0x9b, 0x83, 0xec, 0xea, 0x3b, 0x4a, 0x85, 0xc1);

#endif /* WINVER >= _WIN32_WINNT_WIN8 */

DEFINE_GUID(MF_MT_AUDIO_NUM_CHANNELS,0x37e48bf5, 0x645e, 0x4c5b, 0x89, 0xde, 0xad, 0xa9, 0xe2, 0x9b, 0x69, 0x6a);
DEFINE_GUID(MF_MT_AUDIO_SAMPLES_PER_SECOND,0x5faeeae7, 0x0290, 0x4c31, 0x9e, 0x8a, 0xc5, 0x34, 0xf6, 0x8d, 0x9d, 0xba);
DEFINE_GUID(MF_MT_AUDIO_FLOAT_SAMPLES_PER_SECOND,0xfb3b724a, 0xcfb5, 0x4319, 0xae, 0xfe, 0x6e, 0x42, 0xb2, 0x40, 0x61, 0x32);
DEFINE_GUID(MF_MT_AUDIO_AVG_BYTES_PER_SECOND,0x1aab75c8, 0xcfef, 0x451c, 0xab, 0x95, 0xac, 0x03, 0x4b, 0x8e, 0x17, 0x31);
DEFINE_GUID(MF_MT_AUDIO_BLOCK_ALIGNMENT,0x322de230, 0x9eeb, 0x43bd, 0xab, 0x7a, 0xff, 0x41, 0x22, 0x51, 0x54, 0x1d);
DEFINE_GUID(MF_MT_AUDIO_BITS_PER_SAMPLE,0xf2deb57f, 0x40fa, 0x4764, 0xaa, 0x33, 0xed, 0x4f, 0x2d, 0x1f, 0xf6, 0x69);
DEFINE_GUID(MF_MT_AUDIO_VALID_BITS_PER_SAMPLE,0xd9bf8d6a, 0x9530, 0x4b7c, 0x9d, 0xdf, 0xff, 0x6f, 0xd5, 0x8b, 0xbd, 0x06);
DEFINE_GUID(MF_MT_AUDIO_SAMPLES_PER_BLOCK,0xaab15aac, 0xe13a, 0x4995, 0x92, 0x22, 0x50, 0x1e, 0xa1, 0x5c, 0x68, 0x77);
DEFINE_GUID(MF_MT_AUDIO_CHANNEL_MASK,0x55fb5765, 0x644a, 0x4caf, 0x84, 0x79, 0x93, 0x89, 0x83, 0xbb, 0x15, 0x88);

DEFINE_GUID(MF_MT_AUDIO_FOLDDOWN_MATRIX,0x9d62927c, 0x36be, 0x4cf2, 0xb5, 0xc4, 0xa3, 0x92, 0x6e, 0x3e, 0x87, 0x11);
DEFINE_GUID(MF_MT_AUDIO_WMADRC_PEAKREF,0x9d62927d, 0x36be, 0x4cf2, 0xb5, 0xc4, 0xa3, 0x92, 0x6e, 0x3e, 0x87, 0x11);
DEFINE_GUID(MF_MT_AUDIO_WMADRC_PEAKTARGET,0x9d62927e, 0x36be, 0x4cf2, 0xb5, 0xc4, 0xa3, 0x92, 0x6e, 0x3e, 0x87, 0x11);
DEFINE_GUID(MF_MT_AUDIO_WMADRC_AVGREF,0x9d62927f, 0x36be, 0x4cf2, 0xb5, 0xc4, 0xa3, 0x92, 0x6e, 0x3e, 0x87, 0x11);
DEFINE_GUID(MF_MT_AUDIO_WMADRC_AVGTARGET,0x9d629280, 0x36be, 0x4cf2, 0xb5, 0xc4, 0xa3, 0x92, 0x6e, 0x3e, 0x87, 0x11);
DEFINE_GUID(MF_MT_AUDIO_PREFER_WAVEFORMATEX,0xa901aaba, 0xe037, 0x458a, 0xbd, 0xf6, 0x54, 0x5b, 0xe2, 0x07, 0x40, 0x42);

#if (WINVER >= _WIN32_WINNT_WIN7)
DEFINE_GUID(MF_MT_AAC_PAYLOAD_TYPE,0xbfbabe79, 0x7434, 0x4d1c, 0x94, 0xf0, 0x72, 0xa3, 0xb9, 0xe1, 0x71, 0x88);
DEFINE_GUID(MF_MT_AAC_AUDIO_PROFILE_LEVEL_INDICATION,0x7632f0e6, 0x9538, 0x4d61, 0xac, 0xda, 0xea, 0x29, 0xc8, 0xc1, 0x44, 0x56);
#endif /* WINVER >= _WIN32_WINNT_WIN7 */

DEFINE_GUID(MF_MT_FRAME_SIZE,0x1652c33d, 0xd6b2, 0x4012, 0xb8, 0x34, 0x72, 0x03, 0x08, 0x49, 0xa3, 0x7d);
DEFINE_GUID(MF_MT_FRAME_RATE,0xc459a2e8, 0x3d2c, 0x4e44, 0xb1, 0x32, 0xfe, 0xe5, 0x15, 0x6c, 0x7b, 0xb0);
DEFINE_GUID(MF_MT_PIXEL_ASPECT_RATIO,0xc6376a1e, 0x8d0a, 0x4027, 0xbe, 0x45, 0x6d, 0x9a, 0x0a, 0xd3, 0x9b, 0xb6);
DEFINE_GUID(MF_MT_DRM_FLAGS,0x8772f323, 0x355a, 0x4cc7, 0xbb, 0x78, 0x6d, 0x61, 0xa0, 0x48, 0xae, 0x82);

#if (WINVER >= _WIN32_WINNT_WIN8)
DEFINE_GUID(MF_MT_TIMESTAMP_CAN_BE_DTS, 0x24974215, 0x1b7b, 0x41e4, 0x86, 0x25, 0xac, 0x46, 0x9f, 0x2d, 0xed, 0xaa);
#endif /* WINVER >= _WIN32_WINNT_WIN8 */

DEFINE_GUID(MF_MT_PAD_CONTROL_FLAGS,0x4d0e73e5, 0x80ea, 0x4354, 0xa9, 0xd0, 0x11, 0x76, 0xce, 0xb0, 0x28, 0xea);

DEFINE_GUID(MF_MT_SOURCE_CONTENT_HINT,0x68aca3cc, 0x22d0, 0x44e6, 0x85, 0xf8, 0x28, 0x16, 0x71, 0x97, 0xfa, 0x38);

DEFINE_GUID(MF_MT_VIDEO_CHROMA_SITING,0x65df2370, 0xc773, 0x4c33, 0xaa, 0x64, 0x84, 0x3e, 0x06, 0x8e, 0xfb, 0x0c);
DEFINE_GUID(MF_MT_INTERLACE_MODE,0xe2724bb8, 0xe676, 0x4806, 0xb4, 0xb2, 0xa8, 0xd6, 0xef, 0xb4, 0x4c, 0xcd);
DEFINE_GUID(MF_MT_TRANSFER_FUNCTION,0x5fb0fce9, 0xbe5c, 0x4935, 0xa8, 0x11, 0xec, 0x83, 0x8f, 0x8e, 0xed, 0x93);
DEFINE_GUID(MF_MT_VIDEO_PRIMARIES,0xdbfbe4d7, 0x0740, 0x4ee0, 0x81, 0x92, 0x85, 0x0a, 0xb0, 0xe2, 0x19, 0x35);
DEFINE_GUID(MF_MT_CUSTOM_VIDEO_PRIMARIES,0x47537213, 0x8cfb, 0x4722, 0xaa, 0x34, 0xfb, 0xc9, 0xe2, 0x4d, 0x77, 0xb8);

DEFINE_GUID(MF_MT_YUV_MATRIX,0x3e23d450, 0x2c75, 0x4d25, 0xa0, 0x0e, 0xb9, 0x16, 0x70, 0xd1, 0x23, 0x27);
DEFINE_GUID(MF_MT_VIDEO_LIGHTING,0x53a0529c, 0x890b, 0x4216, 0x8b, 0xf9, 0x59, 0x93, 0x67, 0xad, 0x6d, 0x20);
DEFINE_GUID(MF_MT_VIDEO_NOMINAL_RANGE,0xc21b8ee5, 0xb956, 0x4071, 0x8d, 0xaf, 0x32, 0x5e, 0xdf, 0x5c, 0xab, 0x11);
DEFINE_GUID(MF_MT_GEOMETRIC_APERTURE,0x66758743, 0x7e5f, 0x400d, 0x98, 0x0a, 0xaa, 0x85, 0x96, 0xc8, 0x56, 0x96);
DEFINE_GUID(MF_MT_MINIMUM_DISPLAY_APERTURE,0xd7388766, 0x18fe, 0x48c6, 0xa1, 0x77, 0xee, 0x89, 0x48, 0x67, 0xc8, 0xc4);
DEFINE_GUID(MF_MT_PAN_SCAN_APERTURE,0x79614dde, 0x9187, 0x48fb, 0xb8, 0xc7, 0x4d, 0x52, 0x68, 0x9d, 0xe6, 0x49);
DEFINE_GUID(MF_MT_PAN_SCAN_ENABLED,0x4b7f6bc3, 0x8b13, 0x40b2, 0xa9, 0x93, 0xab, 0xf6, 0x30, 0xb8, 0x20, 0x4e);
DEFINE_GUID(MF_MT_AVG_BITRATE,0x20332624, 0xfb0d, 0x4d9e, 0xbd, 0x0d, 0xcb, 0xf6, 0x78, 0x6c, 0x10, 0x2e);
DEFINE_GUID(MF_MT_AVG_BIT_ERROR_RATE,0x799cabd6, 0x3508, 0x4db4, 0xa3, 0xc7, 0x56, 0x9c, 0xd5, 0x33, 0xde, 0xb1);
DEFINE_GUID(MF_MT_MAX_KEYFRAME_SPACING,0xc16eb52b, 0x73a1, 0x476f, 0x8d, 0x62, 0x83, 0x9d, 0x6a, 0x02, 0x06, 0x52);
DEFINE_GUID(MF_MT_DEFAULT_STRIDE,0x644b4e48, 0x1e02, 0x4516, 0xb0, 0xeb, 0xc0, 0x1c, 0xa9, 0xd4, 0x9a, 0xc6);
DEFINE_GUID(MF_MT_PALETTE,0x6d283f42, 0x9846, 0x4410, 0xaf, 0xd9, 0x65, 0x4d, 0x50, 0x3b, 0x1a, 0x54);
DEFINE_GUID(MF_MT_USER_DATA,0xb6bc765f, 0x4c3b, 0x40a4, 0xbd, 0x51, 0x25, 0x35, 0xb6, 0x6f, 0xe0, 0x9d);
DEFINE_GUID(MF_MT_AM_FORMAT_TYPE,0x73d1072d, 0x1870, 0x4174, 0xa0, 0x63, 0x29, 0xff, 0x4f, 0xf6, 0xc1, 0x1e);
DEFINE_GUID(MF_MT_MPEG_START_TIME_CODE,0x91f67885, 0x4333, 0x4280, 0x97, 0xcd, 0xbd, 0x5a, 0x6c, 0x03, 0xa0, 0x6e);
DEFINE_GUID(MF_MT_MPEG2_PROFILE,0xad76a80b, 0x2d5c, 0x4e0b, 0xb3, 0x75, 0x64, 0xe5, 0x20, 0x13, 0x70, 0x36);
DEFINE_GUID(MF_MT_MPEG2_LEVEL,0x96f66574, 0x11c5, 0x4015, 0x86, 0x66, 0xbf, 0xf5, 0x16, 0x43, 0x6d, 0xa7);
DEFINE_GUID(MF_MT_MPEG2_FLAGS,0x31e3991d, 0xf701, 0x4b2f, 0xb4, 0x26, 0x8a, 0xe3, 0xbd, 0xa9, 0xe0, 0x4b);
DEFINE_GUID(MF_MT_MPEG_SEQUENCE_HEADER,0x3c036de7, 0x3ad0, 0x4c9e, 0x92, 0x16, 0xee, 0x6d, 0x6a, 0xc2, 0x1c, 0xb3);
DEFINE_GUID(MF_MT_DV_AAUX_SRC_PACK_0,0x84bd5d88, 0x0fb8, 0x4ac8, 0xbe, 0x4b, 0xa8, 0x84, 0x8b, 0xef, 0x98, 0xf3);
DEFINE_GUID(MF_MT_DV_AAUX_CTRL_PACK_0,0xf731004e, 0x1dd1, 0x4515, 0xaa, 0xbe, 0xf0, 0xc0, 0x6a, 0xa5, 0x36, 0xac);
DEFINE_GUID(MF_MT_DV_AAUX_SRC_PACK_1,0x720e6544, 0x0225, 0x4003, 0xa6, 0x51, 0x01, 0x96, 0x56, 0x3a, 0x95, 0x8e);
DEFINE_GUID(MF_MT_DV_AAUX_CTRL_PACK_1,0xcd1f470d, 0x1f04, 0x4fe0, 0xbf, 0xb9, 0xd0, 0x7a, 0xe0, 0x38, 0x6a, 0xd8);
DEFINE_GUID(MF_MT_DV_VAUX_SRC_PACK,0x41402d9d, 0x7b57, 0x43c6, 0xb1, 0x29, 0x2c, 0xb9, 0x97, 0xf1, 0x50, 0x09);
DEFINE_GUID(MF_MT_DV_VAUX_CTRL_PACK,0x2f84e1c4, 0x0da1, 0x4788, 0x93, 0x8e, 0x0d, 0xfb, 0xfb, 0xb3, 0x4b, 0x48);

#if (WINVER >= _WIN32_WINNT_WIN7)
DEFINE_GUID(MF_MT_ARBITRARY_HEADER,0x9e6bd6f5, 0x109, 0x4f95, 0x84, 0xac, 0x93, 0x9, 0x15, 0x3a, 0x19, 0xfc );
DEFINE_GUID(MF_MT_ARBITRARY_FORMAT,0x5a75b249, 0xd7d, 0x49a1, 0xa1, 0xc3, 0xe0, 0xd8, 0x7f, 0xc, 0xad, 0xe5);
DEFINE_GUID(MF_MT_IMAGE_LOSS_TOLERANT,0xed062cf4, 0xe34e, 0x4922, 0xbe, 0x99, 0x93, 0x40, 0x32, 0x13, 0x3d, 0x7c);
DEFINE_GUID(MF_MT_MPEG4_SAMPLE_DESCRIPTION,0x261e9d83, 0x9529, 0x4b8f, 0xa1, 0x11, 0x8b, 0x9c, 0x95, 0x0a, 0x81, 0xa9);
DEFINE_GUID(MF_MT_MPEG4_CURRENT_SAMPLE_ENTRY,0x9aa7e155, 0xb64a, 0x4c1d, 0xa5, 0x00, 0x45, 0x5d, 0x60, 0x0b, 0x65, 0x60);
DEFINE_GUID(MF_MT_ORIGINAL_4CC,0xd7be3fe0, 0x2bc7, 0x492d, 0xb8, 0x43, 0x61, 0xa1, 0x91, 0x9b, 0x70, 0xc3);
DEFINE_GUID(MF_MT_ORIGINAL_WAVE_FORMAT_TAG,0x8cbbc843, 0x9fd9, 0x49c2, 0x88, 0x2f, 0xa7, 0x25, 0x86, 0xc4, 0x08, 0xad);
DEFINE_GUID(MF_MT_FRAME_RATE_RANGE_MIN,0xd2e7558c, 0xdc1f, 0x403f, 0x9a, 0x72, 0xd2, 0x8b, 0xb1, 0xeb, 0x3b, 0x5e);
DEFINE_GUID(MF_MT_FRAME_RATE_RANGE_MAX, 0xe3371d41, 0xb4cf, 0x4a05, 0xbd, 0x4e, 0x20, 0xb8, 0x8b, 0xb2, 0xc4, 0xd6);
#endif /* WINVER >= _WIN32_WINNT_WIN7 */

#if (WINVER >= _WIN32_WINNT_WIN8)
DEFINE_GUID(MF_LOW_LATENCY, 0x9c27891a, 0xed7a, 0x40e1, 0x88, 0xe8, 0xb2, 0x27, 0x27, 0xa0, 0x24, 0xee);
DEFINE_GUID(MF_VIDEO_MAX_MB_PER_SEC, 0xe3f2e203, 0xd445, 0x4b8c, 0x92, 0x11, 0xae, 0x39, 0xd, 0x3b, 0xa0, 0x17);
#endif /* WINVER >= _WIN32_WINNT_WIN8 */

DEFINE_GUID(MFMediaType_Default,0x81A412E6, 0x8103, 0x4B06, 0x85, 0x7F, 0x18, 0x62, 0x78, 0x10, 0x24, 0xAC);
DEFINE_GUID(MFMediaType_Audio,0x73647561, 0x0000, 0x0010, 0x80, 0x00, 0x00, 0xAA, 0x00, 0x38, 0x9B, 0x71);
DEFINE_GUID(MFMediaType_Video,0x73646976, 0x0000, 0x0010, 0x80, 0x00, 0x00, 0xAA, 0x00, 0x38, 0x9B, 0x71);
DEFINE_GUID(MFMediaType_Protected,0x7b4b6fe6, 0x9d04, 0x4494, 0xbe, 0x14, 0x7e, 0x0b, 0xd0, 0x76, 0xc8, 0xe4);
DEFINE_GUID(MFMediaType_SAMI,0xe69669a0, 0x3dcd, 0x40cb, 0x9e, 0x2e, 0x37, 0x08, 0x38, 0x7c, 0x06, 0x16);
DEFINE_GUID(MFMediaType_Script,0x72178C22, 0xE45B, 0x11D5, 0xBC, 0x2A, 0x00, 0xB0, 0xD0, 0xF3, 0xF4, 0xAB);
DEFINE_GUID(MFMediaType_Image,0x72178C23, 0xE45B, 0x11D5, 0xBC, 0x2A, 0x00, 0xB0, 0xD0, 0xF3, 0xF4, 0xAB);
DEFINE_GUID(MFMediaType_HTML,0x72178C24, 0xE45B, 0x11D5, 0xBC, 0x2A, 0x00, 0xB0, 0xD0, 0xF3, 0xF4, 0xAB);
DEFINE_GUID(MFMediaType_Binary,0x72178C25, 0xE45B, 0x11D5, 0xBC, 0x2A, 0x00, 0xB0, 0xD0, 0xF3, 0xF4, 0xAB);
DEFINE_GUID(MFMediaType_FileTransfer,0x72178C26, 0xE45B, 0x11D5, 0xBC, 0x2A, 0x00, 0xB0, 0xD0, 0xF3, 0xF4, 0xAB);
DEFINE_GUID(AM_MEDIA_TYPE_REPRESENTATION,0xe2e42ad2, 0x132c, 0x491e, 0xa2, 0x68, 0x3c, 0x7c, 0x2d, 0xca, 0x18, 0x1f);
DEFINE_GUID(FORMAT_MFVideoFormat,0xaed4ab2d, 0x7326, 0x43cb, 0x94, 0x64, 0xc8, 0x79, 0xca, 0xb9, 0xc4, 0x3d);

EXTERN_C const GUID MR_BUFFER_SERVICE;

EXTERN_C void *WINAPI MFHeapAlloc(size_t, ULONG, char *, int, EAllocationType);
EXTERN_C void WINAPI MFHeapFree(void *);

DEFINE_GUID(CLSID_MFSourceResolver, 0x90eab60f, 0xe43a, 0x4188, 0xbc, 0xc4, 0xe4, 0x7f, 0xdf, 0x04, 0x86, 0x8c);

#if (WINVER >= _WIN32_WINNT_WIN7)
LONGLONG WINAPI MFllMulDiv(LONGLONG a, LONGLONG b, LONGLONG c, LONGLONG d);
#endif /* WINVER >= _WIN32_WINNT_WIN7 */

#if defined(__cplusplus)
}
#endif

#endif /* _MFAPI_H */
