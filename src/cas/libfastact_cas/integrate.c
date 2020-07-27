#include "tinyexpr.h"

__declspec(dllexport) DOUBLE fa_integrate(const char* _Expression, const char* _Variable, DOUBLE _Lbound, DOUBLE _Hbound, unsigned int _Intervals)
{
	DOUBLE sum = 0;
	DOUBLE range = _Hbound - _Lbound;
	DOUBLE dx = range / (DOUBLE) _Intervals;
	DOUBLE fx = _Lbound;
	te_variable var = { _Variable, &fx };
	te_expr* n = te_compile(_Expression, &var, 1, 0);
	register UINT i = 1;

	// value of function at _Lbound
	sum += te_eval(n);

	// go to f(x1)
	fx += dx;

	// sumation off odd terms e.g. f(x1) + f(x3) + f(x5) + ...
	do
	{
		sum += 4 * te_eval(n);
		fx += 2 * dx;
	} while (fx < _Hbound);

	// value of function at _Hbound
	sum += te_eval(n);

	// get back to f(n-1)
	fx -= dx;

	// sumation off even terms e.g. f(n-1) + f(n-3) + ... + f(x4) + f(2)
	do
	{
		sum += 2 * te_eval(n);
		fx -= 2 * dx;
	} while (fx > _Lbound);

	range /= (DOUBLE) _Intervals;
	sum *= range / 3.0;

	return sum;
}