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
;┌──────────────────────────────────────┐
;│ clears entire viewport rectangle		│
;│ and fill it with RGB					│
;│ input:								│
;│			rcx = R						│
;│			rdx = G						│
;│			r9 = B						│
;│ output:								│
;│			NaN							│
;└──────────────────────────────────────┘
proc fa_cls c uses rbx
	locals
		d3ddev		dq ?
		rgb_input	db ?,?,?,0x00	;BGR
	endl

	; get d3ddev pointer
	call [fa_get_d3ddev]
	lea	rbx,[rax]
	mov	rax,QWORD [rbx]

	; get RGB color
	mov [rgb_input],r8l
	mov [rgb_input+1],dl
	mov [rgb_input+2],cl
	mov r10d,DWORD [rgb_input]

	fastcall QWORD [rax+IDirect3DDevice9_Clear],rbx,0,0,1,r10d,float DWORD 1.0,DWORD 0
	ret
endp