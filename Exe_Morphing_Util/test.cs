using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using System.Runtime.InteropServices;
using System.Security;

namespace Exe_Morphing_Util
{
    public unsafe class ImportTableConstructor
    {
        private IDictionary<ModuleName, List<string>> ImportTable;

        private IDictionary<ModuleName, List<string>> Modules;

        public ImportTableConstructor()
        {
            ImportTable = new Dictionary<ModuleName, List<string>>();
            Modules = new Dictionary<ModuleName, List<string>>();

            InitModules();
        }

        private void InitModules()
        {
            var Modules = Enum.GetValues(typeof(ModuleName));

            foreach (var Module in Modules)
            {
                string LibraryName = String.Concat(Enum.GetName(typeof(ModuleName), Module), ".dll");

                switch (LibraryName)
                {
                    case "KERNEL32.dll":
                        AddFunctionsToModule(ModuleName.KERNEL32, str_Kernel32Functions);
                        break;
                    //case "MSVCRT.dll":
                    //    AddFunctionsToModule(ModuleName.MSVCRT, str_MSVCRTFunctions);
                    //    break;
                    case "ADVAPI32.dll":
                        AddFunctionsToModule(ModuleName.ADVAPI32, str_Advapi32Functions);
                        break;
                    case "USER32.dll":
                        AddFunctionsToModule(ModuleName.USER32, str_User32Functions);
                        break;
                    //case "NTDSAPI.dll":
                    //    AddFunctionsToModule(ModuleName.NTDSAPI, str_NtdsapiFunctions);
                    //    break;
                    case "OLE32.dll":
                        AddFunctionsToModule(ModuleName.OLE32, str_Ole32Functions);
                        break;
                    //case "NTDLL.dll":
                    //    AddFunctionsToModule(ModuleName.NTDLL, str_NTDLLFunctions);
                    //    break;
                    case "GDI32.dll":
                        AddFunctionsToModule(ModuleName.GDI32, str_GDI32Functions);
                        break;
                    //case "COMCTL32.dll":
                    //    AddFunctionsToModule(ModuleName.COMCTL32, str_ComCtl32Functions);
                    //    break;
                    //case "CRYPT32.dll":
                    //    AddFunctionsToModule(ModuleName.CRYPT32, str_Crypt32Functions);
                    //    break;
                }
            }
        }

        private void AddFunctionsToModule(ModuleName Module, string[] Functions)
        {
            Modules.Add(Module, new List<string>(Functions));//where do you do the section addrs
        }

        #region Module Names

        public enum ModuleName
        {
            KERNEL32,
            //  MSVCRT,
            ADVAPI32,
            USER32,
            OLE32,
            //    NTDLL,
            GDI32,
            // COMCTL32,
            // CRYPT32,
            //   NTDSAPI
        }

        private string[] ModuleNames = new string[]
        {
            "KERNEL32",
       //    "MSVCRT",
          "ADVAPI32",
           "USER32",
            "OLE32",
          //  "NTDLL",
            "GDI32",
        //  "COMCTL32",
          //  "CRYPT32",
         //  "NTDSAPI"
        };

        #endregion

        #region Kernel32 Functions

