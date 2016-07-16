// The following ifdef block is the standard way of creating macros which make exporting 
// from a DLL simpler. All files within this DLL are compiled with the DLL_PROJECT_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see 
// DLL_PROJECT_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef DLL_PROJECT_EXPORTS
#define DLL_PROJECT_API __declspec(dllexport)
#else
#define DLL_PROJECT_API __declspec(dllimport)
#endif

// This class is exported from the dll_project.dll
class DLL_PROJECT_API Cdll_project {
public:
	Cdll_project(void);
	// TODO: add your methods here.
};

extern DLL_PROJECT_API int ndll_project;

DLL_PROJECT_API int fndll_project(void);
