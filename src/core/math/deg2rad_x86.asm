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
;┌──────────────────────────────┐
;│ converts degree to radians	│
;│ input:						│
;│			deg input			│
;│ output:						│
;│			st0 = rad output	│
;└──────────────────────────────┘
proc fa_deg2rad stdcall num:QWORD
	locals
		pi			dq M_PI
		divisor		dq 180.000
	endl
	; calculation using xmm
	; store in st0
	movsd	xmm0,[num]
	divsd	xmm0,[divisor]
	mulsd	xmm0,[pi]
	movsd	[num],xmm0
	fld		[num]
	ret
endp