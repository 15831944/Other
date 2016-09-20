// IfcWnd.h: interface for the CIfcWnd class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_IFCWND_H__668E2017_F6F2_4AAE_9580_44617BE8950F__INCLUDED_)
#define AFX_IFCWND_H__668E2017_F6F2_4AAE_9580_44617BE8950F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "IfcApi.h"

#define HCONTROL 23

class IFCAPI CIfcWnd  
{
public:
	enum
	{
		ObjArrSize = 256
	};

	enum
	{
		HandlEdt,
		BtnEdt,
		BtnDontEdt,
		DontEdt,
		FHandlEdt_SBtnEdt,
		FHandlEdt_SDontEdt,
		FBtnEdt_SHandlEdt,
		FBtnEdt_SDontEdt,
		FBtnDontEdt_SDontEdt,
		FDontEdt_SHandlEdt,
		FDontEdt_SBtnEdt,
		CmbEdt
	};
	int m_xStc, m_yStc, m_xVal, m_yVal, m_Offset, m_xBtn, m_yBtn;
	int m_yCtrl;
	CIfcObject* m_pObjArr[ObjArrSize];
	int m_NumObj;
public:
	CIfcWnd();
	virtual ~CIfcWnd();
	void SetShowParam(int xStc, int yStc, int xVal, int yVal, int Offset,
					  int xBtn, int yBtn, int yCtrl);
//	int ShowHBDataStr(char* Capt, void* Data, int DataType, int isBtn = TRUE);
	int ShowHBHeader(char* Capt1, char* Capt2 = NULL, char* Capt3 = NULL);
	int ShowHBDataStr(char* Capt, void* DataW, void* DataS, int DataType, int ShowType /* = BousHandlEdt*/,
		BtnFunct* ClickFnW = NULL, BtnFunct* ClickFnS = NULL, CADORecord* ptrCurrentRecordset = NULL/*, EdtFunct* UpdateFn = NULL*/);
	int ShowDataStr(char* Capt, void* Data, int DataType, int IsReadOnly = 0/*, EdtFunct* UpdateFn = NULL*/);
	int ShowDataStr(char* Capt, void* Data, int DataType, CADORecord* ptrCurrentRecordset/*, EdtFunct* UpdateFn = NULL*/);
	int ShowDataStr(char* Capt, void* Data, int DataType, 
					char* TxtBtn, BtnFunct ClickFn, 
					int dxBtn, int dyBtn, int IsReadOnly = 0/*, EdtFunct* UpdateFn = NULL*/);
	int HideData(int IsMsg = 1);
	int UpdtData(int IsMsg = 1);

};

#endif // !defined(AFX_IFCWND_H__668E2017_F6F2_4AAE_9580_44617BE8950F__INCLUDED_)
