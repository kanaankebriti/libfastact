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
fa_M_PI				equ 3.14159265358979323846
; Immediate byte constants
fa_EQUAL_ANY			= 0000B
fa_RANGES				= 0100B
fa_EQUAL_EACH			= 1000B
fa_EQUAL_ORDERED		= 1100B
fa_NEGATIVE_POLARITY	= 010000B
fa_BYTE_MASK			= 1000000B

; IDirect3DDevice9 interface
IDirect3DDevice9_Clear equ 344

struct fa_complex
	real	dq	?
	img		dq	?
ends