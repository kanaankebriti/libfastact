// libfastact_nonasm.cpp : Defines the exported functions for the DLL.
//

#include "pch.h"
#include "framework.h"
#include "libfastact_nonasm.h"


// This is an example of an exported variable
LIBFASTACTNONASM_API int nlibfastactnonasm=0;

// This is an example of an exported function.
LIBFASTACTNONASM_API int fnlibfastactnonasm(void)
{
    return 0;
}

// This is the constructor of a class that has been exported.
Clibfastactnonasm::Clibfastactnonasm()
{
    return;
}
