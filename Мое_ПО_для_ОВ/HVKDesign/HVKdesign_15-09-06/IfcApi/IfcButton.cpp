// IfcButton.cpp : implementation file
//

#include "stdafx.h"
//#include "	\ add additional includes here"
#include "IfcObject.h"
#include "IfcButton.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CIfcButton

CIfcButton::CIfcButton(char* Name, int x, int y, BtnFunct ClickFn, int dx/* = 0*/, int dy/* = 0*/)
		:m_ClickFn(ClickFn), m_x(x), m_y(y), m_dx(dx), m_dy(dy)
{
	if(!m_dx)
		dx = BtnLen;
	if(!dy)
		dy = BtnHeight;
	strcpy(m_Name, Name);
}

CIfcButton::~CIfcButton()
{

}


BEGIN_MESSAGE_MAP(CIfcButton, CButton)
	//{{AFX_MSG_MAP(CIfcButton)
	ON_CONTROL_REFLECT(BN_CLICKED, OnClicked)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CIfcButton message handlers

void CIfcButton::OnClicked() 
{
	(m_ClickFn.m_Fn)(m_ClickFn.m_Data);
}

int CIfcButton::Show(CWnd* pView)
{
	DWORD dwStyle = WS_CHILD|WS_TABSTOP|WS_VISIBLE;
	if(!*CIfcObject::m_pIsEdt)
		dwStyle|=WS_DISABLED;
	CreateEx(/**CIfcObject::m_pIsEdt?*/WS_EX_CLIENTEDGE/*:NULL*/, 
	_T("BUTTON"), m_Name, dwStyle, 
	m_x, m_y, m_dx, m_dy, pView->m_hWnd, (HMENU)CIfcObject::m_IDCtrl++);
	SetWndFont(this);
	return TRUE;
}

int CIfcButton::Update(int* IsMsg/* = 0*/)
{
	return TRUE;
}
