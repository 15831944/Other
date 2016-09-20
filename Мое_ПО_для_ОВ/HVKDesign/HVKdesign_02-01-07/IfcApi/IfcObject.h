// IfcObject.h: interface for the CIfcObject class.
//
//////////////////////////////////////////////////////////////////////

#ifndef _IFCOBJECT_H__
#define _IFCOBJECT_H__

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "IfcApi.h"
#include "IfcValue.h"

class IFCAPI CIfcObject// : public CObject  
{
//	static int	m_Len, m_Height;
	enum
	{
		Len = _LEN, 
		Height = _H
	};
	int m_dx, m_dy;
public:
	int   m_xCapt,
		  m_yCapt;
	int	  m_dxCapt,
		  m_dyCapt;
	int	  m_xVal,
		  m_yVal;
	int	  m_dxVal,
		  m_dyVal;
	CIfcValue m_Value;
	CStatic*  m_pCaptStc;
 	static int* m_pIsEdt;
	static int  m_IDCtrl;
	static CFont* m_pFont;
	COLORREF  m_TextClr;
	COLORREF  m_BkgrClr;
public:
	CIfcObject(){m_pCaptStc = NULL;};
	CIfcObject(CIfcValue* Value, int xVal , int yVal, int dxVal = 0, int dyVal = 0,
			 int xCapt = -1, int yCapt = -1, int dxCapt = 0, int dyCapt = 0);
	virtual ~CIfcObject()
	{if(m_pCaptStc)	delete m_pCaptStc;};
	int SetValue(CIfcValue* pValue){ m_Value = *pValue; return TRUE;};
	virtual int Show(CWnd* pView){return TRUE;};
	virtual int Update(int* IsMsg = 0){return TRUE;};
	HBRUSH SetAttrib(HBRUSH hbr);
//	void SetSize(int Len, int Height){m_Len = Len, m_Height = Height;};
protected:
	int ShowStatic(CWnd* pView);
};

#endif // !defined _IFCOBJECT_H__
