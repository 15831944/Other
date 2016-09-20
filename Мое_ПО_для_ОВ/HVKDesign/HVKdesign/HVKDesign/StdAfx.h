// stdafx.h : заголовочный файл директив прекомпилятора

#ifndef _STDAFX_H__
#define _STDAFX_H__

#pragma warning(disable:4786 4275 4273 4251)

/* Подключение библиотеки MFC */
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define VC_EXTRALEAN		// Exclude rarely-used stuff from Windows headers

#include <afxwin.h>         // MFC core and standard components
#include <afxext.h>         // MFC extensions
#include <afxdisp.h>        // MFC Automation classes
#include <afxdtctl.h>		// MFC support for Internet Explorer 4 Common Controls
#include <afxcview.h>
#include <afxdisp.h>        // MFC Automation classes
#ifndef _AFX_NO_AFXCMN_SUPPORT
	#include <afxcmn.h>			// MFC support for Windows Common Controls
#endif // _AFX_NO_AFXCMN_SUPPORT
/* Подключение библиотеки MFC */

/* Подключение интерфейсного Api */

//#include "..\\IfcApi\\IfcApi.h"
//#include "..\\IfcApi\\HVKApi.h"
#include "..\\IfcApi\\HVKDbObject.h"
#include "..\\IfcApi\\HVKCalcObject.h"
#include "..\\IfcApi\\CalcHeatBalance.h"
#include "..\\IfcApi\\IfcFormView.h"
#include "..\\IfcApi\\IfcTreeView.h"
#include "..\\IfcApi\\IfcObject.h"

#include "..\\comApi\\ComApi.h"

#ifdef _DEBUG
#pragma comment(lib, "..\\Debug\\ifcapi.lib")
#pragma comment(lib, "..\\Debug\\comapi.lib")
#else
#pragma comment(lib, "..\\Release\\ifcapi.lib")
#pragma comment(lib, "..\\Release\\comapi.lib")
#endif
/* Подключение интерфейсного Api */

/* Подключение HVKApi */
//#include "..\\HvkApi\\HvkApi.h"
#include "..\\IfcApi\\HvkApi.h"
/*
#ifdef _DEBUG
#pragma comment(lib, "..\\Debug\\hvkapi.lib")
#else
#pragma comment(lib, "..\\Release\\hvkapi.lib")
#endif*/
/* Подключение HVKApi */

/* Файлы проекта */
#include "HVKDesign.h"
#include "MainFrm.h"
#include "HVKMainDoc.h"
#include "HVKMainView.h"
#include "HVKTreeView.h"
/* Файлы проекта */

/* Файлы HVKApi.dll */
#include "..\\IfcApi\\Project.h"
/*
#include "..\\HVKApi\\Project.h"
#include "HVKDbObject.h"
#include "HVKVector.h"
#include "Fence.h"
#include "Room.h"
#include "Floor.h"
#include "Building.h"
#include "City.h"
#include "Party.h"
*/
/* Файлы HVKApi.dll */
//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // ndef _STDAFX_H__
