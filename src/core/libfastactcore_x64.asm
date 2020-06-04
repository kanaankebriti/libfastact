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
format PE64 DLL

entry DllEntryPoint

include '..\include\win64a.inc'
include '..\include\libfastact.inc'
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
			ntdll,'NTDLL.DLL'

	include	'..\include\api\kernel32.inc'
	include	'..\include\api\user32.inc'
	include	'..\include\api\gdi32.inc'

	import	ntdll,\
			RtlTimeToSecondsSince1970,'RtlTimeToSecondsSince1970'
	import	d3d9,\
			Direct3DCreate9,'Direct3DCreate9'
;▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓
section '.data' data readable writeable
	serial_handler dq ?
;▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓
section '.edata' export data readable
	export	'LIBFASTACTCORE_X64.dll',\
			fa_cabs,'fa_cabs',\
			fa_carg,'fa_carg',\
			fa_cimag,'fa_cimag',\
			fa_creal,'fa_creal',\
			fa_isdigit,'fa_isdigit',\
			fa_islower,'fa_islower',\
			fa_isspace,'fa_isspace',\
			fa_isupper,'fa_isupper',\
			fa_abs,'fa_abs',\
			fa_cos,'fa_cos',\
			fa_deg2rad,'fa_deg2rad',\
			fa_det2,'fa_det2',\
			fa_det3,'fa_det3',\
			fa_fabs,'fa_fabs',\
			fa_hypot,'fa_hypot',\
			fa_pow2,'fa_pow2',\
			fa_pow10,'fa_pow10',\
			fa_round,'fa_round',\
			fa_sin,'fa_sin',\
			fa_sqrt,'fa_sqrt',\
			fa_trunc,'fa_trunc',\
			fa_closeserial,'fa_closeserial',\
			fa_openserial,'fa_openserial',\
			fa_serialread,'fa_serialread',\
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
			fa_time,'fa_time',\
			fa_wait,'fa_wait'
;▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓
section '.text' code readable executable

proc DllEntryPoint hinstDLL,fdwReason,lpvReserved
	mov	eax,TRUE
	ret
endp

; complex
include 'complex/cabs_x64.asm'
include 'complex/carg_x64.asm'
include 'complex/cimag_x64.asm'
include 'complex/creal_x64.asm'

; ctype
include 'ctype/isdigit_x64.asm'
include 'ctype/islower_x64.asm'
include 'ctype/isspace_x64.asm'
include 'ctype/isupper_x64.asm'

; math
include 'math/abs_x64.asm'
include 'math/cos_x64.asm'
include 'math/deg2rad_x64.asm'
include 'math/det2_x64.asm'
include 'math/det3_x64.asm'
include 'math/fabs_x64.asm'
include 'math/hypot_x64.asm'
include 'math/pow2_x64.asm'
include 'math/pow10_x64.asm'
include 'math/round_x64.asm'
include 'math/sin_x64.asm'
include 'math/sqrt_x64.asm'
include 'math/trunc_x64.asm'

; serial
include 'serial/closeserial_x64.asm'
include 'serial/openserial_x64.asm'
include 'serial/serialread_x64.asm'

; stdio
include 'stdio/putchar_x64.asm'

; stdlib
include 'stdlib/atoi_x64.asm'
include 'stdlib/atoui_x64.asm'
include 'stdlib/exit_x64.asm'
include 'stdlib/ftoa_x64.asm'
include 'stdlib/itoa_x64.asm'
include 'stdlib/malloc_x64.asm'
include 'stdlib/rand_x64.asm'

; string
include 'string/memcpy_x64.asm'
include 'string/memset_x64.asm'
include 'string/strcat_x64.asm'
include 'string/strcmp_x64.asm'
include 'string/strcpy_x64.asm'
include 'string/strlen_x64.asm'

; time
include 'time/time_x64.asm'
include 'time/wait_x64.asm'