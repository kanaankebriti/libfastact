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
;┌──────────────────────────────────────────────────┐
;│ Allocates a block of size bytes of memory		│
;│ input:											│
;│			rcx = size in bytes						│
;│ output:											│
;│			rax = *ptr to the beginning of the block│
;└──────────────────────────────────────────────────┘
proc fa_malloc c uses rcx
	;╔══════════════════════════╗
	;║LPVOID VirtualAlloc(		║
	;║ LPVOID lpAddress,		║
	;║ SIZE_T dwSize,			║
	;║ DWORD  flAllocationType,	║
	;║ DWORD  flProtect			║
	;║);						║
	;╚══════════════════════════╝
	mov rdx,rcx			; set size
	xor ecx,ecx			; let windows decide allocation address
	mov r8,0x00003000	; MEM_COMMIT = 0x00001000 | MEM_RESERVE = 0x00002000
	mov r9,0x40			; PAGE_EXECUTE_READWRITE = 0x40
	call [VirtualAlloc]
	ret
endp