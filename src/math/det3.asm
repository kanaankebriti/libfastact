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
;┌──────────────────────────┐
;│ computes determinant of 	│
;| a 3×3 Matrix				|
;│ input:					│
;│			xmm0 = m11		│
;│			xmm1 = m12		│
;│			xmm2 = m21		│
;│			xmm3 = m22		│
;│ output:					│
;│			xmm0 = det(m)	│
;└──────────────────────────┘
proc fa_det3
	;┌							  ┐
	;|	 xmm0	  xmm1	   xmm2	  |
	;|	 xmm3	[rsp+48] [rsp+56] |
	;| [rsp+64] [rsp+72] [rsp+80] |
	;└							  ┘
	movq xmm4,[rsp+48]
	movq xmm5,[rsp+56]
	movq xmm6,[rsp+64]
	movq xmm7,[rsp+72]
	movq xmm8,[rsp+80]

	vmulsd xmm9,xmm4,xmm8
	vmulsd xmm10,xmm5,xmm7
	addsd xmm9,xmm10
	mulsd xmm0,xmm9

	vmulsd xmm9,xmm3,xmm8
	vmulsd xmm10,xmm5,xmm6
	addsd xmm9,xmm10
	mulsd xmm1,xmm9

	vmulsd xmm9,xmm3,xmm7
	vmulsd xmm10,xmm4,xmm6
	addsd xmm9,xmm10
	mulsd xmm2,xmm9

	addsd xmm1,xmm2
	addsd xmm0,xmm1
	ret
endp