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
;│ compute cosine				│
;│ input:						│
;│			xmm0 = number		│
;│ output:						│
;│			xmm0 = cos(number)	│
;└──────────────────────────────┘
proc fa_cos
	locals
		temp_result dq ?
	endl

	movsd	[temp_result],xmm0		; move input to [temp_result]
	fld		[temp_result]			; load [temp_result] into x87 stack (ST0)
	fcos							; ST0 = sin(ST0)
	fstp	[temp_result]			; [temp_result] = ST0 = sin(ST0)
	movsd	xmm0,[temp_result]		; save [temp_result] into xmm0 register
	ret
endp