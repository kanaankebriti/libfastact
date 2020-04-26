;░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░
;░This file is part of libfastasm.										░
;░																		░
;░libfastasm is free software: you can redistribute it and/or modify	░
;░it under the terms of the GNU General Public License as published by	░
;░the Free Software Foundation, either version 3 of the License, or		░
;░(at your option) any later version.									░
;░																		░
;░libfastasm is distributed in the hope that it will be useful,			░
;░but WITHOUT ANY WARRANTY; without even the implied warranty of		░
;░MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the			░
;░GNU General Public License for more details.							░
;░																		░
;░You should have received a copy of the GNU General Public License		░
;░along with Foobar.  If not, see <https://www.gnu.org/licenses/>.		░
;░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░
proc fa_createwindow c
	;┌───────────────┐
	;│ set hInstance │
	;└───────────────┘
	;╔══════════════════════════════╗
	;║ HMODULE GetModuleHandleA(	║
	;║ LPCSTR lpModuleName			║
	;║ );							║
	;╚══════════════════════════════╝
	xor		ecx,ecx
	call	[GetModuleHandleA]
	mov		[_main_window_class.hInstance],rax

	;┌──────────────────────┐
	;│ set application icon │
	;└──────────────────────┘
	;╔══════════════════════╗
	;║ HICON LoadIconA(		║
	;║ HINSTANCE hInstance,	║
	;║ LPCSTR    lpIconName	║
	;║ );					║
	;╚══════════════════════╝
	xor		ecx,ecx
	mov		rdx,IDI_HAND
	call	[LoadIcon]
	mov		[_main_window_class.hIcon],rax

	;┌────────────┐
	;│ set crusor │
	;└────────────┘
	;╔══════════════════════════╗
	;║ HCURSOR LoadCursorA(		║
	;║ HINSTANCE hInstance,		║
	;║ LPCSTR    lpCursorName	║
	;║ );						║
	;╚══════════════════════════╝
	xor		ecx,ecx
	mov		rdx,IDC_WAIT
	call	[LoadCursorA]
	mov		[_main_window_class.hCursor],rax

	;┌───────────────────────┐
	;│ set window background │
	;└───────────────────────┘
	mov		[_main_window_class.hbrBackground],COLOR_WINDOW

	;┌───────────────────────┐
	;│ register window calss │
	;└───────────────────────┘
	;╔══════════════════════════╗
	;║ ATOM RegisterClassExA(	║
	;║ const WNDCLASSEXA *Arg1	║
	;║ );						║
	;╚══════════════════════════╝
	;invoke	RegisterClassEx,_main_window_class
	lea		rcx,[_main_window_class]
    call	[RegisterClassExA]

	;┌───────────────┐
	;│ create window │
	;└───────────────┘
	;╔══════════════════════╗
	;║ HWND CreateWindowEx(	║
	;║ DWORD dwExStyle,		║
	;║ LPCTSTR lpClassName,	║
	;║ LPCTSTR lpWindowName,║
	;║ DWORD dwStyle,		║
	;║ int x,				║
	;║ int y,				║
	;║ int nWidth,			║
	;║ int nHeight,			║
	;║ HWND hWndParent,		║
	;║ HMENU hMenu,			║
	;║ HINSTANCE hInstance,	║
	;║ LPVOID lpParam		║
	;║ );					║
	;╚══════════════════════╝
	invoke  CreateWindowEx,0,_class,_window_title,WS_VISIBLE+WS_OVERLAPPEDWINDOW,16,16,800,600,NULL,NULL,[_main_window_class.hInstance],NULL
	mov		[hwnd],rax
	ret
endp

proc WindowProc uses rdi,hwnd,wmsg,wparam,lparam
	mov	[hwnd],rcx
	frame
	cmp	edx,WM_KEYDOWN
	je	.wmkeydown
	cmp	edx,WM_DESTROY
	je	.wmdestroy
	.defwndproc:
	invoke	DefWindowProc,rcx,rdx,r8,r9
	jmp	.finish
	.wmkeydown:
	cmp	r8d,VK_ESCAPE
	jne	.defwndproc
	.wmdestroy:
	invoke	ReleaseDC,[hwnd],[hdc]
	invoke	PostQuitMessage,0
	xor	eax,eax
	.finish:
	endf
	ret
endp