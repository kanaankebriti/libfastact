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
;│ sets the first num bytes of the block of memory	│
;| pointed by destination_str to the specified value│
;│ input:											│
;│			rcx = *destination_str					│
;│			rdx = value								│
;│			r8 = size								│
;│ output:											│
;│			rax = *destination_str					│
;└──────────────────────────────────────────────────┘
proc fa_memset uses rdi r9
	mov r9,rcx	; save *destination_str
	mov	rdi,rcx	; set destination_str
	mov	rcx,r8	; set size
	mov al,dl	; set value
	rep	stosb	; store n times
	mov	rax,r9  ; return pointer
	ret
endp