/****************************************************************************
 *                                                                          *
 * File    : wizard.h                                                       *
 *                                                                          *
 * Purpose : Definitions for Pelles C Wizard API 1.0.                       *
 *                                                                          *
 * History : Date      Reason                                               *
 *           02-04-18  Created                                              *
 *           03-11-23  Added support for Smartphone devices.                *
 *           06-09-10  Added support for Win32 and WinCE installers.        *
 *           07-11-17  Added support for Win64 (64-bit Edition).            *
 *           12-12-13  Removed support for WinCE.                           *
 *           14-02-07  Added interface function WizScanForDependencies().   *
 *                                                                          *
 ****************************************************************************/

#ifndef _WIZARD_H
#define _WIZARD_H

#if defined(_IDE_)
#define WIZAPI __declspec(dllexport)
#else /* !_IDE_ */
#define WIZAPI __declspec(dllimport)
#if defined(_WIN64)
#pragma comment(lib, "wizard64.lib")
#else /* !_WIN64 */
#pragma comment(lib, "wizard.lib")
#endif /* !_WIN64 */
#endif /* !_IDE_ */

/* Project types */
enum WizProjType {
    Project_Win32_GUI = 0,
    Project_Win32_DLL = 1,
    Project_Win32_Library = 2,
    Project_Win32_Console = 3,
    Project_Reserved1 /*Project_WinCE_Pocket_PC_GUI*/ = 4,
    Project_Reserved2 /*Project_WinCE_Pocket_PC_DLL*/ = 5,
    Project_Reserved3 /*Project_WinCE_Pocket_PC_Library*/ = 6,
    Project_Reserved4 /*Project_WinCE_Smartphone_GUI*/ = 7,
    Project_Reserved5 /*Project_WinCE_Smartphone_DLL*/ = 8,
    Project_Reserved6 /*Project_WinCE_Smartphone_Library*/ = 9,
    Project_Win64_GUI = 10,
    Project_Win64_DLL = 11,
    Project_Win64_Library = 12,
    Project_Win64_Console = 13,
    /*Project_WinCE_GUI = Project_WinCE_Pocket_PC_GUI,*/  /* compatibility */
    /*Project_WinCE_DLL = Project_WinCE_Pocket_PC_DLL,*/  /* compatibility */
    /*Project_WinCE_Library = Project_WinCE_Pocket_PC_Library,*/  /* compatibility */
    Project_Win32_Installer = 50,
    Project_Reserved7 /*Project_WinCE_Pocket_PC_Installer*/ = 51,
    Project_Reserved8 /*Project_WinCE_Smartphone_Installer*/ = 52,
};

/* Step page notifications */
enum WizAction {
    Action_SetActive = 1,
    Action_KillActive = 2,
    Action_UpdateUI = 3
};

/* Step page callback procedure */
typedef BOOL (CALLBACK *WIZSTEPPROC)(HWND, enum WizAction);

/* Write file callback procedure */
typedef void (CALLBACK *WIZFILEPROCA)(PSTR, int);
typedef void (CALLBACK *WIZFILEPROCW)(PWSTR, int);

/* File dependency callback procedure */
typedef BOOL (CALLBACK *WIZDEPSPROCA)(LPCSTR, LPVOID);
typedef BOOL (CALLBACK *WIZDEPSPROCW)(LPCWSTR, LPVOID);

/****** Function prototypes ************************************************/

BOOL WINAPI WizAddStepA(LPCSTR, WIZSTEPPROC);
BOOL WINAPI WizAddStepW(LPCWSTR, WIZSTEPPROC);
HINSTANCE WINAPI WizGetInstanceHandle(void);
BOOL WINAPI WizMain(void);
BOOL WINAPI WizShowSteps(void);
BOOL WINAPI WizWriteFileFromResourceA(LPCSTR, LPCSTR);
BOOL WINAPI WizWriteFileFromResourceW(LPCWSTR, LPCWSTR);
BOOL WINAPI WizWriteTextFileFromResourceA(LPCSTR, LPCSTR, WIZFILEPROCA);
BOOL WINAPI WizWriteTextFileFromResourceW(LPCWSTR, LPCWSTR, WIZFILEPROCW);

WIZAPI BOOL WINAPI WizAddProjectFileA(LPCSTR);
WIZAPI BOOL WINAPI WizAddProjectFileW(LPCWSTR);
WIZAPI BOOL WINAPI WizGetProjectNameA(LPSTR, int);
WIZAPI BOOL WINAPI WizGetProjectNameW(LPWSTR, int);
WIZAPI BOOL WINAPI WizGetProjectSymbolA(LPCSTR, LPSTR, int);
WIZAPI BOOL WINAPI WizGetProjectSymbolW(LPCWSTR, LPWSTR, int);
WIZAPI BOOL WINAPI WizSetProjectSymbolA(LPCSTR, LPCSTR);
WIZAPI BOOL WINAPI WizSetProjectSymbolW(LPCWSTR, LPCWSTR);
WIZAPI BOOL WINAPI WizSetProjectType(enum WizProjType);
WIZAPI void WINAPI WizScanForDependenciesA(LPCSTR, WIZDEPSPROCA, LPVOID);
WIZAPI void WINAPI WizScanForDependenciesW(LPCWSTR, WIZDEPSPROCW, LPVOID);

#ifdef UNICODE
#define WizAddStep  WizAddStepW
#define WizAddProjectFile  WizAddProjectFileW
#define WizGetProjectName  WizGetProjectNameW
#define WizGetProjectSymbol  WizGetProjectSymbolW
#define WizSetProjectSymbol  WizSetProjectSymbolW
#define WizWriteFileFromResource WizWriteFileFromResourceW
#define WizWriteTextFileFromResource WizWriteTextFileFromResourceW
#define WizScanForDependencies WizScanForDependenciesW
typedef WIZFILEPROCW WIZFILEPROC;
typedef WIZDEPSPROCW WIZDEPSPROC;
#else /* !UNICODE */
#define WizAddStep  WizAddStepA
#define WizAddProjectFile  WizAddProjectFileA
#define WizGetProjectName  WizGetProjectNameA
#define WizGetProjectSymbol  WizGetProjectSymbolA
#define WizSetProjectSymbol  WizSetProjectSymbolA
#define WizWriteFileFromResource WizWriteFileFromResourceA
#define WizWriteTextFileFromResource WizWriteTextFileFromResourceA
#define WizScanForDependencies WizScanForDependenciesA
typedef WIZFILEPROCA WIZFILEPROC;
typedef WIZDEPSPROCA WIZDEPSPROC;
#endif /* !UNICODE */

#endif /* _WIZARD_H */
