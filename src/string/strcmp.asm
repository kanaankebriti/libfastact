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
;┌──────────────────────────────────────────────────────────────────────────────────────────────────┐
;│ compares the C string str1 to the C string str2													│
;│ input:																							│
;│			rcx = *str1																				│
;│			rdx = *str2																				│
;│ output:																							│
;│			rax < 0	the first character that does not match has a lower value in str1 than in str2	│
;│			rax = 0	the contents of both strings are equal											│
;│			rax > 0	the first character that does not match has a greater value in str1 than in str2│
;└──────────────────────────────────────────────────────────────────────────────────────────────────┘
proc fa_strcmp
	; Using __fastcall convention, ecx = string1, edx = string2
	mov rax,rcx
	sub rax,rdx	; eax = ecx - edx
	sub rdx,16

	@@:
		add		rdx,16
		movdqu	xmm0,dqword[rdx]
		; find the first *different* bytes, hence negative polarity
		pcmpistri xmm0, dqword[rdx + rax], EQUAL_EACH + NEGATIVE_POLARITY
		ja @B

	jc fa_strcmp_diff

	; the strings are equal
	xor eax,eax
	ret

	fa_strcmp_diff:
		; subtract the first different bytes
		add rax,rdx
		movzx rax,BYTE [rax + rcx]
		movzx rdx,BYTE [rdx + rcx]
		sub rax,rdx
		ret
endp