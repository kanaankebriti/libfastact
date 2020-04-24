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
format PE64 DLL

entry DllEntryPoint

include 'include/win64a.inc'
include 'include/libfastasm.inc'
;▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓
section '.reloc' fixups data readable discardable

  if $=$$
    dd 0,8		; if there are no fixups, generate dummy entry
  end if
;▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓
section '.idata' import data readable writeable
	library	kernel32,'KERNEL32.DLL',\
			ntdll,'NTDLL.DLL'

	include	'include\api\kernel32.inc'

	import	ntdll,\
			RtlTimeToSecondsSince1970,'RtlTimeToSecondsSince1970'
;▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓
section '.edata' export data readable
	export	'libfastasm.dll',\
			fa_cabs,'fa_cabs',\
			fa_carg,'fa_carg',\
			fa_cimag,'fa_cimag',\
			fa_creal,'fa_creal',\
			fa_islower,'fa_islower',\
			fa_isupper,'fa_isupper',\
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
include 'ctype/islower.asm'
include 'ctype/isupper.asm'

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
include 'string/memset.asm'
include 'string/strcat.asm'
include 'string/strcmp.asm'
include 'string/strcpy.asm'
include 'string/strlen.asm'

; time
include 'time/time.asm'