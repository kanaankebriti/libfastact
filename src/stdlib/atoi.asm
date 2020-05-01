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
;┌──────────────────────────────┐
;│ convert string to integer	│
;│ input:						│
;│			rcx = *str			│
;│ output:						│
;│			rax = int result	│
;└──────────────────────────────┘
proc fa_atoi c uses rsi
	locals
		ddqDigitRange	db  '0','9',0,0,0,0,0,0,0,0,0,0,0,0,0,0
    	ddqShuffleMask	db  15D,14D,13D,12D,11D,10D,9D,8D,7D,6D,5D,4D,3D,2D,1D,0D
    	ddqFactor1		dw  1D,10D,100D,1000D,1D,10D,100D,1000D
    	ddqFactor2		dd  1D,10000D,100000000D,0
	endl
	mov		rsi,rcx
	; (**A**) indicate negative number in EDX
	mov		rax,-1
	xor		ecx,ecx
	xor		edx,edx
	mov		bl,BYTE [rsi]
	cmp		bl,'-'
	cmove	rdx,rax
	cmp		bl,'+'
	cmove	rcx,rax
	sub		rsi,rdx
	sub		rsi,rcx
	; (**B**)remove leading zeros
	xor		eax,eax					;return value ZERO
	fa_atoi_remove_leading_zeros:
		inc   rsi
		cmp   BYTE [rsi-1],'0'		;skip leading zeros
		je fa_atoi_remove_leading_zeros
	cmp	BYTE [rsi-1],0				;catch empty string/number
	je fa_atoi_finish
	dec	rsi
	;check for valid digit-chars and invert from front to back
	pxor		xmm2,xmm2
	movdqa		xmm0,DQWORD [ddqDigitRange]
	movdqu		xmm1,DQWORD [rsi]
	pcmpistri	xmm0,xmm1,00010100B			; (**C**) iim8=Unsigned bytes, Ranges, Negative Polarity(-), returns strlen() in ECX
	jo fa_atoi_finish						; if first char is invalid return 0 - prevent processing empty string - 0 is still in EAX
	mov			eax,'0'						; value to subtract from chars
	sub			ecx,16						; len-16=negative to zero for shuffle mask
	movd		xmm0,ecx
	pshufb		xmm0,xmm2					; broadcast CL to all 16 BYTEs
	paddb		xmm0,DQWORD [ddqShuffleMask]; Generate permute mask for PSHUFB - all bytes < 0 have highest bit set means place gets zeroed
	pshufb		xmm1,xmm0					; (**D**) permute - now from highest to lowest BYTE are factors 10^0, 10^1, 10^2, ...
	movd		xmm0,eax					; AL='0' from above
	pshufb		xmm0,xmm2					; broadcast AL to XMM0
	psubusb		xmm1,xmm0					; (**1**)
	movdqa		xmm0,xmm1
	punpcklbw	xmm0,xmm2					; (**2**)
	punpckhbw	xmm1,xmm2
	pmaddwd		xmm0,DQWORD [ddqFactor1]	; (**3**)
	pmaddwd		xmm1,DQWORD [ddqFactor1]
	phaddd		xmm0,xmm1					; (**4**)
	pmulld		xmm0,DQWORD [ddqFactor2]	; (**5**)
	pshufd		xmm1,xmm0,11101110B			; (**6**)
	paddd		xmm0,xmm1
	pshufd		xmm1,xmm0,01010101B			; (**7**)
	paddd		xmm0,xmm1
	movd		eax,xmm0
	; negate if negative number
	add			eax,edx						; (**8**)
	xor			eax,edx
	fa_atoi_finish:
		ret
endp