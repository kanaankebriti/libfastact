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
;│ copies the values of num bytes	│
;│ from source destination 			│
;│ input:							│
;│			*destination			│
;│			*source					│
;│			num						│
;│ output:							│
;│			eax = *destination		│
;└──────────────────────────────────┘
proc fa_memcpy c destination:DWORD,source:DWORD,num:DWORD
	push edi
	push esi

	mov edi,[destination]	; load destination location
	mov esi,[source]		; load source location
	mov ecx,[num]			; number of bytes

	@@:
		lodsb
		stosb
		loop	@B

	mov eax,[destination]

	pop esi
	pop edi
	ret
endp