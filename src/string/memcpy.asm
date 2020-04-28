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
;┌──────────────────────────────────┐
;│ copies the values of num bytes	│
;│ from source destination 			│
;│ input:							│
;│			rcx = *destination		│
;│			rdx = *source			│
;│			r8 = num				│
;│ output:							│
;│			rax = *destination		│
;└──────────────────────────────────┘
proc fa_memcpy uses rdi rsi
	mov rdi,rcx		; load destination location
	mov rsi,rdx		; load source location
	mov r9,rcx		; store destination location
	mov ecx,r8d		; number of bytes

	@@:
		lodsb
		stosb
		loop	@B

	mov rax,r9
	ret
endp