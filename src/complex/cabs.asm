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
;┌──────────────────────────────────────────────────┐
;│ retrieves the absolute value of a complex number	│
;│ input:											│
;│			rcx = fa_complex						│
;│ output:											│
;│			xmm0 = abs(fa_complex)					│
;└──────────────────────────────────────────────────┘
proc fa_cabs
	movsd	xmm0,QWORD [rcx]	; xmm0 = real
	movsd	xmm1,QWORD [rcx+8]	; xmm1 = img
	mulsd	xmm0,xmm0			; xmm0 = xmm0 ^ 2
	mulsd	xmm1,xmm1			; xmm1 = xmm1 ^ 2
	addsd	xmm0,xmm1			; xmm0 = xmm0 + xmm1
	sqrtsd	xmm0,xmm0			; Compute Square Root of Scalar Double-Precision Floating-Point Value
	ret
endp