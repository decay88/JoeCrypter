#ifndef _WINCON_H
#define _WINCON_H

#if __POCC__ >= 500
#pragma once
#endif

/* Windows Console subsystem definitions */

#if defined(WIN32_DEFAULT_LIBS)
#pragma comment(lib, "kernel32.lib")
#endif

#ifdef __cplusplus
extern "C" {
#endif

#define RIGHT_ALT_PRESSED  0x0001
#define LEFT_ALT_PRESSED  0x0002
#define RIGHT_CTRL_PRESSED  0x0004
#define LEFT_CTRL_PRESSED  0x0008
#define SHIFT_PRESSED  0x0010
#define NUMLOCK_ON  0x0020
#define SCROLLLOCK_ON  0x0040
#define CAPSLOCK_ON  0x0080
#define ENHANCED_KEY  0x0100
#define NLS_DBCSCHAR  0x00010000
#define NLS_ALPHANUMERIC  0x00000000
#define NLS_KATAKANA  0x00020000
#define NLS_HIRAGANA  0x00040000
#define NLS_ROMAN  0x00400000
#define NLS_IME_CONVERSION  0x00800000
#define NLS_IME_DISABLE  0x20000000

#define FROM_LEFT_1ST_BUTTON_PRESSED  0x0001
#define FROM_LEFT_2ND_BUTTON_PRESSED  0x0004
#define FROM_LEFT_3RD_BUTTON_PRESSED  0x0008
#define FROM_LEFT_4TH_BUTTON_PRESSED  0x0010
#define RIGHTMOST_BUTTON_PRESSED  0x0002

#define MOUSE_MOVED  0x0001
#define DOUBLE_CLICK  0x0002
#define MOUSE_WHEELED  0x0004
#if (_WIN32_WINNT >= 0x0600)
#define MOUSE_HWHEELED  0x0008
#endif /* _WIN32_WINNT >= 0x0600 */

#define KEY_EVENT  0x0001
#define MOUSE_EVENT  0x0002
#define WINDOW_BUFFER_SIZE_EVENT  0x0004
#define MENU_EVENT  0x0008
#define FOCUS_EVENT  0x0010

#define FOREGROUND_BLUE  0x0001
#define FOREGROUND_GREEN  0x0002
#define FOREGROUND_RED  0x0004
#define FOREGROUND_INTENSITY  0x0008
#define BACKGROUND_BLUE  0x0010
#define BACKGROUND_GREEN  0x0020
#define BACKGROUND_RED  0x0040
#define BACKGROUND_INTENSITY  0x0080

#define COMMON_LVB_LEADING_BYTE  0x0100
#define COMMON_LVB_TRAILING_BYTE  0x0200
#define COMMON_LVB_GRID_HORIZONTAL  0x0400
#define COMMON_LVB_GRID_LVERTICAL  0x0800
#define COMMON_LVB_GRID_RVERTICAL  0x1000
#define COMMON_LVB_REVERSE_VIDEO  0x4000
#define COMMON_LVB_UNDERSCORE  0x8000
#define COMMON_LVB_SBCSDBCS  0x0300

#define CTRL_C_EVENT  0
#define CTRL_BREAK_EVENT  1
#define CTRL_CLOSE_EVENT  2
#define CTRL_LOGOFF_EVENT  5
#define CTRL_SHUTDOWN_EVENT  6

#define ENABLE_PROCESSED_INPUT  0x0001
#define ENABLE_LINE_INPUT  0x0002
#define ENABLE_ECHO_INPUT  0x0004
#define ENABLE_WINDOW_INPUT  0x0008
#define ENABLE_MOUSE_INPUT  0x0010

#define ENABLE_PROCESSED_OUTPUT  0x0001
#define ENABLE_WRAP_AT_EOL_OUTPUT  0x0002

#define CONSOLE_TEXTMODE_BUFFER  1

#if (_WIN32_WINNT >= 0x0500)
#define CONSOLE_FULLSCREEN  1
#define CONSOLE_FULLSCREEN_HARDWARE  2

#define CONSOLE_NO_SELECTION  0x0000
#define CONSOLE_SELECTION_IN_PROGRESS  0x0001
#define CONSOLE_SELECTION_NOT_EMPTY  0x0002
#define CONSOLE_MOUSE_SELECTION  0x0004
#define CONSOLE_MOUSE_DOWN  0x0008
#endif /* _WIN32_WINNT >= 0x0500 */

#define ATTACH_PARENT_PROCESS  ((DWORD)-1)

typedef struct _COORD {
    SHORT X;
    SHORT Y;
} COORD, *PCOORD;

typedef struct _SMALL_RECT {
    SHORT Left;
    SHORT Top;
    SHORT Right;
    SHORT Bottom;
} SMALL_RECT, *PSMALL_RECT;

typedef struct _KEY_EVENT_RECORD {
    BOOL bKeyDown;
    WORD wRepeatCount;
    WORD wVirtualKeyCode;
    WORD wVirtualScanCode;
    union {
        WCHAR UnicodeChar;
        CHAR   AsciiChar;
    } uChar;
    DWORD dwControlKeyState;
} KEY_EVENT_RECORD, *PKEY_EVENT_RECORD;

typedef struct _MOUSE_EVENT_RECORD {
    COORD dwMousePosition;
    DWORD dwButtonState;
    DWORD dwControlKeyState;
    DWORD dwEventFlags;
} MOUSE_EVENT_RECORD, *PMOUSE_EVENT_RECORD;

typedef struct _WINDOW_BUFFER_SIZE_RECORD {
    COORD dwSize;
} WINDOW_BUFFER_SIZE_RECORD, *PWINDOW_BUFFER_SIZE_RECORD;

typedef struct _MENU_EVENT_RECORD {
    UINT dwCommandId;
} MENU_EVENT_RECORD, *PMENU_EVENT_RECORD;

typedef struct _FOCUS_EVENT_RECORD {
    BOOL bSetFocus;
} FOCUS_EVENT_RECORD, *PFOCUS_EVENT_RECORD;

typedef struct _INPUT_RECORD {
    WORD EventType;
    union {
        KEY_EVENT_RECORD KeyEvent;
        MOUSE_EVENT_RECORD MouseEvent;
        WINDOW_BUFFER_SIZE_RECORD WindowBufferSizeEvent;
        MENU_EVENT_RECORD MenuEvent;
        FOCUS_EVENT_RECORD FocusEvent;
    } Event;
} INPUT_RECORD, *PINPUT_RECORD;

typedef struct _CHAR_INFO {
    union {
        WCHAR UnicodeChar;
        CHAR AsciiChar;
    } Char;
    WORD Attributes;
} CHAR_INFO, *PCHAR_INFO;

typedef struct _CONSOLE_SCREEN_BUFFER_INFO {
    COORD dwSize;
    COORD dwCursorPosition;
    WORD wAttributes;
    SMALL_RECT srWindow;
    COORD dwMaximumWindowSize;
} CONSOLE_SCREEN_BUFFER_INFO, *PCONSOLE_SCREEN_BUFFER_INFO;

typedef struct _CONSOLE_CURSOR_INFO {
    DWORD dwSize;
    BOOL bVisible;
} CONSOLE_CURSOR_INFO, *PCONSOLE_CURSOR_INFO;

#if (_WIN32_WINNT >= 0x0500)
typedef struct _CONSOLE_FONT_INFO {
    DWORD nFont;
    COORD dwFontSize;
} CONSOLE_FONT_INFO, *PCONSOLE_FONT_INFO;

typedef struct _CONSOLE_SELECTION_INFO {
    DWORD dwFlags;
    COORD dwSelectionAnchor;
    SMALL_RECT srSelection;
} CONSOLE_SELECTION_INFO, *PCONSOLE_SELECTION_INFO;
#endif /* _WIN32_WINNT >= 0x0500 */

typedef BOOL (WINAPI *PHANDLER_ROUTINE)(DWORD);

WINBASEAPI BOOL WINAPI PeekConsoleInputA(HANDLE,PINPUT_RECORD,DWORD,PDWORD);
WINBASEAPI BOOL WINAPI PeekConsoleInputW(HANDLE,PINPUT_RECORD,DWORD,PDWORD);
WINBASEAPI BOOL WINAPI ReadConsoleInputA(HANDLE,PINPUT_RECORD,DWORD,PDWORD);
WINBASEAPI BOOL WINAPI ReadConsoleInputW(HANDLE,PINPUT_RECORD,DWORD,PDWORD);
WINBASEAPI BOOL WINAPI WriteConsoleInputA(HANDLE,CONST INPUT_RECORD*,DWORD,PDWORD);
WINBASEAPI BOOL WINAPI WriteConsoleInputW(HANDLE,CONST INPUT_RECORD*,DWORD,PDWORD);
WINBASEAPI BOOL WINAPI ReadConsoleOutputA(HANDLE,PCHAR_INFO,COORD,COORD,PSMALL_RECT);
WINBASEAPI BOOL WINAPI ReadConsoleOutputW(HANDLE,PCHAR_INFO,COORD,COORD,PSMALL_RECT);
WINBASEAPI BOOL WINAPI WriteConsoleOutputA(HANDLE,CONST CHAR_INFO*,COORD,COORD,PSMALL_RECT);
WINBASEAPI BOOL WINAPI WriteConsoleOutputW(HANDLE,CONST CHAR_INFO*,COORD,COORD,PSMALL_RECT);
WINBASEAPI BOOL WINAPI ReadConsoleOutputCharacterA(HANDLE,LPSTR,DWORD,COORD,PDWORD);
WINBASEAPI BOOL WINAPI ReadConsoleOutputCharacterW(HANDLE,LPWSTR,DWORD,COORD,PDWORD);
WINBASEAPI BOOL WINAPI ReadConsoleOutputAttribute(HANDLE,PWORD,DWORD,COORD,PDWORD);
WINBASEAPI BOOL WINAPI WriteConsoleOutputCharacterA(HANDLE,LPCSTR,DWORD,COORD,PDWORD);
WINBASEAPI BOOL WINAPI WriteConsoleOutputCharacterW(HANDLE,LPCWSTR,DWORD,COORD,PDWORD);
WINBASEAPI BOOL WINAPI WriteConsoleOutputAttribute(HANDLE,CONST WORD*,DWORD,COORD,PDWORD);
WINBASEAPI BOOL WINAPI FillConsoleOutputCharacterA(HANDLE,CHAR,DWORD,COORD,PDWORD);
WINBASEAPI BOOL WINAPI FillConsoleOutputCharacterW(HANDLE,WCHAR,DWORD,COORD,LPDWORD);
WINBASEAPI BOOL WINAPI FillConsoleOutputAttribute(HANDLE,WORD,DWORD,COORD,PDWORD);
WINBASEAPI BOOL WINAPI GetConsoleMode(HANDLE,PDWORD);
WINBASEAPI BOOL WINAPI GetNumberOfConsoleInputEvents(HANDLE,PDWORD);
WINBASEAPI BOOL WINAPI GetConsoleScreenBufferInfo(HANDLE,PCONSOLE_SCREEN_BUFFER_INFO);
WINBASEAPI COORD WINAPI GetLargestConsoleWindowSize(HANDLE);
WINBASEAPI BOOL WINAPI GetConsoleCursorInfo(HANDLE,PCONSOLE_CURSOR_INFO);
WINBASEAPI BOOL WINAPI GetNumberOfConsoleMouseButtons(PDWORD);
WINBASEAPI BOOL WINAPI SetConsoleMode(HANDLE,DWORD);
WINBASEAPI BOOL WINAPI SetConsoleActiveScreenBuffer(HANDLE);
WINBASEAPI BOOL WINAPI FlushConsoleInputBuffer(HANDLE);
WINBASEAPI BOOL WINAPI SetConsoleScreenBufferSize(HANDLE,COORD);
WINBASEAPI BOOL WINAPI SetConsoleCursorPosition(HANDLE,COORD);
WINBASEAPI BOOL WINAPI SetConsoleCursorInfo(HANDLE,CONST CONSOLE_CURSOR_INFO*);
WINBASEAPI BOOL WINAPI ScrollConsoleScreenBufferA(HANDLE,CONST SMALL_RECT*,CONST SMALL_RECT*,COORD,CONST CHAR_INFO*);
WINBASEAPI BOOL WINAPI ScrollConsoleScreenBufferW(HANDLE,CONST SMALL_RECT*,CONST SMALL_RECT*,COORD,CONST CHAR_INFO*);
WINBASEAPI BOOL WINAPI SetConsoleWindowInfo(HANDLE,BOOL,CONST SMALL_RECT*);
WINBASEAPI BOOL WINAPI SetConsoleTextAttribute(HANDLE,WORD);
WINBASEAPI BOOL WINAPI SetConsoleCtrlHandler(PHANDLER_ROUTINE,BOOL);
WINBASEAPI BOOL WINAPI GenerateConsoleCtrlEvent(DWORD,DWORD);
WINBASEAPI BOOL WINAPI AllocConsole(VOID);
WINBASEAPI BOOL WINAPI FreeConsole(VOID);
WINBASEAPI DWORD WINAPI GetConsoleTitleA(LPSTR,DWORD);
WINBASEAPI DWORD WINAPI GetConsoleTitleW(LPWSTR,DWORD);
WINBASEAPI BOOL WINAPI SetConsoleTitleA(LPCSTR);
WINBASEAPI BOOL WINAPI SetConsoleTitleW(LPCWSTR);
WINBASEAPI BOOL WINAPI ReadConsoleA(HANDLE,PVOID,DWORD,PDWORD,PVOID);
WINBASEAPI BOOL WINAPI ReadConsoleW(HANDLE,PVOID,DWORD,PDWORD,PVOID);
WINBASEAPI BOOL WINAPI WriteConsoleA(HANDLE,CONST VOID*,DWORD,PDWORD,PVOID);
WINBASEAPI BOOL WINAPI WriteConsoleW(HANDLE,CONST VOID*,DWORD,PDWORD,PVOID);
WINBASEAPI HANDLE WINAPI CreateConsoleScreenBuffer(DWORD,DWORD,CONST SECURITY_ATTRIBUTES*,DWORD,PVOID);
WINBASEAPI UINT WINAPI GetConsoleCP(VOID);
WINBASEAPI BOOL WINAPI SetConsoleCP(UINT);
WINBASEAPI UINT WINAPI GetConsoleOutputCP(VOID);
WINBASEAPI BOOL WINAPI SetConsoleOutputCP(UINT);
#if (_WIN32_WINNT >= 0x0500)
WINBASEAPI BOOL WINAPI GetCurrentConsoleFont(HANDLE,BOOL,PCONSOLE_FONT_INFO);
WINBASEAPI COORD WINAPI GetConsoleFontSize(HANDLE,DWORD);
WINBASEAPI BOOL WINAPI GetConsoleSelectionInfo(PCONSOLE_SELECTION_INFO);
WINBASEAPI BOOL WINAPI AttachConsole(DWORD);
WINBASEAPI BOOL APIENTRY GetConsoleDisplayMode(LPDWORD);
WINBASEAPI HWND APIENTRY GetConsoleWindow(VOID);
#endif /* _WIN32_WINNT >= 0x0500 */
#if(_WIN32_WINNT >= 0x0501)
WINBASEAPI DWORD APIENTRY GetConsoleProcessList(LPDWORD,DWORD);
#endif /* _WIN32_WINNT >= 0x0501 */
#if (_WIN32_WINNT >= 0x0600)
WINBASEAPI DWORD WINAPI GetConsoleOriginalTitleA(LPSTR,DWORD);
WINBASEAPI DWORD WINAPI GetConsoleOriginalTitleW(LPWSTR,DWORD);
#endif /* _WIN32_WINNT >= 0x0600 */

#ifdef UNICODE
#define PeekConsoleInput PeekConsoleInputW
#define ReadConsoleInput ReadConsoleInputW
#define WriteConsoleInput WriteConsoleInputW
#define ReadConsoleOutput ReadConsoleOutputW
#define WriteConsoleOutput WriteConsoleOutputW
#define ReadConsoleOutputCharacter ReadConsoleOutputCharacterW
#define WriteConsoleOutputCharacter WriteConsoleOutputCharacterW
#define FillConsoleOutputCharacter FillConsoleOutputCharacterW
#define ScrollConsoleScreenBuffer ScrollConsoleScreenBufferW
#define GetConsoleTitle GetConsoleTitleW
#define SetConsoleTitle SetConsoleTitleW
#define ReadConsole ReadConsoleW
#define WriteConsole WriteConsoleW
#if (_WIN32_WINNT >= 0x0600)
#define GetConsoleOriginalTitle GetConsoleOriginalTitleW
#endif /* _WIN32_WINNT >= 0x0600 */
#else
#define PeekConsoleInput PeekConsoleInputA
#define ReadConsoleInput ReadConsoleInputA
#define WriteConsoleInput WriteConsoleInputA
#define ReadConsoleOutput ReadConsoleOutputA
#define WriteConsoleOutput WriteConsoleOutputA
#define ReadConsoleOutputCharacter ReadConsoleOutputCharacterA
#define WriteConsoleOutputCharacter WriteConsoleOutputCharacterA
#define FillConsoleOutputCharacter FillConsoleOutputCharacterA
#define ScrollConsoleScreenBuffer ScrollConsoleScreenBufferA
#define GetConsoleTitle GetConsoleTitleA
#define SetConsoleTitle SetConsoleTitleA
#define ReadConsole ReadConsoleA
#define WriteConsole WriteConsoleA
#if (_WIN32_WINNT >= 0x0600)
#define GetConsoleOriginalTitle GetConsoleOriginalTitleA
#endif /* _WIN32_WINNT >= 0x0600 */
#endif /* UNICODE */

#ifdef __cplusplus
}
#endif

#endif /* _WINCON_H */