        private string[] str_Kernel32Functions = new string[]
        {
            //"GetCurrentThreadId",
            //"QueryPerformanceCounter",
            //"GetSystemTimeAsFileTime",
            //"GetSystemTimeAsFileTime",
            //"GetCurrentProcess",
            "GetTickCount",
            "Sleep",
            "SetUnhandledExceptionFilter",
            "UnhandledExceptionFilter",
            //"GetSystemTime",
            "WriteConsoleW",
            "OutputDebugStringW",
            "GetCommandLineA",
            "GetCommandLineW",
            "MulDiv",
            "GetConsoleMode",
            "SetErrorMode",
            //"VirtualAlloc",
            //"VirtualFree",
            //"GetSystemInfo",
            //"ExpandEnvironmentStringsA",
            //"ExpandEnvironmentStringsW",
            //"GlobalFree",
            //"FindClose",
            //"HeapSize",
            //"ResetEvent",
            "lstrcmpW",
            "lstrcmpA",
            "lstrcatA",
            "lstrcatW",
            "lstrcpyA",
            "lstrcpyW",
            "lstrlenA",
            "lstrlenW",
            "GetStdHandle",
           // "HeapCreate",
           // "GlobalLock",
           // "FileTimeToSystemTime",
           //"VirtualQuery",
            "ExitProcess" ,
          //"HeapDestroy",
          "GetStringTypeW",
          "GetStringTypeA",
          "LCMapStringW",
          //"GetModuleHandleA",
          //"GetStartupInfoA",
          //"GetCommandLineA",
          //"GetVersion",
          //"ExitProcess",
          //"TerminateProcess",
          //"GetCurrentProcess",
          "UnhandledExceptionFilter",
         // "GetModuleFileNameA",
          "FreeEnvironmentStringsA",
          "FreeEnvironmentStringsW",
          "WideCharToMultiByte",
          "GetEnvironmentStrings",
          "GetEnvironmentStringsW",
          //"GetStdHandle",
          //"GetFileType",
          //"HeapCreate",
          //"VirtualFree",
          //"HeapFree",
          //"RtlUnwind",
          //"WriteFile",
          //"GetCPInfo",
          //"GetACP",
          "GetOEMCP",
          "HeapAlloc",
          //"VirtualAlloc",
          //"HeapReAlloc",
          //"GetProcAddress",
          //"LoadLibraryA",
          //"MultiByteToWideChar",
          "LCMapStringA"
        };

        #endregion

        #region MSVCRT Functions

        private string[] str_MSVCRTFunctions = new string[]
        {
            "_except_handler3",
            "_initterm",
            "_adjust_fdiv",
            "free",
            "malloc",
            "wcslen",
            "wcscpy",
            "memcpy",
            "_wcsicmp",
            "wcscat",
            "_purecall",
            "wcscmp",
            "_onexit",
            "__dllonexit",
            "wcschr",
            "__CxxFrameHandler",
            "memmove",
            "swprintf",
            "wcsncpy",
            "sprintf",
            "exit",
            "_controlfp",
            "_XcptFilter",
            "_exit",
            "__set_app_type",
            "__p__fmode",
            "__p__commode",
            "__setusermatherr",
            "_cexit",
            "wcsrchr",
            "__setusermatherr",
            "_ftol",
            "_CxxThrowException",
            "wcsncmp",
            "_wtoi",
            "strncpy",
            "_wtol",
            "strchr",
            "time",
            "_stricmp",
            "??3@YAXPAX@Z",
            "??2@YAPAXI@Z"
        };

        #endregion

        #region AdvApi32 Functions

        private string[] str_Advapi32Functions = new string[]
        {
            "RegCloseKey",
            "RegOpenKeyExW",
            "RegQueryValueExW",
            "RegSetValueExW",
            "RegCreateKeyExW",
            "RegEnumKeyExW",
            "RegDeleteValueW",
            "RegQueryInfoKeyW",
            "OpenProcessToken",
            "RegOpenKeyExA",
            "RegOpenKeyExA",
            "RegQueryValueExA",
            "GetTraceLoggerHandle",
            "GetTraceEnableLevel",
            "UnregisterTraceGuids",
            "GetTraceEnableFlags",
            "GetTokenInformation",
            "RegisterTraceGuidsW",
            "TraceMessage",
            "RegDeleteKeyW",
            "RegEnumValueW",
            "AllocateAndInitializeSid",
            "RegSetValueExA",
            "FreeSid",
            "GetLengthSid",
            "OpenThreadToken",
            "IsValidSid",
            "AdjustTokenPrivileges",
            "CloseServiceHandle",
            "RegCreateKeyExA",
            "InitializeSecurityDescriptor",
            "SetSecurityDescriptorDacl",
            "OpenSCManagerW",
            "EqualSid",
            "CheckTokenMembership",
            "ConvertStringSecurityDescriptorToSecurityDescriptorW",
            "OpenServiceW",
            "ConvertSidToStringSidW",
            "LookupPrivilegeValueW",
            "GetSidSubAuthority",
            "InitializeAcl",
            "CopySid",
            "GetSidSubAuthorityCount",
            "RegEnumKeyW",
            "DeregisterEventSource",
            "RegEnumKeyExA",
            "CryptAcquireContextW",
            "RegGetValueW",
            "LookupAccountSidW",
            "QueryServiceStatus",
            "ConvertStringSidToSidW"
        };

