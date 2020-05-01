// The following ifdef block is the standard way of creating macros which make exporting
// from a DLL simpler. All files within this DLL are compiled with the LIBFASTACTNONASM_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see
// LIBFASTACTNONASM_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef LIBFASTACTNONASM_EXPORTS
#define LIBFASTACTNONASM_API __declspec(dllexport)
#else
#define LIBFASTACTNONASM_API __declspec(dllimport)
#endif

// This class is exported from the dll
class LIBFASTACTNONASM_API Clibfastactnonasm {
public:
	Clibfastactnonasm(void);
	// TODO: add your methods here.
};

extern LIBFASTACTNONASM_API int nlibfastactnonasm;

LIBFASTACTNONASM_API int fnlibfastactnonasm(void);
