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

;┌──────────────────────────────────────┐
;│ draws a 2d line with color RGB		|
;│ input:								│
;│			rcx = IDirect3DDevice9* dev	│
;│ output:								│
;│			NaN							│
;└──────────────────────────────────────┘
proc fa_line c
	locals
		p1 fa_vertex 0,0,0,0,0,0,0 ; x,y,z,rhw,r,g,b
		p2 fa_vertex 300,300,0,0,255,0,0
		vertex_buffer IDirect3DVertexBuffer9
	endl

	;mov	rax, rcx
	;mov	rax, QWORD [rcx]
	;fastcall QWORD [rax+IDirect3DDevice9_BeginScene],rcx
	mov rax,sizeof.IDirect3DVertexBuffer9
	ret
endp