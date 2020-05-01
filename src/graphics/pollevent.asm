;░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░
;░ This file is part of libfastact.										░
;░																		░
;░ libfastact is free software: you can redistribute it and/or modify	░
;░ it under the terms of the GNU General Public License as published by	░
;░ the Free Software Foundation, either version 3 of the License, or	░
;░ (at your option) any later version.									░
;░																		░
;░ libfastact is distributed in the hope that it will be useful,		░
;░ but WITHOUT ANY WARRANTY; without even the implied warranty of		░
;░ MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the			░
;░ GNU General Public License for more details.							░
;░																		░
;░ You should have received a copy of the GNU General Public License	░
;░ along with Foobar.  If not, see <https://www.gnu.org/licenses/>.		░
;░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░
proc fa_pollevent c
	;╔══════════════════════╗
	;║ BOOL WaitMessage();	║
	;╚══════════════════════╝
	call	[WaitMessage]

	;╔══════════════════════╗
	;║ BOOL GetMessage(		║
	;║ LPMSG lpMsg,			║
	;║ HWND  hWnd,			║
	;║ UINT  wMsgFilterMin,	║
	;║ UINT  wMsgFilterMax	║
	;║ );					║
	;╚══════════════════════╝
	lea		rcx,[event]
	mov		rdx,NULL
	xor		r8d,r8d
	xor		r9d,r9d
	call	[GetMessage]
	;╔══════════════════════════╗
	;║ BOOL TranslateMessage(	║
	;║ const MSG *lpMsg			║
	;║ );						║
	;╚══════════════════════════╝
	lea		rcx,[event]
	call	[TranslateMessage]
	lea		rcx,[event]
	call	[DispatchMessage]
	xor eax,eax
	mov		eax,[event.message]
	ret
endp