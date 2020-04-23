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
;┌──────────────────────┐
;│ computes 10^n		│
;│ input:				│
;│			rcx = n		│
;│ output:				│
;│			rax = 10^n	│
;└──────────────────────┘
proc fa_pow10 c uses rbx
	; based on fact that 10^n = 2^n * 5^n
	mov ebx,5D		; for 5^n loop
	xor eax,eax		; rax = 0
	bts rax,rcx		; set bit(n) of rax. this gives 2^n.

	five_power_loop:
		mul rbx
		loop five_power_loop	; rcx = n = loop counter
	ret
endp