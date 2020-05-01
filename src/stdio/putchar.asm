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
;┌──────────────────────────────────────────┐
;│ writes a character to the stdout			│
;│ input:									│
;│			rcx = (unsigned short int) char	│
;│ output:									│
;│			rax = (unsigned short int) char	│
;└──────────────────────────────────────────┘
proc fa_putchar
	locals
		temp_char db ?
	endl

	mov [temp_char],cl			; store character

	;╔══════════════════════════════╗
	;║ HANDLE WINAPI GetStdHandle(	║
	;║ _In_ DWORD nStdHandle		║
	;║ );							║
	;╚══════════════════════════════╝
	mov rcx,STD_OUTPUT_HANDLE	; get stdout handle
	call [GetStdHandle]

	;╔══════════════════════════════════════════════════╗
	;║ BOOL WINAPI WriteConsole(						║
	;║ _In_             HANDLE  hConsoleOutput,			║
	;║ _In_       const VOID    *lpBuffer,				║
	;║ _In_             DWORD   nNumberOfCharsToWrite,	║
	;║ _Out_opt_        LPDWORD lpNumberOfCharsWritten,	║
	;║ _Reserved_       LPVOID  lpReserved				║
	;║ );												║
	;╚══════════════════════════════════════════════════╝
	mov rcx,rax					; write to stdout
	lea rdx,[temp_char]
	mov r8d,1
	xor r9d,r9d
	call [WriteConsole]

	movzx rax,[temp_char]
	ret
endp