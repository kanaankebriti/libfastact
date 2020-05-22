/*
 * TINYEXPR - Tiny recursive descent parser and evaluation engine in C
 *
 * Copyright (c) 2015-2018 Lewis Van Winkle
 *
 * http://CodePlea.com
 *
 * This software is provided 'as-is', without any express or implied
 * warranty. In no event will the authors be held liable for any damages
 * arising from the use of this software.
 *
 * Permission is granted to anyone to use this software for any purpose,
 * including commercial applications, and to alter it and redistribute it
 * freely, subject to the following restrictions:
 *
 * 1. The origin of this software must not be misrepresented; you must not
 * claim that you wrote the original software. If you use this software
 * in a product, an acknowledgement in the product documentation would be
 * appreciated but is not required.
 * 2. Altered source versions must be plainly marked as such, and must not be
 * misrepresented as being the original software.
 * 3. This notice may not be removed or altered from any source distribution.
 */
#ifndef __TINYEXPR_H__
#define __TINYEXPR_H__

#include <Windows.h>

typedef struct te_expr
{
    int type;
    union
    {
        double value;
        const double* bound;
        const void* function;
    };
    void* parameters[1];
} te_expr;

enum
{
    TE_VARIABLE = 0,

    TE_FUNCTION0 = 8, TE_FUNCTION1, TE_FUNCTION2, TE_FUNCTION3,
    TE_FUNCTION4, TE_FUNCTION5, TE_FUNCTION6, TE_FUNCTION7,

    TE_CLOSURE0 = 16, TE_CLOSURE1, TE_CLOSURE2, TE_CLOSURE3,
    TE_CLOSURE4, TE_CLOSURE5, TE_CLOSURE6, TE_CLOSURE7,

    TE_FLAG_PURE = 32
};

typedef struct te_variable
{
    CONST CHAR* name;
    CONST VOID* address;
    INT type;
    VOID* context;
} te_variable;

/// <summary>Parses the input expression, evaluates it, and frees it.Returns NaN on error.</summary>
DOUBLE te_interp(const char* expression, int* error);

/// <summary>Parses the input expression and binds variables.Returns NULL on error.</summary>
te_expr* te_compile(const char* expression, const te_variable* variables, int var_count, int* error);

/// <summary>Evaluates the expression</summary>
DOUBLE te_eval(const te_expr* n);

/// <summary>Prints debugging information on the syntax tree</summary>
VOID te_print(const te_expr* n);

/// <summary>Frees the expression.This is safe to call on NULL pointers.</summary>
VOID te_free(te_expr* n);

static DOUBLE ncr(double n, double r);

#endif /*__TINYEXPR_H__*/