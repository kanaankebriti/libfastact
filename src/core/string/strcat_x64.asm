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
;┌──────────────────────────────────────┐
;│ appends a copy of the source string	│
;│ to the destination string			│
;│ input:								│
;│			rcx = *destination_str		│
;│			rdx = *source_str			│
;│ output:								│
;│			rax = *destination_str		│
;└──────────────────────────────────────┘
proc fa_strcat uses rdi rsi
	mov rdi,rcx		; load destination string
	mov rsi,rdx		; load source string
	mov r8,rcx		; store destination pointer

	xor		al,al	; set al to value we're looking for, 0 in this case which indicates end of a string
	repne	scasb	; find end of dest string. repeat untile get char = ecx = 0
	dec		rdi

	@@:
		lodsb
		stosb
		test	al,al	; check for end of source string which is 0
		jnz		@B

	mov	rax,r8		; restore destination pointer
	ret
endp