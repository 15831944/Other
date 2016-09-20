// IfcTabCtrl.cpp : implementation file
//

#include "stdafx.h"
#include "IfcTabCtrl.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CIfcTabCtrl

CIfcTabCtrl::CIfcTabCtrl(CIfcTabCtrlItem** ItmArr, int NumPage = 1)
			:m_NumPage(NumPage), m_ItmArr(ItmArr)
{
	m_CurSel = -1;
}

CIfcTabCtrl::~CIfcTabCtrl()
{
	for(int i=0; i<m_NumPage; i++)
		if(m_ItmArr[i])
			delete m_ItmArr[i];
	delete[] m_ItmArr;
}


BEGIN_MESSAGE_MAP(CIfcTabCtrl, CTabCtrl)
	//{{AFX_MSG_MAP(CIfcTabCtrl)
	ON_NOTIFY_REFLECT(TCN_SELCHANGE, OnSelchange)
	ON_WM_CTLCOLOR()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CIfcTabCtrl message handlers

void CIfcTabCtrl::OnSelchange(NMHDR* pNMHDR, LRESULT* pResult) 
{
	if(m_CurSel>=0)
		(m_pFrmView->*(m_ItmArr[m_CurSel]->m_HideFn.m_Fn))(m_ItmArr[m_CurSel]->m_HideFn.m_Data);
	m_CurSel= GetCurSel();
	(m_pFrmView->*(m_ItmArr[m_CurSel]->m_ShowFn.m_Fn))(m_ItmArr[m_CurSel]->m_ShowFn.m_Data);
	*pResult = 0;
}

int CIfcTabCtrl::Show(CView* pView, HMENU nIDorHMENU)
{
	m_pFrmView = dynamic_cast<CIfcFormView*>(pView);
	CRect rect;
	pView->GetClientRect(&rect);
	Create(WS_VISIBLE|TCS_FOCUSNEVER|TCS_FIXEDWIDTH|TCS_BUTTONS/*|TCS_FOCUSONBUTTONDOWN|WS_CHILD/*|TCS_RIGHT */,
			CRect(0, 0, rect.right,/* rect.bottom*/25), pView, 12121);
	//ModifyStyle(WS_TABSTOP, TCS_FOCUSNEVER);
	SetFont(pView->GetFont());
//-----------------------------------------------------------------------------------
	TC_ITEM tci;   // в нее записываются параметры создаваемой закладки

	memset(&tci,0,sizeof(tci));
	tci.mask = TCIF_TEXT;		// у закладки будет только текст
	for(int i=0;i<2;i++)
	{	tci.pszText = m_ItmArr[i]->m_Name; // название закладки
		InsertItem(i, &tci);
	}
//-----------------------------------------------------------------------------------

	//чтобы при запуске создавалась первая закладка
	NMHDR hdr;
	hdr.code = TCN_SELCHANGE;
	hdr.hwndFrom = m_hWnd;

	SendMessage(WM_NOTIFY, GetDlgCtrlID(), (LPARAM)&hdr);
	SetFocus();

	return TRUE;
}

int CIfcTabCtrl::Hide(CView* pView)
{
	if(m_CurSel>=0)
		(m_pFrmView->*(m_ItmArr[m_CurSel]->m_HideFn.m_Fn))(m_ItmArr[m_CurSel]->m_HideFn.m_Data);
	m_CurSel = -1;
	return TRUE;
}


HBRUSH CIfcTabCtrl::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
{
	HBRUSH hbr = CTabCtrl::OnCtlColor(pDC, pWnd, nCtlColor);
	
	if(dynamic_cast<CStatic*>(pWnd))
		pDC->SetTextColor(RGB(0, 0, 150)); //цвет текста
	
	return hbr;
}

int CIfcTabCtrl::Update()
{
	NMHDR hdr;
	hdr.code = TCN_SELCHANGE;
	hdr.idFrom = GetCurSel();
	hdr.hwndFrom = m_hWnd;

	SendMessage(WM_NOTIFY, GetDlgCtrlID(), (LPARAM)&hdr);
	SetFocus();

	return TRUE;
}
