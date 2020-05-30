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
;┌──────────────────────────┐
;│ computes determinant of 	│
;| a 2×2 Matrix				|
;│ input:					│
;│			m11				│
;│			m12				│
;│			m21				│
;│			m22				│
;│ output:					│
;│			st0 = det(m)	│
;└──────────────────────────┘
proc fa_det2 stdcall m11:QWORD,m12:QWORD,m21:QWORD,m22:QWORD
	; calculation using xmm
	; store in st0
	locals
		result dq ?
	endl

	movsd	xmm0,[m11]
	movsd	xmm1,[m12]
	movsd	xmm2,[m21]
	movsd	xmm3,[m22]
	;┌			 ┐
	;| xmm0 xmm1 |
	;| xmm2 xmm3 |
	;└			 ┘
	mulsd	xmm0,xmm3
	mulsd	xmm1,xmm2
	subsd	xmm0,xmm1
	movsd	[result],xmm0
	fld		[result]
	ret
endp