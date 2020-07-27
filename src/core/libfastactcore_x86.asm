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
format PE DLL

entry DllEntryPoint

include '..\include\win32a.inc'
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
;▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓
section '.data' data readable writeable
	serial_handler dd ?
;▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓
section '.edata' export data readable
	export	'LIBFASTACTCORE_x86.dll',\
			fa_isdigit,'fa_isdigit',\
			fa_islower,'fa_islower',\
			fa_isspace,'fa_isspace',\
			fa_isupper,'fa_isupper',\
			fa_abs,'fa_abs',\
			fa_cos,'fa_cos',\
			fa_deg2rad,'fa_deg2rad',\
			fa_det2,'fa_det2',\
			fa_hypot,'fa_hypot',\
			fa_sin,'fa_sin',\
			fa_sqrt,'fa_sqrt',\
			fa_memcpy,'fa_memcpy',\
			fa_memset,'fa_memset',\
			fa_strlen,'fa_strlen',\
			fa_wait,'fa_wait'
;▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓
section '.text' code readable executable

proc DllEntryPoint hinstDLL,fdwReason,lpvReserved
	mov	eax,TRUE
	ret
endp

; complex
;include 'complex/cabs_x86.asm'
;include 'complex/carg_x86.asm'
;include 'complex/cimag_x86.asm'
;include 'complex/creal_x86.asm'

; ctype
include 'ctype/isdigit_x86.asm'
include 'ctype/islower_x86.asm'
include 'ctype/isspace_x86.asm'
include 'ctype/isupper_x86.asm'

; math
include 'math/abs_x86.asm'
include 'math/cos_x86.asm'
include 'math/deg2rad_x86.asm'
include 'math/det2_x86.asm'
;include 'math/det3_x86.asm'
;include 'math/fabs_x86.asm'
include 'math/hypot_x86.asm'
;include 'math/pow2_x86.asm'
;include 'math/pow10_x86.asm'
;include 'math/round_x86.asm'
include 'math/sin_x86.asm'
include 'math/sqrt_x86.asm'
;include 'math/trunc_x86.asm'

; serial
;include 'serial/closeserial_x86.asm'
;include 'serial/openserial_x86.asm'
;include 'serial/serialread_x86.asm'

; stdio
;include 'stdio/putchar_x86.asm'

; stdlib
;include 'stdlib/atoi_x86.asm'
;include 'stdlib/atoui_x86.asm'
;include 'stdlib/exit_x86.asm'
;include 'stdlib/ftoa_x86.asm'
;include 'stdlib/itoa_x86.asm'
;include 'stdlib/malloc_x86.asm'
;include 'stdlib/rand_x86.asm'

; string
include 'string/memcpy_x86.asm'
include 'string/memset_x86.asm'
;include 'string/strcat_x86.asm'
;include 'string/strcmp_x86.asm'
;include 'string/strcpy_x86.asm'
include 'string/strlen_x86.asm'

; time
;include 'time/time_x86.asm'
include 'time/wait_x86.asm'