        #endregion

        #region User32 Functions

        private string[] str_User32Functions = new string[]
        {
            "MessageBoxA",
            "LoadIconA",
            "LoadStringA",
            "LoadCursorA",
            "SetWindowTextA",
            "SetForegroundWindow",
            "RegisterClassExA",
            "SendMessageW",
            "CharNextW",
            "GetWindowLongW",
            "SetWindowLongW",
            "PostMessageW",
            "GetSystemMetrics",
            "DestroyWindow",
            "GetClientRect",
            "GetDC",
            "GetWindowRect",
            "ReleaseDC",
            "GetDlgItem",
            "UnregisterClassA",
            "GetParent",
            "ShowWindow",
            "EnableWindow",
            "LoadCursorW",
            "DispatchMessageW",
            "DefWindowProcW",
            "CreateWindowExW",
            "TranslateMessage",
            "MessageBoxW",
            "SetWindowPos",
            "EndDialog",
            "IsWindow",
            "SetFocus",
            "PeekMessageW",
            "SetTimer",
            "SetCursor",
            "SetWindowTextW",
            "KillTimer",
            "DestroyIcon",
            "DialogBoxParamW",
            "GetDesktopWindow",
            "SetDlgItemTextW",
            "InvalidateRect",
            "LoadIconW",
            "LoadImageW",
            "GetSysColor",
            "GetWindowTextW",
            "GetFocus",
            "SystemParametersInfoW",
            "GetMessageW",
            "MapWindowPoints",
            "SetForegroundWindow",
            "BeginPaint",
            "EndPaint",
            "SendDlgItemMessageW",
            "FillRect",
            "GetWindow",
            "RegisterClassW",
            "IsDlgButtonChecked",
            "IsWindowVisible",
            "GetKeyState",
            "PostQuitMessage",
            "MsgWaitForMultipleObjects",
            "ScreenToClient",
            "UpdateWindow",
            "CallWindowProcW",
            "MoveWindow",
            "CheckDlgButton",
            "ClientToScreen",
            "RegisterClassExW",
            "UnregisterClassW",
            "IntersectRect",
            "PtInRect",
            "DestroyMenu",
            "GetWindowThreadProcessId",
            "RegisterClipboardFormatW",
            "GetWindowTextLengthW",
            "IsWindowEnabled",
            "RegisterWindowMessageW",
            "SetCapture"
        };

        #endregion

        #region NtdsApi Functions

        private string[] str_NtdsapiFunctions = new string[]
        {
            "DsFreeNameResultA",
            "DsBindA",
            "DsUnBindA",
            "DsMapSchemaGuidsA",
            "DsBindWithCredA",
            "DsFreeSchemaGuidMapA"
        };
        #endregion

        #region Ole32 Functions

        private string[] str_Ole32Functions = new string[]
        {
            "CoCreateInstance",
            "CoTaskMemFree",
            "CoTaskMemAlloc",
            "CoUninitialize",
            "StringFromGUID2",
            "CoInitializeEx",
            "CoTaskMemRealloc",
            "StringFromCLSID",
            "CLSIDFromString",
            "CoInitialize",
            "PropVariantClear",
            "CoCreateGuid",
            "CreateStreamOnHGlobal",
            "CoGetMalloc",
            "ReleaseStgMedium",
            "CoSetProxyBlanket",
            "CLSIDFromProgID",
            "PropVariantCopy",
            "CoCreateFreeThreadedMarshaler",
            "CreateBindCtx",
            "CoRevokeClassObject",
            "CoRegisterClassObject",
            "IIDFromString",
            "CoInitializeSecurity",
            "CoFreeUnusedLibraries",
            "CoMarshalInterThreadInterfaceInStream",
            "OleInitialize",
            "CoDisconnectObject",
            "CoGetObject",
            "ProgIDFromCLSID",
            "GetHGlobalFromStream",
            //"CoImpersonateClient",
        };

