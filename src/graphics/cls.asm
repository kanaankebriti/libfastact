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

; entire viewport rectangle
; rcx = IDirect3DDevice9* dev
;┌──────────────────────────────────────┐
;│ entire viewport rectangle			│
;│ input:								│
;│			rcx = IDirect3DDevice9* dev	│
;│			rdx = R						│
;│			r8 = G						│
;│			r9 = B						│
;│ output:								│
;│			NaN							│
;└──────────────────────────────────────┘
proc fa_cls c
	locals
		d3ddev		dq ?
		rgb_input	db ?,?,?,0x00	;BGR
	endl

	; get d3ddev pointer
	mov	[d3ddev],rcx
	mov	rax, QWORD [d3ddev]
	mov	rax, QWORD [rax]

	; get RGB color
	mov [rgb_input],r9l
	mov [rgb_input+1],r8l
	mov [rgb_input+2],dl
	mov r10d,DWORD [rgb_input]

	fastcall QWORD [rax+IDirect3DDevice9_Clear],QWORD [d3ddev],0,0,1,r10d,float DWORD 1.0,DWORD 0
	ret
endp