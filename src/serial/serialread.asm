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
;┌──────────────────────────────┐
;│ reads from serial connection	│
;│ input:						│
;│			rcx = *buffer		│
;│			rdx = buf_size		│
;│ output:						│
;│			NaN					│
;└──────────────────────────────┘
proc fa_serialread
	mov r8,rcx
	mov r9,rdx
	;╔══════════════════════════════════════╗
	;║ BOOL ReadFile(						║
	;║ HANDLE       hFile,					║
	;║ LPVOID       lpBuffer,				║
	;║ DWORD        nNumberOfBytesToRead,	║
	;║ LPDWORD      lpNumberOfBytesRead,	║
	;║ LPOVERLAPPED lpOverlapped			║
	;║ );									║
	;╚══════════════════════════════════════╝
	invoke ReadFile, [serial_handler], r8, r9, NULL, NULL

	ret
endp