        #endregion

        #region NTDLL Functions

        private string[] str_NTDLLFunctions = new string[]
        {
            "RtlNtStatusToDosError",
            "RtlInitUnicodeString",
            "RtlFreeHeap",
            "RtlAllocateHeap",
            "EtwTraceMessage",
            "NtClose",
            "EtwUnregisterTraceGuids",
            "EtwGetTraceLoggerHandle",
            "EtwGetTraceEnableLevel",
            "EtwGetTraceEnableFlags",
            "EtwRegisterTraceGuidsW",
            "RtlUnwind",
            "EtwEventWrite",
            "EtwEventRegister",
            "EtwEventUnregister",
            "WinSqmAddToStream",
            "RtlFreeUnicodeString",
            "NtCreateFile",
            "NtQuerySystemInformation",
            "WinSqmIncrementDWORD",
            "NtQueryInformationToken",
            "NtOpenFile",
            "RtlImageNtHeader",
            "WinSqmSetDWORD",
            "DbgPrint",
            "NtQueryInformationProcess",
            "WinSqmIsOptedIn",
            "RtlInitializeCriticalSection",
            "NtOpenThreadToken",
            "RtlLengthSid",
            "RtlDeleteCriticalSection",
            "EtwEventEnabled",
            "NtQueryInformationFile",
        };

        #endregion

        #region GDI32 Functions

        private string[] str_GDI32Functions = new string[]
        {
            "DeleteObject",
            "SelectObject",
            "DeleteDC",
            "GetDeviceCaps",
            "CreateCompatibleDC",
            "CreateFontIndirectW",
            "GetObjectW",
            "GetStockObject",
            "SetTextColor",
            "SetBkColor",
            "BitBlt",
            "CreateSolidBrush",
            "GetTextExtentPoint32W",
            "SetBkMode",
            "CreateDIBSection",
            "ExtTextOutW",
            "GetTextMetricsW",
            "CreatePen",
            "PatBlt",
            "StretchBlt",
            "MoveToEx",
            "LineTo",
            "CreateDCW",
            "GetDIBits",
            "RestoreDC",
            "SaveDC",
            "CreateRectRgn",
            "CreatePalette",
            "StretchDIBits",
            "TextOutW",
            "GetClipBox",
            "GetTextExtentPointW",
            "GetObjectA",
            "SetWindowExtEx",
            "GetTextColor",
            "SelectClipRgn",
            "DeleteMetaFile",
            "GetPixel",
            "GetSystemPaletteEntries",
            "CreatePatternBrush",
            "OffsetRgn",
            "GetClipRgn",
            "ExcludeClipRect",
            "TranslateCharsetInfo",
            "SetBrushOrgEx",
            "EndDoc",
            "SetViewportExtEx",
            "SetDIBits"
        };

        #endregion

        #region COMCTL32 Functions

        private string[] str_ComCtl32Functions = new string[]
        {
            "InitCommonControlsEx",
            "ImageList_Create",
            "ImageList_Destroy",
            //"ImageList_Add",
            //"CreatePropertySheetPageW",
            //"ImageList_ReplaceIcon",
            "ImageList_Draw",
            "ImageList_LoadImageW",
            "ImageList_LoadImageA",
            "ImageList_GetIconSize",
            "CreateStatusWindowW",
            "CreateStatusWindowA",
            "ImageList_DrawEx",
            "ImageList_GetImageCount",
            "ImageList_Remove",
            "ImageList_SetBkColor",
            "ImageList_CoCreateInstance",
            "CreateToolbarEx",
            "ImageList_AddMasked",
            "ImageList_GetImageInfo",
            "ImageList_GetIcon",
            "ImageList_EndDrag",
            "ImageList_DragLeave",
            "ImageList_DragShowNolock",
            "ImageList_BeginDrag",
            "ImageList_DragEnter",
            "ImageList_DragMove",
            "ImageList_SetOverlayImage",
            "ImageList_SetIconSize"     
        };

