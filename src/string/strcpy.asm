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
;┌──────────────────────────────────────────┐
;│ copy string from source to destination 	│
;│ to the destination string				│
;│ input:									│
;│			rcx = *destination_str			│
;│			rdx = *source_str				│
;│ output:									│
;│			NaN								│
;└──────────────────────────────────────────┘
proc fa_strcpy uses rdi rsi
	mov rdi,rcx		; load destination string
	mov rsi,rdx		; load source string
	mov r8,rcx		; store destination pointer

	@@:
		lodsb
		stosb
		test	al,al	; check for end of source string which is 0
		jnz		@B

	mov rax,r8		; restore destination pointer
	ret
endp