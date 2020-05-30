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
;│ convert string to unsigned integer	│
;│ input:								│
;│			rcx = *str					│
;│ output:								│
;│			rax = int result			│
;└──────────────────────────────────────┘
proc fa_atoui uses rbx
	locals
		ddqDigitRange	db  '0','9',0,0,0,0,0,0,0,0,0,0,0,0,0,0
    	ddqShuffleMask	db  15D,14D,13D,12D,11D,10D,9D,8D,7D,6D,5D,4D,3D,2D,1D,0D
    	ddqFactor1		dw  1D,10D,100D,1000D,1D,10D,100D,1000D
    	ddqFactor2		dd  1D,10000D,100000000D,0
	endl
	xor		ebx,ebx
	; (**B**)remove leading zeros
	xor		eax,eax					;return value ZERO
	fa_atoui_remove_leading_zeros:
		inc   rcx
		cmp   BYTE [rcx-1],'0'		;skip leading zeros
		je fa_atoui_remove_leading_zeros
	cmp	BYTE [rcx-1],0				;catch empty string/number
	je fa_atoui_finish
	dec	rcx
	;check for valid digit-chars and invert from front to back
	pxor		xmm2,xmm2
	movdqa		xmm0,DQWORD [ddqDigitRange]
	movdqu		xmm1,DQWORD [rcx]
	pcmpistri	xmm0,xmm1,00010100B			; (**C**) iim8=Unsigned bytes, Ranges, Negative Polarity(-), returns strlen() in ECX
	jo fa_atoi_finish						; if first char is invalid return 0 - prevent processing empty string - 0 is still in EAX
	mov			rax,'0'						; value to subtract from chars
	sub			rcx,16						; len-16=negative to zero for shuffle mask
	movq		xmm0,rcx
	pshufb		xmm0,xmm2					; broadcast CL to all 16 BYTEs
	paddb		xmm0,DQWORD [ddqShuffleMask]; Generate permute mask for PSHUFB - all bytes < 0 have highest bit set means place gets zeroed
	pshufb		xmm1,xmm0					; (**D**) permute - now from highest to lowest BYTE are factors 10^0, 10^1, 10^2, ...
	movq		xmm0,rax					; AL='0' from above
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
	movq		rax,xmm0
	fa_atoui_finish:
		ret
endp