        #endregion

        #region CRYPT32 Functions

        private string[] str_Crypt32Functions = new string[]
        {
            "CertFreeCertificateContext",
            "CertCloseStore",
            "CertOpenStore",
            "CertGetCertificateContextProperty",
            "CertFindCertificateInStore",
            "CertVerifyCertificateChainPolicy",
            "CryptUnprotectData",
            "CryptProtectData",
            "CertFreeCertificateChain",
            "CertGetCertificateChain",
            "CertGetNameStringW",
            "CertEnumCertificatesInStore",
            "CertGetEnhancedKeyUsage",
            "CertCreateCertificateContext",
            "CryptDecodeObject",
            "CryptStringToBinaryW",
            "CertFindExtension",
            "CryptDecodeObjectEx",
            "CertAddCertificateContextToStore",
            "CryptFindOIDInfo",
            "CertNameToStrW",
            "CertSetCertificateContextProperty",
            "CryptEnumOIDInfo",
            "CryptMsgClose",
            "CryptMsgGetParam",
            "CryptQueryObject",
            "CertControlStore",
            "CertFreeCTLContext",
            "CertVerifyTimeValidity",
            "CryptEncodeObjectEx",
            "CryptMsgUpdate",
            "CryptMsgOpenToDecode",
            "CertVerifySubjectCertificateContext",
            "CryptHashPublicKeyInfo",
            "CertAddSerializedElementToStore",
            "CryptProtectMemory",
            "CertDuplicateStore",
            "CertFreeCRLContext",
            "CertAddStoreToCollection",
            "CryptUnprotectMemory",
            "CryptStringToBinaryA",
            "CertCompareCertificateName",
            "CryptFormatObject",
            "CertAddCertificateLinkToStore",
            "CryptSignMessage",
            "CryptMsgGetAndVerifySigner",
            "CertGetPublicKeyLength",
            "CertComparePublicKeyInfo",
            "CryptFindCertificateKeyProvInfo",
            "CertGetIntendedKeyUsage",
            "CryptGetOIDFunctionAddress",
            "CertSelectCertificateChains",
            "CertFreeCertificateChainList",
            "CertAddCRLContextToStore",
            "CertDuplicateCRLContext",
            "CertCreateCTLContext",
            "CertFindAttribute",
            "CertCreateCertificateChainEngine",
            "CertSerializeCertificateStoreElement",
            "CryptSIPRetrieveSubjectGuid",
            "CryptVerifyCertificateSignature",
            "CertEnumCertificateContextProperties",
        };

        #endregion

        public void RandomizeImportTable()
        {
            ImportTable.Clear();

            Random R = new Random(Guid.NewGuid().GetHashCode());

            int NumberOfModules = R.Next(4, Modules.Count); // select between 2 & 6 Libraries to gather functions from

            var libs = ModuleNames.ToList().OrderBy(x => R.Next()).Take(NumberOfModules); // select that number of modules randomly

            foreach (string libName in libs)
            {
                ModuleName modName = (ModuleName)Enum.Parse(typeof(ModuleName), libName); // retrieve the modulename

                List<string> available_functions = Modules[modName]; // retrieve the available functions from the module

                int NumberOfFunctions = new Random(Guid.NewGuid().GetHashCode()).Next(
                                     6, 15
                                        ); // retrieve a random number of functions

                List<string> RandomizedFunctions = new List<string>(); // create a new function list

                for (int i = 0; i < NumberOfFunctions; i++)
                    RandomizedFunctions.Add(available_functions[i]); // populate the list with functions from the specified module

                RandomizedFunctions = RandomizedFunctions.OrderBy(x => R.Next()).Distinct().ToList(); // randomize the function order

                ImportTable.Add(modName, RandomizedFunctions); // add the module + functions to the import table
            }
        }

        #region Clone Import Table

        public unsafe class PortableExecutableParser
        {

            private readonly List<string> _exports = new List<string>();
            public IEnumerable<string> Exports { get { return _exports; } }

