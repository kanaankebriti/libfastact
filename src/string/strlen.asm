;░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░
;░This file is part of libfastasm.										░
;░																		░
;░libfastasm is free software: you can redistribute it and/or modify	░
;░it under the terms of the GNU General Public License as published by	░
;░the Free Software Foundation, either version 3 of the License, or		░
;░(at your option) any later version.									░
;░																		░
;░libfastasm is distributed in the hope that it will be useful,			░
;░but WITHOUT ANY WARRANTY; without even the implied warranty of		░
;░MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the			░
;░GNU General Public License for more details.							░
;░																		░
;░You should have received a copy of the GNU General Public License		░
;░along with Foobar.  If not, see <https://www.gnu.org/licenses/>.		░
;░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░
;┌──────────────────────────────┐
;│ returns length of a string	│
;│ input:						│
;│			rcx = *str			│
;│ output:						│
;│			rax = length of	str	│
;└──────────────────────────────┘
proc fa_strlen c
	mov rax,-16D
	mov rdx,rcx
	pxor xmm0,xmm0
	@@:
    	add rax,16D										; read 8 chars
    	pcmpistri xmm0,dqword[rax + rdx],fa_EQUAL_EACH	; find zero in address [rdx + r8] if any
    	jnz @B								; or try again in next loop
	add rax,rcx
	ret
endp