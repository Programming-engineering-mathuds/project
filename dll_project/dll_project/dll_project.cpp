// dll_project.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "dll_project.h"


// This is an example of an exported variable
DLL_PROJECT_API int ndll_project=0;

// This is an example of an exported function.
DLL_PROJECT_API int fndll_project(void)
{
	return 42;
}

// This is the constructor of a class that has been exported.
// see dll_project.h for the class definition
Cdll_project::Cdll_project()
{
	return;
}