            private readonly List<Tuple<string, List<string>>> _imports = new List<Tuple<string, List<string>>>();
            public IEnumerable<Tuple<string, List<string>>> Imports { get { return _imports; } }

            public PortableExecutableParser(string path)
            {
                LOADED_IMAGE loadedImage;

                if (MapAndLoad(path, null, out loadedImage, true, true))
                    LoadImports(loadedImage);

                GCHandle gcHandle = GCHandle.Alloc(loadedImage, GCHandleType.Pinned);
                UnMapAndLoad(gcHandle.AddrOfPinnedObject());
                gcHandle.Free();
            }

            private static IntPtr RvaToVa(LOADED_IMAGE loadedImage, uint rva)
            {
                return ImageRvaToVa(loadedImage.FileHeader, loadedImage.MappedAddress, rva, IntPtr.Zero);
            }

            private static IntPtr RvaToVa(LOADED_IMAGE loadedImage, IntPtr rva)
            {
                return RvaToVa(loadedImage, (uint)(rva.ToInt32()));
            }

            private void LoadImports(LOADED_IMAGE loadedImage)
            {
                var hMod = (void*)loadedImage.MappedAddress;

                if (hMod != null)
                {
                    uint size;
                    var pImportDir =
                        (IMAGE_IMPORT_DESCRIPTOR*)
                        ImageDirectoryEntryToData(hMod, false,
                                                            IMAGE_DIRECTORY_ENTRY_IMPORT, out size);
                    if (pImportDir != null)
                    {
                        while (pImportDir->OriginalFirstThunk != 0)
                        {
                            try
                            {
                                var szName = (char*)RvaToVa(loadedImage, pImportDir->Name);
                                string name = Marshal.PtrToStringAnsi((IntPtr)szName);
                                var pr = new Tuple<string, List<string>>(name, new List<string>());
                                _imports.Add(pr);
                                var pThunkOrg = (THUNK_DATA*)RvaToVa(loadedImage, pImportDir->OriginalFirstThunk);
                                while (pThunkOrg->AddressOfData != IntPtr.Zero)
                                {
                                    uint ord;
                                    if ((pThunkOrg->Ordinal & 0x80000000) > 0)
                                    {
                                        ord = pThunkOrg->Ordinal & 0xffff;
                                    }
                                    else
                                    {
                                        var pImageByName =
                                            (IMAGE_IMPORT_BY_NAME*)RvaToVa(loadedImage, pThunkOrg->AddressOfData);

                                        if (
                                            !IsBadReadPtr(pImageByName, (uint)sizeof(IMAGE_IMPORT_BY_NAME)))
                                        {
                                            ord = pImageByName->Hint;
                                            var szImportName = pImageByName->Name;
                                            string sImportName = Marshal.PtrToStringAnsi((IntPtr)szImportName);
                                            pr.Item2.Add(sImportName);
                                        }
                                        else
                                        {
                                            break;
                                        }
                                    }
                                    pThunkOrg++;
                                }
                            }
                            catch (AccessViolationException ) { }

                            pImportDir++;
                        }
                    }
                }
            }

            private const ushort IMAGE_DIRECTORY_ENTRY_IMPORT = 1;
            private const ushort IMAGE_DIRECTORY_ENTRY_EXPORT = 0;

            private const CallingConvention WINAPI = CallingConvention.Winapi;

            private const string KERNEL_DLL = "kernel32";
            private const string DBGHELP_DLL = "Dbghelp";
            private const string IMAGEHLP_DLL = "ImageHlp";

            [DllImport(KERNEL_DLL, CallingConvention = WINAPI, EntryPoint = "GetModuleHandleA"), SuppressUnmanagedCodeSecurity]
            public static extern void* GetModuleHandleA(/*IN*/ char* lpModuleName);

            [DllImport(KERNEL_DLL, CallingConvention = WINAPI, EntryPoint = "GetModuleHandleW"), SuppressUnmanagedCodeSecurity]
            public static extern void* GetModuleHandleW(/*IN*/ char* lpModuleName);

