
// The following ifdef block is the standard way of creating macros which make exporting 
// from a DLL simpler. All files within this DLL are compiled with the COMAPI_EXPORTS
// symbol defined on the command line. this symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see 
// COMAPI_API functions as being imported from a DLL, wheras this DLL sees symbols
// defined with this macro as being exported.
#ifdef COMAPI_EXPORTS
#define COMAPI __declspec(dllexport)
#else
#define COMAPI __declspec(dllimport)
#endif

#pragma warning(disable:4786 4275 4273 4251)

#include "AdoRecord.h"

#include <string>
using namespace std;

#ifndef __COMAPI__
COMAPI void GenerateError(HRESULT hr, PWSTR pwszDescription, const string& ExtInfo = NULL);
//COMAPI _ConnectionPtr OpenConnection();
#define __COMAPI__
#endif

