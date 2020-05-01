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
;┌──────────────────────────────────────────┐
;│ returns the hypotenuse of a right-angled	│
;│ triangle whose legs are x and y			│
;│ input:									│
;│			xmm0 = x						│
;│			xmm1 = y						│
;│ output:									│
;│			xmm0 = sqrt(x^2 + y^2)			│
;└──────────────────────────────────────────┘
proc fa_hypot c
	mulsd xmm0,xmm0 ; x^2
	mulsd xmm1,xmm1 ; y^2
	addsd xmm0,xmm1 ; x^2 + y^2
	sqrtsd xmm0,xmm0 ; sqrt(x^2 + y^2)
	ret
endp