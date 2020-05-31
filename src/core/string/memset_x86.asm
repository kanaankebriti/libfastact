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
;┌──────────────────────────────────────────────────┐
;│ sets the first num bytes of the block of memory	│
;| pointed by destination_str to the specified value│
;│ input:											│
;│			rcx = *destination_str					│
;│			rdx = value								│
;│			r8 = size								│
;│ output:											│
;│			rax = *destination_str					│
;└──────────────────────────────────────────────────┘
proc fa_memset stdcall destination:DWORD,value:BYTE,size:DWORD
	mov	edi,[destination]	; set destination_str
	mov	ecx,[size]			; set size
	mov al,[value]			; set value
	rep	stosb				; store n times
	mov	eax,[destination]	; return pointer
	ret
endp