// IfcEdit.cpp : implementation file
//

#include "stdafx.h"
#include "IfcEdit.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CIfcEdit

CIfcEdit::CIfcEdit(CIfcValue* Value, int xVal , int yVal, int dxVal/* = 0*/, int dyVal/* = 0*/,
		 int xCapt/* = -1*/, int yCapt/* = -1*/, int dxCapt/* = 0*/, int dyCapt/* = 0*/, int IsReadOnly/* = 0*/)
		 :CIfcObject(Value, xVal , yVal, dxVal, dyVal, xCapt, yCapt, 
		  dxCapt, dyCapt), m_IsReadOnly(IsReadOnly)
{
	m_TextClr = RGB(0, 0, 150);
}

CIfcEdit::~CIfcEdit()
{

}

int CIfcEdit::Show(CWnd* pView)
{
	if(m_pCaptStc)
	{	ShowStatic(pView);
//		m_pCaptStc->SetFont(CIfcObject::m_pFont);
		SetWndFont(m_pCaptStc);
	}
	char strVal[CIfcValue::MaxSizeStr];
	if(m_Value.m_pVal)
	{	m_Value.SetValue(strVal);
		DWORD dwStyle = WS_CHILD|WS_TABSTOP|WS_VISIBLE|ES_AUTOHSCROLL;
		if(m_IsReadOnly || !*CIfcObject::m_pIsEdt)
			dwStyle|=ES_READONLY;
		CreateEx(/**CIfcObject::m_pIsEdt?*/WS_EX_CLIENTEDGE/*:NULL*/, 
			_T("EDIT"), strVal, dwStyle, m_xVal, m_yVal,
			m_dxVal, m_dyVal, pView->m_hWnd, (HMENU)CIfcObject::m_IDCtrl++);
//		SetFont(pView->GetFont());
		SetWndFont(this);
//		SetFont(CIfcObject::m_pFont);
	}
	return TRUE;
}
void trem(char* str)
{
	int i;
	for(i=0; i<strlen(str)+1; i++)
		if(str[i] == ' ')
			str = &str[i+1];
		else break;
	for(i=strlen(str)-1; i>=0; i--)
		if(str[i] == ' ')
			str[i] =  '\0';
		else break;

};
int CIfcEdit::Update(int* IsMsg/* = 0*/)
{
	char str[CIfcValue::MaxSizeStr];
	if(m_Value.m_pVal)
	{	if(!m_IsReadOnly)
		{	GetWindowText(str, CIfcValue::MaxSizeStr);
			trem(str);
			if(strcmp(str, "-"))	
				m_Value.GetValue(str, IsMsg);
		}
	}
	return TRUE;
}

BEGIN_MESSAGE_MAP(CIfcEdit, CEdit)
	//{{AFX_MSG_MAP(CIfcEdit)
	ON_WM_CTLCOLOR_REFLECT()
	ON_WM_KEYDOWN()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CIfcEdit message handlers

HBRUSH CIfcEdit::CtlColor(CDC* pDC, UINT nCtlColor) 
{
//	pDC->SetTextColor(RGB(256,45,12));
	
	// TODO: Return a non-NULL brush if the parent's handler should not be called
	return NULL;
}


void CIfcEdit::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	if(	m_Value.m_ValType == CIfcValue::Double)
	{	if(nChar >= 48 && nChar <= 57)
			CEdit::OnKeyDown(nChar, nRepCnt, nFlags);
		else 
			nChar = 0;
	}
	if(nChar == VK_RETURN)
	{
		nChar = VK_TAB;
	}
	CEdit::OnKeyDown(nChar, nRepCnt, nFlags);
}

BOOL CIfcEdit::PreTranslateMessage(MSG* pMsg) 
{
	if(pMsg->message == WM_KEYDOWN)	
		if(pMsg->wParam == VK_RETURN)
			pMsg->wParam = VK_TAB;
	return CEdit::PreTranslateMessage(pMsg);
}
