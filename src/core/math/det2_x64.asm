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
;│			xmm0 = m11		│
;│			xmm1 = m12		│
;│			xmm2 = m21		│
;│			xmm3 = m22		│
;│ output:					│
;│			xmm0 = det(m)	│
;└──────────────────────────┘
proc fa_det2
	;┌			 ┐
	;| xmm0 xmm1 |
	;| xmm2 xmm3 |
	;└			 ┘
	mulsd xmm0,xmm3
	mulsd xmm1,xmm2
	subsd xmm0,xmm1
	ret
endp