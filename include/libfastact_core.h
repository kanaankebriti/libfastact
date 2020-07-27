/*░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░
░ This file is part of libfastact.										░
░																		░
░ libfastact is free software: you can redistribute it and/or modify	░
░ it under the terms of the GNU General Public License as published by	░
░ the Free Software Foundation, either version 3 of the License, or		░
░ (at your option) any later version.									░
░																		░
░ libfastact is distributed in the hope that it will be useful,			░
░ but WITHOUT ANY WARRANTY; without even the implied warranty of		░
░ MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the			░
░ GNU General Public License for more details.							░
░																		░
░ You should have received a copy of the GNU General Public License		░
░ along with libfastact.  If not, see <https://www.gnu.org/licenses/>.	░
░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░*/
#pragma once

#ifndef __LIBFASTACT_H__
#define __LIBFASTACT_H__

#include <d3d9.h>

typedef struct fa_complex
{
	double _Val[2];
} fa_complex;

#ifdef __cplusplus
extern "C"
{
#endif
	// complex
	/// <summary>retrieves the absolute value of a complex number</summary>
	double					fa_cabs(fa_complex _X);
	/// <summary>retrieves the argument of a complex number in rad</summary>
	double					fa_carg(fa_complex _X);
	/// <summary>retrieves the imaginary part of a complex number</summary>
	double					fa_cimag(fa_complex _X);
	/// <summary>retrieves the real part of a complex number</summary>
	double					fa_creal(fa_complex _X);

	// ctype
	/// <summary>checks whether c is decimal digit character</summary>
	_Check_return_ SHORT	fa_isdigit(_In_ SHORT _Character);
	/// <summary>checks whether c is a lowercase letter</summary>
	_Check_return_ SHORT	fa_islower(_In_ SHORT _Character);
	/// <summary>checks whether c is a white-space character</summary>
	_Check_return_ SHORT	fa_isspace(_In_ SHORT _Character);
	/// <summary>checks whether c is an uppercase letter</summary>
	_Check_return_ SHORT	fa_isupper(_In_ SHORT _Character);

	// math
	unsigned long long int	fa_abs(long long int _X);
	_Check_return_ DOUBLE	fa_cos(_In_ double _X);
	_Check_return_ DOUBLE	fa_deg2rad(double _X);
	_Check_return_ DOUBLE	fa_det2(double _M11, double _M12, double _M21, double _M22);
	_Check_return_ DOUBLE	fa_det3(double _M11, double _M12, double _M13, double _M21, double _M22, double _M23, double _M31, double _M32, double _M33);
	_Check_return_ DOUBLE	fa_fabs(double _X);
	_Check_return_ DOUBLE	fa_hypot(double _X, double _Y);
	long long int			fa_pow2(long long int _X);
	long long int			fa_pow10(long long int _X);
	long long int			fa_round(double _X);
	_Check_return_ DOUBLE	fa_sin(double _X);
	_Check_return_ DOUBLE	fa_sqrt(double _X);
	long long int			fa_trunc(double _X);

	// serial
	/// <summary>closes a serial connection</summary>
	void*					fa_closeserial();
	/// <summary>opens a serial connection</summary>
	void*					fa_openserial(const char* _Port);
	/// <summary>reads from serial connection</summary>
	void*					fa_serialread(const char* buffer, unsigned int buf_size);

	// stdio
	/// <summary>writes a character to the stdout</summary>
	_Check_return_opt_ INT	fa_putchar(_In_ INT _Character);

	// stdlib
	/// <summary>convert string to integer</summary>
	int						fa_atoi(const char* _Source);
	/// <summary>convert string to unsigned integer</summary>
	unsigned int			fa_atoui(const char* _Source);
	/// <summary>exit the program</summary>
	long long int*			fa_exit(unsigned short int _Status);
	/// <summary>converts float to ascii</summary>
	void					fa_ftoa(double _Value, char* _Destination);
	/// <summary>converts integer to ascii</summary>
	char*					fa_itoa(long long int _Value, char* _Destination);
	/// <summary>allocates a block of size bytes of memory</summary>
	void*					fa_malloc(unsigned long int _Size);
	/// <summary>generate 64bit random number</summary>
	long long int			fa_rand(void);

	// string
	/// <summary>copy string from source to destination</summary>
	char*					fa_memcpy(void* _Destination, void* _Source,unsigned int _Size);
	/// <summary>appends a copy of the source string</summary>
	void*					fa_memset(void* _Destination, short int _Value, int _Size);
	/// <summary>appends a copy of the source string</summary>
	char*					fa_strcat(char* _Destination, const char* _Source);
	/// <summary>compares the C string str1 to the C string str2</summary>
	int						fa_strcmp(const char* _Str1, const char* _Str2);
	/// <summary>copy string from source to destination</summary>
	char*					fa_strcpy(char* _Destination, const char* _Source);
	/// <summary>returns length of a string</summary>
	unsigned long long int	fa_strlen(_In_ _Null_terminated_ const char* _Str);

	// time
	/// <summary>returns current time in unix time format</summary>
	long long int			fa_time(void);
	/// <summary>suspends the execution of the current thread until the time-out interval elapses</summary>
	void					fa_wait(void);

#ifdef __cplusplus
}
#endif

#endif // !__LIBFASTACT_H__