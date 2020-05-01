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
; Definitions of useful mathematical constants
M_E									equ 2.71828182845904523536	; e
M_LOG2E								equ 1.44269504088896340736	; log2(e)
M_LOG10E							equ 0.434294481903251827651	; log10(e)
M_LN2								equ 0.693147180559945309417	; ln(2)
M_LN10								equ 2.30258509299404568402	; ln(10)
M_PI								equ 3.14159265358979323846	; pi
M_PI_2								equ 1.57079632679489661923	; pi/2
M_PI_4								equ 0.785398163397448309616	; pi/4
M_1_PI								equ 0.318309886183790671538	; 1/pi
M_2_PI								equ 0.636619772367581343076	; 2/pi
M_2_SQRTPI							equ 1.12837916709551257390	; 2/sqrt(pi)
M_SQRT2								equ 1.41421356237309504880	; sqrt(2)
M_SQRT1_2							equ 0.707106781186547524401	; 1/sqrt(2)

; Immediate byte constants
EQUAL_ANY							equ 0000B
RANGES								equ 0100B
EQUAL_EACH							equ 1000B
EQUAL_ORDERED						equ 1100B
NEGATIVE_POLARITY					equ 010000B
BYTE_MASK							equ 1000000B

; Lock flags
D3DLOCK_READONLY					equ 0x00000010
D3DLOCK_DISCARD						equ 0x00002000
D3DLOCK_NOOVERWRITE					equ 0x00001000
D3DLOCK_NOSYSLOCK					equ 0x00000800
D3DLOCK_DONOTWAIT					equ 0x00004000
D3DLOCK_NO_DIRTY_UPDATE				equ 0x00008000

; Primitives supported by draw-primitive API
D3DPT_POINTLIST						equ 1
D3DPT_LINELIST						equ 2
D3DPT_LINESTRIP						equ 3
D3DPT_TRIANGLELIST					equ 4
D3DPT_TRIANGLESTRIP					equ 5
D3DPT_TRIANGLEFAN					equ 6
D3DPT_FORCE_DWORD					equ 0x7fffffff

; Flexible vertex format bits
D3DFVF_RESERVED0					equ 0x001
D3DFVF_POSITION_MASK				equ 0x400E
D3DFVF_XYZ							equ 0x002
D3DFVF_XYZRHW						equ 0x004
D3DFVF_XYZB1						equ 0x006
D3DFVF_XYZB2						equ 0x008
D3DFVF_XYZB3						equ 0x00a
D3DFVF_XYZB4						equ 0x00c
D3DFVF_XYZB5						equ 0x00e
D3DFVF_XYZW							equ 0x4002
D3DFVF_NORMAL						equ 0x010
D3DFVF_PSIZE						equ 0x020
D3DFVF_DIFFUSE						equ 0x040
D3DFVF_SPECULAR						equ 0x080
D3DFVF_TEXCOUNT_MASK				equ 0xf00
D3DFVF_TEXCOUNT_SHIFT				equ 8
D3DFVF_TEX0							equ 0x000
D3DFVF_TEX1							equ 0x100
D3DFVF_TEX2							equ 0x200
D3DFVF_TEX3							equ 0x300
D3DFVF_TEX4							equ 0x400
D3DFVF_TEX5							equ 0x500
D3DFVF_TEX6							equ 0x600
D3DFVF_TEX7							equ 0x700
D3DFVF_TEX8							equ 0x800
D3DFVF_LASTBETA_UBYTE4				equ 0x1000
D3DFVF_LASTBETA_D3DCOLOR			equ 0x8000
D3DFVF_RESERVED2					equ 0x6000 ; 2 reserved bits

; Pool types
D3DPOOL_DEFAULT						equ 0
D3DPOOL_MANAGED						equ 1
D3DPOOL_SYSTEMMEM					equ 2
D3DPOOL_SCRATCH						equ 3
D3DPOOL_FORCE_DWORD					equ 0x7fffffff

; IDirect3DDevice9 interface
IDirect3DDevice9_Release			equ 16
IDirect3DDevice9_CreateVertexBuffer equ 208
IDirect3DDevice9_BeginScene			equ 328
IDirect3DDevice9_EndScene			equ 336
IDirect3DDevice9_Clear				equ 344
IDirect3DDevice9_DrawPrimitive		equ 648
IDirect3DDevice9_SetFVF				equ 712
IDirect3DDevice9_SetStreamSource	equ 800

; IDirect3DVertexBuffer9 interface
IDirect3DVertexBuffer9_Lock			equ 88
IDirect3DVertexBuffer9_Unlock		equ 96

struct fa_complex
	real	dq	?
	img		dq	?
ends

struct fa_vertex
	x	dd ?
	y	dd ?
	z	dd ?
	rhw	dd ?
    r	db ?
	g	db ?
	b	db ?
ends

struct IDirect3DVertexBuffer9
    QueryInterface	dd ?
    AddRef			dd ?
    Release			dd ?
	GetDevice		dd ?
	SetPrivateData	dd ?
	GetPrivateData	dd ?
	FreePrivateData dd ?
	SetPriority		dd ?
	GetPriority		dd ?
	PreLoad			dd ?
	GetType			dd ?
	Lock			dd ?
	Unlock			dd ?
	GetDesc			dd ?
ends