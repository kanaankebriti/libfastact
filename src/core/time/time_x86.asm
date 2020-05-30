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
;┌──────────────────────────────────────────┐
;│ returns current time in unix time format	│
;│ input:									│
;│			NaN								│
;│ output:									│
;│			rax = unix time					│
;└──────────────────────────────────────────┘
proc fa_time c
	; get system time -> convert to file time -> convert to unix time
	locals
		system_time		SYSTEMTIME ?
		file_time		FILETIME ?
		ElapsedSeconds	dd ?
	endl

	;╔══════════════════════════╗
	;║ void GetSystemTime(		║
	;║ LPSYSTEMTIME lpSystemTime║
	;║ );						║
	;╚══════════════════════════╝
	lea		ecx,[system_time]
	call	[GetSystemTime]

	;╔══════════════════════════════════╗
	;║ BOOL SystemTimeToFileTime(		║
	;║ const SYSTEMTIME *lpSystemTime,	║
	;║ LPFILETIME       lpFileTime		║
	;║ );								║
	;╚══════════════════════════════════╝
	lea		ecx,[system_time]
	lea		edx,[file_time]
	call	[SystemTimeToFileTime]

	;╔══════════════════════════════════════╗
	;║ BOOLEAN RtlTimeToSecondsSince1970(	║
	;║ PLARGE_INTEGER Time,					║
	;║ PULONG         ElapsedSeconds		║
	;║ );									║
	;╚══════════════════════════════════════╝
	lea		ecx,[file_time]
	lea		edx,[ElapsedSeconds]
	call	[RtlTimeToSecondsSince1970]
	mov		eax,[ElapsedSeconds]
	ret
endp