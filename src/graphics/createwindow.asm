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
	ret
endp

proc WindowProc uses rbx rsi rdi, hwnd,wmsg,wparam,lparam
	mov	[hwnd],rcx
	cmp	edx,WM_CREATE
	je	.wmcreate
	cmp	edx,WM_KEYDOWN
	je	.wmdestroy
	cmp	edx,WM_DESTROY
	je	.wmdestroy
	.defwndproc:
	invoke	DefWindowProc,rcx,rdx,r8,r9
	ret
	.wmcreate:
	invoke	GetDC,rcx
	mov	[hdc],rax
	lea	rdi,[pfd]
	mov	rcx,sizeof.PIXELFORMATDESCRIPTOR shr 3
	xor	eax,eax
	rep	stosq
	mov	[pfd.nSize],sizeof.PIXELFORMATDESCRIPTOR
	mov	[pfd.nVersion],1
	mov	[pfd.dwFlags],PFD_SUPPORT_OPENGL+PFD_DOUBLEBUFFER+PFD_DRAW_TO_WINDOW
	mov	[pfd.iLayerType],PFD_MAIN_PLANE
	mov	[pfd.iPixelType],PFD_TYPE_RGBA
	mov	[pfd.cColorBits],16
	mov	[pfd.cDepthBits],16
	mov	[pfd.cAccumBits],0
	mov	[pfd.cStencilBits],0
	invoke	ChoosePixelFormat,[hdc],pfd
	invoke	SetPixelFormat,[hdc],eax,pfd
	invoke	wglCreateContext,[hdc]
	mov	[hrc],rax
	invoke	wglMakeCurrent,[hdc],[hrc]
	invoke	GetClientRect,[hwnd],rc
	invoke	glViewport,0, 0,[rc.right],[rc.bottom]
	ret
	.wmdestroy:
	invoke	wglMakeCurrent,0,0
	invoke	wglDeleteContext,[hrc]
	invoke	ReleaseDC,[hwnd],[hdc]
	invoke	PostQuitMessage,0
	ret
endp