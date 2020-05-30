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
;┌───────────────────────────────────────────────────┐
;│ retrieves the argument of a complex number in rad │
;│ input:											 │
;│			xmm0 = number							 │
;│ output:											 │
;│			rax = arg(number)						 │
;└───────────────────────────────────────────────────┘
proc fa_carg
	fld	QWORD [rcx]		; xmm0 = real
	fld	QWORD [rcx+8]	; xmm1 = img
	fpatan
	fstp QWORD [rsp]
	movsd xmm0,[rsp]
	ret
endp