            [DllImport(KERNEL_DLL, CallingConvention = WINAPI, EntryPoint = "IsBadReadPtr"), SuppressUnmanagedCodeSecurity]
            public static extern bool IsBadReadPtr(void* lpBase, uint ucb);

            [DllImport(DBGHELP_DLL, CallingConvention = WINAPI, EntryPoint = "ImageDirectoryEntryToData"), SuppressUnmanagedCodeSecurity]
            public static extern void* ImageDirectoryEntryToData(void* pBase, bool mappedAsImage, ushort directoryEntry, out uint size);

            [DllImport(DBGHELP_DLL, CallingConvention = WINAPI), SuppressUnmanagedCodeSecurity]
            public static extern IntPtr ImageRvaToVa(
                IntPtr pNtHeaders,
                IntPtr pBase,
                uint rva,
                IntPtr pLastRvaSection);

            [DllImport(DBGHELP_DLL, CallingConvention = CallingConvention.StdCall), SuppressUnmanagedCodeSecurity]
            public static extern IntPtr ImageNtHeader(IntPtr pImageBase);

            [DllImport(IMAGEHLP_DLL, CallingConvention = CallingConvention.Winapi), SuppressUnmanagedCodeSecurity]
            public static extern bool MapAndLoad(string imageName, string dllPath, out LOADED_IMAGE loadedImage, bool dotDll, bool readOnly);

            [DllImport(IMAGEHLP_DLL)]
            private static extern IntPtr UnMapAndLoad(IntPtr pLoadedImage);

        }

        [StructLayout(LayoutKind.Sequential)]
        public struct LOADED_IMAGE
        {
            public IntPtr moduleName;
            public IntPtr hFile;
            public IntPtr MappedAddress;
            public IntPtr FileHeader;
            public IntPtr lastRvaSection;
            public UInt32 numbOfSections;
            public IntPtr firstRvaSection;
            public UInt32 charachteristics;
            public ushort systemImage;
            public ushort dosImage;
            public ushort readOnly;
            public ushort version;
            public IntPtr links_1;
            public IntPtr links_2;
            public UInt32 sizeOfImage;
        }

        [StructLayout(LayoutKind.Explicit)]
        public unsafe struct IMAGE_IMPORT_BY_NAME
        {
            [FieldOffset(0)]
            public ushort Hint;
            [FieldOffset(2)]
            public fixed char Name[1];
        }

        [StructLayout(LayoutKind.Explicit)]
        public struct IMAGE_IMPORT_DESCRIPTOR
        {
            #region union

            [FieldOffset(0)]
            public uint Characteristics;
            [FieldOffset(0)]
            public uint OriginalFirstThunk;

            #endregion

            [FieldOffset(4)]
            public uint TimeDateStamp;
            [FieldOffset(8)]
            public uint ForwarderChain;
            [FieldOffset(12)]
            public uint Name;
            [FieldOffset(16)]
            public uint FirstThunk;
        }

        [StructLayout(LayoutKind.Sequential)]
        public struct IMAGE_EXPORT_DIRECTORY
        {
            public UInt32 Characteristics;
            public UInt32 TimeDateStamp;
            public UInt16 MajorVersion;
            public UInt16 MinorVersion;
            public UInt32 Name;
            public UInt32 Base;
            public UInt32 NumberOfFunctions;
            public UInt32 NumberOfNames;
            public IntPtr AddressOfFunctions;
            public IntPtr AddressOfNames;
            public IntPtr AddressOfNameOrdinals;
        }

        [StructLayout(LayoutKind.Explicit)]
        public struct THUNK_DATA
        {
            [FieldOffset(0)]
            public uint ForwarderString;
            [FieldOffset(0)]
            public uint Function;
            [FieldOffset(0)]
            public uint Ordinal;
            [FieldOffset(0)]
            public IntPtr AddressOfData;
        }

        #endregion

        public List<Tuple<string, List<string>>> CloneImportTable(string ClonePath)
        {
            PortableExecutableParser ExeParser = new PortableExecutableParser(ClonePath);
            return ExeParser.Imports.ToList();
        }

     
    }
}
