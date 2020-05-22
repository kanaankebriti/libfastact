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
; Definitions of useful mathematical constants
M_E						equ 2.71828182845904523536	; e
M_LOG2E					equ 1.44269504088896340736	; log2(e)
M_LOG10E				equ 0.434294481903251827651	; log10(e)
M_LN2					equ 0.693147180559945309417	; ln(2)
M_LN10					equ 2.30258509299404568402	; ln(10)
M_PI					equ 3.14159265358979323846	; pi
M_PI_2					equ 1.57079632679489661923	; pi/2
M_PI_4					equ 0.785398163397448309616	; pi/4
M_1_PI					equ 0.318309886183790671538	; 1/pi
M_2_PI					equ 0.636619772367581343076	; 2/pi
M_2_SQRTPI				equ 1.12837916709551257390	; 2/sqrt(pi)
M_SQRT2					equ 1.41421356237309504880	; sqrt(2)
M_SQRT1_2				equ 0.707106781186547524401	; 1/sqrt(2)

; Immediate byte constants
EQUAL_ANY				equ 0000B
RANGES					equ 0100B
EQUAL_EACH				equ 1000B
EQUAL_ORDERED			equ 1100B
NEGATIVE_POLARITY		equ 010000B
BYTE_MASK				equ 1000000B

; complex number
struct fa_complex
	real	dq	?
	img		dq	?
ends

; serial communication
GENERIC_READ			equ 0x80000000
GENERIC_WRITE			equ 0x40000000
GENERIC_EXECUTE			equ 0x20000000
GENERIC_ALL				equ 0x10000000

struct DCB
	DCBlength			dd ?	; sizeof(DCB)
	BaudRate			dd ?	; Baudrate at which running
	fBinary				dd ?	; Binary Mode (skip EOF check)
	fParity				dd ?	; Enable parity checking
	fOutxCtsFlow		dd ?	; CTS handshaking on output
	fOutxDsrFlow		dd ?	; DSR handshaking on output
	fDtrControl			dd ?	; DTR Flow control
	fDsrSensitivity		dd ?	; DSR Sensitivity
	fTXContinueOnXoff 	dd ?	; Continue TX when Xoff sent
	fOutX 				dd ?	; Enable output X-ON/X-OFF
	fInX				dd ?	; Enable input X-ON/X-OFF
	fErrorChar			dd ?	; Enable Err Replacement
	fNull				dd ?	; Enable Null stripping
	fRtsControl			dd ?	; Rts Flow control
	fAbortOnError		dd ?	; Abort all reads and writes on Error
	fDummy2				dd ?	; Reserved
	wReserved			dw ?	; Not currently used
	XonLim				dw ?	; Transmit X-ON threshold
	XoffLim				dw ?	; Transmit X-OFF threshold
	ByteSize			db ?	; Number of bits/byte, 4-8
	Parity				db ?	; 0-4=None,Odd,Even,Mark,Space
	StopBits			db ?	; 0,1,2 = 1, 1.5, 2
	XonChar				db ?	; Tx and Rx X-ON character
	XoffChar			db ?	; Tx and Rx X-OFF character
	ErrorChar			db ?	; Error replacement char
	EofChar				db ?	; End of Input character
	EvtChar				db ?	; Received Event character
	wReserved1			dd ?	; Fill for now.
ends