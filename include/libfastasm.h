/*░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░
░This file is part of libfastasm.										░
░																		░
░libfastasm is free software: you can redistribute it and/or modify		░
░it under the terms of the GNU General Public License as published by	░
░the Free Software Foundation, either version 3 of the License, or		░
░(at your option) any later version.									░
░																		░
░libfastasm is distributed in the hope that it will be useful,			░
░but WITHOUT ANY WARRANTY; without even the implied warranty of			░
░MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the			░
░GNU General Public License for more details.							░
░																		░
░You should have received a copy of the GNU General Public License		░
░along with Foobar.  If not, see <https://www.gnu.org/licenses/>.		░
░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░*/
#ifndef _LIBFASTASM

#define fa_EXIT_SUCCESS 0
#define fa_EXIT_FAILURE 1
#define fa_M_PI			3.14159265358979323846
#define fa_M_E			2.71828182845904523536

typedef struct fa_complex
{
	double _Val[2];
} fa_complex;

#ifdef __cplusplus
extern "C"
{
#endif
	// complex
	double					fa_cabs(fa_complex _X);
	double					fa_carg(fa_complex _X);
	double					fa_cimag(fa_complex _X);
	double					fa_creal(fa_complex _X);

	// math
	unsigned long long int	fa_abs(long long int _X);
	double					fa_cos(double _X);
	double					fa_deg2rad(double _X);
	double					fa_fabs(double _X);
	double					fa_hypot(double _X, double _Y);
	long long int			fa_pow2(long long int _X);
	long long int			fa_pow10(long long int _X);
	long long int			fa_round(double _X);
	double					fa_sin(double _X);
	double					fa_sqrt(double _X);
	long long int			fa_trunc(double _X);

	// stdlib
	int						fa_atoi(const char* _Source);
	unsigned int			fa_atoui(const char* _Source);
	long long int			fa_exit(unsigned short int _Status);
	void					fa_ftoa(double _Value, char* _Destination);
	char*					fa_itoa(long long int _Value, char* _Destination);
	void*					fa_malloc(long long int _Size);
	long long int			fa_rand(void);

	// string
	void*					fa_memset(char* _Destination, short int _Value, int _Size);
	char*					fa_strcat(char* _Destination, const char* _Source);
	int						fa_strcmp(const char* _Str1, const char* _Str2);
	char*					fa_strcpy(char* _Destination, const char* _Source);
	unsigned long long int	fa_strlen(const char* _Str);

	// time
	long long int			fa_time(void);

#ifdef __cplusplus
}
#endif

#endif // !_LIBFASTASM