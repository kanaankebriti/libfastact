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
;┌──────────────────────────────────────────────┐
;│ checks whether c is a white-space character	│
;│ input:										│
;│			rcx = number						│
;│ output:										│
;│			rax = 0	if c is not a white-space	│
;│			rax = number if c is a white-space	│
;└──────────────────────────────────────────────┘
proc fa_isspace c
	xor ax,ax
	cmp cx,0x20		; SPC
	je @F
	cmp cx,0x09		; TAB \t
	je @F
	cmp cx,0x0A		; LF \n
	je @F
	cmp cx,0x0B		; VT \v
	je @F
	cmp cx,0x0C		; FF \f
	je @F
	cmp cx,0x0D		; CR \r
	je @F
	ret
	@@:
		mov ax,cx
		ret
endp