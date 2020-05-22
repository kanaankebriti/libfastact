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
#define STEP 0.000001

#include "tinyexpr.h"

double root;
const char* _expression;
const char* _variable;
double upper_than_at;

VOID WINAPI lower_bound()
{
	double lower_than_at = upper_than_at;
	te_variable var = { _variable, &lower_than_at };
	te_expr* n = te_compile(_expression, &var, 1, 0);

	// check current sign of f(x)
	// the root is found if sign of f(x) has changed
	if (te_eval(n) > 0)
		while (te_eval(n) > 0)
			lower_than_at -= STEP;
	else
		while (te_eval(n) < 0)
			lower_than_at -= STEP;
	root = lower_than_at;
}

VOID WINAPI upper_bound()
{
	te_variable var = { _variable, &upper_than_at };
	te_expr* n = te_compile(_expression, &var, 1, 0);

	// check current sign of f(x)
	// the root is found if sign of f(x) has changed
	if (te_eval(n) > 0)
		while (te_eval(n) > 0)
			upper_than_at += STEP;
	else
		while (te_eval(n) < 0)
			upper_than_at += STEP;
	root = upper_than_at;
}

__declspec(dllexport) DOUBLE fa_realroot(const char* __expression, const char* __variable, double __at)
{
	_expression = __expression;		// store __expression for global access
	_variable = __variable;			// store __variable for global access
	upper_than_at = __at;			// store __at for global access
	HANDLE thread[2];				// thread handle arrays
	thread[0] = CreateThread(NULL, 0, lower_bound, NULL, 0, NULL);	// create thread for numbers less than _at
	thread[1] = CreateThread(NULL, 0, upper_bound, NULL, 0, NULL);	// create thread for numbers more than _at
	WaitForMultipleObjects(2, thread, FALSE, 10000);				// wait for all threads for ten seconds
	CloseHandle(thread[0]);			// close thread 1
	CloseHandle(thread[1]);			// close thread 2
	return root;
}