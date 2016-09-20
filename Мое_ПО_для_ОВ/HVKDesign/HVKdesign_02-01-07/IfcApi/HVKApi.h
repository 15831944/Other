
// The following ifdef block is the standard way of creating macros which make exporting 
// from a DLL simpler. All files within this DLL are compiled with the HVKAPI_EXPORTS
// symbol defined on the command line. this symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see 
// HVKAPI_API functions as being imported from a DLL, wheras this DLL sees symbols
// defined with this macro as being exported.
#ifdef HVKAPI_EXPORTS
#define HVKAPI __declspec(dllexport)
#else
#define HVKAPI __declspec(dllimport)
#endif

#pragma warning(disable:4786 4275 4273 4251)

#ifndef _HVKAPI_H__
#define _HVKAPI_H__

/* Подключение интерфейсного Api */
//#include "..\\IfcApi\\IfcApi.h"
#ifdef _DEBUG
#pragma comment(lib, "..\\Debug\\comapi.lib")
//#pragma comment(lib, "..\\Debug\\ifcapi.lib")
#else
#pragma comment(lib, "..\\Release\\comapi.lib")
//#pragma comment(lib, "..\\Release\\ifcapi.lib")
#endif


/* Подключение интерфейсного Api */

/*#include <vector>
#include <string>
using namespace std;

/* Файлы проекта */
/*#include "HVKCalcObject.h"
#include "HVKVector.h"
#include "CalcHeatBalance.h"
#include "CalcHeatLoss.h"
*/
/*#include "Project.h"
#include "Fence.h"
#include "Room.h"
#include "Floor.h"
#include "Building.h"
#include "City.h"
#include "Party.h"
*/
/* Файлы проекта */
//#include "afxwin.h"
/*#include "ADORecord.h"

HVKAPI void GenerateError(HRESULT hr, PWSTR pwszDescription);
HVKAPI _ConnectionPtr OpenConnection();
*/
/*
#include "HVKDbObject.h"
#include "HVKCalcObject.h"
#include "CalcHeatBalance.h"
*/
#endif