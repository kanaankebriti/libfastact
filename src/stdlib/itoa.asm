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
;┌──────────────────────────────┐
;│ converts integer to ascii	│
;│ input:						│
;│			rcx = uint64		│
;│			rdx = *_result_str	│
;│ output:						│
;│			NaN					│
;└──────────────────────────────┘
proc fa_itoa c uses rdi rbx r9 r10
	; max 64bit unsigned int = 9,223,372,036,854,775,807
	; this number has 19 digits

	mov	r8,0xCCCCCCCCCCCCCCCD	; store magic number into rbx
	mov rdi,rdx					; store *_result_str to rdi to reverse ordered store string
	mov r10,rdx					; store *_result_str to r9 for reversing the string

	test rcx,rcx				; check for signed number
	jns @F

	; if signed
	mov		rax,'-'		; load negative symbol
	stosb				; store negative symbol
	neg		rcx			; make original number positive

	@@:
		mov rax,rcx		; save original number
		mul r8			; divide by 10 using magic number
		shr rdx,3		; rdx = quotient
		mov rbx,rdx		; save quotient for next loop
		imul rdx,10D	; rbx = rdx * 10 = quotient * 10
		sub rcx,rdx		; rcx = remainder = original number  - (10 * quotient)
		add rcx,48D		; ascii conversion. '0' = 48
		mov rax,rcx		; store resulted digit
		stosb
		mov rcx,rbx		; do next division using quotient
		test rcx,rcx	; check for no more digits
		jnz @B

	xor eax,eax
	dec rdi				; point to last digit
	mov r9,rdi			; save rdi

	mov		rcx,r10		; save *_result_str for return

	movzx	rbx,BYTE [r10]	; handle first character if is '-'
	cmp		rbx,'-'
	jne		@F
	inc		r10				; skip first '-' character

	; until now number is in reverse order. this section shuffle it to correct order.
	@@:
		movzx	rax,BYTE [r9]	; digit n, n-1, n-2, ...
		movzx	rbx,BYTE [r10]	; digit 1, 2, 3, ...
		xchg	rax,rbx			; exchange (n,1), (n-1,2), (n-3,3), ...
		mov		rdi,r9
		stosb
		xchg	rax,rbx
		mov		rdi,r10
		stosb
		dec		r9				; decrease pointer to the end of the string
		inc		r10				; increase pointer to the beginning of the string
		cmp		r9,r10
		jg		@B				; repeat until r9 > r10. that is, upper pointer is greater than lower pointer.

	mov rax,rcx
	ret
endp