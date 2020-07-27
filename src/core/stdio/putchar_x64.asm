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
;░ along with libfastact.  If not, see <https://www.gnu.org/licenses/>.	░
;░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░
;┌──────────────────────────────────┐
;│ writes a character to the stdout	│
;│ input:							│
;│			rcx = (int) char		│
;│ output:							│
;│			rax = (int) char		│
;└──────────────────────────────────┘
proc fa_putchar
	locals
		temp_char dd ?
	endl

	mov [temp_char],ecx			; store character

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

	mov eax,[temp_char]
	ret
endp