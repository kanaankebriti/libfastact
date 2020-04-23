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
;┌──────────────────────────────────────┐
;│ appends a copy of the source string	│
;│ to the destination string			│
;│ input:								│
;│			rcx = *destination_str		│
;│			rdx = value					│
;│			r8 = size					│
;│ output:								│
;│			rax = *destination_str		│
;└──────────────────────────────────────┘
proc fa_memset c uses rdi r9
	mov r9,rcx	; save *destination_str
	mov	rdi,rcx	; set destination_str
	mov	rcx,r8	; set size
	mov al,dl	; set value
	rep	stosb	; store n times
	mov	rax,r9  ; return pointer
	ret
endp