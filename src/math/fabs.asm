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
;│ returns absolute value of a double number│
;│ input:									│
;│			xmm0 = number					│
;│ output:									│
;│			xmm0 = fabs(number)				│
;└──────────────────────────────────────────┘
proc fa_fabs c
	locals
		input_double dq ?
	endl
	movsd	[input_double],xmm0	; input_double = xmm0
	fld		[input_double]		; load [input_double] into x87 stack (ST0)
	fabs						; round ST0 to integer
	fstp	[input_double]		; [input_double] = ST0 = round(ST0)
	movsd	xmm0,[input_double]	; save [input_double] into xmm0 register
	ret
endp