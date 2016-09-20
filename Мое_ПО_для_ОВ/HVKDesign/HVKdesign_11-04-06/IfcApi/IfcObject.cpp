// IfcObject.cpp: implementation of the CIfcObject class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "IfcObject.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
CIfcObject::CIfcObject(CIfcValue* Value, int xVal , int yVal, int dxVal/* = 0*/, int dyVal/* = 0*/,
		 int xCapt/* = -1*/, int yCapt/* = -1*/, int dxCapt/* = 0*/, int dyCapt/* = 0*/)
		:m_Value(*Value), m_xVal(xVal), m_yVal(yVal), m_dxVal(dxVal), m_dyVal(dyVal),
		m_xCapt(xCapt), m_yCapt(yCapt), m_dxCapt(dxCapt), m_dyCapt(dyCapt)
{	if(!m_dxVal)m_dxVal = Len;
	if(!m_dyVal)m_dyVal = Height;
	if(!m_dxCapt)m_dxCapt = Len;
	if(!m_dyCapt)m_dyCapt = Height;
	if(strcmp(m_Value.m_Capt, ""))
		m_pCaptStc = new CStatic;
	else m_pCaptStc = NULL;
	m_TextClr = RGB(0, 0, 0);
	m_BkgrClr = RGB(255, 255, 255);

};

int CIfcObject::ShowStatic(CWnd* pView)
{
	if(!m_pCaptStc) return FALSE;
	m_pCaptStc->CreateEx(NULL, 
		("STATIC"), m_Value.m_Capt, WS_CHILD|WS_VISIBLE,
		m_xCapt, m_yCapt, m_dxCapt, m_dyCapt,  pView->m_hWnd, (HMENU)CIfcObject::m_IDCtrl++);
	m_pCaptStc->SetFont(pView->GetFont());
	return TRUE;
}

HBRUSH CIfcObject::SetAttrib(HBRUSH hbr)
{
   SetBkMode((HDC)hbr,TRANSPARENT); 
   ::SetTextColor((HDC)hbr, m_TextClr); 
   return hbr;
}