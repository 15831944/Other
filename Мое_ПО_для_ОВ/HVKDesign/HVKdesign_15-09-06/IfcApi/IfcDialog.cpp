// IfcDialog.cpp : implementation file
//

#include "stdafx.h"
//#include "	\ add additional includes here"
#include "IfcDialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CIfcDialog dialog


CIfcDialog::CIfcDialog(CWnd* pParent /*=NULL*/, int x/* = 0*/, int y/* = 0*/, int dx/* = 0*/, int dy/* = 0*/)
	: CDialog(CIfcDialog::IDD, pParent), m_x(x), m_y(y), m_dx(dx), m_dy(dy)
{
	//{{AFX_DATA_INIT(CIfcDialog)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	m_xStc = 20;
	m_yStc = 30;
	m_xVal = 20;
	m_yVal = m_yStc+15;
	m_Offset = 55;
	m_NumObj = 0;
	m_xBtn = 20;
	m_yBtn = 0;
	m_yCtrl = 40;
	ShowBorderStc = FALSE;
}


void CIfcDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CIfcDialog)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CIfcDialog, CDialog)
	//{{AFX_MSG_MAP(CIfcDialog)
	ON_WM_CREATE()
	ON_WM_CTLCOLOR()
	ON_WM_CLOSE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CIfcDialog message handlers

int CIfcDialog::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CDialog::OnCreate(lpCreateStruct) == -1)
		return -1;
	if(m_x && m_y && m_dx && m_dy)
		MoveWindow(m_x, m_y, m_dx, m_dy);

	if(CIfcObject::m_pFont)
		SetFont(CIfcObject::m_pFont);
	for(int i=0; i<m_NumObj; i++)
	{	m_pObjArr[i]->Show(this);
		if(ShowBorderStc && m_pObjArr[i]->m_pCaptStc)
			m_pObjArr[i]->m_pCaptStc->ModifyStyleEx(0, WS_EX_STATICEDGE, SWP_FRAMECHANGED);
	}
		
	return 0;
}

HBRUSH CIfcDialog::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);
	
	if(dynamic_cast<CStatic*>(pWnd))
		pDC->SetTextColor(RGB(0, 0, 150)); //цвет текста
		
	// TODO: Return a different brush if the default is not desired
	return hbr;
/*
  CIfcObject* pIfcObj; 
	if(pIfcObj = dynamic_cast<CIfcObject*>(pWnd))
		return pIfcObj->SetAttrib(hbr); 
*/
}

BOOL CIfcDialog::PreCreateWindow(CREATESTRUCT& cs) 
{
	return CDialog::PreCreateWindow(cs);
}

void CIfcDialog::OnClose() 
{
	// TODO: Add your message handler code here and/or call default
	
	CDialog::OnClose();
}
