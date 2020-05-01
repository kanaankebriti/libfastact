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
;░ along with Foobar.  If not, see <https://www.gnu.org/licenses/>.		░
;░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░
;┌──────────────────────────────────────┐
;│ converts float to ascii				│
;│ input:								│
;│			xmm0 = float input			│
;│			rdx = *_result_str			│
;│			_result_str db 20 dup(?),0	│
;│ output:								│
;│			NaN							│
;└──────────────────────────────────────┘
proc fa_ftoa c uses rdi r10
	locals
		integer_part	dq ?
		decimal_part	dq ?
		ten_const		dq 10.0
	endl
	movsd	[decimal_part],xmm0	; get decimal_part from input
	xor		ecx,ecx			; number of decimal points counter
	mov		rbx,rdx				; store *_result_str into rdx so we can use mul

	; multiply by 10 until no digits after decimal points left
	next_decimal:
		inc		cl
		fld		[decimal_part]	; load real number into stack at ST(0)
		fmul	[ten_const]		; ST0 *= 10
		fisttp	[integer_part]	; trunc [decimal_part] in ST(0) and store it to [integer_part]

		fild	[integer_part]	; load integer number into stack at ST(0)
		fld		[decimal_part]	; load real number into stack at ST(1)
		fmul	[ten_const]		; ST1 *= 10
		fst		[decimal_part]	; store [decimal_part]*10 to [decimal_part] for next iteration

		fcomip	st0,st1
		jne		next_decimal

	fisttp	[decimal_part]		; convert [decimal_part] in ST(1) into integer. at this point, decimal_part contains whole digits.
	movsd	[integer_part],xmm0	; put back float input into integer_part
	fld		[integer_part]		; load real number into stack at ST(0)
	fisttp	[integer_part]		; trunc [decimal_part] and store it to [integer_part]. at this point, decimal_part contains trailing zeros.

	call	fa_pow10			; rax = 10^rcx and rcx is loop counter
	mov		rcx,[integer_part]	; rcx = [integer_part]
	mul		rcx					; rax = [integer_part] * 10^rcx
	sub		[decimal_part],rax	; now decimal_part contains only digits after radix point

	mov		rcx,[decimal_part]	; handle negative values
	call	fa_abs
	mov		[decimal_part],rax

	mov		rdx,rbx				; load back *_result_str and point to _result_str[0]
	call	fa_itoa				; copy [integer_part] which is already in rcx to _result_str

	mov		rcx,rbx				; pass *_result_str for strlen
	call	fa_strlen

	mov		rdi,rbx				; load back *_result_str and point to _result_str[0]
	add		rdi,rax				; point to the digit after last digit.
	mov		rdx,rdi				; store position of the last digit for later (appending decimal_part)
	mov		rax,'.'				; load radix 'dot' character
	stosq						; append 'dot' character to integer_part

	mov		rcx,[decimal_part]
	inc		rdx					; decimal_part begins after radix 'dot' character
	call	fa_itoa				; append decimal_part to 'dot' character

	ret
endp