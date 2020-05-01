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
format PE64 DLL

entry DllEntryPoint

include 'include/win64a.inc'
include 'include/libfastact.inc'
;▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓
section '.reloc' fixups data readable discardable
  if $=$$
    dd 0,8		; if there are no fixups, generate dummy entry
  end if
;▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓
section '.idata' import data readable writeable
	library	kernel32,'KERNEL32.DLL',\
			user32,'USER32.DLL',\
			gdi32,'GDI32.DLL',\
			ntdll,'NTDLL.DLL',\
			d3d9,'D3D9.DLL',\
			fastact_nonasm,'libfastactnonasm.dll'

	include	'include\api\kernel32.inc'
	include	'include\api\user32.inc'
	include	'include\api\gdi32.inc'

	import	ntdll,\
			RtlTimeToSecondsSince1970,'RtlTimeToSecondsSince1970'
	import	d3d9,\
			Direct3DCreate9,'Direct3DCreate9'
	import	fastact_nonasm,\
			fa_begindraw,'fa_begindraw',\
			fa_get_d3ddev,'fa_get_d3ddev',\
			fa_enddraw,'fa_enddraw',\
			fa_initgraphics,'fa_initgraphics',\
			fa_line,'fa_line',\
			fa_pset,'fa_pset'
;▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓
section '.data' data readable writeable
	_main_window_class WNDCLASSEX sizeof.WNDCLASSEX,0,WindowProc,0,0,?,?,?,?,?,_class,?
	_window_title db 'test',0
	_class db '_class',0
	rc RECT
	hdc dq ?
	hrc dq ?
	hwnd dq ?
;▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓
section '.edata' export data readable
	export	'libfastasm.dll',\
			fa_cabs,'fa_cabs',\
			fa_carg,'fa_carg',\
			fa_cimag,'fa_cimag',\
			fa_creal,'fa_creal',\
			fa_isdigit,'fa_isdigit',\
			fa_islower,'fa_islower',\
			fa_isspace,'fa_isspace',\
			fa_isupper,'fa_isupper',\
			fa_createwindow,'fa_createwindow',\
			fa_cls,'fa_cls',\
			fa_abs,'fa_abs',\
			fa_cos,'fa_cos',\
			fa_deg2rad,'fa_deg2rad',\
			fa_fabs,'fa_fabs',\
			fa_hypot,'fa_hypot',\
			fa_pow2,'fa_pow2',\
			fa_pow10,'fa_pow10',\
			fa_round,'fa_round',\
			fa_sin,'fa_sin',\
			fa_sqrt,'fa_sqrt',\
			fa_trunc,'fa_trunc',\
			fa_putchar,'fa_putchar',\
			fa_atoi,'fa_atoi',\
			fa_atoui,'fa_atoui',\
			fa_exit,'fa_exit',\
			fa_ftoa,'fa_ftoa',\
			fa_itoa,'fa_itoa',\
			fa_malloc,'fa_malloc',\
			fa_rand,'fa_rand',\
			fa_memcpy,'fa_memcpy',\
			fa_memset,'fa_memset',\
			fa_strcat,'fa_strcat',\
			fa_strcmp,'fa_strcmp',\
			fa_strcpy,'fa_strcpy',\
			fa_strlen,'fa_strlen',\
			fa_time,'fa_time'
;▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓
section '.text' code readable executable

proc DllEntryPoint hinstDLL,fdwReason,lpvReserved
	mov	eax,TRUE
	ret
endp

; complex
include 'complex/cabs.asm'
include 'complex/carg.asm'
include 'complex/cimag.asm'
include 'complex/creal.asm'

; ctype
include 'ctype/isdigit.asm'
include 'ctype/islower.asm'
include 'ctype/isspace.asm'
include 'ctype/isupper.asm'

; graphics
include 'graphics/createwindow.asm'
include 'graphics/cls.asm'

; math
include 'math/abs.asm'
include 'math/cos.asm'
include 'math/deg2rad.asm'
include 'math/fabs.asm'
include 'math/hypot.asm'
include 'math/pow2.asm'
include 'math/pow10.asm'
include 'math/round.asm'
include 'math/sin.asm'
include 'math/sqrt.asm'
include 'math/trunc.asm'

; stdio
include 'stdio/putchar.asm'

; stdlib
include 'stdlib/atoi.asm'
include 'stdlib/atoui.asm'
include 'stdlib/exit.asm'
include 'stdlib/ftoa.asm'
include 'stdlib/itoa.asm'
include 'stdlib/malloc.asm'
include 'stdlib/rand.asm'

; string
include 'string/memcpy.asm'
include 'string/memset.asm'
include 'string/strcat.asm'
include 'string/strcmp.asm'
include 'string/strcpy.asm'
include 'string/strlen.asm'

; time
include 'time/time.asm'