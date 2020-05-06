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
;┌──────────────────────────┐
;│ opens a serial connection│
;│ input:					│
;│			rcx = *port_name│
;│ output:					│
;│			NaN				│
;└──────────────────────────┘
proc fa_openserial
	;╔══════════════════════════════════════════════╗
	;║ HANDLE CreateFileA(							║
	;║  LPCSTR                lpFileName,			║
	;║  DWORD                 dwDesiredAccess,		║
	;║  DWORD                 dwShareMode,			║
	;║  LPSECURITY_ATTRIBUTES lpSecurityAttributes,	║
	;║  DWORD                 dwCreationDisposition,║
	;║  DWORD                 dwFlagsAndAttributes,	║
	;║  HANDLE                hTemplateFile			║
	;║ );											║
	;╚══════════════════════════════════════════════╝
	invoke CreateFileA,rcx,GENERIC_READ,0,NULL,OPEN_EXISTING,FILE_ATTRIBUTE_NORMAL,NULL
	ret
endp