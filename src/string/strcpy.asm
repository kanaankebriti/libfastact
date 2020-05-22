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
;┌──────────────────────────────────────────┐
;│ copy string from source to destination 	│
;│ input:									│
;│			rcx = *destination_str			│
;│			rdx = *source_str				│
;│ output:									│
;│			rax = *destination_str			│
;└──────────────────────────────────────────┘
proc fa_strcpy uses rdi rsi
	mov rdi,rcx		; load destination string
	mov rsi,rdx		; load source string

	@@:
		lodsb
		stosb
		test	al,al	; check for end of source string which is 0
		jnz		@B

	mov rax,rcx
	ret
endp