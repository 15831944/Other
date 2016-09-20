#ifdef IFCAPI_EXPORTS
#define IFCAPI __declspec(dllexport)
#else
#define IFCAPI __declspec(dllimport)
#endif

#ifndef _IFCAPI__
#define _IFCAPI__

#pragma warning(disable:4786 4275 4273 4251 4172)

#ifdef _DEBUG
#pragma comment(lib, "..\\Debug\\ComApi.lib")
#else
#pragma comment(lib, "..\\Release\\ComApi.lib")
#endif

/*
#include "IfcFormView.h"
#include "IfcTreeView.h"
#include "IfcObject.h"
*/
void SetWndFont(CWnd* pView);

#define _LEN 586
#define _H   23
#endif