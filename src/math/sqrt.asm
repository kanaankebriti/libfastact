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
;│ sqruare root					│
;│ input:						│
;│			xmm0 = number		│
;│ output:						│
;│			xmm0 = sqrt(number)	│
;│			or if number < 0	|
;│			xmm0 = number		│
;└──────────────────────────────┘
proc fa_sqrt c
	pxor	xmm1,xmm1		; xmm1 = 0
	comisd	xmm0,xmm1		; cehck for negative input. xmm0 < 0
	jb		negative_sqrt
	sqrtsd	xmm0,xmm0		; Compute Square Root of Scalar Double-Precision Floating-Point Value. sd means scalar double, as opposed to SIMD packed double	
	mov		eax,1
	ret
	negative_sqrt:
		ret
endp